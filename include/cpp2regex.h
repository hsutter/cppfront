
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

#line 43 "regex.h2"
class range_flags;
    

#line 49 "regex.h2"
template<typename Iter> class match_group;
    

#line 56 "regex.h2"
template<typename Iter> class match_return;
    

#line 61 "regex.h2"
template<typename CharT, typename Iter, int max_groups, int max_alternatives> class match_context;

#line 146 "regex.h2"
template<bool has_change_, bool reset_, int add_, int remove_, fixed_string str> class match_modifiers_state_change;

#line 172 "regex.h2"
template<int flags_, typename Inner> class match_modifiers;

#line 195 "regex.h2"
template<typename CharT, typename ...List> class matcher_list;
    

#line 212 "regex.h2"
class true_end_func;
    

#line 225 "regex.h2"
template<typename CharT, CharT C> class single_class_entry;

#line 233 "regex.h2"
template<typename CharT, CharT Start, CharT End> class range_class_entry;

#line 241 "regex.h2"
template<typename CharT, typename ...List> class combined_class_entry;
    

#line 248 "regex.h2"
template<typename CharT, CharT ...List> class list_class_entry;
    

#line 255 "regex.h2"
template<typename CharT, fixed_string Name, typename Inner> class named_class_entry;
    

#line 260 "regex.h2"
template<typename CharT, typename Inner> class negated_class_entry;
    

#line 267 "regex.h2"
template<typename CharT, fixed_string Name, typename Inner> class shorthand_class_entry;
    

#line 319 "regex.h2"
template<typename CharT> class empty_matcher_logic;
    

#line 328 "regex.h2"
template<typename CharT, size_t alternative> class extract_position_helper;
    

#line 344 "regex.h2"
template<typename CharT, fixed_string syntax, typename base> class special_syntax_wrapper;
    

#line 357 "regex.h2"
class no_reset;
    

#line 361 "regex.h2"
class regex_token;

#line 382 "regex.h2"
class parse_context;
    

#line 516 "regex.h2"
class generation_function_context;
    

#line 532 "regex.h2"
class generation_context;

#line 672 "regex.h2"
class regex_token_base;
    

#line 682 "regex.h2"
class char_token;
    

#line 725 "regex.h2"
class range_token;
    

#line 863 "regex.h2"
class special_range_token;
    

#line 897 "regex.h2"
template<typename CharT, int min_count, int max_count, int kind> class range_token_matcher;

#line 1033 "regex.h2"
template<typename CharT, size_t alternative, typename ...List> class alternative_matcher_logic;

#line 1117 "regex.h2"
template<typename CharT> class any_matcher_logic;

#line 1136 "regex.h2"
template<typename CharT> class branch_reset_matcher_logic;
    

#line 1144 "regex.h2"
template<typename CharT, CharT C, CharT L, CharT U> class char_matcher_logic;

#line 1172 "regex.h2"
template<typename CharT, bool negate, typename ...List> class class_matcher_logic;

#line 1221 "regex.h2"
template<typename CharT> class global_group_reset;
    

#line 1233 "regex.h2"
template<typename CharT, int group, typename ModifierChange, fixed_string name, bool name_brackets> class group_matcher_start_logic;
    

#line 1270 "regex.h2"
template<typename CharT, int group> class group_matcher_end_logic;
    

#line 1294 "regex.h2"
template<typename CharT> class special_group_end_logic;
    

#line 1302 "regex.h2"
template<typename CharT, int group, fixed_string symbol> class group_ref_matcher_logic;
    

#line 1335 "regex.h2"
template<typename CharT, bool match_new_line, bool match_new_line_before_end> class line_end_matcher_logic;

#line 1355 "regex.h2"
template<typename CharT, bool match_new_line> class line_start_matcher_logic;

#line 1372 "regex.h2"
template<typename CharT, bool positive, fixed_string name, typename Pattern> class lookahead_matcher_logic;

#line 1395 "regex.h2"
template<typename CharT, typename ModifierChange> class modifier_matcher_logic;

#line 1407 "regex.h2"
template                   <typename CharT, fixed_string Name, bool negate, typename ...List> class named_class_matcher_logic;
    

#line 1452 "regex.h2"
template<typename CharT, bool negate> class word_boundary_matcher_logic;

#line 1503 "regex.h2"
template<fixed_string name, int group_id, typename Inner> class group_name_list;

#line 1515 "regex.h2"
class group_name_list_end;
    

#line 1520 "regex.h2"
template<typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> class regular_expression;

#line 1601 "regex.h2"
template<typename CharT, typename Matcher> class regular_expression_with_matcher;

#line 1690 "regex.h2"
class regex_parser_modifier_state;
    

#line 1697 "regex.h2"
class regex_parser_group_state;

#line 1732 "regex.h2"
class regex_branch_reset_state;
    

#line 1759 "regex.h2"
template<typename Error_out> class regex_parser;

#line 2792 "regex.h2"
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

template<typename CharT> using bview = std::basic_string_view<CharT>;
template<typename CharT> using bstring = std::basic_string<CharT>;

#line 31 "regex.h2"
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
#line 39 "regex.h2"

#line 43 "regex.h2"
class range_flags {
    public: static const int not_greedy;
    public: static const int greedy;
    public: static const int possessive;

    public: range_flags() = default;
    public: range_flags(range_flags const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_flags const&) -> void = delete;
};
#line 48 "regex.h2"

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

#line 74 "regex.h2"
    public: match_context(match_context const& that);
#line 74 "regex.h2"
    public: auto operator=(match_context const& that) -> match_context& ;
#line 74 "regex.h2"
    public: match_context(match_context&& that) noexcept;
#line 74 "regex.h2"
    public: auto operator=(match_context&& that) noexcept -> match_context& ;

#line 78 "regex.h2"
    public: [[nodiscard]] auto get_group(auto const& group) const& -> auto;

    public: [[nodiscard]] auto get_group_string(auto const& group) const& -> std::string;

#line 86 "regex.h2"
    public: [[nodiscard]] auto get_group_start(auto const& group) const& -> int;

#line 92 "regex.h2"
    public: [[nodiscard]] auto get_group_end(auto const& group) const& -> int;

#line 99 "regex.h2"
    public: auto set_group_end(auto const& group, auto const& pos) & -> void;

#line 104 "regex.h2"
    public: auto set_group_invalid(auto const& group) & -> void;

#line 108 "regex.h2"
    public: auto set_group_start(auto const& group, auto const& pos) & -> void;

#line 112 "regex.h2"
    public: [[nodiscard]] auto size() const& -> auto;

#line 116 "regex.h2"
    public: [[nodiscard]] auto get_alternative_pos(auto const& alternative) const& -> auto;

    public: auto set_alternative_pos(auto const& alternative, auto const& pos) & -> void;

#line 124 "regex.h2"
    public: [[nodiscard]] auto print_ranges() const& -> bstring<CharT>;

#line 138 "regex.h2"
    public: [[nodiscard]] auto fail() const& -> auto;
    public: [[nodiscard]] auto pass(cpp2::in<Iter> cur) const& -> auto;

};

#line 146 "regex.h2"
template<bool has_change_, bool reset_, int add_, int remove_, fixed_string str> class match_modifiers_state_change {

    public: static const bool reset;
    public: static const int add;
    public: static const int remove;
    public: static const bool has_change;

    public: [[nodiscard]] constexpr static auto combine_inner(cpp2::in<int> old_flags) -> auto;

#line 164 "regex.h2"
    public: [[nodiscard]] static auto to_string() -> auto;
    public: match_modifiers_state_change() = default;
    public: match_modifiers_state_change(match_modifiers_state_change const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(match_modifiers_state_change const&) -> void = delete;

#line 165 "regex.h2"
};

using match_modifiers_no_change = match_modifiers_state_change<false,false,0,0,"">;

#line 172 "regex.h2"
template<int flags_, typename Inner> class match_modifiers {

    public: static const int flags;

#line 178 "regex.h2"
    public: template<typename Change> [[nodiscard]] static auto push([[maybe_unused]] Change const& unnamed_param_1) -> auto;
    public: [[nodiscard]] static auto pop() -> auto;
    public: template<typename Change> [[nodiscard]] static auto replace([[maybe_unused]] Change const& unnamed_param_1) -> auto;

#line 185 "regex.h2"
    public: [[nodiscard]] auto has_flag(cpp2::in<int> f) const& -> bool;

#line 188 "regex.h2"
};

#line 195 "regex.h2"
template<typename CharT, typename ...List> class matcher_list {
    public: [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func) -> auto;

    public: template<typename ...OtherList> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] matcher_list<CharT,OtherList...> const& unnamed_param_5) -> auto;

#line 201 "regex.h2"
    private: template<typename First, typename ...Other> [[nodiscard]] static auto match_select(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func) -> auto;

    private: [[nodiscard]] static auto match_select(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func) -> auto;

    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;

    public: template<typename Pre> [[nodiscard]] static auto prepend([[maybe_unused]] Pre const& unnamed_param_1) -> auto;
    public: matcher_list() = default;
    public: matcher_list(matcher_list const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(matcher_list const&) -> void = delete;

#line 209 "regex.h2"
};

template<typename CharT> using no_tail = matcher_list<CharT>;
class true_end_func {
    public: [[nodiscard]] auto operator()(auto const& cur, auto& ctx, [[maybe_unused]] auto const& unnamed_param_4) const& -> auto;
};

