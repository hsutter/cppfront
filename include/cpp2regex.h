
#ifndef ___INCLUDE_CPP2REGEX_H_CPP2
#define ___INCLUDE_CPP2REGEX_H_CPP2


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "regex.h2"

#line 16 "regex.h2"
namespace cpp2 {

namespace regex {

#line 32 "regex.h2"
class expression_flags;

#line 44 "regex.h2"
class range_flags;
    

#line 50 "regex.h2"
template<typename Iter> class match_group;
    

#line 57 "regex.h2"
template<typename Iter> class match_return;
    

#line 62 "regex.h2"
template<typename CharT, typename Iter, int max_groups, int max_alternatives> class match_context;

#line 147 "regex.h2"
template<bool has_change_, bool reset_, int add_, int remove_, fixed_string str> class match_modifiers_state_change;

#line 173 "regex.h2"
template<int flags_, typename Inner> class match_modifiers;

#line 196 "regex.h2"
template<typename CharT, typename ...List> class matcher_list;
    

#line 213 "regex.h2"
class true_end_func;
    

#line 226 "regex.h2"
template<typename CharT, CharT C> class single_class_entry;

#line 234 "regex.h2"
template<typename CharT, CharT Start, CharT End> class range_class_entry;

#line 242 "regex.h2"
template<typename CharT, typename ...List> class combined_class_entry;
    

#line 249 "regex.h2"
template<typename CharT, CharT ...List> class list_class_entry;
    

#line 256 "regex.h2"
template<typename CharT, fixed_string Name, typename Inner> class named_class_entry;
    

#line 261 "regex.h2"
template<typename CharT, typename Inner> class negated_class_entry;
    

#line 268 "regex.h2"
template<typename CharT, fixed_string Name, typename Inner> class shorthand_class_entry;
    

#line 320 "regex.h2"
template<typename CharT> class empty_matcher_logic;
    

#line 329 "regex.h2"
template<typename CharT, size_t alternative> class extract_position_helper;
    

#line 345 "regex.h2"
template<typename CharT, fixed_string syntax, typename base> class special_syntax_wrapper;
    

#line 358 "regex.h2"
class no_reset;
    

#line 362 "regex.h2"
template<typename Func> class on_return;

#line 377 "regex.h2"
class regex_token;

#line 402 "regex.h2"
class parse_context_modifier_state;
    

#line 409 "regex.h2"
class parse_context_group_state;

#line 447 "regex.h2"
class parse_context_branch_reset_state;
    

#line 480 "regex.h2"
class parse_context;
    

#line 861 "regex.h2"
class generation_function_context;
    

#line 877 "regex.h2"
class generation_context;

#line 1046 "regex.h2"
class regex_token_list;
    

#line 1078 "regex.h2"
class regex_token_base;
    

#line 1092 "regex.h2"
class regex_token_check;
    

#line 1107 "regex.h2"
class regex_token_code;
    

#line 1123 "regex.h2"
class regex_token_empty;
    

#line 1139 "regex.h2"
class alternative_token;
    

#line 1157 "regex.h2"
class alternative_token_gen;
    

#line 1203 "regex.h2"
template<typename CharT> class alternative_token_matcher;

#line 1229 "regex.h2"
class any_token;
    

#line 1256 "regex.h2"
class char_token;
    

#line 1300 "regex.h2"
class class_token;
    

#line 1432 "regex.h2"
template<typename CharT, bool negate, typename ...List> class class_token_matcher;

#line 1503 "regex.h2"
class escaped_char_token;
    

#line 1537 "regex.h2"
class group_ref_token;
    

#line 1669 "regex.h2"
class group_token;
    

#line 1897 "regex.h2"
class modifier_token;
    

#line 1913 "regex.h2"
template<typename CharT, bool push, typename ModifierChange> class apply_modifiers_matcher;

#line 1925 "regex.h2"
template<typename CharT> class pop_modifiers_matcher;

#line 1983 "regex.h2"
class lookahead_token;
    

#line 2082 "regex.h2"
class range_token;
    

#line 2225 "regex.h2"
template<typename CharT, int min_count, int max_count, int kind> class range_token_matcher;

#line 2350 "regex.h2"
class special_range_token;
    

#line 2440 "regex.h2"
template<typename CharT> class branch_reset_matcher_logic;
    

#line 2448 "regex.h2"
template<typename CharT, CharT C, CharT L, CharT U> class char_matcher_logic;

#line 2476 "regex.h2"
template<typename CharT, bool negate, typename ...List> class class_matcher_logic;

#line 2532 "regex.h2"
template<typename CharT, typename Matcher> class regular_expression;

#line 2620 "regex.h2"
template<typename Error_out> class regex_parser;

#line 2728 "regex.h2"
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
#include <set>

#line 16 "regex.h2"
namespace cpp2 {

namespace regex {

bool inline constexpr greedy_alternative = false;

template<typename CharT> using bview = std::basic_string_view<CharT>;
template<typename CharT> using bstring = std::basic_string<CharT>;

#line 32 "regex.h2"
class expression_flags {
    public: static const int case_insensitive;
    public: static const int multiple_lines;
    public: static const int single_line;
    public: static const int no_group_captures;
    public: static const int perl_code_syntax;
    public: static const int perl_code_syntax_in_classes;

    public: expression_flags() = default;
    public: expression_flags(expression_flags const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(expression_flags const&) -> void = delete;
};
#line 40 "regex.h2"

#line 44 "regex.h2"
class range_flags {
    public: static const int not_greedy;
    public: static const int greedy;
    public: static const int possessive;

    public: range_flags() = default;
    public: range_flags(range_flags const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_flags const&) -> void = delete;
};
#line 49 "regex.h2"

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

#line 75 "regex.h2"
    public: match_context(match_context const& that);
#line 75 "regex.h2"
    public: auto operator=(match_context const& that) -> match_context& ;
#line 75 "regex.h2"
    public: match_context(match_context&& that) noexcept;
#line 75 "regex.h2"
    public: auto operator=(match_context&& that) noexcept -> match_context& ;

#line 79 "regex.h2"
    public: [[nodiscard]] auto get_group(auto const& group) const& -> auto;

    public: [[nodiscard]] auto get_group_string(auto const& group) const& -> std::string;

#line 87 "regex.h2"
    public: [[nodiscard]] auto get_group_start(auto const& group) const& -> int;

#line 93 "regex.h2"
    public: [[nodiscard]] auto get_group_end(auto const& group) const& -> int;

#line 100 "regex.h2"
    public: auto set_group_end(auto const& group, auto const& pos) & -> void;

#line 105 "regex.h2"
    public: auto set_group_invalid(auto const& group) & -> void;

#line 109 "regex.h2"
    public: auto set_group_start(auto const& group, auto const& pos) & -> void;

#line 113 "regex.h2"
    public: [[nodiscard]] auto size() const& -> auto;

#line 117 "regex.h2"
    public: [[nodiscard]] auto get_alternative_pos(auto const& alternative) const& -> auto;

    public: auto set_alternative_pos(auto const& alternative, auto const& pos) & -> void;

#line 125 "regex.h2"
    public: [[nodiscard]] auto print_ranges() const& -> bstring<CharT>;

#line 139 "regex.h2"
    public: [[nodiscard]] auto fail() const& -> auto;
    public: [[nodiscard]] auto pass(cpp2::impl::in<Iter> cur) const& -> auto;

};

#line 147 "regex.h2"
template<bool has_change_, bool reset_, int add_, int remove_, fixed_string str> class match_modifiers_state_change {

    public: static const bool reset;
    public: static const int add;
    public: static const int remove;
    public: static const bool has_change;

    public: [[nodiscard]] constexpr static auto combine_inner(cpp2::impl::in<int> old_flags) -> auto;

#line 165 "regex.h2"
    public: [[nodiscard]] static auto to_string() -> auto;
    public: match_modifiers_state_change() = default;
    public: match_modifiers_state_change(match_modifiers_state_change const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(match_modifiers_state_change const&) -> void = delete;

#line 166 "regex.h2"
};

using match_modifiers_no_change = match_modifiers_state_change<false,false,0,0,"">;

#line 173 "regex.h2"
template<int flags_, typename Inner> class match_modifiers {

    public: static const int flags;

#line 179 "regex.h2"
    public: template<typename Change> [[nodiscard]] static auto push([[maybe_unused]] Change const& unnamed_param_1) -> auto;
    public: [[nodiscard]] static auto pop() -> auto;
    public: template<typename Change> [[nodiscard]] static auto replace([[maybe_unused]] Change const& unnamed_param_1) -> auto;

#line 186 "regex.h2"
    public: [[nodiscard]] auto has_flag(cpp2::impl::in<int> f) const& -> bool;

#line 189 "regex.h2"
};

#line 196 "regex.h2"
template<typename CharT, typename ...List> class matcher_list {
    public: [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func) -> auto;

    public: template<typename ...OtherList> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] matcher_list<CharT,OtherList...> const& unnamed_param_5) -> auto;

#line 202 "regex.h2"
    private: template<typename First, typename ...Other> [[nodiscard]] static auto match_select(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func) -> auto;

    private: [[nodiscard]] static auto match_select(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func) -> auto;

    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;

