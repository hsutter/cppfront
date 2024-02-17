
#ifndef ___INCLUDE_CPP2REGEX_H_CPP2
#define ___INCLUDE_CPP2REGEX_H_CPP2


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "regex.h2"

#line 15 "regex.h2"
namespace cpp2 {

namespace regex {

#line 31 "regex.h2"
template<typename Iter> class match_group;
    

#line 38 "regex.h2"
template<typename Iter> class match_return;
    

#line 43 "regex.h2"
template<typename CharT, typename Iter, int max_groups, int max_alternatives> class match_context;

#line 116 "regex.h2"
template<typename CharT, typename ...List> class matcher_list;
    

#line 143 "regex.h2"
template<typename CharT, CharT C> class single_class_entry;

#line 151 "regex.h2"
template<typename CharT, CharT Start, CharT End> class range_class_entry;

#line 159 "regex.h2"
template<typename CharT, typename ...List> class combined_class_entry;
    

#line 166 "regex.h2"
template<typename CharT, CharT ...List> class list_class_entry;
    

#line 173 "regex.h2"
template<typename CharT, fixed_string Name, typename Inner> class named_class_entry;
    

#line 178 "regex.h2"
template<typename CharT, typename Inner> class negated_class_entry;
    

#line 185 "regex.h2"
template<typename CharT, fixed_string Name, typename Inner> class shorthand_class_entry;
    

#line 231 "regex.h2"
template<typename CharT, size_t alternative> class extract_position_helper;
    

#line 248 "regex.h2"
template<typename CharT, size_t alternative, typename ...List> class alternative_matcher_logic;

#line 332 "regex.h2"
template<typename CharT> class any_matcher_logic;

#line 348 "regex.h2"
template<typename CharT, CharT C> class char_matcher_logic;

#line 364 "regex.h2"
template<typename CharT, bool negate, typename ...List> class class_matcher_logic;

#line 402 "regex.h2"
template<typename CharT, CharT C> class escaped_char_matcher_logic;

#line 411 "regex.h2"
template<typename CharT, int group, fixed_string name> class group_matcher_start_logic;
    

#line 435 "regex.h2"
template<typename CharT, int group> class group_matcher_end_logic;
    

#line 459 "regex.h2"
template<typename CharT, int group, fixed_string symbol> class group_ref_matcher_logic;
    

#line 480 "regex.h2"
template<typename CharT, bool match_new_line, bool match_new_line_before_end> class line_end_matcher_logic;

#line 502 "regex.h2"
template<typename CharT, bool match_new_line> class line_start_matcher_logic;

#line 520 "regex.h2"
template<typename CharT, fixed_string Name, typename Base> class named_matcher_logic;
    

#line 524 "regex.h2"
template                   <typename CharT, fixed_string Name, bool negate, typename ...List> class named_class_matcher_logic;
    

#line 546 "regex.h2"
template<typename CharT, typename M, int min_count, int max_count> class range_matcher_logic;

#line 618 "regex.h2"
template<typename CharT, typename M, int min_count, int max_count, CharT symbol> class special_range_matcher_logic;
    

#line 627 "regex.h2"
template<typename CharT, bool negate> class word_boundary_matcher_logic;

#line 677 "regex.h2"
template<typename CharT, size_t groups, size_t alternatives, typename Matcher> class regular_expression;

#line 750 "regex.h2"
class regex_parser_state;

#line 782 "regex.h2"
template<typename Error_out> class regex_parser;

#line 1342 "regex.h2"
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

#include <map>

#line 15 "regex.h2"
namespace cpp2 {

namespace regex {

bool inline constexpr greedy_alternative = false;

template<typename CharT> using view = std::basic_string_view<CharT>;
template<typename CharT> using bstring = std::basic_string<CharT>;

//-----------------------------------------------------------------------
//
//  Helper structures for the expression matching.
//
//-----------------------------------------------------------------------
//

template<typename Iter> class match_group {
    public: Iter start {}; 
    public: Iter end {}; 

    public: bool matched {false}; 
};

template<typename Iter> class match_return {
    public: bool matched {false}; 
    public: Iter pos {}; 
};

template<typename CharT, typename Iter, int max_groups, int max_alternatives> class match_context
 {
    public: Iter begin; 
    public: Iter end; 

    private: std::array<match_group<Iter>,max_groups> groups {}; 
    private: std::array<Iter,max_alternatives> alternatives_pos {}; 

    public: explicit match_context(Iter const& begin_, Iter const& end_);

#line 56 "regex.h2"
    public: match_context(match_context const& that);
#line 56 "regex.h2"
    public: auto operator=(match_context const& that) -> match_context& ;
#line 56 "regex.h2"
    public: match_context(match_context&& that) noexcept;
#line 56 "regex.h2"
    public: auto operator=(match_context&& that) noexcept -> match_context& ;

    // Getter and setter for groups
    //
    public: [[nodiscard]] auto get_group(auto const& group) const& -> auto;

    public: [[nodiscard]] auto get_group_string(auto const& group) const& -> std::string;

#line 68 "regex.h2"
    public: [[nodiscard]] auto get_group_start(auto const& group) const& -> auto;
    public: [[nodiscard]] auto get_group_end(auto const& group) const& -> auto;

    public: auto set_group_end(auto const& group, auto const& pos) & -> void;

#line 76 "regex.h2"
    public: auto set_group_invalid(auto const& group) & -> void;

#line 80 "regex.h2"
    public: auto set_group_start(auto const& group, auto const& pos) & -> void;

#line 84 "regex.h2"
    public: [[nodiscard]] auto size() const& -> auto;

    // Getter and setter for alternatives

    public: [[nodiscard]] auto get_alternative_pos(auto const& alternative) const& -> auto;

    public: auto set_alternative_pos(auto const& alternative, auto const& pos) & -> void;

#line 94 "regex.h2"
    // Misc functions
    //
    public: [[nodiscard]] auto print_ranges() const& -> bstring<CharT>;

#line 109 "regex.h2"
};

//  Represents the remainder of the regular expression.
//
//  A matcher can ask this remainder if it would match. If yes a full match of the regular expression is found.
//  Otherwise the matcher can try a different alternative.
//
template<typename CharT, typename ...List> class matcher_list {
    public: [[nodiscard]] static auto match(auto const& cur, auto& ctx) -> auto;

    public: template<typename ...OtherList> [[nodiscard]] static auto match(auto const& cur, auto& ctx, [[maybe_unused]] matcher_list<CharT,OtherList...> const& unnamed_param_3) -> auto;

#line 122 "regex.h2"
    private: template<typename First, typename ...Other> [[nodiscard]] static auto match_select(auto const& cur, auto& ctx) -> auto;

    private: [[nodiscard]] static auto match_select(auto const& cur, auto& ctx) -> auto;

    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;

    public: template<typename Pre> [[nodiscard]] static auto prepend([[maybe_unused]] Pre const& unnamed_param_1) -> auto;
    public: matcher_list() = default;
    public: matcher_list(matcher_list const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(matcher_list const&) -> void = delete;

#line 130 "regex.h2"
};

template<typename CharT> using no_tail = matcher_list<CharT>;

//-----------------------------------------------------------------------
//
//  Character classes for regular expressions.
//
//-----------------------------------------------------------------------
//

// Class syntax: <any character> Example: a
//
template<typename CharT, CharT C> class single_class_entry
 {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: single_class_entry() = default;
    public: single_class_entry(single_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(single_class_entry const&) -> void = delete;

#line 147 "regex.h2"
};

// Class syntax: - Example: a-c
//
template<typename CharT, CharT Start, CharT End> class range_class_entry
 {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: range_class_entry() = default;
    public: range_class_entry(range_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_class_entry const&) -> void = delete;

#line 155 "regex.h2"
};

// Helper for combining two character classes
//
template<typename CharT, typename ...List> class combined_class_entry {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: combined_class_entry() = default;
    public: combined_class_entry(combined_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(combined_class_entry const&) -> void = delete;

#line 162 "regex.h2"
};

// Class syntax: <list of characters>  Example: abcd
//
template<typename CharT, CharT ...List> class list_class_entry {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: list_class_entry() = default;
    public: list_class_entry(list_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(list_class_entry const&) -> void = delete;

#line 169 "regex.h2"
};

// Class syntax: [:<class name:]  Example: [:alnum:]
//
template<typename CharT, fixed_string Name, typename Inner> class named_class_entry {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: named_class_entry() = default;
    public: named_class_entry(named_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(named_class_entry const&) -> void = delete;

#line 176 "regex.h2"
};

template<typename CharT, typename Inner> class negated_class_entry: public Inner {

    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: negated_class_entry() = default;
    public: negated_class_entry(negated_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(negated_class_entry const&) -> void = delete;

#line 181 "regex.h2"
};

// Short class syntax: \<character>  Example: \w
//
template<typename CharT, fixed_string Name, typename Inner> class shorthand_class_entry {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: shorthand_class_entry() = default;
    public: shorthand_class_entry(shorthand_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(shorthand_class_entry const&) -> void = delete;

#line 188 "regex.h2"
};

#line 191 "regex.h2"
// Named basic character classes
//
template        <typename CharT> using digits_class = named_class_entry<CharT,"digits",range_class_entry<CharT,'0','9'>>;
template        <typename CharT> using lower_class = named_class_entry<CharT,"lower",range_class_entry<CharT,'a','z'>>;
template        <typename CharT> using upper_class = named_class_entry<CharT,"upper",range_class_entry<CharT,'A','Z'>>;

// Named other classes
//
template        <typename CharT> using alnum_class = named_class_entry<CharT,"alnum",combined_class_entry<CharT,lower_class<CharT>,upper_class<CharT>,digits_class<CharT>>>;
template        <typename CharT> using alpha_class = named_class_entry<CharT,"alpha",combined_class_entry<CharT,lower_class<CharT>,upper_class<CharT>>>;
template        <typename CharT> using ascii_class = named_class_entry<CharT,"ascii",range_class_entry<CharT,'\x00','\x7F'>>;
template        <typename CharT> using blank_class = named_class_entry<CharT,"blank",list_class_entry<CharT,' ','\t'>>;
template        <typename CharT> using cntrl_class = named_class_entry<CharT,"cntrl",combined_class_entry<CharT,range_class_entry<CharT,'\x00','\x1F'>,single_class_entry<CharT,'\x7F'>>>;
template        <typename CharT> using graph_class = named_class_entry<CharT,"graph",range_class_entry<CharT,'\x21','\x7E'>>;
template        <typename CharT> using print_class = named_class_entry<CharT,"print",range_class_entry<CharT,'\x20','\x7E'>>;
template        <typename CharT> using punct_class = named_class_entry<CharT,"punct",list_class_entry<CharT,'[','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/',':',';','<','=','>','?','@','[','\\',']','^','_','`','{','|','}','~',']'>>;
template        <typename CharT> using space_class = named_class_entry<CharT,"space",list_class_entry<CharT,' ','\t','\r','\n','\v','\f'>>;
template        <typename CharT> using word_class = named_class_entry<CharT,"word",combined_class_entry<CharT,alnum_class<CharT>,single_class_entry<CharT,'_'>>>;
template        <typename CharT> using xdigit_class = named_class_entry<CharT,"xdigit",combined_class_entry<CharT,range_class_entry<CharT,'A','F'>,range_class_entry<CharT,'a','f'>,digits_class<CharT>>>;

// Shorthand class entries
//
template<typename CharT> using short_digits_class = shorthand_class_entry<CharT,"\\d",digits_class<CharT>>;
template             <typename CharT> using short_word_class = shorthand_class_entry<CharT,"\\w",word_class<CharT>>;
template             <typename CharT> using short_space_class = shorthand_class_entry<CharT,"\\s",space_class<CharT>>;

template<typename CharT> using short_not_digits_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\D",digits_class<CharT>>>;
template                 <typename CharT> using short_not_word_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\W",word_class<CharT>>>;
template                 <typename CharT> using short_not_space_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\S",space_class<CharT>>>;

//-----------------------------------------------------------------------
//
//  Matchers for regular expressions.
//
//-----------------------------------------------------------------------
//

#line 229 "regex.h2"
// Helper for greedy alternatives
//
template<typename CharT, size_t alternative> class extract_position_helper {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, [[maybe_unused]] Other const& unnamed_param_3) -> auto;

#line 240 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: extract_position_helper() = default;
    public: extract_position_helper(extract_position_helper const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(extract_position_helper const&) -> void = delete;

#line 242 "regex.h2"
};

//  Regex syntax: |  Example: ab|ba
//
//  Non greedy implementation. First alternative that matches is chosen. 
//
template<typename CharT, size_t alternative, typename ...List> class alternative_matcher_logic {

    public: template<typename Tail> [[nodiscard]] static auto match(auto const& cur, auto& ctx, Tail const& tail) -> auto;

#line 262 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;

    private: template<typename First, typename ...Next> [[nodiscard]] static auto match_first(auto const& cur, auto& ctx, auto const& tail) -> auto;

#line 280 "regex.h2"
    private: template<typename Tail, typename First, typename ...Next> [[nodiscard]] static auto match_greedy(auto const& cur, auto& max_overall_length, auto& max_current_length, auto& ctx, [[maybe_unused]] Tail const& unnamed_param_5) -> auto;
    public: alternative_matcher_logic() = default;
    public: alternative_matcher_logic(alternative_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(alternative_matcher_logic const&) -> void = delete;


#line 328 "regex.h2"
};

//  Regex syntax: .
//
template<typename CharT> class any_matcher_logic
 {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, [[maybe_unused]] Other const& unnamed_param_3) -> auto;

#line 342 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: any_matcher_logic() = default;
    public: any_matcher_logic(any_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(any_matcher_logic const&) -> void = delete;

#line 344 "regex.h2"
};

// Regex syntax: <any character>  Example: a
//
template<typename CharT, CharT C> class char_matcher_logic
 {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, [[maybe_unused]] Other const& unnamed_param_3) -> auto;

#line 357 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: char_matcher_logic() = default;
    public: char_matcher_logic(char_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(char_matcher_logic const&) -> void = delete;

#line 359 "regex.h2"
};

#line 362 "regex.h2"
// Regex syntax: [<character classes>]  Example: [abcx-y[:digits:]]
//
template<typename CharT, bool negate, typename ...List> class class_matcher_logic
 {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, [[maybe_unused]] Other const& unnamed_param_3) -> auto;

#line 374 "regex.h2"
    private: template<typename First, typename ...Other> [[nodiscard]] static auto match_any(cpp2::in<CharT> c) -> bool;

#line 386 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;

    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: class_matcher_logic() = default;
    public: class_matcher_logic(class_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(class_matcher_logic const&) -> void = delete;


#line 398 "regex.h2"
};

// Regex syntax: \<special character>  Example: \.
//
template<typename CharT, CharT C> class escaped_char_matcher_logic
: public char_matcher_logic<CharT,C> {

#line 406 "regex.h2"
    public: [[nodiscard]] static auto to_string() -> auto;
    public: escaped_char_matcher_logic() = default;
    public: escaped_char_matcher_logic(escaped_char_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(escaped_char_matcher_logic const&) -> void = delete;

#line 407 "regex.h2"
};

// Regex syntax: (<inner>) Example: (.*)
//
template<typename CharT, int group, fixed_string name> class group_matcher_start_logic {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, [[maybe_unused]] Other const& unnamed_param_3) -> auto;

#line 418 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;

    public: [[nodiscard]] static auto to_string() -> std::string;
    public: group_matcher_start_logic() = default;
    public: group_matcher_start_logic(group_matcher_start_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_matcher_start_logic const&) -> void = delete;


#line 433 "regex.h2"
};

template<typename CharT, int group> class group_matcher_end_logic {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, [[maybe_unused]] Other const& unnamed_param_3) -> auto;

#line 445 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;

    public: [[nodiscard]] static auto to_string() -> auto;
    public: group_matcher_end_logic() = default;
    public: group_matcher_end_logic(group_matcher_end_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_matcher_end_logic const&) -> void = delete;


#line 455 "regex.h2"
};

// Regex syntax: \<number>  Example: \1
//
template<typename CharT, int group, fixed_string symbol> class group_ref_matcher_logic {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, [[maybe_unused]] Other const& unnamed_param_3) -> auto;

#line 472 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: group_ref_matcher_logic() = default;
    public: group_ref_matcher_logic(group_ref_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_ref_matcher_logic const&) -> void = delete;

#line 474 "regex.h2"
};

// Regex syntax: $  Example: aa$
//
// Also matches new lines endings.
//
template<typename CharT, bool match_new_line, bool match_new_line_before_end> class line_end_matcher_logic
 {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, [[maybe_unused]] Other const& unnamed_param_3) -> auto;

#line 494 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: line_end_matcher_logic() = default;
    public: line_end_matcher_logic(line_end_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(line_end_matcher_logic const&) -> void = delete;

#line 496 "regex.h2"
};

// Regex syntax: ^  Example: ^aa
//
// Also matches new line starts.
//
template<typename CharT, bool match_new_line> class line_start_matcher_logic
 {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, [[maybe_unused]] Other const& unnamed_param_3) -> auto;

#line 513 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: line_start_matcher_logic() = default;
    public: line_start_matcher_logic(line_start_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(line_start_matcher_logic const&) -> void = delete;

#line 515 "regex.h2"
};

// Named character classes
//

template<typename CharT, fixed_string Name, typename Base> class named_matcher_logic: public Base {

    public: [[nodiscard]] static auto to_string() -> auto;
    public: named_matcher_logic() = default;
    public: named_matcher_logic(named_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(named_matcher_logic const&) -> void = delete;

#line 523 "regex.h2"
};
template                   <typename CharT, fixed_string Name, bool negate, typename ...List> class named_class_matcher_logic: public named_matcher_logic<CharT,Name,class_matcher_logic<CharT,negate,List...>> {
    public: named_class_matcher_logic() = default;
    public: named_class_matcher_logic(named_class_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(named_class_matcher_logic const&) -> void = delete;


#line 526 "regex.h2"
};

template<typename CharT> using named_class_no_new_line = named_class_matcher_logic<CharT,"\\\\N",true,single_class_entry<CharT,'\n'>>;// TODO: Remove second \, switch to raw strings.
template<typename CharT> using named_class_white_space = named_class_matcher_logic<CharT,"\\s",false,space_class<CharT>>;
template<typename CharT> using named_class_word = named_class_matcher_logic<CharT,"\\w",false,word_class<CharT>>;
template<typename CharT> using named_class_digits = named_class_matcher_logic<CharT,"\\d",false,digits_class<CharT>>;

#line 534 "regex.h2"
template<typename CharT> using named_class_not_white_space = named_class_matcher_logic<CharT,"\\S",true,space_class<CharT>>;
template<typename CharT> using named_class_not_word = named_class_matcher_logic<CharT,"\\W",true,word_class<CharT>>;
template<typename CharT> using named_class_not_digits = named_class_matcher_logic<CharT,"\\D",true,digits_class<CharT>>;

// Other named matchers
template<typename CharT> using named_string_end_or_before_new_line_at_end = named_matcher_logic<CharT,"\\Z",line_end_matcher_logic<CharT,false,true>>;
template<typename CharT> using named_string_end = named_matcher_logic<CharT,"\\z",line_end_matcher_logic<CharT,false,false>>;
template<typename CharT> using named_string_start = named_matcher_logic<CharT,"\\A",line_start_matcher_logic<CharT,false>>;

#line 545 "regex.h2"
// Regex syntax: <matcher>{min, max}  Example: a{2,4}
template<typename CharT, typename M, int min_count, int max_count> class range_matcher_logic {

    public: [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& tail) -> auto;
    public: static auto reset_ranges(auto& ctx) -> void;

    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;

#line 570 "regex.h2"
    private: [[nodiscard]] static auto is_below_upper_bound(cpp2::in<int> count) -> bool;

#line 575 "regex.h2"
    private: [[nodiscard]] static auto is_below_lower_bound(cpp2::in<int> count) -> bool;

#line 580 "regex.h2"
    private: [[nodiscard]] static auto is_in_range(cpp2::in<int> count) -> bool;

#line 586 "regex.h2"
    private: template<typename Iter, typename Other> [[nodiscard]] static auto match_greedy(cpp2::in<int> count, Iter const& cur, Iter const& last_valid, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> match_return<Iter>;
    public: range_matcher_logic() = default;
    public: range_matcher_logic(range_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_matcher_logic const&) -> void = delete;


#line 614 "regex.h2"
};

// Regex syntax: *, +, or ?  Example: aa*
//
template<typename CharT, typename M, int min_count, int max_count, CharT symbol> class special_range_matcher_logic: public range_matcher_logic<CharT,M,min_count,max_count> {

    public: [[nodiscard]] static auto to_string() -> auto;
    public: special_range_matcher_logic() = default;
    public: special_range_matcher_logic(special_range_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(special_range_matcher_logic const&) -> void = delete;

#line 621 "regex.h2"
};

// Regex syntax: \b or \B  Example: \bword\b
//
// Matches the start end end of word boundaries.
//
template<typename CharT, bool negate> class word_boundary_matcher_logic
 {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, [[maybe_unused]] Other const& unnamed_param_3) -> auto;

#line 658 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> std::string;
    public: word_boundary_matcher_logic() = default;
    public: word_boundary_matcher_logic(word_boundary_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(word_boundary_matcher_logic const&) -> void = delete;


#line 666 "regex.h2"
};

#line 669 "regex.h2"
//-----------------------------------------------------------------------
//
//  Regular expression implementation.
//
//-----------------------------------------------------------------------
//

// Regular expression implementation
template<typename CharT, size_t groups, size_t alternatives, typename Matcher> class regular_expression {

    // TODO: Add named groups.

    public: template<typename Iter> using context = match_context<CharT,Iter,groups,alternatives>;

    private: [[nodiscard]] static auto get_iter(cpp2::in<view<CharT>> str, auto const& pos) -> auto;

#line 692 "regex.h2"
    // TODO: Named multiple return has problems with templates.
    public: template<typename Iter> class search_return {
        public: bool matched; 
        public: context<Iter> ctx; 

        public: explicit search_return(cpp2::in<bool> matched_, context<Iter> const& ctx_);

#line 702 "regex.h2"
        public: [[nodiscard]] auto group_number() const& -> auto;
        public: [[nodiscard]] auto group(cpp2::in<int> g) const& -> auto;
        public: [[nodiscard]] auto group_start(cpp2::in<int> g) const& -> auto;
        public: [[nodiscard]] auto group_end(cpp2::in<int> g) const& -> auto;
        public: search_return(search_return const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(search_return const&) -> void = delete;

#line 706 "regex.h2"
    };

    public: [[nodiscard]] auto match(cpp2::in<view<CharT>> str) const& -> auto;
    public: [[nodiscard]] auto match(cpp2::in<view<CharT>> str, auto const& start) const& -> auto;
    public: [[nodiscard]] auto match(cpp2::in<view<CharT>> str, auto const& start, auto const& length) const& -> auto;
    public: template<typename Iter> [[nodiscard]] auto match(Iter const& start, Iter const& end) const& -> search_return<Iter>;

#line 718 "regex.h2"
    public: [[nodiscard]] auto search(cpp2::in<view<CharT>> str) const& -> auto;
    public: [[nodiscard]] auto search(cpp2::in<view<CharT>> str, auto const& start) const& -> auto;
    public: [[nodiscard]] auto search(cpp2::in<view<CharT>> str, auto const& start, auto const& length) const& -> auto;
    public: template<typename Iter> [[nodiscard]] auto search(Iter const& start, Iter const& end) const& -> search_return<Iter>;

#line 740 "regex.h2"
    public: [[nodiscard]] auto to_string() const& -> auto;
    public: regular_expression() = default;
    public: regular_expression(regular_expression const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regular_expression const&) -> void = delete;

#line 741 "regex.h2"
};

//-----------------------------------------------------------------------
//
//  Parser for regular expression.
//
//-----------------------------------------------------------------------
//

class regex_parser_state {

    // Current list of matchers
    public: std::vector<std::string> cur_match_list {}; 

    /// List of alternate matcher lists. E.g. ab|cd|xy
    public: std::vector<std::vector<std::string>> alternate_match_lists {}; 

    public: auto next_alternative() & -> void;

#line 764 "regex.h2"
    public: auto swap(regex_parser_state& t) & -> void;

#line 769 "regex.h2"
    public: auto add(auto const& matcher) & -> void;

    public: auto wrap_last(auto const& matcher) & -> void;

#line 778 "regex.h2"
    public: [[nodiscard]] auto empty() const& -> bool;
};

#line 782 "regex.h2"
template<typename Error_out> class regex_parser {

    private: std::string_view regex; 
    private: regex_parser_state cur_state {}; 
    private: size_t pos {0}; 

    private: int next_group_id {1}; // Global capture group.
    private: int alternatives_count {0}; 

    private: std::map<std::string,int> named_groups {}; 

    private: bool has_error {false}; 
    private: Error_out error_out; 

    private: std::vector<std::string> supported_classes {"alnum", "alpha", "ascii", "blank", "cntrl", "digits", "graph", 
                                                   "lower", "print", "punct", "space", "upper", "word", "xdigit"}; 

    public: explicit regex_parser(cpp2::in<std::string_view> r, Error_out const& e);

#line 804 "regex.h2"
    // State management functions
    //
    public: [[nodiscard]] auto new_state() & -> regex_parser_state;

#line 812 "regex.h2"
    public: auto restore_state(cpp2::in<regex_parser_state> old_state) & -> void;

#line 816 "regex.h2"
    // Position management functions
    //

    public: [[nodiscard]] auto next(cpp2::out<char> n) & -> bool;

#line 831 "regex.h2"
    public: [[nodiscard]] auto grab_until(cpp2::in<char> e, cpp2::out<std::string> r) & -> bool;

#line 846 "regex.h2"
    public: [[nodiscard]] auto grab_number() & -> std::string;

#line 866 "regex.h2"
    // Misc functions
    //
    public: auto error(cpp2::in<std::string> message) & -> void;

#line 873 "regex.h2"
    public: [[nodiscard]] auto create_matcher(cpp2::in<std::string> name, cpp2::in<std::string> template_arguments) const& -> auto;

#line 880 "regex.h2"
    public: [[nodiscard]] auto create_matcher_from_list(auto const& list) & -> auto;

    public: [[nodiscard]] auto create_matcher_from_state() & -> std::string;

#line 902 "regex.h2"
    public: [[nodiscard]] static auto join(cpp2::in<std::vector<std::string>> list) -> std::string;

#line 914 "regex.h2"
    // Parsing functions
    //

    public: [[nodiscard]] auto is_alternative(cpp2::in<char> c) & -> bool;

#line 924 "regex.h2"
    public: [[nodiscard]] auto is_anchor(cpp2::in<char> c) & -> bool;

#line 937 "regex.h2"
    public: [[nodiscard]] auto is_any(cpp2::in<char> c) & -> bool;

#line 945 "regex.h2"
    public: [[nodiscard]] auto is_class(cpp2::in<char> c) & -> bool;

#line 1061 "regex.h2"
    public: [[nodiscard]] auto is_escape(cpp2::in<char> c) & -> bool;

#line 1160 "regex.h2"
    public: [[nodiscard]] auto is_group(cpp2::in<char> c) & -> bool;

#line 1200 "regex.h2"
    public: [[nodiscard]] auto is_handle_special(cpp2::in<char> c) & -> bool;

#line 1209 "regex.h2"
    public: [[nodiscard]] auto is_range(cpp2::in<char> c) & -> bool;

#line 1272 "regex.h2"
    public: [[nodiscard]] auto is_special_range(cpp2::in<char> c) & -> bool;

#line 1298 "regex.h2"
    public: auto parse_until(cpp2::in<char> term) & -> void;

#line 1321 "regex.h2"
    public: [[nodiscard]] auto parse() & -> std::string;
    public: regex_parser(regex_parser const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_parser const&) -> void = delete;


#line 1333 "regex.h2"
};

template<typename Err> [[nodiscard]] auto generate_template(cpp2::in<std::string_view> regex, Err const& err) -> std::string;

#line 1342 "regex.h2"
}
}


//=== Cpp2 function definitions =================================================

#line 1 "regex.h2"

#line 15 "regex.h2"
namespace cpp2 {

namespace regex {

#line 51 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> match_context<CharT,Iter,max_groups,max_alternatives>::match_context(Iter const& begin_, Iter const& end_)
        : begin{ begin_ }
        , end{ end_ }{

#line 54 "regex.h2"
    }

#line 56 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> match_context<CharT,Iter,max_groups,max_alternatives>::match_context(match_context const& that)
                                   : begin{ that.begin }
                                   , end{ that.end }
                                   , groups{ that.groups }
                                   , alternatives_pos{ that.alternatives_pos }{}
#line 56 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> auto match_context<CharT,Iter,max_groups,max_alternatives>::operator=(match_context const& that) -> match_context& {
                                   begin = that.begin;
                                   end = that.end;
                                   groups = that.groups;
                                   alternatives_pos = that.alternatives_pos;
                                   return *this; }
#line 56 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> match_context<CharT,Iter,max_groups,max_alternatives>::match_context(match_context&& that) noexcept
                                   : begin{ std::move(that).begin }
                                   , end{ std::move(that).end }
                                   , groups{ std::move(that).groups }
                                   , alternatives_pos{ std::move(that).alternatives_pos }{}
#line 56 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> auto match_context<CharT,Iter,max_groups,max_alternatives>::operator=(match_context&& that) noexcept -> match_context& {
                                   begin = std::move(that).begin;
                                   end = std::move(that).end;
                                   groups = std::move(that).groups;
                                   alternatives_pos = std::move(that).alternatives_pos;
                                   return *this; }

#line 60 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::get_group(auto const& group) const& -> auto { return CPP2_ASSERT_IN_BOUNDS(groups, group);  }

#line 62 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::get_group_string(auto const& group) const& -> std::string{
        if (cpp2::cmp_greater_eq(group,max_groups)) {
            return ""; 
        }
        return std::string(CPP2_ASSERT_IN_BOUNDS(groups, group).start, CPP2_ASSERT_IN_BOUNDS(groups, group).end); 
    }
#line 68 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::get_group_start(auto const& group) const& -> auto { return std::distance(begin, CPP2_ASSERT_IN_BOUNDS(groups, group).start); }
#line 69 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::get_group_end(auto const& group) const& -> auto { return std::distance(begin, CPP2_ASSERT_IN_BOUNDS(groups, group).end); }

#line 71 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> auto match_context<CharT,Iter,max_groups,max_alternatives>::set_group_end(auto const& group, auto const& pos) & -> void{
        CPP2_ASSERT_IN_BOUNDS(groups, group).end = pos;
        CPP2_ASSERT_IN_BOUNDS(groups, group).matched = true;
    }

#line 76 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> auto match_context<CharT,Iter,max_groups,max_alternatives>::set_group_invalid(auto const& group) & -> void{
        CPP2_ASSERT_IN_BOUNDS(groups, group).matched = false;
    }

#line 80 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> auto match_context<CharT,Iter,max_groups,max_alternatives>::set_group_start(auto const& group, auto const& pos) & -> void{
        CPP2_ASSERT_IN_BOUNDS(groups, group).start = pos;
    }

#line 84 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::size() const& -> auto { return max_groups;  }

#line 88 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::get_alternative_pos(auto const& alternative) const& -> auto { return CPP2_ASSERT_IN_BOUNDS(alternatives_pos, alternative);  }

#line 90 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> auto match_context<CharT,Iter,max_groups,max_alternatives>::set_alternative_pos(auto const& alternative, auto const& pos) & -> void{
        CPP2_ASSERT_IN_BOUNDS(alternatives_pos, alternative) = pos;
    }

#line 96 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::print_ranges() const& -> bstring<CharT>{
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

#line 117 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto matcher_list<CharT,List...>::match(auto const& cur, auto& ctx) -> auto { return match_select<List...>(cur, ctx);  }

#line 119 "regex.h2"
    template <typename CharT, typename ...List> template<typename ...OtherList> [[nodiscard]] auto matcher_list<CharT,List...>::match(auto const& cur, auto& ctx, [[maybe_unused]] matcher_list<CharT,OtherList...> const& unnamed_param_3) -> auto { 
        return match_select<List...,OtherList...>(cur, ctx);  }

#line 122 "regex.h2"
    template <typename CharT, typename ...List> template<typename First, typename ...Other> [[nodiscard]] auto matcher_list<CharT,List...>::match_select(auto const& cur, auto& ctx) -> auto { 
        return First::match(cur, ctx, matcher_list<CharT,Other...>());  }
#line 124 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto matcher_list<CharT,List...>::match_select(auto const& cur, auto& ctx) -> auto { return match_return(true, cur);  }

#line 126 "regex.h2"
    template <typename CharT, typename ...List> auto matcher_list<CharT,List...>::reset_ranges(auto& ctx) -> void { (List::reset_ranges(ctx), ...);  }
#line 127 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto matcher_list<CharT,List...>::to_string() -> auto { return (bstring<CharT>() + ... + List::to_string());  }

#line 129 "regex.h2"
    template <typename CharT, typename ...List> template<typename Pre> [[nodiscard]] auto matcher_list<CharT,List...>::prepend([[maybe_unused]] Pre const& unnamed_param_1) -> auto { return matcher_list<CharT,Pre,List...>();  }

#line 145 "regex.h2"
    template <typename CharT, CharT C> [[nodiscard]] auto single_class_entry<CharT,C>::includes(cpp2::in<CharT> c) -> auto { return c == C;  }
#line 146 "regex.h2"
    template <typename CharT, CharT C> [[nodiscard]] auto single_class_entry<CharT,C>::to_string() -> auto { return bstring<CharT>(1, C); }

#line 153 "regex.h2"
    template <typename CharT, CharT Start, CharT End> [[nodiscard]] auto range_class_entry<CharT,Start,End>::includes(cpp2::in<CharT> c) -> auto { return [_0 = Start, _1 = c, _2 = End]{ return cpp2::cmp_less_eq(_0,_1) && cpp2::cmp_less_eq(_1,_2); }();  }
#line 154 "regex.h2"
    template <typename CharT, CharT Start, CharT End> [[nodiscard]] auto range_class_entry<CharT,Start,End>::to_string() -> auto { return cpp2::to_string(Start) + "-" + cpp2::to_string(End); }

#line 160 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto combined_class_entry<CharT,List...>::includes(cpp2::in<CharT> c) -> auto { return (false || ... || List::includes(c));  }
#line 161 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto combined_class_entry<CharT,List...>::to_string() -> auto { return ("" + ... + List::to_string()); }

#line 167 "regex.h2"
    template <typename CharT, CharT ...List> [[nodiscard]] auto list_class_entry<CharT,List...>::includes(cpp2::in<CharT> c) -> auto { return (false || ... || (List == c));  }
#line 168 "regex.h2"
    template <typename CharT, CharT ...List> [[nodiscard]] auto list_class_entry<CharT,List...>::to_string() -> auto { return ("" + ... + List); }

#line 174 "regex.h2"
    template <typename CharT, fixed_string Name, typename Inner> [[nodiscard]] auto named_class_entry<CharT,Name,Inner>::includes(cpp2::in<CharT> c) -> auto { return Inner::includes(c);  }
#line 175 "regex.h2"
    template <typename CharT, fixed_string Name, typename Inner> [[nodiscard]] auto named_class_entry<CharT,Name,Inner>::to_string() -> auto { return "[:" + cpp2::to_string(CPP2_UFCS(data)(Name)) + ":]"; }

#line 180 "regex.h2"
    template <typename CharT, typename Inner> [[nodiscard]] auto negated_class_entry<CharT,Inner>::includes(cpp2::in<CharT> c) -> auto { return !(Inner::includes(c));  }

#line 186 "regex.h2"
    template <typename CharT, fixed_string Name, typename Inner> [[nodiscard]] auto shorthand_class_entry<CharT,Name,Inner>::includes(cpp2::in<CharT> c) -> auto { return Inner::includes(c);  }
#line 187 "regex.h2"
    template <typename CharT, fixed_string Name, typename Inner> [[nodiscard]] auto shorthand_class_entry<CharT,Name,Inner>::to_string() -> auto { return bstring<CharT>(CPP2_UFCS(data)(Name)); }

#line 232 "regex.h2"
    template <typename CharT, size_t alternative> template<typename Other> [[nodiscard]] auto extract_position_helper<CharT,alternative>::match(auto const& cur, auto& ctx, [[maybe_unused]] Other const& unnamed_param_3) -> auto{
        auto r {Other::match(cur, ctx)}; 
        if (r.matched) {
            CPP2_UFCS(set_alternative_pos)(ctx, alternative, cur);
        }
        return r; 
    }

#line 240 "regex.h2"
    template <typename CharT, size_t alternative> auto extract_position_helper<CharT,alternative>::reset_ranges(auto& ctx) -> void{}
#line 241 "regex.h2"
    template <typename CharT, size_t alternative> [[nodiscard]] auto extract_position_helper<CharT,alternative>::to_string() -> auto{}

#line 250 "regex.h2"
    template <typename CharT, size_t alternative, typename ...List> template<typename Tail> [[nodiscard]] auto alternative_matcher_logic<CharT,alternative,List...>::match(auto const& cur, auto& ctx, Tail const& tail) -> auto{
        if constexpr (greedy_alternative) {
            auto max_overall_length {0}; 
            auto max_current_length {0}; 
            auto r {match_greedy<Tail,List...>(cur, max_overall_length, max_current_length, ctx, tail)}; 
            static_cast<void>(std::move(max_overall_length));
            static_cast<void>(std::move(max_current_length));
            return r; 
        }else {
            return match_first<List...>(cur, ctx, tail); 
        }
    }
#line 262 "regex.h2"
    template <typename CharT, size_t alternative, typename ...List> auto alternative_matcher_logic<CharT,alternative,List...>::reset_ranges(auto& ctx) -> void { (List::reset_ranges(ctx), ...); }
#line 263 "regex.h2"
    template <typename CharT, size_t alternative, typename ...List> [[nodiscard]] auto alternative_matcher_logic<CharT,alternative,List...>::to_string() -> auto { return CPP2_UFCS(substr)((bstring<CharT>() + ... + ("|" + List::to_string())), 1); }// substr: Remove first '|'.

#line 265 "regex.h2"
    template <typename CharT, size_t alternative, typename ...List> template<typename First, typename ...Next> [[nodiscard]] auto alternative_matcher_logic<CharT,alternative,List...>::match_first(auto const& cur, auto& ctx, auto const& tail) -> auto{
        auto r {First::match(cur, ctx, tail)}; 
        if (r.matched) {
            return r; 
        }else {
            First::reset_ranges(ctx);

            if constexpr (0 != sizeof...(Next)) {
                return match_first<Next...>(cur, ctx, tail); 
            }else {
                return match_return(false, ctx.end); 
            }
        }
    }

#line 280 "regex.h2"
    template <typename CharT, size_t alternative, typename ...List> template<typename Tail, typename First, typename ...Next> [[nodiscard]] auto alternative_matcher_logic<CharT,alternative,List...>::match_greedy(auto const& cur, auto& max_overall_length, auto& max_current_length, auto& ctx, [[maybe_unused]] Tail const& unnamed_param_5) -> auto{
        auto r {First::match(cur, ctx, Tail::prepend(extract_position_helper<CharT,alternative>()))}; 

        // Get the end position of First.
        auto end_overall_pos {cur}; 
        auto end_current_pos {cur}; 
        if (r.matched) {
            end_overall_pos = r.pos;
            end_current_pos = CPP2_UFCS(get_alternative_pos)(ctx, alternative);
        }

        // Compute the new max length and our max length.
        auto my_overall_length {unsafe_narrow<int>(std::distance(cur, std::move(end_overall_pos)))}; 
        max_overall_length = std::max(max_overall_length, my_overall_length);

#line 296 "regex.h2"
        // Check if someone other has something larker
        auto o {match_return(false, ctx.end)}; 
        if constexpr (0 != sizeof...(Next)) {
            o = match_greedy<Tail,Next...>(cur, max_overall_length, max_current_length, ctx, Tail());
        }

        auto my_current_length {unsafe_narrow<int>(std::distance(cur, std::move(end_current_pos)))}; 
        if (max_overall_length == my_overall_length) {
            max_current_length = std::max(max_current_length, my_current_length);
        }

#line 308 "regex.h2"
        if (std::move(r).matched && std::move(my_overall_length) == max_overall_length) {
            // We are the longest. Check now if we are also the longest in this alternative.
            if (std::move(my_current_length) == max_current_length) {
                // Yes we are. Reset all groups by matching again.
                (Next::reset_ranges(ctx), ...);  // Reset all other ranges.
                return First::match(cur, ctx, Tail::prepend(extract_position_helper<CharT,alternative>())); 
            }
            else {
                // We are not, so there was an other match.
                First::reset_ranges(ctx);

                return o; 
            }
        }else {
            // We are not the largest one.
            First::reset_ranges(ctx);

            return o; 
        }
    }

#line 334 "regex.h2"
    template <typename CharT> template<typename Other> [[nodiscard]] auto any_matcher_logic<CharT>::match(auto const& cur, auto& ctx, [[maybe_unused]] Other const& unnamed_param_3) -> auto{
        if (cur != ctx.end) {
            return Other::match(cur + 1, ctx); 
        }else {
            return match_return(false, ctx.end); 
        }
    }

#line 342 "regex.h2"
    template <typename CharT> auto any_matcher_logic<CharT>::reset_ranges(auto& ctx) -> void{}
#line 343 "regex.h2"
    template <typename CharT> [[nodiscard]] auto any_matcher_logic<CharT>::to_string() -> auto { return bstring<CharT>(1, '.'); }

#line 350 "regex.h2"
    template <typename CharT, CharT C> template<typename Other> [[nodiscard]] auto char_matcher_logic<CharT,C>::match(auto const& cur, auto& ctx, [[maybe_unused]] Other const& unnamed_param_3) -> auto{
        if (cur != ctx.end && *cpp2::assert_not_null(cur) == C) {
            return Other::match(cur + 1, ctx); 
        }else {
            return match_return(false, ctx.end); 
        }
    }
#line 357 "regex.h2"
    template <typename CharT, CharT C> auto char_matcher_logic<CharT,C>::reset_ranges(auto& ctx) -> void{}
#line 358 "regex.h2"
    template <typename CharT, CharT C> [[nodiscard]] auto char_matcher_logic<CharT,C>::to_string() -> auto { return bstring<CharT>(1, C); }

#line 366 "regex.h2"
    template <typename CharT, bool negate, typename ...List> template<typename Other> [[nodiscard]] auto class_matcher_logic<CharT,negate,List...>::match(auto const& cur, auto& ctx, [[maybe_unused]] Other const& unnamed_param_3) -> auto{
        if (cur != ctx.end && negate != match_any<List...>(*cpp2::assert_not_null(cur))) {
            return Other::match(cur + 1, ctx); 
        }else {
            return match_return(false, ctx.end); 
        }
    }

#line 374 "regex.h2"
    template <typename CharT, bool negate, typename ...List> template<typename First, typename ...Other> [[nodiscard]] auto class_matcher_logic<CharT,negate,List...>::match_any(cpp2::in<CharT> c) -> bool{
        bool r {First::includes(c)}; 

        if (!(r)) {
            if constexpr (0 != sizeof...(Other)) {
                r = match_any<Other...>(c);
            }
        }

        return r; 
    }

#line 386 "regex.h2"
    template <typename CharT, bool negate, typename ...List> auto class_matcher_logic<CharT,negate,List...>::reset_ranges(auto& ctx) -> void{}

#line 388 "regex.h2"
    template <typename CharT, bool negate, typename ...List> [[nodiscard]] auto class_matcher_logic<CharT,negate,List...>::to_string() -> bstring<CharT>{
        bstring<CharT> r {"["}; 
        if (negate) {
            r += "^";
        }
        r += (bstring<CharT>() + ... + List::to_string());
        r += "]";

        return r; 
    }

#line 406 "regex.h2"
    template <typename CharT, CharT C> [[nodiscard]] auto escaped_char_matcher_logic<CharT,C>::to_string() -> auto { return "\\" + cpp2::to_string(C);  }

#line 412 "regex.h2"
    template <typename CharT, int group, fixed_string name> template<typename Other> [[nodiscard]] auto group_matcher_start_logic<CharT,group,name>::match(auto const& cur, auto& ctx, [[maybe_unused]] Other const& unnamed_param_3) -> auto{
        CPP2_UFCS(set_group_start)(ctx, group, cur);
        auto r {Other::match(cur, ctx)}; 
        return r; 
    }

#line 418 "regex.h2"
    template <typename CharT, int group, fixed_string name> auto group_matcher_start_logic<CharT,group,name>::reset_ranges(auto& ctx) -> void { CPP2_UFCS(set_group_invalid)(ctx, group);  }

#line 420 "regex.h2"
    template <typename CharT, int group, fixed_string name> [[nodiscard]] auto group_matcher_start_logic<CharT,group,name>::to_string() -> std::string{
        if (group != 0) {
            if (0 != CPP2_UFCS(size)(name)) {
                return { "(?<" + cpp2::to_string(CPP2_UFCS(data)(name)) + ">" }; 
            }
            else {
                return "("; 
            }
        }
        else {
            return ""; 
        }
    }

#line 436 "regex.h2"
    template <typename CharT, int group> template<typename Other> [[nodiscard]] auto group_matcher_end_logic<CharT,group>::match(auto const& cur, auto& ctx, [[maybe_unused]] Other const& unnamed_param_3) -> auto{
        CPP2_UFCS(set_group_end)(ctx, group, cur);
        auto r {Other::match(cur, ctx)}; 
        if (!(r.matched)) {
            CPP2_UFCS(set_group_invalid)(ctx, group);
        }
        return r; 
    }

#line 445 "regex.h2"
    template <typename CharT, int group> auto group_matcher_end_logic<CharT,group>::reset_ranges(auto& ctx) -> void{}

#line 447 "regex.h2"
    template <typename CharT, int group> [[nodiscard]] auto group_matcher_end_logic<CharT,group>::to_string() -> auto{
        if (group != 0) {
            return ")"; 
        }
        else {
            return ""; 
        }
    }

#line 460 "regex.h2"
    template <typename CharT, int group, fixed_string symbol> template<typename Other> [[nodiscard]] auto group_ref_matcher_logic<CharT,group,symbol>::match(auto const& cur, auto& ctx, [[maybe_unused]] Other const& unnamed_param_3) -> auto{
        auto g {CPP2_UFCS(get_group)(ctx, group)}; 

        auto pos {cur}; 
        for( ; g.start != g.end && pos != ctx.end; (++g.start, ++pos) ) {
            if (*cpp2::assert_not_null(g.start) != *cpp2::assert_not_null(pos)) {
                return match_return(false, ctx.end); 
            }
        }

        return Other::match(std::move(pos), ctx); 
    }
#line 472 "regex.h2"
    template <typename CharT, int group, fixed_string symbol> auto group_ref_matcher_logic<CharT,group,symbol>::reset_ranges(auto& ctx) -> void{}
#line 473 "regex.h2"
    template <typename CharT, int group, fixed_string symbol> [[nodiscard]] auto group_ref_matcher_logic<CharT,group,symbol>::to_string() -> auto { return bstring<CharT>(CPP2_UFCS(data)(symbol)); }

#line 482 "regex.h2"
    template <typename CharT, bool match_new_line, bool match_new_line_before_end> template<typename Other> [[nodiscard]] auto line_end_matcher_logic<CharT,match_new_line,match_new_line_before_end>::match(auto const& cur, auto& ctx, [[maybe_unused]] Other const& unnamed_param_3) -> auto{
        if (cur == ctx.end || (match_new_line && *cpp2::assert_not_null(cur) == '\n')) {
            return Other::match(cur, ctx); 
        }
        else {if (!(match_new_line_before_end) && (*cpp2::assert_not_null(cur) == '\n' && (cur + 1) == ctx.end)) {// Special cas for new line at end.
            return Other::match(cur, ctx); 
        }
        else {
            return match_return(false, ctx.end); 
        }}
    }

#line 494 "regex.h2"
    template <typename CharT, bool match_new_line, bool match_new_line_before_end> auto line_end_matcher_logic<CharT,match_new_line,match_new_line_before_end>::reset_ranges(auto& ctx) -> void{}
#line 495 "regex.h2"
    template <typename CharT, bool match_new_line, bool match_new_line_before_end> [[nodiscard]] auto line_end_matcher_logic<CharT,match_new_line,match_new_line_before_end>::to_string() -> auto { return "\\$"; }

#line 504 "regex.h2"
    template <typename CharT, bool match_new_line> template<typename Other> [[nodiscard]] auto line_start_matcher_logic<CharT,match_new_line>::match(auto const& cur, auto& ctx, [[maybe_unused]] Other const& unnamed_param_3) -> auto{
        if (cur == ctx.begin || (match_new_line && *cpp2::assert_not_null((cur - 1)) == '\n')) {
            return Other::match(cur, ctx); 
        }
        else {
            return match_return(false, ctx.end); 
        }

    }
#line 513 "regex.h2"
    template <typename CharT, bool match_new_line> auto line_start_matcher_logic<CharT,match_new_line>::reset_ranges(auto& ctx) -> void{}
#line 514 "regex.h2"
    template <typename CharT, bool match_new_line> [[nodiscard]] auto line_start_matcher_logic<CharT,match_new_line>::to_string() -> auto { return bstring<CharT>(1, '^'); }

#line 522 "regex.h2"
    template <typename CharT, fixed_string Name, typename Base> [[nodiscard]] auto named_matcher_logic<CharT,Name,Base>::to_string() -> auto { return bstring<CharT>(CPP2_UFCS(data)(Name));  }

#line 548 "regex.h2"
    template <typename CharT, typename M, int min_count, int max_count> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count>::match(auto const& cur, auto& ctx, auto const& tail) -> auto { return match_greedy(0, cur, cur, ctx, tail); }
#line 549 "regex.h2"
    template <typename CharT, typename M, int min_count, int max_count> auto range_matcher_logic<CharT,M,min_count,max_count>::reset_ranges(auto& ctx) -> void { M::reset_ranges(ctx); }

#line 551 "regex.h2"
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

#line 570 "regex.h2"
    template <typename CharT, typename M, int min_count, int max_count> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count>::is_below_upper_bound(cpp2::in<int> count) -> bool{
        if (-1 == max_count) {return true; }
        else {return cpp2::cmp_less(count,max_count); }
    }

#line 575 "regex.h2"
    template <typename CharT, typename M, int min_count, int max_count> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count>::is_below_lower_bound(cpp2::in<int> count) -> bool{
        if (-1 == min_count) {return false; }
        else {return cpp2::cmp_less(count,min_count); }
    }

#line 580 "regex.h2"
    template <typename CharT, typename M, int min_count, int max_count> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count>::is_in_range(cpp2::in<int> count) -> bool{
        if (-1 != min_count && cpp2::cmp_less(count,min_count)) {return false; }
        if (-1 != max_count && cpp2::cmp_greater(count,max_count)) {return false; }
        return true; 
    }

#line 586 "regex.h2"
    template <typename CharT, typename M, int min_count, int max_count> template<typename Iter, typename Other> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count>::match_greedy(cpp2::in<int> count, Iter const& cur, Iter const& last_valid, auto& ctx, [[maybe_unused]] Other const& unnamed_param_5) -> match_return<Iter>{
        auto r {M::match(cur, ctx, no_tail<CharT>())}; 
        if ( is_below_upper_bound(count) && r.matched && 
            (is_below_lower_bound(count) || r.pos != cur)) 
        {
            auto inner {match_greedy(count + 1, std::move(r).pos, cur, ctx, Other())}; 

            if (inner.matched) {
                return inner; 
            }
        }

        // No match from the recursion. Try to match our tail.
        if (is_in_range(count)) {
            auto o {Other::match(cur, ctx)}; 

            if (o.matched) {
                // Rematch M to set the groups.
                M::reset_ranges(ctx);
                static_cast<void>(M::match(last_valid, ctx, no_tail<CharT>()));
            }

            return o; 
        }
        else {
            return match_return(false, ctx.end); 
        }
    }

#line 620 "regex.h2"
    template <typename CharT, typename M, int min_count, int max_count, CharT symbol> [[nodiscard]] auto special_range_matcher_logic<CharT,M,min_count,max_count,symbol>::to_string() -> auto { return M::to_string() + symbol;  }

#line 629 "regex.h2"
    template <typename CharT, bool negate> template<typename Other> [[nodiscard]] auto word_boundary_matcher_logic<CharT,negate>::match(auto const& cur, auto& ctx, [[maybe_unused]] Other const& unnamed_param_3) -> auto{
        word_class<CharT> words {}; 
        auto is_match {false}; 
        if (cur == ctx.begin) {// String start
            if (cur != ctx.end) {// No empty string
                is_match = CPP2_UFCS(includes)(std::move(words), *cpp2::assert_not_null(cur));
            }
        }
        else {if (cur == ctx.end) {// String end
            is_match = CPP2_UFCS(includes)(words, *cpp2::assert_not_null((cur - 1)));
        }
        else { // Middle of string
            is_match = 
                   (CPP2_UFCS(includes)(words, *cpp2::assert_not_null((cur - 1))) && !(CPP2_UFCS(includes)(words, *cpp2::assert_not_null(cur)))) // End of word: \w\W
                || (!(CPP2_UFCS(includes)(words, *cpp2::assert_not_null((cur - 1)))) && CPP2_UFCS(includes)(std::move(words), *cpp2::assert_not_null(cur)));// Start of word: \W\w

        }}
        if (negate) {
            is_match = !(is_match);
        }

        if (std::move(is_match)) {
            return Other::match(cur, ctx); 
        }
        else {
            return match_return(false, ctx.end); 
        }

    }
#line 658 "regex.h2"
    template <typename CharT, bool negate> auto word_boundary_matcher_logic<CharT,negate>::reset_ranges(auto& ctx) -> void{}
#line 659 "regex.h2"
    template <typename CharT, bool negate> [[nodiscard]] auto word_boundary_matcher_logic<CharT,negate>::to_string() -> std::string{
        if (negate) {
            return "\\B"; 
        }else {
            return "\\b"; 
        }
    }

#line 683 "regex.h2"
    template <typename CharT, size_t groups, size_t alternatives, typename Matcher> [[nodiscard]] auto regular_expression<CharT,groups,alternatives,Matcher>::get_iter(cpp2::in<view<CharT>> str, auto const& pos) -> auto{
        if (cpp2::cmp_less(pos,CPP2_UFCS(size)(str))) {
            return CPP2_UFCS(begin)(str) + pos; 
        }
        else {
            return CPP2_UFCS(end)(str); 
        }
    }

#line 697 "regex.h2"
        template <typename CharT, size_t groups, size_t alternatives, typename Matcher> template <typename Iter> regular_expression<CharT,groups,alternatives,Matcher>::search_return<Iter>::search_return(cpp2::in<bool> matched_, context<Iter> const& ctx_)
            : matched{ matched_ }
            , ctx{ ctx_ }{

#line 700 "regex.h2"
        }

#line 702 "regex.h2"
        template <typename CharT, size_t groups, size_t alternatives, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,groups,alternatives,Matcher>::search_return<Iter>::group_number() const& -> auto { return CPP2_UFCS(size)(ctx);  }
#line 703 "regex.h2"
        template <typename CharT, size_t groups, size_t alternatives, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,groups,alternatives,Matcher>::search_return<Iter>::group(cpp2::in<int> g) const& -> auto { return CPP2_UFCS(get_group_string)(ctx, g); }
#line 704 "regex.h2"
        template <typename CharT, size_t groups, size_t alternatives, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,groups,alternatives,Matcher>::search_return<Iter>::group_start(cpp2::in<int> g) const& -> auto { return CPP2_UFCS(get_group_start)(ctx, g); }
#line 705 "regex.h2"
        template <typename CharT, size_t groups, size_t alternatives, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,groups,alternatives,Matcher>::search_return<Iter>::group_end(cpp2::in<int> g) const& -> auto { return CPP2_UFCS(get_group_end)(ctx, g); }

#line 708 "regex.h2"
    template <typename CharT, size_t groups, size_t alternatives, typename Matcher> [[nodiscard]] auto regular_expression<CharT,groups,alternatives,Matcher>::match(cpp2::in<view<CharT>> str) const& -> auto { return match(CPP2_UFCS(begin)(str), CPP2_UFCS(end)(str)); }
#line 709 "regex.h2"
    template <typename CharT, size_t groups, size_t alternatives, typename Matcher> [[nodiscard]] auto regular_expression<CharT,groups,alternatives,Matcher>::match(cpp2::in<view<CharT>> str, auto const& start) const& -> auto { return match(get_iter(str, start), CPP2_UFCS(end)(str)); }
#line 710 "regex.h2"
    template <typename CharT, size_t groups, size_t alternatives, typename Matcher> [[nodiscard]] auto regular_expression<CharT,groups,alternatives,Matcher>::match(cpp2::in<view<CharT>> str, auto const& start, auto const& length) const& -> auto { return match(get_iter(str, start), get_iter(str, start + length)); }
#line 711 "regex.h2"
    template <typename CharT, size_t groups, size_t alternatives, typename Matcher> template<typename Iter> [[nodiscard]] auto regular_expression<CharT,groups,alternatives,Matcher>::match(Iter const& start, Iter const& end) const& -> search_return<Iter>{
        context ctx {start, end}; 

        auto r {Matcher::match(start, ctx)}; 
        return search_return(r.matched && std::move(r).pos == end, std::move(ctx)); 
    }

#line 718 "regex.h2"
    template <typename CharT, size_t groups, size_t alternatives, typename Matcher> [[nodiscard]] auto regular_expression<CharT,groups,alternatives,Matcher>::search(cpp2::in<view<CharT>> str) const& -> auto { return search(CPP2_UFCS(begin)(str), CPP2_UFCS(end)(str)); }
#line 719 "regex.h2"
    template <typename CharT, size_t groups, size_t alternatives, typename Matcher> [[nodiscard]] auto regular_expression<CharT,groups,alternatives,Matcher>::search(cpp2::in<view<CharT>> str, auto const& start) const& -> auto { return search(get_iter(str, start), CPP2_UFCS(end)(str)); }
#line 720 "regex.h2"
    template <typename CharT, size_t groups, size_t alternatives, typename Matcher> [[nodiscard]] auto regular_expression<CharT,groups,alternatives,Matcher>::search(cpp2::in<view<CharT>> str, auto const& start, auto const& length) const& -> auto { return search(get_iter(str, start), get_iter(str, start + length)); }
#line 721 "regex.h2"
    template <typename CharT, size_t groups, size_t alternatives, typename Matcher> template<typename Iter> [[nodiscard]] auto regular_expression<CharT,groups,alternatives,Matcher>::search(Iter const& start, Iter const& end) const& -> search_return<Iter>{
        auto matched {false}; 
        context ctx {start, end}; 

        auto cur {start}; 
        for( ; true; (++cur) ) {
            if (Matcher::match(cur, ctx).matched) {
                matched = true;
                break;
            }

            if (cur == ctx.end) {
                break;
            }
        }

        return search_return(std::move(matched), std::move(ctx)); 
    }

#line 740 "regex.h2"
    template <typename CharT, size_t groups, size_t alternatives, typename Matcher> [[nodiscard]] auto regular_expression<CharT,groups,alternatives,Matcher>::to_string() const& -> auto { return Matcher::to_string();  }

#line 758 "regex.h2"
    auto regex_parser_state::next_alternative() & -> void{
        std::vector<std::string> new_list {}; 
        std::swap(new_list, cur_match_list);
        static_cast<void>(CPP2_UFCS(insert)(alternate_match_lists, CPP2_UFCS(end)(alternate_match_lists), std::move(new_list)));
    }

#line 764 "regex.h2"
    auto regex_parser_state::swap(regex_parser_state& t) & -> void{
        std::swap(cur_match_list, t.cur_match_list);
        std::swap(alternate_match_lists, t.alternate_match_lists);
    }

#line 769 "regex.h2"
    auto regex_parser_state::add(auto const& matcher) & -> void { CPP2_UFCS(push_back)(cur_match_list, matcher);  }

#line 771 "regex.h2"
    auto regex_parser_state::wrap_last(auto const& matcher) & -> void{
        auto last {CPP2_UFCS(back)(cur_match_list)}; 
        CPP2_UFCS(back)(cur_match_list) = matcher(last);
        static_cast<void>(matcher);
        static_cast<void>(std::move(last));
    }

#line 778 "regex.h2"
    [[nodiscard]] auto regex_parser_state::empty() const& -> bool { return CPP2_UFCS(empty)(cur_match_list);  }

#line 799 "regex.h2"
    template <typename Error_out> regex_parser<Error_out>::regex_parser(cpp2::in<std::string_view> r, Error_out const& e)
        : regex{ r }
        , error_out{ e }{

#line 802 "regex.h2"
    }

#line 806 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::new_state() & -> regex_parser_state{
        regex_parser_state old_state {}; 
        CPP2_UFCS(swap)(old_state, cur_state);
        return old_state; 
    }

#line 812 "regex.h2"
    template <typename Error_out> auto regex_parser<Error_out>::restore_state(cpp2::in<regex_parser_state> old_state) & -> void{
        cur_state = old_state;
    }

#line 819 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::next(cpp2::out<char> n) & -> bool{
        if (cpp2::cmp_less((pos + 1),CPP2_UFCS(size)(regex))) {
            pos += 1;
            n.construct(CPP2_ASSERT_IN_BOUNDS(regex, pos));
            return true; 
        }
        else {
            n.construct('\0');
            return false; 
        }
    }

#line 831 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::grab_until(cpp2::in<char> e, cpp2::out<std::string> r) & -> bool{
        auto start {pos}; 
        auto end {CPP2_UFCS(find)(regex, e, pos)}; 

        if (end != std::string_view::npos) {
            r.construct(CPP2_UFCS(substr)(regex, std::move(start), end - pos));
            pos = std::move(end);
            return true; 
        }
        else {
            r.construct("");
            return false; 
        }
    }

#line 846 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::grab_number() & -> std::string{
        auto start {pos}; 
        auto start_search {pos}; 
        if (CPP2_ASSERT_IN_BOUNDS(regex, start_search) == '-') {
            start_search += 1;
        }
        auto end {CPP2_UFCS(find_first_not_of)(regex, "1234567890", std::move(start_search))}; 

        cpp2::deferred_init<std::string> r; 
        if (end != std::string_view::npos) {
            r.construct(CPP2_UFCS(substr)(regex, start, end - std::move(start)));
            pos = std::move(end) - 1;
        }
        else {
            r.construct(CPP2_UFCS(substr)(regex, std::move(start)));
            pos = CPP2_UFCS(size)(regex) - 1;
        }
        return r.value(); 
    }

#line 868 "regex.h2"
    template <typename Error_out> auto regex_parser<Error_out>::error(cpp2::in<std::string> message) & -> void{
        error_out(("Error during parsing of regex '" + cpp2::to_string(regex) + "' at position '" + cpp2::to_string(pos) + "': " + cpp2::to_string(message)));
        has_error = true;
    }

#line 873 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::create_matcher(cpp2::in<std::string> name, cpp2::in<std::string> template_arguments) const& -> auto{
        auto sep {", "}; 
        if (CPP2_UFCS(empty)(template_arguments)) {sep = ""; }

