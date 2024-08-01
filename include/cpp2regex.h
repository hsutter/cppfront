
#ifndef CPP2REGEX_H_CPP2
#define CPP2REGEX_H_CPP2


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "cpp2regex.h2"

#line 30 "cpp2regex.h2"
namespace cpp2 {

namespace regex {

#line 47 "cpp2regex.h2"
class expression_flags;

#line 59 "cpp2regex.h2"
template<typename Iter> class match_group;

#line 69 "cpp2regex.h2"
template<typename Iter> class match_return;

#line 77 "cpp2regex.h2"
template<typename CharT, typename Iter, int max_groups> class match_context;

#line 149 "cpp2regex.h2"
class true_end_func;

#line 157 "cpp2regex.h2"
class no_reset;

#line 164 "cpp2regex.h2"
template<typename Func> class on_return;

#line 191 "cpp2regex.h2"
template<typename CharT, CharT C> class single_class_entry;

#line 200 "cpp2regex.h2"
template<typename CharT, CharT Start, CharT End> class range_class_entry;

#line 209 "cpp2regex.h2"
template<typename CharT, typename ...List> class combined_class_entry;

#line 218 "cpp2regex.h2"
template<typename CharT, CharT ...List> class list_class_entry;

#line 227 "cpp2regex.h2"
template<typename CharT, string_util::fixed_string Name, typename Inner> class named_class_entry;

#line 234 "cpp2regex.h2"
template<typename CharT, typename Inner> class negated_class_entry;

#line 243 "cpp2regex.h2"
template<typename CharT, string_util::fixed_string Name, typename Inner> class shorthand_class_entry;

#line 296 "cpp2regex.h2"
class regex_token;

#line 322 "cpp2regex.h2"
class regex_token_check;

#line 341 "cpp2regex.h2"
class regex_token_code;

#line 360 "cpp2regex.h2"
class regex_token_empty;

#line 376 "cpp2regex.h2"
class regex_token_list;

#line 418 "cpp2regex.h2"
class parse_context_group_state;

#line 479 "cpp2regex.h2"
class parse_context_branch_reset_state;

#line 522 "cpp2regex.h2"
class parse_context;

#line 920 "cpp2regex.h2"
class generation_function_context;
    

#line 938 "cpp2regex.h2"
class generation_context;

#line 1137 "cpp2regex.h2"
class alternative_token;

#line 1152 "cpp2regex.h2"
class alternative_token_gen;

#line 1202 "cpp2regex.h2"
template<typename CharT> class alternative_token_matcher;

#line 1231 "cpp2regex.h2"
class any_token;

#line 1262 "cpp2regex.h2"
class char_token;

#line 1399 "cpp2regex.h2"
class class_token;

#line 1556 "cpp2regex.h2"
template<typename CharT, bool negate, bool case_insensitive, typename ...List> class class_token_matcher;

#line 1672 "cpp2regex.h2"
class group_ref_token;

#line 1834 "cpp2regex.h2"
class group_token;

#line 2140 "cpp2regex.h2"
class lookahead_token;

#line 2246 "cpp2regex.h2"
class range_flags;
    

#line 2255 "cpp2regex.h2"
class range_token;

#line 2401 "cpp2regex.h2"
template<typename CharT, int min_count, int max_count, int kind> class range_token_matcher;

#line 2538 "cpp2regex.h2"
class special_range_token;

#line 2629 "cpp2regex.h2"
template<typename CharT, typename matcher_wrapper> class regular_expression;

#line 2721 "cpp2regex.h2"
template<typename Error_out> class regex_generator;

#line 2795 "cpp2regex.h2"
}
}


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "cpp2regex.h2"

//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.


//===========================================================================
//  Regex support
//===========================================================================

#ifndef CPP2_CPP2REGEX_H
#define CPP2_CPP2REGEX_H


template<typename matcher_wrapper, typename Iter, typename CharT>
using matcher_wrapper_type = typename matcher_wrapper::template wrap<Iter, CharT>;

template<typename matcher>
using matcher_context_type = typename matcher::context;

using error_func = std::function<void(std::string)>;