    public: template<typename Pre> [[nodiscard]] static auto prepend([[maybe_unused]] Pre const& unnamed_param_1) -> auto;
    public: matcher_list() = default;
    public: matcher_list(matcher_list const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(matcher_list const&) -> void = delete;

#line 210 "regex.h2"
};

template<typename CharT> using no_tail = matcher_list<CharT>;
class true_end_func {
    public: [[nodiscard]] auto operator()(auto const& cur, auto& ctx, [[maybe_unused]] auto const& unnamed_param_4) const& -> auto;
};

#line 226 "regex.h2"
template<typename CharT, CharT C> class single_class_entry
 {
    public: [[nodiscard]] static auto includes(cpp2::impl::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: single_class_entry() = default;
    public: single_class_entry(single_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(single_class_entry const&) -> void = delete;

#line 230 "regex.h2"
};

#line 234 "regex.h2"
template<typename CharT, CharT Start, CharT End> class range_class_entry
 {
    public: [[nodiscard]] static auto includes(cpp2::impl::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: range_class_entry() = default;
    public: range_class_entry(range_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_class_entry const&) -> void = delete;

#line 238 "regex.h2"
};

#line 242 "regex.h2"
template<typename CharT, typename ...List> class combined_class_entry {
    public: [[nodiscard]] static auto includes(cpp2::impl::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: combined_class_entry() = default;
    public: combined_class_entry(combined_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(combined_class_entry const&) -> void = delete;

#line 245 "regex.h2"
};

#line 249 "regex.h2"
template<typename CharT, CharT ...List> class list_class_entry {
    public: [[nodiscard]] static auto includes(cpp2::impl::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: list_class_entry() = default;
    public: list_class_entry(list_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(list_class_entry const&) -> void = delete;

#line 252 "regex.h2"
};

#line 256 "regex.h2"
template<typename CharT, fixed_string Name, typename Inner> class named_class_entry {
    public: [[nodiscard]] static auto includes(cpp2::impl::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: named_class_entry() = default;
    public: named_class_entry(named_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(named_class_entry const&) -> void = delete;

#line 259 "regex.h2"
};

template<typename CharT, typename Inner> class negated_class_entry: public Inner {

    public: [[nodiscard]] static auto includes(cpp2::impl::in<CharT> c) -> auto;
    public: negated_class_entry() = default;
    public: negated_class_entry(negated_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(negated_class_entry const&) -> void = delete;

#line 264 "regex.h2"
};

#line 268 "regex.h2"
template<typename CharT, fixed_string Name, typename Inner> class shorthand_class_entry {
    public: [[nodiscard]] static auto includes(cpp2::impl::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: shorthand_class_entry() = default;
    public: shorthand_class_entry(shorthand_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(shorthand_class_entry const&) -> void = delete;

#line 271 "regex.h2"
};

#line 276 "regex.h2"
template        <typename CharT> using digits_class = named_class_entry<CharT,"digits",range_class_entry<CharT,'0','9'>>;
template        <typename CharT> using lower_class = named_class_entry<CharT,"lower",range_class_entry<CharT,'a','z'>>;
template        <typename CharT> using upper_class = named_class_entry<CharT,"upper",range_class_entry<CharT,'A','Z'>>;

#line 282 "regex.h2"
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

#line 298 "regex.h2"
template                 <typename CharT> using short_digits_class = shorthand_class_entry<CharT,"\\d",digits_class<CharT>>;
template                 <typename CharT> using short_hor_space_class = shorthand_class_entry<CharT,"\\h",hor_space_class<CharT>>;
template                 <typename CharT> using short_space_class = shorthand_class_entry<CharT,"\\s",space_class<CharT>>;
template<typename CharT> using short_vert_space_class = shorthand_class_entry<CharT,"\\v",ver_space_class<CharT>>;
template                 <typename CharT> using short_word_class = shorthand_class_entry<CharT,"\\w",word_class<CharT>>;

#line 305 "regex.h2"
template                     <typename CharT> using short_not_digits_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\D",digits_class<CharT>>>;
template                     <typename CharT> using short_not_hor_space_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\H",hor_space_class<CharT>>>;
template                     <typename CharT> using short_not_space_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\S",space_class<CharT>>>;
template<typename CharT> using short_not_vert_space_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\V",ver_space_class<CharT>>>;
template                     <typename CharT> using short_not_word_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\W",word_class<CharT>>>;

#line 320 "regex.h2"
template<typename CharT> class empty_matcher_logic {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto;
    public: static auto reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: empty_matcher_logic() = default;
    public: empty_matcher_logic(empty_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(empty_matcher_logic const&) -> void = delete;

#line 324 "regex.h2"
};

#line 329 "regex.h2"
template<typename CharT, size_t alternative> class extract_position_helper {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto;

#line 338 "regex.h2"
    public: static auto reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: extract_position_helper() = default;
    public: extract_position_helper(extract_position_helper const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(extract_position_helper const&) -> void = delete;

#line 340 "regex.h2"
};

#line 345 "regex.h2"
template<typename CharT, fixed_string syntax, typename base> class special_syntax_wrapper: public base {

    public: [[nodiscard]] static auto to_string() -> auto;
    public: special_syntax_wrapper() = default;
    public: special_syntax_wrapper(special_syntax_wrapper const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(special_syntax_wrapper const&) -> void = delete;

#line 348 "regex.h2"
};

#line 358 "regex.h2"
class no_reset {
    public: auto operator()([[maybe_unused]] auto& unnamed_param_2) const& -> void;
};

template<typename Func> class on_return {

    private: Func func; 

    public: explicit on_return(Func const& f);
#line 366 "regex.h2"
    public: auto operator=(Func const& f) -> on_return& ;

#line 370 "regex.h2"
    public: ~on_return() noexcept;
    public: on_return(on_return const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(on_return const&) -> void = delete;


#line 373 "regex.h2"
};

template<typename Func> [[nodiscard]] auto make_on_return(Func const& func) -> auto;

class regex_token {

    public: std::string string_rep; 

    public: explicit regex_token(cpp2::impl::in<std::string> str);

#line 385 "regex.h2"
    public: explicit regex_token();

#line 390 "regex.h2"
    public: virtual auto generate_code([[maybe_unused]] generation_context& unnamed_param_2) const -> void = 0;

    public: virtual auto add_groups([[maybe_unused]] std::set<int>& unnamed_param_2) const -> void = 0;
    public: [[nodiscard]] auto to_string() const& -> std::string;
    public: auto set_string(cpp2::impl::in<std::string> s) & -> void;
    public: virtual ~regex_token() noexcept;

    public: regex_token(regex_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_token const&) -> void = delete;

#line 395 "regex.h2"
};

using token_ptr = std::shared_ptr<regex_token>;
using token_vec = std::vector<token_ptr>;

// State of the expression modifiers.
//
class parse_context_modifier_state {
    public: bool group_captures_have_numbers {true}; 
    public: bool perl_code_syntax {false}; 
    public: bool perl_code_syntax_in_classes {false}; 
};

// State of the current group. See '(<pattern>)'
class parse_context_group_state {

    // Current list of matchers
    public: token_vec cur_match_list {}; 

    // List of alternate matcher lists. E.g. ab|cd|xy
    public: token_vec alternate_match_lists {}; 

    public: parse_context_modifier_state modifiers {}; 

    public: auto next_alternative() & -> void;

#line 425 "regex.h2"
    public: auto swap(parse_context_group_state& t) & -> void;

#line 431 "regex.h2"
    public: [[nodiscard]] auto get_tokens() & -> token_ptr;

#line 441 "regex.h2"
    public: auto add(cpp2::impl::in<token_ptr> token) & -> void;

    public: [[nodiscard]] auto empty() const& -> bool;
};

// State for the branch reset. Takes care of the group numbering. See '(|<pattern>)'.
class parse_context_branch_reset_state {
    public: bool is_active {false}; 
    public: int cur_group {1}; // Global capture group.
    public: int max_group {1}; 
    public: int from {1}; 

    public: [[nodiscard]] auto next() & -> int;

#line 461 "regex.h2"
    public: auto set_next(cpp2::impl::in<int> g) & -> void;

#line 466 "regex.h2"
    public: auto next_alternative() & -> void;

#line 472 "regex.h2"
    public: auto set_active_reset(cpp2::impl::in<int> restart) & -> void;

#line 478 "regex.h2"
};

class parse_context {
    private: std::string_view regex; 

    private: size_t pos {0}; 

           public: std::string error_text {""}; 
           public: std::map<std::string,int> named_groups {}; 

    private: parse_context_group_state cur_group_state {}; 
    private: parse_context_branch_reset_state cur_branch_reset_state {}; 

#line 492 "regex.h2"
    public: explicit parse_context(cpp2::impl::in<std::string_view> r, cpp2::impl::in<parse_context_modifier_state> modifiers);

#line 497 "regex.h2"
    // State management functions
    //

    public: [[nodiscard]] auto start_group() & -> parse_context_group_state;

#line 507 "regex.h2"
    public: [[nodiscard]] auto end_group(cpp2::impl::in<parse_context_group_state> old_state) & -> token_ptr;

#line 513 "regex.h2"
    public: [[nodiscard]] auto get_modifiers() const& -> parse_context_modifier_state;

#line 517 "regex.h2"
    public: auto set_modifiers(cpp2::impl::in<parse_context_modifier_state> mod) & -> void;

#line 521 "regex.h2"
    // Branch reset management functions
    //

    public: [[nodiscard]] auto branch_reset_new_state() & -> parse_context_branch_reset_state;

#line 532 "regex.h2"
    public: auto branch_reset_restore_state(cpp2::impl::in<parse_context_branch_reset_state> old_state) & -> void;

#line 538 "regex.h2"
    public: auto next_alternative() & -> void;

#line 543 "regex.h2"
    // Position management functions
    //

    public: [[nodiscard]] auto get_pos() const& -> auto;

    public: [[nodiscard]] auto get_range(cpp2::impl::in<int> start, cpp2::impl::in<int> end) const& -> auto;

    public: auto add_token(cpp2::impl::in<token_ptr> token) & -> void;

#line 554 "regex.h2"
    public: [[nodiscard]] auto has_token() const& -> bool;

#line 558 "regex.h2"
    public: [[nodiscard]] auto pop_token() & -> token_ptr;

#line 568 "regex.h2"
    public: [[nodiscard]] auto get_tokens() & -> token_ptr;

#line 572 "regex.h2"
    // Group management
    public: [[nodiscard]] auto get_cur_group() const& -> int;

#line 577 "regex.h2"
    public: [[nodiscard]] auto next_group() & -> int;

#line 581 "regex.h2"
    public: auto set_named_group(cpp2::impl::in<std::string> name, cpp2::impl::in<int> id) & -> void;

#line 587 "regex.h2"
    public: [[nodiscard]] auto get_named_group(cpp2::impl::in<std::string> name) const& -> int;

#line 597 "regex.h2"
    public: [[nodiscard]] auto current() const& -> char;

    private: [[nodiscard]] auto next_impl(cpp2::impl::in<bool> in_class, cpp2::impl::in<bool> no_skip) & -> bool;

#line 609 "regex.h2"
    public: [[nodiscard]] auto next() & -> auto;
    public: [[nodiscard]] auto next_in_class() & -> auto;
    public: [[nodiscard]] auto next_no_skip() & -> auto;

    public: [[nodiscard]] auto next_n(cpp2::impl::in<int> n) & -> bool;

#line 622 "regex.h2"
    public: [[nodiscard]] auto has_next() const& -> bool;

    public: [[nodiscard]] auto valid() const& -> bool;

    public: [[nodiscard]] auto error(cpp2::impl::in<std::string> err) & -> token_ptr;

#line 631 "regex.h2"
    public: [[nodiscard]] static auto join(auto const& list, auto const& func) -> std::string;

#line 643 "regex.h2"
    public: [[nodiscard]] static auto join(cpp2::impl::in<std::vector<std::string>> list) -> auto;

    private: [[nodiscard]] auto get_next_position(cpp2::impl::in<bool> in_class, cpp2::impl::in<bool> no_skip) const& -> size_t;

#line 684 "regex.h2"
    private: [[nodiscard]] auto grab_until_impl(cpp2::impl::in<std::string> e, cpp2::impl::out<std::string> r, cpp2::impl::in<bool> any) & -> bool;

#line 705 "regex.h2"
    public: [[nodiscard]] auto grab_until(cpp2::impl::in<std::string> e, cpp2::impl::out<std::string> r) & -> auto;
    public: [[nodiscard]] auto grab_until(cpp2::impl::in<char> e, cpp2::impl::out<std::string> r) & -> auto;
    public: [[nodiscard]] auto grab_until_one_of(cpp2::impl::in<std::string> e, cpp2::impl::out<std::string> r) & -> auto;

    public: [[nodiscard]] auto grab_n(cpp2::impl::in<int> n, cpp2::impl::out<std::string> r) & -> bool;

#line 721 "regex.h2"
    public: [[nodiscard]] auto grab_number() & -> std::string;

#line 741 "regex.h2"
    private: [[nodiscard]] auto peek_impl(cpp2::impl::in<bool> in_class) const& -> char;

#line 751 "regex.h2"
    public: [[nodiscard]] auto peek() const& -> auto;
    public: [[nodiscard]] auto peek_in_class() const& -> auto;

    public: [[nodiscard]] auto parser_group_modifiers(cpp2::impl::in<std::string> change_str, cpp2::impl::out<std::string> modifier_change,
                      parse_context_modifier_state& parser_modifiers) & -> bool;

#line 819 "regex.h2"
    public: [[nodiscard]] auto parse_until(cpp2::impl::in<char> term) & -> bool;

#line 856 "regex.h2"
    public: [[nodiscard]] auto parse() & -> auto;
    public: parse_context(parse_context const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(parse_context const&) -> void = delete;


#line 859 "regex.h2"
};

class generation_function_context {
    public: std::string code {""}; 
    public: std::string tabs {""}; 

    public: auto add_tabs(cpp2::impl::in<int> c) & -> void;

#line 872 "regex.h2"
    public: auto remove_tabs(cpp2::impl::in<int> c) & -> void;

#line 875 "regex.h2"
};

class generation_context {

    private: std::vector<generation_function_context> gen_stack {1}; 

    private: bool new_state {true}; 
    private: int matcher_func {0}; 
    private: int reset_func {0}; 
    private: int temp_name {0}; 
    private: std::string entry_func {""}; 

    public: [[nodiscard]] auto match_parameters() const& -> std::string;

    public: auto add(cpp2::impl::in<std::string> s) & -> void;

#line 894 "regex.h2"
    public: auto add_check(cpp2::impl::in<std::string> check) & -> void;

#line 899 "regex.h2"
    public: auto add_statefull(cpp2::impl::in<std::string> next_func, cpp2::impl::in<std::string> c) & -> void;

#line 906 "regex.h2"
    public: [[nodiscard]] auto run(cpp2::impl::in<token_ptr> token) & -> std::string;

#line 912 "regex.h2"
    public: [[nodiscard]] auto generate_func(cpp2::impl::in<token_ptr> token) & -> std::string;

#line 920 "regex.h2"
    public: [[nodiscard]] auto generate_reset(cpp2::impl::in<std::set<int>> groups) & -> std::string;

#line 942 "regex.h2"
    public: [[nodiscard]] auto get_current() & -> generation_function_context*;

#line 946 "regex.h2"
    public: [[nodiscard]] auto get_base() & -> generation_function_context*;

#line 950 "regex.h2"
    public: [[nodiscard]] auto next_func_name() & -> std::string;

#line 954 "regex.h2"
    protected: auto start_func_named(cpp2::impl::in<std::string> name) & -> void;

#line 963 "regex.h2"
    public: [[nodiscard]] auto start_func() & -> std::string;

#line 969 "regex.h2"
    public: auto end_func_statefull(cpp2::impl::in<std::string> s) & -> void;

#line 981 "regex.h2"
    public: auto end_func() & -> void;

#line 985 "regex.h2"
    public: [[nodiscard]] auto get_entry_func() const& -> std::string;

#line 989 "regex.h2"
    protected: [[nodiscard]] auto gen_func_name() & -> std::string;

#line 995 "regex.h2"
    protected: [[nodiscard]] auto gen_reset_func_name() & -> std::string;

#line 1001 "regex.h2"
    public: [[nodiscard]] auto gen_temp() & -> std::string;

#line 1007 "regex.h2"
    public: [[nodiscard]] auto new_context() & -> generation_function_context*;

#line 1015 "regex.h2"
    public: auto finish_context() & -> void;

#line 1023 "regex.h2"
    public: [[nodiscard]] auto create_named_group_lookup(cpp2::impl::in<std::map<std::string,int>> named_groups) const& -> std::string;
    public: generation_context() = default;
    public: generation_context(generation_context const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(generation_context const&) -> void = delete;


#line 1044 "regex.h2"
};

class regex_token_list: public regex_token {

#line 1049 "regex.h2"
    public: token_vec tokens; 

    public: explicit regex_token_list(cpp2::impl::in<token_vec> t);

#line 1056 "regex.h2"
    public: virtual auto generate_code(generation_context& ctx) const -> void;

#line 1062 "regex.h2"
    public: virtual auto add_groups(std::set<int>& groups) const -> void;

#line 1068 "regex.h2"
    public: [[nodiscard]] static auto gen_string(cpp2::impl::in<token_vec> vec) -> std::string;
    public: virtual ~regex_token_list() noexcept;

    public: regex_token_list(regex_token_list const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_token_list const&) -> void = delete;


#line 1075 "regex.h2"
};

#line 1078 "regex.h2"
class regex_token_base: public regex_token {

#line 1081 "regex.h2"
    public: explicit regex_token_base(cpp2::impl::in<std::string> str);

#line 1085 "regex.h2"
    public: explicit regex_token_base();

#line 1089 "regex.h2"
    public: auto add_groups([[maybe_unused]] std::set<int>& unnamed_param_2) const -> void override;
    public: virtual ~regex_token_base() noexcept;

    public: regex_token_base(regex_token_base const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_token_base const&) -> void = delete;

#line 1090 "regex.h2"
};

class regex_token_check: public regex_token_base {

#line 1095 "regex.h2"
    private: std::string check; 

    public: explicit regex_token_check(cpp2::impl::in<std::string> str, cpp2::impl::in<std::string> check_);

#line 1102 "regex.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;
    public: virtual ~regex_token_check() noexcept;

    public: regex_token_check(regex_token_check const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_token_check const&) -> void = delete;


#line 1105 "regex.h2"
};

class regex_token_code: public regex_token_base {

#line 1110 "regex.h2"
    private: std::string code; 

    public: explicit regex_token_code(cpp2::impl::in<std::string> str, cpp2::impl::in<std::string> code_);

#line 1117 "regex.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;
    public: virtual ~regex_token_code() noexcept;

    public: regex_token_code(regex_token_code const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_token_code const&) -> void = delete;


#line 1120 "regex.h2"
};

#line 1123 "regex.h2"
class regex_token_empty: public regex_token_base {

#line 1126 "regex.h2"
    public: explicit regex_token_empty(cpp2::impl::in<std::string> str);

#line 1130 "regex.h2"
    public: auto generate_code([[maybe_unused]] generation_context& unnamed_param_2) const -> void override;
    public: virtual ~regex_token_empty() noexcept;

    public: regex_token_empty(regex_token_empty const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_token_empty const&) -> void = delete;


#line 1133 "regex.h2"
};

//  Regex syntax: |  Example: ab|ba
//
//  Non greedy implementation. First alternative that matches is chosen.
//
class alternative_token: public regex_token_base {

#line 1142 "regex.h2"
    public: explicit alternative_token();

    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 1152 "regex.h2"
    public: auto generate_code([[maybe_unused]] generation_context& unnamed_param_2) const -> void override;
    public: virtual ~alternative_token() noexcept;

    public: alternative_token(alternative_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(alternative_token const&) -> void = delete;


#line 1155 "regex.h2"
};

class alternative_token_gen: public regex_token {

#line 1161 "regex.h2"
    private: token_vec alternatives; 

    public: explicit alternative_token_gen(cpp2::impl::in<token_vec> a);

#line 1168 "regex.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 1184 "regex.h2"
    public: auto add_groups(std::set<int>& groups) const -> void override;

#line 1190 "regex.h2"
    public: [[nodiscard]] static auto gen_string(cpp2::impl::in<token_vec> a) -> std::string;
    public: virtual ~alternative_token_gen() noexcept;

    public: alternative_token_gen(alternative_token_gen const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(alternative_token_gen const&) -> void = delete;


#line 1201 "regex.h2"
};

template<typename CharT> class alternative_token_matcher {

    public: [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, auto const& tail, auto const& ...functions) -> auto;

#line 1208 "regex.h2"
    private: template<typename ...Other> [[nodiscard]] static auto match_first(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, auto const& tail, auto const& cur_func, auto const& cur_reset, Other const& ...other) -> auto;
    public: alternative_token_matcher() = default;
    public: alternative_token_matcher(alternative_token_matcher const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(alternative_token_matcher const&) -> void = delete;


#line 1225 "regex.h2"
};

//  Regex syntax: .
//
class any_token: public regex_token_base {

#line 1232 "regex.h2"
    public: explicit any_token();

    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 1240 "regex.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;
    public: virtual ~any_token() noexcept;

    public: any_token(any_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(any_token const&) -> void = delete;


#line 1243 "regex.h2"
};

template<typename CharT> [[nodiscard]] auto any_token_matcher(auto& cur, auto& ctx, auto const& modifiers) -> bool;

#line 1256 "regex.h2"
class char_token: public regex_token_base {

#line 1259 "regex.h2"
    private: char token; 

    public: explicit char_token(cpp2::impl::in<char> t);

#line 1266 "regex.h2"
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 1270 "regex.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;
    public: virtual ~char_token() noexcept;

    public: char_token(char_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(char_token const&) -> void = delete;


#line 1275 "regex.h2"
};

template<typename CharT, CharT C, CharT L, CharT U> [[nodiscard]] auto char_token_matcher(auto& cur, auto& ctx, auto const& modifiers) -> bool;

#line 1298 "regex.h2"
// Regex syntax: [<character classes>]  Example: [abcx-y[:digits:]]
//
class class_token: public regex_token_base {

#line 1303 "regex.h2"
    private: bool negate; 
    private: std::string class_str; 

    public: explicit class_token(cpp2::impl::in<bool> negate_, cpp2::impl::in<std::string> class_str_, cpp2::impl::in<std::string> str);

#line 1312 "regex.h2"
    // TODO: Rework class generation: Generate check functions for classes.
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 1419 "regex.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 1424 "regex.h2"
    private: [[nodiscard]] static auto create_matcher(cpp2::impl::in<std::string> name, cpp2::impl::in<std::string> template_arguments) -> std::string;
    public: virtual ~class_token() noexcept;

    public: class_token(class_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(class_token const&) -> void = delete;


#line 1430 "regex.h2"
};

template<typename CharT, bool negate, typename ...List> class class_token_matcher
 {
    public: [[nodiscard]] static auto match(auto& cur, auto& ctx, auto const& modifiers) -> bool;

#line 1455 "regex.h2"
    private: template<typename First, typename ...Other> [[nodiscard]] static auto match_any(cpp2::impl::in<CharT> c) -> bool;
    public: class_token_matcher() = default;
    public: class_token_matcher(class_token_matcher const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(class_token_matcher const&) -> void = delete;


#line 1467 "regex.h2"
    // TODO: Implement proper to string
    // to_string: () -> bstring<CharT> = {
    //     r: bstring<CharT> = "[";
    //     if negate {
    //         r += "^";
    //     }
    //     r += (bstring<CharT>() + ... + List::to_string());
    //     r += "]";

    //     return r;
    // }
#line 1478 "regex.h2"
};

[[nodiscard]] auto escape_token_parse(parse_context& ctx) -> token_ptr;

#line 1503 "regex.h2"
class escaped_char_token: public regex_token_base {

#line 1506 "regex.h2"
    private: char token; 

    public: explicit escaped_char_token(cpp2::impl::in<char> t);

#line 1513 "regex.h2"
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 1517 "regex.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;
    public: virtual ~escaped_char_token() noexcept;

    public: escaped_char_token(escaped_char_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(escaped_char_token const&) -> void = delete;


#line 1520 "regex.h2"
};

// Regex syntax: \K Example: ab\Kcd
//
[[nodiscard]] auto global_group_reset_token_parse(parse_context& ctx) -> token_ptr;

#line 1531 "regex.h2"
// Regex syntax: \<number>  Example: \1
//               \g{name_or_number}
//               \k{name_or_number}
//               \k<name_or_number>
//               \k'name_or_number'
//
class group_ref_token: public regex_token_base {

#line 1540 "regex.h2"
    private: int id; 

    public: explicit group_ref_token(cpp2::impl::in<int> id_, cpp2::impl::in<std::string> str);

#line 1547 "regex.h2"
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 1639 "regex.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;
    public: virtual ~group_ref_token() noexcept;

    public: group_ref_token(group_ref_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_ref_token const&) -> void = delete;


#line 1642 "regex.h2"
};

template<typename CharT, int group> [[nodiscard]] auto group_ref_token_matcher(auto& cur, auto& ctx, auto const& modifiers) -> bool;

#line 1669 "regex.h2"
class group_token: public regex_token {

#line 1672 "regex.h2"
    private: int number {-1}; 
    private: token_ptr inner {nullptr}; 
    private: std::string mod {"::cpp2::regex::match_modifiers_no_change"}; 

    public: [[nodiscard]] static auto parse_lookahead(parse_context& ctx, cpp2::impl::in<std::string> syntax, cpp2::impl::in<bool> positive) -> token_ptr;

#line 1689 "regex.h2"
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 1807 "regex.h2"
    public: [[nodiscard]] static auto gen_string(cpp2::impl::in<std::string> name, cpp2::impl::in<bool> name_brackets, cpp2::impl::in<std::string> modifiers, cpp2::impl::in<token_ptr> inner_) -> std::string;

#line 1824 "regex.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 1848 "regex.h2"
    public: auto add_groups(std::set<int>& groups) const -> void override;
    public: virtual ~group_token() noexcept;

    public: group_token() = default;
    public: group_token(group_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_token const&) -> void = delete;


#line 1854 "regex.h2"
};

// Regex syntax: \x<number> or \x{<number>}  Example: \x{62}
//
[[nodiscard]] auto hexadecimal_token_parse(parse_context& ctx) -> token_ptr;

#line 1897 "regex.h2"
class modifier_token: public regex_token_base {

#line 1900 "regex.h2"
    private: std::string mod; 

    public: explicit modifier_token(cpp2::impl::in<std::string> mod_, cpp2::impl::in<std::string> mod_str);

#line 1907 "regex.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;
    public: virtual ~modifier_token() noexcept;

    public: modifier_token(modifier_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(modifier_token const&) -> void = delete;


#line 1911 "regex.h2"
};

template<typename CharT, bool push, typename ModifierChange> class apply_modifiers_matcher {

    public: template<typename Iter, typename Modifiers> [[nodiscard]] static auto match(Iter const& cur, auto& ctx, [[maybe_unused]] Modifiers const& unnamed_param_3, auto const& end_func, auto const& tail) -> auto;
    public: apply_modifiers_matcher() = default;
    public: apply_modifiers_matcher(apply_modifiers_matcher const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(apply_modifiers_matcher const&) -> void = delete;


#line 1923 "regex.h2"
};

template<typename CharT> class pop_modifiers_matcher {

    public: template<typename Iter, typename Modifiers> [[nodiscard]] static auto match(Iter const& cur, auto& ctx, [[maybe_unused]] Modifiers const& unnamed_param_3, auto const& end_func, auto const& tail) -> auto;
    public: pop_modifiers_matcher() = default;
    public: pop_modifiers_matcher(pop_modifiers_matcher const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(pop_modifiers_matcher const&) -> void = delete;


#line 1930 "regex.h2"
};

// Regex syntax: $  Example: aa$
//
[[nodiscard]] auto line_end_token_parse(parse_context& ctx) -> token_ptr;

#line 1950 "regex.h2"
template<typename CharT, bool match_new_line, bool match_new_line_before_end> [[nodiscard]] auto line_end_token_matcher(auto const& cur, auto& ctx, auto const& modifiers) -> bool;

#line 1962 "regex.h2"
// Regex syntax: ^  Example: ^aa
//
[[nodiscard]] auto line_start_token_parse(parse_context& ctx) -> token_ptr;

#line 1976 "regex.h2"
template<typename CharT, bool match_new_line> [[nodiscard]] auto line_start_token_matcher(auto const& cur, auto& ctx, auto const& modifiers) -> bool;

#line 1981 "regex.h2"
// Regex syntax: (?=) or (?!) or (*pla), etc.  Example: (?=AA)
//
class lookahead_token: public regex_token {

#line 1986 "regex.h2"
    protected: bool positive; 
    public: token_ptr inner {nullptr}; 

    public: explicit lookahead_token(cpp2::impl::in<bool> positive_);

#line 1993 "regex.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 1999 "regex.h2"
    public: auto add_groups(std::set<int>& groups) const -> void override;
    public: virtual ~lookahead_token() noexcept;

    public: lookahead_token(lookahead_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(lookahead_token const&) -> void = delete;


#line 2002 "regex.h2"
};

template<typename CharT, bool positive> [[nodiscard]] auto lookahead_token_matcher(auto const& cur, auto& ctx, auto const& modifiers, auto const& func) -> bool;

#line 2013 "regex.h2"
// Named character classes
//

[[nodiscard]] auto named_class_token_parse(parse_context& ctx) -> token_ptr;

#line 2040 "regex.h2"
template<typename CharT> using named_class_no_new_line = class_token_matcher<CharT,true,single_class_entry<CharT,'\n'>>;
template                 <typename CharT> using named_class_digits = class_token_matcher<CharT,false,digits_class<CharT>>;
template                 <typename CharT> using named_class_hor_space = class_token_matcher<CharT,false,hor_space_class<CharT>>;
template                 <typename CharT> using named_class_space = class_token_matcher<CharT,false,space_class<CharT>>;
template                 <typename CharT> using named_class_ver_space = class_token_matcher<CharT,false,ver_space_class<CharT>>;
template                 <typename CharT> using named_class_word = class_token_matcher<CharT,false,word_class<CharT>>;

template                    <typename CharT> using named_class_not_digits = class_token_matcher<CharT,true,digits_class<CharT>>;
template<typename CharT> using named_class_not_hor_space = class_token_matcher<CharT,true,hor_space_class<CharT>>;
template                    <typename CharT> using named_class_not_space = class_token_matcher<CharT,true,space_class<CharT>>;
template<typename CharT> using named_class_not_ver_space = class_token_matcher<CharT,true,ver_space_class<CharT>>;
template                    <typename CharT> using named_class_not_word = class_token_matcher<CharT,true,word_class<CharT>>;

#line 2054 "regex.h2"
// Regex syntax: \o{<number>}  Example: \o{142}
//
[[nodiscard]] auto octal_token_parse(parse_context& ctx) -> token_ptr;

#line 2080 "regex.h2"
// Regex syntax: <matcher>{min, max}  Example: a{2,4}
//
class range_token: public regex_token {

#line 2085 "regex.h2"
    protected: int min_count {-1}; 
    protected: int max_count {-1}; 
    protected: int kind {range_flags::greedy}; 
    protected: token_ptr inner_token {nullptr}; 

    public: explicit range_token();

    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 2162 "regex.h2"
    public: auto parse_modifier(parse_context& ctx) & -> void;

#line 2173 "regex.h2"
    public: [[nodiscard]] auto gen_mod_string() const& -> std::string;

#line 2185 "regex.h2"
    public: [[nodiscard]] auto gen_range_string() const& -> std::string;

#line 2209 "regex.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 2219 "regex.h2"
    public: auto add_groups(std::set<int>& groups) const -> void override;
    public: virtual ~range_token() noexcept;

    public: range_token(range_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_token const&) -> void = delete;


#line 2223 "regex.h2"
};

template<typename CharT, int min_count, int max_count, int kind> class range_token_matcher {

    public: template<typename Iter> [[nodiscard]] static auto match(Iter const& cur, auto& ctx, auto const& modifiers, auto const& inner, auto const& reset_func, auto const& end_func, auto const& tail) -> auto;

#line 2239 "regex.h2"
    private: [[nodiscard]] static auto is_below_upper_bound(cpp2::impl::in<int> count) -> bool;

#line 2244 "regex.h2"
    private: [[nodiscard]] static auto is_below_lower_bound(cpp2::impl::in<int> count) -> bool;

#line 2249 "regex.h2"
    private: [[nodiscard]] static auto is_in_range(cpp2::impl::in<int> count) -> bool;

#line 2255 "regex.h2"
    private: template<typename Iter> [[nodiscard]] static auto match_min_count(Iter const& cur, auto& ctx, auto const& modifiers, auto const& inner, auto const& end_func, int& count_r) -> auto;

#line 2270 "regex.h2"
    private: template<typename Iter> [[nodiscard]] static auto match_greedy(cpp2::impl::in<int> count, Iter const& cur, Iter const& last_valid, auto& ctx, auto const& modifiers, auto const& inner, auto const& reset_func, auto const& end_func, auto const& other) -> match_return<Iter>;

#line 2298 "regex.h2"
    private: template<typename Iter> [[nodiscard]] static auto match_possessive(Iter const& cur, auto& ctx, auto const& modifiers, auto const& inner, auto const& end_func, auto const& other) -> match_return<Iter>;

#line 2322 "regex.h2"
    private: template<typename Iter> [[nodiscard]] static auto match_not_greedy(Iter const& cur, auto& ctx, auto const& modifiers, auto const& inner, auto const& end_func, auto const& other) -> match_return<Iter>;
    public: range_token_matcher() = default;
    public: range_token_matcher(range_token_matcher const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_token_matcher const&) -> void = delete;


#line 2346 "regex.h2"
};

// Regex syntax: *, +, or ?  Example: aa*
//
class special_range_token: public range_token {

#line 2353 "regex.h2"
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;
    public: virtual ~special_range_token() noexcept;

    public: special_range_token() = default;
    public: special_range_token(special_range_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(special_range_token const&) -> void = delete;


#line 2382 "regex.h2"
};

// Regex syntax: \b or \B  Example: \bword\b
//
// Matches the start end end of word boundaries.
//
[[nodiscard]] auto word_boundary_token_parse(parse_context& ctx) -> token_ptr;

#line 2404 "regex.h2"
template<typename CharT, bool negate> [[nodiscard]] auto word_boundary_token_matcher(auto& cur, auto& ctx, auto const& modifiers) -> bool;

#line 2430 "regex.h2"
//-----------------------------------------------------------------------
//
//  Matchers for regular expressions.
//
//-----------------------------------------------------------------------
//

#line 2438 "regex.h2"
// Regex syntax: none Example: -
//
template<typename CharT> class branch_reset_matcher_logic {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto;
    public: static auto reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: branch_reset_matcher_logic() = default;
    public: branch_reset_matcher_logic(branch_reset_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(branch_reset_matcher_logic const&) -> void = delete;

#line 2444 "regex.h2"
};

// Regex syntax: <any character>  Example: a
//
template<typename CharT, CharT C, CharT L, CharT U> class char_matcher_logic
 {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto;

#line 2469 "regex.h2"
    public: static auto reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: char_matcher_logic() = default;
    public: char_matcher_logic(char_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(char_matcher_logic const&) -> void = delete;

#line 2471 "regex.h2"
};

#line 2474 "regex.h2"
// Regex syntax: [<character classes>]  Example: [abcx-y[:digits:]]
//
template<typename CharT, bool negate, typename ...List> class class_matcher_logic
 {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto;

#line 2497 "regex.h2"
    private: template<typename First, typename ...Other> [[nodiscard]] static auto match_any(cpp2::impl::in<CharT> c) -> bool;

#line 2509 "regex.h2"
    public: static auto reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void;

    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: class_matcher_logic() = default;
    public: class_matcher_logic(class_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(class_matcher_logic const&) -> void = delete;


#line 2521 "regex.h2"
};

#line 2524 "regex.h2"
//-----------------------------------------------------------------------
//
//  Regular expression implementation.
//
//-----------------------------------------------------------------------
//

// Regular expression implementation
template<typename CharT, typename Matcher> class regular_expression {

    public: template<typename Iter> using context = match_context<CharT,Iter,Matcher::group_count::value,0>;
    public: using modifiers = match_modifiers<Matcher::initial_flags::value,int>;

    // TODO: Named multiple return has problems with templates.
    public: template<typename Iter> class search_return {
        public: bool matched; 
        public: context<Iter> ctx; 

        public: explicit search_return(cpp2::impl::in<bool> matched_, context<Iter> const& ctx_);

#line 2547 "regex.h2"
        public: [[nodiscard]] auto group_number() const& -> auto;
        public: [[nodiscard]] auto group(cpp2::impl::in<int> g) const& -> auto;
        public: [[nodiscard]] auto group_start(cpp2::impl::in<int> g) const& -> auto;
        public: [[nodiscard]] auto group_end(cpp2::impl::in<int> g) const& -> auto;

        public: [[nodiscard]] auto group(cpp2::impl::in<bstring<CharT>> g) const& -> auto;
        public: [[nodiscard]] auto group_start(cpp2::impl::in<bstring<CharT>> g) const& -> auto;
        public: [[nodiscard]] auto group_end(cpp2::impl::in<bstring<CharT>> g) const& -> auto;

        private: [[nodiscard]] auto get_group_id(cpp2::impl::in<bstring<CharT>> g) const& -> auto;
        public: search_return(search_return const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(search_return const&) -> void = delete;


#line 2563 "regex.h2"
    };

    public: [[nodiscard]] auto match(cpp2::impl::in<bview<CharT>> str) const& -> auto;
    public: [[nodiscard]] auto match(cpp2::impl::in<bview<CharT>> str, auto const& start) const& -> auto;
    public: [[nodiscard]] auto match(cpp2::impl::in<bview<CharT>> str, auto const& start, auto const& length) const& -> auto;
    public: template<typename Iter> [[nodiscard]] auto match(Iter const& start, Iter const& end) const& -> search_return<Iter>;

#line 2575 "regex.h2"
    public: [[nodiscard]] auto search(cpp2::impl::in<bview<CharT>> str) const& -> auto;
    public: [[nodiscard]] auto search(cpp2::impl::in<bview<CharT>> str, auto const& start) const& -> auto;
    public: [[nodiscard]] auto search(cpp2::impl::in<bview<CharT>> str, auto const& start, auto const& length) const& -> auto;
    public: template<typename Iter> [[nodiscard]] auto search(Iter const& start, Iter const& end) const& -> search_return<Iter>;

#line 2597 "regex.h2"
    public: [[nodiscard]] auto to_string() const& -> auto;

    // Helper functions
    //

    private: [[nodiscard]] static auto get_iter(cpp2::impl::in<bview<CharT>> str, auto const& pos) -> auto;
    public: regular_expression() = default;
    public: regular_expression(regular_expression const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regular_expression const&) -> void = delete;


#line 2610 "regex.h2"
};

//-----------------------------------------------------------------------
//
//  Parser for regular expression.
//
//-----------------------------------------------------------------------
//

// Parser and generator for regular expressions.
template<typename Error_out> class regex_parser {

    private: std::string_view regex; 
    private: std::string_view modifier; 
    private: Error_out error_out; 

    private: size_t pos {0}; 
    private: int alternatives_count {0}; 
    private: bool has_error {false}; 

    private: std::string source {""}; 

    public: explicit regex_parser(cpp2::impl::in<std::string_view> r, cpp2::impl::in<std::string_view> m, Error_out const& e);

#line 2638 "regex.h2"
    // Misc functions
    //
    public: auto error(cpp2::impl::in<std::string> message) & -> void;

#line 2645 "regex.h2"
    // Parser helper functions.

    public: [[nodiscard]] auto parser_expression_modifiers(cpp2::impl::out<parse_context_modifier_state> mods) & -> std::string;

#line 2685 "regex.h2"
    // Parsing functions
    //

    public: [[nodiscard]] auto parse() & -> std::string;
    public: regex_parser(regex_parser const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_parser const&) -> void = delete;


#line 2719 "regex.h2"
};

template<typename Err> [[nodiscard]] auto generate_template(cpp2::impl::in<std::string_view> regex, cpp2::impl::in<std::string_view> modifier, Err const& err) -> std::string;

#line 2728 "regex.h2"
}
}


//=== Cpp2 function definitions =================================================

#line 1 "regex.h2"

#line 16 "regex.h2"
namespace cpp2 {

namespace regex {

#line 25 "regex.h2"
//-----------------------------------------------------------------------
//
//  Helper structures for the expression matching.
//
//-----------------------------------------------------------------------
//

#line 33 "regex.h2"
    inline CPP2_CONSTEXPR int expression_flags::case_insensitive = 1;// mod: i
    inline CPP2_CONSTEXPR int expression_flags::multiple_lines = 2;// mod: m
    inline CPP2_CONSTEXPR int expression_flags::single_line = 4;// mod: s
    inline CPP2_CONSTEXPR int expression_flags::no_group_captures = 8;// mod: n
    inline CPP2_CONSTEXPR int expression_flags::perl_code_syntax = 16;// mod: x
    inline CPP2_CONSTEXPR int expression_flags::perl_code_syntax_in_classes = 32;// mod: xx

#line 41 "regex.h2"
// TODO: @enum as template parameter yields two error:
//     error: type 'range_flags' of non-type template parameter is not a structural type
//     error: non-type template parameter has incomplete type 'range_flags'

    inline CPP2_CONSTEXPR int range_flags::not_greedy = 1;
    inline CPP2_CONSTEXPR int range_flags::greedy = 2;
    inline CPP2_CONSTEXPR int range_flags::possessive = 3;

#line 70 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> match_context<CharT,Iter,max_groups,max_alternatives>::match_context(Iter const& begin_, Iter const& end_)
        : begin{ begin_ }
        , end{ end_ }{

#line 73 "regex.h2"
    }

#line 75 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> match_context<CharT,Iter,max_groups,max_alternatives>::match_context(match_context const& that)
                                   : begin{ that.begin }
                                   , end{ that.end }
                                   , groups{ that.groups }
                                   , alternatives_pos{ that.alternatives_pos }{}
#line 75 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> auto match_context<CharT,Iter,max_groups,max_alternatives>::operator=(match_context const& that) -> match_context& {
                                   begin = that.begin;
                                   end = that.end;
                                   groups = that.groups;
                                   alternatives_pos = that.alternatives_pos;
                                   return *this; }
#line 75 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> match_context<CharT,Iter,max_groups,max_alternatives>::match_context(match_context&& that) noexcept
                                   : begin{ std::move(that).begin }
                                   , end{ std::move(that).end }
                                   , groups{ std::move(that).groups }
                                   , alternatives_pos{ std::move(that).alternatives_pos }{}
#line 75 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> auto match_context<CharT,Iter,max_groups,max_alternatives>::operator=(match_context&& that) noexcept -> match_context& {
                                   begin = std::move(that).begin;
                                   end = std::move(that).end;
                                   groups = std::move(that).groups;
                                   alternatives_pos = std::move(that).alternatives_pos;
                                   return *this; }

    // Getter and setter for groups
    //
#line 79 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::get_group(auto const& group) const& -> auto { return CPP2_ASSERT_IN_BOUNDS(groups, group);  }

#line 81 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::get_group_string(auto const& group) const& -> std::string{
        if (cpp2::impl::cmp_greater_eq(group,max_groups) || !(CPP2_ASSERT_IN_BOUNDS(groups, group).matched)) {
            return ""; 
        }
        return std::string(CPP2_ASSERT_IN_BOUNDS(groups, group).start, CPP2_ASSERT_IN_BOUNDS(groups, group).end); 
    }
#line 87 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::get_group_start(auto const& group) const& -> int{
        if (cpp2::impl::cmp_greater_eq(group,max_groups) || !(CPP2_ASSERT_IN_BOUNDS(groups, group).matched)) {
            return 0; 
        }
        return std::distance(begin, CPP2_ASSERT_IN_BOUNDS(groups, group).start); 
    }
#line 93 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::get_group_end(auto const& group) const& -> int{
        if (cpp2::impl::cmp_greater_eq(group,max_groups) || !(CPP2_ASSERT_IN_BOUNDS(groups, group).matched)) {
            return 0; 
        }
        return std::distance(begin, CPP2_ASSERT_IN_BOUNDS(groups, group).end); 
    }

#line 100 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> auto match_context<CharT,Iter,max_groups,max_alternatives>::set_group_end(auto const& group, auto const& pos) & -> void{
        CPP2_ASSERT_IN_BOUNDS(groups, group).end = pos;
        CPP2_ASSERT_IN_BOUNDS(groups, group).matched = true;
    }

#line 105 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> auto match_context<CharT,Iter,max_groups,max_alternatives>::set_group_invalid(auto const& group) & -> void{
        CPP2_ASSERT_IN_BOUNDS(groups, group).matched = false;
    }

#line 109 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> auto match_context<CharT,Iter,max_groups,max_alternatives>::set_group_start(auto const& group, auto const& pos) & -> void{
        CPP2_ASSERT_IN_BOUNDS(groups, group).start = pos;
    }

#line 113 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::size() const& -> auto { return max_groups;  }

    // Getter and setter for alternatives

#line 117 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::get_alternative_pos(auto const& alternative) const& -> auto { return CPP2_ASSERT_IN_BOUNDS(alternatives_pos, alternative);  }

#line 119 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> auto match_context<CharT,Iter,max_groups,max_alternatives>::set_alternative_pos(auto const& alternative, auto const& pos) & -> void{
        CPP2_ASSERT_IN_BOUNDS(alternatives_pos, alternative) = pos;
    }

    // Misc functions
    //
#line 125 "regex.h2"
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

#line 139 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::fail() const& -> auto { return match_return(false, end); }
#line 140 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::pass(cpp2::impl::in<Iter> cur) const& -> auto { return match_return(true, cur);  }

#line 144 "regex.h2"
// Flag change for matching modifiers. Creates a new flag for match_modifiers.
// See expression_flags for possible flags.
//

#line 149 "regex.h2"
    template <bool has_change_, bool reset_, int add_, int remove_, fixed_string str> inline CPP2_CONSTEXPR bool match_modifiers_state_change<has_change_,reset_,add_,remove_,str>::reset = reset_;
    template <bool has_change_, bool reset_, int add_, int remove_, fixed_string str> inline CPP2_CONSTEXPR int match_modifiers_state_change<has_change_,reset_,add_,remove_,str>::add = add_;
    template <bool has_change_, bool reset_, int add_, int remove_, fixed_string str> inline CPP2_CONSTEXPR int match_modifiers_state_change<has_change_,reset_,add_,remove_,str>::remove = remove_;
    template <bool has_change_, bool reset_, int add_, int remove_, fixed_string str> inline CPP2_CONSTEXPR bool match_modifiers_state_change<has_change_,reset_,add_,remove_,str>::has_change = has_change_;

#line 154 "regex.h2"
    template <bool has_change_, bool reset_, int add_, int remove_, fixed_string str> [[nodiscard]] constexpr auto match_modifiers_state_change<has_change_,reset_,add_,remove_,str>::combine_inner(cpp2::impl::in<int> old_flags) -> auto{
        auto new_flags {old_flags}; 
        if (reset) {
            new_flags = 0;
        }
        new_flags = new_flags | add;
        new_flags = new_flags & (~remove);

        return new_flags; 
    }

#line 165 "regex.h2"
    template <bool has_change_, bool reset_, int add_, int remove_, fixed_string str> [[nodiscard]] auto match_modifiers_state_change<has_change_,reset_,add_,remove_,str>::to_string() -> auto { return CPP2_UFCS(data)(str);  }

#line 170 "regex.h2"
// Current modifiers for the regular expression.
// See expression_flags for possible flags.
//

#line 175 "regex.h2"
    template <int flags_, typename Inner> inline CPP2_CONSTEXPR int match_modifiers<flags_,Inner>::flags = flags_;

    // Push/pop management

#line 179 "regex.h2"
    template <int flags_, typename Inner> template<typename Change> [[nodiscard]] auto match_modifiers<flags_,Inner>::push([[maybe_unused]] Change const& unnamed_param_1) -> auto { return match_modifiers<Change::combine_inner(flags),match_modifiers<flags,Inner>>(); }
#line 180 "regex.h2"
    template <int flags_, typename Inner> [[nodiscard]] auto match_modifiers<flags_,Inner>::pop() -> auto { return Inner(); }
#line 181 "regex.h2"
    template <int flags_, typename Inner> template<typename Change> [[nodiscard]] auto match_modifiers<flags_,Inner>::replace([[maybe_unused]] Change const& unnamed_param_1) -> auto { return match_modifiers<Change::combine_inner(flags),Inner>();  }

    // Flag management
    //

#line 186 "regex.h2"
    template <int flags_, typename Inner> [[nodiscard]] auto match_modifiers<flags_,Inner>::has_flag(cpp2::impl::in<int> f) const& -> bool{
        return  0 != (f & flags); 
    }

#line 191 "regex.h2"
//  Represents the remainder of the regular expression.
//
//  A matcher can ask this remainder if it would match. If yes a full match of the regular expression is found.
//  Otherwise the matcher can try a different alternative.
//

#line 197 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto matcher_list<CharT,List...>::match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func) -> auto { return match_select<List...>(cur, ctx, modifiers, end_func);  }

#line 199 "regex.h2"
    template <typename CharT, typename ...List> template<typename ...OtherList> [[nodiscard]] auto matcher_list<CharT,List...>::match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] matcher_list<CharT,OtherList...> const& unnamed_param_5) -> auto { 
        return match_select<List...,OtherList...>(cur, ctx, modifiers, end_func);  }

#line 202 "regex.h2"
    template <typename CharT, typename ...List> template<typename First, typename ...Other> [[nodiscard]] auto matcher_list<CharT,List...>::match_select(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func) -> auto { 
        return First::match(cur, ctx, modifiers, end_func, matcher_list<CharT,Other...>());  }
#line 204 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto matcher_list<CharT,List...>::match_select(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func) -> auto { return end_func(cur, ctx, modifiers);  }

#line 206 "regex.h2"
    template <typename CharT, typename ...List> auto matcher_list<CharT,List...>::reset_ranges(auto& ctx) -> void { (List::reset_ranges(ctx), ...);  }
#line 207 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto matcher_list<CharT,List...>::to_string() -> auto { return (bstring<CharT>() + ... + List::to_string());  }

#line 209 "regex.h2"
    template <typename CharT, typename ...List> template<typename Pre> [[nodiscard]] auto matcher_list<CharT,List...>::prepend([[maybe_unused]] Pre const& unnamed_param_1) -> auto { return matcher_list<CharT,Pre,List...>();  }

#line 214 "regex.h2"
    [[nodiscard]] auto true_end_func::operator()(auto const& cur, auto& ctx, [[maybe_unused]] auto const& unnamed_param_4) const& -> auto { return CPP2_UFCS(pass)(ctx, cur);  }

#line 217 "regex.h2"
//-----------------------------------------------------------------------
//
//  Character classes for regular expressions.
//
//-----------------------------------------------------------------------
//

// Class syntax: <any character> Example: a
//

#line 228 "regex.h2"
    template <typename CharT, CharT C> [[nodiscard]] auto single_class_entry<CharT,C>::includes(cpp2::impl::in<CharT> c) -> auto { return c == C;  }
#line 229 "regex.h2"
    template <typename CharT, CharT C> [[nodiscard]] auto single_class_entry<CharT,C>::to_string() -> auto { return bstring<CharT>(1, C); }

#line 232 "regex.h2"
// Class syntax: - Example: a-c
//

#line 236 "regex.h2"
    template <typename CharT, CharT Start, CharT End> [[nodiscard]] auto range_class_entry<CharT,Start,End>::includes(cpp2::impl::in<CharT> c) -> auto { return [_0 = Start, _1 = c, _2 = End]{ return cpp2::impl::cmp_less_eq(_0,_1) && cpp2::impl::cmp_less_eq(_1,_2); }();  }
#line 237 "regex.h2"
    template <typename CharT, CharT Start, CharT End> [[nodiscard]] auto range_class_entry<CharT,Start,End>::to_string() -> auto { return cpp2::to_string(Start) + "-" + cpp2::to_string(End); }

#line 240 "regex.h2"
// Helper for combining two character classes
//

#line 243 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto combined_class_entry<CharT,List...>::includes(cpp2::impl::in<CharT> c) -> auto { return (false || ... || List::includes(c));  }
#line 244 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto combined_class_entry<CharT,List...>::to_string() -> auto { return (bstring<CharT>() + ... + List::to_string()); }

#line 247 "regex.h2"
// Class syntax: <list of characters>  Example: abcd
//

#line 250 "regex.h2"
    template <typename CharT, CharT ...List> [[nodiscard]] auto list_class_entry<CharT,List...>::includes(cpp2::impl::in<CharT> c) -> auto { return (false || ... || (List == c));  }
#line 251 "regex.h2"
    template <typename CharT, CharT ...List> [[nodiscard]] auto list_class_entry<CharT,List...>::to_string() -> auto { return (bstring<CharT>() + ... + List); }

#line 254 "regex.h2"
// Class syntax: [:<class name:]  Example: [:alnum:]
//

#line 257 "regex.h2"
    template <typename CharT, fixed_string Name, typename Inner> [[nodiscard]] auto named_class_entry<CharT,Name,Inner>::includes(cpp2::impl::in<CharT> c) -> auto { return Inner::includes(c);  }
#line 258 "regex.h2"
    template <typename CharT, fixed_string Name, typename Inner> [[nodiscard]] auto named_class_entry<CharT,Name,Inner>::to_string() -> auto { return "[:" + cpp2::to_string(CPP2_UFCS(data)(Name)) + ":]"; }

#line 263 "regex.h2"
    template <typename CharT, typename Inner> [[nodiscard]] auto negated_class_entry<CharT,Inner>::includes(cpp2::impl::in<CharT> c) -> auto { return !(Inner::includes(c));  }

#line 266 "regex.h2"
// Short class syntax: \<character>  Example: \w
//

#line 269 "regex.h2"
    template <typename CharT, fixed_string Name, typename Inner> [[nodiscard]] auto shorthand_class_entry<CharT,Name,Inner>::includes(cpp2::impl::in<CharT> c) -> auto { return Inner::includes(c);  }
#line 270 "regex.h2"
    template <typename CharT, fixed_string Name, typename Inner> [[nodiscard]] auto shorthand_class_entry<CharT,Name,Inner>::to_string() -> auto { return CPP2_UFCS(str)(Name); }

#line 274 "regex.h2"
// Named basic character classes
//

#line 280 "regex.h2"
// Named other classes
//

#line 296 "regex.h2"
// Shorthand class entries
//

#line 311 "regex.h2"
//-----------------------------------------------------------------------
//
//  Helper matchers for regular expressions.
//
//-----------------------------------------------------------------------
//

// Regex syntax: none Example: -
//

#line 321 "regex.h2"
    template <typename CharT> template<typename Other> [[nodiscard]] auto empty_matcher_logic<CharT>::match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto { return Other::match(cur, ctx, modifiers, end_func);  }
#line 322 "regex.h2"
    template <typename CharT> auto empty_matcher_logic<CharT>::reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void{}
#line 323 "regex.h2"
    template <typename CharT> [[nodiscard]] auto empty_matcher_logic<CharT>::to_string() -> auto { return bstring<CharT>(); }

#line 327 "regex.h2"
// Helper for greedy alternatives
//

#line 330 "regex.h2"
    template <typename CharT, size_t alternative> template<typename Other> [[nodiscard]] auto extract_position_helper<CharT,alternative>::match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto{
        auto r {Other::match(cur, ctx, modifiers, end_func)}; 
        if (r.matched) {
            CPP2_UFCS(set_alternative_pos)(ctx, alternative, cur);
        }
        return r; 
    }

#line 338 "regex.h2"
    template <typename CharT, size_t alternative> auto extract_position_helper<CharT,alternative>::reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void{}
#line 339 "regex.h2"
    template <typename CharT, size_t alternative> [[nodiscard]] auto extract_position_helper<CharT,alternative>::to_string() -> auto { return bstring<CharT>(); }

#line 342 "regex.h2"
// Helper for standard matchers with special syntax
//
//

#line 347 "regex.h2"
    template <typename CharT, fixed_string syntax, typename base> [[nodiscard]] auto special_syntax_wrapper<CharT,syntax,base>::to_string() -> auto { return CPP2_UFCS(str)(syntax); }

#line 350 "regex.h2"
//-----------------------------------------------------------------------
//
// Matchers and generators for regular expressions.
//
//-----------------------------------------------------------------------
//

#line 359 "regex.h2"
    auto no_reset::operator()([[maybe_unused]] auto& unnamed_param_2) const& -> void{}

#line 366 "regex.h2"
    template <typename Func> on_return<Func>::on_return(Func const& f)
        : func{ f }{

#line 368 "regex.h2"
    }
#line 366 "regex.h2"
    template <typename Func> auto on_return<Func>::operator=(Func const& f) -> on_return& {
        func = f;
        return *this;

#line 368 "regex.h2"
    }

#line 370 "regex.h2"
    template <typename Func> on_return<Func>::~on_return() noexcept{
        cpp2::move(*this).func();
    }

#line 375 "regex.h2"
template<typename Func> [[nodiscard]] auto make_on_return(Func const& func) -> auto { return on_return<Func>(func);  }

#line 381 "regex.h2"
    regex_token::regex_token(cpp2::impl::in<std::string> str)
        : string_rep{ str }{

#line 383 "regex.h2"
    }

#line 385 "regex.h2"
    regex_token::regex_token()
        : string_rep{ "" }{

#line 387 "regex.h2"
    }

    //parse: (inout ctx: parse_context) -> token_ptr;

#line 393 "regex.h2"
    [[nodiscard]] auto regex_token::to_string() const& -> std::string{return string_rep; }
#line 394 "regex.h2"
    auto regex_token::set_string(cpp2::impl::in<std::string> s) & -> void{string_rep = s; }

    regex_token::~regex_token() noexcept{}

#line 419 "regex.h2"
    auto parse_context_group_state::next_alternative() & -> void{
        token_vec new_list {}; 
        std::swap(new_list, cur_match_list);
        static_cast<void>(CPP2_UFCS(insert)(alternate_match_lists, CPP2_UFCS(end)(alternate_match_lists), CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_list>)(cpp2::shared, cpp2::move(new_list))));
    }

#line 425 "regex.h2"
    auto parse_context_group_state::swap(parse_context_group_state& t) & -> void{
        std::swap(cur_match_list, t.cur_match_list);
        std::swap(alternate_match_lists, t.alternate_match_lists);
        std::swap(modifiers, t.modifiers);
    }

#line 431 "regex.h2"
    [[nodiscard]] auto parse_context_group_state::get_tokens() & -> token_ptr{
        if (CPP2_UFCS(empty)(alternate_match_lists)) {
            return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_list>)(cpp2::shared, cur_match_list); 
        }
        else {
            next_alternative();
            return CPP2_UFCS_TEMPLATE(cpp2_new<alternative_token_gen>)(cpp2::shared, alternate_match_lists); 
        }
    }

#line 441 "regex.h2"
    auto parse_context_group_state::add(cpp2::impl::in<token_ptr> token) & -> void { CPP2_UFCS(push_back)(cur_match_list, token);  }

#line 443 "regex.h2"
    [[nodiscard]] auto parse_context_group_state::empty() const& -> bool { return CPP2_UFCS(empty)(cur_match_list);  }

#line 453 "regex.h2"
    [[nodiscard]] auto parse_context_branch_reset_state::next() & -> int{
        auto g {cur_group}; 
        cur_group += 1;
        max_group = max(max_group, cur_group);

        return g; 
    }

#line 461 "regex.h2"
    auto parse_context_branch_reset_state::set_next(cpp2::impl::in<int> g) & -> void{
        cur_group = g;
        max_group = max(max_group, g);
    }

#line 466 "regex.h2"
    auto parse_context_branch_reset_state::next_alternative() & -> void{
        if (is_active) {
            cur_group = from;
        }
    }

#line 472 "regex.h2"
    auto parse_context_branch_reset_state::set_active_reset(cpp2::impl::in<int> restart) & -> void{
        is_active = true;
        cur_group = restart;
        from      = restart;
        max_group = restart;
    }

#line 492 "regex.h2"
    parse_context::parse_context(cpp2::impl::in<std::string_view> r, cpp2::impl::in<parse_context_modifier_state> modifiers)
        : regex{ r }{

#line 494 "regex.h2"
        set_modifiers(modifiers);
    }

#line 500 "regex.h2"
    [[nodiscard]] auto parse_context::start_group() & -> parse_context_group_state{
        parse_context_group_state old_state {}; 
        CPP2_UFCS(swap)(old_state, cur_group_state);

        return old_state; 
    }

#line 507 "regex.h2"
    [[nodiscard]] auto parse_context::end_group(cpp2::impl::in<parse_context_group_state> old_state) & -> token_ptr{
        auto inner {CPP2_UFCS(get_tokens)(cur_group_state)}; 
        cur_group_state = old_state;
        return inner; 
    }

#line 513 "regex.h2"
    [[nodiscard]] auto parse_context::get_modifiers() const& -> parse_context_modifier_state{
        return cur_group_state.modifiers; 
    }

#line 517 "regex.h2"
    auto parse_context::set_modifiers(cpp2::impl::in<parse_context_modifier_state> mod) & -> void{
        cur_group_state.modifiers = mod;
    }

#line 524 "regex.h2"
    [[nodiscard]] auto parse_context::branch_reset_new_state() & -> parse_context_branch_reset_state{
        parse_context_branch_reset_state old_state {}; 
        std::swap(old_state, cur_branch_reset_state);

        CPP2_UFCS(set_active_reset)(cur_branch_reset_state, old_state.cur_group);
        return old_state; 
    }

#line 532 "regex.h2"
    auto parse_context::branch_reset_restore_state(cpp2::impl::in<parse_context_branch_reset_state> old_state) & -> void{
        auto max_group {cur_branch_reset_state.max_group}; 
        cur_branch_reset_state = old_state;
        CPP2_UFCS(set_next)(cur_branch_reset_state, cpp2::move(max_group));
    }

#line 538 "regex.h2"
    auto parse_context::next_alternative() & -> void{
        CPP2_UFCS(next_alternative)(cur_group_state);
        CPP2_UFCS(next_alternative)(cur_branch_reset_state);
    }

#line 546 "regex.h2"
    [[nodiscard]] auto parse_context::get_pos() const& -> auto { return pos;  }

#line 548 "regex.h2"
    [[nodiscard]] auto parse_context::get_range(cpp2::impl::in<int> start, cpp2::impl::in<int> end) const& -> auto { return std::string(CPP2_UFCS(substr)(regex, start, end - start + 1));  }

#line 550 "regex.h2"
    auto parse_context::add_token(cpp2::impl::in<token_ptr> token) & -> void{
        CPP2_UFCS(add)(cur_group_state, token);
    }

#line 554 "regex.h2"
    [[nodiscard]] auto parse_context::has_token() const& -> bool{
        return !(CPP2_UFCS(empty)(cur_group_state)); 
    }

#line 558 "regex.h2"
    [[nodiscard]] auto parse_context::pop_token() & -> token_ptr{
        token_ptr r {nullptr}; 
        if (has_token()) {
            r = CPP2_UFCS(back)(cur_group_state.cur_match_list);
            CPP2_UFCS(pop_back)(cur_group_state.cur_match_list);
        }

        return r; 
    }

#line 568 "regex.h2"
    [[nodiscard]] auto parse_context::get_tokens() & -> token_ptr{
        return CPP2_UFCS(get_tokens)(cur_group_state); 
    }

#line 573 "regex.h2"
    [[nodiscard]] auto parse_context::get_cur_group() const& -> int{
        return cur_branch_reset_state.cur_group; 
    }

#line 577 "regex.h2"
    [[nodiscard]] auto parse_context::next_group() & -> int{
        return CPP2_UFCS(next)(cur_branch_reset_state); 
    }

#line 581 "regex.h2"
    auto parse_context::set_named_group(cpp2::impl::in<std::string> name, cpp2::impl::in<int> id) & -> void{
        if (!(CPP2_UFCS(contains)(named_groups, name))) {// Redefinition of group name is not an error. The left most one is retained.
            CPP2_ASSERT_IN_BOUNDS(named_groups, name) = id;
        }
    }

#line 587 "regex.h2"
    [[nodiscard]] auto parse_context::get_named_group(cpp2::impl::in<std::string> name) const& -> int{
        auto iter {CPP2_UFCS(find)(named_groups, name)}; 
        if (iter == CPP2_UFCS(end)(named_groups)) {
             return -1; 
        }
        else {
            return (*cpp2::impl::assert_not_null(cpp2::move(iter))).second;
        }
    }

#line 597 "regex.h2"
    [[nodiscard]] auto parse_context::current() const& -> char{return CPP2_ASSERT_IN_BOUNDS(regex, pos); }

#line 599 "regex.h2"
    [[nodiscard]] auto parse_context::next_impl(cpp2::impl::in<bool> in_class, cpp2::impl::in<bool> no_skip) & -> bool{
        pos = get_next_position(in_class, no_skip);
        if (pos != CPP2_UFCS(size)(regex)) {
            return true; 
        }
        else {
            return false; 
        }
    }

#line 609 "regex.h2"
    [[nodiscard]] auto parse_context::next() & -> auto { return next_impl(false, false); }
#line 610 "regex.h2"
    [[nodiscard]] auto parse_context::next_in_class() & -> auto { return next_impl(true, false);  }
#line 611 "regex.h2"
    [[nodiscard]] auto parse_context::next_no_skip() & -> auto { return next_impl(false, true); }

#line 613 "regex.h2"
    [[nodiscard]] auto parse_context::next_n(cpp2::impl::in<int> n) & -> bool{
        auto r {true}; 
        auto cur {0}; 
        for( ; r && cpp2::impl::cmp_less(cur,n); (r = next()) ) {
            cur += 1;
        }
        return r; 
    }

#line 622 "regex.h2"
    [[nodiscard]] auto parse_context::has_next() const& -> bool{return cpp2::impl::cmp_less(pos,CPP2_UFCS(size)(regex)); }

#line 624 "regex.h2"
    [[nodiscard]] auto parse_context::valid() const& -> bool{return has_next() && CPP2_UFCS(empty)(error_text); }

#line 626 "regex.h2"
    [[nodiscard]] auto parse_context::error(cpp2::impl::in<std::string> err) & -> token_ptr{
        error_text = err;
        return nullptr; 
    }

#line 631 "regex.h2"
    [[nodiscard]] auto parse_context::join(auto const& list, auto const& func) -> std::string{
        std::string r {""}; 

        std::string separator {""}; 
        for ( auto const& cur : list ) {
            r += separator + func(cur);
            separator = ", ";
        }

        return r; 
    }

#line 643 "regex.h2"
    [[nodiscard]] auto parse_context::join(cpp2::impl::in<std::vector<std::string>> list) -> auto { return join(list, [](auto const& arg) -> auto { return arg;  });  }// Todo: Shorthand syntax for const lambda

#line 645 "regex.h2"
    [[nodiscard]] auto parse_context::get_next_position(cpp2::impl::in<bool> in_class, cpp2::impl::in<bool> no_skip) const& -> size_t{
        auto perl_syntax {false}; 
        if (!(no_skip)) {
            if (in_class) {
                perl_syntax = cur_group_state.modifiers.perl_code_syntax && cur_group_state.modifiers.perl_code_syntax_in_classes;
            }
            else {
                perl_syntax = cur_group_state.modifiers.perl_code_syntax;
            }
        }
        auto cur {pos + 1}; 
        if (cpp2::move(perl_syntax)) {
            for( ; cpp2::impl::cmp_less(cur,CPP2_UFCS(size)(regex)); (cur += 1) ) {
                auto n {CPP2_ASSERT_IN_BOUNDS(regex, cur)}; 

                if (space_class<char>::includes(n)) {
                    continue;
                }
                else {if (!(in_class) && '#' == cpp2::move(n)) {
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
        if (cpp2::impl::cmp_greater(cur,CPP2_UFCS(size)(regex))) {
            cur = CPP2_UFCS(size)(regex);
        }
        return cur; 
    }

#line 684 "regex.h2"
    [[nodiscard]] auto parse_context::grab_until_impl(cpp2::impl::in<std::string> e, cpp2::impl::out<std::string> r, cpp2::impl::in<bool> any) & -> bool{
        auto start {pos}; 
        auto end {pos}; 
        if (any) {
            end = CPP2_UFCS(find_first_of)(regex, e, pos);
        }
        else {
            end = CPP2_UFCS(find)(regex, e, pos);
        }

        if (end != std::string_view::npos) {
            r.construct(CPP2_UFCS(substr)(regex, cpp2::move(start), end - pos));
            pos = cpp2::move(end);
            return true; 
        }
        else {
            r.construct("");
            return false; 
        }
    }

#line 705 "regex.h2"
    [[nodiscard]] auto parse_context::grab_until(cpp2::impl::in<std::string> e, cpp2::impl::out<std::string> r) & -> auto { return grab_until_impl(e, cpp2::impl::out(&r), false); }
#line 706 "regex.h2"
    [[nodiscard]] auto parse_context::grab_until(cpp2::impl::in<char> e, cpp2::impl::out<std::string> r) & -> auto { return grab_until_impl(std::string(1, e), cpp2::impl::out(&r), false); }
#line 707 "regex.h2"
    [[nodiscard]] auto parse_context::grab_until_one_of(cpp2::impl::in<std::string> e, cpp2::impl::out<std::string> r) & -> auto { return grab_until_impl(e, cpp2::impl::out(&r), true);  }

#line 709 "regex.h2"
    [[nodiscard]] auto parse_context::grab_n(cpp2::impl::in<int> n, cpp2::impl::out<std::string> r) & -> bool{
        if (cpp2::impl::cmp_less_eq(pos + n,CPP2_UFCS(size)(regex))) {
            r.construct(CPP2_UFCS(substr)(regex, pos, n));
            pos += n - 1;
            return true; 
        }
        else {
            r.construct("");
            return false; 
        }
    }

#line 721 "regex.h2"
    [[nodiscard]] auto parse_context::grab_number() & -> std::string{
        auto start {pos}; 
        auto start_search {pos}; 
        if (CPP2_ASSERT_IN_BOUNDS(regex, start_search) == '-') {
            start_search += 1;
        }
        auto end {CPP2_UFCS(find_first_not_of)(regex, "1234567890", cpp2::move(start_search))};

        cpp2::impl::deferred_init<std::string> r;
        if (end != std::string::npos) {
            r.construct(CPP2_UFCS(substr)(regex, start, end - start));
            pos = cpp2::move(end) - 1;
        }
        else {
            r.construct(CPP2_UFCS(substr)(regex, cpp2::move(start)));
            pos = CPP2_UFCS(size)(regex) - 1;
        }
        return cpp2::move(r.value());
    }

#line 741 "regex.h2"
    [[nodiscard]] auto parse_context::peek_impl(cpp2::impl::in<bool> in_class) const& -> char{
        auto next_pos {get_next_position(in_class, false)}; 
        if (cpp2::impl::cmp_less(next_pos,CPP2_UFCS(size)(regex))) {
            return CPP2_ASSERT_IN_BOUNDS(regex, cpp2::move(next_pos));
        }
        else {
            return '\0'; 
        }
    }

#line 751 "regex.h2"
    [[nodiscard]] auto parse_context::peek() const& -> auto { return peek_impl(false); }
#line 752 "regex.h2"
    [[nodiscard]] auto parse_context::peek_in_class() const& -> auto { return peek_impl(true);  }

#line 754 "regex.h2"
    [[nodiscard]] auto parse_context::parser_group_modifiers(cpp2::impl::in<std::string> change_str, cpp2::impl::out<std::string> modifier_change,
                      parse_context_modifier_state& parser_modifiers) & -> bool{
        auto is_negative {false}; 
        auto is_reset {false}; 

        auto add {0}; 
        auto remove {0}; 

        auto apply {[&, _1 = (&is_negative), _2 = (&remove), _3 = (&add)](cpp2::impl::in<int> flag) mutable -> void{
            if (*cpp2::impl::assert_not_null(_1)) {
                *cpp2::impl::assert_not_null(_2) |= flag;
            }
            else {
                *cpp2::impl::assert_not_null(_3) |= flag;
            }
        }}; 

        auto iter {CPP2_UFCS(begin)(change_str)}; 
        for( ; iter != CPP2_UFCS(end)(change_str); (++iter) ) {
            auto cur {*cpp2::impl::assert_not_null(iter)};
            if (cur == '^') {
                is_reset = true;
            }
            else {if (cur == '-') {
                if (is_reset) {static_cast<void>(error("No negative modifier allowed.")); return false; }
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
                if ((iter + 1) == CPP2_UFCS(end)(change_str) || *cpp2::impl::assert_not_null((iter + 1)) != 'x') {
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
                static_cast<void>(error(("Unknown modifier: " + cpp2::to_string(cpp2::move(cur))))); return false;
            }}}}}}}
        }

        modifier_change.construct("::cpp2::regex::match_modifiers_state_change<true, " + cpp2::to_string(cpp2::move(is_reset)) + ", " + cpp2::to_string(cpp2::move(add)) + ", " + cpp2::to_string(cpp2::move(remove)) + ", \"" + cpp2::to_string(change_str) + "\">");

        return true; 
    }

#line 819 "regex.h2"
    [[nodiscard]] auto parse_context::parse_until(cpp2::impl::in<char> term) & -> bool{
        token_ptr cur_token {}; 

        for( ; valid(); static_cast<void>(next()) ) {
            if (term == current()) {break; }

            cur_token = nullptr;

            if (!(cur_token) && valid()) {cur_token = alternative_token::parse((*this)); }
            if (!(cur_token) && valid()) {cur_token = any_token::parse((*this)); }
            if (!(cur_token) && valid()) {cur_token = class_token::parse((*this)); }
            if (!(cur_token) && valid()) {cur_token = escape_token_parse((*this)); }
            if (!(cur_token) && valid()) {cur_token = global_group_reset_token_parse((*this)); }
            if (!(cur_token) && valid()) {cur_token = group_ref_token::parse((*this)); }
            if (!(cur_token) && valid()) {cur_token = group_token::parse((*this)); }
            if (!(cur_token) && valid()) {cur_token = hexadecimal_token_parse((*this)); }
            if (!(cur_token) && valid()) {cur_token = line_end_token_parse((*this)); }
            if (!(cur_token) && valid()) {cur_token = line_start_token_parse((*this)); }
            if (!(cur_token) && valid()) {cur_token = named_class_token_parse((*this)); }
            if (!(cur_token) && valid()) {cur_token = octal_token_parse((*this)); }
            if (!(cur_token) && valid()) {cur_token = range_token::parse((*this)); }
            if (!(cur_token) && valid()) {cur_token = special_range_token::parse((*this)); }
            if (!(cur_token) && valid()) {cur_token = word_boundary_token_parse((*this)); }

            // Everything else is matched as it is.
            if (!(cur_token) && valid()) {cur_token = char_token::parse((*this)); }

            if (cur_token && valid()) {
                add_token(cur_token);
            }else {
                return false; 
            }
        }

        return true; 
    }

#line 856 "regex.h2"
    [[nodiscard]] auto parse_context::parse() & -> auto { return parse_until('\0');  }

#line 865 "regex.h2"
    auto generation_function_context::add_tabs(cpp2::impl::in<int> c) & -> void{
        int i {0}; 
        for( ; cpp2::impl::cmp_less(i,c); i += 1 ) {
            tabs += "  ";
        }
    }

#line 872 "regex.h2"
    auto generation_function_context::remove_tabs(cpp2::impl::in<int> c) & -> void{
        tabs = CPP2_UFCS(substr)(tabs, 0, c * 2);
    }

#line 887 "regex.h2"
    [[nodiscard]] auto generation_context::match_parameters() const& -> std::string{return "r.pos, ctx, modifiers"; }

#line 889 "regex.h2"
    auto generation_context::add(cpp2::impl::in<std::string> s) & -> void{
        auto cur {get_current()}; 
        (*cpp2::impl::assert_not_null(cur)).code += (cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + cpp2::to_string(s) + "\n");
    }

#line 894 "regex.h2"
    auto generation_context::add_check(cpp2::impl::in<std::string> check) & -> void{
        auto cur {get_current()}; 
        (*cpp2::impl::assert_not_null(cur)).code += (cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "if !cpp2::regex::" + cpp2::to_string(check) + " { r = ctx.fail(); return r; }\n");
    }

#line 899 "regex.h2"
    auto generation_context::add_statefull(cpp2::impl::in<std::string> next_func, cpp2::impl::in<std::string> c) & -> void{
        end_func_statefull(c);

        auto name {CPP2_UFCS(substr)(next_func, 0, CPP2_UFCS(ssize)(next_func) - 2)}; 
        start_func_named(cpp2::move(name));
    }

#line 906 "regex.h2"
    [[nodiscard]] auto generation_context::run(cpp2::impl::in<token_ptr> token) & -> std::string{
        entry_func = generate_func(token);

        return (*cpp2::impl::assert_not_null(get_base())).code;
    }

#line 912 "regex.h2"
    [[nodiscard]] auto generation_context::generate_func(cpp2::impl::in<token_ptr> token) & -> std::string{
        auto name {start_func()}; 
        CPP2_UFCS(generate_code)((*cpp2::impl::assert_not_null(token)), (*this));
        end_func();

        return name; 
    }

#line 920 "regex.h2"
    [[nodiscard]] auto generation_context::generate_reset(cpp2::impl::in<std::set<int>> groups) & -> std::string{
        if (CPP2_UFCS(empty)(groups)) {
            return "cpp2::regex::no_reset()"; 
        }

        auto name {gen_reset_func_name()}; 
        auto cur {new_context()}; 

        (*cpp2::impl::assert_not_null(cur)).code += (cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + cpp2::to_string(name) + ": @struct type = {\n");
        (*cpp2::impl::assert_not_null(cur)).code += (cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "  operator(): (this, inout ctx) = {\n");
        for ( auto const& g : groups ) {
            (*cpp2::impl::assert_not_null(cur)).code += (cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "  ctx.set_group_invalid(" + cpp2::to_string(g) + ");\n");
        }
        (*cpp2::impl::assert_not_null(cur)).code += (cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "  }\n");
        (*cpp2::impl::assert_not_null(cur)).code += (cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "}\n");

        finish_context();

        return cpp2::move(name) + "()";
    }

#line 942 "regex.h2"
    [[nodiscard]] auto generation_context::get_current() & -> generation_function_context*{
        return &CPP2_UFCS(back)(gen_stack); 
    }

#line 946 "regex.h2"
    [[nodiscard]] auto generation_context::get_base() & -> generation_function_context*{
        return &CPP2_ASSERT_IN_BOUNDS_LITERAL(gen_stack, 0); 
    }

#line 950 "regex.h2"
    [[nodiscard]] auto generation_context::next_func_name() & -> std::string{
        return gen_func_name() + "()"; 
    }

#line 954 "regex.h2"
    auto generation_context::start_func_named(cpp2::impl::in<std::string> name) & -> void{
        auto cur {new_context()}; 

        (*cpp2::impl::assert_not_null(cur)).code += (cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + cpp2::to_string(name) + ": @struct type = {\n");
        (*cpp2::impl::assert_not_null(cur)).code += (cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "  operator(): (this, cur, inout ctx, modifiers, other) -> _ = {\n");
        (*cpp2::impl::assert_not_null(cur)).code += (cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "    r := ctx.pass(cur);\n");
        CPP2_UFCS(add_tabs)((*cpp2::impl::assert_not_null(cpp2::move(cur))), 2);
    }

#line 963 "regex.h2"
    [[nodiscard]] auto generation_context::start_func() & -> std::string{
        auto name {gen_func_name()}; 
        start_func_named(name);
        return cpp2::move(name) + "()";
    }

#line 969 "regex.h2"
    auto generation_context::end_func_statefull(cpp2::impl::in<std::string> s) & -> void{
        auto cur {get_current()}; 
        CPP2_UFCS(remove_tabs)((*cpp2::impl::assert_not_null(cur)), 2);
        (*cpp2::impl::assert_not_null(cur)).code += "\n";
        (*cpp2::impl::assert_not_null(cur)).code += (cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "    r = " + cpp2::to_string(s) + ";\n");
        (*cpp2::impl::assert_not_null(cur)).code += (cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "    return r;\n");
        (*cpp2::impl::assert_not_null(cur)).code += (cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "  }\n");
        (*cpp2::impl::assert_not_null(cur)).code += (cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "}\n");

        finish_context();
    }

#line 981 "regex.h2"
    auto generation_context::end_func() & -> void{
        end_func_statefull("other(r.pos, ctx, modifiers)");
    }

#line 985 "regex.h2"
    [[nodiscard]] auto generation_context::get_entry_func() const& -> std::string{
        return entry_func; 
    }

#line 989 "regex.h2"
    [[nodiscard]] auto generation_context::gen_func_name() & -> std::string{
        auto cur_id {matcher_func}; 
        matcher_func += 1;
        return { "func_" + cpp2::to_string(cpp2::move(cur_id)) };
    }

#line 995 "regex.h2"
    [[nodiscard]] auto generation_context::gen_reset_func_name() & -> std::string{
        auto cur_id {reset_func}; 
        reset_func += 1;
        return { "reset_" + cpp2::to_string(cpp2::move(cur_id)) };
    }

#line 1001 "regex.h2"
    [[nodiscard]] auto generation_context::gen_temp() & -> std::string{
        auto cur_id {temp_name}; 
        temp_name += 1;
        return { "tmp_" + cpp2::to_string(cpp2::move(cur_id)) };
    }

#line 1007 "regex.h2"
    [[nodiscard]] auto generation_context::new_context() & -> generation_function_context*{
        CPP2_UFCS(push_back)(gen_stack, generation_function_context());
        auto cur {get_current()}; 
        (*cpp2::impl::assert_not_null(cur)).tabs = "    ";

        return cur; 
    }

#line 1015 "regex.h2"
    auto generation_context::finish_context() & -> void{
        auto cur {get_current()}; 
        auto base {get_base()}; 
        (*cpp2::impl::assert_not_null(base)).code += (*cpp2::impl::assert_not_null(cpp2::move(cur))).code;

        CPP2_UFCS(pop_back)(gen_stack);
    }

#line 1023 "regex.h2"
    [[nodiscard]] auto generation_context::create_named_group_lookup(cpp2::impl::in<std::map<std::string,int>> named_groups) const& -> std::string{
        std::string res {"get_named_group_index: (name) -> int = {\n"}; 

        // Generate if selection.
        std::string sep {""}; 
        for ( auto const& cur : named_groups ) {
            res += (cpp2::to_string(sep) + "if name == \"" + cpp2::to_string(cur.first) + "\" { return " + cpp2::to_string(cur.second) + "; }");
            sep = "else ";
        }

        // Generate else branch or return if list is empty.
        if (CPP2_UFCS(empty)(named_groups)) {
            res += "  _ = name;\n";
            res += "  return -1;\n";
        }
        else {
            res += "  else { return -1; }\n";
        }
        res += "}\n";
        return res; 
    }

#line 1051 "regex.h2"
    regex_token_list::regex_token_list(cpp2::impl::in<token_vec> t)
        : regex_token{ gen_string(t) }
        , tokens{ t }{

#line 1054 "regex.h2"
    }

#line 1056 "regex.h2"
    auto regex_token_list::generate_code(generation_context& ctx) const -> void{
        for ( auto const& token : tokens ) {
            CPP2_UFCS(generate_code)((*cpp2::impl::assert_not_null(token)), ctx);
        }
    }

#line 1062 "regex.h2"
    auto regex_token_list::add_groups(std::set<int>& groups) const -> void{
        for ( auto const& token : tokens ) {
            CPP2_UFCS(add_groups)((*cpp2::impl::assert_not_null(token)), groups);
        }
    }

#line 1068 "regex.h2"
    [[nodiscard]] auto regex_token_list::gen_string(cpp2::impl::in<token_vec> vec) -> std::string{
        std::string r {""}; 
        for ( auto const& token : vec ) {
            r += CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(token)));
        }
        return r; 
    }

    regex_token_list::~regex_token_list() noexcept{}

#line 1081 "regex.h2"
    regex_token_base::regex_token_base(cpp2::impl::in<std::string> str)
        : regex_token{ str }{

#line 1083 "regex.h2"
    }

#line 1085 "regex.h2"
    regex_token_base::regex_token_base()
        : regex_token{  }{

#line 1087 "regex.h2"
    }

#line 1089 "regex.h2"
    auto regex_token_base::add_groups([[maybe_unused]] std::set<int>& unnamed_param_2) const -> void{}

    regex_token_base::~regex_token_base() noexcept{}

#line 1097 "regex.h2"
    regex_token_check::regex_token_check(cpp2::impl::in<std::string> str, cpp2::impl::in<std::string> check_)
        : regex_token_base{ str }
        , check{ check_ }{

#line 1100 "regex.h2"
    }

#line 1102 "regex.h2"
    auto regex_token_check::generate_code(generation_context& ctx) const -> void{
        CPP2_UFCS(add_check)(ctx, check + "(" + CPP2_UFCS(match_parameters)(ctx) + ")");
    }

    regex_token_check::~regex_token_check() noexcept{}

#line 1112 "regex.h2"
    regex_token_code::regex_token_code(cpp2::impl::in<std::string> str, cpp2::impl::in<std::string> code_)
        : regex_token_base{ str }
        , code{ code_ }{

#line 1115 "regex.h2"
    }

#line 1117 "regex.h2"
    auto regex_token_code::generate_code(generation_context& ctx) const -> void{
        CPP2_UFCS(add)(ctx, code);
    }

    regex_token_code::~regex_token_code() noexcept{}

#line 1126 "regex.h2"
    regex_token_empty::regex_token_empty(cpp2::impl::in<std::string> str)
        : regex_token_base{ str }{

#line 1128 "regex.h2"
    }

#line 1130 "regex.h2"
    auto regex_token_empty::generate_code([[maybe_unused]] generation_context& unnamed_param_2) const -> void{
        // Nothing.
    }

    regex_token_empty::~regex_token_empty() noexcept{}

#line 1142 "regex.h2"
    alternative_token::alternative_token()
                            : regex_token_base{  }{}

#line 1144 "regex.h2"
    [[nodiscard]] auto alternative_token::parse(parse_context& ctx) -> token_ptr{
        if (CPP2_UFCS(current)(ctx) != '|') {return nullptr; }

        if (!(CPP2_UFCS(has_token)(ctx))) {return CPP2_UFCS(error)(ctx, "Alternative with no content."); }
        CPP2_UFCS(next_alternative)(ctx);
        return CPP2_UFCS_TEMPLATE(cpp2_new<alternative_token>)(cpp2::shared); 
    }

#line 1152 "regex.h2"
    auto alternative_token::generate_code([[maybe_unused]] generation_context& unnamed_param_2) const -> void{
        // No code gen here. alternative_token_gen is created in the parse_context
    }

    alternative_token::~alternative_token() noexcept{}

#line 1163 "regex.h2"
    alternative_token_gen::alternative_token_gen(cpp2::impl::in<token_vec> a)
        : regex_token{ gen_string(a) }
        , alternatives{ a }{

#line 1166 "regex.h2"
    }

#line 1168 "regex.h2"
    auto alternative_token_gen::generate_code(generation_context& ctx) const -> void{
        std::string functions {""}; 

        for ( auto const& cur : alternatives ) {
            std::set<int> groups {}; 
            CPP2_UFCS(add_groups)((*cpp2::impl::assert_not_null(cur)), groups);

            functions += ", " + CPP2_UFCS(generate_func)(ctx, cur);
            functions += ", " + CPP2_UFCS(generate_reset)(ctx, cpp2::move(groups));
        }

        auto next_name {CPP2_UFCS(next_func_name)(ctx)}; 

        CPP2_UFCS(add_statefull)(ctx, next_name, ("cpp2::regex::alternative_token_matcher<char>::match(" + cpp2::to_string(CPP2_UFCS(match_parameters)(ctx)) + ", other, " + cpp2::to_string(next_name) + " " + cpp2::to_string(cpp2::move(functions)) + ")"));
    }

#line 1184 "regex.h2"
    auto alternative_token_gen::add_groups(std::set<int>& groups) const -> void{
        for ( auto const& cur : alternatives ) {
            CPP2_UFCS(add_groups)((*cpp2::impl::assert_not_null(cur)), groups);
        }
    }

#line 1190 "regex.h2"
    [[nodiscard]] auto alternative_token_gen::gen_string(cpp2::impl::in<token_vec> a) -> std::string{
        std::string r {""}; 
        std::string sep {""}; 

        for ( auto const& cur : a ) {
            r += sep + CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(cur)));
            sep = "|";
        }

        return r; 
    }

    alternative_token_gen::~alternative_token_gen() noexcept{}

#line 1205 "regex.h2"
    template <typename CharT> [[nodiscard]] auto alternative_token_matcher<CharT>::match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, auto const& tail, auto const& ...functions) -> auto{
        return match_first(cur, ctx, modifiers, end_func, tail, functions...); 
    }
#line 1208 "regex.h2"
    template <typename CharT> template<typename ...Other> [[nodiscard]] auto alternative_token_matcher<CharT>::match_first(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, auto const& tail, auto const& cur_func, auto const& cur_reset, Other const& ...other) -> auto{
        auto inner_call {[_0 = (tail), _1 = (end_func)](auto const& tail_cur, auto& tail_ctx, auto const& tail_modifiers) -> auto{
            return _0(tail_cur, tail_ctx, tail_modifiers, _1); 
        }}; 
        auto r {cur_func(cur, ctx, modifiers, cpp2::move(inner_call))};
        if (r.matched) {
            return r; 
        }else {
            cur_reset(ctx);

            if constexpr (0 != sizeof...(Other)) {
                return match_first(cur, ctx, modifiers, end_func, tail, other...); 
            }else {
                return CPP2_UFCS(fail)(ctx); 
            }
        }
    }

#line 1232 "regex.h2"
    any_token::any_token()
                            : regex_token_base{ "." }{}  // TODO: Base class constructor is ignored.

#line 1234 "regex.h2"
    [[nodiscard]] auto any_token::parse(parse_context& ctx) -> token_ptr{
        if ('.' != CPP2_UFCS(current)(ctx)) {return nullptr; }

        return CPP2_UFCS_TEMPLATE(cpp2_new<any_token>)(cpp2::shared); 
    }

#line 1240 "regex.h2"
    auto any_token::generate_code(generation_context& ctx) const -> void{
        CPP2_UFCS(add_check)(ctx, ("any_token_matcher<char>(" + cpp2::to_string(CPP2_UFCS(match_parameters)(ctx)) + ")"));
    }

    any_token::~any_token() noexcept{}

#line 1245 "regex.h2"
template<typename CharT> [[nodiscard]] auto any_token_matcher(auto& cur, auto& ctx, auto const& modifiers) -> bool{
    if (cur != ctx.end // Any char except the end
        && (CPP2_UFCS(has_flag)(modifiers, expression_flags::single_line) || *cpp2::impl::assert_not_null(cur) != '\n')) {// Do not match new lines in multi line mode.
        cur += 1;
        return true; 
    }
    else {
        return false; 
    }
}

#line 1261 "regex.h2"
    char_token::char_token(cpp2::impl::in<char> t)
        : regex_token_base{ std::string(1, t) }
        , token{ t }{

#line 1264 "regex.h2"
    }

#line 1266 "regex.h2"
    [[nodiscard]] auto char_token::parse(parse_context& ctx) -> token_ptr{
        return CPP2_UFCS_TEMPLATE(cpp2_new<char_token>)(cpp2::shared, CPP2_UFCS(current)(ctx)); 
    }

#line 1270 "regex.h2"
    auto char_token::generate_code(generation_context& ctx) const -> void{
        auto upper {safe_toupper(token)}; 
        auto lower {safe_tolower(token)}; 
        CPP2_UFCS(add_check)(ctx, ("char_token_matcher<char, '" + cpp2::to_string(token) + "', '" + cpp2::to_string(cpp2::move(lower)) + "', '" + cpp2::to_string(cpp2::move(upper)) + "'>(" + cpp2::to_string(CPP2_UFCS(match_parameters)(ctx)) + ")"));
    }

    char_token::~char_token() noexcept{}

#line 1277 "regex.h2"
template<typename CharT, CharT C, CharT L, CharT U> [[nodiscard]] auto char_token_matcher(auto& cur, auto& ctx, auto const& modifiers) -> bool{
    if (CPP2_UFCS(has_flag)(modifiers, expression_flags::case_insensitive)) {
        if (cur != ctx.end && (*cpp2::impl::assert_not_null(cur) == L || *cpp2::impl::assert_not_null(cur) == U)) {
            cur += 1;
            return true; 
        }
        else {
            return false; 
        }
    }
    else {
        if (cur != ctx.end && *cpp2::impl::assert_not_null(cur) == C) {
            cur += 1;
            return true; 
        }
        else {
            return false; 
        }
    }
}

#line 1306 "regex.h2"
    class_token::class_token(cpp2::impl::in<bool> negate_, cpp2::impl::in<std::string> class_str_, cpp2::impl::in<std::string> str)
        : regex_token_base{ str }
        , negate{ negate_ }
        , class_str{ class_str_ }{

#line 1310 "regex.h2"
    }

#line 1313 "regex.h2"
    [[nodiscard]] auto class_token::parse(parse_context& ctx) -> token_ptr{
        if (CPP2_UFCS(current)(ctx) != '[') {return nullptr; }

        auto start_pos {CPP2_UFCS(get_pos)(ctx)}; 

        std::vector<std::string> supported_classes {"alnum", "alpha", "ascii", "blank", "cntrl", "digits", "graph", 
                                                       "lower", "print", "punct", "space", "upper", "word", "xdigit"}; 

        std::vector<std::string> classes {}; 

        // First step: parse until the end bracket and push single chars, ranges or groups on the class stack.
        auto is_negate {false}; 
        auto first {true}; 
        auto range {false}; 
        while( CPP2_UFCS(next_in_class)(ctx) & (CPP2_UFCS(current)(ctx) != ']' || first) ) {
            if (CPP2_UFCS(current)(ctx) == '^') {
                is_negate = true;
                continue; // Skip rest of the loop. Also the first update.
            }
            if (CPP2_UFCS(current)(ctx) == '[' && CPP2_UFCS(peek_in_class)(ctx) == ':') {
                // We have a character class.
                static_cast<void>(CPP2_UFCS(next_n)(ctx, 2));// Skip [:

                std::string name {""}; 
                if (!(CPP2_UFCS(grab_until)(ctx, ":]", cpp2::impl::out(&name)))) {return CPP2_UFCS(error)(ctx, "Could not find end of character class."); }
                if (CPP2_UFCS(end)(supported_classes) == std::find(CPP2_UFCS(begin)(supported_classes), CPP2_UFCS(end)(supported_classes), name)) {
                    return CPP2_UFCS(error)(ctx, ("Unsupported character class. Supported ones are: " + cpp2::to_string(CPP2_UFCS(join)(ctx, supported_classes)))); 
                }

                CPP2_UFCS(push_back)(classes, ("[:" + cpp2::to_string(cpp2::move(name)) + ":]"));

                static_cast<void>(CPP2_UFCS(next)(ctx));// Skip ':' pointing to the ending ']'.
            }
            else {if (CPP2_UFCS(current)(ctx) == '\\') {
                if (CPP2_UFCS(next_no_skip)(ctx) && (CPP2_UFCS(current)(ctx) != ']')) {
                    if ( ' ' == CPP2_UFCS(current)(ctx) && CPP2_UFCS(get_modifiers)(ctx).perl_code_syntax && CPP2_UFCS(get_modifiers)(ctx).perl_code_syntax_in_classes) {
                        CPP2_UFCS(push_back)(classes, std::string(1, CPP2_UFCS(current)(ctx)));// TODO: UFCS error with char as argument.
                    }
                    else {
                        auto name {""}; 
                            if ('d' == CPP2_UFCS(current)(ctx)) {name = "short_digits"; }
                        else {if ('D' == CPP2_UFCS(current)(ctx)) {name = "short_not_digits"; }
                        else {if ('h' == CPP2_UFCS(current)(ctx)) {name = "short_hor_space"; }
                        else {if ('H' == CPP2_UFCS(current)(ctx)) {name = "short_not_hor_space"; }
                        else {if ('s' == CPP2_UFCS(current)(ctx)) {name = "short_space"; }
                        else {if ('S' == CPP2_UFCS(current)(ctx)) {name = "short_not_space"; }
                        else {if ('v' == CPP2_UFCS(current)(ctx)) {name = "short_ver_space"; }
                        else {if ('V' == CPP2_UFCS(current)(ctx)) {name = "short_not_ver_space"; }
                        else {if ('w' == CPP2_UFCS(current)(ctx)) {name = "short_word"; }
                        else {if ('W' == CPP2_UFCS(current)(ctx)) {name = "short_not_word"; }
                        else {
                            return CPP2_UFCS(error)(ctx, "Unknown group escape."); 
                        }}}}}}}}}}
                        CPP2_UFCS(push_back)(classes, ("[:" + cpp2::to_string(cpp2::move(name)) + ":]"));
                    }
                }else {
                    return CPP2_UFCS(error)(ctx, "Escape without a following character."); 
                }
            }
            else {if (CPP2_UFCS(current)(ctx) == '-') {
                if (first) {// Literal if first entry.
                    CPP2_UFCS(push_back)(classes, (cpp2::to_string(CPP2_UFCS(current)(ctx))));
                }else {
                    range = true;
                }
            }
            else {
                if (range) {// Modify last element to be a range.
                    CPP2_UFCS(back)(classes) += ("-" + cpp2::to_string(CPP2_UFCS(current)(ctx)));
                    range = false;
                }
                else {
                    CPP2_UFCS(push_back)(classes, (cpp2::to_string(CPP2_UFCS(current)(ctx))));
                }
            }}}

            first = false;
        }

        if (CPP2_UFCS(current)(ctx) != ']') {
            return CPP2_UFCS(error)(ctx, "Error end of character class definition before terminating ']'."); 
        }
        auto end_pos {CPP2_UFCS(get_pos)(ctx)}; 

        if (cpp2::move(range)) {// If '-' is last entry treat it as a literal char.
            CPP2_UFCS(push_back)(classes, "-");
        }

        // Second step: Wrap the item on the class stack with corresponding class implementation.
        for ( auto& cur : classes ) {
            if (CPP2_UFCS(starts_with)(cur, "[:")) {
                auto name {CPP2_UFCS(substr)(cur, 2, CPP2_UFCS(size)(cur) - 4)}; 
                cur = create_matcher((cpp2::to_string(cpp2::move(name)) + "_class"), "");
            }
            else {if (1 != CPP2_UFCS(size)(cur)) {
                cur = create_matcher("range_class_entry", ("'" + cpp2::to_string(CPP2_ASSERT_IN_BOUNDS_LITERAL(cur, 0)) + "', '" + cpp2::to_string(CPP2_ASSERT_IN_BOUNDS_LITERAL(cur, 2)) + "'"));
            }
            else {
                cur = create_matcher("single_class_entry", ("'" + cpp2::to_string(cur) + "'"));
            }}
        }

        auto inner {CPP2_UFCS(join)(ctx, cpp2::move(classes))};
        return CPP2_UFCS_TEMPLATE(cpp2_new<class_token>)(cpp2::shared, cpp2::move(is_negate), cpp2::move(inner), CPP2_UFCS(get_range)(ctx, cpp2::move(start_pos), cpp2::move(end_pos)));
    }

#line 1419 "regex.h2"
    auto class_token::generate_code(generation_context& ctx) const -> void{
        CPP2_UFCS(add_check)(ctx, ("class_token_matcher<char, " + cpp2::to_string(negate) + ", " + cpp2::to_string(class_str) + ">::match(" + cpp2::to_string(CPP2_UFCS(match_parameters)(ctx)) + ")"));
    }

#line 1424 "regex.h2"
    [[nodiscard]] auto class_token::create_matcher(cpp2::impl::in<std::string> name, cpp2::impl::in<std::string> template_arguments) -> std::string{
        auto sep {", "}; 
        if (CPP2_UFCS(empty)(template_arguments)) {sep = ""; }

        return { "::cpp2::regex::" + cpp2::to_string(name) + "<char" + cpp2::to_string(cpp2::move(sep)) + cpp2::to_string(template_arguments) + ">" };
    }

    class_token::~class_token() noexcept{}

#line 1434 "regex.h2"
    template <typename CharT, bool negate, typename ...List> [[nodiscard]] auto class_token_matcher<CharT,negate,List...>::match(auto& cur, auto& ctx, auto const& modifiers) -> bool{
        if (CPP2_UFCS(has_flag)(modifiers, expression_flags::case_insensitive)) {
            if (cur != ctx.end && negate != (match_any<List...>(safe_tolower(*cpp2::impl::assert_not_null(cur))) || match_any<List...>(safe_toupper(*cpp2::impl::assert_not_null(cur))))) {
                cur += 1;
                return true; 
            }
            else {
                return false; 
            }
        }
        else {
            if (cur != ctx.end && negate != match_any<List...>(*cpp2::impl::assert_not_null(cur))) {
                cur += 1;
                return true; 
            }
            else {
                return false; 
            }
        }
    }

#line 1455 "regex.h2"
    template <typename CharT, bool negate, typename ...List> template<typename First, typename ...Other> [[nodiscard]] auto class_token_matcher<CharT,negate,List...>::match_any(cpp2::impl::in<CharT> c) -> bool{
        bool r {First::includes(c)}; 

        if (!(r)) {
            if constexpr (0 != sizeof...(Other)) {
                r = match_any<Other...>(c);
            }
        }

        return r; 
    }

#line 1480 "regex.h2"
[[nodiscard]] auto escape_token_parse(parse_context& ctx) -> token_ptr{
    if (CPP2_UFCS(current)(ctx) != '\\') {return nullptr; }

#line 1484 "regex.h2"
    if (std::string::npos == CPP2_UFCS(find)(std::string("afenrt^.[]()*{}?+|\\"), CPP2_UFCS(peek)(ctx))) {
        return nullptr; 
    }

    static_cast<void>(CPP2_UFCS(next)(ctx));// Skip escape

    if (std::string::npos != CPP2_UFCS(find)(std::string("afenrt\\"), CPP2_UFCS(current)(ctx))) {
        // Escape of string special char
        return CPP2_UFCS_TEMPLATE(cpp2_new<escaped_char_token>)(cpp2::shared, CPP2_UFCS(current)(ctx)); 
    }else {
        // Escape of regex special char
        auto r {CPP2_UFCS_TEMPLATE(cpp2_new<char_token>)(cpp2::shared, CPP2_UFCS(current)(ctx))}; 
        CPP2_UFCS(set_string)((*cpp2::impl::assert_not_null(r)), ("\\\\" + cpp2::to_string(CPP2_UFCS(current)(ctx))));

        return r; 
    }

}

#line 1508 "regex.h2"
    escaped_char_token::escaped_char_token(cpp2::impl::in<char> t)
        : regex_token_base{ "\\\\" + cpp2::to_string(t) }
        , token{ t }{

#line 1511 "regex.h2"
    }

#line 1513 "regex.h2"
    [[nodiscard]] auto escaped_char_token::parse(parse_context& ctx) -> token_ptr{
        return CPP2_UFCS_TEMPLATE(cpp2_new<char_token>)(cpp2::shared, CPP2_UFCS(current)(ctx)); 
    }

#line 1517 "regex.h2"
    auto escaped_char_token::generate_code(generation_context& ctx) const -> void{
        CPP2_UFCS(add_check)(ctx, ("char_token_matcher<char, '\\" + cpp2::to_string(token) + "', '\\" + cpp2::to_string(token) + "', '\\" + cpp2::to_string(token) + "'>(" + cpp2::to_string(CPP2_UFCS(match_parameters)(ctx)) + ")"));
    }

    escaped_char_token::~escaped_char_token() noexcept{}

#line 1524 "regex.h2"
[[nodiscard]] auto global_group_reset_token_parse(parse_context& ctx) -> token_ptr{
    if (!((CPP2_UFCS(current)(ctx) == '\\' && CPP2_UFCS(peek)(ctx) == 'K'))) {return nullptr; }

    static_cast<void>(CPP2_UFCS(next)(ctx));// Skip escape.
    return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_code>)(cpp2::shared, "\\\\K", "ctx.set_group_start(0, r.pos);"); 
}

#line 1542 "regex.h2"
    group_ref_token::group_ref_token(cpp2::impl::in<int> id_, cpp2::impl::in<std::string> str)
        : regex_token_base{ str }
        , id{ id_ }{

#line 1545 "regex.h2"
    }

#line 1547 "regex.h2"
    [[nodiscard]] auto group_ref_token::parse(parse_context& ctx) -> token_ptr{
        if (CPP2_UFCS(current)(ctx) != '\\') {return nullptr; }

        std::string str {"\\\\"}; 
        std::string group {""}; 

        if ([_0 = '0', _1 = CPP2_UFCS(peek)(ctx), _2 = '9']{ return cpp2::impl::cmp_less_eq(_0,_1) && cpp2::impl::cmp_less_eq(_1,_2); }()) {
            static_cast<void>(CPP2_UFCS(next)(ctx));// Skip escape
            group = CPP2_UFCS(grab_number)(ctx);
            if (cpp2::impl::cmp_greater_eq(CPP2_UFCS(ssize)(group),3)) {
                // Octal syntax (\000) not a group ref matcher.
                auto number {0}; 
                if (!(string_to_int(group, number, 8))) {return CPP2_UFCS(error)(ctx, "Could not convert octal to int."); }

                char number_as_char {unsafe_narrow<char>(cpp2::move(number))};

                auto token {CPP2_UFCS_TEMPLATE(cpp2_new<char_token>)(cpp2::shared, number_as_char)}; 
                CPP2_UFCS(set_string)((*cpp2::impl::assert_not_null(token)), ("\\" + cpp2::to_string(int_to_string(cpp2::impl::as_<int>(cpp2::move(number_as_char)), 8))));

                return token; 
            }

            str += group;
            // Regular group ref
        }
        else {if ('g' == CPP2_UFCS(peek)(ctx)) {
            static_cast<void>(CPP2_UFCS(next)(ctx));// Skip escape
            if (!(CPP2_UFCS(next)(ctx))) {return CPP2_UFCS(error)(ctx, "Group escape without a following char."); }// Skip g

            str += "g";

            if (CPP2_UFCS(current)(ctx) == '{') {
                str += "{";
                if (!((CPP2_UFCS(next)(ctx) && CPP2_UFCS(grab_until)(ctx, '}', cpp2::impl::out(&group))))) {return CPP2_UFCS(error)(ctx, "No ending bracket."); }

                str += group + "}";
            }
            else {
                group = CPP2_UFCS(grab_number)(ctx);
                str += group;
            }
        }
        else {if ('k' == CPP2_UFCS(peek)(ctx)) {
            static_cast<void>(CPP2_UFCS(next)(ctx));// Skip escape
            if (!(CPP2_UFCS(next)(ctx))) {return CPP2_UFCS(error)(ctx, "Group escape without a following char."); }// Skip k

            str += "k";

            auto term_char {'\0'}; 
            if (CPP2_UFCS(current)(ctx) == '{') {term_char = '}'; }
            else {if (CPP2_UFCS(current)(ctx) == '<') {term_char = '>'; }
            else {if (CPP2_UFCS(current)(ctx) == '\'') {term_char = '\''; }
            else {
                return CPP2_UFCS(error)(ctx, "Group escape has wrong operator."); 
            }}}

            str += CPP2_UFCS(current)(ctx);

            if (!((CPP2_UFCS(next)(ctx) && CPP2_UFCS(grab_until)(ctx, term_char, cpp2::impl::out(&group))))) {return CPP2_UFCS(error)(ctx, "No ending bracket."); }

            str += group + cpp2::move(term_char);
        }
        else {
            // No group ref matcher
            return nullptr; 
        }}}

        // Parse the group
        group = trim_copy(group);
        int group_id {0}; 
        if (string_to_int(group, group_id)) {
            if (cpp2::impl::cmp_less(group_id,0)) {
                group_id = CPP2_UFCS(get_cur_group)(ctx) + group_id;

                if (cpp2::impl::cmp_less(group_id,1)) {// Negative and zero are no valid groups.
                    return CPP2_UFCS(error)(ctx, ("Relative group reference does not reference a valid group. (Would be " + cpp2::to_string(group_id) + ".)")); 
                }
            }

            if (cpp2::impl::cmp_greater_eq(group_id,CPP2_UFCS(get_cur_group)(ctx))) {
                return CPP2_UFCS(error)(ctx, "Group reference is used before the group is declared."); 
            }
        }
        else {
            // Named group
            group_id = CPP2_UFCS(get_named_group)(ctx, group);
            if (-1 == group_id) {return CPP2_UFCS(error)(ctx, ("Group names does not exist. (Name is: " + cpp2::to_string(cpp2::move(group)) + ")")); }
        }

        return CPP2_UFCS_TEMPLATE(cpp2_new<group_ref_token>)(cpp2::shared, cpp2::move(group_id), cpp2::move(str));
    }

#line 1639 "regex.h2"
    auto group_ref_token::generate_code(generation_context& ctx) const -> void{
        CPP2_UFCS(add_check)(ctx, ("group_ref_token_matcher<char, " + cpp2::to_string(id) + ">(" + cpp2::to_string(CPP2_UFCS(match_parameters)(ctx)) + ")"));
    }

    group_ref_token::~group_ref_token() noexcept{}

#line 1644 "regex.h2"
template<typename CharT, int group> [[nodiscard]] auto group_ref_token_matcher(auto& cur, auto& ctx, auto const& modifiers) -> bool{
    auto g {CPP2_UFCS(get_group)(ctx, group)}; 

    auto group_pos {g.start}; 
    for( ; group_pos != g.end && cur != ctx.end; (++group_pos, ++cur) ) {
        if (CPP2_UFCS(has_flag)(modifiers, expression_flags::case_insensitive)) {
            if (safe_tolower(*cpp2::impl::assert_not_null(group_pos)) != safe_tolower(*cpp2::impl::assert_not_null(cur))) {
                return false; 
            }
        }
        else {
            if (*cpp2::impl::assert_not_null(group_pos) != *cpp2::impl::assert_not_null(cur)) {
                return false; 
            }
        }
    }

    if (cpp2::move(group_pos) == cpp2::move(g).end) {
        return true; 
    }
    else {
        return false; 
    }
}

#line 1676 "regex.h2"
    [[nodiscard]] auto group_token::parse_lookahead(parse_context& ctx, cpp2::impl::in<std::string> syntax, cpp2::impl::in<bool> positive) -> token_ptr{
        static_cast<void>(CPP2_UFCS(next)(ctx));// Skip last token defining the syntax

        auto r {CPP2_UFCS_TEMPLATE(cpp2_new<lookahead_token>)(cpp2::shared, positive)}; 

        auto old_state {CPP2_UFCS(start_group)(ctx)}; 
        if (!(CPP2_UFCS(parse_until)(ctx, ')'))) {return CPP2_UFCS(error)(ctx, "Lookahead without a closing bracket."); }
        (*cpp2::impl::assert_not_null(r)).inner = CPP2_UFCS(end_group)(ctx, cpp2::move(old_state));
        CPP2_UFCS(set_string)((*cpp2::impl::assert_not_null(r)), ("(" + cpp2::to_string(syntax) + cpp2::to_string(CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null((*cpp2::impl::assert_not_null(r)).inner)))) + ")"));

        return r; 
    }

#line 1689 "regex.h2"
    [[nodiscard]] auto group_token::parse(parse_context& ctx) -> token_ptr{
        if (CPP2_UFCS(current)(ctx) != '(') {return nullptr; }

        auto has_id {CPP2_UFCS(get_modifiers)(ctx).group_captures_have_numbers}; 
        auto has_pattern {true}; 
        std::string group_name {""}; 
        auto group_name_brackets {true}; 
        std::string modifier_change {"::cpp2::regex::match_modifiers_no_change"}; 
        std::string modifiers {""}; 

        auto modifiers_change_to {CPP2_UFCS(get_modifiers)(ctx)}; 

        // Skip the '('
        if (!(CPP2_UFCS(next)(ctx))) {return CPP2_UFCS(error)(ctx, "Group without closing bracket."); }
        if (CPP2_UFCS(current)(ctx) == '?') {
            // Special group
            if (!(CPP2_UFCS(next_no_skip)(ctx))) {return CPP2_UFCS(error)(ctx, "Missing character after group opening."); }

            if (CPP2_UFCS(current)(ctx) == '<' || CPP2_UFCS(current)(ctx) == '\'') {
                // named group
                auto end_char {CPP2_UFCS(current)(ctx)}; 
                if (end_char == '<') {
                    end_char = '>';
                }else {
                    group_name_brackets = false;
                }
                has_id = true; // Force id for named groups.
                if (!(CPP2_UFCS(next)(ctx))) { return CPP2_UFCS(error)(ctx, "Missing ending bracket for named group."); }/* skip '<' */
                if (!(CPP2_UFCS(grab_until)(ctx, cpp2::move(end_char), cpp2::impl::out(&group_name)))) {return CPP2_UFCS(error)(ctx, "Missing ending bracket for named group."); }
                if (!(CPP2_UFCS(next)(ctx))) {return CPP2_UFCS(error)(ctx, "Group without closing bracket."); }
            }
            else {if (CPP2_UFCS(current)(ctx) == '#') {
                // Comment
                std::string comment_str {""}; 
                if (!(CPP2_UFCS(grab_until)(ctx, ")", cpp2::impl::out(&comment_str)))) {return CPP2_UFCS(error)(ctx, "Group without closing bracket."); }
                // Do not add comment. Has problems with ranges.

                return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_empty>)(cpp2::shared, ("(?#" + cpp2::to_string(cpp2::move(comment_str)) + ")"));
            }
            else {if (CPP2_UFCS(current)(ctx) == '|') {
                // Branch reset group

                if (!(CPP2_UFCS(next)(ctx))) { return CPP2_UFCS(error)(ctx, "Missing ending bracket for named group."); }/* skip '|' */

                auto old_parser_state {CPP2_UFCS(start_group)(ctx)}; 
                auto old_branch_state {CPP2_UFCS(branch_reset_new_state)(ctx)}; 
                if (!(CPP2_UFCS(parse_until)(ctx, ')'))) {return nullptr; }
                CPP2_UFCS(branch_reset_restore_state)(ctx, cpp2::move(old_branch_state));
                auto inner_ {CPP2_UFCS(end_group)(ctx, cpp2::move(old_parser_state))};

                token_vec list {CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_empty>)(cpp2::shared, "(?|"), cpp2::move(inner_), CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_empty>)(cpp2::shared, ")")};
                return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_list>)(cpp2::shared, cpp2::move(list));
            }
            else {if (CPP2_UFCS(current)(ctx) == '=' || CPP2_UFCS(current)(ctx) == '!') {
                return parse_lookahead(ctx, ("?" + cpp2::to_string(CPP2_UFCS(current)(ctx))), CPP2_UFCS(current)(ctx) == '='); 
            }
            else {
                // Simple modifier
                has_id = false;
                if (!(CPP2_UFCS(grab_until_one_of)(ctx, "):", cpp2::impl::out(&modifiers)))) {return CPP2_UFCS(error)(ctx, "Missing ending bracket for group."); }
                if (!(CPP2_UFCS(parser_group_modifiers)(ctx, modifiers, cpp2::impl::out(&modifier_change), modifiers_change_to))) {
                     return nullptr; 
                }

                if (')' == CPP2_UFCS(current)(ctx)) {
                    has_pattern = false;
                }
                else {
                    if (!(CPP2_UFCS(next)(ctx))) { return CPP2_UFCS(error)(ctx, "Missing ending bracket for group."); }/* skip ':' */
                }
            }}}}
        }
        else {if (CPP2_UFCS(current)(ctx) == '*') {
            // named pattern
            static_cast<void>(CPP2_UFCS(next)(ctx));// Skip *.
            std::string name {""}; 
            if (!(CPP2_UFCS(grab_until)(ctx, ':', cpp2::impl::out(&name)))) {return CPP2_UFCS(error)(ctx, "Missing colon for named pattern."); }

            if (name == "pla" || name == "positive_lookahead") {
                return parse_lookahead(ctx, ("*" + cpp2::to_string(cpp2::move(name)) + ":"), true);
            }
            else {if (name == "nla" || name == "negative_lookahead") {
                return parse_lookahead(ctx, ("*" + cpp2::to_string(cpp2::move(name)) + ":"), false);
            }
            else {
                return CPP2_UFCS(error)(ctx, ("Unknown named group pattern: '" + cpp2::to_string(cpp2::move(name)) + "'"));
            }}
        }}

        if (cpp2::move(has_pattern)) {
            // regular group

            auto r {CPP2_UFCS_TEMPLATE(cpp2_new<group_token>)(cpp2::shared)}; 
            if (cpp2::move(has_id)) {
                (*cpp2::impl::assert_not_null(r)).number = CPP2_UFCS(next_group)(ctx);

                if (0 != CPP2_UFCS(size)(group_name)) {
                    CPP2_UFCS(set_named_group)(ctx, group_name, (*cpp2::impl::assert_not_null(r)).number);
                }
            }

            auto old_state {CPP2_UFCS(start_group)(ctx)}; 
            CPP2_UFCS(set_modifiers)(ctx, cpp2::move(modifiers_change_to));
            if (!(CPP2_UFCS(parse_until)(ctx, ')'))) {return nullptr; }
            (*cpp2::impl::assert_not_null(r)).inner = CPP2_UFCS(end_group)(ctx, cpp2::move(old_state));
            CPP2_UFCS(set_string)((*cpp2::impl::assert_not_null(r)), gen_string(cpp2::move(group_name), cpp2::move(group_name_brackets), cpp2::move(modifiers), (*cpp2::impl::assert_not_null(r)).inner));
            (*cpp2::impl::assert_not_null(r)).mod = cpp2::move(modifier_change);

            return r; 
        }
        else {
            // Only a modifier
            CPP2_UFCS(set_modifiers)(ctx, cpp2::move(modifiers_change_to));

            return CPP2_UFCS_TEMPLATE(cpp2_new<modifier_token>)(cpp2::shared, cpp2::move(modifier_change), cpp2::move(modifiers));
        }
    }

#line 1807 "regex.h2"
    [[nodiscard]] auto group_token::gen_string(cpp2::impl::in<std::string> name, cpp2::impl::in<bool> name_brackets, cpp2::impl::in<std::string> modifiers, cpp2::impl::in<token_ptr> inner_) -> std::string{
        std::string start {"("}; 
        if (0 != CPP2_UFCS(size)(name)) {
            if (name_brackets) {
                start += ("?<" + cpp2::to_string(CPP2_UFCS(data)(name)) + ">");
            }
            else {
                start += ("?'" + cpp2::to_string(CPP2_UFCS(data)(name)) + "'");
            }
        }
        else {if (!(CPP2_UFCS(empty)(modifiers))) {
            start += "?" + modifiers + ":";
        }}

        return cpp2::move(start) + CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(inner_))) + ")";
    }

#line 1824 "regex.h2"
    auto group_token::generate_code(generation_context& ctx) const -> void{
        if (-1 != number) {
            CPP2_UFCS(add)(ctx, ("ctx.set_group_start(" + cpp2::to_string(number) + ", r.pos);"));
        }

        auto next_name {CPP2_UFCS(next_func_name)(ctx)}; 
        CPP2_UFCS(add_statefull)(ctx, next_name, ("cpp2::regex::apply_modifiers_matcher<char, true, " + cpp2::to_string(mod) + ">::match(" + cpp2::to_string(CPP2_UFCS(match_parameters)(ctx)) + ", other, " + cpp2::to_string(next_name) + ")"));

        CPP2_UFCS(generate_code)((*cpp2::impl::assert_not_null(inner)), ctx);
        if (-1 != number) {
            CPP2_UFCS(add)(ctx, ("ctx.set_group_end(" + cpp2::to_string(number) + ", r.pos);"));
            auto tmp_name {CPP2_UFCS(gen_temp)(ctx)}; 
            CPP2_UFCS(add)(ctx, (cpp2::to_string(tmp_name) + " :=  cpp2::regex::make_on_return(:() = {"));
            CPP2_UFCS(add)(ctx, "  if !r&$*.matched {");
            CPP2_UFCS(add)(ctx, ("    ctx&$*.set_group_invalid(" + cpp2::to_string(number) + ");"));
            CPP2_UFCS(add)(ctx, "  }");
            CPP2_UFCS(add)(ctx, "});");
            CPP2_UFCS(add)(ctx, ("_ = " + cpp2::to_string(cpp2::move(tmp_name)) + ";"));// TODO: Guard object problem.
        }

        next_name = CPP2_UFCS(next_func_name)(ctx);
        CPP2_UFCS(add_statefull)(ctx, next_name, ("cpp2::regex::pop_modifiers_matcher<char>::match(" + cpp2::to_string(CPP2_UFCS(match_parameters)(ctx)) + ", other, " + cpp2::to_string(next_name) + ")"));
    }

#line 1848 "regex.h2"
    auto group_token::add_groups(std::set<int>& groups) const -> void{
        CPP2_UFCS(add_groups)((*cpp2::impl::assert_not_null(inner)), groups);
        if (-1 != number) {
            static_cast<void>(CPP2_UFCS(insert)(groups, number));
        }
    }

    group_token::~group_token() noexcept{}

#line 1858 "regex.h2"
[[nodiscard]] auto hexadecimal_token_parse(parse_context& ctx) -> token_ptr{
    if (!((CPP2_UFCS(current)(ctx) == '\\' && CPP2_UFCS(peek)(ctx) == 'x'))) {return nullptr; }

    static_cast<void>(CPP2_UFCS(next)(ctx));// Skip escape.

    if (!(CPP2_UFCS(next)(ctx))) {return CPP2_UFCS(error)(ctx, "x escape without number."); }

    auto has_brackets {false}; 
    std::string number_str {""}; 
    if ('{' == CPP2_UFCS(current)(ctx)) {
        // TODO: Currently does not work since the compiler handles \x also.
        // Bracketed
        has_brackets = true;
        static_cast<void>(CPP2_UFCS(next)(ctx));// Skip '{'
        if (!(CPP2_UFCS(grab_until)(ctx, '}', cpp2::impl::out(&number_str)))) {return CPP2_UFCS(error)(ctx, "No ending bracket for \\x"); }
    }
    else {
        // grab two chars

        if (!(CPP2_UFCS(grab_n)(ctx, 2, cpp2::impl::out(&number_str)))) {return CPP2_UFCS(error)(ctx, "Missing hexadecimal digits after \\x."); }
    }

    auto number {0}; 
    if (!(string_to_int(cpp2::move(number_str), number, 16))) {return CPP2_UFCS(error)(ctx, "Could not convert hexadecimal to int."); }

    // TODO: Change for unicode.
    char number_as_char {unsafe_narrow<char>(cpp2::move(number))};

    std::string syntax {int_to_string(cpp2::impl::as_<int>(number_as_char), 16)};
    if (cpp2::move(has_brackets)) {
        syntax = { "{" + cpp2::to_string(syntax) + "}" };
    }
    syntax = { "\\\\x" + cpp2::to_string(syntax) };

    auto r {CPP2_UFCS_TEMPLATE(cpp2_new<char_token>)(cpp2::shared, cpp2::move(number_as_char))};
    CPP2_UFCS(set_string)((*cpp2::impl::assert_not_null(r)), cpp2::move(syntax));
    return r; 
}

#line 1902 "regex.h2"
    modifier_token::modifier_token(cpp2::impl::in<std::string> mod_, cpp2::impl::in<std::string> mod_str)
        : regex_token_base{ ("(?" + cpp2::to_string(mod_str) + ")") }
        , mod{ mod_ }{

#line 1905 "regex.h2"
    }

#line 1907 "regex.h2"
    auto modifier_token::generate_code(generation_context& ctx) const -> void{
        auto next_name {CPP2_UFCS(next_func_name)(ctx)}; 
        CPP2_UFCS(add_statefull)(ctx, next_name, ("cpp2::regex::apply_modifiers_matcher<char, false, " + cpp2::to_string(mod) + ">::match(" + cpp2::to_string(CPP2_UFCS(match_parameters)(ctx)) + ", other, " + cpp2::to_string(next_name) + ")"));
    }

    modifier_token::~modifier_token() noexcept{}

#line 1915 "regex.h2"
    template <typename CharT, bool push, typename ModifierChange> template<typename Iter, typename Modifiers> [[nodiscard]] auto apply_modifiers_matcher<CharT,push,ModifierChange>::match(Iter const& cur, auto& ctx, [[maybe_unused]] Modifiers const& unnamed_param_3, auto const& end_func, auto const& tail) -> auto{
        if constexpr (push) {
            return tail(cur, ctx, Modifiers::push(ModifierChange()), end_func); 
        }
        else {
            return tail(cur, ctx, Modifiers::replace(ModifierChange()), end_func); 
        }
    }

#line 1927 "regex.h2"
    template <typename CharT> template<typename Iter, typename Modifiers> [[nodiscard]] auto pop_modifiers_matcher<CharT>::match(Iter const& cur, auto& ctx, [[maybe_unused]] Modifiers const& unnamed_param_3, auto const& end_func, auto const& tail) -> auto{
        return tail(cur, ctx, Modifiers::pop(), end_func); 
    }

#line 1934 "regex.h2"
[[nodiscard]] auto line_end_token_parse(parse_context& ctx) -> token_ptr{
    if (CPP2_UFCS(current)(ctx) == '$' || (CPP2_UFCS(current)(ctx) == '\\' && CPP2_UFCS(peek)(ctx) == '$')) {
        if ((CPP2_UFCS(current)(ctx) == '\\')) {static_cast<void>(CPP2_UFCS(next)(ctx)); }// Skip escape
        return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_check>)(cpp2::shared, "\\\\$", "line_end_token_matcher<char, true, true>"); 
    }
    else {if (CPP2_UFCS(current)(ctx) == '\\' && (CPP2_UFCS(peek)(ctx) == 'z' || CPP2_UFCS(peek)(ctx) == 'Z')) {
        static_cast<void>(CPP2_UFCS(next)(ctx));// Skip escape

        auto negate {CPP2_UFCS(current)(ctx) == 'Z'}; 
        return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_check>)(cpp2::shared, ("\\\\" + cpp2::to_string(CPP2_UFCS(current)(ctx))), ("line_end_token_matcher<char, false, " + cpp2::to_string(cpp2::move(negate)) + ">"));
    }
    else {
        return nullptr; 
    }}
}

#line 1950 "regex.h2"
template<typename CharT, bool match_new_line, bool match_new_line_before_end> [[nodiscard]] auto line_end_token_matcher(auto const& cur, auto& ctx, auto const& modifiers) -> bool{
    if (cur == ctx.end || (match_new_line && CPP2_UFCS(has_flag)(modifiers, expression_flags::multiple_lines) && *cpp2::impl::assert_not_null(cur) == '\n')) {
        return true; 
    }
    else {if (match_new_line_before_end && (*cpp2::impl::assert_not_null(cur) == '\n' && (cur + 1) == ctx.end)) {// Special case for new line at end.
        return true; 
    }
    else {
        return false; 
    }}
}

#line 1964 "regex.h2"
[[nodiscard]] auto line_start_token_parse(parse_context& ctx) -> token_ptr{
    if (CPP2_UFCS(current)(ctx) != '^' && !((CPP2_UFCS(current)(ctx) == '\\' && CPP2_UFCS(peek)(ctx) == 'A'))) {return nullptr; }

    if (CPP2_UFCS(current)(ctx) == '\\') {
        static_cast<void>(CPP2_UFCS(next)(ctx));
        return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_check>)(cpp2::shared, "\\\\A", "line_start_token_matcher<char, false>"); 
    }
    else {
        return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_check>)(cpp2::shared, "^", "line_start_token_matcher<char, true>"); 
    }
}

#line 1976 "regex.h2"
template<typename CharT, bool match_new_line> [[nodiscard]] auto line_start_token_matcher(auto const& cur, auto& ctx, auto const& modifiers) -> bool{
    return cur == ctx.begin || // Start of string
           (match_new_line && CPP2_UFCS(has_flag)(modifiers, expression_flags::multiple_lines) && *cpp2::impl::assert_not_null((cur - 1)) == '\n'); // Start of new line
}

#line 1989 "regex.h2"
    lookahead_token::lookahead_token(cpp2::impl::in<bool> positive_)
        : regex_token{ "" }
        , positive{ positive_ }{

#line 1991 "regex.h2"
    }

#line 1993 "regex.h2"
    auto lookahead_token::generate_code(generation_context& ctx) const -> void{
        auto inner_name {CPP2_UFCS(generate_func)(ctx, inner)}; 

        CPP2_UFCS(add_check)(ctx, ("lookahead_token_matcher<char, " + cpp2::to_string(positive) + ">(" + cpp2::to_string(CPP2_UFCS(match_parameters)(ctx)) + ", " + cpp2::to_string(cpp2::move(inner_name)) + ")"));
    }

#line 1999 "regex.h2"
    auto lookahead_token::add_groups(std::set<int>& groups) const -> void{
        CPP2_UFCS(add_groups)((*cpp2::impl::assert_not_null(inner)), groups);
    }

    lookahead_token::~lookahead_token() noexcept{}

#line 2004 "regex.h2"
template<typename CharT, bool positive> [[nodiscard]] auto lookahead_token_matcher(auto const& cur, auto& ctx, auto const& modifiers, auto const& func) -> bool{
    auto r {func(cur, ctx, modifiers, true_end_func())}; 
    if (!(positive)) {
        r.matched = !(r.matched);
    }

    return cpp2::move(r).matched;
}

#line 2016 "regex.h2"
[[nodiscard]] auto named_class_token_parse(parse_context& ctx) -> token_ptr{
    if (CPP2_UFCS(current)(ctx) != '\\') {return nullptr; }

    auto name {""}; 
    auto c_next {CPP2_UFCS(peek)(ctx)}; 

    if ('d' == c_next) {name = "named_class_digits"; }
    else {if ('D' == c_next) {name = "named_class_not_digits"; }
    else {if ('h' == c_next) {name = "named_class_hor_space"; }
    else {if ('H' == c_next) {name = "named_class_not_hor_space"; }
    else {if ('N' == c_next) {name = "named_class_no_new_line"; }
    else {if ('s' == c_next) {name = "named_class_space"; }
    else {if ('S' == c_next) {name = "named_class_not_space"; }
    else {if ('v' == c_next) {name = "named_class_ver_space"; }
    else {if ('V' == c_next) {name = "named_class_not_ver_space"; }
    else {if ('w' == c_next) {name = "named_class_word"; }
    else {if ('W' == cpp2::move(c_next)) {name = "named_class_not_word"; }
    else {return nullptr; }}}}}}}}}}}

    static_cast<void>(CPP2_UFCS(next)(ctx));// Skip escape

    return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_check>)(cpp2::shared, ("\\\\" + cpp2::to_string(CPP2_UFCS(current)(ctx))), (cpp2::to_string(cpp2::move(name)) + "<char>::match"));
}

#line 2056 "regex.h2"
[[nodiscard]] auto octal_token_parse(parse_context& ctx) -> token_ptr{
    if (!((CPP2_UFCS(current)(ctx) == '\\' && CPP2_UFCS(peek)(ctx) == 'o'))) {return nullptr; }

    static_cast<void>(CPP2_UFCS(next)(ctx));// Skip escape.

    if (!(CPP2_UFCS(next)(ctx))) {return CPP2_UFCS(error)(ctx, "o escape without number."); }
    if (CPP2_UFCS(current)(ctx) != '{') {return CPP2_UFCS(error)(ctx, "Missing opening bracket for \\o."); }

    std::string number_str {""}; 
    static_cast<void>(CPP2_UFCS(next)(ctx));// Skip '{'
    if (!(CPP2_UFCS(grab_until)(ctx, '}', cpp2::impl::out(&number_str)))) {return CPP2_UFCS(error)(ctx, "No ending bracket for \\o"); }

    auto number {0}; 
    if (!(string_to_int(cpp2::move(number_str), number, 8))) {return CPP2_UFCS(error)(ctx, "Could not convert octal to int."); }

    // TODO: Change for unicode.
    char number_as_char {unsafe_narrow<char>(cpp2::move(number))};

    std::string syntax {"\\o{" + cpp2::to_string(int_to_string(cpp2::impl::as_<int>(number_as_char), 8)) + "}"};
    auto r {CPP2_UFCS_TEMPLATE(cpp2_new<char_token>)(cpp2::shared, cpp2::move(number_as_char))};
    CPP2_UFCS(set_string)((*cpp2::impl::assert_not_null(r)), cpp2::move(syntax));
    return r; 
}

#line 2090 "regex.h2"
    range_token::range_token()
                             : regex_token{ "" }{}

#line 2092 "regex.h2"
    [[nodiscard]] auto range_token::parse(parse_context& ctx) -> token_ptr{
        auto r {CPP2_UFCS_TEMPLATE(cpp2_new<range_token>)(cpp2::shared)}; 
        if (CPP2_UFCS(current)(ctx) == '{') {
            if (!(CPP2_UFCS(has_token)(ctx))) {return CPP2_UFCS(error)(ctx, "'{' without previous element."); }

            std::string inner {""}; 
            if (!(CPP2_UFCS(grab_until)(ctx, '}', cpp2::impl::out(&inner)))) {return CPP2_UFCS(error)(ctx, "Missing closing bracket '}'."); }

            inner = trim_copy(CPP2_UFCS(substr)(inner, 1));// Remove '{' and white spaces.
            if (CPP2_UFCS(empty)(inner)) {return CPP2_UFCS(error)(ctx, "Empty range specifier. Either '{n}', '{n,}', '{,m}' '{n,m}'"); }

            // Non-greedy or possessive
            CPP2_UFCS(parse_modifier)((*cpp2::impl::assert_not_null(r)), ctx);

            // Get range arguments
            std::string min_count_str {"-1"}; 
            std::string max_count_str {"-1"}; 

            size_t sep {CPP2_UFCS(find)(inner, ",")}; 
            if (sep == std::string::npos) {
                min_count_str = inner;
                max_count_str = inner;
                if (!(string_to_int(cpp2::move(inner), (*cpp2::impl::assert_not_null(r)).min_count))) {return CPP2_UFCS(error)(ctx, "Could not convert range to number."); }
                (*cpp2::impl::assert_not_null(r)).max_count = (*cpp2::impl::assert_not_null(r)).min_count;
            }
            else {
                std::string inner_first {trim_copy(CPP2_UFCS(substr)(inner, 0, sep))}; 
                std::string inner_last {trim_copy(CPP2_UFCS(substr)(cpp2::move(inner), cpp2::move(sep) + 1))};

                if ((CPP2_UFCS(empty)(inner_first) && CPP2_UFCS(empty)(inner_last))) {
                    return CPP2_UFCS(error)(ctx, "Empty range specifier. Either '{n}', '{n,}', '{,m}' '{n,m}'"); 
                }

                if (!(CPP2_UFCS(empty)(inner_first))) {
                    min_count_str = inner_first;
                    if (!(string_to_int(cpp2::move(inner_first), (*cpp2::impl::assert_not_null(r)).min_count))) {return CPP2_UFCS(error)(ctx, "Could not convert range to number."); }
                }
                if (!(CPP2_UFCS(empty)(inner_last))) {
                    max_count_str = inner_last;
                    if (!(string_to_int(cpp2::move(inner_last), (*cpp2::impl::assert_not_null(r)).max_count))) {return CPP2_UFCS(error)(ctx, "Could not convert range to number."); }
                }
            }

#line 2136 "regex.h2"
            // Check validity of the range.
            if (-1 != (*cpp2::impl::assert_not_null(r)).min_count) {
                if (!((cpp2::impl::cmp_less_eq(0,(*cpp2::impl::assert_not_null(r)).min_count)))) {
                    return CPP2_UFCS(error)(ctx, ("Min value in range is negative. Have " + cpp2::to_string((*cpp2::impl::assert_not_null(r)).min_count) + ")"));
                }
            }
            if (-1 != (*cpp2::impl::assert_not_null(r)).max_count) {
                if (!((cpp2::impl::cmp_less_eq(0,(*cpp2::impl::assert_not_null(r)).max_count)))) {
                    return CPP2_UFCS(error)(ctx, ("Max value in range is negative. Have " + cpp2::to_string((*cpp2::impl::assert_not_null(r)).max_count) + ")"));
                }
                if (-1 != (*cpp2::impl::assert_not_null(r)).min_count) {
                    if (!((cpp2::impl::cmp_less_eq((*cpp2::impl::assert_not_null(r)).min_count,(*cpp2::impl::assert_not_null(r)).max_count)))) {
                        return CPP2_UFCS(error)(ctx, ("Min and max values in range are wrong it should hold 0 <= min <= max. Have 0 <= " + cpp2::to_string((*cpp2::impl::assert_not_null(r)).min_count) + " <= " + cpp2::to_string((*cpp2::impl::assert_not_null(r)).max_count)));
                    }
                }
            }

            (*cpp2::impl::assert_not_null(r)).inner_token = CPP2_UFCS(pop_token)(ctx);
            (*cpp2::impl::assert_not_null(r)).string_rep = CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null((*cpp2::impl::assert_not_null(r)).inner_token))) + CPP2_UFCS(gen_range_string)((*cpp2::impl::assert_not_null(r))) + CPP2_UFCS(gen_mod_string)((*cpp2::impl::assert_not_null(r)));

            return r; 
        }

        return nullptr; 
    }

#line 2162 "regex.h2"
    auto range_token::parse_modifier(parse_context& ctx) & -> void{
        if (CPP2_UFCS(peek)(ctx) == '?') {
            kind = range_flags::not_greedy;
            static_cast<void>(CPP2_UFCS(next)(ctx));
        }
        else {if (CPP2_UFCS(peek)(ctx) == '+') {
            kind = range_flags::possessive;
            static_cast<void>(CPP2_UFCS(next)(ctx));
        }}
    }

#line 2173 "regex.h2"
    [[nodiscard]] auto range_token::gen_mod_string() const& -> std::string{
        if (kind == range_flags::not_greedy) {
            return "?"; 
        }
        else {if (kind == range_flags::possessive) {
            return "+"; 
        }
        else {
            return ""; 
        }}
    }

#line 2185 "regex.h2"
    [[nodiscard]] auto range_token::gen_range_string() const& -> std::string{
        std::string r {""}; 
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

        if (kind == range_flags::not_greedy) {
            r += "?";
        }
        else {if (kind == range_flags::possessive) {
            r += "+";
        }}
        return r; 
    }

#line 2209 "regex.h2"
    auto range_token::generate_code(generation_context& ctx) const -> void{
        auto inner_name {CPP2_UFCS(generate_func)(ctx, inner_token)}; 
        std::set<int> groups {}; 
        CPP2_UFCS(add_groups)((*cpp2::impl::assert_not_null(inner_token)), groups);
        auto reset_name {CPP2_UFCS(generate_reset)(ctx, cpp2::move(groups))};

        auto next_name {CPP2_UFCS(next_func_name)(ctx)}; 
        CPP2_UFCS(add_statefull)(ctx, next_name, ("cpp2::regex::range_token_matcher<char, " + cpp2::to_string(min_count) + ", " + cpp2::to_string(max_count) + ", " + cpp2::to_string(kind) + ">::match(" + cpp2::to_string(CPP2_UFCS(match_parameters)(ctx)) + ", " + cpp2::to_string(cpp2::move(inner_name)) + ", " + cpp2::to_string(cpp2::move(reset_name)) + ", other, " + cpp2::to_string(next_name) + ")"));
    }

#line 2219 "regex.h2"
    auto range_token::add_groups(std::set<int>& groups) const -> void{
        CPP2_UFCS(add_groups)((*cpp2::impl::assert_not_null(inner_token)), groups);
    }

    range_token::~range_token() noexcept{}

#line 2227 "regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> template<typename Iter> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::match(Iter const& cur, auto& ctx, auto const& modifiers, auto const& inner, auto const& reset_func, auto const& end_func, auto const& tail) -> auto{
        if (range_flags::possessive == kind) {
            return match_possessive(cur, ctx, modifiers, inner, end_func, tail); 
        }
        else {if (range_flags::greedy == kind) {
            return match_greedy(0, cur, ctx.end, ctx, modifiers, inner, reset_func, end_func, tail); 
        }
        else { // range_flags::not_greedy == kind
            return match_not_greedy(cur, ctx, modifiers, inner, end_func, tail); 
        }}
    }

#line 2239 "regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::is_below_upper_bound(cpp2::impl::in<int> count) -> bool{
        if (-1 == max_count) {return true; }
        else {return cpp2::impl::cmp_less(count,max_count); }
    }

#line 2244 "regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::is_below_lower_bound(cpp2::impl::in<int> count) -> bool{
        if (-1 == min_count) {return false; }
        else {return cpp2::impl::cmp_less(count,min_count); }
    }

#line 2249 "regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::is_in_range(cpp2::impl::in<int> count) -> bool{
        if (-1 != min_count && cpp2::impl::cmp_less(count,min_count)) {return false; }
        if (-1 != max_count && cpp2::impl::cmp_greater(count,max_count)) {return false; }
        return true; 
    }

#line 2255 "regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> template<typename Iter> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::match_min_count(Iter const& cur, auto& ctx, auto const& modifiers, auto const& inner, auto const& end_func, int& count_r) -> auto{// TODO: count_r as out parameter introduces a performance loss.
        auto res {CPP2_UFCS(pass)(ctx, cur)}; 
        auto count {0}; 

