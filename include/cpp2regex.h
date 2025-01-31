
#ifndef CPP2REGEX_H_CPP2
#define CPP2REGEX_H_CPP2


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "cpp2regex.h2"

#line 20 "cpp2regex.h2"
namespace cpp2 {

namespace regex {

#line 36 "cpp2regex.h2"
template<typename Iter> class match_group;

#line 46 "cpp2regex.h2"
template<typename Iter> class match_return;

#line 54 "cpp2regex.h2"
template<typename CharT, typename Iter, int max_groups> class match_context;

#line 125 "cpp2regex.h2"
template<typename CharT, typename Iter, int max_groups> class reverse_match_context;

#line 194 "cpp2regex.h2"
class true_end_func;

#line 202 "cpp2regex.h2"
class no_reset;

#line 209 "cpp2regex.h2"
template<typename Func> class on_return;

#line 236 "cpp2regex.h2"
template<typename CharT, CharT C> class single_class_entry;

#line 245 "cpp2regex.h2"
template<typename CharT, CharT Start, CharT End> class range_class_entry;

#line 254 "cpp2regex.h2"
template<typename CharT, typename ...List> class combined_class_entry;

#line 263 "cpp2regex.h2"
template<typename CharT, CharT ...List> class list_class_entry;

#line 272 "cpp2regex.h2"
template<typename CharT, string_util::fixed_string Name, typename Inner> class named_class_entry;

#line 279 "cpp2regex.h2"
template<typename CharT, typename Inner> class negated_class_entry;

#line 288 "cpp2regex.h2"
template<typename CharT, string_util::fixed_string Name, typename Inner> class shorthand_class_entry;

#line 336 "cpp2regex.h2"
template<typename CharT> class alternative_token_matcher;

#line 427 "cpp2regex.h2"
template<typename CharT, bool negate, bool case_insensitive, typename ...List> class class_token_matcher;

#line 604 "cpp2regex.h2"
class range_flags;
    

#line 613 "cpp2regex.h2"
template<typename CharT, int min_count, int max_count, int kind> class range_token_matcher;

#line 785 "cpp2regex.h2"
template<typename CharT, typename matcher> class regular_expression;

#line 921 "cpp2regex.h2"
}
}


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "cpp2regex.h2"

//  Copyright 2022-2024 Herb Sutter
//  SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//  
//  Part of the Cppfront Project, under the Apache License v2.0 with LLVM Exceptions.
//  See https://github.com/hsutter/cppfront/blob/main/LICENSE for license information.


//===========================================================================
//  Regex support
//===========================================================================

#ifndef CPP2_CPP2REGEX_H
#define CPP2_CPP2REGEX_H


template<typename matcher, typename Iter>
using matcher_context_type = typename matcher::template context<Iter>;

