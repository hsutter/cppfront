
#ifndef ___INCLUDE_CPP2REGEX_H_CPP2
#define ___INCLUDE_CPP2REGEX_H_CPP2


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "regex.h2"

#line 15 "regex.h2"
namespace cpp2 {

namespace regex {

#line 31 "regex.h2"
class expression_flags;

#line 40 "regex.h2"
template<typename Iter> class match_group;
    

#line 47 "regex.h2"
template<typename Iter> class match_return;
    

#line 52 "regex.h2"
template<typename CharT, typename Iter, int max_groups, int max_alternatives> class match_context;

#line 130 "regex.h2"
template<bool has_change_, bool reset_, int add_, int remove_, fixed_string str> class match_modifiers_state_change;

#line 153 "regex.h2"
template<int flags_, typename Inner> class match_modifiers;

#line 176 "regex.h2"
template<typename CharT, typename ...List> class matcher_list;
    

#line 203 "regex.h2"
template<typename CharT, CharT C> class single_class_entry;

#line 211 "regex.h2"
template<typename CharT, CharT Start, CharT End> class range_class_entry;

#line 219 "regex.h2"
template<typename CharT, typename ...List> class combined_class_entry;
    

#line 226 "regex.h2"
template<typename CharT, CharT ...List> class list_class_entry;
    

#line 233 "regex.h2"
template<typename CharT, fixed_string Name, typename Inner> class named_class_entry;
    

#line 238 "regex.h2"
template<typename CharT, typename Inner> class negated_class_entry;
    

#line 245 "regex.h2"
template<typename CharT, fixed_string Name, typename Inner> class shorthand_class_entry;
    

#line 298 "regex.h2"
template<typename CharT, size_t alternative> class extract_position_helper;
    

#line 315 "regex.h2"
template<typename CharT, size_t alternative, typename ...List> class alternative_matcher_logic;

#line 399 "regex.h2"
template<typename CharT> class any_matcher_logic;

#line 418 "regex.h2"
template<typename CharT> class branch_reset_matcher_logic;
    

#line 426 "regex.h2"
template<typename CharT, CharT C, CharT L, CharT U> class char_matcher_logic;

#line 454 "regex.h2"
template<typename CharT, bool negate, typename ...List> class class_matcher_logic;

#line 503 "regex.h2"
template<typename CharT> class empty_matcher_logic;
    

#line 511 "regex.h2"
template<typename CharT, CharT C, CharT L, CharT U> class escaped_char_matcher_logic;

#line 520 "regex.h2"
template<typename CharT> class global_group_reset;
    

#line 532 "regex.h2"
template<typename CharT, int group, typename ModifierChange, fixed_string name, bool name_brackets> class group_matcher_start_logic;
    

#line 565 "regex.h2"
template<typename CharT, int group> class group_matcher_end_logic;
    

#line 589 "regex.h2"
template<typename CharT> class special_group_end_logic;
    

#line 597 "regex.h2"
template<typename CharT, int group, fixed_string symbol> class group_ref_matcher_logic;
    

#line 630 "regex.h2"
template<typename CharT, bool match_new_line, bool match_new_line_before_end> class line_end_matcher_logic;

#line 650 "regex.h2"
template<typename CharT, bool match_new_line> class line_start_matcher_logic;

#line 667 "regex.h2"
template<typename CharT, typename ModifierChange> class modifier_matcher_logic;

#line 679 "regex.h2"
template<typename CharT, fixed_string Name, typename Base> class named_matcher_logic;
    

#line 683 "regex.h2"
template                   <typename CharT, fixed_string Name, bool negate, typename ...List> class named_class_matcher_logic;
    

#line 709 "regex.h2"
template<typename CharT, typename M, int min_count, int max_count, bool greedy, bool possessive> class range_matcher_logic;

#line 837 "regex.h2"
template<typename CharT, typename M, int min_count, int max_count, bool greedy, bool possessive, char symbol> class special_range_matcher_logic;
    

#line 856 "regex.h2"
template<typename CharT, bool negate> class word_boundary_matcher_logic;

#line 907 "regex.h2"
template<fixed_string Name, int group_id, typename Inner> class group_name_list;

#line 919 "regex.h2"
class group_name_list_end;
    

#line 924 "regex.h2"
template<typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> class regular_expression;

#line 1008 "regex.h2"
class regex_parser_modifier_state;
    

#line 1014 "regex.h2"
class regex_parser_state;

#line 1048 "regex.h2"
class regex_branch_reset_state;
    

#line 1075 "regex.h2"
template<typename Error_out> class regex_parser;

#line 1959 "regex.h2"
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

class expression_flags {
    public: static const int case_insensitive;// mod: i
    public: static const int multiple_lines;  // mod: m
    public: static const int single_line;     // mod: s
    public: static const int no_group_captures;// mod: n
    public: static const int perl_code_syntax;// mod: x
    public: static const int perl_code_syntax_in_classes;// mod: xx

    public: expression_flags() = default;
    public: expression_flags(expression_flags const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(expression_flags const&) -> void = delete;
};
#line 39 "regex.h2"

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

#line 65 "regex.h2"
    public: match_context(match_context const& that);
#line 65 "regex.h2"
    public: auto operator=(match_context const& that) -> match_context& ;
#line 65 "regex.h2"
    public: match_context(match_context&& that) noexcept;
#line 65 "regex.h2"
    public: auto operator=(match_context&& that) noexcept -> match_context& ;

    // Getter and setter for groups
    //
    public: [[nodiscard]] auto get_group(auto const& group) const& -> auto;

    public: [[nodiscard]] auto get_group_string(auto const& group) const& -> std::string;

#line 77 "regex.h2"
    public: [[nodiscard]] auto get_group_start(auto const& group) const& -> int;

#line 83 "regex.h2"
    public: [[nodiscard]] auto get_group_end(auto const& group) const& -> int;

#line 90 "regex.h2"
    public: auto set_group_end(auto const& group, auto const& pos) & -> void;

#line 95 "regex.h2"
    public: auto set_group_invalid(auto const& group) & -> void;

#line 99 "regex.h2"
    public: auto set_group_start(auto const& group, auto const& pos) & -> void;

#line 103 "regex.h2"
    public: [[nodiscard]] auto size() const& -> auto;

    // Getter and setter for alternatives

    public: [[nodiscard]] auto get_alternative_pos(auto const& alternative) const& -> auto;