        while( is_below_lower_bound(count) && res.matched ) {
            res = inner(res.pos, ctx, modifiers, end_func);
            if (res.matched) {
                count += 1;
            }
        }

        count_r = cpp2::move(count);
        return res; 
    }

#line 2270 "regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> template<typename Iter> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::match_greedy(cpp2::impl::in<int> count, Iter const& cur, Iter const& last_valid, auto& ctx, auto const& modifiers, auto const& inner, auto const& reset_func, auto const& end_func, auto const& other) -> match_return<Iter>{
        auto inner_call {[_0 = (count + 1), _1 = (cur), _2 = (modifiers), _3 = (inner), _4 = (reset_func), _5 = (end_func), _6 = (other)](auto const& tail_cur, auto& tail_ctx, [[maybe_unused]] auto const& unnamed_param_3) -> auto{/* ignore new modifiers */
            return match_greedy(_0, tail_cur, _1, tail_ctx, _2, _3, _4, _5, _6); 
        }}; 
        auto is_m_valid {true}; 
        auto r {CPP2_UFCS(fail)(ctx)}; 
        if (is_below_upper_bound(count) && (is_below_lower_bound(count) || cur != last_valid)) {
            is_m_valid = false;  // Group ranges in M are invalidated through the call.
            r = inner(cur, ctx, modifiers, cpp2::move(inner_call));
        }

        if (!(r.matched) && is_in_range(count)) {
            // The recursion did not yield a match try now the tail
            r = other(cur, ctx, modifiers, end_func);

            if (r.matched && !(cpp2::move(is_m_valid))) {
                // We have a match rematch M if required
                reset_func(ctx);

                if (cpp2::impl::cmp_greater(count,0)) {
                    static_cast<void>(inner(last_valid, ctx, modifiers, end_func));
                }
            }
        }

        return r; 
    }

