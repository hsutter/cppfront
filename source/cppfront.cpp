
//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.


//===========================================================================
//  cppfront
//===========================================================================

#include "sema.h"
#include <iostream>
#include <cstdio>
#include <optional>

namespace cpp2 {

//  Defined out of line here just to avoid bringing <iostream> into the headers,
//  so that we can't accidentally start depending on iostreams in the compiler body
auto cmdline_processor::print(std::string_view s, int width) -> void
{
    if (width > 0) {
        std::cout << std::setw(width) << std::left;
    }
    std::cout << s;
}


//-----------------------------------------------------------------------
//
//  Stringingizing helpers
//
//-----------------------------------------------------------------------

auto pad(int padding) -> std::string_view
{
    static std::string indent_str = std::string( 1024, ' ' );    // "1K should be enough for everyone"

    if (padding < 1) {
        return "";
    }

    return {
        indent_str.c_str(),
        as<size_t>( std::min( padding, as<int>(std::ssize(indent_str))) )
    };
}


//-----------------------------------------------------------------------
//
//  positional_printer: a Syntax 1 pretty printer
//
//-----------------------------------------------------------------------
//
static auto flag_clean_cpp1 = false;
static cmdline_processor::register_flag cmd_noline(
    9,
    "clean-cpp1",
    "Emit clean Cpp1 without #line directives",
    []{ flag_clean_cpp1 = true; }
);

static auto flag_cpp2_only = false;
static cmdline_processor::register_flag cmd_cpp2_only(
    0,
    "pure-cpp2",
    "Allow Cpp2 syntax only",
    []{ flag_cpp2_only = true; }
);

static auto flag_safe_null_pointers = true;
static cmdline_processor::register_flag cmd_safe_null_pointers(
    2,
    "null-checks",
    "Null safety checks (on by default, '-' to disable)",
    nullptr,
    [](std::string const& opt){ flag_safe_null_pointers = opt.empty(); },
    {},
    true
);

static auto flag_safe_subscripts = true;
static cmdline_processor::register_flag cmd_safe_subscripts(
    2,
    "subscript-checks",
    "Subscript safety checks (on by default, '-' to disable)",
    nullptr,
    [](std::string const& opt){ flag_safe_subscripts = opt.empty(); },
    {},
    true
);

static auto flag_safe_comparisons = true;
static cmdline_processor::register_flag cmd_safe_comparisons(
    2,
    "comparison-checks",
    "Mixed-sign comparison safety checks (on by default, '-' to disable)",
    nullptr,
    [](std::string const& opt){ flag_safe_comparisons = opt.empty(); },
    {},
    true
);

static auto flag_use_source_location = false;
static cmdline_processor::register_flag cmd_enable_source_info(
    2,
    "add-source-info",
    "Enable source_location information for contract checks",
    []{ flag_use_source_location = true; }
);

static auto flag_cpp1_filename = std::string{};
static cmdline_processor::register_flag cmd_cpp1_filename(
    9,
    "output",
    "Output filename, or 'stdout' (default is *.cpp/*.h)",
    nullptr,
    [](std::string const& name) { flag_cpp1_filename = name; }
);

static auto flag_print_colon_errors = false;
static cmdline_processor::register_flag cmd_print_colon_errors(
    9,
    "format-colon-errors",
    "Emit ':line:col:' format for messages (lights up some tools)",
    []{ flag_print_colon_errors = true; }
);

static auto flag_verbose = false;
static cmdline_processor::register_flag cmd_verbose(
    9,
    "verbose",
    "Print verbose statistics",
    []{ flag_verbose = true; }
);

static auto flag_no_exceptions = false;
static cmdline_processor::register_flag cmd_no_exceptions(
    4,
    "fno-exceptions",
    "Disable C++ EH, failed 'as' for 'variant' will assert (for now)",
    []{ flag_no_exceptions = true; }
);

static auto flag_no_rtti = false;
static cmdline_processor::register_flag cmd_no_rtti(
    4,
    "fno-rtti",
    "Disable C++ RTTI, using 'as' for '*'/'std::any' will assert (for now)",
    []{ flag_no_rtti = true; }
);

struct text_with_pos{
    std::string     text;
    source_position pos;
    text_with_pos(std::string const& t, source_position p) : text{t}, pos{p} { }
};

// Defined out of line so we can use flag_print_colon_errors.
auto error::print(auto& o, std::string const& file) const -> void {
    o << file ;
    if (where.lineno > 0) {
        if (flag_print_colon_errors) {
            o << ":"<< (where.lineno);
            if (where.colno >= 0) {
                o << ":" << where.colno;
            }
        }
        else {
            o << "("<< (where.lineno);
            if (where.colno >= 0) {
                o << "," << where.colno;
            }
            o  << ")";
        }
    }
    o << ":";
    if (internal) {
        o << " internal compiler";
    }
    o << " error: " << msg << "\n";
}

class positional_printer
{
    //  Core information
    std::ofstream               out_file      = {}; // Cpp1 syntax output file
    std::ostream*               out           = {}; // will point to out_file or cout
    std::string                 cpp2_filename = {};
    std::string                 cpp1_filename = {};
    std::vector<comment> const* pcomments     = {}; // Cpp2 comments data

    source_position curr_pos                  = {}; // current (line,col) in output
    int             next_comment              = 0;  // index of the next comment not yet printed
    bool            last_was_cpp2             = false;
    bool            source_has_cpp2           = false;

    struct req_act_info {
        colno_t requested;
        colno_t offset;

        req_act_info(colno_t r, colno_t o) : requested{r}, offset{o} { }
    };
    struct {
        lineno_t line = {};
        std::vector<req_act_info> requests = {};
    } prev_line_info = {};

    //  Position override information
    std::vector<source_position> preempt_pos = {};  // use this position instead of the next supplied one
    int             pad_for_this_line   = 0;        // extra padding to add/subtract for this line only
    bool            ignore_align        = false;
    int             ignore_align_indent = 0;
    lineno_t        ignore_align_lineno = 0;
    bool            enable_indent_heuristic = true;

    //  Modal information
    bool            declarations_only   = true;     // print only declarations in the first pass

    std::vector<std::string*>                emit_string_targets;       // option to emit to string instead of out file
    std::vector<std::vector<text_with_pos>*> emit_text_chunks_targets;  // similar for vector<text_pos>

    enum class target_type { string, chunks };
    std::vector<target_type>                 emit_target_stack;         // to interleave them sensibly


    //-----------------------------------------------------------------------
    //  Print text
    //
    auto print( std::string_view s, source_position pos = source_position{}) -> void
    {
        //  If the caller is capturing this output, emit to the
        //  current target instead and skip most positioning logic
        if (!emit_target_stack.empty())
        {
            //  If capturing to a string, emit to the specified string
            if (emit_target_stack.back() == target_type::string) {
                assert(!emit_string_targets.empty());
                *emit_string_targets.back() += s;
            }

            //  If capturing to a vector of chunks, emit to that
            else {
                assert(!emit_text_chunks_targets.empty());
                emit_text_chunks_targets.back()->insert( emit_text_chunks_targets.back()->begin(), text_with_pos(std::string(s), pos) );
            }

            return;
        }

        //  Otherwise, we'll actually print the string to the output file
        //  and update our curr_pos position

        //  Output the string
        assert (out);
        *out << s;

        //  Update curr_pos by finding how many line breaks s contained,
        //  and where the last one was which determines our current colno
        auto last_newline = std::string::npos;  // the last newline we found in the string
        auto newline_pos  = std::size_t(0);     // the current newline we found in the string
        while ((newline_pos = s.find('\n', newline_pos)) != std::string::npos)
        {
            //  For each line break we find, reset pad and inc current lineno
            pad_for_this_line = 0;
            ++curr_pos.lineno;
            last_newline = newline_pos;
            ++newline_pos;
        }

        //  Now also adjust the colno
        if (last_newline != std::string::npos) {
            //  If we found a newline, it's the distance from the last newline to EOL
            curr_pos.colno = s.length() - last_newline;
        }
        else {
            //  Else add the length of the string
            curr_pos.colno += s.length();
        }
    }


    //-----------------------------------------------------------------------
    //  Internal helpers

    //  Start a new line if we're not in col 1 already
    //
    auto ensure_at_start_of_new_line() -> void
    {
        if (curr_pos.colno > 1) {
            auto old_pos = curr_pos;
            print( "\n" );
            assert(curr_pos.lineno == old_pos.lineno+1);
            assert(curr_pos.colno == 1);
        }
    }

    //  Print a #line directive
    //
    auto print_line_directive( lineno_t line ) -> void
    {
        prev_line_info = { curr_pos.lineno, { } };
        ensure_at_start_of_new_line();

        //  Not using print() here because this is transparent to the curr_pos
        if (!flag_clean_cpp1) {
            assert (out);
            *out << "#line " << line << " " << std::quoted(cpp2_filename) << "\n";
        }
    }

    //  Catch up with comment/blank lines
    //
    auto flush_comments( source_position pos ) -> void
    {
        if (!pcomments) {
            return;
        }

        //  For convenience
        auto& comments = *pcomments;

        //  Don't emit comments while in the first declarations-only pass
        if (declarations_only) {
            return;
        }

        //  Add unprinted comments and blank lines as needed to catch up vertically
        //
        while (curr_pos.lineno < pos.lineno)
        {
            //  If a comment goes on this line, print it
            assert( next_comment >= std::ssize(comments) || comments[next_comment].start.lineno >= curr_pos.lineno );
            if (next_comment < std::ssize(comments) && comments[next_comment].start.lineno == curr_pos.lineno)
            {
                //  For a line comment, start it at the right indentation and print it
                //  with a newline end
                if (comments[next_comment].kind == comment::comment_kind::line_comment) {
                    print( pad( comments[next_comment].start.colno - curr_pos.colno + 1 ) );
                    print( comments[next_comment].text );
                    assert( comments[next_comment].text.find("\n") == std::string::npos );  // we shouldn't have newlines
                    print("\n");
                }

                //  For a stream comment, pad out to its column (if we haven't passed it already)
                //  and emit it there
                else {
                    print( pad( comments[next_comment].start.colno - curr_pos.colno ) );
                    print( comments[next_comment].text );
                    assert(curr_pos.lineno <= pos.lineno);  // we shouldn't have overshot
                }

                ++next_comment;
            }

            //  Otherwise, just print a blank line
            else {
                print("\n");
            }
        }
    }

    //  Position ourselves as close to pos as possible,
    //  and catch up with displaying comments
    //
    auto align_to( source_position pos ) -> void
    {
        //  Ignoring this logic is used when we're generating new code sections,
        //  such as return value structs
        if (ignore_align) {
            print( pad( ignore_align_indent - curr_pos.colno ) );
            return;
        }

        //  Otherwise, we need to apply our usual alignment logic

        //  Catch up with displaying comments
        flush_comments( pos );

        //  If we're not on the right line, move forward one line
        if (curr_pos.lineno < pos.lineno) {
            ensure_at_start_of_new_line();
            assert (curr_pos.lineno <= pos.lineno);
            curr_pos.lineno = pos.lineno;   // re-sync
        }

        //  Finally, align to the target column
        if (curr_pos.lineno == pos.lineno) {
            pos.colno = std::max( 1, pos.colno + pad_for_this_line );
            print( pad( pos.colno - curr_pos.colno ) );
        }
    }


public:
    //-----------------------------------------------------------------------
    //  Destructor
    //
    ~positional_printer() {
        flush_comments( {curr_pos.lineno+1, 1} );

        if (is_open() && source_has_cpp2) {
            //  Always make sure the last line ends with a newline
            //  (not really necessary but makes some tools quieter)
            //  -- but only if there's any Cpp2, otherwise don't
            //  because passing through all-Cpp1 code should always
            //  remain diff-identical
            print_extra("\n");
        }
    }

    //-----------------------------------------------------------------------
    //  Open
    //
    auto open(
        std::string                 cpp2_filename_,
        std::string                 cpp1_filename_,
        std::vector<comment> const& comments,
        bool                        has_cpp2
    )
        -> void
    {
        source_has_cpp2 = has_cpp2;
        cpp2_filename = cpp2_filename_;
        assert (!is_open() && !pcomments && "ICE: tried to call .open twice");
        cpp1_filename = cpp1_filename_;
        if (cpp1_filename == "stdout") {
            out = &std::cout;
        }
        else {
            out_file.open(cpp1_filename);
            out = &out_file;
        }
        pcomments = &comments;
    }