#line 225 "regex.h2"
template<typename CharT, CharT C> class single_class_entry
 {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: single_class_entry() = default;
    public: single_class_entry(single_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(single_class_entry const&) -> void = delete;

#line 229 "regex.h2"
};

#line 233 "regex.h2"
template<typename CharT, CharT Start, CharT End> class range_class_entry
 {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: range_class_entry() = default;
    public: range_class_entry(range_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_class_entry const&) -> void = delete;

#line 237 "regex.h2"
};

#line 241 "regex.h2"
template<typename CharT, typename ...List> class combined_class_entry {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: combined_class_entry() = default;
    public: combined_class_entry(combined_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(combined_class_entry const&) -> void = delete;

#line 244 "regex.h2"
};

#line 248 "regex.h2"
template<typename CharT, CharT ...List> class list_class_entry {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: list_class_entry() = default;
    public: list_class_entry(list_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(list_class_entry const&) -> void = delete;

#line 251 "regex.h2"
};

#line 255 "regex.h2"
template<typename CharT, fixed_string Name, typename Inner> class named_class_entry {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: named_class_entry() = default;
    public: named_class_entry(named_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(named_class_entry const&) -> void = delete;

#line 258 "regex.h2"
};

template<typename CharT, typename Inner> class negated_class_entry: public Inner {

    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: negated_class_entry() = default;
    public: negated_class_entry(negated_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(negated_class_entry const&) -> void = delete;

#line 263 "regex.h2"
};

#line 267 "regex.h2"
template<typename CharT, fixed_string Name, typename Inner> class shorthand_class_entry {
    public: [[nodiscard]] static auto includes(cpp2::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: shorthand_class_entry() = default;
    public: shorthand_class_entry(shorthand_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(shorthand_class_entry const&) -> void = delete;

#line 270 "regex.h2"
};

#line 275 "regex.h2"
template        <typename CharT> using digits_class = named_class_entry<CharT,"digits",range_class_entry<CharT,'0','9'>>;
template        <typename CharT> using lower_class = named_class_entry<CharT,"lower",range_class_entry<CharT,'a','z'>>;
template        <typename CharT> using upper_class = named_class_entry<CharT,"upper",range_class_entry<CharT,'A','Z'>>;

#line 281 "regex.h2"
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

#line 297 "regex.h2"
template                 <typename CharT> using short_digits_class = shorthand_class_entry<CharT,"\\d",digits_class<CharT>>;
template                 <typename CharT> using short_hor_space_class = shorthand_class_entry<CharT,"\\h",hor_space_class<CharT>>;
template                 <typename CharT> using short_space_class = shorthand_class_entry<CharT,"\\s",space_class<CharT>>;
template<typename CharT> using short_vert_space_class = shorthand_class_entry<CharT,"\\v",ver_space_class<CharT>>;
template                 <typename CharT> using short_word_class = shorthand_class_entry<CharT,"\\w",word_class<CharT>>;

#line 304 "regex.h2"
template                     <typename CharT> using short_not_digits_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\D",digits_class<CharT>>>;
template                     <typename CharT> using short_not_hor_space_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\H",hor_space_class<CharT>>>;
template                     <typename CharT> using short_not_space_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\S",space_class<CharT>>>;
template<typename CharT> using short_not_vert_space_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\V",ver_space_class<CharT>>>;
template                     <typename CharT> using short_not_word_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\W",word_class<CharT>>>;

#line 319 "regex.h2"
template<typename CharT> class empty_matcher_logic {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto;
    public: static auto reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: empty_matcher_logic() = default;
    public: empty_matcher_logic(empty_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(empty_matcher_logic const&) -> void = delete;

#line 323 "regex.h2"
};

#line 328 "regex.h2"
template<typename CharT, size_t alternative> class extract_position_helper {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto;

#line 337 "regex.h2"
    public: static auto reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: extract_position_helper() = default;
    public: extract_position_helper(extract_position_helper const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(extract_position_helper const&) -> void = delete;

#line 339 "regex.h2"
};

#line 344 "regex.h2"
template<typename CharT, fixed_string syntax, typename base> class special_syntax_wrapper: public base {

    public: [[nodiscard]] static auto to_string() -> auto;
    public: special_syntax_wrapper() = default;
    public: special_syntax_wrapper(special_syntax_wrapper const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(special_syntax_wrapper const&) -> void = delete;

#line 347 "regex.h2"
};

#line 357 "regex.h2"
class no_reset {
    public: auto operator()([[maybe_unused]] auto& unnamed_param_2) const& -> void;
};

class regex_token {

    public: bool needs_state; 
    public: std::string string_rep; 

    public: explicit regex_token(cpp2::in<bool> state, cpp2::in<std::string> str);

#line 372 "regex.h2"
    public: virtual auto generate_code([[maybe_unused]] generation_context& unnamed_param_2) const -> void = 0;

    public: [[nodiscard]] virtual auto get_groups() const -> std::vector<int> = 0;
    public: [[nodiscard]] auto requires_state() const& -> bool;
    public: [[nodiscard]] auto to_string() const& -> std::string;
    public: virtual ~regex_token() noexcept;

    public: regex_token(regex_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_token const&) -> void = delete;

#line 377 "regex.h2"
};

using token_ptr = std::shared_ptr<regex_token>;
using token_vec = std::vector<token_ptr>;

class parse_context {
    private: std::string_view regex; 

    private: size_t pos {0}; 

    public: std::string error_text {""}; 

    private: token_vec cur_state {}; 

    public: explicit parse_context(cpp2::in<std::string_view> r);
#line 391 "regex.h2"
    public: auto operator=(cpp2::in<std::string_view> r) -> parse_context& ;

#line 395 "regex.h2"
    public: auto add_token(cpp2::in<token_ptr> token) & -> void;

#line 399 "regex.h2"
    public: [[nodiscard]] auto has_token() const& -> bool;

#line 403 "regex.h2"
    public: [[nodiscard]] auto pop_token() & -> token_ptr;

#line 413 "regex.h2"
    public: [[nodiscard]] auto get_tokens() const& -> token_vec;

#line 417 "regex.h2"
    public: [[nodiscard]] auto current() const& -> char;

    public: [[nodiscard]] auto has_next() const& -> bool;
    public: [[nodiscard]] auto next() & -> bool;

#line 428 "regex.h2"
    public: [[nodiscard]] auto valid() const& -> bool;

    public: [[nodiscard]] auto error(cpp2::in<std::string> err) & -> token_ptr;

#line 435 "regex.h2"
    private: [[nodiscard]] auto get_next_position(cpp2::in<bool> in_class, cpp2::in<bool> no_skip) const& -> size_t;

#line 475 "regex.h2"
    private: [[nodiscard]] auto grab_until_impl(cpp2::in<std::string> e, cpp2::out<std::string> r, cpp2::in<bool> any) & -> bool;

#line 496 "regex.h2"
    public: [[nodiscard]] auto grab_until(cpp2::in<std::string> e, cpp2::out<std::string> r) & -> auto;
    public: [[nodiscard]] auto grab_until(cpp2::in<char> e, cpp2::out<std::string> r) & -> auto;
    public: [[nodiscard]] auto grab_until_one_of(cpp2::in<std::string> e, cpp2::out<std::string> r) & -> auto;

    private: [[nodiscard]] auto peek_impl(cpp2::in<bool> in_class) const& -> char;

#line 510 "regex.h2"
    public: [[nodiscard]] auto peek() const& -> auto;
    public: [[nodiscard]] auto peek_in_class() const& -> auto;
    public: parse_context(parse_context const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(parse_context const&) -> void = delete;


#line 514 "regex.h2"
};

class generation_function_context {
    public: std::string code {""}; 
    public: std::string tabs {""}; 

    public: auto add_tabs(cpp2::in<int> c) & -> void;

#line 527 "regex.h2"
    public: auto remove_tabs(cpp2::in<int> c) & -> void;

#line 530 "regex.h2"
};

class generation_context {

    public: std::vector<generation_function_context> gen_stack {1}; 

    public: bool new_state {true}; 
    public: int matcher_func {0}; 
    public: int reset_func {0}; 
    public: std::string entry_func {""}; 

    public: [[nodiscard]] auto match_parameters() const& -> std::string;

    public: auto add_check(cpp2::in<std::string> check) & -> void;

#line 548 "regex.h2"
    public: auto add_statefull(cpp2::in<std::string> next_func, cpp2::in<std::string> c) & -> void;

#line 554 "regex.h2"
    public: [[nodiscard]] auto run(cpp2::in<token_vec> tokens) & -> std::string;

#line 560 "regex.h2"
    public: [[nodiscard]] auto generate_func(cpp2::in<token_vec> tokens) & -> std::string;

#line 570 "regex.h2"
    public: [[nodiscard]] auto generate_func(cpp2::in<token_ptr> token) & -> std::string;

#line 578 "regex.h2"
    public: [[nodiscard]] auto generate_reset(cpp2::in<std::vector<int>> groups) & -> std::string;

#line 600 "regex.h2"
    public: [[nodiscard]] auto get_current() & -> generation_function_context*;

#line 604 "regex.h2"
    public: [[nodiscard]] auto get_base() & -> generation_function_context*;

#line 608 "regex.h2"
    public: auto start_func_named(cpp2::in<std::string> name) & -> void;

#line 617 "regex.h2"
    public: [[nodiscard]] auto start_func() & -> std::string;

#line 623 "regex.h2"
    public: auto end_func_statefull(cpp2::in<std::string> s) & -> void;

#line 635 "regex.h2"
    public: auto end_func() & -> void;

#line 639 "regex.h2"
    public: [[nodiscard]] auto get_entry_func() const& -> std::string;

#line 643 "regex.h2"
    public: [[nodiscard]] auto gen_func_name() & -> std::string;

#line 649 "regex.h2"
    public: [[nodiscard]] auto gen_reset_func_name() & -> std::string;

#line 655 "regex.h2"
    public: [[nodiscard]] auto new_context() & -> generation_function_context*;

#line 663 "regex.h2"
    public: auto finish_context() & -> void;

#line 670 "regex.h2"
};

class regex_token_base: public regex_token {

#line 675 "regex.h2"
    public: explicit regex_token_base(cpp2::in<bool> state, cpp2::in<std::string> str);

#line 679 "regex.h2"
    public: [[nodiscard]] auto get_groups() const -> std::vector<int> override;
    public: virtual ~regex_token_base() noexcept;

    public: regex_token_base(regex_token_base const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_token_base const&) -> void = delete;

#line 680 "regex.h2"
};

class char_token: public regex_token_base {

#line 685 "regex.h2"
    private: char token; 

    public: explicit char_token(cpp2::in<char> t);

#line 692 "regex.h2"
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 696 "regex.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;
    public: virtual ~char_token() noexcept;

    public: char_token(char_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(char_token const&) -> void = delete;


#line 701 "regex.h2"
};

template<typename CharT, CharT C, CharT L, CharT U> [[nodiscard]] auto char_token_matcher(auto& cur, auto& ctx, auto const& modifiers) -> bool;

#line 724 "regex.h2"
// Regex syntax: <matcher>{min, max}  Example: a{2,4}
class range_token: public regex_token {

#line 728 "regex.h2"
    protected: int min_count {-1}; 
    protected: int max_count {-1}; 
    protected: int kind {range_flags::greedy}; 
    protected: token_ptr inner_token {nullptr}; 

    public: explicit range_token();

    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 805 "regex.h2"
    public: auto parse_modifier(parse_context& ctx) & -> void;

#line 816 "regex.h2"
    public: [[nodiscard]] auto gen_mod_string() const& -> std::string;

#line 828 "regex.h2"
    public: [[nodiscard]] auto gen_range_string() const& -> std::string;

#line 852 "regex.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 860 "regex.h2"
    public: [[nodiscard]] auto get_groups() const -> std::vector<int> override;
    public: virtual ~range_token() noexcept;

    public: range_token(range_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_token const&) -> void = delete;

#line 861 "regex.h2"
};

class special_range_token: public range_token {

#line 866 "regex.h2"
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;
    public: virtual ~special_range_token() noexcept;

    public: special_range_token() = default;
    public: special_range_token(special_range_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(special_range_token const&) -> void = delete;


#line 895 "regex.h2"
};

template<typename CharT, int min_count, int max_count, int kind> class range_token_matcher {

    public: template<typename Iter> [[nodiscard]] static auto match(Iter const& cur, auto& ctx, auto const& modifiers, auto const& inner, auto const& reset_func, auto const& end_func, auto const& tail) -> auto;

#line 911 "regex.h2"
    private: [[nodiscard]] static auto is_below_upper_bound(cpp2::in<int> count) -> bool;

#line 916 "regex.h2"
    private: [[nodiscard]] static auto is_below_lower_bound(cpp2::in<int> count) -> bool;

#line 921 "regex.h2"
    private: [[nodiscard]] static auto is_in_range(cpp2::in<int> count) -> bool;

#line 927 "regex.h2"
    private: template<typename Iter> [[nodiscard]] static auto match_min_count(Iter const& cur, auto& ctx, auto const& modifiers, auto const& inner, auto const& end_func, int& count_r) -> auto;

#line 942 "regex.h2"
    private: template<typename Iter> [[nodiscard]] static auto match_greedy(cpp2::in<int> count, Iter const& cur, Iter const& last_valid, auto& ctx, auto const& modifiers, auto const& inner, auto const& reset_func, auto const& end_func, auto const& other) -> match_return<Iter>;

#line 970 "regex.h2"
    private: template<typename Iter> [[nodiscard]] static auto match_possessive(Iter const& cur, auto& ctx, auto const& modifiers, auto const& inner, auto const& end_func, auto const& other) -> match_return<Iter>;

#line 994 "regex.h2"
    private: template<typename Iter> [[nodiscard]] static auto match_not_greedy(Iter const& cur, auto& ctx, auto const& modifiers, auto const& inner, auto const& end_func, auto const& other) -> match_return<Iter>;
    public: range_token_matcher() = default;
    public: range_token_matcher(range_token_matcher const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_token_matcher const&) -> void = delete;


#line 1018 "regex.h2"
};

#line 1021 "regex.h2"
//-----------------------------------------------------------------------
//
//  Matchers for regular expressions.
//
//-----------------------------------------------------------------------
//

#line 1029 "regex.h2"
//  Regex syntax: |  Example: ab|ba
//
//  Non greedy implementation. First alternative that matches is chosen. 
//
template<typename CharT, size_t alternative, typename ...List> class alternative_matcher_logic {

    public: template<typename Tail> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, Tail const& tail) -> auto;

#line 1047 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;

    private: template<typename First, typename ...Next> [[nodiscard]] static auto match_first(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, auto const& tail) -> auto;

#line 1065 "regex.h2"
    private: template<typename Tail, typename First, typename ...Next> [[nodiscard]] static auto match_greedy(auto const& cur, auto& max_overall_length, auto& max_current_length, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Tail const& unnamed_param_7) -> auto;
    public: alternative_matcher_logic() = default;
    public: alternative_matcher_logic(alternative_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(alternative_matcher_logic const&) -> void = delete;


#line 1113 "regex.h2"
};

//  Regex syntax: .
//
template<typename CharT> class any_matcher_logic
 {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto;

#line 1130 "regex.h2"
    public: static auto reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: any_matcher_logic() = default;
    public: any_matcher_logic(any_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(any_matcher_logic const&) -> void = delete;

#line 1132 "regex.h2"
};

// Regex syntax: none Example: -
//
template<typename CharT> class branch_reset_matcher_logic {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto;
    public: static auto reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: branch_reset_matcher_logic() = default;
    public: branch_reset_matcher_logic(branch_reset_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(branch_reset_matcher_logic const&) -> void = delete;

#line 1140 "regex.h2"
};

// Regex syntax: <any character>  Example: a
//
template<typename CharT, CharT C, CharT L, CharT U> class char_matcher_logic
 {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto;

#line 1165 "regex.h2"
    public: static auto reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: char_matcher_logic() = default;
    public: char_matcher_logic(char_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(char_matcher_logic const&) -> void = delete;

#line 1167 "regex.h2"
};

#line 1170 "regex.h2"
// Regex syntax: [<character classes>]  Example: [abcx-y[:digits:]]
//
template<typename CharT, bool negate, typename ...List> class class_matcher_logic
 {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto;

#line 1193 "regex.h2"
    private: template<typename First, typename ...Other> [[nodiscard]] static auto match_any(cpp2::in<CharT> c) -> bool;

#line 1205 "regex.h2"
    public: static auto reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void;

    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: class_matcher_logic() = default;
    public: class_matcher_logic(class_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(class_matcher_logic const&) -> void = delete;


#line 1217 "regex.h2"
};

// Regex syntax: \K Example: \K
//
template<typename CharT> class global_group_reset {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto;

#line 1227 "regex.h2"
    public: static auto reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: global_group_reset() = default;
    public: global_group_reset(global_group_reset const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(global_group_reset const&) -> void = delete;

#line 1229 "regex.h2"
};

// Regex syntax: (<inner>) Example: (.*)
//
template<typename CharT, int group, typename ModifierChange, fixed_string name, bool name_brackets> class group_matcher_start_logic {
    public: template<typename Other, typename Modifiers> [[nodiscard]] static auto match(auto const& cur, auto& ctx, [[maybe_unused]] Modifiers const& unnamed_param_3, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto;

#line 1241 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;

#line 1247 "regex.h2"
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: group_matcher_start_logic() = default;
    public: group_matcher_start_logic(group_matcher_start_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_matcher_start_logic const&) -> void = delete;


#line 1268 "regex.h2"
};

template<typename CharT, int group> class group_matcher_end_logic {
    public: template<typename Other, typename Modifier> [[nodiscard]] static auto match(auto const& cur, auto& ctx, [[maybe_unused]] Modifier const& unnamed_param_3, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto;

#line 1282 "regex.h2"
    public: static auto reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void;

    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: group_matcher_end_logic() = default;
    public: group_matcher_end_logic(group_matcher_end_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_matcher_end_logic const&) -> void = delete;


#line 1292 "regex.h2"
};

template<typename CharT> class special_group_end_logic {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto;
    public: static auto reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: special_group_end_logic() = default;
    public: special_group_end_logic(special_group_end_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(special_group_end_logic const&) -> void = delete;

#line 1298 "regex.h2"
};

// Regex syntax: \<number>  Example: \1
//
template<typename CharT, int group, fixed_string symbol> class group_ref_matcher_logic {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto;

#line 1329 "regex.h2"
    public: static auto reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: group_ref_matcher_logic() = default;
    public: group_ref_matcher_logic(group_ref_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_ref_matcher_logic const&) -> void = delete;

#line 1331 "regex.h2"
};

// Regex syntax: $  Example: aa$
//
template<typename CharT, bool match_new_line, bool match_new_line_before_end> class line_end_matcher_logic
 {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto;

#line 1349 "regex.h2"
    public: static auto reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: line_end_matcher_logic() = default;
    public: line_end_matcher_logic(line_end_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(line_end_matcher_logic const&) -> void = delete;

#line 1351 "regex.h2"
};

// Regex syntax: ^  Example: ^aa
//
template<typename CharT, bool match_new_line> class line_start_matcher_logic
 {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto;

#line 1366 "regex.h2"
    public: static auto reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: line_start_matcher_logic() = default;
    public: line_start_matcher_logic(line_start_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(line_start_matcher_logic const&) -> void = delete;

#line 1368 "regex.h2"
};

// Regex syntax: (?=) or (?!) or (*pla), etc.  Example: (?=AA)
//
template<typename CharT, bool positive, fixed_string name, typename Pattern> class lookahead_matcher_logic
 {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto;

#line 1389 "regex.h2"
    public: static auto reset_ranges(auto& ctx) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: lookahead_matcher_logic() = default;
    public: lookahead_matcher_logic(lookahead_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(lookahead_matcher_logic const&) -> void = delete;

#line 1391 "regex.h2"
};

// Regex syntax: (?<modifiers>)  Example: (?i)
//
template<typename CharT, typename ModifierChange> class modifier_matcher_logic
 {
    public: template<typename Other, typename Modifier> [[nodiscard]] static auto match(auto const& cur, auto& ctx, [[maybe_unused]] Modifier const& unnamed_param_3, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto;

#line 1400 "regex.h2"
    public: static auto reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: modifier_matcher_logic() = default;
    public: modifier_matcher_logic(modifier_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(modifier_matcher_logic const&) -> void = delete;

#line 1402 "regex.h2"
};

// Named character classes
//

template                   <typename CharT, fixed_string Name, bool negate, typename ...List> class named_class_matcher_logic: public special_syntax_wrapper<CharT,Name,class_matcher_logic<CharT,negate,List...>> {
    public: named_class_matcher_logic() = default;
    public: named_class_matcher_logic(named_class_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(named_class_matcher_logic const&) -> void = delete;


#line 1409 "regex.h2"
};

template<typename CharT> using named_class_no_new_line = named_class_matcher_logic<CharT,"\\\\N",true,single_class_entry<CharT,'\n'>>;// TODO: Remove second \, switch to raw strings.
template                 <typename CharT> using named_class_digits = named_class_matcher_logic<CharT,"\\d",false,digits_class<CharT>>;
template                 <typename CharT> using named_class_hor_space = named_class_matcher_logic<CharT,"\\h",false,hor_space_class<CharT>>;
template                 <typename CharT> using named_class_space = named_class_matcher_logic<CharT,"\\s",false,space_class<CharT>>;
template                 <typename CharT> using named_class_ver_space = named_class_matcher_logic<CharT,"\\v",false,ver_space_class<CharT>>;
template                 <typename CharT> using named_class_word = named_class_matcher_logic<CharT,"\\w",false,word_class<CharT>>;

#line 1419 "regex.h2"
template                    <typename CharT> using named_class_not_digits = named_class_matcher_logic<CharT,"\\D",true,digits_class<CharT>>;
template<typename CharT> using named_class_not_hor_space = named_class_matcher_logic<CharT,"\\H",true,hor_space_class<CharT>>;
template                    <typename CharT> using named_class_not_space = named_class_matcher_logic<CharT,"\\S",true,space_class<CharT>>;
template<typename CharT> using named_class_not_ver_space = named_class_matcher_logic<CharT,"\\V",true,ver_space_class<CharT>>;
template                    <typename CharT> using named_class_not_word = named_class_matcher_logic<CharT,"\\W",true,word_class<CharT>>;

// Other named matchers
template                                    <typename CharT> using named_string_end_or_before_new_line_at_end = special_syntax_wrapper<CharT,"\\Z",line_end_matcher_logic<CharT,false,true>>;
template          <typename CharT> using named_string_end = special_syntax_wrapper<CharT,"\\z",line_end_matcher_logic<CharT,false,false>>;
template<typename CharT> using named_string_start = special_syntax_wrapper<CharT,"\\A",line_start_matcher_logic<CharT,false>>;

#line 1431 "regex.h2"
// // Regex syntax: *, +, or ?  Example: aa*
// //
// special_range_matcher_logic: <CharT, M, min_count: int, max_count: int, kind: int, symbol: char> type = {
//     this: range_matcher_logic<CharT, M, min_count, max_count, kind> = ();
//     to_string: () -> bstring<CharT> = {
//         r := M::to_string() + symbol;
//         if kind == range_flags::not_greedy {
//             r += "?";
//         }
//         else if kind == range_flags::possessive {
//             r += "+";
//         }

//         return r;
//     }
// }

// Regex syntax: \b or \B  Example: \bword\b
//
// Matches the start end end of word boundaries.
//
template<typename CharT, bool negate> class word_boundary_matcher_logic
 {
    public: template<typename Other> [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto;

#line 1483 "regex.h2"
    public: static auto reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void;
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: word_boundary_matcher_logic() = default;
    public: word_boundary_matcher_logic(word_boundary_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(word_boundary_matcher_logic const&) -> void = delete;


#line 1491 "regex.h2"
};

#line 1494 "regex.h2"
//-----------------------------------------------------------------------
//
//  Regular expression implementation.
//
//-----------------------------------------------------------------------
//

// Helper for named groups.

template<fixed_string name, int group_id, typename Inner> class group_name_list {

    public: [[nodiscard]] static auto get_group_id(auto const& g) -> int;
    public: group_name_list() = default;
    public: group_name_list(group_name_list const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_name_list const&) -> void = delete;


#line 1513 "regex.h2"
};

class group_name_list_end {
    public: [[nodiscard]] static auto get_group_id([[maybe_unused]] auto const& unnamed_param_1) -> auto;
    public: group_name_list_end() = default;
    public: group_name_list_end(group_name_list_end const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_name_list_end const&) -> void = delete;

#line 1517 "regex.h2"
};

// Regular expression implementation
template<typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> class regular_expression {

    public: template<typename Iter> using context = match_context<CharT,Iter,groups,alternatives>;
    public: using modifiers = match_modifiers<flags,int>;

    // TODO: Named multiple return has problems with templates.
    public: template<typename Iter> class search_return {
        public: bool matched; 
        public: context<Iter> ctx; 

        public: explicit search_return(cpp2::in<bool> matched_, context<Iter> const& ctx_);

#line 1535 "regex.h2"
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


#line 1551 "regex.h2"
    };

    public: [[nodiscard]] auto match(cpp2::in<bview<CharT>> str) const& -> auto;
    public: [[nodiscard]] auto match(cpp2::in<bview<CharT>> str, auto const& start) const& -> auto;
    public: [[nodiscard]] auto match(cpp2::in<bview<CharT>> str, auto const& start, auto const& length) const& -> auto;
    public: template<typename Iter> [[nodiscard]] auto match(Iter const& start, Iter const& end) const& -> search_return<Iter>;

#line 1563 "regex.h2"
    public: [[nodiscard]] auto search(cpp2::in<bview<CharT>> str) const& -> auto;
    public: [[nodiscard]] auto search(cpp2::in<bview<CharT>> str, auto const& start) const& -> auto;
    public: [[nodiscard]] auto search(cpp2::in<bview<CharT>> str, auto const& start, auto const& length) const& -> auto;
    public: template<typename Iter> [[nodiscard]] auto search(Iter const& start, Iter const& end) const& -> search_return<Iter>;

#line 1585 "regex.h2"
    public: [[nodiscard]] auto to_string() const& -> auto;

    // Helper functions
    //

    private: [[nodiscard]] static auto get_iter(cpp2::in<bview<CharT>> str, auto const& pos) -> auto;
    public: regular_expression() = default;
    public: regular_expression(regular_expression const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regular_expression const&) -> void = delete;


#line 1598 "regex.h2"
};

// Regular expression implementation
template<typename CharT, typename Matcher> class regular_expression_with_matcher {

    public: template<typename Iter> using context = match_context<CharT,Iter,Matcher::group_count::value,0>;
    public: using modifiers = match_modifiers<Matcher::initial_flags::value,int>;

    // TODO: Named multiple return has problems with templates.
    public: template<typename Iter> class search_return {
        public: bool matched; 
        public: context<Iter> ctx; 

        public: explicit search_return(cpp2::in<bool> matched_, context<Iter> const& ctx_);

#line 1616 "regex.h2"
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


#line 1632 "regex.h2"
    };

    public: [[nodiscard]] auto match(cpp2::in<bview<CharT>> str) const& -> auto;
    public: [[nodiscard]] auto match(cpp2::in<bview<CharT>> str, auto const& start) const& -> auto;
    public: [[nodiscard]] auto match(cpp2::in<bview<CharT>> str, auto const& start, auto const& length) const& -> auto;
    public: template<typename Iter> [[nodiscard]] auto match(Iter const& start, Iter const& end) const& -> search_return<Iter>;

#line 1644 "regex.h2"
    public: [[nodiscard]] auto search(cpp2::in<bview<CharT>> str) const& -> auto;
    public: [[nodiscard]] auto search(cpp2::in<bview<CharT>> str, auto const& start) const& -> auto;
    public: [[nodiscard]] auto search(cpp2::in<bview<CharT>> str, auto const& start, auto const& length) const& -> auto;
    public: template<typename Iter> [[nodiscard]] auto search(Iter const& start, Iter const& end) const& -> search_return<Iter>;

#line 1666 "regex.h2"
    public: [[nodiscard]] auto to_string() const& -> auto;

    // Helper functions
    //

    private: [[nodiscard]] static auto get_iter(cpp2::in<bview<CharT>> str, auto const& pos) -> auto;
    public: regular_expression_with_matcher() = default;
    public: regular_expression_with_matcher(regular_expression_with_matcher const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regular_expression_with_matcher const&) -> void = delete;


#line 1679 "regex.h2"
};

//-----------------------------------------------------------------------
//
//  Parser for regular expression.
//
//-----------------------------------------------------------------------
//

// State of the expression modifiers.
//
class regex_parser_modifier_state {
    public: bool group_captures_have_numbers {true}; 
    public: bool perl_code_syntax {false}; 
    public: bool perl_code_syntax_in_classes {false}; 
};

// State of the current group. See '(<pattern>)'
class regex_parser_group_state {

    // Current list of matchers
    public: std::vector<std::string> cur_match_list {}; 

    // List of alternate matcher lists. E.g. ab|cd|xy
    public: std::vector<std::vector<std::string>> alternate_match_lists {}; 

    public: regex_parser_modifier_state modifiers {}; 

    public: auto next_alternative() & -> void;

#line 1713 "regex.h2"
    public: auto swap(regex_parser_group_state& t) & -> void;

#line 1719 "regex.h2"
    public: auto add(auto const& matcher) & -> void;

    public: auto wrap_last(auto const& matcher) & -> void;

#line 1728 "regex.h2"
    public: [[nodiscard]] auto empty() const& -> bool;
};

// State for the branch reset. Takes care of the group numbering. See '(|<pattern>)'.
class regex_branch_reset_state {
    public: bool is_active {false}; 
    public: int cur_group {1}; // Global capture group.
    public: int max_group {1}; 
    public: int from {1}; 

    public: [[nodiscard]] auto next() & -> int;

#line 1746 "regex.h2"
    public: auto set_next(cpp2::in<int> g) & -> void;

#line 1751 "regex.h2"
    public: auto next_alternative() & -> void;

#line 1756 "regex.h2"
};

// Parser and generator for regular expressions.
template<typename Error_out> class regex_parser {

    private: std::string_view regex; 
    private: std::string_view modifier; 
    private: Error_out error_out; 

    private: regex_parser_group_state cur_group_state {}; 
    private: regex_branch_reset_state cur_branch_reset_state {}; 
    private: size_t pos {0}; 
    private: int alternatives_count {0}; 
    private: std::map<std::string,int> named_groups {}; 
    private: bool has_error {false}; 

    private: std::string source {""}; 

    private: std::vector<std::string> supported_classes {"alnum", "alpha", "ascii", "blank", "cntrl", "digits", "graph", 
                                                   "lower", "print", "punct", "space", "upper", "word", "xdigit"}; 

    public: explicit regex_parser(cpp2::in<std::string_view> r, cpp2::in<std::string_view> m, Error_out const& e);

#line 1783 "regex.h2"
    // State management functions
    //
    public: [[nodiscard]] auto group_new_state() & -> regex_parser_group_state;

#line 1792 "regex.h2"
    public: auto group_restore_state(cpp2::in<regex_parser_group_state> old_state) & -> void;

#line 1796 "regex.h2"
    // Branch reset management functions
    //

    public: [[nodiscard]] auto branch_reset_new_state() & -> regex_branch_reset_state;

#line 1811 "regex.h2"
    public: auto branch_reset_restore_state(cpp2::in<regex_branch_reset_state> old_state) & -> void;

#line 1817 "regex.h2"
    // Position management functions
    //

    private: [[nodiscard]] auto get_next_position(cpp2::in<bool> in_class, cpp2::in<bool> no_skip) const& -> size_t;

#line 1858 "regex.h2"
    private: [[nodiscard]] auto next_impl(cpp2::out<char> n, cpp2::in<bool> in_class, cpp2::in<bool> no_skip) & -> bool;

#line 1870 "regex.h2"
    public: [[nodiscard]] auto next(cpp2::out<char> n) & -> auto;
    public: [[nodiscard]] auto next_in_class(cpp2::out<char> n) & -> auto;
    public: [[nodiscard]] auto next_no_skip(cpp2::out<char> n) & -> auto;

#line 1876 "regex.h2"
    public: [[nodiscard]] auto skip() & -> bool;

#line 1883 "regex.h2"
    public: [[nodiscard]] auto skip_n(cpp2::in<int> n) & -> bool;

#line 1892 "regex.h2"
    public: [[nodiscard]] auto current() const& -> char;

#line 1900 "regex.h2"
    private: [[nodiscard]] auto peek_impl(cpp2::in<bool> in_class) const& -> char;

#line 1910 "regex.h2"
    public: [[nodiscard]] auto peek() const& -> auto;
    public: [[nodiscard]] auto peek_in_class() const& -> auto;

    private: [[nodiscard]] auto grab_until_impl(cpp2::in<std::string> e, cpp2::out<std::string> r, cpp2::in<bool> any) & -> bool;

#line 1934 "regex.h2"
    public: [[nodiscard]] auto grab_until(cpp2::in<std::string> e, cpp2::out<std::string> r) & -> auto;
    public: [[nodiscard]] auto grab_until(cpp2::in<char> e, cpp2::out<std::string> r) & -> auto;
    public: [[nodiscard]] auto grab_until_one_of(cpp2::in<std::string> e, cpp2::out<std::string> r) & -> auto;

    public: [[nodiscard]] auto grab_n(cpp2::in<int> n, cpp2::out<std::string> r) & -> bool;

#line 1950 "regex.h2"
    public: [[nodiscard]] auto grab_number() & -> std::string;

#line 1970 "regex.h2"
    // Misc functions
    //
    public: auto error(cpp2::in<std::string> message) & -> void;

#line 1977 "regex.h2"
    public: [[nodiscard]] static auto join(auto const& list, auto const& func) -> std::string;

#line 1989 "regex.h2"
    public: [[nodiscard]] static auto join(cpp2::in<std::vector<std::string>> list) -> auto;

#line 1992 "regex.h2"
    // Creator functions for matchers.
    //

    public: [[nodiscard]] auto create_matcher(cpp2::in<std::string> name, cpp2::in<std::string> template_arguments) const& -> auto;

#line 2002 "regex.h2"
    public: [[nodiscard]] auto create_matcher_from_list(auto const& list) & -> auto;

    public: [[nodiscard]] auto create_matcher_from_state() & -> std::string;

#line 2020 "regex.h2"
    public: [[nodiscard]] auto create_named_groups_list() const& -> std::string;

#line 2030 "regex.h2"
    // Parser helper functions.

    public: [[nodiscard]] auto parse_lookahead(cpp2::in<std::string> name, cpp2::in<bool> positive) & -> bool;

#line 2043 "regex.h2"
    public: [[nodiscard]] auto parser_expression_modifiers() & -> std::string;

#line 2079 "regex.h2"
    public: [[nodiscard]] auto parser_group_modifiers(cpp2::in<std::string> change_str, cpp2::out<std::string> modifier_change, 
                      regex_parser_modifier_state& parser_modifiers) & -> bool;

#line 2144 "regex.h2"
    // Parsing functions
    //

    public: [[nodiscard]] auto is_alternative(cpp2::in<char> c) & -> bool;

#line 2155 "regex.h2"
    public: [[nodiscard]] auto is_anchor(cpp2::in<char> c) & -> bool;

#line 2168 "regex.h2"
    public: [[nodiscard]] auto is_any(cpp2::in<char> c) & -> bool;

#line 2176 "regex.h2"
    public: [[nodiscard]] auto is_class(cpp2::in<char> c) & -> bool;

#line 2283 "regex.h2"
    public: [[nodiscard]] auto is_escape(cpp2::in<char> c) & -> bool;

#line 2450 "regex.h2"
    public: [[nodiscard]] auto is_group(cpp2::in<char> c) & -> bool;

#line 2582 "regex.h2"
    public: [[nodiscard]] auto is_handle_special(cpp2::in<char> c) & -> bool;

#line 2589 "regex.h2"
    public: [[nodiscard]] auto is_range(cpp2::in<char> c) & -> bool;

#line 2652 "regex.h2"
    public: [[nodiscard]] auto is_special_range(cpp2::in<char> c) & -> bool;

#line 2688 "regex.h2"
    public: auto parse_until(cpp2::in<char> term) & -> void;

#line 2710 "regex.h2"
    public: [[nodiscard]] auto parse_until_new(cpp2::in<char> term) & -> std::string;

#line 2736 "regex.h2"
    public: [[nodiscard]] auto create_named_group_lookup() const& -> std::string;

#line 2758 "regex.h2"
    public: [[nodiscard]] auto parse() & -> std::string;
    public: regex_parser(regex_parser const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_parser const&) -> void = delete;


#line 2783 "regex.h2"
};

template<typename Err> [[nodiscard]] auto generate_template(cpp2::in<std::string_view> regex, cpp2::in<std::string_view> modifier, Err const& err) -> std::string;

#line 2792 "regex.h2"
}
}


//=== Cpp2 function definitions =================================================

#line 1 "regex.h2"

#line 15 "regex.h2"
namespace cpp2 {

namespace regex {

#line 24 "regex.h2"
//-----------------------------------------------------------------------
//
//  Helper structures for the expression matching.
//
//-----------------------------------------------------------------------
//

#line 32 "regex.h2"
    inline CPP2_CONSTEXPR int expression_flags::case_insensitive = 1;// mod: i
    inline CPP2_CONSTEXPR int expression_flags::multiple_lines = 2;// mod: m
    inline CPP2_CONSTEXPR int expression_flags::single_line = 4;// mod: s
    inline CPP2_CONSTEXPR int expression_flags::no_group_captures = 8;// mod: n
    inline CPP2_CONSTEXPR int expression_flags::perl_code_syntax = 16;// mod: x
    inline CPP2_CONSTEXPR int expression_flags::perl_code_syntax_in_classes = 32;// mod: xx

#line 40 "regex.h2"
// TODO: @enum as template parameter yields two error:
//     error: type 'range_flags' of non-type template parameter is not a structural type
//     error: non-type template parameter has incomplete type 'range_flags'

    inline CPP2_CONSTEXPR int range_flags::not_greedy = 1;
    inline CPP2_CONSTEXPR int range_flags::greedy = 2;
    inline CPP2_CONSTEXPR int range_flags::possessive = 3;

#line 69 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> match_context<CharT,Iter,max_groups,max_alternatives>::match_context(Iter const& begin_, Iter const& end_)
        : begin{ begin_ }
        , end{ end_ }{

#line 72 "regex.h2"
    }

#line 74 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> match_context<CharT,Iter,max_groups,max_alternatives>::match_context(match_context const& that)
                                   : begin{ that.begin }
                                   , end{ that.end }
                                   , groups{ that.groups }
                                   , alternatives_pos{ that.alternatives_pos }{}
#line 74 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> auto match_context<CharT,Iter,max_groups,max_alternatives>::operator=(match_context const& that) -> match_context& {
                                   begin = that.begin;
                                   end = that.end;
                                   groups = that.groups;
                                   alternatives_pos = that.alternatives_pos;
                                   return *this; }
#line 74 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> match_context<CharT,Iter,max_groups,max_alternatives>::match_context(match_context&& that) noexcept
                                   : begin{ std::move(that).begin }
                                   , end{ std::move(that).end }
                                   , groups{ std::move(that).groups }
                                   , alternatives_pos{ std::move(that).alternatives_pos }{}
#line 74 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> auto match_context<CharT,Iter,max_groups,max_alternatives>::operator=(match_context&& that) noexcept -> match_context& {
                                   begin = std::move(that).begin;
                                   end = std::move(that).end;
                                   groups = std::move(that).groups;
                                   alternatives_pos = std::move(that).alternatives_pos;
                                   return *this; }

    // Getter and setter for groups
    //
#line 78 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::get_group(auto const& group) const& -> auto { return CPP2_ASSERT_IN_BOUNDS(groups, group);  }

#line 80 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::get_group_string(auto const& group) const& -> std::string{
        if (cpp2::cmp_greater_eq(group,max_groups) || !(CPP2_ASSERT_IN_BOUNDS(groups, group).matched)) {
            return ""; 
        }
        return std::string(CPP2_ASSERT_IN_BOUNDS(groups, group).start, CPP2_ASSERT_IN_BOUNDS(groups, group).end); 
    }
#line 86 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::get_group_start(auto const& group) const& -> int{
        if (cpp2::cmp_greater_eq(group,max_groups) || !(CPP2_ASSERT_IN_BOUNDS(groups, group).matched)) {
            return 0; 
        }
        return std::distance(begin, CPP2_ASSERT_IN_BOUNDS(groups, group).start); 
    }
#line 92 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::get_group_end(auto const& group) const& -> int{
        if (cpp2::cmp_greater_eq(group,max_groups) || !(CPP2_ASSERT_IN_BOUNDS(groups, group).matched)) {
            return 0; 
        }
        return std::distance(begin, CPP2_ASSERT_IN_BOUNDS(groups, group).end); 
    }

#line 99 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> auto match_context<CharT,Iter,max_groups,max_alternatives>::set_group_end(auto const& group, auto const& pos) & -> void{
        CPP2_ASSERT_IN_BOUNDS(groups, group).end = pos;
        CPP2_ASSERT_IN_BOUNDS(groups, group).matched = true;
    }

#line 104 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> auto match_context<CharT,Iter,max_groups,max_alternatives>::set_group_invalid(auto const& group) & -> void{
        CPP2_ASSERT_IN_BOUNDS(groups, group).matched = false;
    }

#line 108 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> auto match_context<CharT,Iter,max_groups,max_alternatives>::set_group_start(auto const& group, auto const& pos) & -> void{
        CPP2_ASSERT_IN_BOUNDS(groups, group).start = pos;
    }

#line 112 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::size() const& -> auto { return max_groups;  }

    // Getter and setter for alternatives

#line 116 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::get_alternative_pos(auto const& alternative) const& -> auto { return CPP2_ASSERT_IN_BOUNDS(alternatives_pos, alternative);  }

#line 118 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> auto match_context<CharT,Iter,max_groups,max_alternatives>::set_alternative_pos(auto const& alternative, auto const& pos) & -> void{
        CPP2_ASSERT_IN_BOUNDS(alternatives_pos, alternative) = pos;
    }

    // Misc functions
    //
#line 124 "regex.h2"
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

#line 138 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::fail() const& -> auto { return match_return(false, end); }
#line 139 "regex.h2"
    template <typename CharT, typename Iter, int max_groups, int max_alternatives> [[nodiscard]] auto match_context<CharT,Iter,max_groups,max_alternatives>::pass(cpp2::in<Iter> cur) const& -> auto { return match_return(true, cur);  }

#line 143 "regex.h2"
// Flag change for matching modifiers. Creates a new flag for match_modifiers.
// See expression_flags for possible flags.
//

#line 148 "regex.h2"
    template <bool has_change_, bool reset_, int add_, int remove_, fixed_string str> inline CPP2_CONSTEXPR bool match_modifiers_state_change<has_change_,reset_,add_,remove_,str>::reset = reset_;
    template <bool has_change_, bool reset_, int add_, int remove_, fixed_string str> inline CPP2_CONSTEXPR int match_modifiers_state_change<has_change_,reset_,add_,remove_,str>::add = add_;
    template <bool has_change_, bool reset_, int add_, int remove_, fixed_string str> inline CPP2_CONSTEXPR int match_modifiers_state_change<has_change_,reset_,add_,remove_,str>::remove = remove_;
    template <bool has_change_, bool reset_, int add_, int remove_, fixed_string str> inline CPP2_CONSTEXPR bool match_modifiers_state_change<has_change_,reset_,add_,remove_,str>::has_change = has_change_;

#line 153 "regex.h2"
    template <bool has_change_, bool reset_, int add_, int remove_, fixed_string str> [[nodiscard]] constexpr auto match_modifiers_state_change<has_change_,reset_,add_,remove_,str>::combine_inner(cpp2::in<int> old_flags) -> auto{
        auto new_flags {old_flags}; 
        if (reset) {
            new_flags = 0;
        }
        new_flags = new_flags | add;
        new_flags = new_flags & (~remove);

        return new_flags; 
    }

#line 164 "regex.h2"
    template <bool has_change_, bool reset_, int add_, int remove_, fixed_string str> [[nodiscard]] auto match_modifiers_state_change<has_change_,reset_,add_,remove_,str>::to_string() -> auto { return CPP2_UFCS(data)(str);  }

#line 169 "regex.h2"
// Current modifiers for the regular expression.
// See expression_flags for possible flags.
//

#line 174 "regex.h2"
    template <int flags_, typename Inner> inline CPP2_CONSTEXPR int match_modifiers<flags_,Inner>::flags = flags_;

    // Push/pop management

#line 178 "regex.h2"
    template <int flags_, typename Inner> template<typename Change> [[nodiscard]] auto match_modifiers<flags_,Inner>::push([[maybe_unused]] Change const& unnamed_param_1) -> auto { return match_modifiers<Change::combine_inner(flags),match_modifiers<flags,Inner>>(); }
#line 179 "regex.h2"
    template <int flags_, typename Inner> [[nodiscard]] auto match_modifiers<flags_,Inner>::pop() -> auto { return Inner(); }
#line 180 "regex.h2"
    template <int flags_, typename Inner> template<typename Change> [[nodiscard]] auto match_modifiers<flags_,Inner>::replace([[maybe_unused]] Change const& unnamed_param_1) -> auto { return match_modifiers<Change::combine_inner(flags),Inner>();  }

    // Flag management
    //

#line 185 "regex.h2"
    template <int flags_, typename Inner> [[nodiscard]] auto match_modifiers<flags_,Inner>::has_flag(cpp2::in<int> f) const& -> bool{
        return  0 != (f & flags); 
    }

#line 190 "regex.h2"
//  Represents the remainder of the regular expression.
//
//  A matcher can ask this remainder if it would match. If yes a full match of the regular expression is found.
//  Otherwise the matcher can try a different alternative.
//

#line 196 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto matcher_list<CharT,List...>::match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func) -> auto { return match_select<List...>(cur, ctx, modifiers, end_func);  }

#line 198 "regex.h2"
    template <typename CharT, typename ...List> template<typename ...OtherList> [[nodiscard]] auto matcher_list<CharT,List...>::match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] matcher_list<CharT,OtherList...> const& unnamed_param_5) -> auto { 
        return match_select<List...,OtherList...>(cur, ctx, modifiers, end_func);  }

#line 201 "regex.h2"
    template <typename CharT, typename ...List> template<typename First, typename ...Other> [[nodiscard]] auto matcher_list<CharT,List...>::match_select(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func) -> auto { 
        return First::match(cur, ctx, modifiers, end_func, matcher_list<CharT,Other...>());  }
#line 203 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto matcher_list<CharT,List...>::match_select(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func) -> auto { return end_func(cur, ctx, modifiers);  }

#line 205 "regex.h2"
    template <typename CharT, typename ...List> auto matcher_list<CharT,List...>::reset_ranges(auto& ctx) -> void { (List::reset_ranges(ctx), ...);  }
#line 206 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto matcher_list<CharT,List...>::to_string() -> auto { return (bstring<CharT>() + ... + List::to_string());  }

#line 208 "regex.h2"
    template <typename CharT, typename ...List> template<typename Pre> [[nodiscard]] auto matcher_list<CharT,List...>::prepend([[maybe_unused]] Pre const& unnamed_param_1) -> auto { return matcher_list<CharT,Pre,List...>();  }

#line 213 "regex.h2"
    [[nodiscard]] auto true_end_func::operator()(auto const& cur, auto& ctx, [[maybe_unused]] auto const& unnamed_param_4) const& -> auto { return CPP2_UFCS(pass)(ctx, cur);  }

#line 216 "regex.h2"
//-----------------------------------------------------------------------
//
//  Character classes for regular expressions.
//
//-----------------------------------------------------------------------
//

// Class syntax: <any character> Example: a
//

#line 227 "regex.h2"
    template <typename CharT, CharT C> [[nodiscard]] auto single_class_entry<CharT,C>::includes(cpp2::in<CharT> c) -> auto { return c == C;  }
#line 228 "regex.h2"
    template <typename CharT, CharT C> [[nodiscard]] auto single_class_entry<CharT,C>::to_string() -> auto { return bstring<CharT>(1, C); }

#line 231 "regex.h2"
// Class syntax: - Example: a-c
//

#line 235 "regex.h2"
    template <typename CharT, CharT Start, CharT End> [[nodiscard]] auto range_class_entry<CharT,Start,End>::includes(cpp2::in<CharT> c) -> auto { return [_0 = Start, _1 = c, _2 = End]{ return cpp2::cmp_less_eq(_0,_1) && cpp2::cmp_less_eq(_1,_2); }();  }
#line 236 "regex.h2"
    template <typename CharT, CharT Start, CharT End> [[nodiscard]] auto range_class_entry<CharT,Start,End>::to_string() -> auto { return cpp2::to_string(Start) + "-" + cpp2::to_string(End); }

#line 239 "regex.h2"
// Helper for combining two character classes
//

#line 242 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto combined_class_entry<CharT,List...>::includes(cpp2::in<CharT> c) -> auto { return (false || ... || List::includes(c));  }
#line 243 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto combined_class_entry<CharT,List...>::to_string() -> auto { return (bstring<CharT>() + ... + List::to_string()); }

#line 246 "regex.h2"
// Class syntax: <list of characters>  Example: abcd
//

#line 249 "regex.h2"
    template <typename CharT, CharT ...List> [[nodiscard]] auto list_class_entry<CharT,List...>::includes(cpp2::in<CharT> c) -> auto { return (false || ... || (List == c));  }
#line 250 "regex.h2"
    template <typename CharT, CharT ...List> [[nodiscard]] auto list_class_entry<CharT,List...>::to_string() -> auto { return (bstring<CharT>() + ... + List); }

#line 253 "regex.h2"
// Class syntax: [:<class name:]  Example: [:alnum:]
//

#line 256 "regex.h2"
    template <typename CharT, fixed_string Name, typename Inner> [[nodiscard]] auto named_class_entry<CharT,Name,Inner>::includes(cpp2::in<CharT> c) -> auto { return Inner::includes(c);  }
#line 257 "regex.h2"
    template <typename CharT, fixed_string Name, typename Inner> [[nodiscard]] auto named_class_entry<CharT,Name,Inner>::to_string() -> auto { return "[:" + cpp2::to_string(CPP2_UFCS(data)(Name)) + ":]"; }

#line 262 "regex.h2"
    template <typename CharT, typename Inner> [[nodiscard]] auto negated_class_entry<CharT,Inner>::includes(cpp2::in<CharT> c) -> auto { return !(Inner::includes(c));  }

#line 265 "regex.h2"
// Short class syntax: \<character>  Example: \w
//

#line 268 "regex.h2"
    template <typename CharT, fixed_string Name, typename Inner> [[nodiscard]] auto shorthand_class_entry<CharT,Name,Inner>::includes(cpp2::in<CharT> c) -> auto { return Inner::includes(c);  }
#line 269 "regex.h2"
    template <typename CharT, fixed_string Name, typename Inner> [[nodiscard]] auto shorthand_class_entry<CharT,Name,Inner>::to_string() -> auto { return CPP2_UFCS(str)(Name); }

#line 273 "regex.h2"
// Named basic character classes
//

#line 279 "regex.h2"
// Named other classes
//

#line 295 "regex.h2"
// Shorthand class entries
//

#line 310 "regex.h2"
//-----------------------------------------------------------------------
//
//  Helper matchers for regular expressions.
//
//-----------------------------------------------------------------------
//

// Regex syntax: none Example: -
//

#line 320 "regex.h2"
    template <typename CharT> template<typename Other> [[nodiscard]] auto empty_matcher_logic<CharT>::match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto { return Other::match(cur, ctx, modifiers, end_func);  }
#line 321 "regex.h2"
    template <typename CharT> auto empty_matcher_logic<CharT>::reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void{}
#line 322 "regex.h2"
    template <typename CharT> [[nodiscard]] auto empty_matcher_logic<CharT>::to_string() -> auto { return bstring<CharT>(); }

#line 326 "regex.h2"
// Helper for greedy alternatives
//

#line 329 "regex.h2"
    template <typename CharT, size_t alternative> template<typename Other> [[nodiscard]] auto extract_position_helper<CharT,alternative>::match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto{
        auto r {Other::match(cur, ctx, modifiers, end_func)}; 
        if (r.matched) {
            CPP2_UFCS(set_alternative_pos)(ctx, alternative, cur);
        }
        return r; 
    }

#line 337 "regex.h2"
    template <typename CharT, size_t alternative> auto extract_position_helper<CharT,alternative>::reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void{}
#line 338 "regex.h2"
    template <typename CharT, size_t alternative> [[nodiscard]] auto extract_position_helper<CharT,alternative>::to_string() -> auto { return bstring<CharT>(); }

#line 341 "regex.h2"
// Helper for standard matchers with special syntax
//
//

#line 346 "regex.h2"
    template <typename CharT, fixed_string syntax, typename base> [[nodiscard]] auto special_syntax_wrapper<CharT,syntax,base>::to_string() -> auto { return CPP2_UFCS(str)(syntax); }

#line 349 "regex.h2"
//-----------------------------------------------------------------------
//
// Matchers and generators for regular expressions.
//
//-----------------------------------------------------------------------
//

#line 358 "regex.h2"
    auto no_reset::operator()([[maybe_unused]] auto& unnamed_param_2) const& -> void{}

#line 366 "regex.h2"
    regex_token::regex_token(cpp2::in<bool> state, cpp2::in<std::string> str)
        : needs_state{ state }
        , string_rep{ str }{

#line 369 "regex.h2"
    }

    //parse: (inout ctx: parse_context) -> token_ptr;

#line 375 "regex.h2"
    [[nodiscard]] auto regex_token::requires_state() const& -> bool{return needs_state; }
#line 376 "regex.h2"
    [[nodiscard]] auto regex_token::to_string() const& -> std::string{return string_rep; }

    regex_token::~regex_token() noexcept{}

#line 391 "regex.h2"
    parse_context::parse_context(cpp2::in<std::string_view> r)
        : regex{ r }{

#line 393 "regex.h2"
    }
#line 391 "regex.h2"
    auto parse_context::operator=(cpp2::in<std::string_view> r) -> parse_context& {
        regex = r;
        pos = 0;
        error_text = "";
        cur_state = {};
        return *this;

#line 393 "regex.h2"
    }

#line 395 "regex.h2"
    auto parse_context::add_token(cpp2::in<token_ptr> token) & -> void{
        CPP2_UFCS(push_back)(cur_state, token);
    }

#line 399 "regex.h2"
    [[nodiscard]] auto parse_context::has_token() const& -> bool{
        return !(CPP2_UFCS(empty)(cur_state)); 
    }

#line 403 "regex.h2"
    [[nodiscard]] auto parse_context::pop_token() & -> token_ptr{
        token_ptr r {nullptr}; 
        if (has_token()) {
            r = CPP2_UFCS(back)(cur_state);
            CPP2_UFCS(pop_back)(cur_state);
        }

        return r; 
    }

#line 413 "regex.h2"
    [[nodiscard]] auto parse_context::get_tokens() const& -> token_vec{
        return cur_state; 
    }

#line 417 "regex.h2"
    [[nodiscard]] auto parse_context::current() const& -> char{return CPP2_ASSERT_IN_BOUNDS(regex, pos); }

#line 419 "regex.h2"
    [[nodiscard]] auto parse_context::has_next() const& -> bool{return cpp2::cmp_less(pos,CPP2_UFCS(size)(regex)); }
#line 420 "regex.h2"
    [[nodiscard]] auto parse_context::next() & -> bool{
        if (has_next()) {
            pos += 1; return true; 
        }

        return false; 
    }

#line 428 "regex.h2"
    [[nodiscard]] auto parse_context::valid() const& -> bool{return has_next() && CPP2_UFCS(empty)(error_text); }

#line 430 "regex.h2"
    [[nodiscard]] auto parse_context::error(cpp2::in<std::string> err) & -> token_ptr{
        error_text = err;
        return nullptr; 
    }

#line 435 "regex.h2"
    [[nodiscard]] auto parse_context::get_next_position(cpp2::in<bool> in_class, cpp2::in<bool> no_skip) const& -> size_t{
        auto perl_syntax {false}; 
        if (!(no_skip)) {
            // TODO: 
            // if in_class {
            //     perl_syntax = cur_group_state.modifiers.perl_code_syntax && cur_group_state.modifiers.perl_code_syntax_in_classes;
            // }
            // else {
            //     perl_syntax = cur_group_state.modifiers.perl_code_syntax;
            // }
        }
        auto cur {pos + 1}; 
        if (std::move(perl_syntax)) {
            for( ; cpp2::cmp_less(cur,CPP2_UFCS(size)(regex)); (cur += 1) ) {
                auto n {CPP2_ASSERT_IN_BOUNDS(regex, cur)}; 

                if (space_class<char>::includes(n)) {
                    continue;
                }
                else {if (!(in_class) && '#' == std::move(n)) {
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

#line 475 "regex.h2"
    [[nodiscard]] auto parse_context::grab_until_impl(cpp2::in<std::string> e, cpp2::out<std::string> r, cpp2::in<bool> any) & -> bool{
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

#line 496 "regex.h2"
    [[nodiscard]] auto parse_context::grab_until(cpp2::in<std::string> e, cpp2::out<std::string> r) & -> auto { return grab_until_impl(e, cpp2::out(&r), false); }
#line 497 "regex.h2"
    [[nodiscard]] auto parse_context::grab_until(cpp2::in<char> e, cpp2::out<std::string> r) & -> auto { return grab_until_impl(std::string(1, e), cpp2::out(&r), false); }
#line 498 "regex.h2"
    [[nodiscard]] auto parse_context::grab_until_one_of(cpp2::in<std::string> e, cpp2::out<std::string> r) & -> auto { return grab_until_impl(e, cpp2::out(&r), true);  }

#line 500 "regex.h2"
    [[nodiscard]] auto parse_context::peek_impl(cpp2::in<bool> in_class) const& -> char{
        auto next_pos {get_next_position(in_class, false)}; 
        if (cpp2::cmp_less(next_pos,CPP2_UFCS(size)(regex))) {
            return CPP2_ASSERT_IN_BOUNDS(regex, std::move(next_pos)); 
        }
        else {
            return '\0'; 
        }
    }

#line 510 "regex.h2"
    [[nodiscard]] auto parse_context::peek() const& -> auto { return peek_impl(false); }
#line 511 "regex.h2"
    [[nodiscard]] auto parse_context::peek_in_class() const& -> auto { return peek_impl(true);  }

#line 520 "regex.h2"
    auto generation_function_context::add_tabs(cpp2::in<int> c) & -> void{
        int i {0}; 
        for( ; cpp2::cmp_less(i,c); i += 1 ) {
            tabs += "  ";
        }
    }

#line 527 "regex.h2"
    auto generation_function_context::remove_tabs(cpp2::in<int> c) & -> void{
        tabs = CPP2_UFCS(substr)(tabs, 0, c * 2);
    }

#line 541 "regex.h2"
    [[nodiscard]] auto generation_context::match_parameters() const& -> std::string{return "r.pos, ctx, modifiers"; }

#line 543 "regex.h2"
    auto generation_context::add_check(cpp2::in<std::string> check) & -> void{
        auto cur {get_current()}; 
        (*cpp2::assert_not_null(cur)).code += (cpp2::to_string((*cpp2::assert_not_null(cur)).tabs) + "if !cpp2::regex::" + cpp2::to_string(check) + " { r = ctx.fail(); return r; }\n");
    }

#line 548 "regex.h2"
    auto generation_context::add_statefull(cpp2::in<std::string> next_func, cpp2::in<std::string> c) & -> void{
        end_func_statefull(c);

        start_func_named(next_func);
    }

#line 554 "regex.h2"
    [[nodiscard]] auto generation_context::run(cpp2::in<token_vec> tokens) & -> std::string{
        entry_func = generate_func(tokens);

        return (*cpp2::assert_not_null(get_base())).code; 
    }

#line 560 "regex.h2"
    [[nodiscard]] auto generation_context::generate_func(cpp2::in<token_vec> tokens) & -> std::string{
        auto name {start_func()}; 
        for ( auto const& token : tokens ) {
            CPP2_UFCS(generate_code)((*cpp2::assert_not_null(token)), (*this));
        }
        end_func();

        return name; 
    }

#line 570 "regex.h2"
    [[nodiscard]] auto generation_context::generate_func(cpp2::in<token_ptr> token) & -> std::string{
        auto name {start_func()}; 
        CPP2_UFCS(generate_code)((*cpp2::assert_not_null(token)), (*this));
        end_func();

        return name; 
    }

#line 578 "regex.h2"
    [[nodiscard]] auto generation_context::generate_reset(cpp2::in<std::vector<int>> groups) & -> std::string{
        if (CPP2_UFCS(empty)(groups)) {
            return "cpp2::regex::no_reset"; 
        }

        auto name {gen_reset_func_name()}; 
        auto cur {new_context()}; 

        (*cpp2::assert_not_null(cur)).code += (cpp2::to_string((*cpp2::assert_not_null(cur)).tabs) + cpp2::to_string(name) + ": @struct type = {\n");
        (*cpp2::assert_not_null(cur)).code += "(cur*.tabs)  operator(): (this, inout ctx) = {\n";
        for ( auto const& g : groups ) {
            (*cpp2::assert_not_null(cur)).code += ("(cur*.tabs)  ctx.set_group_invalid(" + cpp2::to_string(g) + ");\n");
        }
        (*cpp2::assert_not_null(cur)).code += "(cur*.tabs)  }\n";
        (*cpp2::assert_not_null(cur)).code += "(cur*.tabs)}\n";

        finish_context();

        return name; 
    }

#line 600 "regex.h2"
    [[nodiscard]] auto generation_context::get_current() & -> generation_function_context*{
        return &CPP2_UFCS(back)(gen_stack); 
    }

#line 604 "regex.h2"
    [[nodiscard]] auto generation_context::get_base() & -> generation_function_context*{
        return &CPP2_ASSERT_IN_BOUNDS_LITERAL(gen_stack, 0); 
    }

#line 608 "regex.h2"
    auto generation_context::start_func_named(cpp2::in<std::string> name) & -> void{
        auto cur {new_context()}; 

        (*cpp2::assert_not_null(cur)).code += (cpp2::to_string((*cpp2::assert_not_null(cur)).tabs) + cpp2::to_string(name) + ": @struct type = {\n");
        (*cpp2::assert_not_null(cur)).code += (cpp2::to_string((*cpp2::assert_not_null(cur)).tabs) + "  operator(): (this, cur, inout ctx, modifiers, other) -> _ = {\n");
        (*cpp2::assert_not_null(cur)).code += (cpp2::to_string((*cpp2::assert_not_null(cur)).tabs) + "    r := ctx.pass(cur);\n");
        CPP2_UFCS(add_tabs)((*cpp2::assert_not_null(std::move(cur))), 2);
    }

#line 617 "regex.h2"
    [[nodiscard]] auto generation_context::start_func() & -> std::string{
        auto name {gen_func_name()}; 
        start_func_named(name);
        return name; 
    }

#line 623 "regex.h2"
    auto generation_context::end_func_statefull(cpp2::in<std::string> s) & -> void{
        auto cur {get_current()}; 
        CPP2_UFCS(remove_tabs)((*cpp2::assert_not_null(cur)), 2);
        (*cpp2::assert_not_null(cur)).code += "\n";
        (*cpp2::assert_not_null(cur)).code += (cpp2::to_string((*cpp2::assert_not_null(cur)).tabs) + "    r = " + cpp2::to_string(s) + ";\n");
        (*cpp2::assert_not_null(cur)).code += (cpp2::to_string((*cpp2::assert_not_null(cur)).tabs) + "    return r;\n");
        (*cpp2::assert_not_null(cur)).code += (cpp2::to_string((*cpp2::assert_not_null(cur)).tabs) + "  }\n");
        (*cpp2::assert_not_null(cur)).code += (cpp2::to_string((*cpp2::assert_not_null(cur)).tabs) + "}\n");

        finish_context();
    }

#line 635 "regex.h2"
    auto generation_context::end_func() & -> void{
        end_func_statefull("other(r.pos, ctx, modifiers)");
    }

#line 639 "regex.h2"
    [[nodiscard]] auto generation_context::get_entry_func() const& -> std::string{
        return entry_func; 
    }

#line 643 "regex.h2"
    [[nodiscard]] auto generation_context::gen_func_name() & -> std::string{
        auto cur_id {matcher_func}; 
        matcher_func += 1;
        return { "func_" + cpp2::to_string(std::move(cur_id)) }; 
    }

#line 649 "regex.h2"
    [[nodiscard]] auto generation_context::gen_reset_func_name() & -> std::string{
        auto cur_id {reset_func}; 
        reset_func += 1;
        return { "reset_" + cpp2::to_string(std::move(cur_id)) }; 
    }

#line 655 "regex.h2"
    [[nodiscard]] auto generation_context::new_context() & -> generation_function_context*{
        CPP2_UFCS(push_back)(gen_stack, generation_function_context());
        auto cur {get_current()}; 
        (*cpp2::assert_not_null(cur)).tabs = "    ";

        return cur; 
    }

#line 663 "regex.h2"
    auto generation_context::finish_context() & -> void{
        auto cur {get_current()}; 
        auto base {get_base()}; 
        (*cpp2::assert_not_null(base)).code += (*cpp2::assert_not_null(std::move(cur))).code;

        CPP2_UFCS(pop_back)(gen_stack);
    }

#line 675 "regex.h2"
    regex_token_base::regex_token_base(cpp2::in<bool> state, cpp2::in<std::string> str)
        : regex_token{ state, str }{

#line 677 "regex.h2"
    }

#line 679 "regex.h2"
    [[nodiscard]] auto regex_token_base::get_groups() const -> std::vector<int>{return {  }; }

    regex_token_base::~regex_token_base() noexcept{}

#line 687 "regex.h2"
    char_token::char_token(cpp2::in<char> t)
        : regex_token_base{ false, std::string(1, t) }
        , token{ t }{

#line 690 "regex.h2"
    }

#line 692 "regex.h2"
    [[nodiscard]] auto char_token::parse(parse_context& ctx) -> token_ptr{
        return CPP2_UFCS_TEMPLATE(cpp2_new<char_token>)(cpp2::shared, CPP2_UFCS(current)(ctx)); 
    }

#line 696 "regex.h2"
    auto char_token::generate_code(generation_context& ctx) const -> void{
        auto upper {safe_toupper(token)}; 
        auto lower {safe_tolower(token)}; 
        CPP2_UFCS(add_check)(ctx, ("char_token_matcher<char, '" + cpp2::to_string(token) + "', '" + cpp2::to_string(std::move(lower)) + "', '" + cpp2::to_string(std::move(upper)) + "'>(" + cpp2::to_string(CPP2_UFCS(match_parameters)(ctx)) + ")"));
    }

    char_token::~char_token() noexcept{}

#line 703 "regex.h2"
template<typename CharT, CharT C, CharT L, CharT U> [[nodiscard]] auto char_token_matcher(auto& cur, auto& ctx, auto const& modifiers) -> bool{
    if (CPP2_UFCS(has_flag)(modifiers, expression_flags::case_insensitive)) {
        if (cur != ctx.end && (*cpp2::assert_not_null(cur) == L || *cpp2::assert_not_null(cur) == U)) {
            cur += 1;
            return true; 
        }
        else {
            return false; 
        }
    }
    else {
        if (cur != ctx.end && *cpp2::assert_not_null(cur) == C) {
            cur += 1;
            return true; 
        }
        else {
            return false; 
        }
    }
}

#line 733 "regex.h2"
    range_token::range_token()
                             : regex_token{ true, "" }{}

#line 735 "regex.h2"
    [[nodiscard]] auto range_token::parse(parse_context& ctx) -> token_ptr{
        auto r {CPP2_UFCS_TEMPLATE(cpp2_new<range_token>)(cpp2::shared)}; 
        if (CPP2_UFCS(current)(ctx) == '{') {
            if (!(CPP2_UFCS(has_token)(ctx))) {return CPP2_UFCS(error)(ctx, "'{' without previous element."); }

            std::string inner {""}; 
            if (!(CPP2_UFCS(grab_until)(ctx, '}', cpp2::out(&inner)))) {return CPP2_UFCS(error)(ctx, "Missing closing bracket '}'."); }

            inner = trim_copy(CPP2_UFCS(substr)(inner, 1));// Remove '{' and white spaces.
            if (CPP2_UFCS(empty)(inner)) {return CPP2_UFCS(error)(ctx, "Empty range specifier. Either '{n}', '{n,}', '{,m}' '{n,m}'"); }

            // Non-greedy or possessive
            CPP2_UFCS(parse_modifier)((*cpp2::assert_not_null(r)), ctx);

            // Get range arguments
            std::string min_count_str {"-1"}; 
            std::string max_count_str {"-1"}; 

            size_t sep {CPP2_UFCS(find)(inner, ",")}; 
            if (sep == std::string::npos) {
                min_count_str = inner;
                max_count_str = inner;
                if (!(string_to_int(std::move(inner), (*cpp2::assert_not_null(r)).min_count))) {return CPP2_UFCS(error)(ctx, "Could not convert range to number."); }
                (*cpp2::assert_not_null(r)).max_count = (*cpp2::assert_not_null(r)).min_count;
            }
            else {
                std::string inner_first {trim_copy(CPP2_UFCS(substr)(inner, 0, sep))}; 
                std::string inner_last {trim_copy(CPP2_UFCS(substr)(std::move(inner), std::move(sep) + 1))}; 

                if ((CPP2_UFCS(empty)(inner_first) && CPP2_UFCS(empty)(inner_last))) {
                    return CPP2_UFCS(error)(ctx, "Empty range specifier. Either '{n}', '{n,}', '{,m}' '{n,m}'"); 
                }

                if (!(CPP2_UFCS(empty)(inner_first))) {
                    min_count_str = inner_first;
                    if (!(string_to_int(std::move(inner_first), (*cpp2::assert_not_null(r)).min_count))) {return CPP2_UFCS(error)(ctx, "Could not convert range to number."); }
                }
                if (!(CPP2_UFCS(empty)(inner_last))) {
                    max_count_str = inner_last;
                    if (!(string_to_int(std::move(inner_last), (*cpp2::assert_not_null(r)).max_count))) {return CPP2_UFCS(error)(ctx, "Could not convert range to number."); }
                }
            }

#line 779 "regex.h2"
            // Check validity of the range.
            if (-1 != (*cpp2::assert_not_null(r)).min_count) {
                if (!((cpp2::cmp_less_eq(0,(*cpp2::assert_not_null(r)).min_count)))) {
                    return CPP2_UFCS(error)(ctx, ("Min value in range is negative. Have " + cpp2::to_string((*cpp2::assert_not_null(r)).min_count) + ")")); 
                }
            }
            if (-1 != (*cpp2::assert_not_null(r)).max_count) {
                if (!((cpp2::cmp_less_eq(0,(*cpp2::assert_not_null(r)).max_count)))) {
                    return CPP2_UFCS(error)(ctx, ("Max value in range is negative. Have " + cpp2::to_string((*cpp2::assert_not_null(r)).max_count) + ")")); 
                }
                if (-1 != (*cpp2::assert_not_null(r)).min_count) {
                    if (!((cpp2::cmp_less_eq((*cpp2::assert_not_null(r)).min_count,(*cpp2::assert_not_null(r)).max_count)))) {
                        return CPP2_UFCS(error)(ctx, ("Min and max values in range are wrong it should hold 0 <= min <= max. Have 0 <= " + cpp2::to_string((*cpp2::assert_not_null(r)).min_count) + " <= " + cpp2::to_string((*cpp2::assert_not_null(r)).max_count))); 
                    }
                }
            }

            (*cpp2::assert_not_null(r)).inner_token = CPP2_UFCS(pop_token)(ctx);
            (*cpp2::assert_not_null(r)).string_rep = CPP2_UFCS(to_string)((*cpp2::assert_not_null((*cpp2::assert_not_null(r)).inner_token))) + CPP2_UFCS(gen_range_string)((*cpp2::assert_not_null(r))) + CPP2_UFCS(gen_mod_string)((*cpp2::assert_not_null(r)));

            return r; 
        }

        return nullptr; 
    }

#line 805 "regex.h2"
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

#line 816 "regex.h2"
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

#line 828 "regex.h2"
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

#line 852 "regex.h2"
    auto range_token::generate_code(generation_context& ctx) const -> void{
        auto inner_name {CPP2_UFCS(generate_func)(ctx, inner_token)}; 
        auto reset_name {CPP2_UFCS(generate_reset)(ctx, CPP2_UFCS(get_groups)((*cpp2::assert_not_null(inner_token))))}; 

        auto next_name {CPP2_UFCS(gen_func_name)(ctx)}; 
        CPP2_UFCS(add_statefull)(ctx, next_name, ("cpp2::regex::range_token_matcher<char, " + cpp2::to_string(min_count) + ", " + cpp2::to_string(max_count) + ", " + cpp2::to_string(kind) + ">::match(" + cpp2::to_string(CPP2_UFCS(match_parameters)(ctx)) + ", " + cpp2::to_string(std::move(inner_name)) + "(), " + cpp2::to_string(std::move(reset_name)) + "(), other, " + cpp2::to_string(next_name) + "())"));
    }

#line 860 "regex.h2"
    [[nodiscard]] auto range_token::get_groups() const -> std::vector<int>{return {  }; }

    range_token::~range_token() noexcept{}// TODO: Implement

#line 866 "regex.h2"
    [[nodiscard]] auto special_range_token::parse(parse_context& ctx) -> token_ptr{
        auto r {CPP2_UFCS_TEMPLATE(cpp2_new<special_range_token>)(cpp2::shared)}; 
        char symbol {'\0'}; 
        if (CPP2_UFCS(current)(ctx) == '*') {
            (*cpp2::assert_not_null(r)).min_count = 0;
            (*cpp2::assert_not_null(r)).max_count = -1;
            symbol = '*';
        }
        else {if (CPP2_UFCS(current)(ctx) == '+') {
            (*cpp2::assert_not_null(r)).min_count = 1;
            (*cpp2::assert_not_null(r)).max_count = -1;
            symbol = '+';
        }else {if (CPP2_UFCS(current)(ctx) == '?') {
            (*cpp2::assert_not_null(r)).min_count = 0;
            (*cpp2::assert_not_null(r)).max_count = 1;
            symbol = '?';
        }else {
            return nullptr; 
        }}}

        if (!(CPP2_UFCS(has_token)(ctx))) {return CPP2_UFCS(error)(ctx, ("'" + cpp2::to_string(CPP2_UFCS(current)(ctx)) + "' without previous element.")); }

#line 889 "regex.h2"
        CPP2_UFCS(parse_modifier)((*cpp2::assert_not_null(r)), ctx);

        (*cpp2::assert_not_null(r)).inner_token = CPP2_UFCS(pop_token)(ctx);
        (*cpp2::assert_not_null(r)).string_rep = CPP2_UFCS(to_string)((*cpp2::assert_not_null((*cpp2::assert_not_null(r)).inner_token))) + std::move(symbol) + CPP2_UFCS(gen_mod_string)((*cpp2::assert_not_null(r)));
        return r; 
    }

    special_range_token::~special_range_token() noexcept{}

#line 899 "regex.h2"
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

#line 911 "regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::is_below_upper_bound(cpp2::in<int> count) -> bool{
        if (-1 == max_count) {return true; }
        else {return cpp2::cmp_less(count,max_count); }
    }

#line 916 "regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::is_below_lower_bound(cpp2::in<int> count) -> bool{
        if (-1 == min_count) {return false; }
        else {return cpp2::cmp_less(count,min_count); }
    }

#line 921 "regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::is_in_range(cpp2::in<int> count) -> bool{
        if (-1 != min_count && cpp2::cmp_less(count,min_count)) {return false; }
        if (-1 != max_count && cpp2::cmp_greater(count,max_count)) {return false; }
        return true; 
    }

#line 927 "regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> template<typename Iter> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::match_min_count(Iter const& cur, auto& ctx, auto const& modifiers, auto const& inner, auto const& end_func, int& count_r) -> auto{// TODO: count_r as out parameter introduces a performance loss.
        auto res {CPP2_UFCS(pass)(ctx, cur)}; 
        auto count {0}; 

        while( is_below_lower_bound(count) && res.matched ) {
            res = inner(res.pos, ctx, modifiers, end_func);
            if (res.matched) {
                count += 1;
            }
        }

        count_r = std::move(count);
        return res; 
    }

#line 942 "regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> template<typename Iter> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::match_greedy(cpp2::in<int> count, Iter const& cur, Iter const& last_valid, auto& ctx, auto const& modifiers, auto const& inner, auto const& reset_func, auto const& end_func, auto const& other) -> match_return<Iter>{
        auto inner_call {[_0 = (count + 1), _1 = (cur), _2 = (modifiers), _3 = (inner), _4 = (reset_func), _5 = (end_func), _6 = (other)](auto const& tail_cur, auto& tail_ctx, [[maybe_unused]] auto const& unnamed_param_3) -> auto{/* ignore new modifiers */
            return match_greedy(_0, tail_cur, _1, tail_ctx, _2, _3, _4, _5, _6); 
        }}; 
        auto is_m_valid {true}; 
        auto r {CPP2_UFCS(fail)(ctx)}; 
        if (is_below_upper_bound(count) && (is_below_lower_bound(count) || cur != last_valid)) {
            is_m_valid = false;  // Group ranges in M are invalidated through the call.
            r = inner(cur, ctx, modifiers, std::move(inner_call));
        }

        if (!(r.matched) && is_in_range(count)) {
            // The recursion did not yield a match try now the tail
            r = other(cur, ctx, modifiers, end_func);

            if (r.matched && !(std::move(is_m_valid))) {
                // We have a match rematch M if required
                reset_func(ctx);

                if (cpp2::cmp_greater(count,0)) {
                    static_cast<void>(inner(last_valid, ctx, modifiers, end_func));
                }
            }
        }

        return r; 
    }

#line 970 "regex.h2"
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

        return other(std::move(pos), ctx, modifiers, end_func); 
    }

#line 994 "regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> template<typename Iter> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::match_not_greedy(Iter const& cur, auto& ctx, auto const& modifiers, auto const& inner, auto const& end_func, auto const& other) -> match_return<Iter>{
        auto count {0}; 
        auto start {match_min_count(cur, ctx, modifiers, inner, end_func, count)}; 
        if (!(start.matched)) {
          return start; 
        }

        auto pos {std::move(start).pos}; 
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
            pos = std::move(r).pos;
        }

        return other(std::move(pos), ctx, modifiers, end_func); // Upper bound reached.
    }

#line 1035 "regex.h2"
    template <typename CharT, size_t alternative, typename ...List> template<typename Tail> [[nodiscard]] auto alternative_matcher_logic<CharT,alternative,List...>::match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, Tail const& tail) -> auto{
        if constexpr (greedy_alternative) {
            auto max_overall_length {0}; 
            auto max_current_length {0}; 
            auto r {match_greedy<Tail,List...>(cur, max_overall_length, max_current_length, ctx, modifiers, end_func, tail)}; 
            static_cast<void>(std::move(max_overall_length));
            static_cast<void>(std::move(max_current_length));
            return r; 
        }else {
            return match_first<List...>(cur, ctx, modifiers, end_func, tail); 
        }
    }
#line 1047 "regex.h2"
    template <typename CharT, size_t alternative, typename ...List> auto alternative_matcher_logic<CharT,alternative,List...>::reset_ranges(auto& ctx) -> void { (List::reset_ranges(ctx), ...); }
#line 1048 "regex.h2"
    template <typename CharT, size_t alternative, typename ...List> [[nodiscard]] auto alternative_matcher_logic<CharT,alternative,List...>::to_string() -> auto { return CPP2_UFCS(substr)((bstring<CharT>() + ... + ("|" + List::to_string())), 1); }// substr: Remove first '|'.

#line 1050 "regex.h2"
    template <typename CharT, size_t alternative, typename ...List> template<typename First, typename ...Next> [[nodiscard]] auto alternative_matcher_logic<CharT,alternative,List...>::match_first(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, auto const& tail) -> auto{
        auto r {First::match(cur, ctx, modifiers, end_func, tail)}; 
        if (r.matched) {
            return r; 
        }else {
            First::reset_ranges(ctx);

            if constexpr (0 != sizeof...(Next)) {
                return match_first<Next...>(cur, ctx, modifiers, end_func, tail); 
            }else {
                return CPP2_UFCS(fail)(ctx); 
            }
        }
    }

#line 1065 "regex.h2"
    template <typename CharT, size_t alternative, typename ...List> template<typename Tail, typename First, typename ...Next> [[nodiscard]] auto alternative_matcher_logic<CharT,alternative,List...>::match_greedy(auto const& cur, auto& max_overall_length, auto& max_current_length, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Tail const& unnamed_param_7) -> auto{
        auto r {First::match(cur, ctx, modifiers, end_func, Tail::prepend(extract_position_helper<CharT,alternative>()))}; 

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

#line 1081 "regex.h2"
        // Check if someone other has something larker
        auto o {CPP2_UFCS(fail)(ctx)}; 
        if constexpr (0 != sizeof...(Next)) {
            o = match_greedy<Tail,Next...>(cur, max_overall_length, max_current_length, ctx, modifiers, end_func, Tail());
        }

        auto my_current_length {unsafe_narrow<int>(std::distance(cur, std::move(end_current_pos)))}; 
        if (max_overall_length == my_overall_length) {
            max_current_length = std::max(max_current_length, my_current_length);
        }

#line 1093 "regex.h2"
        if (std::move(r).matched && std::move(my_overall_length) == max_overall_length) {
            // We are the longest. Check now if we are also the longest in this alternative.
            if (std::move(my_current_length) == max_current_length) {
                // Yes we are. Reset all groups by matching again.
                (Next::reset_ranges(ctx), ...);  // Reset all other ranges.
                return First::match(cur, ctx, modifiers, end_func, Tail::prepend(extract_position_helper<CharT,alternative>())); 
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

#line 1119 "regex.h2"
    template <typename CharT> template<typename Other> [[nodiscard]] auto any_matcher_logic<CharT>::match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto{
        if (cur != ctx.end && 
          (CPP2_UFCS(has_flag)(modifiers, expression_flags::single_line) || 
           *cpp2::assert_not_null(cur) != '\n')) {
            return Other::match(cur + 1, ctx, modifiers, end_func); 
        }
        else {
            return CPP2_UFCS(fail)(ctx); 
        }
    }

#line 1130 "regex.h2"
    template <typename CharT> auto any_matcher_logic<CharT>::reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void{}
#line 1131 "regex.h2"
    template <typename CharT> [[nodiscard]] auto any_matcher_logic<CharT>::to_string() -> auto { return bstring<CharT>(1, '.'); }

#line 1137 "regex.h2"
    template <typename CharT> template<typename Other> [[nodiscard]] auto branch_reset_matcher_logic<CharT>::match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto { return Other::match(cur, ctx, modifiers, end_func);  }
#line 1138 "regex.h2"
    template <typename CharT> auto branch_reset_matcher_logic<CharT>::reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void{}
#line 1139 "regex.h2"
    template <typename CharT> [[nodiscard]] auto branch_reset_matcher_logic<CharT>::to_string() -> auto { return bstring<CharT>("(?|"); }

#line 1146 "regex.h2"
    template <typename CharT, CharT C, CharT L, CharT U> template<typename Other> [[nodiscard]] auto char_matcher_logic<CharT,C,L,U>::match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto{
        if (CPP2_UFCS(has_flag)(modifiers, expression_flags::case_insensitive)) {
            if (cur != ctx.end && (*cpp2::assert_not_null(cur) == L || *cpp2::assert_not_null(cur) == U)) {
                return Other::match(cur + 1, ctx, modifiers, end_func); 
            }
            else {
                return CPP2_UFCS(fail)(ctx); 
            }
        }
        else {
            if (cur != ctx.end && *cpp2::assert_not_null(cur) == C) {
                return Other::match(cur + 1, ctx, modifiers, end_func); 
            }
            else {
                return CPP2_UFCS(fail)(ctx); 
            }
        }

    }
#line 1165 "regex.h2"
    template <typename CharT, CharT C, CharT L, CharT U> auto char_matcher_logic<CharT,C,L,U>::reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void{}
#line 1166 "regex.h2"
    template <typename CharT, CharT C, CharT L, CharT U> [[nodiscard]] auto char_matcher_logic<CharT,C,L,U>::to_string() -> auto { return bstring<CharT>(1, C); }

#line 1174 "regex.h2"
    template <typename CharT, bool negate, typename ...List> template<typename Other> [[nodiscard]] auto class_matcher_logic<CharT,negate,List...>::match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto{
        if (CPP2_UFCS(has_flag)(modifiers, expression_flags::case_insensitive)) {
            if (cur != ctx.end && negate != (match_any<List...>(safe_tolower(*cpp2::assert_not_null(cur))) || match_any<List...>(safe_toupper(*cpp2::assert_not_null(cur))))) {
                return Other::match(cur + 1, ctx, modifiers, end_func); 
            }
            else {
                return CPP2_UFCS(fail)(ctx); 
            }
        }
        else {
            if (cur != ctx.end && negate != match_any<List...>(*cpp2::assert_not_null(cur))) {
                return Other::match(cur + 1, ctx, modifiers, end_func); 
            }
            else {
                return CPP2_UFCS(fail)(ctx); 
            }
        }
    }

#line 1193 "regex.h2"
    template <typename CharT, bool negate, typename ...List> template<typename First, typename ...Other> [[nodiscard]] auto class_matcher_logic<CharT,negate,List...>::match_any(cpp2::in<CharT> c) -> bool{
        bool r {First::includes(c)}; 

        if (!(r)) {
            if constexpr (0 != sizeof...(Other)) {
                r = match_any<Other...>(c);
            }
        }

        return r; 
    }

#line 1205 "regex.h2"
    template <typename CharT, bool negate, typename ...List> auto class_matcher_logic<CharT,negate,List...>::reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void{}

#line 1207 "regex.h2"
    template <typename CharT, bool negate, typename ...List> [[nodiscard]] auto class_matcher_logic<CharT,negate,List...>::to_string() -> bstring<CharT>{
        bstring<CharT> r {"["}; 
        if (negate) {
            r += "^";
        }
        r += (bstring<CharT>() + ... + List::to_string());
        r += "]";

        return r; 
    }

#line 1222 "regex.h2"
    template <typename CharT> template<typename Other> [[nodiscard]] auto global_group_reset<CharT>::match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto{
        CPP2_UFCS(set_group_start)(ctx, 0, cur);
        return Other::match(cur, ctx, modifiers, end_func); 
    }

#line 1227 "regex.h2"
    template <typename CharT> auto global_group_reset<CharT>::reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void{}
#line 1228 "regex.h2"
    template <typename CharT> [[nodiscard]] auto global_group_reset<CharT>::to_string() -> auto { return bstring<CharT>("\\K"); }

#line 1234 "regex.h2"
    template <typename CharT, int group, typename ModifierChange, fixed_string name, bool name_brackets> template<typename Other, typename Modifiers> [[nodiscard]] auto group_matcher_start_logic<CharT,group,ModifierChange,name,name_brackets>::match(auto const& cur, auto& ctx, [[maybe_unused]] Modifiers const& unnamed_param_3, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto{
        if (-1 != group) {
            CPP2_UFCS(set_group_start)(ctx, group, cur);
        }
        return Other::match(cur, ctx, Modifiers::push(ModifierChange()), end_func); 
    }

#line 1241 "regex.h2"
    template <typename CharT, int group, typename ModifierChange, fixed_string name, bool name_brackets> auto group_matcher_start_logic<CharT,group,ModifierChange,name,name_brackets>::reset_ranges(auto& ctx) -> void{
        if (-1 != group) {
            CPP2_UFCS(set_group_invalid)(ctx, group);
        }
    }

#line 1247 "regex.h2"
    template <typename CharT, int group, typename ModifierChange, fixed_string name, bool name_brackets> [[nodiscard]] auto group_matcher_start_logic<CharT,group,ModifierChange,name,name_brackets>::to_string() -> bstring<CharT>{
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

#line 1271 "regex.h2"
    template <typename CharT, int group> template<typename Other, typename Modifier> [[nodiscard]] auto group_matcher_end_logic<CharT,group>::match(auto const& cur, auto& ctx, [[maybe_unused]] Modifier const& unnamed_param_3, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto{
        if (-1 != group) {
            CPP2_UFCS(set_group_end)(ctx, group, cur);
        }
        auto r {Other::match(cur, ctx, Modifier::pop(), end_func)}; 
        if (!(r.matched) && -1 != group) {
            CPP2_UFCS(set_group_invalid)(ctx, group);
        }
        return r; 
    }

#line 1282 "regex.h2"
    template <typename CharT, int group> auto group_matcher_end_logic<CharT,group>::reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void{}

#line 1284 "regex.h2"
    template <typename CharT, int group> [[nodiscard]] auto group_matcher_end_logic<CharT,group>::to_string() -> bstring<CharT>{
        if (group != 0) {
            return ")"; 
        }
        else {
            return ""; 
        }
    }

#line 1295 "regex.h2"
    template <typename CharT> template<typename Other> [[nodiscard]] auto special_group_end_logic<CharT>::match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto { return Other::match(cur, ctx, modifiers, end_func);  }
#line 1296 "regex.h2"
    template <typename CharT> auto special_group_end_logic<CharT>::reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void{}
#line 1297 "regex.h2"
    template <typename CharT> [[nodiscard]] auto special_group_end_logic<CharT>::to_string() -> auto { return bstring<CharT>(")"); }

#line 1303 "regex.h2"
    template <typename CharT, int group, fixed_string symbol> template<typename Other> [[nodiscard]] auto group_ref_matcher_logic<CharT,group,symbol>::match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto{
        auto g {CPP2_UFCS(get_group)(ctx, group)}; 

        auto pos {cur}; 
        auto group_pos {g.start}; 
        for( ; group_pos != g.end && pos != ctx.end; (++group_pos, ++pos) ) {
            if (CPP2_UFCS(has_flag)(modifiers, expression_flags::case_insensitive)) {
                if (safe_tolower(*cpp2::assert_not_null(group_pos)) != safe_tolower(*cpp2::assert_not_null(pos))) {
                    return CPP2_UFCS(fail)(ctx); 
                }
            }
            else {
                if (*cpp2::assert_not_null(group_pos) != *cpp2::assert_not_null(pos)) {
                    return CPP2_UFCS(fail)(ctx); 
                }
            }
        }

        if (std::move(group_pos) == std::move(g).end) {
            return Other::match(std::move(pos), ctx, modifiers, end_func); 
        }
        else {
            return CPP2_UFCS(fail)(ctx); 
        }

    }
#line 1329 "regex.h2"
    template <typename CharT, int group, fixed_string symbol> auto group_ref_matcher_logic<CharT,group,symbol>::reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void{}
#line 1330 "regex.h2"
    template <typename CharT, int group, fixed_string symbol> [[nodiscard]] auto group_ref_matcher_logic<CharT,group,symbol>::to_string() -> auto { return CPP2_UFCS(str)(symbol); }

#line 1337 "regex.h2"
    template <typename CharT, bool match_new_line, bool match_new_line_before_end> template<typename Other> [[nodiscard]] auto line_end_matcher_logic<CharT,match_new_line,match_new_line_before_end>::match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto{
        if (cur == ctx.end || (match_new_line && CPP2_UFCS(has_flag)(modifiers, expression_flags::multiple_lines) && *cpp2::assert_not_null(cur) == '\n')) {
            return Other::match(cur, ctx, modifiers, end_func); 
        }
        else {if (match_new_line_before_end && (*cpp2::assert_not_null(cur) == '\n' && (cur + 1) == ctx.end)) {// Special case for new line at end.
            return Other::match(cur, ctx, modifiers, end_func); 
        }
        else {
            return CPP2_UFCS(fail)(ctx); 
        }}
    }

#line 1349 "regex.h2"
    template <typename CharT, bool match_new_line, bool match_new_line_before_end> auto line_end_matcher_logic<CharT,match_new_line,match_new_line_before_end>::reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void{}
#line 1350 "regex.h2"
    template <typename CharT, bool match_new_line, bool match_new_line_before_end> [[nodiscard]] auto line_end_matcher_logic<CharT,match_new_line,match_new_line_before_end>::to_string() -> auto { return bstring<CharT>("\\$"); }

#line 1357 "regex.h2"
    template <typename CharT, bool match_new_line> template<typename Other> [[nodiscard]] auto line_start_matcher_logic<CharT,match_new_line>::match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto{
        if (cur == ctx.begin || (match_new_line && CPP2_UFCS(has_flag)(modifiers, expression_flags::multiple_lines) && *cpp2::assert_not_null((cur - 1)) == '\n')) {
            return Other::match(cur, ctx, modifiers, end_func); 
        }
        else {
            return CPP2_UFCS(fail)(ctx); 
        }

    }
#line 1366 "regex.h2"
    template <typename CharT, bool match_new_line> auto line_start_matcher_logic<CharT,match_new_line>::reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void{}
#line 1367 "regex.h2"
    template <typename CharT, bool match_new_line> [[nodiscard]] auto line_start_matcher_logic<CharT,match_new_line>::to_string() -> auto { return bstring<CharT>(1, '^'); }

#line 1374 "regex.h2"
    template <typename CharT, bool positive, fixed_string name, typename Pattern> template<typename Other> [[nodiscard]] auto lookahead_matcher_logic<CharT,positive,name,Pattern>::match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto{
        auto r {Pattern::match(cur, ctx, modifiers, true_end_func(), no_tail<CharT>())}; 

        if (!(positive)) {
            r.matched = !(r.matched);
        }

        if (std::move(r).matched) {
            return Other::match(cur, ctx, modifiers, end_func); 
        }
        else {
            return CPP2_UFCS(fail)(ctx); 
        }

    }
#line 1389 "regex.h2"
    template <typename CharT, bool positive, fixed_string name, typename Pattern> auto lookahead_matcher_logic<CharT,positive,name,Pattern>::reset_ranges(auto& ctx) -> void{Pattern::reset_ranges(ctx); }
#line 1390 "regex.h2"
    template <typename CharT, bool positive, fixed_string name, typename Pattern> [[nodiscard]] auto lookahead_matcher_logic<CharT,positive,name,Pattern>::to_string() -> auto { return "(" + cpp2::to_string(CPP2_UFCS(data)(name)) + cpp2::to_string(Pattern::to_string()) + ")"; }

#line 1397 "regex.h2"
    template <typename CharT, typename ModifierChange> template<typename Other, typename Modifier> [[nodiscard]] auto modifier_matcher_logic<CharT,ModifierChange>::match(auto const& cur, auto& ctx, [[maybe_unused]] Modifier const& unnamed_param_3, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto{
        return Other::match(cur, ctx, Modifier::replace(ModifierChange()), end_func); 
    }
#line 1400 "regex.h2"
    template <typename CharT, typename ModifierChange> auto modifier_matcher_logic<CharT,ModifierChange>::reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void{}
#line 1401 "regex.h2"
    template <typename CharT, typename ModifierChange> [[nodiscard]] auto modifier_matcher_logic<CharT,ModifierChange>::to_string() -> auto { return "(?" + cpp2::to_string(ModifierChange::to_string()) + ")"; }

#line 1454 "regex.h2"
    template <typename CharT, bool negate> template<typename Other> [[nodiscard]] auto word_boundary_matcher_logic<CharT,negate>::match(auto const& cur, auto& ctx, auto const& modifiers, auto const& end_func, [[maybe_unused]] Other const& unnamed_param_5) -> auto{
        word_class<CharT> words {}; 
        auto is_match {false}; 
        if (cur == ctx.begin) {// String start
            if (cur != ctx.end) {// No empty string
                is_match = CPP2_UFCS(includes)(std::move(words), *cpp2::assert_not_null(cur));
            }
        }
        else {if (cur == ctx.end) {// String end
            is_match = CPP2_UFCS(includes)(std::move(words), *cpp2::assert_not_null((cur - 1)));
        }
        else { // Middle of string
            is_match = 
                   (CPP2_UFCS(includes)(words, *cpp2::assert_not_null((cur - 1))) && !(CPP2_UFCS(includes)(words, *cpp2::assert_not_null(cur)))) // End of word: \w\W
                || (!(CPP2_UFCS(includes)(words, *cpp2::assert_not_null((cur - 1)))) && CPP2_UFCS(includes)(words, *cpp2::assert_not_null(cur)));// Start of word: \W\w

        }}
        if (negate) {
            is_match = !(is_match);
        }

        if (std::move(is_match)) {
            return Other::match(cur, ctx, modifiers, end_func); 
        }
        else {
            return CPP2_UFCS(fail)(ctx); 
        }

    }
#line 1483 "regex.h2"
    template <typename CharT, bool negate> auto word_boundary_matcher_logic<CharT,negate>::reset_ranges([[maybe_unused]] auto const& unnamed_param_1) -> void{}
#line 1484 "regex.h2"
    template <typename CharT, bool negate> [[nodiscard]] auto word_boundary_matcher_logic<CharT,negate>::to_string() -> bstring<CharT>{
        if (negate) {
            return "\\B"; 
        }else {
            return "\\b"; 
        }
    }

#line 1505 "regex.h2"
    template <fixed_string name, int group_id, typename Inner> [[nodiscard]] auto group_name_list<name,group_id,Inner>::get_group_id(auto const& g) -> int{
        if (g == CPP2_UFCS(str)(name)) {
            return group_id; 
        }
        else {
            return Inner::get_group_id(g); 
        }
    }

#line 1516 "regex.h2"
    [[nodiscard]] auto group_name_list_end::get_group_id([[maybe_unused]] auto const& unnamed_param_1) -> auto { return -1;  }

#line 1530 "regex.h2"
        template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> template <typename Iter> regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search_return<Iter>::search_return(cpp2::in<bool> matched_, context<Iter> const& ctx_)
            : matched{ matched_ }
            , ctx{ ctx_ }{

#line 1533 "regex.h2"
        }

#line 1535 "regex.h2"
        template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search_return<Iter>::group_number() const& -> auto { return CPP2_UFCS(size)(ctx);  }
#line 1536 "regex.h2"
        template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search_return<Iter>::group(cpp2::in<int> g) const& -> auto { return CPP2_UFCS(get_group_string)(ctx, g); }
#line 1537 "regex.h2"
        template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search_return<Iter>::group_start(cpp2::in<int> g) const& -> auto { return CPP2_UFCS(get_group_start)(ctx, g); }
#line 1538 "regex.h2"
        template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search_return<Iter>::group_end(cpp2::in<int> g) const& -> auto { return CPP2_UFCS(get_group_end)(ctx, g); }

#line 1540 "regex.h2"
        template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search_return<Iter>::group(cpp2::in<bstring<CharT>> g) const& -> auto { return group(get_group_id(g)); }
#line 1541 "regex.h2"
        template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search_return<Iter>::group_start(cpp2::in<bstring<CharT>> g) const& -> auto { return group_start(get_group_id(g)); }
#line 1542 "regex.h2"
        template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search_return<Iter>::group_end(cpp2::in<bstring<CharT>> g) const& -> auto { return group_end(get_group_id(g)); }

#line 1544 "regex.h2"
        template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search_return<Iter>::get_group_id(cpp2::in<bstring<CharT>> g) const& -> auto{
            auto group_id {named_groups::get_group_id(g)}; 
            if (-1 == group_id) {
                // TODO: Throw error.
            }
            return group_id; 
        }

#line 1553 "regex.h2"
    template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::match(cpp2::in<bview<CharT>> str) const& -> auto { return match(CPP2_UFCS(begin)(str), CPP2_UFCS(end)(str)); }
#line 1554 "regex.h2"
    template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::match(cpp2::in<bview<CharT>> str, auto const& start) const& -> auto { return match(get_iter(str, start), CPP2_UFCS(end)(str)); }
#line 1555 "regex.h2"
    template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::match(cpp2::in<bview<CharT>> str, auto const& start, auto const& length) const& -> auto { return match(get_iter(str, start), get_iter(str, start + length)); }
#line 1556 "regex.h2"
    template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> template<typename Iter> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::match(Iter const& start, Iter const& end) const& -> search_return<Iter>{
        context ctx {start, end}; 

        auto r {Matcher::match(start, ctx, modifiers(), true_end_func())}; 
        return search_return(r.matched && r.pos == end, std::move(ctx)); 
    }

#line 1563 "regex.h2"
    template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search(cpp2::in<bview<CharT>> str) const& -> auto { return search(CPP2_UFCS(begin)(str), CPP2_UFCS(end)(str)); }
#line 1564 "regex.h2"
    template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search(cpp2::in<bview<CharT>> str, auto const& start) const& -> auto { return search(get_iter(str, start), CPP2_UFCS(end)(str)); }
#line 1565 "regex.h2"
    template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search(cpp2::in<bview<CharT>> str, auto const& start, auto const& length) const& -> auto { return search(get_iter(str, start), get_iter(str, start + length)); }
#line 1566 "regex.h2"
    template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> template<typename Iter> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::search(Iter const& start, Iter const& end) const& -> search_return<Iter>{
        auto matched {false}; 
        context ctx {start, end}; 

        auto cur {start}; 
        for( ; true; (++cur) ) {
            if (Matcher::match(cur, ctx, modifiers(), true_end_func()).matched) {
                matched = true;
                break;
            }

            if (cur == ctx.end) {
                break;
            }
        }

        return search_return(std::move(matched), std::move(ctx)); 
    }

#line 1585 "regex.h2"
    template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::to_string() const& -> auto { return Matcher::to_string();  }

#line 1590 "regex.h2"
    template <typename CharT, int flags, size_t groups, size_t alternatives, typename named_groups, typename Matcher> [[nodiscard]] auto regular_expression<CharT,flags,groups,alternatives,named_groups,Matcher>::get_iter(cpp2::in<bview<CharT>> str, auto const& pos) -> auto{
        if (cpp2::cmp_less(pos,CPP2_UFCS(size)(str))) {
            return CPP2_UFCS(begin)(str) + pos; 
        }
        else {
            return CPP2_UFCS(end)(str); 
        }
    }

#line 1611 "regex.h2"
        template <typename CharT, typename Matcher> template <typename Iter> regular_expression_with_matcher<CharT,Matcher>::search_return<Iter>::search_return(cpp2::in<bool> matched_, context<Iter> const& ctx_)
            : matched{ matched_ }
            , ctx{ ctx_ }{

#line 1614 "regex.h2"
        }

#line 1616 "regex.h2"
        template <typename CharT, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression_with_matcher<CharT,Matcher>::search_return<Iter>::group_number() const& -> auto { return CPP2_UFCS(size)(ctx);  }
#line 1617 "regex.h2"
        template <typename CharT, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression_with_matcher<CharT,Matcher>::search_return<Iter>::group(cpp2::in<int> g) const& -> auto { return CPP2_UFCS(get_group_string)(ctx, g); }
#line 1618 "regex.h2"
        template <typename CharT, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression_with_matcher<CharT,Matcher>::search_return<Iter>::group_start(cpp2::in<int> g) const& -> auto { return CPP2_UFCS(get_group_start)(ctx, g); }
#line 1619 "regex.h2"
        template <typename CharT, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression_with_matcher<CharT,Matcher>::search_return<Iter>::group_end(cpp2::in<int> g) const& -> auto { return CPP2_UFCS(get_group_end)(ctx, g); }

#line 1621 "regex.h2"
        template <typename CharT, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression_with_matcher<CharT,Matcher>::search_return<Iter>::group(cpp2::in<bstring<CharT>> g) const& -> auto { return group(get_group_id(g)); }
#line 1622 "regex.h2"
        template <typename CharT, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression_with_matcher<CharT,Matcher>::search_return<Iter>::group_start(cpp2::in<bstring<CharT>> g) const& -> auto { return group_start(get_group_id(g)); }
#line 1623 "regex.h2"
        template <typename CharT, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression_with_matcher<CharT,Matcher>::search_return<Iter>::group_end(cpp2::in<bstring<CharT>> g) const& -> auto { return group_end(get_group_id(g)); }

#line 1625 "regex.h2"
        template <typename CharT, typename Matcher> template <typename Iter> [[nodiscard]] auto regular_expression_with_matcher<CharT,Matcher>::search_return<Iter>::get_group_id(cpp2::in<bstring<CharT>> g) const& -> auto{
            auto group_id {Matcher::get_named_group_index(g)}; 
            if (-1 == group_id) {
                // TODO: Throw error.
            }
            return group_id; 
        }

#line 1634 "regex.h2"
    template <typename CharT, typename Matcher> [[nodiscard]] auto regular_expression_with_matcher<CharT,Matcher>::match(cpp2::in<bview<CharT>> str) const& -> auto { return match(CPP2_UFCS(begin)(str), CPP2_UFCS(end)(str)); }
#line 1635 "regex.h2"
    template <typename CharT, typename Matcher> [[nodiscard]] auto regular_expression_with_matcher<CharT,Matcher>::match(cpp2::in<bview<CharT>> str, auto const& start) const& -> auto { return match(get_iter(str, start), CPP2_UFCS(end)(str)); }
#line 1636 "regex.h2"
    template <typename CharT, typename Matcher> [[nodiscard]] auto regular_expression_with_matcher<CharT,Matcher>::match(cpp2::in<bview<CharT>> str, auto const& start, auto const& length) const& -> auto { return match(get_iter(str, start), get_iter(str, start + length)); }
#line 1637 "regex.h2"
    template <typename CharT, typename Matcher> template<typename Iter> [[nodiscard]] auto regular_expression_with_matcher<CharT,Matcher>::match(Iter const& start, Iter const& end) const& -> search_return<Iter>{
        context ctx {start, end}; 

        auto r {Matcher::entry(start, ctx, modifiers())}; 
        return search_return(r.matched && r.pos == end, std::move(ctx)); 
    }

#line 1644 "regex.h2"
    template <typename CharT, typename Matcher> [[nodiscard]] auto regular_expression_with_matcher<CharT,Matcher>::search(cpp2::in<bview<CharT>> str) const& -> auto { return search(CPP2_UFCS(begin)(str), CPP2_UFCS(end)(str)); }
#line 1645 "regex.h2"
    template <typename CharT, typename Matcher> [[nodiscard]] auto regular_expression_with_matcher<CharT,Matcher>::search(cpp2::in<bview<CharT>> str, auto const& start) const& -> auto { return search(get_iter(str, start), CPP2_UFCS(end)(str)); }
#line 1646 "regex.h2"
    template <typename CharT, typename Matcher> [[nodiscard]] auto regular_expression_with_matcher<CharT,Matcher>::search(cpp2::in<bview<CharT>> str, auto const& start, auto const& length) const& -> auto { return search(get_iter(str, start), get_iter(str, start + length)); }
#line 1647 "regex.h2"
    template <typename CharT, typename Matcher> template<typename Iter> [[nodiscard]] auto regular_expression_with_matcher<CharT,Matcher>::search(Iter const& start, Iter const& end) const& -> search_return<Iter>{
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

        return search_return(std::move(matched), std::move(ctx)); 
    }

#line 1666 "regex.h2"
    template <typename CharT, typename Matcher> [[nodiscard]] auto regular_expression_with_matcher<CharT,Matcher>::to_string() const& -> auto { return Matcher::to_string();  }

#line 1671 "regex.h2"
    template <typename CharT, typename Matcher> [[nodiscard]] auto regular_expression_with_matcher<CharT,Matcher>::get_iter(cpp2::in<bview<CharT>> str, auto const& pos) -> auto{
        if (cpp2::cmp_less(pos,CPP2_UFCS(size)(str))) {
            return CPP2_UFCS(begin)(str) + pos; 
        }
        else {
            return CPP2_UFCS(end)(str); 
        }
    }

#line 1707 "regex.h2"
    auto regex_parser_group_state::next_alternative() & -> void{
        std::vector<std::string> new_list {}; 
        std::swap(new_list, cur_match_list);
        static_cast<void>(CPP2_UFCS(insert)(alternate_match_lists, CPP2_UFCS(end)(alternate_match_lists), std::move(new_list)));
    }

#line 1713 "regex.h2"
    auto regex_parser_group_state::swap(regex_parser_group_state& t) & -> void{
        std::swap(cur_match_list, t.cur_match_list);
        std::swap(alternate_match_lists, t.alternate_match_lists);
        std::swap(modifiers, t.modifiers);
    }

#line 1719 "regex.h2"
    auto regex_parser_group_state::add(auto const& matcher) & -> void { CPP2_UFCS(push_back)(cur_match_list, matcher);  }

#line 1721 "regex.h2"
    auto regex_parser_group_state::wrap_last(auto const& matcher) & -> void{
        auto last {CPP2_UFCS(back)(cur_match_list)}; 
        CPP2_UFCS(back)(cur_match_list) = matcher(last);
        static_cast<void>(matcher);
        static_cast<void>(std::move(last));
    }

#line 1728 "regex.h2"
    [[nodiscard]] auto regex_parser_group_state::empty() const& -> bool { return CPP2_UFCS(empty)(cur_match_list);  }

#line 1738 "regex.h2"
    [[nodiscard]] auto regex_branch_reset_state::next() & -> int{
        auto g {cur_group}; 
        cur_group += 1;
        max_group = max(max_group, cur_group);

        return g; 
    }

#line 1746 "regex.h2"
    auto regex_branch_reset_state::set_next(cpp2::in<int> g) & -> void{
        cur_group = g;
        max_group = max(max_group, g);
    }

#line 1751 "regex.h2"
    auto regex_branch_reset_state::next_alternative() & -> void{
        if (is_active) {
            cur_group = from;
        }
    }

#line 1777 "regex.h2"
    template <typename Error_out> regex_parser<Error_out>::regex_parser(cpp2::in<std::string_view> r, cpp2::in<std::string_view> m, Error_out const& e)
        : regex{ r }
        , modifier{ m }
        , error_out{ e }{

#line 1781 "regex.h2"
    }

#line 1785 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::group_new_state() & -> regex_parser_group_state{
        regex_parser_group_state old_state {}; 
        CPP2_UFCS(swap)(old_state, cur_group_state);

        return old_state; 
    }

#line 1792 "regex.h2"
    template <typename Error_out> auto regex_parser<Error_out>::group_restore_state(cpp2::in<regex_parser_group_state> old_state) & -> void{
        cur_group_state = old_state;
    }

#line 1799 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::branch_reset_new_state() & -> regex_branch_reset_state{
        regex_branch_reset_state old_state {}; 
        std::swap(old_state, cur_branch_reset_state);

        cur_branch_reset_state.is_active = true;
        cur_branch_reset_state.cur_group = old_state.cur_group;
        cur_branch_reset_state.from      = cur_branch_reset_state.cur_group;
        cur_branch_reset_state.max_group = cur_branch_reset_state.cur_group;

        return old_state; 
    }

#line 1811 "regex.h2"
    template <typename Error_out> auto regex_parser<Error_out>::branch_reset_restore_state(cpp2::in<regex_branch_reset_state> old_state) & -> void{
        auto next_group {cur_branch_reset_state.max_group}; 
        cur_branch_reset_state = old_state;
        CPP2_UFCS(set_next)(cur_branch_reset_state, std::move(next_group));
    }

#line 1820 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::get_next_position(cpp2::in<bool> in_class, cpp2::in<bool> no_skip) const& -> size_t{
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
        if (std::move(perl_syntax)) {
            for( ; cpp2::cmp_less(cur,CPP2_UFCS(size)(regex)); (cur += 1) ) {
                auto n {CPP2_ASSERT_IN_BOUNDS(regex, cur)}; 

                if (space_class<char>::includes(n)) {
                    continue;
                }
                else {if (!(in_class) && '#' == std::move(n)) {
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

#line 1858 "regex.h2"
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

#line 1870 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::next(cpp2::out<char> n) & -> auto { return next_impl(cpp2::out(&n), false, false); }
#line 1871 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::next_in_class(cpp2::out<char> n) & -> auto { return next_impl(cpp2::out(&n), true, false);  }
#line 1872 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::next_no_skip(cpp2::out<char> n) & -> auto { return next_impl(cpp2::out(&n), false, true); }

#line 1876 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::skip() & -> bool{
        cpp2::deferred_init<char> c; 
        auto r {next(cpp2::out(&c))}; 
        static_cast<void>(std::move(c.value()));
        return r; 
    }

#line 1883 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::skip_n(cpp2::in<int> n) & -> bool{
        auto r {true}; 
        auto cur {0}; 
        for( ; r && cpp2::cmp_less(cur,n); (r = skip()) ) {
            cur += 1;
        }
        return r; 
    }

#line 1892 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::current() const& -> char{
        if (cpp2::cmp_less(pos,CPP2_UFCS(size)(regex))) {
            return CPP2_ASSERT_IN_BOUNDS(regex, pos); 
        }else {
            return '\0'; 
        }
    }

#line 1900 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::peek_impl(cpp2::in<bool> in_class) const& -> char{
        auto next_pos {get_next_position(in_class, false)}; 
        if (cpp2::cmp_less(next_pos,CPP2_UFCS(size)(regex))) {
            return CPP2_ASSERT_IN_BOUNDS(regex, std::move(next_pos)); 
        }
        else {
            return '\0'; 
        }
    }

#line 1910 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::peek() const& -> auto { return peek_impl(false); }
#line 1911 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::peek_in_class() const& -> auto { return peek_impl(true);  }

#line 1913 "regex.h2"
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

#line 1934 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::grab_until(cpp2::in<std::string> e, cpp2::out<std::string> r) & -> auto { return grab_until_impl(e, cpp2::out(&r), false); }
#line 1935 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::grab_until(cpp2::in<char> e, cpp2::out<std::string> r) & -> auto { return grab_until_impl(std::string(1, e), cpp2::out(&r), false); }
#line 1936 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::grab_until_one_of(cpp2::in<std::string> e, cpp2::out<std::string> r) & -> auto { return grab_until_impl(e, cpp2::out(&r), true);  }

#line 1938 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::grab_n(cpp2::in<int> n, cpp2::out<std::string> r) & -> bool{
        if (cpp2::cmp_less_eq(pos + n,CPP2_UFCS(size)(regex))) {
            r.construct(CPP2_UFCS(substr)(regex, pos, n));
            pos += n - 1;
            return true; 
        }
        else {
            r.construct("");
            return false; 
        }
    }

#line 1950 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::grab_number() & -> std::string{
        auto start {pos}; 
        auto start_search {pos}; 
        if (CPP2_ASSERT_IN_BOUNDS(regex, start_search) == '-') {
            start_search += 1;
        }
        auto end {CPP2_UFCS(find_first_not_of)(regex, "1234567890", std::move(start_search))}; 

        cpp2::deferred_init<std::string> r; 
        if (end != std::string::npos) {
            r.construct(CPP2_UFCS(substr)(regex, start, end - start));
            pos = std::move(end) - 1;
        }
        else {
            r.construct(CPP2_UFCS(substr)(regex, std::move(start)));
            pos = CPP2_UFCS(size)(regex) - 1;
        }
        return std::move(r.value()); 
    }

#line 1972 "regex.h2"
    template <typename Error_out> auto regex_parser<Error_out>::error(cpp2::in<std::string> message) & -> void{
        error_out(("Error during parsing of regex '" + cpp2::to_string(regex) + "' at position '" + cpp2::to_string(pos) + "': " + cpp2::to_string(message)));
        has_error = true;
    }

#line 1977 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::join(auto const& list, auto const& func) -> std::string{
        std::string r {""}; 

        std::string separator {""}; 
        for ( auto const& cur : list ) {
            r += separator + func(cur);
            separator = ", ";
        }

        return r; 
    }

#line 1989 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::join(cpp2::in<std::vector<std::string>> list) -> auto { return join(list, [](auto const& arg) -> auto { return arg;  });  }// Todo: Shorthand syntax for const lambda

#line 1995 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::create_matcher(cpp2::in<std::string> name, cpp2::in<std::string> template_arguments) const& -> auto{
        auto sep {", "}; 
        if (CPP2_UFCS(empty)(template_arguments)) {sep = ""; }

        return "::cpp2::regex::" + cpp2::to_string(name) + "<char" + cpp2::to_string(std::move(sep)) + cpp2::to_string(template_arguments) + ">"; 
    }

#line 2002 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::create_matcher_from_list(auto const& list) & -> auto { return create_matcher("matcher_list", join(list));  }

#line 2004 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::create_matcher_from_state() & -> std::string{
        if (0 == CPP2_UFCS(size)(cur_group_state.alternate_match_lists)) {return create_matcher_from_list(cur_group_state.cur_match_list); }

        if (0 == CPP2_UFCS(size)(cur_group_state.cur_match_list)) {
            CPP2_UFCS(add)(cur_group_state, create_matcher("empty_matcher_logic", ""));
        }
        CPP2_UFCS(next_alternative)(cur_group_state);
        CPP2_UFCS(next_alternative)(cur_branch_reset_state);

        auto list {join(cur_group_state.alternate_match_lists, [&](auto const& arg) -> auto { return create_matcher_from_list(arg);  })}; 
        auto alternative_id {alternatives_count}; 
        alternatives_count += 1;

        return create_matcher("alternative_matcher_logic", (cpp2::to_string(std::move(alternative_id)) + ", " + cpp2::to_string(std::move(list)))); 
    }

#line 2020 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::create_named_groups_list() const& -> std::string{
        std::string r {"::cpp2::regex::group_name_list_end"}; 

        for ( auto const& cur : named_groups ) {
            r = { "::cpp2::regex::group_name_list<\"" + cpp2::to_string(cur.first) + "\", " + cpp2::to_string(cur.second) + ", " + cpp2::to_string(r) + ">" };
        }

        return r; 
    }

#line 2032 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::parse_lookahead(cpp2::in<std::string> name, cpp2::in<bool> positive) & -> bool{
        auto old_state {group_new_state()}; 
        parse_until(')');
        auto inner {create_matcher_from_state()}; 
        group_restore_state(std::move(old_state));

        CPP2_UFCS(add)(cur_group_state, create_matcher("lookahead_matcher_logic", (cpp2::to_string(positive) + ", \"" + cpp2::to_string(name) + "\", " + cpp2::to_string(std::move(inner)))));

        return true; 
    }

#line 2043 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::parser_expression_modifiers() & -> std::string{
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
                cur_group_state.modifiers.group_captures_have_numbers = false;
            }
            else {if (c == 'x') {
                add("::cpp2::regex::expression_flags::perl_code_syntax", r);
                cur_group_state.modifiers.perl_code_syntax = true;

                // Check if we have 'xx'
                mod_pos += 1;
                if (cpp2::cmp_less(mod_pos,CPP2_UFCS(ssize)(modifier)) && 'x' == CPP2_ASSERT_IN_BOUNDS(modifier, mod_pos)) {
                    add("::cpp2::regex::expression_flags::perl_code_syntax_in_classes", r);
                    cur_group_state.modifiers.perl_code_syntax_in_classes = true;
                }
            }
            else {error(("Unknown modifier: '" + cpp2::to_string(std::move(c)) + "'")); }}}}}
        }

        return r; 
    }

#line 2079 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::parser_group_modifiers(cpp2::in<std::string> change_str, cpp2::out<std::string> modifier_change, 
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
                error(("Unknown modifier: " + cpp2::to_string(std::move(cur)))); return false; 
            }}}}}}}
        }

        modifier_change.construct("::cpp2::regex::match_modifiers_state_change<true, " + cpp2::to_string(std::move(is_reset)) + ", " + cpp2::to_string(std::move(add)) + ", " + cpp2::to_string(std::move(remove)) + ", \"" + cpp2::to_string(change_str) + "\">");

        return true; 
    }