        return "::cpp2::regex::" + cpp2::to_string(name) + "<char" + cpp2::to_string(std::move(sep)) + cpp2::to_string(template_arguments) + ">"; 
    }

#line 880 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::create_matcher_from_list(auto const& list) & -> auto { return create_matcher("matcher_list", join(list));  }

#line 882 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::create_matcher_from_state() & -> std::string{
        if (0 == CPP2_UFCS(size)(cur_state.alternate_match_lists)) {return create_matcher_from_list(cur_state.cur_match_list); }

        if (0 != CPP2_UFCS(size)(cur_state.cur_match_list)) {
            CPP2_UFCS(next_alternative)(cur_state);
        }

        std::string list {""}; 
        std::string separator {""}; 
        for ( auto const& cur : cur_state.alternate_match_lists ) {
            list += separator + create_matcher_from_list(cur);
            separator = ", ";
        }

        auto alternative_id {alternatives_count}; 
        alternatives_count += 1;

        return create_matcher("alternative_matcher_logic", (cpp2::to_string(std::move(alternative_id)) + ", " + cpp2::to_string(std::move(list)))); 
    }

#line 902 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::join(cpp2::in<std::vector<std::string>> list) -> std::string{
        std::string r {""}; 

        std::string separator {""}; 
        for ( auto const& cur : list ) {
            r += separator + cur;
            separator = ", ";
        }