#line 20 "cpp2regex.h2"
namespace cpp2 {

namespace regex {

template<typename CharT> using bstring = std::basic_string<CharT>;
template <typename CharT> using bview = std::basic_string_view<CharT>;

//-----------------------------------------------------------------------
//
//  Helper structures for the expression matching.
//
//-----------------------------------------------------------------------
//

//  Structure for storing group information.
//
template<typename Iter> class match_group
 {
    public: Iter start {}; 
    public: Iter end {}; 

    public: bool matched {false}; 
    public: match_group(auto const& start_, auto const& end_, auto const& matched_);
public: match_group();

#line 42 "cpp2regex.h2"
};

//  Return value for every matcher.
// 
template<typename Iter> class match_return
 {
    public: bool matched {false}; 
    public: Iter pos {}; 
    public: match_return(auto const& matched_, auto const& pos_);
public: match_return();

#line 50 "cpp2regex.h2"
};

//  Modifiable state during matching.
//
template<typename CharT, typename Iter, int max_groups> class match_context
 {
            public: Iter begin; 
            public: Iter end; 

    private: std::array<match_group<Iter>,max_groups> groups {}; 

    public: match_context(Iter const& begin_, Iter const& end_);

#line 66 "cpp2regex.h2"
    public: match_context(match_context const& that);
#line 66 "cpp2regex.h2"
    public: auto operator=(match_context const& that) -> match_context& ;
#line 66 "cpp2regex.h2"
    public: match_context(match_context&& that) noexcept;
#line 66 "cpp2regex.h2"
    public: auto operator=(match_context&& that) noexcept -> match_context& ;

    // String end and start positions
    //
    public: [[nodiscard]] auto get_string_start() const& -> decltype(auto);
    public: [[nodiscard]] auto get_string_end() const& -> decltype(auto);

    //  Getter and setter for groups
    //
    public: [[nodiscard]] auto get_group(auto const& group) const& -> decltype(auto);

    public: [[nodiscard]] auto get_group_end(auto const& group) const& -> int;

#line 83 "cpp2regex.h2"
    public: [[nodiscard]] auto get_group_start(auto const& group) const& -> int;

#line 89 "cpp2regex.h2"
    public: [[nodiscard]] auto get_group_string(auto const& group) const& -> std::string;

#line 96 "cpp2regex.h2"
    public: auto set_group_end(auto const& group, auto const& pos) & -> void;

#line 101 "cpp2regex.h2"
    public: auto set_group_invalid(auto const& group) & -> void;

#line 105 "cpp2regex.h2"
    public: auto set_group_start(auto const& group, auto const& pos) & -> void;

#line 109 "cpp2regex.h2"
    public: [[nodiscard]] auto size() const& -> decltype(auto);

    //  Misc functions
    //
    public: [[nodiscard]] auto fail() const& -> decltype(auto);
    public: [[nodiscard]] auto pass(cpp2::impl::in<Iter> cur) const& -> decltype(auto);

    public: auto reset() & -> void;

#line 121 "cpp2regex.h2"
};

//  Wrapper of context for reverse matches. Implements only the minimal interface for matching.
//
template<typename CharT, typename Iter, int max_groups> class reverse_match_context
 {
    public: using ReverseIter = std::reverse_iterator<Iter>;
    public: match_context<CharT,Iter,max_groups>* forward_context; 

            public: ReverseIter begin; 
            public: ReverseIter end; 

    public: reverse_match_context(auto const& forward_context_);
#line 133 "cpp2regex.h2"
    public: auto operator=(auto const& forward_context_) -> reverse_match_context& ;

#line 139 "cpp2regex.h2"
    public: reverse_match_context(reverse_match_context const& that);
#line 139 "cpp2regex.h2"
    public: auto operator=(reverse_match_context const& that) -> reverse_match_context& ;
#line 139 "cpp2regex.h2"
    public: reverse_match_context(reverse_match_context&& that) noexcept;
#line 139 "cpp2regex.h2"
    public: auto operator=(reverse_match_context&& that) noexcept -> reverse_match_context& ;

    // String end and start positions
    //
    public: [[nodiscard]] auto get_string_start() const& -> decltype(auto);
    public: [[nodiscard]] auto get_string_end() const& -> decltype(auto);

    //  Getter and setter for groups
    //
    public: auto set_group_end(auto const& group, auto const& pos) & -> void;

#line 152 "cpp2regex.h2"
    public: auto set_group_invalid(auto const& group) & -> void;

#line 156 "cpp2regex.h2"
    public: auto set_group_start(auto const& group, auto const& pos) & -> void;

#line 160 "cpp2regex.h2"
    //  Misc functions
    //
    public: [[nodiscard]] auto fail() const& -> decltype(auto);
    public: [[nodiscard]] auto pass(cpp2::impl::in<ReverseIter> cur) const& -> decltype(auto);
};

//  Helpers for creating wrappers of the match context.
//
template<typename CharT, typename Iter, int max_groups> [[nodiscard]] auto make_forward_match_context(match_context<CharT,Iter,max_groups>& ctx) -> decltype(auto);

#line 172 "cpp2regex.h2"
template<typename CharT, typename Iter, int max_groups> [[nodiscard]] auto make_forward_match_context(reverse_match_context<CharT,Iter,max_groups>& ctx) -> decltype(auto);

#line 176 "cpp2regex.h2"
template<typename CharT, typename Iter, int max_groups> [[nodiscard]] auto make_reverse_match_context(match_context<CharT,Iter,max_groups>& ctx) -> auto;

#line 180 "cpp2regex.h2"
template<typename CharT, typename Iter, int max_groups> [[nodiscard]] auto make_reverse_match_context(reverse_match_context<CharT,Iter,max_groups>& ctx) -> decltype(auto);

#line 184 "cpp2regex.h2"
//  Helpers for creating wrappers of the iterators.
//
template               <typename Iter> [[nodiscard]] auto make_forward_iterator(Iter const& pos) -> auto;
template               <typename Iter> [[nodiscard]] auto make_forward_iterator(std::reverse_iterator<Iter> const& pos) -> auto;
template               <typename Iter> [[nodiscard]] auto make_reverse_iterator(Iter const& pos) -> auto;
template<typename Iter> [[nodiscard]] auto make_reverse_iterator(std::reverse_iterator<Iter> const& pos) -> auto;

#line 192 "cpp2regex.h2"
//  End function that returns a valid match.
//
class true_end_func
 {
    public: [[nodiscard]] auto operator()(auto const& cur, auto& ctx) const& -> decltype(auto);
};

#line 200 "cpp2regex.h2"
//  Empty group reset function.
//
class no_reset
 {
    public: auto operator()([[maybe_unused]] auto& unnamed_param_2) const& -> void;
};

#line 208 "cpp2regex.h2"
//  Evaluate func on destruction of the handle.
template<typename Func> class on_return
 {
    private: Func func; 

    public: on_return(Func const& f);
#line 213 "cpp2regex.h2"
    public: auto operator=(Func const& f) -> on_return& ;

#line 217 "cpp2regex.h2"
    public: ~on_return() noexcept;
    public: on_return(on_return const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(on_return const&) -> void = delete;


#line 220 "cpp2regex.h2"
};

#line 223 "cpp2regex.h2"
//  Helper for auto deduction of the Func type.
template<typename Func> [[nodiscard]] auto make_on_return(Func const& func) -> decltype(auto);

#line 227 "cpp2regex.h2"
//-----------------------------------------------------------------------
//
//  Character classes for regular expressions.
//
//-----------------------------------------------------------------------
//

//  Class syntax: <any character> Example: a
//
template<typename CharT, CharT C> class single_class_entry
 {
    public: [[nodiscard]] static auto includes(cpp2::impl::in<CharT> c) -> decltype(auto);
    public: [[nodiscard]] static auto to_string() -> decltype(auto);
    public: single_class_entry() = default;
    public: single_class_entry(single_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(single_class_entry const&) -> void = delete;

#line 240 "cpp2regex.h2"
};

#line 243 "cpp2regex.h2"
//  Class syntax: - Example: a-c
//
template<typename CharT, CharT Start, CharT End> class range_class_entry
 {
    public: [[nodiscard]] static auto includes(cpp2::impl::in<CharT> c) -> decltype(auto);
    public: [[nodiscard]] static auto to_string() -> decltype(auto);
    public: range_class_entry() = default;
    public: range_class_entry(range_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_class_entry const&) -> void = delete;

#line 249 "cpp2regex.h2"
};

#line 252 "cpp2regex.h2"
//  Helper for combining two character classes
//
template<typename CharT, typename ...List> class combined_class_entry
 {
    public: [[nodiscard]] static auto includes(cpp2::impl::in<CharT> c) -> decltype(auto);
    public: [[nodiscard]] static auto to_string() -> decltype(auto);
    public: combined_class_entry() = default;
    public: combined_class_entry(combined_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(combined_class_entry const&) -> void = delete;

#line 258 "cpp2regex.h2"
};

#line 261 "cpp2regex.h2"
//  Class syntax: <list of characters>  Example: abcd
//
template<typename CharT, CharT ...List> class list_class_entry
 {
    public: [[nodiscard]] static auto includes(cpp2::impl::in<CharT> c) -> decltype(auto);
    public: [[nodiscard]] static auto to_string() -> decltype(auto);
    public: list_class_entry() = default;
    public: list_class_entry(list_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(list_class_entry const&) -> void = delete;

#line 267 "cpp2regex.h2"
};

#line 270 "cpp2regex.h2"
//  Class syntax: [:<class name:]  Example: [:alnum:]
//
template<typename CharT, string_util::fixed_string Name, typename Inner> class named_class_entry
 {
    public: [[nodiscard]] static auto includes(cpp2::impl::in<CharT> c) -> decltype(auto);
    public: [[nodiscard]] static auto to_string() -> decltype(auto);
    public: named_class_entry() = default;
    public: named_class_entry(named_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(named_class_entry const&) -> void = delete;

#line 276 "cpp2regex.h2"
};

#line 279 "cpp2regex.h2"
template<typename CharT, typename Inner> class negated_class_entry
: public Inner {

    public: [[nodiscard]] static auto includes(cpp2::impl::in<CharT> c) -> decltype(auto);
    public: negated_class_entry() = default;
    public: negated_class_entry(negated_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(negated_class_entry const&) -> void = delete;

#line 283 "cpp2regex.h2"
};

#line 286 "cpp2regex.h2"
//  Short class syntax: \<character>  Example: \w
//
template<typename CharT, string_util::fixed_string Name, typename Inner> class shorthand_class_entry
 {
    public: [[nodiscard]] static auto includes(cpp2::impl::in<CharT> c) -> decltype(auto);
    public: [[nodiscard]] static auto to_string() -> decltype(auto);
    public: shorthand_class_entry() = default;
    public: shorthand_class_entry(shorthand_class_entry const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(shorthand_class_entry const&) -> void = delete;

#line 292 "cpp2regex.h2"
};

#line 295 "cpp2regex.h2"
//  Named basic character classes
//
template        <typename CharT> using digits_class = named_class_entry<CharT,"digits",range_class_entry<CharT,'0','9'>>;
template        <typename CharT> using lower_class = named_class_entry<CharT,"lower",range_class_entry<CharT,'a','z'>>;
template        <typename CharT> using upper_class = named_class_entry<CharT,"upper",range_class_entry<CharT,'A','Z'>>;

//  Named other classes
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

template                     <typename CharT> using short_not_digits_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\D",digits_class<CharT>>>;
template                     <typename CharT> using short_not_hor_space_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\H",hor_space_class<CharT>>>;
template                     <typename CharT> using short_not_space_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\S",space_class<CharT>>>;
template<typename CharT> using short_not_vert_space_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\V",ver_space_class<CharT>>>;
template                     <typename CharT> using short_not_word_class = negated_class_entry<CharT,shorthand_class_entry<CharT,"\\W",word_class<CharT>>>;

#line 332 "cpp2regex.h2"
//  Regex syntax: |  Example: ab|ba
//
//  Non greedy implementation. First alternative that matches is chosen.
//
template<typename CharT> class alternative_token_matcher
 {
    public: [[nodiscard]] static auto match(auto const& cur, auto& ctx, auto const& end_func, auto const& tail, auto const& ...functions) -> auto;

#line 342 "cpp2regex.h2"
    private: template<typename ...Other> [[nodiscard]] static auto match_first(auto const& cur, auto& ctx, auto const& end_func, auto const& tail, auto const& cur_func, auto const& cur_reset, Other const& ...other) -> auto;
    public: alternative_token_matcher() = default;
    public: alternative_token_matcher(alternative_token_matcher const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(alternative_token_matcher const&) -> void = delete;


#line 360 "cpp2regex.h2"
};

#line 363 "cpp2regex.h2"
//  Regex syntax: .
//
template<typename CharT, bool single_line> [[nodiscard]] auto any_token_matcher(auto& cur, auto& ctx) -> bool;

#line 377 "cpp2regex.h2"
//  Regex syntax: (?><matcher>)  Example: a(?>bc|c)c
//
template<typename CharT, typename Iter> [[nodiscard]] auto atomic_group_matcher(Iter const& cur, auto& ctx, auto const& inner, auto const& end_func, auto const& other) -> auto;

#line 391 "cpp2regex.h2"
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

#line 425 "cpp2regex.h2"
//  Regex syntax: [<character classes>]  Example: [abcx-y[:digits:]]
//
template<typename CharT, bool negate, bool case_insensitive, typename ...List> class class_token_matcher
 {
    public: [[nodiscard]] static auto match(auto& cur, auto& ctx) -> bool;

#line 458 "cpp2regex.h2"
    private: template<typename First, typename ...Other> [[nodiscard]] static auto match_any(cpp2::impl::in<CharT> c) -> bool;
    public: class_token_matcher() = default;
    public: class_token_matcher(class_token_matcher const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(class_token_matcher const&) -> void = delete;


#line 471 "cpp2regex.h2"
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
#line 482 "cpp2regex.h2"
};

#line 485 "cpp2regex.h2"
// Named short classes
//
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

#line 501 "cpp2regex.h2"
//  Regex syntax: \<number>  Example: \1
//                \g{name_or_number}
//                \k{name_or_number}
//                \k<name_or_number>
//                \k'name_or_number'
//
template<typename CharT, int group, bool case_insensitive, bool reverse> [[nodiscard]] auto group_ref_token_matcher(auto& cur, auto& ctx) -> bool;

#line 546 "cpp2regex.h2"
//  Regex syntax: $  Example: aa$
//
template<typename CharT, bool match_new_line, bool match_new_line_before_end> [[nodiscard]] auto line_end_token_matcher(auto const& cur, auto& ctx) -> bool;

#line 562 "cpp2regex.h2"
//  Regex syntax: ^  Example: ^aa
//
template<typename CharT, bool match_new_line> [[nodiscard]] auto line_start_token_matcher(auto const& cur, auto& ctx) -> bool;

#line 571 "cpp2regex.h2"
//  Regex syntax: (?=) or (?!) or (*pla), etc.  Example: (?=AA)
//
//  Parsed in group_token.
//
template<typename CharT, bool positive> [[nodiscard]] auto lookahead_token_matcher(auto const& cur, auto& ctx, auto const& func) -> bool;

#line 585 "cpp2regex.h2"
//  Regex syntax: (?<=) or (?<!) or (*plb), etc.  Example: (?<=AA)
//
//  Parsed in group_token.
//
template<typename CharT, bool positive> [[nodiscard]] auto lookbehind_token_matcher(auto const& cur, auto& ctx, auto const& func) -> bool;

#line 600 "cpp2regex.h2"
// TODO: @enum as template parameter currently not working. See issue https://github.com/hsutter/cppfront/issues/1147

#line 603 "cpp2regex.h2"
//  Options for range matching.
class range_flags {
    public: static const int not_greedy;// Try to take as few as possible.
    public: static const int greedy;// Try to take as many as possible.
    public: static const int possessive;// Do not give back after a greedy match. No backtracking.

    public: range_flags() = default;
    public: range_flags(range_flags const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_flags const&) -> void = delete;
};
#line 609 "cpp2regex.h2"

#line 611 "cpp2regex.h2"
//  Regex syntax: <matcher>{min, max}  Example: a{2,4}
//
template<typename CharT, int min_count, int max_count, int kind> class range_token_matcher
 {

    public: template<typename Iter> [[nodiscard]] static auto match(Iter const& cur, auto& ctx, auto const& inner, auto const& reset_func, auto const& end_func, auto const& tail) -> auto;

#line 629 "cpp2regex.h2"
    private: [[nodiscard]] static auto is_below_upper_bound(cpp2::impl::in<int> count) -> bool;

#line 634 "cpp2regex.h2"
    private: [[nodiscard]] static auto is_below_lower_bound(cpp2::impl::in<int> count) -> bool;

#line 639 "cpp2regex.h2"
    private: [[nodiscard]] static auto is_in_range(cpp2::impl::in<int> count) -> bool;

#line 645 "cpp2regex.h2"
    private: template<typename Iter> [[nodiscard]] static auto match_min_count(Iter const& cur, auto& ctx, auto const& inner, auto const& end_func, int& count_r) -> auto;

#line 661 "cpp2regex.h2"
    private: template<typename Iter> [[nodiscard]] static auto match_greedy(cpp2::impl::in<int> count, Iter const& cur, Iter const& last_valid, auto& ctx, auto const& inner, auto const& reset_func, auto const& end_func, auto const& other) -> match_return<Iter>;

#line 691 "cpp2regex.h2"
    private: template<typename Iter> [[nodiscard]] static auto match_possessive(Iter const& cur, auto& ctx, auto const& inner, auto const& end_func, auto const& other) -> match_return<Iter>;

#line 719 "cpp2regex.h2"
    private: template<typename Iter> [[nodiscard]] static auto match_not_greedy(Iter const& cur, auto& ctx, auto const& inner, auto const& end_func, auto const& other) -> match_return<Iter>;
    public: range_token_matcher() = default;
    public: range_token_matcher(range_token_matcher const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_token_matcher const&) -> void = delete;


#line 745 "cpp2regex.h2"
};

#line 748 "cpp2regex.h2"
//  Regex syntax: \b or \B  Example: \bword\b
//
//  Matches the start end end of word boundaries.
//
template<typename CharT, bool negate> [[nodiscard]] auto word_boundary_token_matcher(auto& cur, auto& ctx) -> bool;

#line 777 "cpp2regex.h2"
//-----------------------------------------------------------------------
//
//  Regular expression implementation.
//
//-----------------------------------------------------------------------
//

//  Regular expression implementation
template<typename CharT, typename matcher> class regular_expression
 {
    public: template<typename Iter> using context = matcher_context_type<matcher,Iter>;// TODO: Remove when nested types are allowed: https://github.com/hsutter/cppfront/issues/727

    public: template<typename Iter> class search_return
     {
        public: bool matched; 
        public: context<Iter> ctx; 
        public: int pos; 

        public: search_return(cpp2::impl::in<bool> matched_, context<Iter> const& ctx_, Iter const& pos_);

#line 801 "cpp2regex.h2"
        public: search_return(Iter const& begin, Iter const& end);

#line 807 "cpp2regex.h2"
        public: [[nodiscard]] auto group_number() const& -> decltype(auto);
        public: [[nodiscard]] auto group(cpp2::impl::in<int> g) const& -> decltype(auto);
        public: [[nodiscard]] auto group_start(cpp2::impl::in<int> g) const& -> decltype(auto);
        public: [[nodiscard]] auto group_end(cpp2::impl::in<int> g) const& -> decltype(auto);

        public: [[nodiscard]] auto group(cpp2::impl::in<bstring<CharT>> g) const& -> decltype(auto);
        public: [[nodiscard]] auto group_start(cpp2::impl::in<bstring<CharT>> g) const& -> decltype(auto);
        public: [[nodiscard]] auto group_end(cpp2::impl::in<bstring<CharT>> g) const& -> decltype(auto);

        public: auto update(cpp2::impl::in<match_return<Iter>> r) & -> void;

#line 821 "cpp2regex.h2"
        private: [[nodiscard]] auto get_group_id(cpp2::impl::in<bstring<CharT>> g) const& -> auto;
        public: search_return(search_return const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(search_return const&) -> void = delete;


#line 828 "cpp2regex.h2"
    };

    public: [[nodiscard]] auto find_all(auto&& func, cpp2::impl::in<bview<CharT>> str) const& -> decltype(auto);
    public: [[nodiscard]] auto find_all(auto&& func, cpp2::impl::in<bview<CharT>> str, cpp2::impl::in<int> start) const& -> decltype(auto);
    public: [[nodiscard]] auto find_all(auto&& func, cpp2::impl::in<bview<CharT>> str, cpp2::impl::in<int> start, cpp2::impl::in<int> length) const& -> decltype(auto);
    public: template<typename Iter> auto find_all(auto const& func, Iter const& start, Iter const& end) const& -> void;

#line 861 "cpp2regex.h2"
    public: [[nodiscard]] auto match(cpp2::impl::in<bview<CharT>> str) const& -> decltype(auto);
    public: [[nodiscard]] auto match(cpp2::impl::in<bview<CharT>> str, auto const& start) const& -> decltype(auto);
    public: [[nodiscard]] auto match(cpp2::impl::in<bview<CharT>> str, auto const& start, auto const& length) const& -> decltype(auto);
    public: template<typename Iter> [[nodiscard]] auto match(Iter const& start, Iter const& end) const& -> search_return<Iter>;

#line 872 "cpp2regex.h2"
    public: [[nodiscard]] auto search(cpp2::impl::in<bview<CharT>> str) const& -> decltype(auto);
    public: [[nodiscard]] auto search(cpp2::impl::in<bview<CharT>> str, auto const& start) const& -> decltype(auto);
    public: [[nodiscard]] auto search(cpp2::impl::in<bview<CharT>> str, auto const& start, auto const& length) const& -> decltype(auto);
    public: template<typename Iter> [[nodiscard]] auto search(Iter const& start, Iter const& end) const& -> search_return<Iter>;

#line 882 "cpp2regex.h2"
    private: template<typename Iter> [[nodiscard]] auto search_with_context(context<Iter>& ctx, Iter const& start) const& -> match_return<Iter>;

#line 907 "cpp2regex.h2"
    public: [[nodiscard]] auto to_string() const& -> decltype(auto);

    //  Helper functions
    //
    private: [[nodiscard]] static auto get_iter(cpp2::impl::in<bview<CharT>> str, auto const& pos) -> auto;
    public: regular_expression() = default;
    public: regular_expression(regular_expression const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regular_expression const&) -> void = delete;


#line 919 "cpp2regex.h2"
};

}
}
#endif


//=== Cpp2 function definitions =================================================

#line 1 "cpp2regex.h2"

#line 20 "cpp2regex.h2"
namespace cpp2 {

namespace regex {

template <typename Iter> match_group<Iter>::match_group(auto const& start_, auto const& end_, auto const& matched_)
                                                                 : start{ start_ }
                                                                 , end{ end_ }
                                                                 , matched{ matched_ }{}
template <typename Iter> match_group<Iter>::match_group(){}
template <typename Iter> match_return<Iter>::match_return(auto const& matched_, auto const& pos_)
                                                         : matched{ matched_ }
                                                         , pos{ pos_ }{}
template <typename Iter> match_return<Iter>::match_return(){}

#line 61 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> match_context<CharT,Iter,max_groups>::match_context(Iter const& begin_, Iter const& end_)
        : begin{ begin_ }
        , end{ end_ }{

#line 64 "cpp2regex.h2"
    }

#line 66 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> match_context<CharT,Iter,max_groups>::match_context(match_context const& that)
                                   : begin{ that.begin }
                                   , end{ that.end }
                                   , groups{ that.groups }{}
#line 66 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> auto match_context<CharT,Iter,max_groups>::operator=(match_context const& that) -> match_context& {
                                   begin = that.begin;
                                   end = that.end;
                                   groups = that.groups;
                                   return *this; }
#line 66 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> match_context<CharT,Iter,max_groups>::match_context(match_context&& that) noexcept
                                   : begin{ std::move(that).begin }
                                   , end{ std::move(that).end }
                                   , groups{ std::move(that).groups }{}
#line 66 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> auto match_context<CharT,Iter,max_groups>::operator=(match_context&& that) noexcept -> match_context& {
                                   begin = std::move(that).begin;
                                   end = std::move(that).end;
                                   groups = std::move(that).groups;
                                   return *this; }

#line 70 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> [[nodiscard]] auto match_context<CharT,Iter,max_groups>::get_string_start() const& -> decltype(auto) { return begin;  }
#line 71 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> [[nodiscard]] auto match_context<CharT,Iter,max_groups>::get_string_end() const& -> decltype(auto) { return end;  }

#line 75 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> [[nodiscard]] auto match_context<CharT,Iter,max_groups>::get_group(auto const& group) const& -> decltype(auto) { return CPP2_ASSERT_IN_BOUNDS(groups, group);  }

#line 77 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> [[nodiscard]] auto match_context<CharT,Iter,max_groups>::get_group_end(auto const& group) const& -> int{
        if (cpp2::impl::cmp_greater_eq(group,max_groups) || !(CPP2_ASSERT_IN_BOUNDS(groups, group).matched)) {
            return 0; 
        }
        return cpp2::unchecked_narrow<int>(std::distance(begin, CPP2_ASSERT_IN_BOUNDS(groups, group).end)); 
    }
#line 83 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> [[nodiscard]] auto match_context<CharT,Iter,max_groups>::get_group_start(auto const& group) const& -> int{
        if (cpp2::impl::cmp_greater_eq(group,max_groups) || !(CPP2_ASSERT_IN_BOUNDS(groups, group).matched)) {
            return 0; 
        }
        return cpp2::unchecked_narrow<int>(std::distance(begin, CPP2_ASSERT_IN_BOUNDS(groups, group).start)); 
    }
#line 89 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> [[nodiscard]] auto match_context<CharT,Iter,max_groups>::get_group_string(auto const& group) const& -> std::string{
        if (cpp2::impl::cmp_greater_eq(group,max_groups) || !(CPP2_ASSERT_IN_BOUNDS(groups, group).matched)) {
            return ""; 
        }
        return std::string(CPP2_ASSERT_IN_BOUNDS(groups, group).start, CPP2_ASSERT_IN_BOUNDS(groups, group).end); 
    }

#line 96 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> auto match_context<CharT,Iter,max_groups>::set_group_end(auto const& group, auto const& pos) & -> void{
        CPP2_ASSERT_IN_BOUNDS(groups, group).end = pos;
        CPP2_ASSERT_IN_BOUNDS(groups, group).matched = true;
    }

#line 101 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> auto match_context<CharT,Iter,max_groups>::set_group_invalid(auto const& group) & -> void{
        CPP2_ASSERT_IN_BOUNDS(groups, group).matched = false;
    }

#line 105 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> auto match_context<CharT,Iter,max_groups>::set_group_start(auto const& group, auto const& pos) & -> void{
        CPP2_ASSERT_IN_BOUNDS(groups, group).start = pos;
    }

#line 109 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> [[nodiscard]] auto match_context<CharT,Iter,max_groups>::size() const& -> decltype(auto) { return max_groups;  }

#line 113 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> [[nodiscard]] auto match_context<CharT,Iter,max_groups>::fail() const& -> decltype(auto) { return match_return<Iter>(false, end); }
#line 114 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> [[nodiscard]] auto match_context<CharT,Iter,max_groups>::pass(cpp2::impl::in<Iter> cur) const& -> decltype(auto) { return match_return<Iter>(true, cur);  }

#line 116 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> auto match_context<CharT,Iter,max_groups>::reset() & -> void{
        for ( auto& g : groups ) {
            g.matched = false;
        }
    }

#line 133 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> reverse_match_context<CharT,Iter,max_groups>::reverse_match_context(auto const& forward_context_)
        : forward_context{ forward_context_ }
        , begin{ std::make_reverse_iterator((*cpp2::impl::assert_not_null(forward_context)).end) }
        , end{ std::make_reverse_iterator((*cpp2::impl::assert_not_null(forward_context)).begin) }{

#line 137 "cpp2regex.h2"
    }
#line 133 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> auto reverse_match_context<CharT,Iter,max_groups>::operator=(auto const& forward_context_) -> reverse_match_context& {
        forward_context = forward_context_;
        begin = std::make_reverse_iterator((*cpp2::impl::assert_not_null(forward_context)).end);
        end = std::make_reverse_iterator((*cpp2::impl::assert_not_null(forward_context)).begin);
        return *this;

#line 137 "cpp2regex.h2"
    }

#line 139 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> reverse_match_context<CharT,Iter,max_groups>::reverse_match_context(reverse_match_context const& that)
                                   : forward_context{ that.forward_context }
                                   , begin{ that.begin }
                                   , end{ that.end }{}
#line 139 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> auto reverse_match_context<CharT,Iter,max_groups>::operator=(reverse_match_context const& that) -> reverse_match_context& {
                                   forward_context = that.forward_context;
                                   begin = that.begin;
                                   end = that.end;
                                   return *this; }
#line 139 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> reverse_match_context<CharT,Iter,max_groups>::reverse_match_context(reverse_match_context&& that) noexcept
                                   : forward_context{ std::move(that).forward_context }
                                   , begin{ std::move(that).begin }
                                   , end{ std::move(that).end }{}
#line 139 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> auto reverse_match_context<CharT,Iter,max_groups>::operator=(reverse_match_context&& that) noexcept -> reverse_match_context& {
                                   forward_context = std::move(that).forward_context;
                                   begin = std::move(that).begin;
                                   end = std::move(that).end;
                                   return *this; }

