
//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0


//===========================================================================
//  Common types
//===========================================================================

#ifndef __CPP2_COMMON
#define __CPP2_COMMON

#include <string>
#include <string_view>
#include <vector>
#include <cstdint>
#include <cctype>
#include <cassert>
#include <iomanip>
#include <compare>
#include <algorithm>

namespace cpp2 {

//-----------------------------------------------------------------------
// 
//  source_line: represents a source code line
// 
//-----------------------------------------------------------------------
//
struct source_line
{
    std::string text;

    enum class category { empty, preprocessor, comment, import, cpp1, cpp2 }
        cat = category::empty;

    auto prefix() const -> std::string 
    {
        switch (cat) {
        break;case category::empty:         return "/*   */ ";
        break;case category::preprocessor:  return "/* # */ ";
        break;case category::comment:       return "/* / */ ";
        break;case category::import:        return "/* i */ ";
        break;case category::cpp1:          return "/* 1 */ ";
        break;case category::cpp2:          return "/* 2 */ ";
        break;default: assert(!"illegal category"); abort();
        }
    }
};


using lineno_t = int32_t;
using colno_t  = int16_t;

struct source_position
{
    lineno_t    lineno;     // one-based offset into program source
    colno_t     colno;      // one-based offset into line

    source_position(lineno_t l = 1, colno_t  c = 1 )
        : lineno{ l }, colno{ c }
    {
    }

    auto operator<=>(source_position const&) const = default;

    auto to_string() const -> std::string
    {
        return "(" + std::to_string(lineno) + "," + std::to_string(colno) + ")";
    }
};

struct comment
{
    enum class comment_kind { line_comment = 0, stream_comment };

    comment_kind    kind;
    source_position start;
    source_position end;
    std::string     text;
};

//-----------------------------------------------------------------------
// 
//  error: represents a user-readable error message
// 
//-----------------------------------------------------------------------
//
struct error 
{
    source_position where;
    std::string     msg;
    bool            internal = false;

    error( source_position w, std::string const& m, bool i = false )
        : where{w}, msg{m}, internal{i}
    { }

    auto print(auto& o, std::string const& file) const -> void 
    {
        o << file ;
        if (where.lineno > 0) { 
            o << "("<< (where.lineno);
            if (where.colno >= 0) {
                o << "," << where.colno;
            }
            o  << ")";
        }
        o << ":";
        if (internal) {
            o << " internal compiler";
        }
        o << " error: " << msg << "\n";
    }
};


//-----------------------------------------------------------------------
// 
//  Digit classification, with '\'' digit separators
// 
//-----------------------------------------------------------------------
//

//G binary-digit: one of
//G     0 1
//G
auto is_binary_digit(char c) -> bool
{ 
    return c == '0' || c == '1'; 
}

//G hexadecimal-digit: one of
//G     0 1 2 3 4 5 6 7 8 9 A B C D E F
//G     
auto is_hexadecimal_digit(char c) -> bool
{ 
    return isxdigit(c);
}

//G digit: one of
//G     0 1 2 3 4 5 6 7 8 9
//G     
auto is_digit(char c) -> bool
{ 
    return isdigit(c); 
}

//G nondigit: { a..z | A..Z | _ }
//G
auto is_nondigit(char c) -> bool
{ 
    return isalpha(c) || c == '_'; 
};

//G identifier-start:
//G     nondigit
//G
auto is_identifier_start(char c) -> bool
{ 
    return is_nondigit(c); 
}

//G identifier-continue:
//G     digit
//G     nondigit
//G
auto is_identifier_continue(char c) -> bool
{ 
    return is_digit(c) || is_nondigit(c); 
}

//G identifier: identifier-start { identifier-continue }*
//G
auto starts_with_identifier(std::string_view s) -> int
{ 
    if (is_identifier_start(s[0])) {
        auto j = 1;
        while (j < std::ssize(s) && is_identifier_continue(s[j])) { ++j; }
        return j;
    }
    return 0;
};

//  Helper to allow one of the above or a digit separator
//  Example:    is_separator_or( is_binary_digit (c) )
//
auto is_separator_or(auto pred, char c) -> bool
{ 
    return c == '\'' || pred(c); 
}


//-----------------------------------------------------------------------
// 
//  String: A helper workaround for passing a string literal as a
//  template argument
//
//-----------------------------------------------------------------------
//
template<size_t N>
struct String 
{
    constexpr String(const char (&str)[N])
    {
        std::copy_n(str, N, value);
    }

    auto operator<=>(String const&) const = default;