    public: auto set_alternative_pos(auto const& alternative, auto const& pos) & -> void;

#line 113 "regex.h2"
    // Misc functions
    //
    public: [[nodiscard]] auto print_ranges() const& -> bstring<CharT>;

#line 128 "regex.h2"
};

template<bool has_change_, bool reset_, int add_, int remove_, fixed_string str> class match_modifiers_state_change {

    public: static const bool reset;
    public: static const int add;
    public: static const int remove;
    public: static const bool has_change;

    public: [[nodiscard]] constexpr static auto combine_inner(cpp2::in<int> old_flags) -> auto;

#line 148 "regex.h2"
    public: [[nodiscard]] static auto to_string() -> auto;
    public: match_modifiers_state_change() = default;
    public: match_modifiers_state_change(match_modifiers_state_change const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(match_modifiers_state_change const&) -> void = delete;

#line 149 "regex.h2"
};

using match_modifiers_no_change = match_modifiers_state_change<false,false,0,0,"">;

template<int flags_, typename Inner> class match_modifiers {

    public: static const int flags;

    // Push/pop management

    public: template<typename Change> [[nodiscard]] static auto push([[maybe_unused]] Change const& unnamed_param_1) -> auto;
    public: [[nodiscard]] static auto pop() -> auto;
    public: template<typename Change> [[nodiscard]] static auto replace([[maybe_unused]] Change const& unnamed_param_1) -> auto;

    // Flag management
    //

    public: [[nodiscard]] auto has_flag(cpp2::in<int> f) const& -> bool;
    public: match_modifiers() = default;
    public: match_modifiers(match_modifiers const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(match_modifiers const&) -> void = delete;


#line 169 "regex.h2"
};

//  Represents the remainder of the regular expression.
//
//  A matcher can ask this remainder if it would match. If yes a full match of the regular expression is found.
//  Otherwise the matcher can try a different alternative.
//
template<typename CharT, typename ...List> class matcher_list {
    public: [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers) -> auto;

    public: template<typename ...OtherList> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] matcher_list<CharT,OtherList...> const& unnamed_param_4) -> auto;

#line 182 "regex.h2"
    private: template<typename First, typename ...Other> [[nodiscard]] static auto match_select(auto const& cur, auto& ctx, auto const& modifiers) -> auto;

    private: [[nodiscard]] static auto match_select(auto const& cur, auto& ctx, auto const& modifiers) -> auto;

    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;

    public: template<typename Pre> [[nodiscard]] static auto prepend([[maybe_unused]] Pre const& unnamed_param_1) -> auto;
    public: matcher_list() = default;
    public: matcher_list(matcher_list const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(matcher_list const&) -> void = delete;

#line 190 "regex.h2"
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

#line 207 "regex.h2"
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

#line 215 "regex.h2"
};

// Helper for combining two character classes
//
template<typename CharT, typename ...List> class combined_class_entry {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: combined_class_entry() = default;
    public: combined_class_entry(combined_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(combined_class_entry const&) -> void = delete;

#line 222 "regex.h2"
};

// Class syntax: <list of characters>  Example: abcd
//
template<typename CharT, CharT ...List> class list_class_entry {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: list_class_entry() = default;
    public: list_class_entry(list_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(list_class_entry const&) -> void = delete;

#line 229 "regex.h2"
};

// Class syntax: [:<class name:]  Example: [:alnum:]
//
template<typename CharT, fixed_string Name, typename Inner> class named_class_entry {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: named_class_entry() = default;
    public: named_class_entry(named_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(named_class_entry const&) -> void = delete;

#line 236 "regex.h2"
};

template<typename CharT, typename Inner> class negated_class_entry: public Inner {

    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: negated_class_entry() = default;
    public: negated_class_entry(negated_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(negated_class_entry const&) -> void = delete;

#line 241 "regex.h2"
};

// Short class syntax: \<character>  Example: \w
//
template<typename CharT, fixed_string Name, typename Inner> class shorthand_class_entry {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: shorthand_class_entry() = default;
    public: shorthand_class_entry(shorthand_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(shorthand_class_entry const&) -> void = delete;

#line 248 "regex.h2"
};

#line 251 "regex.h2"
// Named basic character classes
//
template        <typename CharT> using digits_class = named_class_entry<CharT,"digits",range_class_entry<CharT,'0','9'>>;
template        <typename CharT> using lower_class = named_class_entry<CharT,"lower",range_class_entry<CharT,'a','z'>>;
template        <typename CharT> using upper_class = named_class_entry<CharT,"upper",range_class_entry<CharT,'A','Z'>>;

// Named other classes
//
template          <typename CharT> using alnum_class = named_class_entry<CharT,"alnum",combined_class_entry<CharT,lower_class<CharT>,upper_class<CharT>,digits_class<CharT>>>;
template          <typename CharT> using alpha_class = named_class_entry<CharT,"alpha",combined_class_entry<CharT,lower_class<CharT>,upper_class<CharT>>>;
template          <typename CharT> using ascii_class = named_class_entry<CharT,"ascii",range_class_entry<CharT,'\x00','\x7F'>>;
template          <typename CharT> using blank_class = named_class_entry<CharT,"blank",list_class_entry<CharT,' ','\t'>>;
template          <typename CharT> using cntrl_class = named_class_entry<CharT,"cntrl",combined_class_entry<CharT,range_class_entry<CharT,'\x00','\x1F'>,single_class_entry<CharT,'\x7F'>>>;
template          <typename CharT> using graph_class = named_class_entry<CharT,"graph",range_class_entry<CharT,'\x21','\x7E'>>;
template<typename CharT> using hor_space_class = named_class_entry<CharT,"hspace",list_class_entry<CharT,'\t',' '>>;
template          <typename CharT> using print_class = named_class_entry<CharT,"print",range_class_entry<CharT,'\x20','\x7E'>>;
template          <typename CharT> using punct_class = named_class_entry<CharT,"punct",list_class_entry<CharT,'[','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/',':',';','<','=','>','?','@','[','\\',']','^','_','`','{','|','}','~',']'>>;
template          <typename CharT> using space_class = named_class_entry<CharT,"space",list_class_entry<CharT,' ','\t','\r','\n','\v','\f'>>;
template<typename CharT> using ver_space_class = named_class_entry<CharT,"vspace",list_class_entry<CharT,'\n','\v','\f','\r'>>;
template          <typename CharT> using word_class = named_class_entry<CharT,"word",combined_class_entry<CharT,alnum_class<CharT>,single_class_entry<CharT,'_'>>>;
template          <typename CharT> using xdigit_class = named_class_entry<CharT,"xdigit",combined_class_entry<CharT,range_class_entry<CharT,'A','F'>,range_class_entry<CharT,'a','f'>,digits_class<CharT>>>;

// Shorthand class entries
//
template                 <typename CharT> using short_digits_class = shorthand_class_entry<CharT,"\\d",digits_class<CharT>>;
template                 <typename CharT> using short_hor_space_class = shorthand_class_entry<CharT,"\\h",hor_space_class<CharT>>;
template                 <typename CharT> using short_space_class = shorthand_class_entry<CharT,"\\s",space_class<CharT>>;
template<typename CharT> using short_vert_space_class = shorthand_class_entry<CharT,"\\v",ver_space_class<CharT>>;
template                 <typename CharT> using short_word_class = shorthand_class_entry<CharT,"\\w",word_class<CharT>>;

#line 282 "regex.h2"
template                     <typename CharT> using short_not_digits_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\D",digits_class<CharT>>>;
template                     <typename CharT> using short_not_hor_space_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\H",hor_space_class<CharT>>>;
template                     <typename CharT> using short_not_space_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\S",space_class<CharT>>>;
template<typename CharT> using short_not_vert_space_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\V",ver_space_class<CharT>>>;
template                     <typename CharT> using short_not_word_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\W",word_class<CharT>>>;

//-----------------------------------------------------------------------
//
//  Matchers for regular expressions.
//
//-----------------------------------------------------------------------
//

#line 296 "regex.h2"
// Helper for greedy alternatives
//
template<typename CharT, size_t alternative> class extract_position_helper {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto;

#line 307 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: extract_position_helper() = default;
    public: extract_position_helper(extract_position_helper const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(extract_position_helper const&) -> void = delete;

#line 309 "regex.h2"
};

//  Regex syntax: |  Example: ab|ba
//
//  Non greedy implementation. First alternative that matches is chosen. 
//
template<typename CharT, size_t alternative, typename ...List> class alternative_matcher_logic {

    public: template<typename Tail> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, Tail const& tail) -> auto;

#line 329 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;

    private: template<typename First, typename ...Next> [[nodiscard]] static auto match_first(auto const& cur, auto& ctx, auto const& modifiers, auto const& tail) -> auto;

#line 347 "regex.h2"
    private: template<typename Tail, typename First, typename ...Next> [[nodiscard]] static auto match_greedy(auto const& cur, auto& max_overall_length, auto& max_current_length, auto& ctx, auto const& modifiers, [[maybe_unused]] Tail const& unnamed_param_6) -> auto;
    public: alternative_matcher_logic() = default;
    public: alternative_matcher_logic(alternative_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(alternative_matcher_logic const&) -> void = delete;


#line 395 "regex.h2"
};

//  Regex syntax: .
//
template<typename CharT> class any_matcher_logic
 {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto;

#line 412 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: any_matcher_logic() = default;
    public: any_matcher_logic(any_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(any_matcher_logic const&) -> void = delete;

#line 414 "regex.h2"
};

// Regex syntax: none Example: -
//
template<typename CharT> class branch_reset_matcher_logic {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto;
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: branch_reset_matcher_logic() = default;
    public: branch_reset_matcher_logic(branch_reset_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(branch_reset_matcher_logic const&) -> void = delete;

#line 422 "regex.h2"
};

// Regex syntax: <any character>  Example: a
//
template<typename CharT, CharT C, CharT L, CharT U> class char_matcher_logic
 {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto;

#line 447 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: char_matcher_logic() = default;
    public: char_matcher_logic(char_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(char_matcher_logic const&) -> void = delete;

#line 449 "regex.h2"
};

#line 452 "regex.h2"
// Regex syntax: [<character classes>]  Example: [abcx-y[:digits:]]
//
template<typename CharT, bool negate, typename ...List> class class_matcher_logic
 {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto;

#line 475 "regex.h2"
    private: template<typename First, typename ...Other> [[nodiscard]] static auto match_any(cpp2::in<CharT> c) -> bool;

#line 487 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;

    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: class_matcher_logic() = default;
    public: class_matcher_logic(class_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(class_matcher_logic const&) -> void = delete;


#line 499 "regex.h2"
};

// Regex syntax: none Example: -
//
template<typename CharT> class empty_matcher_logic {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto;
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: empty_matcher_logic() = default;
    public: empty_matcher_logic(empty_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(empty_matcher_logic const&) -> void = delete;

#line 507 "regex.h2"
};

// Regex syntax: \<special character>  Example: \.
//
template<typename CharT, CharT C, CharT L, CharT U> class escaped_char_matcher_logic
: public char_matcher_logic<CharT,C,L,U> {

#line 515 "regex.h2"
    public: [[nodiscard]] static auto to_string() -> auto;
    public: escaped_char_matcher_logic() = default;
    public: escaped_char_matcher_logic(escaped_char_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(escaped_char_matcher_logic const&) -> void = delete;

#line 516 "regex.h2"
};

// Regex syntax: \K Example: \K
//
template<typename CharT> class global_group_reset {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto;

#line 526 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: global_group_reset() = default;
    public: global_group_reset(global_group_reset const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(global_group_reset const&) -> void = delete;

#line 528 "regex.h2"
};

// Regex syntax: (<inner>) Example: (.*)
//
template<typename CharT, int group, typename ModifierChange, fixed_string name, bool name_brackets> class group_matcher_start_logic {
    public: template<typename Other, typename Modifiers> [[nodiscard]] static auto match(auto const& cur, auto& ctx, [[maybe_unused]] Modifiers const& unnamed_param_3, [[maybe_unused]] Other const& unnamed_param_4) -> auto;

#line 540 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;

    public: [[nodiscard]] static auto to_string() -> std::string;
    public: group_matcher_start_logic() = default;
    public: group_matcher_start_logic(group_matcher_start_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_matcher_start_logic const&) -> void = delete;


#line 563 "regex.h2"
};

template<typename CharT, int group> class group_matcher_end_logic {
    public: template<typename Other, typename Modifier> [[nodiscard]] static auto match(auto const& cur, auto& ctx, Modifier const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto;

#line 577 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;

    public: [[nodiscard]] static auto to_string() -> auto;
    public: group_matcher_end_logic() = default;
    public: group_matcher_end_logic(group_matcher_end_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_matcher_end_logic const&) -> void = delete;


#line 587 "regex.h2"
};

template<typename CharT> class special_group_end_logic {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto;
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: special_group_end_logic() = default;
    public: special_group_end_logic(special_group_end_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(special_group_end_logic const&) -> void = delete;

#line 593 "regex.h2"
};

// Regex syntax: \<number>  Example: \1
//
template<typename CharT, int group, fixed_string symbol> class group_ref_matcher_logic {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto;

#line 624 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: group_ref_matcher_logic() = default;
    public: group_ref_matcher_logic(group_ref_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_ref_matcher_logic const&) -> void = delete;

#line 626 "regex.h2"
};

// Regex syntax: $  Example: aa$
//
template<typename CharT, bool match_new_line, bool match_new_line_before_end> class line_end_matcher_logic
 {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto;

#line 644 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: line_end_matcher_logic() = default;
    public: line_end_matcher_logic(line_end_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(line_end_matcher_logic const&) -> void = delete;

#line 646 "regex.h2"
};

// Regex syntax: ^  Example: ^aa
//
template<typename CharT, bool match_new_line> class line_start_matcher_logic
 {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto;

#line 661 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: line_start_matcher_logic() = default;
    public: line_start_matcher_logic(line_start_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(line_start_matcher_logic const&) -> void = delete;

#line 663 "regex.h2"
};

// Regex syntax: (?<modifiers>)  Example: (?i)
//
template<typename CharT, typename ModifierChange> class modifier_matcher_logic
 {
    public: template<typename Other, typename Modifier> [[nodiscard]] static auto match(auto const& cur, auto& ctx, [[maybe_unused]] Modifier const& unnamed_param_3, [[maybe_unused]] Other const& unnamed_param_4) -> auto;

#line 672 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: modifier_matcher_logic() = default;
    public: modifier_matcher_logic(modifier_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(modifier_matcher_logic const&) -> void = delete;

#line 674 "regex.h2"
};

// Named character classes
//

template<typename CharT, fixed_string Name, typename Base> class named_matcher_logic: public Base {

    public: [[nodiscard]] static auto to_string() -> auto;
    public: named_matcher_logic() = default;
    public: named_matcher_logic(named_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(named_matcher_logic const&) -> void = delete;

#line 682 "regex.h2"
};
template                   <typename CharT, fixed_string Name, bool negate, typename ...List> class named_class_matcher_logic: public named_matcher_logic<CharT,Name,class_matcher_logic<CharT,negate,List...>> {
    public: named_class_matcher_logic() = default;
    public: named_class_matcher_logic(named_class_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(named_class_matcher_logic const&) -> void = delete;


#line 685 "regex.h2"
};

template<typename CharT> using named_class_no_new_line = named_class_matcher_logic<CharT,"\\\\N",true,single_class_entry<CharT,'\n'>>;// TODO: Remove second \, switch to raw strings.
template                 <typename CharT> using named_class_digits = named_class_matcher_logic<CharT,"\\d",false,digits_class<CharT>>;
template                 <typename CharT> using named_class_hor_space = named_class_matcher_logic<CharT,"\\h",false,hor_space_class<CharT>>;
template                 <typename CharT> using named_class_space = named_class_matcher_logic<CharT,"\\s",false,space_class<CharT>>;
template                 <typename CharT> using named_class_ver_space = named_class_matcher_logic<CharT,"\\v",false,ver_space_class<CharT>>;
template                 <typename CharT> using named_class_word = named_class_matcher_logic<CharT,"\\w",false,word_class<CharT>>;

#line 695 "regex.h2"
template                    <typename CharT> using named_class_not_digits = named_class_matcher_logic<CharT,"\\D",true,digits_class<CharT>>;
template<typename CharT> using named_class_not_hor_space = named_class_matcher_logic<CharT,"\\H",true,hor_space_class<CharT>>;
template                    <typename CharT> using named_class_not_space = named_class_matcher_logic<CharT,"\\S",true,space_class<CharT>>;
template<typename CharT> using named_class_not_ver_space = named_class_matcher_logic<CharT,"\\V",true,ver_space_class<CharT>>;
template                    <typename CharT> using named_class_not_word = named_class_matcher_logic<CharT,"\\W",true,word_class<CharT>>;

// Other named matchers
template<typename CharT> using named_string_end_or_before_new_line_at_end = named_matcher_logic<CharT,"\\Z",line_end_matcher_logic<CharT,false,true>>;
template<typename CharT> using named_string_end = named_matcher_logic<CharT,"\\z",line_end_matcher_logic<CharT,false,false>>;
template<typename CharT> using named_string_start = named_matcher_logic<CharT,"\\A",line_start_matcher_logic<CharT,false>>;

#line 708 "regex.h2"
// Regex syntax: <matcher>{min, max}  Example: a{2,4}
template<typename CharT, typename M, int min_count, int max_count, bool greedy, bool possessive> class range_matcher_logic {

    public: template<typename Iter> [[nodiscard]] static auto match(Iter const& cur, auto& ctx, auto const& modifiers, auto const& tail) -> auto;

#line 720 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;

    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;

#line 748 "regex.h2"
    private: [[nodiscard]] static auto is_below_upper_bound(cpp2::in<int> count) -> bool;

#line 753 "regex.h2"
    private: [[nodiscard]] static auto is_below_lower_bound(cpp2::in<int> count) -> bool;

#line 758 "regex.h2"
    private: [[nodiscard]] static auto is_in_range(cpp2::in<int> count) -> bool;

#line 764 "regex.h2"
    private: template<typename Iter> [[nodiscard]] static auto match_min_count(Iter const& cur, auto& ctx, auto const& modifiers, int& count_r) -> auto;

#line 779 "regex.h2"
    private: template<typename Iter, typename Other> [[nodiscard]] static auto match_greedy(cpp2::in<int> count, Iter const& cur, Iter const& last_valid, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_6) -> match_return<Iter>;

#line 809 "regex.h2"
    private: template<typename Iter, typename Other> [[nodiscard]] static auto match_not_greedy(Iter const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> match_return<Iter>;
    public: range_matcher_logic() = default;
    public: range_matcher_logic(range_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_matcher_logic const&) -> void = delete;


#line 833 "regex.h2"
};

// Regex syntax: *, +, or ?  Example: aa*
//
template<typename CharT, typename M, int min_count, int max_count, bool greedy, bool possessive, char symbol> class special_range_matcher_logic: public range_matcher_logic<CharT,M,min_count,max_count,greedy,possessive> {

    public: [[nodiscard]] static auto to_string() -> auto;
    public: special_range_matcher_logic() = default;
    public: special_range_matcher_logic(special_range_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(special_range_matcher_logic const&) -> void = delete;


#line 850 "regex.h2"
};

// Regex syntax: \b or \B  Example: \bword\b
//
// Matches the start end end of word boundaries.
//
template<typename CharT, bool negate> class word_boundary_matcher_logic
 {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto;

#line 887 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> std::string;
    public: word_boundary_matcher_logic() = default;
    public: word_boundary_matcher_logic(word_boundary_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(word_boundary_matcher_logic const&) -> void = delete;


#line 895 "regex.h2"
};

#line 898 "regex.h2"
//-----------------------------------------------------------------------
//
//  Regular expression implementation.
//
//-----------------------------------------------------------------------
//

// Helper for named groups.

template<fixed_string Name, int group_id, typename Inner> class group_name_list {

    public: [[nodiscard]] static auto get_group_id(auto const& name) -> int;
    public: group_name_list() = default;
    public: group_name_list(group_name_list const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_name_list const&) -> void = delete;


#line 917 "regex.h2"
};

class group_name_list_end {
    public: [[nodiscard]] static auto get_group_id([[maybe_unused]] auto const& unnamed_param_1) -> auto;
    public: group_name_list_end() = default;
    public: group_name_list_end(group_name_list_end const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_name_list_end const&) -> void = delete;

#line 921 "regex.h2"
};

// Regular expression implementation
template<typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> class regular_expression {

    public: template<typename Iter> using context = match_context<CharT,Iter,groups,alternatives>;
    public: using modifiers = match_modifiers<flags,int>;

    private: [[nodiscard]] static auto get_iter(cpp2::in<view<CharT>> str, auto const& pos) -> auto;

#line 938 "regex.h2"
    // TODO: Named multiple return has problems with templates.
    public: template<typename Iter> class search_return {
        public: bool matched; 
        public: context<Iter> ctx; 

        public: explicit search_return(cpp2::in<bool> matched_, context<Iter> const& ctx_);

#line 948 "regex.h2"
        public: [[nodiscard]] auto group_number() const& -> auto;
        public: [[nodiscard]] auto group(cpp2::in<int> g) const& -> auto;
        public: [[nodiscard]] auto group_start(cpp2::in<int> g) const& -> auto;
        public: [[nodiscard]] auto group_end(cpp2::in<int> g) const& -> auto;

        public: [[nodiscard]] auto group(cpp2::in<bstring<CharT>> g) const& -> auto;
        public: [[nodiscard]] auto group_start(cpp2::in<bstring<CharT>> g) const& -> auto;
        public: [[nodiscard]] auto group_end(cpp2::in<bstring<CharT>> g) const& -> auto;

        private: [[nodiscard]] auto get_group_id(cpp2::in<bstring<CharT>> g) const& -> auto;
        public: search_return(search_return const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(search_return const&) -> void = delete;


#line 964 "regex.h2"
    };

    public: [[nodiscard]] auto match(cpp2::in<view<CharT>> str) const& -> auto;
    public: [[nodiscard]] auto match(cpp2::in<view<CharT>> str, auto const& start) const& -> auto;
    public: [[nodiscard]] auto match(cpp2::in<view<CharT>> str, auto const& start, auto const& length) const& -> auto;
    public: template<typename Iter> [[nodiscard]] auto match(Iter const& start, Iter const& end) const& -> search_return<Iter>;

#line 976 "regex.h2"
    public: [[nodiscard]] auto search(cpp2::in<view<CharT>> str) const& -> auto;
    public: [[nodiscard]] auto search(cpp2::in<view<CharT>> str, auto const& start) const& -> auto;
    public: [[nodiscard]] auto search(cpp2::in<view<CharT>> str, auto const& start, auto const& length) const& -> auto;
    public: template<typename Iter> [[nodiscard]] auto search(Iter const& start, Iter const& end) const& -> search_return<Iter>;

#line 998 "regex.h2"
    public: [[nodiscard]] auto to_string() const& -> auto;
    public: regular_expression() = default;
    public: regular_expression(regular_expression const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regular_expression const&) -> void = delete;

#line 999 "regex.h2"
};

//-----------------------------------------------------------------------
//
//  Parser for regular expression.
//
//-----------------------------------------------------------------------
//

class regex_parser_modifier_state {
    public: bool group_captures_have_numbers {true}; 
    public: bool perl_code_syntax {false}; 
    public: bool perl_code_syntax_in_classes {false}; 
};

class regex_parser_state {

    // Current list of matchers
    public: std::vector<std::string> cur_match_list {}; 

    /// List of alternate matcher lists. E.g. ab|cd|xy
    public: std::vector<std::vector<std::string>> alternate_match_lists {}; 

    public: regex_parser_modifier_state modifiers {}; 

    public: auto next_alternative() & -> void;

#line 1030 "regex.h2"
    public: auto swap(regex_parser_state& t) & -> void;

#line 1036 "regex.h2"
    public: auto add(auto const& matcher) & -> void;

    public: auto wrap_last(auto const& matcher) & -> void;

#line 1045 "regex.h2"
    public: [[nodiscard]] auto empty() const& -> bool;
};

class regex_branch_reset_state {
    public: bool is_active {false}; 
    public: int cur_group {1}; // Global capture group.
    public: int max_group {1}; 
    public: int from {1}; 

    public: [[nodiscard]] auto next() & -> int;

#line 1062 "regex.h2"
    public: auto set_next(cpp2::in<int> g) & -> void;

#line 1067 "regex.h2"
    public: auto next_alternative() & -> void;

#line 1072 "regex.h2"
};

#line 1075 "regex.h2"
template<typename Error_out> class regex_parser {

    private: std::string_view regex; 
    private: std::string_view modifier; 
    private: regex_parser_state cur_state {}; 
    private: regex_branch_reset_state cur_branch_reset_state {}; 
    private: size_t pos {0}; 

    private: int alternatives_count {0}; 

    private: std::map<std::string,int> named_groups {}; 

    private: bool has_error {false}; 
    private: Error_out error_out; 

    private: std::vector<std::string> supported_classes {"alnum", "alpha", "ascii", "blank", "cntrl", "digits", "graph", 
                                                   "lower", "print", "punct", "space", "upper", "word", "xdigit"}; 

    public: explicit regex_parser(cpp2::in<std::string_view> r, cpp2::in<std::string_view> m, Error_out const& e);

#line 1099 "regex.h2"
    // State management functions
    //
    public: [[nodiscard]] auto new_state() & -> regex_parser_state;

#line 1108 "regex.h2"
    public: auto restore_state(cpp2::in<regex_parser_state> old_state) & -> void;

#line 1112 "regex.h2"
    // Branch reset management functions
    //

    public: [[nodiscard]] auto group_new_state() & -> regex_branch_reset_state;

#line 1127 "regex.h2"
    public: auto group_restore_state(cpp2::in<regex_branch_reset_state> old_state) & -> void;

#line 1133 "regex.h2"
    // Position management functions
    //

    private: [[nodiscard]] auto get_next_position(cpp2::in<bool> in_class, cpp2::in<bool> no_skip) const& -> size_t;

#line 1174 "regex.h2"
    private: [[nodiscard]] auto next_impl(cpp2::out<char> n, cpp2::in<bool> in_class, cpp2::in<bool> no_skip) & -> bool;

#line 1186 "regex.h2"
    public: [[nodiscard]] auto next(cpp2::out<char> n) & -> auto;
    public: [[nodiscard]] auto next_in_class(cpp2::out<char> n) & -> auto;
    public: [[nodiscard]] auto next_no_skip(cpp2::out<char> n) & -> auto;

#line 1192 "regex.h2"
    public: [[nodiscard]] auto skip() & -> bool;

#line 1199 "regex.h2"
    public: [[nodiscard]] auto skip_n(cpp2::in<int> n) & -> bool;

#line 1208 "regex.h2"
    public: [[nodiscard]] auto current() const& -> char;

#line 1216 "regex.h2"
    private: [[nodiscard]] auto peek_impl(cpp2::in<bool> in_class) const& -> char;

#line 1226 "regex.h2"
    public: [[nodiscard]] auto peek() const& -> auto;
    public: [[nodiscard]] auto peek_in_class() const& -> auto;

    private: [[nodiscard]] auto grab_until_impl(cpp2::in<std::string> e, cpp2::out<std::string> r, cpp2::in<bool> any) & -> bool;

#line 1250 "regex.h2"
    public: [[nodiscard]] auto grab_until(cpp2::in<std::string> e, cpp2::out<std::string> r) & -> auto;
    public: [[nodiscard]] auto grab_until(cpp2::in<char> e, cpp2::out<std::string> r) & -> auto;
    public: [[nodiscard]] auto grab_until_one_of(cpp2::in<std::string> e, cpp2::out<std::string> r) & -> auto;

    public: [[nodiscard]] auto grab_number() & -> std::string;

#line 1274 "regex.h2"
    // Misc functions
    //
    public: auto error(cpp2::in<std::string> message) & -> void;

#line 1281 "regex.h2"
    public: [[nodiscard]] auto create_matcher(cpp2::in<std::string> name, cpp2::in<std::string> template_arguments) const& -> auto;

#line 1288 "regex.h2"
    public: [[nodiscard]] auto create_matcher_from_list(auto const& list) & -> auto;

    public: [[nodiscard]] auto create_matcher_from_state() & -> std::string;

#line 1312 "regex.h2"
    public: [[nodiscard]] auto create_named_groups_arg() const& -> std::string;

#line 1322 "regex.h2"
    public: [[nodiscard]] static auto join(cpp2::in<std::vector<std::string>> list) -> std::string;

#line 1334 "regex.h2"
    public: [[nodiscard]] auto parse_modifiers(cpp2::in<std::string> change_str, cpp2::out<std::string> modifier_change, 
                      regex_parser_modifier_state& parser_modifiers) & -> bool;

#line 1399 "regex.h2"
    // Parsing functions
    //

    public: [[nodiscard]] auto is_alternative(cpp2::in<char> c) & -> bool;

#line 1410 "regex.h2"
    public: [[nodiscard]] auto is_anchor(cpp2::in<char> c) & -> bool;

#line 1423 "regex.h2"
    public: [[nodiscard]] auto is_any(cpp2::in<char> c) & -> bool;

#line 1431 "regex.h2"
    public: [[nodiscard]] auto is_class(cpp2::in<char> c) & -> bool;

#line 1538 "regex.h2"
    public: [[nodiscard]] auto is_escape(cpp2::in<char> c) & -> bool;

#line 1647 "regex.h2"
    public: [[nodiscard]] auto is_group(cpp2::in<char> c) & -> bool;

#line 1758 "regex.h2"
    public: [[nodiscard]] auto is_handle_special(cpp2::in<char> c) & -> bool;

#line 1767 "regex.h2"
    public: [[nodiscard]] auto is_range(cpp2::in<char> c) & -> bool;

#line 1841 "regex.h2"
    public: [[nodiscard]] auto is_special_range(cpp2::in<char> c) & -> bool;

#line 1878 "regex.h2"
    public: auto parse_until(cpp2::in<char> term) & -> void;

#line 1900 "regex.h2"
    public: [[nodiscard]] auto parse_modifier() & -> std::string;

#line 1936 "regex.h2"
    public: [[nodiscard]] auto parse() & -> std::string;
    public: regex_parser(regex_parser const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_parser const&) -> void = delete;


#line 1950 "regex.h2"
};

template<typename Err> [[nodiscard]] auto generate_template(cpp2::in<std::string_view> regex, cpp2::in<std::string_view> modifier, Err const& err) -> std::string;

#line 1959 "regex.h2"
}
}


//=== Cpp2 function definitions =================================================

#line 1 "regex.h2"

#line 15 "regex.h2"
namespace cpp2 {

namespace regex {

#line 32 "regex.h2"
    inline CPP2_CONSTEXPR int expression_flags::case_insensitive = 1;
    inline CPP2_CONSTEXPR int expression_flags::multiple_lines = 2;
    inline CPP2_CONSTEXPR int expression_flags::single_line = 4;
    inline CPP2_CONSTEXPR int expression_flags::no_group_captures = 8;
    inline CPP2_CONSTEXPR int expression_flags::perl_code_syntax = 16;
    inline CPP2_CONSTEXPR int expression_flags::perl_code_syntax_in_classes = 32;

#line 60 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> match_context<CharT,Iter,max_groups,max_alternatives>::match_context(Iter const& begin_, Iter const& end_)
        : begin{ begin_ }
        , end{ end_ }{

#line 63 "regex.h2"
    }

#line 65 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> match_context<CharT,Iter,max_groups,max_alternatives>::match_context(match_context const& that)
                                   : begin{ that.begin }
                                   , end{ that.end }
                                   , groups{ that.groups }
                                   , alternatives_pos{ that.alternatives_pos }{}
#line 65 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> auto match_context<CharT,Iter,max_groups,max_alternatives>::operator=(match_context const& that) -> match_context& {
                                   begin = that.begin;
                                   end = that.end;
                                   groups = that.groups;
                                   alternatives_pos = that.alternatives_pos;
                                   return *this; }
#line 65 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> match_context<CharT,Iter,max_groups,max_alternatives>::match_context(match_context&& that) noexcept
                                   : begin{ std::move(that).begin }
                                   , end{ std::move(that).end }
                                   , groups{ std::move(that).groups }
                                   , alternatives_pos{ std::move(that).alternatives_pos }{}
#line 65 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> auto match_context<CharT,Iter,max_groups,max_alternatives>::operator=(match_context&& that) noexcept -> match_context& {
                                   begin = std::move(that).begin;
                                   end = std::move(that).end;
                                   groups = std::move(that).groups;
                                   alternatives_pos = std::move(that).alternatives_pos;
                                   return *this; }

#line 69 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::get_group(auto const& group) const& -> auto { return CPP2_ASSERT_IN_BOUNDS(groups, group);  }

#line 71 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::get_group_string(auto const& group) const& -> std::string{
        if (cpp2::cmp_greater_eq(group,max_groups) || !(CPP2_ASSERT_IN_BOUNDS(groups, group).matched)) {
            return ""; 
        }
        return std::string(CPP2_ASSERT_IN_BOUNDS(groups, group).start, CPP2_ASSERT_IN_BOUNDS(groups, group).end); 
    }
#line 77 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::get_group_start(auto const& group) const& -> int{
        if (cpp2::cmp_greater_eq(group,max_groups) || !(CPP2_ASSERT_IN_BOUNDS(groups, group).matched)) {
            return 0; 
        }
        return std::distance(begin, CPP2_ASSERT_IN_BOUNDS(groups, group).start); 
    }
#line 83 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::get_group_end(auto const& group) const& -> int{
        if (cpp2::cmp_greater_eq(group,max_groups) || !(CPP2_ASSERT_IN_BOUNDS(groups, group).matched)) {
            return 0; 
        }
        return std::distance(begin, CPP2_ASSERT_IN_BOUNDS(groups, group).end); 
    }

#line 90 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> auto match_context<CharT,Iter,max_groups,max_alternatives>::set_group_end(auto const& group, auto const& pos) & -> void{
        CPP2_ASSERT_IN_BOUNDS(groups, group).end = pos;
        CPP2_ASSERT_IN_BOUNDS(groups, group).matched = true;
    }

#line 95 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> auto match_context<CharT,Iter,max_groups,max_alternatives>::set_group_invalid(auto const& group) & -> void{
        CPP2_ASSERT_IN_BOUNDS(groups, group).matched = false;
    }

#line 99 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> auto match_context<CharT,Iter,max_groups,max_alternatives>::set_group_start(auto const& group, auto const& pos) & -> void{
        CPP2_ASSERT_IN_BOUNDS(groups, group).start = pos;
    }

#line 103 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::size() const& -> auto { return max_groups;  }

#line 107 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::get_alternative_pos(auto const& alternative) const& -> auto { return CPP2_ASSERT_IN_BOUNDS(alternatives_pos, alternative);  }

#line 109 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> auto match_context<CharT,Iter,max_groups,max_alternatives>::set_alternative_pos(auto const& alternative, auto const& pos) & -> void{
        CPP2_ASSERT_IN_BOUNDS(alternatives_pos, alternative) = pos;
    }

#line 115 "regex.h2"
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

#line 132 "regex.h2"
    template <bool has_change_, bool reset_, int add_, int remove_, fixed_string str> inline CPP2_CONSTEXPR bool match_modifiers_state_change<has_change_,reset_,add_,remove_,str>::reset = reset_;
    template <bool has_change_, bool reset_, int add_, int remove_, fixed_string str> inline CPP2_CONSTEXPR int match_modifiers_state_change<has_change_,reset_,add_,remove_,str>::add = add_;
    template <bool has_change_, bool reset_, int add_, int remove_, fixed_string str> inline CPP2_CONSTEXPR int match_modifiers_state_change<has_change_,reset_,add_,remove_,str>::remove = remove_;
    template <bool has_change_, bool reset_, int add_, int remove_, fixed_string str> inline CPP2_CONSTEXPR bool match_modifiers_state_change<has_change_,reset_,add_,remove_,str>::has_change = has_change_;

#line 137 "regex.h2"
    template <bool has_change_, bool reset_, int add_, int remove_, fixed_string str> [[nodiscard]] constexpr auto match_modifiers_state_change<has_change_,reset_,add_,remove_,str>::combine_inner(cpp2::in<int> old_flags) -> auto{
        auto new_flags {old_flags}; 
        if (reset) {
            new_flags = 0;
        }
        new_flags = new_flags | add;
        new_flags = new_flags & (~remove);

        return new_flags; 
    }

#line 148 "regex.h2"
    template <bool has_change_, bool reset_, int add_, int remove_, fixed_string str> [[nodiscard]] auto match_modifiers_state_change<has_change_,reset_,add_,remove_,str>::to_string() -> auto { return CPP2_UFCS(data)(str);  }

#line 155 "regex.h2"
    template <int flags_, typename Inner> inline CPP2_CONSTEXPR int match_modifiers<flags_,Inner>::flags = flags_;

#line 159 "regex.h2"
    template <int flags_, typename Inner> template<typename Change> [[nodiscard]] auto match_modifiers<flags_,Inner>::push([[maybe_unused]] Change const& unnamed_param_1) -> auto { return match_modifiers<Change::combine_inner(flags),match_modifiers<flags,Inner>>(); }
#line 160 "regex.h2"
    template <int flags_, typename Inner> [[nodiscard]] auto match_modifiers<flags_,Inner>::pop() -> auto { return Inner(); }
#line 161 "regex.h2"
    template <int flags_, typename Inner> template<typename Change> [[nodiscard]] auto match_modifiers<flags_,Inner>::replace([[maybe_unused]] Change const& unnamed_param_1) -> auto { return match_modifiers<Change::combine_inner(flags),Inner>();  }

#line 166 "regex.h2"
    template <int flags_, typename Inner> [[nodiscard]] auto match_modifiers<flags_,Inner>::has_flag(cpp2::in<int> f) const& -> bool{
        return  0 != (f & flags); 
    }

#line 177 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto matcher_list<CharT,List...>::match(auto const& cur, auto& ctx, auto const& modifiers) -> auto { return match_select<List...>(cur, ctx, modifiers);  }

#line 179 "regex.h2"
    template <typename CharT, typename ...List> template<typename ...OtherList> [[nodiscard]] auto matcher_list<CharT,List...>::match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] matcher_list<CharT,OtherList...> const& unnamed_param_4) -> auto { 
        return match_select<List...,OtherList...>(cur, ctx, modifiers);  }

#line 182 "regex.h2"
    template <typename CharT, typename ...List> template<typename First, typename ...Other> [[nodiscard]] auto matcher_list<CharT,List...>::match_select(auto const& cur, auto& ctx, auto const& modifiers) -> auto { 
        return First::match(cur, ctx, modifiers, matcher_list<CharT,Other...>());  }
#line 184 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto matcher_list<CharT,List...>::match_select(auto const& cur, auto& ctx, auto const& modifiers) -> auto { return match_return(true, cur);  }

#line 186 "regex.h2"
    template <typename CharT, typename ...List> auto matcher_list<CharT,List...>::reset_ranges(auto& ctx) -> void { (List::reset_ranges(ctx), ...);  }
#line 187 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto matcher_list<CharT,List...>::to_string() -> auto { return (bstring<CharT>() + ... + List::to_string());  }

#line 189 "regex.h2"
    template <typename CharT, typename ...List> template<typename Pre> [[nodiscard]] auto matcher_list<CharT,List...>::prepend([[maybe_unused]] Pre const& unnamed_param_1) -> auto { return matcher_list<CharT,Pre,List...>();  }

#line 205 "regex.h2"
    template <typename CharT, CharT C> [[nodiscard]] auto single_class_entry<CharT,C>::includes(cpp2::in<CharT> c) -> auto { return c == C;  }
#line 206 "regex.h2"
    template <typename CharT, CharT C> [[nodiscard]] auto single_class_entry<CharT,C>::to_string() -> auto { return bstring<CharT>(1, C); }

#line 213 "regex.h2"
    template <typename CharT, CharT Start, CharT End> [[nodiscard]] auto range_class_entry<CharT,Start,End>::includes(cpp2::in<CharT> c) -> auto { return [_0 = Start, _1 = c, _2 = End]{ return cpp2::cmp_less_eq(_0,_1) && cpp2::cmp_less_eq(_1,_2); }();  }
#line 214 "regex.h2"
    template <typename CharT, CharT Start, CharT End> [[nodiscard]] auto range_class_entry<CharT,Start,End>::to_string() -> auto { return cpp2::to_string(Start) + "-" + cpp2::to_string(End); }

#line 220 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto combined_class_entry<CharT,List...>::includes(cpp2::in<CharT> c) -> auto { return (false || ... || List::includes(c));  }
#line 221 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto combined_class_entry<CharT,List...>::to_string() -> auto { return ("" + ... + List::to_string()); }

#line 227 "regex.h2"
    template <typename CharT, CharT ...List> [[nodiscard]] auto list_class_entry<CharT,List...>::includes(cpp2::in<CharT> c) -> auto { return (false || ... || (List == c));  }
#line 228 "regex.h2"
    template <typename CharT, CharT ...List> [[nodiscard]] auto list_class_entry<CharT,List...>::to_string() -> auto { return ("" + ... + List); }

#line 234 "regex.h2"
    template <typename CharT, fixed_string Name, typename Inner> [[nodiscard]] auto named_class_entry<CharT,Name,Inner>::includes(cpp2::in<CharT> c) -> auto { return Inner::includes(c);  }
#line 235 "regex.h2"
    template <typename CharT, fixed_string Name, typename Inner> [[nodiscard]] auto named_class_entry<CharT,Name,Inner>::to_string() -> auto { return "[:" + cpp2::to_string(CPP2_UFCS(data)(Name)) + ":]"; }

#line 240 "regex.h2"
    template <typename CharT, typename Inner> [[nodiscard]] auto negated_class_entry<CharT,Inner>::includes(cpp2::in<CharT> c) -> auto { return !(Inner::includes(c));  }

#line 246 "regex.h2"
    template <typename CharT, fixed_string Name, typename Inner> [[nodiscard]] auto shorthand_class_entry<CharT,Name,Inner>::includes(cpp2::in<CharT> c) -> auto { return Inner::includes(c);  }
#line 247 "regex.h2"
    template <typename CharT, fixed_string Name, typename Inner> [[nodiscard]] auto shorthand_class_entry<CharT,Name,Inner>::to_string() -> auto { return bstring<CharT>(CPP2_UFCS(data)(Name)); }

#line 299 "regex.h2"
    template <typename CharT, size_t alternative> template<typename Other> [[nodiscard]] auto extract_position_helper<CharT,alternative>::match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto{
        auto r {Other::match(cur, ctx, modifiers)}; 
        if (r.matched) {
            CPP2_UFCS(set_alternative_pos)(ctx, alternative, cur);
        }
        return r; 
    }

#line 307 "regex.h2"
    template <typename CharT, size_t alternative> auto extract_position_helper<CharT,alternative>::reset_ranges(auto& ctx) -> void{}
#line 308 "regex.h2"
    template <typename CharT, size_t alternative> [[nodiscard]] auto extract_position_helper<CharT,alternative>::to_string() -> auto{}

#line 317 "regex.h2"
    template <typename CharT, size_t alternative, typename ...List> template<typename Tail> [[nodiscard]] auto alternative_matcher_logic<CharT,alternative,List...>::match(auto const& cur, auto& ctx, auto const& modifiers, Tail const& tail) -> auto{
        if constexpr (greedy_alternative) {
            auto max_overall_length {0}; 
            auto max_current_length {0}; 
            auto r {match_greedy<Tail,List...>(cur, max_overall_length, max_current_length, ctx, modifiers, tail)}; 
            static_cast<void>(std::move(max_overall_length));
            static_cast<void>(std::move(max_current_length));
            return r; 
        }else {
            return match_first<List...>(cur, ctx, modifiers, tail); 
        }
    }
#line 329 "regex.h2"
    template <typename CharT, size_t alternative, typename ...List> auto alternative_matcher_logic<CharT,alternative,List...>::reset_ranges(auto& ctx) -> void { (List::reset_ranges(ctx), ...); }
#line 330 "regex.h2"
    template <typename CharT, size_t alternative, typename ...List> [[nodiscard]] auto alternative_matcher_logic<CharT,alternative,List...>::to_string() -> auto { return CPP2_UFCS(substr)((bstring<CharT>() + ... + ("|" + List::to_string())), 1); }// substr: Remove first '|'.

#line 332 "regex.h2"
    template <typename CharT, size_t alternative, typename ...List> template<typename First, typename ...Next> [[nodiscard]] auto alternative_matcher_logic<CharT,alternative,List...>::match_first(auto const& cur, auto& ctx, auto const& modifiers, auto const& tail) -> auto{
        auto r {First::match(cur, ctx, modifiers, tail)}; 
        if (r.matched) {
            return r; 
        }else {
            First::reset_ranges(ctx);

            if constexpr (0 != sizeof...(Next)) {
                return match_first<Next...>(cur, ctx, modifiers, tail); 
            }else {
                return match_return(false, ctx.end); 
            }
        }
    }

#line 347 "regex.h2"
    template <typename CharT, size_t alternative, typename ...List> template<typename Tail, typename First, typename ...Next> [[nodiscard]] auto alternative_matcher_logic<CharT,alternative,List...>::match_greedy(auto const& cur, auto& max_overall_length, auto& max_current_length, auto& ctx, auto const& modifiers, [[maybe_unused]] Tail const& unnamed_param_6) -> auto{
        auto r {First::match(cur, ctx, modifiers, Tail::prepend(extract_position_helper<CharT,alternative>()))}; 

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

#line 363 "regex.h2"
        // Check if someone other has something larker
        auto o {match_return(false, ctx.end)}; 
        if constexpr (0 != sizeof...(Next)) {
            o = match_greedy<Tail,Next...>(cur, max_overall_length, max_current_length, ctx, modifiers, Tail());
        }

        auto my_current_length {unsafe_narrow<int>(std::distance(cur, std::move(end_current_pos)))}; 
        if (max_overall_length == my_overall_length) {
            max_current_length = std::max(max_current_length, my_current_length);
        }

#line 375 "regex.h2"
        if (std::move(r).matched && std::move(my_overall_length) == max_overall_length) {
            // We are the longest. Check now if we are also the longest in this alternative.
            if (std::move(my_current_length) == max_current_length) {
                // Yes we are. Reset all groups by matching again.
                (Next::reset_ranges(ctx), ...);  // Reset all other ranges.
                return First::match(cur, ctx, modifiers, Tail::prepend(extract_position_helper<CharT,alternative>())); 
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

#line 401 "regex.h2"
    template <typename CharT> template<typename Other> [[nodiscard]] auto any_matcher_logic<CharT>::match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto{
        if (cur != ctx.end && 
          (CPP2_UFCS(has_flag)(modifiers, expression_flags::single_line) || 
           *cpp2::assert_not_null(cur) != '\n')) {
            return Other::match(cur + 1, ctx, modifiers); 
        }
        else {
            return match_return(false, ctx.end); 
        }
    }

#line 412 "regex.h2"
    template <typename CharT> auto any_matcher_logic<CharT>::reset_ranges(auto& ctx) -> void{}
#line 413 "regex.h2"
    template <typename CharT> [[nodiscard]] auto any_matcher_logic<CharT>::to_string() -> auto { return bstring<CharT>(1, '.'); }

#line 419 "regex.h2"
    template <typename CharT> template<typename Other> [[nodiscard]] auto branch_reset_matcher_logic<CharT>::match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto { return Other::match(cur, ctx, modifiers);  }
#line 420 "regex.h2"
    template <typename CharT> auto branch_reset_matcher_logic<CharT>::reset_ranges(auto& ctx) -> void{}
#line 421 "regex.h2"
    template <typename CharT> [[nodiscard]] auto branch_reset_matcher_logic<CharT>::to_string() -> auto { return "(?|";  }

#line 428 "regex.h2"
    template <typename CharT, CharT C, CharT L, CharT U> template<typename Other> [[nodiscard]] auto char_matcher_logic<CharT,C,L,U>::match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto{
        if (CPP2_UFCS(has_flag)(modifiers, expression_flags::case_insensitive)) {
            if (cur != ctx.end && (*cpp2::assert_not_null(cur) == L || *cpp2::assert_not_null(cur) == U)) {
                return Other::match(cur + 1, ctx, modifiers); 
            }
            else {
                return match_return(false, ctx.end); 
            }
        }
        else {
            if (cur != ctx.end && *cpp2::assert_not_null(cur) == C) {
                return Other::match(cur + 1, ctx, modifiers); 
            }
            else {
                return match_return(false, ctx.end); 
            }
        }

    }
#line 447 "regex.h2"
    template <typename CharT, CharT C, CharT L, CharT U> auto char_matcher_logic<CharT,C,L,U>::reset_ranges(auto& ctx) -> void{}
#line 448 "regex.h2"
    template <typename CharT, CharT C, CharT L, CharT U> [[nodiscard]] auto char_matcher_logic<CharT,C,L,U>::to_string() -> auto { return bstring<CharT>(1, C); }

#line 456 "regex.h2"
    template <typename CharT, bool negate, typename ...List> template<typename Other> [[nodiscard]] auto class_matcher_logic<CharT,negate,List...>::match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto{
        if (CPP2_UFCS(has_flag)(modifiers, expression_flags::case_insensitive)) {
            if (cur != ctx.end && negate != (match_any<List...>(safe_tolower(*cpp2::assert_not_null(cur))) || match_any<List...>(safe_toupper(*cpp2::assert_not_null(cur))))) {
                return Other::match(cur + 1, ctx, modifiers); 
            }
            else {
                return match_return(false, ctx.end); 
            }
        }
        else {
            if (cur != ctx.end && negate != match_any<List...>(*cpp2::assert_not_null(cur))) {
                return Other::match(cur + 1, ctx, modifiers); 
            }
            else {
                return match_return(false, ctx.end); 
            }
        }
    }

#line 475 "regex.h2"
    template <typename CharT, bool negate, typename ...List> template<typename First, typename ...Other> [[nodiscard]] auto class_matcher_logic<CharT,negate,List...>::match_any(cpp2::in<CharT> c) -> bool{
        bool r {First::includes(c)}; 

        if (!(r)) {
            if constexpr (0 != sizeof...(Other)) {
                r = match_any<Other...>(c);
            }
        }

        return r; 
    }

#line 487 "regex.h2"
    template <typename CharT, bool negate, typename ...List> auto class_matcher_logic<CharT,negate,List...>::reset_ranges(auto& ctx) -> void{}

#line 489 "regex.h2"
    template <typename CharT, bool negate, typename ...List> [[nodiscard]] auto class_matcher_logic<CharT,negate,List...>::to_string() -> bstring<CharT>{
        bstring<CharT> r {"["}; 
        if (negate) {
            r += "^";
        }
        r += (bstring<CharT>() + ... + List::to_string());
        r += "]";

        return r; 
    }

#line 504 "regex.h2"
    template <typename CharT> template<typename Other> [[nodiscard]] auto empty_matcher_logic<CharT>::match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto { return Other::match(cur, ctx, modifiers);  }
#line 505 "regex.h2"
    template <typename CharT> auto empty_matcher_logic<CharT>::reset_ranges(auto& ctx) -> void{}
#line 506 "regex.h2"
    template <typename CharT> [[nodiscard]] auto empty_matcher_logic<CharT>::to_string() -> auto { return bstring<CharT>();  }

#line 515 "regex.h2"
    template <typename CharT, CharT C, CharT L, CharT U> [[nodiscard]] auto escaped_char_matcher_logic<CharT,C,L,U>::to_string() -> auto { return "\\" + cpp2::to_string(C);  }

#line 521 "regex.h2"
    template <typename CharT> template<typename Other> [[nodiscard]] auto global_group_reset<CharT>::match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto{
        CPP2_UFCS(set_group_start)(ctx, 0, cur);
        return Other::match(cur, ctx, modifiers); 
    }

#line 526 "regex.h2"
    template <typename CharT> auto global_group_reset<CharT>::reset_ranges(auto& ctx) -> void{}
#line 527 "regex.h2"
    template <typename CharT> [[nodiscard]] auto global_group_reset<CharT>::to_string() -> auto { return "\\K";  }

#line 533 "regex.h2"
    template <typename CharT, int group, typename ModifierChange, fixed_string name, bool name_brackets> template<typename Other, typename Modifiers> [[nodiscard]] auto group_matcher_start_logic<CharT,group,ModifierChange,name,name_brackets>::match(auto const& cur, auto& ctx, [[maybe_unused]] Modifiers const& unnamed_param_3, [[maybe_unused]] Other const& unnamed_param_4) -> auto{
        if (-1 != group) {
            CPP2_UFCS(set_group_start)(ctx, group, cur);
        }
        return Other::match(cur, ctx, Modifiers::push(ModifierChange())); 
    }

#line 540 "regex.h2"
    template <typename CharT, int group, typename ModifierChange, fixed_string name, bool name_brackets> auto group_matcher_start_logic<CharT,group,ModifierChange,name,name_brackets>::reset_ranges(auto& ctx) -> void { CPP2_UFCS(set_group_invalid)(ctx, group);  }

#line 542 "regex.h2"
    template <typename CharT, int group, typename ModifierChange, fixed_string name, bool name_brackets> [[nodiscard]] auto group_matcher_start_logic<CharT,group,ModifierChange,name,name_brackets>::to_string() -> std::string{
        if (group != 0) {
            if (0 != CPP2_UFCS(size)(name)) {
                if (name_brackets) {
                    return { "(?<" + cpp2::to_string(CPP2_UFCS(data)(name)) + ">" }; 
                }
                else {
                    return { "(?'" + cpp2::to_string(CPP2_UFCS(data)(name)) + "'" }; 
                }
            }
            else {if (ModifierChange::has_change) {
                return { "(?" + cpp2::to_string(ModifierChange::to_string()) + ":" }; 
            }
            else {
                return "("; 
            }}
        }
        else {
            return ""; 
        }
    }

#line 566 "regex.h2"
    template <typename CharT, int group> template<typename Other, typename Modifier> [[nodiscard]] auto group_matcher_end_logic<CharT,group>::match(auto const& cur, auto& ctx, Modifier const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto{
        if (-1 != group) {
            CPP2_UFCS(set_group_end)(ctx, group, cur);
        }
        auto r {Other::match(cur, ctx, Modifier::pop())}; 
        if (!(r.matched) && -1 != group) {
            CPP2_UFCS(set_group_invalid)(ctx, group);
        }
        return r; 
    }

#line 577 "regex.h2"
    template <typename CharT, int group> auto group_matcher_end_logic<CharT,group>::reset_ranges(auto& ctx) -> void{}

#line 579 "regex.h2"
    template <typename CharT, int group> [[nodiscard]] auto group_matcher_end_logic<CharT,group>::to_string() -> auto{
        if (group != 0) {
            return ")"; 
        }
        else {
            return ""; 
        }
    }

#line 590 "regex.h2"
    template <typename CharT> template<typename Other> [[nodiscard]] auto special_group_end_logic<CharT>::match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto { return Other::match(cur, ctx, modifiers);  }
#line 591 "regex.h2"
    template <typename CharT> auto special_group_end_logic<CharT>::reset_ranges(auto& ctx) -> void{}
#line 592 "regex.h2"
    template <typename CharT> [[nodiscard]] auto special_group_end_logic<CharT>::to_string() -> auto { return ")";  }

#line 598 "regex.h2"
    template <typename CharT, int group, fixed_string symbol> template<typename Other> [[nodiscard]] auto group_ref_matcher_logic<CharT,group,symbol>::match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto{
        auto g {CPP2_UFCS(get_group)(ctx, group)}; 

        auto pos {cur}; 
        auto group_pos {g.start}; 
        for( ; group_pos != g.end && pos != ctx.end; (++group_pos, ++pos) ) {
            if (CPP2_UFCS(has_flag)(modifiers, expression_flags::case_insensitive)) {
                if (safe_tolower(*cpp2::assert_not_null(group_pos)) != safe_tolower(*cpp2::assert_not_null(pos))) {
                    return match_return(false, ctx.end); 
                }
            }
            else {
                if (*cpp2::assert_not_null(group_pos) != *cpp2::assert_not_null(pos)) {
                    return match_return(false, ctx.end); 
                }
            }
        }

        if (std::move(group_pos) == std::move(g).end) {
            return Other::match(std::move(pos), ctx, modifiers); 
        }
        else {
            return match_return(false, ctx.end); 
        }

    }
#line 624 "regex.h2"
    template <typename CharT, int group, fixed_string symbol> auto group_ref_matcher_logic<CharT,group,symbol>::reset_ranges(auto& ctx) -> void{}
#line 625 "regex.h2"
    template <typename CharT, int group, fixed_string symbol> [[nodiscard]] auto group_ref_matcher_logic<CharT,group,symbol>::to_string() -> auto { return bstring<CharT>(CPP2_UFCS(data)(symbol)); }

#line 632 "regex.h2"
    template <typename CharT, bool match_new_line, bool match_new_line_before_end> template<typename Other> [[nodiscard]] auto line_end_matcher_logic<CharT,match_new_line,match_new_line_before_end>::match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto{
        if (cur == ctx.end || (match_new_line && CPP2_UFCS(has_flag)(modifiers, expression_flags::multiple_lines) && *cpp2::assert_not_null(cur) == '\n')) {
            return Other::match(cur, ctx, modifiers); 
        }
        else {if (match_new_line_before_end && (*cpp2::assert_not_null(cur) == '\n' && (cur + 1) == ctx.end)) {// Special case for new line at end.
            return Other::match(cur, ctx, modifiers); 
        }
        else {
            return match_return(false, ctx.end); 
        }}
    }

#line 644 "regex.h2"
    template <typename CharT, bool match_new_line, bool match_new_line_before_end> auto line_end_matcher_logic<CharT,match_new_line,match_new_line_before_end>::reset_ranges(auto& ctx) -> void{}
#line 645 "regex.h2"
    template <typename CharT, bool match_new_line, bool match_new_line_before_end> [[nodiscard]] auto line_end_matcher_logic<CharT,match_new_line,match_new_line_before_end>::to_string() -> auto { return "\\$"; }

#line 652 "regex.h2"
    template <typename CharT, bool match_new_line> template<typename Other> [[nodiscard]] auto line_start_matcher_logic<CharT,match_new_line>::match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto{
        if (cur == ctx.begin || (match_new_line && CPP2_UFCS(has_flag)(modifiers, expression_flags::multiple_lines) && *cpp2::assert_not_null((cur - 1)) == '\n')) {
            return Other::match(cur, ctx, modifiers); 
        }
        else {
            return match_return(false, ctx.end); 
        }

    }
#line 661 "regex.h2"
    template <typename CharT, bool match_new_line> auto line_start_matcher_logic<CharT,match_new_line>::reset_ranges(auto& ctx) -> void{}
#line 662 "regex.h2"
    template <typename CharT, bool match_new_line> [[nodiscard]] auto line_start_matcher_logic<CharT,match_new_line>::to_string() -> auto { return bstring<CharT>(1, '^'); }

#line 669 "regex.h2"
    template <typename CharT, typename ModifierChange> template<typename Other, typename Modifier> [[nodiscard]] auto modifier_matcher_logic<CharT,ModifierChange>::match(auto const& cur, auto& ctx, [[maybe_unused]] Modifier const& unnamed_param_3, [[maybe_unused]] Other const& unnamed_param_4) -> auto{
        return Other::match(cur, ctx, Modifier::replace(ModifierChange())); 
    }
#line 672 "regex.h2"
    template <typename CharT, typename ModifierChange> auto modifier_matcher_logic<CharT,ModifierChange>::reset_ranges(auto& ctx) -> void{}
#line 673 "regex.h2"
    template <typename CharT, typename ModifierChange> [[nodiscard]] auto modifier_matcher_logic<CharT,ModifierChange>::to_string() -> auto { return "(?" + cpp2::to_string(ModifierChange::to_string()) + ")"; }

#line 681 "regex.h2"
    template <typename CharT, fixed_string Name, typename Base> [[nodiscard]] auto named_matcher_logic<CharT,Name,Base>::to_string() -> auto { return bstring<CharT>(CPP2_UFCS(data)(Name));  }

#line 711 "regex.h2"
    template <typename CharT, typename M, int min_count, int max_count, bool greedy, bool possessive> template<typename Iter> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count,greedy,possessive>::match(Iter const& cur, auto& ctx, auto const& modifiers, auto const& tail) -> auto{
        if (greedy) {
            return match_greedy(0, cur, cur, ctx, modifiers, tail); 
        }
        else {
            return match_not_greedy(cur, ctx, modifiers, tail); 
        }
    }

#line 720 "regex.h2"
    template <typename CharT, typename M, int min_count, int max_count, bool greedy, bool possessive> auto range_matcher_logic<CharT,M,min_count,max_count,greedy,possessive>::reset_ranges(auto& ctx) -> void { M::reset_ranges(ctx); }

#line 722 "regex.h2"
    template <typename CharT, typename M, int min_count, int max_count, bool greedy, bool possessive> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count,greedy,possessive>::to_string() -> bstring<CharT>{
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

      if (!(greedy)) {
        r += "?";
      }
      else {if (possessive) {
        r += "+";
      }}

      return r; 
    }

#line 748 "regex.h2"
    template <typename CharT, typename M, int min_count, int max_count, bool greedy, bool possessive> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count,greedy,possessive>::is_below_upper_bound(cpp2::in<int> count) -> bool{
        if (-1 == max_count) {return true; }
        else {return cpp2::cmp_less(count,max_count); }
    }

#line 753 "regex.h2"
    template <typename CharT, typename M, int min_count, int max_count, bool greedy, bool possessive> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count,greedy,possessive>::is_below_lower_bound(cpp2::in<int> count) -> bool{
        if (-1 == min_count) {return false; }
        else {return cpp2::cmp_less(count,min_count); }
    }

#line 758 "regex.h2"
    template <typename CharT, typename M, int min_count, int max_count, bool greedy, bool possessive> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count,greedy,possessive>::is_in_range(cpp2::in<int> count) -> bool{
        if (-1 != min_count && cpp2::cmp_less(count,min_count)) {return false; }
        if (-1 != max_count && cpp2::cmp_greater(count,max_count)) {return false; }
        return true; 
    }

#line 764 "regex.h2"
    template <typename CharT, typename M, int min_count, int max_count, bool greedy, bool possessive> template<typename Iter> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count,greedy,possessive>::match_min_count(Iter const& cur, auto& ctx, auto const& modifiers, int& count_r) -> auto{// TODO: count_r as out parameter introduces a performance loss.
        auto res {match_return(true, cur)}; 
        auto count {0}; 

        while( is_below_lower_bound(count) && res.matched ) {
            res = M::match(res.pos, ctx, modifiers, no_tail<CharT>());
            if (res.matched) {
                count += 1;
            }
        }

        count_r = std::move(count);
        return res; 
    }

#line 779 "regex.h2"
    template <typename CharT, typename M, int min_count, int max_count, bool greedy, bool possessive> template<typename Iter, typename Other> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count,greedy,possessive>::match_greedy(cpp2::in<int> count, Iter const& cur, Iter const& last_valid, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_6) -> match_return<Iter>{
        auto r {M::match(cur, ctx, modifiers, no_tail<CharT>())}; 
        if ( is_below_upper_bound(count) && r.matched && 
            (is_below_lower_bound(count) || r.pos != cur)) 
        {
            auto inner {match_greedy(count + 1, std::move(r).pos, cur, ctx, modifiers, Other())}; 

            if (possessive || // Do not backtrack if possessive.
               inner.matched) {
                return inner; 
            }
        }

        // No match from the recursion. Try to match our tail.
        if (is_in_range(count)) {
            auto o {Other::match(cur, ctx, modifiers)}; 

            if (o.matched) {
                // Rematch M to set the groups.
                M::reset_ranges(ctx);
                static_cast<void>(M::match(last_valid, ctx, modifiers, no_tail<CharT>()));
            }

            return o; 
        }
        else {
            return match_return(false, ctx.end); 
        }
    }

#line 809 "regex.h2"
    template <typename CharT, typename M, int min_count, int max_count, bool greedy, bool possessive> template<typename Iter, typename Other> [[nodiscard]] auto range_matcher_logic<CharT,M,min_count,max_count,greedy,possessive>::match_not_greedy(Iter const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> match_return<Iter>{
        auto count {0}; 
        auto start {match_min_count(cur, ctx, modifiers, count)}; 
        if (!(start.matched)) {
          return start; 
        }

        auto pos {std::move(start).pos}; 
        while( is_below_upper_bound(count) ) {
            auto o {Other::match(pos, ctx, modifiers)}; 
            if (o.matched) {
                return o; 
            }

            auto r {M::match(pos, ctx, modifiers, no_tail<CharT>())}; 
            if (!(r.matched)) {
                return match_return(false, ctx.end); 
            }
            count += 1;
            pos = r.pos;
        }

        return Other::match(std::move(pos), ctx, modifiers); // Upper bound reached.
    }

#line 839 "regex.h2"
    template <typename CharT, typename M, int min_count, int max_count, bool greedy, bool possessive, char symbol> [[nodiscard]] auto special_range_matcher_logic<CharT,M,min_count,max_count,greedy,possessive,symbol>::to_string() -> auto{
        auto r {M::to_string() + symbol}; 
        if (!(greedy)) {
            r += "?";
        }
        else {if (possessive) {
            r += "+";
        }}

        return r; 
    }

#line 858 "regex.h2"
    template <typename CharT, bool negate> template<typename Other> [[nodiscard]] auto word_boundary_matcher_logic<CharT,negate>::match(auto const& cur, auto& ctx, auto const& modifiers, [[maybe_unused]] Other const& unnamed_param_4) -> auto{
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
            return Other::match(cur, ctx, modifiers); 
        }
        else {
            return match_return(false, ctx.end); 
        }

    }
#line 887 "regex.h2"
    template <typename CharT, bool negate> auto word_boundary_matcher_logic<CharT,negate>::reset_ranges(auto& ctx) -> void{}
#line 888 "regex.h2"
    template <typename CharT, bool negate> [[nodiscard]] auto word_boundary_matcher_logic<CharT,negate>::to_string() -> std::string{
        if (negate) {
            return "\\B"; 
        }else {
            return "\\b"; 
        }
    }

#line 909 "regex.h2"
    template <fixed_string Name, int group_id, typename Inner> [[nodiscard]] auto group_name_list<Name,group_id,Inner>::get_group_id(auto const& name) -> int{
        if (name == CPP2_UFCS(data)(Name)) {
            return group_id; 
        }
        else {
            return Inner::get_group_id(name); 
        }
    }

#line 920 "regex.h2"
    [[nodiscard]] auto group_name_list_end::get_group_id([[maybe_unused]] auto const& unnamed_param_1) -> auto { return -1;  }

#line 929 "regex.h2"
    template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::get_iter(cpp2::in<view<CharT>> str, auto const& pos) -> auto{
        if (cpp2::cmp_less(pos,CPP2_UFCS(size)(str))) {
            return CPP2_UFCS(begin)(str) + pos; 
        }
        else {
            return CPP2_UFCS(end)(str); 
        }
    }

#line 943 "regex.h2"
        template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> template <typename Iter> regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search_return<Iter>::search_return(cpp2::in<bool> matched_, context<Iter> const& ctx_)
            : matched{ matched_ }
            , ctx{ ctx_ }{

#line 946 "regex.h2"
        }

#line 948 "regex.h2"
        template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search_return<Iter>::group_number() const& -> auto { return CPP2_UFCS(size)(ctx);  }
#line 949 "regex.h2"
        template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search_return<Iter>::group(cpp2::in<int> g) const& -> auto { return CPP2_UFCS(get_group_string)(ctx, g); }
#line 950 "regex.h2"
        template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search_return<Iter>::group_start(cpp2::in<int> g) const& -> auto { return CPP2_UFCS(get_group_start)(ctx, g); }
#line 951 "regex.h2"
        template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search_return<Iter>::group_end(cpp2::in<int> g) const& -> auto { return CPP2_UFCS(get_group_end)(ctx, g); }

#line 953 "regex.h2"
        template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search_return<Iter>::group(cpp2::in<bstring<CharT>> g) const& -> auto { return group(get_group_id(g)); }
#line 954 "regex.h2"
        template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search_return<Iter>::group_start(cpp2::in<bstring<CharT>> g) const& -> auto { return group_start(get_group_id(g)); }
#line 955 "regex.h2"
        template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search_return<Iter>::group_end(cpp2::in<bstring<CharT>> g) const& -> auto { return group_end(get_group_id(g)); }

#line 957 "regex.h2"
        template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search_return<Iter>::get_group_id(cpp2::in<bstring<CharT>> g) const& -> auto{
            auto group_id {named_groups::get_group_id(g)}; 
            if (-1 == group_id) {
                // TODO: Throw error.
            }
            return group_id; 
        }

#line 966 "regex.h2"
    template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::match(cpp2::in<view<CharT>> str) const& -> auto { return match(CPP2_UFCS(begin)(str), CPP2_UFCS(end)(str)); }
#line 967 "regex.h2"
    template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::match(cpp2::in<view<CharT>> str, auto const& start) const& -> auto { return match(get_iter(str, start), CPP2_UFCS(end)(str)); }
#line 968 "regex.h2"
    template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::match(cpp2::in<view<CharT>> str, auto const& start, auto const& length) const& -> auto { return match(get_iter(str, start), get_iter(str, start + length)); }
#line 969 "regex.h2"
    template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> template<typename Iter> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::match(Iter const& start, Iter const& end) const& -> search_return<Iter>{
        context ctx {start, end}; 

        auto r {Matcher::match(start, ctx, modifiers())}; 
        return search_return(r.matched && std::move(r).pos == end, std::move(ctx)); 
    }

#line 976 "regex.h2"
    template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search(cpp2::in<view<CharT>> str) const& -> auto { return search(CPP2_UFCS(begin)(str), CPP2_UFCS(end)(str)); }
#line 977 "regex.h2"
    template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search(cpp2::in<view<CharT>> str, auto const& start) const& -> auto { return search(get_iter(str, start), CPP2_UFCS(end)(str)); }
#line 978 "regex.h2"
    template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search(cpp2::in<view<CharT>> str, auto const& start, auto const& length) const& -> auto { return search(get_iter(str, start), get_iter(str, start + length)); }
#line 979 "regex.h2"
    template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> template<typename Iter> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search(Iter const& start, Iter const& end) const& -> search_return<Iter>{
        auto matched {false}; 
        context ctx {start, end}; 

        auto cur {start}; 
        for( ; true; (++cur) ) {
            if (Matcher::match(cur, ctx, modifiers()).matched) {
                matched = true;
                break;
            }

            if (cur == ctx.end) {
                break;
            }
        }

        return search_return(std::move(matched), std::move(ctx)); 
    }

#line 998 "regex.h2"
    template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::to_string() const& -> auto { return Matcher::to_string();  }

#line 1024 "regex.h2"
    auto regex_parser_state::next_alternative() & -> void{
        std::vector<std::string> new_list {}; 
        std::swap(new_list, cur_match_list);
        static_cast<void>(CPP2_UFCS(insert)(alternate_match_lists, CPP2_UFCS(end)(alternate_match_lists), std::move(new_list)));
    }

#line 1030 "regex.h2"
    auto regex_parser_state::swap(regex_parser_state& t) & -> void{
        std::swap(cur_match_list, t.cur_match_list);
        std::swap(alternate_match_lists, t.alternate_match_lists);
        std::swap(modifiers, t.modifiers);
    }

#line 1036 "regex.h2"
    auto regex_parser_state::add(auto const& matcher) & -> void { CPP2_UFCS(push_back)(cur_match_list, matcher);  }

#line 1038 "regex.h2"
    auto regex_parser_state::wrap_last(auto const& matcher) & -> void{
        auto last {CPP2_UFCS(back)(cur_match_list)}; 
        CPP2_UFCS(back)(cur_match_list) = matcher(last);
        static_cast<void>(matcher);
        static_cast<void>(std::move(last));
    }

#line 1045 "regex.h2"
    [[nodiscard]] auto regex_parser_state::empty() const& -> bool { return CPP2_UFCS(empty)(cur_match_list);  }

#line 1054 "regex.h2"
    [[nodiscard]] auto regex_branch_reset_state::next() & -> int{
        auto g {cur_group}; 
        cur_group += 1;
        max_group = max(max_group, cur_group);

        return g; 
    }

#line 1062 "regex.h2"
    auto regex_branch_reset_state::set_next(cpp2::in<int> g) & -> void{
        cur_group = g;
        max_group = max(max_group, g);
    }

#line 1067 "regex.h2"
    auto regex_branch_reset_state::next_alternative() & -> void{
        if (is_active) {
            cur_group = from;
        }
    }

#line 1093 "regex.h2"
    template <typename Error_out> regex_parser<Error_out>::regex_parser(cpp2::in<std::string_view> r, cpp2::in<std::string_view> m, Error_out const& e)
        : regex{ r }
        , modifier{ m }
        , error_out{ e }{

#line 1097 "regex.h2"
    }

#line 1101 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::new_state() & -> regex_parser_state{
        regex_parser_state old_state {}; 
        CPP2_UFCS(swap)(old_state, cur_state);

        return old_state; 
    }

#line 1108 "regex.h2"
    template <typename Error_out> auto regex_parser<Error_out>::restore_state(cpp2::in<regex_parser_state> old_state) & -> void{
        cur_state = old_state;
    }

#line 1115 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::group_new_state() & -> regex_branch_reset_state{
        regex_branch_reset_state old_state {}; 
        std::swap(old_state, cur_branch_reset_state);

        cur_branch_reset_state.is_active = true;
        cur_branch_reset_state.cur_group = old_state.cur_group;
        cur_branch_reset_state.from      = cur_branch_reset_state.cur_group;
        cur_branch_reset_state.max_group = cur_branch_reset_state.cur_group;

        return old_state; 
    }

#line 1127 "regex.h2"
    template <typename Error_out> auto regex_parser<Error_out>::group_restore_state(cpp2::in<regex_branch_reset_state> old_state) & -> void{
        auto next_group {cur_branch_reset_state.max_group}; 
        cur_branch_reset_state = old_state;
        CPP2_UFCS(set_next)(cur_branch_reset_state, std::move(next_group));
    }

#line 1136 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::get_next_position(cpp2::in<bool> in_class, cpp2::in<bool> no_skip) const& -> size_t{
        auto perl_syntax {false}; 
        if (!(no_skip)) {
            if (in_class) {
                perl_syntax = cur_state.modifiers.perl_code_syntax && cur_state.modifiers.perl_code_syntax_in_classes;
            }
            else {
                perl_syntax = cur_state.modifiers.perl_code_syntax;
            }
        }
        auto cur {pos + 1}; 
        if (std::move(perl_syntax)) {
            for( ; cpp2::cmp_less(cur,CPP2_UFCS(size)(regex)); (cur += 1) ) {
                auto n {CPP2_ASSERT_IN_BOUNDS(regex, cur)}; 

                if (space_class<char>::includes(n)) {
                    continue;
                }
                else {if (!(in_class) && '#' == n) {
                    cur = CPP2_UFCS(find)(regex, "\n", cur);
                    if (std::string::npos == cur) {
                        // No new line, comment runs until the end of the pattern
                        cur = CPP2_UFCS(size)(regex);
                    }
                }
                else { // None space none comment char
                    break;
                }}
            }
        }

        // Check for end of file.
        if (cpp2::cmp_greater(cur,CPP2_UFCS(size)(regex))) {
            cur = CPP2_UFCS(size)(regex);
        }
        return cur; 
    }

#line 1174 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::next_impl(cpp2::out<char> n, cpp2::in<bool> in_class, cpp2::in<bool> no_skip) & -> bool{
        pos = get_next_position(in_class, no_skip);
        if (pos != CPP2_UFCS(size)(regex)) {
            n.construct(CPP2_ASSERT_IN_BOUNDS(regex, pos));
            return true; 
        }
        else {
            n.construct('\0');
            return false; 
        }
    }

#line 1186 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::next(cpp2::out<char> n) & -> auto { return next_impl(cpp2::out(&n), false, false); }
#line 1187 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::next_in_class(cpp2::out<char> n) & -> auto { return next_impl(cpp2::out(&n), true, false);  }
#line 1188 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::next_no_skip(cpp2::out<char> n) & -> auto { return next_impl(cpp2::out(&n), false, true); }

#line 1192 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::skip() & -> bool{
        cpp2::deferred_init<char> c; 
        auto r {next(cpp2::out(&c))}; 
        static_cast<void>(std::move(c.value()));
        return r; 
    }

#line 1199 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::skip_n(cpp2::in<int> n) & -> bool{
        auto r {true}; 
        auto cur {0}; 
        for( ; r && cpp2::cmp_less(cur,n); (r = skip()) ) {
            cur += 1;
        }
        return r; 
    }

#line 1208 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::current() const& -> char{
        if (cpp2::cmp_less(pos,CPP2_UFCS(size)(regex))) {
            return CPP2_ASSERT_IN_BOUNDS(regex, pos); 
        }else {
            return '\0'; 
        }
    }

#line 1216 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::peek_impl(cpp2::in<bool> in_class) const& -> char{
        auto next_pos {get_next_position(in_class, false)}; 
        if (cpp2::cmp_less(next_pos,CPP2_UFCS(size)(regex))) {
            return CPP2_ASSERT_IN_BOUNDS(regex, std::move(next_pos)); 
        }
        else {
            return '\0'; 
        }
    }

#line 1226 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::peek() const& -> auto { return peek_impl(false); }
#line 1227 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::peek_in_class() const& -> auto { return peek_impl(true);  }

#line 1229 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::grab_until_impl(cpp2::in<std::string> e, cpp2::out<std::string> r, cpp2::in<bool> any) & -> bool{
        auto start {pos}; 
        auto end {pos}; 
        if (any) {
            end = CPP2_UFCS(find_first_of)(regex, e, pos);
        }
        else {
            end = CPP2_UFCS(find)(regex, e, pos);
        }

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

#line 1250 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::grab_until(cpp2::in<std::string> e, cpp2::out<std::string> r) & -> auto { return grab_until_impl(e, cpp2::out(&r), false); }
#line 1251 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::grab_until(cpp2::in<char> e, cpp2::out<std::string> r) & -> auto { return grab_until_impl(std::string(1, e), cpp2::out(&r), false); }
#line 1252 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::grab_until_one_of(cpp2::in<std::string> e, cpp2::out<std::string> r) & -> auto { return grab_until_impl(e, cpp2::out(&r), true);  }

#line 1254 "regex.h2"
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

#line 1276 "regex.h2"
    template <typename Error_out> auto regex_parser<Error_out>::error(cpp2::in<std::string> message) & -> void{
        error_out(("Error during parsing of regex '" + cpp2::to_string(regex) + "' at position '" + cpp2::to_string(pos) + "': " + cpp2::to_string(message)));
        has_error = true;
    }

#line 1281 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::create_matcher(cpp2::in<std::string> name, cpp2::in<std::string> template_arguments) const& -> auto{
        auto sep {", "}; 
        if (CPP2_UFCS(empty)(template_arguments)) {sep = ""; }

        return "::cpp2::regex::" + cpp2::to_string(name) + "<char" + cpp2::to_string(std::move(sep)) + cpp2::to_string(template_arguments) + ">"; 
    }

#line 1288 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::create_matcher_from_list(auto const& list) & -> auto { return create_matcher("matcher_list", join(list));  }

#line 1290 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::create_matcher_from_state() & -> std::string{
        if (0 == CPP2_UFCS(size)(cur_state.alternate_match_lists)) {return create_matcher_from_list(cur_state.cur_match_list); }

        if (0 == CPP2_UFCS(size)(cur_state.cur_match_list)) {
            CPP2_UFCS(add)(cur_state, create_matcher("empty_matcher_logic", ""));
        }
        CPP2_UFCS(next_alternative)(cur_state);
        CPP2_UFCS(next_alternative)(cur_branch_reset_state);

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

#line 1312 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::create_named_groups_arg() const& -> std::string{
        std::string r {"::cpp2::regex::group_name_list_end"}; 

        for ( auto const& cur : named_groups ) {
            r = { "::cpp2::regex::group_name_list<\"" + cpp2::to_string(cur.first) + "\", " + cpp2::to_string(cur.second) + ", " + cpp2::to_string(r) + ">" };
        }

        return r; 
    }

#line 1322 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::join(cpp2::in<std::vector<std::string>> list) -> std::string{
        std::string r {""}; 

        std::string separator {""}; 
        for ( auto const& cur : list ) {
            r += separator + cur;
            separator = ", ";
        }

        return r; 
    }

#line 1334 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::parse_modifiers(cpp2::in<std::string> change_str, cpp2::out<std::string> modifier_change, 
                      regex_parser_modifier_state& parser_modifiers) & -> bool{
        auto is_negative {false}; 
        auto is_reset {false}; 

        auto add {0}; 
        auto remove {0}; 

        auto apply {[&, _1 = (&is_negative), _2 = (&remove), _3 = (&add)](cpp2::in<int> flag) mutable -> void{
            if (*cpp2::assert_not_null(_1)) {
                *cpp2::assert_not_null(_2) |= flag;
            }
            else {
                *cpp2::assert_not_null(_3) |= flag;
            }
        }}; 

        auto iter {CPP2_UFCS(begin)(change_str)}; 
        for( ; iter != CPP2_UFCS(end)(change_str); (++iter) ) {
            auto cur {*cpp2::assert_not_null(iter)}; 
            if (cur == '^') {
                is_reset = true;
            }
            else {if (cur == '-') {
                if (is_reset) {error("No negative modifier allowed."); return false; }
                is_negative = true;
            }
            else {if (cur == 'i') {apply(expression_flags::case_insensitive); }
            else {if (cur == 'm') {apply(expression_flags::multiple_lines); }
            else {if (cur == 's') {apply(expression_flags::single_line); }
            else {if (cur == 'n') {
                apply(expression_flags::no_group_captures);
                parser_modifiers.group_captures_have_numbers = is_negative;
            }
            else {if (cur == 'x') {
                if ((iter + 1) == CPP2_UFCS(end)(change_str) || *cpp2::assert_not_null((iter + 1)) != 'x') {
                    // x modifier
                    apply(expression_flags::perl_code_syntax);
                    parser_modifiers.perl_code_syntax = !(is_negative);

                    // Just x unsets xx and remove x also removes xx
                    remove |= expression_flags::perl_code_syntax_in_classes;
                    parser_modifiers.perl_code_syntax_in_classes = false;
                }
                else { // xx modifier
                    // xx also sets or unsets x
                    apply(expression_flags::perl_code_syntax);
                    parser_modifiers.perl_code_syntax = !(is_negative);

                    apply(expression_flags::perl_code_syntax_in_classes);
                    parser_modifiers.perl_code_syntax_in_classes = !(is_negative);

                    ++iter; // Skip the second x
                }
            }
            else {
                error(("Unknown modifier: " + cpp2::to_string(cur))); return false; 
            }}}}}}}
        }

        modifier_change.construct("::cpp2::regex::match_modifiers_state_change<true, " + cpp2::to_string(std::move(is_reset)) + ", " + cpp2::to_string(std::move(add)) + ", " + cpp2::to_string(std::move(remove)) + ", \"" + cpp2::to_string(change_str) + "\">");

        return true; 
    }

#line 1402 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_alternative(cpp2::in<char> c) & -> bool{
        if (c != '|') {return false; }

        CPP2_UFCS(next_alternative)(cur_state);
        CPP2_UFCS(next_alternative)(cur_branch_reset_state);
        return true; 
    }

#line 1410 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_anchor(cpp2::in<char> c) & -> bool{
        if (c == '^') {
            CPP2_UFCS(add)(cur_state, create_matcher("line_start_matcher_logic", "true"));
            return true; 
        }
        else {if (c == '$') {
            CPP2_UFCS(add)(cur_state, create_matcher("line_end_matcher_logic", "true, true"));
            return true; 
        }}

        return false; 
    }

#line 1423 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_any(cpp2::in<char> c) & -> bool{
        if (c == '.') {
            CPP2_UFCS(add)(cur_state, create_matcher("any_matcher_logic", ""));
            return true; 
        }
        return false; 
    }

#line 1431 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_class(cpp2::in<char> c) & -> bool{
        if (c != '[') {return false; }

        std::vector<std::string> classes {}; 

        char c_cur {current()}; 

        // First step: parse until the end bracket and push single chars, ranges or groups on the class stack.
        auto negate {false}; 
        auto first {true}; 
        auto range {false}; 
        while( next_in_class(cpp2::out(&c_cur)) & (c_cur != ']' || first) ) {
            if (c_cur == '^') {
                negate = true;
                continue; // Skip rest of the loop. Also the first update.
            }
            if (c_cur == '[' && peek_in_class() == ':') {
                // We have a character class.
                static_cast<void>(skip_n(2));

                std::string name {""}; 
                if (!(grab_until(":]", cpp2::out(&name)))) {error("Could not find end of character class."); return false; }
                if (CPP2_UFCS(end)(supported_classes) == std::find(CPP2_UFCS(begin)(supported_classes), CPP2_UFCS(end)(supported_classes), name)) {
                    error(("Unsupported character class. Supported ones are: " + cpp2::to_string(join(supported_classes))));
                    return false; 
                }

                CPP2_UFCS(push_back)(classes, ("[:" + cpp2::to_string(name) + ":]"));

                static_cast<void>(skip());// Skip ':' pointing to the ending ']'.
            }
            else {if (c_cur == '\\') {
                if (next_no_skip(cpp2::out(&c_cur)) && (c_cur != ']')) {
                    if ( ' ' == c_cur && cur_state.modifiers.perl_code_syntax && cur_state.modifiers.perl_code_syntax_in_classes) {
                        CPP2_UFCS(push_back)(classes, std::string(1, c_cur));// TODO: UFCS error with char as argument.
                    }
                    else {
                        auto name {""}; 
                            if ('d' == c_cur) {name = "short_digits"; }
                        else {if ('D' == c_cur) {name = "short_not_digits"; }
                        else {if ('h' == c_cur) {name = "short_hor_space"; }
                        else {if ('H' == c_cur) {name = "short_not_hor_space"; }
                        else {if ('s' == c_cur) {name = "short_space"; }
                        else {if ('S' == c_cur) {name = "short_not_space"; }
                        else {if ('v' == c_cur) {name = "short_ver_space"; }
                        else {if ('V' == c_cur) {name = "short_not_ver_space"; }
                        else {if ('w' == c_cur) {name = "short_word"; }
                        else {if ('W' == c_cur) {name = "short_not_word"; }
                        else {
                            error("Unknown group escape.");
                            return false; 
                        }}}}}}}}}}
                        CPP2_UFCS(push_back)(classes, ("[:" + cpp2::to_string(name) + ":]"));
                    }
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

#line 1538 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_escape(cpp2::in<char> c) & -> bool{
        if (c != '\\') {return false; }

        auto start {pos}; // Keep start for group matchers.
        auto c_next {'\0'}; 
        if (!(next(cpp2::out(&c_next)))) {error("Escape without a following character."); return false; }

        auto add_group_matcher {[&, _1 = std::move(start), _2 = (&pos)](cpp2::in<std::string> name) mutable -> bool{

            auto name_trim {trim_copy(name)}; 
            int group_id {0}; 
            if (string_to_int(name_trim, group_id)) {
                if (cpp2::cmp_less(group_id,0)) {
                    group_id = cur_branch_reset_state.cur_group + group_id;

                    if (cpp2::cmp_less(group_id,1)) {// Negative and zero are no valid groups.
                        error(("Relative group reference does not reference a valid group. (Would be " + cpp2::to_string(group_id) + ".)"));
                        return false; 
                    }
                }

                if (cpp2::cmp_greater_eq(group_id,cur_branch_reset_state.cur_group)) {error("Group reference is used before the group is declared."); return false; }
            }
            else {
                // Named group
                auto iter {CPP2_UFCS(find)(named_groups, std::move(name_trim))}; 
                if (iter == CPP2_UFCS(end)(named_groups)) {error(("Group names does not exist. (Name is: " + cpp2::to_string(name) + ")")); return false; }

                group_id = (*cpp2::assert_not_null(std::move(iter))).second;
            }
            CPP2_UFCS(add)(cur_state, create_matcher("group_ref_matcher_logic", (cpp2::to_string(std::move(group_id)) + ", \"\\" + cpp2::to_string(CPP2_UFCS(substr)(regex, _1, *cpp2::assert_not_null(_2) - _1 + 1)) + "\"")));

            return true; 
        }}; 

        if ([_0 = '1', _1 = c_next, _2 = '9']{ return cpp2::cmp_less_eq(_0,_1) && cpp2::cmp_less_eq(_1,_2); }()) {
            auto group {grab_number()}; 
            if (!(add_group_matcher(std::move(group)))) {return false; }
        }
        else {if (std::string::npos != CPP2_UFCS(find)(std::string("tnrfae"), c_next)) {
            auto inner {create_matcher("char_matcher_logic", ("'\\" + cpp2::to_string(c_next) + "', '\\" + cpp2::to_string(c_next) + "', '\\" + cpp2::to_string(c_next) + "'"))}; 
            CPP2_UFCS(add)(cur_state, create_matcher("named_matcher_logic", ("\"\\\\" + cpp2::to_string(c_next) + "\", " + cpp2::to_string(std::move(inner)))));
        }
        else {if (std::string::npos != CPP2_UFCS(find)(std::string("^.[]$()*{}?+|"), c_next)) {
            if (c_next == '$') {
                // TODO: Provide proper escape for cppfront capture
                CPP2_UFCS(add)(cur_state, create_matcher("line_end_matcher_logic", "true, true"));
            }
            else {
                CPP2_UFCS(add)(cur_state, create_matcher("escaped_char_matcher_logic", ("'" + cpp2::to_string(c_next) + "', '" + cpp2::to_string(safe_tolower(c_next)) + "', '" + cpp2::to_string(safe_toupper(c_next)) + "'")));
            }
        }
        else {if ('\\' == c_next) {
            CPP2_UFCS(add)(cur_state, create_matcher("escaped_char_matcher_logic", "'\\\\', '\\\\', '\\\\'"));
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
        else {if ('K' == c_next) {
            CPP2_UFCS(add)(cur_state, create_matcher("global_group_reset", ""));
        }
        else {if ('A' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("named_string_start", "")); }
        else {if ('b' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("word_boundary_matcher_logic", "false")); }
        else {if ('B' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("word_boundary_matcher_logic", "true")); }
        else {if ('d' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("named_class_digits", "")); }
        else {if ('D' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("named_class_not_digits", "")); }
        else {if ('h' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("named_class_hor_space", "")); }
        else {if ('H' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("named_class_not_hor_space", "")); }
        else {if ('N' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("named_class_no_new_line", "")); }
        else {if ('s' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("named_class_space", "")); }
        else {if ('S' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("named_class_not_space", "")); }
        else {if ('v' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("named_class_ver_space", "")); }
        else {if ('V' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("named_class_not_ver_space", "")); }
        else {if ('w' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("named_class_word", "")); }
        else {if ('W' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("named_class_not_word", "")); }
        else {if ('Z' == c_next) {CPP2_UFCS(add)(cur_state, create_matcher("named_string_end_or_before_new_line_at_end", "")); }
        else {if ('z' == std::move(c_next)) {CPP2_UFCS(add)(cur_state, create_matcher("named_string_end", "")); }
        else {
            error("Unknown escape.");
            return false; 
        }}}}}}}}}}}}}}}}}}}}}}}

        return true; 
    }

