
#ifndef REGEX_H_CPP2
#define REGEX_H_CPP2


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "regex.h2"

#line 13 "regex.h2"
namespace cpp2 {

namespace regex {

#line 20 "regex.h2"
class list_end;

class match_return;

#line 37 "regex.h2"
template<typename CharT, typename State, size_t max_groups> class match_context;

#line 83 "regex.h2"
template<typename CharT, typename Matcher, typename State, size_t groups> class regular_expression;

#line 124 "regex.h2"
template<typename CharT, int state_index, typename ...List> class alternative_matcher_logic;

#line 195 "regex.h2"
template<typename CharT> class any_matcher_logic;

#line 203 "regex.h2"
template<typename CharT, CharT C> class char_matcher_logic;

#line 211 "regex.h2"
template<typename CharT, CharT C> class single_class_entry;

#line 217 "regex.h2"
template<typename CharT, CharT Start, CharT End> class range_class_entry;

#line 223 "regex.h2"
template<typename CharT, typename ...List> class and_class_entry;


#line 228 "regex.h2"
template<typename CharT, CharT ...List> class list_class_entry;


#line 233 "regex.h2"
template<typename CharT, fixed_string Name, typename Inner> class named_class_entry;


#line 257 "regex.h2"
template<typename CharT, bool negate, typename ...List> class class_matcher_logic;

#line 302 "regex.h2"
template<typename CharT> class empty_matcher_logic;

#line 310 "regex.h2"
template<typename CharT, CharT C> class escaped_char_matcher_logic;

#line 316 "regex.h2"
template<typename CharT> class line_end_matcher_logic;

#line 324 "regex.h2"
template<typename CharT> class line_start_matcher_logic;

#line 332 "regex.h2"
class list_matcher_state;


#line 336 "regex.h2"
template<typename CharT, int state_index, typename ...List> class list_matcher_logic;

#line 426 "regex.h2"
template<typename CharT, typename M, int group> class group_matcher_logic;
    

#line 457 "regex.h2"
template<typename CharT, int group> class group_ref_matcher_logic;
    

#line 466 "regex.h2"
template<typename CharT, typename M, int min_count, int max_count, int state_index> class range_matcher_logic;

#line 557 "regex.h2"
template<typename CharT, typename M, int min_count, int max_count, int state_index, CharT symbol> class special_range_matcher_logic;
    

#line 563 "regex.h2"
class regex_parser_state;
    

#line 593 "regex.h2"
template<typename Error_out> class regex_parser;

#line 977 "regex.h2"
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

class list_end {
      public: list_end() = default;
      public: list_end(list_end const&) = delete; /* No 'that' constructor, suppress copy */
      public: auto operator=(list_end const&) -> void = delete;
};
#line 21 "regex.h2"

class match_return
 {
    public: bool matched {false}; 
    public: size_t length {0}; 