    char value[N] = {};
};


//  Bool to string
//
template<typename T>
    requires std::is_same_v<T, std::string>
auto as(bool b) -> T
{
    return b ? "true" : "false";
}


//  Explicit cast
template<typename T>
auto as(auto x) -> T {
    return T(x);
}


//  String path prefix from filename
//
auto strip_path(std::string const& file) -> std::string
{
    auto i = std::ssize(file)-1;
    while (i >= 0 && file[i] != '\\' && file[i] != '/') {
        --i;
    }
    return {file, as<size_t>(i+1)};
}


//-----------------------------------------------------------------------
// 
//  Command line handling
// 
//-----------------------------------------------------------------------
//

class cmdline_processor
{
    bool help_requested = false;

    struct arg
    {
        int pos;
        std::string text;

        arg(int p, char* t) : pos{p}, text{t} { }
    };
    std::vector<arg> args;

    using callback = void (*)();
    struct flag
    {
        std::string name;
        int         unique_prefix = 0;
        std::string description;
        callback    handler;
        std::string synonym;

        flag(std::string_view n, std::string_view d, callback h, std::string_view s) 
            : name{n}, description{d}, handler{h}, synonym{s}
        { }
    };
    std::vector<flag> flags;

    //  Define this in the main .cpp to avoid bringing <iostream> into the headers,
    //  so that we can't accidentally start depending on iostreams in the compiler body
    static auto print(std::string_view, int width = 0) -> void;

public:
    auto process_flags() -> void
    {
        print("cppfront 0.1.1 compiler\nCopyright (C) Herb Sutter\n");

        constexpr auto processed = -1;

        //  Calculate the unique prefixes
        for (auto flag1 = flags.begin(); flag1 != flags.end(); ++flag1) {
            for (auto flag2 = flag1+1; flag2 != flags.end(); ++flag2) {
                int i = 0;
                while (
                    i < std::ssize(flag1->name) && 
                    i < std::ssize(flag2->name) &&
                    flag1->name[i] == flag2->name[i]
                    )
                {
                    ++i;
                }
                //  Record that we found the unique prefix must be at least this long
                flag1->unique_prefix = std::max( flag1->unique_prefix, i+1 );
                flag2->unique_prefix = std::max( flag2->unique_prefix, i+1 );
            }
        }

        //  Look for matches
        for (auto& arg : args) {
            for (auto& flag : flags) {
                if (
                    arg.text.starts_with(flag.name.substr(0, flag.unique_prefix)) ||
                    arg.text == flag.synonym
                    )
                {
                    flag.handler();
                    arg.pos = processed;
                    break;
                }
            }
            if (arg.pos != processed && arg.text.starts_with("-")) {
                arg.pos = processed;
                print("Unknown option: " + arg.text + " (try -help)\n");
                help_requested = true;
            }
        }

        std::erase_if( args, [=](auto& arg){ return arg.pos == processed; } );
    }

    auto print_help() -> void
    {
        std::sort(flags.begin(), flags.end(), [](auto& a, auto& b){ return a.name < b.name; });

        help_requested = true;
        print("\nUsage: cppfront [options] file ...\n\nOptions:\n");
        for (auto& flag : flags) {
            print("  ");
            auto n = flag.name.substr(0, flag.unique_prefix);
            if (flag.unique_prefix < flag.name.length()) {
                n += "[";
                n += flag.name.substr(flag.unique_prefix);
                n += "]";
            }
            if (!flag.synonym.empty()) {
                n += ", " + flag.synonym;
            }
            print(n, 15);
            print(flag.description);
            print("\n");
        }
    }

    struct register_flag {
        register_flag(std::string_view name, std::string_view description, callback handler, std::string_view synonym = {});
    };
    friend register_flag;

    auto set_args(int argc, char* argv[]) -> void {
        for (auto i = 1; i < argc; ++i) {
            args.emplace_back( i, argv[i] );
        }
    }

    auto help_was_requested() -> bool {
        return help_requested;
    }

    auto arguments() -> std::vector<arg>& {
        return args;
    }

    auto print_version() -> void {
        print("All rights reserved\n");
        print("\nSPDX-License-Identifier: CC-BY-NC-ND-4.0");
        print("\n  No commercial use");
        print("\n  No forks/derivatives");
        print("\n");
        print("\nNote: This is a hilariously incomplete personal project.");
        print("\nIt's known to be incomplet and incorrekt, and it has lots of b");
        print("\nad formAt ting. Absolutely no warranty - use at your own risk.");
        print("\n");
        help_requested = true;
    }

} cmdline;

cmdline_processor::register_flag::register_flag(std::string_view name, std::string_view description, callback handler, std::string_view synonym) {
    cmdline.flags.emplace_back( name, description, handler, synonym );
}

static cmdline_processor::register_flag cmd_help   ( 
    "-help",
    "Print help",                
    []{ cmdline.print_help(); },
    "-?"
);

static cmdline_processor::register_flag cmd_version( 
    "-version", 
    "Print version information", 
    []{ cmdline.print_version(); }
);

}

#endif