#line 143 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> [[nodiscard]] auto reverse_match_context<CharT,Iter,max_groups>::get_string_start() const& -> decltype(auto) { return end;  }
#line 144 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> [[nodiscard]] auto reverse_match_context<CharT,Iter,max_groups>::get_string_end() const& -> decltype(auto) { return begin;  }

#line 148 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> auto reverse_match_context<CharT,Iter,max_groups>::set_group_end(auto const& group, auto const& pos) & -> void{
        (*cpp2::impl::assert_not_null(forward_context)).set_group_end(group, CPP2_UFCS(base)((pos)));
    }

#line 152 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> auto reverse_match_context<CharT,Iter,max_groups>::set_group_invalid(auto const& group) & -> void{
        (*cpp2::impl::assert_not_null(forward_context)).set_group_invalid(group);
    }

#line 156 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> auto reverse_match_context<CharT,Iter,max_groups>::set_group_start(auto const& group, auto const& pos) & -> void{
        (*cpp2::impl::assert_not_null(forward_context)).set_group_start(group, CPP2_UFCS(base)((pos)));
    }

#line 162 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> [[nodiscard]] auto reverse_match_context<CharT,Iter,max_groups>::fail() const& -> decltype(auto) { return match_return<ReverseIter>(false, end); }
#line 163 "cpp2regex.h2"
    template <typename CharT, typename Iter, int max_groups> [[nodiscard]] auto reverse_match_context<CharT,Iter,max_groups>::pass(cpp2::impl::in<ReverseIter> cur) const& -> decltype(auto) { return match_return<ReverseIter>(true, cur);  }