#line 2298 "regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> template<typename Iter> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::match_possessive(Iter const& cur, auto& ctx, auto const& modifiers, auto const& inner, auto const& end_func, auto const& other) -> match_return<Iter>{
        auto count {0}; 
        auto r {match_min_count(cur, ctx, modifiers, inner, end_func, count)}; 

        if (!(r.matched)) {
          return r; 
        }

        auto pos {r.pos}; 
        while( r.matched && is_below_upper_bound(count) ) {
            r = inner(pos, ctx, modifiers, true_end_func());

            if (pos == r.pos) {
                break; // Break infinite loop.
            }
            if (r.matched) {
                count += 1;
                pos = r.pos;
            }
        }

        return other(cpp2::move(pos), ctx, modifiers, end_func);
    }

#line 2322 "regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> template<typename Iter> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::match_not_greedy(Iter const& cur, auto& ctx, auto const& modifiers, auto const& inner, auto const& end_func, auto const& other) -> match_return<Iter>{
        auto count {0}; 
        auto start {match_min_count(cur, ctx, modifiers, inner, end_func, count)}; 
        if (!(start.matched)) {
          return start; 
        }

        auto pos {cpp2::move(start).pos};
        while( is_below_upper_bound(count) ) {
            auto o {other(pos, ctx, modifiers, end_func)}; 
            if (o.matched) {
                return o; 
            }

            auto r {inner(pos, ctx, modifiers, end_func)}; 
            if (!(r.matched)) {
                return CPP2_UFCS(fail)(ctx); 
            }
            count += 1;
            pos = cpp2::move(r).pos;
        }

        return other(cpp2::move(pos), ctx, modifiers, end_func); // Upper bound reached.
    }

