
#ifndef REGEX_H_CPP2
#define REGEX_H_CPP2


#include "cpp2util.h"


namespace cpp2 {

namespace regex {

template<typename Iter> class match_group;
    

template<typename CharT, typename Iter, size_t max_groups> class match_context;

template<typename ...List> class template_list;


template<typename CharT, size_t groups, typename Matcher> class regular_expression;

template<typename CharT, CharT C> class char_matcher_logic;

class regex_parser_state;
    

template<typename Error_out> class regex_parser;

}
}

//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

namespace cpp2 {

namespace regex {

template<typename CharT> using view = std::basic_string_view<CharT>;
template<typename CharT> using bstring = std::basic_string<CharT>;

template<typename Iter> class match_group {
    public: Iter start {}; 
    public: Iter end {}; 

    public: bool matched {false}; 
};

template<typename CharT, typename Iter, size_t max_groups> class match_context
 {
    public: std::array<match_group<Iter>,max_groups> groups {}; 

    public: template<size_t pos> [[nodiscard]] auto get_group() & -> auto;
    public: match_context() = default;
    public: match_context(match_context const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(match_context const&) -> void = delete;

};

template<typename ...List> class template_list {
    public: template<typename Iter> [[nodiscard]] static auto match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx) -> auto;

    private: template<typename Iter, typename First, typename ...Other> [[nodiscard]] static auto select(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx) -> auto;

    private: template<typename Iter> [[nodiscard]] static auto select(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx) -> auto;
    public: template_list() = default;
    public: template_list(template_list const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(template_list const&) -> void = delete;

};

template<typename CharT, size_t groups, typename Matcher> class regular_expression {

    public: using Iter = view<CharT>::const_iterator;
    public: using context = match_context<CharT,Iter,groups>;

    public: [[nodiscard]] auto search(cpp2::in<view<CharT>> str, context& ctx) const& -> bool;

    public: [[nodiscard]] auto to_string() const& -> auto;
    public: regular_expression() = default;
    public: regular_expression(regular_expression const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regular_expression const&) -> void = delete;

};

template<typename CharT, CharT C> class char_matcher_logic
 {
    public: template<typename Iter, typename Other> [[nodiscard]] static auto match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> bool;
    public: char_matcher_logic() = default;
    public: char_matcher_logic(char_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(char_matcher_logic const&) -> void = delete;


};

class regex_parser_state {
    public: std::vector<std::string> cur_match_list {}; 
    public: std::vector<std::vector<std::string>> alternate_match_lists {}; 

    public: auto start_new_list() & -> void;

    public: auto swap(regex_parser_state& t) & -> void;

    public: auto add(auto const& matcher) & -> void;

    public: auto wrap_last(auto const& matcher) & -> void;

    public: [[nodiscard]] auto empty() const& -> bool;
};

template<typename Error_out> class regex_parser {

    private: std::string_view regex; 
    private: regex_parser_state cur_state {}; 
    private: size_t pos {0}; 

    private: int named_groups {1}; // Global capture group.

    private: Error_out error_out; 

    public: explicit regex_parser(cpp2::in<std::string_view> r, Error_out const& e);

    public: auto parse_until(cpp2::in<char> term) & -> void;

    private: [[nodiscard]] static auto join(cpp2::in<std::vector<std::string>> list) -> std::string;

    public: [[nodiscard]] auto create_matcher_from_state() & -> std::string;

    public: [[nodiscard]] auto parse() & -> std::string;
    public: regex_parser(regex_parser const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_parser const&) -> void = delete;


};

template<typename Err> [[nodiscard]] auto generate_template(cpp2::in<std::string_view> regex, Err const& err) -> std::string;

}
}

namespace cpp2 {

namespace regex {

    template <typename CharT, typename Iter, size_t max_groups> template<size_t pos> [[nodiscard]] auto match_context<CharT,Iter,max_groups>::get_group() & -> auto { return &groups[pos];  }

    template <typename ...List> template<typename Iter> [[nodiscard]] auto template_list<List...>::match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx) -> auto { return select<Iter,List...>(begin, cur, end, ctx);  }

    template <typename ...List> template<typename Iter, typename First, typename ...Other> [[nodiscard]] auto template_list<List...>::select(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx) -> auto {
        return First::match(begin, cur, end, ctx, template_list<Other...>());  }
    template <typename ...List> template<typename Iter> [[nodiscard]] auto template_list<List...>::select(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx) -> auto { return true;  }

    template <typename CharT, size_t groups, typename Matcher> [[nodiscard]] auto regular_expression<CharT,groups,Matcher>::search(cpp2::in<view<CharT>> str, context& ctx) const& -> bool{
        auto cur {CPP2_UFCS(begin)(str)}; 
        auto end {str.end()}; 
        for( ; cur!=end; (++cur) ) {
            if (Matcher::match(cur, cur, end, ctx)) {
                return true; 
            }
        }

        return false; 
    }

    template <typename CharT, size_t groups, typename Matcher> [[nodiscard]] auto regular_expression<CharT,groups,Matcher>::to_string() const& -> auto { return Matcher::to_string();  }

    template <typename CharT, CharT C> template<typename Iter, typename Other> [[nodiscard]] auto char_matcher_logic<CharT,C>::match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> bool{
        if (cur!=end && *cur==C) {
            return Other::match(begin, cur + 1, end, ctx);
        }else {
            return false; 
        }
    }

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

    template <typename Error_out> regex_parser<Error_out>::regex_parser(cpp2::in<std::string_view> r, Error_out const& e)
        : regex{ r }
        , error_out{ e }{

    }

    template <typename Error_out> auto regex_parser<Error_out>::parse_until(cpp2::in<char> term) & -> void{
        for( ; pos!=CPP2_UFCS(size)(regex); pos += 1 ) {
            char c {regex[pos]}; 

            if (c==term) {return ; }

            // if is_alternative(c) { continue; }
            // if is_any(c) { continue; }
            // if is_class(c) { continue; }
            // if is_escape(c) { continue; }
            // if is_anchor(c) { continue; }
            // if is_group(c) { continue; }
            // if is_handle_special(c) { continue; }
            // if is_range(c) { continue; }
            // if is_special_range(c) { continue; }

            // No special char push a character match
            CPP2_UFCS(add)(cur_state, "::cpp2::regex::char_matcher_logic<char, '" + cpp2::to_string(c) + "'>");
        }
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::join(cpp2::in<std::vector<std::string>> list) -> std::string{
        std::string r {""}; 

        std::string seperator {""}; 
        for ( auto const& cur : list ) {
            r += seperator + cur;
            seperator = ", ";
        }

        return r; 
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::create_matcher_from_state() & -> std::string{
        return join(cur_state.cur_match_list); 
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::parse() & -> std::string{

        parse_until('\0');

        auto inner {create_matcher_from_state()}; 
        return "::cpp2::regex::regular_expression<char, " + cpp2::to_string(named_groups) + ", ::cpp2::regex::template_list<" + cpp2::to_string(std::move(inner)) + ">>";
    }

template<typename Err> [[nodiscard]] auto generate_template(cpp2::in<std::string_view> regex, Err const& err) -> std::string{
    regex_parser<Err> parser {regex, err}; 
    auto r {CPP2_UFCS(parse)(parser)}; 
    static_cast<void>(std::move(parser));
    return r; 
}

}
}

#endif