    auto reopen() -> void
    {
        assert (is_open() && "ICE: tried to call .reopen without first calling .open");
        assert(cpp1_filename.ends_with(".h"));
        out_file.close();
        out_file.open(cpp1_filename + "pp");
    }

    auto is_open() -> bool {
        if (out) {
            assert (pcomments && "ICE: if is_open, pcomments should also be set");
        }
        return out;
    }


    //-----------------------------------------------------------------------
    //  Abandon: close and delete
    //
    auto abandon() -> void
    {
        if (!is_open()) {
            return;
        }
        if (out_file.is_open()) {
            out_file.close();
            std::remove(cpp1_filename.c_str());
        }
    }


    //-----------------------------------------------------------------------
    //  Print extra text and don't track positions
    //  Used for Cpp2 boundary comment and prelude and final newline
    //
    auto print_extra( std::string_view s ) -> void
    {
        assert (is_open() && "ICE: printer must be open before printing");
        print( s );
    }


    //-----------------------------------------------------------------------
    //  Print a Cpp1 line, which should be at lineno
    //
    auto print_cpp1( std::string_view s, lineno_t line ) -> void
    {
        assert (is_open() && "ICE: printer must be open before printing");

        //  Keep track of whether the last thing we printed was Cpp2
        last_was_cpp2 = false;

        //  Always start a Cpp1 line on its own new line
        ensure_at_start_of_new_line();

        //  If we are out of sync with the current logical line number,
        //  emit a #line directive to re-sync
        if (curr_pos.lineno != line) {
            print_line_directive( line );
            curr_pos.lineno = line;
        }

        //  Print the line
        assert (curr_pos.colno == 1);
        print( s );
        print( "\n" );
    }


    //-----------------------------------------------------------------------
    //  Start a new Cpp2 section, which should start at lineno
    //
    auto start_cpp2(lineno_t line) -> void
    {
        assert (is_open() && "ICE: printer must be open before printing");

        //  Because the blank/comment lines before a Cpp2 code section are part
        //  of the Cpp2 section, and not printed in thedeclarations-only pass
        if (!last_was_cpp2 && declarations_only) {
            print ("\n");
        }

        //  Keep track of whether the last thing we printed was Cpp2
        last_was_cpp2 = true;

        //  Always start a Cpp2 section on its own new line
        ensure_at_start_of_new_line();

        //  If we are out of sync with the current logical line number,
        //  emit a #line directive to re-sync
        if (curr_pos.lineno != line) {
            print_line_directive( line );
            curr_pos.lineno = line;
        }

        assert (curr_pos.colno == 1);
    }


    //-----------------------------------------------------------------------
    //  Print a Cpp2 item, which should be at pos
    //
    auto print_cpp2(std::string_view s, source_position pos) -> void
    {
        assert (is_open() && "ICE: printer must be open before printing");

        //  Keep track of whether the last thing we printed was Cpp2
        //  Note: We should have been switched to Cpp2 with a `start_cpp2` call
        assert(last_was_cpp2 && "ICE: didn't call start_cpp2 to begin a Cpp2 section");
        last_was_cpp2 = true;

        //  Skip alignment work if we're capturing emitted text
        if (emit_target_stack.empty())
        {
            //  Remember where we are
            auto last_pos = curr_pos;

            //  We may want to adjust the position based on (1) a position preemption request
            //  or else (2) to repeat a similar adjustment we discovered on the previous line
            auto adjusted_pos = pos;

            //  (1) See if there's a position preemption request, if so use it up
            //      For now, the preempt position use cases are about overriding colno
            //      and only on the same line. In the future, we might have more use cases.
            if (!preempt_pos.empty()) {
                if (preempt_pos.back().lineno == pos.lineno) {
                    adjusted_pos.colno = preempt_pos.back().colno;
                }
            }

            //  (2) Otherwise, see if there's a previous line's offset to repeat
            //      If we moved to a new line, then this is the first
            //      non-comment non-whitespace text on the new line
            else if (last_pos.lineno == pos.lineno-1 && enable_indent_heuristic) {
                //  If the last line had a request for this colno, remember its actual offset
                constexpr int sentinel = -100;
                auto last_line_offset = sentinel;
                for(auto i = 0;
                    i < std::ssize(prev_line_info.requests) && prev_line_info.requests[i].requested <= pos.colno;
                    ++i
                    )
                {
                    if (prev_line_info.requests[i].requested == pos.colno) {
                        last_line_offset = prev_line_info.requests[i].offset;
                        break;
                    }
                }

                //  If there was one, apply the actual column number offset
                if (last_line_offset > sentinel) {
                    adjusted_pos.colno += last_line_offset;
                }
            }
            enable_indent_heuristic = true;

            //  If we're changing lines, start accumulating this new line's request/actual adjustment info
            if (last_pos.lineno < adjusted_pos.lineno) {
                prev_line_info = { curr_pos.lineno, { } };
            }

            align_to(adjusted_pos);

            //  Remember the requested and actual offset columns for this item
            prev_line_info.requests.push_back( req_act_info( pos.colno /*requested*/ , curr_pos.colno /*actual*/ - pos.colno ) );
        }

        print(s, pos);
    }


    //-----------------------------------------------------------------------
    //  Position override control functions
    //

    //  Use this position instead of the next supplied one
    //  Useful when Cpp1 syntax is emitted in a different order/verbosity
    //  than Cpp2 such as with declarations
    //
    auto preempt_position_push(source_position pos) -> void
    {
        preempt_pos.push_back( pos );
    }

    auto preempt_position_pop() -> void
    {
        assert(!preempt_pos.empty());
        preempt_pos.pop_back();
    }

    //  Add (or, if negative, subtract) padding for the current line only
    //
    auto add_pad_in_this_line(colno_t extra) -> void
    {
        pad_for_this_line += extra;
    }

    //  Enable indent heuristic for just this line
    //
    auto disable_indent_heuristic_for_next_text() -> void {
        enable_indent_heuristic = false;
    }

    //  Ignore position information, usually when emitting generated code
    //  such as generated multi-return type structs
    //
    auto ignore_alignment(bool ignore, int indent = 0) -> void
    {
        //  We'll only ever call this in local non-nested true/false pairs.
        //  If we ever want to generalize (support nesting, or make it non-brittle),
        //  wrap this in a push/pop stack.
        if (ignore) {
            ignore_align        = true;
            ignore_align_indent = indent;
            ignore_align_lineno = curr_pos.lineno;      // push state
        }
        else {
            ignore_align        = false;
            ignore_align_indent = 0;
            if (ignore_align_lineno != curr_pos.lineno) {
                ensure_at_start_of_new_line();
                print_line_directive(ignore_align_lineno+1);
            }
            curr_pos.lineno     = ignore_align_lineno+1;  // pop state
        }
    }


    //-----------------------------------------------------------------------
    //  Modal state control functions
    //

    //  In the first pass we will print only declarations (the default)
    //  For the second pass this function enables printing definitions
    //
    auto enable_definitions() -> void {
        declarations_only = false;
    }

    auto doing_declarations_only() const -> bool {
        return declarations_only;
    }

    //  Provide an option to store to a given string instead, which is
    //  useful for capturing Cpp1-formatted output for generated code
    //
    auto emit_to_string( std::string* target = {} ) -> void {
        if (target) {
            emit_string_targets.push_back( target );
            emit_target_stack.push_back(target_type::string);
        }
        else {
            emit_string_targets.pop_back();
            emit_target_stack.pop_back();
        }
    }

    //  Provide an option to store to a vector<text_with_pos>, which is
    //  useful for postfix expression which have to mix unwrapping operators
    //  with emitting sub-elements such as expression lists
    //
    auto emit_to_text_chunks( std::vector<text_with_pos>* target = {} ) -> void {
        if (target) {
            emit_text_chunks_targets.push_back( target );
            emit_target_stack.push_back(target_type::chunks);
        }
        else {
            emit_text_chunks_targets.pop_back();
            emit_target_stack.pop_back();
        }
    }

};


//-----------------------------------------------------------------------
//
//  cppfront: a compiler instance
//
//-----------------------------------------------------------------------
//
class cppfront
{
    std::string sourcefile;
    std::vector<error> errors;

    //  For building
    //
    cpp2::source source;
    cpp2::tokens tokens;
    cpp2::parser parser;
    cpp2::sema   sema;

    bool source_loaded                  = true;
    bool last_postfix_expr_was_pointer  = false;
    bool violates_bounds_safety         = false;
    bool violates_initialization_safety = false;
    bool suppress_move_from_last_use    = false;

    struct arg_info {
        passing_style pass   = passing_style::in;
        token const*  ptoken = {};
    };
    std::vector<arg_info> current_args  = { {} };

    //  For lowering
    //
    positional_printer printer;
    bool               in_definite_init  = false;
    bool               in_parameter_list = false;

    std::string                                   function_return_name;
    std::vector<parameter_declaration_list_node*> function_returns;
    parameter_declaration_list_node               single_anon;
        //  special value - hack for now to note single-anon-return type kind in this function_returns working list
    std::vector<std::string>                      function_requires_conditions;

    struct iter_info {
        iteration_statement_node const* stmt;
        bool used = false;
    };
    std::vector<iter_info> iteration_statements;

    std::vector<bool>                             in_non_rvalue_context   = { false };
    std::vector<bool>                             need_expression_list_parens = { true };
    auto push_need_expression_list_parens( bool b ) -> void { need_expression_list_parens.push_back(b);            }
    auto pop_need_expression_list_parens()          -> void { assert(std::ssize(need_expression_list_parens) > 1);
                                                              need_expression_list_parens.pop_back();              }
    auto should_add_expression_list_parens()        -> bool { assert(!need_expression_list_parens.empty());
                                                              return need_expression_list_parens.back();           }
    auto consumed_expression_list_parens()          -> void { if( std::ssize(need_expression_list_parens) > 1 )
                                                                  need_expression_list_parens.back() = false;      }

public:
    //-----------------------------------------------------------------------
    //  Constructor
    //
    //  filename    the source file to be processed
    //
    cppfront(std::string const& filename)
        : sourcefile{ filename }
        , source{ errors }
        , tokens{ errors }
        , parser{ errors }
        , sema{ errors }
    {
        //  "Constraints enable creativity in the right directions"
        //  sort of applies here
        //
        if (!sourcefile.ends_with(".cpp2") && !sourcefile.ends_with(".h2"))
        {
            errors.emplace_back(
                source_position(-1, -1),
                "source filename must end with .cpp2 or .h2: " + sourcefile
            );
        }

        //  Load the program file into memory
        //
        else if (!source.load(sourcefile))
        {
            if (errors.empty()) {
                errors.emplace_back(
                    source_position(-1, -1),
                    "file not found: " + sourcefile
                );
            }
            source_loaded = false;
        }

        else
        {
            //  Tokenize
            //
            tokens.lex(source.get_lines());

            //  Parse
            //
            try
            {
                for (auto const& [line, entry] : tokens.get_map()) {
                    if (!parser.parse(entry, tokens.get_generated())) {
                        errors.emplace_back(
                            source_position(line, 0),
                            "parse failed for section starting here"
                        );
                    }
                }

                //  Sema
                parser.visit(sema);
                if (!sema.apply_local_rules()) {
                    violates_initialization_safety = true;
                }
            }
            catch (std::runtime_error& e) {
                errors.emplace_back(
                    source_position(-1, -1),
                    e.what()
                );
            }
        }
    }