#line 30 "cpp2regex.h2"
namespace cpp2 {

namespace regex {

template <typename CharT> using bview = std::basic_string_view<CharT>;
template<typename CharT> using bstring = std::basic_string<CharT>;

#line 47 "cpp2regex.h2"
class expression_flags
 {
private: cpp2::u8 _value; private: constexpr expression_flags(cpp2::impl::in<cpp2::i64> _val);

private: constexpr auto operator=(cpp2::impl::in<cpp2::i64> _val) -> expression_flags& ;
public: constexpr auto operator|=(expression_flags const& that) & -> void;
public: constexpr auto operator&=(expression_flags const& that) & -> void;
public: constexpr auto operator^=(expression_flags const& that) & -> void;
public: [[nodiscard]] constexpr auto operator|(expression_flags const& that) const& -> expression_flags;
public: [[nodiscard]] constexpr auto operator&(expression_flags const& that) const& -> expression_flags;
public: [[nodiscard]] constexpr auto operator^(expression_flags const& that) const& -> expression_flags;
public: [[nodiscard]] constexpr auto has(expression_flags const& that) const& -> bool;
public: constexpr auto set(expression_flags const& that) & -> void;
public: constexpr auto clear(expression_flags const& that) & -> void;
public: static const expression_flags case_insensitive;
public: static const expression_flags multiple_lines;
public: static const expression_flags single_line;
public: static const expression_flags no_group_captures;
public: static const expression_flags perl_code_syntax;
public: static const expression_flags perl_code_syntax_in_classes;
public: static const expression_flags none;
public: [[nodiscard]] constexpr auto get_raw_value() const& -> cpp2::u8;
public: constexpr explicit expression_flags();
public: constexpr expression_flags(expression_flags const& that);
public: constexpr auto operator=(expression_flags const& that) -> expression_flags& ;
public: constexpr expression_flags(expression_flags&& that) noexcept;
public: constexpr auto operator=(expression_flags&& that) noexcept -> expression_flags& ;
public: [[nodiscard]] auto operator<=>(expression_flags const& that) const& -> std::strong_ordering = default;
public: [[nodiscard]] auto to_string() const& -> std::string;

#line 55 "cpp2regex.h2"
};

#line 59 "cpp2regex.h2"
template<typename Iter> class match_group
 {
    public: Iter start {}; 
    public: Iter end {}; 

    public: bool matched {false}; 
    public: match_group(auto const& start_, auto const& end_, auto const& matched_);
public: match_group();

#line 65 "cpp2regex.h2"
};

#line 69 "cpp2regex.h2"
template<typename Iter> class match_return
 {
    public: bool matched {false}; 
    public: Iter pos {}; 
    public: match_return(auto const& matched_, auto const& pos_);
public: match_return();

#line 73 "cpp2regex.h2"
};

#line 77 "cpp2regex.h2"
template<typename CharT, typename Iter, int max_groups> class match_context
 {
            public: Iter begin; 
            public: Iter end; 

    private: std::array<match_group<Iter>,max_groups> groups {}; 

    public: explicit match_context(Iter const& begin_, Iter const& end_);

#line 89 "cpp2regex.h2"
    public: match_context(match_context const& that);
#line 89 "cpp2regex.h2"
    public: auto operator=(match_context const& that) -> match_context& ;
#line 89 "cpp2regex.h2"
    public: match_context(match_context&& that) noexcept;
#line 89 "cpp2regex.h2"
    public: auto operator=(match_context&& that) noexcept -> match_context& ;

#line 93 "cpp2regex.h2"
    public: [[nodiscard]] auto get_group(auto const& group) const& -> auto;

    public: [[nodiscard]] auto get_group_end(auto const& group) const& -> int;

#line 102 "cpp2regex.h2"
    public: [[nodiscard]] auto get_group_start(auto const& group) const& -> int;

#line 109 "cpp2regex.h2"
    public: [[nodiscard]] auto get_group_string(auto const& group) const& -> std::string;

#line 117 "cpp2regex.h2"
    public: auto set_group_end(auto const& group, auto const& pos) & -> void;

#line 123 "cpp2regex.h2"
    public: auto set_group_invalid(auto const& group) & -> void;

#line 127 "cpp2regex.h2"
    public: auto set_group_start(auto const& group, auto const& pos) & -> void;

#line 131 "cpp2regex.h2"
    public: [[nodiscard]] auto size() const& -> auto;

#line 135 "cpp2regex.h2"
    public: [[nodiscard]] auto fail() const& -> auto;
    public: [[nodiscard]] auto pass(cpp2::impl::in<Iter> cur) const& -> auto;

#line 140 "cpp2regex.h2"
    public: [[nodiscard]] auto get_group_idx(auto const& group) const& -> size_t;

#line 144 "cpp2regex.h2"
};

#line 149 "cpp2regex.h2"
class true_end_func
 {
    public: [[nodiscard]] auto operator()(auto const& cur, auto& ctx) const& -> auto;
};

#line 157 "cpp2regex.h2"
class no_reset
 {
    public: auto operator()([[maybe_unused]] auto& unnamed_param_2) const& -> void;
};

#line 164 "cpp2regex.h2"
template<typename Func> class on_return
 {
    private: Func func; 

    public: explicit on_return(Func const& f);
#line 168 "cpp2regex.h2"
    public: auto operator=(Func const& f) -> on_return& ;

#line 172 "cpp2regex.h2"
    public: ~on_return() noexcept;
    public: on_return(on_return const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(on_return const&) -> void = delete;


#line 175 "cpp2regex.h2"
};

#line 179 "cpp2regex.h2"
template<typename Func> [[nodiscard]] auto make_on_return(Func const& func) -> auto;

#line 191 "cpp2regex.h2"
template<typename CharT, CharT C> class single_class_entry
 {
    public: [[nodiscard]] static auto includes(cpp2::impl::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: single_class_entry() = default;
    public: single_class_entry(single_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(single_class_entry const&) -> void = delete;

#line 195 "cpp2regex.h2"
};

#line 200 "cpp2regex.h2"
template<typename CharT, CharT Start, CharT End> class range_class_entry
 {
    public: [[nodiscard]] static auto includes(cpp2::impl::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: range_class_entry() = default;
    public: range_class_entry(range_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_class_entry const&) -> void = delete;

#line 204 "cpp2regex.h2"
};

#line 209 "cpp2regex.h2"
template<typename CharT, typename ...List> class combined_class_entry
 {
    public: [[nodiscard]] static auto includes(cpp2::impl::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: combined_class_entry() = default;
    public: combined_class_entry(combined_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(combined_class_entry const&) -> void = delete;

#line 213 "cpp2regex.h2"
};

#line 218 "cpp2regex.h2"
template<typename CharT, CharT ...List> class list_class_entry
 {
    public: [[nodiscard]] static auto includes(cpp2::impl::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: list_class_entry() = default;
    public: list_class_entry(list_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(list_class_entry const&) -> void = delete;

#line 222 "cpp2regex.h2"
};

#line 227 "cpp2regex.h2"
template<typename CharT, string_util::fixed_string Name, typename Inner> class named_class_entry
 {
    public: [[nodiscard]] static auto includes(cpp2::impl::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: named_class_entry() = default;
    public: named_class_entry(named_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(named_class_entry const&) -> void = delete;

#line 231 "cpp2regex.h2"
};

#line 234 "cpp2regex.h2"
template<typename CharT, typename Inner> class negated_class_entry
: public Inner {

    public: [[nodiscard]] static auto includes(cpp2::impl::in<CharT> c) -> auto;
    public: negated_class_entry() = default;
    public: negated_class_entry(negated_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(negated_class_entry const&) -> void = delete;

#line 238 "cpp2regex.h2"
};

#line 243 "cpp2regex.h2"
template<typename CharT, string_util::fixed_string Name, typename Inner> class shorthand_class_entry
 {
    public: [[nodiscard]] static auto includes(cpp2::impl::in<CharT> c) -> auto;
    public: [[nodiscard]] static auto to_string() -> auto;
    public: shorthand_class_entry() = default;
    public: shorthand_class_entry(shorthand_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(shorthand_class_entry const&) -> void = delete;

#line 247 "cpp2regex.h2"
};

#line 252 "cpp2regex.h2"
template        <typename CharT> using digits_class = named_class_entry<CharT,"digits",range_class_entry<CharT,'0','9'>>;
template        <typename CharT> using lower_class = named_class_entry<CharT,"lower",range_class_entry<CharT,'a','z'>>;
template        <typename CharT> using upper_class = named_class_entry<CharT,"upper",range_class_entry<CharT,'A','Z'>>;

#line 258 "cpp2regex.h2"
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

#line 274 "cpp2regex.h2"
template                 <typename CharT> using short_digits_class = shorthand_class_entry<CharT,"\\d",digits_class<CharT>>;
template                 <typename CharT> using short_hor_space_class = shorthand_class_entry<CharT,"\\h",hor_space_class<CharT>>;
template                 <typename CharT> using short_space_class = shorthand_class_entry<CharT,"\\s",space_class<CharT>>;
template<typename CharT> using short_vert_space_class = shorthand_class_entry<CharT,"\\v",ver_space_class<CharT>>;
template                 <typename CharT> using short_word_class = shorthand_class_entry<CharT,"\\w",word_class<CharT>>;

template                     <typename CharT> using short_not_digits_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\D",digits_class<CharT>>>;
template                     <typename CharT> using short_not_hor_space_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\H",hor_space_class<CharT>>>;
template                     <typename CharT> using short_not_space_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\S",space_class<CharT>>>;
template<typename CharT> using short_not_vert_space_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\V",ver_space_class<CharT>>>;
template                     <typename CharT> using short_not_word_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\W",word_class<CharT>>>;

#line 296 "cpp2regex.h2"
class regex_token
 {
    public: std::string string_rep; 

    public: explicit regex_token(cpp2::impl::in<std::string> str);

#line 304 "cpp2regex.h2"
    public: explicit regex_token();

#line 309 "cpp2regex.h2"
    public: virtual auto generate_code([[maybe_unused]] generation_context& unnamed_param_2) const -> void = 0;

    public: virtual auto add_groups([[maybe_unused]] std::set<int>& unnamed_param_2) const -> void;
    public: [[nodiscard]] auto to_string() const& -> std::string;
    public: auto set_string(cpp2::impl::in<std::string> s) & -> void;
    public: virtual ~regex_token() noexcept;

    public: regex_token(regex_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_token const&) -> void = delete;

#line 314 "cpp2regex.h2"
};

using token_ptr = std::shared_ptr<regex_token>;
using token_vec = std::vector<token_ptr>;

#line 320 "cpp2regex.h2"
//  Adds a check in code generation.
//
class regex_token_check
: public regex_token {

#line 326 "cpp2regex.h2"
    private: std::string check; 

    public: explicit regex_token_check(cpp2::impl::in<std::string> str, cpp2::impl::in<std::string> check_);

#line 333 "cpp2regex.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;
    public: virtual ~regex_token_check() noexcept;

    public: regex_token_check(regex_token_check const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_token_check const&) -> void = delete;


#line 336 "cpp2regex.h2"
};

#line 339 "cpp2regex.h2"
//  Adds code in code generation.
//
class regex_token_code
: public regex_token {

#line 345 "cpp2regex.h2"
    private: std::string code; 

    public: explicit regex_token_code(cpp2::impl::in<std::string> str, cpp2::impl::in<std::string> code_);

#line 352 "cpp2regex.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;
    public: virtual ~regex_token_code() noexcept;

    public: regex_token_code(regex_token_code const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_token_code const&) -> void = delete;


#line 355 "cpp2regex.h2"
};

#line 358 "cpp2regex.h2"
//  Token that does not influence the matching. E.g. comment.
//
class regex_token_empty
: public regex_token {

#line 364 "cpp2regex.h2"
    public: explicit regex_token_empty(cpp2::impl::in<std::string> str);

#line 368 "cpp2regex.h2"
    public: auto generate_code([[maybe_unused]] generation_context& unnamed_param_2) const -> void override;
    public: virtual ~regex_token_empty() noexcept;

    public: regex_token_empty(regex_token_empty const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_token_empty const&) -> void = delete;


#line 371 "cpp2regex.h2"
};

#line 374 "cpp2regex.h2"
//  Represents a list of regex tokens as one token.
//
class regex_token_list
: public regex_token {

#line 380 "cpp2regex.h2"
    public: token_vec tokens; 

    public: explicit regex_token_list(cpp2::impl::in<token_vec> t);

#line 387 "cpp2regex.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 393 "cpp2regex.h2"
    public: auto add_groups(std::set<int>& groups) const -> void override;

#line 399 "cpp2regex.h2"
    public: [[nodiscard]] static auto gen_string(cpp2::impl::in<token_vec> vec) -> std::string;
    public: virtual ~regex_token_list() noexcept;

    public: regex_token_list(regex_token_list const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_token_list const&) -> void = delete;


#line 406 "cpp2regex.h2"
};

#line 409 "cpp2regex.h2"
//-----------------------------------------------------------------------
//
//  Parse and generation context.
//
//-----------------------------------------------------------------------
//

//  State of the current capturing group. See '(<pattern>)'
//
class parse_context_group_state
 {
    public: token_vec cur_match_list {};           // Current list of matchers.
    public: token_vec alternate_match_lists {};    // List of alternate matcher lists. E.g. ab|cd|xy.
    public: expression_flags modifiers {};         // Current modifiers for the group/regular expression.

    //  Start a new alternative.
    public: auto next_alternative() & -> void;

#line 432 "cpp2regex.h2"
    //  Swap this state with the other one.
    public: auto swap(parse_context_group_state& t) & -> void;

#line 439 "cpp2regex.h2"
    //  Convert this state into a regex token.
    public: [[nodiscard]] auto get_as_token() & -> token_ptr;

#line 451 "cpp2regex.h2"
    //  Add a token to the current matcher list.
    public: auto add(cpp2::impl::in<token_ptr> token) & -> void;

#line 456 "cpp2regex.h2"
    //  True if current matcher list is empty.
    public: [[nodiscard]] auto empty() const& -> bool;

#line 460 "cpp2regex.h2"
    //  Apply optimizations to the matcher list.
    public: static auto post_process_list(token_vec& list) -> void;
    public: parse_context_group_state(auto const& cur_match_list_, auto const& alternate_match_lists_, auto const& modifiers_);
public: parse_context_group_state();


#line 474 "cpp2regex.h2"
};

#line 477 "cpp2regex.h2"
//  State for the branch reset. Takes care of the group numbering. See '(|<pattern>)'.
//
class parse_context_branch_reset_state
 {
    public: bool is_active {false}; // If we have a branch reset group.
    public: int cur_group {1}; // Next group identifier. 0 == global capture group.
    public: int max_group {1}; // Maximum group identifier generated.
    public: int from {1};     // Starting identifier on new alternative branch.

    //  Next group identifier.
    public: [[nodiscard]] auto next() & -> int;

#line 495 "cpp2regex.h2"
    //  Set next group identifier.
    public: auto set_next(cpp2::impl::in<int> g) & -> void;

#line 501 "cpp2regex.h2"
    //  Start a new alternative branch.
    public: auto next_alternative() & -> void;

#line 508 "cpp2regex.h2"
    //  Initialize for a branch reset group.
    public: auto set_active_reset(cpp2::impl::in<int> restart) & -> void;
    public: parse_context_branch_reset_state(auto const& is_active_, auto const& cur_group_, auto const& max_group_, auto const& from_);
public: parse_context_branch_reset_state();


#line 515 "cpp2regex.h2"
};

#line 518 "cpp2regex.h2"
//  Context during parsing of the regular expressions.
// 
//  Keeps track of the distributed group identifiers, current parsed group and branch resets.
//
class parse_context
 {
    private: std::string_view regex; // Regular expression string.
    private: size_t pos {0};   // Current parsing position.
    private: token_ptr root;   // Token representing the regular expression.

    private: parse_context_group_state cur_group_state {}; 
    private: parse_context_branch_reset_state cur_branch_reset_state {}; 

#line 532 "cpp2regex.h2"
           public: std::map<std::string,int> named_groups {}; 

    private: error_func error_out; // TODO: Declaring std::function<void(std::string)> fails for cpp2.
    private: bool has_error {false}; 

    public: explicit parse_context(cpp2::impl::in<std::string_view> r, auto const& e);

#line 543 "cpp2regex.h2"
    //  State management functions
    //

    //  Returned group state needs to be stored and provided in `end_group`.
    public: [[nodiscard]] auto start_group() & -> parse_context_group_state;

#line 556 "cpp2regex.h2"
    //  `old_state` argument needs to be from start group.
    public: [[nodiscard]] auto end_group(cpp2::impl::in<parse_context_group_state> old_state) & -> token_ptr;

#line 564 "cpp2regex.h2"
    public: [[nodiscard]] auto get_modifiers() const& -> expression_flags;

#line 568 "cpp2regex.h2"
    public: auto set_modifiers(cpp2::impl::in<expression_flags> mod) & -> void;

#line 572 "cpp2regex.h2"
    //  Branch reset management functions
    //

    public: [[nodiscard]] auto branch_reset_new_state() & -> parse_context_branch_reset_state;

#line 584 "cpp2regex.h2"
    public: auto branch_reset_restore_state(cpp2::impl::in<parse_context_branch_reset_state> old_state) & -> void;

#line 591 "cpp2regex.h2"
    public: auto next_alternative() & -> void;

#line 597 "cpp2regex.h2"
    //  Regex token management
    //
    public: auto add_token(cpp2::impl::in<token_ptr> token) & -> void;

#line 603 "cpp2regex.h2"
    public: [[nodiscard]] auto has_token() const& -> bool;

#line 607 "cpp2regex.h2"
    public: [[nodiscard]] auto pop_token() & -> token_ptr;

#line 618 "cpp2regex.h2"
    public: [[nodiscard]] auto get_as_token() & -> token_ptr;

#line 622 "cpp2regex.h2"
    //  Group management
    //
    public: [[nodiscard]] auto get_cur_group() const& -> int;

#line 628 "cpp2regex.h2"
    public: [[nodiscard]] auto next_group() & -> int;

#line 632 "cpp2regex.h2"
    public: auto set_named_group(cpp2::impl::in<std::string> name, cpp2::impl::in<int> id) & -> void;

#line 639 "cpp2regex.h2"
    public: [[nodiscard]] auto get_named_group(cpp2::impl::in<std::string> name) const& -> int;

#line 650 "cpp2regex.h2"
    //  Position management functions
    //
    public: [[nodiscard]] auto current() const& -> char;

    //  Get the next token in the regex, skipping spaces according to the parameters. See `x` and `xx` modifiers.
    private: [[nodiscard]] auto get_next_position(cpp2::impl::in<bool> in_class, cpp2::impl::in<bool> no_skip) const& -> size_t;

#line 694 "cpp2regex.h2"
    //  Return true if next token is available.
    private: [[nodiscard]] auto next_impl(cpp2::impl::in<bool> in_class, cpp2::impl::in<bool> no_skip) & -> bool;

#line 706 "cpp2regex.h2"
    public: [[nodiscard]] auto next() & -> auto;
    public: [[nodiscard]] auto next_in_class() & -> auto;
    public: [[nodiscard]] auto next_no_skip() & -> auto;

    public: [[nodiscard]] auto next_n(cpp2::impl::in<int> n) & -> bool;

#line 719 "cpp2regex.h2"
    public: [[nodiscard]] auto has_next() const& -> bool;

    private: [[nodiscard]] auto grab_until_impl(cpp2::impl::in<std::string> e, cpp2::impl::out<std::string> r, cpp2::impl::in<bool> any) & -> bool;

#line 742 "cpp2regex.h2"
    public: [[nodiscard]] auto grab_until(cpp2::impl::in<std::string> e, cpp2::impl::out<std::string> r) & -> auto;
    public: [[nodiscard]] auto grab_until(cpp2::impl::in<char> e, cpp2::impl::out<std::string> r) & -> auto;
    public: [[nodiscard]] auto grab_until_one_of(cpp2::impl::in<std::string> e, cpp2::impl::out<std::string> r) & -> auto;

    public: [[nodiscard]] auto grab_n(cpp2::impl::in<int> n, cpp2::impl::out<std::string> r) & -> bool;

#line 759 "cpp2regex.h2"
    public: [[nodiscard]] auto grab_number() & -> std::string;

#line 780 "cpp2regex.h2"
    private: [[nodiscard]] auto peek_impl(cpp2::impl::in<bool> in_class) const& -> char;

#line 790 "cpp2regex.h2"
    public: [[nodiscard]] auto peek() const& -> auto;
    public: [[nodiscard]] auto peek_in_class() const& -> auto;

#line 794 "cpp2regex.h2"
    //  Parsing functions
    //
    public: [[nodiscard]] auto parser_group_modifiers(cpp2::impl::in<std::string> change_str, expression_flags& parser_modifiers) & -> bool;

#line 850 "cpp2regex.h2"
    public: [[nodiscard]] auto parse_until(cpp2::impl::in<char> term) & -> bool;

#line 888 "cpp2regex.h2"
    public: [[nodiscard]] auto parse(cpp2::impl::in<std::string> modifiers) & -> bool;

#line 903 "cpp2regex.h2"
    //  Misc functions

    public: [[nodiscard]] auto get_pos() const& -> auto;
    public: [[nodiscard]] auto get_range(cpp2::impl::in<size_t> start, cpp2::impl::in<size_t> end) const& -> auto;
    public: [[nodiscard]] auto valid() const& -> bool;

    public: [[nodiscard]] auto error(cpp2::impl::in<std::string> err) & -> token_ptr;
    public: parse_context(parse_context const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(parse_context const&) -> void = delete;


#line 914 "cpp2regex.h2"
};

#line 917 "cpp2regex.h2"
//  Context for one function generation. Generation of functions can be interleaved,
//  therefore we buffer the code for one function here.
//
class generation_function_context {
    public: std::string code {""}; 
    public: std::string tabs {""}; 

    public: auto add_tabs(cpp2::impl::in<int> c) & -> void;

#line 931 "cpp2regex.h2"
    public: auto remove_tabs(cpp2::impl::in<int> c) & -> void;
    public: generation_function_context(auto const& code_, auto const& tabs_);
public: generation_function_context();


#line 934 "cpp2regex.h2"
};

#line 937 "cpp2regex.h2"
//  Context for generating the state machine.
class generation_context
 {
    private: std::vector<generation_function_context> gen_stack {1}; // Element 0 contains all the code.

    private: int matcher_func {0}; 
    private: int reset_func {0}; 
    private: int temp_name {0}; 
    private: std::string entry_func {""}; 

    //  Generation helpers
    //
    public: [[nodiscard]] auto match_parameters() const& -> std::string;

    //  Code generation.

    //  Add code line.
    public: auto add(cpp2::impl::in<std::string> s) & -> void;

#line 959 "cpp2regex.h2"
    //  Add check for token. The check needs to be a function call that returns a boolean.
    public: auto add_check(cpp2::impl::in<std::string> check) & -> void;

#line 965 "cpp2regex.h2"
    //  Add a stateful check. The check needs to return a `match_return`.
    public: auto add_statefull(cpp2::impl::in<std::string> next_func, cpp2::impl::in<std::string> check) & -> void;

#line 974 "cpp2regex.h2"
    protected: auto start_func_named(cpp2::impl::in<std::string> name) & -> void;

#line 985 "cpp2regex.h2"
    protected: [[nodiscard]] auto start_func() & -> std::string;

#line 992 "cpp2regex.h2"
    protected: auto end_func_statefull(cpp2::impl::in<std::string> s) & -> void;

#line 1011 "cpp2regex.h2"
    //  Generate the function for a token.
    public: [[nodiscard]] auto generate_func(cpp2::impl::in<token_ptr> token) & -> std::string;

#line 1021 "cpp2regex.h2"
    //  Generate the reset for a list of group identifiers.
    public: [[nodiscard]] auto generate_reset(cpp2::impl::in<std::set<int>> groups) & -> std::string;

#line 1044 "cpp2regex.h2"
    //  Name generation
    //
    protected: [[nodiscard]] auto gen_func_name() & -> std::string;

#line 1052 "cpp2regex.h2"
    public: [[nodiscard]] auto next_func_name() & -> std::string;

#line 1056 "cpp2regex.h2"
    protected: [[nodiscard]] auto gen_reset_func_name() & -> std::string;

#line 1062 "cpp2regex.h2"
    public: [[nodiscard]] auto gen_temp() & -> std::string;

#line 1068 "cpp2regex.h2"
    //  Context management
    //
    public: [[nodiscard]] auto new_context() & -> generation_function_context*;

#line 1078 "cpp2regex.h2"
    public: auto finish_context() & -> void;

#line 1086 "cpp2regex.h2"
    //  Misc functions
    //
    private: [[nodiscard]] auto get_current() & -> generation_function_context*;

#line 1092 "cpp2regex.h2"
    private: [[nodiscard]] auto get_base() & -> generation_function_context*;

#line 1096 "cpp2regex.h2"
    public: [[nodiscard]] auto get_entry_func() const& -> std::string;

#line 1100 "cpp2regex.h2"
    public: [[nodiscard]] auto create_named_group_lookup(cpp2::impl::in<std::map<std::string,int>> named_groups) const& -> std::string;

#line 1124 "cpp2regex.h2"
    //  Run the generation for the token.
    public: [[nodiscard]] auto run(cpp2::impl::in<token_ptr> token) & -> std::string;
    public: generation_context() = default;
    public: generation_context(generation_context const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(generation_context const&) -> void = delete;


#line 1130 "cpp2regex.h2"
};

#line 1133 "cpp2regex.h2"
//  Regex syntax: |  Example: ab|ba
//
//  Non greedy implementation. First alternative that matches is chosen.
//
class alternative_token
: public regex_token_empty {
                                     // No code gen here. alternative_token_gen is created in the parse_context

    public: explicit alternative_token();

    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;
    public: virtual ~alternative_token() noexcept;

    public: alternative_token(alternative_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(alternative_token const&) -> void = delete;


#line 1150 "cpp2regex.h2"
};

class alternative_token_gen
: public regex_token {

#line 1156 "cpp2regex.h2"
    private: token_vec alternatives; 

    public: explicit alternative_token_gen(cpp2::impl::in<token_vec> a);

#line 1163 "cpp2regex.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 1180 "cpp2regex.h2"
    public: auto add_groups(std::set<int>& groups) const -> void override;

#line 1187 "cpp2regex.h2"
    public: [[nodiscard]] static auto gen_string(cpp2::impl::in<token_vec> a) -> std::string;
    public: virtual ~alternative_token_gen() noexcept;

    public: alternative_token_gen(alternative_token_gen const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(alternative_token_gen const&) -> void = delete;


#line 1199 "cpp2regex.h2"
};

#line 1202 "cpp2regex.h2"
template<typename CharT> class alternative_token_matcher
 {
    public: [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& end_func, auto const& tail, auto const& ...functions) -> auto;

#line 1208 "cpp2regex.h2"
    private: template<typename ...Other> [[nodiscard]] static auto match_first(auto const& cur, auto& ctx, auto const& end_func, auto const& tail, auto const& cur_func, auto const& cur_reset, Other const& ...other) -> auto;
    public: alternative_token_matcher() = default;
    public: alternative_token_matcher(alternative_token_matcher const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(alternative_token_matcher const&) -> void = delete;


#line 1226 "cpp2regex.h2"
};

#line 1229 "cpp2regex.h2"
//  Regex syntax: .
//
class any_token
: public regex_token_check {

#line 1235 "cpp2regex.h2"
    public: explicit any_token(cpp2::impl::in<bool> single_line);

#line 1239 "cpp2regex.h2"
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;
    public: virtual ~any_token() noexcept;

    public: any_token(any_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(any_token const&) -> void = delete;


#line 1244 "cpp2regex.h2"
};

#line 1247 "cpp2regex.h2"
template<typename CharT, bool single_line> [[nodiscard]] auto any_token_matcher(auto& cur, auto& ctx) -> bool;

#line 1260 "cpp2regex.h2"
//  Regex syntax: a
//
class char_token
: public regex_token {

#line 1266 "cpp2regex.h2"
    private: std::string token; 
    private: bool ignore_case; 

    public: explicit char_token(cpp2::impl::in<char> t, cpp2::impl::in<bool> ignore_case_);

#line 1275 "cpp2regex.h2"
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 1279 "cpp2regex.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 1302 "cpp2regex.h2"
    public: auto gen_case_insensitive(cpp2::impl::in<std::string> lower, cpp2::impl::in<std::string> upper, generation_context& ctx) const& -> void;

#line 1323 "cpp2regex.h2"
    public: auto gen_case_sensitive(generation_context& ctx) const& -> void;

#line 1341 "cpp2regex.h2"
    public: [[nodiscard]] auto add_escapes(std::string str) const& -> std::string;

#line 1356 "cpp2regex.h2"
    public: auto append(char_token const& that) & -> void;
    public: virtual ~char_token() noexcept;

    public: char_token(char_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(char_token const&) -> void = delete;


#line 1360 "cpp2regex.h2"
};

#line 1363 "cpp2regex.h2"
// TODO: Check if vectorization works at some point with this implementation.
// char_token_matcher: <tokens: string_util::fixed_string> (inout cur, inout ctx) -> bool = {
//     if !(std::distance(cur, ctx.end) < tokens..size()) {
//         return false;
//     }
//     matched : bool = true;
//     (copy i: int = 0) while i < tokens..size() next i += 1 {
//         if tokens..data()[i] != cur[i] {
//             matched = false; // No break for performance optimization. Without break, the loop vectorizes.
//         }
//     }
//     if matched {
//         cur += tokens..size();
//     }
//     return matched;
// }

// char_token_case_insensitive_matcher: <lower: string_util::fixed_string, upper: string_util::fixed_string> (inout cur, inout ctx) -> bool = {
//     if !(std::distance(cur, ctx.end) < lower..size()) {
//         return false;
//     }
//     matched : bool = true;
//     (copy i : int = 0) while i < lower..size() next i += 1 {
//         if !(lower..data()[i] == cur[i] || upper..data()[i] == cur[i]) {
//             matched = false; // No break for performance optimization. Without break, the loop vectorizes.
//         }
//     }
//     if matched {
//         cur += lower..size();
//     }
//     return matched;
// }

#line 1397 "cpp2regex.h2"
//  Regex syntax: [<character classes>]  Example: [abcx-y[:digits:]]
//
class class_token
: public regex_token {

#line 1403 "cpp2regex.h2"
    private: bool negate; 
    private: bool case_insensitive; 
    private: std::string class_str; 

    public: explicit class_token(cpp2::impl::in<bool> negate_, cpp2::impl::in<bool> case_insensitive_, cpp2::impl::in<std::string> class_str_, cpp2::impl::in<std::string> str);

#line 1415 "cpp2regex.h2"
    //  TODO: Rework class generation: Generate check functions for classes.
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 1541 "cpp2regex.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 1546 "cpp2regex.h2"
    private: [[nodiscard]] static auto create_matcher(cpp2::impl::in<std::string> name, cpp2::impl::in<std::string> template_arguments) -> std::string;
    public: virtual ~class_token() noexcept;

    public: class_token(class_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(class_token const&) -> void = delete;


#line 1553 "cpp2regex.h2"
};

#line 1556 "cpp2regex.h2"
template<typename CharT, bool negate, bool case_insensitive, typename ...List> class class_token_matcher
 {
    public: [[nodiscard]] static auto match(auto& cur, auto& ctx) -> bool;

#line 1587 "cpp2regex.h2"
    private: template<typename First, typename ...Other> [[nodiscard]] static auto match_any(cpp2::impl::in<CharT> c) -> bool;
    public: class_token_matcher() = default;
    public: class_token_matcher(class_token_matcher const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(class_token_matcher const&) -> void = delete;


#line 1600 "cpp2regex.h2"
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
#line 1611 "cpp2regex.h2"
};

#line 1614 "cpp2regex.h2"
//  Regex syntax: \a or \n or \[
//
[[nodiscard]] auto escape_token_parse(parse_context& ctx) -> token_ptr;

#line 1655 "cpp2regex.h2"
//  Regex syntax: \K Example: ab\Kcd
//
[[nodiscard]] auto global_group_reset_token_parse(parse_context& ctx) -> token_ptr;

#line 1666 "cpp2regex.h2"
//  Regex syntax: \<number>  Example: \1
//                \g{name_or_number}
//                \k{name_or_number}
//                \k<name_or_number>
//                \k'name_or_number'
//
class group_ref_token
: public regex_token {

#line 1676 "cpp2regex.h2"
    private: int id; 
    private: bool case_insensitive; 

    public: explicit group_ref_token(cpp2::impl::in<int> id_, cpp2::impl::in<bool> case_insensitive_, cpp2::impl::in<std::string> str);

#line 1686 "cpp2regex.h2"
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 1787 "cpp2regex.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;
    public: virtual ~group_ref_token() noexcept;

    public: group_ref_token(group_ref_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_ref_token const&) -> void = delete;


#line 1790 "cpp2regex.h2"
};

#line 1793 "cpp2regex.h2"
template<typename CharT, int group, bool case_insensitive> [[nodiscard]] auto group_ref_token_matcher(auto& cur, auto& ctx) -> bool;

#line 1824 "cpp2regex.h2"
//  Regex syntax: (<tokens>)      Example: (abc)
//                (?<modifiers)            (?i)
//                (?<modifiers>:<tokens>)  (?i:abc)
//                (?<<name>>:<tokens>)     (?<start>:abc)
//                (?#<comment>)            (#Step 1 finished)
//                (?|<tokens>)             (?|(abc)|(cde))
//                (?=<tokens>)             (?=abc)
//                (?!<tokens>)             (?!abc)
//                (*<name>:<tokens)        (*pla:abc)
//
class group_token
: public regex_token {

#line 1838 "cpp2regex.h2"
    private: int number {-1}; 
    private: token_ptr inner {nullptr}; 

    public: [[nodiscard]] static auto parse_lookahead(parse_context& ctx, cpp2::impl::in<std::string> syntax, cpp2::impl::in<bool> positive) -> token_ptr;

#line 1855 "cpp2regex.h2"
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 1992 "cpp2regex.h2"
    public: [[nodiscard]] static auto gen_string(cpp2::impl::in<std::string> name, cpp2::impl::in<bool> name_brackets, cpp2::impl::in<bool> has_modifier, cpp2::impl::in<std::string> modifiers, cpp2::impl::in<token_ptr> inner_) -> std::string;

#line 2010 "cpp2regex.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 2030 "cpp2regex.h2"
    public: auto add_groups(std::set<int>& groups) const -> void override;
    public: virtual ~group_token() noexcept;

    public: group_token() = default;
    public: group_token(group_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_token const&) -> void = delete;


#line 2037 "cpp2regex.h2"
};

#line 2040 "cpp2regex.h2"
//  Regex syntax: \x<number> or \x{<number>}  Example: \x{62}
//
[[nodiscard]] auto hexadecimal_token_parse(parse_context& ctx) -> token_ptr;

#line 2081 "cpp2regex.h2"
//  Regex syntax: $  Example: aa$
//
[[nodiscard]] auto line_end_token_parse(parse_context& ctx) -> token_ptr;

#line 2100 "cpp2regex.h2"
template<typename CharT, bool match_new_line, bool match_new_line_before_end> [[nodiscard]] auto line_end_token_matcher(auto const& cur, auto& ctx) -> bool;

#line 2114 "cpp2regex.h2"
//  Regex syntax: ^  Example: ^aa
//
[[nodiscard]] auto line_start_token_parse(parse_context& ctx) -> token_ptr;

#line 2129 "cpp2regex.h2"
template<typename CharT, bool match_new_line> [[nodiscard]] auto line_start_token_matcher(auto const& cur, auto& ctx) -> bool;

#line 2136 "cpp2regex.h2"
//  Regex syntax: (?=) or (?!) or (*pla), etc.  Example: (?=AA)
//
//  Parsed in group_token.
//
class lookahead_token
: public regex_token {

#line 2144 "cpp2regex.h2"
    protected: bool positive; 
    public:   token_ptr inner {nullptr}; 

    public: explicit lookahead_token(cpp2::impl::in<bool> positive_);

#line 2151 "cpp2regex.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 2157 "cpp2regex.h2"
    public: auto add_groups(std::set<int>& groups) const -> void override;
    public: virtual ~lookahead_token() noexcept;

    public: lookahead_token(lookahead_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(lookahead_token const&) -> void = delete;


#line 2160 "cpp2regex.h2"
};

template<typename CharT, bool positive> [[nodiscard]] auto lookahead_token_matcher(auto const& cur, auto& ctx, auto const& func) -> bool;

#line 2173 "cpp2regex.h2"
// Named character classes
//
[[nodiscard]] auto named_class_token_parse(parse_context& ctx) -> token_ptr;

#line 2201 "cpp2regex.h2"
template                    <typename CharT,          bool case_insensitive> using named_class_no_new_line = class_token_matcher<CharT,true,case_insensitive,single_class_entry<CharT,'\n'>>;
template                    <typename CharT,          bool case_insensitive> using named_class_digits = class_token_matcher<CharT,false,case_insensitive,digits_class<CharT>>;
template                    <typename CharT,          bool case_insensitive> using named_class_hor_space = class_token_matcher<CharT,false,case_insensitive,hor_space_class<CharT>>;
template                    <typename CharT,          bool case_insensitive> using named_class_space = class_token_matcher<CharT,false,case_insensitive,space_class<CharT>>;
template                    <typename CharT,          bool case_insensitive> using named_class_ver_space = class_token_matcher<CharT,false,case_insensitive,ver_space_class<CharT>>;
template                    <typename CharT,          bool case_insensitive> using named_class_word = class_token_matcher<CharT,false,case_insensitive,word_class<CharT>>;

template                    <typename CharT,          bool case_insensitive> using named_class_not_digits = class_token_matcher<CharT,true,case_insensitive,digits_class<CharT>>;
template                    <typename CharT,          bool case_insensitive> using named_class_not_hor_space = class_token_matcher<CharT,true,case_insensitive,hor_space_class<CharT>>;
template                    <typename CharT,          bool case_insensitive> using named_class_not_space = class_token_matcher<CharT,true,case_insensitive,space_class<CharT>>;
template                    <typename CharT,          bool case_insensitive> using named_class_not_ver_space = class_token_matcher<CharT,true,case_insensitive,ver_space_class<CharT>>;
template                    <typename CharT,          bool case_insensitive> using named_class_not_word = class_token_matcher<CharT,true,case_insensitive,word_class<CharT>>;

#line 2215 "cpp2regex.h2"
//  Regex syntax: \o{<number>}  Example: \o{142}
//
[[nodiscard]] auto octal_token_parse(parse_context& ctx) -> token_ptr;

#line 2242 "cpp2regex.h2"
// TODO: @enum as template parameter currently not working. See issue https://github.com/hsutter/cppfront/issues/1147

#line 2245 "cpp2regex.h2"
//  Options for range matching.
class range_flags {
    public: static const int not_greedy;// Try to take as few as possible.
    public: static const int greedy;// Try to take as many as possible.
    public: static const int possessive;// Do not give back after a greedy match. No backtracking.

    public: range_flags() = default;
    public: range_flags(range_flags const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_flags const&) -> void = delete;
};
#line 2251 "cpp2regex.h2"

#line 2253 "cpp2regex.h2"
//  Regex syntax: <matcher>{min, max}  Example: a{2,4}
//
class range_token
: public regex_token {

#line 2259 "cpp2regex.h2"
              protected: int min_count {-1}; 
              protected: int max_count {-1}; 
              protected: int kind {range_flags::greedy}; 
              protected: token_ptr inner_token {nullptr}; 

    public: explicit range_token();

    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 2339 "cpp2regex.h2"
    public: auto parse_modifier(parse_context& ctx) & -> void;

#line 2351 "cpp2regex.h2"
    public: [[nodiscard]] auto gen_mod_string() const& -> std::string;

#line 2364 "cpp2regex.h2"
    public: [[nodiscard]] auto gen_range_string() const& -> std::string;

#line 2383 "cpp2regex.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 2394 "cpp2regex.h2"
    public: auto add_groups(std::set<int>& groups) const -> void override;
    public: virtual ~range_token() noexcept;

    public: range_token(range_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_token const&) -> void = delete;


#line 2398 "cpp2regex.h2"
};

#line 2401 "cpp2regex.h2"
template<typename CharT, int min_count, int max_count, int kind> class range_token_matcher
 {

    public: template<typename Iter> [[nodiscard]] static auto match(Iter const& cur, auto& ctx, auto const& inner, auto const& reset_func, auto const& end_func, auto const& tail) -> auto;

#line 2417 "cpp2regex.h2"
    private: [[nodiscard]] static auto is_below_upper_bound(cpp2::impl::in<int> count) -> bool;

#line 2422 "cpp2regex.h2"
    private: [[nodiscard]] static auto is_below_lower_bound(cpp2::impl::in<int> count) -> bool;

#line 2427 "cpp2regex.h2"
    private: [[nodiscard]] static auto is_in_range(cpp2::impl::in<int> count) -> bool;

#line 2433 "cpp2regex.h2"
    private: template<typename Iter> [[nodiscard]] static auto match_min_count(Iter const& cur, auto& ctx, auto const& inner, auto const& end_func, int& count_r) -> auto;

#line 2449 "cpp2regex.h2"
    private: template<typename Iter> [[nodiscard]] static auto match_greedy(cpp2::impl::in<int> count, Iter const& cur, Iter const& last_valid, auto& ctx, auto const& inner, auto const& reset_func, auto const& end_func, auto const& other) -> match_return<Iter>;

#line 2479 "cpp2regex.h2"
    private: template<typename Iter> [[nodiscard]] static auto match_possessive(Iter const& cur, auto& ctx, auto const& inner, auto const& end_func, auto const& other) -> match_return<Iter>;

#line 2507 "cpp2regex.h2"
    private: template<typename Iter> [[nodiscard]] static auto match_not_greedy(Iter const& cur, auto& ctx, auto const& inner, auto const& end_func, auto const& other) -> match_return<Iter>;
    public: range_token_matcher() = default;
    public: range_token_matcher(range_token_matcher const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_token_matcher const&) -> void = delete;


#line 2533 "cpp2regex.h2"
};

#line 2536 "cpp2regex.h2"
//  Regex syntax: *, +, or ?  Example: aa*
//
class special_range_token
: public range_token {

#line 2542 "cpp2regex.h2"
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;
    public: virtual ~special_range_token() noexcept;

    public: special_range_token() = default;
    public: special_range_token(special_range_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(special_range_token const&) -> void = delete;


#line 2572 "cpp2regex.h2"
};

#line 2575 "cpp2regex.h2"
//  Regex syntax: \b or \B  Example: \bword\b
//
//  Matches the start end end of word boundaries.
//
[[nodiscard]] auto word_boundary_token_parse(parse_context& ctx) -> token_ptr;

#line 2596 "cpp2regex.h2"
template<typename CharT, bool negate> [[nodiscard]] auto word_boundary_token_matcher(auto& cur, auto& ctx) -> bool;

#line 2621 "cpp2regex.h2"
//-----------------------------------------------------------------------
//
//  Regular expression implementation.
//
//-----------------------------------------------------------------------
//

//  Regular expression implementation
template<typename CharT, typename matcher_wrapper> class regular_expression
 {
    public: template<typename Iter> using matcher = matcher_wrapper_type<matcher_wrapper,Iter,CharT>;// TODO: Remove when nested types are allowed: https://github.com/hsutter/cppfront/issues/727
    public: template<typename Iter> using context = matcher_context_type<matcher<Iter>>;// TODO: Remove when nested types are allowed: https://github.com/hsutter/cppfront/issues/727

    public: template<typename Iter> class search_return
     {
        public: bool matched; 
        public: context<Iter> ctx; 
        public: int pos; 

        public: explicit search_return(cpp2::impl::in<bool> matched_, context<Iter> const& ctx_, Iter const& pos_);

#line 2646 "cpp2regex.h2"
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


#line 2662 "cpp2regex.h2"
    };

    public: [[nodiscard]] auto match(cpp2::impl::in<bview<CharT>> str) const& -> auto;
    public: [[nodiscard]] auto match(cpp2::impl::in<bview<CharT>> str, auto const& start) const& -> auto;
    public: [[nodiscard]] auto match(cpp2::impl::in<bview<CharT>> str, auto const& start, auto const& length) const& -> auto;
    public: template<typename Iter> [[nodiscard]] auto match(Iter const& start, Iter const& end) const& -> search_return<Iter>;

#line 2675 "cpp2regex.h2"
    public: [[nodiscard]] auto search(cpp2::impl::in<bview<CharT>> str) const& -> auto;
    public: [[nodiscard]] auto search(cpp2::impl::in<bview<CharT>> str, auto const& start) const& -> auto;
    public: [[nodiscard]] auto search(cpp2::impl::in<bview<CharT>> str, auto const& start, auto const& length) const& -> auto;
    public: template<typename Iter> [[nodiscard]] auto search(Iter const& start, Iter const& end) const& -> search_return<Iter>;

#line 2698 "cpp2regex.h2"
    public: [[nodiscard]] auto to_string() const& -> auto;

    //  Helper functions
    //
    private: [[nodiscard]] static auto get_iter(cpp2::impl::in<bview<CharT>> str, auto const& pos) -> auto;
    public: regular_expression() = default;
    public: regular_expression(regular_expression const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regular_expression const&) -> void = delete;


#line 2710 "cpp2regex.h2"
};

#line 2713 "cpp2regex.h2"
//-----------------------------------------------------------------------
//
//  Parser for regular expression.
//
//-----------------------------------------------------------------------
//

//  Parser and generator for regular expressions.
template<typename Error_out> class regex_generator
 {
    private: std::string_view regex; 
    private: std::string modifier {""}; 
    private: std::string modifier_escape {""}; 

    private: Error_out error_out; 

    private: std::string source {""}; 

    public: explicit regex_generator(cpp2::impl::in<std::string_view> r, Error_out const& e);

#line 2736 "cpp2regex.h2"
    public: [[nodiscard]] auto parse() & -> std::string;

#line 2771 "cpp2regex.h2"
    private: auto extract_modifiers() & -> void;
    public: regex_generator(regex_generator const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_generator const&) -> void = delete;


#line 2785 "cpp2regex.h2"
};

template<typename Err> [[nodiscard]] auto generate_regex(cpp2::impl::in<std::string_view> regex, Err const& err) -> std::string;

#line 2795 "cpp2regex.h2"
}
}


#endif

#line 1 "cpp2regex.h2"

//=== Cpp2 function definitions =================================================

#line 1 "cpp2regex.h2"

#line 30 "cpp2regex.h2"
namespace cpp2 {

namespace regex {


constexpr expression_flags::expression_flags(cpp2::impl::in<cpp2::i64> _val)
                                                          : _value{ cpp2::unsafe_narrow<cpp2::u8>(_val) } {  }

constexpr auto expression_flags::operator=(cpp2::impl::in<cpp2::i64> _val) -> expression_flags&  { 
                                                          _value = cpp2::unsafe_narrow<cpp2::u8>(_val);
                                                          return *this; }
constexpr auto expression_flags::operator|=(expression_flags const& that) & -> void { _value |= that._value; }
constexpr auto expression_flags::operator&=(expression_flags const& that) & -> void { _value &= that._value; }
constexpr auto expression_flags::operator^=(expression_flags const& that) & -> void { _value ^= that._value; }
[[nodiscard]] constexpr auto expression_flags::operator|(expression_flags const& that) const& -> expression_flags { return _value | that._value; }
[[nodiscard]] constexpr auto expression_flags::operator&(expression_flags const& that) const& -> expression_flags { return _value & that._value; }
[[nodiscard]] constexpr auto expression_flags::operator^(expression_flags const& that) const& -> expression_flags { return _value ^ that._value; }
[[nodiscard]] constexpr auto expression_flags::has(expression_flags const& that) const& -> bool { return _value & that._value; }
constexpr auto expression_flags::set(expression_flags const& that) & -> void { _value |= that._value; }
constexpr auto expression_flags::clear(expression_flags const& that) & -> void { _value &= ~that._value; }
inline CPP2_CONSTEXPR expression_flags expression_flags::case_insensitive{ 1 };

inline CPP2_CONSTEXPR expression_flags expression_flags::multiple_lines{ 2 };

inline CPP2_CONSTEXPR expression_flags expression_flags::single_line{ 4 };

inline CPP2_CONSTEXPR expression_flags expression_flags::no_group_captures{ 8 };

inline CPP2_CONSTEXPR expression_flags expression_flags::perl_code_syntax{ 16 };

inline CPP2_CONSTEXPR expression_flags expression_flags::perl_code_syntax_in_classes{ 32 };

inline CPP2_CONSTEXPR expression_flags expression_flags::none{ 0 };

[[nodiscard]] constexpr auto expression_flags::get_raw_value() const& -> cpp2::u8 { return _value; }
constexpr expression_flags::expression_flags()
                                        : _value{ none._value }{}
constexpr expression_flags::expression_flags(expression_flags const& that)
                                              : _value{ that._value }{}
constexpr auto expression_flags::operator=(expression_flags const& that) -> expression_flags& {
                                              _value = that._value;
                                              return *this;}
constexpr expression_flags::expression_flags(expression_flags&& that) noexcept
                                              : _value{ std::move(that)._value }{}
constexpr auto expression_flags::operator=(expression_flags&& that) noexcept -> expression_flags& {
                                              _value = std::move(that)._value;
                                              return *this;}
[[nodiscard]] auto expression_flags::to_string() const& -> std::string{

std::string _ret {"("}; 

std::string _comma {}; 
if ((*this) == none) {return "(none)"; }
if (((*this) & case_insensitive) == case_insensitive) {_ret += _comma + "case_insensitive";_comma = ", ";}
if (((*this) & multiple_lines) == multiple_lines) {_ret += _comma + "multiple_lines";_comma = ", ";}
if (((*this) & single_line) == single_line) {_ret += _comma + "single_line";_comma = ", ";}
if (((*this) & no_group_captures) == no_group_captures) {_ret += _comma + "no_group_captures";_comma = ", ";}
if (((*this) & perl_code_syntax) == perl_code_syntax) {_ret += _comma + "perl_code_syntax";_comma = ", ";}
if (((*this) & perl_code_syntax_in_classes) == perl_code_syntax_in_classes) {_ret += _comma + "perl_code_syntax_in_classes";_comma = ", ";}
return cpp2::move(_ret) + ")"; 
}

template <typename Iter> match_group<Iter>::match_group(auto const& start_, auto const& end_, auto const& matched_)
                                                                 : start{ start_ }
                                                                 , end{ end_ }
                                                                 , matched{ matched_ }{}
template <typename Iter> match_group<Iter>::match_group(){}
template <typename Iter> match_return<Iter>::match_return(auto const& matched_, auto const& pos_)
                                                         : matched{ matched_ }
                                                         , pos{ pos_ }{}
template <typename Iter> match_return<Iter>::match_return(){}
#line 38 "cpp2regex.h2"
//-----------------------------------------------------------------------
//
//  Helper structures for the expression matching.
//
//-----------------------------------------------------------------------
//

//  Possible modifiers for a regular expression.
//

#line 49 "cpp2regex.h2"
                                  // mod: i
                                  // mod: m
                                  // mod: s
                                  // mod: n
                                  // mod: x
                                  // mod: xx

#line 57 "cpp2regex.h2"
//  Structure for storing group information.
//

#line 67 "cpp2regex.h2"
//  Return value for every matcher.
// 

#line 75 "cpp2regex.h2"
//  Modifiable state during matching.
//

#line 84 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> match_context<CharT,Iter,max_groups>::match_context(Iter const& begin_, Iter const& end_)
        : begin{ begin_ }
        , end{ end_ }{

#line 87 "cpp2regex.h2"
    }

#line 89 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> match_context<CharT,Iter,max_groups>::match_context(match_context const& that)
                                   : begin{ that.begin }
                                   , end{ that.end }
                                   , groups{ that.groups }{}
#line 89 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> auto match_context<CharT,Iter,max_groups>::operator=(match_context const& that) -> match_context& {
                                   begin = that.begin;
                                   end = that.end;
                                   groups = that.groups;
                                   return *this; }
#line 89 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> match_context<CharT,Iter,max_groups>::match_context(match_context&& that) noexcept
                                   : begin{ std::move(that).begin }
                                   , end{ std::move(that).end }
                                   , groups{ std::move(that).groups }{}
#line 89 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> auto match_context<CharT,Iter,max_groups>::operator=(match_context&& that) noexcept -> match_context& {
                                   begin = std::move(that).begin;
                                   end = std::move(that).end;
                                   groups = std::move(that).groups;
                                   return *this; }

    //  Getter and setter for groups
    //
#line 93 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> [[nodiscard]] auto match_context<CharT,Iter,max_groups>::get_group(auto const& group) const& -> auto { return CPP2_ASSERT_IN_BOUNDS(groups, get_group_idx(group));  }

#line 95 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> [[nodiscard]] auto match_context<CharT,Iter,max_groups>::get_group_end(auto const& group) const& -> int{
        auto idx {get_group_idx(group)}; 
        if (cpp2::impl::cmp_greater_eq(group,max_groups) || !(CPP2_ASSERT_IN_BOUNDS(groups, idx).matched)) {
            return 0; 
        }
        return cpp2::unsafe_narrow<int>(std::distance(begin, CPP2_ASSERT_IN_BOUNDS(groups, cpp2::move(idx)).end)); 
    }
#line 102 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> [[nodiscard]] auto match_context<CharT,Iter,max_groups>::get_group_start(auto const& group) const& -> int{
        auto idx {get_group_idx(group)}; 
        if (cpp2::impl::cmp_greater_eq(group,max_groups) || !(CPP2_ASSERT_IN_BOUNDS(groups, idx).matched)) {
            return 0; 
        }
        return cpp2::unsafe_narrow<int>(std::distance(begin, CPP2_ASSERT_IN_BOUNDS(groups, cpp2::move(idx)).start)); 
    }
#line 109 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> [[nodiscard]] auto match_context<CharT,Iter,max_groups>::get_group_string(auto const& group) const& -> std::string{
        auto idx {get_group_idx(group)}; 
        if (cpp2::impl::cmp_greater_eq(group,max_groups) || !(CPP2_ASSERT_IN_BOUNDS(groups, idx).matched)) {
            return ""; 
        }
        return std::string(CPP2_ASSERT_IN_BOUNDS(groups, idx).start, CPP2_ASSERT_IN_BOUNDS(groups, cpp2::move(idx)).end); 
    }

#line 117 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> auto match_context<CharT,Iter,max_groups>::set_group_end(auto const& group, auto const& pos) & -> void{
        auto idx {get_group_idx(group)}; 
        CPP2_ASSERT_IN_BOUNDS(groups, idx).end = pos;
        CPP2_ASSERT_IN_BOUNDS(groups, idx).matched = true;
    }

#line 123 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> auto match_context<CharT,Iter,max_groups>::set_group_invalid(auto const& group) & -> void{
        CPP2_ASSERT_IN_BOUNDS(groups, get_group_idx(group)).matched = false;
    }

#line 127 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> auto match_context<CharT,Iter,max_groups>::set_group_start(auto const& group, auto const& pos) & -> void{
        CPP2_ASSERT_IN_BOUNDS(groups, get_group_idx(group)).start = pos;
    }

#line 131 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> [[nodiscard]] auto match_context<CharT,Iter,max_groups>::size() const& -> auto { return max_groups;  }

    //  Misc functions
    //
#line 135 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> [[nodiscard]] auto match_context<CharT,Iter,max_groups>::fail() const& -> auto { return match_return<Iter>(false, end); }
#line 136 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> [[nodiscard]] auto match_context<CharT,Iter,max_groups>::pass(cpp2::impl::in<Iter> cur) const& -> auto { return match_return<Iter>(true, cur);  }

    //  Private functions
    //
#line 140 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> [[nodiscard]] auto match_context<CharT,Iter,max_groups>::get_group_idx(auto const& group) const& -> size_t{
        if (cpp2::cpp2_default.is_active() && !(cpp2::impl::cmp_greater_eq(group,0)) ) { cpp2::cpp2_default.report_violation(""); }
        return cpp2::impl::as_<size_t>(group); 
    }

#line 147 "cpp2regex.h2"
//  End function that returns a valid match.
//

#line 151 "cpp2regex.h2"
    [[nodiscard]] auto true_end_func::operator()(auto const& cur, auto& ctx) const& -> auto { return ctx.pass(cur);  }

#line 155 "cpp2regex.h2"
//  Empty group reset function.
//

#line 159 "cpp2regex.h2"
    auto no_reset::operator()([[maybe_unused]] auto& unnamed_param_2) const& -> void{}

#line 163 "cpp2regex.h2"
//  Evaluate func on destruction of the handle.

#line 168 "cpp2regex.h2"
    template <typename Func> on_return<Func>::on_return(Func const& f)
        : func{ f }{

#line 170 "cpp2regex.h2"
    }
#line 168 "cpp2regex.h2"
    template <typename Func> auto on_return<Func>::operator=(Func const& f) -> on_return& {
        func = f;
        return *this;

#line 170 "cpp2regex.h2"
    }

#line 172 "cpp2regex.h2"
    template <typename Func> on_return<Func>::~on_return() noexcept{
        cpp2::move(*this).func();
    }

#line 178 "cpp2regex.h2"
//  Helper for auto deduction of the Func type.
#line 179 "cpp2regex.h2"
template<typename Func> [[nodiscard]] auto make_on_return(Func const& func) -> auto { return on_return<Func>(func);  }

#line 182 "cpp2regex.h2"
//-----------------------------------------------------------------------
//
//  Character classes for regular expressions.
//
//-----------------------------------------------------------------------
//

//  Class syntax: <any character> Example: a
//

#line 193 "cpp2regex.h2"
    template <typename CharT, CharT C> [[nodiscard]] auto single_class_entry<CharT,C>::includes(cpp2::impl::in<CharT> c) -> auto { return c == C;  }
#line 194 "cpp2regex.h2"
    template <typename CharT, CharT C> [[nodiscard]] auto single_class_entry<CharT,C>::to_string() -> auto { return bstring<CharT>(1, C); }

#line 198 "cpp2regex.h2"
//  Class syntax: - Example: a-c
//

#line 202 "cpp2regex.h2"
    template <typename CharT, CharT Start, CharT End> [[nodiscard]] auto range_class_entry<CharT,Start,End>::includes(cpp2::impl::in<CharT> c) -> auto { return [_0 = Start, _1 = c, _2 = End]{ return cpp2::impl::cmp_less_eq(_0,_1) && cpp2::impl::cmp_less_eq(_1,_2); }();  }
#line 203 "cpp2regex.h2"
    template <typename CharT, CharT Start, CharT End> [[nodiscard]] auto range_class_entry<CharT,Start,End>::to_string() -> auto { return "" + cpp2::to_string(Start) + "-" + cpp2::to_string(End) + ""; }

#line 207 "cpp2regex.h2"
//  Helper for combining two character classes
//

#line 211 "cpp2regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto combined_class_entry<CharT,List...>::includes(cpp2::impl::in<CharT> c) -> auto { return (false || ... || List::includes(c));  }
#line 212 "cpp2regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto combined_class_entry<CharT,List...>::to_string() -> auto { return (bstring<CharT>() + ... + List::to_string()); }

#line 216 "cpp2regex.h2"
//  Class syntax: <list of characters>  Example: abcd
//

#line 220 "cpp2regex.h2"
    template <typename CharT, CharT ...List> [[nodiscard]] auto list_class_entry<CharT,List...>::includes(cpp2::impl::in<CharT> c) -> auto { return (false || ... || (List == c));  }
#line 221 "cpp2regex.h2"
    template <typename CharT, CharT ...List> [[nodiscard]] auto list_class_entry<CharT,List...>::to_string() -> auto { return (bstring<CharT>() + ... + List); }

#line 225 "cpp2regex.h2"
//  Class syntax: [:<class name:]  Example: [:alnum:]
//

#line 229 "cpp2regex.h2"
    template <typename CharT, string_util::fixed_string Name, typename Inner> [[nodiscard]] auto named_class_entry<CharT,Name,Inner>::includes(cpp2::impl::in<CharT> c) -> auto { return Inner::includes(c);  }
#line 230 "cpp2regex.h2"
    template <typename CharT, string_util::fixed_string Name, typename Inner> [[nodiscard]] auto named_class_entry<CharT,Name,Inner>::to_string() -> auto { return "[:" + cpp2::to_string(Name.data()) + ":]"; }

#line 237 "cpp2regex.h2"
    template <typename CharT, typename Inner> [[nodiscard]] auto negated_class_entry<CharT,Inner>::includes(cpp2::impl::in<CharT> c) -> auto { return !(Inner::includes(c));  }

#line 241 "cpp2regex.h2"
//  Short class syntax: \<character>  Example: \w
//

#line 245 "cpp2regex.h2"
    template <typename CharT, string_util::fixed_string Name, typename Inner> [[nodiscard]] auto shorthand_class_entry<CharT,Name,Inner>::includes(cpp2::impl::in<CharT> c) -> auto { return Inner::includes(c);  }
#line 246 "cpp2regex.h2"
    template <typename CharT, string_util::fixed_string Name, typename Inner> [[nodiscard]] auto shorthand_class_entry<CharT,Name,Inner>::to_string() -> auto { return Name.str(); }

#line 250 "cpp2regex.h2"
//  Named basic character classes
//

#line 256 "cpp2regex.h2"
//  Named other classes
//

#line 272 "cpp2regex.h2"
// Shorthand class entries
//

#line 287 "cpp2regex.h2"
//-----------------------------------------------------------------------
//
//  Tokens for regular expressions.
//
//-----------------------------------------------------------------------
//

// Basic class for a regex token.
//

#line 300 "cpp2regex.h2"
    regex_token::regex_token(cpp2::impl::in<std::string> str)
        : string_rep{ str }{

#line 302 "cpp2regex.h2"
    }

#line 304 "cpp2regex.h2"
    regex_token::regex_token()
        : string_rep{ "" }{

#line 306 "cpp2regex.h2"
    }

    //parse: (inout ctx: parse_context) -> token_ptr;
                                                                       // Generate the matching code.

#line 311 "cpp2regex.h2"
    auto regex_token::add_groups([[maybe_unused]] std::set<int>& unnamed_param_2) const -> void{}// Adds all group indices to the set.
#line 312 "cpp2regex.h2"
    [[nodiscard]] auto regex_token::to_string() const& -> std::string{return string_rep; }// Create a string representation.
#line 313 "cpp2regex.h2"
    auto regex_token::set_string(cpp2::impl::in<std::string> s) & -> void{string_rep = s; }

    regex_token::~regex_token() noexcept{}// Set the string representation.

#line 328 "cpp2regex.h2"
    regex_token_check::regex_token_check(cpp2::impl::in<std::string> str, cpp2::impl::in<std::string> check_)
        : regex_token{ str }
        , check{ check_ }{

#line 331 "cpp2regex.h2"
    }

#line 333 "cpp2regex.h2"
    auto regex_token_check::generate_code(generation_context& ctx) const -> void{
        ctx.add_check(check + "(" + ctx.match_parameters() + ")");
    }

    regex_token_check::~regex_token_check() noexcept{}

#line 347 "cpp2regex.h2"
    regex_token_code::regex_token_code(cpp2::impl::in<std::string> str, cpp2::impl::in<std::string> code_)
        : regex_token{ str }
        , code{ code_ }{

#line 350 "cpp2regex.h2"
    }

#line 352 "cpp2regex.h2"
    auto regex_token_code::generate_code(generation_context& ctx) const -> void{
        ctx.add(code);
    }

    regex_token_code::~regex_token_code() noexcept{}

#line 364 "cpp2regex.h2"
    regex_token_empty::regex_token_empty(cpp2::impl::in<std::string> str)
        : regex_token{ str }{

#line 366 "cpp2regex.h2"
    }

#line 368 "cpp2regex.h2"
    auto regex_token_empty::generate_code([[maybe_unused]] generation_context& unnamed_param_2) const -> void{
        // Nothing.
    }

    regex_token_empty::~regex_token_empty() noexcept{}

#line 382 "cpp2regex.h2"
    regex_token_list::regex_token_list(cpp2::impl::in<token_vec> t)
        : regex_token{ gen_string(t) }
        , tokens{ t }{

#line 385 "cpp2regex.h2"
    }

#line 387 "cpp2regex.h2"
    auto regex_token_list::generate_code(generation_context& ctx) const -> void{
        for ( auto const& token : tokens ) {
            (*cpp2::impl::assert_not_null(token)).generate_code(ctx);
        }
    }

#line 393 "cpp2regex.h2"
    auto regex_token_list::add_groups(std::set<int>& groups) const -> void{
        for ( auto const& token : tokens ) {
            (*cpp2::impl::assert_not_null(token)).add_groups(groups);
        }
    }

#line 399 "cpp2regex.h2"
    [[nodiscard]] auto regex_token_list::gen_string(cpp2::impl::in<token_vec> vec) -> std::string{
        std::string r {""}; 
        for ( auto const& token : vec ) {
            r += (*cpp2::impl::assert_not_null(token)).to_string();
        }
        return r; 
    }

    regex_token_list::~regex_token_list() noexcept{}

#line 425 "cpp2regex.h2"
    auto parse_context_group_state::next_alternative() & -> void{
        token_vec new_list {}; 
        std::swap(new_list, cur_match_list);
        post_process_list(new_list);
        static_cast<void>(alternate_match_lists.insert(alternate_match_lists.end(), CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_list>)(cpp2::shared, cpp2::move(new_list))));
    }

#line 433 "cpp2regex.h2"
    auto parse_context_group_state::swap(parse_context_group_state& t) & -> void{
        std::swap(cur_match_list, t.cur_match_list);
        std::swap(alternate_match_lists, t.alternate_match_lists);
        std::swap(modifiers, t.modifiers);
    }

#line 440 "cpp2regex.h2"
    [[nodiscard]] auto parse_context_group_state::get_as_token() & -> token_ptr{
        if (alternate_match_lists.empty()) {
            post_process_list(cur_match_list);
            return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_list>)(cpp2::shared, cur_match_list); 
        }
        else {
            next_alternative();
            return CPP2_UFCS_TEMPLATE(cpp2_new<alternative_token_gen>)(cpp2::shared, alternate_match_lists); 
        }
    }

#line 452 "cpp2regex.h2"
    auto parse_context_group_state::add(cpp2::impl::in<token_ptr> token) & -> void{
        cur_match_list.push_back(token);
    }

#line 457 "cpp2regex.h2"
    [[nodiscard]] auto parse_context_group_state::empty() const& -> bool { return cur_match_list.empty();  }

#line 461 "cpp2regex.h2"
    auto parse_context_group_state::post_process_list(token_vec& list) -> void{
        // Merge all characters
        auto merge_pos {list.begin()}; 
        for( ; merge_pos != list.end(); (++merge_pos) ) {
            if (cpp2::impl::is<char_token>(*cpp2::impl::assert_not_null(*cpp2::impl::assert_not_null(merge_pos)))) {
                auto combine_pos {merge_pos + 1}; 
                while( combine_pos != list.end() && cpp2::impl::is<char_token>(*cpp2::impl::assert_not_null(*cpp2::impl::assert_not_null(combine_pos))) ) {// The erase advances combine_pos
                    (cpp2::impl::as_<char_token>(*cpp2::impl::assert_not_null(*cpp2::impl::assert_not_null(merge_pos)))).append(cpp2::impl::as_<char_token>(*cpp2::impl::assert_not_null(*cpp2::impl::assert_not_null(combine_pos))));
                    combine_pos = list.erase(combine_pos);
                }
            }
        }
    }

    parse_context_group_state::parse_context_group_state(auto const& cur_match_list_, auto const& alternate_match_lists_, auto const& modifiers_)
                                                                                              : cur_match_list{ cur_match_list_ }
                                                                                              , alternate_match_lists{ alternate_match_lists_ }
                                                                                              , modifiers{ modifiers_ }{}
parse_context_group_state::parse_context_group_state(){}

#line 487 "cpp2regex.h2"
    [[nodiscard]] auto parse_context_branch_reset_state::next() & -> int{
        auto g {cur_group}; 
        cur_group += 1;
        max_group = max(max_group, cur_group);

        return g; 
    }

#line 496 "cpp2regex.h2"
    auto parse_context_branch_reset_state::set_next(cpp2::impl::in<int> g) & -> void{
        cur_group = g;
        max_group = max(max_group, g);
    }

#line 502 "cpp2regex.h2"
    auto parse_context_branch_reset_state::next_alternative() & -> void{
        if (is_active) {
            cur_group = from;
        }
    }

#line 509 "cpp2regex.h2"
    auto parse_context_branch_reset_state::set_active_reset(cpp2::impl::in<int> restart) & -> void{
        is_active = true;
        cur_group = restart;
        from      = restart;
        max_group = restart;
    }

    parse_context_branch_reset_state::parse_context_branch_reset_state(auto const& is_active_, auto const& cur_group_, auto const& max_group_, auto const& from_)
                                                                                    : is_active{ is_active_ }
                                                                                    , cur_group{ cur_group_ }
                                                                                    , max_group{ max_group_ }
                                                                                    , from{ from_ }{}
parse_context_branch_reset_state::parse_context_branch_reset_state(){}

#line 537 "cpp2regex.h2"
    parse_context::parse_context(cpp2::impl::in<std::string_view> r, auto const& e)
        : regex{ r }
        , root{ CPP2_UFCS_TEMPLATE_NONLOCAL(cpp2_new<regex_token_empty>)(cpp2::shared, "") }
        , error_out{ e }{

#line 541 "cpp2regex.h2"
    }

#line 547 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::start_group() & -> parse_context_group_state
    {
        parse_context_group_state old_state {}; 
        old_state.swap(cur_group_state);
        cur_group_state.modifiers = old_state.modifiers;

        return old_state; 
    }

#line 557 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::end_group(cpp2::impl::in<parse_context_group_state> old_state) & -> token_ptr
    {
        auto inner {cur_group_state.get_as_token()}; 
        cur_group_state = old_state;
        return inner; 
    }

#line 564 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::get_modifiers() const& -> expression_flags{
        return cur_group_state.modifiers; 
    }

#line 568 "cpp2regex.h2"
    auto parse_context::set_modifiers(cpp2::impl::in<expression_flags> mod) & -> void{
        cur_group_state.modifiers = mod;
    }

#line 575 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::branch_reset_new_state() & -> parse_context_branch_reset_state
    {
        parse_context_branch_reset_state old_state {}; 
        std::swap(old_state, cur_branch_reset_state);

        cur_branch_reset_state.set_active_reset(old_state.cur_group);
        return old_state; 
    }

#line 584 "cpp2regex.h2"
    auto parse_context::branch_reset_restore_state(cpp2::impl::in<parse_context_branch_reset_state> old_state) & -> void
    {
        auto max_group {cur_branch_reset_state.max_group}; 
        cur_branch_reset_state = old_state;
        cur_branch_reset_state.set_next(cpp2::move(max_group));
    }

#line 591 "cpp2regex.h2"
    auto parse_context::next_alternative() & -> void
    {
        cur_group_state.next_alternative();
        cur_branch_reset_state.next_alternative();
    }

#line 599 "cpp2regex.h2"
    auto parse_context::add_token(cpp2::impl::in<token_ptr> token) & -> void{
        cur_group_state.add(token);
    }

#line 603 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::has_token() const& -> bool{
        return !(cur_group_state.empty()); 
    }

#line 607 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::pop_token() & -> token_ptr
    {
        token_ptr r {nullptr}; 
        if (has_token()) {
            r = cur_group_state.cur_match_list.back();
            cur_group_state.cur_match_list.pop_back();
        }

        return r; 
    }

#line 618 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::get_as_token() & -> token_ptr{
        return root; 
    }

#line 624 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::get_cur_group() const& -> int{
        return cur_branch_reset_state.cur_group; 
    }

#line 628 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::next_group() & -> int{
        return cur_branch_reset_state.next(); 
    }

#line 632 "cpp2regex.h2"
    auto parse_context::set_named_group(cpp2::impl::in<std::string> name, cpp2::impl::in<int> id) & -> void
    {
        if (!(named_groups.contains(name))) {// Redefinition of group name is not an error. The left most one is retained.
            CPP2_ASSERT_IN_BOUNDS(named_groups, name) = id;
        }
    }

#line 639 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::get_named_group(cpp2::impl::in<std::string> name) const& -> int
    {
        auto iter {named_groups.find(name)}; 
        if (iter == named_groups.end()) {
             return -1; 
        }
        else {
            return (*cpp2::impl::assert_not_null(cpp2::move(iter))).second; 
        }
    }

#line 652 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::current() const& -> char{return CPP2_ASSERT_IN_BOUNDS(regex, pos); }

#line 655 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::get_next_position(cpp2::impl::in<bool> in_class, cpp2::impl::in<bool> no_skip) const& -> size_t
    {
        auto perl_syntax {false}; 
        if (!(no_skip)) {
            if (in_class) {
                perl_syntax = get_modifiers().has(expression_flags::perl_code_syntax) && get_modifiers().has(expression_flags::perl_code_syntax_in_classes);
            }
            else {
                perl_syntax = get_modifiers().has(expression_flags::perl_code_syntax);
            }
        }
        auto cur {pos + 1}; 
        if (cpp2::move(perl_syntax)) {
            for( ; cpp2::impl::cmp_less(cur,regex.size()); (cur += 1) ) {
                auto n {CPP2_ASSERT_IN_BOUNDS(regex, cur)}; 

                if (space_class<char>::includes(n)) {
                    continue;
                }
                else {if (!(in_class) && '#' == cpp2::move(n)) {
                    cur = regex.find("\n", cur);
                    if (std::string::npos == cur) {
                        // No new line, comment runs until the end of the pattern
                        cur = regex.size();
                    }
                }
                else { // None space none comment char
                    break;
                }}
            }
        }

        //  Check for end of file.
        if (cpp2::impl::cmp_greater(cur,regex.size())) {
            cur = regex.size();
        }
        return cur; 
    }

#line 695 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::next_impl(cpp2::impl::in<bool> in_class, cpp2::impl::in<bool> no_skip) & -> bool
    {
        pos = get_next_position(in_class, no_skip);
        if (pos != regex.size()) {
            return true; 
        }
        else {
            return false; 
        }
    }

#line 706 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::next() & -> auto { return next_impl(false, false); }
#line 707 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::next_in_class() & -> auto { return next_impl(true, false);  }
#line 708 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::next_no_skip() & -> auto { return next_impl(false, true); }

#line 710 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::next_n(cpp2::impl::in<int> n) & -> bool{
        auto r {true}; 
        auto cur {0}; 
        for( ; r && cpp2::impl::cmp_less(cur,n); (r = next()) ) {
            cur += 1;
        }
        return r; 
    }

#line 719 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::has_next() const& -> bool{return cpp2::impl::cmp_less(pos,regex.size()); }

#line 721 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::grab_until_impl(cpp2::impl::in<std::string> e, cpp2::impl::out<std::string> r, cpp2::impl::in<bool> any) & -> bool
    {
        auto end {pos}; 
        if (any) {
            end = regex.find_first_of(e, pos);
        }
        else {
            end = regex.find(e, pos);
        }

        if (end != std::string_view::npos) {
            r.construct(regex.substr(pos, end - pos));
            pos = cpp2::move(end);
            return true; 
        }
        else {
            r.construct("");
            return false; 
        }
    }

#line 742 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::grab_until(cpp2::impl::in<std::string> e, cpp2::impl::out<std::string> r) & -> auto { return grab_until_impl(e, cpp2::impl::out(&r), false); }
#line 743 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::grab_until(cpp2::impl::in<char> e, cpp2::impl::out<std::string> r) & -> auto { return grab_until_impl(std::string(1, e), cpp2::impl::out(&r), false); }
#line 744 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::grab_until_one_of(cpp2::impl::in<std::string> e, cpp2::impl::out<std::string> r) & -> auto { return grab_until_impl(e, cpp2::impl::out(&r), true);  }

#line 746 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::grab_n(cpp2::impl::in<int> n, cpp2::impl::out<std::string> r) & -> bool
    {
        if (cpp2::impl::cmp_less_eq(pos + cpp2::impl::as_<size_t>(n),regex.size())) {
            r.construct(regex.substr(pos, cpp2::impl::as_<size_t>(n)));
            pos += (cpp2::impl::as_<size_t>(n)) - 1;
            return true; 
        }
        else {
            r.construct("");
            return false; 
        }
    }

#line 759 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::grab_number() & -> std::string
    {
        auto start {pos}; 
        auto start_search {pos}; 
        if (CPP2_ASSERT_IN_BOUNDS(regex, start_search) == '-') {
            start_search += 1;
        }
        auto end {regex.find_first_not_of("1234567890", cpp2::move(start_search))}; 

        cpp2::impl::deferred_init<std::string> r; 
        if (end != std::string::npos) {
            r.construct(regex.substr(start, end - start));
            pos = cpp2::move(end) - 1;
        }
        else {
            r.construct(regex.substr(cpp2::move(start)));
            pos = regex.size() - 1;
        }
        return cpp2::move(r.value()); 
    }

#line 780 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::peek_impl(cpp2::impl::in<bool> in_class) const& -> char{
        auto next_pos {get_next_position(in_class, false)}; 
        if (cpp2::impl::cmp_less(next_pos,regex.size())) {
            return CPP2_ASSERT_IN_BOUNDS(regex, cpp2::move(next_pos)); 
        }
        else {
            return '\0'; 
        }
    }

#line 790 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::peek() const& -> auto { return peek_impl(false); }
#line 791 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::peek_in_class() const& -> auto { return peek_impl(true);  }

#line 796 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::parser_group_modifiers(cpp2::impl::in<std::string> change_str, expression_flags& parser_modifiers) & -> bool
    {
        auto is_negative {false}; 
        auto is_reset {false}; 

        auto apply {[&, _1 = (&is_negative), _2 = (&parser_modifiers)](cpp2::impl::in<expression_flags> flag) mutable -> void{
            if (*cpp2::impl::assert_not_null(_1)) {
                (*cpp2::impl::assert_not_null(_2)).clear(flag);
            }
            else {
                (*cpp2::impl::assert_not_null(_2)).set(flag);
            }
        }}; 

        auto iter {change_str.begin()}; 
        for( ; iter != change_str.end(); (++iter) ) 
        {
            auto cur {*cpp2::impl::assert_not_null(iter)}; 
            if (cur == '^') {
                is_reset = true;
                parser_modifiers = expression_flags::none;
            }
            else {if (cur == '-') {
                if (is_reset) {static_cast<void>(error("No negative modifier allowed.")); return false; }
                is_negative = true;
            }
            else {if (cur == 'i') {apply(expression_flags::case_insensitive); }
            else {if (cur == 'm') {apply(expression_flags::multiple_lines); }
            else {if (cur == 's') {apply(expression_flags::single_line); }
            else {if (cur == 'n') {apply(expression_flags::no_group_captures); }
            else {if (cur == 'x') {
                if ((iter + 1) == change_str.end() || *cpp2::impl::assert_not_null((iter + 1)) != 'x') {
                    // x modifier
                    apply(expression_flags::perl_code_syntax);

                    // Just x unsets xx and remove x also removes xx
                    parser_modifiers.clear(expression_flags::perl_code_syntax_in_classes);
                }
                else { // xx modifier
                    // xx also sets or unsets x
                    apply(expression_flags::perl_code_syntax);
                    apply(expression_flags::perl_code_syntax_in_classes);

                    ++iter; // Skip the second x
                }
            }
            else {
                static_cast<void>(error("Unknown modifier: " + cpp2::to_string(cpp2::move(cur)) + "")); return false; 
            }}}}}}}
        }

        return true; 
    }

#line 850 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::parse_until(cpp2::impl::in<char> term) & -> bool{
        token_ptr cur_token {}; 

        for( ; valid(); static_cast<void>(next()) ) 
        {
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

#line 888 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::parse(cpp2::impl::in<std::string> modifiers) & -> bool
    {

        expression_flags flags {}; 
        if (!(parser_group_modifiers(modifiers, flags))) {return false; }
        set_modifiers(cpp2::move(flags));

        auto r {parse_until('\0')}; 
        if (r) {
            root = cur_group_state.get_as_token();
        }

        return r; 
    }

#line 905 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::get_pos() const& -> auto { return pos; }
#line 906 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::get_range(cpp2::impl::in<size_t> start, cpp2::impl::in<size_t> end) const& -> auto { return std::string(regex.substr(start, end - start + 1));  }
#line 907 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::valid() const& -> bool{return has_next() && !(has_error); }

#line 909 "cpp2regex.h2"
    [[nodiscard]] auto parse_context::error(cpp2::impl::in<std::string> err) & -> token_ptr{
        has_error = true;
        error_out("Error during parsing of regex '" + cpp2::to_string(regex) + "' at position '" + cpp2::to_string(pos) + "': " + cpp2::to_string(err) + "");
        return nullptr; 
    }

#line 924 "cpp2regex.h2"
    auto generation_function_context::add_tabs(cpp2::impl::in<int> c) & -> void{
        int i {0}; 
        for( ; cpp2::impl::cmp_less(i,c); i += 1 ) {
            tabs += "  ";
        }
    }

#line 931 "cpp2regex.h2"
    auto generation_function_context::remove_tabs(cpp2::impl::in<int> c) & -> void{
        tabs = tabs.substr(0, (cpp2::impl::as_<size_t>(c)) * 2);
    }

    generation_function_context::generation_function_context(auto const& code_, auto const& tabs_)
                                                       : code{ code_ }
                                                       , tabs{ tabs_ }{}
generation_function_context::generation_function_context(){}

#line 949 "cpp2regex.h2"
    [[nodiscard]] auto generation_context::match_parameters() const& -> std::string{return "r.pos, ctx"; }

#line 954 "cpp2regex.h2"
    auto generation_context::add(cpp2::impl::in<std::string> s) & -> void{
        auto cur {get_current()}; 
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + cpp2::to_string(s) + "\n";
    }

#line 960 "cpp2regex.h2"
    auto generation_context::add_check(cpp2::impl::in<std::string> check) & -> void{
        auto cur {get_current()}; 
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "if !cpp2::regex::" + cpp2::to_string(check) + " { r.matched = false; break; }\n";
    }

#line 966 "cpp2regex.h2"
    auto generation_context::add_statefull(cpp2::impl::in<std::string> next_func, cpp2::impl::in<std::string> check) & -> void
    {
        end_func_statefull(check);

        auto name {next_func.substr(0, next_func.size() - 2)}; 
        start_func_named(cpp2::move(name));
    }

#line 974 "cpp2regex.h2"
    auto generation_context::start_func_named(cpp2::impl::in<std::string> name) & -> void
    {
        auto cur {new_context()}; 

        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + cpp2::to_string(name) + ": @struct type = {\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "  operator(): (this, cur: Iter, inout ctx: context, other) -> cpp2::regex::match_return<Iter> = {\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "    r := ctx..pass(cur);\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "    do {\n";
        (*cpp2::impl::assert_not_null(cpp2::move(cur))).add_tabs(3);
    }

#line 985 "cpp2regex.h2"
    [[nodiscard]] auto generation_context::start_func() & -> std::string
    {
        auto name {gen_func_name()}; 
        start_func_named(name);
        return cpp2::move(name) + "()"; 
    }

#line 992 "cpp2regex.h2"
    auto generation_context::end_func_statefull(cpp2::impl::in<std::string> s) & -> void
    {
        auto cur {get_current()}; 
        (*cpp2::impl::assert_not_null(cur)).remove_tabs(3);
        (*cpp2::impl::assert_not_null(cur)).code += "\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "    } while false;\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "    if r.matched {\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "      r = " + cpp2::to_string(s) + ";\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "    }\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "    else {\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "      r.pos = ctx.end;\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "    }\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "    return r;\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "  }\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "}\n";

        finish_context();
    }

#line 1012 "cpp2regex.h2"
    [[nodiscard]] auto generation_context::generate_func(cpp2::impl::in<token_ptr> token) & -> std::string
    {
        auto name {start_func()}; 
        (*cpp2::impl::assert_not_null(token)).generate_code((*this));
        end_func_statefull("other(" + cpp2::to_string(match_parameters()) + ")");

        return name; 
    }

#line 1022 "cpp2regex.h2"
    [[nodiscard]] auto generation_context::generate_reset(cpp2::impl::in<std::set<int>> groups) & -> std::string
    {
        if (groups.empty()) {
            return "cpp2::regex::no_reset()"; 
        }

        auto name {gen_reset_func_name()}; 
        auto cur {new_context()}; 

        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + cpp2::to_string(name) + ": @struct type = {\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "  operator(): (this, inout ctx) = {\n";
        for ( auto const& g : groups ) {
            (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "  ctx..set_group_invalid(" + cpp2::to_string(g) + ");\n";
        }
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "  }\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "}\n";

        finish_context();

        return cpp2::move(name) + "()"; 
    }

#line 1046 "cpp2regex.h2"
    [[nodiscard]] auto generation_context::gen_func_name() & -> std::string{
        auto cur_id {matcher_func}; 
        matcher_func += 1;
        return "func_" + cpp2::to_string(cpp2::move(cur_id)) + ""; 
    }

#line 1052 "cpp2regex.h2"
    [[nodiscard]] auto generation_context::next_func_name() & -> std::string{
        return gen_func_name() + "()"; 
    }

#line 1056 "cpp2regex.h2"
    [[nodiscard]] auto generation_context::gen_reset_func_name() & -> std::string{
        auto cur_id {reset_func}; 
        reset_func += 1;
        return "reset_" + cpp2::to_string(cpp2::move(cur_id)) + ""; 
    }

#line 1062 "cpp2regex.h2"
    [[nodiscard]] auto generation_context::gen_temp() & -> std::string{
        auto cur_id {temp_name}; 
        temp_name += 1;
        return "tmp_" + cpp2::to_string(cpp2::move(cur_id)) + ""; 
    }

#line 1070 "cpp2regex.h2"
    [[nodiscard]] auto generation_context::new_context() & -> generation_function_context*{
        gen_stack.push_back(generation_function_context());
        auto cur {get_current()}; 
        (*cpp2::impl::assert_not_null(cur)).tabs = "    ";

        return cur; 
    }

#line 1078 "cpp2regex.h2"
    auto generation_context::finish_context() & -> void{
        auto cur {get_current()}; 
        auto base {get_base()}; 
        (*cpp2::impl::assert_not_null(base)).code += (*cpp2::impl::assert_not_null(cpp2::move(cur))).code;

        gen_stack.pop_back();
    }

#line 1088 "cpp2regex.h2"
    [[nodiscard]] auto generation_context::get_current() & -> generation_function_context*{
        return &gen_stack.back(); 
    }

#line 1092 "cpp2regex.h2"
    [[nodiscard]] auto generation_context::get_base() & -> generation_function_context*{
        return &CPP2_ASSERT_IN_BOUNDS_LITERAL(gen_stack, 0); 
    }

#line 1096 "cpp2regex.h2"
    [[nodiscard]] auto generation_context::get_entry_func() const& -> std::string{
        return entry_func; 
    }

#line 1100 "cpp2regex.h2"
    [[nodiscard]] auto generation_context::create_named_group_lookup(cpp2::impl::in<std::map<std::string,int>> named_groups) const& -> std::string
    {
        std::string res {"get_named_group_index: (name) -> int = {\n"}; 

        //  Generate if selection.
        std::string sep {""}; 
        for ( auto const& cur : named_groups ) {
            res += "" + cpp2::to_string(sep) + "if name == \"" + cpp2::to_string(cur.first) + "\" { return " + cpp2::to_string(cur.second) + "; }";
            sep = "else ";
        }

        //  Generate else branch or return if list is empty.
        if (named_groups.empty()) {
            res += "  _ = name;\n";
            res += "  return -1;\n";
        }
        else {
            res += "  else { return -1; }\n";
        }
        res += "}\n";
        return res; 
    }

#line 1125 "cpp2regex.h2"
    [[nodiscard]] auto generation_context::run(cpp2::impl::in<token_ptr> token) & -> std::string{
        entry_func = generate_func(token);

        return (*cpp2::impl::assert_not_null(get_base())).code; 
    }

#line 1141 "cpp2regex.h2"
    alternative_token::alternative_token()
                            : regex_token_empty{ "" }{}

#line 1143 "cpp2regex.h2"
    [[nodiscard]] auto alternative_token::parse(parse_context& ctx) -> token_ptr{
        if (ctx.current() != '|') {return nullptr; }

        if (!(ctx.has_token())) {return ctx.error("Alternative with no content."); }
        ctx.next_alternative();
        return CPP2_UFCS_TEMPLATE(cpp2_new<alternative_token>)(cpp2::shared); 
    }

    alternative_token::~alternative_token() noexcept{}

#line 1158 "cpp2regex.h2"
    alternative_token_gen::alternative_token_gen(cpp2::impl::in<token_vec> a)
        : regex_token{ gen_string(a) }
        , alternatives{ a }{

#line 1161 "cpp2regex.h2"
    }

#line 1163 "cpp2regex.h2"
    auto alternative_token_gen::generate_code(generation_context& ctx) const -> void
    {
        std::string functions {""}; 

        for ( auto const& cur : alternatives ) {
            std::set<int> groups {}; 
            (*cpp2::impl::assert_not_null(cur)).add_groups(groups);

            functions += ", " + ctx.generate_func(cur);
            functions += ", " + ctx.generate_reset(cpp2::move(groups));
        }

        auto next_name {ctx.next_func_name()}; 

        ctx.add_statefull(next_name, "cpp2::regex::alternative_token_matcher<char>::match(" + cpp2::to_string(ctx.match_parameters()) + ", other, " + cpp2::to_string(next_name) + " " + cpp2::to_string(cpp2::move(functions)) + ")");
    }

#line 1180 "cpp2regex.h2"
    auto alternative_token_gen::add_groups(std::set<int>& groups) const -> void
    {
        for ( auto const& cur : alternatives ) {
            (*cpp2::impl::assert_not_null(cur)).add_groups(groups);
        }
    }

#line 1187 "cpp2regex.h2"
    [[nodiscard]] auto alternative_token_gen::gen_string(cpp2::impl::in<token_vec> a) -> std::string
    {
        std::string r {""}; 
        std::string sep {""}; 

        for ( auto const& cur : a ) {
            r += sep + (*cpp2::impl::assert_not_null(cur)).to_string();
            sep = "|";
        }

        return r; 
    }

    alternative_token_gen::~alternative_token_gen() noexcept{}

#line 1204 "cpp2regex.h2"
    template <typename CharT> [[nodiscard]] auto alternative_token_matcher<CharT>::match(auto const& cur, auto& ctx, auto const& end_func, auto const& tail, auto const& ...functions) -> auto{
        return match_first(cur, ctx, end_func, tail, functions...); 
    }

#line 1208 "cpp2regex.h2"
    template <typename CharT> template<typename ...Other> [[nodiscard]] auto alternative_token_matcher<CharT>::match_first(auto const& cur, auto& ctx, auto const& end_func, auto const& tail, auto const& cur_func, auto const& cur_reset, Other const& ...other) -> auto
    {
        auto inner_call {[_0 = (tail), _1 = (end_func)](auto const& tail_cur, auto& tail_ctx) -> auto{
            return _0(tail_cur, tail_ctx, _1); 
        }}; 
        auto r {cur_func(cur, ctx, cpp2::move(inner_call))}; 
        if (r.matched) {
            return r; 
        }else {
            cur_reset(ctx);

            if constexpr (0 != sizeof...(Other)) {
                return match_first(cur, ctx, end_func, tail, other...); 
            }else {
                return ctx.fail(); 
            }
        }
    }

#line 1235 "cpp2regex.h2"
    any_token::any_token(cpp2::impl::in<bool> single_line)
        : regex_token_check{ ".", "any_token_matcher<char, " + cpp2::to_string(single_line) + ">" }{

#line 1237 "cpp2regex.h2"
    }

#line 1239 "cpp2regex.h2"
    [[nodiscard]] auto any_token::parse(parse_context& ctx) -> token_ptr{
        if ('.' != ctx.current()) {return nullptr; }

        return CPP2_UFCS_TEMPLATE(cpp2_new<any_token>)(cpp2::shared, ctx.get_modifiers().has(expression_flags::single_line)); 
    }

    any_token::~any_token() noexcept{}

#line 1247 "cpp2regex.h2"
template<typename CharT, bool single_line> [[nodiscard]] auto any_token_matcher(auto& cur, auto& ctx) -> bool
{
    if ( cur != ctx.end                     // any char except the end
        && (single_line || *cpp2::impl::assert_not_null(cur) != '\n')) // do not match new lines in multi line mode
    {
        cur += 1;
        return true; 
    }
    //  Else
    return false; 
}

#line 1269 "cpp2regex.h2"
    char_token::char_token(cpp2::impl::in<char> t, cpp2::impl::in<bool> ignore_case_)
        : regex_token{ std::string(1, t) }
        , token{ t }
        , ignore_case{ ignore_case_ }{

#line 1273 "cpp2regex.h2"
    }

#line 1275 "cpp2regex.h2"
    [[nodiscard]] auto char_token::parse(parse_context& ctx) -> token_ptr{
        return CPP2_UFCS_TEMPLATE(cpp2_new<char_token>)(cpp2::shared, ctx.current(), ctx.get_modifiers().has(expression_flags::case_insensitive)); 
    }

#line 1279 "cpp2regex.h2"
    auto char_token::generate_code(generation_context& ctx) const -> void
    {
        if (ignore_case) {
            std::string upper {token}; 
            std::string lower {token}; 
{
size_t i{0};

#line 1285 "cpp2regex.h2"
            for( ; cpp2::impl::cmp_less(i,token.size()); i += 1 ) {
                CPP2_ASSERT_IN_BOUNDS(lower, i) = string_util::safe_tolower(CPP2_ASSERT_IN_BOUNDS(token, i));
                CPP2_ASSERT_IN_BOUNDS(upper, i) = string_util::safe_toupper(CPP2_ASSERT_IN_BOUNDS(token, i));
            }
}

#line 1290 "cpp2regex.h2"
            if (upper != lower) {
                gen_case_insensitive(cpp2::move(lower), cpp2::move(upper), ctx);
            }
            else {
                gen_case_sensitive(ctx);
            }
        }
        else {
            gen_case_sensitive(ctx);
        }
    }

#line 1302 "cpp2regex.h2"
    auto char_token::gen_case_insensitive(cpp2::impl::in<std::string> lower, cpp2::impl::in<std::string> upper, generation_context& ctx) const& -> void
    {
        std::string name {"str_" + cpp2::to_string(ctx.gen_temp()) + ""}; 
        std::string lower_name {"lower_" + cpp2::to_string(name) + ""}; 
        std::string upper_name {"upper_" + cpp2::to_string(cpp2::move(name)) + ""}; 
        auto size {token.size()}; 
        ctx.add("" + cpp2::to_string(lower_name) + " : std::array<char, " + cpp2::to_string(size) + " + 1> = \"" + cpp2::to_string(add_escapes(lower)) + "\";");  // TODO: Add constexpr when Issue https://github.com/hsutter/cppfront/issues/1104 is resolved.
        ctx.add("" + cpp2::to_string(upper_name) + " : std::array<char, " + cpp2::to_string(size) + " + 1> = \"" + cpp2::to_string(add_escapes(upper)) + "\";");  // TODO: Add constexpr when Issue https://github.com/hsutter/cppfront/issues/1104 is resolved.
        ctx.add("if std::distance(r.pos, ctx.end) < " + cpp2::to_string(size) + " {");
        ctx.add("    r.matched = false;");
        ctx.add("    break;");
        ctx.add("}");
        ctx.add("");
        ctx.add("(copy i : int = 0) while i < " + cpp2::to_string(size) + " next (i += 1) {");
        ctx.add("    if !(" + cpp2::to_string(cpp2::move(lower_name)) + "[i] == r.pos[i] || " + cpp2::to_string(cpp2::move(upper_name)) + "[i] == r.pos[i]) { r.matched = false; }");
        ctx.add("}");
        ctx.add("");
        ctx.add("if r.matched { r.pos += " + cpp2::to_string(cpp2::move(size)) + "; }");
        ctx.add("else { break; }");
    }

#line 1323 "cpp2regex.h2"
    auto char_token::gen_case_sensitive(generation_context& ctx) const& -> void
    {
        std::string name {"str_" + cpp2::to_string(ctx.gen_temp()) + ""}; 
        auto size {token.size()}; 
        ctx.add("" + cpp2::to_string(name) + " : std::array<char, " + cpp2::to_string(size) + " + 1> = \"" + cpp2::to_string(add_escapes(token)) + "\";");  // TODO: Add constexpr when Issue https://github.com/hsutter/cppfront/issues/1104 is resolved.
        ctx.add("if std::distance(r.pos, ctx.end) < " + cpp2::to_string(size) + " {");
        ctx.add("    r.matched = false;");
        ctx.add("    break;");
        ctx.add("}");
        ctx.add("");
        ctx.add("(copy i : int = 0) while i < " + cpp2::to_string(size) + " next (i += 1) {");
        ctx.add("    if " + cpp2::to_string(cpp2::move(name)) + "[i] != r.pos[i] { r.matched = false; }");
        ctx.add("}");
        ctx.add("");
        ctx.add("if r.matched { r.pos += " + cpp2::to_string(cpp2::move(size)) + "; }");
        ctx.add("else { break; }");
    }

#line 1341 "cpp2regex.h2"
    [[nodiscard]] auto char_token::add_escapes(std::string str) const& -> std::string
    {
        str = string_util::replace_all(str, "\\", "\\\\");
        str = string_util::replace_all(str, "\a", "\\a");
        str = string_util::replace_all(str, "\f", "\\f");
        str = string_util::replace_all(str, "\x1b", "\" \"\\x1b\" \""); // Generate a separated string. This prevents
                                                                        // situations like `\x1bblub` from generating
                                                                        // wrong hex characters.
        str = string_util::replace_all(str, "\n", "\\n");
        str = string_util::replace_all(str, "\r", "\\r");
        str = string_util::replace_all(str, "\t", "\\t");

        return cpp2::move(str); 
    }

#line 1356 "cpp2regex.h2"
    auto char_token::append(char_token const& that) & -> void{
        (*this).token += that.token;
        (*this).string_rep += that.string_rep;
    }

    char_token::~char_token() noexcept{}

#line 1407 "cpp2regex.h2"
    class_token::class_token(cpp2::impl::in<bool> negate_, cpp2::impl::in<bool> case_insensitive_, cpp2::impl::in<std::string> class_str_, cpp2::impl::in<std::string> str)
        : regex_token{ str }
        , negate{ negate_ }
        , case_insensitive{ case_insensitive_ }
        , class_str{ class_str_ }
#line 1408 "cpp2regex.h2"
    {

#line 1413 "cpp2regex.h2"
    }

#line 1416 "cpp2regex.h2"
    [[nodiscard]] auto class_token::parse(parse_context& ctx) -> token_ptr
    {
        if (ctx.current() != '[') {return nullptr; }

        auto start_pos {ctx.get_pos()}; 

        std::vector<std::string> supported_classes {"alnum", "alpha", "ascii", "blank", "cntrl", "digits", "graph", 
                                                       "lower", "print", "punct", "space", "upper", "word", "xdigit"}; 

        std::vector<std::string> classes {}; 

        //  First step: parse until the end bracket and push single chars, ranges or groups on the class stack.
        auto is_negate {false}; 
        auto first {true}; 
        auto range {false}; 
        while( ctx.next_in_class() && (ctx.current() != ']' || first) ) 
        {
            if (ctx.current() == '^') 
            {
                is_negate = true;
                continue; // Skip rest of the loop. Also the first update.
            }

            if (ctx.current() == '[' && ctx.peek_in_class() == ':') 
            {
                //  We have a character class.
                static_cast<void>(ctx.next_n(2));// Skip [:

                std::string name {""}; 
                if (!(ctx.grab_until(":]", cpp2::impl::out(&name)))) {return ctx.error("Could not find end of character class."); }
                if (supported_classes.end() == std::find(supported_classes.begin(), supported_classes.end(), name)) {
                    return ctx.error("Unsupported character class. Supported ones are: " + cpp2::to_string(string_util::join(supported_classes)) + ""); 
                }

                classes.push_back("[:" + cpp2::to_string(cpp2::move(name)) + ":]");

                static_cast<void>(ctx.next());// Skip ':' pointing to the ending ']'.
            }
            else {if (ctx.current() == '\\') 
            {
                if (ctx. next_no_skip()  && (ctx. current() != ']')) 
                {
                    if ( ' ' == ctx. current() 
                        && ctx.get_modifiers().has(expression_flags::perl_code_syntax) 
                        && ctx.get_modifiers().has(expression_flags::perl_code_syntax_in_classes)) 
                    {
                        classes.push_back(std::string(1, ctx.current()));
                    }
                    else {
                        auto name {""}; 
                        if (     'd' == ctx. current()) { name = "short_digits"; }
                        else {if ('D' == ctx.current()) {name = "short_not_digits"; }
                        else {if ('h' == ctx.current()) {name = "short_hor_space"; }
                        else {if ('H' == ctx.current()) {name = "short_not_hor_space"; }
                        else {if ('s' == ctx.current()) {name = "short_space"; }
                        else {if ('S' == ctx.current()) {name = "short_not_space"; }
                        else {if ('v' == ctx.current()) {name = "short_ver_space"; }
                        else {if ('V' == ctx.current()) {name = "short_not_ver_space"; }
                        else {if ('w' == ctx.current()) {name = "short_word"; }
                        else {if ('W' == ctx.current()) {name = "short_not_word"; }
                        else {
                            return ctx.error("Unknown group escape."); 
                        }}}}}}}}}}
                        classes.push_back("[:" + cpp2::to_string(cpp2::move(name)) + ":]");
                    }
                }else {
                    return ctx.error("Escape without a following character."); 
                }
            }
            else {if (ctx.current() == '-') 
            {
                if (first) {// Literal if first entry.
                    classes.push_back("" + cpp2::to_string(ctx.current()) + "");
                }else {
                    range = true;
                }
            }
            else 
            {
                if (range) {// Modify last element to be a range.
                    classes.back() += "-" + cpp2::to_string(ctx.current()) + "";
                    range = false;
                }
                else {
                    classes.push_back("" + cpp2::to_string(ctx.current()) + "");
                }
            }}}

            first = false;
        }

        if (ctx.current() != ']') {
            return ctx.error("Error end of character class definition before terminating ']'."); 
        }
        auto end_pos {ctx.get_pos()}; 

        if (cpp2::move(range)) {// If '-' is last entry treat it as a literal char.
            classes.push_back("-");
        }

        // Second step: Wrap the item on the class stack with corresponding class implementation.
        for ( auto& cur : classes ) 
        {
            if (cur.starts_with("[:")) {
                auto name {cur.substr(2, cur.size() - 4)}; 
                cur = create_matcher("" + cpp2::to_string(cpp2::move(name)) + "_class", "");
            }
            else {if (1 != cur.size()) {
                cur = create_matcher("range_class_entry", "'" + cpp2::to_string(CPP2_ASSERT_IN_BOUNDS_LITERAL(cur, 0)) + "', '" + cpp2::to_string(CPP2_ASSERT_IN_BOUNDS_LITERAL(cur, 2)) + "'");
            }
            else {
                cur = create_matcher("single_class_entry", "'" + cpp2::to_string(cur) + "'");
            }}
        }

        auto inner {string_util::join(cpp2::move(classes))}; 
        auto string_rep {ctx.get_range(cpp2::move(start_pos), cpp2::move(end_pos))}; 
        return CPP2_UFCS_TEMPLATE(cpp2_new<class_token>)(cpp2::shared, 
            cpp2::move(is_negate), 
            ctx.get_modifiers().has(expression_flags::case_insensitive), 
            cpp2::move(inner), 
            cpp2::move(string_rep)
            ); 
    }

#line 1541 "cpp2regex.h2"
    auto class_token::generate_code(generation_context& ctx) const -> void
    {
        ctx.add_check("class_token_matcher<char, " + cpp2::to_string(negate) + ", " + cpp2::to_string(case_insensitive) + ", " + cpp2::to_string(class_str) + ">::match(" + cpp2::to_string(ctx.match_parameters()) + ")");
    }

#line 1546 "cpp2regex.h2"
    [[nodiscard]] auto class_token::create_matcher(cpp2::impl::in<std::string> name, cpp2::impl::in<std::string> template_arguments) -> std::string
    {
        auto sep {", "}; 
        if (template_arguments.empty()) {sep = ""; }

        return "::cpp2::regex::" + cpp2::to_string(name) + "<char" + cpp2::to_string(cpp2::move(sep)) + cpp2::to_string(template_arguments) + ">"; 
    }

    class_token::~class_token() noexcept{}

#line 1558 "cpp2regex.h2"
    template <typename CharT, bool negate, bool case_insensitive, typename ...List> [[nodiscard]] auto class_token_matcher<CharT,negate,case_insensitive,List...>::match(auto& cur, auto& ctx) -> bool
    {
        if constexpr (case_insensitive) 
        {
            if ( cur != ctx.end 
                && negate != (
                       match_any<List...>(string_util::safe_tolower(*cpp2::impl::assert_not_null(cur))) 
                    || match_any<List...>(string_util::safe_toupper(*cpp2::impl::assert_not_null(cur))))) 

            {
                cur += 1;
                return true; 
            }
            else {
                return false; 
            }
        }
        else 
        {
            if (cur != ctx.end && negate != match_any<List...>(*cpp2::impl::assert_not_null(cur))) {
                cur += 1;
                return true; 
            }
            else {
                return false; 
            }
        }
    }

#line 1587 "cpp2regex.h2"
    template <typename CharT, bool negate, bool case_insensitive, typename ...List> template<typename First, typename ...Other> [[nodiscard]] auto class_token_matcher<CharT,negate,case_insensitive,List...>::match_any(cpp2::impl::in<CharT> c) -> bool
    {
        bool r {First::includes(c)}; 

        if (!(r)) {
            if constexpr (0 != sizeof...(Other)) {
                r = match_any<Other...>(c);
            }
        }

        return r; 
    }

#line 1616 "cpp2regex.h2"
[[nodiscard]] auto escape_token_parse(parse_context& ctx) -> token_ptr
{
    if (ctx.current() != '\\') {return nullptr; }

#line 1621 "cpp2regex.h2"
    if (std::string::npos == std::string("afenrt^.[]()*{}?+|\\").find(ctx.peek())) {
        return nullptr; 
    }

    static_cast<void>(ctx.next());// Skip escape

    if (std::string::npos != std::string("afenrt\\").find(ctx.current())) 
    {
        // Escape of string special char
        char t {'\0'}; 
        if (     'a' == ctx. current()) { t = '\a'; }
        else {if ('f' == ctx.current()) {t = '\f'; }
        else {if ('e' == ctx.current()) {t = '\x1b'; }
        else {if ('n' == ctx.current()) {t = '\n'; }
        else {if ('r' == ctx.current()) {t = '\r'; }
        else {if ('t' == ctx.current()) {t = '\t'; }
        else {if ('\\' == ctx.current()) {t = '\\'; }
        else {return ctx.error("Internal: missing switch case for special escape."); }}}}}}}

        auto r {CPP2_UFCS_TEMPLATE(cpp2_new<char_token>)(cpp2::shared, cpp2::move(t), false)}; 
        (*cpp2::impl::assert_not_null(r)).set_string("\\" + cpp2::to_string(ctx.current()) + "");
        return r; 
    }
    else 
    {
        // Escape of regex special char
        auto r {CPP2_UFCS_TEMPLATE(cpp2_new<char_token>)(cpp2::shared, ctx.current(), false)}; 
        (*cpp2::impl::assert_not_null(r)).set_string("\\" + cpp2::to_string(ctx.current()) + "");
        return r; 
    }

}

#line 1657 "cpp2regex.h2"
[[nodiscard]] auto global_group_reset_token_parse(parse_context& ctx) -> token_ptr
{
    if (!((ctx.current() == '\\' && ctx.peek() == 'K'))) {return nullptr; }

    static_cast<void>(ctx.next());// Skip escape.
    return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_code>)(cpp2::shared, "\\K", "ctx..set_group_start(0, r.pos);"); 
}

#line 1679 "cpp2regex.h2"
    group_ref_token::group_ref_token(cpp2::impl::in<int> id_, cpp2::impl::in<bool> case_insensitive_, cpp2::impl::in<std::string> str)
        : regex_token{ str }
        , id{ id_ }
        , case_insensitive{ case_insensitive_ }
#line 1680 "cpp2regex.h2"
    {

#line 1684 "cpp2regex.h2"
    }

#line 1686 "cpp2regex.h2"
    [[nodiscard]] auto group_ref_token::parse(parse_context& ctx) -> token_ptr
    {
        if (ctx.current() != '\\') {return nullptr; }

        std::string str {"\\"}; 
        std::string group {""}; 

        if ([_0 = '0', _1 = ctx.peek(), _2 = '9']{ return cpp2::impl::cmp_less_eq(_0,_1) && cpp2::impl::cmp_less_eq(_1,_2); }()) 
        {
            static_cast<void>(ctx.next());// Skip escape
            group = ctx.grab_number();

            if (cpp2::impl::cmp_greater_eq(group.size(),cpp2::impl::as_<size_t, 3>())) 
            {
                // Octal syntax (\000) not a group ref matcher.
                auto number {0}; 
                if (!(string_util::string_to_int(group, number, 8))) {return ctx.error("Could not convert octal to int."); }

                char number_as_char {cpp2::unsafe_narrow<char>(cpp2::move(number))}; 

                auto token {CPP2_UFCS_TEMPLATE(cpp2_new<char_token>)(cpp2::shared, number_as_char, ctx.get_modifiers().has(expression_flags::case_insensitive))}; 
                (*cpp2::impl::assert_not_null(token)).set_string("\\" + cpp2::to_string(string_util::int_to_string<8>(cpp2::impl::as_<int>(cpp2::move(number_as_char)))) + "");

                return token; 
            }

            str += group;
            // Regular group ref
        }
        else {if ('g' == ctx.peek()) 
        {
            static_cast<void>(ctx.next());// Skip escape
            if (!(ctx.next())) {return ctx.error("Group escape without a following char."); }// Skip g

            str += "g";

            if (ctx.current() == '{') {
                str += "{";
                if (!((ctx.next() && ctx.grab_until('}', cpp2::impl::out(&group))))) {return ctx.error("No ending bracket."); }

                str += group + "}";
            }
            else {
                group = ctx.grab_number();
                str += group;
            }
        }
        else {if ('k' == ctx.peek()) 
        {
            static_cast<void>(ctx.next());// Skip escape
            if (!(ctx.next())) {return ctx.error("Group escape without a following char."); }// Skip k

            str += "k";

            auto term_char {'\0'}; 
            if (ctx.current() == '{') {term_char = '}'; }
            else {if (ctx.current() == '<') {term_char = '>'; }
            else {if (ctx.current() == '\'') {term_char = '\''; }
            else {
                return ctx.error("Group escape has wrong operator."); 
            }}}

            str += ctx.current();

            if (!((ctx.next() && ctx.grab_until(term_char, cpp2::impl::out(&group))))) {return ctx.error("No ending bracket."); }

            str += group + cpp2::move(term_char);
        }
        else 
        {
            // No group ref matcher
            return nullptr; 
        }}}

        // Parse the group
        group = string_util::trim_copy(group);
        int group_id {0}; 
        if (string_util::string_to_int(group, group_id)) 
        {
            if (cpp2::impl::cmp_less(group_id,0)) {
                group_id = ctx.get_cur_group() + group_id;

                if (cpp2::impl::cmp_less(group_id,1)) {// Negative and zero are no valid groups.
                    return ctx.error("Relative group reference does not reference a valid group. (Would be " + cpp2::to_string(group_id) + ".)"); 
                }
            }

            if (cpp2::impl::cmp_greater_eq(group_id,ctx.get_cur_group())) {
                return ctx.error("Group reference is used before the group is declared."); 
            }
        }
        else 
        {
            // Named group
            group_id = ctx.get_named_group(group);
            if (-1 == group_id) {return ctx.error("Group names does not exist. (Name is: " + cpp2::to_string(cpp2::move(group)) + ")"); }
        }

        return CPP2_UFCS_TEMPLATE(cpp2_new<group_ref_token>)(cpp2::shared, cpp2::move(group_id), ctx.get_modifiers().has(expression_flags::case_insensitive), cpp2::move(str)); 
    }

#line 1787 "cpp2regex.h2"
    auto group_ref_token::generate_code(generation_context& ctx) const -> void{
        ctx.add_check("group_ref_token_matcher<char, " + cpp2::to_string(id) + ", " + cpp2::to_string(case_insensitive) + ">(" + cpp2::to_string(ctx.match_parameters()) + ")");
    }

    group_ref_token::~group_ref_token() noexcept{}

#line 1793 "cpp2regex.h2"
template<typename CharT, int group, bool case_insensitive> [[nodiscard]] auto group_ref_token_matcher(auto& cur, auto& ctx) -> bool
{
    auto g {ctx.get_group(group)}; 

    auto group_pos {cpp2::move(g).start}; 
    for( ; 
        group_pos != g.end 
        && cur != ctx.end; 
    (++group_pos, ++cur) ) 
    {
        if constexpr (case_insensitive) {
            if (string_util::safe_tolower(*cpp2::impl::assert_not_null(group_pos)) != string_util::safe_tolower(*cpp2::impl::assert_not_null(cur))) {
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

#line 1841 "cpp2regex.h2"
    [[nodiscard]] auto group_token::parse_lookahead(parse_context& ctx, cpp2::impl::in<std::string> syntax, cpp2::impl::in<bool> positive) -> token_ptr
    {
        static_cast<void>(ctx.next());// Skip last token defining the syntax

        auto r {CPP2_UFCS_TEMPLATE(cpp2_new<lookahead_token>)(cpp2::shared, positive)}; 

        auto old_state {ctx.start_group()}; 
        if (!(ctx.parse_until(')'))) {return ctx.error("Lookahead without a closing bracket."); }
        (*cpp2::impl::assert_not_null(r)).inner = ctx.end_group(cpp2::move(old_state));
        (*cpp2::impl::assert_not_null(r)).set_string("(" + cpp2::to_string(syntax) + cpp2::to_string((*cpp2::impl::assert_not_null((*cpp2::impl::assert_not_null(r)).inner)).to_string()) + ")");

        return r; 
    }

#line 1855 "cpp2regex.h2"
    [[nodiscard]] auto group_token::parse(parse_context& ctx) -> token_ptr
    {
        if (ctx.current() != '(') {return nullptr; }

        auto has_id {!(ctx.get_modifiers().has(expression_flags::no_group_captures))}; 
        auto has_pattern {true}; 
        std::string group_name {""}; 
        auto group_name_brackets {true}; 
        std::string modifiers {""}; 
        auto modifiers_change_to {ctx.get_modifiers()}; 

        //  Skip the '('
        if (!(ctx.next())) {return ctx.error("Group without closing bracket."); }

        if (ctx.current() == '?') 
        {
            //  Special group
            if (!(ctx.next_no_skip())) {return ctx.error("Missing character after group opening."); }

            if (ctx.current() == '<' || ctx.current() == '\'') 
            {
                //  Named group
                auto end_char {ctx.current()}; 
                if (end_char == '<') {
                    end_char = '>';
                }else {
                    group_name_brackets = false;
                }
                has_id = true; // Force id for named groups.
                if (!(ctx.next()))            { return ctx. error("Missing ending bracket for named group.");  }/* skip '<' */
                if (!(ctx.grab_until(cpp2::move(end_char), cpp2::impl::out(&group_name)))) {return ctx.error("Missing ending bracket for named group."); }
                if (!(ctx.next())) {return ctx.error("Group without closing bracket."); }
            }
            else {if (ctx.current() == '#') 
            {
                //  Comment
                std::string comment_str {""}; 
                static_cast<void>(ctx.next());// Skip #
                if (!(ctx.grab_until(")", cpp2::impl::out(&comment_str)))) {return ctx.error("Group without closing bracket."); }
                //  Do not add comment. Has problems with ranges.

                //  Pop token and add a list. This fixes comments between a token and a range
                if (ctx.has_token()) {
                    token_vec list {}; 
                    list.push_back(ctx.pop_token());
                    list.push_back(CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_empty>)(cpp2::shared, "(?#" + cpp2::to_string(cpp2::move(comment_str)) + ")"));

                    return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_list>)(cpp2::shared, cpp2::move(list)); 
                }
                else {
                    return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_empty>)(cpp2::shared, "(?#" + cpp2::to_string(cpp2::move(comment_str)) + ")"); 
                }
            }
            else {if (ctx.current() == '|') 
            {
                //  Branch reset group

                if (!(ctx.next()))            { return ctx. error("Missing ending bracket for named group.");  }/* skip '|' */

                auto old_parser_state {ctx.start_group()}; 
                auto old_branch_state {ctx.branch_reset_new_state()}; 
                if (!(ctx.parse_until(')'))) {return nullptr; }
                ctx.branch_reset_restore_state(cpp2::move(old_branch_state));
                auto inner_ {ctx.end_group(cpp2::move(old_parser_state))}; 

                token_vec list {CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_empty>)(cpp2::shared, "(?|"), cpp2::move(inner_), CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_empty>)(cpp2::shared, ")")}; 
                return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_list>)(cpp2::shared, cpp2::move(list)); 
            }
            else {if (ctx.current() == '=' || ctx.current() == '!') 
            {
                return parse_lookahead(ctx, "?" + cpp2::to_string(ctx.current()) + "", ctx.current() == '='); 
            }
            else 
            {
                //  Simple modifier
                has_id = false;
                if (!(ctx.grab_until_one_of("):", cpp2::impl::out(&modifiers)))) {return ctx.error("Missing ending bracket for group."); }
                if (!(ctx.parser_group_modifiers(modifiers, modifiers_change_to))) {
                     return nullptr; 
                }

                if (')' == ctx.current()) {
                    has_pattern = false;
                }
                else {
                    if (!(ctx.next()))            { return ctx. error("Missing ending bracket for group.");  }/* skip ':' */
                }
            }}}}
        }
        else {if (ctx.current() == '*') 
        {
            //  Named pattern
            static_cast<void>(ctx.next());// Skip *.
            std::string name {""}; 
            if (!(ctx.grab_until(':', cpp2::impl::out(&name)))) {return ctx.error("Missing colon for named pattern."); }

            if (name == "pla" || name == "positive_lookahead") {
                return parse_lookahead(ctx, "*" + cpp2::to_string(cpp2::move(name)) + ":", true); 
            }
            else {if (name == "nla" || name == "negative_lookahead") {
                return parse_lookahead(ctx, "*" + cpp2::to_string(cpp2::move(name)) + ":", false); 
            }
            else {
                return ctx.error("Unknown named group pattern: '" + cpp2::to_string(cpp2::move(name)) + "'"); 
            }}
        }}

        if (cpp2::move(has_pattern)) 
        {
            //  Regular group

            auto r {CPP2_UFCS_TEMPLATE(cpp2_new<group_token>)(cpp2::shared)}; 
            if (has_id) {
                (*cpp2::impl::assert_not_null(r)).number = ctx.next_group();

                if (0 != group_name.size()) {
                    ctx.set_named_group(group_name, (*cpp2::impl::assert_not_null(r)).number);
                }
            }

            auto old_state {ctx.start_group()}; 
            ctx.set_modifiers(cpp2::move(modifiers_change_to));
            if (!(ctx.parse_until(')'))) {return nullptr; }
            (*cpp2::impl::assert_not_null(r)).inner = ctx.end_group(cpp2::move(old_state));
            (*cpp2::impl::assert_not_null(r)).set_string(gen_string(cpp2::move(group_name), cpp2::move(group_name_brackets), !(cpp2::move(has_id)), cpp2::move(modifiers), (*cpp2::impl::assert_not_null(r)).inner));

            return r; 
        }
        else 
        {
            //  Only a modifier
            ctx.set_modifiers(cpp2::move(modifiers_change_to));

            return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_empty>)(cpp2::shared, "(?" + cpp2::to_string(cpp2::move(modifiers)) + ")"); 
        }
    }

#line 1992 "cpp2regex.h2"
    [[nodiscard]] auto group_token::gen_string(cpp2::impl::in<std::string> name, cpp2::impl::in<bool> name_brackets, cpp2::impl::in<bool> has_modifier, cpp2::impl::in<std::string> modifiers, cpp2::impl::in<token_ptr> inner_) -> std::string
    {
        std::string start {"("}; 
        if (0 != name.size()) {
            if (name_brackets) {
                start += "?<" + cpp2::to_string(name.data()) + ">";
            }
            else {
                start += "?'" + cpp2::to_string(name.data()) + "'";
            }
        }
        else {if (has_modifier) {
            start += "?" + modifiers + ":";
        }}

        return cpp2::move(start) + (*cpp2::impl::assert_not_null(inner_)).to_string() + ")"; 
    }

#line 2010 "cpp2regex.h2"
    auto group_token::generate_code(generation_context& ctx) const -> void
    {
        if (-1 != number) {
            ctx.add("ctx..set_group_start(" + cpp2::to_string(number) + ", r.pos);");
        }

        (*cpp2::impl::assert_not_null(inner)).generate_code(ctx);
        if (-1 != number) {
            ctx.add("ctx..set_group_end(" + cpp2::to_string(number) + ", r.pos);");
            auto tmp_name {ctx.gen_temp()}; 
            ctx.add("" + cpp2::to_string(tmp_name) + "_func :=  :() = {");
            ctx.add("  if !r&$*.matched {");
            ctx.add("    ctx&$*..set_group_invalid(" + cpp2::to_string(number) + ");");
            ctx.add("  }");
            ctx.add("};");
            ctx.add("" + cpp2::to_string(tmp_name) + " :=  cpp2::regex::make_on_return(" + cpp2::to_string(tmp_name) + "_func);");
            ctx.add("_ = " + cpp2::to_string(cpp2::move(tmp_name)) + ";");// Logic is done in the destructor. Same behavior as for guard objects.
        }
    }

#line 2030 "cpp2regex.h2"
    auto group_token::add_groups(std::set<int>& groups) const -> void
    {
        (*cpp2::impl::assert_not_null(inner)).add_groups(groups);
        if (-1 != number) {
            static_cast<void>(groups.insert(number));
        }
    }

    group_token::~group_token() noexcept{}

#line 2042 "cpp2regex.h2"
[[nodiscard]] auto hexadecimal_token_parse(parse_context& ctx) -> token_ptr
{
    if (!((ctx.current() == '\\' && ctx.peek() == 'x'))) {return nullptr; }

    static_cast<void>(ctx.next());// Skip escape.

    if (!(ctx.next())) {return ctx.error("x escape without number."); }

    auto has_brackets {false}; 
    std::string number_str {""}; 
    if ('{' == ctx.current()) {
        //  Bracketed
        has_brackets = true;
        static_cast<void>(ctx.next());// Skip '{'
        if (!(ctx.grab_until('}', cpp2::impl::out(&number_str)))) {return ctx.error("No ending bracket for \\x"); }
    }
    else {
        //  Grab two chars
        if (!(ctx.grab_n(2, cpp2::impl::out(&number_str)))) {return ctx.error("Missing hexadecimal digits after \\x."); }
    }

    auto number {0}; 
    if (!(string_util::string_to_int(cpp2::move(number_str), number, 16))) {return ctx.error("Could not convert hexadecimal to int."); }

    // TODO: Change for unicode.
    char number_as_char {cpp2::unsafe_narrow<char>(cpp2::move(number))}; 

    std::string syntax {string_util::int_to_string<16>(cpp2::impl::as_<int>(number_as_char))}; 
    if (cpp2::move(has_brackets)) {
        syntax = "{" + cpp2::to_string(syntax) + "}";
    }
    syntax = "\\x" + cpp2::to_string(syntax) + "";

    auto r {CPP2_UFCS_TEMPLATE(cpp2_new<char_token>)(cpp2::shared, cpp2::move(number_as_char), ctx.get_modifiers().has(expression_flags::case_insensitive))}; 
    (*cpp2::impl::assert_not_null(r)).set_string(cpp2::move(syntax));
    return r; 
}

#line 2083 "cpp2regex.h2"
[[nodiscard]] auto line_end_token_parse(parse_context& ctx) -> token_ptr
{
    if (ctx.current() == '$' || (ctx.current() == '\\' && ctx.peek() == '$')) {
        if ((ctx.current() == '\\')) {static_cast<void>(ctx.next()); }// Skip escape
        return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_check>)(cpp2::shared, "$", "line_end_token_matcher<char, " + cpp2::to_string(ctx.get_modifiers().has(expression_flags::multiple_lines)) + ", true>"); 
    }
    else {if (ctx.current() == '\\' && (ctx.peek() == 'z' || ctx.peek() == 'Z')) {
        static_cast<void>(ctx.next());// Skip escape

        auto negate {ctx.current() == 'Z'}; 
        return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_check>)(cpp2::shared, "\\" + cpp2::to_string(ctx.current()) + "", "line_end_token_matcher<char, false, " + cpp2::to_string(cpp2::move(negate)) + ">"); 
    }
    else {
        return nullptr; 
    }}
}

#line 2100 "cpp2regex.h2"
template<typename CharT, bool match_new_line, bool match_new_line_before_end> [[nodiscard]] auto line_end_token_matcher(auto const& cur, auto& ctx) -> bool
{
    if (cur == ctx.end || (match_new_line && *cpp2::impl::assert_not_null(cur) == '\n')) {
        return true; 
    }
    else {if (match_new_line_before_end && (*cpp2::impl::assert_not_null(cur) == '\n' && (cur + 1) == ctx.end)) {// Special case for new line at end.
        return true; 
    }
    else {
        return false; 
    }}
}

#line 2116 "cpp2regex.h2"
[[nodiscard]] auto line_start_token_parse(parse_context& ctx) -> token_ptr
{
    if (ctx.current() != '^' && !((ctx.current() == '\\' && ctx.peek() == 'A'))) {return nullptr; }

    if (ctx.current() == '\\') {
        static_cast<void>(ctx.next());
        return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_check>)(cpp2::shared, "\\A", "line_start_token_matcher<char, false>"); 
    }
    else {
        return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_check>)(cpp2::shared, "^", "line_start_token_matcher<char, " + cpp2::to_string(ctx.get_modifiers().has(expression_flags::multiple_lines)) + ">"); 
    }
}

#line 2129 "cpp2regex.h2"
template<typename CharT, bool match_new_line> [[nodiscard]] auto line_start_token_matcher(auto const& cur, auto& ctx) -> bool
{
    return cur == ctx.begin || // Start of string
           (match_new_line && *cpp2::impl::assert_not_null((cur - 1)) == '\n'); // Start of new line
}

#line 2147 "cpp2regex.h2"
    lookahead_token::lookahead_token(cpp2::impl::in<bool> positive_)
        : regex_token{ "" }
        , positive{ positive_ }{

#line 2149 "cpp2regex.h2"
    }

#line 2151 "cpp2regex.h2"
    auto lookahead_token::generate_code(generation_context& ctx) const -> void{
        auto inner_name {ctx.generate_func(inner)}; 

        ctx.add_check("lookahead_token_matcher<char, " + cpp2::to_string(positive) + ">(" + cpp2::to_string(ctx.match_parameters()) + ", " + cpp2::to_string(cpp2::move(inner_name)) + ")");
    }

#line 2157 "cpp2regex.h2"
    auto lookahead_token::add_groups(std::set<int>& groups) const -> void{
        (*cpp2::impl::assert_not_null(inner)).add_groups(groups);
    }

