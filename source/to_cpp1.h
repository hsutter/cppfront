
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
//  Lowering to Cpp1 syntax
//===========================================================================

#ifndef CPP2_TO_CPP1_H
#define CPP2_TO_CPP1_H

#include "sema.h"
#include <filesystem>

namespace cpp2 {

//-----------------------------------------------------------------------
//
//  Stringingizing helpers
//
//-----------------------------------------------------------------------

auto pad(int padding)
    -> std::string_view
{
    if (padding < 1) {
        return "";
    }

    return {
        indent_str.c_str(),
        _as<size_t>( std::min( padding, _as<int>(std::ssize(indent_str))) )
    };
}

auto multi_return_type_name(declaration_node const& n)
    -> std::string
{
    //  When generating a multi-return struct, also enable multi-return
    //  from a (), [], or * operator. We can expand this in the future,
    //  but with care because most operators should 'do as the ints do'
    //  (e.g., it doesn't seem sensible for == to return multiple values)
    constexpr std::pair<std::string_view, std::string_view> canonized_names[] = {
        { "operator()", "operator_call"        },
        { "operator[]", "operator_subscript"   },
        { "operator*",  "operator_dereference" }
    };

    assert (n.is_function() && n.name());
    auto ret = n.name()->to_string();
    for (auto [op, canon] : canonized_names) {
        if (ret == op) {
            ret = canon;
            break;
        }
    }
    ret += "_ret";

    return ret;
}


//-----------------------------------------------------------------------
//
//  positional_printer: a Syntax 1 pretty printer
//
//-----------------------------------------------------------------------
//
static auto flag_emit_cppfront_info = false;
static cmdline_processor::register_flag cmd_emit_cppfront_info(
    8,
    "emit-cppfront-info",
    "Emit cppfront version/build in Cpp1 file",
    []{ flag_emit_cppfront_info = true; }
);

static auto flag_clean_cpp1 = false;
static cmdline_processor::register_flag cmd_clean_cpp1(
    8,
    "clean-cpp1",
    "Emit clean Cpp1 without #line directives",
    []{ flag_clean_cpp1 = true; }
);

static auto flag_line_paths = false;
static cmdline_processor::register_flag cmd_line_paths(
    8,
    "line-paths",
    "Emit absolute paths in #line directives",
    [] { flag_line_paths = true; }
);

static auto flag_import_std = false;
static cmdline_processor::register_flag cmd_import_std(
    0,
    "import-std",
    "import all std:: via 'import std;' - ignored if -include-std is set",
    []{ flag_import_std = true; }
);

static auto flag_include_std = false;
static cmdline_processor::register_flag cmd_include_std(
    0,
    "include-std",
    "#include all std:: headers",
    []{ flag_include_std = true; }
);

static auto flag_cpp2_only = false;
static cmdline_processor::register_flag cmd_cpp2_only(
    0,
    "pure-cpp2",
    "Allow Cpp2 syntax only - also sets -import-std",
    []{ flag_cpp2_only = true; flag_import_std = true; }
);

static auto flag_safe_null_pointers = true;
static cmdline_processor::register_flag cmd_safe_null_pointers(
    2,
    "no-null-checks",
    "Disable null safety checks",
    []{ flag_safe_null_pointers = false; }
);

static auto flag_safe_subscripts = true;
static cmdline_processor::register_flag cmd_safe_subscripts(
    2,
    "no-subscript-checks",
    "Disable subscript safety checks",
    []{ flag_safe_subscripts = false; }
);

static auto flag_safe_comparisons = true;
static cmdline_processor::register_flag cmd_safe_comparisons(
    2,
    "no-comparison-checks",
    "Disable mixed-sign comparison safety checks",
    []{ flag_safe_comparisons = false; }
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
    8,
    "output filename",
    "Output to 'filename' (can be 'stdout') - default is *.cpp/*.h",
    nullptr,
    [](std::string const& name) { flag_cpp1_filename = name; }
);

static auto flag_verbose = false;
static cmdline_processor::register_flag cmd_verbose(
    9,
    "verbose",
    "Print verbose output and statistics",
    []{ flag_verbose = true; }
);

static auto flag_no_exceptions = false;
static cmdline_processor::register_flag cmd_no_exceptions(
    4,
    "fno-exceptions",
    "Disable C++ EH - failed 'as' for 'variant' will assert",
    []{ flag_no_exceptions = true; }
);

static auto flag_no_rtti = false;
static cmdline_processor::register_flag cmd_no_rtti(
    4,
    "fno-rtti",
    "Disable C++ RTTI - using 'as' for '*'/'std::any' will assert",
    []{ flag_no_rtti = true; }
);

struct text_with_pos{
    std::string     text;
    source_position pos;
    text_with_pos(std::string const& t, source_position p) : text{t}, pos{p} { }
};

class positional_printer
{
public:
    positional_printer()                          = default;
private:
    positional_printer(positional_printer const&) = delete;
    void operator=(positional_printer const&)     = delete;

    //  Core information
    std::ofstream               out_file        = {}; // Cpp1 syntax output file
    std::ostream*               out             = {}; // will point to out_file or cout
    std::string                 cpp2_filename   = {};
    std::string                 cpp1_filename   = {};
    std::vector<comment> const* pcomments       = {}; // Cpp2 comments data
    source const*               psource         = {};
    parser const*               pparser         = {};

    source_position curr_pos                    = {}; // current (line,col) in output
    lineno_t        generated_pos_line          = {}; // current line in generated output
    int             last_line_indentation       = {};
    int             next_comment                = 0;  // index of the next comment not yet printed
    bool            last_was_empty              = false;
    int             empty_lines_suppressed      = 0;
    bool            just_printed_line_directive = false;
    bool            printed_extra               = false;
    char            last_printed_char           = {};

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

public:
    //  Modal information
    enum phases {
        phase0_type_decls           = 0,
        phase1_type_defs_func_decls = 1,
        phase2_func_defs            = 2
    };
    auto get_phase() const { return phase; }

private:
    phases phase = phase0_type_decls;

    auto inc_phase() -> void {
        switch (phase) {
        break;case phase0_type_decls          : phase = phase1_type_defs_func_decls;
        break;case phase1_type_defs_func_decls: phase = phase2_func_defs;
        break;default                         : assert(!"ICE: invalid lowering phase");
        }
        curr_pos     = {};
        next_comment = 0;   // start over with the comments
    }

    std::vector<std::string*>                emit_string_targets;       // option to emit to string instead of out file
    std::vector<std::vector<text_with_pos>*> emit_text_chunks_targets;  // similar for vector<text_pos>

    enum class target_type { string, chunks };
    std::vector<target_type>                 emit_target_stack;         // to interleave them sensibly


    //-----------------------------------------------------------------------
    //  Print text
    //
    auto print(
        std::string_view s,
        source_position  pos = source_position{},
        bool             track_curr_pos = true,
        bool             is_known_empty = false
    )
        -> void
    {
        //  Take ownership of (and reset) just_printed_line_directive value
        auto line_directive_already_done = std::exchange(just_printed_line_directive, false);

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

        if (s.length() > 0) {
            last_printed_char = s.back();
        }

        //  Reject consecutive empty lines: If this line is empty
        if (
            ( s == "\n" || is_known_empty )
            && curr_pos.colno <= 1
            )
        {
            //  And so was the last one, update logical position only
            //  and increment empty_lines_suppressed instead of printing
            if (last_was_empty) {
                if (track_curr_pos) {
                    ++curr_pos.lineno;
                    curr_pos.colno = 1;
                }
                ++empty_lines_suppressed;
                return;
            }
            //  If this is the first consecutive empty, remember and continue
            last_was_empty = true;
        }
        //  Otherwise, if this line is not empty
        else {
            //  Remember that this line was not empty
            last_was_empty = false;

            //  And if we did suppress any empties, emit a #line to resync
            if (empty_lines_suppressed > 0) {
                if (!line_directive_already_done) {
                    print_line_directive(curr_pos.lineno);
                }
                empty_lines_suppressed = 0;
            }
        }

        //  Output the string
        assert (out);
        *out << s;

        //  Update curr_pos by finding how many line breaks s contained,
        //  and where the last one was which determines our current colno
        if (track_curr_pos)
        {
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
                curr_pos.colno = unsafe_narrow<colno_t>(s.length() - last_newline);
            }
            else {
                //  Else add the length of the string
                curr_pos.colno += unsafe_narrow<colno_t>(s.length());
            }
        }
    }


    //-----------------------------------------------------------------------
    //  Internal helpers

    //  Start a new line if we're not in col 1 already
    //
    auto ensure_at_start_of_new_line()
        -> void
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
    auto print_line_directive( lineno_t line )
        -> void
    {
        //  Ignore requests from generated code (negative line numbers)
        if (line < 1) {
            return;
        }

        //  Otherwise, implement the request
        prev_line_info = { curr_pos.lineno, { } };
        ensure_at_start_of_new_line();

        //  Not using print() here because this is transparent to the curr_pos
        if (!flag_clean_cpp1) {
            assert (out);
            *out << "#line " << line << " " << std::quoted(cpp2_filename) << "\n";
        }
        just_printed_line_directive = true;
    }

    //  Catch up with comment/blank lines
    //
    auto print_comment(comment const& c)
        -> void
    {
        //  For a line comment, start it at the right indentation and print it
        //  with a newline end
        if (c.kind == comment::comment_kind::line_comment) {
            print( pad( c.start.colno - curr_pos.colno + 1 ) );
            print( c.text );
            assert( c.text.find("\n") == std::string::npos );  // we shouldn't have newlines
            print("\n");
        }

        //  For a stream comment, pad out to its column (if we haven't passed it already)
        //  and emit it there
        else {
            print( pad( c.start.colno - curr_pos.colno ) );
            print( c.text );
        }

        c.dbg_was_printed = true;
    }