#line 2147 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_alternative(cpp2::in<char> c) & -> bool{
        if (c != '|') {return false; }

        CPP2_UFCS(next_alternative)(cur_group_state);
        CPP2_UFCS(next_alternative)(cur_branch_reset_state);
        return true; 
    }

#line 2155 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_anchor(cpp2::in<char> c) & -> bool{
        if (c == '^') {
            CPP2_UFCS(add)(cur_group_state, create_matcher("line_start_matcher_logic", "true"));
            return true; 
        }
        else {if (c == '$') {
            CPP2_UFCS(add)(cur_group_state, create_matcher("line_end_matcher_logic", "true, true"));
            return true; 
        }}

        return false; 
    }

#line 2168 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_any(cpp2::in<char> c) & -> bool{
        if (c != '.') {return false; }

        CPP2_UFCS(add)(cur_group_state, create_matcher("any_matcher_logic", ""));
        return true; 

    }

#line 2176 "regex.h2"
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
                static_cast<void>(skip_n(2));// Skip [:

                std::string name {""}; 
                if (!(grab_until(":]", cpp2::out(&name)))) {error("Could not find end of character class."); return false; }
                if (CPP2_UFCS(end)(supported_classes) == std::find(CPP2_UFCS(begin)(supported_classes), CPP2_UFCS(end)(supported_classes), name)) {
                    error(("Unsupported character class. Supported ones are: " + cpp2::to_string(join(supported_classes))));
                    return false; 
                }

                CPP2_UFCS(push_back)(classes, ("[:" + cpp2::to_string(std::move(name)) + ":]"));

                static_cast<void>(skip());// Skip ':' pointing to the ending ']'.
            }
            else {if (c_cur == '\\') {
                if (next_no_skip(cpp2::out(&c_cur)) && (c_cur != ']')) {
                    if ( ' ' == c_cur && cur_group_state.modifiers.perl_code_syntax && cur_group_state.modifiers.perl_code_syntax_in_classes) {
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
                        CPP2_UFCS(push_back)(classes, ("[:" + cpp2::to_string(std::move(name)) + ":]"));
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
                cur = create_matcher((cpp2::to_string(std::move(name)) + "_class"), "");
            }
            else {if (1 != CPP2_UFCS(size)(cur)) {
                cur = create_matcher("range_class_entry", ("'" + cpp2::to_string(CPP2_ASSERT_IN_BOUNDS_LITERAL(cur, 0)) + "', '" + cpp2::to_string(CPP2_ASSERT_IN_BOUNDS_LITERAL(cur, 2)) + "'"));
            }
            else {
                cur = create_matcher("single_class_entry", ("'" + cpp2::to_string(cur) + "'"));
            }}
        }

        auto inner {join(std::move(classes))}; 
        CPP2_UFCS(add)(cur_group_state, create_matcher("class_matcher_logic", (cpp2::to_string(std::move(negate)) + ", " + cpp2::to_string(std::move(inner)))));
        return true; 
    }

#line 2283 "regex.h2"
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
            CPP2_UFCS(add)(cur_group_state, create_matcher("group_ref_matcher_logic", (cpp2::to_string(std::move(group_id)) + ", \"\\" + cpp2::to_string(CPP2_UFCS(substr)(regex, _1, *cpp2::assert_not_null(_2) - _1 + 1)) + "\"")));

            return true; 
        }}; 

        if ([_0 = '0', _1 = c_next, _2 = '9']{ return cpp2::cmp_less_eq(_0,_1) && cpp2::cmp_less_eq(_1,_2); }()) {
            auto group {grab_number()}; 
            if (cpp2::cmp_greater_eq(CPP2_UFCS(ssize)(group),3)) {
                // \000 syntax
                auto number {0}; 
                if (!(string_to_int(std::move(group), number, 8))) {error("Could not convert octal to int."); return false; }

                char number_as_char {unsafe_narrow<char>(std::move(number))}; 

                std::string syntax {"\\" + cpp2::to_string(int_to_string(cpp2::as_<int>(number_as_char), 8))}; 
                auto char_matcher {create_matcher("char_matcher_logic", ("'" + cpp2::to_string(number_as_char) + "', '" + cpp2::to_string(safe_tolower(number_as_char)) + "', '" + cpp2::to_string(safe_toupper(number_as_char)) + "'"))}; 
                CPP2_UFCS(add)(cur_group_state, create_matcher("special_syntax_wrapper", ("\"" + cpp2::to_string(std::move(syntax)) + "\", " + cpp2::to_string(std::move(char_matcher)))));
            }
            else {
                if (!(std::move(add_group_matcher)(std::move(group)))) {return false; }
            }
        }
        else {if (std::string::npos != CPP2_UFCS(find)(std::string("tnrfae^.[]$()*{}?+|"), c_next)) {
            if (c_next == '$') {
                // TODO: Provide proper escape for cppfront capture
                CPP2_UFCS(add)(cur_group_state, create_matcher("line_end_matcher_logic", "true, true"));
            }
            else {
                auto inner {create_matcher("char_matcher_logic", ("'\\" + cpp2::to_string(c_next) + "', '\\" + cpp2::to_string(c_next) + "', '\\" + cpp2::to_string(c_next) + "'"))}; 
                CPP2_UFCS(add)(cur_group_state, create_matcher("special_syntax_wrapper", ("\"\\\\" + cpp2::to_string(std::move(c_next)) + "\", " + cpp2::to_string(std::move(inner)))));
            }
        }
        else {if ('\\' == c_next) {
            auto inner {create_matcher("char_matcher_logic", "'\\\\', '\\\\', '\\\\'")}; 
            CPP2_UFCS(add)(cur_group_state, create_matcher("special_syntax_wrapper", ("\"\\\\\\\\\", " + cpp2::to_string(std::move(inner)))));
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
            if (!(std::move(add_group_matcher)(std::move(group)))) {return false; }
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
            CPP2_UFCS(add)(cur_group_state, create_matcher("global_group_reset", ""));
        }
        else {if ('x' == c_next) {
            if (!(next(cpp2::out(&c_next)))) {error("x escape without number."); return false; }
            auto has_brackets {false}; 
            std::string number_str {""}; 
            if ('{' == std::move(c_next)) {
                // TODO: Currently does not work since the compiler handles \x also.
                // Bracketed
                has_brackets = true;
                static_cast<void>(skip());// Skip '{'
                if (!(grab_until('}', cpp2::out(&number_str)))) {error("No ending bracket for \\x"); return false; }
            }
            else {
                // grab two chars

                if (!(grab_n(2, cpp2::out(&number_str)))) {error("Missing hexadecimal digits after \\x."); return false; }
            }

            auto number {0}; 
            if (!(string_to_int(std::move(number_str), number, 16))) {error("Could not convert hexadecimal to int."); return false; }

            char number_as_char {unsafe_narrow<char>(std::move(number))}; 

            std::string syntax {int_to_string(cpp2::as_<int>(number_as_char), 16)}; 
            if (std::move(has_brackets)) {
                syntax = { "{" + cpp2::to_string(syntax) + "}" };
            }
            syntax = { "\\x" + cpp2::to_string(syntax) };
            auto char_matcher {create_matcher("char_matcher_logic", ("'" + cpp2::to_string(number_as_char) + "', '" + cpp2::to_string(safe_tolower(number_as_char)) + "', '" + cpp2::to_string(safe_toupper(number_as_char)) + "'"))}; 
            CPP2_UFCS(add)(cur_group_state, create_matcher("special_syntax_wrapper", ("\"" + cpp2::to_string(std::move(syntax)) + "\", " + cpp2::to_string(std::move(char_matcher)))));
        }
        else {if ('o' == c_next) {
            if (!(next(cpp2::out(&c_next)))) {error("o escape without bracket."); return false; }
            std::string number_str {""}; 
            if ('{' == std::move(c_next)) {
                static_cast<void>(skip());// Skip '{'
                if (!(grab_until('}', cpp2::out(&number_str)))) {error("No ending bracket for \\o"); return false; }
            }

            auto number {0}; 
            if (!(string_to_int(std::move(number_str), number, 8))) {error("Could not convert octal to int."); return false; }

            char number_as_char {unsafe_narrow<char>(std::move(number))}; 

            std::string syntax {"\\o{" + cpp2::to_string(int_to_string(cpp2::as_<int>(number_as_char), 8)) + "}"}; 
            auto char_matcher {create_matcher("char_matcher_logic", ("'" + cpp2::to_string(number_as_char) + "', '" + cpp2::to_string(safe_tolower(number_as_char)) + "', '" + cpp2::to_string(safe_toupper(number_as_char)) + "'"))}; 
            CPP2_UFCS(add)(cur_group_state, create_matcher("special_syntax_wrapper", ("\"" + cpp2::to_string(std::move(syntax)) + "\", " + cpp2::to_string(std::move(char_matcher)))));
        }
        else {if ('A' == c_next) {CPP2_UFCS(add)(cur_group_state, create_matcher("named_string_start", "")); }
        else {if ('b' == c_next) {CPP2_UFCS(add)(cur_group_state, create_matcher("word_boundary_matcher_logic", "false")); }
        else {if ('B' == c_next) {CPP2_UFCS(add)(cur_group_state, create_matcher("word_boundary_matcher_logic", "true")); }
        else {if ('d' == c_next) {CPP2_UFCS(add)(cur_group_state, create_matcher("named_class_digits", "")); }
        else {if ('D' == c_next) {CPP2_UFCS(add)(cur_group_state, create_matcher("named_class_not_digits", "")); }
        else {if ('h' == c_next) {CPP2_UFCS(add)(cur_group_state, create_matcher("named_class_hor_space", "")); }
        else {if ('H' == c_next) {CPP2_UFCS(add)(cur_group_state, create_matcher("named_class_not_hor_space", "")); }
        else {if ('N' == c_next) {CPP2_UFCS(add)(cur_group_state, create_matcher("named_class_no_new_line", "")); }
        else {if ('s' == c_next) {CPP2_UFCS(add)(cur_group_state, create_matcher("named_class_space", "")); }
        else {if ('S' == c_next) {CPP2_UFCS(add)(cur_group_state, create_matcher("named_class_not_space", "")); }
        else {if ('v' == c_next) {CPP2_UFCS(add)(cur_group_state, create_matcher("named_class_ver_space", "")); }
        else {if ('V' == c_next) {CPP2_UFCS(add)(cur_group_state, create_matcher("named_class_not_ver_space", "")); }
        else {if ('w' == c_next) {CPP2_UFCS(add)(cur_group_state, create_matcher("named_class_word", "")); }
        else {if ('W' == c_next) {CPP2_UFCS(add)(cur_group_state, create_matcher("named_class_not_word", "")); }
        else {if ('Z' == c_next) {CPP2_UFCS(add)(cur_group_state, create_matcher("named_string_end_or_before_new_line_at_end", "")); }
        else {if ('z' == std::move(c_next)) {CPP2_UFCS(add)(cur_group_state, create_matcher("named_string_end", "")); }
        else {
            error("Unknown escape.");
            return false; 
        }}}}}}}}}}}}}}}}}}}}}}}}

        return true; 
    }