    lookahead_token::~lookahead_token() noexcept{}

#line 2162 "cpp2regex.h2"
template<typename CharT, bool positive> [[nodiscard]] auto lookahead_token_matcher(auto const& cur, auto& ctx, auto const& func) -> bool
{
    auto r {func(cur, ctx, true_end_func())}; 
    if (!(positive)) {
        r.matched = !(r.matched);
    }

    return cpp2::move(r).matched; 
}

#line 2175 "cpp2regex.h2"
[[nodiscard]] auto named_class_token_parse(parse_context& ctx) -> token_ptr
{
    if (ctx.current() != '\\') {return nullptr; }

    auto name {""}; 
    auto c_next {ctx.peek()}; 

    if (     'd' == c_next) { name = "named_class_digits"; }
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
    else                  { return nullptr; }}}}}}}}}}}

    static_cast<void>(ctx.next());// Skip escape

    return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_check>)(cpp2::shared, "\\" + cpp2::to_string(ctx.current()) + "", "" + cpp2::to_string(cpp2::move(name)) + "<char, " + cpp2::to_string(ctx.get_modifiers().has(expression_flags::case_insensitive)) + ">::match"); 
}

#line 2217 "cpp2regex.h2"
[[nodiscard]] auto octal_token_parse(parse_context& ctx) -> token_ptr
{
    if (!((ctx.current() == '\\' && ctx.peek() == 'o'))) {return nullptr; }

    static_cast<void>(ctx.next());// Skip escape.

    if (!(ctx.next()))      { return ctx. error("o escape without number."); }
    if (ctx.current() != '{') {return ctx.error("Missing opening bracket for \\o."); }

    std::string number_str {""}; 
    static_cast<void>(ctx.next());// Skip '{'
    if (!(ctx.grab_until('}', cpp2::impl::out(&number_str)))) {return ctx.error("No ending bracket for \\o"); }

    auto number {0}; 
    if (!(string_util::string_to_int(cpp2::move(number_str), number, 8))) {return ctx.error("Could not convert octal to int."); }

    // TODO: Change for unicode.
    char number_as_char {cpp2::unsafe_narrow<char>(cpp2::move(number))}; 

    std::string syntax {"\\o{" + cpp2::to_string(string_util::int_to_string<8>(cpp2::impl::as_<int>(number_as_char))) + "}"}; 
    auto r {CPP2_UFCS_TEMPLATE(cpp2_new<char_token>)(cpp2::shared, cpp2::move(number_as_char), ctx.get_modifiers().has(expression_flags::case_insensitive))}; 
    (*cpp2::impl::assert_not_null(r)).set_string(cpp2::move(syntax));
    return r; 
}