        return r; 
    }

#line 917 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_alternative(cpp2::in<char> c) & -> bool{
        if (c != '|') {return false; }

        CPP2_UFCS(next_alternative)(cur_state);
        return true; 
    }

#line 924 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_anchor(cpp2::in<char> c) & -> bool{
        if (c == '^') {
            CPP2_UFCS(add)(cur_state, create_matcher("line_start_matcher_logic", "true"));
            return true; 
        }
        else {if (c == '$') {
            CPP2_UFCS(add)(cur_state, create_matcher("line_end_matcher_logic", "true, false"));
            return true; 
        }}

        return false; 
    }

#line 937 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_any(cpp2::in<char> c) & -> bool{
        if (c == '.') {
            CPP2_UFCS(add)(cur_state, create_matcher("any_matcher_logic", ""));
            return true; 
        }
        return false; 
    }

#line 945 "regex.h2"
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

        // First step: parse until the end bracket and push single chars, ranges or groups on the class stack.
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
                if (end == std::string::npos) {error("Could not find end of character class."); return false; }

                auto name {CPP2_UFCS(substr)(regex, pos, end - pos)}; 
                if (CPP2_UFCS(end)(supported_classes) == std::find(CPP2_UFCS(begin)(supported_classes), CPP2_UFCS(end)(supported_classes), name)) {
                    error(("Unsupported character class. Supported ones are: " + cpp2::to_string(join(supported_classes))));
                    return false; 
                }

                CPP2_UFCS(push_back)(classes, ("[:" + cpp2::to_string(name) + ":]"));

                end += 1; // Skip ':' pointing to the ending ']'.
                pos = end;
            }
            else {if (c_cur == '\\') {
                if (next_item()  && (c_cur != ']')) {
                    auto name {""}; 
                    if (     's' == c_cur) { name = "short_space"; }
                    else {if ('S' == c_cur) {name = "short_not_space"; }
                    else {if ('w' == c_cur) {name = "short_word"; }
                    else {if ('W' == c_cur) {name = "short_not_word"; }
                    else {if ('d' == c_cur) {name = "short_digits"; }
                    else {if ('D' == c_cur) {name = "short_not_digits"; }
                    else {
                        error("Unknown group escape.");
                        return false; 
                    }}}}}}
                    CPP2_UFCS(push_back)(classes, ("[:" + cpp2::to_string(name) + ":]"));
                }else {
                    error("Escape without a following character.");
                    return false; 
                }
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
            }}}

            first = false;
        }

        static_cast<void>(std::move(next_item));// TODO: Use in while is not recognized.

        if (std::move(c_cur) != ']') {
            error("Error end of character class definition before terminating ']'.");
            return false; 
        }

        if (std::move(range)) {// If '-' is last entry treat it as a literal char.
            CPP2_UFCS(push_back)(classes, "-");
        }

        // Second step: Wrap the item on the class stack with corresponding class implementation.
        for ( auto& cur : classes ) {
            if (CPP2_UFCS(starts_with)(cur, "[:")) {
                auto name {CPP2_UFCS(substr)(cur, 2, CPP2_UFCS(size)(cur) - 4)}; 
                cur = create_matcher((cpp2::to_string(name) + "_class"), "");
            }
            else {if (1 != CPP2_UFCS(size)(cur)) {
                cur = create_matcher("range_class_entry", ("'" + cpp2::to_string(CPP2_ASSERT_IN_BOUNDS_LITERAL(cur, 0)) + "', '" + cpp2::to_string(CPP2_ASSERT_IN_BOUNDS_LITERAL(cur, 2)) + "'"));
            }
            else {
                cur = create_matcher("single_class_entry", ("'" + cpp2::to_string(cur) + "'"));
            }}
        }

        auto inner {join(std::move(classes))}; 
        CPP2_UFCS(add)(cur_state, create_matcher("class_matcher_logic", (cpp2::to_string(std::move(negate)) + ", " + cpp2::to_string(std::move(inner)))));
        return true; 
    }

