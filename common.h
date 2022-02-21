
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

    enum class category { empty, preprocessor, comment, import, cpp, cpp2 }
        cat = category::empty;

    auto prefix() const -> std::string 
    {
        switch (cat) {
        break;case category::empty:         return "|     |  ";
        break;case category::preprocessor:  return "| #   |  ";
        break;case category::comment:       return "| /   |  ";
        break;case category::import:        return "|  i  |  ";
        break;case category::cpp:           return "| 1   |  ";
        break;case category::cpp2:          return "|   2 |  ";
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

    source_position(
        lineno_t l = 0,
        colno_t  c = 0
    )
        : lineno{ l }
        , colno{ c }
    {
    }

    auto to_string() const -> std::string
    {
        return "(" + std::to_string(lineno) + "," + std::to_string(colno) + ")";
    }
};

struct comment
{
    source_position pos;
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
auto is_binary_digit(char c) 
{ 
    return c == '0' || c == '1'; 
}

//G hexadecimal-digit: one of
//G     0 1 2 3 4 5 6 7 8 9 A B C D E F
//G     
auto is_hexadecimal_digit(char c) 
{ 
    return isxdigit(c);
}

//G nonzero-digit: one of
//G     1 2 3 4 5 6 7 8 9
//G     
//G digit: { 0 | nonzero-digit }
//G     
auto is_digit(char c) 
{ 
    return isdigit(c); 
}

//G nondigit: { a..z | A..Z | _ }
//G
auto is_nondigit(char c) 
{ 
    return isalpha(c) || c == '_'; 
};

//G identifier-start:
//G     nondigit
//GT    universal-character-name of class XID_Start
//G
auto is_identifier_start(char c) 
{ 
    return is_nondigit(c); 
}

//G identifier-continue:
//G     digit
//G     nondigit
//GT    universal-character-name of class XID_Continue
//G
auto is_identifier_continue(char c)
{ 
    return is_digit(c) || is_nondigit(c); 
}

//G identifier: identifier-start { identifier-continue }*
//G
auto starts_with_identifier(std::string_view s)
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
auto is_separator_or(auto pred, char c) 
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

    char value[N];
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


}

#endif