#line 1647 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_group(cpp2::in<char> c) & -> bool{
        if (c != '(') {return false; }

        auto has_id {cur_state.modifiers.group_captures_have_numbers}; 
        auto has_pattern {true}; 
        std::string group_name {""}; 
        auto group_name_brackets {true}; 
        std::string modifier_change {"::cpp2::regex::match_modifiers_no_change"}; 

        auto modifiers_change_to {cur_state.modifiers}; 

        char c_next {'\0'}; 
        // Skip the '('
        if (!(next(cpp2::out(&c_next)))) {error("Group without closing bracket."); return false; }
        if (c_next == '?') {
            // Special group
            if (!(next_no_skip(cpp2::out(&c_next)))) {error("Missing character after group opening."); return false; }

            if (c_next == '<' || c_next == '\'') {
                // named group
                auto end_char {c_next}; 
                if (end_char == '<') {
                    end_char = '>';
                }else {
                    group_name_brackets = false;
                }
                has_id = true; // Force id for named groups.
                if (!(next(cpp2::out(&c_next))))   { error("Missing ending bracket for named group."); return false; }/* skip '<' */
                if (!(grab_until(std::move(end_char), cpp2::out(&group_name)))) {error("Missing ending bracket for named group."); return false; }
                if (!(next(cpp2::out(&c_next)))) {error("Group without closing bracket."); return false; }
            }
            else {if (c_next == '#') {
                // Comment
                std::string comment_str {""}; 
                if (!(grab_until(")", cpp2::out(&comment_str)))) {error("Group without closing bracket."); return false; }
                // Do not add comment. Has problems with ranges.

                return true; 
            }
            else {if (c_next == '|') {
                // Branch reset group

                if (!(next(cpp2::out(&c_next))))   { error("Missing ending bracket for named group."); return false; }/* skip '|' */

                auto old_parser_state {new_state()}; 
                auto old_branch_state {group_new_state()}; 
                parse_until(')');
                auto inner {create_matcher_from_state()}; 
                group_restore_state(std::move(old_branch_state));
                restore_state(std::move(old_parser_state));

                auto start_matcher {create_matcher("branch_reset_matcher_logic", "")}; 
                auto end_matcher {create_matcher("special_group_end_logic", "")}; 

                std::vector<std::string> v {std::move(start_matcher), std::move(inner), std::move(end_matcher)}; 
                CPP2_UFCS(add)(cur_state, create_matcher_from_list(std::move(v)));

                return true; 
            }
            else {
                // Simple modifier
                has_id = false;
                std::string change_str {""}; 
                if (!(grab_until_one_of("):", cpp2::out(&change_str)))) {error("Missing ending bracket for group."); return false; }
                if (!(parse_modifiers(std::move(change_str), cpp2::out(&modifier_change), modifiers_change_to))) {
                     return false; 
                }

                if (')' == current()) {
                    has_pattern = false;
                }
                else {
                    if (!(next(cpp2::out(&c_next))))   { error("Missing ending bracket for group."); return false; }/* skip ':' */
                }
            }}}
        }

        if (std::move(has_pattern)) {
            // regular group

            auto group_number {-1}; 
            if (std::move(has_id)) {
                group_number = CPP2_UFCS(next)(cur_branch_reset_state);
            }

            auto old_state {new_state()}; 
            cur_state.modifiers = std::move(modifiers_change_to);
            parse_until(')');
            auto inner {create_matcher_from_state()}; 
            restore_state(std::move(old_state));

            auto start_matcher {create_matcher("group_matcher_start_logic", (cpp2::to_string(group_number) + ", " + cpp2::to_string(std::move(modifier_change)) + ", \"" + cpp2::to_string(group_name) + "\", " + cpp2::to_string(std::move(group_name_brackets))))}; 
            if (0 != CPP2_UFCS(size)(group_name)) {
                if (!(CPP2_UFCS(contains)(named_groups, group_name))) {// Redefinition of group name is not an error. The left most one is retained.
                    CPP2_ASSERT_IN_BOUNDS(named_groups, group_name) = group_number;
                }
            }
            auto end_matcher {create_matcher("group_matcher_end_logic", (cpp2::to_string(std::move(group_number))))}; 

            std::vector<std::string> v {std::move(start_matcher), std::move(inner), std::move(end_matcher)}; 
            CPP2_UFCS(add)(cur_state, create_matcher_from_list(std::move(v)));
        }
        else {
            // Only a modifier
            cur_state.modifiers = std::move(modifiers_change_to);
            CPP2_UFCS(add)(cur_state, create_matcher("modifier_matcher_logic", (cpp2::to_string(std::move(modifier_change)))));
        }

        return true; 
    }