#line 2353 "regex.h2"
    [[nodiscard]] auto special_range_token::parse(parse_context& ctx) -> token_ptr{
        auto r {CPP2_UFCS_TEMPLATE(cpp2_new<special_range_token>)(cpp2::shared)}; 
        char symbol {'\0'}; 
        if (CPP2_UFCS(current)(ctx) == '*') {
            (*cpp2::impl::assert_not_null(r)).min_count = 0;
            (*cpp2::impl::assert_not_null(r)).max_count = -1;
            symbol = '*';
        }
        else {if (CPP2_UFCS(current)(ctx) == '+') {
            (*cpp2::impl::assert_not_null(r)).min_count = 1;
            (*cpp2::impl::assert_not_null(r)).max_count = -1;
            symbol = '+';
        }else {if (CPP2_UFCS(current)(ctx) == '?') {
            (*cpp2::impl::assert_not_null(r)).min_count = 0;
            (*cpp2::impl::assert_not_null(r)).max_count = 1;
            symbol = '?';
        }else {
            return nullptr; 
        }}}

        if (!(CPP2_UFCS(has_token)(ctx))) {return CPP2_UFCS(error)(ctx, ("'" + cpp2::to_string(CPP2_UFCS(current)(ctx)) + "' without previous element.")); }

#line 2376 "regex.h2"
        CPP2_UFCS(parse_modifier)((*cpp2::impl::assert_not_null(r)), ctx);

        (*cpp2::impl::assert_not_null(r)).inner_token = CPP2_UFCS(pop_token)(ctx);
        (*cpp2::impl::assert_not_null(r)).string_rep = CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null((*cpp2::impl::assert_not_null(r)).inner_token))) + cpp2::move(symbol) + CPP2_UFCS(gen_mod_string)((*cpp2::impl::assert_not_null(r)));
        return r; 
    }

    special_range_token::~special_range_token() noexcept{}