#line 1061 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_escape(cpp2::in<char> c) & -> bool{
        if (c != '\\') {return false; }

        auto start {pos}; // Keep start for group matchers.
        pos += 1;

        auto add_group_matcher {[&, _1 = std::move(start), _2 = (&pos)](cpp2::in<std::string> name) mutable -> bool{

            int group_id {0}; 
            if (string_to_int(name, group_id)) {
                if (cpp2::cmp_less(group_id,0)) {
                    group_id = next_group_id + group_id;

                    if (cpp2::cmp_less(group_id,1)) {// Negative and zero are no valid groups.
                        error(("Relative group reference does not reference a valid group. (Would be " + cpp2::to_string(group_id) + ".)"));
                        return false; 
                    }
                }

                if (cpp2::cmp_greater_eq(group_id,next_group_id)) {error("Group reference is used before the group is declared."); return false; }
            }
            else {
                // Named group
                auto iter {CPP2_UFCS(find)(named_groups, name)}; 
                if (iter == CPP2_UFCS(end)(named_groups)) {error(("Group names does not exist. (Name is: " + cpp2::to_string(name) + ")")); return false; }

                group_id = (*cpp2::assert_not_null(std::move(iter))).second;
            }
            CPP2_UFCS(add)(cur_state, create_matcher("group_ref_matcher_logic", (cpp2::to_string(std::move(group_id)) + ", \"\\" + cpp2::to_string(CPP2_UFCS(substr)(regex, _1, *cpp2::assert_not_null(_2) - _1 + 1)) + "\"")));

            return true; 
        }}; 

        if (cpp2::cmp_greater_eq(pos,CPP2_UFCS(size)(regex))) {error("Escape without a following character."); return false; }

        char c_next {CPP2_ASSERT_IN_BOUNDS(regex, pos)}; 

        if ([_0 = '1', _1 = c_next, _2 = '9']{ return cpp2::cmp_less_eq(_0,_1) && cpp2::cmp_less_eq(_1,_2); }()) {
            if (!(add_group_matcher(std::string(1, c_next)))) {return false; }
        }
        else {if (std::string::npos != CPP2_UFCS(find)(std::string("^.[]$()*{}?+|"), c_next)) {
            if (c_next == '$') {
                // TODO: Provide proper escape for cppfront capture
                CPP2_UFCS(add)(cur_state, create_matcher("line_end_matcher_logic", "true, false"));
            }
            else {
                CPP2_UFCS(add)(cur_state, create_matcher("escaped_char_matcher_logic", ("'" + cpp2::to_string(c_next) + "'")));
            }
        }
        else {if ('\\' == c_next) {
            CPP2_UFCS(add)(cur_state, create_matcher("escaped_char_matcher_logic", "'\\\\'"));
        }
        else {if ('g' == c_next) {
            if (!(next(cpp2::out(&c_next)))) {error("Group escape without a following char."); return false; }

            std::string group {""}; 
            if (c_next == '{') {
                if (!((next(cpp2::out(&c_next)) && grab_until('}', cpp2::out(&group))))) {error("No ending bracket."); return false; }
            }
            else {
                group = grab_number();
            }
            if (!(add_group_matcher(std::move(group)))) {return false; }
        }
        else {if ('k' == c_next) {
            if (!(next(cpp2::out(&c_next)))) {error("Group escape without a following char."); return false; }

            auto term_char {'\0'}; 
            if (c_next == '{') {term_char = '}'; }
            else {if (c_next == '<') {term_char = '>'; }
            else {if (c_next == '\'') {term_char = '\''; }
            else {
                error("Group escape has wrong operator."); return false; 
            }}}

            std::string group {""}; 
            if (!((next(cpp2::out(&c_next)) && grab_until(std::move(term_char), cpp2::out(&group))))) {error("No ending bracket."); return false; }
            if (!(std::move(add_group_matcher)(std::move(group)))) {return false; }
        }
        else {if ('N' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("named_class_no_new_line", "")); }
        else {if ('s' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("named_class_white_space", "")); }
        else {if ('S' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("named_class_not_white_space", "")); }
        else {if ('w' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("named_class_word", "")); }
        else {if ('W' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("named_class_not_word", "")); }
        else {if ('d' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("named_class_digits", "")); }
        else {if ('D' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("named_class_not_digits", "")); }
        else {if ('Z' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("named_string_end_or_before_new_line_at_end", "")); }
        else {if ('z' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("named_string_end", "")); }
        else {if ('A' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("named_string_start", "")); }
        else {if ('b' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("word_boundary_matcher_logic", "false")); }
        else {if ('B' == std::move(c_next)) {CPP2_UFCS(add)(cur_state, create_matcher("word_boundary_matcher_logic", "true")); }
        else {
            error("Unknown escape.");
            return false; 
        }}}}}}}}}}}}}}}}}

        return true; 
    }