#line 1758 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_handle_special(cpp2::in<char> c) & -> bool{
        if (c == '\'') {
            CPP2_UFCS(add)(cur_state, create_matcher("char_matcher_logic", ("'\\" + cpp2::to_string(c) + "', '\\" + cpp2::to_string(c) + "', '\\" + cpp2::to_string(c) + "'")));
            return true; 
        }

        return false; 
    }

#line 1767 "regex.h2"
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
        if (!(skip())) {error("End of regex before closing '}'."); return false; }

        std::string inner {""}; 
        if (!(grab_until('}', cpp2::out(&inner)))) {error("Missing closing bracket."); return false; }

        inner = trim_copy(inner);
        if (CPP2_UFCS(empty)(inner)) {error("Empty range specifier. Either '{n}', '{n,}', '{,m}' '{n,m}'"); return false; }

        auto greedy {true}; 
        auto possessive {false}; 
        if (peek() == '?') {
            greedy = false;
            static_cast<void>(skip());
        }
        else {if (peek() == '+') {
            possessive = true;
            static_cast<void>(skip());
        }}

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

        CPP2_UFCS(wrap_last)(cur_state, [&, _1 = std::move(min_count), _2 = std::move(max_count)](auto const& inner) -> auto { return create_matcher("range_matcher_logic", (cpp2::to_string(std::move(inner)) + ", " + cpp2::to_string(_1) + ", " + cpp2::to_string(_2) + ", " + cpp2::to_string(std::move(greedy)) + ", " + cpp2::to_string(std::move(possessive))));  });

        return true; 
    }