    //-----------------------------------------------------------------------
    //  lower_to_cpp1
    //
    //  Emits the target file with the last '2' stripped
    //
    struct lower_to_cpp1_ret {
        lineno_t cpp1_lines = 0;
        lineno_t cpp2_lines = 0;
    };
    auto lower_to_cpp1() -> lower_to_cpp1_ret
    {
        auto ret = lower_to_cpp1_ret{};

        //  Only lower to Cpp1 if we haven't already encountered errors
        if (!errors.empty()) {
            return {};
        }

        //  Now we'll open the Cpp1 file
        auto cpp1_filename = sourcefile.substr(0, std::ssize(sourcefile) - 1);
        if (!flag_cpp1_filename.empty()) {
            cpp1_filename = flag_cpp1_filename; // use override if present
        }

        printer.open(
            sourcefile,
            cpp1_filename,
            tokens.get_comments(),
            source.has_cpp2()
        );
        if (!printer.is_open()) {
            errors.emplace_back(
                source_position{},
                "could not open output file " + cpp1_filename
            );
            return {};
        }

        //  Generate a reasonable macroized name
        auto cpp1_FILENAME = to_upper_and_underbar(cpp1_filename);

        //  Only emit extra lines if we actually have Cpp2, because
        //  we want pure-Cpp1 files to pass through with zero changes
        if (source.has_cpp2())
        {
            if (cpp1_filename.back() == 'h') {
                printer.print_extra( "\n#ifndef " + cpp1_FILENAME+"__CPP2");
                printer.print_extra( "\n#define " + cpp1_FILENAME+"__CPP2" + "\n\n" );
            }

            if (!flag_clean_cpp1) {
                printer.print_extra( "// ----- Cpp2 support -----\n" );
            }
            if (flag_use_source_location) {
                printer.print_extra( "#define CPP2_USE_SOURCE_LOCATION Yes\n" );
            }
            if (flag_cpp2_only) {
                printer.print_extra( "#define CPP2_USE_MODULES         Yes\n" );
            }
            if (flag_no_exceptions) {
                printer.print_extra( "#define CPP2_NO_EXCEPTIONS       Yes\n" );
            }
            if (flag_no_rtti) {
                printer.print_extra( "#define CPP2_NO_RTTI             Yes\n" );
            }
            printer.print_extra( "#include \"cpp2util.h\"\n\n" );
        }

        auto map_iter = tokens.get_map().cbegin();
        auto hpp_includes = std::string{};

        //  First, echo the non-Cpp2 parts
        //
        for (
            lineno_t curr_lineno = 0;
            auto const& line : source.get_lines()
            )
        {
            //  Skip dummy line we added to make 0-vs-1-based offsets readable
            if (curr_lineno != 0)
            {
                //  If it's a Cpp1 line, emit it
                if (line.cat != source_line::category::cpp2)
                {
                    ++ret.cpp1_lines;

                    if (flag_cpp2_only &&
                        !line.text.empty() &&
                        line.cat != source_line::category::comment &&
                        line.cat != source_line::category::import
                        )
                    {
                        if (line.cat == source_line::category::preprocessor) {
                            if (!line.text.ends_with(".h2\"")) {
                                errors.emplace_back(
                                    source_position(curr_lineno, 1),
                                    "pure-cpp2 switch disables the preprocessor, including #include (except of .h2 files) - use import instead (note: 'import std;' is implicit in -pure-cpp2)"
                                );
                                return {};
                            }
                        }
                        else {
                            errors.emplace_back(
                                source_position(curr_lineno, 1),
                                "pure-cpp2 switch disables Cpp1 syntax"
                            );
                            return {};
                        }
                    }

                    if (line.cat == source_line::category::preprocessor && line.text.ends_with(".h2\"")) {
                        //  Strip off the 2"
                        auto h_include = line.text.substr(0, line.text.size()-2);
                        printer.print_cpp1( h_include + "\"", curr_lineno );
                        hpp_includes += h_include + "pp\"\n";
                    }
                    else {
                        printer.print_cpp1( line.text, curr_lineno );
                    }
                }

                //  If it's a Cpp2 line...
                else {
                    ++ret.cpp2_lines;

                    //  We should be in a position to emit a set of Cpp2 declarations
                    if (map_iter != tokens.get_map().cend() && map_iter->first /*line*/ <= curr_lineno)
                    {
                        //  We should be here only when we're at exactly the first line of a Cpp2 section
                        assert (map_iter->first == curr_lineno);
                        assert (!map_iter->second.empty());

                        //  Get the parse tree for this section and emit each forward declaration
                        auto decls = parser.get_parse_tree(map_iter->second);
                        for (auto& decl : decls) {
                            assert(decl);

                            //  Treat each declaration as the start of a Cpp2 section (so we get #line)
                            printer.start_cpp2( decl->position().lineno );
                            emit(*decl);
                        }
                        ++map_iter;
                    }
                }
            }
            ++curr_lineno;
        }

        //  We can stop here if there's no Cpp2 code -- a file with no Cpp2
        //  should have perfect passthrough verifiable with diff, including
        //  that we didn't misidentify anything as Cpp2 (even in the
        //  presence of nonstandard vendor extensions)
        //
        if (!source.has_cpp2()) {
            assert(ret.cpp2_lines == 0);
            return ret;
        }

        //  If there is Cpp2 code, we have more to do...

        //  First, if this is a .h2 we need to switch filenames
        if (cpp1_filename.back() == 'h')
        {
            printer.print_extra( "\n#endif\n" );

            printer.reopen();
            if (!printer.is_open()) {
                errors.emplace_back(
                    source_position{},
                    "could not open second output file " + cpp1_filename
                );
                return {};
            }

            printer.print_extra( "\n#ifndef " + cpp1_FILENAME+"__CPP2" );
            printer.print_extra( "\n#error To use this file, write '#include \"" + cpp1_filename + "2\"' in a '.cpp2' file (this intermediate file is not intended to be compiled on its own)"  );
            printer.print_extra( "\n#endif\n" );

            cpp1_FILENAME += "PP";
            printer.print_extra( "\n#ifndef " + cpp1_FILENAME+"__CPP2" );
            printer.print_extra( "\n#define " + cpp1_FILENAME+"__CPP2" + "\n\n" );
        }

        //  Next, bring in the Cpp2 helpers
        //
        if (!flag_clean_cpp1) {
            printer.print_extra( "\n//=== Cpp2 definitions ==========================================================\n\n" );
        }

        //  Next, emit the Cpp2 definitions
        //
        printer.print_extra( hpp_includes );

        printer.enable_definitions();

        for (auto& section : tokens.get_map())
        {
            assert (!section.second.empty());

            //  Tell the printer that we're starting a Cpp2 section
            //  This time, we use the actual first start line of the section which includes
            //  the blank/comment lines at the beginning if any (whereas in the first pass
            //  we used the line of the first Cpp2 token in the section to skip blanks/comments)
            printer.start_cpp2( section.first /*lineno*/);

            //  Get the parse tree for this section and emit each forward declaration
            auto decls = parser.get_parse_tree(section.second);
            for (auto& decl : decls) {
                assert(decl);
                emit(*decl);
            }
        }

        if (cpp1_filename.back() == 'h') {
            printer.print_extra( "\n#endif" );
        }

        return ret;
    }


    //-----------------------------------------------------------------------
    //
    //  emit() functions - each emits a kind of node
    //
    //  The body often mirrors the node's visit() function, unless customization
    //  is needed where Cpp1 and Cpp2 have different grammar orders
    //

    auto print_to_string(auto& i, auto... more) -> std::string {
        auto print = std::string{};
        printer.emit_to_string(&print);
        emit(i, more...);
        printer.emit_to_string();
        return print;
    };