#line 1160 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_group(cpp2::in<char> c) & -> bool{
        if (c != '(') {return false; }

        auto group_number {next_group_id}; 
        next_group_id += 1;

        auto old_state {new_state()}; 

        auto start_matcher {create_matcher("group_matcher_start_logic", (cpp2::to_string(group_number) + ", \"\""))}; 

        char c_next {'\0'}; 
        // Skip the '('
        if (!(next(cpp2::out(&c_next)))) {error("Group without closing bracket."); return false; }
        if (c_next == '?') {
            // Named group
            if (!((next(cpp2::out(&c_next)) && c_next == '<'))) {error("Missing opening bracket for named group."); return false; }
            std::string name {""}; 
            if (!(grab_until('>', cpp2::out(&name)))) {error("Missing ending bracket for named group."); return false; }
            if (!(next(cpp2::out(&c_next)))) {error("Group without closing bracket."); return false; }

            if (!(CPP2_UFCS(contains)(named_groups, name))) {// Redefinition of group name is not an error. The left most one is retained.
                CPP2_ASSERT_IN_BOUNDS(named_groups, name) = group_number;
            }
            start_matcher = create_matcher("group_matcher_start_logic", (cpp2::to_string(group_number) + ", \"" + cpp2::to_string(std::move(name)) + "\""));
        }

        parse_until(')');

        auto inner {create_matcher_from_state()}; 
        restore_state(std::move(old_state));

        std::vector<std::string> v {
            std::move(start_matcher), 
            std::move(inner), 
            create_matcher("group_matcher_end_logic", (cpp2::to_string(std::move(group_number))))}; 
        CPP2_UFCS(add)(cur_state, create_matcher_from_list(std::move(v)));

        return true; 
    }