#line 1841 "regex.h2"
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

        auto greedy {true}; 
        auto possessive {false}; 
        if (peek() == '?') {
            greedy = false;
            static_cast<void>(skip());
        }
        else {if (peek() == '+') {
            possessive = true;
            static_cast<void>(skip());
        }}

        if (CPP2_UFCS(empty)(cur_state)) {
            error(("'" + cpp2::to_string(c) + "' without previous element."));
            return false; 
        }

        CPP2_UFCS(wrap_last)(cur_state, [&, _1 = std::move(min_range), _2 = std::move(max_range), _3 = c](auto const& inner) -> auto { return create_matcher("special_range_matcher_logic", (cpp2::to_string(inner) + ", " + cpp2::to_string(_1) + ", " + cpp2::to_string(_2) + ", " + cpp2::to_string(std::move(greedy)) + ", " + cpp2::to_string(std::move(possessive)) + ", '" + cpp2::to_string(_3) + "'"));  });
        return true; 
    }

#line 1878 "regex.h2"
    template <typename Error_out> auto regex_parser<Error_out>::parse_until(cpp2::in<char> term) & -> void{
        char c {current()}; 
        for( ; c != '\n'; static_cast<void>(next(cpp2::out(&c))) ) {
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
            CPP2_UFCS(add)(cur_state, create_matcher("char_matcher_logic", ("'" + cpp2::to_string(c) + "', '" + cpp2::to_string(safe_tolower(c)) + "', '" + cpp2::to_string(safe_toupper(c)) + "'")));
        }
    }