    public: [[nodiscard]] static auto create(cpp2::in<bool> m, cpp2::in<size_t> l) -> match_return;

#line 35 "regex.h2"
};

template<typename CharT, typename State, size_t max_groups> class match_context
 {
    public: view<CharT> str; 
    public: std::array<std::pair<size_t,size_t>,max_groups> ranges {}; 
    public: std::array<view<CharT>,max_groups> groups {}; 

    public: State state {};

    public: explicit match_context();

#line 49 "regex.h2"
    public: explicit match_context(view<CharT> const& s);
#line 49 "regex.h2"
    public: auto operator=(view<CharT> const& s) -> match_context& ;

#line 54 "regex.h2"
    public: match_context(match_context const& that);
#line 54 "regex.h2"
    public: auto operator=(match_context const& that) -> match_context& ;
#line 54 "regex.h2"
    public: match_context(match_context&& that) noexcept;
#line 54 "regex.h2"
    public: auto operator=(match_context&& that) noexcept -> match_context& ;

    public: auto invalidate_group(cpp2::in<size_t> group) & -> void;

#line 61 "regex.h2"
    public: auto set_group(cpp2::in<size_t> group, cpp2::in<size_t> pos, cpp2::in<size_t> length) & -> void;

#line 66 "regex.h2"
    public: [[nodiscard]] auto print_ranges() const& -> bstring<CharT>;

#line 80 "regex.h2"
    public: template<int pos> [[nodiscard]] auto get_state() & -> auto;
};

template<typename CharT, typename Matcher, typename State, size_t groups> class regular_expression {

    public: using context = match_context<CharT,State,groups>;

    public: [[nodiscard]] auto match(cpp2::in<view<CharT>> str) const& -> bool;

#line 94 "regex.h2"
    public: [[nodiscard]] auto match(cpp2::in<view<CharT>> str, context& ctx) const& -> bool;

#line 101 "regex.h2"
    public: [[nodiscard]] auto search(cpp2::in<view<CharT>> str, context& ctx) const& -> bool;
    public: [[nodiscard]] auto search(cpp2::in<view<CharT>> str, cpp2::in<size_t> start, context& ctx) const& -> bool;

#line 116 "regex.h2"
    public: [[nodiscard]] auto to_string() const& -> auto;
    public: regular_expression() = default;
    public: regular_expression(regular_expression const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regular_expression const&) -> void = delete;

#line 117 "regex.h2"
};

/*regular_expression: @interface <CharT> type = {

    match: <Ctx> (pos: size_t, inout ctx: Ctx) -> bool;
}*/

template<typename CharT, int state_index, typename ...List> class alternative_matcher_logic {

    private: [[nodiscard]] static auto prepare_state(auto& ctx, cpp2::in<bool> init) -> auto;

#line 136 "regex.h2"
    public: [[nodiscard]] static auto alternate_match(cpp2::in<size_t> pos, auto& ctx) -> auto;
    public: [[nodiscard]] static auto invalidate_groups(auto& ctx) -> auto;
    public: [[nodiscard]] static auto match(cpp2::in<size_t> pos, auto& ctx) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;

    private: template<typename First, typename ...Other> [[nodiscard]] static auto alternate_all(cpp2::in<size_t> pos, auto& ctx, auto const& state) -> match_return;

#line 164 "regex.h2"
    private: template<typename First, typename ...Other> static auto invalidate_all(auto& ctx) -> void;

#line 172 "regex.h2"
    private: template<typename First, typename ...Other> [[nodiscard]] static auto match_all(cpp2::in<size_t> pos, auto& ctx, auto const& state) -> match_return;
    public: alternative_matcher_logic() = default;
    public: alternative_matcher_logic(alternative_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(alternative_matcher_logic const&) -> void = delete;


#line 193 "regex.h2"
};

template<typename CharT> class any_matcher_logic
 {
    public: [[nodiscard]] static auto alternate_match(cpp2::in<size_t> pos, auto& ctx) -> auto;
    public: static auto invalidate_groups(auto& ctx) -> void;
    public: [[nodiscard]] static auto match(cpp2::in<size_t> pos, auto& ctx) -> match_return;
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: any_matcher_logic() = default;
    public: any_matcher_logic(any_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(any_matcher_logic const&) -> void = delete;

#line 201 "regex.h2"
};

template<typename CharT, CharT C> class char_matcher_logic
 {
    public: [[nodiscard]] static auto alternate_match(cpp2::in<size_t> pos, auto& ctx) -> auto;
    public: static auto invalidate_groups(auto& ctx) -> void;
    public: [[nodiscard]] static auto match(cpp2::in<size_t> pos, auto& ctx) -> match_return;
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: char_matcher_logic() = default;
    public: char_matcher_logic(char_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(char_matcher_logic const&) -> void = delete;

#line 209 "regex.h2"
};

template<typename CharT, CharT C> class single_class_entry
 {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: single_class_entry() = default;
    public: single_class_entry(single_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(single_class_entry const&) -> void = delete;

#line 215 "regex.h2"
};

template<typename CharT, CharT Start, CharT End> class range_class_entry
 {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: range_class_entry() = default;
    public: range_class_entry(range_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_class_entry const&) -> void = delete;

#line 221 "regex.h2"
};

template<typename CharT, typename ...List> class and_class_entry {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: and_class_entry() = default;
    public: and_class_entry(and_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(and_class_entry const&) -> void = delete;

#line 226 "regex.h2"
};

template<typename CharT, CharT ...List> class list_class_entry {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: list_class_entry() = default;
    public: list_class_entry(list_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(list_class_entry const&) -> void = delete;

#line 231 "regex.h2"
};

template<typename CharT, fixed_string Name, typename Inner> class named_class_entry {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: named_class_entry() = default;
    public: named_class_entry(named_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(named_class_entry const&) -> void = delete;

#line 236 "regex.h2"
};

#line 239 "regex.h2"
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
    public: [[nodiscard]] static auto alternate_match(cpp2::in<size_t> pos, auto& ctx) -> auto;
    public: static auto invalidate_groups(auto& ctx) -> void;

    public: [[nodiscard]] static auto match(cpp2::in<size_t> pos, auto& ctx) -> match_return;

#line 277 "regex.h2"
    private: template<typename First, typename ...Other> [[nodiscard]] static auto match_any(cpp2::in<CharT> c) -> bool;

#line 289 "regex.h2"
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: class_matcher_logic() = default;
    public: class_matcher_logic(class_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(class_matcher_logic const&) -> void = delete;


#line 299 "regex.h2"
};

#line 302 "regex.h2"
template<typename CharT> class empty_matcher_logic
 {
    public: [[nodiscard]] static auto alternate_match(cpp2::in<size_t> pos, auto& ctx) -> auto;
    public: static auto invalidate_groups(auto& ctx) -> void;
    public: [[nodiscard]] static auto match(cpp2::in<size_t> pos, auto& ctx) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: empty_matcher_logic() = default;
    public: empty_matcher_logic(empty_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(empty_matcher_logic const&) -> void = delete;

#line 308 "regex.h2"
};

template<typename CharT, CharT C> class escaped_char_matcher_logic
: public char_matcher_logic<CharT,C> {

    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: escaped_char_matcher_logic() = default;
    public: escaped_char_matcher_logic(escaped_char_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(escaped_char_matcher_logic const&) -> void = delete;

#line 314 "regex.h2"
};

template<typename CharT> class line_end_matcher_logic
 {
    public: [[nodiscard]] static auto alternate_match(cpp2::in<size_t> pos, auto& ctx) -> auto;
    public: static auto invalidate_groups(auto& ctx) -> void;
    public: [[nodiscard]] static auto match(cpp2::in<size_t> pos, auto& ctx) -> auto;
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: line_end_matcher_logic() = default;
    public: line_end_matcher_logic(line_end_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(line_end_matcher_logic const&) -> void = delete;

#line 322 "regex.h2"
};

template<typename CharT> class line_start_matcher_logic
 {
    public: [[nodiscard]] static auto alternate_match(cpp2::in<size_t> pos, auto& ctx) -> auto;
    public: static auto invalidate_groups(auto& ctx) -> void;
    public: [[nodiscard]] static auto match(cpp2::in<size_t> pos, auto& ctx) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: line_start_matcher_logic() = default;
    public: line_start_matcher_logic(line_start_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(line_start_matcher_logic const&) -> void = delete;

#line 330 "regex.h2"
};

class list_matcher_state: public std::vector<int> {

};

template<typename CharT, int state_index, typename ...List> class list_matcher_logic
 {

    private: [[nodiscard]] static auto prepare_state(auto& ctx, cpp2::in<bool> init) -> auto;

#line 350 "regex.h2"
    public: [[nodiscard]] static auto alternate_match(cpp2::in<size_t> pos, auto& ctx) -> auto;
    public: static auto invalidate_groups(auto& ctx) -> void;
    public: [[nodiscard]] static auto match(cpp2::in<size_t> pos, auto& ctx) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;

    private: template<typename First, typename ...Other> static auto invalidate_all(auto& ctx) -> void;

#line 363 "regex.h2"
    private: template<typename First, typename ...Other> [[nodiscard]] static auto match_all(cpp2::in<size_t> pos, auto& ctx, auto const& state) -> match_return;

#line 388 "regex.h2"
    private: template<typename First, typename ...Other> [[nodiscard]] static auto rematch_all(cpp2::in<size_t> pos, auto& ctx, auto const& state) -> match_return;
    public: list_matcher_logic() = default;
    public: list_matcher_logic(list_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(list_matcher_logic const&) -> void = delete;


#line 424 "regex.h2"
};

template<typename CharT, typename M, int group> class group_matcher_logic {
    public: [[nodiscard]] static auto alternate_match(cpp2::in<size_t> pos, auto& ctx) -> match_return;

#line 436 "regex.h2"
    public: static auto invalidate_groups(auto& ctx) -> void;

    public: [[nodiscard]] static auto match(cpp2::in<size_t> pos, auto& ctx) -> match_return;

#line 447 "regex.h2"
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: group_matcher_logic() = default;
    public: group_matcher_logic(group_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_matcher_logic const&) -> void = delete;


#line 455 "regex.h2"
};

template<typename CharT, int group> class group_ref_matcher_logic {
    public: [[nodiscard]] static auto alternate_match(cpp2::in<size_t> pos, auto& ctx) -> auto;
    public: static auto invalidate_groups(auto& ctx) -> void;
    public: [[nodiscard]] static auto match(cpp2::in<size_t> pos, auto& ctx) -> auto;

#line 463 "regex.h2"
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: group_ref_matcher_logic() = default;
    public: group_ref_matcher_logic(group_ref_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_ref_matcher_logic const&) -> void = delete;

#line 464 "regex.h2"
};

template<typename CharT, typename M, int min_count, int max_count, int state_index> class range_matcher_logic {

    // TODO: Add static assert on min_count and max_count.

    private: [[nodiscard]] static auto get_min_count() -> auto;

#line 478 "regex.h2"
    public: [[nodiscard]] static auto alternate_match(cpp2::in<size_t> pos, auto& ctx) -> match_return;

#line 498 "regex.h2"
    public: static auto invalidate_groups(auto& ctx) -> void;

    public: [[nodiscard]] static auto match(cpp2::in<size_t> pos, auto& ctx) -> match_return;

#line 537 "regex.h2"
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: range_matcher_logic() = default;
    public: range_matcher_logic(range_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_matcher_logic const&) -> void = delete;


#line 555 "regex.h2"
};

template<typename CharT, typename M, int min_count, int max_count, int state_index, CharT symbol> class special_range_matcher_logic: public range_matcher_logic<CharT,M,min_count,max_count,state_index> {

#line 560 "regex.h2"
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: special_range_matcher_logic() = default;
    public: special_range_matcher_logic(special_range_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(special_range_matcher_logic const&) -> void = delete;

#line 561 "regex.h2"
};

class regex_parser_state {
    public: std::vector<std::string> cur_match_list {}; 
    public: std::vector<std::vector<std::string>> alternate_match_lists {}; 

    public: auto start_new_list() & -> void;

#line 573 "regex.h2"
    public: auto swap(regex_parser_state& t) & -> void;

#line 578 "regex.h2"
    public: auto add(auto const& matcher) & -> void;

#line 582 "regex.h2"
    public: auto wrap_last(auto const& matcher) & -> void;

#line 589 "regex.h2"
    public: [[nodiscard]] auto empty() const& -> bool;
};

#line 593 "regex.h2"
template<typename Error_out> class regex_parser {

    private: std::string_view regex; 
    private: regex_parser_state cur_state {}; 
    private: size_t pos {0}; 

    private: int named_groups {1}; // Global capture group.

    private: std::vector<std::string> matcher_states {};

    private: Error_out error_out; 

    private: std::vector<std::string> supported_classes {"alnum", "alpha", "ascii", "blank", "cntrl", "digits", "graph", "lower", "print", "punct", "space", "upper", "word", "xdigit"};

    public: explicit regex_parser(cpp2::in<std::string_view> r, Error_out const& e);

#line 612 "regex.h2"
    public: [[nodiscard]] auto new_state() & -> regex_parser_state;

#line 618 "regex.h2"
    public: auto restore_state(cpp2::in<regex_parser_state> old_state) & -> void;

#line 622 "regex.h2"
    private: [[nodiscard]] auto push_matcher_state(cpp2::in<std::string> t) & -> int;

#line 628 "regex.h2"
    private: [[nodiscard]] static auto join(cpp2::in<std::vector<std::string>> list) -> std::string;

#line 640 "regex.h2"
    private: [[nodiscard]] auto create_matcher_from_list(cpp2::in<std::vector<std::string>> list) & -> std::string;

#line 651 "regex.h2"
    public: [[nodiscard]] auto create_matcher_state() const& -> std::string;

#line 656 "regex.h2"
    public: [[nodiscard]] auto create_matcher_from_state() & -> std::string;

#line 679 "regex.h2"
    public: auto error(cpp2::in<std::string> message) & -> void;

#line 683 "regex.h2"
    public: [[nodiscard]] auto is_alternative(cpp2::in<char> c) & -> bool;

#line 690 "regex.h2"
    public: [[nodiscard]] auto is_anchor(cpp2::in<char> c) & -> bool;

#line 704 "regex.h2"
    public: [[nodiscard]] auto is_any(cpp2::in<char> c) & -> bool;

#line 712 "regex.h2"
    public: [[nodiscard]] auto is_class(cpp2::in<char> c) & -> bool;

#line 807 "regex.h2"
    public: [[nodiscard]] auto is_escape(cpp2::in<char> c) & -> bool;

#line 841 "regex.h2"
    public: [[nodiscard]] auto is_group(cpp2::in<char> c) & -> bool;

#line 860 "regex.h2"
    public: [[nodiscard]] auto is_handle_special(cpp2::in<char> c) & -> bool;

#line 869 "regex.h2"
    public: [[nodiscard]] auto is_range(cpp2::in<char> c) & -> bool;

#line 912 "regex.h2"
    public: [[nodiscard]] auto is_special_range(cpp2::in<char> c) & -> bool;

#line 938 "regex.h2"
    public: auto parse_until(cpp2::in<char> term) & -> void;

#line 959 "regex.h2"
    public: [[nodiscard]] auto parse() & -> std::string;
    public: regex_parser(regex_parser const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_parser const&) -> void = delete;


#line 968 "regex.h2"
};

template<typename Err> [[nodiscard]] auto generate_template(cpp2::in<std::string_view> regex, Err const& err) -> std::string;

#line 977 "regex.h2"
}
}


//=== Cpp2 function definitions =================================================

#line 1 "regex.h2"

#line 13 "regex.h2"
namespace cpp2 {

namespace regex {

#line 27 "regex.h2"
    [[nodiscard]] auto match_return::create(cpp2::in<bool> m, cpp2::in<size_t> l) -> match_return{
      if (m) {
        return { true, l }; 
      }
      else {
        return { false, 0 }; 
      }
    }

#line 45 "regex.h2"
    template <typename CharT, typename State, size_t max_groups> match_context<CharT,State,max_groups>::match_context()
        : str{ "" }{// TODO: How to delegate???

#line 47 "regex.h2"
        CPP2_UFCS(fill)(ranges, std::make_pair(bstring<CharT>::npos, bstring<CharT>::npos));
    }
    template <typename CharT, typename State, size_t max_groups> match_context<CharT,State,max_groups>::match_context(view<CharT> const& s)
        : str{ s }{

#line 51 "regex.h2"
        CPP2_UFCS(fill)(ranges, std::make_pair(bstring<CharT>::npos, bstring<CharT>::npos));
    }
#line 49 "regex.h2"
    template <typename CharT, typename State, size_t max_groups> auto match_context<CharT,State,max_groups>::operator=(view<CharT> const& s) -> match_context& {
        str = s;
        ranges = {};
        groups = {};
        state = {};

#line 51 "regex.h2"
        CPP2_UFCS(fill)(ranges, std::make_pair(bstring<CharT>::npos, bstring<CharT>::npos));
        return *this;
#line 52 "regex.h2"
    }

    template <typename CharT, typename State, size_t max_groups> match_context<CharT,State,max_groups>::match_context(match_context const& that)
                                   : str{ that.str }
                                   , ranges{ that.ranges }
                                   , groups{ that.groups }
                                   , state{ that.state }{}
#line 54 "regex.h2"
    template <typename CharT, typename State, size_t max_groups> auto match_context<CharT,State,max_groups>::operator=(match_context const& that) -> match_context& {
                                   str = that.str;
                                   ranges = that.ranges;
                                   groups = that.groups;
                                   state = that.state;
                                   return *this; }
#line 54 "regex.h2"
    template <typename CharT, typename State, size_t max_groups> match_context<CharT,State,max_groups>::match_context(match_context&& that) noexcept
                                   : str{ std::move(that).str }
                                   , ranges{ std::move(that).ranges }
                                   , groups{ std::move(that).groups }
                                   , state{ std::move(that).state }{}
#line 54 "regex.h2"
    template <typename CharT, typename State, size_t max_groups> auto match_context<CharT,State,max_groups>::operator=(match_context&& that) noexcept -> match_context& {
                                   str = std::move(that).str;
                                   ranges = std::move(that).ranges;
                                   groups = std::move(that).groups;
                                   state = std::move(that).state;
                                   return *this; }

#line 56 "regex.h2"
    template <typename CharT, typename State, size_t max_groups> auto match_context<CharT,State,max_groups>::invalidate_group(cpp2::in<size_t> group) & -> void{
        CPP2_ASSERT_IN_BOUNDS(ranges, group) = { bstring<CharT>::npos, bstring<CharT>::npos };
        CPP2_ASSERT_IN_BOUNDS(groups, group) = {  };
    }

    template <typename CharT, typename State, size_t max_groups> auto match_context<CharT,State,max_groups>::set_group(cpp2::in<size_t> group, cpp2::in<size_t> pos, cpp2::in<size_t> length) & -> void{
        CPP2_ASSERT_IN_BOUNDS(ranges, group) = { pos, pos + length };
        CPP2_ASSERT_IN_BOUNDS(groups, group) = CPP2_UFCS(substr)(str, pos, pos + length);
    }

    template <typename CharT, typename State, size_t max_groups> [[nodiscard]] auto match_context<CharT,State,max_groups>::print_ranges() const& -> bstring<CharT>{
        bstring<CharT> r {""}; 
        for ( auto const& cur : ranges ) {
            if (cur.first != bstring<CharT>::npos) {
                r += "(" + cpp2::to_string(cur.first) + "," + cpp2::to_string(cur.second) + ")";
            }
            else {
                r += "(?,?)";
            }
        }

        return r; 
    }

    template <typename CharT, typename State, size_t max_groups> template<int pos> [[nodiscard]] auto match_context<CharT,State,max_groups>::get_state() & -> auto { return &std::get<pos>(state);  }

#line 87 "regex.h2"
    template <typename CharT, typename Matcher, typename State, size_t groups> [[nodiscard]] auto regular_expression<CharT,Matcher,State,groups>::match(cpp2::in<view<CharT>> str) const& -> bool{
        context ctx {str};    // TODO: Wrong error about not initialized.
        auto r {match(str, ctx)}; 
        static_cast<void>(std::move(ctx));
        return r; 
    }

    template <typename CharT, typename Matcher, typename State, size_t groups> [[nodiscard]] auto regular_expression<CharT,Matcher,State,groups>::match(cpp2::in<view<CharT>> str, context& ctx) const& -> bool{// TODO: Could call method with out parameter.
        ctx = { str };
        auto r {Matcher::match(0, ctx)}; 

        return std::move(r).matched && CPP2_ASSERT_IN_BOUNDS(ctx.ranges, 0).first == 0 && CPP2_ASSERT_IN_BOUNDS(ctx.ranges, 0).second == CPP2_UFCS(size)(str); 
    }

    template <typename CharT, typename Matcher, typename State, size_t groups> [[nodiscard]] auto regular_expression<CharT,Matcher,State,groups>::search(cpp2::in<view<CharT>> str, context& ctx) const& -> bool { return search(str, 0, ctx);  }
    template <typename CharT, typename Matcher, typename State, size_t groups> [[nodiscard]] auto regular_expression<CharT,Matcher,State,groups>::search(cpp2::in<view<CharT>> str, cpp2::in<size_t> start, context& ctx) const& -> bool{
        ctx = { str };

        // TODO: Improve find logic. (E.g. skip more elements on failure.)
        auto cur {start}; 
        for( ; cpp2::cmp_less_eq(cur,CPP2_UFCS(size)(str)); (cur += 1) ) {
            if (Matcher::match(cur, ctx).matched) {
                return true; 
            }
        }

        return false; 
    }

    template <typename CharT, typename Matcher, typename State, size_t groups> [[nodiscard]] auto regular_expression<CharT,Matcher,State,groups>::to_string() const& -> auto { return Matcher::to_string();  }

#line 126 "regex.h2"
    template <typename CharT, int state_index, typename ...List> [[nodiscard]] auto alternative_matcher_logic<CharT,state_index,List...>::prepare_state(auto& ctx, cpp2::in<bool> init) -> auto{
        auto state {CPP2_UFCS_TEMPLATE(get_state<state_index>)(ctx)};

        if (init) {
            *cpp2::assert_not_null(state) = 0;
        }

        return state;
    }

    template <typename CharT, int state_index, typename ...List> [[nodiscard]] auto alternative_matcher_logic<CharT,state_index,List...>::alternate_match(cpp2::in<size_t> pos, auto& ctx) -> auto { return alternate_all<List...>(pos, ctx, prepare_state(ctx, false));  }
    template <typename CharT, int state_index, typename ...List> [[nodiscard]] auto alternative_matcher_logic<CharT,state_index,List...>::invalidate_groups(auto& ctx) -> auto { return invalidate_all<List...>(ctx);  }
    template <typename CharT, int state_index, typename ...List> [[nodiscard]] auto alternative_matcher_logic<CharT,state_index,List...>::match(cpp2::in<size_t> pos, auto& ctx) -> auto { return match_all<List...>(pos, ctx, prepare_state(ctx, true));  }
    template <typename CharT, int state_index, typename ...List> [[nodiscard]] auto alternative_matcher_logic<CharT,state_index,List...>::to_string() -> auto { return CPP2_UFCS(substr)(((bstring<CharT>() + ... + ("|" + List::to_string()))), 1);  }// substr: Remove first '|'.

    template <typename CharT, int state_index, typename ...List> template<typename First, typename ...Other> [[nodiscard]] auto alternative_matcher_logic<CharT,state_index,List...>::alternate_all(cpp2::in<size_t> pos, auto& ctx, auto const& state) -> match_return{
        auto constexpr entry_pos = sizeof...(List) - sizeof...(Other) - 1;

        match_return r {false, 0};
        if (*cpp2::assert_not_null(state) == entry_pos) {
            // Current state is the same element. Try an alternative match.
            r = First::alternate_match(pos, ctx);
        }
        else {if (cpp2::cmp_less((cpp2::as_<size_t>(*cpp2::assert_not_null(state))),entry_pos)) {
            // Previous alternative has not match. Try the next one.
            *cpp2::assert_not_null(state) = entry_pos;
            r = First::match(pos, ctx);
        }}

        if (!(r.matched)) {
            if constexpr (0 != sizeof...(Other)) {
                r = alternate_all<Other...>(pos, ctx, state);
            }
        }

        return r;
    }

    template <typename CharT, int state_index, typename ...List> template<typename First, typename ...Other> auto alternative_matcher_logic<CharT,state_index,List...>::invalidate_all(auto& ctx) -> void{
        First::invalidate_groups(ctx);

        if constexpr (0 != sizeof...(Other)) {
            invalidate_all<Other...>(ctx);
        }
    }

    template <typename CharT, int state_index, typename ...List> template<typename First, typename ...Other> [[nodiscard]] auto alternative_matcher_logic<CharT,state_index,List...>::match_all(cpp2::in<size_t> pos, auto& ctx, auto const& state) -> match_return{
        auto constexpr entry_pos = sizeof...(List) - sizeof...(Other) - 1;

        match_return r {First::match(pos, ctx)}; 

        if (r.matched) {
            *cpp2::assert_not_null(state) = entry_pos;
            return r; 
        }
        else {
            First::invalidate_groups(ctx); // Did not match we need to remove matched ranges.

            if constexpr (0 != sizeof...(Other)) {
                return match_all<Other...>(pos + std::move(r).length, ctx, state);
            }
            else {
                *cpp2::assert_not_null(state) = sizeof...(List);
                return { false, 0 }; 
            }
        }
    }

#line 197 "regex.h2"
    template <typename CharT> [[nodiscard]] auto any_matcher_logic<CharT>::alternate_match(cpp2::in<size_t> pos, auto& ctx) -> auto { return match_return(false, 0);  }
    template <typename CharT> auto any_matcher_logic<CharT>::invalidate_groups(auto& ctx) -> void{}
    template <typename CharT> [[nodiscard]] auto any_matcher_logic<CharT>::match(cpp2::in<size_t> pos, auto& ctx) -> match_return { return match_return::create(cpp2::cmp_less(pos,CPP2_UFCS(size)(ctx.str)), 1);  }
    template <typename CharT> [[nodiscard]] auto any_matcher_logic<CharT>::to_string() -> bstring<CharT> { return bstring<CharT>(1, '.');  }

#line 205 "regex.h2"
    template <typename CharT, CharT C> [[nodiscard]] auto char_matcher_logic<CharT,C>::alternate_match(cpp2::in<size_t> pos, auto& ctx) -> auto { return match_return(false, 0);  }
    template <typename CharT, CharT C> auto char_matcher_logic<CharT,C>::invalidate_groups(auto& ctx) -> void{}
    template <typename CharT, CharT C> [[nodiscard]] auto char_matcher_logic<CharT,C>::match(cpp2::in<size_t> pos, auto& ctx) -> match_return { return match_return::create(cpp2::cmp_less(pos,CPP2_UFCS(size)(ctx.str)) && CPP2_ASSERT_IN_BOUNDS(ctx.str, pos) == C, 1);  }
    template <typename CharT, CharT C> [[nodiscard]] auto char_matcher_logic<CharT,C>::to_string() -> bstring<CharT> { return bstring<CharT>(1, C);  }

#line 213 "regex.h2"
    template <typename CharT, CharT C> [[nodiscard]] auto single_class_entry<CharT,C>::includes(cpp2::in<CharT> c) -> auto { return c == C;  }
    template <typename CharT, CharT C> [[nodiscard]] auto single_class_entry<CharT,C>::to_string() -> auto { return bstring<CharT>(1, C);  }

#line 219 "regex.h2"
    template <typename CharT, CharT Start, CharT End> [[nodiscard]] auto range_class_entry<CharT,Start,End>::includes(cpp2::in<CharT> c) -> auto { return [_0 = Start, _1 = c, _2 = End]{ return cpp2::cmp_less_eq(_0,_1) && cpp2::cmp_less_eq(_1,_2); }();  }
    template <typename CharT, CharT Start, CharT End> [[nodiscard]] auto range_class_entry<CharT,Start,End>::to_string() -> auto { return cpp2::to_string(Start) + "-" + cpp2::to_string(End);  }

#line 224 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto and_class_entry<CharT,List...>::includes(cpp2::in<CharT> c) -> auto { return (false || ... || List::includes(c));  }
    template <typename CharT, typename ...List> [[nodiscard]] auto and_class_entry<CharT,List...>::to_string() -> auto { return ("" + ... + List::to_string());  }

#line 229 "regex.h2"
    template <typename CharT, CharT ...List> [[nodiscard]] auto list_class_entry<CharT,List...>::includes(cpp2::in<CharT> c) -> auto { return (false || ... || (List == c));  }
    template <typename CharT, CharT ...List> [[nodiscard]] auto list_class_entry<CharT,List...>::to_string() -> auto { return ("" + ... + List);  }

#line 234 "regex.h2"
    template <typename CharT, fixed_string Name, typename Inner> [[nodiscard]] auto named_class_entry<CharT,Name,Inner>::includes(cpp2::in<CharT> c) -> auto { return Inner::includes(c);  }
    template <typename CharT, fixed_string Name, typename Inner> [[nodiscard]] auto named_class_entry<CharT,Name,Inner>::to_string() -> auto { return "[:" + cpp2::to_string(CPP2_UFCS(data)(Name)) + ":]";  }

#line 259 "regex.h2"
    template <typename CharT, bool negate, typename ...List> [[nodiscard]] auto class_matcher_logic<CharT,negate,List...>::alternate_match(cpp2::in<size_t> pos, auto& ctx) -> auto { return match_return(false, 0);  }
    template <typename CharT, bool negate, typename ...List> auto class_matcher_logic<CharT,negate,List...>::invalidate_groups(auto& ctx) -> void{}

    template <typename CharT, bool negate, typename ...List> [[nodiscard]] auto class_matcher_logic<CharT,negate,List...>::match(cpp2::in<size_t> pos, auto& ctx) -> match_return{
        if (cpp2::cmp_greater_eq(pos,CPP2_UFCS(size)(ctx.str))) {
            return match_return(false, 0);
        }

        CharT c {CPP2_ASSERT_IN_BOUNDS(ctx.str, pos)};
        bool r {match_any<List...>(std::move(c))};

        if (negate) {
            r = !(r);
        }

        return match_return::create(std::move(r), 1);
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

    template <typename CharT, bool negate, typename ...List> [[nodiscard]] auto class_matcher_logic<CharT,negate,List...>::to_string() -> bstring<CharT>{
        bstring<CharT> r {"["};
        if (negate) {
            r += "^";
        }
        r += (bstring<CharT>() + ... + List::to_string());
        r += "]";

        return r;
    }

#line 304 "regex.h2"
    template <typename CharT> [[nodiscard]] auto empty_matcher_logic<CharT>::alternate_match(cpp2::in<size_t> pos, auto& ctx) -> auto { return match_return(false, 0);  }
    template <typename CharT> auto empty_matcher_logic<CharT>::invalidate_groups(auto& ctx) -> void{}
    template <typename CharT> [[nodiscard]] auto empty_matcher_logic<CharT>::match(cpp2::in<size_t> pos, auto& ctx) -> auto { return match_return(true, 0);  }
    template <typename CharT> [[nodiscard]] auto empty_matcher_logic<CharT>::to_string() -> auto { return bstring<CharT>();  }

#line 313 "regex.h2"
    template <typename CharT, CharT C> [[nodiscard]] auto escaped_char_matcher_logic<CharT,C>::to_string() -> bstring<CharT> { return "\\" + cpp2::to_string(C);  }

#line 318 "regex.h2"
    template <typename CharT> [[nodiscard]] auto line_end_matcher_logic<CharT>::alternate_match(cpp2::in<size_t> pos, auto& ctx) -> auto { return match_return(false, 0);  }
    template <typename CharT> auto line_end_matcher_logic<CharT>::invalidate_groups(auto& ctx) -> void{}
    template <typename CharT> [[nodiscard]] auto line_end_matcher_logic<CharT>::match(cpp2::in<size_t> pos, auto& ctx) -> auto { return match_return::create(pos == CPP2_UFCS(size)(ctx.str) || CPP2_ASSERT_IN_BOUNDS(ctx.str, pos) == '\n', 0);  }// TODO: Extend to other line feeds.
    template <typename CharT> [[nodiscard]] auto line_end_matcher_logic<CharT>::to_string() -> bstring<CharT> { return "\\$";  }

#line 326 "regex.h2"
    template <typename CharT> [[nodiscard]] auto line_start_matcher_logic<CharT>::alternate_match(cpp2::in<size_t> pos, auto& ctx) -> auto { return match_return(false, 0);  }
    template <typename CharT> auto line_start_matcher_logic<CharT>::invalidate_groups(auto& ctx) -> void{}
    template <typename CharT> [[nodiscard]] auto line_start_matcher_logic<CharT>::match(cpp2::in<size_t> pos, auto& ctx) -> auto { return match_return::create(pos == 0 || CPP2_ASSERT_IN_BOUNDS(ctx.str, pos - 1) == '\n', 0);  }// TODO: Extend to other line feeds.
    template <typename CharT> [[nodiscard]] auto line_start_matcher_logic<CharT>::to_string() -> auto { return bstring<CharT>(1, '^');  }

#line 339 "regex.h2"
    template <typename CharT, int state_index, typename ...List> [[nodiscard]] auto list_matcher_logic<CharT,state_index,List...>::prepare_state(auto& ctx, cpp2::in<bool> init) -> auto{
        auto state {CPP2_UFCS_TEMPLATE(get_state<state_index>)(ctx)};

        if (init) {
            CPP2_UFCS(clear)((*cpp2::assert_not_null(state)));
            CPP2_UFCS(resize)((*cpp2::assert_not_null(state)), sizeof...(List));
        }

        return state;
    }

    template <typename CharT, int state_index, typename ...List> [[nodiscard]] auto list_matcher_logic<CharT,state_index,List...>::alternate_match(cpp2::in<size_t> pos, auto& ctx) -> auto { return rematch_all<List...>(pos, ctx, prepare_state(ctx, false));  }
    template <typename CharT, int state_index, typename ...List> auto list_matcher_logic<CharT,state_index,List...>::invalidate_groups(auto& ctx) -> void { invalidate_all<List...>(ctx);  }
    template <typename CharT, int state_index, typename ...List> [[nodiscard]] auto list_matcher_logic<CharT,state_index,List...>::match(cpp2::in<size_t> pos, auto& ctx) -> auto { return match_all<List...>(pos, ctx, prepare_state(ctx, true));  }
    template <typename CharT, int state_index, typename ...List> [[nodiscard]] auto list_matcher_logic<CharT,state_index,List...>::to_string() -> auto { return (bstring<CharT>() + ... + List::to_string()); }

    template <typename CharT, int state_index, typename ...List> template<typename First, typename ...Other> auto list_matcher_logic<CharT,state_index,List...>::invalidate_all(auto& ctx) -> void{
      First::invalidate_groups(ctx);

      if constexpr (0 != sizeof...(Other)) {
          invalidate_all<Other...>(ctx);
      }
    }

    template <typename CharT, int state_index, typename ...List> template<typename First, typename ...Other> [[nodiscard]] auto list_matcher_logic<CharT,state_index,List...>::match_all(cpp2::in<size_t> pos, auto& ctx, auto const& state) -> match_return{
      auto constexpr entry_pos = sizeof...(List) - sizeof...(Other) - 1;
      match_return r {First::match(pos, ctx)}; 

      if (r.matched) {
        CPP2_ASSERT_IN_BOUNDS((*cpp2::assert_not_null(state)), entry_pos) = pos;

        if constexpr (0 != sizeof...(Other)) {
          while( r.matched ) {
            match_return o {match_all<Other...>(pos + r.length, ctx, state)};

            if (o.matched) {
                r.length += o.length;
                break;
            }
            else {
                r = First::alternate_match(pos, ctx);
            }
          }
        }
      }

      return r; 
    }

    template <typename CharT, int state_index, typename ...List> template<typename First, typename ...Other> [[nodiscard]] auto list_matcher_logic<CharT,state_index,List...>::rematch_all(cpp2::in<size_t> pos, auto& ctx, auto const& state) -> match_return{
        auto constexpr entry_pos = sizeof...(List) - sizeof...(Other) - 1;

        match_return r {false, 0};
        auto length {0};
        if constexpr (0 != sizeof...(Other)) {
            r = rematch_all<Other...>(CPP2_ASSERT_IN_BOUNDS((*cpp2::assert_not_null(state)), entry_pos + 1), ctx, state);
            length = CPP2_ASSERT_IN_BOUNDS((*cpp2::assert_not_null(state)), entry_pos + 1) - CPP2_ASSERT_IN_BOUNDS((*cpp2::assert_not_null(state)), entry_pos);
        }else {
            r = { false, 0 };// Default fails. This triggers the alternate on the last element.
        }

        if (!(r.matched)) {
            r = First::alternate_match(pos, ctx);

            if constexpr (0 != sizeof...(Other)) {
                while( r.matched ) {
                    match_return o {match_all<Other...>(pos + r.length, ctx, state)};

                    if (o.matched) {
                        r.length += o.length;
                        break;
                    }
                    else {
                        r = First::alternate_match(pos, ctx);
                    }
                }
            }
        }
        else {
            // Adjust total match length of the list.
            r.length += std::move(length);
        }

        return r;
    }

#line 427 "regex.h2"
    template <typename CharT, typename M, int group> [[nodiscard]] auto group_matcher_logic<CharT,M,group>::alternate_match(cpp2::in<size_t> pos, auto& ctx) -> match_return{
        match_return r {M::alternate_match(pos, ctx)};

        if (r.matched) {
            CPP2_UFCS(set_group)(ctx, group, pos, r.length);
        }
        return r; 
    }

    template <typename CharT, typename M, int group> auto group_matcher_logic<CharT,M,group>::invalidate_groups(auto& ctx) -> void { CPP2_UFCS(invalidate_group)(ctx, group);  }

    template <typename CharT, typename M, int group> [[nodiscard]] auto group_matcher_logic<CharT,M,group>::match(cpp2::in<size_t> pos, auto& ctx) -> match_return{
        match_return r {M::match(pos, ctx)};

        if (r.matched) {
            CPP2_UFCS(set_group)(ctx, group, pos, r.length);
        }
        return r;
    }

    template <typename CharT, typename M, int group> [[nodiscard]] auto group_matcher_logic<CharT,M,group>::to_string() -> bstring<CharT>{
        if (group == 0) {
            return M::to_string();
        }
        else {
            return "(" + cpp2::to_string(M::to_string()) + ")";
        }
    }

#line 458 "regex.h2"
    template <typename CharT, int group> [[nodiscard]] auto group_ref_matcher_logic<CharT,group>::alternate_match(cpp2::in<size_t> pos, auto& ctx) -> auto { return match_return(false, 0);  }
    template <typename CharT, int group> auto group_ref_matcher_logic<CharT,group>::invalidate_groups(auto& ctx) -> void{}
    template <typename CharT, int group> [[nodiscard]] auto group_ref_matcher_logic<CharT,group>::match(cpp2::in<size_t> pos, auto& ctx) -> auto { 
        return match_return::create(CPP2_UFCS(starts_with)(CPP2_UFCS(substr)(ctx.str, pos), CPP2_ASSERT_IN_BOUNDS(ctx.groups, group)), CPP2_UFCS(size)(CPP2_ASSERT_IN_BOUNDS(ctx.groups, group)));  }

    template <typename CharT, int group> [[nodiscard]] auto group_ref_matcher_logic<CharT,group>::to_string() -> bstring<CharT> { return "\\(" + cpp2::to_string(group) + ")";  }

#line 470 "regex.h2"
    template <typename CharT, typename M, int min_count, int max_count, int state_index> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count,state_index>::get_min_count() -> auto{
        if constexpr (min_count == -1) {
            return 0;
        }else {
            return min_count;
        }
    }

    template <typename CharT, typename M, int min_count, int max_count, int state_index> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count,state_index>::alternate_match(cpp2::in<size_t> pos, auto& ctx) -> match_return{
        auto state {CPP2_UFCS_TEMPLATE(get_state<state_index>)(ctx)};

        if (!(CPP2_UFCS(empty)((*cpp2::assert_not_null(state))))) {
            auto length {CPP2_UFCS(back)((*cpp2::assert_not_null(state)))};
            CPP2_UFCS(pop_back)((*cpp2::assert_not_null(state)));

            auto valid {cpp2::cmp_greater_eq(CPP2_UFCS(ssize)((*cpp2::assert_not_null(state))),get_min_count())};
            if (!(valid) || CPP2_UFCS(empty)((*cpp2::assert_not_null(state)))) {
                M::invalidate_groups(ctx);
            }else {
                static_cast<void>(M::match(pos + CPP2_UFCS(back)((*cpp2::assert_not_null(std::move(state)))), ctx));// Repopulate the ranges.
            }

            return match_return::create(std::move(valid), std::move(length));
        }else {
            return match_return(false, 0);
        }
    }

    template <typename CharT, typename M, int min_count, int max_count, int state_index> auto range_matcher_logic<CharT,M,min_count,max_count,state_index>::invalidate_groups(auto& ctx) -> void { M::invalidate_groups(ctx);  }

    template <typename CharT, typename M, int min_count, int max_count, int state_index> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count,state_index>::match(cpp2::in<size_t> pos, auto& ctx) -> match_return{
      match_return r {true, 0}; 
      match_return o {true, 0}; 

      auto state {CPP2_UFCS_TEMPLATE(get_state<state_index>)(ctx)};
      CPP2_UFCS(clear)((*cpp2::assert_not_null(state)));

      int count {0};

      o = M::match(pos, ctx);
      auto ctx_copy {ctx};
      for( ; (o.matched && cpp2::cmp_less(count,max_count)); o = M::match(pos + r.length, ctx_copy) ) {

        // Stop for empty matches.
        if (o.length == 0 && cpp2::cmp_greater_eq(count,get_min_count())) {
            break;
        }

        ctx = ctx_copy;

        CPP2_UFCS(push_back)((*cpp2::assert_not_null(state)), r.length);
        r.length += o.length;
        count += 1;

        ctx_copy = ctx; // For context. TODO: Separate context and state.
      }

      static_cast<void>(std::move(state));
      auto valid {cpp2::cmp_greater_eq(std::move(count),get_min_count())};

      // If we do not reach the minimal count invalidate all groups.
      if (!(valid)) {
        M::invalidate_groups(ctx);
      }
      return match_return::create(std::move(valid), std::move(r).length);
    }

    template <typename CharT, typename M, int min_count, int max_count, int state_index> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count,state_index>::to_string() -> bstring<CharT>{
      std::string r {M::to_string()}; 

      if (min_count == max_count) {
        r += "{" + cpp2::to_string(min_count) + "}";
      }
      else {if (min_count == -1) {
        r += "{," + cpp2::to_string(max_count) + "}";
      }
      else {if (max_count == std::numeric_limits<int>::max()) {
        r += "{" + cpp2::to_string(min_count) + ",}";
      }
      else {
        r += "{" + cpp2::to_string(min_count) + "," + cpp2::to_string(max_count) + "}";
      }}}

      return r; 
    }

#line 560 "regex.h2"
    template <typename CharT, typename M, int min_count, int max_count, int state_index, CharT symbol> [[nodiscard]] auto special_range_matcher_logic<CharT,M,min_count,max_count,state_index,symbol>::to_string() -> bstring<CharT> { return M::to_string() + symbol;  }

#line 567 "regex.h2"
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

#line 607 "regex.h2"
    template <typename Error_out> regex_parser<Error_out>::regex_parser(cpp2::in<std::string_view> r, Error_out const& e)
        : regex{ r }
        , error_out{ e }{

#line 610 "regex.h2"
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::new_state() & -> regex_parser_state{
        regex_parser_state old_state {}; 
        CPP2_UFCS(swap)(old_state, cur_state);
        return old_state; 
    }

    template <typename Error_out> auto regex_parser<Error_out>::restore_state(cpp2::in<regex_parser_state> old_state) & -> void{
        cur_state = old_state;
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::push_matcher_state(cpp2::in<std::string> t) & -> int{
        auto id {CPP2_UFCS(ssize)(matcher_states)};
        CPP2_UFCS(push_back)(matcher_states, t);
        return id;
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

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::create_matcher_from_list(cpp2::in<std::vector<std::string>> list) & -> std::string{
        if (CPP2_UFCS(empty)(list)) {return "::cpp2::regex::empty_matcher_logic<char>"; }

        auto state_index {push_matcher_state("::cpp2::regex::list_matcher_state")};
        std::string matcher {"::cpp2::regex::list_matcher_logic<char, " + cpp2::to_string(std::move(state_index)) + ", "};
        matcher += join(list);
        matcher += ">";

        return matcher; 
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::create_matcher_state() const& -> std::string{
        auto inner {join(matcher_states)};
        return "std::tuple<" + cpp2::to_string(std::move(inner)) + ">";
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::create_matcher_from_state() & -> std::string{
        // Early out for no alternatives
        if (0 == CPP2_UFCS(size)(cur_state.alternate_match_lists)) {return create_matcher_from_list(cur_state.cur_match_list); }

        auto state_index {push_matcher_state("int")};
        std::string matcher {"::cpp2::regex::alternative_matcher_logic<char, " + cpp2::to_string(std::move(state_index)) + ", "};

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

    template <typename Error_out> auto regex_parser<Error_out>::error(cpp2::in<std::string> message) & -> void{
        error_out("Error during parsing of regex '" + cpp2::to_string(regex) + "' at position '" + cpp2::to_string(pos) + "': " + cpp2::to_string(message));
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
                    error_out("Unsupported character class. Supported ones are: " + cpp2::to_string(join(supported_classes)));
                }

                CPP2_UFCS(push_back)(classes, "[:" + cpp2::to_string(name) + ":]");

                end += 1; // Skip ':' pointing to the ending ']'.
                pos = end;

            }
            else {if (c_cur == '-') {
                if (first) {// Literal if first entry.
                    CPP2_UFCS(push_back)(classes, cpp2::to_string(c_cur));
                }else {
                    range = true;
                }
            }
            else {
                if (range) {// Modify last element to be a range.
                    CPP2_UFCS(back)(classes) += "-" + cpp2::to_string(c_cur);
                    range = false;
                }
                else {
                    CPP2_UFCS(push_back)(classes, cpp2::to_string(c_cur));
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
                cur = "::cpp2::regex::" + cpp2::to_string(name) + "_class<char>";
            }
            else {if (1 != CPP2_UFCS(size)(cur)) {
                cur = "::cpp2::regex::range_class_entry<char, '" + cpp2::to_string(CPP2_ASSERT_IN_BOUNDS(cur, 0)) + "', '" + cpp2::to_string(CPP2_ASSERT_IN_BOUNDS(cur, 2)) + "'>";
            }
            else {
                cur = "::cpp2::regex::single_class_entry<char, '" + cpp2::to_string(cur) + "'>";
            }}
        }

        auto inner {join(std::move(classes))};
        CPP2_UFCS(add)(cur_state, "::cpp2::regex::class_matcher_logic<char, " + cpp2::to_string(std::move(negate)) + ", " + cpp2::to_string(std::move(inner)) + ">");
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

            CPP2_UFCS(add)(cur_state, "::cpp2::regex::group_ref_matcher_logic<char, " + cpp2::to_string(std::move(group_id)) + ">");
        }
        else {if (std::string::npos != CPP2_UFCS(find)(std::string("^.[]$()*{}?+|"), c_next)) {
            if (c_next == '$') {
                // TODO: Provide proper escape for cppfront capture .
                CPP2_UFCS(add)(cur_state, "::cpp2::regex::line_end_matcher_logic<char>");
            }
            else {
                CPP2_UFCS(add)(cur_state, "::cpp2::regex::escaped_char_matcher_logic<char, '" + cpp2::to_string(c_next) + "'>");
            }
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

        std::string min_count {"-1"};
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
        auto matcher_state {push_matcher_state("std::vector<int>")};
        CPP2_UFCS(wrap_last)(cur_state, [&, _1 = std::move(min_count), _2 = std::move(max_count)](auto const& inner) -> auto { return "::cpp2::regex::range_matcher_logic<char, " + cpp2::to_string(std::move(inner)) + ", " + cpp2::to_string(_1) + ", " + cpp2::to_string(_2) + ", " + cpp2::to_string(std::move(matcher_state)) + ">";  });
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

        auto matcher_state {push_matcher_state("std::vector<int>")};
        CPP2_UFCS(wrap_last)(cur_state, [&, _1 = std::move(min_range), _2 = std::move(max_range), _3 = c](auto const& inner) -> auto { return "::cpp2::regex::special_range_matcher_logic<char, " + cpp2::to_string(inner) + ", " + cpp2::to_string(_1) + ", " + cpp2::to_string(_2) + ", " + cpp2::to_string(std::move(matcher_state)) + ", '" + cpp2::to_string(_3) + "'>";  });
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
            CPP2_UFCS(add)(cur_state, "::cpp2::regex::char_matcher_logic<char, '" + cpp2::to_string(c) + "'>");
        }
    }

    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::parse() & -> std::string{

        parse_until('\0');

        auto inner {create_matcher_from_state()}; 
        auto matcher_state {create_matcher_state()};
        return "::cpp2::regex::regular_expression<char, ::cpp2::regex::group_matcher_logic<char, " + cpp2::to_string(std::move(inner)) + ", 0>, " + cpp2::to_string(std::move(matcher_state)) + ", " + cpp2::to_string(named_groups) + ">";
    }

#line 970 "regex.h2"
template<typename Err> [[nodiscard]] auto generate_template(cpp2::in<std::string_view> regex, Err const& err) -> std::string{
    regex_parser<Err> parser {regex, err}; 
    auto r {CPP2_UFCS(parse)(parser)}; 
    static_cast<void>(std::move(parser));
    return r; 
}

}
}

#endif