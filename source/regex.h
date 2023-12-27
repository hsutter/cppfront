
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

#line 115 "regex.h2"
template<typename CharT, typename Matcher, size_t groups> class regular_expression;

#line 155 "regex.h2"
template<typename CharT, typename ...List> class alternative_matcher_logic;
    

#line 176 "regex.h2"
template<typename CharT> class any_matcher_logic;

#line 182 "regex.h2"
template<typename CharT, CharT C> class char_matcher_logic;

#line 188 "regex.h2"
template<typename CharT> class empty_matcher_logic;

#line 194 "regex.h2"
template<typename CharT, typename ...List> class list_matcher_logic;

#line 219 "regex.h2"
template<typename CharT, typename M, int group> class group_matcher_logic;
    

#line 231 "regex.h2"
template<typename CharT, int group> class group_ref_matcher_logic;
    

#line 237 "regex.h2"
template<typename CharT, typename M, int min_count, int max_count> class range_matcher_logic;

#line 274 "regex.h2"
template<typename CharT, typename M, int min_count, int max_count, CharT symbol> class special_range_matcher_logic;
    

#line 280 "regex.h2"
class regex_parser_state;
    

#line 310 "regex.h2"
template<typename Error_out> class regex_parser;

#line 548 "regex.h2"
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

    public: [[nodiscard]] static auto create(cpp2::in<bool> m, cpp2::in<size_t> l) -> match_return;

#line 78 "regex.h2"
};