#line 1900 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::parse_modifier() & -> std::string{
        std::string r {"0"}; 
        std::string sep {" | "}; 

        auto add {[&, _1 = std::move(sep)](auto const& name, auto& r) mutable -> void{
            r += (cpp2::to_string(_1) + cpp2::to_string(name));
        }}; 

        auto mod_pos {0}; 
        for( ; cpp2::cmp_less(mod_pos,CPP2_UFCS(ssize)(modifier)); mod_pos += 1 ) {
            char c {CPP2_ASSERT_IN_BOUNDS(modifier, mod_pos)}; 

            if (     c == 'i') { add("::cpp2::regex::expression_flags::case_insensitive", r); }
            else {if (c == 'm') {add("::cpp2::regex::expression_flags::multiple_lines", r); }
            else {if (c == 's') {add("::cpp2::regex::expression_flags::single_line", r); }
            else {if (c == 'n') {
                add("::cpp2::regex::expression_flags::no_group_captures", r);
                cur_state.modifiers.group_captures_have_numbers = false;
            }
            else {if (c == 'x') {
                add("::cpp2::regex::expression_flags::perl_code_syntax", r);
                cur_state.modifiers.perl_code_syntax = true;

                // Check if we have 'xx'
                mod_pos += 1;
                if (cpp2::cmp_less(mod_pos,CPP2_UFCS(ssize)(modifier)) && 'x' == CPP2_ASSERT_IN_BOUNDS(modifier, mod_pos)) {
                    add("::cpp2::regex::expression_flags::perl_code_syntax_in_classes", r);
                    cur_state.modifiers.perl_code_syntax_in_classes = true;
                }
            }
            else {error(("Unknown modifier: '" + cpp2::to_string(c) + "'")); }}}}}
        }

        return r; 
    }

