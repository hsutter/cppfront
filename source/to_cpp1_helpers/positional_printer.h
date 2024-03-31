#ifndef CPP2_POSITIONAL_PRINTER_H
#define CPP2_POSITIONAL_PRINTER_H

#include "../parse.h"

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
    9,
    "emit-cppfront-info",
    "Emit cppfront version/build in output file",
    []{ flag_emit_cppfront_info = true; }
);

static auto flag_clean_cpp1 = false;
static cmdline_processor::register_flag cmd_clean_cpp1(
    9,
    "clean-cpp1",
    "Emit clean Cpp1 without #line directives",
    []{ flag_clean_cpp1 = true; }
);

static auto flag_line_paths = false;
static cmdline_processor::register_flag cmd_line_paths(
    9,
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
    9,
    "output filename",
    "Output to 'filename' (can be 'stdout') - default is *.cpp/*.h",
    nullptr,
    [](std::string const& name) { flag_cpp1_filename = name; }
);

static auto flag_print_colon_errors = false;
static cmdline_processor::register_flag cmd_print_colon_errors(
    9,
    "format-colon-errors",
    "Emit ':line:col:' format for messages - lights up some tools",
    []{ flag_print_colon_errors = true; }
);

static auto flag_verbose = false;
static cmdline_processor::register_flag cmd_verbose(
    9,
    "verbose",
    "Print verbose statistics and -debug output",
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

// Defined out of line so we can use flag_print_colon_errors.
auto error_entry::print(
    auto&              o,
    std::string const& file
) const
    -> void
{
    o << file ;
    if (where.lineno > 0) {
        if (flag_print_colon_errors) {
            o << ":" << (where.lineno);
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

} // namespace cpp2

#endif