#line 2450 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_group(cpp2::in<char> c) & -> bool{
        if (c != '(') {return false; }

        auto has_id {cur_group_state.modifiers.group_captures_have_numbers}; 
        auto has_pattern {true}; 
        std::string group_name {""}; 
        auto group_name_brackets {true}; 
        std::string modifier_change {"::cpp2::regex::match_modifiers_no_change"}; 

        auto modifiers_change_to {cur_group_state.modifiers}; 

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

                auto old_parser_state {group_new_state()}; 
                auto old_branch_state {branch_reset_new_state()}; 
                parse_until(')');
                auto inner {create_matcher_from_state()}; 
                branch_reset_restore_state(std::move(old_branch_state));
                group_restore_state(std::move(old_parser_state));

                auto start_matcher {create_matcher("branch_reset_matcher_logic", "")}; 
                auto end_matcher {create_matcher("special_group_end_logic", "")}; 

                std::vector<std::string> v {std::move(start_matcher), std::move(inner), std::move(end_matcher)}; 
                CPP2_UFCS(add)(cur_group_state, create_matcher_from_list(std::move(v)));

                return true; 
            }
            else {if (c_next == '=' || c_next == '!') {
                static_cast<void>(skip());// Skip '!'
                // Positive or negative lookahead
                return parse_lookahead(("?" + cpp2::to_string(c_next)), std::move(c_next) == '='); 
            }
            else {
                // Simple modifier
                has_id = false;
                std::string change_str {""}; 
                if (!(grab_until_one_of("):", cpp2::out(&change_str)))) {error("Missing ending bracket for group."); return false; }
                if (!(parser_group_modifiers(std::move(change_str), cpp2::out(&modifier_change), modifiers_change_to))) {
                     return false; 
                }

                if (')' == current()) {
                    has_pattern = false;
                }
                else {
                    if (!(next(cpp2::out(&c_next))))   { error("Missing ending bracket for group."); return false; }/* skip ':' */
                }
            }}}}
        }
        else {if (std::move(c_next) == '*') {
            // named pattern
            static_cast<void>(skip());// Skip *.
            std::string name {""}; 
            if (!(grab_until(':', cpp2::out(&name)))) {error("Missing colon for named pattern."); return false; }

            if (name == "pla" || name == "positive_lookahead") {
                return parse_lookahead(("*" + cpp2::to_string(std::move(name)) + ":"), true); 
            }
            else {if (name == "nla" || name == "negative_lookahead") {
                return parse_lookahead(("*" + cpp2::to_string(std::move(name)) + ":"), false); 
            }
            else {
                error(("Unknown named group pattern: '" + cpp2::to_string(std::move(name)) + "'")); return false; 
            }}
        }}

        if (std::move(has_pattern)) {
            // regular group

            auto group_number {-1}; 
            if (std::move(has_id)) {
                group_number = CPP2_UFCS(next)(cur_branch_reset_state);
            }

            auto old_state {group_new_state()}; 
            cur_group_state.modifiers = std::move(modifiers_change_to);
            parse_until(')');
            auto inner {create_matcher_from_state()}; 
            group_restore_state(std::move(old_state));

            auto start_matcher {create_matcher("group_matcher_start_logic", (cpp2::to_string(group_number) + ", " + cpp2::to_string(std::move(modifier_change)) + ", \"" + cpp2::to_string(group_name) + "\", " + cpp2::to_string(std::move(group_name_brackets))))}; 
            if (0 != CPP2_UFCS(size)(group_name)) {
                if (!(CPP2_UFCS(contains)(named_groups, group_name))) {// Redefinition of group name is not an error. The left most one is retained.
                    CPP2_ASSERT_IN_BOUNDS(named_groups, group_name) = group_number;
                }
            }
            auto end_matcher {create_matcher("group_matcher_end_logic", (cpp2::to_string(std::move(group_number))))}; 

            std::vector<std::string> v {std::move(start_matcher), std::move(inner), std::move(end_matcher)}; 
            CPP2_UFCS(add)(cur_group_state, create_matcher_from_list(std::move(v)));
        }
        else {
            // Only a modifier
            cur_group_state.modifiers = std::move(modifiers_change_to);
            CPP2_UFCS(add)(cur_group_state, create_matcher("modifier_matcher_logic", (cpp2::to_string(std::move(modifier_change)))));
        }

        return true; 
    }