#line 168 "cpp2regex.h2"
template<typename CharT, typename Iter, int max_groups> [[nodiscard]] auto make_forward_match_context(match_context<CharT,Iter,max_groups>& ctx) -> decltype(auto){
    return ctx; 
}

#line 172 "cpp2regex.h2"
template<typename CharT, typename Iter, int max_groups> [[nodiscard]] auto make_forward_match_context(reverse_match_context<CharT,Iter,max_groups>& ctx) -> decltype(auto){
    return *cpp2::impl::assert_not_null(ctx.forward_context); 
}

#line 176 "cpp2regex.h2"
template<typename CharT, typename Iter, int max_groups> [[nodiscard]] auto make_reverse_match_context(match_context<CharT,Iter,max_groups>& ctx) -> auto{
    return reverse_match_context<CharT,Iter,max_groups>(&ctx); 
}

#line 180 "cpp2regex.h2"
template<typename CharT, typename Iter, int max_groups> [[nodiscard]] auto make_reverse_match_context(reverse_match_context<CharT,Iter,max_groups>& ctx) -> decltype(auto){
    return ctx; 
}

#line 186 "cpp2regex.h2"
template               <typename Iter> [[nodiscard]] auto make_forward_iterator(Iter const& pos) -> auto { return pos; }
#line 187 "cpp2regex.h2"
template               <typename Iter> [[nodiscard]] auto make_forward_iterator(std::reverse_iterator<Iter> const& pos) -> auto { return CPP2_UFCS(base)(pos); }
#line 188 "cpp2regex.h2"
template               <typename Iter> [[nodiscard]] auto make_reverse_iterator(Iter const& pos) -> auto { return std::make_reverse_iterator(pos); }
#line 189 "cpp2regex.h2"
template<typename Iter> [[nodiscard]] auto make_reverse_iterator(std::reverse_iterator<Iter> const& pos) -> auto { return pos;  }

