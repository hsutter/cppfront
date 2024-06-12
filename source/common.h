
//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.


//  We want cppfront to build cleanly at very high warning levels, with warnings
//  as errors -- so disable a handful that fire incorrectly due to compiler bugs
#ifdef _MSC_VER
    #pragma warning(disable: 4456 4706)
#endif
#if defined(__GNUC__) && __GNUC__ >= 13 && !defined(__clang_major__)
    #pragma GCC diagnostic ignored "-Wdangling-reference"
#endif

#include "cpp2util.h"


//===========================================================================
//  When defined, builds cppfront in an instrumented (and slower) mode that
//  prints more information under -_debug
//===========================================================================

//#define CPP2_DEBUG_BUILD


//===========================================================================
//  Common types
//===========================================================================

#ifndef CPP2_COMMON_H
#define CPP2_COMMON_H

#include <algorithm>
#include <cassert>
#include <cctype>
#include <chrono>
#include <compare>
#include <cstdint>
#include <iomanip>
#include <iterator>
#include <memory>
#include <map>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

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
            unsafe_narrow<int>(std::find_if_not( text.begin(), text.end(), &isspace )
                               - text.begin());
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
using index_t  = int32_t;

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

    void add_code  (const std::string&      text) { parts.push_back(cpp_code{text}); }
    void add_string(const std::string&      text) { parts.push_back(raw_string{text}); }
    void add_string(const std::string_view& text) { parts.push_back(raw_string{std::string(text)}); }

    void clear() { parts.clear(); }

    auto generate() const -> std::string
    {
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
}

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
//G     '__identifier__' keyword    [Note: without whitespace before the keyword]
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
}


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
auto _as(bool b)
    -> T
{
    return b ? "true" : "false";
}


//  Explicit cast
//
template<typename T>
auto _as(auto x)
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
    return {file, _as<size_t>(i+1)};
}


//-----------------------------------------------------------------------
//
//  String: A helper workaround for passing a string literal as a
//  template argument
//
//-----------------------------------------------------------------------
//
template<std::size_t N>
struct String
{
    constexpr String(const char (&str)[N])
    {
        std::copy_n(str, N, value);
    }

    auto operator<=>(String const&) const = default;

    char value[N] = {};
};


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