    auto flush_comments( source_position pos )
        -> void
    {
        if (!pcomments) {
            return;
        }

        //  For convenience
        auto& comments = *pcomments;

        //  Add unprinted comments and blank lines as needed to catch up vertically
        //
        while (curr_pos.lineno < pos.lineno)
        {
            //  If a comment goes on this line, print it
            if (
                next_comment < std::ssize(comments)
                && comments[next_comment].start.lineno <= curr_pos.lineno
                )
            {
                //  Emit non-function body comments in phase1_type_defs_func_decls,
                //  and emit function body comments in phase2_func_defs
                assert(pparser);
                if (
                    (
                        phase == phase1_type_defs_func_decls
                        && !pparser->is_within_function_body( comments[next_comment].start.lineno )
                        )
                    ||
                    (
                        phase == phase2_func_defs
                        && pparser->is_within_function_body( comments[next_comment].start.lineno )
                        )
                    )
                {
                    print_comment( comments[next_comment] );
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

    auto print_unprinted_comments()
    {
        for (auto const& c : *pcomments) {
            if (!c.dbg_was_printed) {
                print_comment(c);
            }
        }
    }

    //  Position ourselves as close to pos as possible,
    //  and catch up with displaying comments
    //
    auto align_to( source_position pos )
        -> void
    {
        auto on_same_line = curr_pos.lineno == pos.lineno;

        //  Ignoring this logic is used when we're generating new code sections,
        //  such as return value structs, and emitting raw string literals
        if (ignore_align) {
            print( pad( ignore_align_indent - curr_pos.colno ) );
            return;
        }

        //  Otherwise, we need to apply our usual alignment logic

        //  Catch up with displaying comments
        flush_comments( pos );

        //  If we're not on the right line
        if (
            printed_extra
            && !on_same_line
            )
        {
            print_line_directive(pos.lineno);
            curr_pos.lineno = pos.lineno;
            printed_extra = false;
        }
        else if (curr_pos.lineno < pos.lineno)
        {
            //  In case we're just one away, try a blank line
            //  (this might get ignored and we'll get the line directive)
            print( "\n" );
            if (curr_pos.lineno != pos.lineno) {
                print_line_directive(pos.lineno);
            }
            curr_pos.lineno = pos.lineno;
        }

        //  Finally, align to the target column, if we're on the right line
        //  and not one-past-the-end on the extra line at section end)
        assert(
            psource
            && 0 <= curr_pos.lineno
            && curr_pos.lineno < std::ssize(psource->get_lines())+1
        );
        if (
            curr_pos.lineno == pos.lineno
            && curr_pos.lineno < std::ssize(psource->get_lines())
            )
        {
            //  Record this line's indentation as the 'last' line for next time
            last_line_indentation = psource->get_lines()[curr_pos.lineno].indent();

            //  If this line was originally densely spaced (had <2 whitespace
            //  between all tokens), then the programmer likely wasn't doing a lot
            //  of special formatting...
            if (psource->get_lines()[curr_pos.lineno].all_tokens_are_densely_spaced)
            {
                //  For the first token in a line, use the line's original indentation
                if (curr_pos.colno <= 1)
                {
                    print( pad( psource->get_lines()[curr_pos.lineno].indent() ) );
                }
                //  For later tokens, don't try to add padding
                else {
                    if (
                        last_printed_char == ';'
                        && on_same_line
                        )
                    {
                        print( " " );
                    }
                }
            }
            //  Otherwise, make a best effort to adjust position with some padding
            else
            {
                pos.colno = std::max( 1, pos.colno + pad_for_this_line );
                print( pad( pos.colno - curr_pos.colno ) );
            }
        }
    }


public:
    //-----------------------------------------------------------------------
    //  Finalize phase
    //
    auto finalize_phase(bool print_remaining_comments = false)
    {
        if (
            is_open()
            && psource
            && psource->has_cpp2()
            )
        {
            flush_comments( {curr_pos.lineno+1, 1} );

            if (print_remaining_comments) {
                print_unprinted_comments();
            }

            //  Always make sure the very last line ends with a newline
            //  (not really necessary but makes some tools quieter)
            //  -- but only if there's any Cpp2, otherwise don't
            //  because passing through all-Cpp1 code should always
            //  remain diff-identical
            if (phase == phase2_func_defs) {
                print_extra("\n");
            }
        }
    }


    //-----------------------------------------------------------------------
    //  Open
    //
    auto open(
        std::string                 cpp2_filename_,
        std::string                 cpp1_filename_,
        std::vector<comment> const& comments,
        cpp2::source const&         source,
        cpp2::parser const&         parser
    )
        -> void
    {
        cpp2_filename = (flag_line_paths) ?
            std::filesystem::absolute(std::filesystem::path(cpp2_filename_)).string() :
            cpp2_filename_;
        assert(
            !is_open()
            && !pcomments
            && "ICE: tried to call .open twice"
        );
        cpp1_filename = cpp1_filename_;
        if (cpp1_filename == "stdout") {
            out = &std::cout;
        }
        else {
            out_file.open(cpp1_filename);
            out = &out_file;
        }
        pcomments = &comments;
        psource   = &source;
        pparser   = &parser;
    }

    auto reopen()
        -> void
    {
        assert(
            is_open()
            && "ICE: tried to call .reopen without first calling .open"
        );
        assert(cpp1_filename.ends_with(".h"));
        out_file.close();
        out_file.open(cpp1_filename + "pp");
    }

    auto is_open()
        -> bool
    {
        if (out) {
            assert(
                pcomments
                && "ICE: if is_open, pcomments should also be set"
            );
        }
        return out;
    }


    //-----------------------------------------------------------------------
    //  Abandon: close and delete
    //
    auto abandon()
        -> void
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
    auto print_extra( std::string_view s )
        -> void
    {
        assert(
            is_open()
            && "ICE: printer must be open before printing"
        );
        print( s, source_position{}, false );
        printed_extra = true;
    }


    //-----------------------------------------------------------------------
    //  Print a Cpp1 line, which should be at lineno
    //
    auto print_cpp1( std::string_view s, lineno_t line )
        -> void
    {
        assert(
            is_open()
            && line >= 0
            && "ICE: printer must be open before printing, and line number must not be negative (Cpp1 code is never generated)"
        );

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
    //  Used when we start a new Cpp2 section, or when we emit the same item
    //  more than once (notably when we emit operator= more than once)
    //
    auto reset_line_to(lineno_t line, bool force = false)
        -> void
    {
        //  Always start a Cpp2 section on its own new line
        ensure_at_start_of_new_line();

        //  If we are out of sync with the current logical line number,
        //  emit a #line directive to re-sync
        if (
            force
            || curr_pos.lineno != line
            )
        {
            print_line_directive( line );
            curr_pos.lineno = line;
        }

        assert (curr_pos.colno == 1);
    }


    //-----------------------------------------------------------------------
    //  Print a Cpp2 item, which should be at pos
    //
    auto print_cpp2(
        std::string_view s,
        source_position  pos,
        bool             leave_newlines_alone = false,
        bool             is_known_empty = false

    )
        -> void
    {
        //  If we're printing for real (not to a string target)
        if (emit_target_stack.empty())
        {
            //  If we're in a generated text region (signified by negative
            //  line numbers), then shunt this call to print_extra instead
            if (pos.lineno < 1) {
                if (generated_pos_line != pos.lineno) {
                    *out << "\n" + std::string(last_line_indentation, ' ');
                    generated_pos_line = pos.lineno;
                }
                print_extra(s);
                return;
            }

            //  Otherwise, we're no longer in generated code, so reset the
            //  generated code counter
            generated_pos_line = {};
        }

        assert(
            is_open()
            && "ICE: printer must be open before printing"
        );

        //  If there are any embedded newlines, split this string into
        //  separate print_cpp2 calls
        if (auto newline_pos = s.find('\n');
            !leave_newlines_alone
            && s.length() > 1
            && newline_pos != s.npos
            )
        {
            while (newline_pos != std::string_view::npos)
            {
                //  Print the text before the next newline
                if (newline_pos > 0) {
                    print_cpp2( s.substr(0, newline_pos), pos );
                }

                //  Emit the newline as a positioned empty string
                assert (s[newline_pos] == '\n');
                ++pos.lineno;
                pos.colno = 1;
                print_cpp2( "", pos, false, curr_pos.colno <= 1 );

                s.remove_prefix( newline_pos+1 );
                newline_pos = s.find('\n');
            }
            //  Print any tail following the last newline
            if (!s.empty()) {
                print_cpp2( s, pos );
            }
            return;
        }

        //  The rest of this call handles a single chunk that's either a
        //  standalone "\n" or a piece of text that doesn't have a newline

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
            else if (
                last_pos.lineno == pos.lineno-1
                && enable_indent_heuristic
                )
            {
                //  If the last line had a request for this colno, remember its actual offset
                constexpr int sentinel = -100;
                auto last_line_offset = sentinel;
                for(auto i = 0;
                    i < std::ssize(prev_line_info.requests)
                        && prev_line_info.requests[i].requested <= pos.colno;
                    ++i
                    )
                {
                    if (prev_line_info.requests[i].requested == pos.colno)
                    {
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

        print(s, pos, true, is_known_empty );
    }


    //-----------------------------------------------------------------------
    //  Position override control functions
    //

    //  Use this position instead of the next supplied one
    //  Useful when Cpp1 syntax is emitted in a different order/verbosity
    //  than Cpp2 such as with declarations
    //
    auto preempt_position_push(source_position pos)
        -> void
    {
        preempt_pos.push_back( pos );
    }

    auto preempt_position_pop()
        -> void
    {
        assert(!preempt_pos.empty());
        preempt_pos.pop_back();
    }

    //  Add (or, if negative, subtract) padding for the current line only
    //
    auto add_pad_in_this_line(colno_t extra)
        -> void
    {
        pad_for_this_line += extra;
    }

    //  Enable indent heuristic for just this line
    //
    auto disable_indent_heuristic_for_next_text()
        -> void
    {
        enable_indent_heuristic = false;
    }

    //  Ignore position information, usually when emitting generated code
    //  such as generated multi-return type structs
    //
    auto ignore_alignment(
        bool ignore,
        int  indent = 0
    )
        -> void
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
            curr_pos.lineno     = ignore_align_lineno;  // pop state
        }
    }


    //-----------------------------------------------------------------------
    //  Modal state control functions
    //

    auto next_phase()
        -> void
    {
        inc_phase();
    }

    //  Provide an option to store to a given string instead, which is
    //  useful for capturing Cpp1-formatted output for generated code
    //
    auto emit_to_string( std::string* target = {} )
        -> void
    {
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
    auto emit_to_text_chunks( std::vector<text_with_pos>* target = {} )
        -> void
    {
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
struct function_prolog {
    std::vector<std::string> mem_inits  = {};
    std::vector<std::string> statements = {};
};

class cppfront
{
    std::string              sourcefile;
    std::vector<error_entry> errors;

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

    declaration_node const* having_signature_emitted = {};

    declaration_node const*   generating_assignment_from      = {};
    declaration_node const*   generating_move_from            = {};
    declaration_node const*   generating_postfix_inc_dec_from = {};
    bool                      emitting_that_function          = false;
    bool                      emitting_move_that_function     = false;
    std::vector<token const*> already_moved_that_members      = {};

    struct arg_info {
        passing_style pass   = passing_style::in;
        token const*  ptoken = {};
    };
    std::vector<arg_info> current_args  = { {} };

    struct active_using_declaration {
        token const* identifier = {};

        explicit active_using_declaration(using_statement_node const& n) {
          if (auto id = get_if<id_expression_node::qualified>(&n.id->id)) {
              identifier = (*id)->ids.back().id->identifier;
          }
        }
    };

    using source_order_name_lookup_res =
        std::optional<std::variant<declaration_node const*, active_using_declaration>>;

    //  Stack of the currently active nested declarations we're inside
    std::vector<declaration_node const*> current_declarations = { {} };

    //  Stack of the currently active names for source order name lookup:
    //  Like 'current_declarations' + also parameters and using declarations
    std::vector<source_order_name_lookup_res::value_type> current_names = { {} };

    //  Maintain a stack of the functions we're currently processing, which can
    //  be up to MaxNestedFunctions in progress (if we run out, bump the Max).
    //  The main reason for this is to be able to pass function_info's, especially
    //  their .epilog, by reference for performance while still having lifetime safety
    struct function_info
    {
        declaration_node const*                    decl                         = {};
        function_type_node const*                  func                         = {};
        declaration_node::declared_value_set_funcs declared_value_set_functions = {};
        function_prolog                            prolog                       = {};
        std::vector<std::string>                   epilog                       = {};
        int                                        ordinal                      = {};

        function_info(
            declaration_node const*                    decl_,
            function_type_node const*                  func_,
            declaration_node::declared_value_set_funcs declared_value_set_functions_
        )
            : decl{decl_}
            , func{func_}
            , declared_value_set_functions{declared_value_set_functions_}
        { }
    };
    class current_functions_
    {
        std::deque<function_info> list = { {} };
    public:
        auto push(
            declaration_node const*                    decl,
            function_type_node const*                  func,
            declaration_node::declared_value_set_funcs thats
        ) {
            list.emplace_back(decl, func, thats);
        }

        auto pop() {
            list.pop_back();
        }

        auto back() -> function_info& {
            assert(!empty());
            return list.back();
        }

        auto empty() -> bool {
            return list.empty();
        }
    };
    current_functions_ current_functions;

    //  For lowering
    //
    positional_printer printer;
    bool               in_definite_init  = false;
    bool               in_parameter_list = false;

    struct function_return {
        parameter_declaration_list_node* param_list;
        passing_style                    pass;
        bool                             is_deduced;

        function_return(
            parameter_declaration_list_node* param_list_,
            passing_style                    pass_ = passing_style::invalid,
            bool                             is_deduced_ = false
        )
            : param_list{param_list_}
            , pass{pass_}
            , is_deduced{is_deduced_}
        { }
    };
    std::vector<function_return>         function_returns;
    parameter_declaration_list_node      single_anon;
        //  special value - hack for now to note single-anon-return type kind in this function_returns working list
    std::vector<std::string>                      function_requires_conditions;

    struct iter_info {
        iteration_statement_node const* stmt;
        bool used = false;
    };
    std::vector<iter_info> iteration_statements;

    std::vector<bool>                             in_non_rvalue_context   = { false };
    std::vector<bool>                             in_single_unqualified_id_return  = { false };
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
        , source    { errors }
        , tokens    { errors }
        , parser    { errors }
        , sema      { errors }
    {
        //  "Constraints enable creativity in the right directions"
        //  sort of applies here
        //
        if (
            !sourcefile.ends_with(".cpp2")
            && !sourcefile.ends_with(".h2")
            )
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
                            "parse failed for section starting here",
                            false,
                            true    // a noisy fallback error message
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
    auto lower_to_cpp1()
        -> lower_to_cpp1_ret
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
            source,
            parser
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


        //---------------------------------------------------------------------
        //  Do lowered file prolog
        //
        //  Only emit extra lines if we actually have Cpp2, because
        //  we want Cpp1-only files to pass through with zero changes
        //  (unless the user requested import/include of std)
        if (
            source.has_cpp2()
            || flag_import_std
            || flag_include_std
            )
        {
            if (flag_emit_cppfront_info) {
                printer.print_extra(
                    "\n// Generated by cppfront "
                    #include "version.info"
                    " build "
                    #include "build.info"
                );
            }
            printer.print_extra( "\n" );
            if (cpp1_filename.back() == 'h') {
                printer.print_extra( "#ifndef " + cpp1_FILENAME+"_CPP2\n");
                printer.print_extra( "#define " + cpp1_FILENAME+"_CPP2" + "\n\n" );
            }

            if (flag_use_source_location) {
                printer.print_extra( "#define CPP2_USE_SOURCE_LOCATION Yes\n" );
            }

            if (flag_include_std) {
                printer.print_extra( "#define CPP2_INCLUDE_STD         Yes\n" );
            }
            else if (flag_import_std) {
                printer.print_extra( "#define CPP2_IMPORT_STD          Yes\n" );
            }

            if (flag_no_exceptions) {
                printer.print_extra( "#define CPP2_NO_EXCEPTIONS       Yes\n" );
            }

            if (flag_no_rtti) {
                printer.print_extra( "#define CPP2_NO_RTTI             Yes\n" );
            }
        }

        auto map_iter = tokens.get_map().cbegin();
        auto hpp_includes = std::string{};


        //---------------------------------------------------------------------
        //  Do phase0_type_decls
        assert(printer.get_phase() == printer.phase0_type_decls);

        if (
            source.has_cpp2()
            && !flag_clean_cpp1
            )
        {
            printer.print_extra( "\n//=== Cpp2 type declarations ====================================================\n\n" );
        }

        if (
            !tokens.get_map().empty()
            || flag_import_std
            || flag_include_std
            )
        {
            printer.print_extra( "\n#include \"cpp2util.h\"\n\n" );
        }

        if (
            source.has_cpp2()
            && !flag_clean_cpp1
            )
        {
            printer.reset_line_to(1, true);
        }

        for (auto& section : tokens.get_map())
        {
            assert (!section.second.empty());

            //  Get the parse tree for this section and emit each forward declaration
            auto decls = parser.get_parse_tree_declarations_in_range(section.second);
            for (auto& decl : decls) {
                assert(decl);
                emit(*decl);
            }
        }


        //---------------------------------------------------------------------
        //  Do phase1_type_defs_func_decls
        //
        printer.finalize_phase();
        printer.next_phase();

        if (
            source.has_cpp2()
            && !flag_clean_cpp1
            )
        {
            printer.print_extra( "\n//=== Cpp2 type definitions and function declarations ===========================\n\n" );
            printer.reset_line_to(1, true);
        }

        assert (printer.get_phase() == positional_printer::phase1_type_defs_func_decls);
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
                    if (
                        source.has_cpp2()
                        && line.cat != source_line::category::preprocessor
                        )
                    {
                        ++ret.cpp2_lines;
                    }
                    else
                    {
                        ++ret.cpp1_lines;
                    }

                    if (
                        flag_cpp2_only
                        && !line.text.empty()
                        && line.cat != source_line::category::comment
                        && line.cat != source_line::category::import
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

                    if (
                        line.cat == source_line::category::preprocessor
                        && line.text.ends_with(".h2\"")
                        )
                    {
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
                    if (
                        map_iter != tokens.get_map().cend()
                        && map_iter->first /*line*/ <= curr_lineno
                        )
                    {
                        //  We should be here only when we're at exactly the first line of a Cpp2 section
                        assert (map_iter->first == curr_lineno);
                        assert (!map_iter->second.empty());

                        //  Get the parse tree for this section and emit each forward declaration
                        auto decls = parser.get_parse_tree_declarations_in_range(map_iter->second);
                        for (auto& decl : decls) {
                            assert(decl);
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

        //  First, if this is a .h2 and in a -pure-cpp2 compilation,
        //  we need to switch filenames
        if (
            cpp1_filename.back() == 'h'
            && flag_cpp2_only
            )
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

            printer.print_extra( "\n#ifndef " + cpp1_FILENAME+"_CPP2" );
            printer.print_extra( "\n#error This file is part of a '.h2' header compiled to be consumed from another -pure-cpp2 file. To use this file, write '#include \"" + cpp1_filename + "2\"' in a '.h2' or '.cpp2' file compiled with -pure-cpp2."  );
            printer.print_extra( "\n#endif\n" );

            cpp1_FILENAME += "PP";
            printer.print_extra( "\n#ifndef " + cpp1_FILENAME+"_CPP2" );
            printer.print_extra( "\n#define " + cpp1_FILENAME+"_CPP2" + "\n\n" );

            printer.print_extra( hpp_includes );
        }


        //---------------------------------------------------------------------
        //  Do phase2_func_defs
        //
        printer.finalize_phase();
        printer.next_phase();

        if (
            source.has_cpp2()
            && !flag_clean_cpp1
            )
        {
            printer.print_extra( "\n//=== Cpp2 function definitions =================================================\n\n" );
            printer.reset_line_to(1, true);
        }

        for (auto& section : tokens.get_map())
        {
            assert (!section.second.empty());

            //  Get the parse tree for this section and emit each forward declaration
            auto decls = parser.get_parse_tree_declarations_in_range(section.second);
            for (auto& decl : decls) {
                assert(decl);
                emit(*decl);
            }
        }

        if (cpp1_filename.back() == 'h') {
            printer.print_extra( "\n#endif" );
        }

        printer.finalize_phase( true );

        //  Finally, some debug checks
        assert(
            (!errors.empty() || tokens.num_unprinted_comments() == 0)
            && "ICE: not all comments were printed"
        );

        return ret;
    }


    //-----------------------------------------------------------------------
    //
    //  emit() functions - each emits a kind of node
    //
    //  The body often mirrors the node's visit() function, unless customization
    //  is needed where Cpp1 and Cpp2 have different grammar orders
    //

    void print_to_string(
        std::string* str,
        auto&        i,
        auto...      more
    )
    {
        //  Quick special-purpose state preservation... this tactical hack
        //  is fine for now, but if needed more then generalize this
        auto state1 = need_expression_list_parens;
        auto state2 = already_moved_that_members;

        printer.emit_to_string(str);
        emit(i, more...);
        printer.emit_to_string();

        //  Restore state
        need_expression_list_parens.swap(state1);
        already_moved_that_members .swap(state2);
    };

    auto print_to_string(
        auto&   i,
        auto... more
    )
        -> std::string
    {
        auto print = std::string{};
        print_to_string(&print, i, more...);
        return print;
    };

    //-----------------------------------------------------------------------
    //  try_emit
    //
    //  Helper to emit whatever is in a variant where each
    //  alternative is a smart pointer
    //
    template <int I>
    auto try_emit(
        auto&     v,
        auto&&... more
    )
        -> void
    {
        if (v.index() == I) {
            auto const& alt = std::get<I>(v);
            assert (alt);
            emit (*alt, CPP2_FORWARD(more)...);
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(
        token const&    n,
        bool            is_qualified = false,
        source_position pos          = {}
    )
        -> void
    {   STACKINSTR
        if (pos == source_position{}) {
            pos = n.position();
        }

        //  Implicit "cpp2::" qualification of Cpp2 fixed-width type aliases
        //  and cpp2::finally
        if (
            !is_qualified
            && (
                n.type() == lexeme::Cpp2FixedType
                || n == "finally"
                )
            )
        {
            printer.print_cpp2("cpp2::", pos);
        }

        //  'this' is not a pointer
        if (n == "this") {
            printer.print_cpp2("(*this)", pos);
        }
        //  Reclaim the alternative names and some keywords for users
        else if (
            n == "and"
            || n == "and_eq"
            || n == "bitand"
            || n == "bitor"
            || n == "compl"
            || n == "not"
            || n == "not_eq"
            || n == "or"
            || n == "or_eq"
            || n == "xor"
            || n == "xor_eq"
            || n == "new"
            || n == "class"
            || n == "struct"
            || n == "enum"
            || n == "union"
            || n == "default"
            )
        {
            printer.print_cpp2("cpp2_"+n.to_string(), pos);
        }
        else {
            printer.print_cpp2(n, pos, true);
        }

        in_definite_init = is_definite_initialization(&n);
    }


    //-----------------------------------------------------------------------
    //
    auto emit(
        literal_node const& n,
        source_position     pos = {}
    )
        -> void
    {   STACKINSTR
        if (pos == source_position{}) {
            pos = n.position();
        }

        assert(n.literal);
        emit(*n.literal);
        if (n.user_defined_suffix) {
            emit(*n.user_defined_suffix);
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(
        unqualified_id_node const& n,
        int                        synthesized_multi_return_size = 0,
        bool                       is_local_name                 = true,
        bool                       is_qualified                  = false,
        bool                       is_class_member_access        = false
    )
        -> void
    {   STACKINSTR
        assert( n.identifier );
        auto last_use = is_definite_last_use(n.identifier);

        auto decl = sema.get_declaration_of(*n.identifier, false, true);

        bool add_forward =
            last_use
            && last_use->is_forward
            && last_use->safe_to_move
            && !in_non_rvalue_context.back()
            && !is_class_member_access;

        //  We always want to std::move from named return values,
        //  regardless of their types, so use std::move for that
        bool add_std_move =
            synthesized_multi_return_size > 1
            || (
                synthesized_multi_return_size == 1
                && decl
                && !decl->initializer
                );

        //  Otherwise we'll use cpp2::move
        bool add_move =
            !add_forward
            && (
                !last_use
                || last_use->safe_to_move
                )
            && (
                add_std_move
                || (last_use && !suppress_move_from_last_use)
                )
            && !in_non_rvalue_context.back()
            && !is_class_member_access;

        //  Add `cpp2::move(*this).` when implicitly moving a member on last use
        //  This way, members of lvalue reference type won't be implicitly moved
        bool add_this =
            add_move
            && decl
            && decl->identifier
            && *decl->identifier == "this"
            && *n.identifier != "this";

        if (
            add_move
            && in_single_unqualified_id_return.size() > 0
            && in_single_unqualified_id_return.back()
            && (
                !decl
                || decl->initializer
                )
            )
        {
            add_move = false;
        }

        if (
            emitting_move_that_function
            && *n.identifier == "that"
            )
        {
            add_move = true;
        }

        //  For an explicit 'forward' apply forwarding to correct identifier
        assert (!current_args.empty());
        if (current_args.back().pass == passing_style::forward) {
            add_forward = current_args.back().ptoken == n.identifier;
        }

        if (add_std_move) {
            printer.print_cpp2("std::move(", n.position());
        }
        else if (add_move) {
            printer.print_cpp2("cpp2::move(", n.position());
        }

        if (add_forward) {
            printer.print_cpp2("CPP2_FORWARD(", {n.position().lineno, n.position().colno - 8});
        }

        if (add_this) {
            printer.print_cpp2("*this).", n.position());
        }

        assert(n.identifier);
        emit(*n.identifier, is_qualified);  // inform the identifier if we know this is qualified

        if (n.open_angle != source_position{}) {
            printer.print_cpp2("<", n.open_angle);
            auto first = true;
            for (auto& a : n.template_args) {
                if (!first) {
                    printer.print_cpp2(",", a.comma);
                }
                first = false;
                try_emit<template_argument::expression>(a.arg);
                try_emit<template_argument::type_id   >(a.arg);
            }
            printer.print_cpp2(">", n.close_angle);
        }

        in_definite_init = is_definite_initialization(n.identifier);
        if (
            !in_definite_init
            && !in_parameter_list
            )
        {
            if (
                is_local_name
                && !(*n.identifier == "this")
                && !(*n.identifier == "that")
                && decl
                && (
                    synthesized_multi_return_size != 0
                    //  note pointer equality: if we're not in the actual declaration of n.identifier
                    || decl->identifier != n.identifier
                    )
                //  and this variable was uninitialized
                && !decl->initializer
                //  and it's either a non-parameter or an out parameter
                && (
                    !decl->parameter
                    || (
                        decl->parameter
                        && decl->parameter->pass == passing_style::out
                        )
                    )
                )
            {
                printer.print_cpp2(".value()", n.position());
            }
        }
        else if (synthesized_multi_return_size != 0) {
            printer.print_cpp2(".value()", n.position());
        }

        if (
            !add_this
            && (
                add_move
                || add_std_move
                || add_forward
                )
            )
        {
            printer.print_cpp2(")", n.position());
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(
        qualified_id_node const& n,
        bool include_unqualified_id = true
        )
        -> void
    {   STACKINSTR
        if (!sema.check(n)) {
            return;
        }

        auto ident = std::string{};
        printer.emit_to_string(&ident);

        for (auto const& id : std::span{n.ids}.first(n.ids.size() - !include_unqualified_id))
        {
            if (id.scope_op) {
                emit(*id.scope_op);
            }
            emit(*id.id, 0, true, true);    // inform the unqualified-id that it's qualified
        }

        printer.emit_to_string();
        printer.print_cpp2( ident, n.position() );
    }


    //-----------------------------------------------------------------------
    //
    auto emit(
        type_id_node const& n,
        source_position     pos = {}
    )
        -> void
    {   STACKINSTR
        if (pos == source_position{}) {
            pos = n.position();
        }

        if (n.is_wildcard()) {
            printer.print_cpp2("auto", pos);
        }
        else {
            try_emit<type_id_node::unqualified>(n.id, 0, false);
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
    auto emit(
        id_expression_node const& n,
        bool                      is_local_name          = true,
        bool                      is_class_member_access = false
    )
        -> void
    {   STACKINSTR
        try_emit<id_expression_node::qualified  >(n.id);
        try_emit<id_expression_node::unqualified>(n.id, 0, is_local_name, false, is_class_member_access);
    }


    auto emit_prolog_mem_inits(
        function_prolog const& prolog,
        colno_t                indent
    )
        -> void
    {   STACKINSTR
        for (auto& line : prolog.mem_inits) {
            printer.print_extra("\n");
            printer.print_extra(pad(indent-1));
            printer.print_extra(line);
        }
    }

    auto emit_prolog_statements(
        function_prolog const& prolog,
        colno_t                indent
    )
        -> void
    {   STACKINSTR
        for (auto& line : prolog.statements) {
            printer.print_extra("\n");
            printer.print_extra(pad(indent-1));
            printer.print_extra(line);
        }
    }

    auto emit_epilog_statements(
        std::vector<std::string> const& epilog,
        colno_t                         indent
    )
        -> void
    {   STACKINSTR
        for (auto& line : epilog) {
            printer.print_extra("\n");
            printer.print_extra(pad(indent-1));
            printer.print_extra(line);
        }
    }

    //-----------------------------------------------------------------------
    //
    auto emit(
        compound_statement_node  const& n,
        function_prolog          const& function_prolog = {},
        std::vector<std::string> const& function_epilog = {}
    )
        -> void
    {   STACKINSTR
        emit_prolog_mem_inits(function_prolog, n.body_indent+1);

        printer.print_cpp2( "{", n.open_brace );

        emit_prolog_statements(function_prolog, n.body_indent+1);

        for (auto const& x : n.statements) {
            assert(x);
            emit(*x);
        }

        emit_epilog_statements( function_epilog, n.body_indent+1);

        printer.print_cpp2( "}", n.close_brace );
    }


    //-----------------------------------------------------------------------
    //
    auto emit(
        inspect_expression_node const& n,
        bool                           is_expression
    )
        -> void
    {   STACKINSTR
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
        printer.print_cpp2("{ " + constexpr_qualifier + "auto&& _expr = ", n.position());

        assert(n.expression);
        emit(*n.expression);
        printer.print_cpp2(";", n.position());

        assert(
            n.identifier
            && *n.identifier == "inspect"
        );

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

            assert (
                *alt->is_as_keyword == "is"
                || *alt->is_as_keyword == "as"
            );
            // TODO: pick up 'as' next, for now just do 'is'

            if (*alt->is_as_keyword == "is")
            {
                //  Stringize the expression-statement now...
                auto statement = std::string{};
                printer.emit_to_string(&statement);
                emit(*alt->statement);
                printer.emit_to_string();
                //  ... and jettison the final ; for an expression-statement
                while (
                    !statement.empty()
                    && (
                        statement.back() == ';'
                        || isspace(statement.back())
                        )
                    )
                {
                    statement.pop_back();
                }

                replace_all( statement, "cpp2::impl::as_<", "cpp2::impl::as<" );

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
                        printer.print_cpp2("(cpp2::impl::is<" + id + ">(_expr)) ", alt->position());
                    }
                    else {
                        assert (alt->value);
                        printer.print_cpp2("(cpp2::impl::is(_expr, " + id + ")) ", alt->position());
                    }
                    printer.print_cpp2(return_prefix, alt->position());
                }

                printer.print_cpp2(statement, alt->position());

                if (
                    is_expression
                    && id != "auto"
                    )
                {
                    assert(alt->statement->is_expression());
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
    auto emit(selection_statement_node const& n)
        -> void
    {   STACKINSTR
        assert(n.identifier);
        emit(*n.identifier);

        if (n.is_constexpr) {
            printer.print_cpp2(" constexpr", n.position());
        }

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
    auto emit(iteration_statement_node const& n)
        -> void
    {   STACKINSTR
        assert(n.identifier);

        iteration_statements.push_back({ &n, false});
        auto labelname = std::string{};
        if (n.label) {
            labelname = n.label->to_string();
        }

        //  Handle while
        //
        if (*n.identifier == "while") {
            assert(
                n.condition
                && n.statements
                && !n.range
                && !n.body
            );

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
            emit(*n.statements);
            if (!labelname.empty()) {
                printer.print_extra(" CPP2_CONTINUE_BREAK("+labelname+") }");
            }
        }

        //  Handle do
        //
        else if (*n.identifier == "do") {
            assert(
                n.condition
                && n.statements
                && !n.range
                && !n.body
            );

            printer.print_cpp2("do ", n.position());
            if (!labelname.empty()) {
                printer.print_extra("{");
            }
            emit(*n.statements);
            if (!labelname.empty()) {
                printer.print_extra(" CPP2_CONTINUE_BREAK("+labelname+") }");
            }
            printer.print_cpp2(" while ( ", n.position());
            if (n.next_expression) {
                //  Gotta say, this feels kind of nifty... short-circuit eval
                //  and smuggling work into a condition via a lambda, O my...
                printer.print_cpp2("[&]{ ", n.position());
                emit(*n.next_expression);
                printer.print_cpp2(" ; return true; }() && ", n.position());
            }
            emit(*n.condition);
            printer.print_cpp2(");", n.position());
        }

        //  Handle for
        //
        else if (*n.identifier == "for") {
            assert(
                !n.condition
                && !n.statements
                && n.range
                && n.parameter
                && n.body
            );

            //  Note: This used to emit cpp2_range as a range-for-loop scope variable,
            //        but some major compilers seem to have random troubles with that;
            //        the workaround to avoid their bugs for now is to emit a { } block
            //        around the Cpp1 range-for and make the scope variable a normal local

            printer.print_cpp2("for ( ", n.position());

            emit(*n.parameter);

            printer.print_cpp2(" : ", n.position());

            //  If this expression is just a single expression-list, we can
            //  take over direct control of emitting it without needing to
            //  go through the whole grammar, and surround it with braces
            if (n.range->is_expression_list()) {
                printer.print_cpp2( "{ ", n.position() );
                emit(*n.range->get_expression_list(), false);
                printer.print_cpp2( " }", n.position() );
            }
            //  Otherwise, just emit the general expression as usual
            else {
                emit(*n.range);
            }

            printer.print_cpp2(" ) ", n.position());
            if (!labelname.empty()) {
                printer.print_extra("{");
            }

            //  If there's a next-expression, smuggle it in via a nested do/while(false) loop
            //  (nested "continue" will work, but "break" won't until we do extra work to implement
            //  that using a flag and implementing "break" as "_for_break = true; continue;")
            if (n.next_expression) {
                printer.print_cpp2(" { do ", n.position());
            }

            assert(n.body);
            emit(*n.body);

            if (n.next_expression) {
                printer.print_cpp2(" while (false); ", n.position());
                emit(*n.next_expression);
                printer.print_cpp2("; }", n.position());
            }

            printer.print_cpp2("", n.position());
            if (!labelname.empty()) {
                printer.print_extra(" CPP2_CONTINUE_BREAK("+labelname+") }");
            }
        }

        else {
            assert(!"ICE: unexpected case");
        }

        assert (iteration_statements.back().stmt);
        if (
            iteration_statements.back().stmt->label
            && !iteration_statements.back().used
            )
        {
            auto name = iteration_statements.back().stmt->label->to_string();
            errors.emplace_back(
                iteration_statements.back().stmt->position(),
                name + ": a named loop must have its name used (did you forget 'break " + name + ";' or 'continue " + name + "';?)"
            );
        }

        iteration_statements.pop_back();
    }


    //-----------------------------------------------------------------------
    //
    auto emit(return_statement_node const& n)
        -> void
    {   STACKINSTR
        assert (!current_functions.empty());
        if (current_functions.back().func->has_postconditions()) {
            printer.print_cpp2( "cpp2_finally_presuccess.run(); ", n.position() );
        }

        assert(n.identifier);
        assert(*n.identifier == "return");
        printer.print_cpp2("return ", n.position());

        in_single_unqualified_id_return.push_back(
            n.expression
            && n.expression->is_unqualified_id()
        );
        auto guard = finally([&]{ in_single_unqualified_id_return.pop_back(); });

        //  Return with expression == single anonymous return type
        //
        if (n.expression)
        {
            assert(!current_functions.empty());
            auto is_forward_return =
                !function_returns.empty()
                && function_returns.back().pass == passing_style::forward;
            auto is_deduced_return =
                !function_returns.empty()
                && function_returns.back().is_deduced;

            //  If we're doing a forward return of a single-token name
            if (auto tok = n.expression->expr->get_postfix_expression_node()->expr->get_token();
                tok
                && is_forward_return
                )
            {
                //  Ensure we're not returning a local or an in/move parameter
                auto is_parameter_name = current_functions.back().decl->has_parameter_named(*tok);
                if (
                    is_parameter_name
                    && (
                        current_functions.back().decl->has_in_parameter_named(*tok)
                        || current_functions.back().decl->has_move_parameter_named(*tok)
                        )
                    )
                {
                    errors.emplace_back(
                        n.position(),
                        "a 'forward' return type cannot return an 'in' or 'move' parameter"
                    );
                    return;
                }
                else if (
                    !is_parameter_name
                    && sema.get_declaration_of(*tok)
                    && !sema.is_captured(*tok)
                    )
                {
                    errors.emplace_back(
                        n.position(),
                        "a 'forward' return type cannot return a local variable"
                    );
                    return;
                } else if (
                    is_literal(tok->type()) || n.expression->expr->is_result_a_temporary_variable()
                )
                {
                    errors.emplace_back(
                        n.position(),
                        "a 'forward' return type cannot return a temporary variable"
                    );
                    return;
                }
            }

            //  If this expression is just a single expression-list, we can
            //  take over direct control of emitting it without needing to
            //  go through the whole grammar, and surround it with braces
            if (n.expression->is_expression_list()) {
                if (!is_deduced_return) {
                    printer.print_cpp2( "{ ", n.position() );
                }
                emit(*n.expression->get_expression_list(), false);
                if (!is_deduced_return) {
                    printer.print_cpp2( " }", n.position() );
                }
            }
            //  Otherwise, just emit the general expression as usual
            else {
                emit(*n.expression);
            }

            if (
                function_returns.empty()
                || function_returns.back().param_list != &single_anon
                )
            {
                errors.emplace_back(
                    n.position(),
                    "return statement with expression must be in a function with a single anonymous return value"
                );
                return;
            }
        }

        else if (
            !function_returns.empty()
            && function_returns.back().param_list == &single_anon
            )
        {
            errors.emplace_back(
                n.position(),
                "return statement must have an expression in a function with a single anonymous return value"
            );
        }

        //  Return without expression, could be assignment operator
        //
        else if (generating_assignment_from == current_functions.back().decl)
        {
            printer.print_cpp2("*this", n.position());
        }

        //  Otherwise, zero or named return values
        //
        else if (
            !function_returns.empty()
            && function_returns.back().param_list
            )
        {
            auto& parameters = function_returns.back().param_list->parameters;

            auto stmt = std::string{};

            //  Put braces only around multiple named returns, which are a struct
            //  - single named returns are emitted as ordinary returns, and extra
            //  { } would be legal but generate a noisy warning on some compilers
            if (std::ssize(parameters) > 1) {
                stmt += std::string(" { ");
            }

            for (bool first = true; auto& param : parameters) {
                if (!first) {
                    stmt += ", ";
                }
                first = false;
                assert(param->declaration->identifier);

                printer.emit_to_string(&stmt);
                emit(*param->declaration->identifier, cpp2::unsafe_narrow<int>(parameters.size()));
                printer.emit_to_string();
            }

            if (std::ssize(parameters) > 1) {
                stmt += std::string(" }");
            }

            printer.print_cpp2(stmt, n.position());
        }

        printer.print_cpp2("; ", n.position());
    }


    //-----------------------------------------------------------------------
    //
    auto emit(jump_statement_node const& n)
        -> void
    {   STACKINSTR
        assert(n.keyword);

        if (n.label) {
            auto iter_stmt =
                std::find_if(
                    iteration_statements.begin(),
                    iteration_statements.end(),
                    [&](auto& s){
                        assert(s.stmt);
                        return
                            s.stmt->label
                            && std::string_view{*s.stmt->label} == std::string_view{*n.label}
                            ;
                    }
                );
            if (iter_stmt == iteration_statements.end())
            {
                errors.emplace_back(
                    n.position(),
                    "a named " + n.keyword->to_string() + " must use the name of an enclosing local loop label"
                );
                return;
            }
            iter_stmt->used = true;
            assert((*iter_stmt).stmt->label);
            printer.print_cpp2(
                "goto " + to_upper_and_underbar(*n.keyword) + "_" + (*iter_stmt).stmt->label->to_string() + ";",
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
    auto emit(using_statement_node const& n)
        -> void
    {   STACKINSTR
        assert(n.keyword);
        emit(*n.keyword);

        if (n.for_namespace) {
            printer.print_cpp2(" namespace", n.position());
        } else {
            current_names.push_back(active_using_declaration{n});
        }

        printer.print_cpp2(" " + print_to_string(*n.id) + ";", n.position());
    }


    //-----------------------------------------------------------------------
    //
    auto build_capture_lambda_intro_for(
        capture_group&  captures,
        source_position pos,
        bool            include_default_reference_capture = false
    )
        -> std::string
    {
        //  First calculate the stringized version of each capture expression
        //  This will let us compare and de-duplicate repeated capture expressions
        for (auto& cap : captures.members)
        {
            assert(cap.capture_expr->cap_grp == &captures);
            if (cap.str.empty()) {
                print_to_string(&cap.str, *cap.capture_expr, true);
                suppress_move_from_last_use = true;
                print_to_string(&cap.str_suppressed_move, *cap.capture_expr, true);
                suppress_move_from_last_use = false;
            }
        }

        // If move from last use was used on the variable we need to rewrite the str to add std::move
        // to earlier use of the variable. That will save us from capturing one variable two times
        // (one with copy and one with std::move).
        for (auto rit = captures.members.rbegin(); rit != captures.members.rend(); ++rit)
        {
            auto is_same_str_suppressed_move = [s=rit->str_suppressed_move](auto& cap){
                return cap.str_suppressed_move == s;
            };

            auto rit2 = std::find_if(rit+1, captures.members.rend(), is_same_str_suppressed_move);
            while (rit2 != captures.members.rend())
            {
                rit2->str = rit->str;
                rit2 = std::find_if(rit2+1, captures.members.rend(), is_same_str_suppressed_move);
            }
        }

        //  Then build the capture list, ignoring duplicated expressions
        auto lambda_intro = std::string("[");
        auto num_captures = 0;

        if (
            (!current_functions.empty()
                && current_functions.back().decl->is_function_with_this()
                && !current_functions.back().decl->parent_is_namespace()
                )
            || include_default_reference_capture
            )
        {
            //  Note: & is needed (when allowed, not at namespace scope) because a
            //  nested UFCS might be viewed as trying to capture 'this'
            lambda_intro += "&";
            ++num_captures;
        }

        printer.emit_to_string(&lambda_intro);

        auto handled = std::vector<std::string>{};
        for (auto& cap : captures.members)
        {
            //  If we haven't handled a capture that looks like this one
            if (std::find(handled.begin(), handled.end(), cap.str) == handled.end())
            {
                //  Remember it
                handled.push_back(cap.str);

                //  And handle it
                if (num_captures != 0) { // not first
                    lambda_intro += ", ";
                }
                cap.cap_sym = "_"+std::to_string(num_captures);
                printer.print_cpp2(cap.cap_sym + " = " + cap.str, pos);
            }
            ++num_captures;
        }
        printer.emit_to_string();
        lambda_intro += "]";

        return lambda_intro;
    }


    //-----------------------------------------------------------------------
    //
    auto emit(primary_expression_node const& n)
        -> void
    {   STACKINSTR
        try_emit<primary_expression_node::identifier     >(n.expr);
        try_emit<primary_expression_node::expression_list>(n.expr);
        try_emit<primary_expression_node::id_expression  >(n.expr);
        try_emit<primary_expression_node::inspect        >(n.expr, true);
        try_emit<primary_expression_node::literal        >(n.expr);

        if (n.expr.index() == primary_expression_node::declaration)
        {
            //  This must be an anonymous declaration
            auto& decl = std::get<primary_expression_node::declaration>(n.expr);
            assert(
                decl
                && !decl->identifier
            );

            //  Handle an anonymous function
            if (decl->is_function()) {
                auto lambda_intro = build_capture_lambda_intro_for(decl->captures, n.position());

                // Handle an anonymous generic function with explicit type list
                if (decl->template_parameters) {
                    print_to_string(&lambda_intro, *decl->template_parameters, false, true);
                }

                emit(*decl, lambda_intro);
            }
            //  Else an anonymous object as 'typeid { initializer }'
            else {
                assert(decl->is_object());
                auto& type_id = std::get<declaration_node::an_object>(decl->type);

                printer.add_pad_in_this_line( -5 );

                emit(*type_id);
                printer.print_cpp2("{", decl->position());

                if (!decl->initializer) {
                    errors.emplace_back(
                        decl->position(),
                        "an anonymous object declaration must have '=' and an initializer"
                    );
                    return;
                }

                emit(*decl->initializer, false);

                printer.print_cpp2("}", decl->position());
            }
        }
    }

    //  Not yet implemented. TODO: finalize deducing pointer types from parameter lists
    auto is_pointer_declaration(
        parameter_declaration_list_node const*,
        int,
        int
    )
        -> bool
    {
        return false;
    }

    auto is_pointer_declaration(
        declaration_node const* decl_node,
        int                     deref_cnt,
        int                     addr_cnt
    )
        -> bool
    {
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

    auto is_pointer_declaration(
        function_type_node const* fun_node,
        int                       deref_cnt,
        int                       addr_cnt
    )
        -> bool
    {
        if (!fun_node) {
            return false;
        }
        if (addr_cnt > deref_cnt) {
            return true;
        }

        return std::visit([&]<typename T>(T const& type){
            if constexpr (std::is_same_v<T, std::monostate>) {
                return false;
            }
            else if constexpr (std::is_same_v<T, function_type_node::single_type_id>) {
                return is_pointer_declaration(type.type.get(),  deref_cnt, addr_cnt);
            }
            else {
                return is_pointer_declaration(type.get(),  deref_cnt, addr_cnt);
            }
        }, fun_node->returns);
    }

    auto is_pointer_declaration(
        type_id_node const* type_id_node,
        int                 deref_cnt,
        int                 addr_cnt
    )
        -> bool
    {
        if (!type_id_node) {
            return false;
        }
        if (addr_cnt > deref_cnt) {
            return true;
        }

        if ( type_id_node->dereference_of ) {
            return is_pointer_declaration(type_id_node->dereference_of, deref_cnt + type_id_node->dereference_cnt, addr_cnt);
        } else if ( type_id_node->address_of ) {
            return is_pointer_declaration(type_id_node->address_of, deref_cnt, addr_cnt + 1);
        }

        auto pointer_declarators_cnt = std::count_if(std::cbegin(type_id_node->pc_qualifiers), std::cend(type_id_node->pc_qualifiers), [](auto* q) {
            return q->type() == lexeme::Multiply;
        });

        if (
            pointer_declarators_cnt == 0
            && type_id_node->suspicious_initialization
            )
        {
            return is_pointer_declaration(type_id_node->suspicious_initialization, deref_cnt, addr_cnt);
        }

        return (unsafe_narrow<int>(pointer_declarators_cnt) + addr_cnt - deref_cnt) > 0;
    }

    auto is_pointer_declaration(
        type_node const*,
        int,
        int
    )
        -> bool
    {
        return false;
    }

    auto is_pointer_declaration(
        namespace_node const*,
        int,
        int
    )
        -> bool
    {
        return false;
    }

    auto is_pointer_declaration(
        alias_node const*,
        int,
        int
    )
        -> bool
    {
        return false;
    }

    auto is_pointer_declaration(
        declaration_sym const* decl,
        int                    deref_cnt,
        int                    addr_cnt
    )
        -> bool
    {
        if (!decl) {
            return false;
        }
        if (addr_cnt > deref_cnt) {
            return true;
        }
        return is_pointer_declaration(decl->declaration, deref_cnt, addr_cnt);
    }

    auto is_pointer_declaration(
        token const* t,
        int          deref_cnt = 0,
        int          addr_cnt = 0
    )
        -> bool
    {
        if (!t) {
            return false;
        }
        if (addr_cnt > deref_cnt) {
            return true;
        }
        auto decl = sema.get_declaration_of(*t, true);
        return is_pointer_declaration(decl, deref_cnt, addr_cnt);
    }


    auto source_order_name_lookup(std::string_view identifier)
        -> source_order_name_lookup_res
    {
        for (
            auto first = current_names.rbegin(), last = current_names.rend() - 1;
            first != last;
            ++first
            )
        {
            if (
                auto decl = get_if<declaration_node const*>(&*first);
                decl
                && *decl
                && (*decl)->has_name(identifier)
                )
            {
                return *decl;
            }
            else if (
                auto using_ = get_if<active_using_declaration>(&*first);
                using_
                && using_->identifier
                && *using_->identifier == identifier
                )
            {
                return *using_;
            }
        }

        return {};
    }

    auto lookup_finds_type_scope_function(id_expression_node const& n)
        -> bool
    {
        if (!n.is_unqualified())
        {
            return false;
        }

        auto const& id = *get<id_expression_node::unqualified>(n.id);
        auto lookup = source_order_name_lookup(*id.identifier);

        if (
            !lookup
            || get_if<active_using_declaration>(&*lookup)
            )
        {
            return false;
        }

        auto decl = get<declaration_node const*>(*lookup);

        if (
            !decl->is_function()
            || !decl->has_name()
            || !decl->parent_is_type()
            )
        {
            return false;
        }

        return true;
    }

    auto lookup_finds_variable_with_placeholder_type_under_initialization(id_expression_node const& n)
        -> bool
    {
        if (!n.is_unqualified())
        {
            return false;
        }

        auto const& id = *get<id_expression_node::unqualified>(n.id);
        auto lookup = source_order_name_lookup(*id.identifier);

        if (
            !lookup
            || get_if<active_using_declaration>(&*lookup)
            )
        {
            return false;
        }

        auto decl = get<declaration_node const*>(*lookup);
        if (
            decl
            && decl->has_name(*id.identifier)
            )
        {
            if (
                !decl->is_object()
                && !decl->is_object_alias()
                )
            {
                return false;
            }

            if (decl->is_object()) {
                auto type = &**get_if<declaration_node::an_object>(&decl->type);
                return type->is_wildcard()
                       && contains(current_declarations, decl);
            }
            auto const& type = (**get_if<declaration_node::an_alias>(&decl->type)).type_id;
            return (
                    !type
                    || type->is_wildcard()
                    )
                   && contains(current_declarations, decl);
        }

        return false;
    }

    //-----------------------------------------------------------------------
    //
    auto emit(
        //  Note: parameter is not const as we'll fill in the capture .str info
        postfix_expression_node& n,
        bool                     for_lambda_capture = false
    )
        -> void
    {   STACKINSTR
        if (!sema.check(n)) {
            return;
        }

        assert(n.expr);
        last_postfix_expr_was_pointer = false;

        //  For a 'move that' parameter, track the members we already moved from
        //  so we can diagnose attempts to move from the same member twice
        if (
            emitting_move_that_function
            && n.expr->get_token()
            && *n.expr->get_token() == "that"
            )
        {
            if (n.ops.empty()) {
                if (!already_moved_that_members.empty()) {
                    errors.emplace_back(
                        n.position(),
                        "attempting to move from whole 'that' object after a 'that.member' was already moved from"
                    );
                    return;
                }
                //  push a sentinel for "all members"
                already_moved_that_members.push_back(nullptr);
            }
            else {
                auto member = n.ops[0].id_expr->get_token();
                assert(member);

                for (
                    auto i = already_moved_that_members.begin();
                    i != already_moved_that_members.end();
                    ++i
                    )
                {
                    if (
                        !*i
                        || **i == *member
                        )
                    {
                        errors.emplace_back(
                            n.position(),
                            "attempting to move twice from 'that." + member->to_string() + "'"
                        );
                        return;
                    }
                }

                already_moved_that_members.push_back(member);
            }
        }

        //  Ensure that forwarding postfix-expressions start with a forwarded parameter name
        //
        assert (!current_args.empty());
        if (current_args.back().pass == passing_style::forward)
        {
            assert (n.expr->get_token());
            assert (!current_args.back().ptoken);
            current_args.back().ptoken = n.expr->get_token();
            auto decl = sema.get_declaration_of(*current_args.back().ptoken);
            if (!(decl && decl->parameter && decl->parameter->pass == passing_style::forward))
            {
                errors.emplace_back(
                    n.position(),
                    n.expr->get_token()->to_string() + " is not a forwarding parameter name"
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
                        auto op = [&]{
                            if (
                                n.ops.size() >= 2
                                && n.ops[0].op->type() == lexeme::LeftParen
                                )
                            {
                                return n.ops[1].op;
                            }
                            else
                            {
                                return n.ops.front().op;
                            }
                        }();

                        if (
                            op->type() == lexeme::PlusPlus
                            || op->type() == lexeme::MinusMinus
                            || op->type() == lexeme::LeftBracket
                            )
                        {
                            errors.emplace_back(
                                op->position(),
                                op->to_string() + " - pointer arithmetic is illegal - use std::span or gsl::span instead"
                            );
                            violates_bounds_safety = true;
                        }
                        else if (
                            op->type() == lexeme::Tilde
                            )
                        {
                            errors.emplace_back(
                                op->position(),
                                op->to_string() + " - pointer bitwise manipulation is illegal - use std::bit_cast to convert to raw bytes first"
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
        if (
            n.cap_grp
            && !for_lambda_capture
            )
        {
            //  First stringize ourselves so that we compare equal against
            //  the first *cap_grp .str_suppressed_move that matches us (which is what the
            //  lambda introducer generator used to create a lambda capture)
            suppress_move_from_last_use = true;
            auto my_sym = print_to_string(n, true);
            suppress_move_from_last_use = false;

            auto found = std::find_if(n.cap_grp->members.cbegin(), n.cap_grp->members.cend(), [my_sym](auto& cap) {
                return cap.str_suppressed_move == my_sym;
            });

            assert(
                found != n.cap_grp->members.cend()
                && "ICE: could not find this postfix-expression in capture group"
            );
            //  And then emit that capture symbol with number
            assert (!found->cap_sym.empty());
            captured_part += found->cap_sym;
        }

        //  Otherwise, we're going to have to potentially do some work to change
        //  some Cpp2 postfix operators to Cpp1 prefix operators, so let's set up...
        auto prefix            = std::vector<text_with_pos>{};
        auto suffix            = std::vector<text_with_pos>{};

        auto last_was_prefixed = false;
        auto saw_dollar        = false;

        struct text_chunks_with_parens_position {
            std::vector<text_with_pos> text_chunks;
            source_position            open_pos;
            source_position            close_pos;
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

            //  Going backwards if we found LeftParen it might be UFCS
            //  expr_list is emitted to 'args' for future use
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
            //  Going backwards if we found Dot and there is args variable
            //  it means that it should be handled by UFCS
            else if(
                i->op->type() == lexeme::Dot
                && args
                //  Disable UFCS if name lookup would hard-error (#550).
                //  That happens when it finds that the function identifier being called is the name
                //  of a variable with deduced type and we are in its initializer (e.g., x := y.x();)
                //  So lower it to a member call instead, the only possible valid meaning.
                && !lookup_finds_variable_with_placeholder_type_under_initialization(*i->id_expr)
                )
            {
                //  The function name is the argument to the macro
                auto funcname = print_to_string(*i->id_expr);

                //  First, build the UFCS macro name

                auto ufcs_string = std::string("CPP2_UFCS");

                //  If there are template arguments, use the _TEMPLATE version
                if (std::ssize(i->id_expr->template_arguments()) > 0) {
                    //  If it is qualified, use the _QUALIFIED version
                    if (i->id_expr->is_qualified()) {
                        ufcs_string += "_QUALIFIED";
                        //  And split the unqualified id in the function name as two macro arguments
                        auto& id = *get<id_expression_node::qualified>(i->id_expr->id);
                        funcname =
                            "("
                            + print_to_string(id, false)
                            + "::),"
                            + print_to_string(*cpp2::impl::assert_not_null(id.ids.back().id), 0, true, true);
                    }
                    ufcs_string += "_TEMPLATE";
                }

                //  If we're in an object declaration (i.e., initializer)
                //  at namespace scope, use the _NONLOCAL version
                //
                //  Note: If there are other cases where code could execute
                //  in a non-local scope where a capture-default for the UFCS
                //  lambda would not be allowed, then add them here
                if (
                    current_declarations.back()->is_namespace()
                    || (
                        current_declarations.back()->is_object()
                        && current_declarations.back()->parent_is_namespace()
                        )
                    || (
                        (
                         current_declarations.back()->is_alias()
                         || (
                             current_declarations.back()->is_function()
                             && current_declarations.back() == having_signature_emitted
                             )
                         )
                        && (
                            current_declarations.back()->parent_is_namespace()
                            || current_declarations.back()->parent_is_type()
                            )
                        )
                    )
                {
                    ufcs_string += "_NONLOCAL";
                }

                //  If it's a last use, emit as part of the macro name
                //
                //  Note: This ensures a valid member call is still prioritized
                //  by leveraging the last use only in the non-member branch
                //  For example, `x.f()` won't emit as 'CPP2_UFCS(cpp2::move(f))(x)'
                //  to never take the branch that wants to call `x.cpp2::move(f)()`
                if (auto last_use = is_definite_last_use(i->id_expr->get_token());
                    last_use
                    && last_use->safe_to_move
                    && !lookup_finds_type_scope_function(*i->id_expr)
                    )
                {
                    if (last_use->is_forward) {
                        ufcs_string += "_FORWARD";
                    }
                    else {
                        ufcs_string += "_MOVE";
                    }

                    in_non_rvalue_context.push_back(true);
                    funcname = print_to_string(*i->id_expr);
                    in_non_rvalue_context.pop_back();
                }

                //  Second, emit the UFCS argument list

                //  If the computed function name is an explicit member access
                //  we don't need to go through the UFCS macro
                //  Note: This also works around compiler bugs
                if (funcname.starts_with("cpp2::move(*this).")) {
                    prefix.emplace_back(funcname + "(", args.value().open_pos );
                }
                else {
                    prefix.emplace_back(ufcs_string + "(" + funcname + ")(", args.value().open_pos );
                }
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
            else if (
                i->op->type() == lexeme::MinusMinus
                || i->op->type() == lexeme::PlusPlus
                || i->op->type() == lexeme::Multiply
                || i->op->type() == lexeme::Ampersand
                || i->op->type() == lexeme::Tilde
                )
            {
                // omit some needless parens
                if (
                    !last_was_prefixed
                    && i != n.ops.rbegin()
                    )
                {
                    prefix.emplace_back( "(", i->op->position() );
                }
                prefix.emplace_back( i->op->to_string(), i->op->position());

                //  Enable null dereference checks
                if (
                    flag_safe_null_pointers
                    && i->op->type() == lexeme::Multiply
                    )
                {
                    prefix.emplace_back( "cpp2::impl::assert_not_null(", i->op->position() );
                }
                if (
                    flag_safe_null_pointers
                    && i->op->type() == lexeme::Multiply
                    )
                {
                    suffix.emplace_back( ")", i->op->position() );
                }

                // omit some needless parens
                if (
                    !last_was_prefixed
                    && i != n.ops.rbegin()
                    )
                {
                    suffix.emplace_back( ")", i->op->position() );
                }
                last_was_prefixed = true;
            }

            //  Handle the other Cpp2 postfix operators that stay postfix in Cpp1 (currently: '...')
            else if (is_postfix_operator(i->op->type())) {
                flush_args();
                suffix.emplace_back( i->op->to_string(), i->op->position());
            }

            //  Handle the suffix operators that remain suffix
            //
            else {
                flush_args();

                assert(i->op);
                last_was_prefixed = false;

                //  Enable subscript bounds checks
                if (
                    flag_safe_subscripts
                    && i->op->type() == lexeme::LeftBracket
                    && std::ssize(i->expr_list->expressions) == 1
                    )
                {
                    suffix.emplace_back( ")", i->op->position() );
                }
                else if (i->op_close) {
                    suffix.emplace_back( i->op_close->to_string(), i->op_close->position() );
                }

                if (i->id_expr)
                {
                    if (args) {
                        //  If args are stored it means that this is function or method
                        //  that is not handled by UFCS and args need to be printed
                        suffix.emplace_back(")", args.value().close_pos);
                        for (auto&& e: args.value().text_chunks) {
                            suffix.push_back(e);
                        }
                        suffix.emplace_back("(", args.value().open_pos);
                        args.reset();
                    }

                    auto print = print_to_string(*i->id_expr, false /*not a local name*/, i->op->type() == lexeme::Dot);
                    suffix.emplace_back( print, i->id_expr->position() );
                }

                if (i->expr_list) {
                    auto text = print_to_text_chunks(*i->expr_list);
                    for (auto&& e: text) {
                        suffix.push_back(e);
                    }
                }

                //  Enable subscript bounds checks
                if (
                    flag_safe_subscripts
                    && i->op->type() == lexeme::LeftBracket
                    && std::ssize(i->expr_list->expressions) == 1
                    )
                {
                    if (auto lit = i->expr_list->expressions.front().expr->get_literal();
                        lit
                        && lit->literal->type() == lexeme::DecimalLiteral
                        )
                    {
                        prefix.emplace_back( "CPP2_ASSERT_IN_BOUNDS_LITERAL(", i->op->position() );
                    }
                    else
                    {
                        prefix.emplace_back( "CPP2_ASSERT_IN_BOUNDS(", i->op->position() );
                    }
                    suffix.emplace_back( ", ", i->op->position() );
                }
                else {
                    suffix.emplace_back( i->op->to_string(), i->op->position() );
                }
            }
        }

        //  Print the prefixes (in forward order)
        for (auto& e : prefix) {
            printer.print_cpp2(e.text, n.position());
        }

        //  If this is an --, ++, or &, don't add cpp2::move on the lhs
        //  even if this is a definite last use (only do that when an rvalue is okay)
        if (
            n.ops.front().op->type() == lexeme::MinusMinus
            || n.ops.front().op->type() == lexeme::PlusPlus
            || n.ops.front().op->type() == lexeme::Ampersand
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
    auto emit(prefix_expression_node const& n)
        -> void
    {   STACKINSTR
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
    auto emit(is_as_expression_node const& n)
        -> void
    {   STACKINSTR
        std::string prefix = {};
        std::string suffix = {};

        auto wildcard_found = false;
        bool as_on_literal  = false;

        assert(
            n.expr
            && n.expr->get_postfix_expression_node()
            && n.expr->get_postfix_expression_node()->expr
        );
        {
            auto& p = n.expr->get_postfix_expression_node()->expr;
            if (auto t = p->get_token();
                t
                && is_literal(t->type())
                && t->type() != lexeme::StringLiteral
                && t->type() != lexeme::FloatLiteral
                && !std::get<primary_expression_node::literal>(p->expr)->user_defined_suffix
                && std::ssize(n.ops) > 0
                && *n.ops[0].op == "as"
                )
            {
                as_on_literal = true;
            }
        }

        for (
            auto i = n.ops.rbegin();
            i != n.ops.rend();
            ++i
            )
        {
            //  If it's "ISORAS type", emit "cpp2::impl::ISORAS<type>(expr)"
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
                    auto op_name = i->op->to_string();
                    if (op_name == "as") {
                        op_name = "as_";    // use the static_assert-checked 'as' by default...
                    }                       // we'll override this inside inspect-expressions
                    prefix += "cpp2::impl::" + op_name + "<" + print_to_string(*i->type) + ">(";
                    suffix = ")" + suffix;
                }
            }
            //  Else it's "is value", emit "cpp2::impl::is(expr, value)"
            else
            {
                assert(i->expr);
                prefix += "cpp2::impl::" + i->op->to_string() + "(";
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
    auto emit(binary_expression_node<Name,Term> const& n)
        -> void
    {   STACKINSTR
        assert(n.expr);
        assert(
            n.terms.empty()
            || n.terms.front().op
        );

        //  If this is relational comparison
        if (
            !n.terms.empty()
            && (
                n.terms.front().op->type() == lexeme::Less
                || n.terms.front().op->type() == lexeme::LessEq
                || n.terms.front().op->type() == lexeme::Greater
                || n.terms.front().op->type() == lexeme::GreaterEq
                || n.terms.front().op->type() == lexeme::EqualComparison
                || n.terms.front().op->type() == lexeme::NotEqualComparison
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
                        printer.print_cpp2( "cpp2::impl::cmp_less(", n.position());
                    break;case lexeme::LessEq:
                        printer.print_cpp2( "cpp2::impl::cmp_less_eq(", n.position());
                    break;case lexeme::Greater:
                        printer.print_cpp2( "cpp2::impl::cmp_greater(", n.position());
                    break;case lexeme::GreaterEq:
                        printer.print_cpp2( "cpp2::impl::cmp_greater_eq(", n.position());
                    break;default:
                        ;
                    }
                }

                emit(*n.expr);

                //  emit == and != as infix a ? b operators (since we don't have
                //  any checking/instrumentation we want to do for those)
                if (flag_safe_comparisons) {
                    switch (op.type()) {
                    break;case lexeme::EqualComparison:
                          case lexeme::NotEqualComparison:
                        printer.print_cpp2( " ", n.position() );
                        emit(op);
                        printer.print_cpp2( " ", n.position() );
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
                    assert(
                        term.op
                        && term.expr
                    );
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
                            lambda_body += "cpp2::impl::cmp_less(";
                        break;case lexeme::LessEq:
                            lambda_body += "cpp2::impl::cmp_less_eq(";
                        break;case lexeme::Greater:
                            lambda_body += "cpp2::impl::cmp_greater(";
                        break;case lexeme::GreaterEq:
                            lambda_body += "cpp2::impl::cmp_greater_eq(";
                        break;default:
                            ;
                        }
                    }

                    auto rhs_expr = print_to_string(*term.expr);

                    lambda_body += lhs_name;

                    //  emit == and != as infix a ? b operators (since we don't have
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

        //  Else if this is an assignment expression, don't add cpp2::move on the lhs
        //  even if this is a definite last use (only do that when an rvalue is okay)
        if (
            !n.terms.empty()
            && is_assignment_operator(n.terms.front().op->type())
            )
        {
            suppress_move_from_last_use = true;
        }
        //  If it's "_ =" then emit static_cast<void>()
        bool emit_discard = false;
        if (
            !n.terms.empty()
            && n.terms.front().op->type() == lexeme::Assignment
            && n.expr->get_postfix_expression_node()
            && n.expr->get_postfix_expression_node()->get_first_token_ignoring_this()
            && *n.expr->get_postfix_expression_node()->get_first_token_ignoring_this() == "_"
            )
        {
            printer.print_cpp2( "static_cast<void>(", n.position() );
            emit_discard = true;
        }
        else
        {
            emit(*n.expr);
        }
        suppress_move_from_last_use = false;

        //  Check that this isn't an illegal pointer operation
        //      (initial partial implementation)
        if (
            !n.terms.empty()
            && last_postfix_expr_was_pointer
            )
        {
            auto rhs_post = n.get_second_postfix_expression_node();
            assert(
                rhs_post
                && rhs_post->expr
            );
            auto rhs_tok = rhs_post->expr->get_token();
            if (
                is_assignment_operator(n.terms.front().op->type())
                && rhs_tok
                && (
                    *rhs_tok == "nullptr"
                    || is_digit((rhs_tok->as_string_view())[0])
                    )
                )
            {
                errors.emplace_back(
                    n.terms.front().op->position(),
                    n.terms.front().op->to_string() + " - pointer assignment from null or integer is illegal"
                );
                violates_lifetime_safety = true;
            }
            else if (
                *n.terms.front().op == "+"
                || *n.terms.front().op == "+="
                || *n.terms.front().op == "-"
                || *n.terms.front().op == "-="
                )
            {
                errors.emplace_back(
                    n.terms.front().op->position(),
                    n.terms.front().op->to_string() + " - pointer arithmetic is illegal - use std::span or gsl::span instead"
                );
                violates_bounds_safety = true;
            }
        }

        auto first = true;
        for (auto const& x : n.terms) {
            assert(x.op);
            assert(x.expr);

            //  Normally we'll just emit the operator, but if this is an
            //  assignment that's a definite initialization, change it to
            //  a .construct() call
            if (
                x.op->type() == lexeme::Assignment
                && in_definite_init
                )
            {
                printer.print_cpp2( ".construct(", n.position() );
                emit(*x.expr);
                printer.print_cpp2( ")", n.position() );
            }
            else
            {
                //  For the first operator only, if we are emitting a "_ =" discard
                //  then we don't need the =
                if (
                    !emit_discard
                    || !first
                ) {
                    printer.print_cpp2(" ", n.position());
                    emit(*x.op);
                    printer.print_cpp2(" ", n.position());
                }

                //  When assigning a single expression-list, we can
                //  take over direct control of emitting it without needing to
                //  go through the whole grammar, and surround it with braces
                if (
                    x.op->type() == lexeme::Assignment
                    && x.expr->is_expression_list()
                    )
                {
                    printer.print_cpp2( "{ ", n.position() );
                    emit(*x.expr->get_expression_list(), false);
                    printer.print_cpp2( " }", n.position() );
                }
                //  Otherwise, just emit the general expression as usual
                else {
                    emit(*x.expr);
                }
            }

            first = false;
        }
        // Finish emitting the "_ =" discard.
        if (emit_discard) {
            printer.print_cpp2( ")", n.position() );
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(expression_node const& n)
        -> void
    {   STACKINSTR
        assert(n.expr);
        push_need_expression_list_parens(true);
        emit(*n.expr);
        pop_need_expression_list_parens();
    }


    //-----------------------------------------------------------------------
    //
    auto emit(
        expression_list_node const& n,
        bool                        parens_ok = true
    )
        -> void
    {   STACKINSTR
        auto add_parens =
            should_add_expression_list_parens()
            && !n.inside_initializer
            && parens_ok
            ;
        add_parens |=
            n.is_fold_expression() &&
            !(n.inside_initializer && current_declarations.back()->initializer->position() != n.open_paren->position())
            ;
        if (add_parens) {
            printer.print_cpp2( *n.open_paren, n.position());
        }

        auto first = true;
        for (auto const& x : n.expressions) {
            if (!first) {
                printer.print_cpp2(", ", n.position());
            }
            first = false;
            auto is_out = false;

            if (x.pass != passing_style::in) {
                assert(
                    x.pass == passing_style::out
                    || x.pass == passing_style::move
                    || x.pass == passing_style::forward
                );
                if (x.pass == passing_style::out) {
                    is_out = true;
                    printer.print_cpp2("cpp2::impl::out(&", n.position());
                }
                else if (x.pass == passing_style::move) {
                    printer.print_cpp2("std::move(", n.position());
                }
            }

            if (is_out) {
                in_non_rvalue_context.push_back(true);
            }

            assert(x.expr);
            current_args.push_back( {x.pass} );
            emit(*x.expr);
            current_args.pop_back();

            if (is_out) {
                in_non_rvalue_context.pop_back();
            }

            if (
                x.pass == passing_style::move
                || x.pass == passing_style::out
                )
            {
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
    auto emit(
        expression_statement_node const& n,
        bool                             can_have_semicolon,
        source_position                  function_body_start = {},
        bool                             function_void_ret   = false,
        function_prolog const&           function_prolog     = {},
        std::vector<std::string> const&  function_epilog     = {},
        bool                             emitted             = false
    )
        -> void
    {   STACKINSTR
        assert(n.expr);
        auto generating_return = false;

        if (function_body_start != source_position{}) {
            emit_prolog_mem_inits(function_prolog, n.position().colno);
            printer.print_cpp2(" { ", function_body_start);
            emit_prolog_statements(function_prolog, n.position().colno);
            if (!function_void_ret) {
                printer.print_cpp2("return ", n.position());
                generating_return = true;
            }
        }

        if (!emitted) {
            //  When generating 'return' of a single expression-list, we can
            //  take over direct control of emitting it without needing to
            //  go through the whole grammar, and surround it with braces
            if (
                generating_return
                && n.expr->is_expression_list()
                && !n.expr->get_expression_list()->is_fold_expression()
                )
            {
                auto is_deduced_return =
                    !function_returns.empty()
                    && function_returns.back().is_deduced;

                if (!is_deduced_return) {
                    printer.print_cpp2( "{ ", n.position() );
                }
                emit(*n.expr->get_expression_list(), false);
                if (!is_deduced_return) {
                    printer.print_cpp2( " }", n.position() );
                }
            }
            //  Otherwise, just emit the general expression as usual
            else {
                emit(*n.expr);
            }
            if (can_have_semicolon) {
                printer.print_cpp2(";", n.position());
            }
        }

        if (function_body_start != source_position{}) {
            emit_epilog_statements( function_epilog, n.position().colno);
            printer.print_cpp2(" }", n.position());
        }
    }


    // Consider moving these `stack` functions to `common.h` to enable more general use.

    template<typename T>
    auto stack_value(
        T& var,
        std::type_identity_t<T> const& value
    )
        -> auto
    {
        return finally([&var, old = std::exchange(var, value)]() {
            var = old;
        });
    }

    template<typename T>
    auto stack_element(
        std::vector<T>& cont,
        std::type_identity_t<T> const& value
    )
        -> auto
    {
        cont.push_back(value);
        return finally([&]{ cont.pop_back(); });
    }

    template<typename T>
    auto stack_size(std::vector<T>& cont)
        -> auto
    {
        return finally([&, size = cont.size()]{ cont.resize(size); });
    }

    template<typename T>
    auto stack_size_if(
        std::vector<T>& cont,
        bool cond
    )
        -> std::optional<decltype(stack_size(cont))>
    {
        if (cond) {
            return stack_size(cont);
        }
        return {};
    }

    //-----------------------------------------------------------------------
    //
    auto emit(
        statement_node const&           n,
        bool                            can_have_semicolon  = true,
        source_position                 function_body_start = {},
        bool                            function_void_ret   = false,
        function_prolog const&          function_prolog     = {},
        std::vector<std::string> const& function_epilog     = {}
    )
        -> void
    {   STACKINSTR
        if (!sema.check(n)) {
            return;
        }

        auto emit_parameters =
            !n.emitted
            && n.parameters
            ;

        auto guard = stack_size_if(current_names, emit_parameters);
        if (emit_parameters) {
            printer.print_extra( "\n");
            printer.print_extra( "{");
            for (auto& param : n.parameters->parameters) {
                printer.print_extra( "\n");
                printer.print_extra( print_to_string(*param, false, false, true) );
            }
        }

        //  Do expression statement case first... it's the most complex
        //  because it's used for single-statement function bodies
        try_emit<statement_node::expression >(
            n.statement,
            can_have_semicolon,
            function_body_start,
            function_void_ret,
            function_prolog,
            function_epilog,
            n.emitted
        );

        //  Otherwise, skip this one if it was already handled earlier (i.e., a constructor member init)
        if (n.emitted) {
            return;
        }

        printer.disable_indent_heuristic_for_next_text();

        try_emit<statement_node::compound   >(n.statement, function_prolog, function_epilog);

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

        try_emit<statement_node::selection  >(n.statement);
        try_emit<statement_node::declaration>(n.statement);
        try_emit<statement_node::return_    >(n.statement);
        try_emit<statement_node::iteration  >(n.statement);
        try_emit<statement_node::using_     >(n.statement);
        try_emit<statement_node::contract   >(n.statement);
        try_emit<statement_node::inspect    >(n.statement, false);
        try_emit<statement_node::jump       >(n.statement);

        printer.preempt_position_pop();

        if (emit_parameters) {
            printer.print_extra( "\n");
            printer.print_extra( "}");
        }
    }


    //-----------------------------------------------------------------------
    //  Within a type scope implementation, disallow declaring a name that
    //  is the same as (i.e., shadows) a type scope name... this is a
    //  convenient place to check because we have the decls stack
    //
    auto check_shadowing_of_type_scope_names(
        declaration_node const& decl
    )
        -> bool
    {
        if (
            decl.has_name()                 // this is a named declaration
            && !decl.has_name("this")       // that's not 'this'
            && !decl.parent_is_type()       // and the type isn't the direct parent
            && is_name_declared_in_current_type_scope(*decl.name())
            )                               // and it shadows a name
        {
            errors.emplace_back(
                decl.position(),
                "a type's implementation may not declare a name that is the same as (i.e., shadows) a type scope name - for example, a type scope function's local variable may not have the same as one of the type's members"
            );
            return false;
        }

        return true;
    }


    //-----------------------------------------------------------------------
    //
    auto emit(
        parameter_declaration_node const& n,
        bool                              is_returns            = false,
        bool                              is_template_parameter = false,
        bool                              is_statement          = false
    )
        -> void
    {   STACKINSTR
        if (!sema.check(n)) {
            return;
        }

        //  Can't declare functions as parameters -- only pointers to functions which are objects
        assert( n.declaration );
        assert( !n.declaration->is_function() );

        if (!check_shadowing_of_type_scope_names(*n.declaration)) {
            return;
        }

        assert( n.declaration->identifier );
        auto identifier     = print_to_string( *n.declaration->identifier );
        auto identifier_pos = n.position();

        if (n.mod == parameter_declaration_node::modifier::implicit)
        {
            assert(!current_functions.empty());
            if (
                n.pass != passing_style::out
                || !current_functions.back().decl->has_name("operator=")
                )
            {
                errors.emplace_back(
                    n.position(),
                    "only an 'out this' parameter of an 'operator=' function may be declared implicit"
                );
            }
        }

        current_names.push_back(&*n.declaration);

        //-----------------------------------------------------------------------
        //  Skip 'this' parameters

        if (n.declaration->has_name("this"))
        {
            //  Since we're skipping "out this," plus possibly "implicit " and
            //  whitespace, any following parameters on the same line can shift left
            printer.add_pad_in_this_line(-18);

            return;
        }

        //-----------------------------------------------------------------------
        //  Handle 'that' parameters

        if (n.declaration->has_name("that"))
        {
            emitting_that_function = true;
            assert(
                n.pass == passing_style::in
                || n.pass == passing_style::move
            );
            auto pass = std::string{" const&"};
            if (
                n.pass == passing_style::move
                || emitting_move_that_function
                )
            {
                pass = "&&";
            }

            auto func_name = get_enclosing_function_name();
            assert(func_name);

            auto type_name = get_enclosing_type_name();
            assert(type_name);

            //  If we're in an empty type that has no member object, mark 'that' as
            //  [[maybe_unused]] to silence Cpp1 compiler warnings
            assert(!current_functions.empty());
            auto maybe_unused = std::string{};
            if (current_functions.back().decl->get_parent()->get_type_scope_declarations(declaration_node::objects).empty()) {
                maybe_unused = "[[maybe_unused]] ";
            }

            printer.print_cpp2(
                maybe_unused + print_to_string( *type_name ) + pass + " that",
                n.position()
            );
            return;
        }

        //-----------------------------------------------------------------------
        //  Handle type parameters

        // Common template naming
        auto emit_template_name = [&]() {
            if (n.declaration->is_variadic) {
                printer.print_cpp2(
                    "...",
                    identifier_pos
                );
            }

            if (identifier == "_") {
                printer.print_cpp2( unnamed_type_param_name(n.ordinal, n.declaration->identifier->get_token()),
                                    identifier_pos );
            }
            else {
                printer.print_cpp2( identifier, identifier_pos );
            }
        };
        if (n.declaration->is_type()) {
            assert( is_template_parameter );
            printer.print_cpp2("typename ", identifier_pos);

            emit_template_name();
            return;
        }

        //-----------------------------------------------------------------------
        //  Else handle template non-type parameters

        assert( n.declaration->is_object() );
        auto const& type_id = *std::get<declaration_node::an_object>(n.declaration->type);

        if (is_template_parameter) {
            emit( type_id );
            printer.print_cpp2(" ", type_id.position());

            emit_template_name();
            return;
        }

        //-----------------------------------------------------------------------
        //  Else handle ordinary parameters

        auto param_type = print_to_string(type_id);

        //  If there are template parameters on this function or its enclosing
        //  type, see if this parameter's name is an unqualified-id with a
        //  template parameter name, or mentions a template parameter as a
        //  template argument
        auto has_template_parameter_type_named = [](
            declaration_node const& decl,
            std::string_view        name
            )
            -> bool
        {
            if (decl.template_parameters) {
                for (auto& tparam : decl.template_parameters->parameters)
                {
                    assert(
                        tparam
                        && tparam->name()
                    );
                    //  For now just do a quick string match
                    auto tparam_name = tparam->name()->to_string();
                    if (
                        tparam->declaration->is_type()
                        && (
                            name == tparam_name
                            || name.find("<"+tparam_name) != std::string_view::npos
                            || name.find(","+tparam_name) != std::string_view::npos
                        )
                        )
                    {
                        return true;
                    }
                }
            }
            return false;
        };

        assert( current_declarations.back() );
        auto is_dependent_parameter_type =
            has_template_parameter_type_named( *current_declarations.back(), param_type )
            || (
                current_declarations.back()->parent_is_type()
                && current_declarations.back()->has_name("operator=")
                && has_template_parameter_type_named( *current_declarations.back()->get_parent(), param_type)
                )
            ;

        //  First any prefix

        if (identifier == "_") {
            printer.print_cpp2( "[[maybe_unused]] ", identifier_pos );
            identifier = "unnamed_param_" + std::to_string(n.ordinal);
        }

        if (
            !is_returns
            && !n.declaration->is_variadic
            && !type_id.is_wildcard()
            && !is_dependent_parameter_type
            && !type_id.is_pointer_qualified()
            )
        {
            switch (n.pass) {
            break;case passing_style::in     : printer.print_cpp2( "cpp2::impl::in<",  n.position() );
            break;case passing_style::out    : printer.print_cpp2( "cpp2::impl::out<", n.position() );
            break;default: ;
            }
        }

        printer.preempt_position_push( n.position() );

        if (
            type_id.is_pointer_qualified()
            && n.pass == passing_style::in
            )
        {
            printer.print_cpp2( param_type, n.position() );
        }
        else if (
            type_id.is_wildcard()
            || is_dependent_parameter_type
            || n.declaration->is_variadic
            )
        {
            auto name = std::string{"auto"};
            if (is_dependent_parameter_type) {
                name = param_type;
            }
            else if (
                n.declaration->is_variadic
                && !type_id.is_wildcard()
                )
            {
                auto name = n.declaration->identifier->get_token();
                assert(name);
                auto req = std::string{"(std::is_convertible_v<CPP2_TYPEOF("};
                req += *name;
                req += "), ";
                req += param_type;
                req += "> && ...)";
                function_requires_conditions.push_back(req);
            }

            switch (n.pass) {
            break;case passing_style::in     : printer.print_cpp2( name+" const&", n.position() );
            break;case passing_style::copy   : printer.print_cpp2( name,           n.position() );
            break;case passing_style::inout  : printer.print_cpp2( name+"&",       n.position() );

            //  For generic out parameters, we take a pointer to anything with paramater named "identifier_"
            //  and then generate the out<> as a stack local with the expected name "identifier"
            break;case passing_style::out    : printer.print_cpp2( name,           n.position() );
                                               current_functions.back().prolog.statements.push_back(
                                                   "auto " + identifier + " = cpp2::impl::out(" + identifier + "_); "
                                               );
                                               identifier += "_";

            break;case passing_style::move   : printer.print_cpp2( name+"&&",      n.position() );
            break;case passing_style::forward: printer.print_cpp2( name+"&&",      n.position() );
            break;default: ;
            }
        }
        else if (n.pass == passing_style::forward) {
            printer.print_cpp2("auto", n.position());

            auto name = n.declaration->identifier->get_token();
            assert(name);
            auto req = std::string{"std::is_same_v<"};
            req += param_type;
            req += ", CPP2_TYPEOF(";
            req += *name;
            req += ")>";
            function_requires_conditions.push_back(req);
        }
        else {
            if (is_returns) {
                printer.print_extra( param_type );
            }
            else {
                printer.print_cpp2( param_type, type_id.position() );
            }
        }

        printer.preempt_position_pop();

        //  Then any suffix

        if (
            !is_returns
            && !type_id.is_wildcard()
            && !is_dependent_parameter_type
            && !type_id.is_pointer_qualified()
            && !n.declaration->is_variadic
            )
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

        if (is_returns) {
            printer.print_extra( " " + identifier );
        }
        else {
            printer.print_cpp2( " ", identifier_pos );
            if (n.declaration->is_variadic)
            {
                if (n.direction() == passing_style::out) {
                    errors.emplace_back(
                        n.declaration->position(),
                        "a variadic parameter cannot be 'out'"
                    );
                    return;
                }

                printer.print_cpp2(
                    "...",
                    identifier_pos
                );
            }
            printer.print_cpp2( identifier, identifier_pos );
        }

        if (
            !is_returns
            && n.declaration->initializer
            )
        {
            auto guard = stack_element(current_declarations, &*n.declaration);
            if (is_statement) {
                printer.print_cpp2( "{", n.declaration->initializer->position() );
            }
            else {
                printer.print_cpp2( " = ", n.declaration->initializer->position() );
            }
            emit(*n.declaration->initializer, !is_statement);
            if (is_statement) {
                printer.print_cpp2( "};", n.declaration->initializer->position() );
            }
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(
        parameter_declaration_list_node const& n,
        bool                                   is_returns                 = false,
        bool                                   is_template_parameter      = false,
        bool                                   generating_postfix_inc_dec = false
    )
        -> void
    {   STACKINSTR
        in_parameter_list = true;

        if (is_returns) {
            printer.print_extra( "{ " );
        }
        else {
            assert(n.open_paren);
            emit(*n.open_paren);
        }

        //  So we don't get cute about text-aligning the first parameter when it's on a new line
        printer.disable_indent_heuristic_for_next_text();

        auto prev_pos = n.position();
        auto first    = true;
        for (auto const& x : n.parameters) {
            if (
                !first
                && !is_returns
                )
            {
                printer.print_cpp2( ", ", prev_pos );
            }
            prev_pos = x->position();
            assert(x);
            emit(*x, is_returns, is_template_parameter);
            if (!x->declaration->has_name("this")) {
                first = false;
            }
            if (is_returns) {
                printer.print_extra( "; " );
            }
        }

        if (is_returns) {
            printer.print_extra( "};\n" );
        }
        else {
            //  If we're generating Cpp1 postfix ++ or --, add the dummy int parameter
            if (generating_postfix_inc_dec) {
                if (!first) {
                    printer.print_cpp2( ",", n.position() );
                }
                printer.print_cpp2( "int", n.position() );
            }

            //  Position heuristic (aka hack): Avoid emitting extra whitespace before )
            //  beyond column 10
            assert(n.close_paren);
            auto col = std::min( n.close_paren->position().colno, colno_t{10});
            printer.preempt_position_push({ n.close_paren->position().lineno, col});
            emit(*n.close_paren);
            printer.preempt_position_pop();
        }

        in_parameter_list = false;
    }


    //-----------------------------------------------------------------------
    //
    auto emit(
        // note: parameter is deliberately not const because we will fill
        //       in the capture .str information
        contract_node& n
    )
        -> void
    {   STACKINSTR
        assert (n.kind);

        //  If this is one of Cpp2's predefined contract groups,
        //  make it convenient to use without cpp2:: qualification
        auto name = std::string{"cpp2::cpp2_default"};
        if (n.group)
        {
            auto group = print_to_string(*n.group);
            if (group != "_") {
                name = group;
            }
            if (
                name == "cpp2_default"
                || name == "bounds_safety"
                || name == "null_safety"
                || name == "type_safety"
                || name == "testing"
                )
            {
                name.insert(0, "cpp2::");
            }
        }

        //  "Unevaluated" is for static analysis only, and are never evaluated, so just skip them
        //  (The only requirement for an Unevaluated condition is that it parses; and even that's
        //  easy to relax if we ever want to allow arbitrary tokens in an Unevaluated condition)
        if (n.group && n.group->to_string() == "unevaluated") {
            return;
        }

        //  For a postcondition, we'll wrap it in a lambda and register it
        //
        if (*n.kind == "post") {
            auto lambda_intro = build_capture_lambda_intro_for(n.captures, n.position(), true);
            printer.print_cpp2(
                "cpp2_finally_presuccess.add(" +
                    lambda_intro + "{",
                n.position()
            );
        }

        //  Emit the contract group name, and report any violation to that group
        //
        assert(n.condition);
        auto message = std::string{"\"\""};
        if (n.message) {
            message = "CPP2_CONTRACT_MSG(" + print_to_string(*n.message) + ")";
        }

        auto separator = std::string{""};
        printer.print_cpp2(
            "if (",
            n.position()
        );
        for (auto const& flag : n.flags) {
            printer.print_cpp2(
                separator + print_to_string(*flag),
                n.position()
            );
            separator = " && ";
        }
        printer.print_cpp2(
            separator + name + ".is_active()",
            n.position()
        );
        printer.print_cpp2(
            " && !(" + print_to_string(*n.condition) + ") ) " +
                "{ " + name + ".report_violation(" + message + "); }",
            n.position()
        );

        //  For a postcondition, close out the lambda
        //
        if (*n.kind == "post") {
            printer.print_cpp2( "} );", n.position()
            );
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(
        function_type_node const& n,
        bool                      is_main                    = false,
        bool                      is_ctor_or_dtor            = false,
        std::string               suffix1                    = {},
        bool                      generating_postfix_inc_dec = false
    )
        -> void
    {   STACKINSTR
        if (!sema.check(n)) {
            return;
        }

        if (
            is_main
            && n.parameters->parameters.size() > 0
            )
        {
            printer.print_cpp2(
                "(int const argc_, char** argv_)",
                n.parameters->position()
            );
            current_functions.back().prolog.statements.push_back(
                "auto const args = cpp2::make_args(argc_, argv_); "
            );
        }
        else {
            emit(*n.parameters, false, false, generating_postfix_inc_dec);
        }

        //  For an anonymous function, the emitted lambda is 'constexpr' or 'mutable'
        if (!n.my_decl->has_name())
        {
            if (n.my_decl->is_constexpr) {
                //  The current design path we're trying out is for all '==' functions to be
                //  emitted as Cpp1 'constexpr', including anonymous functions. For anonymous
                //  functions that have captures, the intent is that '==' implies "the result
                //  always the same (depends only on the arguments)." Specifically, the result
                //  doesn't depend on the captured state, so the captured state should be const.
                //  But until we want to take a dependency on post-C++20 constexpr relaxation
                //  to make more code work with 'constexpr' even when not invoked in constexpr
                //  contexts, we will emit it as const/whitespace instead for now.
                //
                //  printer.print_cpp2( " constexpr", n.position() );
                //      // consider enabling when P2242, P2280, and similar papers are widely implemented
            }
            else {
                printer.print_cpp2( " mutable", n.position() );
            }
        }

        //  For now, adding implicit noexcept only for move/swap/dtor functions
        if (
            n.is_move()
            || n.is_swap()
            || n.is_destructor()
            || generating_move_from == n.my_decl
            )
        {
            printer.print_cpp2( " noexcept", n.position() );
        }

        printer.print_cpp2( suffix1, n.position() );

        //  Handle a special member function
        if (
            n.is_assignment()
            || generating_assignment_from == n.my_decl
            )
        {
            assert(
                n.returns.index() == function_type_node::empty
                && n.my_decl->parent_declaration->name()
            );
            printer.print_cpp2(
                " -> " + print_to_string( *n.my_decl->parent_declaration->name() ) + "& ",
                n.position()
            );
        }

        //  Otherwise, handle a default return type
        else if (n.returns.index() == function_type_node::empty)
        {
            if (is_main)
            {
                printer.print_cpp2( " -> int", n.position() );
            }
            else if(!is_ctor_or_dtor)
            {
                printer.print_cpp2( " -> void", n.position() );
            }
        }

        //  Otherwise, handle a single anonymous return type
        else if (n.returns.index() == function_type_node::id)
        {
            auto is_type_scope_function_with_in_this =
                n.my_decl->parent_is_type()
                && n.parameters->ssize() > 0
                && (*n.parameters)[0]->direction() == passing_style::in
                ;

            printer.print_cpp2( " -> ", n.position() );
            auto& r = std::get<function_type_node::id>(n.returns);
            assert(r.type);

            auto return_type = print_to_string(*r.type);

            if (r.pass == passing_style::forward) {
                if (r.type->is_wildcard()) {
                    printer.print_cpp2( "auto&&", n.position() );
                }
                else {
                    printer.print_cpp2( return_type, n.position() );
                    if (is_type_scope_function_with_in_this) {
                        printer.print_cpp2( " const&", n.position() );
                    }
                    else if (!generating_postfix_inc_dec) {
                        printer.print_cpp2( "&", n.position() );
                    }
                }
            }
            else {
                printer.print_cpp2( return_type, n.position() );
            }
        }

        //  Otherwise, handle multiple/named returns
        else {
            printer.print_cpp2( " -> ", n.position() );
            assert (n.my_decl);
            printer.print_cpp2( multi_return_type_name(*n.my_decl), n.position());
        }
    }


    //-----------------------------------------------------------------------
    //
    auto is_name_declared_in_current_type_scope(std::string_view s)
        -> bool
    {
        if (!s.empty())
        {
            //  Navigate to the enclosing type, if there is one...
            for (auto parent = current_declarations.rbegin();
                parent != current_declarations.rend();
                ++parent
                )
            {
                if (
                    *parent
                    && (*parent)->is_namespace()
                    )
                {
                    break;
                }
                //  ... and here it is, so...
                if (
                    *parent
                    && (*parent)->is_type()
                        )
                        {
                            //  ... for each of its type scope decls...
                            for (auto const& decl : (*parent)->get_type_scope_declarations())
                            {
                                //  ... check the name
                                if (decl->has_name(s))
                                {
                                    return true;
                                }
                            }
                            break;
                }
            }
        }
        return false;
    }


    //-----------------------------------------------------------------------
    //
    auto get_enclosing_type_name()
        -> token const*
    {
        //  Navigate to the enclosing type, if there is one...
        for (auto parent = current_declarations.rbegin();
            parent != current_declarations.rend();
            ++parent
            )
        {
            if (
                *parent
                && (*parent)->is_namespace()
                )
            {
                break;
            }
            //  ... and here it is, so...
            if (
                *parent
                && (*parent)->is_type()
                )
            {
                return (*parent)->name();
            }
        }
        return {};
    }


    //-----------------------------------------------------------------------
    //
    auto get_enclosing_function_name()
        -> token const*
    {
        //  Navigate to the enclosing function, if there is one...
        for (auto parent = current_declarations.rbegin();
            parent != current_declarations.rend();
            ++parent
            )
        {
            if (
                *parent
                && (*parent)->is_namespace()
                )
            {
                break;
            }
            //  ... and here it is, so...
            if (
                *parent
                && (*parent)->is_function()
                )
            {
                return (*parent)->name();
            }
        }
        return {};
    }


    //-----------------------------------------------------------------------
    //  Helper to emit type-qualified names for member functions
    //
    auto type_qualification_if_any_for(
        declaration_node const& n
    )
        -> std::string
    {
        auto ret = std::string{};

        if (
            printer.get_phase() == printer.phase2_func_defs
            && n.parent_is_type()
//            && !n.name()->as_string_view().starts_with("operator")
            )
        {
            //  If this function is inside templated type(s),
            //  emit those outer template parameter lists too
            auto parent = n.parent_declaration;
            while (
                parent
                && parent->is_type()
                )
            {
                auto list = std::string{""};
                if (parent->template_parameters) {
                    auto separator = std::string{"<"};
                    for (auto& tparam : parent->template_parameters->parameters) {
                        assert (tparam->has_name());
                        list += separator;
                        if ("_" == tparam->name()->to_string()) {
                            list += unnamed_type_param_name(tparam->ordinal,
                                                            tparam->declaration->identifier->get_token());
                        }
                        else {
                            list += tparam->name()->to_string();
                        }
                        if(tparam->declaration->is_variadic) {
                            list += "...";
                        }
                        separator = ",";
                    }
                    list += ">";
                }
                ret = print_to_string(*parent->identifier) + list + "::" + ret;
                parent = parent->parent_declaration;
            }
        }

        return ret;
    }

    //-----------------------------------------------------------------------
    //  Constructors and assignment operators
    //
    auto emit_special_member_function(
        declaration_node const& n,
        std::string             prefix
    )
        -> void
    {   STACKINSTR
        assert(n.is_function());
        auto& func = std::get<declaration_node::a_function>(n.type);
        assert(func);

        auto is_assignment =
            generating_assignment_from == &n
            || (*func->parameters)[0]->pass == passing_style::inout;

        if (
            func->parameters->ssize() > 1
            && (*func->parameters)[1]->has_name("that")
            )
        {
            emitting_that_function = true;
            if (
                (*func->parameters)[1]->pass == passing_style::move
                || generating_move_from == &n
                )
            {
                emitting_move_that_function = true;
            }
        }

        //  Do the 'out' param and member init work only in the definition phase
        if (printer.get_phase() == printer.phase2_func_defs)
        {
            auto canonize_object_name = [&]( declaration_node const* obj )
                -> std::string
            {
                assert(obj->has_name());
                auto ret = obj->name()->to_string();
                if (ret == "this") {
                    ret = print_to_string( *obj->get_object_type() );
                }
                return ret;
            };

            //  We'll use this common guidance in several errors,
            //  so write it once to keep the guidance consistent
            assert (n.parent_declaration && n.parent_declaration->name());
            auto error_msg = "an operator= body must start with a series of 'member = value;' initialization statements for each of the type-scope objects in the same order they are declared, or the member must have a default initializer (in type '" + n.parent_declaration->name()->to_string() + "')";

            //  If this constructor's type has data members, handle their initialization
            //      - objects is the list of this type's declarations
            //      - statements is the list of this constructor's statements
            auto objects    = n.parent_declaration->get_type_scope_declarations(n.objects);
            auto statements = n.get_initializer_statements();
            auto out_inits  = std::vector<std::string>{};

            auto object     = objects.begin();
            auto statement  = statements.begin();
            auto separator  = std::string{": "};

            while (object != objects.end())
            {
                auto object_name = canonize_object_name(*object);

                auto is_object_before_base =
                    n.get_decl_if_type_scope_object_name_before_a_base_type(*(*object)->name());

                auto found_explicit_init = false;
                auto found_default_init  = false;
                auto stmt_pos = n.position();

                auto initializer = std::string{};

                //  If we're at an assignment statement, get the lhs and rhs
                if (statement != statements.end())
                {
                    assert (*statement);
                    stmt_pos = (*statement)->position();
                    if (stmt_pos.lineno < 0) {
                        stmt_pos = n.position();
                    }

                    auto lhs = std::string{};
                    auto rhs = std::string{};
                    {
                        auto exprs = (*statement)->get_lhs_rhs_if_simple_assignment();
                        if (exprs.lhs) {
                            if (auto tok = exprs.lhs->get_first_token_ignoring_this()) {
                                lhs = *tok;
                            }
                            else {
                                lhs = print_to_string( *exprs.lhs );
                            }
                        }
                        if (exprs.rhs) {
                            rhs = print_to_string( *exprs.rhs );
                        }
                    }

                    //  If this is an initialization of an 'out' parameter, stash it
                    if (n.has_out_parameter_named(lhs)){
                        out_inits.push_back( print_to_string(**statement, false) );
                        (*statement)->emitted = true;
                        ++statement;
                        continue;
                    }

                    //  Now we're ready to check whether this is an assignment to *object

                    if (!lhs.empty())
                    {
                        //  First, see if it's an assignment 'name = something'
                        found_explicit_init = object_name == lhs;

                        //  Otherwise, see if it's 'this.name = something'
                        if (!found_explicit_init)
                        {
                            //  If it's of the form 'this.name', check 'name'
                            if (
                                starts_with( lhs, "(*this).")
                                && object_name == lhs.substr(8)
                                )
                            {
                                found_explicit_init = true;
                            }
                        }

                        if (found_explicit_init)
                        {
                            initializer = rhs;

                            //  We've used this statement, so note it
                            //  and move 'statement' forward
                            (*statement)->emitted = true;
                            ++statement;
                        }
                    }
                }

                //  Otherwise, use a default... for a non-copy/move that's the member initializer
                //  (for which we don't need to emit anything special because it will get used),
                //  and for a copy/move function we default to "= that.same_member" (or, if this
                //  is a base type, to assigning from the lowered base subobject)
                if (!found_explicit_init)
                {
                    if (emitting_that_function && (*object)->has_name("this"))
                    {
                        auto pass = std::string{" const&"};
                        if (emitting_move_that_function) {
                            pass = "&&";
                        }
                        initializer =
                            "static_cast<"
                            + object_name
                            + pass
                            + ">(that)";
                        found_default_init = true;
                    }
                    else if (emitting_move_that_function)
                    {
                        initializer =
                            "std::move(that)."
                            + object_name;
                        found_default_init = true;
                    }
                    else if (emitting_that_function)
                    {
                        initializer =
                            "that."
                            + object_name;
                        found_default_init = true;
                    }
                    else if ((*object)->initializer)
                    {
                        initializer = print_to_string(*(*object)->initializer, false);
                        found_default_init = true;
                    }
                }

                //  If this is not an assignment to *object,
                //  and there was no member initializer, complain
                if (
                    !found_explicit_init
                    && !found_default_init
                    )
                {
                    errors.emplace_back(
                        stmt_pos,
                        "in operator=, expected '" + object_name + " = ...' initialization statement (because type scope object '" + object_name + "' does not have a default initializer)"
                    );
                    errors.emplace_back(
                        (*object)->position(),
                        "see declaration for '" + object_name + "' here"
                    );
                    errors.emplace_back(
                        stmt_pos,
                        error_msg
                    );
                    return;
                }

                assert(
                    found_explicit_init
                    || found_default_init
                );

                //  Emit the initializer if it it isn't '_' (don't care) and ...
                if (initializer == "_") {
                    //  And on to the next data member...
                    ++object;
                    continue;
                }

                if (initializer.empty()) {
                    initializer = "{}";
                }

                //  (a) ... if this is assignment, emit it in all cases
                if (is_assignment)
                {
                    assert ((*object)->name());

                    //  Flush any 'out' parameter initializations
                    for (auto& init : out_inits) {
                        current_functions.back().prolog.statements.push_back(init + ";");
                    }
                    out_inits = {};

                    //  Then add this statement

                    //  Use ::operator= for base classes
                    if ((*object)->has_name("this")) {
                        current_functions.back().prolog.statements.push_back(
                            print_to_string( *(*object)->get_object_type() ) +
                            "::operator= ( " +
                            initializer +
                            " );"
                        );
                    }
                    //  Else just use infix assignment
                    else {
                        current_functions.back().prolog.statements.push_back(
                            object_name +
                            " = " +
                            initializer +
                            ";"
                        );
                    }
                }
                //  (b) ... if this isn't assignment, only need to emit it if it was
                //          explicit, or is a base type or 'that' initializer
                else if (
                    found_explicit_init
                    || is_object_before_base
                    || (
                        (*object)->has_name("this")
                         && !initializer.empty()
                        )
                    || emitting_that_function
                    )
                {
                    if (is_object_before_base) {
                        assert (is_object_before_base->name());
                        object_name =
                            print_to_string( *is_object_before_base->parent_declaration->name() )
                            + "_"
                            + (*object)->name()->to_string()
                            + "_as_base";
                    }

                    //  Flush any 'out' parameter initializations
                    auto out_inits_with_commas = [&]() -> std::string {
                        auto ret = std::string{};
                        for (auto& init : out_inits) {
                            ret += init + ", ";
                        }
                        out_inits = {};
                        return ret;
                    }();

                    //  If there were any, wedge them into this initializer
                    //  using (holds nose) the comma operator and extra parens
                    //  as we add this statement
                    if (!out_inits_with_commas.empty()) {
                        current_functions.back().prolog.mem_inits.push_back(
                            separator +
                            object_name +
                            "{(" +
                            out_inits_with_commas +
                            initializer +
                            " )}"
                        );
                    }
                    else {
                        if (initializer == "{}") {
                            initializer = "";
                        }
                        current_functions.back().prolog.mem_inits.push_back(
                            separator +
                            object_name +
                            "{ " +
                            initializer +
                            " }"
                        );
                    }
                    separator = ", ";
                }

                //  And on to the next data member...
                ++object;
            }

            //  Now no data members should be left over
            if (object != objects.end())
            {
                errors.emplace_back(
                    (*object)->position(),
                    canonize_object_name(*object) + " was not initialized - did you forget to write a default initializer, or assign to it in the operator= body?"
                );
                errors.emplace_back(
                    (*object)->position(),
                    "see declaration for '" + canonize_object_name(*object) + "' here"
                );
                errors.emplace_back(
                    (*object)->position(),
                    error_msg
                );
                return;
            }

            //  Flush any possible remaining 'out' parameters
            for (auto& init : out_inits) {
                current_functions.back().prolog.statements.push_back(init + ";");
            }
        }

        //  For a constructor, print the type name instead of the operator= function name
        assert(n.parent_is_type());
        if (!is_assignment)
        {
            printer.print_cpp2( prefix, n.position() );
            printer.print_cpp2( type_qualification_if_any_for(n), n.position() );
            printer.print_cpp2( print_to_string( *n.parent_declaration->name() ), n.position() );
            emit( *func, false, true );
        }
        //  For an assignment operator, similar to emitting an ordinary function
        else
        {
            assert (!current_functions.empty());
            current_functions.back().epilog.push_back( "return *this;");
            printer.print_cpp2( prefix, n.position() );
            printer.print_cpp2( "auto " + type_qualification_if_any_for(n) + print_to_string( *n.name() ), n.position());
            emit( *func );
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(
        declaration_node const& n,
        std::string const&      capture_intro = {}
    )
        -> void
    {   STACKINSTR
        // Helper for declarations with parent *template-head*s.
        auto const emit_parent_template_parameters = [&]() {
            auto parent_template_parameters = std::string{};
            auto parent = n.parent_declaration;
            while (
                parent
                && parent->is_type()
                )
            {
                if (parent->requires_clause_expression) {
                    parent_template_parameters =
                        "requires( " + print_to_string(*parent->requires_clause_expression) + " )\n"
                        + parent_template_parameters;
                }
                if (parent->template_parameters) {
                    parent_template_parameters =
                        "template " + print_to_string( *parent->template_parameters, false, true )
                        + " " + parent_template_parameters;
                }
                parent = parent->parent_declaration;
            }
            printer.print_cpp2(parent_template_parameters, n.position());
        };

        //  Helper for declarations that can have requires-clauses
        auto const emit_requires_clause = [&]() {
            if (
                n.requires_clause_expression
                || !function_requires_conditions.empty()
                )
            {
                printer.print_extra("\n");
                printer.ignore_alignment( true, n.position().colno + 4 );
                if (printer.get_phase() == printer.phase1_type_defs_func_decls) {
                    // Workaround GCC 10 not supporting requires in forward declarations in some cases.
                    // See commit 5a0d77f8e297902c0b9712c5aafb6208cfa4c139.
                    if (n.is_object() || n.parent_is_type()) {
                        printer.print_extra("CPP2_REQUIRES_ (");
                    }
                    else {
                        printer.print_extra("CPP2_REQUIRES (");
                    }
                }
                else {
                    printer.print_extra("requires (");
                }

                if (n.requires_clause_expression) {
                    emit(*n.requires_clause_expression);
                    if (!function_requires_conditions.empty()) {
                        printer.print_extra(" && ");
                    }
                }

                if (!function_requires_conditions.empty()) {
                    printer.print_extra(function_requires_conditions.front());
                    for (auto it = std::cbegin(function_requires_conditions)+1; it != std::cend(function_requires_conditions); ++it) {
                        printer.print_extra(" && " + *it);
                    }
                }

                printer.print_extra(") ");
                function_requires_conditions = {};
                printer.ignore_alignment( false );
            }
        };


        //  Declarations are handled in multiple passes,
        //  but we only want to do the sema checks once
        if (
            printer.get_phase() == printer.phase2_func_defs
            && !sema.check(n)
            )
        {
            return;
        }

        //  In phase 0, only need to consider namespaces and types

        if (
            printer.get_phase() == printer.phase0_type_decls
            && !n.is_namespace()
            && !n.is_type()
            )
        {
            return;
        }

        //  If this is a generated declaration (negative source line number),
        //  add a line break before
        if (
            printer.get_phase() == printer.phase2_func_defs
            && n.position().lineno < 1
            )
        {
            printer.print_extra("\n");
        }

        auto guard0 = stack_value(having_signature_emitted, &n);
        auto guard1 = stack_element(current_declarations, &n);
        current_names.push_back(&n);
        auto guard2 = stack_size_if(current_names, !n.is_namespace());

        //  Handle aliases

        if (n.is_alias())
        {
            auto& a = std::get<declaration_node::an_alias>(n.type);
            assert(a);

            //  Namespace-scope aliases are emitted in phase 1,
            //  type-scope object aliases in both phases 1 and 2, and
            //  function-scope aliases in phase 2
            if (
                (
                    !n.parent_is_function()
                    && printer.get_phase() == printer.phase1_type_defs_func_decls
                    )
                ||
                (
                    n.parent_is_type()
                    && n.is_object_alias()
                    && printer.get_phase() == printer.phase2_func_defs
                    )
                ||
                (
                    n.parent_is_function()
                    && printer.get_phase() == printer.phase2_func_defs
                    )
                )
            {
                assert(
                    a->is_type_alias()
                    || a->is_namespace_alias()
                    || a->is_object_alias()
                );

                //  If we're in a type scope, handle the access specifier
                if (
                    n.parent_is_type()
                    && printer.get_phase() == printer.phase1_type_defs_func_decls
                    )
                {
                    if (!n.is_default_access()) {
                        printer.print_cpp2(to_string(n.access) + ": ", n.position());
                    }
                    else {
                        printer.print_cpp2("public: ", n.position());
                    }
                }

                //  Emit template parameters if any
                if (
                    a->is_object_alias()
                    && n.parent_is_type()
                    && printer.get_phase() == printer.phase2_func_defs
                    )
                {
                    emit_parent_template_parameters();
                }

                if (n.template_parameters) {
                    printer.print_cpp2("template", n.position());
                    emit(*n.template_parameters, false, true);
                    printer.print_cpp2(" ", n.position());
                }

                //  Emit requires clause if any
                emit_requires_clause();

                //  Handle type aliases
                if (a->is_type_alias()) {
                    printer.print_cpp2(
                        "using "
                            + print_to_string(*n.identifier)
                            + " = "
                            + print_to_string( *std::get<alias_node::a_type>(a->initializer) )
                            + ";\n",
                        n.position()
                    );
                }

                //  Handle namespace aliases
                else if (a->is_namespace_alias()) {
                    printer.print_cpp2(
                        "namespace "
                            + print_to_string(*n.identifier)
                            + " = "
                            + print_to_string( *std::get<alias_node::a_namespace>(a->initializer) )
                            + ";\n",
                        n.position()
                    );
                }

                //  Handle object aliases:
                //      - at function scope, it's const&
                //      - at namespace scope, it's inline constexpr
                //      - at type scope, it's also inline constexpr but see note (*) below
                else if (a->is_object_alias())
                {
                    auto type = std::string{"auto"};
                    if (a->type_id) {
                        type = print_to_string(*a->type_id);
                    }

                    auto print_initializer_to_string = [&](expression_node const& n) -> std::string {
                        //  If this expression is just a single expression-list, we can
                        //  take over direct control of emitting it without needing to
                        //  go through the whole grammar, and surround it with braces
                        if (n.is_expression_list()) {
                            return "{ "
                                   + print_to_string(*n.get_expression_list(), false)
                                   + " }";
                        }
                        //  Otherwise, just emit the general expression as usual
                        else {
                            return " = "
                                   + print_to_string(n);
                        }
                    };

                    //  (*) If this is at type scope, Cpp1 requires an out-of-line declaration dance
                    //  for some cases to work - see https://stackoverflow.com/questions/11928089/
                    if (n.parent_is_type())
                    {
                        assert (n.parent_declaration->name());

                        if (printer.get_phase() == printer.phase1_type_defs_func_decls) {
                            printer.print_cpp2(
                                "static const "
                                    + type + " "
                                    + print_to_string(*n.identifier)
                                    + ";\n",
                                n.position()
                            );
                        }
                        else if (printer.get_phase() == printer.phase2_func_defs) {
                            //  The following logic is not yet complete, so give a diagnostic for now
                            if (n.parent_declaration->parent_is_type()) {
                                errors.emplace_back(
                                    n.position(),
                                    "(temporary alpha limitation) an object alias cannot yet appear inside a nested type"
                                );
                                return;
                            }

                            printer.print_cpp2(
                                "inline CPP2_CONSTEXPR "
                                    + type
                                    + " "
                                    + type_qualification_if_any_for(n)
                                    + print_to_string(*n.identifier)
                                    + print_initializer_to_string( *std::get<alias_node::an_object>(a->initializer) )
                                    + ";\n",
                                n.position()
                            );
                        }
                    }
                    //  Otherwise, at function and namespace scope we can just define
                    else
                    {
                        auto intro = std::string{};
                        if (n.parent_is_function()) {
                            intro = "constexpr";
                        }
                        else if (n.parent_is_namespace()) {
                            intro = "inline constexpr";
                        }

                        printer.print_cpp2(
                            type + " "
                                + intro + " "
                                + print_to_string(*n.identifier)
                                + print_initializer_to_string( *std::get<alias_node::an_object>(a->initializer) )
                                + ";\n",
                            n.position()
                        );
                    }
                }

                else {
                    assert(!"ICE: should be unreachable - invalid alias");
                }

                return;
            }
        }


        //  Handle other declarations

        auto need_to_generate_assignment      = false;
        auto need_to_generate_move            = false;
        auto need_to_generate_postfix_inc_dec = false;

        if (
            n.is_function()
            && n.has_name()
            )
        {   // reset the 'that' flags
            emitting_that_function      = false;
            emitting_move_that_function = false;
            already_moved_that_members  = {};
        }

        auto is_main =
            !n.parent_declaration
            && n.has_name("main")
            ;
        auto is_in_type = n.parent_is_type();

        if (!check_shadowing_of_type_scope_names(n)) {
            return;
        }


        //  If this is a function that has multiple return values,
        //  first we need to emit the struct that contains the returns
        if (
            printer.get_phase() == printer.phase1_type_defs_func_decls
            && n.is_function()
            )
        {
            auto& func = std::get<declaration_node::a_function>(n.type);
            assert(func);

            if (func->returns.index() == function_type_node::list)
            {
                auto& r = std::get<function_type_node::list>(func->returns);
                assert(r);
                assert(std::ssize(r->parameters) > 0);

                auto func_name = n.name()->to_string();

                //  If it's a single named value, emit it as an anonymous return value
                if (std::ssize(r->parameters) == 1)
                {
                    printer.print_extra(
                        "\nusing "
                        + func_name + "_ret = "
                        + print_to_string( *r->parameters[0]->declaration->get_object_type() )
                        + ";"
                    );
                }
                //  Else just emit it as an ordinary struct
                else
                {
                    printer.print_extra( "\nstruct " + multi_return_type_name(n) + " ");
                    emit(*r, true);
                }
                printer.print_extra( "\n" );
            }
        }

        //  If this is a class definition that has data members before bases,
        //  first we need to emit the aggregate that contains the members
        if (
            n.is_type()
            && printer.get_phase() == printer.phase1_type_defs_func_decls
            )
        {
            assert(
                n.initializer
                && n.initializer->is_compound()
            );
            auto& compound_stmt = std::get<statement_node::compound>(n.initializer->statement);

            assert(compound_stmt);
            auto found = false;

            for (auto& stmt : compound_stmt->statements)
            {
                if (stmt->is_declaration())
                {
                    auto& decl = std::get<statement_node::declaration>(stmt->statement);
                    assert(decl);
                    assert(decl->name());

                    auto emit_as_base =
                        decl->get_decl_if_type_scope_object_name_before_a_base_type(*decl->name());

                    if (emit_as_base) {
                        printer.print_extra(
                            "\nstruct "
                                + print_to_string(*decl->parent_declaration->name())
                                + "_"
                                + decl->name()->to_string()
                                + "_as_base { "
                                + print_to_string( *decl->get_object_type() )
                                + " "
                                + decl->name()->to_string()
                                + "; };"
                        );
                        found = true;
                    }
                }
            }

            if (found) {
                printer.print_extra("\n");
            }
        }

        //  In class definitions, emit the explicit access specifier if there
        //  is one, or default to private for data and public for functions
        if (printer.get_phase() == printer.phase1_type_defs_func_decls)
        {
            if (!n.is_default_access()) {
                assert (is_in_type);
                printer.print_cpp2(to_string(n.access) + ": ", n.position());
            }
            else if (is_in_type) {
                if (n.is_object()) {
                    printer.print_cpp2("private: ", n.position());
                }
                else {
                    printer.print_cpp2("public: ", n.position());
                }
            }
        }

        //  Print a line directive before every function definition, excluding lambdas.
        //  This is needed to enable debugging with lldb.
        if (
            printer.get_phase() == printer.phase2_func_defs
            && n.is_function()
            && n.has_name()
            && n.initializer
            )
        {
            printer.print_extra("");
        }

        //  If this is a function definition and the function is inside
        //  type(s) that have template parameters and/or requires clauses,
        //  emit those outer template parameters and requires clauses too
        if (
            printer.get_phase() == printer.phase2_func_defs
            && n.is_function()
            && n.initializer    // only if the function has a definition (is not abstract)
            )
        {
            emit_parent_template_parameters();
        }

        //  Now, emit our own template parameters
        if (
            n.template_parameters
            && (
                printer.get_phase() <  printer.phase2_func_defs
                || n.is_object()
                || (
                    n.is_function()
                    && n.has_name()     // only if it is not unnamed function aka lambda
                    && n.initializer    // only if the function has a definition (is not abstract)
                    && printer.get_phase() == printer.phase2_func_defs
                    )
                )
            && (
                !n.is_concept()
                || printer.get_phase() == printer.phase1_type_defs_func_decls
                )
            )
        {
            printer.print_cpp2("template", n.position());
            emit(*n.template_parameters, false, true);
            printer.print_cpp2(" ", n.position());
        }

        //  User-defined type
        if (n.is_type())
        {
            assert(
                n.initializer
                && n.initializer->is_compound()
            );
            auto& compound_stmt = std::get<statement_node::compound>(n.initializer->statement);

            if (printer.get_phase() != printer.phase2_func_defs)
            {
                if (n.requires_clause_expression) {
                    printer.print_cpp2("requires( ", n.requires_pos);
                    emit(*n.requires_clause_expression);
                    printer.print_cpp2(" )\n", n.requires_pos);
                }

                printer.print_cpp2("class ", n.position());
                emit(*n.identifier);

                //  Type declaration
                if (printer.get_phase() == printer.phase0_type_decls) {
                    printer.print_cpp2( ";\n", n.position() );
                    return;
                }
            }

            if (
                n.is_type_final()
                && printer.get_phase() == printer.phase1_type_defs_func_decls
                )
            {
                printer.print_cpp2( " final", n.position() );
            }

            //  Type definition
            auto separator              = std::string{":"};
            auto started_body           = false;
            auto saved_for_body         = std::vector<std::pair<std::string, source_position>>{};
            auto found_constructor      = false;
            auto found_that_constructor = false;
            assert(compound_stmt);

            auto start_body = [&]{
                if (!started_body) {
                    printer.print_cpp2(" {", compound_stmt->position());
                    started_body = true;
                    for (auto& [line, pos] : saved_for_body) {
                        printer.print_cpp2(line + "\n", pos);
                    }
                }
            };

            for (auto& stmt : compound_stmt->statements)
            {
                assert(stmt);
                if (
                    !stmt->is_declaration()
                    && !stmt->is_using()
                    )
                {
                    //  We will already have emitted an error for this in sema.check
                    return;
                }

                //  If it's a using statement, save it up if we haven't started the body yet

                if (stmt->is_using()) {
                    auto& use = std::get<statement_node::using_>(stmt->statement);
                    assert(use);
                    if (started_body) {
                        emit(*use);
                    }
                    else {
                        saved_for_body.emplace_back( print_to_string(*use), use->position() );
                    }
                    continue;
                }

                //  Else it's a declaration...

                auto& decl = std::get<statement_node::declaration>(stmt->statement);
                assert(decl);

                if (
                    decl->is_alias()
                    && printer.get_phase() == printer.phase1_type_defs_func_decls
                    )
                {
                    if (started_body) {
                        emit(*decl);
                    }
                    else {
                        saved_for_body.emplace_back( print_to_string(*decl), decl->position() );
                    }
                    continue;
                }

                if (decl->is_constructor()) {
                    found_constructor = true;
                }
                if (decl->is_constructor_with_that()) {
                    found_that_constructor = true;
                }

                //  First we'll encounter the base types == subobjects named "this"
                //  and any data members declared before them that we push into private bases
                assert(decl->name());
                auto emit_as_base =
                    decl->get_decl_if_type_scope_object_name_before_a_base_type(*decl->name())
                    || decl->has_name("this")
                    ;
                if (emit_as_base)
                {
                    //  Do the sema check for these declarations here, because we're
                    //  handling them here instead of going through emit() for them
                    if (!sema.check(*decl)) {
                        return;
                    }

                    if (decl->has_name("this")) {
                        if (printer.get_phase() == printer.phase1_type_defs_func_decls) {
                            printer.print_cpp2(
                                separator + " public " + print_to_string(*decl->get_object_type()),
                                compound_stmt->position()
                            );
                            separator = ",";
                        }
                    }
                    else
                    {
                        if (printer.get_phase() == printer.phase1_type_defs_func_decls) {
                            printer.print_cpp2(
                                separator
                                    + " public "
                                    + print_to_string(*decl->parent_declaration->name())
                                    + "_"
                                    + decl->name()->to_string()
                                    + "_as_base",
                                compound_stmt->position()
                            );
                            separator = ",";
                        }
                    }
                    current_names.push_back(decl.get());
                }
                //  Then we'll switch to start the body == other members
                else
                {
                    if (printer.get_phase() == printer.phase1_type_defs_func_decls) {
                        start_body();
                    }
                    emit(*decl);
                }
            }

            if (printer.get_phase() == printer.phase1_type_defs_func_decls)
            {
                //  Ensure we emit the { even if there are only bases in the type
                start_body();

                auto id     = print_to_string(*n.identifier);
                auto indent = static_cast<size_t>(
                                std::clamp(
                                    compound_stmt->body_indent,
                                    n.position().colno,
                                    n.position().colno + 5      // sanity check
                                    )
                                );
                auto prefix = "\n" + std::string( indent, ' ' ) + "public: ";

                if (n.member_function_generation)
                {
                    //  If no constructor was defined, there should only be
                    //  a default constructor, so generate that
                    if (!found_constructor) {
                        printer.print_extra( prefix + id + "() = default;" );
                    }

                    //  If no 'that' constructor was defined, disable copy/move
                    //  so that Cpp1 doesn't silently generate it anyway
                    if (!found_that_constructor) {
                        printer.print_extra( prefix + id + "(" + id + " const&) = delete; /* No 'that' constructor, suppress copy */" );
                        printer.print_extra( prefix + "auto operator=(" + id + " const&) -> void = delete;" );
                    }

                    if (!found_constructor || !found_that_constructor) {
                        printer.print_extra( "\n" );
                    }
                }

                printer.print_cpp2("};\n", compound_stmt->close_brace);
            }
        }


        //  Namespace
        if (n.is_namespace())
        {
            printer.print_cpp2("namespace ", n.position());

            //  "_" is the anonymous namespace, which is just whitespace in Cpp1
            if (auto tok = n.identifier->get_token();
                tok
                && *tok != "_"
                )
            {
                emit(*n.identifier);
            }

            assert(
                n.initializer
                && n.initializer->is_compound()
            );
            auto& compound_stmt = std::get<statement_node::compound>(n.initializer->statement);

            printer.print_cpp2(" {", compound_stmt->position());

            assert(compound_stmt);
            for (auto& stmt : compound_stmt->statements) {
                assert(stmt);
                if (stmt->is_declaration()) {
                    auto& decl = std::get<statement_node::declaration>(stmt->statement);
                    assert(decl);
                    emit(*decl);
                }
                else if (stmt->is_using()) {
                    auto& use = std::get<statement_node::using_>(stmt->statement);
                    assert(use);
                    emit(*use);
                }
                else {
                    errors.emplace_back(
                        stmt->position(),
                        "a namespace scope must contain only declarations or 'using' statements, not other code"
                    );
                    return;
                }
            }

            printer.print_cpp2("}\n", compound_stmt->close_brace);
        }

        //  Function
        else if (
            n.is_function()
            && (
                printer.get_phase() < printer.phase2_func_defs
                || n.initializer    // only emit definition if the function has one (is not abstract)
                || n.is_defaultable_function()
                )
            )
        {
            auto is_streaming_operator = [](std::string_view sv) {
                return
                    sv == "operator<<"
                    || sv == "operator>>"
                    ;
                };

            auto is_binary_arithmetic_operator = [](std::string_view sv) {
                return
                    sv == "operator+"
                    || sv == "operator-"
                    || sv == "operator*"
                    || sv == "operator/"
                    || sv == "operator%"
                    ;
                };

            auto emit_as_friend =
                n.name()
                && (
                    is_streaming_operator( n.name()->as_string_view() )
                    || (!n.is_function_with_this() && is_binary_arithmetic_operator( n.name()->as_string_view() ))
                    )
                ;

            //  Start fresh (there may be one spurious leftover
            //  requires-condition created during the declarations pass)
            function_requires_conditions = {};

            auto& func = std::get<declaration_node::a_function>(n.type);
            assert(func);

            current_functions.push(
                &n,
                func.get(),
                n.find_parent_declared_value_set_functions()
                );
            auto guard0 = finally([&]{ current_functions.pop(); });

            auto guard1 = stack_size(current_names);

            //  If this is at expression scope, we can't emit "[[nodiscard]] auto name"
            //  so print the provided intro instead, which will be a Cpp1 lambda-introducer
            if (capture_intro != "")
            {
                assert (!n.identifier && !is_main);
                printer.print_cpp2(capture_intro, n.position());
                emit( *func );
            }

            //  Else start introducing a normal function
            else
            {
                assert (n.identifier);

                //  Handle member functions
                std::string prefix  = {};
                std::string suffix1 = {};
                std::string suffix2 = {};

                if (n.is_constexpr) {
                    prefix += "constexpr ";
                }

                if (
                    !n.has_initializer()
                    && n.is_defaultable_function()
                    )
                {
                    suffix2 += " = default";
                }

                //  If there's a 'this' parameter, handle it here (the parameter emission will skip it)
                //  because Cpp1 syntax requires its information to be spread around the declaration syntax
                assert (func->parameters);
                if (
                    !func->parameters->parameters.empty()
                    && func->parameters->parameters[0]->declaration->has_name("this")
                    )
                {
                    assert (is_in_type);
                    auto& this_ = func->parameters->parameters[0];

                    switch (this_->pass) {
                    break;case passing_style::in:
                        suffix1 += " const";
                        //  Cpp1 ref-qualifiers don't belong on virtual functions
                        if (!this_->is_polymorphic()) {
                            suffix1 += "&";
                        }
                    break;case passing_style::inout:
                        //  Cpp1 ref-qualifiers don't belong on virtual functions
                        if (!this_->is_polymorphic()) {
                            suffix1 += " &";
                        }
                    break;case passing_style::out:
                        ; // constructor is handled below
                    break;case passing_style::move:
                        suffix1 += " &&";

                    //  We shouldn't be able to get into a state where these values
                    //  exist here, if we did it's our compiler bug
                    break;case passing_style::copy:
                          case passing_style::forward:
                          default:
                        errors.emplace_back( n.position(), "ICE: invalid parameter passing style, should have been rejected", true);
                    }

                    //  Note: Include a phase check because Cpp1 does not allow
                    //        these on out-of-line definitions
                    if (printer.get_phase() != printer.phase2_func_defs)
                    {
                        switch (this_->mod) {
                        break;case parameter_declaration_node::modifier::implicit:
                            ;
                        break;case parameter_declaration_node::modifier::virtual_:
                            prefix += "virtual ";
                            if (!n.initializer) {
                                suffix2 += " = 0";
                            }
                        break;case parameter_declaration_node::modifier::override_:
                            suffix2 += " override";
                        break;case parameter_declaration_node::modifier::final_:
                            suffix2 += " final";
                        break;default:
                            if (
                                func->is_constructor()
                                && !func->is_constructor_with_that()
                                && generating_assignment_from != &n
                                )
                            {
                                prefix += "explicit ";
                            }
                        }
                    }
                }
                //  Else if there isn't a 'this' parameter, but this function is in a type scope,
                //  it's a Cpp1 non-member function so we need to say so (on the declaration only)
                else if (
                    is_in_type
                    && printer.get_phase() != printer.phase2_func_defs
                    ) {
                    if (emit_as_friend) {
                        prefix += "friend ";
                    }
                    else {
                        prefix += "static ";
                    }
                }

                //  If there's a return type, it's [[nodiscard]] implicitly and all the time
                //  -- for now there's no opt-out, wait and see whether we actually need one
                if (
                    func->has_non_void_return_type()
                    && !func->is_assignment()
                    && !func->is_compound_assignment()
                    && !func->is_increment_or_decrement()
                    && (
                        printer.get_phase() == printer.phase1_type_defs_func_decls
                        || n.has_initializer()  // so we're printing it in phase 2
                        )
                    && (
                        !emit_as_friend         // can't have an attribute on a friend declaration-not-definition
                        || printer.get_phase() != printer.phase1_type_defs_func_decls
                        )
                    && !(
                        n.name()
                        && is_streaming_operator(n.name()->as_string_view())
                        )
                    )
                {
                    printer.print_cpp2( "[[nodiscard]] ", n.position() );
                }

                //  Now we have all the pieces we need for the Cpp1 function declaration

                //  For a special member function, we need to do more work to translate
                //  in-body initialization statements to the Cpp1 mem-init-list syntax
                if (
                    n.is_constructor()
                    || n.is_assignment()
                    )
                {
                    assert(
                        !is_main
                        && suffix2.empty()
                        && "ICE: an operator= shouldn't have been able to generate a suffix (or be main)"
                    );

                    emit_special_member_function(
                        n,
                        prefix
                    );

                    //  If there's no inheritance and this operator= has two parameters,
                    //  it's setting from a single value -- either from the same type
                    //  (aka copy/move) or another type (a conversion) -- so recurse to
                    //  emit related functions if the user didn't write them by hand
                    if (
                        !n.parent_is_polymorphic()
                        && func->parameters->ssize() == 2
                        && generating_assignment_from != &n
                        )
                    {
                        assert(!current_functions.empty());

                        //  A)  Generate (A)ssignment from a constructor,
                        //      if the user didn't write the assignment function themselves
                        if (
                            //  A1) This is '(out   this, that)'
                            //      and no  '(inout this, that)' was written by the user
                            (
                                &n == current_functions.back().declared_value_set_functions.out_this_in_that
                                && !current_functions.back().declared_value_set_functions.inout_this_in_that
                                )
                            ||
                            //  A2) This is '(out   this, move that)'
                            //      and no  '(inout this, move that)' was written by the user
                            //  (*) and no  '(inout this,      that)' was written by the user (*)
                            //
                            //  (*) This third test is to tie-break M2 and A2 in favor of M2. Both M2 and A2
                            //      can generate a missing '(inout this, move that)', and if we have both
                            //      options then we should prefer to use M2 (generate move assignment from
                            //      copy assignment) rather than A2 (generate move assignment from move
                            //      construction) as M2 is a better fit (move assignment is more like copy
                            //      assignment than like move construction, because assignments are designed
                            //      structurally to set the value of an existing 'this' object)
                            (
                                &n == current_functions.back().declared_value_set_functions.out_this_move_that
                                && !current_functions.back().declared_value_set_functions.inout_this_move_that
                                && !current_functions.back().declared_value_set_functions.inout_this_in_that
                                )
                            ||
                            //  A3) This is '(out   this, something-other-than-that)'
                            (
                                n.is_constructor()
                                && !n.is_constructor_with_that()
                                && !contains( current_functions.back().declared_value_set_functions.assignments_from, n.nth_parameter_type_name(2) )
                                )
                            )
                        {
                            need_to_generate_assignment = true;
                        }

                        if (generating_move_from != &n) {

                            //  M)  Generate (M)ove from copy,
                            //      if the user didn't write the move function themselves
                            if (
                                //  M1) This is '(out   this,      that)'
                                //      and no  '(out   this, move that)' was written by the user
                                (
                                    &n == current_functions.back().declared_value_set_functions.out_this_in_that
                                    && !current_functions.back().declared_value_set_functions.out_this_move_that
                                    )
                                ||
                                //  M2) This is '(inout this,      that)'
                                //      and no  '(inout this, move that)' was written by the user
                                (
                                    &n == current_functions.back().declared_value_set_functions.inout_this_in_that
                                    && !current_functions.back().declared_value_set_functions.inout_this_move_that
                                    )
                                )
                            {
                                need_to_generate_move = true;
                            }

                        }
                    }
                }

                //  For a destructor, we need to translate
                else if (n.is_destructor())
                {
                    assert(
                        !is_main
                        // prefix can be "virtual"
                        // suffix1 will be " &&" though we'll ignore that
                        // suffix2 can be "= 0"
                    );

                    //  Print the ~-prefixed type name instead of the operator= function name
                    assert(
                        n.parent_is_type()
                        && n.parent_declaration->name()
                    );
                    printer.print_cpp2(
                        prefix
                            + type_qualification_if_any_for(n)
                            + "~" + print_to_string(*n.parent_declaration->name()),
                        n.position()
                    );
                    emit( *func, false, true);
                    printer.print_cpp2( suffix2, n.position() );
                }

                //  Ordinary functions are easier, do all their declarations except
                //  don't emit abstract virtual functions in phase 2
                else if (
                    n.initializer
                    || printer.get_phase() < printer.phase2_func_defs
                    )
                {
                    printer.print_cpp2( prefix, n.position() );
                    printer.print_cpp2( "auto ", n.position() );
                    if (
                        !emit_as_friend
                        || printer.get_phase() != printer.phase2_func_defs
                        )
                    {
                        printer.print_cpp2( type_qualification_if_any_for(n), n.position() );
                    }

                    emit( *n.name() );
                    emit( *func, is_main, false, suffix1, generating_postfix_inc_dec_from != nullptr );
                    printer.print_cpp2( suffix2, n.position() );

                    //  If this is ++ or --, also generate a Cpp1 postfix version of the operator
                    if (func->is_increment_or_decrement())
                    {
                        if (generating_postfix_inc_dec_from) {
                            assert (generating_postfix_inc_dec_from == &n);
                        }
                        else {
                            need_to_generate_postfix_inc_dec = true;
                        }
                    }
                }
            }

            //  If we're only emitting declarations, end the function declaration
            if (
                printer.get_phase() == printer.phase1_type_defs_func_decls
                && !n.is_function_expression()
                )
            {
                emit_requires_clause();
                if (n.position().lineno < 0) {
                    printer.print_cpp2( ";\n", n.position() );
                }
                else {
                    printer.print_cpp2( ";", n.position() );
                }

                //  Note: Not just early "return;" here because we may need
                //  to recurse to emit generated operator declarations too,
                //  so all the definition work goes into a big 'else' branch
            }

            //  Else emit the definition
            else if (n.initializer)
            {
                if (func->returns.index() == function_type_node::list) {
                    auto& r = std::get<function_type_node::list>(func->returns);
                    function_returns.emplace_back(r.get());
                }
                else if (func->returns.index() == function_type_node::id) {
                    function_returns.emplace_back(
                        &single_anon,               // use special value as a note
                        std::get<function_type_node::id>(func->returns).pass,
                        std::get<function_type_node::id>(func->returns).type->is_wildcard()
                    );
                }
                else {
                    function_returns.emplace_back(nullptr);        // no return type at all
                }

                if (func->has_postconditions()) {
                    current_functions.back().prolog.statements.push_back("cpp2::finally_presuccess cpp2_finally_presuccess;");
                }

                if (func->returns.index() == function_type_node::list)
                {
                    auto& r = std::get<function_type_node::list>(func->returns);
                    assert(r);
                    for (auto& param : r->parameters)
                    {
                        assert(param && param->declaration);
                        auto& decl    = *param->declaration;

                        assert(decl.is_object());
                        auto& id_expr = std::get<declaration_node::an_object>(decl.type);
                        assert(id_expr);

                        auto loc = std::string{};
                        if (!decl.initializer) {
                            loc += ("    cpp2::impl::deferred_init<");
                        }

                        //  For convenience, just capture the id-expression as a string
                        printer.emit_to_string(&loc);
                        emit(*id_expr);
                        printer.emit_to_string();

                        if (!decl.initializer) {
                            loc += (">");
                        }
                        loc += " ";
                        loc += decl.name()->as_string_view();
                        if (decl.initializer)
                        {
                            std::string init;
                            printer.emit_to_string(&init);
                            printer.print_cpp2 ( " {", decl.initializer->position() );
                            if (!decl.initializer->is_expression()) {
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
                        current_functions.back().prolog.statements.push_back(loc);
                    }
                }

                for (auto&& c : func->contracts)
                {
                    auto print = std::string();
                    printer.emit_to_string(&print);
                    auto guard = stack_value(having_signature_emitted, nullptr);
                    emit(*c);
                    printer.emit_to_string();
                    current_functions.back().prolog.statements.push_back(print);
                }

                printer.preempt_position_push( n.equal_sign );

                emit_requires_clause();

                having_signature_emitted = nullptr;

                //  If this is ++ or --, also generate a Cpp1 postfix version of the operator
                if (generating_postfix_inc_dec_from)
                {
                    assert (generating_postfix_inc_dec_from == &n);

                    auto param1 = std::string{"*this"};
                    if (
                        !n.parent_declaration
                        || !n.parent_declaration->is_type()
                        )
                    {
                        param1 = n.first_parameter_name();
                    }

                    printer.print_cpp2(
                        " { auto ret = " + param1 + "; ++" + param1 + "; return ret; }",
                        n.position()
                    );
                }
                //  Else just emit the normal function body
                else {
                    emit(
                        *n.initializer,
                        true, func->position(), func->returns.index() == function_type_node::empty,
                        current_functions.back().prolog,
                        current_functions.back().epilog
                    );
                }

                printer.preempt_position_pop();

                function_returns.pop_back();
            }

            //  Finally, do the potential recursions...

            //  If this was a constructor and we want also want to emit
            //  it as an assignment operator, do it via a recursive call
            if (need_to_generate_assignment)
            {
                //  Reset the 'emitted' flags
                for (auto& statement : n.get_initializer_statements()) {
                    statement->emitted = false;
                }

                //  Then reposition and do the recursive call
                printer.reset_line_to(n.position().lineno);
                generating_assignment_from = &n;
                emit( n, capture_intro );
                generating_assignment_from = {};
            }

            //  If this was a constructor and we want also want to emit
            //  it as an assignment operator, do it via a recursive call
            if (need_to_generate_move)
            {
                //  Reset the 'emitted' flags
                for (auto& statement : n.get_initializer_statements()) {
                    statement->emitted = false;
                }

                //  Then reposition and do the recursive call
                printer.reset_line_to(n.position().lineno);
                generating_move_from = &n;
                emit( n, capture_intro );
                generating_move_from = {};
            }

            //  If this is ++ or --, emit the Cpp1 postfix version via a recursive call
            if (need_to_generate_postfix_inc_dec)
            {
                //  Reset the 'emitted' flags
                for (auto& statement : n.get_initializer_statements()) {
                    statement->emitted = false;
                }

                //  Then reposition and do the recursive call
                printer.reset_line_to(n.position().lineno);
                generating_postfix_inc_dec_from = &n;
                emit( n, capture_intro );
                generating_postfix_inc_dec_from = {};
            }
        }

        //  Object with optional initializer
        else if (
            n.is_object()
            && (
                (
                    n.parent_is_namespace()
                    && printer.get_phase() >= printer.phase1_type_defs_func_decls
                    )
                ||
                (
                    n.parent_is_type()
                    && printer.get_phase() == printer.phase1_type_defs_func_decls
                    )
                ||
                (
                    n.parent_is_function()
                    && printer.get_phase() == printer.phase2_func_defs
                    )
                ||
                (
                    n.is_inside_global_unnamed_function()
                    && printer.get_phase() == printer.phase1_type_defs_func_decls
                    )
                )
            )
        {
            auto& type = std::get<declaration_node::an_object>(n.type);
            if (
                printer.get_phase() == printer.phase2_func_defs
                && type->is_concept()
               )
            {
                return;
            }

            emit_requires_clause();

            if (
                printer.get_phase() != printer.phase2_func_defs
                && n.parent_is_namespace()
                && !type->is_concept()
                )
            {
                printer.print_cpp2( "extern ", n.position() );
            }

            //  Emit "auto" for deduced types (of course)
            if (type->is_wildcard()) {
                assert(n.initializer);
                emit( *type, n.position() );
            }
            //  Otherwise, emit the type
            else {
                //  If there isn't an initializer, use deferred_init<T>
                if (!n.initializer) {
                    if (n.parent_is_function()) {
                        printer.print_cpp2( "cpp2::impl::deferred_init<", n.position() );
                    }
                    else if (!n.parent_is_type()) {
                        errors.emplace_back(
                            n.position(),
                            "a namespace-scope object must have an initializer"
                        );
                        return;
                    }
                }
                printer.preempt_position_push(n.position());
                emit( *type );
                printer.preempt_position_pop();
                //  one pointer is enough for now, pointer-to-function fun can be later
                if (
                    !n.initializer
                    && n.parent_is_function()
                    )
                {
                    printer.print_cpp2( ">", n.position() );
                }
            }

            printer.print_cpp2( " ", n.position());
            assert(n.identifier);

            //  If this is anonymous object (named "_"), generate a unique name
            if (n.has_name("_")) {
                if (n.has_wildcard_type()) {
                    errors.emplace_back(
                        n.identifier->position(),
                        "an object can have an anonymous name or an anonymous type, but not both at the same type (rationale: if '_ := f();' were allowed to keep the returned object alive, that syntax would be dangerously close to '_ = f();' to discard the returned object, and such importantly opposite meanings deserve more than a one-character typo distance; and explicit discarding gets the nice syntax because it's likely more common)"
                    );
                    return;
                }

                //  Minimize diff noise by using ordinals for generated names, not line/col info
                auto next_unique_id = [&]() -> std::string
                {
                    if (current_functions.empty()) {
                        //  Generate a globally unique label for non-function-locals,
                        //  so the declarations and definitions match
                        return labelized_position( n.identifier->get_token() );
                    }
                    //  Else just use a per-function ordinal
                    return std::to_string( ++current_functions.back().ordinal );
                };

                printer.print_cpp2(
                    "auto_" + next_unique_id(),
                    n.identifier->position()
                );
            }
            else {
                emit(*n.identifier);
            }

            if (
                n.parent_is_namespace()
                && printer.get_phase() != printer.phase2_func_defs
                && !type->is_concept()
                )
            {
                printer.print_cpp2( ";", n.position());
                return;
            }

            //  If there's an initializer, emit it
            if (n.initializer)
            {
                printer.add_pad_in_this_line(-100);
                if (type->is_concept()) {
                    printer.print_cpp2( " = ", n.position() );
                } else {
                    printer.print_cpp2( " {", n.position() );
                }

                push_need_expression_list_parens(false);
                assert( n.initializer );
                emit( *n.initializer, false );
                pop_need_expression_list_parens();

                if (!type->is_concept()) {
                    printer.print_cpp2( "}", n.position() );
                }
            }

            printer.print_cpp2( "; ", n.position() );
        }
    }


    //-----------------------------------------------------------------------
    //  print_errors
    //
    auto print_errors()
        -> void
    {
        if (!errors.empty()) {
            //  Delete the output file
            printer.abandon();
        }

        error_entry const* prev                  = {};
        bool               print_fallback_errors = true; // true until we find a non-fallback message

        for (auto&& error : errors)
        {
            //  Only print fallback error messages if we
            //  haven't found a better (non-fallback) one yet
            if (!error.fallback) {
                print_fallback_errors = false;
            }
            if (error.fallback && !print_fallback_errors) {
                continue;
            }

            //  Suppress adjacent duplicates (e.g., can arise when we
            //  reenter operator= to emit it as an assignment operator)
            if (
                !prev
                || error != *prev
                )
            {
                error.print(std::cerr, strip_path(sourcefile));
            }
            prev = &error;
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

    auto had_no_errors()
        -> bool
    {
        return errors.empty();
    }


    //-----------------------------------------------------------------------
    //  debug_print
    //
    auto debug_print() const
        -> void
    {
        //  Only create debug output files if we managed to load the source file.
        //
        if (source_loaded)
        {
            auto out_source  = std::ofstream{ sourcefile+"-source"  };
            source.debug_print( out_source );

            auto out_tokens  = std::ofstream{ sourcefile+"-tokens"  };
            tokens.debug_print( out_tokens );

            auto out_parse   = std::ofstream{ sourcefile+"-parse"   };
            parser.debug_print( out_parse );

            auto out_symbols = std::ofstream{ sourcefile+"-symbols" };
            sema.debug_print  ( out_symbols );
        }
    }


    //-----------------------------------------------------------------------
    //  has_cpp1: pass through
    //
    auto has_cpp1() const
        -> bool
    {
        return source.has_cpp1();
    }


    //-----------------------------------------------------------------------
    //  has_cpp2: pass through
    //
    auto has_cpp2() const
        -> bool
    {
        return source.has_cpp2();
    }
};

}


#endif