#line 2582 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_handle_special(cpp2::in<char> c) & -> bool{
        if (c != '\'') {return false; }

        CPP2_UFCS(add)(cur_group_state, create_matcher("char_matcher_logic", ("'\\" + cpp2::to_string(c) + "', '\\" + cpp2::to_string(c) + "', '\\" + cpp2::to_string(c) + "'")));
        return true; 
    }

#line 2589 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::is_range(cpp2::in<char> c) & -> bool{

        if (c != '{') {return false; }
        if (CPP2_UFCS(empty)(cur_group_state)) {error("'{' without previous element.");return false; }
        if (!(skip())) {error("End of regex before closing '}'."); return false; }

        std::string inner {""}; 
        if (!(grab_until('}', cpp2::out(&inner)))) {error("Missing closing bracket."); return false; }

        inner = trim_copy(inner);
        if (CPP2_UFCS(empty)(inner)) {error("Empty range specifier. Either '{n}', '{n,}', '{,m}' '{n,m}'"); return false; }

        auto kind {range_flags::greedy}; 
        if (peek() == '?') {
            kind = range_flags::not_greedy;
            static_cast<void>(skip());
        }
        else {if (peek() == '+') {
            kind = range_flags::possessive;
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
            if (!(string_to_int(std::move(inner), min_count_number))) {error("Could not convert range to number."); return false; }
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
                min_count = std::move(inner_first);
                if (!(string_to_int(inner, min_count_number))) {error("Could not convert range to number."); return false; }
            }
            if (!(CPP2_UFCS(empty)(inner_last))) {
                max_count = std::move(inner_last);
                if (!(string_to_int(std::move(inner), max_count_number))) {error("Could not convert range to number."); return false; }
            }
        }

        if (!(([_0 = 0, _1 = min_count_number, _2 = max_count_number]{ return cpp2::cmp_less_eq(_0,_1) && cpp2::cmp_less_eq(_1,_2); }()))) {
            error(("Min and max values in range are wrong it should hold 0 <= min <= max. Have 0 <= " + cpp2::to_string(std::move(min_count_number)) + " <= " + cpp2::to_string(std::move(max_count_number))));
            return false; 
        }

        CPP2_UFCS(wrap_last)(cur_group_state, [&, _1 = std::move(min_count), _2 = std::move(max_count)](auto const& inner) -> auto { return create_matcher("range_matcher_logic", (cpp2::to_string(inner) + ", " + cpp2::to_string(_1) + ", " + cpp2::to_string(_2) + ", " + cpp2::to_string(kind)));  });

        return true; 
    }

