
//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0


//===========================================================================
//  Source loader
//===========================================================================

#ifndef __CPP2_LOAD
#define __CPP2_LOAD

#include "common.h"
#include <fstream>
#include <ostream>
#include <iterator>
#include <regex>
#include <cctype>


namespace cpp2 {

//---------------------------------------------------------------------------
//  move_next: advances i as long as p(line[i]) is true or the end of line
// 
//  line    current line being processed
//  i       current index
//  p       predicate to apply
//
auto move_next(std::string const& line, int& i, auto p) -> bool
{
    while (i < ssize(line) && line[i] && p(line[i])) {
        ++i;
    }
    return i < ssize(line) && line[i];
}


//---------------------------------------------------------------------------
//  peek_first_non_whitespace: returns the first non-whitespace char in line
// 
//  line    current line being processed
//
auto peek_first_non_whitespace(std::string const& line) -> char
{
    auto i = 0;

    //  find first non-whitespace character
    if (!move_next(line, i, isspace)) {
        return '\0';
    }

    return line[i];
}


//---------------------------------------------------------------------------
//  is_preprocessor: returns whether this is a preprocessor line starting
//  with #, and whether it will be followed by another preprocessor line
// 
//  line        current line being processed
//  first_line  whether this is supposed to be the first line (start with #)
//
struct is_preprocessor_ret { 
    bool is_preprocessor; 
    bool has_continuation; 
};
auto is_preprocessor(std::string const& line, bool first_line) 
    -> is_preprocessor_ret
{
    auto i = 0;

    //  see if the first non-whitespace is #
    if (first_line && peek_first_non_whitespace(line) != '#') {
        return { false, false };
    }

    //  return true iff last character is a \ continuation
    return { true, line.back() == '\\' };
}


//---------------------------------------------------------------------------
//  starts_with_import: returns whether the line starts with "import"
// 
//  line    current line being processed
//
auto starts_with_import(std::string const& line) -> bool
{
    const auto ws = std::regex("\\s+"); // whitespace
    auto i = 1;
    for (std::sregex_token_iterator iter(std::begin(line), std::end(line), ws, -1);
        iter != std::sregex_token_iterator();
        ++iter, ++i) {
        if (iter->length() > 0) {
            return *iter == "import";
        }
    }
    return false;
}


//---------------------------------------------------------------------------
//  starts_with_whitespace_slash_slash: is this a "// comment" line
// 
//  line    current line being processed
//
auto starts_with_whitespace_slash_slash(std::string const& line) -> bool
{
    auto i = 0;

    //  find first non-whitespace character
    if (!move_next(line, i, isspace)) {
        return false;
    }

    return i < ssize(line)-1 && line[i] == '/' && line[i+1] == '/';
}


//---------------------------------------------------------------------------
//  starts_with_whitespace_slash_star_and_no_star_slash: is this a "/* comment" line
// 
//  line    current line being processed
//
auto starts_with_whitespace_slash_star_and_no_star_slash(std::string const& line) 
    -> bool
{
    auto i = 0;

    //  find first non-whitespace character
    if (!move_next(line, i, isspace)) {
        return false;
    }

    if (i < ssize(line) - 1 && line[i] == '/' && line[i + 1] == '*') {
        return line.find("*/", i) == std::string::npos;
    }
    else {
        return false;
    }
}


//---------------------------------------------------------------------------
//  starts_with_identifier_colon: returns whether the line starts with an
//  identifier followed by a colon
// 
//  line    current line being processed
//
auto starts_with_identifier_colon(std::string const& line) -> bool
{
    auto i = 0;

    //  find first non-whitespace character
    if (!move_next(line, i, isspace)) {
        return false;
    }

    //  find identifier
    auto j = starts_with_identifier({&line[i], std::size(line)-i});
    if (j == 0) { 
        return false; 
    }
    i += j;

    if (!move_next(line, i, isalnum)) {
        return false;
    }

    //  find first non-whitespace character
    if (!move_next(line, i, isspace)) {
        return false;
    }

    assert (i < ssize(line));
    return line[i] == ':';
}


//---------------------------------------------------------------------------
//  process_cpp_line: just enough to know what to skip over
// 
//  line        current line being processed
//  in_comment  whether this line begins inside a multi-line comment
//
struct process_line_ret { 
    bool all_comment_line; 
    bool empty_line; 
};
auto process_cpp_line(
    std::string const&  line, 
    bool&               in_comment, 
    int&                brace_depth, 
    lineno_t            lineno, 
    std::vector<error>& errors
)
    -> process_line_ret
{
    if (starts_with_whitespace_slash_slash(line)) {
        return { true, false };
    }

    if (starts_with_whitespace_slash_star_and_no_star_slash(line)) {
        in_comment = true;
        return { true, false };
    }

    struct process_line_ret r { in_comment, true };

    auto prev = ' ';
    for (auto i = colno_t{0}; i < ssize(line); ++i) {

        if (!std::isspace(line[i])) {
            r.empty_line = false;
        }

        if (in_comment) {
            switch (line[i]) {
                break;case '/': if (prev == '*') { in_comment = false; }
            }
        }

        else {
            r.all_comment_line = false;
            switch (line[i]) {
                break;case '{':
                    ++brace_depth;

                break;case '}':
                    if (brace_depth < 1) { 
                        //  Might as well give a diagnostic in Cpp1 code since
                        //  we're relying on balanced { } to find Cpp2 code
                        errors.emplace_back(
                            source_position{lineno, i},
                            "closing } does not match a prior {"
                        ); 
                    }
                    else {
                        --brace_depth; 
                    }

                break;case '*':
                    if (prev == '/') { in_comment = true; }

                break;case '/': 
                    if (prev == '/') { in_comment = false; return r; }
            }
        }

        prev = line[i];
    }

    return r;
}


//---------------------------------------------------------------------------
//  process_cpp2_line: to find the end of a Cpp2 definition
//      - find first of ; and {
//          - if ; we're done
//          - if { find matching }
//      - then there must be nothing else on the last line
//  
//  line        current line being processed
//  in_comment  whether this line begins inside a multi-line comment
//
//  Returns:    whether additional lines should be inspected
//
auto process_cpp2_line(
    std::string const&  line, 
    bool&               in_comment, 
    int&                brace_depth, 
    bool&               found_semi,
    bool&               found_openbrace,
    lineno_t            lineno, 
    std::vector<error>& errors
)
    -> bool
{
    auto found_end = false;

    auto prev = ' ';
    for (auto i = colno_t{0}; i < ssize(line); ++i) {

        if (in_comment) {
            switch (line[i]) {
            break;case '/': if (prev == '*') { in_comment = false; }
            }
        }

        else {
            if (found_end && !isspace(line[i])) {
                errors.emplace_back(
                    source_position{lineno, i}, 
                    std::string("unexpected text '")
                        + line[i]
                        + "' - after the closing ; or } of a definition, the rest"
                          " of the line should contain only whitespace or comments"
                ); 
            }

            switch (line[i]) {
            break;case '{':
                ++brace_depth;

            break;case '}':
                if (brace_depth < 1) { 
                    errors.emplace_back(
                        source_position{lineno, i}, 
                        "closing } does not match a prior {"
                    ); 
                }
                else {
                    --brace_depth; 
                    if (brace_depth < 1) {
                        found_end = true;
                    }
                }

            break;case ';':
                if (brace_depth == 0) { found_end = true; }

            break;case '*':
                if (prev == '/') { in_comment = true; }

            break;case '/': 
                if (prev == '/') { in_comment = false; return false; }
            }
        }

        prev = line[i];
    }

    return found_end;
}


//-----------------------------------------------------------------------
// 
//  source: Represents a program source file
// 
//-----------------------------------------------------------------------
//
class source 
{
    std::vector<error>&      errors;
    std::vector<source_line> lines;

public:
    //-----------------------------------------------------------------------
    //  Constructor
    // 
    //  errors      error list
    //
    source(
        std::vector<error>& errors
    )
        : errors{ errors }
        , lines( 1 )        // extra blank to avoid off-by-one everywhere
    {
    }