#line 196 "cpp2regex.h2"
    [[nodiscard]] auto true_end_func::operator()(auto const& cur, auto& ctx) const& -> decltype(auto) { return ctx.pass(cur);  }

#line 204 "cpp2regex.h2"
    auto no_reset::operator()([[maybe_unused]] auto& unnamed_param_2) const& -> void{}

#line 213 "cpp2regex.h2"
    template <typename Func> on_return<Func>::on_return(Func const& f)
        : func{ f }{

#line 215 "cpp2regex.h2"
    }
#line 213 "cpp2regex.h2"
    template <typename Func> auto on_return<Func>::operator=(Func const& f) -> on_return& {
        func = f;
        return *this;

#line 215 "cpp2regex.h2"
    }

#line 217 "cpp2regex.h2"
    template <typename Func> on_return<Func>::~on_return() noexcept{
        cpp2::move(*this).func();
    }

#line 224 "cpp2regex.h2"
template<typename Func> [[nodiscard]] auto make_on_return(Func const& func) -> decltype(auto) { return on_return<Func>(func);  }

#line 238 "cpp2regex.h2"
    template <typename CharT, CharT C> [[nodiscard]] auto single_class_entry<CharT,C>::includes(cpp2::impl::in<CharT> c) -> decltype(auto) { return c == C;  }