#line 2652 "regex.h2"
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

        auto kind {range_flags::greedy}; 
        if (peek() == '?') {
            kind = range_flags::not_greedy;
            static_cast<void>(skip());
        }
        else {if (peek() == '+') {
            kind = range_flags::possessive;
            static_cast<void>(skip());
        }}

        if (CPP2_UFCS(empty)(cur_group_state)) {
            error(("'" + cpp2::to_string(c) + "' without previous element."));
            return false; 
        }

        CPP2_UFCS(wrap_last)(cur_group_state, [&, _1 = std::move(min_range), _2 = std::move(max_range), _3 = c](auto const& inner) -> auto { return create_matcher("special_range_matcher_logic", (cpp2::to_string(inner) + ", " + cpp2::to_string(_1) + ", " + cpp2::to_string(_2) + ", " + cpp2::to_string(kind) + ", '" + cpp2::to_string(_3) + "'"));  });
        return true; 
    }

#line 2688 "regex.h2"
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
            CPP2_UFCS(add)(cur_group_state, create_matcher("char_matcher_logic", ("'" + cpp2::to_string(c) + "', '" + cpp2::to_string(safe_tolower(c)) + "', '" + cpp2::to_string(safe_toupper(c)) + "'")));
        }
    }

#line 2710 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::parse_until_new(cpp2::in<char> term) & -> std::string{
        parse_context parse_ctx {regex}; 

        token_ptr cur_token {}; 

        for( ; CPP2_UFCS(valid)(parse_ctx); static_cast<void>(CPP2_UFCS(next)(parse_ctx)) ) {
            if (term == CPP2_UFCS(current)(parse_ctx)) {break; }

            cur_token = nullptr;
            if (!(cur_token) && CPP2_UFCS(valid)(parse_ctx)) {cur_token = range_token::parse(parse_ctx); }
            if (!(cur_token) && CPP2_UFCS(valid)(parse_ctx)) {cur_token = special_range_token::parse(parse_ctx); }
            if (!(cur_token) && CPP2_UFCS(valid)(parse_ctx)) {cur_token = char_token::parse(parse_ctx); }

            if (cur_token && CPP2_UFCS(valid)(parse_ctx)) {
                CPP2_UFCS(add_token)(parse_ctx, cur_token);
            }else {
                error(parse_ctx.error_text);
                return ""; 
            }
        }

        generation_context gen_ctx {}; 
        source += CPP2_UFCS(run)(gen_ctx, CPP2_UFCS(get_tokens)(std::move(parse_ctx)));
        return CPP2_UFCS(get_entry_func)(std::move(gen_ctx)); 
    }