    //-----------------------------------------------------------------------
    //  load: Read a line-by-line view of 'filename', preserving line breaks
    //
    //  filename                the source file to be loaded
    //  source                  program textual representation
    //
    auto load( 
        std::string const&  filename 
    )
        -> bool
    {
        std::ifstream in{ filename };
        if (!in.is_open()) {
            return false;
        }

        const auto max_line_len = 5000;
        char buf[max_line_len];
        auto in_comment = false;
        auto brace_depth = 0;

        while (in.getline(&buf[0], max_line_len)) {

            //  Handle preprocessor source separately, they're outside the language
            //
            if (auto pre = is_preprocessor(buf, true); pre.is_preprocessor)
            {
                lines.push_back({ &buf[0], source_line::category::preprocessor });
                while (pre.has_continuation && in.getline(&buf[0], max_line_len))
                {
                    lines.push_back({ &buf[0], source_line::category::preprocessor });
                    pre = is_preprocessor(buf, false);
                }
            }

            else
            {
                lines.push_back({ &buf[0], source_line::category::cpp1 });

                //  Switch to cpp2 mode if the line starts with "identifier :"
                //
                if (brace_depth == 0 && starts_with_identifier_colon(lines.back().text)) {

                    //  Mark this line, and preceding comment/blank source, as cpp2
                    lines.back().cat = source_line::category::cpp2;
                    if (std::ssize(lines) > 1) {
                        auto prev = --std::end(lines);
                        while (--prev != std::begin(lines)
                               && (prev->cat == source_line::category::empty
                                   || prev->cat == source_line::category::comment))
                        {
                            prev->cat = source_line::category::cpp2;
                        }
                    }

                    //  Find the end of the definition:
                    auto found_semi = false;
                    auto found_openbrace = false;
                    while (
                        !process_cpp2_line(
                            lines.back().text, 
                            in_comment, 
                            brace_depth, 
                            found_semi, 
                            found_openbrace, 
                            std::ssize(lines)-1, 
                            errors
                        )
                        && in.getline(&buf[0], max_line_len)
                        )
                    {
                        lines.push_back({ &buf[0], source_line::category::cpp2 });
                    }

                }

                //  Else still in Cpp1 code, but could be a comment, empty, or import
                //
                else
                {
                    if (starts_with_import(lines.back().text)) {
                        lines.back().cat = source_line::category::import;
                    }
                    else {
                        auto stats = process_cpp_line(
                            lines.back().text, 
                            in_comment, 
                            brace_depth, 
                            std::ssize(lines) - 1,
                            errors
                        );
                        if (stats.all_comment_line) {
                            lines.back().cat = source_line::category::comment;
                        }
                        else if (stats.empty_line) {
                            lines.back().cat = source_line::category::empty;
                        }
                    }
                }

            }
        }

        if (brace_depth != 0) {
            errors.emplace_back(
                source_position{lineno_t(std::ssize(lines)), 0}, 
                std::string("end of file reached with ") 
                    + std::to_string(brace_depth) + " missing } to match earlier {"
            );
        }

        return true;
    }


    //-----------------------------------------------------------------------
    //  get_lines: Access the source lines
    //
    auto get_lines() const -> std::vector<source_line> const& 
    {
        return lines;
    }


    //-----------------------------------------------------------------------
    //  debug_print
    //
    auto debug_print(std::ostream& o) const -> void 
    {
        for (auto lineno = 0; auto const& line : lines) {
            //  Skip dummy first entry
            if (lineno > 0) {
                o << line.prefix() << line.text << '\n';
            }
            ++lineno;
        }
    }

    //  We don't intend to copy this type, so make it move-only
    //  just to ensure there are no accidental copies
    //
    source(source const&)            = delete;
    source& operator=(source const&) = delete;
    source(source&&)                 = default;
    source& operator=(source&&)      = default;
};

}

#endif
