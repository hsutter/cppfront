
//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.


#ifdef _MSC_VER
#pragma warning(disable: 4456)
#endif

#include "cpp2util.h"


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
#include <unordered_map>

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

    enum class category { empty, preprocessor, comment, import, cpp1, cpp2, rawstring };
    category cat;

    bool all_tokens_are_densely_spaced = true; // to be overridden in lexing if they're not

    source_line(
        std::string_view t = {},
        category         c = category::empty
    )
        : text{t}
        , cat{c}
    { }

    auto indent() const
        -> int
    {
        return
            std::find_if_not( text.begin(), text.end(), &isspace )
                - text.begin();
    }

    auto prefix() const
        -> std::string
    {
        switch (cat) {
        break;case category::empty:         return "/*   */ ";
        break;case category::preprocessor:  return "/* # */ ";
        break;case category::comment:       return "/* / */ ";
        break;case category::import:        return "/* i */ ";
        break;case category::cpp1:          return "/* 1 */ ";
        break;case category::cpp2:          return "/* 2 */ ";
        break;case category::rawstring:     return "/* R */ ";
        break;default: assert(!"illegal category"); abort();
        }
    }
};


using lineno_t = int32_t;
using colno_t  = int32_t;   // not int16_t... encountered >80,000 char line during testing

struct source_position
{
    lineno_t    lineno;     // one-based offset into program source
    colno_t     colno;      // one-based offset into line

    source_position(lineno_t l = 1, colno_t  c = 1 )
        : lineno{ l }, colno{ c }
    {
    }

    auto operator<=>(source_position const&) const = default;

    auto to_string() const
        -> std::string
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

    mutable bool    dbg_was_printed = false;
};

struct string_parts {
    struct cpp_code   { std::string text; };
    struct raw_string { std::string text; };
    enum adds_sequences { no_ends = 0, on_the_beginning = 1, on_the_end = 2, on_both_ends = 3 };

    string_parts(const std::string& beginseq,
                 const std::string& endseq,
                 adds_sequences     strateg) 
     : begin_seq{beginseq}
     , end_seq{endseq}
     , strategy{strateg}
    {
        if (!(strategy & on_the_beginning)) {
            parts.push_back(raw_string{""});
        }
    }

    void add_code(const std::string& text) { parts.push_back(cpp_code{text});}
    void add_string(const std::string& text) { parts.push_back(raw_string{text});}
    void add_string(const std::string_view& text) { parts.push_back(raw_string{std::string(text)});}

    void clear() { parts.clear(); }

    auto generate() const -> std::string {
        
        if (parts.empty()) { 
            return (strategy & on_the_beginning ? begin_seq : std::string{}) 
                 + (strategy & on_the_end ? end_seq : std::string{}); 
        }

        auto result = std::visit(begin_visit{begin_seq, strategy}, 
                                 parts.front());

        if (std::ssize(parts) > 1) { 
            auto it1 = parts.cbegin();
            auto it2 = parts.cbegin()+1;
            for(;it2 != parts.cend(); ++it1, ++it2) {
                result += std::visit(generator_visit{begin_seq, end_seq}, *it1, *it2);
            }
        }

        if (!(strategy & on_the_end)) {
            result += std::visit([this](const auto& lhs) {
                return generator_visit{begin_seq, end_seq}(lhs, raw_string{""});
            }, parts.back());
        }

        result += std::visit(end_visit{end_seq, strategy}, parts.back());

        return result;
    }

    auto is_expanded() const -> bool {
        for (const auto& p : parts) {
            if (std::holds_alternative<cpp_code>(p)) {
                return true;
            }
        }
        return false;
    }

private:
    std::string     begin_seq;
    std::string     end_seq;
    adds_sequences  strategy;
    std::vector<std::variant<raw_string, cpp_code>> parts;

    struct begin_visit {
        std::string begin_seq;
        adds_sequences strategy;

        auto operator()(const raw_string& part) const -> std::string {
            return (strategy & on_the_beginning ? begin_seq : "") + part.text;
        }
        auto operator()(const cpp_code& part) const -> std::string {
            return part.text;
        }
    };

    struct end_visit {
        std::string end_seq;
        adds_sequences strategy;
        auto operator()(const raw_string&) const -> std::string {
            return strategy & on_the_end ? end_seq : "";
        }
        auto operator()(const cpp_code&) const -> std::string {
            return {};
        }
    };

    struct generator_visit {
        std::string begin_seq;
        std::string end_seq;