#line 2247 "cpp2regex.h2"
    inline CPP2_CONSTEXPR int range_flags::not_greedy{ 1 };
    inline CPP2_CONSTEXPR int range_flags::greedy{ 2 };
    inline CPP2_CONSTEXPR int range_flags::possessive{ 3 };

#line 2264 "cpp2regex.h2"
    range_token::range_token()
                             : regex_token{ "" }{}

#line 2266 "cpp2regex.h2"
    [[nodiscard]] auto range_token::parse(parse_context& ctx) -> token_ptr
    {
        auto r {CPP2_UFCS_TEMPLATE(cpp2_new<range_token>)(cpp2::shared)}; 
        if (ctx.current() == '{') 
        {
            if (!(ctx.has_token())) {return ctx.error("'{' without previous element."); }

            std::string inner {""}; 
            if (!(ctx.grab_until('}', cpp2::impl::out(&inner)))) {return ctx.error("Missing closing bracket '}'."); }

            inner = string_util::trim_copy(inner.substr(1));  // Remove '{' and white spaces.
            if (inner.empty()) {return ctx.error("Empty range specifier. Either '{n}', '{n,}', '{,m}' '{n,m}'"); }

            // Non-greedy or possessive
            (*cpp2::impl::assert_not_null(r)).parse_modifier(ctx);

            // Get range arguments
            std::string min_count_str {"-1"}; 
            std::string max_count_str {"-1"}; 

            size_t sep {inner.find(",")}; 
            if (sep == std::string::npos) 
            {
                min_count_str = inner;
                max_count_str = inner;
                if (!(string_util::string_to_int(cpp2::move(inner), (*cpp2::impl::assert_not_null(r)).min_count))) {return ctx.error("Could not convert range to number."); }
                (*cpp2::impl::assert_not_null(r)).max_count = (*cpp2::impl::assert_not_null(r)).min_count;
            }
            else 
            {
                std::string inner_first {string_util::trim_copy(inner.substr(0, sep))}; 
                std::string inner_last {string_util::trim_copy(cpp2::move(inner).substr(cpp2::move(sep) + 1))}; 

                if ((inner_first.empty() && inner_last.empty())) {
                    return ctx.error("Empty range specifier. Either '{n}', '{n,}', '{,m}' '{n,m}'"); 
                }

                if (!(inner_first.empty())) {
                    min_count_str = inner_first;
                    if (!(string_util::string_to_int(cpp2::move(inner_first), (*cpp2::impl::assert_not_null(r)).min_count))) {return ctx.error("Could not convert range to number."); }
                }
                if (!(inner_last.empty())) {
                    max_count_str = inner_last;
                    if (!(string_util::string_to_int(cpp2::move(inner_last), (*cpp2::impl::assert_not_null(r)).max_count))) {return ctx.error("Could not convert range to number."); }
                }
            }

            // Check validity of the range.
            if (-1 != (*cpp2::impl::assert_not_null(r)).min_count) {
                if (!((cpp2::impl::cmp_less_eq(0,(*cpp2::impl::assert_not_null(r)).min_count)))) {
                    return ctx.error("Min value in range is negative. Have " + cpp2::to_string((*cpp2::impl::assert_not_null(r)).min_count) + ")"); 
                }
            }
            if (-1 != (*cpp2::impl::assert_not_null(r)).max_count) {
                if (!((cpp2::impl::cmp_less_eq(0,(*cpp2::impl::assert_not_null(r)).max_count)))) {
                    return ctx.error("Max value in range is negative. Have " + cpp2::to_string((*cpp2::impl::assert_not_null(r)).max_count) + ")"); 
                }
                if (-1 != (*cpp2::impl::assert_not_null(r)).min_count) {
                    if (!((cpp2::impl::cmp_less_eq((*cpp2::impl::assert_not_null(r)).min_count,(*cpp2::impl::assert_not_null(r)).max_count)))) {
                        return ctx.error("Min and max values in range are wrong it should hold 0 <= min <= max. Have 0 <= " + cpp2::to_string((*cpp2::impl::assert_not_null(r)).min_count) + " <= " + cpp2::to_string((*cpp2::impl::assert_not_null(r)).max_count) + ""); 
                    }
                }
            }

            (*cpp2::impl::assert_not_null(r)).inner_token = ctx.pop_token();
            (*cpp2::impl::assert_not_null(r)).string_rep = (*cpp2::impl::assert_not_null((*cpp2::impl::assert_not_null(r)).inner_token)).to_string() + (*cpp2::impl::assert_not_null(r)).gen_range_string() + (*cpp2::impl::assert_not_null(r)).gen_mod_string();

            return r; 
        }

        return nullptr; 
    }