#line 1936 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::parse() & -> std::string{
        auto mod {parse_modifier()}; 
        parse_until('\0');

        if (has_error) {return "Error"; }

        auto named_groups_arg {create_named_groups_arg()}; 
        auto inner {create_matcher_from_state()}; 
        auto start {create_matcher("group_matcher_start_logic", "0, ::cpp2::regex::match_modifiers_no_change, \"\", false")}; 
        auto end {create_matcher("group_matcher_end_logic", "0")}; 
        auto list {create_matcher("matcher_list", (cpp2::to_string(std::move(start)) + ", " + cpp2::to_string(std::move(inner)) + ", " + cpp2::to_string(std::move(end))))}; 
        return   create_matcher("regular_expression", (cpp2::to_string(std::move(mod)) + ", " + cpp2::to_string(cur_branch_reset_state.cur_group) + ", " + cpp2::to_string(alternatives_count) + ", " + cpp2::to_string(std::move(named_groups_arg)) + ", " + cpp2::to_string(std::move(list)))); 
    }

#line 1952 "regex.h2"
template<typename Err> [[nodiscard]] auto generate_template(cpp2::in<std::string_view> regex, cpp2::in<std::string_view> modifier, Err const& err) -> std::string{
    regex_parser<Err> parser {regex, modifier, err}; 
    auto r {CPP2_UFCS(parse)(parser)}; 
    static_cast<void>(std::move(parser));
    return r; 
}

}
}

#endif