#line 2736 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::create_named_group_lookup() const& -> std::string{
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

#line 2758 "regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_parser<Error_out>::parse() & -> std::string{
        auto mod {parser_expression_modifiers()}; 

        source += "{\n";
        source += ("  group_count: type == std::integral_constant<int, " + cpp2::to_string(cur_branch_reset_state.cur_group) + ">;  //TODO: Use static constexpr when alpha limitation of nested types declarations is lifted.\n");
        source += ("  initial_flags: type == std::integral_constant<int, " + cpp2::to_string(std::move(mod)) + ">;  //TODO: Use static constexpr when alpha limitation of nested types declarations is lifted.\n");

        auto start_name {parse_until_new('\0')}; 
        source += "  entry: (cur, inout ctx, modifiers) -> _ = {\n";
        source += "    ctx.set_group_start(0, cur);";
        source += ("    r := " + cpp2::to_string(std::move(start_name)) + "()(cur, ctx, modifiers, cpp2::regex::true_end_func());\n");
        source += "    if r.matched { ctx.set_group_end(0, r.pos); }";
        source += "    return r;\n";
        source += "  }\n";

        source += "  to_string: () \"TODO\";\n"; // (regex)$\";\n";
        source += create_named_group_lookup();
        source += "}\n";

#line 2778 "regex.h2"
        std::cout << source << std::endl;
        if (has_error) {return "Error"; }

        return source; 
    }

#line 2785 "regex.h2"
template<typename Err> [[nodiscard]] auto generate_template(cpp2::in<std::string_view> regex, cpp2::in<std::string_view> modifier, Err const& err) -> std::string{
    regex_parser<Err> parser {regex, modifier, err}; 
    auto r {CPP2_UFCS(parse)(parser)}; 
    static_cast<void>(std::move(parser));
    return r; 
}

}
}

#endif