#line 2339 "cpp2regex.h2"
    auto range_token::parse_modifier(parse_context& ctx) & -> void
    {
        if (ctx.peek() == '?') {
            kind = range_flags::not_greedy;
            static_cast<void>(ctx.next());
        }
        else {if (ctx.peek() == '+') {
            kind = range_flags::possessive;
            static_cast<void>(ctx.next());
        }}
    }

#line 2351 "cpp2regex.h2"
    [[nodiscard]] auto range_token::gen_mod_string() const& -> std::string
    {
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

#line 2364 "cpp2regex.h2"
    [[nodiscard]] auto range_token::gen_range_string() const& -> std::string
    {
        std::string r {""}; 
        if (min_count == max_count) {
            r += "{" + cpp2::to_string(min_count) + "}";
        }
        else {if (min_count == -1) {
            r += "{," + cpp2::to_string(max_count) + "}";
        }
        else {if (max_count == -1) {
            r += "{" + cpp2::to_string(min_count) + ",}";
        }
        else {
            r += "{" + cpp2::to_string(min_count) + "," + cpp2::to_string(max_count) + "}";
        }}}

        return r; 
    }

#line 2383 "cpp2regex.h2"
    auto range_token::generate_code(generation_context& ctx) const -> void
    {
        auto inner_name {ctx.generate_func(inner_token)}; 
        std::set<int> groups {}; 
        (*cpp2::impl::assert_not_null(inner_token)).add_groups(groups);
        auto reset_name {ctx.generate_reset(cpp2::move(groups))}; 

        auto next_name {ctx.next_func_name()}; 
        ctx.add_statefull(next_name, "cpp2::regex::range_token_matcher<char, " + cpp2::to_string(min_count) + ", " + cpp2::to_string(max_count) + ", " + cpp2::to_string(kind) + ">::match(" + cpp2::to_string(ctx.match_parameters()) + ", " + cpp2::to_string(cpp2::move(inner_name)) + ", " + cpp2::to_string(cpp2::move(reset_name)) + ", other, " + cpp2::to_string(next_name) + ")");
    }

#line 2394 "cpp2regex.h2"
    auto range_token::add_groups(std::set<int>& groups) const -> void{
        (*cpp2::impl::assert_not_null(inner_token)).add_groups(groups);
    }

    range_token::~range_token() noexcept{}

#line 2404 "cpp2regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> template<typename Iter> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::match(Iter const& cur, auto& ctx, auto const& inner, auto const& reset_func, auto const& end_func, auto const& tail) -> auto
    {
        if (range_flags::possessive == kind) {
            return match_possessive(cur, ctx, inner, end_func, tail); 
        }
        else {if (range_flags::greedy == kind) {
            return match_greedy(0, cur, ctx.end, ctx, inner, reset_func, end_func, tail); 
        }
        else { // range_flags::not_greedy == kind
            return match_not_greedy(cur, ctx, inner, end_func, tail); 
        }}
    }

#line 2417 "cpp2regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::is_below_upper_bound(cpp2::impl::in<int> count) -> bool{
        if (-1 == max_count) {return true; }
        else {return cpp2::impl::cmp_less(count,max_count); }
    }

