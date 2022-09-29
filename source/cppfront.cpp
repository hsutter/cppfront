
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
    1,
    "clean-cpp1",
    "Emit clean Cpp1 without #line directives",
    []{ flag_clean_cpp1 = true; }
);

static auto flag_cpp2_only = false;
static cmdline_processor::register_flag cmd_cpp2_only(
    1,
    "pure-cpp2",
    "Allow Cpp2 syntax only",
    []{ flag_cpp2_only = true; }
);

static auto flag_safe_null_pointers = false;
static cmdline_processor::register_flag cmd_safe_null_pointers(
    2,
    "null-checks",
    "Enable null safety contract checks",
    []{ flag_safe_null_pointers = true; }
);

static auto flag_safe_subscripts = false;
static cmdline_processor::register_flag cmd_safe_subscripts(
    2,
    "subscript-checks",
    "Enable subscript bounds safety contract checks",
    []{ flag_safe_subscripts = true; }
);

static auto flag_use_source_location = false;
static cmdline_processor::register_flag cmd_enable_source_info(
    2,
    "add-source-info",
    "Enable source locations for contract checks",
    []{ flag_use_source_location = true; }
);


struct text_with_pos{
    std::string     text;
    source_position pos;
    text_with_pos(std::string const& t, source_position p) : text{t}, pos{p} { }
};


class positional_printer
{
    //  Core information
    std::ofstream               out       = {};     // Cpp1 syntax output file
    std::string                 filename  = {};
    std::vector<comment> const* pcomments = {};     // Cpp2 comments data

    source_position curr_pos            = {};       // current (line,col) in output
    int             next_comment        = 0;        // index of the next comment not yet printed
    bool            last_was_cpp2       = false;

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
    source_position preempt_pos         = {};       // use this position instead of the next supplied one
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
        out << s;

