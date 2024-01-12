
#ifndef REGEX_H_CPP2
#define REGEX_H_CPP2


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "regex.h2"

#line 13 "regex.h2"
namespace cpp2 {

namespace regex {

#line 20 "regex.h2"
template<typename Iter> class match_group;
    

#line 27 "regex.h2"
template<typename Iter> class match_return;
    

#line 32 "regex.h2"
template<typename CharT, typename Iter, size_t max_groups> class match_context;

#line 66 "regex.h2"
template<typename ...List> class matcher_list;
    

#line 80 "regex.h2"
template<typename CharT, size_t groups, typename Matcher> class regular_expression;

#line 104 "regex.h2"
template<typename CharT, typename ...List> class alternative_matcher_logic;

#line 127 "regex.h2"
template<typename CharT> class any_matcher_logic;

#line 142 "regex.h2"
template<typename CharT, CharT C> class char_matcher_logic;

#line 155 "regex.h2"
template<typename CharT, CharT C> class single_class_entry;

#line 161 "regex.h2"
template<typename CharT, CharT Start, CharT End> class range_class_entry;

#line 167 "regex.h2"
template<typename CharT, typename ...List> class and_class_entry;
    

#line 172 "regex.h2"
template<typename CharT, CharT ...List> class list_class_entry;
    

#line 177 "regex.h2"
template<typename CharT, fixed_string Name, typename Inner> class named_class_entry;
    

#line 201 "regex.h2"
template<typename CharT, bool negate, typename ...List> class class_matcher_logic;

#line 236 "regex.h2"
template<typename CharT, CharT C> class escaped_char_matcher_logic;

#line 242 "regex.h2"
template<typename CharT, int group> class group_matcher_start_logic;
    

#line 263 "regex.h2"
template<typename CharT, int group> class group_matcher_end_logic;
    

#line 282 "regex.h2"
template<typename CharT, int group> class group_ref_matcher_logic;
    

#line 298 "regex.h2"
template<typename CharT> class line_end_matcher_logic;

#line 313 "regex.h2"
template<typename CharT> class line_start_matcher_logic;

#line 328 "regex.h2"
template<typename CharT, typename List> class list_matcher_logic;

#line 337 "regex.h2"
template<typename CharT, typename M, int min_count, int max_count> class range_matcher_logic;

#line 407 "regex.h2"
template<typename CharT, typename M, int min_count, int max_count, CharT symbol> class special_range_matcher_logic;
    

#line 413 "regex.h2"
class regex_parser_state;
    

#line 443 "regex.h2"
template<typename Error_out> class regex_parser;

#line 807 "regex.h2"
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

#line 13 "regex.h2"
namespace cpp2 {

namespace regex {

template<typename CharT> using view = std::basic_string_view<CharT>;
template<typename CharT> using bstring = std::basic_string<CharT>;

template<typename Iter> class match_group {
    public: Iter start {}; 
    public: Iter end {}; 

    public: bool matched {false}; 
};

template<typename Iter> class match_return {
    public: bool matched {false}; 
    public: Iter pos {}; 
};

template<typename CharT, typename Iter, size_t max_groups> class match_context
 {
    public: std::array<match_group<Iter>,max_groups> groups {}; 

    public: auto set_group_start(auto const& pos, auto const& start) & -> void;

#line 40 "regex.h2"
    public: auto set_group_end(auto const& pos, auto const& end) & -> void;

#line 45 "regex.h2"
    public: auto set_group_invalid(auto const& pos) & -> void;

#line 49 "regex.h2"
    public: [[nodiscard]] auto get_group(auto const& pos) & -> auto;

    public: [[nodiscard]] auto print_ranges(auto const& begin) const& -> bstring<CharT>;
    public: match_context() = default;
    public: match_context(match_context const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(match_context const&) -> void = delete;


#line 64 "regex.h2"
};

template<typename ...List> class matcher_list {
    public: template<typename Iter> [[nodiscard]] static auto match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx) -> auto;

    public: template<typename Iter, typename ...OtherList> [[nodiscard]] static auto match_combine(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] matcher_list<OtherList...> const& unnamed_param_5) -> auto;

#line 72 "regex.h2"
    private: template<typename Iter, typename First, typename ...Other> [[nodiscard]] static auto match_select(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx) -> auto;