#line 2422 "cpp2regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::is_below_lower_bound(cpp2::impl::in<int> count) -> bool{
        if (-1 == min_count) {return false; }
        else {return cpp2::impl::cmp_less(count,min_count); }
    }

#line 2427 "cpp2regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::is_in_range(cpp2::impl::in<int> count) -> bool{
        if (-1 != min_count && cpp2::impl::cmp_less(count,min_count)) {return false; }
        if (-1 != max_count && cpp2::impl::cmp_greater(count,max_count)) {return false; }
        return true; 
    }

#line 2433 "cpp2regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> template<typename Iter> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::match_min_count(Iter const& cur, auto& ctx, auto const& inner, auto const& end_func, int& count_r) -> auto
    {   // TODO: count_r as out parameter introduces a performance loss.
        auto res {ctx.pass(cur)}; 
        auto count {0}; 

        while( is_below_lower_bound(count) && res.matched ) {
            res = inner(res.pos, ctx, end_func);
            if (res.matched) {
                count += 1;
            }
        }

        count_r = cpp2::move(count);
        return res; 
    }

#line 2449 "cpp2regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> template<typename Iter> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::match_greedy(cpp2::impl::in<int> count, Iter const& cur, Iter const& last_valid, auto& ctx, auto const& inner, auto const& reset_func, auto const& end_func, auto const& other) -> match_return<Iter>
    {
        auto inner_call {[_0 = (count + 1), _1 = (cur), _2 = (inner), _3 = (reset_func), _4 = (end_func), _5 = (other)](auto const& tail_cur, auto& tail_ctx) -> auto{
            return match_greedy(_0, tail_cur, _1, tail_ctx, _2, _3, _4, _5); 
        }}; 
        auto is_m_valid {true}; 
        auto r {ctx.fail()}; 
        if (is_below_upper_bound(count) && (is_below_lower_bound(count) || cur != last_valid)) {
            is_m_valid = false;  // Group ranges in M are invalidated through the call.
            r = inner(cur, ctx, cpp2::move(inner_call));
        }

        if (!(r.matched) && is_in_range(count)) 
        {
            //  The recursion did not yield a match try now the tail
            r = other(cur, ctx, end_func);

            if (r.matched && !(cpp2::move(is_m_valid))) {
                //  We have a match rematch M if required
                reset_func(ctx);

                if (cpp2::impl::cmp_greater(count,0)) {
                    static_cast<void>(inner(last_valid, ctx, true_end_func()));
                }
            }
        }

        return r; 
    }