#line 2388 "regex.h2"
[[nodiscard]] auto word_boundary_token_parse(parse_context& ctx) -> token_ptr{
    if (CPP2_UFCS(current)(ctx) != '\\') {return nullptr; }

    if (CPP2_UFCS(peek)(ctx) == 'b') {
        static_cast<void>(CPP2_UFCS(next)(ctx));
        return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_check>)(cpp2::shared, "\\\\b", "word_boundary_token_matcher<char, false>"); 
    }
    else {if (CPP2_UFCS(peek)(ctx) == 'B') {
        static_cast<void>(CPP2_UFCS(next)(ctx));
        return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_check>)(cpp2::shared, "\\\\B", "word_boundary_token_matcher<char, true>"); 
    }
    else {
        return nullptr; 
    }}
}

#line 2404 "regex.h2"
template<typename CharT, bool negate> [[nodiscard]] auto word_boundary_token_matcher(auto& cur, auto& ctx, auto const& modifiers) -> bool{
    static_cast<void>(modifiers);
    word_class<CharT> words {}; 
    auto is_match {false}; 
    if (cur == ctx.begin) {// String start
        if (cur != ctx.end) {// No empty string
            is_match = CPP2_UFCS(includes)(cpp2::move(words), *cpp2::impl::assert_not_null(cur));
        }
    }
    else {if (cur == ctx.end) {// String end
        is_match = CPP2_UFCS(includes)(cpp2::move(words), *cpp2::impl::assert_not_null((cur - 1)));
    }
    else { // Middle of string
        is_match = 
                (CPP2_UFCS(includes)(words, *cpp2::impl::assert_not_null((cur - 1))) && !(CPP2_UFCS(includes)(words, *cpp2::impl::assert_not_null(cur)))) // End of word: \w\W
            || (!(CPP2_UFCS(includes)(words, *cpp2::impl::assert_not_null((cur - 1)))) && CPP2_UFCS(includes)(words, *cpp2::impl::assert_not_null(cur)));// Start of word: \W\w

    }}
    if (negate) {
        is_match = !(is_match);
    }

    return is_match; 
}