#line 1200 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_handle_special(cpp2::in<char> c) & -> bool{
        if (c == '\'') {
            CPP2_UFCS(add)(cur_state, create_matcher("char_matcher_logic", ("'\\" + cpp2::to_string(c) + "'")));
            return true; 
        }

        return false; 
    }

#line 1209 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_range(cpp2::in<char> c) & -> bool{

        auto to_int {[&](auto const& str) mutable -> int{
            // TODO: Add exception handling.
            // try {
                return std::stoi(str); 
            // } catch (_) {
            //     error("Could not convert range argument '(inner)$' to int.");
            // }
            // return 0;
        }}; 

        if (c != '{') {return false; }
        if (CPP2_UFCS(empty)(cur_state)) {error("'{' without previous element.");return false; }

        size_t end {CPP2_UFCS(find)(regex, "}", pos)}; 
        if (end == std::string::npos) {error("Missing closing bracket."); return false; }

        std::string inner {trim_copy(CPP2_UFCS(substr)(regex, pos + 1, end - pos - 1))}; 
        if (CPP2_UFCS(empty)(inner)) {error("Empty range specifier. Either '{n}', '{n,}', '{,m}' '{n,m}'"); return false; }

        std::string min_count {"-1"}; 
        int min_count_number {0}; 
        std::string max_count {"-1"}; 
        int max_count_number {std::numeric_limits<int>::max()}; 

        size_t sep {CPP2_UFCS(find)(inner, ",")}; 
        if (sep == std::string::npos) {
            min_count = inner;
            max_count = inner;
            min_count_number = std::move(to_int)(inner);
            max_count_number = min_count_number;
        }
        else {
            std::string inner_first {trim_copy(CPP2_UFCS(substr)(inner, 0, sep))}; 
            std::string inner_last {trim_copy(CPP2_UFCS(substr)(inner, std::move(sep) + 1))}; 

            if ((CPP2_UFCS(empty)(inner_first) && CPP2_UFCS(empty)(inner_last))) {
                error("Empty range specifier. Either '{n}', '{n,}', '{,m}' '{n,m}'");
                return false; 
            }

            if (!(CPP2_UFCS(empty)(inner_first))) {
                min_count = inner_first;
                min_count_number = to_int(std::move(inner_first));
            }
            if (!(CPP2_UFCS(empty)(inner_last))) {
                max_count = inner_last;
                max_count_number = std::move(to_int)(std::move(inner_last));
            }
        }

        if (!(([_0 = 0, _1 = min_count_number, _2 = max_count_number]{ return cpp2::cmp_less_eq(_0,_1) && cpp2::cmp_less_eq(_1,_2); }()))) {
            error(("Min and max values in range are wrong it should hold 0 <= min <= max. Have 0 <= " + cpp2::to_string(std::move(min_count_number)) + " <= " + cpp2::to_string(std::move(max_count_number))));
            return false; 
        }

        CPP2_UFCS(wrap_last)(cur_state, [&, _1 = std::move(min_count), _2 = std::move(max_count)](auto const& inner) -> auto { return create_matcher("range_matcher_logic", (cpp2::to_string(std::move(inner)) + ", " + cpp2::to_string(_1) + ", " + cpp2::to_string(_2)));  });
        pos = std::move(end);

        return true; 
    }