    //-----------------------------------------------------------------------
    //  try_emit
    //
    //  Helper to emit whatever is in a variant where each
    //  alternative is a smart pointer
    //
    template <int I>
    auto try_emit(auto& v, auto... more) -> void {
        if (v.index() == I) {
            auto const& alt = std::get<I>(v);
            assert (alt);
            emit (*alt, more...);
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(token const& n, bool is_qualified = false, source_position pos = {}) -> void
    {
        if (pos == source_position{}) {
            pos = n.position();
        }

        //  Implicit "cpp2::" qualification of Cpp2 fixed-width type aliases
        if (!is_qualified && n.type() == lexeme::Cpp2FixedType)
        {
            printer.print_cpp2("cpp2::", pos);
        }

        if (n == "new") {
            printer.print_cpp2("cpp2_new", pos);
        }
        else {
            printer.print_cpp2(n, pos);
        }

        in_definite_init = is_definite_initialization(&n);
    }


    //-----------------------------------------------------------------------
    //
    auto emit(
        unqualified_id_node const& n,
        bool in_synthesized_multi_return = false,
        bool is_local_name = true,
        bool is_qualified = false
    )
        -> void
    {
        auto last_use = is_definite_last_use(n.identifier);

        bool add_forward =
            last_use && last_use->is_forward &&
            !in_non_rvalue_context.back();

        bool add_move =
            !add_forward &&
            (in_synthesized_multi_return || (last_use && !suppress_move_from_last_use)) &&
            !in_non_rvalue_context.back();

        //  For an explicit 'forward' apply forwarding to correct identifier
        assert (!current_args.empty());
        if (current_args.back().pass == passing_style::forward) {
            add_forward = current_args.back().ptoken == n.identifier;
        }

        if (add_move) {
            printer.print_cpp2("std::move(", n.position());
        }
        if (add_forward) {
            printer.print_cpp2("CPP2_FORWARD(", {n.position().lineno, n.position().colno - 8});
        }

        assert(n.identifier);
        emit(*n.identifier, is_qualified);  // inform the identifier if we know this is qualified

        if (!n.template_args.empty()) {
            printer.print_cpp2("<", n.open_angle);
            auto first = true;
            for (auto& a : n.template_args) {
                if (!first) {
                    printer.print_cpp2(",", a.comma);
                }
                first = false;
                try_emit<unqualified_id_node::expression>(a.arg);
                try_emit<unqualified_id_node::type_id   >(a.arg);
            }
            printer.print_cpp2(">", n.close_angle);
        }

        in_definite_init = is_definite_initialization(n.identifier);
        if (!in_definite_init && !in_parameter_list) {
            if (auto decl = sema.get_declaration_of(*n.identifier);
                is_local_name &&
                decl &&
                //  note pointer equality: if we're not in the actual declaration of n.identifier
                (in_synthesized_multi_return || decl->identifier != n.identifier) &&
                //  and this variable was uninitialized
                !decl->initializer &&
                //  and it's either a non-parameter or an out parameter
                (!decl->parameter || (decl->parameter && decl->parameter->pass == passing_style::out))
                )
            {
                printer.print_cpp2(".value()", n.position());
            }
        }
        else if (in_synthesized_multi_return) {
            printer.print_cpp2(".value()", n.position());
        }

        if (add_move || add_forward) {
            printer.print_cpp2(")", n.position());
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(qualified_id_node const& n) -> void
    {
        //  Implicit "cpp2::" qualification of "unique.new" and "shared.new"
        if (n.ids.size() == 2 &&
            (*n.ids[0].id->identifier == "unique" || *n.ids[0].id->identifier == "shared") &&
            *n.ids[1].scope_op == "." &&
            *n.ids[1].id->identifier == "new"
            )
        {
            printer.print_cpp2("cpp2::", n.position());
        }

        auto ident = std::string{};
        printer.emit_to_string(&ident);

        for (auto const& id : n.ids)
        {
            if (id.scope_op) {
                emit(*id.scope_op);
            }
            emit(*id.id, false, true, true);    // inform the unqualified-id that it's qualified
        }

        printer.emit_to_string();
        printer.print_cpp2( ident, n.position() );
    }


    //-----------------------------------------------------------------------
    //
    auto emit(type_id_node const& n, source_position pos = {}) -> void
    {
        if (pos == source_position{}) {
            pos = n.position();
        }

        if (n.is_wildcard()) {
            printer.print_cpp2("auto", pos);
        }
        else {
            try_emit<type_id_node::unqualified>(n.id, false, false);
            try_emit<type_id_node::qualified  >(n.id);
            try_emit<type_id_node::keyword    >(n.id);
        }

        for (auto i = n.pc_qualifiers.rbegin(); i != n.pc_qualifiers.rend(); ++i) {
            if ((**i) == "const") { printer.print_cpp2(" ", pos); }
            emit(**i, false, pos);
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(id_expression_node const& n, bool is_local_name = true) -> void
    {
        try_emit<id_expression_node::qualified  >(n.id);
        try_emit<id_expression_node::unqualified>(n.id, false, is_local_name);
    }


    //-----------------------------------------------------------------------
    //
    auto emit(
        compound_statement_node  const&  n,
        std::vector<std::string> const& function_prolog = {},
        std::vector<std::string> const& function_epilog = {},
        colno_t                         function_indent = 1
    )
        -> void
    {
        auto pos = n.open_brace;
        pos.lineno -= std::ssize(function_prolog);
        printer.print_cpp2( "{", pos );

        if (!function_prolog.empty()) {
            printer.ignore_alignment( true, function_indent + 4 );
            auto pos = source_position{};
            if (!n.statements.empty()) {
                pos = n.statements.front()->position();
            }
            for (auto& loc : function_prolog) {
                printer.print_cpp2("\n", pos);
                printer.print_cpp2(loc, pos);
            }
            printer.ignore_alignment( false );
        }

        for (auto const& x : n.statements) {
            assert(x);
            emit(*x);
        }

        if (!function_epilog.empty()) {
            printer.ignore_alignment( true, function_indent + 4 );
            auto pos = source_position{};
            if (!n.statements.empty()) {
                pos = n.statements.front()->position();
            }
            for (auto& loc : function_epilog) {
                printer.print_cpp2("\n", pos);
                printer.print_cpp2(loc, pos);
            }
            printer.ignore_alignment( false );
        }

        printer.print_cpp2( "}", n.close_brace );
    }


    //-----------------------------------------------------------------------
    //
    auto emit(inspect_expression_node const& n, bool is_expression) -> void
    {
        auto constexpr_qualifier = std::string{};
        if (n.is_constexpr) {
            constexpr_qualifier = "constexpr ";
        }

        //  If this is an expression, it will have an explicit result type,
        //  and we need to start the lambda that we'll immediately invoke
        auto result_type = std::string{};
        if (is_expression) {
            assert(n.result_type);
            printer.emit_to_string(&result_type);
            emit(*n.result_type);
            printer.emit_to_string();
            printer.print_cpp2("[&] () -> " + result_type + " ", n.position());
        }
        printer.print_cpp2("{ " + constexpr_qualifier + "auto&& __expr = ", n.position());

        assert(n.expression);
        emit(*n.expression);
        printer.print_cpp2(";", n.position());

        assert(n.identifier && *n.identifier == "inspect");

        assert(!n.alternatives.empty());
        auto found_wildcard = false;

        for (auto first = true; auto&& alt : n.alternatives)
        {
            assert(alt && alt->is_as_keyword);
            if (!first) {
                printer.print_cpp2("else ", alt->position());
            }
            first = false;

            auto id = std::string{};
            printer.emit_to_string(&id);

            if (alt->type_id) {
                emit(*alt->type_id);
            }
            else {
                assert(alt->value);
                emit(*alt->value);
            }
            printer.emit_to_string();

            assert (*alt->is_as_keyword == "is" || *alt->is_as_keyword == "as");
            // TODO: pick up 'as' next, for now just do 'is'

            if (*alt->is_as_keyword == "is")
            {
                //  Stringize the expression-statement now...
                auto statement = std::string{};
                printer.emit_to_string(&statement);
                emit(*alt->statement);
                printer.emit_to_string();
                //  ... and jettison the final ; for an expression-statement
                while (!statement.empty() && (statement.back() == ';' || isspace(statement.back()))) {
                    statement.pop_back();
                }

                replace_all( statement, "cpp2::as_<", "cpp2::as<" );

                //  If this is an inspect-expression, we'll have to wrap each alternative
                //  in an 'if constexpr' so that its type is ignored for mismatches with
                //  the inspect-expression's type
                auto return_prefix = std::string{};
                auto return_suffix = std::string{";"};   // use this to tack the ; back on in the alternative body
                if (is_expression) {
                    return_prefix = "{ if constexpr( requires{" + statement + ";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF((" + statement + "))," + result_type + "> ) return ";
                    return_suffix += " }";
                }

                if (id == "auto") {
                    found_wildcard = true;
                    if (is_expression) {
                        printer.print_cpp2("return ", alt->position());
                    }
                }
                else {
                    printer.print_cpp2("if " + constexpr_qualifier, alt->position());
                    if (alt->type_id) {
                        printer.print_cpp2("(cpp2::is<" + id + ">(__expr)) ", alt->position());
                    }
                    else {
                        assert (alt->value);
                        printer.print_cpp2("(cpp2::is(__expr, " + id + ")) ", alt->position());
                    }
                    printer.print_cpp2(return_prefix, alt->position());
                }

                printer.print_cpp2(statement, alt->position());

                if (is_expression && id != "auto") {
                    assert(alt->statement->statement.index() == statement_node::expression);
                    printer.print_cpp2("; else return " + result_type + "{}", alt->position());
                    printer.print_cpp2("; else return " + result_type + "{}", alt->position());
                }

                printer.print_cpp2(return_suffix, alt->position());
            }
            else {
                errors.emplace_back(
                    alt->position(),
                    "(temporary alpha limitation) cppfront is still learning 'inspect' - only simple 'is' alternatives are currently supported"
                );
                return;
            }
        }

        if (is_expression) {
            if (!found_wildcard) {
                errors.emplace_back(
                    n.position(),
                    "an inspect expression must have an `is _` match-anything wildcard alternative"
                );
                return;
            }
        }
        else {
            printer.print_cpp2("}", n.close_brace);
        }

        //  If this is an expression, finally actually invoke the lambda
        if (is_expression) {
            printer.print_cpp2("()", n.close_brace);
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(selection_statement_node const& n) -> void
    {
        assert(n.identifier);
        emit(*n.identifier);

        printer.print_cpp2(" (", n.position());
        printer.add_pad_in_this_line(1);

        assert(n.expression);
        emit(*n.expression);

        printer.print_cpp2(") ", n.position());
        printer.add_pad_in_this_line(1);

        assert(n.true_branch);
        emit(*n.true_branch);

        if (n.has_source_false_branch) {
            printer.print_cpp2("else ", n.else_pos);
            emit(*n.false_branch);
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(iteration_statement_node const& n) -> void
    {
        assert(n.identifier);
        in_non_rvalue_context.push_back(true);

        iteration_statements.push_back({ &n, false});
        auto labelname = labelized_position(n.label);

        //  Handle while
        //
        if (*n.identifier == "while") {
            assert(n.condition && n.statement && !n.range && !n.body);

            //  We emit Cpp2 while loops as Cpp2 for loops if there's a "next" clause
            if (!n.next_expression) {
                printer.print_cpp2("while( ", n.position());
                emit(*n.condition);
            }
            else {
                printer.print_cpp2("for( ; ", n.position());
                emit(*n.condition);
                printer.print_cpp2("; ", n.position());
                printer.add_pad_in_this_line(-10);
                emit(*n.next_expression);
            }
            printer.print_cpp2(" ) ", n.position());
            if (!labelname.empty()) {
                printer.print_extra("{");
            }
            emit(*n.statement);
            if (!labelname.empty()) {
                printer.print_extra(" CPP2_CONTINUE_BREAK("+labelname+") }");
            }

            in_non_rvalue_context.pop_back();
        }

        //  Handle do
        //
        else if (*n.identifier == "do") {
            assert(n.condition && n.statement && !n.range && !n.body);

            printer.print_cpp2("do ", n.position());
            if (!labelname.empty()) {
                printer.print_extra("{");
            }
            emit(*n.statement);
            if (!labelname.empty()) {
                printer.print_extra(" CPP2_CONTINUE_BREAK("+labelname+") }");
            }
            printer.print_cpp2(" while ( ", n.position());
            emit(*n.condition);
            if (n.next_expression) {
                //  Gotta say, this feels kind of nifty... short-circuit eval
                //  and smuggling work into a condition via a lambda, O my...
                printer.print_cpp2(" && [&]{ ", n.position());
                emit(*n.next_expression);
                printer.print_cpp2(" ; return true; }() ", n.position());
            }
            printer.print_cpp2(");", n.position());

            in_non_rvalue_context.pop_back();
        }

        //  Handle for
        //
        else if (*n.identifier == "for") {
            assert(!n.condition && !n.statement && n.range && n.body);

            printer.print_cpp2("for ( auto&& cpp2_range = ", n.position());
            if (n.for_with_in) {
                printer.print_cpp2("std::as_const(", n.position());
            }
            emit(*n.range);
            if (n.for_with_in) {
                printer.print_cpp2(")", n.position());
            }
            printer.print_cpp2(";  ", n.position());
            emit(*n.get_for_parameter());
            printer.print_cpp2(" : cpp2_range ) ", n.position());
            if (!labelname.empty()) {
                printer.print_extra("{");
            }

            //  If there's a next-expression, smuggle it in via a nested do/while(false) loop
            //  (nested "continue" will work, but "break" won't until we do extra work to implement
            //  that using a flag and implementing "break" as "__for_break = true; continue;")
            if (n.next_expression) {
                printer.print_cpp2(" { do ", n.position());
            }

            assert(n.body->initializer);
            emit(*n.body->initializer);

            if (n.next_expression) {
                printer.print_cpp2(" while (false); ", n.position());
                emit(*n.next_expression);
                printer.print_cpp2("; }", n.position());
            }

            printer.print_cpp2("", n.position());
            if (!labelname.empty()) {
                printer.print_extra(" CPP2_CONTINUE_BREAK("+labelname+") }");
            }

            in_non_rvalue_context.pop_back();
        }

        else {
            assert(!"ICE: unexpected case");
        }

        assert (iteration_statements.back().stmt);
        if (iteration_statements.back().stmt->label && !iteration_statements.back().used) {
            auto name = iteration_statements.back().stmt->label->to_string(true);
            errors.emplace_back(
                iteration_statements.back().stmt->position(),
                name + ": a named loop must have its name used (did you forget 'break " + name + ";' or 'continue " + name + "';?)"
            );
        }

        iteration_statements.pop_back();
    }


    //-----------------------------------------------------------------------
    //
    auto emit(return_statement_node const& n) -> void
    {
        assert(n.identifier);
        assert(*n.identifier == "return");
        printer.print_cpp2("return ", n.position());

        //  Return with expression == single anonymous return type
        //
        if (n.expression) {
            emit(*n.expression);
            if (function_returns.empty() || function_returns.back() != &single_anon) {
                errors.emplace_back(
                    n.position(),
                    "return statement with expression must be in a function with a single anonymous return value"
                );
                return;
            }
        }

        else if (!function_returns.empty() && function_returns.back() == &single_anon) {
            errors.emplace_back(
                n.position(),
                "return statement must have an expression in a function with a single anonymous return value"
            );
        }

        //  Return without expression == zero or named return values
        //
        else if (!function_returns.empty() && function_returns.back()) {
            //auto stmt = function_return_name + " { "; // we shouldn't need this with { } init
            auto stmt = std::string(" { ");
            auto& parameters = function_returns.back()->parameters;
            for (bool first = true; auto& param : parameters) {
                if (!first) {
                    stmt += ", ";
                }
                first = false;
                assert(param->declaration->identifier);

                printer.emit_to_string(&stmt);
                emit(*param->declaration->identifier, true);
                printer.emit_to_string();
            }
            stmt += " }";
            printer.print_cpp2(stmt, n.position());
        }

        printer.print_cpp2("; ", n.position());
    }


    //-----------------------------------------------------------------------
    //
    auto emit(jump_statement_node const& n) -> void
    {
        assert(n.keyword);

        if (n.label) {
            auto iter_stmt =
                std::find_if(
                    iteration_statements.begin(),
                    iteration_statements.end(),
                    [&](auto& s){
                        assert(s.stmt);
                        return
                            s.stmt->label &&
                            std::string_view{*s.stmt->label} == std::string_view{*n.label};
                    }
                );
            if (iter_stmt == iteration_statements.end())
            {
                errors.emplace_back(
                    n.position(),
                    "a named " + n.keyword->to_string(true) + " must use the name of an enclosing local loop label"
                );
                return;
            }
            iter_stmt->used = true;
            assert((*iter_stmt).stmt->label);
            printer.print_cpp2(
                "goto " + to_upper_and_underbar(*n.keyword) + "_" + labelized_position((*iter_stmt).stmt->label) + ";",
                n.position()
            );
        }
        else {
            emit(*n.keyword);
            printer.print_cpp2(";", n.position());
        }
    }


    //-----------------------------------------------------------------------
    //
    auto build_capture_lambda_intro_for( capture_group& captures, source_position pos ) -> std::string
    {
        //  First calculate the stringized version of each capture expression
        //  This will let us compare and de-duplicate repeated capture expressions
        for (auto& cap : captures.members)
        {
            assert(cap.capture_expr->cap_grp == &captures);
            printer.emit_to_string(&cap.str);
            emit(*cap.capture_expr, true);
            printer.emit_to_string();
        }

        //  Then build the capture list, ignoring duplicated expressions
        auto lambda_intro = std::string("[");
        printer.emit_to_string(&lambda_intro);

        auto num = 0;
        auto handled = std::vector<std::string>{};
        for (auto& cap : captures.members)
        {
            //  If we haven't handled a capture that looks like this one
            if (std::find(handled.begin(), handled.end(), cap.str) == handled.end())
            {
                //  Remember it
                handled.push_back(cap.str);

                //  And handle it
                if (num != 0) { // not first
                    lambda_intro += ", ";
                }
                printer.print_cpp2("_"+std::to_string(num)+" = ", pos);
                emit(*cap.capture_expr, true);
            }
            ++num;
        }
        printer.emit_to_string();
        lambda_intro += "]";

        return lambda_intro;
    }


    //-----------------------------------------------------------------------
    //
    auto emit(primary_expression_node const& n) -> void
    {
        try_emit<primary_expression_node::identifier     >(n.expr);
        try_emit<primary_expression_node::expression_list>(n.expr);
        try_emit<primary_expression_node::id_expression  >(n.expr);
        try_emit<primary_expression_node::inspect        >(n.expr, true);

        if (n.expr.index() == primary_expression_node::declaration)
        {
            //  This must be an anonymous declaration
            auto& decl = std::get<primary_expression_node::declaration>(n.expr);
            assert(decl && !decl->identifier);

            //  Handle an anonymous function
            if (decl->is(declaration_node::function)) {
                auto lambda_intro = build_capture_lambda_intro_for(decl->captures, n.position());
                emit(*decl, lambda_intro);
            }
            //  Else an anonymous object as 'typeid { initializer }'
            else {
                assert(decl->is(declaration_node::object));
                auto& type_id = std::get<declaration_node::object>(decl->type);

                printer.add_pad_in_this_line( -5 );

                emit(*type_id);
                printer.print_cpp2("{", decl->position());

                assert(decl->initializer);
                emit(*decl->initializer, false);

                printer.print_cpp2("}", decl->position());
            }
        }
    }

    // Don't work yet, TODO: finalize deducing pointer types from parameter lists
    auto is_pointer_declaration(parameter_declaration_list_node const*, int, int) -> bool {
        return false;
    }

    auto is_pointer_declaration(declaration_node const* decl_node, int deref_cnt, int addr_cnt) -> bool {
        if (!decl_node) {
            return false;
        }
        if (addr_cnt > deref_cnt) {
            return true;
        }

        return std::visit([&](auto const& type){
            return is_pointer_declaration(type.get(), deref_cnt, addr_cnt);
        }, decl_node->type);
    }

    auto is_pointer_declaration(function_type_node const* fun_node, int deref_cnt, int addr_cnt) -> bool {
        if (!fun_node) { 
            return false;
        }
        if (addr_cnt > deref_cnt) {
            return true;
        }

        return std::visit([&]<typename T>(T const& type){
            if constexpr (std::is_same_v<T, std::monostate>) {
                return false;
            } else {
                return is_pointer_declaration(type.get(),  deref_cnt, addr_cnt);
            }
        }, fun_node->returns);
    }

    auto is_pointer_declaration(type_id_node const* type_node, int deref_cnt, int addr_cnt) -> bool {
        if (!type_node) { 
            return false;
        }
        if (addr_cnt > deref_cnt) {
            return true; 
        }

        if ( type_node->dereference_of ) {
            return is_pointer_declaration(type_node->dereference_of, deref_cnt + type_node->dereference_cnt, addr_cnt);
        } else if ( type_node->address_of ) {
            return is_pointer_declaration(type_node->address_of, deref_cnt, addr_cnt + 1);
        }

        int pointer_declarators_cnt = std::count_if(std::cbegin(type_node->pc_qualifiers), std::cend(type_node->pc_qualifiers), [](auto* q) {
            return q->type() == lexeme::Multiply;
        });

        if (pointer_declarators_cnt == 0 && type_node->suspicious_initialization) {
            return is_pointer_declaration(type_node->suspicious_initialization, deref_cnt, addr_cnt);
        }

        return (pointer_declarators_cnt + addr_cnt - deref_cnt) > 0;
    }

    auto is_pointer_declaration(declaration_sym const* decl, int deref_cnt, int addr_cnt) -> bool {
        if (!decl) {
            return false;
        }
        if (addr_cnt > deref_cnt) {
            return true;
        }
        return is_pointer_declaration(decl->declaration, deref_cnt, addr_cnt);
    }

    auto is_pointer_declaration(token const* t, int deref_cnt = 0, int addr_cnt = 0) -> bool {
        if (!t) {
            return false;
        }
        if (addr_cnt > deref_cnt) {
            return true;
        }
        auto decl = sema.get_declaration_of(*t, true);
        return is_pointer_declaration(decl, deref_cnt, addr_cnt);
    }

    //-----------------------------------------------------------------------
    //
    auto emit(postfix_expression_node& n, bool for_lambda_capture = false) -> void
        // note: parameter is deliberately not const because we we will fill
        //       in the capture .str information, and we may also adjust token
        //       column positions when moving operators to prefix notation
    {
        assert(n.expr);
        last_postfix_expr_was_pointer = false;

        //  Ensure that forwarding postfix-expressions start with a forwarded parameter name
        //
        assert (!current_args.empty());
        if (current_args.back().pass == passing_style::forward)
        {
            assert (n.expr->get_token());
            assert (!current_args.back().ptoken);
            current_args.back().ptoken = n.expr->get_token();
            auto decl = sema.get_declaration_of(*current_args.back().ptoken);
            if (!(decl && decl->parameter && decl->parameter->pass == passing_style::forward)) {
                errors.emplace_back(
                    n.position(),
                    n.expr->get_token()->to_string(true) + " is not a forwarding parameter name"
                );
            }
        }

        //  Check that this isn't pointer arithmentic
        //      (initial partial implementation)
        if (n.expr->expr.index() == primary_expression_node::id_expression)
        {
            auto& id = std::get<primary_expression_node::id_expression>(n.expr->expr);
            assert(id);
            if (id->id.index() == id_expression_node::unqualified)
            {
                auto& unqual = std::get<id_expression_node::unqualified>(id->id);
                assert(unqual);
                //  TODO: Generalize this: 
                //        - we don't recognize pointer types from Cpp1
                //        - we don't deduce pointer types from parameter_declaration_list_node
                if ( is_pointer_declaration(unqual->identifier) ) {
                    if (n.ops.empty()) {
                        last_postfix_expr_was_pointer = true;
                    }
                    else
                    {
                        auto op = [&](){
                            if (n.ops.size() >= 2 && n.ops[0].op->type() == lexeme::LeftParen) {
                                return n.ops[1].op;
                            } else {
                                return n.ops.front().op;
                            }
                        }();

                        if (op->type() == lexeme::PlusPlus ||
                            op->type() == lexeme::MinusMinus ||
                            op->type() == lexeme::LeftBracket
                            ) {
                            errors.emplace_back(
                                op->position(),
                                op->to_string(true) + " - pointer arithmetic is illegal - use std::span or gsl::span instead"
                            );
                            violates_bounds_safety = true;
                        }
                        else if (op->type() == lexeme::Tilde) {
                            errors.emplace_back(
                                op->position(),
                                op->to_string(true) + " - pointer bitwise manipulation is illegal - use std::bit_cast to convert to raw bytes first"
                            );
                        }
                    }
                }
            }
        }

        //  Simple case: If there are no .ops, just emit the expression
        if (n.ops.empty()) {
            emit(*n.expr);
            return;
        }

        //  Check to see if it's a capture expression that contains $,
        //  and if we're not capturing the expression for the lambda
        //  introducer replace it with the capture name
        auto captured_part = std::string{};
        if (n.cap_grp && !for_lambda_capture)
        {
            //  First stringize ourselves so that we compare equal against
            //  the first *cap_grp .str that matches us (which is what the
            //  lambda introducer generator used to create a lambda capture)
            auto my_str = std::string{};
            printer.emit_to_string(&my_str);
            emit(n, true);  // reentrant, but not in this 'if' because for_lambda_capture == true
            printer.emit_to_string();

            //  Look in the capture group to see which capture # we are
            auto mynum = 0;
            for (auto const& cap : n.cap_grp->members) {
                if (cap.str == my_str) {
                    break;
                }
                ++mynum;
            }
            assert (mynum < std::ssize(n.cap_grp->members) && "could not find this postfix-expression in capture group");
            //  And then emit that capture number
            captured_part += "_" + std::to_string(mynum);
        }

        //  Otherwise, we're going to have to potentially do some work to change
        //  some Cpp2 postfix operators to Cpp1 prefix operators, so let's set up...
        auto prefix            = std::vector<text_with_pos>{};
        auto suffix            = std::vector<text_with_pos>{};

        auto last_was_prefixed = false;
        auto saw_dollar        = false;

        struct text_chunks_with_parens_position {
            std::vector<text_with_pos> text_chunks;
            cpp2::source_position open_pos;
            cpp2::source_position close_pos;
        };

        auto args = std::optional<text_chunks_with_parens_position>{};

        auto flush_args = [&] {
            if (args) {
                suffix.emplace_back(")", args.value().close_pos);
                for (auto&& e: args.value().text_chunks) {
                    suffix.push_back(e);
                }
                suffix.emplace_back("(", args.value().open_pos);
                args.reset();
            }
        };

        auto print_to_text_chunks = [&](auto& i, auto... more) {
            auto text = std::vector<text_with_pos>{};
            printer.emit_to_text_chunks(&text);
            push_need_expression_list_parens(false);
            emit(i, more...);
            pop_need_expression_list_parens();
            printer.emit_to_text_chunks();
            return text;
        };

        for (auto i = n.ops.rbegin(); i != n.ops.rend(); ++i)
        {
            assert(i->op);

            //  If we already captured a part as a _## lambda capture,
            //  skip the part of this expression before the $ symbol
            //
            if (!captured_part.empty()) {
                if (i->op->type() == lexeme::Dollar) {
                    break;
                }
            }
            //  Else skip the part of this expression after the $ symbol
            else if (for_lambda_capture) {
                if (i->op->type() == lexeme::Dollar) {
                    saw_dollar = true;
                    continue;
                }
                if (!saw_dollar) {
                    continue;
                }
            }

            // Going backwards if we found LeftParen it might be UFCS
            // expr_list is emited to args variable for future use
            if (i->op->type() == lexeme::LeftParen) {

                assert(i->op);
                assert(i->op_close);
                auto local_args = text_chunks_with_parens_position{{}, i->op->position(), i->op_close->position()};

                assert (i->expr_list);
                if (!i->expr_list->expressions.empty()) {
                    local_args.text_chunks = print_to_text_chunks(*i->expr_list);
                }

                flush_args();
                args.emplace(std::move(local_args));
            }
            // Going backwards if we found Dot and there is args variable
            // it means that it should be handled by UFCS
            else if( i->op->type() == lexeme::Dot && args )
            {
                auto funcname = print_to_string(*i->id_expr);

                auto ufcs_string = std::string("CPP2_UFCS");

                if (i->id_expr->template_args_count() > 0) {
                    ufcs_string += "_TEMPLATE";
                    // we need to replace "fun<int,long,double>" to "fun, (<int,long,double>)" to be able to generate
                    // from obj.fun<int, long, double>(1,2) this CPP2_UFCS_TEMPLATE(fun, (<int,long, double>), obj, 1, 2)
                    auto split = funcname.find('<'); assert(split != std::string::npos);
                    funcname.insert(split, ", (");
                    assert(funcname.back() == '>');
                    funcname += ')';
                }
                //  If there are no additional arguments, use the _0 version
                if (args.value().text_chunks.empty()) {
                    ufcs_string += "_0";
                }

                prefix.emplace_back(ufcs_string + "(" + funcname + ", ", args.value().open_pos );
                suffix.emplace_back(")", args.value().close_pos );
                if (!args.value().text_chunks.empty()) {
                    for (auto&& e: args.value().text_chunks) {
                        suffix.push_back(e);
                    }
                    suffix.emplace_back(", ", i->op->position());
                }
                args.reset();
            }

            //  Handle the Cpp2 postfix operators that are prefix in Cpp1
            //
            else if (i->op->type() == lexeme::MinusMinus ||
                i->op->type() == lexeme::PlusPlus ||
                i->op->type() == lexeme::Multiply ||
                i->op->type() == lexeme::Ampersand ||
                i->op->type() == lexeme::Tilde
                )
            {
                adjust_remaining_token_columns_on_this_line_visitor v(i->op->position(), 0 - i->op->length());
                n.visit(v, 0);

                if (!last_was_prefixed && i != n.ops.rbegin()) {    // omit some needless parens
                    prefix.emplace_back( "(", i->op->position() );
                }
                prefix.emplace_back( i->op->to_string(true), i->op->position());

                //  Enable null dereference checks
                if (flag_safe_null_pointers && i->op->type() == lexeme::Multiply) {
                    prefix.emplace_back( "cpp2::assert_not_null(", i->op->position() );
                }
                if (flag_safe_null_pointers && i->op->type() == lexeme::Multiply) {
                    suffix.emplace_back( ")", i->op->position() );
                }

                if (!last_was_prefixed && i != n.ops.rbegin()) {    // omit some needless parens
                    suffix.emplace_back( ")", i->op->position() );
                }
                last_was_prefixed = true;
            }

            //  Handle the suffix operators that remain suffix
            //
            else {
                assert(i->op);
                last_was_prefixed = false;

                //  Enable subscript bounds checks
                if (flag_safe_subscripts && i->op->type() == lexeme::LeftBracket) {
                    suffix.emplace_back( ")", i->op->position() );
                }
                else if (i->op_close) {
                    suffix.emplace_back( i->op_close->to_string(true), i->op_close->position() );
                }

                if (i->id_expr) {

                    if (args) {
                        // if args are stored it means that this is function or method
                        // that is not handled by UFCS and args need to be printed
                        suffix.emplace_back(")", args.value().close_pos);
                        for (auto&& e: args.value().text_chunks) {
                            suffix.push_back(e);
                        }
                        suffix.emplace_back("(", args.value().open_pos);
                        args.reset();
                    }

                    auto print = print_to_string(*i->id_expr, false /*not a local name*/);
                    suffix.emplace_back( print, i->id_expr->position() );
                }

                if (i->expr_list) {
                    auto text = print_to_text_chunks(*i->expr_list);
                    for (auto&& e: text) {
                        suffix.push_back(e);
                    }
                }

                //  Enable subscript bounds checks
                if (flag_safe_subscripts && i->op->type() == lexeme::LeftBracket) {
                    prefix.emplace_back( "cpp2::assert_in_bounds(", i->op->position() );
                    suffix.emplace_back( ", ", i->op->position() );
                }
                else {
                    suffix.emplace_back( i->op->to_string(true), i->op->position() );
                }
            }
        }

        //  Print the prefixes (in forward order)
        for (auto& e : prefix) {
            printer.print_cpp2(e.text, n.position());
        }

        //  If this is an --, ++, or &, don't add std::move on the lhs
        //  even if this is a definite last use (only do that when an rvalue is okay)
        if (n.ops.front().op->type() == lexeme::MinusMinus ||
            n.ops.front().op->type() == lexeme::PlusPlus ||
            n.ops.front().op->type() == lexeme::Ampersand
            )
        {
            suppress_move_from_last_use = true;
        }

        //  Now print the core expression -- or the captured_part in its place
        if (captured_part.empty()) {
            emit(*n.expr);
        }
        else {
            printer.print_cpp2(captured_part, n.position());
        }
        suppress_move_from_last_use = false;

        flush_args();

        //  Print the suffixes (in reverse order)
        while (!suffix.empty()) {
            printer.print_cpp2(suffix.back().text, suffix.back().pos);
            suffix.pop_back();
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(prefix_expression_node const& n) -> void
    {
        auto suffix = std::string{};
        for (auto const& x : n.ops) {
            assert(x);
            if (x->type() == lexeme::Not) {
                printer.print_cpp2("!(", n.position());
                printer.add_pad_in_this_line(-3);
                suffix += ")";
            }
            else {
                printer.print_cpp2(*x, x->position());
            }
        }
        assert(n.expr);
        push_need_expression_list_parens(true);
        emit(*n.expr);
        pop_need_expression_list_parens();
        printer.print_cpp2(suffix, n.position());
    }


    //-----------------------------------------------------------------------
    //
    auto emit(is_as_expression_node const& n) -> void
    {
        std::string prefix = {};
        std::string suffix = {};

        auto wildcard_found = false;
        bool as_on_literal  = false;

        assert(
            n.expr &&
            n.expr->get_postfix_expression_node() &&
            n.expr->get_postfix_expression_node()->expr
        );
        if (auto t = n.expr->get_postfix_expression_node()->expr->get_token();
            t && is_literal(t->type()) && t->type() != lexeme::StringLiteral && t->type() != lexeme::FloatLiteral
            && std::ssize(n.ops) > 0 && *n.ops[0].op == "as"
        ) {
            as_on_literal = true;
        }

        for (auto i = n.ops.rbegin(); i != n.ops.rend(); ++i)
        {
            //  If it's "ISORAS type", emit "cpp2::ISORAS<type>(expr)"
            if (i->type)
            {
                if (i->type->is_wildcard()) {
                    wildcard_found = true;
                    if (*i->op != "is") {
                        errors.emplace_back(
                            n.position(),
                            "'as _' wildcard is not allowed, specify a concrete target type instead"
                        );
                    }
                    else if (std::ssize(n.ops) > 1) {
                        errors.emplace_back(
                            n.position(),
                            "an 'is _' wildcard may only be used on its own, not in a chain with other 'is'/'as' in the same subexpression"
                        );
                    }
                }
                else {
                    auto op_name = i->op->to_string(true);
                    if (op_name == "as") {
                        op_name = "as_";    // use the static_assert-checked 'as' by default...
                    }                       // we'll override this inside inspect-expressions
                    prefix += "cpp2::" + op_name + "<" + print_to_string(*i->type) + ">(";
                    suffix = ")" + suffix;
                }
            }
            //  Else it's "is value", emit "cpp2::is(expr, value)"
            else
            {
                assert(i->expr);
                prefix += "cpp2::" + i->op->to_string(true) + "(";
                suffix = ", " + print_to_string(*i->expr) + ")" + suffix;
            }
        }

        if (as_on_literal) {
            auto last_pos = prefix.rfind('>'); assert(last_pos != prefix.npos);
            prefix.insert(last_pos, ", " + print_to_string(*n.expr));
        }

        printer.print_cpp2(prefix, n.position());
        if (wildcard_found) {
            printer.print_cpp2("true", n.position());
        }
        else if(!as_on_literal) {
            emit(*n.expr);
        }
        printer.print_cpp2(suffix, n.position());
    }


    //-----------------------------------------------------------------------
    //
    template<
        String   Name,
        typename Term
    >
    auto emit(binary_expression_node<Name,Term> const& n) -> void
    {
        assert(n.expr);
        assert(n.terms.empty() || n.terms.front().op);

        //  If this is relational comparison
        if (!n.terms.empty() &&
            (
            n.terms.front().op->type() == lexeme::Less            ||
            n.terms.front().op->type() == lexeme::LessEq          ||
            n.terms.front().op->type() == lexeme::Greater         ||
            n.terms.front().op->type() == lexeme::GreaterEq       ||
            n.terms.front().op->type() == lexeme::EqualComparison ||
            n.terms.front().op->type() == lexeme::NotEqualComparison
            )
            )
        {
            auto const& op = *n.terms.front().op;

            //  If this is one (non-chained) comparison, just emit it directly
            if (std::ssize(n.terms) < 2)
            {
                assert (std::ssize(n.terms) == 1);

                //  emit < <= >= > as cmp_*(a,b) calls (if selected)
                if (flag_safe_comparisons) {
                    switch (op.type()) {
                    break;case lexeme::Less:
                        printer.print_cpp2( "cpp2::cmp_less(", n.position());
                    break;case lexeme::LessEq:
                        printer.print_cpp2( "cpp2::cmp_less_eq(", n.position());
                    break;case lexeme::Greater:
                        printer.print_cpp2( "cpp2::cmp_greater(", n.position());
                    break;case lexeme::GreaterEq:
                        printer.print_cpp2( "cpp2::cmp_greater_eq(", n.position());
                    break;default:
                        ;
                    }
                }

                emit(*n.expr);

                //  emit == and != as infix a @ b operators (since we don't have
                //  any checking/instrumentation we want to do for those)
                if (flag_safe_comparisons) {
                    switch (op.type()) {
                    break;case lexeme::EqualComparison:
                          case lexeme::NotEqualComparison:
                        emit(op);
                    break;default:
                        printer.print_cpp2( ",", n.position() );
                    }
                }
                else {
                    emit(op);
                }

                emit(*n.terms.front().expr);

                if (flag_safe_comparisons) {
                    switch (op.type()) {
                    break;case lexeme::Less:
                          case lexeme::LessEq:
                          case lexeme::Greater:
                          case lexeme::GreaterEq:
                        printer.print_cpp2( ")", n.position() );
                    break;default:
                        ;
                    }
                }

                return;
            }

            //  Else if this is a chained comparison, emit it as a lambda,
            //  to get single evaluation via the lambda capture
            else
            {
                //  To check for the valid chains: all </<=, all >/>=, or all ==
                auto found_lt = 0;  // < and <=
                auto found_gt = 0;  // > and >=
                auto found_eq = 0;  // ==
                auto count    = 0;

                auto const* lhs = n.expr.get();
                auto lhs_name = "_" + std::to_string(count);

                auto lambda_capture = lhs_name + " = " + print_to_string(*lhs);
                auto lambda_body    = std::string{};

                for (auto const& term : n.terms)
                {
                    assert(term.op && term.expr);
                    ++count;
                    auto rhs_name = "_" + std::to_string(count);

                    //  Not the first expression? Insert a "&&"
                    if (found_lt + found_gt + found_eq > 0) {
                        lambda_body += " && ";
                    }

                    //  Remember what we've seen
                    switch (term.op->type()) {
                    break;case lexeme::Less:
                          case lexeme::LessEq:
                        found_lt = 1;
                    break;case lexeme::Greater:
                          case lexeme::GreaterEq:
                        found_gt = 1;
                    break;case lexeme::EqualComparison:
                        found_eq = 1;
                    break;default:
                        ;
                    }

                    //  emit < <= >= > as cmp_*(a,b) calls (if selected)
                    if (flag_safe_comparisons) {
                        switch (term.op->type()) {
                        break;case lexeme::Less:
                            lambda_body += "cpp2::cmp_less(";
                        break;case lexeme::LessEq:
                            lambda_body += "cpp2::cmp_less_eq(";
                        break;case lexeme::Greater:
                            lambda_body += "cpp2::cmp_greater(";
                        break;case lexeme::GreaterEq:
                            lambda_body += "cpp2::cmp_greater_eq(";
                        break;default:
                            ;
                        }
                    }

                    auto rhs_expr = print_to_string(*term.expr);

                    lambda_body    += lhs_name;

                    //  emit == and != as infix a @ b operators (since we don't have
                    //  any checking/instrumentation we want to do for those)
                    if (flag_safe_comparisons) {
                        switch (term.op->type()) {
                        break;case lexeme::EqualComparison:
                            lambda_body += *term.op;
                        break;case lexeme::NotEqualComparison:
                            errors.emplace_back(
                                n.position(),
                                "!= comparisons cannot appear in a comparison chain (see https://wg21.link/p0893)"
                            );
                            return;
                        break;default:
                            lambda_body += ",";
                        }
                    }
                    else {
                        lambda_body += *term.op;
                    }

                    lambda_capture += ", " + rhs_name + " = " + rhs_expr;
                    lambda_body    += rhs_name;

                    lhs = term.expr.get();
                    lhs_name = rhs_name;

                    if (flag_safe_comparisons) {
                        switch (term.op->type()) {
                        break;case lexeme::Less:
                                case lexeme::LessEq:
                                case lexeme::Greater:
                                case lexeme::GreaterEq:
                            lambda_body += ")";
                        break;default:
                            ;
                        }
                    }
                }

                assert(found_lt + found_gt + found_eq > 0);
                if (found_lt + found_gt + found_eq != 1) {
                    errors.emplace_back(
                        n.position(),
                        "a comparison chain must be all < and <=, all > and >=, or all == (see https://wg21.link/p0893)"
                    );
                    return;
                }

                printer.print_cpp2( "[" + lambda_capture + "]{ return " + lambda_body + "; }()", n.position());

                return;
            }
        }

        //  Else if this is an assignment expression, don't add std::move on the lhs
        //  even if this is a definite last use (only do that when an rvalue is okay)
        if (!n.terms.empty() && is_assignment_operator(n.terms.front().op->type())) {
            suppress_move_from_last_use = true;
        }
        emit(*n.expr);
        suppress_move_from_last_use = false;

        //  Check that this isn't an illegal pointer operation
        //      (initial partial implementation)
        if (!n.terms.empty() && last_postfix_expr_was_pointer)
        {
            auto rhs_post = n.get_second_postfix_expression_node();
            assert(rhs_post && rhs_post->expr);
            auto rhs_tok = rhs_post->expr->get_token();
            if (is_assignment_operator(n.terms.front().op->type()) && rhs_tok &&
                (*rhs_tok == "nullptr" || is_digit(((std::string_view)*rhs_tok)[0]))
                )
            {
                errors.emplace_back(
                    n.terms.front().op->position(),
                    n.terms.front().op->to_string(true) + " - pointer assignment from null or integer is illegal"
                );
                violates_lifetime_safety = true;
            }
            else if (
                *n.terms.front().op == "+" || *n.terms.front().op == "+=" ||
                *n.terms.front().op == "-" || *n.terms.front().op == "-="
                )
            {
                errors.emplace_back(
                    n.terms.front().op->position(),
                    n.terms.front().op->to_string(true) + " - pointer arithmetic is illegal - use std::span or gsl::span instead"
                );
                violates_bounds_safety = true;
            }
        }

        for (auto const& x : n.terms) {
            assert(x.op);
            assert(x.expr);

            //  Normally we'll just emit the operator, but if this is an
            //  assignment that's a definite initialization, change it to
            //  a .construct() call
            if (x.op->type() == lexeme::Assignment && in_definite_init) {
                printer.print_cpp2( ".construct(", n.position() );
                emit(*x.expr);
                printer.print_cpp2( ")", n.position() );
            }
            else {
                printer.print_cpp2(" ", n.position());
                emit(*x.op);
                printer.print_cpp2(" ", n.position());
                emit(*x.expr);
            }
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(expression_node const& n) -> void
    {
        assert(n.expr);
        push_need_expression_list_parens(true);
        emit(*n.expr);
        pop_need_expression_list_parens();
    }


    //-----------------------------------------------------------------------
    //
    auto emit(expression_list_node const& n) -> void
    {
        auto add_parens = should_add_expression_list_parens() && !n.inside_initializer;
        if (add_parens) {
            printer.print_cpp2( *n.open_paren, n.position());
        }

        auto first = true;
        for (auto const& x : n.expressions) {
            if (!first) {
                printer.print_cpp2(", ", n.position());
            }
            first = false;
            auto offset = 0;
            auto is_out = false;

            if (x.pass != passing_style::in) {
                assert(
                    x.pass == passing_style::out ||
                    x.pass == passing_style::move ||
                    x.pass == passing_style::forward
                );
                if (x.pass == passing_style::out) {
                    is_out = true;
                    printer.print_cpp2("&", n.position());
                    offset = -3;   // because we're replacing "out " (followed by at least one space) with "&"
                }
                else if (x.pass == passing_style::move) {
                    printer.print_cpp2("std::move(", n.position());
                    offset = 6;    // because we're replacing "move " (followed by at least one space) with "std::move("
                }
            }

            if (is_out) {
                in_non_rvalue_context.push_back(true);
            }

            assert(x.expr);
            adjust_remaining_token_columns_on_this_line_visitor v(x.expr->position(), offset);
            current_args.push_back( {x.pass} );
            x.expr->visit(v, 0);
            emit(*x.expr);
            current_args.pop_back();

            if (is_out) {
                in_non_rvalue_context.pop_back();
            }

            if (x.pass == passing_style::move) {
                printer.print_cpp2(")", n.position());
            }
        }

        if (add_parens) {
            printer.print_cpp2( *n.close_paren, n.position());
        }
        //  We want to consume only one of these
        consumed_expression_list_parens();
    }


    //-----------------------------------------------------------------------
    //
    auto emit(expression_statement_node const& n, bool can_have_semicolon, source_position function_body_start = {}, bool function_void_ret = false ) -> void
    {
        assert(n.expr);

        if (function_body_start != source_position{}) {
            if (!function_returns.empty() && function_returns.back() != nullptr && function_returns.back() != &single_anon) {
                errors.emplace_back(
                    n.position(),
                    "a function with named return value(s) must have a full { } body"
                );
                return;
            }

            printer.print_cpp2(" { ", function_body_start);
            if (!function_void_ret) {
                printer.print_cpp2("return ", n.position());
            }
        }

        emit(*n.expr);
        if (can_have_semicolon) {
            printer.print_cpp2(";", n.position());
        }

        if (function_body_start != source_position{}) {
            printer.print_cpp2(" }", n.position());
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(
        statement_node const&           n,
        bool                            can_have_semicolon  = true,
        source_position                 function_body_start = {},
        bool                            function_void_ret   = false,
        std::vector<std::string> const& function_prolog     = {},
        std::vector<std::string> const& function_epilog     = {},
        colno_t                         function_indent     = 1
    )
        -> void
    {
        printer.disable_indent_heuristic_for_next_text();

        try_emit<statement_node::compound   >(n.statement, function_prolog, function_epilog, function_indent);

        //  NOTE: Reset preemption here because
        //  - for compound statements written as "= { ... }", we want to keep the
        //    preempted position which moves the { to where the = was
        //  - but for other statement types, we want to get rid of any leftover
        //    preemption (ideally there wouldn't be any, but sometimes there is
        //    and it should not apply to what we're about to emit)
        printer.preempt_position_push({});
        //  This only has a whitespace effect in the generated Cpp1 code, but it's
        //  aesthetic and aesthetics are important in this case -- we want to keep
        //  the original source's personal whitespace formatting style as much as we can

        try_emit<statement_node::expression >(n.statement, can_have_semicolon, function_body_start, function_void_ret);
        try_emit<statement_node::selection  >(n.statement);
        try_emit<statement_node::declaration>(n.statement);
        try_emit<statement_node::return_    >(n.statement);
        try_emit<statement_node::iteration  >(n.statement);
        try_emit<statement_node::contract   >(n.statement);
        try_emit<statement_node::inspect    >(n.statement, false);
        try_emit<statement_node::jump       >(n.statement);

        printer.preempt_position_pop();
    }


    //-----------------------------------------------------------------------
    //
    auto emit(parameter_declaration_node const& n, bool returns = false) -> void
    {
        //  Can't declare functions as parameters -- only pointers to functions which are objects
        assert( n.declaration );
        assert( n.declaration->is(declaration_node::object) );

        auto const& type_id = *std::get<declaration_node::object>(n.declaration->type);

        auto unqid = std::get_if<type_id_node::unqualified>(&type_id.id);
        auto is_wildcard = unqid && *(*unqid)->identifier == "_";

        //  First any prefix
        if (!returns && !is_wildcard)
        {
            switch (n.pass) {
            break;case passing_style::in     : printer.print_cpp2( "cpp2::in<",  n.position() );
            break;case passing_style::out    : printer.print_cpp2( "cpp2::out<", n.position() );
            break;default: ;
            }
        }

        printer.preempt_position_push( n.position() );

        if (is_wildcard) {
            switch (n.pass) {
            break;case passing_style::in     : printer.print_cpp2( "auto const&", n.position() );
            break;case passing_style::copy   : printer.print_cpp2( "auto",        n.position() );
            break;case passing_style::inout  : printer.print_cpp2( "auto&",       n.position() );
            break;case passing_style::out    : printer.print_cpp2( "auto&",       n.position() ); // TODO: support out<auto> via rewrite to template param
            break;case passing_style::move   : printer.print_cpp2( "auto&&",      n.position() );
            break;case passing_style::forward: printer.print_cpp2( "auto&&",      n.position() );
            break;default: ;
            }
        }
        else if (n.pass == passing_style::forward) {
            printer.print_cpp2("auto", n.position());

            auto name = n.declaration->identifier->get_token();
            assert(name);
            auto req = std::string{ "std::is_same_v<CPP2_TYPEOF(" };
            req += *name;
            req += "), ";
            printer.emit_to_string(&req);
            emit( type_id );
            printer.emit_to_string();
            req += ">";
            function_requires_conditions.push_back(req);
        }
        else {
            emit( type_id );
        }

        printer.preempt_position_pop();

        //  Then any suffix
        if (!returns && !is_wildcard)
        {
            switch (n.pass) {
            break;case passing_style::in     : printer.print_cpp2( ">",  n.position() );
            break;case passing_style::copy   : printer.print_cpp2( "",   n.position() );
            break;case passing_style::inout  : printer.print_cpp2( "&",  n.position() );
            break;case passing_style::out    : printer.print_cpp2( ">",  n.position() );
            break;case passing_style::move   : printer.print_cpp2( "&&", n.position() );
            break;case passing_style::forward: printer.print_cpp2( "&&", n.position() );
            break;default: ;
            }
        }

        printer.print_cpp2( " ", n.declaration->identifier->position() );
        emit( *n.declaration->identifier );

        if (!returns && n.declaration->initializer) {
            printer.print_cpp2( " = ", n.declaration->initializer->position() );
            emit(*n.declaration->initializer);
        }

        //TODO - when we get to classes and inheritance
        //o << pre(indent+1);
        //using enum parameter_declaration_node::modifier;
        //switch (n.mod) {
        //break;case implicit  : o << "implicit";
        //break;case virtual_  : o << "virtual";
        //break;case override_ : o << "override";
        //break;case final_    : o << "final";
        //}
        //o << "\n";
    }


    //-----------------------------------------------------------------------
    //
    auto emit(parameter_declaration_list_node const& n, bool returns = false) -> void
    {
        in_parameter_list = true;

        if (returns) {
            printer.print_cpp2( "{\n", n.position() );
        }
        else {
            assert(n.open_paren);
            printer.print_cpp2( "(", n.open_paren->position() );
        }

        //  So we don't get cute about text-aligning the first parameter when it's on a new line
        printer.disable_indent_heuristic_for_next_text();

        auto prev_pos = n.position();
        for (auto first = true; auto const& x : n.parameters) {
            if (!first && !returns) {
                printer.print_cpp2( ", ", prev_pos );
            }
            prev_pos = x->position();
            assert(x);
            emit(*x, returns);
            first = false;
            if (returns) {
                printer.print_cpp2( ";\n", x->position() );
            }
        }

        if (returns) {
            printer.print_cpp2( "};", n.position() );
        }
        else {
            //  Position heuristic (aka hack): Avoid emitting extra whitespace before )
            //  beyond column 10
            assert(n.close_paren);
            auto col = std::min( n.close_paren->position().colno, colno_t{10});
            printer.print_cpp2( ")", { n.close_paren->position().lineno, col});
        }

        in_parameter_list = false;
    }


    //-----------------------------------------------------------------------
    //
    auto emit(contract_node& n) -> void
        // note: parameter is deliberately not const because we will fill
        //       in the capture .str information
    {
        assert (n.kind);

        //  For a postcondition, we'll wrap it in a final_action_success lambda
        //
        if (*n.kind == "post") {
            auto lambda_intro = build_capture_lambda_intro_for(n.captures, n.position());
            printer.print_cpp2(
                "auto post_" + std::to_string(n.position().lineno) + "_" +
                    std::to_string(n.position().colno) + " = cpp2::finally_success(" +
                    lambda_intro + "{",
                n.position()
            );
        }

        //  Emit the contract group name (defaults to cpp2::Default)
        //
        if (n.group) {
            //  If this is one of Cpp2's predefined contract groups,
            //  make it convenient to use without cpp2:: qualification
            if (auto uid = std::get_if<id_expression_node::unqualified>(&n.group->id)) {
                assert (*uid && (**uid).identifier);
                if (
                    *(**uid).identifier == "Default" ||
                    *(**uid).identifier == "Bounds"  ||
                    *(**uid).identifier == "Null"    ||
                    *(**uid).identifier == "Type"    ||
                    *(**uid).identifier == "Testing"
                    )
                {
                    printer.print_cpp2("cpp2::", n.position());
                }
            }

            printer.preempt_position_push(n.position());
            printer.add_pad_in_this_line(-20);
            emit(*n.group);
            printer.preempt_position_pop();
        }
        else {
            printer.print_cpp2("cpp2::Default", n.position());
            printer.add_pad_in_this_line(-8);
        }

        //  And invoke .expects on that contract group
        //
        printer.print_cpp2(".expects(", n.position());
        assert(n.condition);
        emit (*n.condition);
        printer.print_cpp2(", ", n.position());
        if (n.message) {
            emit (*n.message);
        }
        else {
            printer.print_cpp2("\"\"", n.position());
        }
        printer.print_cpp2(");", n.position());

        //  For a postcondition, close out the final_action_success lambda
        //
        if (*n.kind == "post") {
            printer.print_cpp2( "} );", n.position()
            );
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(function_type_node const& n, token const* ident) -> void
    {
        assert(n.parameters);
        emit(*n.parameters);

        //  Add implicit noexcept when we implement proper EH
        //  to handle calling Cpp1 code that throws
        //if (!n.throws) {
        //    printer.add_pad_in_this_line(-25);
        //    printer.print_cpp2( " noexcept", n.position() );
        //}

        if (n.returns.index() == function_type_node::empty) {
            if (ident) {
                printer.print_cpp2( " -> void", n.position() );
            }
        }

        else if (n.returns.index() == function_type_node::id) {
            printer.print_cpp2( " -> ", n.position() );
            auto& r = std::get<function_type_node::id>(n.returns);
            assert(r);
            emit(*r);
        }

        else {
            printer.print_cpp2( " -> ", n.position() );
            function_return_name = {};
            printer.emit_to_string(&function_return_name);
            assert(ident);
            printer.print_cpp2( *ident, ident->position() );
            printer.print_cpp2( "__ret", ident->position() );
            printer.emit_to_string();
            printer.print_cpp2( function_return_name, ident->position() );
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(declaration_node const& n, std::string const& capture_intro = {}) -> void
    {
        //  If this is a function that has multiple return values,
        //  first we need to emit the struct that contains the returns
        if (printer.doing_declarations_only() && n.is(declaration_node::function))
        {
            auto& func = std::get<declaration_node::function>(n.type);
            assert(func);

            if (func->returns.index() == function_type_node::list) {
                auto& r = std::get<function_type_node::list>(func->returns);
                assert(r);
                assert(std::ssize(r->parameters) > 0);
                printer.ignore_alignment( true, n.position().colno );
                printer.print_cpp2( "struct ", n.position() );
                printer.ignore_alignment( true, n.position().colno + 4 );
                printer.print_cpp2( *n.identifier->identifier, n.position() );
                printer.print_cpp2( "__ret ", n.position() );
                emit(*r, true);
                printer.print_cpp2( "\n", n.position() );
                printer.ignore_alignment( false );
            }
        }

        //  Function
        if (n.is(declaration_node::function))
        {
            //  Start fresh (there may be one spurious leftover
            //  requires-condition created during the declarations pass)
            function_requires_conditions = {};

            auto& func = std::get<declaration_node::function>(n.type);
            assert(func);

            //  If this is at expression scope, we can't emit "[[nodiscard]] auto name"
            //  so print the provided intro instead, which will be a lambda-capture-list
            if (capture_intro != "") {
                assert (!n.identifier);
                printer.print_cpp2(capture_intro, n.position());
                emit( *func, nullptr );
            }
            else {
                assert (n.identifier);
                if (func->returns.index() != function_type_node::empty) {
                    printer.print_cpp2( "[[nodiscard]] ", n.position() );
                }
                printer.print_cpp2( "auto ", n.position() );
                printer.print_cpp2( *n.identifier->identifier, n.identifier->position() );
                emit( *func, n.identifier->identifier );
            }

            //  Function declaration
            if (printer.doing_declarations_only()) {
                printer.print_cpp2( ";\n", n.position() );
                return;
            }

            if (func->returns.index() == function_type_node::list) {
                auto& r = std::get<function_type_node::list>(func->returns);
                function_returns.push_back(r.get());
            }
            else if (func->returns.index() == function_type_node::id) {
                function_returns.push_back(&single_anon);   // use special value as a note
            }
            else {
                function_returns.push_back(nullptr);        // no return type at all
            }

            //  Function body
            assert( n.initializer );

            auto function_return_locals = std::vector<std::string>{};
            auto function_epilog        = std::vector<std::string>{};

            for (auto&& c : func->contracts) {
                auto print = std::string();
                printer.emit_to_string(&print);
                emit(*c);
                printer.emit_to_string();
                function_return_locals.push_back(print);
            }

            if (func->returns.index() == function_type_node::list)
            {
                auto& r = std::get<function_type_node::list>(func->returns);
                assert(r);
                for (auto& param : r->parameters)
                {
                    assert(param && param->declaration);
                    auto& decl    = *param->declaration;

                    assert(decl.type.index() == declaration_node::object);
                    auto& id_expr = std::get<declaration_node::object>(decl.type);
                    assert(id_expr);

                    auto loc = std::string{};
                    if (!decl.initializer) {
                        loc += ("    cpp2::deferred_init<");
                    }

                    //  For convenience, just capture the id-expression as a string
                    printer.emit_to_string(&loc);
                    emit(*id_expr);
                    printer.emit_to_string();

                    if (!decl.initializer) {
                        loc += (">");
                    }
                    loc += " ";
                    loc += ((std::string_view)*decl.identifier->identifier);
                    if (decl.initializer)
                    {
                        std::string init;
                        printer.emit_to_string(&init);
                        printer.print_cpp2 ( " {", decl.initializer->position() );
                        if (decl.initializer->statement.index() != statement_node::expression) {
                            errors.emplace_back(
                                decl.initializer->position(),
                                "return value initializer must be an expression"
                            );
                            return;
                        }
                        auto& expr = std::get<statement_node::expression>(decl.initializer->statement);
                        assert(expr);

                        emit(*expr, false);
                        printer.print_cpp2 ( "}", decl.initializer->position() );
                        printer.emit_to_string();

                        loc += init;
                    }
                    loc += ";";
                    function_return_locals.push_back(loc);
                }
            }

            //function_epilog.push_back("/*EPILOG-TEST*/");

            printer.preempt_position_push( n.equal_sign );

            // TODO: something like this to get rid of extra blank lines
            //       inside the start of bodies of functions that have
            //       multiple contracts
            //printer.skip_lines( std::ssize(function_return_locals) );

            //  If processing the parameters generated any requires conditions,
            //  emit them here
            if (!function_requires_conditions.empty()) {
                printer.ignore_alignment( true, n.position().colno + 4 );
                printer.print_extra("\n");
                for (auto const& req : function_requires_conditions) {
                    printer.print_extra("requires " + req);
                }
                function_requires_conditions = {};
                printer.ignore_alignment( false );
            }

            emit(
                *n.initializer,
                true, func->position(), n.identifier && func->returns.index() == function_type_node::empty,
                function_return_locals, function_epilog, n.position().colno
            );

            printer.preempt_position_pop();

            function_returns.pop_back();
        }

        //  Object with optional initializer
        else if (!printer.doing_declarations_only() && n.is(declaration_node::object))
        {
            auto& type = std::get<declaration_node::object>(n.type);

            //  Emit "auto" for deduced types (of course)
            if (type->is_wildcard()) {
                assert(n.initializer);
                //printer.print_cpp2("auto", n.position());
                emit( *type, n.position() );
            }
            //  Otherwise, emit the type
            else {
                //  If there isn't an initializer, use cpp2::deferred_init<T>
                if (!n.initializer) {
                    if (n.parent_scope && n.parent_scope->is(declaration_node::function)) {
                        printer.print_cpp2( "cpp2::deferred_init<", n.position() );
                    }
                    else {
                        errors.emplace_back(
                            n.position(),
                            "a non-local object must have an initializer"
                        );
                        return;
                    }
                }
                printer.preempt_position_push(n.position());
                emit( *type );
                printer.preempt_position_pop();
                //  one pointer is enough for now, pointer-to-function fun can be later
                if (!n.initializer) {
                    printer.print_cpp2( ">", n.position() );
                }
            }

            printer.print_cpp2( " ", n.position());
            assert(n.identifier);
            emit(*n.identifier);

            //  If there's an initializer, emit it
            if (n.initializer)
            {
                in_non_rvalue_context.push_back(true);
                printer.add_pad_in_this_line(-100);
                printer.print_cpp2( " {", n.position() );

                push_need_expression_list_parens(false);
                assert( n.initializer );
                emit( *n.initializer, false );
                pop_need_expression_list_parens();

                printer.print_cpp2( "}", n.position() );
                in_non_rvalue_context.pop_back();
            }

            printer.print_cpp2( "; ", n.position() );
        }
    }


    //-----------------------------------------------------------------------
    //  print_errors
    //
    auto print_errors() -> void
    {
        if (!errors.empty()) {
            //  Delete the output file
            printer.abandon();
        }

        for (auto&& error : errors) {
            error.print(std::cerr, strip_path(sourcefile));
        }
        if (violates_lifetime_safety) {
            std::cerr << "  ==> program violates lifetime safety guarantee - see previous errors\n";
        }
        if (violates_bounds_safety) {
            std::cerr << "  ==> program violates bounds safety guarantee - see previous errors\n";
        }
        if (violates_initialization_safety) {
            std::cerr << "  ==> program violates initialization safety guarantee - see previous errors\n";
        }
    }

    auto had_no_errors() -> bool
    {
        return errors.empty();
    }


    //-----------------------------------------------------------------------
    //  debug_print
    //
    auto debug_print() -> void
    {
        //  Only create debug output files if we managed to load the source file.
        //
        if (source_loaded)
        {
            auto out_source     = std::ofstream{ sourcefile+"-source"  };
            source.debug_print( out_source     );

            auto out_tokens     = std::ofstream{ sourcefile+"-tokens"  };
            tokens.debug_print( out_tokens     );

            auto out_parse      = std::ofstream{ sourcefile+"-parse"   };
            auto tree_printer   = parse_tree_printer{out_parse  };
            parser.visit      ( tree_printer   );

            auto out_symbols    = std::ofstream{ sourcefile+"-symbols" };
            sema.debug_print  ( out_symbols    );
        }
    }


    //-----------------------------------------------------------------------
    //  has_cpp1: pass through
    //
    auto has_cpp1() const -> bool {
        return source.has_cpp1();
    }


    //-----------------------------------------------------------------------
    //  has_cpp2: pass through
    //
    auto has_cpp2() const -> bool {
        return source.has_cpp2();
    }
};

}


//===========================================================================
//  main - driver
//===========================================================================

using namespace std;
using namespace cpp2;

static auto enable_debug_output_files = false;
static cmdline_processor::register_flag cmd_debug(
    9,
    "debug",
    "Emit compiler debug output files",
    []{ enable_debug_output_files = true; }
);

auto main(int argc, char* argv[]) -> int
{
    cmdline.set_args(argc, argv);
    cmdline.process_flags();

    if (cmdline.help_was_requested()) {
        return EXIT_SUCCESS;
    }

    if (cmdline.arguments().empty()) {
        std::cerr << "cppfront: error: no input files (try -help)\n";
        return EXIT_FAILURE;
    }

    //  For each Cpp2 source file
    int exit_status = EXIT_SUCCESS;
    for (auto const& arg : cmdline.arguments())
    {
        std::cout << arg.text << "...";

        //  Load + lex + parse + sema
        cppfront c(arg.text);

        //  Generate Cpp1 (this may catch additional late errors)
        auto count = c.lower_to_cpp1();

        //  If there were no errors, say so and generate Cpp1
        if (c.had_no_errors())
        {
            if (!c.has_cpp1()) {
                std::cout << " ok (all Cpp2, passes safety checks)\n";
            }
            else if (c.has_cpp2()) {
                std::cout << " ok (mixed Cpp1/Cpp2, Cpp2 code passes safety checks)\n";
            }
            else {
                std::cout << " ok (all Cpp1)\n";
            }

            if (flag_verbose) {
                std::cout << "   Cpp1: " << count.cpp1_lines << " lines\n";
                std::cout << "   Cpp2: " << count.cpp2_lines << " lines";
                if (count.cpp1_lines + count.cpp2_lines > 0) {
                    std::cout << " (" << 100 * count.cpp2_lines / (count.cpp1_lines + count.cpp2_lines) << "%)";
                }
                std::cout << "\n";
            }

            std::cout << "\n";
        }
        //  Otherwise, print the errors
        else
        {
            std::cerr << "\n";
            c.print_errors();
            std::cerr << "\n";
            exit_status = EXIT_FAILURE;
        }

        //  In any case, emit the debug information (during early development this is
        //  on by default, later we'll flip the switch to turn it on instead of off)
        if (enable_debug_output_files) {
            c.debug_print();
        }
    }
    return exit_status;
}