        auto operator()(const raw_string&, const cpp_code& part ) const -> std::string {
            return end_seq + " + " + part.text;
        }
        auto operator()(const cpp_code&, const raw_string& part ) const -> std::string  {
            return " + " + begin_seq + part.text;
        }
        auto operator()(const raw_string&, const raw_string& part ) const -> std::string  {
            return part.text;
        }
        auto operator()(const cpp_code&, const cpp_code& part ) const -> std::string  {
            return " + " + part.text;
        }
    };
};

struct raw_string
{
    source_position start;
    std::string     text;
    std::string     opening_seq;
    std::string     closing_seq;
    bool            should_interpolate = false;
};

struct multiline_raw_string
{
    std::string     text;
    source_position end = {0, 0};
};

//-----------------------------------------------------------------------
//
//  error: represents a user-readable error message
//
//-----------------------------------------------------------------------
//
struct error_entry
{
    source_position where;
    std::string     msg;
    bool            internal = false;
    bool            fallback = false;   // only emit this message if there was nothing better

    error_entry(
        source_position  w,
        std::string_view m,
        bool             i = false,
        bool             f = false
    )
        : where{w}
        , msg{m}
        , internal{i}
        , fallback{f}
    { }

    auto operator==(error_entry const& that)
        -> bool
    {
        return
            where == that.where
            && msg == that.msg
            ;
    }

    auto print(auto& o, std::string const& file) const
        -> void;
};


//-----------------------------------------------------------------------
//
//  Digit classification, with '\'' digit separators
//
//-----------------------------------------------------------------------
//

//G binary-digit:
//G     one of '0' '1'
//G
auto is_binary_digit(char c)
    -> bool
{
    return
        c == '0'
        || c == '1'
        ;
}

//G digit: one of
//G     binary-digit
//G     one of '2' '3' '4' '5' '6' '7' '8' '9'
//G
auto is_digit(char c)
    -> bool
{
    return isdigit(c);
}

//G hexadecimal-digit:
//G     digit
//G     one of 'A' 'B' 'C' 'D' 'E' 'F'
//G
auto is_hexadecimal_digit(char c)
    -> bool
{
    return isxdigit(c);
}

//G nondigit:
//G     one of 'a'..'z'
//G     one of 'A'..'Z'
//G     _
//G
auto is_nondigit(char c)
    -> bool
{
    return
        isalpha(c)
        || c == '_'
        ;
};

//G identifier-start:
//G     nondigit
//G
auto is_identifier_start(char c)
    -> bool
{
    return is_nondigit(c);
}

//G identifier-continue:
//G     digit
//G     nondigit
//G
auto is_identifier_continue(char c)
    -> bool
{
    return
        is_digit(c)
        || is_nondigit(c)
        ;
}

//G identifier:
//G     identifier-start
//G     identifier identifier-continue
//G     'operator' operator
//G
auto starts_with_identifier(std::string_view s)
    -> int
{
    if (is_identifier_start(s[0])) {
        auto j = 1;
        while (
            j < std::ssize(s)
            && is_identifier_continue(s[j])
            )
        {
            ++j;
        }
        return j;
    }
    return 0;
};


//  Helper to allow one of the above or a digit separator
//  Example:    is_separator_or( is_binary_digit (c) )
//
auto is_separator_or(auto pred, char c)
    -> bool
{
    return
        c == '\''
        || pred(c)
        ;
}


//  Bool to string
//
template<typename T>
    requires std::is_same_v<T, std::string>
auto __as(bool b)
    -> T
{
    return b ? "true" : "false";
}


//  Explicit cast
//
template<typename T>
auto __as(auto x)
    -> T
{
    return T(x);
}


//  String path prefix from filename
//
auto strip_path(std::string const& file)
    -> std::string
{
    auto i = std::ssize(file)-1;
    while (
        i >= 0
        && file[i] != '\\'
        && file[i] != '/'
        )
    {
        --i;
    }
    return {file, __as<size_t>(i+1)};
}


//-----------------------------------------------------------------------
//
//  Misc helpers
//
//-----------------------------------------------------------------------
//
auto replace_all(std::string& s, std::string_view what, std::string_view with)
{
    for (
        std::string::size_type pos{};
        s.npos != (pos = s.find(what.data(), pos, what.length()));
        pos += with.length()
        )
    {
        s.replace(pos, what.length(), with.data(), with.length());
    }
    return s;
}


auto to_upper(char c)
    -> char
{
    //  C toupper is only not-UB in [0,127] and returns the wrong type,
    //  so wrap the range check and the type cast here in one place...
    //  note the 126 (not 127) is intentional to avoid a GCC warning
    if (0 <= c && c <= 126) { return static_cast<char>(std::toupper(c)); }
    //  else
    return c;
}