template<typename CharT, size_t max_groups> class match_context
 {
    public: view<CharT> str; 
    public: std::array<std::pair<size_t,size_t>,max_groups> ranges {}; 
    public: std::array<view<CharT>,max_groups> groups {}; 

    public: explicit match_context();

#line 90 "regex.h2"
    public: explicit match_context(view<CharT> const& s);
#line 90 "regex.h2"
    public: auto operator=(view<CharT> const& s) -> match_context& ;

#line 95 "regex.h2"
    public: auto set_group(cpp2::in<size_t> group, cpp2::in<size_t> pos, cpp2::in<size_t> length) & -> void;

#line 100 "regex.h2"
    public: [[nodiscard]] auto print_ranges() const& -> bstring<CharT>;
    public: match_context(match_context const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(match_context const&) -> void = delete;


#line 113 "regex.h2"
};

template<typename CharT, typename Matcher, size_t groups> class regular_expression {

    public: using context = match_context<CharT,groups>;

    public: [[nodiscard]] auto match(cpp2::in<view<CharT>> str) const& -> bool;

#line 126 "regex.h2"
    public: [[nodiscard]] auto match(cpp2::in<view<CharT>> str, context& ctx) const& -> bool;

#line 133 "regex.h2"
    public: [[nodiscard]] auto search(cpp2::in<view<CharT>> str, cpp2::in<size_t> start, context& ctx) const& -> bool;

#line 147 "regex.h2"
    public: [[nodiscard]] auto to_string() const& -> auto;
    public: regular_expression() = default;
    public: regular_expression(regular_expression const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regular_expression const&) -> void = delete;

#line 148 "regex.h2"
};

/*regular_expression: @interface <CharT> type = {

    match: <Ctx> (pos: size_t, inout ctx: Ctx) -> bool;
}*/

template<typename CharT, typename ...List> class alternative_matcher_logic {
    public: [[nodiscard]] static auto match(cpp2::in<size_t> pos, auto& ctx) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;

    private: template<typename First, typename ...Other> [[nodiscard]] static auto match_all(cpp2::in<size_t> pos, auto& ctx) -> match_return;
    public: alternative_matcher_logic() = default;
    public: alternative_matcher_logic(alternative_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(alternative_matcher_logic const&) -> void = delete;


#line 174 "regex.h2"
};

template<typename CharT> class any_matcher_logic
 {
    public: [[nodiscard]] static auto match(cpp2::in<size_t> pos, auto& ctx) -> match_return;
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: any_matcher_logic() = default;
    public: any_matcher_logic(any_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(any_matcher_logic const&) -> void = delete;

#line 180 "regex.h2"
};

template<typename CharT, CharT C> class char_matcher_logic
 {
    public: [[nodiscard]] static auto match(cpp2::in<size_t> pos, auto& ctx) -> match_return;
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: char_matcher_logic() = default;
    public: char_matcher_logic(char_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(char_matcher_logic const&) -> void = delete;

#line 186 "regex.h2"
};

template<typename CharT> class empty_matcher_logic
 {
    public: [[nodiscard]] static auto match(cpp2::in<size_t> pos, auto& ctx) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: empty_matcher_logic() = default;
    public: empty_matcher_logic(empty_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(empty_matcher_logic const&) -> void = delete;

#line 192 "regex.h2"
};

template<typename CharT, typename ...List> class list_matcher_logic
 {
    public: [[nodiscard]] static auto match(cpp2::in<size_t> pos, auto& ctx) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;

    private: template<typename First, typename ...Other> [[nodiscard]] static auto match_all(cpp2::in<size_t> pos, auto& ctx) -> match_return;
    public: list_matcher_logic() = default;
    public: list_matcher_logic(list_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(list_matcher_logic const&) -> void = delete;


#line 217 "regex.h2"
};

template<typename CharT, typename M, int group> class group_matcher_logic {
    public: [[nodiscard]] static auto match(cpp2::in<size_t> pos, auto& ctx) -> match_return;

#line 228 "regex.h2"
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: group_matcher_logic() = default;
    public: group_matcher_logic(group_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_matcher_logic const&) -> void = delete;

#line 229 "regex.h2"
};

template<typename CharT, int group> class group_ref_matcher_logic {
    public: [[nodiscard]] static auto match(cpp2::in<size_t> pos, auto& ctx) -> auto;

    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: group_ref_matcher_logic() = default;
    public: group_ref_matcher_logic(group_ref_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_ref_matcher_logic const&) -> void = delete;

#line 235 "regex.h2"
};

template<typename CharT, typename M, int min_count, int max_count> class range_matcher_logic {

    // TODO: Add static assert on min_count and max_count.

    public: [[nodiscard]] static auto match(cpp2::in<size_t> pos, auto& ctx) -> match_return;

#line 254 "regex.h2"
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: range_matcher_logic() = default;
    public: range_matcher_logic(range_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_matcher_logic const&) -> void = delete;


#line 272 "regex.h2"
};

template<typename CharT, typename M, int min_count, int max_count, CharT symbol> class special_range_matcher_logic: public range_matcher_logic<CharT,M,min_count,max_count> {

#line 277 "regex.h2"
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: special_range_matcher_logic() = default;
    public: special_range_matcher_logic(special_range_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(special_range_matcher_logic const&) -> void = delete;

#line 278 "regex.h2"
};

class regex_parser_state {
    public: std::vector<std::string> cur_match_list {}; 
    public: std::vector<std::vector<std::string>> alternate_match_lists {}; 

public: auto start_new_list() & -> void;

#line 290 "regex.h2"
    public: auto swap(regex_parser_state& t) & -> void;

#line 295 "regex.h2"
    public: auto add(auto const& matcher) & -> void;

#line 299 "regex.h2"
    public: auto wrap_last(auto const& matcher) & -> void;

#line 306 "regex.h2"
    public: [[nodiscard]] auto empty() const& -> bool;
};

#line 310 "regex.h2"
template<typename Error_out> class regex_parser {

    private: std::string_view regex; 
    private: regex_parser_state cur_state {}; 
    private: size_t pos {0}; 

    private: int named_groups {1}; // Global capture group.

    private: Error_out error_out; 

    public: explicit regex_parser(cpp2::in<std::string_view> r, Error_out const& e);

#line 325 "regex.h2"
    public: [[nodiscard]] auto new_state() & -> regex_parser_state;

#line 331 "regex.h2"
    public: auto restore_state(cpp2::in<regex_parser_state> old_state) & -> void;

#line 335 "regex.h2"
    private: [[nodiscard]] static auto create_matcher_from_list(cpp2::in<std::vector<std::string>> list) -> std::string;

#line 350 "regex.h2"
    public: [[nodiscard]] auto create_matcher_from_state() const& -> std::string;

#line 370 "regex.h2"
    public: auto error(cpp2::in<std::string> message) & -> void;

#line 374 "regex.h2"
    public: [[nodiscard]] auto is_alternative(cpp2::in<char> c) & -> bool;

#line 381 "regex.h2"
    public: [[nodiscard]] auto is_any(cpp2::in<char> c) & -> bool;

#line 389 "regex.h2"
    public: [[nodiscard]] auto is_escape(cpp2::in<char> c) & -> bool;

#line 417 "regex.h2"
    public: [[nodiscard]] auto is_group(cpp2::in<char> c) & -> bool;

#line 436 "regex.h2"
    public: [[nodiscard]] auto is_handle_special(cpp2::in<char> c) & -> bool;

#line 445 "regex.h2"
    public: [[nodiscard]] auto is_range(cpp2::in<char> c) & -> bool;

#line 487 "regex.h2"
    public: [[nodiscard]] auto is_special_range(cpp2::in<char> c) & -> bool;

#line 512 "regex.h2"
    public: auto parse_until(cpp2::in<char> term) & -> void;

#line 531 "regex.h2"
    public: [[nodiscard]] auto parse() & -> std::string;
    public: regex_parser(regex_parser const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_parser const&) -> void = delete;


#line 539 "regex.h2"
};

template<typename Err> [[nodiscard]] auto generate_template(cpp2::in<std::string_view> regex, Err const& err) -> std::string;

#line 548 "regex.h2"
}
}


//=== Cpp2 function definitions =================================================

#line 1 "regex.h2"

#line 56 "regex.h2"
namespace cpp2 {

namespace regex {

#line 70 "regex.h2"
    [[nodiscard]] auto match_return::create(cpp2::in<bool> m, cpp2::in<size_t> l) -> match_return{
      if (m) {
        return { true, l }; 
      }
      else {
        return { false, 0 }; 
      }
    }

#line 86 "regex.h2"
    template <typename CharT, size_t max_groups> match_context<CharT,max_groups>::match_context()
        : str{ "" }{// TODO: How to delegate???

#line 88 "regex.h2"
        CPP2_UFCS(fill)(ranges, std::make_pair(bstring<CharT>::npos, bstring<CharT>::npos));
    }
    template <typename CharT, size_t max_groups> match_context<CharT,max_groups>::match_context(view<CharT> const& s)
        : str{ s }{

#line 92 "regex.h2"
        CPP2_UFCS(fill)(ranges, std::make_pair(bstring<CharT>::npos, bstring<CharT>::npos));
    }
#line 90 "regex.h2"
    template <typename CharT, size_t max_groups> auto match_context<CharT,max_groups>::operator=(view<CharT> const& s) -> match_context& {
        str = s;
        ranges = {};
        groups = {};

#line 92 "regex.h2"
        CPP2_UFCS(fill)(ranges, std::make_pair(bstring<CharT>::npos, bstring<CharT>::npos));
        return *this;
#line 93 "regex.h2"
    }

    template <typename CharT, size_t max_groups> auto match_context<CharT,max_groups>::set_group(cpp2::in<size_t> group, cpp2::in<size_t> pos, cpp2::in<size_t> length) & -> void{
        CPP2_ASSERT_IN_BOUNDS(ranges, group) = { pos, pos + length };
        CPP2_ASSERT_IN_BOUNDS(groups, group) = CPP2_UFCS(substr)(str, pos, pos + length);
    }

    template <typename CharT, size_t max_groups> [[nodiscard]] auto match_context<CharT,max_groups>::print_ranges() const& -> bstring<CharT>{
        bstring<CharT> r {""}; 
        for ( auto const& cur : ranges ) {
            if (cur.first != bstring<CharT>::npos) {
                r += "(" + cpp2::to_string(cur.first) + "," + cpp2::to_string(cur.second) + ")";
            }
            else {
                r += "(-1,-1)";
            }
        }

        return r; 
    }

#line 119 "regex.h2"
    template <typename CharT, typename Matcher, size_t groups> [[nodiscard]] auto regular_expression<CharT,Matcher,groups>::match(cpp2::in<view<CharT>> str) const& -> bool{
        context ctx {str};    // TODO: Wrong error about not initialized.
        auto r {match(str, ctx)}; 
        static_cast<void>(std::move(ctx));
        return r; 
    }

    template <typename CharT, typename Matcher, size_t groups> [[nodiscard]] auto regular_expression<CharT,Matcher,groups>::match(cpp2::in<view<CharT>> str, context& ctx) const& -> bool{// TODO: Could call method with out parameter.
        ctx = { str };
        auto r {Matcher::match(0, ctx)}; 

        return std::move(r).matched && CPP2_ASSERT_IN_BOUNDS(ctx.ranges, 0).first == 0 && CPP2_ASSERT_IN_BOUNDS(ctx.ranges, 0).second == CPP2_UFCS(size)(str); 
    }

    template <typename CharT, typename Matcher, size_t groups> [[nodiscard]] auto regular_expression<CharT,Matcher,groups>::search(cpp2::in<view<CharT>> str, cpp2::in<size_t> start, context& ctx) const& -> bool{
        ctx = { str };

        // TODO: Improve find logic. (E.g. skip more elements on failure.)
        auto cur {start}; 
        for( ; cpp2::cmp_less(cur,CPP2_UFCS(size)(str)); (cur += 1) ) {
            if (Matcher::match(cur, ctx).first) {
                return true; 
            }
        }

        return false; 
    }

    template <typename CharT, typename Matcher, size_t groups> [[nodiscard]] auto regular_expression<CharT,Matcher,groups>::to_string() const& -> auto { return Matcher::to_string();  }

#line 156 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto alternative_matcher_logic<CharT,List...>::match(cpp2::in<size_t> pos, auto& ctx) -> auto { return match_all<List...>(pos, ctx);  }
    template <typename CharT, typename ...List> [[nodiscard]] auto alternative_matcher_logic<CharT,List...>::to_string() -> auto { return CPP2_UFCS(substr)(((bstring<CharT>() + ... + ("|" + List::to_string()))), 1);  }// substr: Remove first '|'.

    template <typename CharT, typename ...List> template<typename First, typename ...Other> [[nodiscard]] auto alternative_matcher_logic<CharT,List...>::match_all(cpp2::in<size_t> pos, auto& ctx) -> match_return{
        match_return r {First::match(pos, ctx)}; 

        if (r.matched) {
            return r; 
        }
        else {
            if constexpr (0 != sizeof...(Other)) {
                return match_all<Other...>(pos + std::move(r).length, ctx); 
            }
            else {
                return { false, 0 }; 
            }
        }
    }

#line 178 "regex.h2"
    template <typename CharT> [[nodiscard]] auto any_matcher_logic<CharT>::match(cpp2::in<size_t> pos, auto& ctx) -> match_return { return match_return::create(cpp2::cmp_less(pos,CPP2_UFCS(size)(ctx.str)), 1);  }
    template <typename CharT> [[nodiscard]] auto any_matcher_logic<CharT>::to_string() -> bstring<CharT> { return bstring<CharT>(1, '.');  }

#line 184 "regex.h2"
    template <typename CharT, CharT C> [[nodiscard]] auto char_matcher_logic<CharT,C>::match(cpp2::in<size_t> pos, auto& ctx) -> match_return { return match_return::create(cpp2::cmp_less(pos,CPP2_UFCS(size)(ctx.str)) && CPP2_ASSERT_IN_BOUNDS(ctx.str, pos) == C, 1);  }
    template <typename CharT, CharT C> [[nodiscard]] auto char_matcher_logic<CharT,C>::to_string() -> bstring<CharT> { return bstring<CharT>(1, C);  }

#line 190 "regex.h2"
    template <typename CharT> [[nodiscard]] auto empty_matcher_logic<CharT>::match(cpp2::in<size_t> pos, auto& ctx) -> auto { return match_return(true, 0);  }
    template <typename CharT> [[nodiscard]] auto empty_matcher_logic<CharT>::to_string() -> auto { return bstring<CharT>();  }

#line 196 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto list_matcher_logic<CharT,List...>::match(cpp2::in<size_t> pos, auto& ctx) -> auto { return match_all<List...>(pos, ctx);  }
    template <typename CharT, typename ...List> [[nodiscard]] auto list_matcher_logic<CharT,List...>::to_string() -> auto { return (bstring<CharT>() + ... + List::to_string()); }

    template <typename CharT, typename ...List> template<typename First, typename ...Other> [[nodiscard]] auto list_matcher_logic<CharT,List...>::match_all(cpp2::in<size_t> pos, auto& ctx) -> match_return{
      match_return r {First::match(pos, ctx)}; 

      if (r.matched) {
        if constexpr (0 != sizeof...(Other)) {
          match_return o {match_all<Other...>(pos + r.length, ctx)}; 

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

#line 220 "regex.h2"
    template <typename CharT, typename M, int group> [[nodiscard]] auto group_matcher_logic<CharT,M,group>::match(cpp2::in<size_t> pos, auto& ctx) -> match_return{
        match_return r {M::match(pos, ctx)}; 

        if (r.matched) {
            CPP2_UFCS(set_group)(ctx, group, pos, r.length);
        }
        return r; 
    }
    template <typename CharT, typename M, int group> [[nodiscard]] auto group_matcher_logic<CharT,M,group>::to_string() -> bstring<CharT> { return "(" + cpp2::to_string(M::to_string()) + ")";  }

#line 232 "regex.h2"
    template <typename CharT, int group> [[nodiscard]] auto group_ref_matcher_logic<CharT,group>::match(cpp2::in<size_t> pos, auto& ctx) -> auto { 
        return match_return::create(CPP2_UFCS(starts_with)(CPP2_UFCS(substr)(ctx.str, pos), CPP2_ASSERT_IN_BOUNDS(ctx.groups, group)), CPP2_UFCS(size)(CPP2_ASSERT_IN_BOUNDS(ctx.groups, group)));  }
    template <typename CharT, int group> [[nodiscard]] auto group_ref_matcher_logic<CharT,group>::to_string() -> bstring<CharT> { return "\\(" + cpp2::to_string(group) + ")";  }

#line 241 "regex.h2"
    template <typename CharT, typename M, int min_count, int max_count> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count>::match(cpp2::in<size_t> pos, auto& ctx) -> match_return{
      match_return r {true, 0}; 
      match_return o {true, 0}; 

      int count {-1};  // First while is always true

      for( ; (o.matched && cpp2::cmp_less(count,max_count)); o = M::match(pos + r.length, ctx) ) {
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

#line 277 "regex.h2"
    template <typename CharT, typename M, int min_count, int max_count, CharT symbol> [[nodiscard]] auto special_range_matcher_logic<CharT,M,min_count,max_count,symbol>::to_string() -> bstring<CharT> { return M::to_string() + symbol;  }

#line 284 "regex.h2"
auto regex_parser_state::start_new_list() & -> void{
        std::vector<std::string> new_list {}; 
        std::swap(new_list, cur_match_list);
        static_cast<void>(CPP2_UFCS(insert)(alternate_match_lists, CPP2_UFCS(begin)(alternate_match_lists), std::move(new_list)));
    }

    auto regex_parser_state::swap(regex_parser_state& t) & -> void{
        std::swap(cur_match_list, t.cur_match_list);
        std::swap(alternate_match_lists, t.alternate_match_lists);
    }

    auto regex_parser_state::add(auto const& matcher) & -> void{
        CPP2_UFCS(push_back)(cur_match_list, matcher);
    }

    auto regex_parser_state::wrap_last(auto const& matcher) & -> void{
        std::string last {CPP2_UFCS(back)(cur_match_list)}; 
        CPP2_UFCS(back)(cur_match_list) = matcher(last);
        static_cast<void>(matcher);
        static_cast<void>(std::move(last));
    }

    [[nodiscard]] auto regex_parser_state::empty() const& -> bool { return CPP2_UFCS(empty)(cur_match_list);  }

#line 320 "regex.h2"
    template <typename Error_out> regex_parser<Error_out>::regex_parser(cpp2::in<std::string_view> r, Error_out const& e)
        : regex{ r }
        , error_out{ e }{

#line 323 "regex.h2"
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::new_state() & -> regex_parser_state{
        regex_parser_state old_state {}; 
        CPP2_UFCS(swap)(old_state, cur_state);
        return old_state; 
    }

    template <typename Error_out> auto regex_parser<Error_out>::restore_state(cpp2::in<regex_parser_state> old_state) & -> void{
        cur_state = old_state;
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::create_matcher_from_list(cpp2::in<std::vector<std::string>> list) -> std::string{
        if (CPP2_UFCS(empty)(list)) {return "::cpp2::regex::empty_matcher_logic<char>"; }

        std::string matcher {"::cpp2::regex::list_matcher_logic<char, "}; 

        std::string seperator {""}; 
        for ( auto const& cur : list ) {
            matcher += seperator + cur;
            seperator = ", ";
        }
        matcher += ">";

        return matcher; 
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::create_matcher_from_state() const& -> std::string{
        // Early out for no alternatives
        if (0 == CPP2_UFCS(size)(cur_state.alternate_match_lists)) {return create_matcher_from_list(cur_state.cur_match_list); }

        std::string matcher {"::cpp2::regex::alternative_matcher_logic<char, "}; 

        std::string seperator {""}; 
        auto add {[&, _1 = (&matcher), _2 = (&seperator)](auto const& list) mutable -> void{
            *cpp2::assert_not_null(_1) += *cpp2::assert_not_null(_2) + create_matcher_from_list(list);
            *cpp2::assert_not_null(_2) = ", ";
        }}; 
        if (0 != CPP2_UFCS(size)(cur_state.cur_match_list)) {add(cur_state.cur_match_list); }
        for ( auto const& cur : cur_state.alternate_match_lists ) {
            add(cur);
        }
        matcher += ">";

        return matcher; 
    }

    template <typename Error_out> auto regex_parser<Error_out>::error(cpp2::in<std::string> message) & -> void{
        error_out("Error during parsing of regex '" + cpp2::to_string(regex) + "' at position '" + cpp2::to_string(pos) + "': " + cpp2::to_string(message));
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_alternative(cpp2::in<char> c) & -> bool{
        if (c != '|') {return false; }

        CPP2_UFCS(start_new_list)(cur_state);
        return true; 
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_any(cpp2::in<char> c) & -> bool{
        if (c == '.') {
            CPP2_UFCS(add)(cur_state, "::cpp2::regex::any_matcher_logic<char>");
            return true; 
        }
        return false; 
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_escape(cpp2::in<char> c) & -> bool{
        if (c != '\\') {return false; }

        pos += 1;

        if (cpp2::cmp_greater_eq(pos,CPP2_UFCS(size)(regex))) {error("Escape without a follwoing character."); }

        char c_next {CPP2_ASSERT_IN_BOUNDS(regex, pos)}; 

        if ([_0 = '1', _1 = c_next, _2 = '9']{ return cpp2::cmp_less_eq(_0,_1) && cpp2::cmp_less_eq(_1,_2); }()) {
            int group_id {c_next - '0'}; 

            if (cpp2::cmp_greater_eq(group_id,named_groups)) {error("Group reference is used before the group is declared."); }

            CPP2_UFCS(add)(cur_state, "::cpp2::regex::group_ref_matcher_logic<char, " + cpp2::to_string(std::move(group_id)) + ">");
        }
        else {if (std::string::npos != CPP2_UFCS(find)(std::string("^.[]$()*{}?+|"), c_next)) {
            CPP2_UFCS(add)(cur_state, "::cpp2::regex::char_matcher_logic<char, '" + cpp2::to_string(c_next) + "'>");
        }
        else {if ('\\' == std::move(c_next)) {
            CPP2_UFCS(add)(cur_state, "::cpp2::regex::char_matcher_logic<char, '\\\\'>");
        }else {
            error("Unkonwn escape.");
        }}}

        return true; 
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_group(cpp2::in<char> c) & -> bool{
        if (c != '(') {return false; }

        auto group_number {named_groups}; 
        named_groups += 1;

        auto old_state {new_state()}; 

        pos += 1;  // Skip the '('
        parse_until(')');

        auto inner {create_matcher_from_state()}; 
        restore_state(std::move(old_state));

        CPP2_UFCS(add)(cur_state, "::cpp2::regex::group_matcher_logic<char, " + cpp2::to_string(std::move(inner)) + ", " + cpp2::to_string(std::move(group_number)) + ">");

        return true; 
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_handle_special(cpp2::in<char> c) & -> bool{
        if (c == '\'') {
            CPP2_UFCS(add)(cur_state, "::cpp2::regex::char_matcher_logic<char, '\\" + cpp2::to_string(c) + "'>");
            return true; 
        }

        return false; 
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_range(cpp2::in<char> c) & -> bool{

        if (c != '{') {return false; }
        if (CPP2_UFCS(empty)(cur_state)) {error("'{' without previous element."); }

        size_t end {CPP2_UFCS(find)(regex, "}", pos)}; 
        if (end == std::string::npos) {error("Missing closing bracket."); }

        std::string inner {trim_copy(CPP2_UFCS(substr)(regex, pos + 1, end - pos - 1))}; 
        if (CPP2_UFCS(empty)(inner)) {error("Empty range specifier. Either '{n}', '{n,}', '{,m}' '{n,m}'"); }

        std::string min_count {"0"}; 
        std::string max_count {"std::numeric_limits<int>::max()"}; 

        size_t sep {CPP2_UFCS(find)(inner, ",")}; 
        if (sep == std::string::npos) {
            min_count = inner;
            max_count = inner;
        }
        else {
            std::string inner_first {trim_copy(CPP2_UFCS(substr)(inner, 0, sep))}; 
            std::string inner_last {trim_copy(CPP2_UFCS(substr)(inner, std::move(sep) + 1))}; 

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
        CPP2_UFCS(wrap_last)(cur_state, [&, _1 = std::move(min_count), _2 = std::move(max_count)](auto const& inner) -> auto { return "::cpp2::regex::range_matcher_logic<char, " + cpp2::to_string(std::move(inner)) + ", " + cpp2::to_string(_1) + ", " + cpp2::to_string(_2) + ">";  });
        pos = std::move(end);

        return true; 
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_special_range(cpp2::in<char> c) & -> bool{
        std::string min_range {"0"}; 
        std::string max_range {"std::numeric_limits<int>::max()"}; 
        if (c == '*') {
            min_range = "0";
        }
        else {if (c == '+') {
            min_range = "1";
        }
        else {if (c == '?') {
            min_range = "0";
            max_range = "1";
        }
        else {
            return false; 
        }}}

        if (CPP2_UFCS(empty)(cur_state)) {
            error("'" + cpp2::to_string(c) + "' without previous element.");
        }

        CPP2_UFCS(wrap_last)(cur_state, [&, _1 = std::move(min_range), _2 = std::move(max_range), _3 = c](auto const& inner) -> auto { return "::cpp2::regex::special_range_matcher_logic<char, " + cpp2::to_string(inner) + ", " + cpp2::to_string(_1) + ", " + cpp2::to_string(_2) + ", '" + cpp2::to_string(_3) + "'>";  });
        return true; 
    }

    template <typename Error_out> auto regex_parser<Error_out>::parse_until(cpp2::in<char> term) & -> void{
        for( ; pos != CPP2_UFCS(size)(regex); pos += 1 ) {
            char c {CPP2_ASSERT_IN_BOUNDS(regex, pos)}; 

            if (c == term) {return ; }

            if (is_any(c)) {continue; }
            if (is_range(c)) {continue; }
            if (is_special_range(c)) {continue; }
            if (is_group(c)) {continue; }
            if (is_escape(c)) {continue; }
            if (is_alternative(c)) {continue; }
            if (is_handle_special(c)) {continue; }

            // No special char push a character match
            CPP2_UFCS(add)(cur_state, "::cpp2::regex::char_matcher_logic<char, '" + cpp2::to_string(c) + "'>");
        }
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::parse() & -> std::string{

        parse_until('\0');

        auto inner {create_matcher_from_state()}; 
        return "::cpp2::regex::regular_expression<char, ::cpp2::regex::group_matcher_logic<char, " + cpp2::to_string(std::move(inner)) + ", 0>, " + cpp2::to_string(named_groups) + ">"; 
    }

#line 541 "regex.h2"
template<typename Err> [[nodiscard]] auto generate_template(cpp2::in<std::string_view> regex, Err const& err) -> std::string{
    regex_parser<Err> parser {regex, err}; 
    auto r {CPP2_UFCS(parse)(parser)}; 
    static_cast<void>(std::move(parser));
    return r; 
}

}
}

#endif