#line 2479 "cpp2regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> template<typename Iter> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::match_possessive(Iter const& cur, auto& ctx, auto const& inner, auto const& end_func, auto const& other) -> match_return<Iter>
    {
        auto count {0}; 
        auto r {match_min_count(cur, ctx, inner, end_func, count)}; 

        if (!(r.matched)) {
          return r; 
        }

        auto pos {r.pos}; 
        while( 
            r.matched 
            && is_below_upper_bound(count) ) 
        {
            r = inner(pos, ctx, true_end_func());

            if (pos == r.pos) {
                break; // Break infinite loop.
            }
            if (r.matched) {
                count += 1;
                pos = r.pos;
            }
        }

        return other(cpp2::move(pos), ctx, end_func); 
    }

#line 2507 "cpp2regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> template<typename Iter> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::match_not_greedy(Iter const& cur, auto& ctx, auto const& inner, auto const& end_func, auto const& other) -> match_return<Iter>
    {
        auto count {0}; 
        auto start {match_min_count(cur, ctx, inner, end_func, count)}; 
        if (!(start.matched)) {
          return start; 
        }

        auto pos {cpp2::move(start).pos}; 
        while( is_below_upper_bound(count) ) 
        {
            auto o {other(pos, ctx, end_func)}; 
            if (o.matched) {
                return o; 
            }

            auto r {inner(pos, ctx, end_func)}; 
            if (!(r.matched)) {
                return ctx.fail(); 
            }
            count += 1;
            pos = cpp2::move(r).pos;
        }

        return other(cpp2::move(pos), ctx, end_func); // Upper bound reached.
    }