#line 239 "cpp2regex.h2"
    template <typename CharT, CharT C> [[nodiscard]] auto single_class_entry<CharT,C>::to_string() -> decltype(auto) { return bstring<CharT>(1, C); }

#line 247 "cpp2regex.h2"
    template <typename CharT, CharT Start, CharT End> [[nodiscard]] auto range_class_entry<CharT,Start,End>::includes(cpp2::impl::in<CharT> c) -> decltype(auto) { return [_0 = Start, _1 = c, _2 = End]{ return cpp2::impl::cmp_less_eq(_0,_1) && cpp2::impl::cmp_less_eq(_1,_2); }();  }
#line 248 "cpp2regex.h2"
    template <typename CharT, CharT Start, CharT End> [[nodiscard]] auto range_class_entry<CharT,Start,End>::to_string() -> decltype(auto) { return "" + cpp2::to_string(Start) + "-" + cpp2::to_string(End) + ""; }

#line 256 "cpp2regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto combined_class_entry<CharT,List...>::includes(cpp2::impl::in<CharT> c) -> decltype(auto) { return (false || ... || List::includes(c));  }
#line 257 "cpp2regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto combined_class_entry<CharT,List...>::to_string() -> decltype(auto) { return (bstring<CharT>() + ... + List::to_string()); }

#line 265 "cpp2regex.h2"
    template <typename CharT, CharT ...List> [[nodiscard]] auto list_class_entry<CharT,List...>::includes(cpp2::impl::in<CharT> c) -> decltype(auto) { return (false || ... || (List == c));  }
#line 266 "cpp2regex.h2"
    template <typename CharT, CharT ...List> [[nodiscard]] auto list_class_entry<CharT,List...>::to_string() -> decltype(auto) { return (bstring<CharT>() + ... + List); }

#line 274 "cpp2regex.h2"
    template <typename CharT, string_util::fixed_string Name, typename Inner> [[nodiscard]] auto named_class_entry<CharT,Name,Inner>::includes(cpp2::impl::in<CharT> c) -> decltype(auto) { return Inner::includes(c);  }
#line 275 "cpp2regex.h2"
    template <typename CharT, string_util::fixed_string Name, typename Inner> [[nodiscard]] auto named_class_entry<CharT,Name,Inner>::to_string() -> decltype(auto) { return "[:" + cpp2::to_string(Name.data()) + ":]"; }

#line 282 "cpp2regex.h2"
    template <typename CharT, typename Inner> [[nodiscard]] auto negated_class_entry<CharT,Inner>::includes(cpp2::impl::in<CharT> c) -> decltype(auto) { return !(Inner::includes(c));  }

#line 290 "cpp2regex.h2"
    template <typename CharT, string_util::fixed_string Name, typename Inner> [[nodiscard]] auto shorthand_class_entry<CharT,Name,Inner>::includes(cpp2::impl::in<CharT> c) -> decltype(auto) { return Inner::includes(c);  }
#line 291 "cpp2regex.h2"
    template <typename CharT, string_util::fixed_string Name, typename Inner> [[nodiscard]] auto shorthand_class_entry<CharT,Name,Inner>::to_string() -> decltype(auto) { return Name.str(); }

#line 338 "cpp2regex.h2"
    template <typename CharT> [[nodiscard]] auto alternative_token_matcher<CharT>::match(auto const& cur, auto& ctx, auto const& end_func, auto const& tail, auto const& ...functions) -> auto{
        return match_first(cur, ctx, end_func, tail, functions...); 
    }

#line 342 "cpp2regex.h2"
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

#line 365 "cpp2regex.h2"
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

#line 379 "cpp2regex.h2"
template<typename CharT, typename Iter> [[nodiscard]] auto atomic_group_matcher(Iter const& cur, auto& ctx, auto const& inner, auto const& end_func, auto const& other) -> auto
{
    auto r {inner(cur, ctx, true_end_func())}; 

    if (r.matched) {
        r = other(r.pos, ctx, end_func);
    }

    return r; 
}

#line 429 "cpp2regex.h2"
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

#line 458 "cpp2regex.h2"
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

#line 507 "cpp2regex.h2"
template<typename CharT, int group, bool case_insensitive, bool reverse> [[nodiscard]] auto group_ref_token_matcher(auto& cur, auto& ctx) -> bool
{
    auto g {ctx.get_group(group)}; 

    auto group_pos {g.start}; 
    auto group_end {g.end}; 
    int group_inc {1}; 
    if (reverse) {
        group_pos = g.end;
        group_end = cpp2::move(g).start;
        group_inc = -1;
    }

    for( ; 
        group_pos != group_end 
        && cur != ctx.end; 
    (group_pos += group_inc, ++cur) ) 
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

    if (cpp2::move(group_pos) == cpp2::move(group_end)) {
        return true; 
    }
    else {
        return false; 
    }
}