#line 2441 "regex.h2"
    template <typename CharT> template<typename Other> [[nodiscard]] auto branch_reset_matcher_logic<CharT>::match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto { return Other::match(cur, ctx, modifiers, end_func);  }
#line 2442 "regex.h2"
    template <typename CharT> auto branch_reset_matcher_logic<CharT>::reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void{}
#line 2443 "regex.h2"
    template <typename CharT> [[nodiscard]] auto branch_reset_matcher_logic<CharT>::to_string() -> auto { return bstring<CharT>("(?|"); }

#line 2450 "regex.h2"
    template <typename CharT, CharT C, CharT L, CharT U> template<typename Other> [[nodiscard]] auto char_matcher_logic<CharT,C,L,U>::match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto{
        if (CPP2_UFCS(has_flag)(modifiers, expression_flags::case_insensitive)) {
            if (cur != ctx.end && (*cpp2::impl::assert_not_null(cur) == L || *cpp2::impl::assert_not_null(cur) == U)) {
                return Other::match(cur + 1, ctx, modifiers, end_func); 
            }
            else {
                return CPP2_UFCS(fail)(ctx); 
            }
        }
        else {
            if (cur != ctx.end && *cpp2::impl::assert_not_null(cur) == C) {
                return Other::match(cur + 1, ctx, modifiers, end_func); 
            }
            else {
                return CPP2_UFCS(fail)(ctx); 
            }
        }

    }