#line 1272 "regex.h2"
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
            return false; 
        }

        CPP2_UFCS(wrap_last)(cur_state, [&, _1 = std::move(min_range), _2 = std::move(max_range), _3 = c](auto const& inner) -> auto { return create_matcher("special_range_matcher_logic", (cpp2::to_string(inner) + ", " + cpp2::to_string(_1) + ", " + cpp2::to_string(_2) + ", '" + cpp2::to_string(_3) + "'"));  });
        return true; 
    }

#line 1298 "regex.h2"
    template <typename Error_out> auto regex_parser<Error_out>::parse_until(cpp2::in<char> term) & -> void{
        for( ; pos != CPP2_UFCS(size)(regex); pos += 1 ) {
            char c {CPP2_ASSERT_IN_BOUNDS(regex, pos)}; 

            if (c == term) {return ; }

            if (!(has_error) && is_alternative(c)) {continue; }
            if (!(has_error) && is_any(c)) {continue; }
            if (!(has_error) && is_class(c)) {continue; }
            if (!(has_error) && is_escape(c)) {continue; }
            if (!(has_error) && is_anchor(c)) {continue; }
            if (!(has_error) && is_group(c)) {continue; }
            if (!(has_error) && is_handle_special(c)) {continue; }
            if (!(has_error) && is_range(c)) {continue; }
            if (!(has_error) && is_special_range(c)) {continue; }

            if (has_error) {return ; }

            // No special char, push a character match
            CPP2_UFCS(add)(cur_state, create_matcher("char_matcher_logic", ("'" + cpp2::to_string(c) + "'")));
        }
    }

#line 1321 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::parse() & -> std::string{
        parse_until('\0');

        if (has_error) {return "Error"; }

        auto inner {create_matcher_from_state()}; 
        auto start {create_matcher("group_matcher_start_logic", "0, \"\"")}; 
        auto end {create_matcher("group_matcher_end_logic", "0")}; 
        auto list {create_matcher("matcher_list", (cpp2::to_string(std::move(start)) + ", " + cpp2::to_string(std::move(inner)) + ", " + cpp2::to_string(std::move(end))))}; 
        return   create_matcher("regular_expression", (cpp2::to_string(next_group_id) + ", " + cpp2::to_string(alternatives_count) + ", " + cpp2::to_string(std::move(list)))); 
    }

#line 1335 "regex.h2"
template<typename Err> [[nodiscard]] auto generate_template(cpp2::in<std::string_view> regex, Err const& err) -> std::string{
    regex_parser<Err> parser {regex, err}; 
    auto r {CPP2_UFCS(parse)(parser)}; 
    static_cast<void>(std::move(parser));
    return r; 
}

}
}

#endif