#line 548 "cpp2regex.h2"
template<typename CharT, bool match_new_line, bool match_new_line_before_end> [[nodiscard]] auto line_end_token_matcher(auto const& cur, auto& ctx) -> bool
{
    if (cur == CPP2_UFCS(get_string_end)(ctx) || (match_new_line && *cpp2::impl::assert_not_null(cur) == '\n')) {
        return true; 
    }
    else {if (match_new_line_before_end && (*cpp2::impl::assert_not_null(cur) == '\n' && (cur + 1) == CPP2_UFCS(get_string_end)(ctx))) {// Special case for new line at end.
        return true; 
    }
    else {
        return false; 
    }}
}

#line 564 "cpp2regex.h2"
template<typename CharT, bool match_new_line> [[nodiscard]] auto line_start_token_matcher(auto const& cur, auto& ctx) -> bool
{
    return cur == CPP2_UFCS(get_string_start)(ctx) || // Start of string
           (match_new_line && *cpp2::impl::assert_not_null((cur - 1)) == '\n'); // Start of new line
}

#line 575 "cpp2regex.h2"
template<typename CharT, bool positive> [[nodiscard]] auto lookahead_token_matcher(auto const& cur, auto& ctx, auto const& func) -> bool
{
    auto r {func(make_forward_iterator(cur), make_forward_match_context(ctx), true_end_func())}; 
    if (!(positive)) {
        r.matched = !(r.matched);
    }

    return cpp2::move(r).matched; 
}

#line 589 "cpp2regex.h2"
template<typename CharT, bool positive> [[nodiscard]] auto lookbehind_token_matcher(auto const& cur, auto& ctx, auto const& func) -> bool
{
    auto r {func(make_reverse_iterator(cur), make_reverse_match_context(ctx), true_end_func())}; 
    if (!(positive)) {
        r.matched = !(r.matched);
    }

    return cpp2::move(r).matched; 
}

#line 605 "cpp2regex.h2"
    inline CPP2_CONSTEXPR int range_flags::not_greedy{ 1 };
    inline CPP2_CONSTEXPR int range_flags::greedy{ 2 };
    inline CPP2_CONSTEXPR int range_flags::possessive{ 3 };

#line 616 "cpp2regex.h2"
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

#line 629 "cpp2regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::is_below_upper_bound(cpp2::impl::in<int> count) -> bool{
        if (-1 == max_count) {return true; }
        else {return cpp2::impl::cmp_less(count,max_count); }
    }

#line 634 "cpp2regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::is_below_lower_bound(cpp2::impl::in<int> count) -> bool{
        if (-1 == min_count) {return false; }
        else {return cpp2::impl::cmp_less(count,min_count); }
    }

#line 639 "cpp2regex.h2"
    template <typename CharT, int min_count, int max_count, int kind> [[nodiscard]] auto range_token_matcher<CharT,min_count,max_count,kind>::is_in_range(cpp2::impl::in<int> count) -> bool{
        if (-1 != min_count && cpp2::impl::cmp_less(count,min_count)) {return false; }
        if (-1 != max_count && cpp2::impl::cmp_greater(count,max_count)) {return false; }
        return true; 
    }

#line 645 "cpp2regex.h2"
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

#line 661 "cpp2regex.h2"
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

#line 691 "cpp2regex.h2"
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

#line 719 "cpp2regex.h2"
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

#line 752 "cpp2regex.h2"
template<typename CharT, bool negate> [[nodiscard]] auto word_boundary_token_matcher(auto& cur, auto& ctx) -> bool
{
    word_class<CharT> words {}; 
    auto is_match {false}; 
    if (cur == ctx.begin) {// Iteration start
        if (cur != ctx.end) {// No empty string
            is_match = cpp2::move(words).includes(*cpp2::impl::assert_not_null(cur));
        }
    }
    else {if (cur == ctx.end) {// Iteration end
        is_match = cpp2::move(words).includes(*cpp2::impl::assert_not_null((cur - 1)));
    }
    else { // Middle of iteration
        is_match = 
                (words.includes(*cpp2::impl::assert_not_null((cur - 1))) && !(words.includes(*cpp2::impl::assert_not_null(cur)))) // End of word: \w\W
            || (!(words.includes(*cpp2::impl::assert_not_null((cur - 1)))) && words.includes(*cpp2::impl::assert_not_null(cur)));// Start of word: \W\w
    }}
    if (negate) {
        is_match = !(is_match);
    }

    return is_match; 
}

#line 795 "cpp2regex.h2"
        template <typename CharT, typename matcher> template <typename Iter> regular_expression<CharT,matcher>::search_return<Iter>::search_return(cpp2::impl::in<bool> matched_, context<Iter> const& ctx_, Iter const& pos_)
            : matched{ matched_ }
            , ctx{ ctx_ }
            , pos{ cpp2::unchecked_narrow<int>(std::distance(ctx_.begin, pos_)) }{

#line 799 "cpp2regex.h2"
        }

#line 801 "cpp2regex.h2"
        template <typename CharT, typename matcher> template <typename Iter> regular_expression<CharT,matcher>::search_return<Iter>::search_return(Iter const& begin, Iter const& end)
            : matched{ false }
            , ctx{ begin, end }
            , pos{ 0 }{

#line 805 "cpp2regex.h2"
        }

#line 807 "cpp2regex.h2"
        template <typename CharT, typename matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,matcher>::search_return<Iter>::group_number() const& -> decltype(auto) { return ctx.size(); }
#line 808 "cpp2regex.h2"
        template <typename CharT, typename matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,matcher>::search_return<Iter>::group(cpp2::impl::in<int> g) const& -> decltype(auto) { return ctx.get_group_string(g); }
#line 809 "cpp2regex.h2"
        template <typename CharT, typename matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,matcher>::search_return<Iter>::group_start(cpp2::impl::in<int> g) const& -> decltype(auto) { return ctx.get_group_start(g); }
#line 810 "cpp2regex.h2"
        template <typename CharT, typename matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,matcher>::search_return<Iter>::group_end(cpp2::impl::in<int> g) const& -> decltype(auto) { return ctx.get_group_end(g); }

#line 812 "cpp2regex.h2"
        template <typename CharT, typename matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,matcher>::search_return<Iter>::group(cpp2::impl::in<bstring<CharT>> g) const& -> decltype(auto) { return group(get_group_id(g)); }
#line 813 "cpp2regex.h2"
        template <typename CharT, typename matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,matcher>::search_return<Iter>::group_start(cpp2::impl::in<bstring<CharT>> g) const& -> decltype(auto) { return group_start(get_group_id(g)); }