#line 2469 "regex.h2"
    template <typename CharT, CharT C, CharT L, CharT U> auto char_matcher_logic<CharT,C,L,U>::reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void{}
#line 2470 "regex.h2"
    template <typename CharT, CharT C, CharT L, CharT U> [[nodiscard]] auto char_matcher_logic<CharT,C,L,U>::to_string() -> auto { return bstring<CharT>(1, C); }

#line 2478 "regex.h2"
    template <typename CharT, bool negate, typename ...List> template<typename Other> [[nodiscard]] auto class_matcher_logic<CharT,negate,List...>::match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto{
        if (CPP2_UFCS(has_flag)(modifiers, expression_flags::case_insensitive)) {
            if (cur != ctx.end && negate != (match_any<List...>(safe_tolower(*cpp2::impl::assert_not_null(cur))) || match_any<List...>(safe_toupper(*cpp2::impl::assert_not_null(cur))))) {
                return Other::match(cur + 1, ctx, modifiers, end_func); 
            }
            else {
                return CPP2_UFCS(fail)(ctx); 
            }
        }
        else {
            if (cur != ctx.end && negate != match_any<List...>(*cpp2::impl::assert_not_null(cur))) {
                return Other::match(cur + 1, ctx, modifiers, end_func); 
            }
            else {
                return CPP2_UFCS(fail)(ctx); 
            }
        }
    }

#line 2497 "regex.h2"
    template <typename CharT, bool negate, typename ...List> template<typename First, typename ...Other> [[nodiscard]] auto class_matcher_logic<CharT,negate,List...>::match_any(cpp2::impl::in<CharT> c) -> bool{
        bool r {First::includes(c)}; 

        if (!(r)) {
            if constexpr (0 != sizeof...(Other)) {
                r = match_any<Other...>(c);
            }
        }

        return r; 
    }

#line 2509 "regex.h2"
    template <typename CharT, bool negate, typename ...List> auto class_matcher_logic<CharT,negate,List...>::reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void{}

#line 2511 "regex.h2"
    template <typename CharT, bool negate, typename ...List> [[nodiscard]] auto class_matcher_logic<CharT,negate,List...>::to_string() -> bstring<CharT>{
        bstring<CharT> r {"["}; 
        if (negate) {
            r += "^";
        }
        r += (bstring<CharT>() + ... + List::to_string());
        r += "]";

        return r; 
    }

#line 2542 "regex.h2"
        template <typename CharT, typename Matcher> template <typename Iter> regular_expression<CharT,Matcher>::search_return<Iter>::search_return(cpp2::impl::in<bool> matched_, context<Iter> const& ctx_)
            : matched{ matched_ }
            , ctx{ ctx_ }{

#line 2545 "regex.h2"
        }

#line 2547 "regex.h2"
        template <typename CharT, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,Matcher>::search_return<Iter>::group_number() const& -> auto { return CPP2_UFCS(size)(ctx);  }
#line 2548 "regex.h2"
        template <typename CharT, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,Matcher>::search_return<Iter>::group(cpp2::impl::in<int> g) const& -> auto { return CPP2_UFCS(get_group_string)(ctx, g); }
#line 2549 "regex.h2"
        template <typename CharT, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,Matcher>::search_return<Iter>::group_start(cpp2::impl::in<int> g) const& -> auto { return CPP2_UFCS(get_group_start)(ctx, g); }
#line 2550 "regex.h2"
        template <typename CharT, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,Matcher>::search_return<Iter>::group_end(cpp2::impl::in<int> g) const& -> auto { return CPP2_UFCS(get_group_end)(ctx, g); }

#line 2552 "regex.h2"
        template <typename CharT, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,Matcher>::search_return<Iter>::group(cpp2::impl::in<bstring<CharT>> g) const& -> auto { return group(get_group_id(g)); }
#line 2553 "regex.h2"
        template <typename CharT, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,Matcher>::search_return<Iter>::group_start(cpp2::impl::in<bstring<CharT>> g) const& -> auto { return group_start(get_group_id(g)); }
#line 2554 "regex.h2"
        template <typename CharT, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,Matcher>::search_return<Iter>::group_end(cpp2::impl::in<bstring<CharT>> g) const& -> auto { return group_end(get_group_id(g)); }

#line 2556 "regex.h2"
        template <typename CharT, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,Matcher>::search_return<Iter>::get_group_id(cpp2::impl::in<bstring<CharT>> g) const& -> auto{
            auto group_id {Matcher::get_named_group_index(g)}; 
            if (-1 == group_id) {
                // TODO: Throw error.
            }
            return group_id; 
        }

#line 2565 "regex.h2"
    template <typename CharT, typename Matcher> [[nodiscard]] auto regular_expression<CharT,Matcher>::match(cpp2::impl::in<bview<CharT>> str) const& -> auto { return match(CPP2_UFCS(begin)(str), CPP2_UFCS(end)(str)); }
#line 2566 "regex.h2"
    template <typename CharT, typename Matcher> [[nodiscard]] auto regular_expression<CharT,Matcher>::match(cpp2::impl::in<bview<CharT>> str, auto const& start) const& -> auto { return match(get_iter(str, start), CPP2_UFCS(end)(str)); }
#line 2567 "regex.h2"
    template <typename CharT, typename Matcher> [[nodiscard]] auto regular_expression<CharT,Matcher>::match(cpp2::impl::in<bview<CharT>> str, auto const& start, auto const& length) const& -> auto { return match(get_iter(str, start), get_iter(str, start + length)); }
#line 2568 "regex.h2"
    template <typename CharT, typename Matcher> template<typename Iter> [[nodiscard]] auto regular_expression<CharT,Matcher>::match(Iter const& start, Iter const& end) const& -> search_return<Iter>{
        context ctx {start, end}; 

        auto r {Matcher::entry(start, ctx, modifiers())}; 
        return search_return(r.matched && r.pos == end, cpp2::move(ctx));
    }

#line 2575 "regex.h2"
    template <typename CharT, typename Matcher> [[nodiscard]] auto regular_expression<CharT,Matcher>::search(cpp2::impl::in<bview<CharT>> str) const& -> auto { return search(CPP2_UFCS(begin)(str), CPP2_UFCS(end)(str)); }
#line 2576 "regex.h2"
    template <typename CharT, typename Matcher> [[nodiscard]] auto regular_expression<CharT,Matcher>::search(cpp2::impl::in<bview<CharT>> str, auto const& start) const& -> auto { return search(get_iter(str, start), CPP2_UFCS(end)(str)); }
#line 2577 "regex.h2"
    template <typename CharT, typename Matcher> [[nodiscard]] auto regular_expression<CharT,Matcher>::search(cpp2::impl::in<bview<CharT>> str, auto const& start, auto const& length) const& -> auto { return search(get_iter(str, start), get_iter(str, start + length)); }
#line 2578 "regex.h2"
    template <typename CharT, typename Matcher> template<typename Iter> [[nodiscard]] auto regular_expression<CharT,Matcher>::search(Iter const& start, Iter const& end) const& -> search_return<Iter>{
        auto matched {false}; 
        context ctx {start, end}; 

        auto cur {start}; 
        for( ; true; (++cur) ) {
            if (Matcher::entry(cur, ctx, modifiers()).matched) {
                matched = true;
                break;
            }

            if (cur == ctx.end) {
                break;
            }
        }

        return search_return(cpp2::move(matched), cpp2::move(ctx));
    }

#line 2597 "regex.h2"
    template <typename CharT, typename Matcher> [[nodiscard]] auto regular_expression<CharT,Matcher>::to_string() const& -> auto { return Matcher::to_string();  }

#line 2602 "regex.h2"
    template <typename CharT, typename Matcher> [[nodiscard]] auto regular_expression<CharT,Matcher>::get_iter(cpp2::impl::in<bview<CharT>> str, auto const& pos) -> auto{
        if (cpp2::impl::cmp_less(pos,CPP2_UFCS(size)(str))) {
            return CPP2_UFCS(begin)(str) + pos; 
        }
        else {
            return CPP2_UFCS(end)(str); 
        }
    }

#line 2632 "regex.h2"
    template <typename Error_out> regex_parser<Error_out>::regex_parser(cpp2::impl::in<std::string_view> r, cpp2::impl::in<std::string_view> m, Error_out const& e)
        : regex{ r }
        , modifier{ m }
        , error_out{ e }{

#line 2636 "regex.h2"
    }

#line 2640 "regex.h2"
    template <typename Error_out> auto regex_parser<Error_out>::error(cpp2::impl::in<std::string> message) & -> void{
        error_out(("Error during parsing of regex '" + cpp2::to_string(regex) + "' at position '" + cpp2::to_string(pos) + "': " + cpp2::to_string(message)));
        has_error = true;
    }

#line 2647 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::parser_expression_modifiers(cpp2::impl::out<parse_context_modifier_state> mods) & -> std::string{
        std::string r {"0"}; 
        std::string sep {" | "}; 

        auto add {[&, _1 = cpp2::move(sep)](auto const& name, auto& r) mutable -> void{
            r += (cpp2::to_string(_1) + cpp2::to_string(name));
        }}; 

        mods.construct();

        auto mod_pos {0}; 
        for( ; cpp2::impl::cmp_less(mod_pos,CPP2_UFCS(ssize)(modifier)); mod_pos += 1 ) {
            char c {CPP2_ASSERT_IN_BOUNDS(modifier, mod_pos)}; 

            if (     c == 'i') { add("::cpp2::regex::expression_flags::case_insensitive", r); }
            else {if (c == 'm') {add("::cpp2::regex::expression_flags::multiple_lines", r); }
            else {if (c == 's') {add("::cpp2::regex::expression_flags::single_line", r); }
            else {if (c == 'n') {
                add("::cpp2::regex::expression_flags::no_group_captures", r);
                mods.value().group_captures_have_numbers = false;
            }
            else {if (c == 'x') {
                add("::cpp2::regex::expression_flags::perl_code_syntax", r);
                mods.value().perl_code_syntax = true;

                // Check if we have 'xx'
                mod_pos += 1;
                if (cpp2::impl::cmp_less(mod_pos,CPP2_UFCS(ssize)(modifier)) && 'x' == CPP2_ASSERT_IN_BOUNDS(modifier, mod_pos)) {
                    add("::cpp2::regex::expression_flags::perl_code_syntax_in_classes", r);
                    mods.value().perl_code_syntax_in_classes = true;
                }
            }
            else {error(("Unknown modifier: '" + cpp2::to_string(cpp2::move(c)) + "'")); }}}}}
        }

        return r; 
    }

#line 2688 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::parse() & -> std::string{
        cpp2::impl::deferred_init<parse_context_modifier_state> modifiers;
        auto mod {parser_expression_modifiers(cpp2::impl::out(&modifiers))};
        parse_context parse_ctx {regex, cpp2::move(modifiers.value())};
        if (!(CPP2_UFCS(parse)(parse_ctx))) {
            error(parse_ctx.error_text);
            return "Error"; 
        }

        source += "{\n";
        source += ("  group_count: type == std::integral_constant<int, " + cpp2::to_string(CPP2_UFCS(get_cur_group)(parse_ctx)) + ">;  //TODO: Use static constexpr when alpha limitation of nested types declarations is lifted.\n");
        source += ("  initial_flags: type == std::integral_constant<int, " + cpp2::to_string(cpp2::move(mod)) + ">;  //TODO: Use static constexpr when alpha limitation of nested types declarations is lifted.\n");

        generation_context gen_ctx {}; 
        source += CPP2_UFCS(run)(gen_ctx, CPP2_UFCS(get_tokens)(parse_ctx));
        source += "  entry: (cur, inout ctx, modifiers) -> _ = {\n";
        source += "    ctx.set_group_start(0, cur);\n";
        source += ("    r := " + cpp2::to_string(CPP2_UFCS(get_entry_func)(gen_ctx)) + "(cur, ctx, modifiers, cpp2::regex::true_end_func());\n");
        source += "    if r.matched { ctx.set_group_end(0, r.pos); }\n";
        source += "    return r;\n";
        source += "  }\n";

        auto string {CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(CPP2_UFCS(get_tokens)(parse_ctx))))};
        source += ("  to_string: () -> std::string = { return \"" + cpp2::to_string(cpp2::move(string)) + "\"; }\n");
        source += CPP2_UFCS(create_named_group_lookup)(cpp2::move(gen_ctx), parse_ctx.named_groups);
        source += "}\n";

        static_cast<void>(cpp2::move(parse_ctx));

        return source; 
    }

#line 2721 "regex.h2"
template<typename Err> [[nodiscard]] auto generate_template(cpp2::impl::in<std::string_view> regex, cpp2::impl::in<std::string_view> modifier, Err const& err) -> std::string{
    regex_parser<Err> parser {regex, modifier, err}; 
    auto r {CPP2_UFCS(parse)(parser)}; 
    static_cast<void>(cpp2::move(parser));
    return r; 
}

}
}

#endif