auto to_upper_and_underbar(std::string_view s)
    -> std::string
{
    auto ret = std::string{s};
    for (char& c : ret) {
        if (std::isalnum(c)) { c = to_upper(c); }
        else                 { c = '_'; }
    }
    return ret;
}


auto starts_with(
    std::string const& s,
    std::string_view   sv
)
    -> bool
{
    return std::string_view(s).starts_with(sv);
}


auto contains(
    auto const& range,
    auto const& value
)
    -> bool
{
    return std::find(
        range.begin(),
        range.end(),
        value
        )
        != range.end();
}

auto contains(
    std::string const& s,
    auto const&        value
)
    -> bool
{
    return s.find(value) != s.npos;
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

    using callback0 = void (*)();
    using callback1 = void (*)(std::string const&);
    struct flag
    {
        int         group = 0;
        std::string name;
        int         unique_prefix = 0;
        std::string description;
        callback0   handler0;
        callback1   handler1;
        std::string synonym;
        bool        opt_out;

        flag(int g, std::string_view n, std::string_view d, callback0 h0, callback1 h1, std::string_view s, bool o)
            : group{g}, name{n}, description{d}, handler0{h0}, handler1{h1}, synonym{s}, opt_out{o}
        { }
    };
    std::vector<flag> flags;
    int max_flag_length = 0;

    std::unordered_map<int, std::string> labels = {
        { 2, "Additional dynamic safety checks and contract information" },
        { 4, "Support for constrained target environments" },
        { 9, "Other options" }
    };

    //  Define this in the main .cpp to avoid bringing <iostream> into the headers,
    //  so that we can't accidentally start depending on iostreams in the compiler body
    static auto print(std::string_view, int width = 0)
        -> void;

public:
    auto process_flags()
        -> void
    {
        constexpr auto processed = -1;

        //  Calculate the unique prefixes
        for (auto flag1 = flags.begin(); flag1 != flags.end(); ++flag1) {
            for (auto flag2 = flag1+1; flag2 != flags.end(); ++flag2) {
                int i = 0;
                while (
                    i < std::ssize(flag1->name)
                    && i < std::ssize(flag2->name)
                    && flag1->name[i] != ' '
                    && flag2->name[i] != ' '
                    && flag1->name[i] == flag2->name[i]
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
        for (auto arg = args.begin(); arg != args.end(); ++arg)
        {
            //  The arg should never be empty, but we're going to do a [0]
            //  subscript next so we should either check or assert
            if (arg->text.empty()) {
                continue;
            }

            //  Provide a way to ignore the rest of the command line
            //  for the purpose of looking for switches
            if (arg->text == "--") {
                arg->pos = processed;
                break;
            }

            for (auto& flag : flags) {
                auto length_to_match = std::max(flag.unique_prefix, __as<int>(arg->text.length())-1);
                if (
                    flag.opt_out
                    && arg->text.ends_with("-")
                    )
                {
                    length_to_match = std::max(flag.unique_prefix, __as<int>(arg->text.length())-2);
                }

                //  Allow a switch to start with either - or /
                if (arg->text.starts_with("-" + flag.name.substr(0, length_to_match))
                    || arg->text.starts_with("/" + flag.name.substr(0, length_to_match))
                    || arg->text == "-" + flag.synonym
                    || arg->text == "/" + flag.synonym
                    )
                {
                    assert(flag.handler0 || flag.handler1);

                    //  If this is a standalone switch, just process it
                    if (flag.handler0) {
                        flag.handler0();
                    }

                    //  Else
                    else {
                        //  If this is a switch that could be suffixed with "-" to opt out
                        if (flag.opt_out) {
                            flag.handler1( arg->text.ends_with("-") ? "-" : "" );
                        }
                        //  Else this is a switch that takes the next arg as its value, so pass that
                        else {
                            if (arg+1 == args.end()) {
                                print("Missing argument to option " + arg->text + " (try -help)\n");
                                help_requested = true;
                            }
                            arg->pos = processed;
                            ++arg;  // move to next argument, which is the argument to this switch
                            flag.handler1(arg->text);
                        }
                    }

                    arg->pos = processed;
                    break;
                }
            }
        }

        std::erase_if( args, [=](auto& arg){ return arg.pos == processed; } );
    }

    auto print_help()
        -> void
    {
        help_requested = true;

        std::sort(
            flags.begin(),
            flags.end(),
            [](auto& a, auto& b){ return a.group < b.group || (a.group == b.group && a.name < b.name); }
        );

        print("\nUsage: cppfront [options] file ...\n\nOptions:\n");
        int last_group = -1;
        for (auto& flag : flags) {
            //  Skip hidden flags
            if (flag.name.front() == '_') {
                continue;
            }

            if (last_group != flag.group) {
                print("\n");
                last_group = flag.group;
                if (!labels[flag.group].empty()) {
                    print( labels[flag.group] + "\n");
                }
            }
            print("  -");
            auto n = flag.name.substr(0, flag.unique_prefix);
            if (flag.unique_prefix < std::ssize(flag.name)) {
                auto name_length = __as<int>(std::min(flag.name.find(' '), flag.name.size()));
                n += "[";
                n += flag.name.substr(flag.unique_prefix, name_length - flag.unique_prefix);
                n += "]";
                n += flag.name.substr(name_length);
            }
            if (flag.opt_out) {
                n += "[-]";
            }
            if (!flag.synonym.empty()) {
                n += ", -" + flag.synonym;
            }
            print(n, max_flag_length + 3);
            print(flag.description);
            print("\n");
        }
    }

    auto add_flag(
        int              group,
        std::string_view name,
        std::string_view description,
        callback0        handler0,
        callback1        handler1,
        std::string_view synonym,
        bool             opt_out
    )
        -> void
    {
        flags.emplace_back( group, name, description, handler0, handler1, synonym, opt_out );
        auto length = std::ssize(name);
        if (opt_out) { length += 3; }   // space to print "[-]"
        if (max_flag_length < length) {
            max_flag_length = length;
        }
    }
    struct register_flag {
        register_flag(
            int              group,
            std::string_view name,
            std::string_view description,
            callback0        handler0,
            callback1        handler1 = {},
            std::string_view synonym  = {},
            bool             opt_out  = false
        );
    };

    auto set_args(
        int   argc,
        char* argv[]
    )
        -> void
    {
        for (auto i = 1; i < argc; ++i) {
            args.emplace_back( i, argv[i] );
        }
    }

    auto help_was_requested()
        -> bool
    {
        return help_requested;
    }

    auto arguments()
        -> std::vector<arg>&
    {
        return args;
    }

    //  This is used only by the owner of the 'main' branch
    //  to generate stable build version strings
    auto gen_version()
        -> void
    {
        help_requested = true;
        std::string_view a = __DATE__;
        std::string_view b = __TIME__;
        std::unordered_map<std::string_view, char> m = { {"Jan",'1'}, {"Feb",'2'}, {"Mar",'3'}, {"Apr",'4'}, {"May",'5'}, {"Jun",'6'}, {"Jul",'7'}, {"Aug",'8'}, {"Sep",'9'}, {"Oct",'A'}, {"Nov",'B'}, {"Dec",'C'} };

        auto stamp = std::to_string(atoi(&a[9])-15);
        stamp += m[a.substr(0, 3)];
        stamp += a.substr(4,2);
        stamp += ":";
        stamp += b.substr(0,2);
        stamp += b.substr(3,2);
        for (auto& c : stamp) { if (c == ' ') { c = '0'; } }
        print( "\"" + stamp + "\"");
    }

    auto print_version()
        -> void
    {
        help_requested = true;
        print("\ncppfront compiler v0.2.1   Build "
            #include "build.info"
        );
        print("\nCopyright(c) Herb Sutter   All rights reserved\n");
        print("\nSPDX-License-Identifier: CC-BY-NC-ND-4.0");
        print("\n  No commercial use");
        print("\n  No forks/derivatives");
        print("\n  Note: This license emphasizes that this is a personal");
        print("\n        experiment; it will be upgraded if that changes\n");
        print("\nAbsolutely no warranty - try at your own risk\n");
    }

} cmdline;

cmdline_processor::register_flag::register_flag(
    int              group,
    std::string_view name,
    std::string_view description,
    callback0        handler0,
    callback1        handler1,
    std::string_view synonym,
    bool             opt_out
)
{
    cmdline.add_flag( group, name, description, handler0, handler1, synonym, opt_out );
}

static cmdline_processor::register_flag cmd_help   (
    0,
    "help",
    "Print help",
    []{ cmdline.print_help(); },
    nullptr,
    "?"
);

static cmdline_processor::register_flag cmd_version(
    0,
    "version",
    "Print version information",
    []{ cmdline.print_version(); }
);

static cmdline_processor::register_flag cmd_gen_version(
    0,
    "_gen_version",
    "Generate version information",
    []{ cmdline.gen_version(); }
);

}

#endif