#line 2542 "cpp2regex.h2"
    [[nodiscard]] auto special_range_token::parse(parse_context& ctx) -> token_ptr
    {
        auto r {CPP2_UFCS_TEMPLATE(cpp2_new<special_range_token>)(cpp2::shared)}; 
        char symbol {'\0'}; 
        if (ctx.current() == '*') {
            (*cpp2::impl::assert_not_null(r)).min_count = 0;
            (*cpp2::impl::assert_not_null(r)).max_count = -1;
            symbol = '*';
        }
        else {if (ctx.current() == '+') {
            (*cpp2::impl::assert_not_null(r)).min_count = 1;
            (*cpp2::impl::assert_not_null(r)).max_count = -1;
            symbol = '+';
        }else {if (ctx.current() == '?') {
            (*cpp2::impl::assert_not_null(r)).min_count = 0;
            (*cpp2::impl::assert_not_null(r)).max_count = 1;
            symbol = '?';
        }else {
            return nullptr; 
        }}}

        if (!(ctx.has_token())) {return ctx.error("'" + cpp2::to_string(ctx.current()) + "' without previous element."); }

#line 2566 "cpp2regex.h2"
        (*cpp2::impl::assert_not_null(r)).parse_modifier(ctx);

        (*cpp2::impl::assert_not_null(r)).inner_token = ctx.pop_token();
        (*cpp2::impl::assert_not_null(r)).string_rep = (*cpp2::impl::assert_not_null((*cpp2::impl::assert_not_null(r)).inner_token)).to_string() + cpp2::move(symbol) + (*cpp2::impl::assert_not_null(r)).gen_mod_string();
        return r; 
    }

    special_range_token::~special_range_token() noexcept{}

#line 2579 "cpp2regex.h2"
[[nodiscard]] auto word_boundary_token_parse(parse_context& ctx) -> token_ptr
{
    if (ctx.current() != '\\') {return nullptr; }

    if (ctx.peek() == 'b') {
        static_cast<void>(ctx.next());
        return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_check>)(cpp2::shared, "\\b", "word_boundary_token_matcher<char, false>"); 
    }
    else {if (ctx.peek() == 'B') {
        static_cast<void>(ctx.next());
        return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_check>)(cpp2::shared, "\\B", "word_boundary_token_matcher<char, true>"); 
    }
    else {
        return nullptr; 
    }}
}

#line 2596 "cpp2regex.h2"
template<typename CharT, bool negate> [[nodiscard]] auto word_boundary_token_matcher(auto& cur, auto& ctx) -> bool
{
    word_class<CharT> words {}; 
    auto is_match {false}; 
    if (cur == ctx.begin) {// String start
        if (cur != ctx.end) {// No empty string
            is_match = cpp2::move(words).includes(*cpp2::impl::assert_not_null(cur));
        }
    }
    else {if (cur == ctx.end) {// String end
        is_match = cpp2::move(words).includes(*cpp2::impl::assert_not_null((cur - 1)));
    }
    else { // Middle of string
        is_match = 
                (words.includes(*cpp2::impl::assert_not_null((cur - 1))) && !(words.includes(*cpp2::impl::assert_not_null(cur)))) // End of word: \w\W
            || (!(words.includes(*cpp2::impl::assert_not_null((cur - 1)))) && words.includes(*cpp2::impl::assert_not_null(cur)));// Start of word: \W\w
    }}
    if (negate) {
        is_match = !(is_match);
    }

    return is_match; 
}

#line 2640 "cpp2regex.h2"
        template <typename CharT, typename matcher_wrapper> template <typename Iter> regular_expression<CharT,matcher_wrapper>::search_return<Iter>::search_return(cpp2::impl::in<bool> matched_, context<Iter> const& ctx_, Iter const& pos_)
            : matched{ matched_ }
            , ctx{ ctx_ }
            , pos{ cpp2::unsafe_narrow<int>(std::distance(ctx_.begin, pos_)) }{

#line 2644 "cpp2regex.h2"
        }

#line 2646 "cpp2regex.h2"
        template <typename CharT, typename matcher_wrapper> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,matcher_wrapper>::search_return<Iter>::group_number() const& -> auto { return ctx.size();  }
#line 2647 "cpp2regex.h2"
        template <typename CharT, typename matcher_wrapper> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,matcher_wrapper>::search_return<Iter>::group(cpp2::impl::in<int> g) const& -> auto { return ctx.get_group_string(g); }
#line 2648 "cpp2regex.h2"
        template <typename CharT, typename matcher_wrapper> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,matcher_wrapper>::search_return<Iter>::group_start(cpp2::impl::in<int> g) const& -> auto { return ctx.get_group_start(g); }
#line 2649 "cpp2regex.h2"
        template <typename CharT, typename matcher_wrapper> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,matcher_wrapper>::search_return<Iter>::group_end(cpp2::impl::in<int> g) const& -> auto { return ctx.get_group_end(g); }

#line 2651 "cpp2regex.h2"
        template <typename CharT, typename matcher_wrapper> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,matcher_wrapper>::search_return<Iter>::group(cpp2::impl::in<bstring<CharT>> g) const& -> auto { return group(get_group_id(g)); }
#line 2652 "cpp2regex.h2"
        template <typename CharT, typename matcher_wrapper> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,matcher_wrapper>::search_return<Iter>::group_start(cpp2::impl::in<bstring<CharT>> g) const& -> auto { return group_start(get_group_id(g)); }
#line 2653 "cpp2regex.h2"
        template <typename CharT, typename matcher_wrapper> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,matcher_wrapper>::search_return<Iter>::group_end(cpp2::impl::in<bstring<CharT>> g) const& -> auto { return group_end(get_group_id(g)); }

#line 2655 "cpp2regex.h2"
        template <typename CharT, typename matcher_wrapper> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,matcher_wrapper>::search_return<Iter>::get_group_id(cpp2::impl::in<bstring<CharT>> g) const& -> auto{
            auto group_id {matcher<Iter>::get_named_group_index(g)}; 
            if (-1 == group_id) {
                // TODO: Throw error.
            }
            return group_id; 
        }

#line 2664 "cpp2regex.h2"
    template <typename CharT, typename matcher_wrapper> [[nodiscard]] auto regular_expression<CharT,matcher_wrapper>::match(cpp2::impl::in<bview<CharT>> str) const& -> auto { return match(str.begin(), str.end()); }
#line 2665 "cpp2regex.h2"
    template <typename CharT, typename matcher_wrapper> [[nodiscard]] auto regular_expression<CharT,matcher_wrapper>::match(cpp2::impl::in<bview<CharT>> str, auto const& start) const& -> auto { return match(get_iter(str, start), str.end()); }
#line 2666 "cpp2regex.h2"
    template <typename CharT, typename matcher_wrapper> [[nodiscard]] auto regular_expression<CharT,matcher_wrapper>::match(cpp2::impl::in<bview<CharT>> str, auto const& start, auto const& length) const& -> auto { return match(get_iter(str, start), get_iter(str, start + length)); }
#line 2667 "cpp2regex.h2"
    template <typename CharT, typename matcher_wrapper> template<typename Iter> [[nodiscard]] auto regular_expression<CharT,matcher_wrapper>::match(Iter const& start, Iter const& end) const& -> search_return<Iter>
    {
        context<Iter> ctx {start, end}; 

        auto r {matcher<Iter>::entry(start, ctx)}; 
        return search_return<Iter>(r.matched && r.pos == end, cpp2::move(ctx), r.pos); 
    }

#line 2675 "cpp2regex.h2"
    template <typename CharT, typename matcher_wrapper> [[nodiscard]] auto regular_expression<CharT,matcher_wrapper>::search(cpp2::impl::in<bview<CharT>> str) const& -> auto { return search(str.begin(), str.end()); }
#line 2676 "cpp2regex.h2"
    template <typename CharT, typename matcher_wrapper> [[nodiscard]] auto regular_expression<CharT,matcher_wrapper>::search(cpp2::impl::in<bview<CharT>> str, auto const& start) const& -> auto { return search(get_iter(str, start), str.end()); }
#line 2677 "cpp2regex.h2"
    template <typename CharT, typename matcher_wrapper> [[nodiscard]] auto regular_expression<CharT,matcher_wrapper>::search(cpp2::impl::in<bview<CharT>> str, auto const& start, auto const& length) const& -> auto { return search(get_iter(str, start), get_iter(str, start + length)); }
#line 2678 "cpp2regex.h2"
    template <typename CharT, typename matcher_wrapper> template<typename Iter> [[nodiscard]] auto regular_expression<CharT,matcher_wrapper>::search(Iter const& start, Iter const& end) const& -> search_return<Iter>
    {
        context<Iter> ctx {start, end}; 
        auto r {ctx.fail()}; 

        auto cur {start}; 
        for( ; true; (++cur) ) {
            r = matcher<Iter>::entry(cur, ctx);
            if (r.matched) {
                break;
            }

            if (cur == ctx.end) {
                break;
            }
        }

        return search_return<Iter>(r.matched, cpp2::move(ctx), cpp2::move(r).pos); 
    }

#line 2698 "cpp2regex.h2"
    template <typename CharT, typename matcher_wrapper> [[nodiscard]] auto regular_expression<CharT,matcher_wrapper>::to_string() const& -> auto { return matcher_wrapper::to_string();  }

#line 2702 "cpp2regex.h2"
    template <typename CharT, typename matcher_wrapper> [[nodiscard]] auto regular_expression<CharT,matcher_wrapper>::get_iter(cpp2::impl::in<bview<CharT>> str, auto const& pos) -> auto{
        if (cpp2::impl::cmp_less(pos,str.size())) {
            return str.begin() + pos; 
        }
        else {
            return str.end(); 
        }
    }

#line 2731 "cpp2regex.h2"
    template <typename Error_out> regex_generator<Error_out>::regex_generator(cpp2::impl::in<std::string_view> r, Error_out const& e)
        : regex{ r }
        , error_out{ e }{

#line 2734 "cpp2regex.h2"
    }

#line 2736 "cpp2regex.h2"
    template <typename Error_out> [[nodiscard]] auto regex_generator<Error_out>::parse() & -> std::string
    {
        // Extract modifiers and adapt regex.
        extract_modifiers();

        parse_context parse_ctx {regex, error_out}; 
        if (!(parse_ctx.parse(modifier))) {
            return ""; 
        }

        source += "{\n";
        source += " wrap: <Iter, CharT> type = {\n"; // TODO: Remove wrapper when template template parameters are available.
        source += "  context: type == cpp2::regex::match_context<CharT, Iter, " + cpp2::to_string(parse_ctx.get_cur_group()) + ">;";

        generation_context gen_ctx {}; 
        source += gen_ctx.run(parse_ctx.get_as_token());
        source += "  entry: (cur: Iter, inout ctx: context) -> cpp2::regex::match_return<Iter> = {\n";
        source += "    ctx..set_group_start(0, cur);\n";
        source += "    r := " + cpp2::to_string(gen_ctx.get_entry_func()) + "(cur, ctx, cpp2::regex::true_end_func());\n";
        source += "    if r.matched { ctx..set_group_end(0, r.pos); }\n";
        source += "    return r;\n";
        source += "  }\n";

        source += cpp2::move(gen_ctx).create_named_group_lookup(parse_ctx.named_groups);
        source += "}\n";

        auto string {(*cpp2::impl::assert_not_null(parse_ctx.get_as_token())).to_string()}; 
        source += "  to_string: () -> std::string = { return R\"(" + cpp2::to_string(modifier_escape) + cpp2::to_string(cpp2::move(string)) + cpp2::to_string(modifier_escape) + cpp2::to_string(modifier) + ")\"; }\n";
        source += "}\n";

        static_cast<void>(cpp2::move(parse_ctx));

        return source; 
    }

#line 2771 "cpp2regex.h2"
    template <typename Error_out> auto regex_generator<Error_out>::extract_modifiers() & -> void
    {
        if (regex.find_first_of("'/") == 0) {
            char mod_token {CPP2_ASSERT_IN_BOUNDS_LITERAL(regex, 0)}; 

            auto end_pos {regex.rfind(mod_token)}; 
            if (end_pos != 0) {
                // Found valid start end escape
                modifier = regex.substr(end_pos + 1);
                modifier_escape = cpp2::move(mod_token);
                regex = regex.substr(1, cpp2::move(end_pos) - 1);
            }
        }
    }

#line 2787 "cpp2regex.h2"
template<typename Err> [[nodiscard]] auto generate_regex(cpp2::impl::in<std::string_view> regex, Err const& err) -> std::string
{
    regex_generator<Err> parser {regex, err}; 
    auto r {parser.parse()}; 
    static_cast<void>(cpp2::move(parser));
    return r; 
}

}
}

#endif
