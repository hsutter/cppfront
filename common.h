
//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception


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
    enum class category { empty, preprocessor, comment, import, cpp, cpp2 } cat;

    auto prefix() const -> std::string 
    {
        switch (cat) {
        break;case category::empty:         return "|     |  ";
        break;case category::preprocessor:  return "| #   |  ";
        break;case category::comment:       return "| /   |  ";
        break;case category::import:        return "|  i  |  ";
        break;case category::cpp:           return "| 1   |  ";
        break;case category::cpp2:          return "|   2 |  ";
        break;default: assert(false);       abort();
        }
    }
};


using lineno_t = int32_t;
using colno_t  = int16_t;

struct source_position
{
    lineno_t    lineno;     // zero-based offset into program
    colno_t     colno;      // one-based offset into line

    source_position(
        int l,
        int c
    )
        : lineno{ lineno_t(l) }
        , colno{ colno_t(c) }
    {
    }
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
        if (where.lineno >= 0) { 
            //  Add 1 to line to make it 1-based (human-readable)
            o << "("<< (where.lineno+1);
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
        while (j < ssize(s) && is_identifier_continue(s[j])) { ++j; }
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
auto as_string(bool b) -> std::string
{
    return b ? "true" : "false";
}


// when a cast is required because... don't get me started on signedness
auto as_size_t(int i) -> size_t {
    return size_t(i);
}


//  String path prefix from filename
//
auto strip_path(std::string const& file) -> std::string
{
    auto i = std::ssize(file)-1;
    while (i >= 0 && file[i] != '\\' && file[i] != '/') {
        --i;
    }
    return {file, as_size_t(i+1)};
}


}

#endif
