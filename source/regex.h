
#ifndef REGEX_H_CPP2
#define REGEX_H_CPP2


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "regex.h2"

#line 56 "regex.h2"
namespace cpp2 {

namespace regex {

#line 63 "regex.h2"
class list_end;

class match_return;

#line 80 "regex.h2"
template<typename CharT, size_t max_groups> class match_context;

#line 92 "regex.h2"
template<typename CharT> class any_matcher_logic;

#line 98 "regex.h2"
template<typename CharT, CharT C> class char_matcher_logic;

#line 104 "regex.h2"
template<typename CharT, typename ...List> class list_matcher_logic;

#line 134 "regex.h2"
template<typename CharT, typename M, int group> class group_matcher_logic;
    

#line 146 "regex.h2"
template<typename CharT, typename M, int min_count, int max_count> class range_matcher_logic;

#line 183 "regex.h2"
template<typename CharT, typename M> class star_matcher_logic;
    

#line 190 "regex.h2"
template<typename Error_out> class regex_parser;

#line 347 "regex.h2"
}
}


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "regex.h2"

//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

// From https://stackoverflow.com/questions/216823/how-to-trim-a-stdstring

// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    rtrim(s);
    ltrim(s);
}

// trim from start (copying)
static inline std::string ltrim_copy(std::string_view s) {
    std::string t(s);
    ltrim(t);
    return t;
}

// trim from end (copying)
static inline std::string rtrim_copy(std::string_view s) {
    std::string t(s);
    rtrim(t);
    return t;
}

// trim from both ends (copying)
static inline std::string trim_copy(std::string_view s) {
    std::string t(s);
    trim(t);
    return t;
}

#line 56 "regex.h2"
namespace cpp2 {

namespace regex {

template<typename CharT> using view = std::basic_string_view<CharT>;
template<typename CharT> using bstring = std::basic_string<CharT>;

class list_end {
      public: list_end() = default;
      public: list_end(list_end const&) = delete; /* No 'that' constructor, suppress copy */
      public: auto operator=(list_end const&) -> void = delete;
};
#line 64 "regex.h2"

class match_return
 {
    public: bool matched {false}; 
    public: size_t length {0}; 