auto is_empty_or_a_decimal_number(std::string_view s)
    -> bool
{
    auto size = std::ssize(s);
    if (size == 0) { return true; }

    auto i = 0;
    while (i < size && isspace(s[i]) ) { ++i; }
    while (i < size && isdigit(s[i]) ) { ++i; }
    while (i < size && isspace(s[i]) ) { ++i; }
    return i == size;
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


//  Print an integer with 1,000's separators (always commas, not locale-driven)
template <typename T>
    requires std::is_integral_v<T>  // Note: `std::integral` concept not yet available in Apple Clang
auto print_with_thousands(T val)
    -> std::string
{
    auto ret = std::to_string(val % 10);
    auto pos = 0;
    while ((val /= 10) > 0) {
        if ((++pos % 3) == 0) { ret = ',' + ret; }
        ret = std::to_string(val % 10) + ret;
    }
    return ret;
}


//  In keep trying to write string+string_view, and it ought to Just Work without
//  the current workarounds. Not having that is a minor impediment to using safe
//  and efficient string_views, which we should be encouraging. So for my own use
//  and to remove that minor impediment to writing safe and efficient code, I'm
//  just going to add this until we get P2591 in C++26(?) -- See: wg21.link/p2591
//
template<class charT, class traits, class Allocator>
[[nodiscard]] constexpr auto operator+(
    std::basic_string<charT, traits, Allocator> lhs,
    std::type_identity_t<std::basic_string_view<charT, traits>> rhs
    )
    -> std::basic_string<charT, traits, Allocator>
{
    return lhs.append(rhs);
}

template<class charT, class traits, class Allocator>
[[nodiscard]] constexpr auto operator+(
    std::type_identity_t<std::basic_string_view<charT, traits>> lhs,
    std::basic_string<charT, traits, Allocator> rhs
    )
    -> std::basic_string<charT, traits, Allocator>
{
    return rhs.insert(0, lhs);
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
        { 8, "Cpp1 file emission options" },
        { 9, "Cppfront output options" }
    };

    static auto print(std::string_view s, int width = 0)
        -> void
    {
        if (width > 0) {
            std::cout << std::setw(width) << std::left;
        }
        std::cout << s;
    }

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
                auto length_to_match = std::max(flag.unique_prefix, _as<int>(arg->text.length())-1);
                if (
                    flag.opt_out
                    && arg->text.ends_with("-")
                    )
                {
                    length_to_match = std::max(flag.unique_prefix, _as<int>(arg->text.length())-2);
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
                                break;
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
                auto name_length = _as<int>(std::min(flag.name.find(' '), flag.name.size()));
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
            max_flag_length = unsafe_narrow<int>(length);
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
        print("\ncppfront compiler "
            #include "version.info"
        "   Build "
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

static auto flag_verbose = false;
static cmdline_processor::register_flag cmd_verbose(
    9,
    "verbose",
    "Print verbose output and statistics",
    []{ flag_verbose = true; }
);

static auto flag_internal_debug = false;
static cmdline_processor::register_flag cmd_internal_debug(
    0,
    "_debug",
    "Generate internal debug data, implies -verbose",
    []{ flag_internal_debug = true; flag_verbose = true; }
);

static auto flag_print_colon_errors = false;
static cmdline_processor::register_flag cmd_print_colon_errors(
    9,
    "format-colon-errors",
    "Emit ':line:col:' format for messages - lights up some tools",
    []{ flag_print_colon_errors = true; }
);


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

};


//-----------------------------------------------------------------------
//
//  stable_vector: a simple segmented vector with limited interface
//                 that doesn't invalidate by moving memory
//
//-----------------------------------------------------------------------
//
template <typename T>
class stable_vector
{
    static constexpr size_t PageSize = 1'000;

    std::vector< std::vector<T> > data;

    auto add_segment( std::initializer_list<T> init = {} ) -> void {
        data.push_back( init );
        data.back().reserve(PageSize);
    }

public:
    stable_vector( std::initializer_list<T> init = {}) {
        add_segment( init);
    }

    auto empty() const -> bool {
        return data.size() == 1 && data.back().empty();
    }

    auto size() const -> size_t {
        testing.enforce(!data.empty());
        return (data.size() - 1) * PageSize + data.back().size();
    }

    auto ssize() const -> ptrdiff_t {
        return unsafe_narrow<ptrdiff_t>(size());
    }

    auto operator[](size_t idx) -> T& {
        bounds_safety.enforce(idx < size());
        return data[idx / PageSize][idx % PageSize];
    }

    auto operator[](size_t idx) const -> T const& {
        bounds_safety.enforce(idx < size());
        return data[idx / PageSize][idx % PageSize];
    }

    auto back() -> T& {
        return data.back().back();
    }

    auto push_back(T const& t) -> void {
        if (data.back().size() == data.back().capacity()) {
            add_segment();
        }
        data.back().push_back(t);
    }

    template< class... Args >
    auto emplace_back( Args&&... args ) -> T& {
        if (data.back().size() == data.back().capacity()) {
            add_segment();
        }
        return data.back().emplace_back(CPP2_FORWARD(args)...);
    }

    auto pop_back() -> void {
        bounds_safety.enforce(size() > 0);
        if (
            data.back().empty()
            && data.size() > 1
            )
        {
            data.pop_back();
        }
        data.back().pop_back();
    }

    //-------------------------------------------------------------------
    //  Debug interface
    //
    auto debug_print(std::ostream& o) const
        -> void
    {
        o << "stable_vector:\n";
        for (auto i = 0; auto& chunk : data) {
            o << "  -- page " << i++ << " --\n    ";
            for (auto e : chunk) {
                o << e << ' ';
            }
            o << "\n";
        }
    }

    //-------------------------------------------------------------------
    //  Iterator interface
    //
    class iterator {
        stable_vector* v;
        size_t         pos = 0;
    public:
        using value_type        = T;
        using difference_type   = std::ptrdiff_t;
        using pointer           = T*;
        using reference         = T&;
        using iterator_category = std::random_access_iterator_tag;

        iterator( stable_vector* v_ = nullptr, size_t pos_ = 0) : v{v_}, pos{pos_} { }
        auto operator++ ()           -> iterator { if (pos < v->size()) { ++pos; } return *this; }
        auto operator-- ()           -> iterator { if (pos > 0        ) { --pos; } return *this; }
        auto operator+= (size_t off) -> iterator { if (pos + off < v->size()) { pos += off; } else { pos = v->size(); } return *this; }
        auto operator-= (size_t off) -> iterator { if (pos - off > 0        ) { pos -= off; } else { pos = 0;         } return *this; }
        auto operator*  () const     -> T&       { return  (*v)[pos      ]; }
        auto operator-> () const     -> T*       { return &(*v)[pos      ]; }
        auto operator[] (size_t off) -> T&       { return  (*v)[pos + off]; }
        auto operator+  (size_t off) -> iterator { auto i = *this; i += off; return i; }
        auto operator-  (size_t off) -> iterator { auto i = *this; i -= off; return i; }
        auto operator-  (iterator const& that)   -> ptrdiff_t { return pos - that.pos; }
        auto operator<=>(iterator const&) const  -> std::strong_ordering = default;
    };

    class const_iterator {
        stable_vector const* v;
        size_t               pos = 0;
    public:
        using value_type        = const T;
        using difference_type   = std::ptrdiff_t;
        using pointer           = T const*;
        using reference         = T const&;
        using iterator_category = std::random_access_iterator_tag;

        const_iterator( stable_vector const* v_ = nullptr, size_t pos_ = 0) : v{v_}, pos{pos_} { }
        auto operator++ ()           -> const_iterator { if (pos < v->size()) { ++pos; } return *this; }
        auto operator-- ()           -> const_iterator { if (pos > 0        ) { --pos; } return *this; }
        auto operator+= (size_t off) -> const_iterator { if (pos + off < v->size()) { pos += off; } else { pos = v->size(); } return *this; }
        auto operator-= (size_t off) -> const_iterator { if (pos - off > 0        ) { pos -= off; } else { pos = 0;         } return *this; }
        auto operator*  () const     -> T const&       { return  (*v)[pos      ]; }
        auto operator-> () const     -> T const*       { return &(*v)[pos      ]; }
        auto operator[] (size_t off) -> T const&       { return  (*v)[pos + off]; }
        auto operator+  (size_t off) -> const_iterator { auto i = *this; i += off; return i; }
        auto operator-  (size_t off) -> const_iterator { auto i = *this; i -= off; return i; }
        auto operator-  (const_iterator const& that)   -> ptrdiff_t { return pos - that.pos; }
        auto operator<=>(const_iterator const&) const  -> std::strong_ordering = default;
    };

    auto  begin()       -> iterator       { return {this, 0     }; }
    auto  end  ()       -> iterator       { return {this, size()}; }
    auto  begin() const -> const_iterator { return {this, 0     }; }
    auto  end  () const -> const_iterator { return {this, size()}; }
    auto cbegin() const -> const_iterator { return {this, 0     }; }
    auto cend  () const -> const_iterator { return {this, size()}; }
};

template <typename T>
auto operator+ (size_t off, typename stable_vector<T>::iterator const& it) -> typename stable_vector<T>::iterator { auto i = it; i += off; return i; }

template <typename T>
auto operator+ (size_t off, typename stable_vector<T>::const_iterator const& it) -> typename stable_vector<T>::const_iterator { auto i = it; i += off; return i; }

//  And now jump over to std:: to drop in the size/ssize overloads
}
namespace std {
    template <typename T>
    auto  size(cpp2::stable_vector<T> const& v) -> ptrdiff_t { return v. size();  }
    template <typename T>
    auto ssize(cpp2::stable_vector<T> const& v) -> ptrdiff_t { return v.ssize();  }
}
namespace cpp2 {


//-----------------------------------------------------------------------
//
//  Internal instrumentation
//
//-----------------------------------------------------------------------
//

//-----------------------------------------------------------------------
//
//  stackinstr: builds debug information to find causes of large stacks
//
//  Useful if we need to optimize deep recursion to use less stack
//
//-----------------------------------------------------------------------
//
class stackinstr
{
    struct entry
    {
        ptrdiff_t        delta;
        ptrdiff_t        cumulative;
        std::string_view func_name;
        std::string_view file;
        int              line;
        char*            ptr;

        entry(
            std::string_view n,
            std::string_view f,
            int              l,
            char*            p
        )
            : delta     { entries.empty() ? 0 : std::abs(entries.back().ptr - p) }
            , cumulative{ entries.empty() ? 0 : entries.back().cumulative + delta }
            , func_name { n }
            , file      { f }
            , line      { l }
            , ptr       { p }
        { }
    };
    static std::vector<entry> entries;
    static std::vector<entry> deepest;
    static std::vector<entry> largest;

    static auto print(auto&& ee, std::string_view label) {
        std::cout << "\n=== Stack debug information: " << label << " stack ===\n";
        for (auto& e: ee)
        if  (e.ptr) {
            std::cout
                << "  " << std::setw(6)
                << ((std::abs(e.delta) < 1000000)? std::to_string(e.delta) : "-----") << " "
                << std::setw(8)
                << ((std::abs(e.delta) < 1000000)? std::to_string(e.cumulative) : "-------") << " "
                << e.func_name << " (" << e.file << ":" << e.line << ")\n";
        }
    }

public:
    struct guard {
        guard( std::string_view /*name*/, std::string_view /*file*/, int /*line*/, char* /*p*/ ) {
            //if (flag_internal_debug) {
            //    entries.emplace_back(name, file, line ,p);
            //    if (ssize(deepest) < ssize(entries)) {
            //        deepest = entries;
            //    }
            //    if (largest.empty() || largest.back().cumulative < entries.back().cumulative) {
            //        largest = entries;
            //    }
            //}
        }
        ~guard() {
            //if (flag_internal_debug) {
            //    entries.pop_back();
            //}
        }
    };

    static auto print_entries() { print( entries, "Current" ); }
    static auto print_deepest() { print( deepest, "Deepest" ); }
    static auto print_largest() { print( largest, "Largest" ); }
};

std::vector<stackinstr::entry> stackinstr::entries;
std::vector<stackinstr::entry> stackinstr::deepest;
std::vector<stackinstr::entry> stackinstr::largest;

#define STACKINSTR stackinstr::guard _s_guard{ __func__, __FILE__, __LINE__, reinterpret_cast<char*>(&_s_guard) };


//-----------------------------------------------------------------------
//
//  timer:  a little profiling timer to measure time spent in
//          specific sections of code
//
//  Use CPP2_SCOPE_TIMER("unique name") to declare local objects whose
//  total timings will be reported in -verbose in CPP2_DEBUG_BUILD builds.
//
//-----------------------------------------------------------------------
//
class timer
{
    using clock = std::chrono::high_resolution_clock;

    bool                           running  = false;
    std::chrono::time_point<clock> start_tm = clock::now();
    std::chrono::duration<double>  duration = {};

public:
    auto start() {
        testing.enforce( !running );
        running  = true;
        start_tm = clock::now();
    }

    auto stop() {
        testing.enforce( running );
        running   = false;
        duration += clock::now() - start_tm;
    }

    void reset() {
        duration = {};
    }

    auto elapsed() const {
        testing.enforce( !running );
        return std::chrono::duration_cast<std::chrono::milliseconds>(duration);
    }
};

static std::unordered_map<std::string_view, timer> timers;  // global named timers

auto scope_timer(std::string_view name) {
    timers[name].start();
    auto stop = [=]{ timers[name].stop(); };
    return finally( std::move(stop) );
}

#ifdef CPP2_DEBUG_BUILD
#define CPP2_CONCAT(x,y)       x##y
#define CPP2_UNIQUE_NAME(x,y)  CPP2_CONCAT(x,y)
#define CPP2_SCOPE_TIMER(name) auto CPP2_UNIQUE_NAME(timer,__LINE__) = scope_timer(name)
#else
#define CPP2_SCOPE_TIMER(name)
#endif

}

#endif