        //  Update curr_pos by finding how many line breaks s contained,
        //  and where the last one was which determines our current colno
        auto last_newline = std::string::npos;  // the last newline we found in the string
        auto newline_pos  = 0;                  // the current newline we found in the string
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
            out << "#line " << line << " " << std::quoted(filename + "2") << "\n";
        }
    }

    //  Catch up with comment/blank lines
    //
    auto flush_comments( source_position pos ) -> void
    {
        assert(pcomments);

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
    //  Open
    //
    auto open(
        std::string                 cpp1_filename,
        std::vector<comment> const& comments
    )
        -> void
    {
        assert (!out.is_open() && !pcomments && "ICE: tried to call .open twice");
        filename = cpp1_filename;
        out.open(filename);
        pcomments = &comments;
    }

    auto is_open() -> bool {
        if (out.is_open()) {
            assert (pcomments && "ICE: if out.is_open, pcomments should also be set");
        }
        return out.is_open();
    }


    //-----------------------------------------------------------------------
    //  Abandon: close and delete
    //
    auto abandon() -> void
    {
        if (!out.is_open()) {
            return;
        }
        out.close();
        std::remove(filename.c_str());
    }


    //-----------------------------------------------------------------------
    //  Print extra text and don't track positions
    //  Used for Cpp2 boundary comment and prelude
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
            if (preempt_pos != source_position{}) {
                if (preempt_pos.lineno == pos.lineno) {
                    adjusted_pos.colno = preempt_pos.colno;
                }
                preempt_pos = {};
                assert (preempt_pos == source_position{});
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
    auto preempt_position(source_position pos) -> void
    {
        preempt_pos = pos;
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
    auto emit_to_string( std::string* target = nullptr ) -> void {
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
    auto emit_to_text_chunks( std::vector<text_with_pos>* target = nullptr ) -> void {
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

    bool source_loaded                   = true;
    bool last_postfix_expr_was_pointer   = false;
    bool violates_bounds_safety          = false;
    bool violates_initialization_safety  = false;
    bool suppress_move_from_last_use     = false;

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
        if (!sourcefile.ends_with(".cpp2"))
        {
            errors.emplace_back(
                source_position(-1, -1),
                "source filename must end with .cpp2: " + sourcefile
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
                    if (!parser.parse(entry)) {
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
    //  Emits the target file with the last '2' stripped -> .cpp
    //
    auto lower_to_cpp1() -> void
    {
        //  Only lower to Cpp1 if we haven't already encountered errors
        if (!errors.empty()) {
            return;
        }

        //  Now we'll open the .cpp file
        printer.open(
            sourcefile.substr(0, std::ssize(sourcefile) - 1),
            tokens.get_comments()
        );

        //  Only emit extra lines if we actually have Cpp2, because
        //  we want pure-Cpp1 files to pass through with zero changes
        if (source.has_cpp2()) {
            if (!flag_clean_cpp1) {
                printer.print_extra( "// ----- Cpp2 support -----\n" );
            }
            if (flag_use_source_location) {
                printer.print_extra( "#define CPP2_USE_SOURCE_LOCATION Yes\n" );
            }
            if (flag_cpp2_only) {
                printer.print_extra( "#define CPP2_USE_MODULES         Yes\n" );
            }
            printer.print_extra( "#include \"cpp2util.h\"\n\n" );
        }

        auto map_iter = tokens.get_map().cbegin();

        //  First, echo the non-Cpp2 parts
        //
        auto cpp2_found = false;

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
                    if (flag_cpp2_only &&
                        !line.text.empty() &&
                        line.cat != source_line::category::comment &&
                        line.cat != source_line::category::import
                        )
                    {
                        if (line.cat == source_line::category::preprocessor) {
                            errors.emplace_back(
                                source_position(curr_lineno, 1),
                                "pure-cpp2 switch disables the preprocessor, including #include - use import instead (note: 'import std;' is implicit in -pure-cpp2)"
                            );
                        }
                        else {
                            errors.emplace_back(
                                source_position(curr_lineno, 1),
                                "pure-cpp2 switch disables Cpp1 syntax"
                            );
                        }
                        return;
                    }

                    printer.print_cpp1( line.text, curr_lineno );
                }

                //  If it's a Cpp2 line...
                else {
                    cpp2_found = true;

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
        if (!cpp2_found) {
            return;
        }

        //  If there is Cpp2 code, we have more to do...
        //  Next, bring in the Cpp2 helpers
        //
        if (!flag_clean_cpp1) {
            printer.print_extra( "\n//=== Cpp2 definitions ==========================================================\n\n" );
        }

        //  Next, emit the Cpp2 definitions
        //
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

        if (source.has_cpp2()) {
            //  Always make sure the last line ends with a newline
            //  (not really necessary but makes some tools quieter)
            //  -- but only if there's any Cpp2, otherwise don't
            //  because passing through all-Cpp1 code should always
            //  remain diff-identical
            printer.print_extra("\n");
        }
    }


    //-----------------------------------------------------------------------
    //
    //  emit() functions - each emits a kind of node
    //
    //  The body often mirrors the node's visit() function, unless customization
    //  is needed where Cpp1 and Cpp2 have different grammar orders
    //

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
    //  A StringLiteral could include captures
    //
    auto expand_string_literal(token const& n) -> std::string
    {
        assert(n.type() == lexeme::StringLiteral);

        auto text = std::string_view(n);
        auto length = n.length();
        assert (std::ssize(text) == length);

        assert(length >= 2);
        assert(text.back() == '"');

        auto pos = 0;
        auto ret = std::string{};   // the return string we're going to build
        auto current_start = 0;     // the current offset before which the string has been into ret

        //  Skip prefix to first non-" character
        while (pos < length && text[pos] != '"') {
            ++pos;
        }
        assert(pos < length && text[pos] == '"');
        ++pos;

        //  Now we're on the first character of the string itself
        for ( ; pos < length && (text[pos] != '"' || text[pos-1] == '\\'); ++pos)
        {
            //  Find the next )$
            if (text[pos] == '$' && text[pos-1] == ')')
            {
                //  Scan back to find the matching (
                auto paren_depth = 1;
                auto open = pos - 2;

                //  "next" in the string is the "last" one encountered in the backwards scan
                auto last_nonwhitespace = '\0';

                for( ; text[open] != '"' || text[open-1] != '\\'; --open)
                {
                    if (text[open] == ')') {
                        ++paren_depth;
                    }
                    else if (text[open] == '(') {
                        --paren_depth;
                        if (paren_depth == 0) {
                            break;
                        }
                    }
                    else if (
                        (text[open] == '+' && text[open - 1] == '+') ||
                        (text[open] == '-' && text[open - 1] == '-')
                        )
                    {
                        errors.emplace_back(
                            source_position( n.position().lineno, n.position().colno + pos ),
                            "a string interpolation expression may not contain ++ or --"
                        );
                        return "";
                    }
                    else if (
                        (text[open] == '*' || text[open] == '&' || text[open] == '~') &&
                        !isspace(text[open - 1]) &&
                        !isalnum(last_nonwhitespace) && last_nonwhitespace != '('
                        )
                    {
                        errors.emplace_back(
                            source_position( n.position().lineno, n.position().colno + pos ),
                            "a string interpolation expression may not contain unary & * or ~"
                        );
                        return "";
                    }

                    if (!std::isspace(text[open])) {
                        last_nonwhitespace = text[open];
                    }
                }
                if (text[open] == '"')
                {
                    errors.emplace_back(
                        source_position( n.position().lineno, n.position().colno + pos ),
                        "no matching ( for string interpolation ending in )$"
                    );
                    return "";
                }
                assert (text[open] == '(');

                //  'open' is now at the matching (

                //  Put the next non-interpolated chunk straight into ret
                if (current_start > 0) {
                    ret += '"';
                }
                ret += text.substr(current_start, open - current_start);
                ret += '"';

                //  Then put interpolated chunk into ret
                ret += " + cpp2::to_string";
                ret += text.substr(open, pos - open);
                ret += " + ";

                current_start = pos+1;
            }
        }

        //  Now we should be on the the final " closing the string
        assert(pos == length-1 && text[pos] == '"');

        //  Put the final non-interpolated chunk straight into ret
        if (current_start > 0) {
            ret += '"';
        }
        ret += text.substr(current_start);

        return ret;
    }


    //-----------------------------------------------------------------------
    //
    auto emit(token const& n) -> void
    {
        if (n == "new") {
            printer.print_cpp2("cpp2_new", n.position());
        }
        else if (n.type() == lexeme::StringLiteral) {
            printer.print_cpp2( expand_string_literal(n), n.position() );
        }
        else {
            printer.print_cpp2(n, n.position());
        }

        in_definite_init = is_definite_initialization(&n);
    }


    //-----------------------------------------------------------------------
    //
    auto emit(unqualified_id_node const& n, bool in_synthesized_multi_return = false ) -> void
    {
        auto last_use = is_definite_last_use(n.identifier);

        bool add_std_forward =
            last_use && last_use->is_forward;

        bool add_std_move =
            !add_std_forward &&
            (in_synthesized_multi_return || (last_use && !suppress_move_from_last_use));

        if (add_std_move) {
            printer.print_cpp2("std::move(", n.position());
        }
        if (add_std_forward) {
            printer.print_cpp2("CPP2_FORWARD(", n.position());
        }

        assert(n.identifier);
        emit(*n.identifier);

        if (n.const_qualifier) {
            printer.print_cpp2(" ", n.const_qualifier->position());
            emit(*n.const_qualifier);
        }

        if (!n.template_args.empty()) {
            printer.print_cpp2("<", n.open_angle);
            auto first = true;
            for (auto& a : n.template_args) {
                if (!first) {
                    printer.print_cpp2(",", a.comma);
                }
                first = false;
                try_emit<unqualified_id_node::expression   >(a.arg);
                try_emit<unqualified_id_node::id_expression>(a.arg);
            }
            printer.print_cpp2(">", n.close_angle);
        }

        in_definite_init = is_definite_initialization(n.identifier);
        if (in_synthesized_multi_return) {
            printer.print_cpp2(".value()", n.position());
        }
        else if (!in_definite_init && !in_parameter_list) {
            if (auto decl = sema.get_declaration_of(*n.identifier);
                decl &&
                //  note pointer equality: if we're not in the actual declaration of n.identifier
                decl->identifier != n.identifier &&
                //  and this variable was uninitialized
                !decl->initializer &&
                //  and it's either a non-parameter or an out parameter
                (!decl->parameter || (decl->parameter && decl->parameter->pass == passing_style::out))
                )
            {
                printer.print_cpp2(".value()", n.position());
            }
        }

        if (add_std_move || add_std_forward) {
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
            emit(*id.id);
        }

        printer.emit_to_string();
        printer.print_cpp2( ident, n.position() );
    }


    //-----------------------------------------------------------------------
    //
    auto emit(id_expression_node const& n) -> void
    {
        try_emit<id_expression_node::qualified  >(n.id);
        try_emit<id_expression_node::unqualified>(n.id);
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
            assert(alt->id_expression);
            emit(*alt->id_expression);
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

                //  If this is an inspect-expression, we'll have to wrap each alternative
                //  in an 'if constexpr' so that its type is ignored for mismatches with
                //  the inspect-expression's type
                auto return_prefix = std::string{};
                auto return_suffix = std::string{";"};   // use this to tack the ; back on in the alternative body
                if (is_expression) {
                    return_prefix = "{ if constexpr( requires{" + statement + ";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(" + statement + ")," + result_type + "> ) return ";
                    return_suffix += " }";
                }

                if (id == "_") {
                    found_wildcard = true;
                    if (is_expression) {
                        printer.print_cpp2("return ", alt->position());
                    }
                }
                else {
                    printer.print_cpp2("if " + constexpr_qualifier + "(cpp2::is<" + id + ">(__expr)) " + return_prefix, alt->position());
                }

                printer.print_cpp2(statement, alt->position());

                if (is_expression && id != "_") {
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
        printer.print_cpp2("\n", n.close_brace);
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
            emit(*n.statement);
            return;
        }

        //  Handle do
        //
        if (*n.identifier == "do") {
            assert(n.condition && n.statement && !n.range && !n.body);

            printer.print_cpp2("do ", n.position());
            emit(*n.statement);
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
            return;
        }

        //  Handle for
        //
        if (*n.identifier == "for") {
            assert(!n.condition && !n.statement && n.range && n.body);

            //  TODO: break n.range into subexpressions and lifetime-extend
            //        each subexpression, because that's the right thing to do
            //  For now, just use a for-scope auto&&
            //  Also: using the name 'cpp2_range' for now because '__range' is reserved
            //        and common enough that it might clash with existing impls
            printer.print_cpp2("for ( auto&& cpp2_range = ", n.position());
            emit(*n.range);
            printer.print_cpp2(";  ", n.position());
            emit(*n.get_for_parameter());
            printer.print_cpp2(" : cpp2_range ) ", n.position());

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

            return;
        }

        assert(!"compiler bug: unexpected case");
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
    auto build_capture_lambda_intro_for( capture_group& captures, source_position pos ) -> std::string
    {
        //  First calculate the stringized version of each capture expression
        //  This will let us compare and de-duplicate repeated capture expressions
        for (auto& cap : captures)
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
        for (auto& cap : captures)
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
            auto& decl = std::get<primary_expression_node::declaration>(n.expr);

            //  The usual non-null assertion, plus it should be an anonymous function
            assert(decl && !decl->identifier && decl->is(declaration_node::function));

            auto lambda_intro = build_capture_lambda_intro_for(decl->captures, n.position());

            emit(*decl, lambda_intro);
        }
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
                auto decl = sema.get_declaration_of(*unqual->identifier);
                //  TODO: Generalize this -- for now we detect only cases of the form "p: *int = ...;"
                //        We don't recognize pointer types that are deduced, multi-level, or from Cpp1
                if (decl && decl->declaration && decl->declaration->pointer_declarator) {
                    if (n.ops.empty()) {
                        last_postfix_expr_was_pointer = true;
                    }
                    else
                    {
                        if (n.ops.front().op->type() == lexeme::PlusPlus ||
                            n.ops.front().op->type() == lexeme::MinusMinus ||
                            n.ops.front().op->type() == lexeme::LeftBracket
                            ) {
                            errors.emplace_back(
                                n.ops.front().op->position(),
                                n.ops.front().op->to_string(true) + " - pointer arithmetic is illegal - use std::span or gsl::span instead"
                            );
                            violates_bounds_safety = true;
                        }
                        else if (n.ops.front().op->type() == lexeme::Tilde) {
                            errors.emplace_back(
                                n.ops.front().op->position(),
                                n.ops.front().op->to_string(true) + " - pointer bitwise manipulation is illegal - use std::bit_cast to convert to raw bytes first"
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
            for (auto const& cap : *n.cap_grp) {
                if (cap.str == my_str) {
                    break;
                }
                ++mynum;
            }
            assert (mynum < n.cap_grp->size() && "could not find this postfix-expression in capture group");
            //  And then emit that capture number
            captured_part += "_" + std::to_string(mynum);
        }

        //  Check to see if it's just a function call with "." syntax,
        //  and if so use this path to convert it to UFCS
        if (// there's a single-token expression followed by . and (
            n.expr->get_token() &&                      //  if the base expression is a single token
            std::ssize(n.ops) >= 2 &&                   //  and we're of the form:
            n.ops[0].op->type() == lexeme::Dot &&       //       token . id-expr ( expr-list )
            n.ops[1].op->type() == lexeme::LeftParen &&
            // and either there's nothing after that, or there's just a $ after that
            (
                std::ssize(n.ops) == 2 ||
                (std::ssize(n.ops) == 3 && n.ops[2].op->type() == lexeme::Dollar)
            )
            )
        {
            //  If we already replaced this with a capture (which contains the UFCS
            //  work already done when the capture was computed), emit the capture
            if (!captured_part.empty()) {
                printer.print_cpp2(captured_part, n.position());
                return;
            }

            //  Otherwise, do the UFCS work...

            //  The . has its id_expr
            assert (n.ops[0].id_expr);

            //  The ( has its expr_list and op_close
            assert (n.ops[1].expr_list && n.ops[1].op_close);

            //  If there are no additional arguments, use the CPP2_UFCS_0 version
            if (!n.ops[1].expr_list->expressions.empty()) {
                printer.print_cpp2("CPP2_UFCS(", n.position());
            }
            else {
                printer.print_cpp2("CPP2_UFCS_0(", n.position());
            }

            //  Make the "funcname" the first argument to CPP2_UFCS
            emit(*n.ops[0].id_expr);
            printer.print_cpp2(", ", n.position());

            //  Then make the base expression the second argument
            emit(*n.expr);

            //  Then tack on any additional arguments
            if (!n.ops[1].expr_list->expressions.empty()) {
                printer.print_cpp2(", ", n.position());
                emit(*n.ops[1].expr_list);
            }
            printer.print_cpp2(")", n.position());

            //  And we're done. This path has handled this node, so return...
            return;
        }

        //  Otherwise, we're going to have to potentially do some work to change
        //  some Cpp2 postfix operators to Cpp1 prefix operators, so let's set up...
        auto prefix            = std::vector<text_with_pos>{};
        auto suffix            = std::vector<text_with_pos>{};

        auto emitted_n         = false;
        auto last_was_prefixed = false;
        auto saw_dollar        = false;

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

            //  Handle the Cpp2 postfix operators that are prefix in Cpp1
            //
            if (i->op->type() == lexeme::MinusMinus ||
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
                    auto print = std::string{};
                    printer.emit_to_string(&print);
                    emit(*i->id_expr);
                    printer.emit_to_string();
                    suffix.emplace_back( print, i->id_expr->position() );
                }

                if (i->expr_list) {
                    auto text = std::vector<text_with_pos>{};
                    printer.emit_to_text_chunks(&text);
                    emit(*i->expr_list);
                    printer.emit_to_text_chunks();
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
            assert(x->type() == lexeme::Not);   // should be the only prefix operator
            printer.add_pad_in_this_line(-3);
            printer.print_cpp2("!(", n.position());
            suffix += ")";
        }
        assert(n.expr);
        emit(*n.expr);
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

        //  Handle is/as expressions
        //  TODO: Generalize
        if (!n.terms.empty() && *n.terms.front().op == "is")
        {
            if (n.terms.size() > 1) {
                errors.emplace_back(
                    n.position(),
                    "(temporary alpha limitation) this compiler is just starting to learn 'is' and only supports a single is-expression (no chaining with other is/as)"
                );
                return;
            }

            printer.print_cpp2("cpp2::is<", n.position());
            emit(*n.terms.front().expr);
            printer.print_cpp2(">(", n.position());

            emit(*n.expr);

            printer.print_cpp2(")", n.position());
            return;
        }

        if (!n.terms.empty() && *n.terms.front().op == "as")
        {
            if (n.terms.size() > 1) {
                errors.emplace_back(
                    n.position(),
                    "(temporary alpha limitation) this compiler is just starting to learn 'as' and only supports a single as-expression (no chaining with other is/as)"
                );
                return;
            }

            printer.print_cpp2("cpp2::as<", n.position());
            emit(*n.terms.front().expr);
            printer.print_cpp2(">(", n.position());

            emit(*n.expr);

            printer.print_cpp2(")", n.position());
            return;
        }

        //  If this is an assignment expression, don't add std::move on the lhs
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
        emit(*n.expr);
    }


    //-----------------------------------------------------------------------
    //
    auto emit(expression_list_node const& n) -> void
    {
        auto first = true;
        for (auto const& x : n.expressions) {
            if (!first) {
                printer.print_cpp2(", ", n.position());
            }
            first = false;
            auto offset = 0;

            if (x.pass != passing_style::in) {
                assert(to_string_view(x.pass) == "out" || to_string_view(x.pass) == "move");
                if (to_string_view(x.pass) == "out") {
                    printer.print_cpp2("&", n.position());
                    offset = -3;   // because we're replacing "out " (followed by at least one space) with "&"
                }
                else if (to_string_view(x.pass) == "move") {
                    printer.print_cpp2("std::move(", n.position());
                    offset = 6;    // because we're replacing "move " (followed by at least one space) with "std::move("
                }
            }

            assert(x.expr);
            adjust_remaining_token_columns_on_this_line_visitor v(x.expr->position(), offset);
            x.expr->visit(v, 0);
            emit(*x.expr);

            if (to_string_view(x.pass) == "move") {
                printer.print_cpp2(")", n.position());
            }
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(expression_statement_node const& n, bool can_have_semicolon, source_position function_body_start = {}, bool function_void_ret = false ) -> void
    {
        assert(n.expr);

        if (function_body_start != source_position{}) {
            printer.print_cpp2(" { ", function_body_start);
            if (!function_void_ret) {
                printer.print_cpp2("return ", n.position());
            }
        }

        emit(*n.expr);
        if (n.has_semicolon && can_have_semicolon) {
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
        //  TODO: If there's a let on this statement, generate a block scope
        if (n.let) {

            //  TODO

        }

        printer.disable_indent_heuristic_for_next_text();

        try_emit<statement_node::compound   >(n.statement, function_prolog, function_epilog, function_indent);

        //  NOTE: Reset preemption here because
        //  - for compound statements written as "= { ... }", we want to keep the
        //    preempted position which moves the { to where the = was
        //  - but for other statement types, we want to get rid of any leftover
        //    preemption (ideally there wouldn't be any, but sometimes there is
        //    and it should not apply to what we're about to emit)
        printer.preempt_position({});
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
    }


    //-----------------------------------------------------------------------
    //
    auto emit(parameter_declaration_node const& n, bool returns = false) -> void
    {
        //  Can't declare functions as parameters -- only pointers to functions which are objects
        assert( n.declaration );
        assert( n.declaration->is(declaration_node::object) );

        auto const& id_expr = *std::get<declaration_node::object>(n.declaration->type);

        auto unqid = std::get_if<id_expression_node::unqualified>(&id_expr.id);
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

        printer.preempt_position( n.position() );

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
            emit( id_expr );
            printer.emit_to_string();
            req += ">";
            function_requires_conditions.push_back(req);
        }
        else {
            emit( id_expr );
            if (n.declaration->pointer_declarator) {
                printer.print_cpp2(" ", n.declaration->pointer_declarator->position());
                emit(*n.declaration->pointer_declarator);
            }
        }

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

            printer.preempt_position( n.position() );
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
            printer.print_cpp2( "(", n.pos_open_paren );
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
            auto col = std::min( n.pos_close_paren.colno, colno_t{10} );
            printer.print_cpp2( ")", { n.pos_close_paren.lineno, col } );
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

            printer.preempt_position(n.position());
            printer.add_pad_in_this_line(-20);
            emit(*n.group);
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
    auto emit(declaration_node const& n, std::string const& in_expression_intro = "") -> void
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
            if (in_expression_intro != "") {
                assert (!n.identifier);
                printer.print_cpp2(in_expression_intro, n.position());
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
                        printer.print_cpp2 ( " = ", decl.initializer->position() );
                        if (decl.initializer->statement.index() != statement_node::expression) {
                            errors.emplace_back(
                                decl.initializer->position(),
                                "return value initializer must be an expression"
                            );
                            return;
                        }
                        auto& expr = std::get<statement_node::expression>(decl.initializer->statement);
                        assert(expr);

                        emit(*decl.initializer);
                        printer.emit_to_string();

                        loc += init;
                    }
                    loc += ";";
                    function_return_locals.push_back(loc);
                }
            }

            //function_epilog.push_back("/*EPILOG-TEST*/");

            printer.preempt_position( n.equal_sign );

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

            function_returns.pop_back();
        }

        //  Object with optional initializer
        else if (!printer.doing_declarations_only() && n.is(declaration_node::object))
        {
            auto& type = std::get<declaration_node::object>(n.type);

            //  Emit "auto" for deduced types (of course)
            if (type->id.index() == id_expression_node::empty) {
                assert(n.initializer);
                printer.print_cpp2("auto", n.position());
            }
            //  Otherwise, emit the type
            else {
                //  If there isn't an initializer, use cpp2::deferred_init<T>
                if (!n.initializer) {
                    printer.print_cpp2( "cpp2::deferred_init<", n.position() );
                }
                printer.preempt_position(n.position());
                emit( *type );
                if (n.pointer_declarator) {
                    printer.print_cpp2("*", n.position());
                }
                //  one pointer is enough for now, pointer-to-function fun can be later
                if (!n.initializer) {
                    printer.print_cpp2( ">", n.position() );
                }
            }

            printer.print_cpp2( " ", n.position());
            assert(n.identifier);
            emit(*n.identifier);
            //printer.print_cpp2( *n.identifier->identifier, n.position() );

            //  If there's an initializer, emit it
            if (n.initializer)
            {
                printer.add_pad_in_this_line(-100);
                printer.print_cpp2( " { ", n.position() );

                assert( n.initializer );
                emit( *n.initializer, false );

                printer.print_cpp2( " }", n.position() );
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
static cmdline_processor::register_flag cmd_noline(
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
        return 0;
    }

    if (cmdline.arguments().empty()) {
        std::cout << "cppfront: error: no input files\n";
        return 0;
    }

    //  For each .cpp2 source file
    for (auto const& arg : cmdline.arguments())
    {
        std::cout << arg.text << "...";

        //  Load + lex + parse + sema
        cppfront c(arg.text);

        //  Generate Cpp1 (this may catch additional late errors)
        c.lower_to_cpp1();

        //  If there were no errors, say so and generate Cpp1
        if (c.had_no_errors()) {
            if (!c.has_cpp1()) {
                std::cout << " ok (all Cpp2, passes safety checks)\n\n";
            }
            else if (c.has_cpp2()) {
                std::cout << " ok (mixed Cpp1/Cpp2, Cpp2 code passes safety checks)\n\n";
            }
            else {
                std::cout << " ok (all Cpp1)\n\n";
            }
        }
        //  Otherwise, print the errors
        else {
            std::cout << "\n";
            c.print_errors();
            std::cout << "\n";
        }

        //  In any case, emit the debug information (during early development this is
        //  on by default, later we'll flip the switch to turn it on instead of off)
        if (enable_debug_output_files) {
            c.debug_print();
        }
    }
}