#line 814 "cpp2regex.h2"
        template <typename CharT, typename matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,matcher>::search_return<Iter>::group_end(cpp2::impl::in<bstring<CharT>> g) const& -> decltype(auto) { return group_end(get_group_id(g)); }

#line 816 "cpp2regex.h2"
        template <typename CharT, typename matcher> template <typename Iter> auto regular_expression<CharT,matcher>::search_return<Iter>::update(cpp2::impl::in<match_return<Iter>> r) & -> void{
            matched = r.matched;
            pos     = cpp2::unchecked_narrow<int>(std::distance(ctx.begin, r.pos));
        }

#line 821 "cpp2regex.h2"
        template <typename CharT, typename matcher> template <typename Iter> [[nodiscard]] auto regular_expression<CharT,matcher>::search_return<Iter>::get_group_id(cpp2::impl::in<bstring<CharT>> g) const& -> auto{
            auto group_id {matcher::get_named_group_index(g)}; 
            if (-1 == group_id) {
                // TODO: Throw error.
            }
            return group_id; 
        }

#line 830 "cpp2regex.h2"
    template <typename CharT, typename matcher> [[nodiscard]] auto regular_expression<CharT,matcher>::find_all(auto&& func, cpp2::impl::in<bview<CharT>> str) const& -> decltype(auto) { return find_all(CPP2_FORWARD(func), str.begin(), str.end()); }
#line 831 "cpp2regex.h2"
    template <typename CharT, typename matcher> [[nodiscard]] auto regular_expression<CharT,matcher>::find_all(auto&& func, cpp2::impl::in<bview<CharT>> str, cpp2::impl::in<int> start) const& -> decltype(auto) { return find_all(CPP2_FORWARD(func), get_iter(str, start), str.end()); }
#line 832 "cpp2regex.h2"
    template <typename CharT, typename matcher> [[nodiscard]] auto regular_expression<CharT,matcher>::find_all(auto&& func, cpp2::impl::in<bview<CharT>> str, cpp2::impl::in<int> start, cpp2::impl::in<int> length) const& -> decltype(auto) { return find_all(CPP2_FORWARD(func), get_iter(str, start), get_iter(str, start + length));  }
#line 833 "cpp2regex.h2"
    template <typename CharT, typename matcher> template<typename Iter> auto regular_expression<CharT,matcher>::find_all(auto const& func, Iter const& start, Iter const& end) const& -> void
    {
        auto sr {search_return<Iter>(start, end)}; 
        auto cont {true}; 
        auto cur {start}; 

        while( cont ) {
            auto r {search_with_context(sr.ctx, cur)}; 
            cont = r.matched; // First update the continue so that the user can override it.

            if (r.matched) {
                sr.update(cpp2::move(r));
                cont = func(sr);
            }

            if (cont) {
                // Prevent infinity loop for zero length match.
                cont = 0 != sr.ctx.get_group_end(0) - sr.ctx.get_group_start(0);
            }

            // Check now if to continue, user may override
            if (cont) {
                cur = start + sr.ctx.get_group_end(0);
                CPP2_UFCS(reset)(sr.ctx);
            }
        }
    }

#line 861 "cpp2regex.h2"
    template <typename CharT, typename matcher> [[nodiscard]] auto regular_expression<CharT,matcher>::match(cpp2::impl::in<bview<CharT>> str) const& -> decltype(auto) { return match(str.begin(), str.end()); }
#line 862 "cpp2regex.h2"
    template <typename CharT, typename matcher> [[nodiscard]] auto regular_expression<CharT,matcher>::match(cpp2::impl::in<bview<CharT>> str, auto const& start) const& -> decltype(auto) { return match(get_iter(str, start), str.end()); }
#line 863 "cpp2regex.h2"
    template <typename CharT, typename matcher> [[nodiscard]] auto regular_expression<CharT,matcher>::match(cpp2::impl::in<bview<CharT>> str, auto const& start, auto const& length) const& -> decltype(auto) { return match(get_iter(str, start), get_iter(str, start + length));  }
#line 864 "cpp2regex.h2"
    template <typename CharT, typename matcher> template<typename Iter> [[nodiscard]] auto regular_expression<CharT,matcher>::match(Iter const& start, Iter const& end) const& -> search_return<Iter>
    {
        context<Iter> ctx {start, end}; 

        auto r {matcher::entry(start, ctx)}; 
        return search_return<Iter>(r.matched && r.pos == end, cpp2::move(ctx), r.pos); 
    }

#line 872 "cpp2regex.h2"
    template <typename CharT, typename matcher> [[nodiscard]] auto regular_expression<CharT,matcher>::search(cpp2::impl::in<bview<CharT>> str) const& -> decltype(auto) { return search(str.begin(), str.end()); }
#line 873 "cpp2regex.h2"
    template <typename CharT, typename matcher> [[nodiscard]] auto regular_expression<CharT,matcher>::search(cpp2::impl::in<bview<CharT>> str, auto const& start) const& -> decltype(auto) { return search(get_iter(str, start), str.end()); }
#line 874 "cpp2regex.h2"
    template <typename CharT, typename matcher> [[nodiscard]] auto regular_expression<CharT,matcher>::search(cpp2::impl::in<bview<CharT>> str, auto const& start, auto const& length) const& -> decltype(auto) { return search(get_iter(str, start), get_iter(str, start + length));  }
#line 875 "cpp2regex.h2"
    template <typename CharT, typename matcher> template<typename Iter> [[nodiscard]] auto regular_expression<CharT,matcher>::search(Iter const& start, Iter const& end) const& -> search_return<Iter>
    {
        context<Iter> ctx {start, end}; 
        auto r {search_with_context(ctx, start)}; 
        return search_return<Iter>(r.matched, cpp2::move(ctx), cpp2::move(r).pos); 
    }

#line 882 "cpp2regex.h2"
    template <typename CharT, typename matcher> template<typename Iter> [[nodiscard]] auto regular_expression<CharT,matcher>::search_with_context(context<Iter>& ctx, Iter const& start) const& -> match_return<Iter>
    {
        auto r {ctx.fail()}; 

        auto cur {start}; 
        for( ; true; (++cur) ) {
            r = matcher::entry(cur, ctx);
            if (r.matched) {
                break;
            }

            if (cur == ctx.end) {
                break;
            }

            if (matcher::is_start_match()) {
                break; // Always break with \G option.
            }
        }

        return r; 
    }

#line 907 "cpp2regex.h2"
    template <typename CharT, typename matcher> [[nodiscard]] auto regular_expression<CharT,matcher>::to_string() const& -> decltype(auto) { return matcher::to_string();  }

#line 911 "cpp2regex.h2"
    template <typename CharT, typename matcher> [[nodiscard]] auto regular_expression<CharT,matcher>::get_iter(cpp2::impl::in<bview<CharT>> str, auto const& pos) -> auto{
        if (cpp2::impl::cmp_less(pos,str.size())) {
            return str.begin() + pos; 
        }
        else {
            return str.end(); 
        }
    }

#line 921 "cpp2regex.h2"
}
}

#endif