    private: template<typename Iter> [[nodiscard]] static auto match_select(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx) -> auto;

    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: matcher_list() = default;
    public: matcher_list(matcher_list const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(matcher_list const&) -> void = delete;

#line 78 "regex.h2"
};

template<typename CharT, size_t groups, typename Matcher> class regular_expression {

    public: using Iter = view<CharT>::const_iterator;
    public: using context = match_context<CharT,Iter,groups>;

    public: [[nodiscard]] auto search(cpp2::in<view<CharT>> str, context& ctx) const& -> bool;

#line 101 "regex.h2"
    public: [[nodiscard]] auto to_string() const& -> auto;
    public: regular_expression() = default;
    public: regular_expression(regular_expression const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regular_expression const&) -> void = delete;

#line 102 "regex.h2"
};

template<typename CharT, typename ...List> class alternative_matcher_logic {

    public: template<typename Iter, typename Other> [[nodiscard]] static auto match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> auto;
    private: template<typename Iter, typename Tail, typename First, typename ...Other> [[nodiscard]] static auto match_all(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Tail const& unnamed_param_5) -> match_return<Iter>;

#line 122 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;

    public: [[nodiscard]] static auto to_string() -> auto;
    public: alternative_matcher_logic() = default;
    public: alternative_matcher_logic(alternative_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(alternative_matcher_logic const&) -> void = delete;

#line 125 "regex.h2"
};

template<typename CharT> class any_matcher_logic
 {
    public: template<typename Iter, typename Other> [[nodiscard]] static auto match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> match_return<Iter>;

#line 137 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;

    public: [[nodiscard]] static auto to_string() -> auto;
    public: any_matcher_logic() = default;
    public: any_matcher_logic(any_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(any_matcher_logic const&) -> void = delete;

#line 140 "regex.h2"
};

template<typename CharT, CharT C> class char_matcher_logic
 {
    public: template<typename Iter, typename Other> [[nodiscard]] static auto match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> match_return<Iter>;

#line 151 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: char_matcher_logic() = default;
    public: char_matcher_logic(char_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(char_matcher_logic const&) -> void = delete;

#line 153 "regex.h2"
};

template<typename CharT, CharT C> class single_class_entry
 {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: single_class_entry() = default;
    public: single_class_entry(single_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(single_class_entry const&) -> void = delete;

#line 159 "regex.h2"
};

template<typename CharT, CharT Start, CharT End> class range_class_entry
 {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: range_class_entry() = default;
    public: range_class_entry(range_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_class_entry const&) -> void = delete;

#line 165 "regex.h2"
};

template<typename CharT, typename ...List> class and_class_entry {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: and_class_entry() = default;
    public: and_class_entry(and_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(and_class_entry const&) -> void = delete;

#line 170 "regex.h2"
};

template<typename CharT, CharT ...List> class list_class_entry {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: list_class_entry() = default;
    public: list_class_entry(list_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(list_class_entry const&) -> void = delete;

#line 175 "regex.h2"
};

template<typename CharT, fixed_string Name, typename Inner> class named_class_entry {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: named_class_entry() = default;
    public: named_class_entry(named_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(named_class_entry const&) -> void = delete;

#line 180 "regex.h2"
};

#line 183 "regex.h2"
// Named character classes.
template        <typename CharT> using digits_class = named_class_entry<CharT,"digits",range_class_entry<CharT,'0','9'>>;
template        <typename CharT> using lower_class = named_class_entry<CharT,"lower",range_class_entry<CharT,'a','z'>>;
template        <typename CharT> using upper_class = named_class_entry<CharT,"upper",range_class_entry<CharT,'A','Z'>>;

// Named classes.
template        <typename CharT> using alnum_class = named_class_entry<CharT,"alnum",and_class_entry<CharT,lower_class<CharT>,upper_class<CharT>,digits_class<CharT>>>;
template        <typename CharT> using alpha_class = named_class_entry<CharT,"alpha",and_class_entry<CharT,lower_class<CharT>,upper_class<CharT>>>;
template        <typename CharT> using ascii_class = named_class_entry<CharT,"ascii",range_class_entry<CharT,'\x00','\x7F'>>;
template        <typename CharT> using blank_class = named_class_entry<CharT,"blank",list_class_entry<CharT,' ','\t'>>;
template        <typename CharT> using cntrl_class = named_class_entry<CharT,"cntrl",and_class_entry<CharT,range_class_entry<CharT,'\x00','\x1F'>,single_class_entry<CharT,'\x7F'>>>;
template        <typename CharT> using graph_class = named_class_entry<CharT,"graph",range_class_entry<CharT,'\x21','\x7E'>>;
template        <typename CharT> using print_class = named_class_entry<CharT,"print",range_class_entry<CharT,'\x20','\x7E'>>;
template        <typename CharT> using punct_class = named_class_entry<CharT,"punct",list_class_entry<CharT,'[','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/',':',';','<','=','>','?','@','[','\\',']','^','_','`','{','|','}','~',']'>>;
template        <typename CharT> using space_class = named_class_entry<CharT,"space",list_class_entry<CharT,' ','\t','\r','\n','\v','\f'>>;
template        <typename CharT> using word_class = named_class_entry<CharT,"word",and_class_entry<CharT,alnum_class<CharT>,single_class_entry<CharT,'_'>>>;
template        <typename CharT> using xdigit_class = named_class_entry<CharT,"xdigit",and_class_entry<CharT,range_class_entry<CharT,'A','F'>,range_class_entry<CharT,'a','f'>,digits_class<CharT>>>;

template<typename CharT, bool negate, typename ...List> class class_matcher_logic
 {
    public: template<typename Iter, typename Other> [[nodiscard]] static auto match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> match_return<Iter>;

#line 211 "regex.h2"
    private: template<typename First, typename ...Other> [[nodiscard]] static auto match_any(cpp2::in<CharT> c) -> bool;

#line 223 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: class_matcher_logic() = default;
    public: class_matcher_logic(class_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(class_matcher_logic const&) -> void = delete;


#line 234 "regex.h2"
};

template<typename CharT, CharT C> class escaped_char_matcher_logic
: public char_matcher_logic<CharT,C> {

    public: [[nodiscard]] static auto to_string() -> auto;
    public: escaped_char_matcher_logic() = default;
    public: escaped_char_matcher_logic(escaped_char_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(escaped_char_matcher_logic const&) -> void = delete;

#line 240 "regex.h2"
};

template<typename CharT, int group> class group_matcher_start_logic {
    public: template<typename Iter, typename Other> [[nodiscard]] static auto match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> match_return<Iter>;

#line 252 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: group_matcher_start_logic() = default;
    public: group_matcher_start_logic(group_matcher_start_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_matcher_start_logic const&) -> void = delete;


#line 261 "regex.h2"
};

template<typename CharT, int group> class group_matcher_end_logic {
    public: template<typename Iter, typename Other> [[nodiscard]] static auto match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> match_return<Iter>;

#line 271 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: group_matcher_end_logic() = default;
    public: group_matcher_end_logic(group_matcher_end_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_matcher_end_logic const&) -> void = delete;


#line 280 "regex.h2"
};

template<typename CharT, int group> class group_ref_matcher_logic {
    public: template<typename Iter, typename Other> [[nodiscard]] static auto match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> match_return<Iter>;

#line 294 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: group_ref_matcher_logic() = default;
    public: group_ref_matcher_logic(group_ref_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_ref_matcher_logic const&) -> void = delete;

#line 296 "regex.h2"
};

template<typename CharT> class line_end_matcher_logic
 {
    public: template<typename Iter, typename Other> [[nodiscard]] static auto match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> match_return<Iter>;

#line 309 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: line_end_matcher_logic() = default;
    public: line_end_matcher_logic(line_end_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(line_end_matcher_logic const&) -> void = delete;

#line 311 "regex.h2"
};

template<typename CharT> class line_start_matcher_logic
 {
    public: template<typename Iter, typename Other> [[nodiscard]] static auto match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> match_return<Iter>;

#line 324 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: line_start_matcher_logic() = default;
    public: line_start_matcher_logic(line_start_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(line_start_matcher_logic const&) -> void = delete;

#line 326 "regex.h2"
};

template<typename CharT, typename List> class list_matcher_logic
 {
    public: template<typename Iter, typename Other> [[nodiscard]] static auto match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> match_return<Iter>;

#line 333 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: list_matcher_logic() = default;
    public: list_matcher_logic(list_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(list_matcher_logic const&) -> void = delete;

#line 335 "regex.h2"
};

template<typename CharT, typename M, int min_count, int max_count> class range_matcher_logic {

#line 340 "regex.h2"
    public: template<typename Iter, typename Other> [[nodiscard]] static auto match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> auto;

#line 343 "regex.h2"
    private: [[nodiscard]] static auto is_below_upper_bound(cpp2::in<int> count) -> bool;

#line 348 "regex.h2"
    private: [[nodiscard]] static auto is_below_lower_bound(cpp2::in<int> count) -> bool;

#line 353 "regex.h2"
    private: [[nodiscard]] static auto is_in_range(cpp2::in<int> count) -> bool;

#line 358 "regex.h2"
    private: template<typename Iter, typename Other> [[nodiscard]] static auto match_greedy(cpp2::in<int> count, Iter const& begin, Iter const& cur, Iter const& last_valid, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_7) -> match_return<Iter>;

#line 386 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: range_matcher_logic() = default;
    public: range_matcher_logic(range_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_matcher_logic const&) -> void = delete;


#line 405 "regex.h2"
};

template<typename CharT, typename M, int min_count, int max_count, CharT symbol> class special_range_matcher_logic: public range_matcher_logic<CharT,M,min_count,max_count> {

    public: [[nodiscard]] static auto to_string() -> auto;
    public: special_range_matcher_logic() = default;
    public: special_range_matcher_logic(special_range_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(special_range_matcher_logic const&) -> void = delete;

#line 410 "regex.h2"
};

#line 413 "regex.h2"
class regex_parser_state {
    public: std::vector<std::string> cur_match_list {}; 
    public: std::vector<std::vector<std::string>> alternate_match_lists {}; 

    public: auto start_new_list() & -> void;

#line 423 "regex.h2"
    public: auto swap(regex_parser_state& t) & -> void;

#line 428 "regex.h2"
    public: auto add(auto const& matcher) & -> void;

#line 432 "regex.h2"
    public: auto wrap_last(auto const& matcher) & -> void;

#line 439 "regex.h2"
    public: [[nodiscard]] auto empty() const& -> bool;
};

#line 443 "regex.h2"
template<typename Error_out> class regex_parser {

    private: std::string_view regex; 
    private: regex_parser_state cur_state {}; 
    private: size_t pos {0}; 

    private: int named_groups {1}; // Global capture group.

    private: Error_out error_out; 

    private: std::vector<std::string> supported_classes {"alnum", "alpha", "ascii", "blank", "cntrl", "digits", "graph", "lower", "print", "punct", "space", "upper", "word", "xdigit"}; 

    public: explicit regex_parser(cpp2::in<std::string_view> r, Error_out const& e);

#line 460 "regex.h2"
    public: [[nodiscard]] auto new_state() & -> regex_parser_state;

#line 466 "regex.h2"
    public: auto restore_state(cpp2::in<regex_parser_state> old_state) & -> void;

#line 470 "regex.h2"
    public: auto error(cpp2::in<std::string> message) & -> void;

#line 474 "regex.h2"
    public: [[nodiscard]] auto is_alternative(cpp2::in<char> c) & -> bool;

#line 481 "regex.h2"
    public: [[nodiscard]] auto is_anchor(cpp2::in<char> c) & -> bool;

#line 495 "regex.h2"
    public: [[nodiscard]] auto is_any(cpp2::in<char> c) & -> bool;

#line 503 "regex.h2"
    public: [[nodiscard]] auto is_class(cpp2::in<char> c) & -> bool;

#line 598 "regex.h2"
    public: [[nodiscard]] auto is_escape(cpp2::in<char> c) & -> bool;

#line 633 "regex.h2"
    public: [[nodiscard]] auto is_group(cpp2::in<char> c) & -> bool;

#line 656 "regex.h2"
    public: [[nodiscard]] auto is_handle_special(cpp2::in<char> c) & -> bool;

#line 665 "regex.h2"
    public: [[nodiscard]] auto is_range(cpp2::in<char> c) & -> bool;

#line 707 "regex.h2"
    public: [[nodiscard]] auto is_special_range(cpp2::in<char> c) & -> bool;

#line 732 "regex.h2"
    public: auto parse_until(cpp2::in<char> term) & -> void;

#line 753 "regex.h2"
    private: [[nodiscard]] static auto join(cpp2::in<std::vector<std::string>> list) -> std::string;

#line 765 "regex.h2"
    public: [[nodiscard]] auto create_matcher_from_list(auto const& list) & -> auto;

#line 768 "regex.h2"
    public: [[nodiscard]] auto create_matcher_from_state() & -> std::string;

#line 789 "regex.h2"
    public: [[nodiscard]] auto parse() & -> std::string;
    public: regex_parser(regex_parser const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_parser const&) -> void = delete;


#line 798 "regex.h2"
};

template<typename Err> [[nodiscard]] auto generate_template(cpp2::in<std::string_view> regex, Err const& err) -> std::string;

#line 807 "regex.h2"
}
}


//=== Cpp2 function definitions =================================================

#line 1 "regex.h2"

#line 13 "regex.h2"
namespace cpp2 {

namespace regex {

#line 36 "regex.h2"
    template <typename CharT, typename Iter, size_t max_groups> auto match_context<CharT,Iter,max_groups>::set_group_start(auto const& pos, auto const& start) & -> void{
        CPP2_ASSERT_IN_BOUNDS(groups, pos).start = start;
    }

    template <typename CharT, typename Iter, size_t max_groups> auto match_context<CharT,Iter,max_groups>::set_group_end(auto const& pos, auto const& end) & -> void{
        CPP2_ASSERT_IN_BOUNDS(groups, pos).end = end;
        CPP2_ASSERT_IN_BOUNDS(groups, pos).matched = true;
    }

    template <typename CharT, typename Iter, size_t max_groups> auto match_context<CharT,Iter,max_groups>::set_group_invalid(auto const& pos) & -> void{
        CPP2_ASSERT_IN_BOUNDS(groups, pos).matched = false;
    }

    template <typename CharT, typename Iter, size_t max_groups> [[nodiscard]] auto match_context<CharT,Iter,max_groups>::get_group(auto const& pos) & -> auto { return CPP2_ASSERT_IN_BOUNDS(groups, pos);  }

    template <typename CharT, typename Iter, size_t max_groups> [[nodiscard]] auto match_context<CharT,Iter,max_groups>::print_ranges(auto const& begin) const& -> bstring<CharT>{
        bstring<CharT> r {""}; 
        for ( auto const& cur : groups ) {
            if (cur.matched) {
                r += ("(" + cpp2::to_string(std::distance(begin, cur.start)) + "," + cpp2::to_string(std::distance(begin, cur.end)) + ")");
            }
            else {
                r += "(?,?)";
            }
        }

        return r; 
    }

#line 67 "regex.h2"
    template <typename ...List> template<typename Iter> [[nodiscard]] auto matcher_list<List...>::match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx) -> auto { return match_select<Iter,List...>(begin, cur, end, ctx);  }

    template <typename ...List> template<typename Iter, typename ...OtherList> [[nodiscard]] auto matcher_list<List...>::match_combine(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] matcher_list<OtherList...> const& unnamed_param_5) -> auto { 
        return match_select<Iter,List...,OtherList...>(begin, cur, end, ctx);  }

    template <typename ...List> template<typename Iter, typename First, typename ...Other> [[nodiscard]] auto matcher_list<List...>::match_select(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx) -> auto { 
        return First::match(begin, cur, end, ctx, matcher_list<Other...>());  }
    template <typename ...List> template<typename Iter> [[nodiscard]] auto matcher_list<List...>::match_select(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx) -> auto { return match_return<Iter>(true, cur);  }

    template <typename ...List> auto matcher_list<List...>::reset_ranges(auto& ctx) -> void { (List::reset_ranges(ctx), ...);  }
    template <typename ...List> [[nodiscard]] auto matcher_list<List...>::to_string() -> auto { return (bstring<char>() + ... + List::to_string());  }

#line 85 "regex.h2"
    template <typename CharT, size_t groups, typename Matcher> [[nodiscard]] auto regular_expression<CharT,groups,Matcher>::search(cpp2::in<view<CharT>> str, context& ctx) const& -> bool{
        auto cur {CPP2_UFCS(begin)(str)}; 
        auto end {str.end()}; 
        for( ; true; (++cur) ) {
            if (Matcher::match(cur, cur, end, ctx).matched) {
                return true; 
            }

            if (cur == end) {
                break;
            }
        }

        return false; 
    }

    template <typename CharT, size_t groups, typename Matcher> [[nodiscard]] auto regular_expression<CharT,groups,Matcher>::to_string() const& -> auto { return Matcher::to_string();  }

#line 106 "regex.h2"
    template <typename CharT, typename ...List> template<typename Iter, typename Other> [[nodiscard]] auto alternative_matcher_logic<CharT,List...>::match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> auto { return match_all<Iter,Other,List...>(begin, cur, end, ctx, Other());  }
    template <typename CharT, typename ...List> template<typename Iter, typename Tail, typename First, typename ...Other> [[nodiscard]] auto alternative_matcher_logic<CharT,List...>::match_all(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Tail const& unnamed_param_5) -> match_return<Iter>{
        auto r {First::match(begin, cur, end, ctx, Tail())}; 
        if (r.matched) {
            return r; 
        }else {
            First::reset_ranges(ctx);

            if constexpr (0 != sizeof...(Other)) {
                return match_all<Iter,Tail,Other...>(begin, cur, end, ctx, Tail()); 
            }else {
                return match_return<Iter>(false, end); 
            }
        }
    }

    template <typename CharT, typename ...List> auto alternative_matcher_logic<CharT,List...>::reset_ranges(auto& ctx) -> void { (List::reset_ranges(ctx), ...);  }

    template <typename CharT, typename ...List> [[nodiscard]] auto alternative_matcher_logic<CharT,List...>::to_string() -> auto { return CPP2_UFCS(substr)((bstring<CharT>() + ... + ("|" + List::to_string())), 1);  }// substr: Remove first '|'.

#line 129 "regex.h2"
    template <typename CharT> template<typename Iter, typename Other> [[nodiscard]] auto any_matcher_logic<CharT>::match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> match_return<Iter>{
        if (cur != end) {
            return Other::match(begin, cur + 1, end, ctx); 
        }else {
            return match_return<Iter>(false, end); 
        }
    }

    template <typename CharT> auto any_matcher_logic<CharT>::reset_ranges(auto& ctx) -> void{}

    template <typename CharT> [[nodiscard]] auto any_matcher_logic<CharT>::to_string() -> auto { return bstring<CharT>(1, '.');  }

#line 144 "regex.h2"
    template <typename CharT, CharT C> template<typename Iter, typename Other> [[nodiscard]] auto char_matcher_logic<CharT,C>::match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> match_return<Iter>{
        if (cur != end && *cpp2::assert_not_null(cur) == C) {
            return Other::match(begin, cur + 1, end, ctx); 
        }else {
            return match_return<Iter>(false, end); 
        }
    }
    template <typename CharT, CharT C> auto char_matcher_logic<CharT,C>::reset_ranges(auto& ctx) -> void{}
    template <typename CharT, CharT C> [[nodiscard]] auto char_matcher_logic<CharT,C>::to_string() -> auto { return bstring<CharT>(1, C);  }

#line 157 "regex.h2"
    template <typename CharT, CharT C> [[nodiscard]] auto single_class_entry<CharT,C>::includes(cpp2::in<CharT> c) -> auto { return c == C;  }
    template <typename CharT, CharT C> [[nodiscard]] auto single_class_entry<CharT,C>::to_string() -> auto { return bstring<CharT>(1, C);  }

#line 163 "regex.h2"
    template <typename CharT, CharT Start, CharT End> [[nodiscard]] auto range_class_entry<CharT,Start,End>::includes(cpp2::in<CharT> c) -> auto { return [_0 = Start, _1 = c, _2 = End]{ return cpp2::cmp_less_eq(_0,_1) && cpp2::cmp_less_eq(_1,_2); }();  }
    template <typename CharT, CharT Start, CharT End> [[nodiscard]] auto range_class_entry<CharT,Start,End>::to_string() -> auto { return cpp2::to_string(Start) + "-" + cpp2::to_string(End);  }

#line 168 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto and_class_entry<CharT,List...>::includes(cpp2::in<CharT> c) -> auto { return (false || ... || List::includes(c));  }
    template <typename CharT, typename ...List> [[nodiscard]] auto and_class_entry<CharT,List...>::to_string() -> auto { return ("" + ... + List::to_string());  }

#line 173 "regex.h2"
    template <typename CharT, CharT ...List> [[nodiscard]] auto list_class_entry<CharT,List...>::includes(cpp2::in<CharT> c) -> auto { return (false || ... || (List == c));  }
    template <typename CharT, CharT ...List> [[nodiscard]] auto list_class_entry<CharT,List...>::to_string() -> auto { return ("" + ... + List);  }

#line 178 "regex.h2"
    template <typename CharT, fixed_string Name, typename Inner> [[nodiscard]] auto named_class_entry<CharT,Name,Inner>::includes(cpp2::in<CharT> c) -> auto { return Inner::includes(c);  }
    template <typename CharT, fixed_string Name, typename Inner> [[nodiscard]] auto named_class_entry<CharT,Name,Inner>::to_string() -> auto { return "[:" + cpp2::to_string(CPP2_UFCS(data)(Name)) + ":]";  }

#line 203 "regex.h2"
    template <typename CharT, bool negate, typename ...List> template<typename Iter, typename Other> [[nodiscard]] auto class_matcher_logic<CharT,negate,List...>::match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> match_return<Iter>{
        if (cur != end && negate != match_any<List...>(*cpp2::assert_not_null(cur))) {
            return Other::match(begin, cur + 1, end, ctx); 
        }else {
            return match_return<Iter>(false, end); 
        }
    }

    template <typename CharT, bool negate, typename ...List> template<typename First, typename ...Other> [[nodiscard]] auto class_matcher_logic<CharT,negate,List...>::match_any(cpp2::in<CharT> c) -> bool{
        bool r {First::includes(c)}; 

        if (!(r)) {
            if constexpr (0 != sizeof...(Other)) {
                r = match_any<Other...>(c);
            }
        }

        return r; 
    }

    template <typename CharT, bool negate, typename ...List> auto class_matcher_logic<CharT,negate,List...>::reset_ranges(auto& ctx) -> void{}
    template <typename CharT, bool negate, typename ...List> [[nodiscard]] auto class_matcher_logic<CharT,negate,List...>::to_string() -> bstring<CharT>{
        bstring<CharT> r {"["}; 
        if (negate) {
            r += "^";
        }
        r += (bstring<CharT>() + ... + List::to_string());
        r += "]";

        return r; 
    }

#line 239 "regex.h2"
    template <typename CharT, CharT C> [[nodiscard]] auto escaped_char_matcher_logic<CharT,C>::to_string() -> auto { return "\\" + cpp2::to_string(C);  }

#line 243 "regex.h2"
    template <typename CharT, int group> template<typename Iter, typename Other> [[nodiscard]] auto group_matcher_start_logic<CharT,group>::match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> match_return<Iter>{
        auto r {Other::match(begin, cur, end, ctx)}; 
        if (r.matched) {
            CPP2_UFCS(set_group_start)(ctx, group, cur);
        }else {
            CPP2_UFCS(set_group_invalid)(ctx, group);
        }
        return r; 
    }
    template <typename CharT, int group> auto group_matcher_start_logic<CharT,group>::reset_ranges(auto& ctx) -> void{CPP2_UFCS(set_group_invalid)(ctx, group); }
    template <typename CharT, int group> [[nodiscard]] auto group_matcher_start_logic<CharT,group>::to_string() -> auto{
        if (group != 0) {
            return "("; 
        }
        else {
            return ""; 
        }
    }

#line 264 "regex.h2"
    template <typename CharT, int group> template<typename Iter, typename Other> [[nodiscard]] auto group_matcher_end_logic<CharT,group>::match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> match_return<Iter>{
        auto r {Other::match(begin, cur, end, ctx)}; 
        if (r.matched) {
            CPP2_UFCS(set_group_end)(ctx, group, cur);
        }
        return r; 
    }
    template <typename CharT, int group> auto group_matcher_end_logic<CharT,group>::reset_ranges(auto& ctx) -> void{}
    template <typename CharT, int group> [[nodiscard]] auto group_matcher_end_logic<CharT,group>::to_string() -> auto{
        if (group != 0) {
            return ")"; 
        }
        else {
            return ""; 
        }
    }

#line 283 "regex.h2"
    template <typename CharT, int group> template<typename Iter, typename Other> [[nodiscard]] auto group_ref_matcher_logic<CharT,group>::match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> match_return<Iter>{
        auto g {CPP2_UFCS(get_group)(ctx, group)}; 

        for( ; g.start != g.end && cur != end; (++g.start, ++cur) ) {
            if (*cpp2::assert_not_null(g.start) != *cpp2::assert_not_null(cur)) {
                return match_return<Iter>(false, end); 
            }
        }

        return Other::match(begin, cur, end, ctx); 
    }
    template <typename CharT, int group> auto group_ref_matcher_logic<CharT,group>::reset_ranges(auto& ctx) -> void{}
    template <typename CharT, int group> [[nodiscard]] auto group_ref_matcher_logic<CharT,group>::to_string() -> bstring<CharT> { return { "\\(" + cpp2::to_string(group) + ")" };  }

#line 300 "regex.h2"
    template <typename CharT> template<typename Iter, typename Other> [[nodiscard]] auto line_end_matcher_logic<CharT>::match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> match_return<Iter>{
        if (cur == end || *cpp2::assert_not_null(cur) == '\n') {
            return Other::match(begin, cur, end, ctx); 
        }
        else {
            return match_return<Iter>(false, end); 
        }

    }
    template <typename CharT> auto line_end_matcher_logic<CharT>::reset_ranges(auto& ctx) -> void{}
    template <typename CharT> [[nodiscard]] auto line_end_matcher_logic<CharT>::to_string() -> bstring<CharT> { return "\\$";  }

#line 315 "regex.h2"
    template <typename CharT> template<typename Iter, typename Other> [[nodiscard]] auto line_start_matcher_logic<CharT>::match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> match_return<Iter>{
        if (cur == begin || *cpp2::assert_not_null((cur - 1)) == '\n') {
            return Other::match(begin, cur, end, ctx); 
        }
        else {
            return match_return<Iter>(false, end); 
        }

    }
    template <typename CharT> auto line_start_matcher_logic<CharT>::reset_ranges(auto& ctx) -> void{}
    template <typename CharT> [[nodiscard]] auto line_start_matcher_logic<CharT>::to_string() -> auto { return bstring<CharT>(1, '^');  }

#line 330 "regex.h2"
    template <typename CharT, typename List> template<typename Iter, typename Other> [[nodiscard]] auto list_matcher_logic<CharT,List>::match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> match_return<Iter>{
        return List::match_combine(begin, cur, end, ctx, Other()); 
    }
    template <typename CharT, typename List> auto list_matcher_logic<CharT,List>::reset_ranges(auto& ctx) -> void{List::reset_ranges(ctx); }
    template <typename CharT, typename List> [[nodiscard]] auto list_matcher_logic<CharT,List>::to_string() -> auto { return List::to_string();  }

#line 340 "regex.h2"
    template <typename CharT, typename M, int min_count, int max_count> template<typename Iter, typename Other> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count>::match(Iter const& begin, Iter const& cur, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> auto { 
        return match_greedy(0, begin, cur, cur, end, ctx, Other());  }

    template <typename CharT, typename M, int min_count, int max_count> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count>::is_below_upper_bound(cpp2::in<int> count) -> bool{
        if (-1 == max_count) {return true; }
        else {return cpp2::cmp_less(count,max_count); }
    }

    template <typename CharT, typename M, int min_count, int max_count> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count>::is_below_lower_bound(cpp2::in<int> count) -> bool{
        if (-1 == min_count) {return false; }
        else {return cpp2::cmp_less(count,min_count); }
    }

    template <typename CharT, typename M, int min_count, int max_count> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count>::is_in_range(cpp2::in<int> count) -> bool{
        if (-1 != min_count && cpp2::cmp_less(count,min_count)) {return false; }
        if (-1 != max_count && cpp2::cmp_greater(count,max_count)) {return false; }
        return true; 
    }
    template <typename CharT, typename M, int min_count, int max_count> template<typename Iter, typename Other> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count>::match_greedy(cpp2::in<int> count, Iter const& begin, Iter const& cur, Iter const& last_valid, Iter const& end, auto& ctx, [[maybe_unused]] Other const& unnamed_param_7) -> match_return<Iter>{
        auto r {M::match(begin, cur, end, ctx, matcher_list<>())}; 
        if ( is_below_upper_bound(count) && r.matched && 
            (is_below_lower_bound(count) || r.pos != cur)) 
        {
            auto inner {match_greedy(count + 1, begin, std::move(r).pos, cur, end, ctx, Other())}; 

            if (inner.matched) {
                return inner; 
            }
        }

        // No match from the recursion. Try to match our tail.
        if (is_in_range(count)) {
            auto o {Other::match(begin, cur, end, ctx)}; 

            if (o.matched) {
                // Rematch M to set the groups.
                M::reset_ranges(ctx);
                static_cast<void>(M::match(begin, last_valid, end, ctx, matcher_list<>()));
            }

            return o; 
        }
        else {
            return match_return<Iter>(false, end); 
        }
    }
    template <typename CharT, typename M, int min_count, int max_count> auto range_matcher_logic<CharT,M,min_count,max_count>::reset_ranges(auto& ctx) -> void{M::reset_ranges(ctx); }
    template <typename CharT, typename M, int min_count, int max_count> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count>::to_string() -> bstring<CharT>{
      std::string r {M::to_string()}; 

      if (min_count == max_count) {
        r += ("{" + cpp2::to_string(min_count) + "}");
      }
      else {if (min_count == -1) {
        r += ("{," + cpp2::to_string(max_count) + "}");
      }
      else {if (max_count == -1) {
        r += ("{" + cpp2::to_string(min_count) + ",}");
      }
      else {
        r += ("{" + cpp2::to_string(min_count) + "," + cpp2::to_string(max_count) + "}");
      }}}

      return r; 
    }

#line 409 "regex.h2"
    template <typename CharT, typename M, int min_count, int max_count, CharT symbol> [[nodiscard]] auto special_range_matcher_logic<CharT,M,min_count,max_count,symbol>::to_string() -> auto { return M::to_string() + symbol;  }

#line 417 "regex.h2"
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

#line 455 "regex.h2"
    template <typename Error_out> regex_parser<Error_out>::regex_parser(cpp2::in<std::string_view> r, Error_out const& e)
        : regex{ r }
        , error_out{ e }{

#line 458 "regex.h2"
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::new_state() & -> regex_parser_state{
        regex_parser_state old_state {}; 
        CPP2_UFCS(swap)(old_state, cur_state);
        return old_state; 
    }

    template <typename Error_out> auto regex_parser<Error_out>::restore_state(cpp2::in<regex_parser_state> old_state) & -> void{
        cur_state = old_state;
    }

    template <typename Error_out> auto regex_parser<Error_out>::error(cpp2::in<std::string> message) & -> void{
        error_out(("Error during parsing of regex '" + cpp2::to_string(regex) + "' at position '" + cpp2::to_string(pos) + "': " + cpp2::to_string(message)));
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_alternative(cpp2::in<char> c) & -> bool{
        if (c != '|') {return false; }

        CPP2_UFCS(start_new_list)(cur_state);
        return true; 
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_anchor(cpp2::in<char> c) & -> bool{
        auto r {false}; 
        if (c == '^') {
            CPP2_UFCS(add)(cur_state, "::cpp2::regex::line_start_matcher_logic<char>");
            r = true;
        }
        else {if (c == '$') {
            CPP2_UFCS(add)(cur_state, "::cpp2::regex::line_end_matcher_logic<char>");
            r = true;
        }}

        return r; 
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_any(cpp2::in<char> c) & -> bool{
        if (c == '.') {
            CPP2_UFCS(add)(cur_state, "::cpp2::regex::any_matcher_logic<char>");
            return true; 
        }
        return false; 
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_class(cpp2::in<char> c) & -> bool{
        if (c != '[') {return false; }

        std::vector<std::string> classes {}; 

        char c_cur {CPP2_ASSERT_IN_BOUNDS(regex, pos)}; 
        auto next_item {[&, _1 = (&pos), _3 = regex, _4 = (&c_cur)]() mutable -> bool{
            *cpp2::assert_not_null(_1) += 1;
            if (cpp2::cmp_greater_eq(*cpp2::assert_not_null(_1),CPP2_UFCS(size)(_3))) {return false; }

            *cpp2::assert_not_null(_4) = CPP2_ASSERT_IN_BOUNDS(_3, *cpp2::assert_not_null(_1));
            return true; 

        }}; 

        auto peek_item {[&, _1 = pos, _2 = regex]() mutable -> char{
            if (cpp2::cmp_greater_eq((_1 + 1),CPP2_UFCS(size)(_2))) {return '\0'; }
            else {return CPP2_ASSERT_IN_BOUNDS(regex, pos + 1); }
        }}; 

        auto negate {false}; 

        auto first {true}; 
        auto range {false}; 
        while( next_item() & (c_cur != ']' || first) ) {
            if (c_cur == '^') {
                negate = true;
                continue; // Skip rest of the loop. Also the first update.
            }
            if (c_cur == '[' && peek_item() == ':') {
                // We have a character class.
                pos += 2; // Skip ':]'

                auto end {CPP2_UFCS(find)(regex, ":]", pos)}; 
                if (end == std::string::npos) {error_out("Could not find end of character class."); }

                auto name {CPP2_UFCS(substr)(regex, pos, end - pos)}; 
                if (CPP2_UFCS(end)(supported_classes) == std::find(CPP2_UFCS(begin)(supported_classes), CPP2_UFCS(end)(supported_classes), name)) {
                    error_out(("Unsupported character class. Supported ones are: " + cpp2::to_string(join(supported_classes))));
                }

                CPP2_UFCS(push_back)(classes, ("[:" + cpp2::to_string(name) + ":]"));

                end += 1; // Skip ':' pointing to the ending ']'.
                pos = end;

            }
            else {if (c_cur == '-') {
                if (first) {// Literal if first entry.
                    CPP2_UFCS(push_back)(classes, (cpp2::to_string(c_cur)));
                }else {
                    range = true;
                }
            }
            else {
                if (range) {// Modify last element to be a range.
                    CPP2_UFCS(back)(classes) += ("-" + cpp2::to_string(c_cur));
                    range = false;
                }
                else {
                    CPP2_UFCS(push_back)(classes, (cpp2::to_string(c_cur)));
                }
            }}

            first = false;
        }

        static_cast<void>(std::move(next_item));// TODO: Use in while is not recognized.

        if (std::move(c_cur) != ']') {
            error_out("Error end of character class definition before terminating ']'.");
        }

        if (std::move(range)) {// If '-' is last entry treat it as a literal char.
            CPP2_UFCS(push_back)(classes, "-");
        }

        for ( auto& cur : classes ) {
            if (CPP2_UFCS(starts_with)(cur, "[:")) {
                auto name {CPP2_UFCS(substr)(cur, 2, CPP2_UFCS(size)(cur) - 4)}; 
                cur = { "::cpp2::regex::" + cpp2::to_string(name) + "_class<char>" };
            }
            else {if (1 != CPP2_UFCS(size)(cur)) {
                cur = { "::cpp2::regex::range_class_entry<char, '" + cpp2::to_string(CPP2_ASSERT_IN_BOUNDS(cur, 0)) + "', '" + cpp2::to_string(CPP2_ASSERT_IN_BOUNDS(cur, 2)) + "'>" };
            }
            else {
                cur = { "::cpp2::regex::single_class_entry<char, '" + cpp2::to_string(cur) + "'>" };
            }}
        }

        auto inner {join(std::move(classes))}; 
        CPP2_UFCS(add)(cur_state, ("::cpp2::regex::class_matcher_logic<char, " + cpp2::to_string(std::move(negate)) + ", " + cpp2::to_string(std::move(inner)) + ">"));
        return true; 
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_escape(cpp2::in<char> c) & -> bool{
        if (c != '\\') {return false; }

        pos += 1;

        if (cpp2::cmp_greater_eq(pos,CPP2_UFCS(size)(regex))) {error("Escape without a following character."); }

        char c_next {CPP2_ASSERT_IN_BOUNDS(regex, pos)}; 

        if ([_0 = '1', _1 = c_next, _2 = '9']{ return cpp2::cmp_less_eq(_0,_1) && cpp2::cmp_less_eq(_1,_2); }()) {
            int group_id {c_next - '0'}; 

            if (cpp2::cmp_greater_eq(group_id,named_groups)) {error("Group reference is used before the group is declared."); }

            CPP2_UFCS(add)(cur_state, ("::cpp2::regex::group_ref_matcher_logic<char, " + cpp2::to_string(std::move(group_id)) + ">"));
        }
        else {if (std::string::npos != CPP2_UFCS(find)(std::string("^.[]$()*{}?+|"), c_next)) {
            if (c_next == '$') {
                // TODO: Provide proper escape for cppfront capture .
                CPP2_UFCS(add)(cur_state, "::cpp2::regex::line_end_matcher_logic<char>");
            }
            else {
                CPP2_UFCS(add)(cur_state, ("::cpp2::regex::escaped_char_matcher_logic<char, '" + cpp2::to_string(c_next) + "'>"));
            }
        }
        else {if ('\\' == std::move(c_next)) {
            CPP2_UFCS(add)(cur_state, "::cpp2::regex::escaped_char_matcher_logic<char, '\\\\'>");
        }
        else {
            error("Unknown escape.");
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

        std::vector<std::string> v {
            ("::cpp2::regex::group_matcher_start_logic<char, " + cpp2::to_string(group_number) + ">"), 
            std::move(inner), 
            ("::cpp2::regex::group_matcher_end_logic<char, " + cpp2::to_string(std::move(group_number)) + ">")}; 
        CPP2_UFCS(add)(cur_state, create_matcher_from_list(std::move(v)));

        return true; 
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_handle_special(cpp2::in<char> c) & -> bool{
        if (c == '\'') {
            CPP2_UFCS(add)(cur_state, ("::cpp2::regex::char_matcher_logic<char, '\\" + cpp2::to_string(c) + "'>"));
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

        std::string min_count {"-1"}; 
        std::string max_count {"-1"}; 

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
        std::string max_range {"-1"}; 
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
            error(("'" + cpp2::to_string(c) + "' without previous element."));
        }

        CPP2_UFCS(wrap_last)(cur_state, [&, _1 = std::move(min_range), _2 = std::move(max_range), _3 = c](auto const& inner) -> auto { return "::cpp2::regex::special_range_matcher_logic<char, " + cpp2::to_string(inner) + ", " + cpp2::to_string(_1) + ", " + cpp2::to_string(_2) + ", '" + cpp2::to_string(_3) + "'>";  });
        return true; 
    }

    template <typename Error_out> auto regex_parser<Error_out>::parse_until(cpp2::in<char> term) & -> void{
        for( ; pos != CPP2_UFCS(size)(regex); pos += 1 ) {
            char c {CPP2_ASSERT_IN_BOUNDS(regex, pos)}; 

            if (c == term) {return ; }

            if (is_alternative(c)) {continue; }
            if (is_any(c)) {continue; }
            if (is_class(c)) {continue; }
            if (is_escape(c)) {continue; }
            if (is_anchor(c)) {continue; }
            if (is_group(c)) {continue; }
            if (is_handle_special(c)) {continue; }
            if (is_range(c)) {continue; }
            if (is_special_range(c)) {continue; }

            // No special char push a character match
            CPP2_UFCS(add)(cur_state, ("::cpp2::regex::char_matcher_logic<char, '" + cpp2::to_string(c) + "'>"));
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

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::create_matcher_from_list(auto const& list) & -> auto { 
            return "::cpp2::regex::list_matcher_logic<char, ::cpp2::regex::matcher_list<" + cpp2::to_string(join(list)) + ">>";  }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::create_matcher_from_state() & -> std::string{
        if (0 == CPP2_UFCS(size)(cur_state.alternate_match_lists)) {return create_matcher_from_list(cur_state.cur_match_list); }

        std::string matcher {"::cpp2::regex::alternative_matcher_logic<char, "}; 

        std::string seperator {""}; 
        auto add {[&, _1 = (&matcher), _2 = (&seperator)](auto const& list) mutable -> void{
            *cpp2::assert_not_null(_1) += *cpp2::assert_not_null(_2) + create_matcher_from_list(list);
            *cpp2::assert_not_null(_2) = ", ";
        }}; 

        auto cur {CPP2_UFCS(rbegin)(cur_state.alternate_match_lists)}; 
        for( ; cur != CPP2_UFCS(rend)(cur_state.alternate_match_lists); (++cur) ) {
            add(*cpp2::assert_not_null(cur));
        }
        if (0 != CPP2_UFCS(size)(cur_state.cur_match_list)) {std::move(add)(cur_state.cur_match_list); }
        matcher += ">";

        return matcher; 
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::parse() & -> std::string{

        parse_until('\0');

        auto inner {create_matcher_from_state()}; 
        inner = { "::cpp2::regex::group_matcher_start_logic<char, 0>, " + cpp2::to_string(inner) + ", ::cpp2::regex::group_matcher_end_logic<char, 0>" };
        return { "::cpp2::regex::regular_expression<char, " + cpp2::to_string(named_groups) + ", ::cpp2::regex::matcher_list<" + cpp2::to_string(std::move(inner)) + ">>" }; 
    }

#line 800 "regex.h2"
template<typename Err> [[nodiscard]] auto generate_template(cpp2::in<std::string_view> regex, Err const& err) -> std::string{
    regex_parser<Err> parser {regex, err}; 
    auto r {CPP2_UFCS(parse)(parser)}; 
    static_cast<void>(std::move(parser));
    return r; 
}

}
}

#endif