    public: [[nodiscard]] static auto create(auto const& m, auto const& l) -> match_return;

#line 78 "regex.h2"
};

template<typename CharT, size_t max_groups> class match_context
 {

    public: std::array<view<CharT>,max_groups> groups; 

};

/*regular_expression: @interface <CharT> type = {

    match: <Ctx> (str: view<CharT>, inout ctx: Ctx) -> bool;
}*/

template<typename CharT> class any_matcher_logic
 {
    public: [[nodiscard]] static auto match(cpp2::in<view<CharT>> str, auto& ctx) -> match_return;
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: any_matcher_logic() = default;
    public: any_matcher_logic(any_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(any_matcher_logic const&) -> void = delete;

#line 96 "regex.h2"
};

template<typename CharT, CharT C> class char_matcher_logic
 {
    public: [[nodiscard]] static auto match(cpp2::in<view<CharT>> str, auto& ctx) -> match_return;
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: char_matcher_logic() = default;
    public: char_matcher_logic(char_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(char_matcher_logic const&) -> void = delete;

#line 102 "regex.h2"
};

template<typename CharT, typename ...List> class list_matcher_logic
 {
    public: [[nodiscard]] static auto match(cpp2::in<view<CharT>> str, auto& ctx) -> match_return;

#line 110 "regex.h2"
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;

#line 114 "regex.h2"
    private: template<typename First, typename ...Other> [[nodiscard]] static auto match_all(cpp2::in<view<CharT>> str, auto& ctx) -> match_return;
    public: list_matcher_logic() = default;
    public: list_matcher_logic(list_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(list_matcher_logic const&) -> void = delete;


#line 132 "regex.h2"
};

template<typename CharT, typename M, int group> class group_matcher_logic {
    public: [[nodiscard]] static auto match(cpp2::in<view<CharT>> str, auto& ctx) -> match_return;

#line 143 "regex.h2"
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: group_matcher_logic() = default;
    public: group_matcher_logic(group_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_matcher_logic const&) -> void = delete;

#line 144 "regex.h2"
};

template<typename CharT, typename M, int min_count, int max_count> class range_matcher_logic {

    // TODO: Add static assert on min_count and max_count.

    public: [[nodiscard]] static auto match(cpp2::in<view<CharT>> str, auto& ctx) -> match_return;

#line 163 "regex.h2"
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: range_matcher_logic() = default;
    public: range_matcher_logic(range_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_matcher_logic const&) -> void = delete;


#line 181 "regex.h2"
};

template<typename CharT, typename M> class star_matcher_logic: public range_matcher_logic<CharT,M,0,std::numeric_limits<int>::max()> {

#line 186 "regex.h2"
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: star_matcher_logic() = default;
    public: star_matcher_logic(star_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(star_matcher_logic const&) -> void = delete;

#line 187 "regex.h2"
};

#line 190 "regex.h2"
template<typename Error_out> class regex_parser {

    private: std::string_view regex; 
    private: std::vector<std::string> list {}; 
    private: size_t pos {0}; 

    private: size_t named_groups {1}; // Global capture group.

    private: Error_out error_out; 

    public: explicit regex_parser(cpp2::in<std::string_view> r, Error_out const& e);

#line 205 "regex.h2"
    public: [[nodiscard]] static auto create_list_matcher(cpp2::in<std::vector<std::string>> elements) -> std::string;

#line 218 "regex.h2"
    public: auto error(cpp2::in<std::string> message) & -> void;

#line 222 "regex.h2"
    public: [[nodiscard]] auto get_back() & -> std::string;

#line 228 "regex.h2"
    public: [[nodiscard]] auto is_any(cpp2::in<char> c) & -> bool;

#line 236 "regex.h2"
    public: [[nodiscard]] auto is_group(cpp2::in<char> c) & -> bool;

#line 259 "regex.h2"
    public: [[nodiscard]] auto is_range(cpp2::in<char> c) & -> bool;

#line 302 "regex.h2"
    public: [[nodiscard]] auto is_star(cpp2::in<char> c) & -> bool;

#line 315 "regex.h2"
    public: auto parse_until(cpp2::in<char> term) & -> void;

#line 331 "regex.h2"
    public: [[nodiscard]] auto parse() & -> std::string;
    public: regex_parser(regex_parser const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_parser const&) -> void = delete;


#line 338 "regex.h2"
};

template<typename Err> [[nodiscard]] auto generate_template(cpp2::in<std::string_view> regex, Err const& err) -> std::string;

#line 347 "regex.h2"
}
}


//=== Cpp2 function definitions =================================================

#line 1 "regex.h2"

#line 56 "regex.h2"
namespace cpp2 {

namespace regex {

#line 70 "regex.h2"
    [[nodiscard]] auto match_return::create(auto const& m, auto const& l) -> match_return{
      if (m) {
        return { true, l }; 
      }
      else {
        return { false, 0 }; 
      }
    }

#line 94 "regex.h2"
    template <typename CharT> [[nodiscard]] auto any_matcher_logic<CharT>::match(cpp2::in<view<CharT>> str, auto& ctx) -> match_return { return match_return::create(!(CPP2_UFCS(empty)(str)), 1);  }
    template <typename CharT> [[nodiscard]] auto any_matcher_logic<CharT>::to_string() -> bstring<CharT> { return bstring<CharT>(1, '.');  }

#line 100 "regex.h2"
    template <typename CharT, CharT C> [[nodiscard]] auto char_matcher_logic<CharT,C>::match(cpp2::in<view<CharT>> str, auto& ctx) -> match_return { return match_return::create(!(CPP2_UFCS(empty)(str)) && CPP2_UFCS(front)(str) == C, 1);  }
    template <typename CharT, CharT C> [[nodiscard]] auto char_matcher_logic<CharT,C>::to_string() -> bstring<CharT> { return bstring<CharT>(1, C);  }

#line 106 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto list_matcher_logic<CharT,List...>::match(cpp2::in<view<CharT>> str, auto& ctx) -> match_return{
      return match_all<List...>(str, ctx); 
    }

    template <typename CharT, typename ...List> [[nodiscard]] auto list_matcher_logic<CharT,List...>::to_string() -> bstring<CharT>{
      return { (bstring<CharT>() + ... + List::to_string()) }; 
    }

    template <typename CharT, typename ...List> template<typename First, typename ...Other> [[nodiscard]] auto list_matcher_logic<CharT,List...>::match_all(cpp2::in<view<CharT>> str, auto& ctx) -> match_return{
      match_return r {First::match(str, ctx)}; 

      if (r.matched) {
        if constexpr (0 != sizeof...(Other)) {
          match_return o {match_all<Other...>(CPP2_UFCS(substr)(str, r.length), ctx)}; 

          if (o.matched) {
            r.length += std::move(o).length;
          }
          else {
            r = { false, 0 };
          }
        }
      }

      return r; 
    }

#line 135 "regex.h2"
    template <typename CharT, typename M, int group> [[nodiscard]] auto group_matcher_logic<CharT,M,group>::match(cpp2::in<view<CharT>> str, auto& ctx) -> match_return{
        match_return r {M::match(str, ctx)}; 

        if (r.matched) {
            CPP2_ASSERT_IN_BOUNDS(ctx.groups, group) = CPP2_UFCS(substr)(str, 0, r.length);
        }
        return r; 
    }
    template <typename CharT, typename M, int group> [[nodiscard]] auto group_matcher_logic<CharT,M,group>::to_string() -> bstring<CharT> { return "(" + cpp2::to_string(M::to_string()) + ")";  }

#line 150 "regex.h2"
    template <typename CharT, typename M, int min_count, int max_count> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count>::match(cpp2::in<view<CharT>> str, auto& ctx) -> match_return{
      match_return r {true, 0}; 
      match_return o {true, 0}; 

      int count {-1};  // First while is always true

      for( ; (o.matched && cpp2::cmp_less(count,max_count)); o = M::match(CPP2_UFCS(substr)(str, r.length), ctx) ) {
        r.length += o.length;
        count += 1;
      }

      return match_return::create(cpp2::cmp_greater_eq(std::move(count),min_count), std::move(r).length); 
    }
    template <typename CharT, typename M, int min_count, int max_count> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count>::to_string() -> bstring<CharT>{
      std::string r {M::to_string()}; 

      if (min_count == max_count) {
        r += "{" + cpp2::to_string(min_count) + "}";
      }
      else {if (min_count == 0) {
        r += "{," + cpp2::to_string(max_count) + "}";
      }
      else {if (max_count == std::numeric_limits<int>::max()) {
        r += "(" + cpp2::to_string(min_count) + ",}";
      }
      else {
        r += "{" + cpp2::to_string(min_count) + "," + cpp2::to_string(max_count) + "}";
      }}}

      return r; 
    }

#line 186 "regex.h2"
    template <typename CharT, typename M> [[nodiscard]] auto star_matcher_logic<CharT,M>::to_string() -> bstring<CharT> { return M::to_string() + "*";  }

#line 200 "regex.h2"
    template <typename Error_out> regex_parser<Error_out>::regex_parser(cpp2::in<std::string_view> r, Error_out const& e)
        : regex{ r }
        , error_out{ e }{

#line 203 "regex.h2"
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::create_list_matcher(cpp2::in<std::vector<std::string>> elements) -> std::string{
        std::string template_expression {"::cpp2::regex::list_matcher_logic<char, "}; 

        std::string seperator {""}; 
        for ( auto const& cur : elements ) {
            template_expression += seperator + cur;
            seperator = ", ";
        }
        template_expression += ">";

        return template_expression; 
    }

    template <typename Error_out> auto regex_parser<Error_out>::error(cpp2::in<std::string> message) & -> void{
        error_out("Error during parsing of regex '" + cpp2::to_string(regex) + "' at position '" + cpp2::to_string(pos) + "': " + cpp2::to_string(message));
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::get_back() & -> std::string{
        auto b {CPP2_UFCS(back)(list)}; 
        CPP2_UFCS(pop_back)(list);
        return b; 
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_any(cpp2::in<char> c) & -> bool{
        if (c == '.') {
            CPP2_UFCS(push_back)(list, "::cpp2::regex::any_matcher_logic<char>");
            return true; 
        }
        return false; 
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_group(cpp2::in<char> c) & -> bool{
        if (c != '(') {return false; }

        auto group_number {named_groups}; 
        named_groups += 1;

        // Create a new global list.
        std::vector<std::string> cur_list {}; 
        std::swap(cur_list, list);

        pos += 1;  // Skip the '('
        parse_until(')');

        // Restore the old global list.
        std::swap(cur_list, list);

        auto inner {create_list_matcher(std::move(cur_list))}; 

        CPP2_UFCS(push_back)(list, "::cpp2::regex::group_matcher_logic<char, " + cpp2::to_string(std::move(inner)) + ", " + cpp2::to_string(std::move(group_number)) + ">");

        return true; 
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_range(cpp2::in<char> c) & -> bool{

        if (c != '{') {return false; }
        if (CPP2_UFCS(empty)(list)) {error("'{' without previous element."); }

        size_t end {CPP2_UFCS(find)(regex, "}", pos)}; 
        if (end == std::string::npos) {error("Missing closing bracket."); }

        std::string inner {trim_copy(CPP2_UFCS(substr)(regex, pos + 1, end - pos - 1))}; 
        if (CPP2_UFCS(empty)(inner)) {error("Empty range specifier. Either '{n}', '{n,}', '{,m}' '{n,m}'"); }

        std::string min_count {"0"}; 
        std::string max_count {"std::numeric_limits<int>::max()"}; 

        size_t sep {CPP2_UFCS(find)(inner, ",")}; 
        if (sep == std::string::npos) {
            min_count = inner;
            max_count = std::move(inner);
        }
        else {
            std::string inner_first {trim_copy(CPP2_UFCS(substr)(inner, 0, sep))}; 
            std::string inner_last {trim_copy(CPP2_UFCS(substr)(std::move(inner), std::move(sep) + 1))}; 

            if ((CPP2_UFCS(empty)(inner_first) && CPP2_UFCS(empty)(inner_last))) {
                error("Empty range specifier. Either '{n}', '{n,}', '{,m}' '{n,m}'");
            }

            if (!(CPP2_UFCS(empty)(inner_first))) {
                min_count = std::move(inner_first);
            }
            if (!(CPP2_UFCS(empty)(inner_last))) {
                max_count = std::move(inner_last);
            }
        }

        // TODO: Check 0 <=n <= m
        auto inner_matcher {get_back()}; 
        CPP2_UFCS(push_back)(list, "::cpp2::regex::range_matcher_logic<char, " + cpp2::to_string(std::move(inner_matcher)) + ", " + cpp2::to_string(std::move(min_count)) + ", " + cpp2::to_string(std::move(max_count)) + ">");
        pos = std::move(end);

        return true; 
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_star(cpp2::in<char> c) & -> bool{
        if (c == '*') {
            if (CPP2_UFCS(empty)(list)) {
                error("'*' without previous element.");
            }
            auto inner {get_back()}; 
            CPP2_UFCS(push_back)(list, "::cpp2::regex::star_matcher_logic<char, " + cpp2::to_string(std::move(inner)) + ">");

            return true; 
        }
        return false; 
    }

    template <typename Error_out> auto regex_parser<Error_out>::parse_until(cpp2::in<char> term) & -> void{
        for( ; pos != CPP2_UFCS(size)(regex); pos += 1 ) {
            char c {CPP2_ASSERT_IN_BOUNDS(regex, pos)}; 

            if (c == term) {return ; }

            if (is_any(c)) {continue; }
            if (is_range(c)) {continue; }
            if (is_star(c)) {continue; }
            if (is_group(c)) {continue; }

            // No special char push a character match
            CPP2_UFCS(push_back)(list, "::cpp2::regex::char_matcher_logic<char, '" + cpp2::to_string(c) + "'>");
        }
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::parse() & -> std::string{

        parse_until('\0');

        return create_list_matcher(list); 
    }

#line 340 "regex.h2"
template<typename Err> [[nodiscard]] auto generate_template(cpp2::in<std::string_view> regex, Err const& err) -> std::string{
    regex_parser<Err> parser {regex, err}; 
    auto r {CPP2_UFCS(parse)(parser)}; 
    static_cast<void>(std::move(parser));
    return r; 
}

}
}

#endif
