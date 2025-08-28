#line 13 "reflect.h2"
#include "parse.h"
#include "cpp2regex.h"

#ifndef REFLECT_H_CPP2
#define REFLECT_H_CPP2


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "reflect.h2"

#line 17 "reflect.h2"
namespace cpp2 {

namespace meta {

#line 29 "reflect.h2"
class compiler_services;

#line 212 "reflect.h2"
template<typename T> class reflection_base;

#line 248 "reflect.h2"
class declaration;

#line 333 "reflect.h2"
class function_declaration;

#line 438 "reflect.h2"
class object_declaration;

#line 474 "reflect.h2"
class type_or_namespace_declaration;

#line 585 "reflect.h2"
class type_declaration;

#line 629 "reflect.h2"
class namespace_declaration;

#line 648 "reflect.h2"
class alias_declaration;

#line 667 "reflect.h2"
class parameter_declaration;

#line 713 "reflect.h2"
template<String Name, typename Term> class binary_expression;

#line 840 "reflect.h2"
class expression_list;

#line 873 "reflect.h2"
class prefix_expression;

#line 915 "reflect.h2"
class postfix_expression;

#line 986 "reflect.h2"
class template_arg;

#line 1012 "reflect.h2"
class unqualified_id;

#line 1044 "reflect.h2"
class qualified_id;

#line 1088 "reflect.h2"
class type_id;

#line 1131 "reflect.h2"
class primary_expression;

#line 1170 "reflect.h2"
class id_expression;

#line 1206 "reflect.h2"
class expression;

#line 1257 "reflect.h2"
class is_as_expression;

#line 1318 "reflect.h2"
class statement;

#line 1360 "reflect.h2"
class expression_statement;

#line 1382 "reflect.h2"
class compound_statement;

#line 1421 "reflect.h2"
class selection_statement;

#line 1447 "reflect.h2"
class return_statement;

#line 1469 "reflect.h2"
class iteration_statement;

#line 1966 "reflect.h2"
class value_member_info;

#line 2607 "reflect.h2"
class simple_traverser;

#line 4091 "reflect.h2"
class autodiff_special_func;

#line 4127 "reflect.h2"
class autodiff_declared_variable;

#line 4145 "reflect.h2"
class autodiff_declaration_stack_item;

#line 4184 "reflect.h2"
class autodiff_context;
    

#line 4547 "reflect.h2"
class autodiff_diff_code;
    

#line 4595 "reflect.h2"
class autodiff_activity_check;
    

#line 4681 "reflect.h2"
class autodiff_handler_base;
    

#line 4699 "reflect.h2"
class autodiff_expression_handler;
    

#line 5286 "reflect.h2"
class autodiff_stmt_handler;

#line 5569 "reflect.h2"
class autodiff_declaration_handler;

#line 5914 "reflect.h2"
class expression_flags;

#line 5930 "reflect.h2"
class regex_token;

#line 5957 "reflect.h2"
class regex_token_check;

#line 5978 "reflect.h2"
class regex_token_code;

#line 5999 "reflect.h2"
class regex_token_empty;

#line 6017 "reflect.h2"
class regex_token_list;

#line 6069 "reflect.h2"
class parse_context_group_state;

#line 6130 "reflect.h2"
class parse_context_branch_reset_state;

#line 6173 "reflect.h2"
class parse_context;

#line 6574 "reflect.h2"
class generation_function_context;
    

#line 6592 "reflect.h2"
class generation_context;

#line 6791 "reflect.h2"
class alternative_token;

#line 6806 "reflect.h2"
class alternative_token_gen;

#line 6871 "reflect.h2"
class any_token;

#line 6888 "reflect.h2"
class atomic_group_token;

#line 6918 "reflect.h2"
class char_token;

#line 7033 "reflect.h2"
class class_token;

#line 7257 "reflect.h2"
class group_ref_token;

#line 7394 "reflect.h2"
class group_token;

#line 7741 "reflect.h2"
class lookahead_lookbehind_token;

#line 7836 "reflect.h2"
class range_token;

#line 7993 "reflect.h2"
class special_range_token;

#line 8079 "reflect.h2"
template<typename Error_out> class regex_generator;

#line 8342 "reflect.h2"
}

}


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "reflect.h2"

//  Copyright 2022-2025 Herb Sutter
//  SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//  
//  Part of the Cppfront Project, under the Apache License v2.0 with LLVM Exceptions.
//  See https://github.com/hsutter/cppfront/blob/main/LICENSE for license information.


//===========================================================================
//  Reflection and meta
//===========================================================================

#line 15 "reflect.h2"
using namespace cpp2::regex;

#line 17 "reflect.h2"
namespace cpp2 {

namespace meta {

#line 29 "reflect.h2"
class compiler_services
 {

#line 33 "reflect.h2"
    private: std::vector<error_entry>* errors; 
    private: std::set<std::string>* includes; 
    private: std::vector<std::string>* extra_cpp1; 
    private: std::vector<std::string>* extra_build; 
    private: std::string file_name; 
    private: int errors_original_size; 
    private: stable_vector<token>* generated_tokens; 
    private: cpp2::parser parser; 
    private: std::string metafunction_name {}; 
    private: std::vector<std::string> metafunction_args {}; 
    private: bool metafunctions_used {false}; 

#line 47 "reflect.h2"
    public: compiler_services(

        cpp2::impl::in<std::vector<error_entry>*> errors_, 
        cpp2::impl::in<std::set<std::string>*> includes_, 
        cpp2::impl::in<std::vector<std::string>*> extra_cpp1_, 
        cpp2::impl::in<std::vector<std::string>*> extra_build_, 
        cpp2::impl::in<std::string> filename, 
        cpp2::impl::in<stable_vector<token>*> generated_tokens_
    );

#line 69 "reflect.h2"
    public: [[nodiscard]] auto filename() const& -> std::string_view;

    public: auto set_metafunction_name(cpp2::impl::in<std::string_view> name, cpp2::impl::in<std::vector<std::string>> args) & -> void;

#line 77 "reflect.h2"
    public: [[nodiscard]] auto get_metafunction_name() const& -> std::string_view;

    public: [[nodiscard]] auto get_argument(cpp2::impl::in<int> index) & -> std::string;

#line 87 "reflect.h2"
    public: [[nodiscard]] auto get_arguments() & -> std::vector<std::string>;

#line 92 "reflect.h2"
    public: [[nodiscard]] auto arguments_were_used() const& -> bool;
using parse_statement_ret = std::unique_ptr<statement_node>;


#line 94 "reflect.h2"
    protected: [[nodiscard]] auto parse_statement(

        std::string_view source
    ) & -> parse_statement_ret;

#line 147 "reflect.h2"
    public: auto add_runtime_support_include(cpp2::impl::in<std::string_view> s, cpp2::impl::in<bool> angles = false) & -> void;

#line 158 "reflect.h2"
    public: [[nodiscard]] auto add_extra_cpp1_code(cpp2::impl::in<std::string> s) & -> decltype(auto);
    public: [[nodiscard]] auto add_extra_build_step(cpp2::impl::in<std::string> s) & -> decltype(auto);

    public: [[nodiscard]] virtual auto position() const -> source_position;

#line 170 "reflect.h2"
    public: auto require(

        cpp2::impl::in<bool> b, 
        cpp2::impl::in<std::string_view> msg
    ) const& -> void;

#line 181 "reflect.h2"
    public: auto error(cpp2::impl::in<std::string_view> msg) const& -> void;

#line 193 "reflect.h2"
    public: auto report_violation(auto const& msg) const& -> void;

#line 201 "reflect.h2"
    public: [[nodiscard]] auto is_active() const& -> decltype(auto);
    public: virtual ~compiler_services() noexcept;
public: compiler_services(compiler_services const& that);
public: compiler_services(compiler_services&& that) noexcept;

#line 202 "reflect.h2"
};

#line 212 "reflect.h2"
template<typename T> class reflection_base
: public compiler_services {

#line 216 "reflect.h2"
    protected: T* n; 

    protected: reflection_base(

        cpp2::impl::in<T*> n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 229 "reflect.h2"
    public: [[nodiscard]] auto position() const -> source_position override;

    public: [[nodiscard]] auto print() const& -> std::string;

    public: [[nodiscard]] auto is_same(cpp2::impl::in<reflection_base> o) const& -> bool;
    public: template<typename TO> [[nodiscard]] auto is_same(reflection_base<TO> const& o) const& -> bool;
    public: virtual ~reflection_base() noexcept;
public: reflection_base(reflection_base const& that);
public: reflection_base(reflection_base&& that) noexcept;

#line 235 "reflect.h2"
};

#line 248 "reflect.h2"
class declaration
: public reflection_base<declaration_node> {

#line 252 "reflect.h2"
    public: declaration(

        cpp2::impl::in<declaration_node*> n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 261 "reflect.h2"
    public: [[nodiscard]] auto is_public() const& -> bool;
    public: [[nodiscard]] auto is_protected() const& -> bool;
    public: [[nodiscard]] auto is_private() const& -> bool;
    public: [[nodiscard]] auto is_default_access() const& -> bool;

    public: [[nodiscard]] auto default_to_public() & -> decltype(auto);
    public: [[nodiscard]] auto default_to_protected() & -> decltype(auto);
    public: [[nodiscard]] auto default_to_private() & -> decltype(auto);

    public: [[nodiscard]] auto make_public() & -> bool;
    public: [[nodiscard]] auto make_protected() & -> bool;
    public: [[nodiscard]] auto make_private() & -> bool;

    public: [[nodiscard]] auto has_name() const& -> bool;
    public: [[nodiscard]] auto has_name(cpp2::impl::in<std::string_view> s) const& -> bool;

    public: [[nodiscard]] auto name() const& -> std::string_view;

#line 282 "reflect.h2"
    public: [[nodiscard]] auto has_initializer() const& -> bool;

    public: [[nodiscard]] auto get_initializer() const& -> statement;

    public: [[nodiscard]] auto is_global() const& -> bool;
    public: [[nodiscard]] auto is_function() const& -> bool;
    public: [[nodiscard]] auto is_object() const& -> bool;
    public: [[nodiscard]] auto is_base_object() const& -> bool;
    public: [[nodiscard]] auto is_member_object() const& -> bool;
    public: [[nodiscard]] auto is_type() const& -> bool;
    public: [[nodiscard]] auto is_namespace() const& -> bool;
    public: [[nodiscard]] auto is_alias() const& -> bool;

    public: [[nodiscard]] auto is_type_alias() const& -> bool;
    public: [[nodiscard]] auto is_namespace_alias() const& -> bool;
    public: [[nodiscard]] auto is_object_alias() const& -> bool;

    public: [[nodiscard]] auto is_function_expression() const& -> bool;

    public: [[nodiscard]] auto as_function() const& -> function_declaration;
    public: [[nodiscard]] auto as_object() const& -> object_declaration;
    public: [[nodiscard]] auto as_type() const& -> type_declaration;
    public: [[nodiscard]] auto as_nonglobal_namespace() const& -> namespace_declaration;
    public: [[nodiscard]] auto as_alias() const& -> alias_declaration;

    public: [[nodiscard]] auto get_parent() const& -> declaration;

    public: [[nodiscard]] auto parent_is_function() const& -> bool;
    public: [[nodiscard]] auto parent_is_object() const& -> bool;
    public: [[nodiscard]] auto parent_is_type() const& -> bool;
    public: [[nodiscard]] auto parent_is_nonglobal_namespace() const& -> bool;
    public: [[nodiscard]] auto parent_is_alias() const& -> bool;

    public: [[nodiscard]] auto parent_is_type_alias() const& -> bool;
    public: [[nodiscard]] auto parent_is_namespace_alias() const& -> bool;
    public: [[nodiscard]] auto parent_is_object_alias() const& -> bool;

    public: [[nodiscard]] auto parent_is_polymorphic() const& -> bool;

    public: auto mark_for_removal_from_enclosing_type() & -> void;
    public: virtual ~declaration() noexcept;
public: declaration(declaration const& that);
public: declaration(declaration&& that) noexcept;


#line 327 "reflect.h2"
};

#line 333 "reflect.h2"
class function_declaration
: public declaration {

#line 337 "reflect.h2"
    public: function_declaration(

        cpp2::impl::in<declaration_node*> n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 347 "reflect.h2"
    public: [[nodiscard]] auto index_of_parameter_named(cpp2::impl::in<std::string_view> s) const& -> int;
    public: [[nodiscard]] auto has_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool;
    public: [[nodiscard]] auto has_return_named(cpp2::impl::in<std::string_view> s) const& -> bool;
    public: [[nodiscard]] auto has_parameter_or_return_named(cpp2::impl::in<std::string_view> s) const& -> bool;
    public: [[nodiscard]] auto has_in_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool;
    public: [[nodiscard]] auto has_in_ref_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool;
    public: [[nodiscard]] auto has_copy_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool;
    public: [[nodiscard]] auto has_inout_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool;
    public: [[nodiscard]] auto has_out_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool;
    public: [[nodiscard]] auto has_move_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool;
    public: [[nodiscard]] auto has_forward_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool;
    public: [[nodiscard]] auto first_parameter_name() const& -> std::string;

    public: [[nodiscard]] auto has_parameter_with_name_and_pass(cpp2::impl::in<std::string_view> s, cpp2::impl::in<passing_style> pass) const& -> bool;

    public: [[nodiscard]] auto is_function_with_this() const& -> bool;
    public: [[nodiscard]] auto is_virtual() const& -> bool;
    public: [[nodiscard]] auto is_defaultable() const& -> bool;
    public: [[nodiscard]] auto is_constructor() const& -> bool;
    public: [[nodiscard]] auto is_default_constructor() const& -> bool;
    public: [[nodiscard]] auto is_move() const& -> bool;
    public: [[nodiscard]] auto is_swap() const& -> bool;
    public: [[nodiscard]] auto is_constructor_with_that() const& -> bool;
    public: [[nodiscard]] auto is_constructor_with_in_that() const& -> bool;
    public: [[nodiscard]] auto is_constructor_with_move_that() const& -> bool;
    public: [[nodiscard]] auto is_assignment() const& -> bool;
    public: [[nodiscard]] auto is_assignment_with_that() const& -> bool;
    public: [[nodiscard]] auto is_assignment_with_in_that() const& -> bool;
    public: [[nodiscard]] auto is_assignment_with_move_that() const& -> bool;
    public: [[nodiscard]] auto is_destructor() const& -> bool;

    public: [[nodiscard]] auto is_copy_or_move() const& -> bool;

    public: [[nodiscard]] auto has_declared_return_type() const& -> bool;
    public: [[nodiscard]] auto has_deduced_return_type() const& -> bool;
    public: [[nodiscard]] auto has_bool_return_type() const& -> bool;
    public: [[nodiscard]] auto has_non_void_return_type() const& -> bool;

    public: [[nodiscard]] auto has_compound_body() const& -> bool;

    public: [[nodiscard]] auto get_body() const& -> statement;
    public: [[nodiscard]] auto get_compound_body() const& -> compound_statement;
    public: [[nodiscard]] auto get_unnamed_return_type() const& -> std::string;
    public: [[nodiscard]] auto get_signature() const& -> std::string;

    public: [[nodiscard]] auto is_binary_comparison_function() const& -> bool;

    public: [[nodiscard]] auto get_parameters() const& -> std::vector<parameter_declaration>;

#line 404 "reflect.h2"
    public: [[nodiscard]] auto get_returns() const& -> std::vector<parameter_declaration>;

#line 416 "reflect.h2"
    public: [[nodiscard]] auto default_to_virtual() & -> decltype(auto);

    public: [[nodiscard]] auto make_virtual() & -> bool;

    public: auto add_initializer(cpp2::impl::in<std::string_view> source) & -> void;
    public: function_declaration(function_declaration const& that);
public: function_declaration(function_declaration&& that) noexcept;


#line 432 "reflect.h2"
};

#line 438 "reflect.h2"
class object_declaration
: public declaration {

#line 442 "reflect.h2"
    public: object_declaration(

        cpp2::impl::in<declaration_node*> n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 452 "reflect.h2"
    public: [[nodiscard]] auto is_const() const& -> bool;
    public: [[nodiscard]] auto has_wildcard_type() const& -> bool;

    public: [[nodiscard]] auto type() const& -> std::string;

#line 462 "reflect.h2"
    public: [[nodiscard]] auto initializer() const& -> std::string;
    public: object_declaration(object_declaration const& that);
public: object_declaration(object_declaration&& that) noexcept;


#line 468 "reflect.h2"
};

#line 474 "reflect.h2"
class type_or_namespace_declaration
: public declaration {

#line 478 "reflect.h2"
    public: type_or_namespace_declaration(

        cpp2::impl::in<declaration_node*> n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 488 "reflect.h2"
    public: auto reserve_names(cpp2::impl::in<std::string_view> name, auto&& ...etc) const& -> void;

#line 502 "reflect.h2"
    public: [[nodiscard]] auto get_member_functions() const& -> std::vector<function_declaration>;

#line 513 "reflect.h2"
    public: [[nodiscard]] auto get_member_functions_needing_initializer() const& -> std::vector<function_declaration>;

#line 528 "reflect.h2"
    public: [[nodiscard]] auto get_member_objects() const& -> std::vector<object_declaration>;

#line 538 "reflect.h2"
    public: [[nodiscard]] auto get_member_types() const& -> std::vector<type_declaration>;

#line 548 "reflect.h2"
    public: [[nodiscard]] auto get_member_aliases() const& -> std::vector<alias_declaration>;

#line 558 "reflect.h2"
    public: [[nodiscard]] auto get_members() const& -> std::vector<declaration>;

#line 568 "reflect.h2"
    public: auto add_member(cpp2::impl::in<std::string_view> source) & -> void;
    public: type_or_namespace_declaration(type_or_namespace_declaration const& that);
public: type_or_namespace_declaration(type_or_namespace_declaration&& that) noexcept;


#line 582 "reflect.h2"
};

#line 585 "reflect.h2"
class type_declaration
: public type_or_namespace_declaration {

#line 589 "reflect.h2"
    public: type_declaration(

        cpp2::impl::in<declaration_node*> n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 600 "reflect.h2"
    public: [[nodiscard]] auto is_polymorphic() const& -> bool;
    public: [[nodiscard]] auto is_final() const& -> bool;
    public: [[nodiscard]] auto make_final() & -> bool;
struct query_declared_value_set_functions_ret { bool out_this_in_that; bool out_this_move_that; bool inout_this_in_that; bool inout_this_move_that; };



#line 604 "reflect.h2"
    public: [[nodiscard]] auto query_declared_value_set_functions() const& -> query_declared_value_set_functions_ret;

#line 620 "reflect.h2"
    public: [[nodiscard]] auto disable_member_function_generation() & -> decltype(auto);
    public: [[nodiscard]] auto disable_ref_qualifier_generation() & -> decltype(auto);

#line 624 "reflect.h2"
    public: [[nodiscard]] auto remove_marked_members() & -> decltype(auto);
    public: [[nodiscard]] auto remove_all_members() & -> decltype(auto);
    public: type_declaration(type_declaration const& that);
public: type_declaration(type_declaration&& that) noexcept;

#line 626 "reflect.h2"
};

#line 629 "reflect.h2"
class namespace_declaration
: public type_or_namespace_declaration {

#line 633 "reflect.h2"
    public: namespace_declaration(

        cpp2::impl::in<declaration_node*> n_, 
        cpp2::impl::in<compiler_services> s
    );
    public: namespace_declaration(namespace_declaration const& that);
public: namespace_declaration(namespace_declaration&& that) noexcept;


#line 642 "reflect.h2"
};

#line 648 "reflect.h2"
class alias_declaration
: public declaration {

#line 652 "reflect.h2"
    public: alias_declaration(

        cpp2::impl::in<declaration_node*> n_, 
        cpp2::impl::in<compiler_services> s
    );
    public: alias_declaration(alias_declaration const& that);
public: alias_declaration(alias_declaration&& that) noexcept;


#line 661 "reflect.h2"
};

#line 667 "reflect.h2"
class parameter_declaration
: public reflection_base<parameter_declaration_node> {

#line 671 "reflect.h2"
    public: parameter_declaration(

        cpp2::impl::in<parameter_declaration_node*> n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 680 "reflect.h2"
    public: [[nodiscard]] auto get_declaration() const& -> object_declaration;
    public: [[nodiscard]] auto get_passing_style() const& -> passing_style;

    public: [[nodiscard]] auto is_implicit() const& -> bool;
    public: [[nodiscard]] auto is_virtual() const& -> bool;
    public: [[nodiscard]] auto is_override() const& -> bool;
    public: [[nodiscard]] auto is_final() const& -> bool;
    public: parameter_declaration(parameter_declaration const& that);
public: parameter_declaration(parameter_declaration&& that) noexcept;

#line 687 "reflect.h2"
};

#line 700 "reflect.h2"
using multiplicative_expression = binary_expression<"multiplicative",is_as_expression_node>;
using additive_expression = binary_expression<"additive",multiplicative_expression_node>;
using shift_expression = binary_expression<"shift",additive_expression_node>;
using compare_expression = binary_expression<"compare",shift_expression_node>;
using relational_expression = binary_expression<"relational",compare_expression_node>;
using equality_expression = binary_expression<"equality",relational_expression_node>;
using bit_and_expression = binary_expression<"bit-and",equality_expression_node>;
using bit_xor_expression = binary_expression<"bit-xor",bit_and_expression_node>;
using bit_or_expression = binary_expression<"bit-or",bit_xor_expression_node>;
using logical_and_expression = binary_expression<"logical-and",bit_or_expression_node>;
using logical_or_expression = binary_expression<"logical-or",logical_and_expression_node>;
using assignment_expression = binary_expression<"assignment",logical_or_expression_node>;

template<String Name, typename Term> class binary_expression
: public reflection_base<binary_expression_node<Name,Term>> {

#line 717 "reflect.h2"
    public: binary_expression(

        binary_expression_node<Name,Term>* const& n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 726 "reflect.h2"
    public: [[nodiscard]] auto is_fold_expression() const& -> bool;
    public: [[nodiscard]] auto lhs_is_id_expression() const& -> bool;
    public: [[nodiscard]] auto is_standalone_expression() const& -> bool;
    public: [[nodiscard]] auto terms_size() const& -> int;
    public: [[nodiscard]] auto is_identifier() const& -> bool;
    public: [[nodiscard]] auto is_id_expression() const& -> bool;
    public: [[nodiscard]] auto is_unqualified_id() const& -> bool;
    public: [[nodiscard]] auto is_expression_list() const& -> bool;
    public: [[nodiscard]] auto is_literal() const& -> bool;

    public: template<typename T> class term_t {
        private: std::string op; 
        private: T term; 

        public: term_t(auto&& o, auto&& ptr, auto&& cs);

        public: [[nodiscard]] auto get_op() const& -> std::string;
        public: [[nodiscard]] auto get_term() const& -> T;
        public: term_t(term_t const& that);

public: auto operator=(term_t const& that) -> term_t& ;
public: term_t(term_t&& that) noexcept;
public: auto operator=(term_t&& that) noexcept -> term_t& ;

#line 744 "reflect.h2"
    };

    public: [[nodiscard]] auto get_terms() const& -> auto;

#line 821 "reflect.h2"
    public: [[nodiscard]] auto as_expression_list() const& -> expression_list;
    public: [[nodiscard]] auto as_literal() const& -> std::string;

#line 825 "reflect.h2"
    public: [[nodiscard]] auto get_if_only_a_postfix_expression() const& -> postfix_expression;

    public: [[nodiscard]] auto get_lhs_postfix_expression() const& -> postfix_expression;

    public: [[nodiscard]] auto get_second_postfix_expression() const& -> postfix_expression;

    public: [[nodiscard]] auto is_result_a_temporary_variable() const& -> bool;

    public: [[nodiscard]] auto to_string() const& -> std::string;
    public: binary_expression(binary_expression const& that);
public: binary_expression(binary_expression&& that) noexcept;

#line 834 "reflect.h2"
};

#line 840 "reflect.h2"
class expression_list
: public reflection_base<expression_list_node> {

#line 844 "reflect.h2"
    public: expression_list(

        cpp2::impl::in<expression_list_node*> n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 853 "reflect.h2"
    public: [[nodiscard]] auto is_empty() const& -> bool;
    public: [[nodiscard]] auto is_fold_expression() const& -> bool;

    public: [[nodiscard]] auto get_expressions() const& -> std::vector<expression>;

#line 866 "reflect.h2"
    public: [[nodiscard]] auto to_string() const& -> std::string;
    public: expression_list(expression_list const& that);
public: expression_list(expression_list&& that) noexcept;

#line 867 "reflect.h2"
};

#line 873 "reflect.h2"
class prefix_expression
: public reflection_base<prefix_expression_node> {

#line 877 "reflect.h2"
    public: prefix_expression(

        cpp2::impl::in<prefix_expression_node*> n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 886 "reflect.h2"
    public: [[nodiscard]] auto get_ops() const& -> std::vector<std::string>;

#line 894 "reflect.h2"
    public: [[nodiscard]] auto get_postfix_expression() const& -> postfix_expression;

    public: [[nodiscard]] auto is_fold_expression() const& -> bool;
    public: [[nodiscard]] auto is_identifier() const& -> bool;
    public: [[nodiscard]] auto is_id_expression() const& -> bool;
    public: [[nodiscard]] auto is_unqualified_id() const& -> bool;
    public: [[nodiscard]] auto is_expression_list() const& -> bool;
    public: [[nodiscard]] auto is_literal() const& -> bool;
    public: [[nodiscard]] auto is_result_a_temporary_variable() const& -> bool;

    public: [[nodiscard]] auto as_expression_list() const& -> expression_list;
    public: [[nodiscard]] auto as_literal() const& -> std::string;
    public: [[nodiscard]] auto as_identifier() const& -> std::string;

    public: [[nodiscard]] auto to_string() const& -> std::string;
    public: virtual ~prefix_expression() noexcept;
public: prefix_expression(prefix_expression const& that);
public: prefix_expression(prefix_expression&& that) noexcept;

#line 909 "reflect.h2"
};

#line 915 "reflect.h2"
class postfix_expression
: public reflection_base<postfix_expression_node> {

#line 919 "reflect.h2"
    public: postfix_expression(

        cpp2::impl::in<postfix_expression_node*> n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 928 "reflect.h2"
    public: [[nodiscard]] auto get_primary_expression() const& -> primary_expression;

    public: class term_t {
        private: postfix_expression_node::term const* term_; 
        private: compiler_services const* cs_; 

        public: term_t(auto&& term, auto&& cs);

        public: [[nodiscard]] auto get_op() const& -> std::string_view;

#line 944 "reflect.h2"
        public: [[nodiscard]] auto is_id_expression() const& -> bool;
        public: [[nodiscard]] auto is_expression_list() const& -> bool;
        public: [[nodiscard]] auto is_expression() const& -> bool;

        public: [[nodiscard]] auto get_id_expression() const& -> id_expression;
        public: [[nodiscard]] auto get_expression_list() const& -> expression_list;
        public: [[nodiscard]] auto get_expression() const& -> expression;
        public: term_t(term_t const& that);
public: term_t(term_t&& that) noexcept;

#line 951 "reflect.h2"
    };

    public: [[nodiscard]] auto get_terms() const& -> auto;

#line 959 "reflect.h2"
    public: [[nodiscard]] auto is_fold_expression() const& -> bool;
    public: [[nodiscard]] auto is_identifier() const& -> bool;
    public: [[nodiscard]] auto is_id_expression() const& -> bool;
    public: [[nodiscard]] auto is_unqualified_id() const& -> bool;
    public: [[nodiscard]] auto is_expression_list() const& -> bool;
    public: [[nodiscard]] auto is_literal() const& -> bool;

    public: [[nodiscard]] auto as_identifier() const& -> std::string;
    public: [[nodiscard]] auto as_expression_list() const& -> expression_list;
    public: [[nodiscard]] auto as_literal() const& -> std::string;

    public: [[nodiscard]] auto get_first_token_ignoring_this() const& -> std::string_view;

#line 976 "reflect.h2"
    public: [[nodiscard]] auto starts_with_function_call_with_num_parameters(cpp2::impl::in<int> num) const& -> bool;
    public: [[nodiscard]] auto is_result_a_temporary_variable() const& -> bool;

    public: [[nodiscard]] auto to_string() const& -> std::string;
    public: postfix_expression(postfix_expression const& that);
public: postfix_expression(postfix_expression&& that) noexcept;

#line 980 "reflect.h2"
};

#line 986 "reflect.h2"
class template_arg
: public reflection_base<template_argument> {

#line 990 "reflect.h2"
    public: template_arg(

        cpp2::impl::in<template_argument*> n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 999 "reflect.h2"
    public: [[nodiscard]] auto is_expression() const& -> bool;
    public: [[nodiscard]] auto is_type_id() const& -> bool;

    public: [[nodiscard]] auto as_expression() const& -> expression;
    public: [[nodiscard]] auto as_type_id() const& -> type_id;

    public: [[nodiscard]] auto to_string() const& -> std::string;
    public: template_arg(template_arg const& that);
public: template_arg(template_arg&& that) noexcept;

#line 1006 "reflect.h2"
};

#line 1012 "reflect.h2"
class unqualified_id
: public reflection_base<unqualified_id_node> {

#line 1016 "reflect.h2"
    public: unqualified_id(

        cpp2::impl::in<unqualified_id_node*> n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 1025 "reflect.h2"
    public: [[nodiscard]] auto is_identifier() const& -> bool;

    public: [[nodiscard]] auto get_identifier() const& -> std::string;

#line 1035 "reflect.h2"
    public: [[nodiscard]] auto as_token() const& -> std::string;

    public: [[nodiscard]] auto to_string() const& -> std::string;
    public: unqualified_id(unqualified_id const& that);
public: unqualified_id(unqualified_id&& that) noexcept;

#line 1038 "reflect.h2"
};

#line 1044 "reflect.h2"
class qualified_id
: public reflection_base<qualified_id_node> {

#line 1048 "reflect.h2"
    public: qualified_id(

        cpp2::impl::in<qualified_id_node*> n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 1057 "reflect.h2"
    public: class term_t {
        private: std::string op; 
        private: unqualified_id unqualified; 

        public: term_t(auto&& o, auto&& ptr, auto&& cs);

        public: [[nodiscard]] auto get_op() const& -> std::string;
        public: [[nodiscard]] auto get_unqualified() const& -> unqualified_id;
        public: term_t(term_t const& that);
public: term_t(term_t&& that) noexcept;

#line 1065 "reflect.h2"
    };

    public: [[nodiscard]] auto get_terms() const& -> auto;

#line 1079 "reflect.h2"
    public: [[nodiscard]] auto as_token() const& -> std::string;

    public: [[nodiscard]] auto to_string() const& -> std::string;
    public: qualified_id(qualified_id const& that);
public: qualified_id(qualified_id&& that) noexcept;

#line 1082 "reflect.h2"
};

#line 1088 "reflect.h2"
class type_id
: public reflection_base<type_id_node> {

#line 1092 "reflect.h2"
    public: type_id(

        cpp2::impl::in<type_id_node*> n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 1107 "reflect.h2"
    public: [[nodiscard]] auto is_postfix_expression() const& -> bool;
    public: [[nodiscard]] auto is_qualified_id() const& -> bool;
    public: [[nodiscard]] auto is_unqualified_id() const& -> bool;
    public: [[nodiscard]] auto is_function_typeid() const& -> bool;
    public: [[nodiscard]] auto is_keyword() const& -> bool;
    public: [[nodiscard]] auto is_wildcard() const& -> bool;
    public: [[nodiscard]] auto is_pointer_qualified() const& -> bool;
    public: [[nodiscard]] auto is_concept() const& -> bool;

    public: [[nodiscard]] auto as_postfix_expression() const& -> postfix_expression;
    public: [[nodiscard]] auto as_qualified_id() const& -> qualified_id;
    public: [[nodiscard]] auto as_unqualified_id() const& -> unqualified_id;

#line 1121 "reflect.h2"
    public: [[nodiscard]] auto as_keyword() const& -> std::string;
    public: [[nodiscard]] auto as_token() const& -> std::string;

    public: [[nodiscard]] auto to_string() const& -> std::string;
    public: type_id(type_id const& that);
public: type_id(type_id&& that) noexcept;

#line 1125 "reflect.h2"
};

#line 1131 "reflect.h2"
class primary_expression
: public reflection_base<primary_expression_node> {

#line 1135 "reflect.h2"
    public: primary_expression(

        cpp2::impl::in<primary_expression_node*> n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 1150 "reflect.h2"
    public: [[nodiscard]] auto is_fold_expression() const& -> bool;
    public: [[nodiscard]] auto is_identifier() const& -> bool;
    public: [[nodiscard]] auto is_id_expression() const& -> bool;
    public: [[nodiscard]] auto is_unqualified_id() const& -> bool;
    public: [[nodiscard]] auto is_expression_list() const& -> bool;
    public: [[nodiscard]] auto is_literal() const& -> bool;
    public: [[nodiscard]] auto is_declaration() const& -> bool;

    public: [[nodiscard]] auto as_identifier() const& -> std::string;
    public: [[nodiscard]] auto as_expression_list() const& -> expression_list;
    public: [[nodiscard]] auto as_literal() const& -> std::string;
    public: [[nodiscard]] auto as_declaration() const& -> declaration;

    public: [[nodiscard]] auto to_string() const& -> std::string;
    public: primary_expression(primary_expression const& that);
public: primary_expression(primary_expression&& that) noexcept;

#line 1164 "reflect.h2"
};

#line 1170 "reflect.h2"
class id_expression
: public reflection_base<id_expression_node> {

#line 1174 "reflect.h2"
    public: id_expression(

        cpp2::impl::in<id_expression_node*> n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 1189 "reflect.h2"
    public: [[nodiscard]] auto is_fold_expression() const& -> bool;
    public: [[nodiscard]] auto is_empty() const& -> bool;
    public: [[nodiscard]] auto is_identifier() const& -> bool;
    public: [[nodiscard]] auto is_qualified() const& -> bool;
    public: [[nodiscard]] auto is_unqualified() const& -> bool;

    public: [[nodiscard]] auto as_identifier() const& -> std::string;
    public: [[nodiscard]] auto as_qualified() const& -> qualified_id;
    public: [[nodiscard]] auto as_unqualified() const& -> unqualified_id;

    public: [[nodiscard]] auto to_string() const& -> std::string;
    public: virtual ~id_expression() noexcept;
public: id_expression(id_expression const& that);
public: id_expression(id_expression&& that) noexcept;

#line 1200 "reflect.h2"
};

#line 1206 "reflect.h2"
class expression
: public reflection_base<expression_node> {

#line 1210 "reflect.h2"
    public: expression(

        cpp2::impl::in<expression_node*> n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 1219 "reflect.h2"
    public: [[nodiscard]] auto is_fold_expression() const& -> bool;
    public: [[nodiscard]] auto is_standalone_expression() const& -> bool;
    public: [[nodiscard]] auto subexpression_count() const& -> int;
    public: [[nodiscard]] auto is_identifier() const& -> bool;
    public: [[nodiscard]] auto is_id_expression() const& -> bool;
    public: [[nodiscard]] auto is_unqualified_id() const& -> bool;
    public: [[nodiscard]] auto is_expression_list() const& -> bool;
    public: [[nodiscard]] auto is_empty_expression_list() const& -> bool;
    public: [[nodiscard]] auto is_literal() const& -> bool;
    public: [[nodiscard]] auto is_assignment_expression() const& -> bool;

    public: [[nodiscard]] auto is_simple_assignment() const& -> bool;
struct get_lhs_rhs_if_simple_assignment_ret { postfix_expression lhs; logical_or_expression rhs; };



#line 1235 "reflect.h2"
    public: [[nodiscard]] auto get_lhs_rhs_if_simple_assignment() const& -> get_lhs_rhs_if_simple_assignment_ret;

#line 1246 "reflect.h2"
    public: [[nodiscard]] auto as_assignment_expression() const& -> assignment_expression;
    public: [[nodiscard]] auto as_expression_list() const& -> expression_list;
    public: [[nodiscard]] auto as_literal() const& -> std::string;

    public: [[nodiscard]] auto to_string() const& -> std::string;
    public: virtual ~expression() noexcept;
public: expression(expression const& that);
public: expression(expression&& that) noexcept;

#line 1251 "reflect.h2"
};

#line 1257 "reflect.h2"
class is_as_expression
: public reflection_base<is_as_expression_node> {

#line 1261 "reflect.h2"
    public: is_as_expression(

        cpp2::impl::in<is_as_expression_node*> n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 1270 "reflect.h2"
    public: class term_t {
        private: std::string op; 
        private: expression expr; 

        public: term_t(auto&& o, auto&& ptr, auto&& cs);

        public: [[nodiscard]] auto get_op() const& -> std::string;
        public: [[nodiscard]] auto get_expr() const& -> expression;
        public: term_t(term_t const& that);
public: term_t(term_t&& that) noexcept;

#line 1278 "reflect.h2"
    };

    public: [[nodiscard]] auto get_expression() const& -> prefix_expression;

    public: [[nodiscard]] auto get_terms() const& -> auto;

#line 1288 "reflect.h2"
    public: [[nodiscard]] auto is_fold_expression() const& -> bool;
    public: [[nodiscard]] auto is_identifier() const& -> bool;
    public: [[nodiscard]] auto is_id_expression() const& -> bool;
    public: [[nodiscard]] auto is_unqualified_id() const& -> bool;
    public: [[nodiscard]] auto is_expression_list() const& -> bool;
    public: [[nodiscard]] auto is_literal() const& -> bool;

    public: [[nodiscard]] auto as_expression_list() const& -> expression_list;
    public: [[nodiscard]] auto as_literal() const& -> std::string;

    public: [[nodiscard]] auto get_identifier() const& -> std::string_view;

#line 1304 "reflect.h2"
    public: [[nodiscard]] auto to_string() const& -> std::string;
    public: virtual ~is_as_expression() noexcept;
public: is_as_expression(is_as_expression const& that);
public: is_as_expression(is_as_expression&& that) noexcept;

#line 1305 "reflect.h2"
};

#line 1318 "reflect.h2"
class statement
: public reflection_base<statement_node> {

#line 1322 "reflect.h2"
    public: statement(

        cpp2::impl::in<statement_node*> n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 1331 "reflect.h2"
    public: [[nodiscard]] auto is_expression_statement() const& -> bool;
    public: [[nodiscard]] auto is_compound_statement() const& -> bool;
    public: [[nodiscard]] auto is_selection_statement() const& -> bool;
    public: [[nodiscard]] auto is_declaration() const& -> bool;
    public: [[nodiscard]] auto is_return_statement() const& -> bool;
    public: [[nodiscard]] auto is_iteration_statement() const& -> bool;
    public: [[nodiscard]] auto is_using_statement() const& -> bool;
    public: [[nodiscard]] auto is_contract() const& -> bool;
    public: [[nodiscard]] auto is_inspect_expression() const& -> bool;
    public: [[nodiscard]] auto is_jump_statement() const& -> bool;

    public: [[nodiscard]] auto as_expression_statement() const& -> expression_statement;
    public: [[nodiscard]] auto as_compound_statement() const& -> compound_statement;
    public: [[nodiscard]] auto as_selection_statement() const& -> selection_statement;
    public: [[nodiscard]] auto as_declaration() const& -> declaration;
    public: [[nodiscard]] auto as_return_statement() const& -> return_statement;
    public: [[nodiscard]] auto as_iteration_statement() const& -> iteration_statement;

#line 1353 "reflect.h2"
    public: [[nodiscard]] auto to_string() const& -> std::string;
    public: virtual ~statement() noexcept;
public: statement(statement const& that);
public: statement(statement&& that) noexcept;

#line 1354 "reflect.h2"
};

#line 1360 "reflect.h2"
class expression_statement
: public reflection_base<expression_statement_node> {

#line 1364 "reflect.h2"
    public: expression_statement(

        cpp2::impl::in<expression_statement_node*> n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 1373 "reflect.h2"
    public: [[nodiscard]] auto get_expression() const& -> expression;

    public: [[nodiscard]] auto to_string() const& -> std::string;
    public: expression_statement(expression_statement const& that);
public: expression_statement(expression_statement&& that) noexcept;

#line 1376 "reflect.h2"
};

#line 1382 "reflect.h2"
class compound_statement
: public reflection_base<compound_statement_node> {

#line 1386 "reflect.h2"
    public: compound_statement(

        cpp2::impl::in<compound_statement_node*> n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 1395 "reflect.h2"
    public: [[nodiscard]] auto get_statements() const& -> std::vector<statement>;

#line 1405 "reflect.h2"
    public: auto add_statement(cpp2::impl::in<std::string_view> source, cpp2::impl::in<int> before_position = 0) & -> void;
    public: compound_statement(compound_statement const& that);
public: compound_statement(compound_statement&& that) noexcept;


#line 1415 "reflect.h2"
};

#line 1421 "reflect.h2"
class selection_statement
: public reflection_base<selection_statement_node> {

#line 1425 "reflect.h2"
    public: selection_statement(

        cpp2::impl::in<selection_statement_node*> n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 1434 "reflect.h2"
    public: [[nodiscard]] auto has_false_branch_in_source_code() const& -> bool;
    public: [[nodiscard]] auto has_false_branch() const& -> bool;

    public: [[nodiscard]] auto get_identifier() const& -> std::string_view;
    public: [[nodiscard]] auto get_expression() const& -> logical_or_expression;
    public: [[nodiscard]] auto get_true_branch() const& -> compound_statement;
    public: [[nodiscard]] auto get_false_branch() const& -> compound_statement;
    public: selection_statement(selection_statement const& that);
public: selection_statement(selection_statement&& that) noexcept;

#line 1441 "reflect.h2"
};

#line 1447 "reflect.h2"
class return_statement
: public reflection_base<return_statement_node> {

#line 1451 "reflect.h2"
    public: return_statement(

        cpp2::impl::in<return_statement_node*> n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 1460 "reflect.h2"
    public: [[nodiscard]] auto has_expression() const& -> bool;

    public: [[nodiscard]] auto get_expression() const& -> expression;
    public: return_statement(return_statement const& that);
public: return_statement(return_statement&& that) noexcept;

#line 1463 "reflect.h2"
};

#line 1469 "reflect.h2"
class iteration_statement
: public reflection_base<iteration_statement_node> {

#line 1473 "reflect.h2"
    public: iteration_statement(

        cpp2::impl::in<iteration_statement_node*> n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 1482 "reflect.h2"
    public: [[nodiscard]] auto is_do() const& -> bool;
    public: [[nodiscard]] auto is_while() const& -> bool;
    public: [[nodiscard]] auto is_for() const& -> bool;
    public: [[nodiscard]] auto has_next() const& -> bool;

    public: [[nodiscard]] auto get_label() const& -> std::string;
    public: [[nodiscard]] auto get_next_expression() const& -> assignment_expression;
    public: [[nodiscard]] auto get_do_while_condition() const& -> logical_or_expression;
    public: [[nodiscard]] auto get_do_while_body() const& -> compound_statement;
    public: [[nodiscard]] auto get_for_range() const& -> expression;
    public: [[nodiscard]] auto get_for_parameter() const& -> parameter_declaration;
    public: [[nodiscard]] auto get_for_body() const& -> statement;
    public: iteration_statement(iteration_statement const& that);
public: iteration_statement(iteration_statement&& that) noexcept;

#line 1494 "reflect.h2"
};

#line 1509 "reflect.h2"
auto add_virtual_destructor(meta::type_declaration& t) -> void;

#line 1529 "reflect.h2"
auto interface(meta::type_declaration& t) -> void;

#line 1577 "reflect.h2"
auto polymorphic_base(meta::type_declaration& t) -> void;

#line 1622 "reflect.h2"
auto ordered_impl(
    meta::type_declaration& t, 
    cpp2::impl::in<std::string_view> ordering
) -> void;

#line 1651 "reflect.h2"
auto ordered(meta::type_declaration& t) -> void;

#line 1659 "reflect.h2"
auto weakly_ordered(meta::type_declaration& t) -> void;

#line 1667 "reflect.h2"
auto partially_ordered(meta::type_declaration& t) -> void;

#line 1689 "reflect.h2"
auto copyable(meta::type_declaration& t) -> void;

#line 1721 "reflect.h2"
auto copy_constructible(meta::type_declaration& t) -> void;

#line 1753 "reflect.h2"
auto hashable(meta::type_declaration& t) -> void;

#line 1786 "reflect.h2"
auto basic_value(meta::type_declaration& t) -> void;

#line 1814 "reflect.h2"
auto value(meta::type_declaration& t) -> void;

#line 1820 "reflect.h2"
auto weakly_ordered_value(meta::type_declaration& t) -> void;

#line 1826 "reflect.h2"
auto partially_ordered_value(meta::type_declaration& t) -> void;

#line 1855 "reflect.h2"
auto cpp1_rule_of_zero(meta::type_declaration& t) -> void;

#line 1897 "reflect.h2"
auto cpp2_struct(meta::type_declaration& t) -> void;

#line 1966 "reflect.h2"
class value_member_info {
    public: std::string name; 
    public: std::string type; 
    public: std::string value; 
    public: value_member_info(auto const& name_, auto const& type_, auto const& value_);

#line 1970 "reflect.h2"
};

auto basic_enum(
    meta::type_declaration& t, 
    auto const& nextval, 
    cpp2::impl::in<bool> bitwise
    ) -> void;

#line 2236 "reflect.h2"
auto cpp2_enum(meta::type_declaration& t) -> void;

#line 2263 "reflect.h2"
auto flag_enum(meta::type_declaration& t) -> void;

#line 2309 "reflect.h2"
auto cpp2_union(meta::type_declaration& t) -> void;

#line 2460 "reflect.h2"
auto print(cpp2::impl::in<meta::type_declaration> t) -> void;

#line 2471 "reflect.h2"
auto noisy(cpp2::impl::in<meta::type_declaration> t) -> void;
struct python_param_names_and_types_ret { std::string names; std::string types; };



#line 2495 "reflect.h2"
[[nodiscard]] auto python_param_names_and_types(cpp2::impl::in<meta::function_declaration> mf) -> python_param_names_and_types_ret;

#line 2515 "reflect.h2"
auto python(meta::type_declaration& t) -> void;

#line 2558 "reflect.h2"
auto javascript(meta::type_declaration& t) -> void;

#line 2599 "reflect.h2"
auto sample_print(cpp2::impl::in<std::string_view> s, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 2607 "reflect.h2"
class simple_traverser {

    public: virtual auto pre_traverse(cpp2::impl::in<meta::declaration> decl) -> void;

#line 2613 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::declaration> decl) -> void;

#line 2633 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::function_declaration> f) -> void;

#line 2637 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::function_declaration> f) -> void;

#line 2658 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::object_declaration> o) -> void;

#line 2662 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::object_declaration> o) -> void;

#line 2670 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::type_declaration> t) -> void;

#line 2674 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::type_declaration> t) -> void;

#line 2682 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::parameter_declaration> t) -> void;

#line 2686 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::parameter_declaration> t) -> void;

#line 2691 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::statement> stmt) -> void;

#line 2695 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::statement> stmt) -> void;

#line 2730 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::compound_statement> stmt) -> void;

#line 2734 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::compound_statement> stmt) -> void;

#line 2744 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::return_statement> stmt) -> void;

#line 2748 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::return_statement> stmt) -> void;

#line 2756 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::iteration_statement> stmt) -> void;

#line 2760 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::iteration_statement> stmt) -> void;

#line 2779 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::selection_statement> stmt) -> void;

#line 2783 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::selection_statement> stmt) -> void;

#line 2794 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::expression> expr) -> void;

#line 2800 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::expression> expr) -> void;

#line 2814 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::assignment_expression> binexpr) -> void;

#line 2831 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::assignment_expression> binexpr) -> void;

#line 2842 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::logical_or_expression> binexpr) -> void;

#line 2859 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::logical_or_expression> binexpr) -> void;

#line 2871 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::logical_and_expression> binexpr) -> void;

#line 2888 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::logical_and_expression> binexpr) -> void;

#line 2899 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::bit_or_expression> binexpr) -> void;

#line 2916 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::bit_or_expression> binexpr) -> void;

#line 2927 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::bit_xor_expression> binexpr) -> void;

#line 2944 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::bit_xor_expression> binexpr) -> void;

#line 2956 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::bit_and_expression> binexpr) -> void;

#line 2973 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::bit_and_expression> binexpr) -> void;

#line 2985 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::equality_expression> binexpr) -> void;

#line 3002 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::equality_expression> binexpr) -> void;

#line 3013 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::relational_expression> binexpr) -> void;

#line 3030 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::relational_expression> binexpr) -> void;

#line 3041 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::compare_expression> binexpr) -> void;

#line 3058 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::compare_expression> binexpr) -> void;

#line 3069 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::shift_expression> binexpr) -> void;

#line 3086 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::shift_expression> binexpr) -> void;

#line 3097 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::additive_expression> binexpr) -> void;

#line 3114 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::additive_expression> binexpr) -> void;

#line 3126 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::multiplicative_expression> binexpr) -> void;

#line 3143 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::multiplicative_expression> binexpr) -> void;

#line 3154 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::is_as_expression> isas) -> void;

#line 3170 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::is_as_expression> isas) -> void;

#line 3181 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::expression_list> exprs) -> void;

#line 3188 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::prefix_expression> prefix) -> void;

#line 3204 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::prefix_expression> prefix) -> void;

#line 3209 "reflect.h2"
    public: virtual auto pre_traverse(cpp2::impl::in<meta::postfix_expression> postfix) -> void;

#line 3225 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::postfix_expression> postfix) -> void;

#line 3244 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::unqualified_id> uid) -> void;

#line 3250 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::qualified_id> qid) -> void;

#line 3260 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::type_id> tid) -> void;

#line 3277 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::primary_expression> primary) -> void;

#line 3297 "reflect.h2"
    public: virtual auto traverse(cpp2::impl::in<meta::id_expression> idexpr) -> void;
    public: simple_traverser() = default;
    public: simple_traverser(simple_traverser const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(simple_traverser const&) -> void = delete;


#line 3312 "reflect.h2"
};

#line 3325 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::declaration> decl, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 3347 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::function_declaration> f, cpp2::impl::in<cpp2::i32> indent = 0) -> void;

#line 3377 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::object_declaration> o, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 3387 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::type_declaration> t, cpp2::impl::in<cpp2::i32> indent = 0) -> void;

#line 3408 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::parameter_declaration> t, cpp2::impl::in<cpp2::i32> indent = 0) -> void;

#line 3427 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::statement> stmt, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 3474 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::compound_statement> stmt, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 3491 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::return_statement> stmt, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 3501 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::iteration_statement> stmt, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 3533 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::expression> expr, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 3547 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::assignment_expression> binexpr, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 3577 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::logical_or_expression> binexpr, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 3607 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::logical_and_expression> binexpr, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 3637 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::bit_or_expression> binexpr, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 3667 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::bit_xor_expression> binexpr, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 3697 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::bit_and_expression> binexpr, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 3727 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::equality_expression> binexpr, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 3757 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::relational_expression> binexpr, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 3787 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::compare_expression> binexpr, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 3817 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::shift_expression> binexpr, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 3847 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::additive_expression> binexpr, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 3877 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::multiplicative_expression> binexpr, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 3907 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::is_as_expression> isas, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 3933 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::expression_list> exprs, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 3948 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::prefix_expression> prefix, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 3972 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::postfix_expression> postfix, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 4005 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::unqualified_id> uid, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 4016 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::qualified_id> qid, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 4032 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::type_id> tid, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 4049 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::primary_expression> primary, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 4069 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::id_expression> idexpr, cpp2::impl::in<cpp2::i32> indent) -> void;

#line 4091 "reflect.h2"
class autodiff_special_func {
           public: std::string name; 
           public: int n_args; 
    public: bool is_member; 

           public: std::string code_primal; 
           public: std::string code_fwd; 
    public: std::string code_primal_higher_order; 
    public: std::string code_fwd_higher_order; 

    public: autodiff_special_func(cpp2::impl::in<std::string> name_, cpp2::impl::in<int> n_args_, cpp2::impl::in<bool> is_member_, cpp2::impl::in<std::string> code_primal_ = "", cpp2::impl::in<std::string> code_fwd_ = "", 
                          cpp2::impl::in<std::string> code_primal_higher_order_ = "", cpp2::impl::in<std::string> code_fwd_higher_order_ = "");

#line 4120 "reflect.h2"
    public: autodiff_special_func(autodiff_special_func const& that);
#line 4120 "reflect.h2"
    public: auto operator=(autodiff_special_func const& that) -> autodiff_special_func& ;
#line 4120 "reflect.h2"
    public: autodiff_special_func(autodiff_special_func&& that) noexcept;
#line 4120 "reflect.h2"
    public: auto operator=(autodiff_special_func&& that) noexcept -> autodiff_special_func& ;

    public: [[nodiscard]] auto is_match(cpp2::impl::in<autodiff_special_func> o) const& -> bool;

#line 4125 "reflect.h2"
};

class autodiff_declared_variable {
           public: std::string name {""}; 
           public: std::string decl {""}; 
           public: bool is_active {false}; 
           public: bool is_member {false}; 

    public: explicit autodiff_declared_variable();

    public: autodiff_declared_variable(cpp2::impl::in<std::string> name_, cpp2::impl::in<std::string> decl_, cpp2::impl::in<bool> is_active_, cpp2::impl::in<bool> is_member_);

#line 4142 "reflect.h2"
    public: autodiff_declared_variable(autodiff_declared_variable const& that);
#line 4142 "reflect.h2"
    public: auto operator=(autodiff_declared_variable const& that) -> autodiff_declared_variable& ;
#line 4142 "reflect.h2"
    public: autodiff_declared_variable(autodiff_declared_variable&& that) noexcept;
#line 4142 "reflect.h2"
    public: auto operator=(autodiff_declared_variable&& that) noexcept -> autodiff_declared_variable& ;
};

class autodiff_declaration_stack_item {
           public: std::string full_name; 
    public: meta::type_or_namespace_declaration decl; 

    public: std::vector<meta::declaration> diff_request {}; 
    public: std::vector<meta::declaration> diff_done {}; 

    public: std::vector<std::vector<autodiff_declared_variable>> declared_variables_stack {1}; 

    public: autodiff_declaration_stack_item(cpp2::impl::in<std::string> full_name_, cpp2::impl::in<meta::type_or_namespace_declaration> decl_);
using lookup_declaration_ret = std::vector<meta::declaration>;


#line 4159 "reflect.h2"
    public: [[nodiscard]] auto lookup_declaration(cpp2::impl::in<std::string> decl_name) const& -> lookup_declaration_ret;
struct lookup_variable_declaration_ret { bool found; autodiff_declared_variable r; };



#line 4169 "reflect.h2"
    public: [[nodiscard]] auto lookup_variable_declaration(cpp2::impl::in<std::string> decl_name) const& -> lookup_variable_declaration_ret;
    public: autodiff_declaration_stack_item(autodiff_declaration_stack_item const& that);
public: autodiff_declaration_stack_item(autodiff_declaration_stack_item&& that) noexcept;


#line 4182 "reflect.h2"
};

class autodiff_context {
    private: int temporary_count {0}; 

#line 4194 "reflect.h2"
    public: std::vector<autodiff_special_func> special_funcs {
        autodiff_special_func("sin", 1,                   false, 
            "sin(_a1_)", 
            "cos(_a1_) * _ad1_", 
            "sin(_a1_)", 
            "_ad1_.sin(_a1_)"

        ), 
        autodiff_special_func("cos", 1,                   false, 
            "cos(_a1_)", 
            "-sin(_a1_) * _ad1_", 
            "cos(_a1_)", 
            "_ad1_.cos(_a1_)"
        ), 
        autodiff_special_func("exp", 1,                   false, 
            "exp(_a1_)", 
            "exp(_a1_) * _ad1_", 
            "exp(_a1_)", 
            "_ad1_.exp(_a1_)"
        ), 
        autodiff_special_func("sqrt", 1,                   false, 
            "sqrt(_a1_)", 
            "0.5 * _ad1_ / sqrt(_a1_)", 
            "sqrt(_a1_)", 
            "_ad1_.sqrt(_a1_)"
        ), 
        autodiff_special_func("push_back", 1,                   true, 
            "_o_.push_back(_a1_);", 
            "_od_.push_back(_ad1_);")}; 

#line 4225 "reflect.h2"
            public: std::string fwd_suffix {"_d"}; 
            public: std::string rws_suffix {"_b"}; 
            private: int order {1}; 
            public: bool reverse {false}; 

#line 4231 "reflect.h2"
    public: std::string fwd_ad_type {"double"}; 
    public: std::string rws_ad_type {"double"}; 

           public: std::map<std::string,std::vector<meta::declaration>> declaration_map {}; 
    public: std::vector<autodiff_declaration_stack_item> declaration_stack {}; 

    public: explicit autodiff_context();
    public: autodiff_context(cpp2::impl::in<int> order_, cpp2::impl::in<bool> reverse_);

#line 4254 "reflect.h2"
    public: auto add_variable_declaration(cpp2::impl::in<std::string> name, cpp2::impl::in<std::string> type, cpp2::impl::in<bool> is_active, cpp2::impl::in<bool> is_member = false) & -> void;

#line 4258 "reflect.h2"
    public: [[nodiscard]] auto is_variable_active(cpp2::impl::in<std::string> name) & -> bool;

#line 4262 "reflect.h2"
    public: auto create_namespace_stack(cpp2::impl::in<meta::type_or_namespace_declaration> t) & -> void;

#line 4279 "reflect.h2"
    public: [[nodiscard]] auto is_forward() const& -> decltype(auto);
    public: [[nodiscard]] auto is_reverse() const& -> decltype(auto);
    public: [[nodiscard]] auto is_taylor() const& -> decltype(auto);

    public: [[nodiscard]] auto gen_temporary() & -> std::string;

#line 4288 "reflect.h2"
    public: [[nodiscard]] auto is_type_active(cpp2::impl::in<std::string> type) & -> bool;

#line 4309 "reflect.h2"
    public: [[nodiscard]] auto get_fwd_ad_type(cpp2::impl::in<std::string> type) & -> std::string;

#line 4327 "reflect.h2"
    public: [[nodiscard]] auto get_rws_ad_type(cpp2::impl::in<std::string> type) & -> std::string;

#line 4345 "reflect.h2"
    public: [[nodiscard]] auto get_reverse_passing_style(cpp2::impl::in<passing_style> p) const& -> passing_style;
using lookup_declaration_ret = std::vector<meta::declaration>;


#line 4373 "reflect.h2"
    public: [[nodiscard]] auto lookup_declaration(cpp2::impl::in<std::string> decl_name) & -> lookup_declaration_ret;

#line 4396 "reflect.h2"
    public: [[nodiscard]] auto lookup_variable_declaration(cpp2::impl::in<std::string> name) & -> autodiff_declared_variable;
using lookup_function_declaration_ret = std::vector<meta::function_declaration>;


#line 4413 "reflect.h2"
    public: [[nodiscard]] auto lookup_function_declaration(cpp2::impl::in<std::string> decl_name) & -> lookup_function_declaration_ret;
using lookup_member_function_declaration_ret = std::vector<meta::function_declaration>;


#line 4423 "reflect.h2"
    public: [[nodiscard]] auto lookup_member_function_declaration(cpp2::impl::in<meta::type_declaration> obj_type, cpp2::impl::in<std::string> decl_name) & -> lookup_member_function_declaration_ret;
using lookup_type_declaration_ret = std::vector<meta::type_declaration>;


#line 4433 "reflect.h2"
    public: [[nodiscard]] auto lookup_type_declaration(cpp2::impl::in<std::string> decl_name) & -> lookup_type_declaration_ret;
struct lookup_special_function_handling_ret { bool m; std::string code_primal; std::string code_fwd; };



#line 4443 "reflect.h2"
    public: [[nodiscard]] auto lookup_special_function_handling(cpp2::impl::in<std::string> func_name, cpp2::impl::in<int> n_args, cpp2::impl::in<bool> is_member) const& -> lookup_special_function_handling_ret;

#line 4465 "reflect.h2"
    public: auto add_as_differentiated(cpp2::impl::in<meta::declaration> t) & -> void;

#line 4473 "reflect.h2"
    public: auto add_for_differentiation(cpp2::impl::in<meta::declaration> t) & -> void;

#line 4493 "reflect.h2"
    public: [[nodiscard]] static auto is_in_list(cpp2::impl::in<meta::declaration> v, cpp2::impl::in<std::vector<meta::declaration>> list) -> bool;

#line 4503 "reflect.h2"
    public: auto enter_function() & -> void;

#line 4508 "reflect.h2"
    public: auto leave_function() & -> void;

#line 4512 "reflect.h2"
    public: auto push_stack(cpp2::impl::in<meta::type_or_namespace_declaration> decl) & -> void;

#line 4525 "reflect.h2"
    public: auto pop_stack() & -> void;

#line 4540 "reflect.h2"
    public: auto finish() & -> void;
    public: autodiff_context(autodiff_context const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(autodiff_context const&) -> void = delete;


#line 4545 "reflect.h2"
};

class autodiff_diff_code {
    public: autodiff_context* ctx; 

           public: std::string fwd {""}; 
           public: std::string rws_primal {""}; 
    public: std::string rws_backprop {""}; 

    public: autodiff_diff_code(cpp2::impl::in<autodiff_context*> ctx_);
#line 4554 "reflect.h2"
    public: auto operator=(cpp2::impl::in<autodiff_context*> ctx_) -> autodiff_diff_code& ;

#line 4558 "reflect.h2"
    public: auto add_forward(cpp2::impl::in<std::string> v) & -> void;
    public: auto add_reverse_primal(cpp2::impl::in<std::string> v) & -> void;
    public: auto add_reverse_backprop(cpp2::impl::in<std::string> v) & -> void;

    public: auto reset() & -> void;

#line 4569 "reflect.h2"
    public: auto operator=(cpp2::impl::in<std::string> v) -> autodiff_diff_code& ;

#line 4575 "reflect.h2"
    public: auto operator+=(cpp2::impl::in<std::string> v) & -> void;

#line 4580 "reflect.h2"
    public: auto operator+=(cpp2::impl::in<autodiff_diff_code> v) & -> void;

#line 4585 "reflect.h2"
    public: [[nodiscard]] auto empty() const& -> bool;
    public: autodiff_diff_code(autodiff_diff_code const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(autodiff_diff_code const&) -> void = delete;


#line 4588 "reflect.h2"
};

#line 4595 "reflect.h2"
class autodiff_activity_check: public simple_traverser {

#line 4598 "reflect.h2"
           public: autodiff_context* ctx; 
           public: bool active {false}; 

    public: autodiff_activity_check(cpp2::impl::in<autodiff_context*> ctx_);

#line 4605 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::object_declaration> o) -> void override;

#line 4623 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::primary_expression> primary) -> void override;

#line 4647 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::postfix_expression> postfix) -> void override;
    public: autodiff_activity_check(autodiff_activity_check const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(autodiff_activity_check const&) -> void = delete;


#line 4679 "reflect.h2"
};

class autodiff_handler_base {
    public: autodiff_context* ctx; 

    public: autodiff_diff_code diff; 

    public: autodiff_handler_base(cpp2::impl::in<autodiff_context*> ctx_);
#line 4686 "reflect.h2"
    public: auto operator=(cpp2::impl::in<autodiff_context*> ctx_) -> autodiff_handler_base& ;

#line 4692 "reflect.h2"
    public: auto append(autodiff_handler_base const& o) & -> void;
    public: autodiff_handler_base(autodiff_handler_base const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(autodiff_handler_base const&) -> void = delete;


#line 4697 "reflect.h2"
};

class autodiff_expression_handler: public simple_traverser, public autodiff_handler_base {

#line 4703 "reflect.h2"
    public: using base = simple_traverser;

    public: std::string primal_expr {""}; 
    public: std::string fwd_expr {""}; 
    public: std::string rws_expr {""}; 

    public: autodiff_expression_handler(cpp2::impl::in<autodiff_context*> ctx_);

#line 4713 "reflect.h2"
    public: [[nodiscard]] auto add_suffix_if_not_wildcard(cpp2::impl::in<std::string> lhs, cpp2::impl::in<std::string> suffix) const& -> std::string;

#line 4722 "reflect.h2"
    public: [[nodiscard]] auto prepare_backprop(cpp2::impl::in<std::string> rhs_b, cpp2::impl::in<std::string> lhs, cpp2::impl::in<std::string> lhs_d, cpp2::impl::in<std::string> lhs_b) const& -> std::string;

#line 4731 "reflect.h2"
    public: auto gen_assignment(cpp2::impl::in<std::string> lhs, cpp2::impl::in<std::string> lhs_d, cpp2::impl::in<std::string> lhs_b, cpp2::impl::in<std::string> rhs, cpp2::impl::in<std::string> rhs_d, cpp2::impl::in<std::string> rhs_b) & -> void;

#line 4741 "reflect.h2"
    public: [[nodiscard]] auto gen_assignment(cpp2::impl::in<std::string> lhs, cpp2::impl::in<std::string> lhs_d, cpp2::impl::in<std::string> lhs_b) & -> decltype(auto);

    public: [[nodiscard]] auto gen_assignment(cpp2::impl::in<std::string> lhs) & -> decltype(auto);

#line 4747 "reflect.h2"
    public: auto gen_declaration(cpp2::impl::in<std::string> lhs, cpp2::impl::in<std::string> lhs_d, cpp2::impl::in<std::string> lhs_b, cpp2::impl::in<std::string> rhs, cpp2::impl::in<std::string> rhs_d, cpp2::impl::in<std::string> rhs_b, cpp2::impl::in<std::string> type, cpp2::impl::in<std::string> type_d, cpp2::impl::in<std::string> type_b) & -> void;

#line 4757 "reflect.h2"
    public: [[nodiscard]] auto gen_declaration(cpp2::impl::in<std::string> lhs, cpp2::impl::in<std::string> lhs_d, cpp2::impl::in<std::string> lhs_b, cpp2::impl::in<std::string> rhs, cpp2::impl::in<std::string> rhs_d, cpp2::impl::in<std::string> rhs_b, cpp2::impl::in<std::string> type) & -> decltype(auto);

    public: [[nodiscard]] auto gen_declaration(cpp2::impl::in<std::string> lhs, cpp2::impl::in<std::string> lhs_d, cpp2::impl::in<std::string> lhs_b, cpp2::impl::in<std::string> type) & -> decltype(auto);

    public: [[nodiscard]] auto gen_declaration(cpp2::impl::in<std::string> lhs, cpp2::impl::in<std::string> type) & -> decltype(auto);

#line 4766 "reflect.h2"
    public: class primal_fwd_rws_name {
        public: std::string primal {""}; 
        public: std::string fwd {""}; 
        public: std::string rws {""}; 
        public: bool active {false}; 
        public: primal_fwd_rws_name(auto&& primal_, auto&& fwd_, auto&& rws_, auto&& active_)
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(primal_), std::add_const_t<std::string>&> && std::is_convertible_v<CPP2_TYPEOF(fwd_), std::add_const_t<std::string>&> && std::is_convertible_v<CPP2_TYPEOF(rws_), std::add_const_t<std::string>&> && std::is_convertible_v<CPP2_TYPEOF(active_), std::add_const_t<bool>&>) ;
public: primal_fwd_rws_name();

#line 4771 "reflect.h2"
    };

    public: [[nodiscard]] auto handle_expression_list(cpp2::impl::in<meta::expression_list> list) & -> std::vector<primal_fwd_rws_name>;

#line 4782 "reflect.h2"
    public: [[nodiscard]] auto handle_expression_term(auto const& term) & -> primal_fwd_rws_name;

#line 4843 "reflect.h2"
    public: auto handle_function_call(cpp2::impl::in<meta::postfix_expression> postfix, cpp2::impl::in<bool> has_return) & -> void;

#line 4992 "reflect.h2"
    public: [[nodiscard]] auto handle_special_function(cpp2::impl::in<std::string> object, cpp2::impl::in<std::string> object_d, cpp2::impl::in<std::string> function_name, cpp2::impl::in<std::vector<primal_fwd_rws_name>> args) & -> bool;

#line 5027 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::expression> expr) -> void override;

#line 5031 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::assignment_expression> binexpr) -> void override;

#line 5035 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::logical_or_expression> binexpr) -> void override;

#line 5039 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::logical_and_expression> binexpr) -> void override;

#line 5043 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::bit_or_expression> binexpr) -> void override;

#line 5047 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::bit_xor_expression> binexpr) -> void override;

#line 5051 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::bit_and_expression> binexpr) -> void override;

#line 5055 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::equality_expression> binexpr) -> void override;

#line 5059 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::relational_expression> binexpr) -> void override;

#line 5063 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::compare_expression> binexpr) -> void override;

#line 5067 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::shift_expression> binexpr) -> void override;

#line 5071 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::additive_expression> binexpr) -> void override;

#line 5102 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::multiplicative_expression> binexpr) -> void override;

#line 5189 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::is_as_expression> isas) -> void override;

#line 5193 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::prefix_expression> prefix) -> void override;

#line 5209 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::postfix_expression> postfix) -> void override;

#line 5249 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::primary_expression> primary) -> void override;
    public: autodiff_expression_handler(autodiff_expression_handler const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(autodiff_expression_handler const&) -> void = delete;


#line 5284 "reflect.h2"
};

class autodiff_stmt_handler: public simple_traverser, public autodiff_handler_base {

#line 5290 "reflect.h2"
    public: using base = simple_traverser;

    private: meta::function_declaration mf; 

    public: autodiff_stmt_handler(cpp2::impl::in<autodiff_context*> ctx_, cpp2::impl::in<meta::function_declaration> mf_);

#line 5299 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::declaration> decl) -> void override;

#line 5304 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::function_declaration> f) -> void override;

#line 5309 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::object_declaration> o) -> void override;

#line 5360 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::type_declaration> t) -> void override;

#line 5365 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::parameter_declaration> t) -> void override;

#line 5370 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::statement> stmt) -> void override;

#line 5375 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::compound_statement> stmt) -> void override;

#line 5383 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::return_statement> stmt) -> void override;

#line 5400 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::iteration_statement> stmt) -> void override;

#line 5450 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::selection_statement> stmt) -> void override;

#line 5461 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::expression> expr) -> void override;

#line 5465 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::assignment_expression> binexpr) -> void override;

#line 5478 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::logical_or_expression> binexpr) -> void override;

#line 5482 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::logical_and_expression> binexpr) -> void override;

#line 5486 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::bit_or_expression> binexpr) -> void override;

#line 5490 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::bit_xor_expression> binexpr) -> void override;

#line 5494 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::bit_and_expression> binexpr) -> void override;

#line 5498 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::equality_expression> binexpr) -> void override;

#line 5502 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::relational_expression> binexpr) -> void override;

#line 5506 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::compare_expression> binexpr) -> void override;

#line 5510 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::shift_expression> binexpr) -> void override;

#line 5514 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::additive_expression> binexpr) -> void override;

#line 5518 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::multiplicative_expression> binexpr) -> void override;

#line 5522 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::is_as_expression> isas) -> void override;

#line 5526 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::prefix_expression> prefix) -> void override;

#line 5531 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::postfix_expression> postfix) -> void override;

#line 5563 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::primary_expression> primary) -> void override;
    public: autodiff_stmt_handler(autodiff_stmt_handler const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(autodiff_stmt_handler const&) -> void = delete;


#line 5567 "reflect.h2"
};

class autodiff_declaration_handler: public simple_traverser, public autodiff_handler_base {

#line 5573 "reflect.h2"
    public: using base = simple_traverser;

    private: meta::type_or_namespace_declaration decl; 

    private: bool is_type_context {false}; 
    private: std::string diff_ad_type {""}; 

    public: autodiff_declaration_handler(cpp2::impl::in<autodiff_context*> ctx_, cpp2::impl::in<meta::type_or_namespace_declaration> decl_);

#line 5585 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::declaration> decl) -> void override;

#line 5590 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::function_declaration> f) -> void override;

#line 5748 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::object_declaration> o) -> void override;

#line 5776 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::type_declaration> t) -> void override;

#line 5800 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::parameter_declaration> t) -> void override;

#line 5805 "reflect.h2"
    public: auto traverse(cpp2::impl::in<meta::statement> stmt) -> void override;
    public: autodiff_declaration_handler(autodiff_declaration_handler const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(autodiff_declaration_handler const&) -> void = delete;


#line 5808 "reflect.h2"
};

#line 5811 "reflect.h2"
auto autodiff(meta::type_declaration& t) -> void;

#line 5910 "reflect.h2"
using error_func = std::function<void(cpp2::impl::in<std::string> x)>;

#line 5914 "reflect.h2"
class expression_flags
 {
private: cpp2::u8 _value; private: constexpr expression_flags(cpp2::impl::in<cpp2::i64> _val);

private: constexpr auto operator=(cpp2::impl::in<cpp2::i64> _val) -> expression_flags& ;
public: constexpr auto operator|=(expression_flags const& that) & -> decltype(auto);
public: constexpr auto operator&=(expression_flags const& that) & -> decltype(auto);
public: constexpr auto operator^=(expression_flags const& that) & -> decltype(auto);
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
public: [[nodiscard]] auto to_string_impl(cpp2::impl::in<std::string_view> prefix, cpp2::impl::in<std::string_view> separator) const& -> std::string;
public: [[nodiscard]] auto to_string() const& -> std::string;
public: [[nodiscard]] auto to_code() const& -> std::string;
public: [[nodiscard]] static auto from_string(cpp2::impl::in<std::string_view> s) -> expression_flags;
public: [[nodiscard]] static auto from_code(cpp2::impl::in<std::string_view> s) -> expression_flags;

#line 5922 "reflect.h2"
};

#line 5930 "reflect.h2"
class regex_token
 {
    public: std::string string_rep; 

    public: regex_token(cpp2::impl::in<std::string> str);

#line 5938 "reflect.h2"
    public: explicit regex_token();

#line 5943 "reflect.h2"
    public: virtual auto generate_code([[maybe_unused]] generation_context& unnamed_param_2) const -> void = 0;
    public: [[nodiscard]] virtual auto reverse() const -> std::shared_ptr<regex_token> = 0;

    public: virtual auto add_groups([[maybe_unused]] std::set<int>& unnamed_param_2) const -> void;
    public: [[nodiscard]] auto to_string() const& -> std::string;
    public: auto set_string(cpp2::impl::in<std::string> s) & -> void;
    public: virtual ~regex_token() noexcept;

    public: regex_token(regex_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_token const&) -> void = delete;

#line 5949 "reflect.h2"
};

using token_ptr = std::shared_ptr<regex_token>;
using token_vec = std::vector<token_ptr>;

#line 5955 "reflect.h2"
//  Adds a check in code generation.
//
class regex_token_check
: public regex_token {

#line 5961 "reflect.h2"
    private: std::string check; 

    public: regex_token_check(cpp2::impl::in<std::string> str, cpp2::impl::in<std::string> check_);

#line 5968 "reflect.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 5972 "reflect.h2"
    public: [[nodiscard]] auto reverse() const -> token_ptr override;
    public: virtual ~regex_token_check() noexcept;

    public: regex_token_check(regex_token_check const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_token_check const&) -> void = delete;

#line 5973 "reflect.h2"
};

#line 5976 "reflect.h2"
//  Adds code in code generation.
//
class regex_token_code
: public regex_token {

#line 5982 "reflect.h2"
    private: std::string code; 

    public: regex_token_code(cpp2::impl::in<std::string> str, cpp2::impl::in<std::string> code_);

#line 5989 "reflect.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 5993 "reflect.h2"
    public: [[nodiscard]] auto reverse() const -> token_ptr override;
    public: virtual ~regex_token_code() noexcept;

    public: regex_token_code(regex_token_code const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_token_code const&) -> void = delete;

#line 5994 "reflect.h2"
};

#line 5997 "reflect.h2"
//  Token that does not influence the matching. E.g. comment.
//
class regex_token_empty
: public regex_token {

#line 6003 "reflect.h2"
    public: regex_token_empty(cpp2::impl::in<std::string> str);

#line 6007 "reflect.h2"
    public: auto generate_code([[maybe_unused]] generation_context& unnamed_param_2) const -> void override;

#line 6011 "reflect.h2"
    public: [[nodiscard]] auto reverse() const -> token_ptr override;
    public: virtual ~regex_token_empty() noexcept;

    public: regex_token_empty(regex_token_empty const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_token_empty const&) -> void = delete;

#line 6012 "reflect.h2"
};

#line 6015 "reflect.h2"
//  Represents a list of regex tokens as one token.
//
class regex_token_list
: public regex_token {

#line 6021 "reflect.h2"
    public: token_vec tokens; 

    public: regex_token_list(cpp2::impl::in<token_vec> t);

#line 6028 "reflect.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 6034 "reflect.h2"
    public: auto add_groups(std::set<int>& groups) const -> void override;

#line 6040 "reflect.h2"
    public: [[nodiscard]] static auto gen_string(cpp2::impl::in<token_vec> vec) -> std::string;

#line 6048 "reflect.h2"
    public: [[nodiscard]] auto reverse() const -> token_ptr override;
    public: virtual ~regex_token_list() noexcept;

    public: regex_token_list(regex_token_list const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_token_list const&) -> void = delete;


#line 6060 "reflect.h2"
};

#line 6063 "reflect.h2"
//
//  Parse and generation context.
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

#line 6083 "reflect.h2"
    //  Swap this state with the other one. NOLINTNEXTLINE(performance-noexcept-swap)
    public: auto swap(parse_context_group_state& t) & -> void;

#line 6090 "reflect.h2"
    //  Convert this state into a regex token.
    public: [[nodiscard]] auto get_as_token() & -> token_ptr;

#line 6102 "reflect.h2"
    //  Add a token to the current matcher list.
    public: auto add(cpp2::impl::in<token_ptr> token) & -> void;

#line 6107 "reflect.h2"
    //  True if current matcher list is empty.
    public: [[nodiscard]] auto empty() const& -> bool;

#line 6111 "reflect.h2"
    //  Apply optimizations to the matcher list.
    public: static auto post_process_list(token_vec& list) -> void;
    public: parse_context_group_state(auto const& cur_match_list_, auto const& alternate_match_lists_, auto const& modifiers_);
public: parse_context_group_state();


#line 6125 "reflect.h2"
};

#line 6128 "reflect.h2"
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

#line 6146 "reflect.h2"
    //  Set next group identifier.
    public: auto set_next(cpp2::impl::in<int> g) & -> void;

#line 6152 "reflect.h2"
    //  Start a new alternative branch.
    public: auto next_alternative() & -> void;

#line 6159 "reflect.h2"
    //  Initialize for a branch reset group.
    public: auto set_active_reset(cpp2::impl::in<int> restart) & -> void;
    public: parse_context_branch_reset_state(auto const& is_active_, auto const& cur_group_, auto const& max_group_, auto const& from_);
public: parse_context_branch_reset_state();


#line 6166 "reflect.h2"
};

#line 6169 "reflect.h2"
//  Context during parsing of the regular expressions.
// 
//  Keeps track of the distributed group identifiers, current parsed group and branch resets.
//
class parse_context
 {
    private: std::string_view regex; // Regular expression string.
    private: size_t pos {0};   // Current parsing position.
    private: token_ptr root;   // Token representing the regular expression.

    public: bool is_start_match {false};  // If the regex contains \G at the beginning.

    private: parse_context_group_state cur_group_state {}; 
    private: parse_context_branch_reset_state cur_branch_reset_state {}; 

#line 6185 "reflect.h2"
           public: std::map<std::string,int> named_groups {}; 

    private: error_func error_out; // TODO: Declaring std::function<void(std::string)> fails for cpp2.
    private: bool has_error {false}; 

    public: parse_context(cpp2::impl::in<std::string_view> r, auto const& e);

#line 6196 "reflect.h2"
    //  State management functions
    //

    //  Returned group state needs to be stored and provided in `end_group`.
    public: [[nodiscard]] auto start_group() & -> parse_context_group_state;

#line 6209 "reflect.h2"
    //  `old_state` argument needs to be from start group.
    public: [[nodiscard]] auto end_group(cpp2::impl::in<parse_context_group_state> old_state) & -> token_ptr;

#line 6217 "reflect.h2"
    public: [[nodiscard]] auto get_modifiers() const& -> expression_flags;

#line 6221 "reflect.h2"
    public: auto set_modifiers(cpp2::impl::in<expression_flags> mod) & -> void;

#line 6225 "reflect.h2"
    //  Branch reset management functions
    //

    public: [[nodiscard]] auto branch_reset_new_state() & -> parse_context_branch_reset_state;

#line 6237 "reflect.h2"
    public: auto branch_reset_restore_state(cpp2::impl::in<parse_context_branch_reset_state> old_state) & -> void;

#line 6244 "reflect.h2"
    public: auto next_alternative() & -> void;

#line 6250 "reflect.h2"
    //  Regex token management
    //
    public: auto add_token(cpp2::impl::in<token_ptr> token) & -> void;

#line 6256 "reflect.h2"
    public: [[nodiscard]] auto has_token() const& -> bool;

#line 6260 "reflect.h2"
    public: [[nodiscard]] auto pop_token() & -> token_ptr;

#line 6271 "reflect.h2"
    public: [[nodiscard]] auto get_as_token() & -> token_ptr;

#line 6275 "reflect.h2"
    //  Group management
    //
    public: [[nodiscard]] auto get_cur_group() const& -> int;

#line 6281 "reflect.h2"
    public: [[nodiscard]] auto next_group() & -> int;

#line 6285 "reflect.h2"
    public: auto set_named_group(cpp2::impl::in<std::string> name, cpp2::impl::in<int> id) & -> void;

#line 6292 "reflect.h2"
    public: [[nodiscard]] auto get_named_group(cpp2::impl::in<std::string> name) const& -> int;

#line 6303 "reflect.h2"
    //  Position management functions
    //
    public: [[nodiscard]] auto current() const& -> char;

    //  Get the next token in the regex, skipping spaces according to the parameters. See `x` and `xx` modifiers.
    private: [[nodiscard]] auto get_next_position(cpp2::impl::in<bool> in_class, cpp2::impl::in<bool> no_skip) const& -> size_t;

#line 6347 "reflect.h2"
    //  Return true if next token is available.
    private: [[nodiscard]] auto next_impl(cpp2::impl::in<bool> in_class, cpp2::impl::in<bool> no_skip) & -> bool;

#line 6359 "reflect.h2"
    public: [[nodiscard]] auto next() & -> decltype(auto);
    public: [[nodiscard]] auto next_in_class() & -> decltype(auto);
    public: [[nodiscard]] auto next_no_skip() & -> decltype(auto);

    public: [[nodiscard]] auto next_n(cpp2::impl::in<int> n) & -> bool;

#line 6372 "reflect.h2"
    public: [[nodiscard]] auto has_next() const& -> bool;

    private: [[nodiscard]] auto grab_until_impl(cpp2::impl::in<std::string> e, cpp2::impl::out<std::string> r, cpp2::impl::in<bool> any) & -> bool;

#line 6395 "reflect.h2"
    public: [[nodiscard]] auto grab_until(cpp2::impl::in<std::string> e, cpp2::impl::out<std::string> r) & -> decltype(auto);
    public: [[nodiscard]] auto grab_until(cpp2::impl::in<char> e, cpp2::impl::out<std::string> r) & -> decltype(auto);
    public: [[nodiscard]] auto grab_until_one_of(cpp2::impl::in<std::string> e, cpp2::impl::out<std::string> r) & -> decltype(auto);

    public: [[nodiscard]] auto grab_n(cpp2::impl::in<int> n, cpp2::impl::out<std::string> r) & -> bool;

#line 6412 "reflect.h2"
    public: [[nodiscard]] auto grab_number() & -> std::string;

#line 6433 "reflect.h2"
    private: [[nodiscard]] auto peek_impl(cpp2::impl::in<bool> in_class) const& -> char;

#line 6443 "reflect.h2"
    public: [[nodiscard]] auto peek() const& -> decltype(auto);
    public: [[nodiscard]] auto peek_in_class() const& -> decltype(auto);

#line 6447 "reflect.h2"
    //  Parsing functions
    //
    public: [[nodiscard]] auto parser_group_modifiers(cpp2::impl::in<std::string> change_str, expression_flags& parser_modifiers) & -> bool;

#line 6503 "reflect.h2"
    public: [[nodiscard]] auto parse_until(cpp2::impl::in<char> term) & -> bool;

#line 6542 "reflect.h2"
    public: [[nodiscard]] auto parse(cpp2::impl::in<std::string> modifiers) & -> bool;

#line 6557 "reflect.h2"
    //  Misc functions

    public: [[nodiscard]] auto get_pos() const& -> decltype(auto);
    public: [[nodiscard]] auto get_range(cpp2::impl::in<size_t> start, cpp2::impl::in<size_t> end) const& -> decltype(auto);
    public: [[nodiscard]] auto valid() const& -> bool;

    public: [[nodiscard]] auto error(cpp2::impl::in<std::string> err) & -> token_ptr;
    public: parse_context(parse_context const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(parse_context const&) -> void = delete;


#line 6568 "reflect.h2"
};

#line 6571 "reflect.h2"
//  Context for one function generation. Generation of functions can be interleaved,
//  therefore we buffer the code for one function here.
//
class generation_function_context {
    public: std::string code {""}; 
    public: std::string tabs {""}; 

    public: auto add_tabs(cpp2::impl::in<int> c) & -> void;

#line 6585 "reflect.h2"
    public: auto remove_tabs(cpp2::impl::in<int> c) & -> void;
    public: generation_function_context(auto const& code_, auto const& tabs_);
public: generation_function_context();


#line 6588 "reflect.h2"
};

#line 6591 "reflect.h2"
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

#line 6613 "reflect.h2"
    //  Add check for token. The check needs to be a function call that returns a boolean.
    public: auto add_check(cpp2::impl::in<std::string> check) & -> void;

#line 6619 "reflect.h2"
    //  Add a stateful check. The check needs to return a `match_return`.
    public: auto add_statefull(cpp2::impl::in<std::string> next_func, cpp2::impl::in<std::string> check) & -> void;

#line 6628 "reflect.h2"
    protected: auto start_func_named(cpp2::impl::in<std::string> name) & -> void;

#line 6639 "reflect.h2"
    protected: [[nodiscard]] auto start_func() & -> std::string;

#line 6646 "reflect.h2"
    protected: auto end_func_statefull(cpp2::impl::in<std::string> s) & -> void;

#line 6666 "reflect.h2"
    //  Generate the function for a token.
    public: [[nodiscard]] auto generate_func(cpp2::impl::in<token_ptr> token) & -> std::string;

#line 6676 "reflect.h2"
    //  Generate the reset for a list of group identifiers.
    public: [[nodiscard]] auto generate_reset(cpp2::impl::in<std::set<int>> groups) & -> std::string;

#line 6699 "reflect.h2"
    //  Name generation
    //
    protected: [[nodiscard]] auto gen_func_name() & -> std::string;

#line 6707 "reflect.h2"
    public: [[nodiscard]] auto next_func_name() & -> std::string;

#line 6711 "reflect.h2"
    protected: [[nodiscard]] auto gen_reset_func_name() & -> std::string;

#line 6717 "reflect.h2"
    public: [[nodiscard]] auto gen_temp() & -> std::string;

#line 6723 "reflect.h2"
    //  Context management
    //
    public: [[nodiscard]] auto new_context() & -> generation_function_context*;

#line 6733 "reflect.h2"
    public: auto finish_context() & -> void;

#line 6741 "reflect.h2"
    //  Misc functions
    //
    private: [[nodiscard]] auto get_current() & -> generation_function_context*;

#line 6747 "reflect.h2"
    private: [[nodiscard]] auto get_base() & -> generation_function_context*;

#line 6751 "reflect.h2"
    public: [[nodiscard]] auto get_entry_func() const& -> std::string;

#line 6755 "reflect.h2"
    public: [[nodiscard]] auto create_named_group_lookup(cpp2::impl::in<std::map<std::string,int>> named_groups) const& -> std::string;

#line 6779 "reflect.h2"
    //  Run the generation for the token.
    public: [[nodiscard]] auto run(cpp2::impl::in<token_ptr> token) & -> std::string;
    public: generation_context() = default;
    public: generation_context(generation_context const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(generation_context const&) -> void = delete;


#line 6785 "reflect.h2"
};

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


#line 6804 "reflect.h2"
};

class alternative_token_gen
: public regex_token {

#line 6810 "reflect.h2"
    private: token_vec alternatives; 

    public: alternative_token_gen(cpp2::impl::in<token_vec> a);

#line 6817 "reflect.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 6834 "reflect.h2"
    public: auto add_groups(std::set<int>& groups) const -> void override;

#line 6841 "reflect.h2"
    public: [[nodiscard]] static auto gen_string(cpp2::impl::in<token_vec> a) -> std::string;

#line 6854 "reflect.h2"
    public: [[nodiscard]] auto reverse() const -> token_ptr override;
    public: virtual ~alternative_token_gen() noexcept;

    public: alternative_token_gen(alternative_token_gen const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(alternative_token_gen const&) -> void = delete;


#line 6866 "reflect.h2"
};

#line 6869 "reflect.h2"
//  Regex syntax: .
//
class any_token
: public regex_token_check {

#line 6875 "reflect.h2"
    public: any_token(cpp2::impl::in<bool> single_line);

#line 6879 "reflect.h2"
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;
    public: virtual ~any_token() noexcept;

    public: any_token(any_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(any_token const&) -> void = delete;


#line 6884 "reflect.h2"
};

//  Regex syntax: (?><matcher>)  Example: a(?>bc|c)c
//
class atomic_group_token
: public regex_token {

#line 6892 "reflect.h2"
            public: token_ptr inner_token {nullptr}; 

    public: explicit atomic_group_token();

    public: [[nodiscard]] auto reverse() const -> token_ptr override;

#line 6903 "reflect.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 6911 "reflect.h2"
    public: auto add_groups(std::set<int>& groups) const -> void override;
    public: virtual ~atomic_group_token() noexcept;

    public: atomic_group_token(atomic_group_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(atomic_group_token const&) -> void = delete;


#line 6914 "reflect.h2"
};

//  Regex syntax: a
//
class char_token
: public regex_token {

#line 6922 "reflect.h2"
    private: std::string token; 
    private: bool ignore_case; 

    public: char_token(cpp2::impl::in<char> t, cpp2::impl::in<bool> ignore_case_);

#line 6931 "reflect.h2"
    public: char_token(cpp2::impl::in<std::string> t, cpp2::impl::in<bool> ignore_case_);

#line 6937 "reflect.h2"
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 6941 "reflect.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 6964 "reflect.h2"
    public: auto gen_case_insensitive(cpp2::impl::in<std::string> lower, cpp2::impl::in<std::string> upper, generation_context& ctx) const& -> void;

#line 6985 "reflect.h2"
    public: auto gen_case_sensitive(generation_context& ctx) const& -> void;

#line 7003 "reflect.h2"
    public: [[nodiscard]] auto add_escapes(std::string str) const& -> std::string;

#line 7018 "reflect.h2"
    public: [[nodiscard]] auto reverse() const -> token_ptr override;

#line 7024 "reflect.h2"
    public: auto append(char_token const& that) & -> void;
    public: virtual ~char_token() noexcept;

    public: char_token(char_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(char_token const&) -> void = delete;


#line 7028 "reflect.h2"
};

#line 7031 "reflect.h2"
//  Regex syntax: [<character classes>]  Example: [abcx-y[:digits:]]
//
class class_token
: public regex_token {

#line 7037 "reflect.h2"
    private: bool negate; 
    private: bool case_insensitive; 
    private: std::string class_str; 

    public: class_token(cpp2::impl::in<bool> negate_, cpp2::impl::in<bool> case_insensitive_, cpp2::impl::in<std::string> class_str_, cpp2::impl::in<std::string> str);

#line 7049 "reflect.h2"
    //  TODO: Rework class generation: Generate check functions for classes.
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 7175 "reflect.h2"
    public: [[nodiscard]] auto reverse() const -> token_ptr override;

#line 7184 "reflect.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 7189 "reflect.h2"
    private: [[nodiscard]] static auto create_matcher(cpp2::impl::in<std::string> name, cpp2::impl::in<std::string> template_arguments) -> std::string;
    public: virtual ~class_token() noexcept;

    public: class_token(class_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(class_token const&) -> void = delete;


#line 7196 "reflect.h2"
};

#line 7199 "reflect.h2"
//  Regex syntax: \a or \n or \[
//
[[nodiscard]] auto escape_token_parse(parse_context& ctx) -> token_ptr;

#line 7240 "reflect.h2"
//  Regex syntax: \K Example: ab\Kcd
//
[[nodiscard]] auto global_group_reset_token_parse(parse_context& ctx) -> token_ptr;

#line 7251 "reflect.h2"
//  Regex syntax: \<number>  Example: \1
//                \g{name_or_number}
//                \k{name_or_number}
//                \k<name_or_number>
//                \k'name_or_number'
//
class group_ref_token
: public regex_token {

#line 7261 "reflect.h2"
    private: int id; 
    private: bool case_insensitive; 
    private: bool reverse_eval; 

    public: group_ref_token(cpp2::impl::in<int> id_, cpp2::impl::in<bool> case_insensitive_, cpp2::impl::in<bool> reverse_, cpp2::impl::in<std::string> str);

#line 7273 "reflect.h2"
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 7374 "reflect.h2"
    public: [[nodiscard]] auto reverse() const -> token_ptr override;

#line 7378 "reflect.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;
    public: virtual ~group_ref_token() noexcept;

    public: group_ref_token(group_ref_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_ref_token const&) -> void = delete;


#line 7381 "reflect.h2"
};

#line 7384 "reflect.h2"
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

#line 7398 "reflect.h2"
    private: int number {-1}; 
    private: bool reverse_eval {false}; 
    private: token_ptr inner {nullptr}; 

    public: [[nodiscard]] static auto parse_lookahead_lookbehind(parse_context& ctx, cpp2::impl::in<std::string> syntax, cpp2::impl::in<bool> lookahead, cpp2::impl::in<bool> positive) -> token_ptr;

#line 7420 "reflect.h2"
    public: [[nodiscard]] static auto parse_atomic_pattern(parse_context& ctx, cpp2::impl::in<std::string> syntax) -> token_ptr;

#line 7434 "reflect.h2"
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 7593 "reflect.h2"
    public: [[nodiscard]] auto reverse() const -> token_ptr override;

#line 7601 "reflect.h2"
    public: [[nodiscard]] static auto gen_string(cpp2::impl::in<std::string> name, cpp2::impl::in<bool> name_brackets, cpp2::impl::in<bool> has_modifier, cpp2::impl::in<std::string> modifiers, cpp2::impl::in<token_ptr> inner_) -> std::string;

#line 7619 "reflect.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 7650 "reflect.h2"
    public: auto add_groups(std::set<int>& groups) const -> void override;
    public: virtual ~group_token() noexcept;

    public: group_token() = default;
    public: group_token(group_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_token const&) -> void = delete;


#line 7657 "reflect.h2"
};

#line 7660 "reflect.h2"
//  Regex syntax: \x<number> or \x{<number>}  Example: \x{62}
//
[[nodiscard]] auto hexadecimal_token_parse(parse_context& ctx) -> token_ptr;

#line 7701 "reflect.h2"
//  Regex syntax: $  Example: aa$
//
[[nodiscard]] auto line_end_token_parse(parse_context& ctx) -> token_ptr;

#line 7721 "reflect.h2"
//  Regex syntax: ^  Example: ^aa
//
[[nodiscard]] auto line_start_token_parse(parse_context& ctx) -> token_ptr;

#line 7737 "reflect.h2"
//  Regex syntax: (?=) or (?!) or (*pla), etc.  Example: (?=AA)
//
//  Parsed in group_token.
//
class lookahead_lookbehind_token
: public regex_token {

#line 7745 "reflect.h2"
    protected: bool lookahead; 
    protected: bool positive; 
    public:   token_ptr inner {nullptr}; 

    public: lookahead_lookbehind_token(cpp2::impl::in<bool> lookahead_, cpp2::impl::in<bool> positive_);

#line 7754 "reflect.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 7765 "reflect.h2"
    public: [[nodiscard]] auto reverse() const -> token_ptr override;

#line 7772 "reflect.h2"
    public: auto add_groups(std::set<int>& groups) const -> void override;
    public: virtual ~lookahead_lookbehind_token() noexcept;

    public: lookahead_lookbehind_token(lookahead_lookbehind_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(lookahead_lookbehind_token const&) -> void = delete;


#line 7775 "reflect.h2"
};

#line 7778 "reflect.h2"
// Named character classes
//
[[nodiscard]] auto named_class_token_parse(parse_context& ctx) -> token_ptr;

#line 7806 "reflect.h2"
//  Regex syntax: \o{<number>}  Example: \o{142}
//
[[nodiscard]] auto octal_token_parse(parse_context& ctx) -> token_ptr;

#line 7834 "reflect.h2"
//  Regex syntax: <matcher>{min, max}  Example: a{2,4}
//
class range_token
: public regex_token {

#line 7840 "reflect.h2"
              protected: int min_count {-1}; 
              protected: int max_count {-1}; 
              protected: int kind {range_flags::greedy}; 
              protected: token_ptr inner_token {nullptr}; 

    public: explicit range_token();

    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 7920 "reflect.h2"
    public: auto parse_modifier(parse_context& ctx) & -> void;

#line 7932 "reflect.h2"
    public: [[nodiscard]] auto gen_mod_string() const& -> std::string;

#line 7945 "reflect.h2"
    public: [[nodiscard]] auto gen_range_string() const& -> std::string;

#line 7964 "reflect.h2"
    public: [[nodiscard]] auto reverse() const -> token_ptr override;

#line 7974 "reflect.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 7985 "reflect.h2"
    public: auto add_groups(std::set<int>& groups) const -> void override;
    public: virtual ~range_token() noexcept;

    public: range_token(range_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_token const&) -> void = delete;


#line 7988 "reflect.h2"
};

#line 7991 "reflect.h2"
//  Regex syntax: *, +, or ?  Example: aa*
//
class special_range_token
: public range_token {

#line 7997 "reflect.h2"
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;
    public: virtual ~special_range_token() noexcept;

    public: special_range_token() = default;
    public: special_range_token(special_range_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(special_range_token const&) -> void = delete;


#line 8027 "reflect.h2"
};

//  Regex syntax: \G  Example: \Gaa
//
//  Forces the match and/or consecutive matches to start at the position of the last match.
//
[[nodiscard]] auto start_match_parse(parse_context& ctx) -> token_ptr;

#line 8049 "reflect.h2"
//  Regex syntax: \b or \B  Example: \bword\b
//
//  Matches the start end end of word boundaries.
//
[[nodiscard]] auto word_boundary_token_parse(parse_context& ctx) -> token_ptr;

#line 8071 "reflect.h2"
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

    public: regex_generator(cpp2::impl::in<std::string_view> r, Error_out const& e);

#line 8094 "reflect.h2"
    public: [[nodiscard]] auto parse() & -> std::string;

#line 8129 "reflect.h2"
    private: auto extract_modifiers() & -> void;
    public: regex_generator(regex_generator const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_generator const&) -> void = delete;


#line 8143 "reflect.h2"
};

template<typename Err> [[nodiscard]] auto generate_regex(cpp2::impl::in<std::string_view> regex, Err const& err) -> std::string;

#line 8155 "reflect.h2"
auto regex_gen(meta::type_declaration& t) -> void;

#line 8210 "reflect.h2"
//-----------------------------------------------------------------------
//
//  apply_metafunctions
//
[[nodiscard]] auto apply_metafunctions(
    declaration_node& n, 
    type_declaration& rtype, 
    auto const& error
    ) -> bool;

#line 8342 "reflect.h2"
}

}


//=== Cpp2 function definitions =================================================

#line 1 "reflect.h2"

#line 17 "reflect.h2"
namespace cpp2 {

namespace meta {

#line 22 "reflect.h2"
//-----------------------------------------------------------------------
//
//  Compiler services
//
//-----------------------------------------------------------------------
//

#line 31 "reflect.h2"
    //  Common data members
    //

#line 45 "reflect.h2"
    //  Constructor
    //
#line 47 "reflect.h2"
    compiler_services::compiler_services(

        cpp2::impl::in<std::vector<error_entry>*> errors_, 
        cpp2::impl::in<std::set<std::string>*> includes_, 
        cpp2::impl::in<std::vector<std::string>*> extra_cpp1_, 
        cpp2::impl::in<std::vector<std::string>*> extra_build_, 
        cpp2::impl::in<std::string> filename, 
        cpp2::impl::in<stable_vector<token>*> generated_tokens_
    )
        : errors{ errors_ }
        , includes{ includes_ }
        , extra_cpp1{ extra_cpp1_ }
        , extra_build{ extra_build_ }
        , file_name{ filename }
        , errors_original_size{ cpp2::unchecked_narrow<int>(std::ssize(*cpp2::impl::assert_not_null(errors))) }
        , generated_tokens{ generated_tokens_ }
        , parser{ *cpp2::impl::assert_not_null(errors), *cpp2::impl::assert_not_null(includes), *cpp2::impl::assert_not_null(extra_cpp1), *cpp2::impl::assert_not_null(extra_build), file_name }
#line 56 "reflect.h2"
    {

#line 65 "reflect.h2"
    }

    //  Common API
    //
#line 69 "reflect.h2"
    [[nodiscard]] auto compiler_services::filename() const& -> std::string_view { return file_name;  }

#line 71 "reflect.h2"
    auto compiler_services::set_metafunction_name(cpp2::impl::in<std::string_view> name, cpp2::impl::in<std::vector<std::string>> args) & -> void{
        metafunction_name  = name;
        metafunction_args  = args;
        metafunctions_used = CPP2_UFCS(empty)(args);
    }

#line 77 "reflect.h2"
    [[nodiscard]] auto compiler_services::get_metafunction_name() const& -> std::string_view { return metafunction_name;  }

#line 79 "reflect.h2"
    [[nodiscard]] auto compiler_services::get_argument(cpp2::impl::in<int> index) & -> std::string{
        metafunctions_used = true;
        if (([_0 = 0, _1 = index, _2 = CPP2_UFCS(ssize)(metafunction_args)]{ return cpp2::impl::cmp_less_eq(_0,_1) && cpp2::impl::cmp_less(_1,_2); }())) {
            return CPP2_ASSERT_IN_BOUNDS(metafunction_args, index); 
        }
        return ""; 
    }

#line 87 "reflect.h2"
    [[nodiscard]] auto compiler_services::get_arguments() & -> std::vector<std::string>{
        metafunctions_used = true;
        return metafunction_args; 
    }

#line 92 "reflect.h2"
    [[nodiscard]] auto compiler_services::arguments_were_used() const& -> bool { return metafunctions_used;  }

#line 94 "reflect.h2"
    [[nodiscard]] auto compiler_services::parse_statement(

        std::string_view source
    ) & -> parse_statement_ret

    {
            cpp2::impl::deferred_init<std::unique_ptr<statement_node>> ret;
#line 100 "reflect.h2"
        auto original_source {source}; 

        CPP2_UFCS(push_back)(generated_lines, std::vector<source_line>());
        auto lines {&CPP2_UFCS(back)(generated_lines)}; 

        auto add_line {[&, _1 = lines](cpp2::impl::in<std::string_view> s) mutable -> void{
            static_cast<void>(CPP2_UFCS(emplace_back)((*cpp2::impl::assert_not_null(_1)), s, source_line::category::cpp2));
        }}; 
{
auto newline_pos{CPP2_UFCS(find)(source, '\n')};

        //  First split this string into source_lines
        //

#line 112 "reflect.h2"
        if ( cpp2::impl::cmp_greater(CPP2_UFCS(ssize)(source),1) 
            && newline_pos != source.npos) 
        {
            while( newline_pos != source.npos ) 
            {
                add_line(CPP2_UFCS(substr)(source, 0, newline_pos));
                CPP2_UFCS(remove_prefix)(source, newline_pos + 1);
                newline_pos = CPP2_UFCS(find)(source, '\n');
            }
        }
}

#line 123 "reflect.h2"
        if (!(CPP2_UFCS(empty)(source))) {
            cpp2::move(add_line)(cpp2::move(source));
        }

        //  Now lex this source fragment to generate
        //  a single grammar_map entry, whose .second
        //  is the vector of tokens
        static_cast<void>(CPP2_UFCS(emplace_back)(generated_lexers, *cpp2::impl::assert_not_null(errors)));
        auto tokens {&CPP2_UFCS(back)(generated_lexers)}; 
        CPP2_UFCS(lex)((*cpp2::impl::assert_not_null(tokens)), *cpp2::impl::assert_not_null(cpp2::move(lines)), true);

        if (cpp2::cpp2_default.is_active() && !(std::ssize(CPP2_UFCS(get_map)((*cpp2::impl::assert_not_null(tokens)))) == 1) ) { cpp2::cpp2_default.report_violation(""); }

        //  Now parse this single declaration from
        //  the lexed tokens
        ret.construct(CPP2_UFCS(parse_one_declaration)(parser, 
                (*cpp2::impl::assert_not_null(CPP2_UFCS(begin)(CPP2_UFCS(get_map)(*cpp2::impl::assert_not_null(cpp2::move(tokens)))))).second, 
                *cpp2::impl::assert_not_null(generated_tokens)
              ));
        if (!(ret.value())) {
            error("parse failed - the source string is not a valid statement:\n" + cpp2::to_string(cpp2::move(original_source)) + "");
        }return std::move(ret.value()); 
    }

#line 147 "reflect.h2"
    auto compiler_services::add_runtime_support_include(cpp2::impl::in<std::string_view> s, cpp2::impl::in<bool> angles) & -> void{
        std::string inc {s}; 
        if (angles) {
            inc = "<" + inc + ">";
        }
        else {
            inc = "\"" + inc + "\"";
        }
        static_cast<void>(CPP2_UFCS(emplace)((*cpp2::impl::assert_not_null(includes)), cpp2::move(inc)));
    }

#line 158 "reflect.h2"
    [[nodiscard]] auto compiler_services::add_extra_cpp1_code(cpp2::impl::in<std::string> s) & -> decltype(auto) { return CPP2_UFCS(push_back)((*cpp2::impl::assert_not_null(extra_cpp1)), s);  }
#line 159 "reflect.h2"
    [[nodiscard]] auto compiler_services::add_extra_build_step(cpp2::impl::in<std::string> s) & -> decltype(auto) { return CPP2_UFCS(push_back)((*cpp2::impl::assert_not_null(extra_build)), s + "\n");  }

#line 161 "reflect.h2"
    [[nodiscard]] auto compiler_services::position() const -> source_position

    {
        return {  }; 
    }

    //  Error diagnosis and handling, integrated with compiler output
    //  Unlike a contract violation, .requires continues further processing
    //
#line 170 "reflect.h2"
    auto compiler_services::require(

        cpp2::impl::in<bool> b, 
        cpp2::impl::in<std::string_view> msg
    ) const& -> void
    {
        if (!(b)) {
            error(msg);
        }
    }

#line 181 "reflect.h2"
    auto compiler_services::error(cpp2::impl::in<std::string_view> msg) const& -> void
    {
        auto message {cpp2::impl::as_<std::string>(msg)}; 
        if (!(CPP2_UFCS(empty)(metafunction_name))) {
            message = "while applying @" + cpp2::to_string(metafunction_name) + " - " + cpp2::to_string(message) + "";
        }
        static_cast<void>(CPP2_UFCS(emplace_back)((*cpp2::impl::assert_not_null(errors)), position(), cpp2::move(message)));
    }

    //  Enable custom contracts on this object, integrated with compiler output
    //  Unlike .requires, a contract violation stops further processing
    //
#line 193 "reflect.h2"
    auto compiler_services::report_violation(auto const& msg) const& -> void{
        error(msg);
        throw(std::runtime_error(
            "  ==> programming bug found in metafunction @" + cpp2::to_string(metafunction_name) + " "
            "- contract violation - see previous errors"
        ));
    }

#line 201 "reflect.h2"
    [[nodiscard]] auto compiler_services::is_active() const& -> decltype(auto) { return true;  }

    compiler_services::~compiler_services() noexcept{}
compiler_services::compiler_services(compiler_services const& that)
                                     : errors{ that.errors }
                                     , includes{ that.includes }
                                     , extra_cpp1{ that.extra_cpp1 }
                                     , extra_build{ that.extra_build }
                                     , file_name{ that.file_name }
                                     , errors_original_size{ that.errors_original_size }
                                     , generated_tokens{ that.generated_tokens }
                                     , parser{ that.parser }
                                     , metafunction_name{ that.metafunction_name }
                                     , metafunction_args{ that.metafunction_args }
                                     , metafunctions_used{ that.metafunctions_used }{}
compiler_services::compiler_services(compiler_services&& that) noexcept
                                     : errors{ std::move(that).errors }
                                     , includes{ std::move(that).includes }
                                     , extra_cpp1{ std::move(that).extra_cpp1 }
                                     , extra_build{ std::move(that).extra_build }
                                     , file_name{ std::move(that).file_name }
                                     , errors_original_size{ std::move(that).errors_original_size }
                                     , generated_tokens{ std::move(that).generated_tokens }
                                     , parser{ std::move(that).parser }
                                     , metafunction_name{ std::move(that).metafunction_name }
                                     , metafunction_args{ std::move(that).metafunction_args }
                                     , metafunctions_used{ std::move(that).metafunctions_used }{}

#line 205 "reflect.h2"
//-----------------------------------------------------------------------
//
//  All reflection types are wrappers around a pointer to node
//
//-----------------------------------------------------------------------
//

#line 218 "reflect.h2"
    template <typename T> reflection_base<T>::reflection_base(

        cpp2::impl::in<T*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : compiler_services{ s }
        , n{ n_ }
#line 223 "reflect.h2"
    {

#line 226 "reflect.h2"
        if (cpp2::cpp2_default.is_active() && !(n) ) { cpp2::cpp2_default.report_violation(CPP2_CONTRACT_MSG("a meta:: reflection must point to a valid node, not null")); }
    }

#line 229 "reflect.h2"
    template <typename T> [[nodiscard]] auto reflection_base<T>::position() const -> source_position { return CPP2_UFCS(position)((*cpp2::impl::assert_not_null(n)));  }

#line 231 "reflect.h2"
    template <typename T> [[nodiscard]] auto reflection_base<T>::print() const& -> std::string { return CPP2_UFCS(pretty_print_visualize)((*cpp2::impl::assert_not_null(n)), 0);  }

#line 233 "reflect.h2"
    template <typename T> [[nodiscard]] auto reflection_base<T>::is_same(cpp2::impl::in<reflection_base> o) const& -> bool { return n == o.n; }// Test pointers
#line 234 "reflect.h2"
    template <typename T> template<typename TO> [[nodiscard]] auto reflection_base<T>::is_same(reflection_base<TO> const& o) const& -> bool { return false;  }

    template <typename T> reflection_base<T>::~reflection_base() noexcept{}
template <typename T> reflection_base<T>::reflection_base(reflection_base const& that)
                                     : compiler_services{ static_cast<compiler_services const&>(that) }
                                     , n{ that.n }{}
template <typename T> reflection_base<T>::reflection_base(reflection_base&& that) noexcept
                                     : compiler_services{ static_cast<compiler_services&&>(that) }
                                     , n{ std::move(that).n }{}// Different types => false

#line 238 "reflect.h2"
//-----------------------------------------------------------------------
//
//  Declarations
//
//-----------------------------------------------------------------------
//

//-----------------------------------------------------------------------
//  All declarations
//

#line 252 "reflect.h2"
    declaration::declaration(

        cpp2::impl::in<declaration_node*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : reflection_base<declaration_node>{ n_, s }
#line 257 "reflect.h2"
    {

    }

#line 261 "reflect.h2"
    [[nodiscard]] auto declaration::is_public() const& -> bool { return CPP2_UFCS(is_public)((*cpp2::impl::assert_not_null(n))); }
#line 262 "reflect.h2"
    [[nodiscard]] auto declaration::is_protected() const& -> bool { return CPP2_UFCS(is_protected)((*cpp2::impl::assert_not_null(n))); }
#line 263 "reflect.h2"
    [[nodiscard]] auto declaration::is_private() const& -> bool { return CPP2_UFCS(is_private)((*cpp2::impl::assert_not_null(n))); }
#line 264 "reflect.h2"
    [[nodiscard]] auto declaration::is_default_access() const& -> bool { return CPP2_UFCS(is_default_access)((*cpp2::impl::assert_not_null(n)));  }

#line 266 "reflect.h2"
    [[nodiscard]] auto declaration::default_to_public() & -> decltype(auto) { return static_cast<void>(CPP2_UFCS(make_public)((*cpp2::impl::assert_not_null(n)))); }
#line 267 "reflect.h2"
    [[nodiscard]] auto declaration::default_to_protected() & -> decltype(auto) { return static_cast<void>(CPP2_UFCS(make_protected)((*cpp2::impl::assert_not_null(n))));  }
#line 268 "reflect.h2"
    [[nodiscard]] auto declaration::default_to_private() & -> decltype(auto) { return static_cast<void>(CPP2_UFCS(make_private)((*cpp2::impl::assert_not_null(n)))); }

#line 270 "reflect.h2"
    [[nodiscard]] auto declaration::make_public() & -> bool { return CPP2_UFCS(make_public)((*cpp2::impl::assert_not_null(n))); }
#line 271 "reflect.h2"
    [[nodiscard]] auto declaration::make_protected() & -> bool { return CPP2_UFCS(make_protected)((*cpp2::impl::assert_not_null(n))); }
#line 272 "reflect.h2"
    [[nodiscard]] auto declaration::make_private() & -> bool { return CPP2_UFCS(make_private)((*cpp2::impl::assert_not_null(n))); }

#line 274 "reflect.h2"
    [[nodiscard]] auto declaration::has_name() const& -> bool { return CPP2_UFCS(has_name)((*cpp2::impl::assert_not_null(n))); }
#line 275 "reflect.h2"
    [[nodiscard]] auto declaration::has_name(cpp2::impl::in<std::string_view> s) const& -> bool { return CPP2_UFCS(has_name)((*cpp2::impl::assert_not_null(n)), s); }

#line 277 "reflect.h2"
    [[nodiscard]] auto declaration::name() const& -> std::string_view{
        if (has_name()) {return CPP2_UFCS(as_string_view)((*cpp2::impl::assert_not_null(CPP2_UFCS(name)(*cpp2::impl::assert_not_null(n))))); }
        else          { return ""; }
    }

#line 282 "reflect.h2"
    [[nodiscard]] auto declaration::has_initializer() const& -> bool { return CPP2_UFCS(has_initializer)((*cpp2::impl::assert_not_null(n)));  }

#line 284 "reflect.h2"
    [[nodiscard]] auto declaration::get_initializer() const& -> statement { return { CPP2_UFCS(get)((*cpp2::impl::assert_not_null(n)).initializer), (*this) };  }

#line 286 "reflect.h2"
    [[nodiscard]] auto declaration::is_global() const& -> bool { return CPP2_UFCS(is_global)((*cpp2::impl::assert_not_null(n))); }
#line 287 "reflect.h2"
    [[nodiscard]] auto declaration::is_function() const& -> bool { return CPP2_UFCS(is_function)((*cpp2::impl::assert_not_null(n))); }
#line 288 "reflect.h2"
    [[nodiscard]] auto declaration::is_object() const& -> bool { return CPP2_UFCS(is_object)((*cpp2::impl::assert_not_null(n))); }
#line 289 "reflect.h2"
    [[nodiscard]] auto declaration::is_base_object() const& -> bool { return CPP2_UFCS(is_base_object)((*cpp2::impl::assert_not_null(n))); }
#line 290 "reflect.h2"
    [[nodiscard]] auto declaration::is_member_object() const& -> bool { return CPP2_UFCS(is_member_object)((*cpp2::impl::assert_not_null(n)));  }
#line 291 "reflect.h2"
    [[nodiscard]] auto declaration::is_type() const& -> bool { return CPP2_UFCS(is_type)((*cpp2::impl::assert_not_null(n))); }
#line 292 "reflect.h2"
    [[nodiscard]] auto declaration::is_namespace() const& -> bool { return CPP2_UFCS(is_namespace)((*cpp2::impl::assert_not_null(n))); }
#line 293 "reflect.h2"
    [[nodiscard]] auto declaration::is_alias() const& -> bool { return CPP2_UFCS(is_alias)((*cpp2::impl::assert_not_null(n))); }

#line 295 "reflect.h2"
    [[nodiscard]] auto declaration::is_type_alias() const& -> bool { return CPP2_UFCS(is_type_alias)((*cpp2::impl::assert_not_null(n))); }
#line 296 "reflect.h2"
    [[nodiscard]] auto declaration::is_namespace_alias() const& -> bool { return CPP2_UFCS(is_namespace_alias)((*cpp2::impl::assert_not_null(n)));  }
#line 297 "reflect.h2"
    [[nodiscard]] auto declaration::is_object_alias() const& -> bool { return CPP2_UFCS(is_object_alias)((*cpp2::impl::assert_not_null(n))); }

#line 299 "reflect.h2"
    [[nodiscard]] auto declaration::is_function_expression() const& -> bool { return CPP2_UFCS(is_function_expression)((*cpp2::impl::assert_not_null(n)));  }

#line 301 "reflect.h2"
    [[nodiscard]] auto declaration::as_function() const& -> function_declaration { return { n, (*this) }; }
#line 302 "reflect.h2"
    [[nodiscard]] auto declaration::as_object() const& -> object_declaration { return { n, (*this) }; }
#line 303 "reflect.h2"
    [[nodiscard]] auto declaration::as_type() const& -> type_declaration { return { n, (*this) }; }
#line 304 "reflect.h2"
    [[nodiscard]] auto declaration::as_nonglobal_namespace() const& -> namespace_declaration { return { n, (*this) };  }
#line 305 "reflect.h2"
    [[nodiscard]] auto declaration::as_alias() const& -> alias_declaration { return { n, (*this) }; }

#line 307 "reflect.h2"
    [[nodiscard]] auto declaration::get_parent() const& -> declaration { return declaration((*cpp2::impl::assert_not_null(n)).parent_declaration, (*this)); }

#line 309 "reflect.h2"
    [[nodiscard]] auto declaration::parent_is_function() const& -> bool { return CPP2_UFCS(parent_is_function)((*cpp2::impl::assert_not_null(n))); }
#line 310 "reflect.h2"
    [[nodiscard]] auto declaration::parent_is_object() const& -> bool { return CPP2_UFCS(parent_is_object)((*cpp2::impl::assert_not_null(n))); }
#line 311 "reflect.h2"
    [[nodiscard]] auto declaration::parent_is_type() const& -> bool { return CPP2_UFCS(parent_is_type)((*cpp2::impl::assert_not_null(n))); }
#line 312 "reflect.h2"
    [[nodiscard]] auto declaration::parent_is_nonglobal_namespace() const& -> bool { return CPP2_UFCS(parent_is_nonglobal_namespace)((*cpp2::impl::assert_not_null(n)));  }
#line 313 "reflect.h2"
    [[nodiscard]] auto declaration::parent_is_alias() const& -> bool { return CPP2_UFCS(parent_is_alias)((*cpp2::impl::assert_not_null(n))); }

#line 315 "reflect.h2"
    [[nodiscard]] auto declaration::parent_is_type_alias() const& -> bool { return CPP2_UFCS(parent_is_type_alias)((*cpp2::impl::assert_not_null(n))); }
#line 316 "reflect.h2"
    [[nodiscard]] auto declaration::parent_is_namespace_alias() const& -> bool { return CPP2_UFCS(parent_is_namespace_alias)((*cpp2::impl::assert_not_null(n)));  }
#line 317 "reflect.h2"
    [[nodiscard]] auto declaration::parent_is_object_alias() const& -> bool { return CPP2_UFCS(parent_is_object_alias)((*cpp2::impl::assert_not_null(n))); }

#line 319 "reflect.h2"
    [[nodiscard]] auto declaration::parent_is_polymorphic() const& -> bool { return CPP2_UFCS(parent_is_polymorphic)((*cpp2::impl::assert_not_null(n)));  }

#line 321 "reflect.h2"
    auto declaration::mark_for_removal_from_enclosing_type() & -> void
                                                    // this precondition should be sufficient ...
    {
        if (cpp2::type_safety.is_active() && !(parent_is_type()) ) { cpp2::type_safety.report_violation(""); }
#line 324 "reflect.h2"
        auto test {CPP2_UFCS(type_member_mark_for_removal)((*cpp2::impl::assert_not_null(n)))}; 
        if (cpp2::cpp2_default.is_active() && !(cpp2::move(test)) ) { cpp2::cpp2_default.report_violation(""); }// ... to ensure this assert is true
    }

    declaration::~declaration() noexcept{}
declaration::declaration(declaration const& that)
                                     : reflection_base<declaration_node>{ static_cast<reflection_base<declaration_node> const&>(that) }{}
declaration::declaration(declaration&& that) noexcept
                                     : reflection_base<declaration_node>{ static_cast<reflection_base<declaration_node>&&>(that) }{}

#line 330 "reflect.h2"
//-----------------------------------------------------------------------
//  Function declarations
//

#line 337 "reflect.h2"
    function_declaration::function_declaration(

        cpp2::impl::in<declaration_node*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : declaration{ n_, s }
#line 342 "reflect.h2"
    {

        if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(is_function)((*cpp2::impl::assert_not_null(n)))) ) { cpp2::cpp2_default.report_violation(""); }
    }

#line 347 "reflect.h2"
    [[nodiscard]] auto function_declaration::index_of_parameter_named(cpp2::impl::in<std::string_view> s) const& -> int { return CPP2_UFCS(index_of_parameter_named)((*cpp2::impl::assert_not_null(n)), s); }
#line 348 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool { return CPP2_UFCS(has_parameter_named)((*cpp2::impl::assert_not_null(n)), s); }
#line 349 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_return_named(cpp2::impl::in<std::string_view> s) const& -> bool { return CPP2_UFCS(has_return_named)((*cpp2::impl::assert_not_null(n)), s); }
#line 350 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_parameter_or_return_named(cpp2::impl::in<std::string_view> s) const& -> bool { return CPP2_UFCS(has_parameter_or_return_named)((*cpp2::impl::assert_not_null(n)), s);  }
#line 351 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_in_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool { return CPP2_UFCS(has_in_parameter_named)((*cpp2::impl::assert_not_null(n)), s); }
#line 352 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_in_ref_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool { return CPP2_UFCS(has_in_ref_parameter_named)((*cpp2::impl::assert_not_null(n)), s); }
#line 353 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_copy_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool { return CPP2_UFCS(has_copy_parameter_named)((*cpp2::impl::assert_not_null(n)), s); }
#line 354 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_inout_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool { return CPP2_UFCS(has_inout_parameter_named)((*cpp2::impl::assert_not_null(n)), s); }
#line 355 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_out_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool { return CPP2_UFCS(has_out_parameter_named)((*cpp2::impl::assert_not_null(n)), s); }
#line 356 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_move_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool { return CPP2_UFCS(has_move_parameter_named)((*cpp2::impl::assert_not_null(n)), s); }
#line 357 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_forward_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool { return CPP2_UFCS(has_forward_parameter_named)((*cpp2::impl::assert_not_null(n)), s); }
#line 358 "reflect.h2"
    [[nodiscard]] auto function_declaration::first_parameter_name() const& -> std::string { return CPP2_UFCS(first_parameter_name)((*cpp2::impl::assert_not_null(n))); }

#line 360 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_parameter_with_name_and_pass(cpp2::impl::in<std::string_view> s, cpp2::impl::in<passing_style> pass) const& -> bool { 
                                                  return CPP2_UFCS(has_parameter_with_name_and_pass)((*cpp2::impl::assert_not_null(n)), s, pass);  }
#line 362 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_function_with_this() const& -> bool { return CPP2_UFCS(is_function_with_this)((*cpp2::impl::assert_not_null(n))); }
#line 363 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_virtual() const& -> bool { return CPP2_UFCS(is_virtual_function)((*cpp2::impl::assert_not_null(n))); }
#line 364 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_defaultable() const& -> bool { return CPP2_UFCS(is_defaultable_function)((*cpp2::impl::assert_not_null(n))); }
#line 365 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_constructor() const& -> bool { return CPP2_UFCS(is_constructor)((*cpp2::impl::assert_not_null(n))); }
#line 366 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_default_constructor() const& -> bool { return CPP2_UFCS(is_default_constructor)((*cpp2::impl::assert_not_null(n))); }
#line 367 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_move() const& -> bool { return CPP2_UFCS(is_move)((*cpp2::impl::assert_not_null(n))); }
#line 368 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_swap() const& -> bool { return CPP2_UFCS(is_swap)((*cpp2::impl::assert_not_null(n))); }
#line 369 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_constructor_with_that() const& -> bool { return CPP2_UFCS(is_constructor_with_that)((*cpp2::impl::assert_not_null(n))); }
#line 370 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_constructor_with_in_that() const& -> bool { return CPP2_UFCS(is_constructor_with_in_that)((*cpp2::impl::assert_not_null(n))); }
#line 371 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_constructor_with_move_that() const& -> bool { return CPP2_UFCS(is_constructor_with_move_that)((*cpp2::impl::assert_not_null(n)));  }
#line 372 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_assignment() const& -> bool { return CPP2_UFCS(is_assignment)((*cpp2::impl::assert_not_null(n))); }
#line 373 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_assignment_with_that() const& -> bool { return CPP2_UFCS(is_assignment_with_that)((*cpp2::impl::assert_not_null(n))); }
#line 374 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_assignment_with_in_that() const& -> bool { return CPP2_UFCS(is_assignment_with_in_that)((*cpp2::impl::assert_not_null(n))); }
#line 375 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_assignment_with_move_that() const& -> bool { return CPP2_UFCS(is_assignment_with_move_that)((*cpp2::impl::assert_not_null(n)));  }
#line 376 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_destructor() const& -> bool { return CPP2_UFCS(is_destructor)((*cpp2::impl::assert_not_null(n))); }

#line 378 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_copy_or_move() const& -> bool { return is_constructor_with_that() || is_assignment_with_that(); }

#line 380 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_declared_return_type() const& -> bool { return CPP2_UFCS(has_declared_return_type)((*cpp2::impl::assert_not_null(n))); }
#line 381 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_deduced_return_type() const& -> bool { return CPP2_UFCS(has_deduced_return_type)((*cpp2::impl::assert_not_null(n))); }
#line 382 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_bool_return_type() const& -> bool { return CPP2_UFCS(has_bool_return_type)((*cpp2::impl::assert_not_null(n))); }
#line 383 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_non_void_return_type() const& -> bool { return CPP2_UFCS(has_non_void_return_type)((*cpp2::impl::assert_not_null(n))); }

#line 385 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_compound_body() const& -> bool { return CPP2_UFCS(is_function_with_compound_body)((*cpp2::impl::assert_not_null(n))); }

#line 387 "reflect.h2"
    [[nodiscard]] auto function_declaration::get_body() const& -> statement { return { CPP2_UFCS(get_function_body)((*cpp2::impl::assert_not_null(n))), (*this) }; }
#line 388 "reflect.h2"
    [[nodiscard]] auto function_declaration::get_compound_body() const& -> compound_statement { return { CPP2_UFCS(get_function_compound_body)((*cpp2::impl::assert_not_null(n))), (*this) }; }
#line 389 "reflect.h2"
    [[nodiscard]] auto function_declaration::get_unnamed_return_type() const& -> std::string { return CPP2_UFCS(unnamed_return_type_to_string)((*cpp2::impl::assert_not_null(n))); }
#line 390 "reflect.h2"
    [[nodiscard]] auto function_declaration::get_signature() const& -> std::string { return CPP2_UFCS(signature_to_string)((*cpp2::impl::assert_not_null(n))); }

#line 392 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_binary_comparison_function() const& -> bool { return CPP2_UFCS(is_binary_comparison_function)((*cpp2::impl::assert_not_null(n)));  }

#line 394 "reflect.h2"
    [[nodiscard]] auto function_declaration::get_parameters() const& -> std::vector<parameter_declaration>

    {
        std::vector<parameter_declaration> ret {}; 
        for ( auto const& param : CPP2_UFCS(get_function_parameters)((*cpp2::impl::assert_not_null(n))) ) {
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, param, (*this)));
        }
        return ret; 
    }

#line 404 "reflect.h2"
    [[nodiscard]] auto function_declaration::get_returns() const& -> std::vector<parameter_declaration>

    {
        std::vector<parameter_declaration> ret {}; 
        for ( auto const& param : CPP2_UFCS(get_function_returns)((*cpp2::impl::assert_not_null(n))) ) {
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, param, (*this)));
        }
        return ret; 
    }

    //  Modifying operations
    //
#line 416 "reflect.h2"
    [[nodiscard]] auto function_declaration::default_to_virtual() & -> decltype(auto) { return static_cast<void>(CPP2_UFCS(make_function_virtual)((*cpp2::impl::assert_not_null(n)))); }

#line 418 "reflect.h2"
    [[nodiscard]] auto function_declaration::make_virtual() & -> bool { return CPP2_UFCS(make_function_virtual)((*cpp2::impl::assert_not_null(n))); }

#line 420 "reflect.h2"
    auto function_declaration::add_initializer(cpp2::impl::in<std::string_view> source) & -> void

#line 423 "reflect.h2"
    {
        if ((*this).is_active() && !(!(has_initializer())) ) { (*this).report_violation(CPP2_CONTRACT_MSG("cannot add an initializer to a function that already has one")); }
        if ((*this).is_active() && !(parent_is_type()) ) { (*this).report_violation(CPP2_CONTRACT_MSG("cannot add an initializer to a function that isn't in a type scope")); }
#line 424 "reflect.h2"
        auto stmt {parse_statement(source)}; 
        if (!((cpp2::impl::as_<bool>(stmt)))) {
            error("cannot add an initializer that is not a valid statement");
            return ; 
        }
        require(CPP2_UFCS(add_function_initializer)((*cpp2::impl::assert_not_null(n)), std::move(cpp2::move(stmt))), 
                 std::string("unexpected error while attempting to add initializer"));
    }

    function_declaration::function_declaration(function_declaration const& that)
                                     : declaration{ static_cast<declaration const&>(that) }{}
function_declaration::function_declaration(function_declaration&& that) noexcept
                                     : declaration{ static_cast<declaration&&>(that) }{}

#line 435 "reflect.h2"
//-----------------------------------------------------------------------
//  Object declarations
//

#line 442 "reflect.h2"
    object_declaration::object_declaration(

        cpp2::impl::in<declaration_node*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : declaration{ n_, s }
#line 447 "reflect.h2"
    {

        if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(is_object)((*cpp2::impl::assert_not_null(n)))) ) { cpp2::cpp2_default.report_violation(""); }
    }

#line 452 "reflect.h2"
    [[nodiscard]] auto object_declaration::is_const() const& -> bool { return CPP2_UFCS(is_const)((*cpp2::impl::assert_not_null(n))); }
#line 453 "reflect.h2"
    [[nodiscard]] auto object_declaration::has_wildcard_type() const& -> bool { return CPP2_UFCS(has_wildcard_type)((*cpp2::impl::assert_not_null(n)));  }

#line 455 "reflect.h2"
    [[nodiscard]] auto object_declaration::type() const& -> std::string{
        auto ret {CPP2_UFCS(object_type)((*cpp2::impl::assert_not_null(n)))}; 
        require(!(contains(ret, "(*ERROR*)")), 
                 "cannot to_string this type: " + ret);
        return ret; 
    }

#line 462 "reflect.h2"
    [[nodiscard]] auto object_declaration::initializer() const& -> std::string{
        auto ret {CPP2_UFCS(object_initializer)((*cpp2::impl::assert_not_null(n)))}; 
        require(!(contains(ret, "(*ERROR*)")), 
                 "cannot to_string this initializer: " + ret);
        return ret; 
    }

    object_declaration::object_declaration(object_declaration const& that)
                                     : declaration{ static_cast<declaration const&>(that) }{}
object_declaration::object_declaration(object_declaration&& that) noexcept
                                     : declaration{ static_cast<declaration&&>(that) }{}

#line 471 "reflect.h2"
//-----------------------------------------------------------------------
//  Type and namespace declarations
//

#line 478 "reflect.h2"
    type_or_namespace_declaration::type_or_namespace_declaration(

        cpp2::impl::in<declaration_node*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : declaration{ n_, s }
#line 483 "reflect.h2"
    {

        if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(is_type)((*cpp2::impl::assert_not_null(n))) || CPP2_UFCS(is_namespace)((*cpp2::impl::assert_not_null(n)))) ) { cpp2::cpp2_default.report_violation(""); }
    }

#line 488 "reflect.h2"
    auto type_or_namespace_declaration::reserve_names(cpp2::impl::in<std::string_view> name, auto&& ...etc) const& -> void
    {                           // etc is not declared ':string_view' for compatibility with GCC 10.x
        for ( 
             auto const& m : get_members() ) {
            CPP2_UFCS(require)(m, !(CPP2_UFCS(has_name)(m, name)), 
                       "in a '" + cpp2::to_string(get_metafunction_name()) + "' type, the name '" + cpp2::to_string(name) + "' "
                       "is reserved for use by the '" + cpp2::to_string(get_metafunction_name()) + "' implementation"
            );
        }
        if constexpr (!(CPP2_PACK_EMPTY(etc))) {
            reserve_names(CPP2_FORWARD(etc)...);
        }
    }

#line 502 "reflect.h2"
    [[nodiscard]] auto type_or_namespace_declaration::get_member_functions() const& -> std::vector<function_declaration>

    {
        std::vector<function_declaration> ret {}; 
        for ( 
             auto const& d : CPP2_UFCS(get_nested_declarations)((*cpp2::impl::assert_not_null(n)), declaration_node::functions) ) {
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, d, (*this)));
        }
        return ret; 
    }

#line 513 "reflect.h2"
    [[nodiscard]] auto type_or_namespace_declaration::get_member_functions_needing_initializer() const& -> std::vector<function_declaration>

    {
        std::vector<function_declaration> ret {}; 
        for ( 
             auto const& d : CPP2_UFCS(get_nested_declarations)((*cpp2::impl::assert_not_null(n)), declaration_node::functions) ) 
        if ( !(CPP2_UFCS(has_initializer)((*cpp2::impl::assert_not_null(d)))) 
            && !(CPP2_UFCS(is_virtual_function)((*cpp2::impl::assert_not_null(d)))) 
            && !(CPP2_UFCS(is_defaultable_function)((*cpp2::impl::assert_not_null(d))))) 
        {
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, d, (*this)));
        }
        return ret; 
    }

#line 528 "reflect.h2"
    [[nodiscard]] auto type_or_namespace_declaration::get_member_objects() const& -> std::vector<object_declaration>

    {
        std::vector<object_declaration> ret {}; 
        for ( auto const& d : CPP2_UFCS(get_nested_declarations)((*cpp2::impl::assert_not_null(n)), declaration_node::objects) ) {
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, d, (*this)));
        }
        return ret; 
    }

#line 538 "reflect.h2"
    [[nodiscard]] auto type_or_namespace_declaration::get_member_types() const& -> std::vector<type_declaration>

    {
        std::vector<type_declaration> ret {}; 
        for ( auto const& d : CPP2_UFCS(get_nested_declarations)((*cpp2::impl::assert_not_null(n)), declaration_node::types) ) {
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, d, (*this)));
        }
        return ret; 
    }

#line 548 "reflect.h2"
    [[nodiscard]] auto type_or_namespace_declaration::get_member_aliases() const& -> std::vector<alias_declaration>

    {
        std::vector<alias_declaration> ret {}; 
        for ( auto const& d : CPP2_UFCS(get_nested_declarations)((*cpp2::impl::assert_not_null(n)), declaration_node::aliases) ) {
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, d, (*this)));
        }
        return ret; 
    }

#line 558 "reflect.h2"
    [[nodiscard]] auto type_or_namespace_declaration::get_members() const& -> std::vector<declaration>

    {
        std::vector<declaration> ret {}; 
        for ( auto const& d : CPP2_UFCS(get_nested_declarations)((*cpp2::impl::assert_not_null(n)), declaration_node::all) ) {
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, d, (*this)));
        }
        return ret; 
    }

#line 568 "reflect.h2"
    auto type_or_namespace_declaration::add_member(cpp2::impl::in<std::string_view> source) & -> void
    {
        auto decl {parse_statement(source)}; 
        if (!((cpp2::impl::as_<bool>(decl)))) {
            error("the provided source string is not a valid statement");
            return ; 
        }
        if (!(CPP2_UFCS(is_declaration)((*cpp2::impl::assert_not_null(decl))))) {
            error("cannot add a member that is not a declaration");
        }

        require(CPP2_UFCS(add_type_or_namespace_member)((*cpp2::impl::assert_not_null(n)), std::move(cpp2::move(decl))), 
                 std::string("unexpected error while attempting to add member:\n") + source);
    }

    type_or_namespace_declaration::type_or_namespace_declaration(type_or_namespace_declaration const& that)
                                     : declaration{ static_cast<declaration const&>(that) }{}
type_or_namespace_declaration::type_or_namespace_declaration(type_or_namespace_declaration&& that) noexcept
                                     : declaration{ static_cast<declaration&&>(that) }{}

#line 589 "reflect.h2"
    type_declaration::type_declaration(

        cpp2::impl::in<declaration_node*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : type_or_namespace_declaration{ n_, s }
#line 594 "reflect.h2"
    {

        if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(is_type)((*cpp2::impl::assert_not_null(n)))) ) { cpp2::cpp2_default.report_violation(""); }
    }

#line 600 "reflect.h2"
    [[nodiscard]] auto type_declaration::is_polymorphic() const& -> bool { return CPP2_UFCS(is_polymorphic)((*cpp2::impl::assert_not_null(n))); }
#line 601 "reflect.h2"
    [[nodiscard]] auto type_declaration::is_final() const& -> bool { return CPP2_UFCS(is_type_final)((*cpp2::impl::assert_not_null(n))); }
#line 602 "reflect.h2"
    [[nodiscard]] auto type_declaration::make_final() & -> bool { return CPP2_UFCS(make_type_final)((*cpp2::impl::assert_not_null(n))); }

#line 604 "reflect.h2"
    [[nodiscard]] auto type_declaration::query_declared_value_set_functions() const& -> query_declared_value_set_functions_ret

#line 611 "reflect.h2"
    {
            cpp2::impl::deferred_init<bool> out_this_in_that;
            cpp2::impl::deferred_init<bool> out_this_move_that;
            cpp2::impl::deferred_init<bool> inout_this_in_that;
            cpp2::impl::deferred_init<bool> inout_this_move_that;
#line 612 "reflect.h2"
        auto declared {CPP2_UFCS(find_declared_value_set_functions)((*cpp2::impl::assert_not_null(n)))}; 
        out_this_in_that.construct(declared.out_this_in_that != nullptr);
        out_this_move_that.construct(declared.out_this_move_that != nullptr);
        inout_this_in_that.construct(declared.inout_this_in_that != nullptr);
        inout_this_move_that.construct(cpp2::move(declared).inout_this_move_that != nullptr);
        return  { std::move(out_this_in_that.value()), std::move(out_this_move_that.value()), std::move(inout_this_in_that.value()), std::move(inout_this_move_that.value()) }; // NOLINT(performance-move-const-arg)
    }

#line 620 "reflect.h2"
    [[nodiscard]] auto type_declaration::disable_member_function_generation() & -> decltype(auto) { return CPP2_UFCS(type_disable_member_function_generation)((*cpp2::impl::assert_not_null(n)));  }
#line 621 "reflect.h2"
    [[nodiscard]] auto type_declaration::disable_ref_qualifier_generation() & -> decltype(auto) { return CPP2_UFCS(type_disable_ref_qualifier_generation)((*cpp2::impl::assert_not_null(n))); }

    //  At some point we may want to allow this also for namespaces, but for now only types
#line 624 "reflect.h2"
    [[nodiscard]] auto type_declaration::remove_marked_members() & -> decltype(auto) { return CPP2_UFCS(type_remove_marked_members)((*cpp2::impl::assert_not_null(n)));  }
#line 625 "reflect.h2"
    [[nodiscard]] auto type_declaration::remove_all_members() & -> decltype(auto) { return CPP2_UFCS(type_remove_all_members)((*cpp2::impl::assert_not_null(n))); }

    type_declaration::type_declaration(type_declaration const& that)
                                     : type_or_namespace_declaration{ static_cast<type_or_namespace_declaration const&>(that) }{}
type_declaration::type_declaration(type_declaration&& that) noexcept
                                     : type_or_namespace_declaration{ static_cast<type_or_namespace_declaration&&>(that) }{}

#line 633 "reflect.h2"
    namespace_declaration::namespace_declaration(

        cpp2::impl::in<declaration_node*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : type_or_namespace_declaration{ n_, s }
#line 638 "reflect.h2"
    {

        if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(is_namespace)((*cpp2::impl::assert_not_null(n)))) ) { cpp2::cpp2_default.report_violation(""); }
    }

    namespace_declaration::namespace_declaration(namespace_declaration const& that)
                                     : type_or_namespace_declaration{ static_cast<type_or_namespace_declaration const&>(that) }{}
namespace_declaration::namespace_declaration(namespace_declaration&& that) noexcept
                                     : type_or_namespace_declaration{ static_cast<type_or_namespace_declaration&&>(that) }{}

#line 645 "reflect.h2"
//-----------------------------------------------------------------------
//  Alias declarations
//

#line 652 "reflect.h2"
    alias_declaration::alias_declaration(

        cpp2::impl::in<declaration_node*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : declaration{ n_, s }
#line 657 "reflect.h2"
    {

        if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(is_alias)((*cpp2::impl::assert_not_null(n)))) ) { cpp2::cpp2_default.report_violation(""); }
    }

    alias_declaration::alias_declaration(alias_declaration const& that)
                                     : declaration{ static_cast<declaration const&>(that) }{}
alias_declaration::alias_declaration(alias_declaration&& that) noexcept
                                     : declaration{ static_cast<declaration&&>(that) }{}

#line 664 "reflect.h2"
//-----------------------------------------------------------------------
//  Parameter declarations
//

#line 671 "reflect.h2"
    parameter_declaration::parameter_declaration(

        cpp2::impl::in<parameter_declaration_node*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : reflection_base<parameter_declaration_node>{ n_, s }
#line 676 "reflect.h2"
    {

    }

#line 680 "reflect.h2"
    [[nodiscard]] auto parameter_declaration::get_declaration() const& -> object_declaration { return { CPP2_UFCS(get)((*cpp2::impl::assert_not_null(n)).declaration), (*this) }; }
#line 681 "reflect.h2"
    [[nodiscard]] auto parameter_declaration::get_passing_style() const& -> passing_style { return (*cpp2::impl::assert_not_null(n)).pass; }

#line 683 "reflect.h2"
    [[nodiscard]] auto parameter_declaration::is_implicit() const& -> bool { return (*cpp2::impl::assert_not_null(n)).mod == parameter_declaration_node::modifier::implicit;  }
#line 684 "reflect.h2"
    [[nodiscard]] auto parameter_declaration::is_virtual() const& -> bool { return (*cpp2::impl::assert_not_null(n)).mod == parameter_declaration_node::modifier::virtual_;  }
#line 685 "reflect.h2"
    [[nodiscard]] auto parameter_declaration::is_override() const& -> bool { return (*cpp2::impl::assert_not_null(n)).mod == parameter_declaration_node::modifier::override_;  }
#line 686 "reflect.h2"
    [[nodiscard]] auto parameter_declaration::is_final() const& -> bool { return (*cpp2::impl::assert_not_null(n)).mod == parameter_declaration_node::modifier::final_; }

    parameter_declaration::parameter_declaration(parameter_declaration const& that)
                                     : reflection_base<parameter_declaration_node>{ static_cast<reflection_base<parameter_declaration_node> const&>(that) }{}
parameter_declaration::parameter_declaration(parameter_declaration&& that) noexcept
                                     : reflection_base<parameter_declaration_node>{ static_cast<reflection_base<parameter_declaration_node>&&>(that) }{}

#line 690 "reflect.h2"
//-----------------------------------------------------------------------
// 
//  Expressions
//
//-----------------------------------------------------------------------
//

//-----------------------------------------------------------------------
//  Binary expressions
//

#line 717 "reflect.h2"
    template <String Name, typename Term> binary_expression<Name,Term>::binary_expression(

        binary_expression_node<Name,Term>* const& n_, 
        cpp2::impl::in<compiler_services> s
    )
        : reflection_base<binary_expression_node<Name,Term>>{ n_, s }
#line 722 "reflect.h2"
    {

    }

#line 726 "reflect.h2"
    template <String Name, typename Term> [[nodiscard]] auto binary_expression<Name,Term>::is_fold_expression() const& -> bool { return CPP2_UFCS(is_fold_expression)((*cpp2::impl::assert_not_null((*this).n))); }
#line 727 "reflect.h2"
    template <String Name, typename Term> [[nodiscard]] auto binary_expression<Name,Term>::lhs_is_id_expression() const& -> bool { return CPP2_UFCS(lhs_is_id_expression)((*cpp2::impl::assert_not_null((*this).n))); }
#line 728 "reflect.h2"
    template <String Name, typename Term> [[nodiscard]] auto binary_expression<Name,Term>::is_standalone_expression() const& -> bool { return CPP2_UFCS(is_standalone_expression)((*cpp2::impl::assert_not_null((*this).n)));  }
#line 729 "reflect.h2"
    template <String Name, typename Term> [[nodiscard]] auto binary_expression<Name,Term>::terms_size() const& -> int { return CPP2_UFCS(terms_size)((*cpp2::impl::assert_not_null((*this).n))); }
#line 730 "reflect.h2"
    template <String Name, typename Term> [[nodiscard]] auto binary_expression<Name,Term>::is_identifier() const& -> bool { return CPP2_UFCS(is_identifier)((*cpp2::impl::assert_not_null((*this).n))); }
#line 731 "reflect.h2"
    template <String Name, typename Term> [[nodiscard]] auto binary_expression<Name,Term>::is_id_expression() const& -> bool { return CPP2_UFCS(is_id_expression)((*cpp2::impl::assert_not_null((*this).n))); }
#line 732 "reflect.h2"
    template <String Name, typename Term> [[nodiscard]] auto binary_expression<Name,Term>::is_unqualified_id() const& -> bool { return CPP2_UFCS(is_unqualified_id)((*cpp2::impl::assert_not_null((*this).n))); }
#line 733 "reflect.h2"
    template <String Name, typename Term> [[nodiscard]] auto binary_expression<Name,Term>::is_expression_list() const& -> bool { return CPP2_UFCS(is_expression_list)((*cpp2::impl::assert_not_null((*this).n))); }
#line 734 "reflect.h2"
    template <String Name, typename Term> [[nodiscard]] auto binary_expression<Name,Term>::is_literal() const& -> bool { return CPP2_UFCS(is_literal)((*cpp2::impl::assert_not_null((*this).n))); }

#line 740 "reflect.h2"
        template <String Name, typename Term> template <typename T> binary_expression<Name,Term>::term_t<T>::term_t(auto&& o, auto&& ptr, auto&& cs)
                                                                      : op{ CPP2_FORWARD(o) }
                                                                      , term{ CPP2_FORWARD(ptr), CPP2_FORWARD(cs) }{}

#line 742 "reflect.h2"
        template <String Name, typename Term> template <typename T> [[nodiscard]] auto binary_expression<Name,Term>::term_t<T>::get_op() const& -> std::string { return op; }
#line 743 "reflect.h2"
        template <String Name, typename Term> template <typename T> [[nodiscard]] auto binary_expression<Name,Term>::term_t<T>::get_term() const& -> T { return term; }

        template <String Name, typename Term> template <typename T> binary_expression<Name,Term>::term_t<T>::term_t(term_t const& that)
                                : op{ that.op }
                                , term{ that.term }{}

template <String Name, typename Term> template <typename T> auto binary_expression<Name,Term>::term_t<T>::operator=(term_t const& that) -> term_t& {
                                op = that.op;
                                term = that.term;
                                return *this;}
template <String Name, typename Term> template <typename T> binary_expression<Name,Term>::term_t<T>::term_t(term_t&& that) noexcept
                                : op{ std::move(that).op }
                                , term{ std::move(that).term }{}
template <String Name, typename Term> template <typename T> auto binary_expression<Name,Term>::term_t<T>::operator=(term_t&& that) noexcept -> term_t& {
                                op = std::move(that).op;
                                term = std::move(that).term;
                                return *this;}
#line 746 "reflect.h2"
    template <String Name, typename Term> [[nodiscard]] auto binary_expression<Name,Term>::get_terms() const& -> auto{
        if constexpr (std::is_same_v<Term,is_as_expression_node>) {
            std::vector<term_t<is_as_expression>> ret {}; 
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, "", CPP2_UFCS(get)((*cpp2::impl::assert_not_null((*this).n)).expr), (*this)));
            for ( auto const& t : (*cpp2::impl::assert_not_null((*this).n)).terms ) {static_cast<void>(CPP2_UFCS(emplace_back)(ret, *cpp2::impl::assert_not_null(t.op), CPP2_UFCS(get)(t.expr), (*this))); }
            return ret; 
        }
        if constexpr (std::is_same_v<Term,multiplicative_expression_node>) {
            std::vector<term_t<multiplicative_expression>> ret {}; 
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, "", CPP2_UFCS(get)((*cpp2::impl::assert_not_null((*this).n)).expr), (*this)));
            for ( auto const& t : (*cpp2::impl::assert_not_null((*this).n)).terms ) {static_cast<void>(CPP2_UFCS(emplace_back)(ret, *cpp2::impl::assert_not_null(t.op), CPP2_UFCS(get)(t.expr), (*this))); }
            return ret; 
        }
        if constexpr (std::is_same_v<Term,additive_expression_node>)        {
            std::vector<term_t<additive_expression>> ret {}; 
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, "", CPP2_UFCS(get)((*cpp2::impl::assert_not_null((*this).n)).expr), (*this)));
            for ( auto const& t : (*cpp2::impl::assert_not_null((*this).n)).terms ) {static_cast<void>(CPP2_UFCS(emplace_back)(ret, *cpp2::impl::assert_not_null(t.op), CPP2_UFCS(get)(t.expr), (*this))); }
            return ret; 
        }
        if constexpr (std::is_same_v<Term,shift_expression_node>)           {
            std::vector<term_t<shift_expression>> ret {}; 
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, "", CPP2_UFCS(get)((*cpp2::impl::assert_not_null((*this).n)).expr), (*this)));
            for ( auto const& t : (*cpp2::impl::assert_not_null((*this).n)).terms ) {static_cast<void>(CPP2_UFCS(emplace_back)(ret, *cpp2::impl::assert_not_null(t.op), CPP2_UFCS(get)(t.expr), (*this))); }
            return ret; 
        }
        if constexpr (std::is_same_v<Term,compare_expression_node>)         {
            std::vector<term_t<compare_expression>> ret {}; 
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, "", CPP2_UFCS(get)((*cpp2::impl::assert_not_null((*this).n)).expr), (*this)));
            for ( auto const& t : (*cpp2::impl::assert_not_null((*this).n)).terms ) {static_cast<void>(CPP2_UFCS(emplace_back)(ret, *cpp2::impl::assert_not_null(t.op), CPP2_UFCS(get)(t.expr), (*this))); }
            return ret; 
        }
        if constexpr (std::is_same_v<Term,relational_expression_node>)      {
            std::vector<term_t<relational_expression>> ret {}; 
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, "", CPP2_UFCS(get)((*cpp2::impl::assert_not_null((*this).n)).expr), (*this)));
            for ( auto const& t : (*cpp2::impl::assert_not_null((*this).n)).terms ) {static_cast<void>(CPP2_UFCS(emplace_back)(ret, *cpp2::impl::assert_not_null(t.op), CPP2_UFCS(get)(t.expr), (*this))); }
            return ret; 
        }
        if constexpr (std::is_same_v<Term,equality_expression_node>)        {
            std::vector<term_t<equality_expression>> ret {}; 
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, "", CPP2_UFCS(get)((*cpp2::impl::assert_not_null((*this).n)).expr), (*this)));
            for ( auto const& t : (*cpp2::impl::assert_not_null((*this).n)).terms ) {static_cast<void>(CPP2_UFCS(emplace_back)(ret, *cpp2::impl::assert_not_null(t.op), CPP2_UFCS(get)(t.expr), (*this))); }
            return ret; 
        }
        if constexpr (std::is_same_v<Term,bit_and_expression_node>)         {
            std::vector<term_t<bit_and_expression>> ret {}; 
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, "", CPP2_UFCS(get)((*cpp2::impl::assert_not_null((*this).n)).expr), (*this)));
            for ( auto const& t : (*cpp2::impl::assert_not_null((*this).n)).terms ) {static_cast<void>(CPP2_UFCS(emplace_back)(ret, *cpp2::impl::assert_not_null(t.op), CPP2_UFCS(get)(t.expr), (*this))); }
            return ret; 
        }
        if constexpr (std::is_same_v<Term,bit_xor_expression_node>)         {
            std::vector<term_t<bit_xor_expression>> ret {}; 
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, "", CPP2_UFCS(get)((*cpp2::impl::assert_not_null((*this).n)).expr), (*this)));
            for ( auto const& t : (*cpp2::impl::assert_not_null((*this).n)).terms ) {static_cast<void>(CPP2_UFCS(emplace_back)(ret, *cpp2::impl::assert_not_null(t.op), CPP2_UFCS(get)(t.expr), (*this))); }
            return ret; 
        }
        if constexpr (std::is_same_v<Term,bit_or_expression_node>)          {
            std::vector<term_t<bit_or_expression>> ret {}; 
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, "", CPP2_UFCS(get)((*cpp2::impl::assert_not_null((*this).n)).expr), (*this)));
            for ( auto const& t : (*cpp2::impl::assert_not_null((*this).n)).terms ) {static_cast<void>(CPP2_UFCS(emplace_back)(ret, *cpp2::impl::assert_not_null(t.op), CPP2_UFCS(get)(t.expr), (*this))); }
            return ret; 
        }
        if constexpr (std::is_same_v<Term,logical_and_expression_node>)     {
            std::vector<term_t<logical_and_expression>> ret {}; 
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, "", CPP2_UFCS(get)((*cpp2::impl::assert_not_null((*this).n)).expr), (*this)));
            for ( auto const& t : (*cpp2::impl::assert_not_null((*this).n)).terms ) {static_cast<void>(CPP2_UFCS(emplace_back)(ret, *cpp2::impl::assert_not_null(t.op), CPP2_UFCS(get)(t.expr), (*this))); }
            return ret; 
        }
        if constexpr (std::is_same_v<Term,logical_or_expression_node>)      {
            std::vector<term_t<logical_or_expression>> ret {}; 
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, "", CPP2_UFCS(get)((*cpp2::impl::assert_not_null((*this).n)).expr), (*this)));
            for ( auto const& t : (*cpp2::impl::assert_not_null((*this).n)).terms ) {static_cast<void>(CPP2_UFCS(emplace_back)(ret, *cpp2::impl::assert_not_null(t.op), CPP2_UFCS(get)(t.expr), (*this))); }
            return ret; 
        }
    }

#line 821 "reflect.h2"
    template <String Name, typename Term> [[nodiscard]] auto binary_expression<Name,Term>::as_expression_list() const& -> expression_list { return { CPP2_UFCS(get_expression_list)((*cpp2::impl::assert_not_null((*this).n))), (*this) };  }
#line 822 "reflect.h2"
    template <String Name, typename Term> [[nodiscard]] auto binary_expression<Name,Term>::as_literal() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(CPP2_UFCS(get_literal)(*cpp2::impl::assert_not_null((*this).n))))); }

    //  Get the postfix-expression, if that's the entire expression (not actually binary)
#line 825 "reflect.h2"
    template <String Name, typename Term> [[nodiscard]] auto binary_expression<Name,Term>::get_if_only_a_postfix_expression() const& -> postfix_expression { return { CPP2_UFCS(get_if_only_a_postfix_expression_node)((*cpp2::impl::assert_not_null((*this).n))), (*this) };  }
    //  Get left-hand postfix-expression
#line 827 "reflect.h2"
    template <String Name, typename Term> [[nodiscard]] auto binary_expression<Name,Term>::get_lhs_postfix_expression() const& -> postfix_expression { return { CPP2_UFCS(get_postfix_expression_node)((*cpp2::impl::assert_not_null((*this).n))), (*this) }; }
    //  Get first right-hand postfix-expression, if there is one
#line 829 "reflect.h2"
    template <String Name, typename Term> [[nodiscard]] auto binary_expression<Name,Term>::get_second_postfix_expression() const& -> postfix_expression { return { CPP2_UFCS(get_second_postfix_expression_node)((*cpp2::impl::assert_not_null((*this).n))), (*this) }; }

#line 831 "reflect.h2"
    template <String Name, typename Term> [[nodiscard]] auto binary_expression<Name,Term>::is_result_a_temporary_variable() const& -> bool { return CPP2_UFCS(is_result_a_temporary_variable)((*cpp2::impl::assert_not_null((*this).n))); }

#line 833 "reflect.h2"
    template <String Name, typename Term> [[nodiscard]] auto binary_expression<Name,Term>::to_string() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null((*this).n)));  }

    template <String Name, typename Term> binary_expression<Name,Term>::binary_expression(binary_expression const& that)
                                     : reflection_base<binary_expression_node<Name,Term>>{ static_cast<reflection_base<binary_expression_node<Name,Term>> const&>(that) }{}
template <String Name, typename Term> binary_expression<Name,Term>::binary_expression(binary_expression&& that) noexcept
                                     : reflection_base<binary_expression_node<Name,Term>>{ static_cast<reflection_base<binary_expression_node<Name,Term>>&&>(that) }{}

#line 837 "reflect.h2"
//-----------------------------------------------------------------------
//  Expression list
//

#line 844 "reflect.h2"
    expression_list::expression_list(

        cpp2::impl::in<expression_list_node*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : reflection_base<expression_list_node>{ n_, s }
#line 849 "reflect.h2"
    {

    }

#line 853 "reflect.h2"
    [[nodiscard]] auto expression_list::is_empty() const& -> bool { return CPP2_UFCS(is_empty)((*cpp2::impl::assert_not_null(n))); }
#line 854 "reflect.h2"
    [[nodiscard]] auto expression_list::is_fold_expression() const& -> bool { return CPP2_UFCS(is_fold_expression)((*cpp2::impl::assert_not_null(n)));  }

#line 856 "reflect.h2"
    [[nodiscard]] auto expression_list::get_expressions() const& -> std::vector<expression>

    {
        std::vector<expression> ret {}; 
        for ( auto const& expr : CPP2_UFCS(get_expressions)((*cpp2::impl::assert_not_null(n))) ) {
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, expression(CPP2_UFCS(get)(expr.expr), (*this))));
        }
        return ret; 
    }

#line 866 "reflect.h2"
    [[nodiscard]] auto expression_list::to_string() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(n)));  }

    expression_list::expression_list(expression_list const& that)
                                     : reflection_base<expression_list_node>{ static_cast<reflection_base<expression_list_node> const&>(that) }{}
expression_list::expression_list(expression_list&& that) noexcept
                                     : reflection_base<expression_list_node>{ static_cast<reflection_base<expression_list_node>&&>(that) }{}

#line 870 "reflect.h2"
//-----------------------------------------------------------------------
//  Prefix expressions
//

#line 877 "reflect.h2"
    prefix_expression::prefix_expression(

        cpp2::impl::in<prefix_expression_node*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : reflection_base<prefix_expression_node>{ n_, s }
#line 882 "reflect.h2"
    {

    }

#line 886 "reflect.h2"
    [[nodiscard]] auto prefix_expression::get_ops() const& -> std::vector<std::string>{
        std::vector<std::string> ret {}; 
        for ( auto const& op : (*cpp2::impl::assert_not_null(n)).ops ) {
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(op)))));
        }
        return ret; 
    }

#line 894 "reflect.h2"
    [[nodiscard]] auto prefix_expression::get_postfix_expression() const& -> postfix_expression { return { CPP2_UFCS(get)((*cpp2::impl::assert_not_null((*this).n)).expr), (*this) };  }

#line 896 "reflect.h2"
    [[nodiscard]] auto prefix_expression::is_fold_expression() const& -> bool { return CPP2_UFCS(is_fold_expression)((*cpp2::impl::assert_not_null(n))); }
#line 897 "reflect.h2"
    [[nodiscard]] auto prefix_expression::is_identifier() const& -> bool { return CPP2_UFCS(is_identifier)((*cpp2::impl::assert_not_null(n))); }
#line 898 "reflect.h2"
    [[nodiscard]] auto prefix_expression::is_id_expression() const& -> bool { return CPP2_UFCS(is_id_expression)((*cpp2::impl::assert_not_null(n))); }
#line 899 "reflect.h2"
    [[nodiscard]] auto prefix_expression::is_unqualified_id() const& -> bool { return CPP2_UFCS(is_unqualified_id)((*cpp2::impl::assert_not_null(n))); }
#line 900 "reflect.h2"
    [[nodiscard]] auto prefix_expression::is_expression_list() const& -> bool { return CPP2_UFCS(is_expression_list)((*cpp2::impl::assert_not_null(n))); }
#line 901 "reflect.h2"
    [[nodiscard]] auto prefix_expression::is_literal() const& -> bool { return CPP2_UFCS(is_literal)((*cpp2::impl::assert_not_null(n))); }
#line 902 "reflect.h2"
    [[nodiscard]] auto prefix_expression::is_result_a_temporary_variable() const& -> bool { return CPP2_UFCS(is_result_a_temporary_variable)((*cpp2::impl::assert_not_null(n)));  }

#line 904 "reflect.h2"
    [[nodiscard]] auto prefix_expression::as_expression_list() const& -> expression_list { return { CPP2_UFCS(get_expression_list)((*cpp2::impl::assert_not_null((*this).n))), (*this) };  }
#line 905 "reflect.h2"
    [[nodiscard]] auto prefix_expression::as_literal() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(CPP2_UFCS(get_literal)(*cpp2::impl::assert_not_null(n))))); }
#line 906 "reflect.h2"
    [[nodiscard]] auto prefix_expression::as_identifier() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(CPP2_UFCS(get_identifier)(*cpp2::impl::assert_not_null(n))))); }

#line 908 "reflect.h2"
    [[nodiscard]] auto prefix_expression::to_string() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null((*this).n)));  }

    prefix_expression::~prefix_expression() noexcept{}
prefix_expression::prefix_expression(prefix_expression const& that)
                                     : reflection_base<prefix_expression_node>{ static_cast<reflection_base<prefix_expression_node> const&>(that) }{}
prefix_expression::prefix_expression(prefix_expression&& that) noexcept
                                     : reflection_base<prefix_expression_node>{ static_cast<reflection_base<prefix_expression_node>&&>(that) }{}

#line 912 "reflect.h2"
//-----------------------------------------------------------------------
//  Postfix expressions
//

#line 919 "reflect.h2"
    postfix_expression::postfix_expression(

        cpp2::impl::in<postfix_expression_node*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : reflection_base<postfix_expression_node>{ n_, s }
#line 924 "reflect.h2"
    {

    }

#line 928 "reflect.h2"
    [[nodiscard]] auto postfix_expression::get_primary_expression() const& -> primary_expression { return { CPP2_UFCS(get)((*cpp2::impl::assert_not_null((*this).n)).expr), (*this) };  }

#line 934 "reflect.h2"
        postfix_expression::term_t::term_t(auto&& term, auto&& cs)
                                                            : term_{ CPP2_FORWARD(term) }
                                                            , cs_{ CPP2_FORWARD(cs) }{}

#line 936 "reflect.h2"
        [[nodiscard]] auto postfix_expression::term_t::get_op() const& -> std::string_view { return CPP2_UFCS(as_string_view)((*cpp2::impl::assert_not_null((*cpp2::impl::assert_not_null(term_)).op))); }

        //  If op is        More is contained in the        Notes
        //
        //  .               id_expression                   member selection
        //  [ (             expression_list                 subscript or function call
        //  ...             expression                      fold expression

#line 944 "reflect.h2"
        [[nodiscard]] auto postfix_expression::term_t::is_id_expression() const& -> bool { return CPP2_UFCS(get)((*cpp2::impl::assert_not_null(term_)).id_expr) != nullptr; }
#line 945 "reflect.h2"
        [[nodiscard]] auto postfix_expression::term_t::is_expression_list() const& -> bool { return CPP2_UFCS(get)((*cpp2::impl::assert_not_null(term_)).expr_list) != nullptr; }
#line 946 "reflect.h2"
        [[nodiscard]] auto postfix_expression::term_t::is_expression() const& -> bool { return CPP2_UFCS(get)((*cpp2::impl::assert_not_null(term_)).last_expr) != nullptr; }

#line 948 "reflect.h2"
        [[nodiscard]] auto postfix_expression::term_t::get_id_expression() const& -> id_expression { return { CPP2_UFCS(get)((*cpp2::impl::assert_not_null(term_)).id_expr), *cpp2::impl::assert_not_null(cs_) }; }
#line 949 "reflect.h2"
        [[nodiscard]] auto postfix_expression::term_t::get_expression_list() const& -> expression_list { return { CPP2_UFCS(get)((*cpp2::impl::assert_not_null(term_)).expr_list), *cpp2::impl::assert_not_null(cs_) };  }
#line 950 "reflect.h2"
        [[nodiscard]] auto postfix_expression::term_t::get_expression() const& -> expression { return { CPP2_UFCS(get)((*cpp2::impl::assert_not_null(term_)).last_expr), *cpp2::impl::assert_not_null(cs_) }; }

        postfix_expression::term_t::term_t(term_t const& that)
                                     : term_{ that.term_ }
                                     , cs_{ that.cs_ }{}
postfix_expression::term_t::term_t(term_t&& that) noexcept
                                     : term_{ std::move(that).term_ }
                                     , cs_{ std::move(that).cs_ }{}

#line 953 "reflect.h2"
    [[nodiscard]] auto postfix_expression::get_terms() const& -> auto{
        std::vector<term_t> ret {}; 
        for ( auto const& t : (*cpp2::impl::assert_not_null((*this).n)).ops ) {static_cast<void>(CPP2_UFCS(emplace_back)(ret, &t, &(*this))); }
        return ret; 
    }

#line 959 "reflect.h2"
    [[nodiscard]] auto postfix_expression::is_fold_expression() const& -> bool { return CPP2_UFCS(is_fold_expression)((*cpp2::impl::assert_not_null(n)));  }
#line 960 "reflect.h2"
    [[nodiscard]] auto postfix_expression::is_identifier() const& -> bool { return CPP2_UFCS(is_identifier)((*cpp2::impl::assert_not_null(n))); }
#line 961 "reflect.h2"
    [[nodiscard]] auto postfix_expression::is_id_expression() const& -> bool { return CPP2_UFCS(is_id_expression)((*cpp2::impl::assert_not_null(n))); }
#line 962 "reflect.h2"
    [[nodiscard]] auto postfix_expression::is_unqualified_id() const& -> bool { return CPP2_UFCS(is_unqualified_id)((*cpp2::impl::assert_not_null(n)));  }
#line 963 "reflect.h2"
    [[nodiscard]] auto postfix_expression::is_expression_list() const& -> bool { return CPP2_UFCS(is_expression_list)((*cpp2::impl::assert_not_null(n)));  }
#line 964 "reflect.h2"
    [[nodiscard]] auto postfix_expression::is_literal() const& -> bool { return CPP2_UFCS(is_literal)((*cpp2::impl::assert_not_null(n))); }

#line 966 "reflect.h2"
    [[nodiscard]] auto postfix_expression::as_identifier() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(CPP2_UFCS(get_identifier)(*cpp2::impl::assert_not_null(n))))); }
#line 967 "reflect.h2"
    [[nodiscard]] auto postfix_expression::as_expression_list() const& -> expression_list { return { CPP2_UFCS(get_expression_list)((*cpp2::impl::assert_not_null((*this).n))), (*this) };  }
#line 968 "reflect.h2"
    [[nodiscard]] auto postfix_expression::as_literal() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(CPP2_UFCS(get_literal)(*cpp2::impl::assert_not_null(n))))); }

#line 970 "reflect.h2"
    [[nodiscard]] auto postfix_expression::get_first_token_ignoring_this() const& -> std::string_view{
        auto ptok {CPP2_UFCS(get_first_token_ignoring_this)((*cpp2::impl::assert_not_null(n)))}; 
        if (ptok) {return *cpp2::impl::assert_not_null(cpp2::move(ptok)); }
        return ""; 
    }

#line 976 "reflect.h2"
    [[nodiscard]] auto postfix_expression::starts_with_function_call_with_num_parameters(cpp2::impl::in<int> num) const& -> bool { return CPP2_UFCS(starts_with_function_call_with_n_parameters)((*cpp2::impl::assert_not_null(n)), num);  }
#line 977 "reflect.h2"
    [[nodiscard]] auto postfix_expression::is_result_a_temporary_variable() const& -> bool { return CPP2_UFCS(is_result_a_temporary_variable)((*cpp2::impl::assert_not_null(n))); }

#line 979 "reflect.h2"
    [[nodiscard]] auto postfix_expression::to_string() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(n)));  }

    postfix_expression::postfix_expression(postfix_expression const& that)
                                     : reflection_base<postfix_expression_node>{ static_cast<reflection_base<postfix_expression_node> const&>(that) }{}
postfix_expression::postfix_expression(postfix_expression&& that) noexcept
                                     : reflection_base<postfix_expression_node>{ static_cast<reflection_base<postfix_expression_node>&&>(that) }{}

#line 983 "reflect.h2"
//-----------------------------------------------------------------------
//  Template arguments
//

#line 990 "reflect.h2"
    template_arg::template_arg(

        cpp2::impl::in<template_argument*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : reflection_base<template_argument>{ n_, s }
#line 995 "reflect.h2"
    {

    }

#line 999 "reflect.h2"
    [[nodiscard]] auto template_arg::is_expression() const& -> bool { return CPP2_UFCS(is_expression)((*cpp2::impl::assert_not_null(n)));  }
#line 1000 "reflect.h2"
    [[nodiscard]] auto template_arg::is_type_id() const& -> bool { return CPP2_UFCS(is_type_id)((*cpp2::impl::assert_not_null(n))); }

#line 1002 "reflect.h2"
    [[nodiscard]] auto template_arg::as_expression() const& -> expression { return { CPP2_UFCS(get_expression)((*cpp2::impl::assert_not_null((*this).n))), (*this) };  }
#line 1003 "reflect.h2"
    [[nodiscard]] auto template_arg::as_type_id() const& -> type_id { return { CPP2_UFCS(get_type_id)((*cpp2::impl::assert_not_null((*this).n))), (*this) }; }

#line 1005 "reflect.h2"
    [[nodiscard]] auto template_arg::to_string() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(n)));  }

    template_arg::template_arg(template_arg const& that)
                                     : reflection_base<template_argument>{ static_cast<reflection_base<template_argument> const&>(that) }{}
template_arg::template_arg(template_arg&& that) noexcept
                                     : reflection_base<template_argument>{ static_cast<reflection_base<template_argument>&&>(that) }{}

#line 1009 "reflect.h2"
//-----------------------------------------------------------------------
//  Unqualified IDs
//

#line 1016 "reflect.h2"
    unqualified_id::unqualified_id(

        cpp2::impl::in<unqualified_id_node*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : reflection_base<unqualified_id_node>{ n_, s }
#line 1021 "reflect.h2"
    {

    }

#line 1025 "reflect.h2"
    [[nodiscard]] auto unqualified_id::is_identifier() const& -> bool { return CPP2_UFCS(is_identifier)((*cpp2::impl::assert_not_null(n))); }

#line 1027 "reflect.h2"
    [[nodiscard]] auto unqualified_id::get_identifier() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(CPP2_UFCS(get_identifier)(*cpp2::impl::assert_not_null(n)))));  }

    //get_template_args: (this) -> std::vector<template_arg> = {
    //    ret: std::vector<template_arg> = ();
    //    for this.n*.template_arguments() do (t) { _ = ret.emplace_back( t&, this ); }
    //    return ret;
    //}

#line 1035 "reflect.h2"
    [[nodiscard]] auto unqualified_id::as_token() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(CPP2_UFCS(get_token)(*cpp2::impl::assert_not_null(n)))));  }

#line 1037 "reflect.h2"
    [[nodiscard]] auto unqualified_id::to_string() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(n)));  }

    unqualified_id::unqualified_id(unqualified_id const& that)
                                     : reflection_base<unqualified_id_node>{ static_cast<reflection_base<unqualified_id_node> const&>(that) }{}
unqualified_id::unqualified_id(unqualified_id&& that) noexcept
                                     : reflection_base<unqualified_id_node>{ static_cast<reflection_base<unqualified_id_node>&&>(that) }{}

#line 1041 "reflect.h2"
//-----------------------------------------------------------------------
//  Qualified IDs
//

#line 1048 "reflect.h2"
    qualified_id::qualified_id(

        cpp2::impl::in<qualified_id_node*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : reflection_base<qualified_id_node>{ n_, s }
#line 1053 "reflect.h2"
    {

    }

#line 1061 "reflect.h2"
        qualified_id::term_t::term_t(auto&& o, auto&& ptr, auto&& cs)
                                                                      : op{ CPP2_FORWARD(o) }
                                                                      , unqualified{ CPP2_FORWARD(ptr), CPP2_FORWARD(cs) }{}

#line 1063 "reflect.h2"
        [[nodiscard]] auto qualified_id::term_t::get_op() const& -> std::string { return op; }
#line 1064 "reflect.h2"
        [[nodiscard]] auto qualified_id::term_t::get_unqualified() const& -> unqualified_id { return unqualified;  }

        qualified_id::term_t::term_t(term_t const& that)
                                     : op{ that.op }
                                     , unqualified{ that.unqualified }{}
qualified_id::term_t::term_t(term_t&& that) noexcept
                                     : op{ std::move(that).op }
                                     , unqualified{ std::move(that).unqualified }{}

#line 1067 "reflect.h2"
    [[nodiscard]] auto qualified_id::get_terms() const& -> auto{
        std::vector<term_t> ret {}; 
        for ( auto const& t : (*cpp2::impl::assert_not_null((*this).n)).ids ) {static_cast<void>(CPP2_UFCS(emplace_back)(ret, *cpp2::impl::assert_not_null(t.scope_op), CPP2_UFCS(get)(t.id), (*this))); }
        return ret; 
    }

    //get_template_args: (this) -> std::vector<template_arg> = {
    //    ret: std::vector<template_arg> = ();
    //    for this.n*.template_arguments() do (t) { _ = ret.emplace_back( t&, this ); }
    //    return ret;
    //}

#line 1079 "reflect.h2"
    [[nodiscard]] auto qualified_id::as_token() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(CPP2_UFCS(get_token)(*cpp2::impl::assert_not_null(n)))));  }

#line 1081 "reflect.h2"
    [[nodiscard]] auto qualified_id::to_string() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(n)));  }

    qualified_id::qualified_id(qualified_id const& that)
                                     : reflection_base<qualified_id_node>{ static_cast<reflection_base<qualified_id_node> const&>(that) }{}
qualified_id::qualified_id(qualified_id&& that) noexcept
                                     : reflection_base<qualified_id_node>{ static_cast<reflection_base<qualified_id_node>&&>(that) }{}

#line 1085 "reflect.h2"
//-----------------------------------------------------------------------
//  Type IDs
//

#line 1092 "reflect.h2"
    type_id::type_id(

        cpp2::impl::in<type_id_node*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : reflection_base<type_id_node>{ n_, s }
#line 1097 "reflect.h2"
    {

    }

    //get_template_args: (this) -> std::vector<template_arg> = {
    //    ret: std::vector<template_arg> = ();
    //    for this.n*.template_arguments() do (t) { _ = ret.emplace_back( t&, this ); }
    //    return ret;
    //}

#line 1107 "reflect.h2"
    [[nodiscard]] auto type_id::is_postfix_expression() const& -> bool { return CPP2_UFCS(is_postfix_expression)((*cpp2::impl::assert_not_null((*this).n)));  }
#line 1108 "reflect.h2"
    [[nodiscard]] auto type_id::is_qualified_id() const& -> bool { return CPP2_UFCS(is_qualified_id)((*cpp2::impl::assert_not_null((*this).n))); }
#line 1109 "reflect.h2"
    [[nodiscard]] auto type_id::is_unqualified_id() const& -> bool { return CPP2_UFCS(is_unqualified_id)((*cpp2::impl::assert_not_null((*this).n))); }
#line 1110 "reflect.h2"
    [[nodiscard]] auto type_id::is_function_typeid() const& -> bool { return CPP2_UFCS(is_function_typeid)((*cpp2::impl::assert_not_null((*this).n))); }
#line 1111 "reflect.h2"
    [[nodiscard]] auto type_id::is_keyword() const& -> bool { return CPP2_UFCS(is_keyword)((*cpp2::impl::assert_not_null((*this).n))); }
#line 1112 "reflect.h2"
    [[nodiscard]] auto type_id::is_wildcard() const& -> bool { return CPP2_UFCS(is_wildcard)((*cpp2::impl::assert_not_null((*this).n))); }
#line 1113 "reflect.h2"
    [[nodiscard]] auto type_id::is_pointer_qualified() const& -> bool { return CPP2_UFCS(is_pointer_qualified)((*cpp2::impl::assert_not_null((*this).n)));  }
#line 1114 "reflect.h2"
    [[nodiscard]] auto type_id::is_concept() const& -> bool { return CPP2_UFCS(is_concept)((*cpp2::impl::assert_not_null((*this).n))); }

#line 1116 "reflect.h2"
    [[nodiscard]] auto type_id::as_postfix_expression() const& -> postfix_expression { return { CPP2_UFCS(get_postfix_expression)((*cpp2::impl::assert_not_null(n))), (*this) };  }
#line 1117 "reflect.h2"
    [[nodiscard]] auto type_id::as_qualified_id() const& -> qualified_id { return { CPP2_UFCS(get_qualified_id)((*cpp2::impl::assert_not_null(n))), (*this) }; }
#line 1118 "reflect.h2"
    [[nodiscard]] auto type_id::as_unqualified_id() const& -> unqualified_id { return { CPP2_UFCS(get_unqualified_id)((*cpp2::impl::assert_not_null(n))), (*this) }; }
    // TODO
    //as_function_typeid   : (this) -> function_typeid    = (n*.get_function_typeid(),    this);
#line 1121 "reflect.h2"
    [[nodiscard]] auto type_id::as_keyword() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(CPP2_UFCS(get_keyword)(*cpp2::impl::assert_not_null(n))))); }
#line 1122 "reflect.h2"
    [[nodiscard]] auto type_id::as_token() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(CPP2_UFCS(get_token)(*cpp2::impl::assert_not_null(n))))); }

#line 1124 "reflect.h2"
    [[nodiscard]] auto type_id::to_string() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(n)));  }

    type_id::type_id(type_id const& that)
                                     : reflection_base<type_id_node>{ static_cast<reflection_base<type_id_node> const&>(that) }{}
type_id::type_id(type_id&& that) noexcept
                                     : reflection_base<type_id_node>{ static_cast<reflection_base<type_id_node>&&>(that) }{}

#line 1128 "reflect.h2"
//-----------------------------------------------------------------------
//  Primary expressions
//

#line 1135 "reflect.h2"
    primary_expression::primary_expression(

        cpp2::impl::in<primary_expression_node*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : reflection_base<primary_expression_node>{ n_, s }
#line 1140 "reflect.h2"
    {

    }

    //get_template_args: (this) -> std::vector<template_arg> = {
    //    ret: std::vector<template_arg> = ();
    //    for this.n*.template_arguments() do (t) { _ = ret.emplace_back( t&, this ); }
    //    return ret;
    //}

#line 1150 "reflect.h2"
    [[nodiscard]] auto primary_expression::is_fold_expression() const& -> bool { return CPP2_UFCS(is_fold_expression)((*cpp2::impl::assert_not_null(n)));  }
#line 1151 "reflect.h2"
    [[nodiscard]] auto primary_expression::is_identifier() const& -> bool { return CPP2_UFCS(is_identifier)((*cpp2::impl::assert_not_null(n))); }
#line 1152 "reflect.h2"
    [[nodiscard]] auto primary_expression::is_id_expression() const& -> bool { return CPP2_UFCS(is_id_expression)((*cpp2::impl::assert_not_null(n))); }
#line 1153 "reflect.h2"
    [[nodiscard]] auto primary_expression::is_unqualified_id() const& -> bool { return CPP2_UFCS(is_unqualified_id)((*cpp2::impl::assert_not_null(n)));  }
#line 1154 "reflect.h2"
    [[nodiscard]] auto primary_expression::is_expression_list() const& -> bool { return CPP2_UFCS(is_expression_list)((*cpp2::impl::assert_not_null(n)));  }
#line 1155 "reflect.h2"
    [[nodiscard]] auto primary_expression::is_literal() const& -> bool { return CPP2_UFCS(is_literal)((*cpp2::impl::assert_not_null(n))); }
#line 1156 "reflect.h2"
    [[nodiscard]] auto primary_expression::is_declaration() const& -> bool { return CPP2_UFCS(is_declaration)((*cpp2::impl::assert_not_null(n))); }

#line 1158 "reflect.h2"
    [[nodiscard]] auto primary_expression::as_identifier() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(CPP2_UFCS(get_identifier)(*cpp2::impl::assert_not_null(n))))); }
#line 1159 "reflect.h2"
    [[nodiscard]] auto primary_expression::as_expression_list() const& -> expression_list { return { CPP2_UFCS(get_expression_list)((*cpp2::impl::assert_not_null((*this).n))), (*this) };  }
#line 1160 "reflect.h2"
    [[nodiscard]] auto primary_expression::as_literal() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(CPP2_UFCS(get_literal)(*cpp2::impl::assert_not_null(n))))); }
#line 1161 "reflect.h2"
    [[nodiscard]] auto primary_expression::as_declaration() const& -> declaration { return { CPP2_UFCS(get_declaration)((*cpp2::impl::assert_not_null((*this).n))), (*this) }; }

#line 1163 "reflect.h2"
    [[nodiscard]] auto primary_expression::to_string() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(n)));  }

    primary_expression::primary_expression(primary_expression const& that)
                                     : reflection_base<primary_expression_node>{ static_cast<reflection_base<primary_expression_node> const&>(that) }{}
primary_expression::primary_expression(primary_expression&& that) noexcept
                                     : reflection_base<primary_expression_node>{ static_cast<reflection_base<primary_expression_node>&&>(that) }{}

#line 1167 "reflect.h2"
//-----------------------------------------------------------------------
//  ID expression
//

#line 1174 "reflect.h2"
    id_expression::id_expression(

        cpp2::impl::in<id_expression_node*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : reflection_base<id_expression_node>{ n_, s }
#line 1179 "reflect.h2"
    {

    }

    //get_template_args: (this) -> std::vector<template_arg> = {
    //    ret: std::vector<template_arg> = ();
    //    for this.n*.template_arguments() do (t) { _ = ret.emplace_back( t&, this ); }
    //    return ret;
    //}

#line 1189 "reflect.h2"
    [[nodiscard]] auto id_expression::is_fold_expression() const& -> bool { return CPP2_UFCS(is_fold_expression)((*cpp2::impl::assert_not_null(n))); }
#line 1190 "reflect.h2"
    [[nodiscard]] auto id_expression::is_empty() const& -> bool { return CPP2_UFCS(is_empty)((*cpp2::impl::assert_not_null(n))); }
#line 1191 "reflect.h2"
    [[nodiscard]] auto id_expression::is_identifier() const& -> bool { return CPP2_UFCS(is_identifier)((*cpp2::impl::assert_not_null(n))); }
#line 1192 "reflect.h2"
    [[nodiscard]] auto id_expression::is_qualified() const& -> bool { return CPP2_UFCS(is_qualified)((*cpp2::impl::assert_not_null(n))); }
#line 1193 "reflect.h2"
    [[nodiscard]] auto id_expression::is_unqualified() const& -> bool { return CPP2_UFCS(is_unqualified)((*cpp2::impl::assert_not_null(n))); }

#line 1195 "reflect.h2"
    [[nodiscard]] auto id_expression::as_identifier() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(CPP2_UFCS(get_identifier)(*cpp2::impl::assert_not_null(n))))); }
#line 1196 "reflect.h2"
    [[nodiscard]] auto id_expression::as_qualified() const& -> qualified_id { return { CPP2_UFCS(get_qualified_id)((*cpp2::impl::assert_not_null(n))), (*this) }; }
#line 1197 "reflect.h2"
    [[nodiscard]] auto id_expression::as_unqualified() const& -> unqualified_id { return { CPP2_UFCS(get_unqualified_id)((*cpp2::impl::assert_not_null(n))), (*this) }; }

#line 1199 "reflect.h2"
    [[nodiscard]] auto id_expression::to_string() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(n)));  }

    id_expression::~id_expression() noexcept{}
id_expression::id_expression(id_expression const& that)
                                     : reflection_base<id_expression_node>{ static_cast<reflection_base<id_expression_node> const&>(that) }{}
id_expression::id_expression(id_expression&& that) noexcept
                                     : reflection_base<id_expression_node>{ static_cast<reflection_base<id_expression_node>&&>(that) }{}

#line 1203 "reflect.h2"
//-----------------------------------------------------------------------
//  General expression
//

#line 1210 "reflect.h2"
    expression::expression(

        cpp2::impl::in<expression_node*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : reflection_base<expression_node>{ n_, s }
#line 1215 "reflect.h2"
    {

    }

#line 1219 "reflect.h2"
    [[nodiscard]] auto expression::is_fold_expression() const& -> bool { return CPP2_UFCS(is_fold_expression)((*cpp2::impl::assert_not_null(n))); }
#line 1220 "reflect.h2"
    [[nodiscard]] auto expression::is_standalone_expression() const& -> bool { return CPP2_UFCS(is_standalone_expression)((*cpp2::impl::assert_not_null(n)));  }
#line 1221 "reflect.h2"
    [[nodiscard]] auto expression::subexpression_count() const& -> int { return CPP2_UFCS(subexpression_count)((*cpp2::impl::assert_not_null(n))); }
#line 1222 "reflect.h2"
    [[nodiscard]] auto expression::is_identifier() const& -> bool { return CPP2_UFCS(is_identifier)((*cpp2::impl::assert_not_null(n))); }
#line 1223 "reflect.h2"
    [[nodiscard]] auto expression::is_id_expression() const& -> bool { return CPP2_UFCS(is_id_expression)((*cpp2::impl::assert_not_null(n))); }
#line 1224 "reflect.h2"
    [[nodiscard]] auto expression::is_unqualified_id() const& -> bool { return CPP2_UFCS(is_unqualified_id)((*cpp2::impl::assert_not_null(n))); }
#line 1225 "reflect.h2"
    [[nodiscard]] auto expression::is_expression_list() const& -> bool { return CPP2_UFCS(is_expression_list)((*cpp2::impl::assert_not_null(n))); }
#line 1226 "reflect.h2"
    [[nodiscard]] auto expression::is_empty_expression_list() const& -> bool { return CPP2_UFCS(is_empty_expression_list)((*cpp2::impl::assert_not_null(n)));  }
#line 1227 "reflect.h2"
    [[nodiscard]] auto expression::is_literal() const& -> bool { return CPP2_UFCS(is_literal)((*cpp2::impl::assert_not_null(n))); }
#line 1228 "reflect.h2"
    [[nodiscard]] auto expression::is_assignment_expression() const& -> bool { return CPP2_UFCS(is_assignment_expression)((*cpp2::impl::assert_not_null(n)));  }

#line 1230 "reflect.h2"
    [[nodiscard]] auto expression::is_simple_assignment() const& -> bool{
        auto ret {CPP2_UFCS(get_lhs_rhs_if_simple_assignment)((*cpp2::impl::assert_not_null(n)))}; 
        return ret.lhs && ret.rhs; 
    }

#line 1235 "reflect.h2"
    [[nodiscard]] auto expression::get_lhs_rhs_if_simple_assignment() const& -> get_lhs_rhs_if_simple_assignment_ret

#line 1240 "reflect.h2"
    {
            cpp2::impl::deferred_init<postfix_expression> lhs;
            cpp2::impl::deferred_init<logical_or_expression> rhs;
#line 1241 "reflect.h2"
        auto ret {CPP2_UFCS(get_lhs_rhs_if_simple_assignment)((*cpp2::impl::assert_not_null(n)))}; 
        lhs.construct(ret.lhs, (*this));
        rhs.construct(cpp2::move(ret).rhs, (*this));
    return  { std::move(lhs.value()), std::move(rhs.value()) }; }

#line 1246 "reflect.h2"
    [[nodiscard]] auto expression::as_assignment_expression() const& -> assignment_expression { return { CPP2_UFCS(get_assignment_expression)((*cpp2::impl::assert_not_null(n))), (*this) };  }
#line 1247 "reflect.h2"
    [[nodiscard]] auto expression::as_expression_list() const& -> expression_list { return { CPP2_UFCS(get_expression_list)((*cpp2::impl::assert_not_null(n))), (*this) }; }
#line 1248 "reflect.h2"
    [[nodiscard]] auto expression::as_literal() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(CPP2_UFCS(get_literal)(*cpp2::impl::assert_not_null(n))))); }

#line 1250 "reflect.h2"
    [[nodiscard]] auto expression::to_string() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(n)));  }

    expression::~expression() noexcept{}
expression::expression(expression const& that)
                                     : reflection_base<expression_node>{ static_cast<reflection_base<expression_node> const&>(that) }{}
expression::expression(expression&& that) noexcept
                                     : reflection_base<expression_node>{ static_cast<reflection_base<expression_node>&&>(that) }{}

#line 1254 "reflect.h2"
//-----------------------------------------------------------------------
//  is_as_expression
//

#line 1261 "reflect.h2"
    is_as_expression::is_as_expression(

        cpp2::impl::in<is_as_expression_node*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : reflection_base<is_as_expression_node>{ n_, s }
#line 1266 "reflect.h2"
    {

    }

#line 1274 "reflect.h2"
        is_as_expression::term_t::term_t(auto&& o, auto&& ptr, auto&& cs)
                                                                      : op{ CPP2_FORWARD(o) }
                                                                      , expr{ CPP2_FORWARD(ptr), CPP2_FORWARD(cs) }{}

#line 1276 "reflect.h2"
        [[nodiscard]] auto is_as_expression::term_t::get_op() const& -> std::string { return op; }
#line 1277 "reflect.h2"
        [[nodiscard]] auto is_as_expression::term_t::get_expr() const& -> expression { return expr; }

        is_as_expression::term_t::term_t(term_t const& that)
                                     : op{ that.op }
                                     , expr{ that.expr }{}
is_as_expression::term_t::term_t(term_t&& that) noexcept
                                     : op{ std::move(that).op }
                                     , expr{ std::move(that).expr }{}

#line 1280 "reflect.h2"
    [[nodiscard]] auto is_as_expression::get_expression() const& -> prefix_expression { return { CPP2_UFCS(get)((*cpp2::impl::assert_not_null(n)).expr), (*this) };  }

#line 1282 "reflect.h2"
    [[nodiscard]] auto is_as_expression::get_terms() const& -> auto{
        std::vector<term_t> ret {}; 
        for ( auto const& t : (*cpp2::impl::assert_not_null((*this).n)).ops ) {static_cast<void>(CPP2_UFCS(emplace_back)(ret, *cpp2::impl::assert_not_null(t.op), CPP2_UFCS(get)(t.expr), (*this))); }
        return ret; 
    }

#line 1288 "reflect.h2"
    [[nodiscard]] auto is_as_expression::is_fold_expression() const& -> bool { return CPP2_UFCS(is_fold_expression)((*cpp2::impl::assert_not_null((*this).n)));  }
#line 1289 "reflect.h2"
    [[nodiscard]] auto is_as_expression::is_identifier() const& -> bool { return CPP2_UFCS(is_identifier)((*cpp2::impl::assert_not_null((*this).n))); }
#line 1290 "reflect.h2"
    [[nodiscard]] auto is_as_expression::is_id_expression() const& -> bool { return CPP2_UFCS(is_id_expression)((*cpp2::impl::assert_not_null((*this).n))); }
#line 1291 "reflect.h2"
    [[nodiscard]] auto is_as_expression::is_unqualified_id() const& -> bool { return CPP2_UFCS(is_unqualified_id)((*cpp2::impl::assert_not_null((*this).n)));  }
#line 1292 "reflect.h2"
    [[nodiscard]] auto is_as_expression::is_expression_list() const& -> bool { return CPP2_UFCS(is_expression_list)((*cpp2::impl::assert_not_null((*this).n)));  }
#line 1293 "reflect.h2"
    [[nodiscard]] auto is_as_expression::is_literal() const& -> bool { return CPP2_UFCS(is_literal)((*cpp2::impl::assert_not_null((*this).n))); }

#line 1295 "reflect.h2"
    [[nodiscard]] auto is_as_expression::as_expression_list() const& -> expression_list { return { CPP2_UFCS(get_expression_list)((*cpp2::impl::assert_not_null((*this).n))), (*this) };  }
#line 1296 "reflect.h2"
    [[nodiscard]] auto is_as_expression::as_literal() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(CPP2_UFCS(get_literal)(*cpp2::impl::assert_not_null(n))))); }

#line 1298 "reflect.h2"
    [[nodiscard]] auto is_as_expression::get_identifier() const& -> std::string_view{
        auto ptok {CPP2_UFCS(get_identifier)((*cpp2::impl::assert_not_null((*this).n)))}; 
        if (ptok) {return *cpp2::impl::assert_not_null(cpp2::move(ptok)); }
        return ""; 
    }

#line 1304 "reflect.h2"
    [[nodiscard]] auto is_as_expression::to_string() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null((*this).n)));  }

    is_as_expression::~is_as_expression() noexcept{}
is_as_expression::is_as_expression(is_as_expression const& that)
                                     : reflection_base<is_as_expression_node>{ static_cast<reflection_base<is_as_expression_node> const&>(that) }{}
is_as_expression::is_as_expression(is_as_expression&& that) noexcept
                                     : reflection_base<is_as_expression_node>{ static_cast<reflection_base<is_as_expression_node>&&>(that) }{}

#line 1308 "reflect.h2"
//-----------------------------------------------------------------------
// 
//  Statements
//
//-----------------------------------------------------------------------
//

//-----------------------------------------------------------------------
//  General statement
//

#line 1322 "reflect.h2"
    statement::statement(

        cpp2::impl::in<statement_node*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : reflection_base<statement_node>{ n_, s }
#line 1327 "reflect.h2"
    {

    }

#line 1331 "reflect.h2"
    [[nodiscard]] auto statement::is_expression_statement() const& -> bool { return CPP2_UFCS(is_expression)((*cpp2::impl::assert_not_null(n)));  }
#line 1332 "reflect.h2"
    [[nodiscard]] auto statement::is_compound_statement() const& -> bool { return CPP2_UFCS(is_compound)((*cpp2::impl::assert_not_null(n))); }
#line 1333 "reflect.h2"
    [[nodiscard]] auto statement::is_selection_statement() const& -> bool { return CPP2_UFCS(is_selection)((*cpp2::impl::assert_not_null(n))); }
#line 1334 "reflect.h2"
    [[nodiscard]] auto statement::is_declaration() const& -> bool { return CPP2_UFCS(is_declaration)((*cpp2::impl::assert_not_null(n))); }
#line 1335 "reflect.h2"
    [[nodiscard]] auto statement::is_return_statement() const& -> bool { return CPP2_UFCS(is_return)((*cpp2::impl::assert_not_null(n))); }
#line 1336 "reflect.h2"
    [[nodiscard]] auto statement::is_iteration_statement() const& -> bool { return CPP2_UFCS(is_iteration)((*cpp2::impl::assert_not_null(n))); }
#line 1337 "reflect.h2"
    [[nodiscard]] auto statement::is_using_statement() const& -> bool { return CPP2_UFCS(is_using)((*cpp2::impl::assert_not_null(n))); }
#line 1338 "reflect.h2"
    [[nodiscard]] auto statement::is_contract() const& -> bool { return CPP2_UFCS(is_contract)((*cpp2::impl::assert_not_null(n))); }
#line 1339 "reflect.h2"
    [[nodiscard]] auto statement::is_inspect_expression() const& -> bool { return CPP2_UFCS(is_inspect)((*cpp2::impl::assert_not_null(n))); }
#line 1340 "reflect.h2"
    [[nodiscard]] auto statement::is_jump_statement() const& -> bool { return CPP2_UFCS(is_jump)((*cpp2::impl::assert_not_null(n))); }

#line 1342 "reflect.h2"
    [[nodiscard]] auto statement::as_expression_statement() const& -> expression_statement { return { CPP2_UFCS_TEMPLATE(get_if<expression_statement_node>)((*cpp2::impl::assert_not_null(n))), (*this) }; }
#line 1343 "reflect.h2"
    [[nodiscard]] auto statement::as_compound_statement() const& -> compound_statement { return { CPP2_UFCS_TEMPLATE(get_if<compound_statement_node>)((*cpp2::impl::assert_not_null(n))), (*this) }; }
#line 1344 "reflect.h2"
    [[nodiscard]] auto statement::as_selection_statement() const& -> selection_statement { return selection_statement(CPP2_UFCS_TEMPLATE(get_if<selection_statement_node>)((*cpp2::impl::assert_not_null(n))), (*this)); }
#line 1345 "reflect.h2"
    [[nodiscard]] auto statement::as_declaration() const& -> declaration { return declaration(CPP2_UFCS_TEMPLATE(get_if<declaration_node>)((*cpp2::impl::assert_not_null(n))), (*this)); }
#line 1346 "reflect.h2"
    [[nodiscard]] auto statement::as_return_statement() const& -> return_statement { return return_statement(CPP2_UFCS_TEMPLATE(get_if<return_statement_node>)((*cpp2::impl::assert_not_null(n))), (*this)); }
#line 1347 "reflect.h2"
    [[nodiscard]] auto statement::as_iteration_statement() const& -> iteration_statement { return iteration_statement(CPP2_UFCS_TEMPLATE(get_if<iteration_statement_node>)((*cpp2::impl::assert_not_null(n))), (*this)); }
    //as_using_statement      : (this) -> using_statement       = using_statement      (n*.get_if<using_statement_node>(), this);
    //as_contract             : (this) -> contract              = contract             (n*.get_if<contract_node>(), this);
    //as_inspect_expression   : (this) -> inspect_expression    = inspect_expression   (n*.get_if<inspect_expression_node>(), this);
    //as_jump_statement       : (this) -> jump_statement        = jump_statement       (n*.get_if<jump_statement_node>(), this);

#line 1353 "reflect.h2"
    [[nodiscard]] auto statement::to_string() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(n)));  }

    statement::~statement() noexcept{}
statement::statement(statement const& that)
                                     : reflection_base<statement_node>{ static_cast<reflection_base<statement_node> const&>(that) }{}
statement::statement(statement&& that) noexcept
                                     : reflection_base<statement_node>{ static_cast<reflection_base<statement_node>&&>(that) }{}

#line 1357 "reflect.h2"
//-----------------------------------------------------------------------
//  Expression statements
//

#line 1364 "reflect.h2"
    expression_statement::expression_statement(

        cpp2::impl::in<expression_statement_node*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : reflection_base<expression_statement_node>{ n_, s }
#line 1369 "reflect.h2"
    {

    }

#line 1373 "reflect.h2"
    [[nodiscard]] auto expression_statement::get_expression() const& -> expression { return { CPP2_UFCS(get)((*cpp2::impl::assert_not_null(n)).expr), (*this) }; }

#line 1375 "reflect.h2"
    [[nodiscard]] auto expression_statement::to_string() const& -> std::string { return CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(n))); }

    expression_statement::expression_statement(expression_statement const& that)
                                     : reflection_base<expression_statement_node>{ static_cast<reflection_base<expression_statement_node> const&>(that) }{}
expression_statement::expression_statement(expression_statement&& that) noexcept
                                     : reflection_base<expression_statement_node>{ static_cast<reflection_base<expression_statement_node>&&>(that) }{}

#line 1379 "reflect.h2"
//-----------------------------------------------------------------------
//  Compound statements
//

#line 1386 "reflect.h2"
    compound_statement::compound_statement(

        cpp2::impl::in<compound_statement_node*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : reflection_base<compound_statement_node>{ n_, s }
#line 1391 "reflect.h2"
    {

    }

#line 1395 "reflect.h2"
    [[nodiscard]] auto compound_statement::get_statements() const& -> std::vector<statement>

    {
        std::vector<statement> ret {}; 
        for ( auto const& stmt : CPP2_UFCS(get_statements)((*cpp2::impl::assert_not_null(n))) ) {
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, stmt, (*this)));
        }
        return ret; 
    }

#line 1405 "reflect.h2"
    auto compound_statement::add_statement(cpp2::impl::in<std::string_view> source, cpp2::impl::in<int> before_position) & -> void
    {
        auto stmt {parse_statement(source)}; 
        if (!((cpp2::impl::as_<bool>(stmt)))) {
            error("the provided source string is not a valid statement");
            return ; 
        }
        require(CPP2_UFCS(add_statement)((*cpp2::impl::assert_not_null(n)), std::move(cpp2::move(stmt)), before_position), 
                 std::string("unexpected error while attempting to add statement:\n") + source);
    }

    compound_statement::compound_statement(compound_statement const& that)
                                     : reflection_base<compound_statement_node>{ static_cast<reflection_base<compound_statement_node> const&>(that) }{}
compound_statement::compound_statement(compound_statement&& that) noexcept
                                     : reflection_base<compound_statement_node>{ static_cast<reflection_base<compound_statement_node>&&>(that) }{}

#line 1418 "reflect.h2"
//-----------------------------------------------------------------------
//  Selection statements
//

#line 1425 "reflect.h2"
    selection_statement::selection_statement(

        cpp2::impl::in<selection_statement_node*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : reflection_base<selection_statement_node>{ n_, s }
#line 1430 "reflect.h2"
    {

    }

#line 1434 "reflect.h2"
    [[nodiscard]] auto selection_statement::has_false_branch_in_source_code() const& -> bool { return CPP2_UFCS(has_false_branch_in_source_code)((*cpp2::impl::assert_not_null(n)));  }
#line 1435 "reflect.h2"
    [[nodiscard]] auto selection_statement::has_false_branch() const& -> bool { return CPP2_UFCS(has_false_branch)((*cpp2::impl::assert_not_null(n))); }

#line 1437 "reflect.h2"
    [[nodiscard]] auto selection_statement::get_identifier() const& -> std::string_view { return CPP2_UFCS(as_string_view)((*cpp2::impl::assert_not_null(CPP2_UFCS(get_identifier)(*cpp2::impl::assert_not_null(n))))); }
#line 1438 "reflect.h2"
    [[nodiscard]] auto selection_statement::get_expression() const& -> logical_or_expression { return { CPP2_UFCS(get_expression)((*cpp2::impl::assert_not_null(n))), (*this) }; }
#line 1439 "reflect.h2"
    [[nodiscard]] auto selection_statement::get_true_branch() const& -> compound_statement { return { CPP2_UFCS(get_true_branch)((*cpp2::impl::assert_not_null(n))), (*this) }; }
#line 1440 "reflect.h2"
    [[nodiscard]] auto selection_statement::get_false_branch() const& -> compound_statement { return { CPP2_UFCS(get_false_branch)((*cpp2::impl::assert_not_null(n))), (*this) }; }

    selection_statement::selection_statement(selection_statement const& that)
                                     : reflection_base<selection_statement_node>{ static_cast<reflection_base<selection_statement_node> const&>(that) }{}
selection_statement::selection_statement(selection_statement&& that) noexcept
                                     : reflection_base<selection_statement_node>{ static_cast<reflection_base<selection_statement_node>&&>(that) }{}

#line 1444 "reflect.h2"
//-----------------------------------------------------------------------
//  Return statements
//

#line 1451 "reflect.h2"
    return_statement::return_statement(

        cpp2::impl::in<return_statement_node*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : reflection_base<return_statement_node>{ n_, s }
#line 1456 "reflect.h2"
    {

    }

#line 1460 "reflect.h2"
    [[nodiscard]] auto return_statement::has_expression() const& -> bool { return CPP2_UFCS(has_expression)((*cpp2::impl::assert_not_null(n))); }

#line 1462 "reflect.h2"
    [[nodiscard]] auto return_statement::get_expression() const& -> expression { return { CPP2_UFCS(get_expression)((*cpp2::impl::assert_not_null(n))), (*this) };  }

    return_statement::return_statement(return_statement const& that)
                                     : reflection_base<return_statement_node>{ static_cast<reflection_base<return_statement_node> const&>(that) }{}
return_statement::return_statement(return_statement&& that) noexcept
                                     : reflection_base<return_statement_node>{ static_cast<reflection_base<return_statement_node>&&>(that) }{}

#line 1466 "reflect.h2"
//-----------------------------------------------------------------------
//  Iteration statements - for, do, while
//

#line 1473 "reflect.h2"
    iteration_statement::iteration_statement(

        cpp2::impl::in<iteration_statement_node*> n_, 
        cpp2::impl::in<compiler_services> s
    )
        : reflection_base<iteration_statement_node>{ n_, s }
#line 1478 "reflect.h2"
    {

    }

#line 1482 "reflect.h2"
    [[nodiscard]] auto iteration_statement::is_do() const& -> bool { return CPP2_UFCS(is_do)((*cpp2::impl::assert_not_null(n))); }
#line 1483 "reflect.h2"
    [[nodiscard]] auto iteration_statement::is_while() const& -> bool { return CPP2_UFCS(is_while)((*cpp2::impl::assert_not_null(n)));  }
#line 1484 "reflect.h2"
    [[nodiscard]] auto iteration_statement::is_for() const& -> bool { return CPP2_UFCS(is_for)((*cpp2::impl::assert_not_null(n))); }
#line 1485 "reflect.h2"
    [[nodiscard]] auto iteration_statement::has_next() const& -> bool { return CPP2_UFCS(has_next)((*cpp2::impl::assert_not_null(n)));  }

#line 1487 "reflect.h2"
    [[nodiscard]] auto iteration_statement::get_label() const& -> std::string { return CPP2_UFCS(to_string)(CPP2_UFCS(get_label)((*cpp2::impl::assert_not_null(n)))); }
#line 1488 "reflect.h2"
    [[nodiscard]] auto iteration_statement::get_next_expression() const& -> assignment_expression { return { CPP2_UFCS(get_next_expression)((*cpp2::impl::assert_not_null(n))), (*this) }; }
#line 1489 "reflect.h2"
    [[nodiscard]] auto iteration_statement::get_do_while_condition() const& -> logical_or_expression { return { CPP2_UFCS(get_do_while_condition)((*cpp2::impl::assert_not_null(n))), (*this) };  }
#line 1490 "reflect.h2"
    [[nodiscard]] auto iteration_statement::get_do_while_body() const& -> compound_statement { return { CPP2_UFCS(get_do_while_body)((*cpp2::impl::assert_not_null(n))), (*this) }; }
#line 1491 "reflect.h2"
    [[nodiscard]] auto iteration_statement::get_for_range() const& -> expression { return { CPP2_UFCS(get_for_range)((*cpp2::impl::assert_not_null(n))), (*this) }; }
#line 1492 "reflect.h2"
    [[nodiscard]] auto iteration_statement::get_for_parameter() const& -> parameter_declaration { return { CPP2_UFCS(get_for_parameter)((*cpp2::impl::assert_not_null(n))), (*this) }; }
#line 1493 "reflect.h2"
    [[nodiscard]] auto iteration_statement::get_for_body() const& -> statement { return { CPP2_UFCS(get_for_body)((*cpp2::impl::assert_not_null(n))), (*this) }; }

    iteration_statement::iteration_statement(iteration_statement const& that)
                                     : reflection_base<iteration_statement_node>{ static_cast<reflection_base<iteration_statement_node> const&>(that) }{}
iteration_statement::iteration_statement(iteration_statement&& that) noexcept
                                     : reflection_base<iteration_statement_node>{ static_cast<reflection_base<iteration_statement_node>&&>(that) }{}

#line 1497 "reflect.h2"
//-----------------------------------------------------------------------
//
//  Metafunctions - these are hardwired for now until we get to the
//  step of writing a Cpp2 interpreter to run inside the compiler
//
//-----------------------------------------------------------------------
//

//-----------------------------------------------------------------------
//  Some common metafunction helpers (metafunctions are just functions,
//  so they can be factored as usual)
//
#line 1509 "reflect.h2"
auto add_virtual_destructor(meta::type_declaration& t) -> void
{
    CPP2_UFCS(add_member)(t, "operator=: (virtual move this) = { }");
}

#line 1515 "reflect.h2"
//-----------------------------------------------------------------------
//
//      "... an abstract base class defines an interface ..."
//
//          -- Stroustrup (The Design and Evolution of C++, 12.3.1)
//
//-----------------------------------------------------------------------
//
//  interface
//
//  an abstract base class having only pure virtual named functions,
//  a public default constructor, a public virtual destructor, and
//  protected copy/move operations
//
#line 1529 "reflect.h2"
auto interface(meta::type_declaration& t) -> void
{
    auto has_dtor {false}; 

    for ( auto& m : CPP2_UFCS(get_members)(t) ) 
    {
        CPP2_UFCS(require)(m, !(CPP2_UFCS(is_object)(m)), 
                   "interfaces may not contain data objects");
        if (CPP2_UFCS(is_function)(m)) {
            auto mf {CPP2_UFCS(as_function)(m)}; 
            CPP2_UFCS(require)(mf, !(CPP2_UFCS(is_copy_or_move)(mf)), 
                        "interfaces may not copy or move; consider a virtual clone() instead");
            CPP2_UFCS(require)(mf, !(CPP2_UFCS(has_initializer)(mf)), 
                        "interface functions must not have a function body; remove the '=' initializer");
            CPP2_UFCS(require)(mf, CPP2_UFCS(make_public)(mf), 
                        "interface functions must be public");
            CPP2_UFCS(default_to_virtual)(mf);
            has_dtor |= CPP2_UFCS(is_destructor)(cpp2::move(mf));
        }
    }

    //  Add public default constructor + protected copy/move operations
    CPP2_UFCS(add_member)(t, "operator=: (out this) = { }");
    CPP2_UFCS(add_member)(t, "protected operator=: (out this, that) = { }");

    //  Add public virtual destructor
    if (!(cpp2::move(has_dtor))) {
        CPP2_UFCS(add_virtual_destructor)(t);
    }
}

#line 1561 "reflect.h2"
//-----------------------------------------------------------------------
//
//     "C.35: A base class destructor should be either public and
//      virtual, or protected and non-virtual."
//
//          -- Stroustrup, Sutter, et al. (C++ Core Guidelines)
//
//-----------------------------------------------------------------------
//
//  polymorphic_base
//
//  A polymorphic base type whose destructor is either public and virtual
//  or else protected and nonvirtual.
//
//  Unlike an interface, it can have nonpublic and nonvirtual functions.
//
#line 1577 "reflect.h2"
auto polymorphic_base(meta::type_declaration& t) -> void
{
    auto has_dtor {false}; 

    for ( auto& mf : CPP2_UFCS(get_member_functions)(t) ) 
    {
        if (CPP2_UFCS(is_default_access)(mf)) {
            CPP2_UFCS(default_to_public)(mf);
        }
        CPP2_UFCS(require)(mf, !(CPP2_UFCS(is_copy_or_move)(mf)), 
                    "polymorphic base types may not copy or move; consider a virtual clone() instead");
        if (CPP2_UFCS(is_destructor)(mf)) {
            has_dtor = true;
            CPP2_UFCS(require)(mf, ((CPP2_UFCS(is_public)(mf) || CPP2_UFCS(is_default_access)(mf)) && CPP2_UFCS(is_virtual)(mf)) 
                        || (CPP2_UFCS(is_protected)(mf) && !(CPP2_UFCS(is_virtual)(mf))), 
                        "a polymorphic base type destructor must be public and virtual, or protected and nonvirtual");
        }
    }

    if (!(cpp2::move(has_dtor))) {
        CPP2_UFCS(add_virtual_destructor)(t);
    }
}

#line 1602 "reflect.h2"
//-----------------------------------------------------------------------
//
//     "... A totally ordered type ... requires operator<=> that
//      returns std::strong_ordering. If the function is not
//      user-written, a lexicographical memberwise implementation
//      is generated by default..."
//
//          -- P0707R4, section 3
//
//      Note: This feature derived from Cpp2 was already adopted
//            into Standard C++ via paper P0515, so most of the
//            heavy lifting is done by the Cpp1 C++20/23 compiler,
//            including the memberwise default semantics
//            (In contrast, cppfront has to do the work itself for
//            default memberwise semantics for operator= assignment
//            as those aren't yet part of Standard C++)
//
//-----------------------------------------------------------------------
//

#line 1622 "reflect.h2"
auto ordered_impl(
    meta::type_declaration& t, 
    cpp2::impl::in<std::string_view> ordering// must be "strong_ordering" etc.
) -> void
{
    auto has_spaceship {false}; 

    for ( auto& mf : CPP2_UFCS(get_member_functions)(t) ) 
    {
        if (CPP2_UFCS(has_name)(mf, "operator<=>")) {
            has_spaceship = true;
            auto return_name {CPP2_UFCS(get_unnamed_return_type)(mf)}; 
            if (CPP2_UFCS(find)(return_name, ordering) == return_name.npos) 
            {
                CPP2_UFCS(error)(mf, "operator<=> must return std::" + cpp2::impl::as_<std::string>(ordering));
            }
        }
    }

    if (!(cpp2::move(has_spaceship))) {
        CPP2_UFCS(add_member)(t, "operator<=>: (this, that) -> std::" + (cpp2::impl::as_<std::string>(ordering)) + ";");
    }
}

//-----------------------------------------------------------------------
//  ordered - a totally ordered type
//
//  Note: the ordering that should be encouraged as default gets the nice name
//
#line 1651 "reflect.h2"
auto ordered(meta::type_declaration& t) -> void
{
    ordered_impl(t, "strong_ordering");
}

//-----------------------------------------------------------------------
//  weakly_ordered - a weakly ordered type
//
#line 1659 "reflect.h2"
auto weakly_ordered(meta::type_declaration& t) -> void
{
    ordered_impl(t, "weak_ordering");
}

//-----------------------------------------------------------------------
//  partially_ordered - a partially ordered type
//
#line 1667 "reflect.h2"
auto partially_ordered(meta::type_declaration& t) -> void
{
    ordered_impl(t, "partial_ordering");
}

#line 1673 "reflect.h2"
//-----------------------------------------------------------------------
//
//     "A value is ... a regular type. It must have all public
//      default construction, copy/move construction/assignment,
//      and destruction, all of which are generated by default
//      if not user-written; and it must not have any protected
//      or virtual functions (including the destructor)."
//
//          -- P0707R4, section 3
//
//-----------------------------------------------------------------------
//
//  copyable
//
//  A type with (copy and move) x (construction and assignment)
//
#line 1689 "reflect.h2"
auto copyable(meta::type_declaration& t) -> void
{
    //  If the user explicitly wrote any of the copy/move functions,
    //  they must also have written the most general one - we can't
    //  assume we can safely generate it for them since they've opted
    //  into customized semantics
    auto smfs {CPP2_UFCS(query_declared_value_set_functions)(t)}; 
    if ( !(smfs.out_this_in_that) 
        && (
            smfs.out_this_move_that 
            || smfs.inout_this_in_that 
            || smfs.inout_this_move_that)) 

    {
        CPP2_UFCS(error)(t, 
            "this type is partially copyable/movable - when you provide "
            "any of the more-specific operator= signatures, you must also provide "
            "the one with the general signature (out this, that); alternatively, "
            "consider removing all the operator= functions and let them all be "
            "generated for you with default memberwise semantics"
        );
    }
    else {if (!(cpp2::move(smfs).out_this_in_that)) {
        CPP2_UFCS(add_member)(t, "operator=: (out this, that) = { }");
    }}
}

#line 1717 "reflect.h2"
//  copy_constructible
//
//  A type with (copy and move) construction
//
#line 1721 "reflect.h2"
auto copy_constructible(meta::type_declaration& t) -> void
{
    //  If the user explicitly wrote any of the copy/move constructors,
    //  they must also have written the most general one - we can't
    //  assume we can safely generate it for them since they've opted
    //  into customized semantics
    auto smfs {CPP2_UFCS(query_declared_value_set_functions)(t)}; 
    if ( !(smfs.out_this_in_that) 
        && smfs.out_this_move_that) 
    {
        CPP2_UFCS(error)(t, 
            "this type is partially copy/move constructible - when you provide "
            "the (out this, move that) operator= signature, you must also provide "
            "the one with the general signature (out this, that)"
        );
    }
    else {if (
        !(smfs.out_this_in_that) 
        && !(smfs.out_this_move_that)) 
    {
        CPP2_UFCS(add_member)(t, "operator=: (out this,      that) = { }");
        CPP2_UFCS(add_member)(t, "operator=: (out this, move that) = { }");
    }}
}

#line 1747 "reflect.h2"
//-----------------------------------------------------------------------
//
//  hashable
//
//  A memberwise hashable type
//
#line 1753 "reflect.h2"
auto hashable(meta::type_declaration& t) -> void
{
    CPP2_UFCS(require)(t, !(CPP2_UFCS(empty)(CPP2_UFCS(get_member_objects)(t))), 
               "a hashable type must have at least one data member");

    std::string hash {"    hash: (this) -> size_t = {\n"
                        "        ret: size_t = 0;"}; 

    for ( 
          auto const& o : CPP2_UFCS(get_member_objects)(t) ) 
    {
        cpp2::impl::deferred_init<std::string> o_hash; 
        if (CPP2_UFCS(name)(o) == "this") {
            o_hash.construct("" + cpp2::to_string(CPP2_UFCS(type)(o)) + "::hash()");
        }
        else {
            o_hash.construct("std::hash<" + cpp2::to_string(CPP2_UFCS(type)(o)) + ">()(" + cpp2::to_string(CPP2_UFCS(name)(o)) + ")");
        }

        hash += "\n        cpp2::hash_combine( ret, " + cpp2::to_string(cpp2::move(o_hash.value())) + " );";
    }

    CPP2_UFCS(add_member)(t, cpp2::move(hash) + "\n        return ret;\n    }");
}

#line 1779 "reflect.h2"
//-----------------------------------------------------------------------
//
//  basic_value
//
//  A regular type: copyable, plus has public default construction
//  and no protected or virtual functions
//
#line 1786 "reflect.h2"
auto basic_value(meta::type_declaration& t) -> void
{
    CPP2_UFCS(copyable)(t);

    auto has_default_ctor {false}; 
    for ( auto& mf : CPP2_UFCS(get_member_functions)(t) ) {
        has_default_ctor |= CPP2_UFCS(is_default_constructor)(mf);
        CPP2_UFCS(require)(mf, !(CPP2_UFCS(is_protected)(mf)) && !(CPP2_UFCS(is_virtual)(mf)), 
                    "a value type may not have a protected or virtual function");
        CPP2_UFCS(require)(mf, !(CPP2_UFCS(is_destructor)(mf)) || CPP2_UFCS(is_public)(mf) || CPP2_UFCS(is_default_access)(mf), 
                    "a value type may not have a non-public destructor");
    }

    if (!(cpp2::move(has_default_ctor))) {
        CPP2_UFCS(add_member)(t, "operator=: (out this) = { }");
    }
}

//-----------------------------------------------------------------------
//
//     "A 'value' is a totally ordered basic_value..."
//
//          -- P0707R4, section 3
//
//  value - a value type that is totally ordered
//
//  Note: the ordering that should be encouraged as default gets the nice name
//
#line 1814 "reflect.h2"
auto value(meta::type_declaration& t) -> void
{
    CPP2_UFCS(ordered)(t);
    CPP2_UFCS(basic_value)(t);
}

#line 1820 "reflect.h2"
auto weakly_ordered_value(meta::type_declaration& t) -> void
{
    CPP2_UFCS(weakly_ordered)(t);
    CPP2_UFCS(basic_value)(t);
}

#line 1826 "reflect.h2"
auto partially_ordered_value(meta::type_declaration& t) -> void
{
    CPP2_UFCS(partially_ordered)(t);
    CPP2_UFCS(basic_value)(t);
}

#line 1833 "reflect.h2"
//-----------------------------------------------------------------------
//
//     C.20: If you can avoid defining default operations, do
//
//     ##### Reason
//
//     It's the simplest and gives the cleanest semantics.
//
//     ...
//
//     This is known as "the rule of zero".
//
//          -- C++ Core Guidelines
//             C.20: If you can avoid defining any default operations, do
//             <https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rc-zero>
//
//-----------------------------------------------------------------------
//
//  cpp1_rule_of_zero
//
//  a type without declared copy/move/destructor functions
//
#line 1855 "reflect.h2"
auto cpp1_rule_of_zero(meta::type_declaration& t) -> void
{
    for ( auto& mf : CPP2_UFCS(get_member_functions)(t) ) 
    {
        CPP2_UFCS(require)(t, !(CPP2_UFCS(is_constructor_with_that)(mf)) 
                   && !(CPP2_UFCS(is_assignment_with_that)(mf)) 
                   && !(CPP2_UFCS(is_destructor)(mf)), 
                   "the rule of zero requires no copy/move/destructor functions");
    }
    CPP2_UFCS(disable_member_function_generation)(t);
}

//-----------------------------------------------------------------------
//
//     "By definition, a `struct` is a `class` in which members
//      are by default `public`; that is,
//
//      	struct s { ...
//
//      is simply shorthand for
//
//          class s { public: ...
//
//      ... Which style you use depends on circumstances and taste.
//      I usually prefer to use `struct` for classes that have all
//      data `public`."
//
//          -- Stroustrup (The C++ Programming Language, 3rd ed., p. 234)
//
//-----------------------------------------------------------------------
//
//  struct
//
//  a type with only public bases, objects, and functions,
//  no virtual functions, and no user-defined constructors
//  (i.e., no invariants) or assignment or destructors.
// 
//  For GCC 10 compatibility, optionally allow passing struct<noforward>
//  that generates a memberwise constructor with a generic deduced
//  parameters instead of concrete forwarding parameters (mainly used
//  for cppfront internal use, so cppfront builds under GCC 10)
//
#line 1897 "reflect.h2"
auto cpp2_struct(meta::type_declaration& t) -> void
{
    std::string ctor_params {}; 
    std::string ctor_inits {}; 

    auto found_member_without_initializer {false}; 

    for ( auto& m : CPP2_UFCS(get_members)(t) ) 
    {
        CPP2_UFCS(require)(m, CPP2_UFCS(make_public)(m), 
                   "all struct members must be public");
        if (CPP2_UFCS(is_function)(m)) {
            auto mf {CPP2_UFCS(as_function)(m)}; 
            CPP2_UFCS(require)(t, !(CPP2_UFCS(is_virtual)(mf)), 
                       "a struct may not have a virtual function");
            CPP2_UFCS(require)(t, !(CPP2_UFCS(has_name)(cpp2::move(mf), "operator=")), 
                       "a struct may not have a user-defined operator=");
        }
        else {if (CPP2_UFCS(is_object)(m)) {
            auto mo {CPP2_UFCS(as_object)(m)}; 
            if (CPP2_UFCS(name)(mo) != "this") {
                if (CPP2_UFCS(get_argument)(t, 0) == "noforward") {
                    ctor_params += "" + cpp2::to_string(CPP2_UFCS(name)(mo)) + "_, ";
                }
                else {
                    ctor_params += "forward " + cpp2::to_string(CPP2_UFCS(name)(mo)) + "_ : " + cpp2::to_string(CPP2_UFCS(type)(mo)) + ", ";
                }
                ctor_inits  += "" + cpp2::to_string(CPP2_UFCS(name)(mo)) + " = " + cpp2::to_string(CPP2_UFCS(name)(mo)) + "_; ";
            }
            else {
                ctor_inits += "" + cpp2::to_string(CPP2_UFCS(type)(mo)) + " = (" + cpp2::to_string(CPP2_UFCS(initializer)(mo)) + "); ";
            }
            found_member_without_initializer |= !(CPP2_UFCS(has_initializer)(cpp2::move(mo)));
        }}
    }
    CPP2_UFCS(cpp1_rule_of_zero)(t);

    //  If we found any data members
    if (!(CPP2_UFCS(empty)(ctor_params))) 
    {
        //  Then to enable construction from corresponding values
        //  requires a constructor... an exception to the rule of zero
        CPP2_UFCS(add_member)(t, "    operator=: (implicit out this, " + cpp2::to_string(cpp2::move(ctor_params)) + ") = { " + cpp2::to_string(cpp2::move(ctor_inits)) + " }");

        //  And if all members had initializers, we need a default constructor
        if (!(cpp2::move(found_member_without_initializer))) {
            CPP2_UFCS(add_member)(t, "    operator=: (implicit out this) = { }");
        }
    }
}

value_member_info::value_member_info(auto const& name_, auto const& type_, auto const& value_)
                                                               : name{ name_ }
                                                               , type{ type_ }
                                                               , value{ value_ }{}

#line 1949 "reflect.h2"
//-----------------------------------------------------------------------
//
//     "C enumerations constitute a curiously half-baked concept. ...
//      the cleanest way out was to deem each enumeration a separate type."
//
//          -- Stroustrup (The Design and Evolution of C++, 11.7)
//
//     "An enumeration is a distinct type ... with named constants"
//
//          -- ISO C++ Standard
//
//-----------------------------------------------------------------------
//
//  basic_enum
//
//  a type together with named constants that are its possible values
//

#line 1972 "reflect.h2"
auto basic_enum(
    meta::type_declaration& t, 
    auto const& nextval, 
    cpp2::impl::in<bool> bitwise
    ) -> void
{
    std::vector<value_member_info> enumerators {}; 
    cpp2::i64 min_value {}; 
    cpp2::i64 max_value {}; 
    cpp2::impl::deferred_init<std::string> underlying_type; 

    CPP2_UFCS(reserve_names)(t, "operator=", "operator<=>");
    if (bitwise) {
        CPP2_UFCS(reserve_names)(t, "has", "set", "clear", "to_string", "get_raw_value", "none");
    }

    //  1. Gather: The names of all the user-written members, and find/compute the type

    underlying_type.construct(CPP2_UFCS(get_argument)(t, 0));// use the first template argument, if there was one

    auto found_non_numeric {false}; 
{
std::string value{"-1"};

#line 1995 "reflect.h2"
    for ( 
          auto const& m : CPP2_UFCS(get_members)(t) ) 
    if (  CPP2_UFCS(is_member_object)(m)) 
    {
        CPP2_UFCS(require)(m, CPP2_UFCS(is_public)(m) || CPP2_UFCS(is_default_access)(m), 
                    "an enumerator cannot be protected or private");

        auto mo {CPP2_UFCS(as_object)(m)}; 
        if (!(CPP2_UFCS(has_wildcard_type)(mo))) {
            CPP2_UFCS(error)(mo, 
                "an explicit underlying type should be specified as a compile-time argument "
                "to the metafunction - try 'enum<u16>' or 'flag_enum<u64>'"
            );
        }

        auto init {CPP2_UFCS(initializer)(mo)}; 

        auto is_default_or_numeric {is_empty_or_a_decimal_number(init)}; 
        found_non_numeric |= !(CPP2_UFCS(empty)(init)) && !(is_default_or_numeric);
        CPP2_UFCS(require)(m, !(cpp2::move(is_default_or_numeric)) || !(found_non_numeric) || CPP2_UFCS(has_name)(mo, "none"), 
            "" + cpp2::to_string(CPP2_UFCS(name)(mo)) + ": enumerators with non-numeric values must come after all default and numeric values");

        nextval(value, cpp2::move(init));

        auto v {std::strtoll(&CPP2_ASSERT_IN_BOUNDS_LITERAL(value, 0), nullptr, 10)}; // for non-numeric values we'll just get 0 which is okay for now
        if (cpp2::impl::cmp_less(v,min_value)) {
            min_value = v;
        }
        if (cpp2::impl::cmp_greater(v,max_value)) {
            max_value = cpp2::move(v);
        }

        //  Adding local variable 'e' to work around a Clang warning
        value_member_info e {cpp2::impl::as_<std::string>(CPP2_UFCS(name)(mo)), "", value}; 
        CPP2_UFCS(push_back)(enumerators, cpp2::move(e));

        CPP2_UFCS(mark_for_removal_from_enclosing_type)(mo);
        static_cast<void>(cpp2::move(mo));
    }
}

#line 2035 "reflect.h2"
    if ((CPP2_UFCS(empty)(enumerators))) {
        CPP2_UFCS(error)(t, "an enumeration must contain at least one enumerator value");
        return ; 
    }

    //  Compute the default underlying type, if it wasn't explicitly specified
    if (underlying_type.value() == "") 
    {
        CPP2_UFCS(require)(t, !(cpp2::move(found_non_numeric)), 
            "if you write an enumerator with a non-numeric-literal value, "
            "you must specify the enumeration's underlying type"
        );

        if (!(bitwise)) {
            if (cpp2::impl::cmp_greater_eq(min_value,std::numeric_limits<cpp2::i8>::min()) && cpp2::impl::cmp_less_eq(max_value,std::numeric_limits<cpp2::i8>::max())) {
                underlying_type.value() = "i8";
            }
            else {if (cpp2::impl::cmp_greater_eq(min_value,std::numeric_limits<cpp2::i16>::min()) && cpp2::impl::cmp_less_eq(max_value,std::numeric_limits<cpp2::i16>::max())) {
                underlying_type.value() = "i16";
            }
            else {if (cpp2::impl::cmp_greater_eq(min_value,std::numeric_limits<cpp2::i32>::min()) && cpp2::impl::cmp_less_eq(max_value,std::numeric_limits<cpp2::i32>::max())) {
                underlying_type.value() = "i32";
            }
            else {if (cpp2::impl::cmp_greater_eq(cpp2::move(min_value),std::numeric_limits<cpp2::i64>::min()) && cpp2::impl::cmp_less_eq(cpp2::move(max_value),std::numeric_limits<cpp2::i64>::max())) {
                underlying_type.value() = "i64";
            }
            else {
                CPP2_UFCS(error)(t, 
                    "values are outside the range representable by the "
                    "largest supported underlying signed type (i64)"
                );
            }}}}
        }
        else {
            auto umax {cpp2::move(max_value) * cpp2::impl::as_<cpp2::u64, 2>()}; 
            if (cpp2::impl::cmp_less_eq(umax,std::numeric_limits<cpp2::u8>::max())) {
                underlying_type.value() = "u8";
            }
            else {if (cpp2::impl::cmp_less_eq(umax,std::numeric_limits<cpp2::u16>::max())) {
                underlying_type.value() = "u16";
            }
            else {if (cpp2::impl::cmp_less_eq(cpp2::move(umax),std::numeric_limits<cpp2::u32>::max())) {
                underlying_type.value() = "u32";
            }
            else {
                underlying_type.value() = "u64";
            }}}
        }
    }

#line 2086 "reflect.h2"
    //  2. Replace: Erase the contents and replace with modified contents
    //
    //  Note that most values and functions are declared as '==' compile-time values, i.e. Cpp1 'constexpr'

    CPP2_UFCS(remove_marked_members)(t);

    //  Generate the 'none' value if appropriate, and use that or
    //  else the first enumerator as the default-constructed value
    auto default_value {CPP2_ASSERT_IN_BOUNDS_LITERAL(enumerators, 0).name}; 
    if (bitwise) {
        default_value = "none";
        value_member_info e {"none", "", "0"}; 
        CPP2_UFCS(push_back)(enumerators, cpp2::move(e));
    }

    //  Generate all the private implementation
    CPP2_UFCS(add_member)(t, "    _value            : " + cpp2::to_string(underlying_type.value()) + ";");
    CPP2_UFCS(add_member)(t, "    private operator= : (implicit out this, _val: i64) == "
                                            "_value = cpp2::unchecked_narrow<" + cpp2::to_string(underlying_type.value()) + ">(_val);");

    //  Generate the bitwise operations
    if (bitwise) {
        CPP2_UFCS(add_member)(t, "    operator|=: ( inout this, that )                 == _value |= that._value;");
        CPP2_UFCS(add_member)(t, "    operator&=: ( inout this, that )                 == _value &= that._value;");
        CPP2_UFCS(add_member)(t, "    operator^=: ( inout this, that )                 == _value ^= that._value;");
        CPP2_UFCS(add_member)(t, "    operator| : (       this, that ) -> " + cpp2::to_string(CPP2_UFCS(name)(t)) + "  == _value |  that._value;");
        CPP2_UFCS(add_member)(t, "    operator& : (       this, that ) -> " + cpp2::to_string(CPP2_UFCS(name)(t)) + "  == _value &  that._value;");
        CPP2_UFCS(add_member)(t, "    operator^ : (       this, that ) -> " + cpp2::to_string(CPP2_UFCS(name)(t)) + "  == _value ^  that._value;");
        CPP2_UFCS(add_member)(t, "    has       : (       this, that ) -> bool         == _value &  that._value;");
        CPP2_UFCS(add_member)(t, "    set       : ( inout this, that )                 == { _value |= that._value;  }");
        CPP2_UFCS(add_member)(t, "    clear     : ( inout this, that )                 == { _value &= that._value~; }");
    }

    //  Add the enumerators
    for ( auto const& e : enumerators ) {
        CPP2_UFCS(add_member)(t, "    " + cpp2::to_string(e.name) + " : " + cpp2::to_string(CPP2_UFCS(name)(t)) + " == " + cpp2::to_string(e.value) + ";");
    }

    //  Generate the common functions
    CPP2_UFCS(add_member)(t, "    get_raw_value     : (this) -> " + cpp2::to_string(cpp2::move(underlying_type.value())) + " == _value;");
    CPP2_UFCS(add_member)(t, "    operator=         : (out this) == { _value = " + cpp2::to_string(default_value) + "._value; }");
    CPP2_UFCS(add_member)(t, "    operator=         : (out this, that) == { }");
    CPP2_UFCS(add_member)(t, "    operator<=>       : (this, that) -> std::strong_ordering;");
{
std::string to_string_impl{"    to_string_impl: (this, prefix: std::string_view"};

    //  Provide 'to_string' and 'to_code' functions to print enumerator
    //  name(s) as human-readable strings or as code expressions

#line 2133 "reflect.h2"
    {
        if (bitwise) {
            to_string_impl += ", separator: std::string_view ) -> std::string = { \n"
                              "    ret : std::string = \"(\";\n"
                              "    sep : std::string = ();\n"
                              "    if this == none { return \"(none)\"; }\n";
        }
        else {
            to_string_impl += ") -> std::string = { \n";
        }

        to_string_impl += "    pref := cpp2::to_string(prefix);\n";

        for ( 
              auto const& e : enumerators ) {
            if (e.name != "_") {// ignore unnamed values
                if (bitwise) {
                    if (e.name != "none") {
                        to_string_impl += "    if (this & " + cpp2::to_string(CPP2_UFCS(name)(t)) + "::" + cpp2::to_string(e.name) + ") == " + cpp2::to_string(CPP2_UFCS(name)(t)) + "::" + cpp2::to_string(e.name) + " { "
                                                  "ret += sep + pref + \"" + cpp2::to_string(e.name) + "\"; sep = separator; "
                                              "}\n";
                    }
                }
                else {
                    to_string_impl += "    if this == " + cpp2::to_string(CPP2_UFCS(name)(t)) + "::" + cpp2::to_string(e.name) + " { return pref + \"" + cpp2::to_string(e.name) + "\"; }\n";
                }
            }
        }

        if (bitwise) {
            to_string_impl += "    return ret+\")\";\n}\n";
        }
        else {
            to_string_impl += "    return \"invalid " + cpp2::to_string(CPP2_UFCS(name)(t)) + " value\";\n}\n";
        }

        CPP2_UFCS(add_member)(t, cpp2::move(to_string_impl));
    }
}

#line 2172 "reflect.h2"
    if (bitwise) {
        CPP2_UFCS(add_member)(t, "    to_string: (this) -> std::string = to_string_impl( \"\", \", \" );");
        CPP2_UFCS(add_member)(t, "    to_code  : (this) -> std::string = to_string_impl( \"" + cpp2::to_string(CPP2_UFCS(name)(t)) + "::\", \" | \" );");
    }
    else {
        CPP2_UFCS(add_member)(t, "    to_string: (this) -> std::string = to_string_impl( \"\" );");
        CPP2_UFCS(add_member)(t, "    to_code  : (this) -> std::string = to_string_impl( \"" + cpp2::to_string(CPP2_UFCS(name)(t)) + "::\" );");
    }
{
std::string from_string{"    from_string: (s: std::string_view) -> " + cpp2::to_string(CPP2_UFCS(name)(t)) + " = { \n"};

    //  Provide a 'from_string' function to parse strings into enumerators    

#line 2183 "reflect.h2"
    {
        std::string_view prefix {""}; 
        std::string_view combine_op {"return"}; 

        //  For flags, accept a list that we break apart and then |= together
        if (bitwise) 
        {
            prefix      = "flag_";
            combine_op  = "ret |=";

            from_string += "        ret := none;\n"
                           "        outer: do {\n"
                           "        for cpp2::string_util::split_string_list(s) do (x) {\n";
        }
        //  Otherwise, accept just a single string
        else {
            from_string += "        x := s;\n";
        }
{
std::string_view else_{""};

#line 2203 "reflect.h2"
        for ( 
              auto const& e : cpp2::move(enumerators) ) {
            from_string += "            " + cpp2::to_string(else_) + "if \"" + cpp2::to_string(e.name) + "\" == x { " + cpp2::to_string(combine_op) + " " + cpp2::to_string(CPP2_UFCS(name)(t)) + "::" + cpp2::to_string(e.name) + "; }\n";
            else_ = "else ";
        }
}

#line 2209 "reflect.h2"
        if (bitwise) {
            from_string += "            else { break outer; }\n"
                           "        }\n"
                           "        return ret;\n"
                           "        } while false;\n";
        }

        from_string += "        cpp2::type_safety.report_violation( (\"can't convert string '\" + cpp2::to_string(s) + \"' to " + cpp2::to_string(cpp2::move(prefix)) + "enum of type " + cpp2::to_string(CPP2_UFCS(name)(t)) + "\").c_str() );\n"
                       "        return " + cpp2::to_string(CPP2_UFCS(name)(t)) + "::" + cpp2::to_string(cpp2::move(default_value)) + ";\n"
                       "    }\n\n";

        CPP2_UFCS(add_member)(t, cpp2::move(from_string));
    }
}

#line 2223 "reflect.h2"
    CPP2_UFCS(add_member)(t, "    from_code: (s: std::string_view) -> " + cpp2::to_string(CPP2_UFCS(name)(t)) + " = { str: std::string = s; return from_string( cpp2::string_util::replace_all(str, \"" + cpp2::to_string(CPP2_UFCS(name)(t)) + "::\", \"\" ) ); }");
}

#line 2227 "reflect.h2"
//-----------------------------------------------------------------------
//
//    "An enum[...] is a totally ordered value type that stores a
//     value of its enumerators's type, and otherwise has only public
//     member variables of its enumerator's type, all of which are
//     naturally scoped because they are members of a type."
//
//          -- P0707R4, section 3
//
#line 2236 "reflect.h2"
auto cpp2_enum(meta::type_declaration& t) -> void
{
    //  Let basic_enum do its thing, with an incrementing value generator
    CPP2_UFCS(basic_enum)(t, 
        [](std::string& value, cpp2::impl::in<std::string> specified_value) -> void{
            if (!(CPP2_UFCS(empty)(specified_value))) {
                value = specified_value;
            }else {
                auto v {std::strtoll(&CPP2_ASSERT_IN_BOUNDS_LITERAL(value, 0), nullptr, 10)}; 
                value = cpp2::impl::as_<std::string>((cpp2::move(v) + 1));
            }
        }, 
        false   // disable bitwise operations
    );
}

#line 2253 "reflect.h2"
//-----------------------------------------------------------------------
//
//     "flag_enum expresses an enumeration that stores values
//      corresponding to bitwise-or'd enumerators. The enumerators must
//      be powers of two, and are automatically generated [...] A none
//      value is provided [...] Operators | and & are provided to
//      combine and extract values."
//
//          -- P0707R4, section 3
//
#line 2263 "reflect.h2"
auto flag_enum(meta::type_declaration& t) -> void
{
    //  Let basic_enum do its thing, with a power-of-two value generator
    CPP2_UFCS(basic_enum)(t, 
        [](std::string& value, cpp2::impl::in<std::string> specified_value) -> void{
            if (!(CPP2_UFCS(empty)(specified_value))) {
                value = specified_value;
            }else {
                auto v {std::strtoll(&CPP2_ASSERT_IN_BOUNDS_LITERAL(value, 0), nullptr, 10)}; 
                if (cpp2::impl::cmp_less(v,1)) {
                    value = "1";
                }
                else {
                    value = cpp2::impl::as_<std::string>((cpp2::move(v) * 2));
                }
            }
        }, 
        true    // enable bitwise operations
    );
}

#line 2285 "reflect.h2"
//-----------------------------------------------------------------------
//
//     "As with void*, programmers should know that unions [...] are
//      inherently dangerous, should be avoided wherever possible,
//      and should be handled with special care when actually needed."
//
//          -- Stroustrup (The Design and Evolution of C++, 14.3.4.1)
//
//     "C++17 needs a type-safe union... The implications of the
//      consensus `variant` design are well understood and have been
//      explored over several LEWG discussions, over a thousand emails,
//      a joint LEWG/EWG session, and not to mention 12 years of
//      experience with Boost and other libraries."
//
//          -- Axel Naumann, in P0088 (wg21.link/p0088),
//             the adopted proposal for C++17 std::variant
//
//-----------------------------------------------------------------------
//
//  union
//
//  a type that contains exactly one of a fixed set of values at a time
//

#line 2309 "reflect.h2"
auto cpp2_union(meta::type_declaration& t) -> void
{
    std::vector<value_member_info> alternatives {}; 
{
auto value{0};

    //  1. Gather: All the user-written members, and find/compute the max size

#line 2316 "reflect.h2"
    for ( 

           auto const& m : CPP2_UFCS(get_members)(t) )  { do 
    if (   CPP2_UFCS(is_member_object)(m)) 
    {
        CPP2_UFCS(require)(m, CPP2_UFCS(is_public)(m) || CPP2_UFCS(is_default_access)(m), 
                   "a union alternative cannot be protected or private"
                );

        CPP2_UFCS(require)(m, !(CPP2_UFCS(starts_with)(CPP2_UFCS(name)(m), "is_")) 
                   && !(CPP2_UFCS(starts_with)(CPP2_UFCS(name)(m), "set_")), 
                   "a union alternative's name cannot start with 'is_' or 'set_' - that could cause "
                   "user confusion with the 'is_alternative' and 'set_alternative' generated functions"
                );

        auto mo {CPP2_UFCS(as_object)(m)}; 
        CPP2_UFCS(require)(mo, CPP2_UFCS(empty)(CPP2_UFCS(initializer)(mo)), 
                    "a union alternative cannot have an initializer"
                );

        //  Adding local variable 'e' to work around a Clang warning
        value_member_info e {cpp2::impl::as_<std::string>(CPP2_UFCS(name)(mo)), CPP2_UFCS(type)(mo), cpp2::impl::as_<std::string>(value)}; 
        CPP2_UFCS(push_back)(alternatives, cpp2::move(e));

        CPP2_UFCS(mark_for_removal_from_enclosing_type)(mo);
        static_cast<void>(cpp2::move(mo));
    } while (false); ++value; }
}

#line 2344 "reflect.h2"
    std::string discriminator_type {}; 
    if (cpp2::impl::cmp_less(CPP2_UFCS(ssize)(alternatives),std::numeric_limits<cpp2::i8>::max())) {
        discriminator_type = "i8";
    }
    else {if (cpp2::impl::cmp_less(CPP2_UFCS(ssize)(alternatives),std::numeric_limits<cpp2::i16>::max())) {
        discriminator_type = "i16";
    }
    else {if (cpp2::impl::cmp_less(CPP2_UFCS(ssize)(alternatives),std::numeric_limits<cpp2::i32>::max())) {
        discriminator_type = "i32";
    }
    else {
        discriminator_type = "i64";
    }}}

#line 2359 "reflect.h2"
    //  2. Replace: Erase the contents and replace with modified contents

    CPP2_UFCS(remove_marked_members)(t);
{
std::string storage{"    _storage: cpp2::aligned_storage<cpp2::max( "};

    //  Provide storage

#line 2365 "reflect.h2"
    {
        for ( 
              auto const& e : alternatives ) {
            storage += "sizeof(" + cpp2::to_string(e.type) + "), ";
        }

        storage += "), cpp2::max( ";

        for ( 
              auto const& e : alternatives ) {
            storage += "alignof(" + cpp2::to_string(e.type) + "), ";
        }

        storage += " )> = ();\n";
        CPP2_UFCS(add_member)(t, cpp2::move(storage));
    }
}

    //  Provide discriminator
#line 2383 "reflect.h2"
    CPP2_UFCS(add_member)(t, "    _discriminator: " + cpp2::to_string(cpp2::move(discriminator_type)) + " = -1;\n");

    //  Add the alternatives: is_alternative, get_alternative, and set_alternative
    for ( 
         auto const& a : alternatives ) 
    {
        CPP2_UFCS(add_member)(t, "    is_" + cpp2::to_string(a.name) + ": (this) -> bool = _discriminator == " + cpp2::to_string(a.value) + ";\n");

        CPP2_UFCS(add_member)(t, "    " + cpp2::to_string(a.name) + ": (this) -> forward " + cpp2::to_string(a.type) + " pre(is_" + cpp2::to_string(a.name) + "()) = "
                            "reinterpret_cast<* const " + cpp2::to_string(a.type) + ">(_storage&)*;\n"
                    );

        CPP2_UFCS(add_member)(t, "    " + cpp2::to_string(a.name) + ": (inout this) -> forward " + cpp2::to_string(a.type) + " pre(is_" + cpp2::to_string(a.name) + "()) = "
                            "reinterpret_cast<*" + cpp2::to_string(a.type) + ">(_storage&)*;\n"
                    );

        CPP2_UFCS(add_member)(t, "    set_" + cpp2::to_string(a.name) + ": (inout this, _value: " + cpp2::to_string(a.type) + ") = { "
                            "if !is_" + cpp2::to_string(a.name) + "() { _destroy(); std::construct_at( reinterpret_cast<*" + cpp2::to_string(a.type) + ">(_storage&), _value); } "
                            "else { reinterpret_cast<*" + cpp2::to_string(a.type) + ">(_storage&)* = _value; } "
                            "_discriminator = " + cpp2::to_string(a.value) + "; "
                            "}\n"
                    );

        CPP2_UFCS(add_member)(t, "    set_" + cpp2::to_string(a.name) + ": (inout this, forward _args...: _) = { "
                            "if !is_" + cpp2::to_string(a.name) + "() { _destroy(); std::construct_at( reinterpret_cast<*" + cpp2::to_string(a.type) + ">(_storage&), _args...); } "
                            " else { reinterpret_cast<*" + cpp2::to_string(a.type) + ">(_storage&)* = :" + cpp2::to_string(a.type) + " = (_args...); } "
                            "_discriminator = " + cpp2::to_string(a.value) + "; "
                            "}\n"
                    );
    }
{
std::string destroy{"    private _destroy: (inout this) = {\n"};

    //  Add destroy

#line 2416 "reflect.h2"
    {
        for ( 
              auto const& a : alternatives ) {
            destroy += "        if _discriminator == " + cpp2::to_string(a.value) + " { std::destroy_at( reinterpret_cast<*" + cpp2::to_string(a.type) + ">(_storage&) ); }\n";
        }

        destroy += "        _discriminator = -1;\n"
                   "    }\n";
        CPP2_UFCS(add_member)(t, cpp2::move(destroy));
    }
}

    //  Add the destructor
#line 2428 "reflect.h2"
    CPP2_UFCS(add_member)(t, "    operator=: (move this) = { _destroy(); _ = this; }");

    //  Add default constructor
    CPP2_UFCS(add_member)(t, "    operator=: (out this) = { }");
{
std::string value_set{""};

    //  Add copy/move construction and assignment

#line 2435 "reflect.h2"
    {
        for ( 
              auto const& a : cpp2::move(alternatives) ) {
            value_set += "        if that.is_" + cpp2::to_string(a.name) + "() { set_" + cpp2::to_string(a.name) + "( that." + cpp2::to_string(a.name) + "() ); }\n";
        }
        value_set += "    }\n";

        CPP2_UFCS(add_member)(t, "    operator=: (out this, that) = {\n"
                      "        _storage = ();\n"
                      "        _discriminator = -1;\n" 
                      + value_set
                    );
        CPP2_UFCS(add_member)(t, "    operator=: (inout this, that) = {\n"
                      "        _storage = _;\n"
                      "        _discriminator = _;\n" 
                      + cpp2::move(value_set)
                    );
    }
}
#line 2453 "reflect.h2"
}

#line 2456 "reflect.h2"
//-----------------------------------------------------------------------
//
//  print - output a pretty-printed visualization of t
//
#line 2460 "reflect.h2"
auto print(cpp2::impl::in<meta::type_declaration> t) -> void
{
    std::cout << CPP2_UFCS(print)(t) << "\n";
}

#line 2466 "reflect.h2"
//-----------------------------------------------------------------------
//
//  noisy - make each function print its name and signature,
//          so the programmer can see what's called
//
#line 2471 "reflect.h2"
auto noisy(cpp2::impl::in<meta::type_declaration> t) -> void
{
    for ( 
         auto const& m : CPP2_UFCS(get_members)(t) ) 
    if ( CPP2_UFCS(is_function)(m) 
        && !(CPP2_UFCS(has_name)(m, "operator="))) 
    {
        auto mf {CPP2_UFCS(as_function)(m)}; 
        if (CPP2_UFCS(has_compound_body)(mf)) {
            auto body {CPP2_UFCS(get_compound_body)(mf)}; 
            CPP2_UFCS(add_statement)(body, "    std::cout << \"" + cpp2::to_string(CPP2_UFCS(get_signature)(cpp2::move(mf))) + "\\n\";");
            static_cast<void>(cpp2::move(body));
        }
    }
}

#line 2488 "reflect.h2"
//-----------------------------------------------------------------------
//
//  python - expose the type using pybind11
// 
//  *** Basic proof of concept only, limited and not well tested
//      Hardcoded for pybind11 and g++10 and my local cppfront include path
//
#line 2495 "reflect.h2"
[[nodiscard]] auto python_param_names_and_types(cpp2::impl::in<meta::function_declaration> mf) -> python_param_names_and_types_ret

#line 2501 "reflect.h2"
{
    std::string names {};
    std::string types {};
#line 2502 "reflect.h2"
    for ( 
         auto const& param : CPP2_UFCS(get_parameters)(mf) ) 
    if ( CPP2_UFCS(name)(CPP2_UFCS(get_declaration)(param)) != "this") 
    {
        names += ", ";
        if (!(CPP2_UFCS(empty)(types))) {
            types += ", ";
        }
        names += std::string("pybind11::arg(\"") + CPP2_UFCS(name)(CPP2_UFCS(get_declaration)(param)) + "\")";
        types += CPP2_UFCS(type)(CPP2_UFCS(get_declaration)(param));
    }return  { std::move(names), std::move(types) }; 
}

#line 2515 "reflect.h2"
auto python(meta::type_declaration& t) -> void
{
    std::string bind {}; 
    bind += "PYBIND11_MODULE(" + cpp2::to_string(CPP2_UFCS(name)(t)) + "lib, m) {\n";
    bind += "    pybind11::class_<" + cpp2::to_string(CPP2_UFCS(name)(t)) + ">(m, \"" + cpp2::to_string(CPP2_UFCS(name)(t)) + "\")\n";

    for ( 
         auto const& m : CPP2_UFCS(get_members)(t) ) 
    if ( CPP2_UFCS(is_function)(m)) 
    {
        auto mf {CPP2_UFCS(as_function)(m)}; 
        auto params {CPP2_UFCS(python_param_names_and_types)(mf)}; 

        if (CPP2_UFCS(is_constructor)(mf)) {
            bind += "        .def(pybind11::init<" + cpp2::to_string(cpp2::move(params).types) + ">())\n";
        }
        else {if (!(CPP2_UFCS(has_name)(mf, "operator="))) {
            bind += "        .def(\"" + cpp2::to_string(CPP2_UFCS(name)(mf)) + "\", &" + cpp2::to_string(CPP2_UFCS(name)(t)) + "::" + cpp2::to_string(CPP2_UFCS(name)(mf)) + " " + cpp2::to_string(cpp2::move(params).names) + ")\n";
        }}
    }

    bind += "    ;\n";
    bind += "}\n";

    auto file {CPP2_UFCS(filename)(t)}; 
    if (CPP2_UFCS(ends_with)(file, ".cpp2")) {
        file = CPP2_UFCS(substr)(file, 0, CPP2_UFCS(size)(file) - 5);// drop the ".cpp2"
    }
    std::string build {"g++-10 -O3 -shared -std=c++20 -fPIC $(python3 -m pybind11 --includes) " + cpp2::to_string(file) + ".cpp -o " + cpp2::to_string(file) + "lib$(python3-config --extension-suffix)"}; 

    CPP2_UFCS(add_runtime_support_include)(t, "pybind11/pybind11.h", true);
    CPP2_UFCS(add_runtime_support_include)(t, "pybind11/stl.h", true);
    CPP2_UFCS(add_extra_cpp1_code)(t, cpp2::move(bind));
    CPP2_UFCS(add_extra_build_step)(t, cpp2::move(build));
}

#line 2552 "reflect.h2"
//-----------------------------------------------------------------------
//
//  javascript - expose the type using emscripten
// 
//  *** Basic proof of concept only, limited and not well tested
//
#line 2558 "reflect.h2"
auto javascript(meta::type_declaration& t) -> void
{
    std::string bind {}; 
    bind += "using namespace emscripten;\n";
    bind += "EMSCRIPTEN_BINDINGS(" + cpp2::to_string(CPP2_UFCS(name)(t)) + "_module) {\n";
    bind += "    class_<" + cpp2::to_string(CPP2_UFCS(name)(t)) + ">(\"" + cpp2::to_string(CPP2_UFCS(name)(t)) + "\")\n";

    for ( 
         auto const& m : CPP2_UFCS(get_members)(t) ) 
    if ( CPP2_UFCS(is_function)(m)) 
    {
        auto mf {CPP2_UFCS(as_function)(m)}; 
        auto params {CPP2_UFCS(python_param_names_and_types)(mf)}; // good enough! only care about .types

        if (CPP2_UFCS(is_constructor)(mf)) {
            bind += "        .constructor<" + cpp2::to_string(cpp2::move(params).types) + ">()\n";
        }
        else {if (!(CPP2_UFCS(has_name)(mf, "operator="))) {
            bind += "        .function(\"" + cpp2::to_string(CPP2_UFCS(name)(mf)) + "\", &" + cpp2::to_string(CPP2_UFCS(name)(t)) + "::" + cpp2::to_string(CPP2_UFCS(name)(mf)) + ")\n";
        }}
    }

    bind += "    ;\n";
    bind += "}\n";

    auto file {CPP2_UFCS(filename)(t)}; 
    if (CPP2_UFCS(ends_with)(file, ".cpp2")) {
        file = CPP2_UFCS(substr)(file, 0, CPP2_UFCS(size)(file) - 5);// drop the ".cpp2"
    }
    std::string build {"em++ -std=c++20 -O3 " + cpp2::to_string(file) + ".cpp --bind -s MODULARIZE=1 -s ENVIRONMENT='web,node' -s ALLOW_MEMORY_GROWTH=1 -s FILESYSTEM=0 -s LEGACY_VM_SUPPORT=1 -o " + cpp2::to_string(file) + ".js"}; 
    CPP2_UFCS(add_runtime_support_include)(t, "emscripten/bind.h", true);
    CPP2_UFCS(add_extra_cpp1_code)(t, cpp2::move(bind));
    CPP2_UFCS(add_extra_build_step)(t, cpp2::move(build));
    CPP2_UFCS(disable_ref_qualifier_generation)(t);
}

#line 2595 "reflect.h2"
//-----------------------------------------------------------------------
//
//  For reflection test cases
//
#line 2599 "reflect.h2"
auto sample_print(cpp2::impl::in<std::string_view> s, cpp2::impl::in<cpp2::i32> indent) -> void
{
    std::cout 
        << pre(indent) 
        << s 
        << "\n";
}

#line 2609 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::declaration> decl) -> void{
        traverse(decl);
    }

#line 2613 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::declaration> decl) -> void
    {
        if (CPP2_UFCS(is_function)(decl)) {
            pre_traverse(CPP2_UFCS(as_function)(decl));
        }

        if (CPP2_UFCS(is_object)(decl)) {
            pre_traverse(CPP2_UFCS(as_object)(decl));
        }

        if (CPP2_UFCS(is_type)(decl)) {
            pre_traverse(CPP2_UFCS(as_type)(decl));
        }

        // ...
        // ... extend as desired to namespace, alias, etc.
        // ...
    }

#line 2633 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::function_declaration> f) -> void{
        traverse(f);
    }

#line 2637 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::function_declaration> f) -> void
    {
        auto parameters {CPP2_UFCS(get_parameters)(f)}; 
        for ( auto const& param : cpp2::move(parameters) ) {
            pre_traverse(param);
        }

        auto returns {CPP2_UFCS(get_returns)(f)}; 
        for ( auto const& param : cpp2::move(returns) ) {
            pre_traverse(param);
        }

        if (!(CPP2_UFCS(has_compound_body)(f))) {
            pre_traverse(CPP2_UFCS(get_body)(f));
        }
        else {
            pre_traverse(CPP2_UFCS(get_compound_body)(f));
        }
    }

#line 2658 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::object_declaration> o) -> void{
        traverse(o);
    }

#line 2662 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::object_declaration> o) -> void
    {
        if (CPP2_UFCS(has_initializer)(o)) {
            pre_traverse(CPP2_UFCS(get_initializer)(o));
        }
    }

#line 2670 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::type_declaration> t) -> void{
        traverse(t);
    }

#line 2674 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::type_declaration> t) -> void
    {
        for ( auto const& m : CPP2_UFCS(get_members)(t) ) {
            pre_traverse(m);
        }
    }

#line 2682 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::parameter_declaration> t) -> void{
        traverse(t);
    }

#line 2686 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::parameter_declaration> t) -> void
    {
        pre_traverse(CPP2_UFCS(get_declaration)(t));
    }

#line 2691 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::statement> stmt) -> void{
        traverse(stmt);
    }

#line 2695 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::statement> stmt) -> void
    {
        if (CPP2_UFCS(is_expression_statement)(stmt)) {
            pre_traverse(CPP2_UFCS(get_expression)(CPP2_UFCS(as_expression_statement)(stmt)));
        }

        if (CPP2_UFCS(is_compound_statement)(stmt)) {
            pre_traverse(CPP2_UFCS(as_compound_statement)(stmt));
        }

        if (CPP2_UFCS(is_selection_statement)(stmt)) 
        {
            pre_traverse(CPP2_UFCS(as_selection_statement)(stmt));
        }

        if (CPP2_UFCS(is_declaration)(stmt)) {
            pre_traverse(CPP2_UFCS(as_declaration)(stmt));
        }

        if (CPP2_UFCS(is_return_statement)(stmt)) {
            pre_traverse(CPP2_UFCS(as_return_statement)(stmt));
        }

        if (CPP2_UFCS(is_iteration_statement)(stmt)) {
            pre_traverse(CPP2_UFCS(as_iteration_statement)(stmt));
        }

        // TODO:
        //  using
        //  contract
        //  inspect
        //  jump
    }

#line 2730 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::compound_statement> stmt) -> void{
        traverse(stmt);
    }

#line 2734 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::compound_statement> stmt) -> void
    {
        auto stmts {CPP2_UFCS(get_statements)(stmt)}; 

        for ( auto const& cur : cpp2::move(stmts) ) {
            pre_traverse(cur);
        }
    }

#line 2744 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::return_statement> stmt) -> void{
        traverse(stmt);
    }

#line 2748 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::return_statement> stmt) -> void
    {
        if (CPP2_UFCS(has_expression)(stmt)) {
            pre_traverse(CPP2_UFCS(get_expression)(stmt));
        }
    }

#line 2756 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::iteration_statement> stmt) -> void{
        traverse(stmt);
    }

#line 2760 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::iteration_statement> stmt) -> void
    {
        if (CPP2_UFCS(is_do)(stmt) || CPP2_UFCS(is_while)(stmt)) {
            pre_traverse(CPP2_UFCS(get_do_while_condition)(stmt));
            pre_traverse(CPP2_UFCS(get_do_while_body)(stmt));
        }
        else {
            if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(is_for)(stmt)) ) { cpp2::cpp2_default.report_violation(""); }
            pre_traverse(CPP2_UFCS(get_for_range)(stmt));
            pre_traverse(CPP2_UFCS(get_for_parameter)(stmt));
            pre_traverse(CPP2_UFCS(get_for_body)(stmt));
        }

        if (CPP2_UFCS(has_next)(stmt)) {
            pre_traverse(CPP2_UFCS(get_next_expression)(stmt));
        }
    }

#line 2779 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::selection_statement> stmt) -> void{
        traverse(stmt);
    }

#line 2783 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::selection_statement> stmt) -> void
    {
        pre_traverse(CPP2_UFCS(get_expression)(stmt));
        pre_traverse(CPP2_UFCS(get_true_branch)(stmt));

        if (CPP2_UFCS(has_false_branch)(stmt)) {
            pre_traverse(CPP2_UFCS(get_false_branch)(stmt));
        }
    }

#line 2794 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::expression> expr) -> void
    {
        // Nothing to select here.
        traverse(expr);
    }

#line 2800 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::expression> expr) -> void
    {
        //  An expression has other shortcuts to query deeper properties,
        //  but let's just traverse all the nested grammer elements to
        //  show how that traversal works

        // The expressions use the pre_traverse function to decide which expression
        // they are. The correct one calls traverse only once.

        //  The expression's basic payload is just an assignment expression
        pre_traverse(CPP2_UFCS(as_assignment_expression)(expr));
    }

#line 2814 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::assignment_expression> binexpr) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 
        if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(terms))) ) { cpp2::cpp2_default.report_violation(""); }

        //  If this has only one term, it's not an actual assignment,
        //  it's holding a lower grammar production so go traverse that
        if (CPP2_UFCS(ssize)(terms) == 1) {
            pre_traverse(CPP2_UFCS(get_term)(CPP2_UFCS(front)(cpp2::move(terms))));
        }

        //  Else we're at an actual binary expression with a rhs
        else {
            traverse(binexpr);
        }
    }

#line 2831 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::assignment_expression> binexpr) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 

        for ( 
             auto const& term : cpp2::move(terms) ) 
        {
            traverse(CPP2_UFCS(get_term)(term));
        }
    }

#line 2842 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::logical_or_expression> binexpr) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 
        if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(terms))) ) { cpp2::cpp2_default.report_violation(""); }

        //  If this has only one term, it's not an actual logical-or,
        //  it's holding a lower grammar production so go traverse that
        if (CPP2_UFCS(ssize)(terms) == 1) {
            pre_traverse(CPP2_UFCS(get_term)(CPP2_UFCS(front)(cpp2::move(terms))));
        }

        //  Else we're at an actual binary expression with a rhs
        else {
            traverse(binexpr);
        }
    }

#line 2859 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::logical_or_expression> binexpr) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 

        for ( 
             auto const& term : cpp2::move(terms) ) 
        {
            traverse(CPP2_UFCS(get_term)(term));
        }
    }

#line 2871 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::logical_and_expression> binexpr) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 
        if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(terms))) ) { cpp2::cpp2_default.report_violation(""); }

        //  If this has only one term, it's not an actual logical-and,
        //  it's holding a lower grammar production so go traverse that
        if (CPP2_UFCS(ssize)(terms) == 1) {
            pre_traverse(CPP2_UFCS(get_term)(CPP2_UFCS(front)(cpp2::move(terms))));
        }

        //  Else we're at an actual binary expression with a rhs
        else {
            traverse(binexpr);
        }
    }

#line 2888 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::logical_and_expression> binexpr) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 

        for ( 
             auto const& term : cpp2::move(terms) ) 
        {
            traverse(CPP2_UFCS(get_term)(term));
        }
    }

#line 2899 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::bit_or_expression> binexpr) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 
        if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(terms))) ) { cpp2::cpp2_default.report_violation(""); }

        //  If this has only one term, it's not an actual bit-or,
        //  it's holding a lower grammar production so go traverse that
        if (CPP2_UFCS(ssize)(terms) == 1) {
            pre_traverse(CPP2_UFCS(get_term)(CPP2_UFCS(front)(cpp2::move(terms))));
        }

        //  Else we're at an actual binary expression with a rhs
        else {
            traverse(binexpr);
        }
    }

#line 2916 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::bit_or_expression> binexpr) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 

        for ( 
             auto const& term : cpp2::move(terms) ) 
        {
            traverse(CPP2_UFCS(get_term)(term));
        }
    }

#line 2927 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::bit_xor_expression> binexpr) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 
        if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(terms))) ) { cpp2::cpp2_default.report_violation(""); }

        //  If this has only one term, it's not an actual bit-xor,
        //  it's holding a lower grammar production so go traverse that
        if (CPP2_UFCS(ssize)(terms) == 1) {
            pre_traverse(CPP2_UFCS(get_term)(CPP2_UFCS(front)(cpp2::move(terms))));
        }

        //  Else we're at an actual binary expression with a rhs
        else {
            traverse(binexpr);
        }
    }

#line 2944 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::bit_xor_expression> binexpr) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 

        for ( 
             auto const& term : cpp2::move(terms) ) 
        {
            traverse(CPP2_UFCS(get_term)(term));
        }
    }

#line 2956 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::bit_and_expression> binexpr) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 
        if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(terms))) ) { cpp2::cpp2_default.report_violation(""); }

        //  If this has only one term, it's not an actual bit-and,
        //  it's holding a lower grammar production so go traverse that
        if (CPP2_UFCS(ssize)(terms) == 1) {
            pre_traverse(CPP2_UFCS(get_term)(CPP2_UFCS(front)(cpp2::move(terms))));
        }

        //  Else we're at an actual binary expression with a rhs
        else {
            traverse(binexpr);
        }
    }

#line 2973 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::bit_and_expression> binexpr) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 

        for ( 
             auto const& term : cpp2::move(terms) ) 
        {
            traverse(CPP2_UFCS(get_term)(term));
        }
    }

#line 2985 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::equality_expression> binexpr) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 
        if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(terms))) ) { cpp2::cpp2_default.report_violation(""); }

        //  If this has only one term, it's not an actual equality,
        //  it's holding a lower grammar production so go traverse that
        if (CPP2_UFCS(ssize)(terms) == 1) {
            pre_traverse(CPP2_UFCS(get_term)(CPP2_UFCS(front)(cpp2::move(terms))));
        }

        //  Else we're at an actual binary expression with a rhs
        else {
            traverse(binexpr);
        }
    }

#line 3002 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::equality_expression> binexpr) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 

        for ( 
             auto const& term : cpp2::move(terms) ) 
        {
            traverse(CPP2_UFCS(get_term)(term));
        }
    }

#line 3013 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::relational_expression> binexpr) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 
        if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(terms))) ) { cpp2::cpp2_default.report_violation(""); }

        //  If this has only one term, it's not an actual relational,
        //  it's holding a lower grammar production so go traverse that
        if (CPP2_UFCS(ssize)(terms) == 1) {
            pre_traverse(CPP2_UFCS(get_term)(CPP2_UFCS(front)(cpp2::move(terms))));
        }

        //  Else we're at an actual binary expression with a rhs
        else {
            traverse(binexpr);
        }
    }

#line 3030 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::relational_expression> binexpr) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 

        for ( 
             auto const& term : cpp2::move(terms) ) 
        {
            traverse(CPP2_UFCS(get_term)(term));
        }
    }

#line 3041 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::compare_expression> binexpr) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 
        if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(terms))) ) { cpp2::cpp2_default.report_violation(""); }

        //  If this has only one term, it's not an actual compare,
        //  it's holding a lower grammar production so go traverse that
        if (CPP2_UFCS(ssize)(terms) == 1) {
            pre_traverse(CPP2_UFCS(get_term)(CPP2_UFCS(front)(cpp2::move(terms))));
        }

        //  Else we're at an actual binary expression with a rhs
        else {
            traverse(binexpr);
        }
    }

#line 3058 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::compare_expression> binexpr) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 

        for ( 
             auto const& term : cpp2::move(terms) ) 
        {
            traverse(CPP2_UFCS(get_term)(term));
        }
    }

#line 3069 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::shift_expression> binexpr) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 
        if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(terms))) ) { cpp2::cpp2_default.report_violation(""); }

        //  If this has only one term, it's not an actual shift,
        //  it's holding a lower grammar production so go traverse that
        if (CPP2_UFCS(ssize)(terms) == 1) {
            pre_traverse(CPP2_UFCS(get_term)(CPP2_UFCS(front)(cpp2::move(terms))));
        }

        //  Else we're at an actual binary expression with a rhs
        else {
            traverse(binexpr);
        }
    }

#line 3086 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::shift_expression> binexpr) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 

        for ( 
             auto const& term : cpp2::move(terms) ) 
        {
            traverse(CPP2_UFCS(get_term)(term));
        }
    }

#line 3097 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::additive_expression> binexpr) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 
        if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(terms))) ) { cpp2::cpp2_default.report_violation(""); }

        //  If this has only one term, it's not an actual additive,
        //  it's holding a lower grammar production so go traverse that
        if (CPP2_UFCS(ssize)(terms) == 1) {
            pre_traverse(CPP2_UFCS(get_term)(CPP2_UFCS(front)(cpp2::move(terms))));
        }

        //  Else we're at an actual binary expression with a rhs
        else {
            traverse(binexpr);
        }
    }

#line 3114 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::additive_expression> binexpr) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 

        for ( 
             auto const& term : cpp2::move(terms) ) 
        {
            traverse(CPP2_UFCS(get_term)(term));
        }
    }

#line 3126 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::multiplicative_expression> binexpr) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 
        if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(terms))) ) { cpp2::cpp2_default.report_violation(""); }

        //  If this has only one term, it's not an actual multiplicative,
        //  it's holding a lower grammar production so go traverse that
        if (CPP2_UFCS(ssize)(terms) == 1) {
            pre_traverse(CPP2_UFCS(get_term)(CPP2_UFCS(front)(cpp2::move(terms))));
        }

        //  Else we're at an actual binary expression with a rhs
        else {
            traverse(binexpr);
        }
    }

#line 3143 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::multiplicative_expression> binexpr) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 

        for ( 
             auto const& term : cpp2::move(terms) ) 
        {
            traverse(CPP2_UFCS(get_term)(term));
        }
    }

#line 3154 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::is_as_expression> isas) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(isas)}; 

        //  If this has no additional terms, it's not an actual is-as,
        //  it's holding a lower grammar production so go traverse that
        if (CPP2_UFCS(empty)(cpp2::move(terms))) {
            pre_traverse(CPP2_UFCS(get_expression)(isas));
        }

        //  Else we're at an actual is-as expression with a rhs
        else {
            traverse(isas);
        }
    }

#line 3170 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::is_as_expression> isas) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(isas)}; 

        pre_traverse(CPP2_UFCS(get_expression)(isas));

        for ( auto const& term : cpp2::move(terms) ) {
            traverse(CPP2_UFCS(get_expr)(term));
        }
    }

#line 3181 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::expression_list> exprs) -> void
    {
        for ( auto const& expr : CPP2_UFCS(get_expressions)(exprs) ) {
            traverse(expr);
        }
    }

#line 3188 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::prefix_expression> prefix) -> void
    {
        auto ops {CPP2_UFCS(get_ops)(prefix)}; 

        //  If this has no additional ops, it's not a naked prefix expr,
        //  it's holding a lower grammar production so go traverse that
        if (CPP2_UFCS(empty)(cpp2::move(ops))) {
            pre_traverse(CPP2_UFCS(get_postfix_expression)(prefix));
        }

        //  Else we're at an actual prefix expression with ops
        else {
            traverse(prefix);
        }
    }

#line 3204 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::prefix_expression> prefix) -> void
    {
        pre_traverse(CPP2_UFCS(get_postfix_expression)(prefix));
    }

#line 3209 "reflect.h2"
    auto simple_traverser::pre_traverse(cpp2::impl::in<meta::postfix_expression> postfix) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(postfix)}; 

        //  If this has no additional terms, it's not a naked postfix expr,
        //  it's holding a lower grammar production so go traverse that
        if (CPP2_UFCS(empty)(cpp2::move(terms))) {
            traverse(CPP2_UFCS(get_primary_expression)(postfix));
        }

        //  Else we're at an actual postfix expression with ops
        else {
            traverse(postfix);
        }
    }

#line 3225 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::postfix_expression> postfix) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(postfix)}; 

        traverse(CPP2_UFCS(get_primary_expression)(postfix));

        for ( auto const& term : cpp2::move(terms) ) {
            if (CPP2_UFCS(is_id_expression)(term)) {
                traverse(CPP2_UFCS(get_id_expression)(term));
            }
            else {if (CPP2_UFCS(is_expression_list)(term)) {
                traverse(CPP2_UFCS(get_expression_list)(term));
            }
            else {if (CPP2_UFCS(is_expression)(term)) {
                traverse(CPP2_UFCS(get_expression)(term));
            }}}
        }
    }

#line 3244 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::unqualified_id> uid) -> void
    {
        static_cast<void>(uid);
    }

#line 3250 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::qualified_id> qid) -> void
    {
        for ( 
             auto const& term : CPP2_UFCS(get_terms)(qid) ) 
        {
            traverse(CPP2_UFCS(get_unqualified)(term));
        }
    }

#line 3260 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::type_id> tid) -> void
    {
        if (CPP2_UFCS(is_postfix_expression)(tid)) {
            traverse(CPP2_UFCS(as_postfix_expression)(tid));
        }
        else {if (CPP2_UFCS(is_qualified_id)(tid)) {
            traverse(CPP2_UFCS(as_qualified_id)(tid));
        }
        else {if (CPP2_UFCS(is_unqualified_id)(tid)) {
            traverse(CPP2_UFCS(as_unqualified_id)(tid));
        }
        else {
            // Regular type_id
        }}}
    }

#line 3277 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::primary_expression> primary) -> void
    {
        if (CPP2_UFCS(is_identifier)(primary)) {
            // Regular identifier
        }
        else {if (CPP2_UFCS(is_expression_list)(primary)) {
            traverse(CPP2_UFCS(as_expression_list)(primary));
        }
        else {if (CPP2_UFCS(is_literal)(primary)) {
            // Regular literal
        }
        else {if (CPP2_UFCS(is_declaration)(primary)) {
            // TODO: traverse(primary.as_declaration());
        }
        else {
            // Regular primary
        }}}}
    }

#line 3297 "reflect.h2"
    auto simple_traverser::traverse(cpp2::impl::in<meta::id_expression> idexpr) -> void
    {
        if (CPP2_UFCS(is_identifier)(idexpr)) {
            // Regular id
        }
        else {if (CPP2_UFCS(is_qualified)(idexpr)) {
            traverse(CPP2_UFCS(as_qualified)(idexpr));
        }
        else {if (CPP2_UFCS(is_unqualified)(idexpr)) {
            traverse(CPP2_UFCS(as_unqualified)(idexpr));
        }
        else {
            // Regular id expr
        }}}
    }

#line 3315 "reflect.h2"
//-----------------------------------------------------------------------
//
//  sample_traverser serves two purposes:
// 
//      - infrastructure for writing reflection API test cases
// 
//      - a sample for how code can use the reflection API, notably
//        for reflecting on function bodies (statements, expressions)
//

#line 3325 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::declaration> decl, cpp2::impl::in<cpp2::i32> indent) -> void
{
    sample_print("Declaration: " + cpp2::to_string(CPP2_UFCS(name)(decl)) + "", indent);

    if (CPP2_UFCS(is_function)(decl)) {
        sample_traverser(CPP2_UFCS(as_function)(decl), indent + 1);
    }

    if (CPP2_UFCS(is_object)(decl)) {
        sample_traverser(CPP2_UFCS(as_object)(decl), indent + 1);
    }

    if (CPP2_UFCS(is_type)(decl)) {
        sample_traverser(CPP2_UFCS(as_type)(decl), indent + 1);
    }

    // ...
    // ... extend as desired to namespace, alias, etc.
    // ...
}

#line 3347 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::function_declaration> f, cpp2::impl::in<cpp2::i32> indent) -> void
{
    sample_print("Function: " + cpp2::to_string(CPP2_UFCS(name)(f)) + "", indent + 1);

    auto parameters {CPP2_UFCS(get_parameters)(f)}; 
    if (!(CPP2_UFCS(empty)(parameters))) {
        sample_print("Parameters:", indent + 2);
        for ( auto const& param : cpp2::move(parameters) ) {
            sample_traverser(param, indent + 3);
        }
    }

    auto returns {CPP2_UFCS(get_returns)(f)}; 
    if (!(CPP2_UFCS(empty)(returns))) {
        sample_print("Returns:", indent + 2);
        for ( auto const& param : cpp2::move(returns) ) {
            sample_traverser(param, indent + 3);
        }
    }

    sample_print("Body:", indent + 2);
    if (!(CPP2_UFCS(has_compound_body)(f))) {
        sample_traverser(CPP2_UFCS(get_body)(f), indent + 3);
    }
    else {
        sample_traverser(CPP2_UFCS(get_compound_body)(f), indent + 3);
    }
}

#line 3377 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::object_declaration> o, cpp2::impl::in<cpp2::i32> indent) -> void
{
    sample_print("Object: name " + cpp2::to_string(CPP2_UFCS(name)(o)) + ", type " + cpp2::to_string(CPP2_UFCS(type)(o)) + "", indent);
    if (CPP2_UFCS(has_initializer)(o)) {
        sample_print("Initializer:", indent + 1);
        sample_traverser(CPP2_UFCS(get_initializer)(o), indent + 2);
    }
}

#line 3387 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::type_declaration> t, cpp2::impl::in<cpp2::i32> indent) -> void
{
    sample_print("Type: " + cpp2::to_string(CPP2_UFCS(name)(t)) + "", indent);

    if (CPP2_UFCS(parent_is_nonglobal_namespace)(t)) 
    {
        auto ns {CPP2_UFCS(as_nonglobal_namespace)(CPP2_UFCS(get_parent)(t))}; 
        sample_print("is a member of namespace " + cpp2::to_string(CPP2_UFCS(name)(ns)) + " which contains the following names:", indent + 1);
        for ( auto const& m : CPP2_UFCS(get_members)(ns) ) {
            sample_print(CPP2_UFCS(name)(m), indent + 2);
        }
        CPP2_UFCS(add_member)(ns, "add_1: (x) = x+1;");
        static_cast<void>(cpp2::move(ns));
    }

    for ( auto const& m : CPP2_UFCS(get_members)(t) ) {
        sample_traverser(m, indent + 1);
    }
}

#line 3408 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::parameter_declaration> t, cpp2::impl::in<cpp2::i32> indent) -> void
{
    sample_print("parameter:", indent);

    auto pass {CPP2_UFCS(get_passing_style)(t)}; 
    if (pass == passing_style::in)          { sample_print("passing style: in", indent + 1);}
    if (pass == passing_style::in_ref)      { sample_print("passing style: in_ref", indent + 1);}
    if (pass == passing_style::copy)        { sample_print("passing style: copy", indent + 1);}
    if (pass == passing_style::inout)       { sample_print("passing style: inout", indent + 1);}
    if (pass == passing_style::out)         { sample_print("passing style: out", indent + 1);}
    if (pass == passing_style::move)        { sample_print("passing style: move", indent + 1);}
    if (pass == passing_style::forward)     { sample_print("passing style: forward", indent + 1);}
    if (cpp2::move(pass) == passing_style::forward_ref) {sample_print("passing style: forward_ref", indent + 1); }

    sample_print("declaration:", indent + 1);
    sample_traverser(CPP2_UFCS(get_declaration)(t), indent + 2);
}

#line 3427 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::statement> stmt, cpp2::impl::in<cpp2::i32> indent) -> void
{
    if (CPP2_UFCS(is_expression_statement)(stmt)) {
        sample_traverser(CPP2_UFCS(get_expression)(CPP2_UFCS(as_expression_statement)(stmt)), indent);
    }

    if (CPP2_UFCS(is_compound_statement)(stmt)) {
        sample_traverser(CPP2_UFCS(as_compound_statement)(stmt), indent);
    }

    if (CPP2_UFCS(is_selection_statement)(stmt)) 
    {
        auto sel {CPP2_UFCS(as_selection_statement)(stmt)}; 
        sample_print("" + cpp2::to_string(CPP2_UFCS(get_identifier)(sel)) + " statement", indent);

        sample_print("condition:", indent + 1);
        sample_traverser(CPP2_UFCS(get_expression)(sel), indent + 2);

        sample_print("true branch:", indent + 1);
        sample_traverser(CPP2_UFCS(get_true_branch)(sel), indent + 2);

        if (CPP2_UFCS(has_false_branch)(sel)) {
            sample_print("false branch:", indent + 1);
            sample_traverser(CPP2_UFCS(get_false_branch)(cpp2::move(sel)), indent + 2);
        }
    }

    if (CPP2_UFCS(is_declaration)(stmt)) {
        sample_traverser(CPP2_UFCS(as_declaration)(stmt), indent + 1);
    }

    if (CPP2_UFCS(is_return_statement)(stmt)) {
        sample_traverser(CPP2_UFCS(as_return_statement)(stmt), indent + 1);
    }

    if (CPP2_UFCS(is_iteration_statement)(stmt)) {
        sample_traverser(CPP2_UFCS(as_iteration_statement)(stmt), indent + 1);
    }

    // TODO:
    //  using
    //  contract
    //  inspect
    //  jump
}

#line 3474 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::compound_statement> stmt, cpp2::impl::in<cpp2::i32> indent) -> void
{
    auto stmts {CPP2_UFCS(get_statements)(stmt)}; 

    if (CPP2_UFCS(empty)(stmts)) {
        sample_print("compound statement (empty)", indent);
        return ; 
    }

    // Else
    sample_print("compound statement", indent);
    for ( auto const& stmt2 : cpp2::move(stmts) ) {
        sample_traverser(stmt2, indent + 1);
    }
}

#line 3491 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::return_statement> stmt, cpp2::impl::in<cpp2::i32> indent) -> void
{
    sample_print("return statement", indent);
    if (CPP2_UFCS(has_expression)(stmt)) {
        sample_print("expression", indent + 1);
        sample_traverser(CPP2_UFCS(get_expression)(stmt), indent + 2);
    }
}

#line 3501 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::iteration_statement> stmt, cpp2::impl::in<cpp2::i32> indent) -> void
{
    if (CPP2_UFCS(is_do)(stmt) || CPP2_UFCS(is_while)(stmt)) {
        if (CPP2_UFCS(is_do)(stmt)) {
            sample_print("do loop:", indent);
        }
        else {
            sample_print("while loop:", indent);
        }
        sample_print("condition:", indent + 1);
        sample_traverser(CPP2_UFCS(get_do_while_condition)(stmt), indent + 2);
        sample_print("body:", indent + 1);
        sample_traverser(CPP2_UFCS(get_do_while_body)(stmt), indent + 2);
    }
    else {
        if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(is_for)(stmt)) ) { cpp2::cpp2_default.report_violation(""); }
        sample_print("for loop:", indent);
        sample_print("range:", indent + 1);
        sample_traverser(CPP2_UFCS(get_for_range)(stmt), indent + 2);
        sample_print("parameter:", indent + 1);
        sample_traverser(CPP2_UFCS(get_for_parameter)(stmt), indent + 2);
        sample_print("body:", indent + 1);
        sample_traverser(CPP2_UFCS(get_for_body)(stmt), indent + 2);
    }

    if (CPP2_UFCS(has_next)(stmt)) {
        sample_print("next expression:", indent + 1);
        sample_traverser(CPP2_UFCS(get_next_expression)(stmt), indent + 2);
    }
}

#line 3533 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::expression> expr, cpp2::impl::in<cpp2::i32> indent) -> void
{
    //  An expression has other shortcuts to query deeper properties,
    //  but let's just traverse all the nested grammar elements to
    //  show how that traversal works

    //  The expression's basic payload is just an assignment expression
    //  today - this can change when we add try-expressions
    if (CPP2_UFCS(is_assignment_expression)(expr)) {
        sample_traverser(CPP2_UFCS(as_assignment_expression)(expr), indent);
    }
}

#line 3547 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::assignment_expression> binexpr, cpp2::impl::in<cpp2::i32> indent) -> void
{
    auto terms {CPP2_UFCS(get_terms)(binexpr)}; 
    if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(terms))) ) { cpp2::cpp2_default.report_violation(""); }

    //  If this has only one term, it's not an actual assignment,
    //  it's holding a lower grammar production so go traverse that
    if (CPP2_UFCS(ssize)(terms) == 1) {
        sample_traverser(CPP2_UFCS(get_term)(CPP2_UFCS(front)(cpp2::move(terms))), indent);
    }

    //  Else we're at an actual binary expression with a rhs
    else {
        sample_print("assignment", indent);
{
auto first{true};

#line 3563 "reflect.h2"
        for ( 
             auto const& term : cpp2::move(terms) ) 
        {
            if (!(first)) {
                sample_print("op: " + cpp2::to_string(CPP2_UFCS(get_op)(term)) + "", indent + 1);
            }
            first = false;
            sample_print("term:", indent + 1);
            sample_traverser(CPP2_UFCS(get_term)(term), indent + 2);
        }
}
#line 3573 "reflect.h2"
    }
}

#line 3577 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::logical_or_expression> binexpr, cpp2::impl::in<cpp2::i32> indent) -> void
{
    auto terms {CPP2_UFCS(get_terms)(binexpr)}; 
    if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(terms))) ) { cpp2::cpp2_default.report_violation(""); }

    //  If this has only one term, it's not an actual logical-or,
    //  it's holding a lower grammar production so go traverse that
    if (CPP2_UFCS(ssize)(terms) == 1) {
        sample_traverser(CPP2_UFCS(get_term)(CPP2_UFCS(front)(cpp2::move(terms))), indent);
    }

    //  Else we're at an actual binary expression with a rhs
    else {
        sample_print("logical-or", indent);
{
auto first{true};

#line 3593 "reflect.h2"
        for ( 
             auto const& term : cpp2::move(terms) ) 
        {
            if (!(first)) {
                sample_print("op: " + cpp2::to_string(CPP2_UFCS(get_op)(term)) + "", indent + 1);
            }
            first = false;
            sample_print("term:", indent + 1);
            sample_traverser(CPP2_UFCS(get_term)(term), indent + 2);
        }
}
#line 3603 "reflect.h2"
    }
}

#line 3607 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::logical_and_expression> binexpr, cpp2::impl::in<cpp2::i32> indent) -> void
{
    auto terms {CPP2_UFCS(get_terms)(binexpr)}; 
    if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(terms))) ) { cpp2::cpp2_default.report_violation(""); }

    //  If this has only one term, it's not an actual logical-and,
    //  it's holding a lower grammar production so go traverse that
    if (CPP2_UFCS(ssize)(terms) == 1) {
        sample_traverser(CPP2_UFCS(get_term)(CPP2_UFCS(front)(cpp2::move(terms))), indent);
    }

    //  Else we're at an actual binary expression with a rhs
    else {
        sample_print("logical-and", indent);
{
auto first{true};

#line 3623 "reflect.h2"
        for ( 
             auto const& term : cpp2::move(terms) ) 
        {
            if (!(first)) {
                sample_print("op: " + cpp2::to_string(CPP2_UFCS(get_op)(term)) + "", indent + 1);
            }
            first = false;
            sample_print("term:", indent + 1);
            sample_traverser(CPP2_UFCS(get_term)(term), indent + 2);
        }
}
#line 3633 "reflect.h2"
    }
}

#line 3637 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::bit_or_expression> binexpr, cpp2::impl::in<cpp2::i32> indent) -> void
{
    auto terms {CPP2_UFCS(get_terms)(binexpr)}; 
    if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(terms))) ) { cpp2::cpp2_default.report_violation(""); }

    //  If this has only one term, it's not an actual bit-or,
    //  it's holding a lower grammar production so go traverse that
    if (CPP2_UFCS(ssize)(terms) == 1) {
        sample_traverser(CPP2_UFCS(get_term)(CPP2_UFCS(front)(cpp2::move(terms))), indent);
    }

    //  Else we're at an actual binary expression with a rhs
    else {
        sample_print("bit-or", indent);
{
auto first{true};

#line 3653 "reflect.h2"
        for ( 
             auto const& term : cpp2::move(terms) ) 
        {
            if (!(first)) {
                sample_print("op: " + cpp2::to_string(CPP2_UFCS(get_op)(term)) + "", indent + 1);
            }
            first = false;
            sample_print("term:", indent + 1);
            sample_traverser(CPP2_UFCS(get_term)(term), indent + 2);
        }
}
#line 3663 "reflect.h2"
    }
}

#line 3667 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::bit_xor_expression> binexpr, cpp2::impl::in<cpp2::i32> indent) -> void
{
    auto terms {CPP2_UFCS(get_terms)(binexpr)}; 
    if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(terms))) ) { cpp2::cpp2_default.report_violation(""); }

    //  If this has only one term, it's not an actual bit-xor,
    //  it's holding a lower grammar production so go traverse that
    if (CPP2_UFCS(ssize)(terms) == 1) {
        sample_traverser(CPP2_UFCS(get_term)(CPP2_UFCS(front)(cpp2::move(terms))), indent);
    }

    //  Else we're at an actual binary expression with a rhs
    else {
        sample_print("bit-xor", indent);
{
auto first{true};

#line 3683 "reflect.h2"
        for ( 
             auto const& term : cpp2::move(terms) ) 
        {
            if (!(first)) {
                sample_print("op: " + cpp2::to_string(CPP2_UFCS(get_op)(term)) + "", indent + 1);
            }
            first = false;
            sample_print("term:", indent + 1);
            sample_traverser(CPP2_UFCS(get_term)(term), indent + 2);
        }
}
#line 3693 "reflect.h2"
    }
}

#line 3697 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::bit_and_expression> binexpr, cpp2::impl::in<cpp2::i32> indent) -> void
{
    auto terms {CPP2_UFCS(get_terms)(binexpr)}; 
    if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(terms))) ) { cpp2::cpp2_default.report_violation(""); }

    //  If this has only one term, it's not an actual bit-and,
    //  it's holding a lower grammar production so go traverse that
    if (CPP2_UFCS(ssize)(terms) == 1) {
        sample_traverser(CPP2_UFCS(get_term)(CPP2_UFCS(front)(cpp2::move(terms))), indent);
    }

    //  Else we're at an actual binary expression with a rhs
    else {
        sample_print("bit-and", indent);
{
auto first{true};

#line 3713 "reflect.h2"
        for ( 
             auto const& term : cpp2::move(terms) ) 
        {
            if (!(first)) {
                sample_print("op: " + cpp2::to_string(CPP2_UFCS(get_op)(term)) + "", indent + 1);
            }
            first = false;
            sample_print("term:", indent + 1);
            sample_traverser(CPP2_UFCS(get_term)(term), indent + 2);
        }
}
#line 3723 "reflect.h2"
    }
}

#line 3727 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::equality_expression> binexpr, cpp2::impl::in<cpp2::i32> indent) -> void
{
    auto terms {CPP2_UFCS(get_terms)(binexpr)}; 
    if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(terms))) ) { cpp2::cpp2_default.report_violation(""); }

    //  If this has only one term, it's not an actual equality,
    //  it's holding a lower grammar production so go traverse that
    if (CPP2_UFCS(ssize)(terms) == 1) {
        sample_traverser(CPP2_UFCS(get_term)(CPP2_UFCS(front)(cpp2::move(terms))), indent);
    }

    //  Else we're at an actual binary expression with a rhs
    else {
        sample_print("equality", indent);
{
auto first{true};

#line 3743 "reflect.h2"
        for ( 
             auto const& term : cpp2::move(terms) ) 
        {
            if (!(first)) {
                sample_print("op: " + cpp2::to_string(CPP2_UFCS(get_op)(term)) + "", indent + 1);
            }
            first = false;
            sample_print("term:", indent + 1);
            sample_traverser(CPP2_UFCS(get_term)(term), indent + 2);
        }
}
#line 3753 "reflect.h2"
    }
}

#line 3757 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::relational_expression> binexpr, cpp2::impl::in<cpp2::i32> indent) -> void
{
    auto terms {CPP2_UFCS(get_terms)(binexpr)}; 
    if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(terms))) ) { cpp2::cpp2_default.report_violation(""); }

    //  If this has only one term, it's not an actual relational,
    //  it's holding a lower grammar production so go traverse that
    if (CPP2_UFCS(ssize)(terms) == 1) {
        sample_traverser(CPP2_UFCS(get_term)(CPP2_UFCS(front)(cpp2::move(terms))), indent);
    }

    //  Else we're at an actual binary expression with a rhs
    else {
        sample_print("relational", indent);
{
auto first{true};

#line 3773 "reflect.h2"
        for ( 
             auto const& term : cpp2::move(terms) ) 
        {
            if (!(first)) {
                sample_print("op: " + cpp2::to_string(CPP2_UFCS(get_op)(term)) + "", indent + 1);
            }
            first = false;
            sample_print("term:", indent + 1);
            sample_traverser(CPP2_UFCS(get_term)(term), indent + 2);
        }
}
#line 3783 "reflect.h2"
    }
}

#line 3787 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::compare_expression> binexpr, cpp2::impl::in<cpp2::i32> indent) -> void
{
    auto terms {CPP2_UFCS(get_terms)(binexpr)}; 
    if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(terms))) ) { cpp2::cpp2_default.report_violation(""); }

    //  If this has only one term, it's not an actual compare,
    //  it's holding a lower grammar production so go traverse that
    if (CPP2_UFCS(ssize)(terms) == 1) {
        sample_traverser(CPP2_UFCS(get_term)(CPP2_UFCS(front)(cpp2::move(terms))), indent);
    }

    //  Else we're at an actual binary expression with a rhs
    else {
        sample_print("compare", indent);
{
auto first{true};

#line 3803 "reflect.h2"
        for ( 
             auto const& term : cpp2::move(terms) ) 
        {
            if (!(first)) {
                sample_print("op: " + cpp2::to_string(CPP2_UFCS(get_op)(term)) + "", indent + 1);
            }
            first = false;
            sample_print("term:", indent + 1);
            sample_traverser(CPP2_UFCS(get_term)(term), indent + 2);
        }
}
#line 3813 "reflect.h2"
    }
}

#line 3817 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::shift_expression> binexpr, cpp2::impl::in<cpp2::i32> indent) -> void
{
    auto terms {CPP2_UFCS(get_terms)(binexpr)}; 
    if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(terms))) ) { cpp2::cpp2_default.report_violation(""); }

    //  If this has only one term, it's not an actual shift,
    //  it's holding a lower grammar production so go traverse that
    if (CPP2_UFCS(ssize)(terms) == 1) {
        sample_traverser(CPP2_UFCS(get_term)(CPP2_UFCS(front)(cpp2::move(terms))), indent);
    }

    //  Else we're at an actual binary expression with a rhs
    else {
        sample_print("shift", indent);
{
auto first{true};

#line 3833 "reflect.h2"
        for ( 
             auto const& term : cpp2::move(terms) ) 
        {
            if (!(first)) {
                sample_print("op: " + cpp2::to_string(CPP2_UFCS(get_op)(term)) + "", indent + 1);
            }
            first = false;
            sample_print("term:", indent + 1);
            sample_traverser(CPP2_UFCS(get_term)(term), indent + 2);
        }
}
#line 3843 "reflect.h2"
    }
}

#line 3847 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::additive_expression> binexpr, cpp2::impl::in<cpp2::i32> indent) -> void
{
    auto terms {CPP2_UFCS(get_terms)(binexpr)}; 
    if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(terms))) ) { cpp2::cpp2_default.report_violation(""); }

    //  If this has only one term, it's not an actual additive,
    //  it's holding a lower grammar production so go traverse that
    if (CPP2_UFCS(ssize)(terms) == 1) {
        sample_traverser(CPP2_UFCS(get_term)(CPP2_UFCS(front)(cpp2::move(terms))), indent);
    }

    //  Else we're at an actual binary expression with a rhs
    else {
        sample_print("additive", indent);
{
auto first{true};

#line 3863 "reflect.h2"
        for ( 
             auto const& term : cpp2::move(terms) ) 
        {
            if (!(first)) {
                sample_print("op: " + cpp2::to_string(CPP2_UFCS(get_op)(term)) + "", indent + 1);
            }
            first = false;
            sample_print("term:", indent + 1);
            sample_traverser(CPP2_UFCS(get_term)(term), indent + 2);
        }
}
#line 3873 "reflect.h2"
    }
}

#line 3877 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::multiplicative_expression> binexpr, cpp2::impl::in<cpp2::i32> indent) -> void
{
    auto terms {CPP2_UFCS(get_terms)(binexpr)}; 
    if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(terms))) ) { cpp2::cpp2_default.report_violation(""); }

    //  If this has only one term, it's not an actual multiplicative,
    //  it's holding a lower grammar production so go traverse that
    if (CPP2_UFCS(ssize)(terms) == 1) {
        sample_traverser(CPP2_UFCS(get_term)(CPP2_UFCS(front)(cpp2::move(terms))), indent);
    }

    //  Else we're at an actual binary expression with a rhs
    else {
        sample_print("multiplicative", indent);
{
auto first{true};

#line 3893 "reflect.h2"
        for ( 
             auto const& term : cpp2::move(terms) ) 
        {
            if (!(first)) {
                sample_print("op: " + cpp2::to_string(CPP2_UFCS(get_op)(term)) + "", indent + 1);
            }
            first = false;
            sample_print("term:", indent + 1);
            sample_traverser(CPP2_UFCS(get_term)(term), indent + 2);
        }
}
#line 3903 "reflect.h2"
    }
}

#line 3907 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::is_as_expression> isas, cpp2::impl::in<cpp2::i32> indent) -> void
{
    auto terms {CPP2_UFCS(get_terms)(isas)}; 

    //  If this has no additional terms, it's not an actual is-as,
    //  it's holding a lower grammar production so go traverse that
    if (CPP2_UFCS(empty)(terms)) {
        sample_traverser(CPP2_UFCS(get_expression)(isas), indent);
    }

    //  Else we're at an actual is-as expression with a rhs
    else {
        sample_print("is-as expression", indent);

        sample_print("expression", indent + 1);
        sample_traverser(CPP2_UFCS(get_expression)(isas), indent + 2);

        for ( auto const& term : cpp2::move(terms) ) {
            sample_print("op: " + cpp2::to_string(CPP2_UFCS(get_op)(term)) + "", indent + 1);
            sample_print("term:", indent + 1);
            sample_traverser(CPP2_UFCS(get_expr)(term), indent + 2);
        }
    }
}

#line 3933 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::expression_list> exprs, cpp2::impl::in<cpp2::i32> indent) -> void
{
    if (CPP2_UFCS(is_empty)(exprs)) {
        sample_print("()", indent);
    }
    else {
        sample_print("(", indent);
        for ( auto const& expr : CPP2_UFCS(get_expressions)(exprs) ) {
            sample_traverser(expr, indent + 1);
        }
        sample_print(")", indent);
    }
}

#line 3948 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::prefix_expression> prefix, cpp2::impl::in<cpp2::i32> indent) -> void
{
    auto ops {CPP2_UFCS(get_ops)(prefix)}; 

    //  If this has no additional ops, it's not a naked prefix expr,
    //  it's holding a lower grammar production so go traverse that
    if (CPP2_UFCS(empty)(ops)) {
        sample_traverser(CPP2_UFCS(get_postfix_expression)(prefix), indent);
    }

    //  Else we're at an actual prefix expression with ops
    else {
        sample_print("prefix expression", indent);

        for ( auto const& op : cpp2::move(ops) ) {
            sample_print("op: " + cpp2::to_string(op) + "", indent + 1);
        }

        sample_print("expression", indent + 1);
        sample_traverser(CPP2_UFCS(get_postfix_expression)(prefix), indent + 2);
    }
}

#line 3972 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::postfix_expression> postfix, cpp2::impl::in<cpp2::i32> indent) -> void
{
    auto terms {CPP2_UFCS(get_terms)(postfix)}; 

    //  If this has no additional terms, it's not a naked postfix expr,
    //  it's holding a lower grammar production so go traverse that
    if (CPP2_UFCS(empty)(terms)) {
        sample_traverser(CPP2_UFCS(get_primary_expression)(postfix), indent);
    }

    //  Else we're at an actual postfix expression with ops
    else {
        sample_print("postfix expression", indent);

        sample_print("expression", indent + 1);
        sample_traverser(CPP2_UFCS(get_primary_expression)(postfix), indent + 2);

        for ( auto const& term : cpp2::move(terms) ) {
            sample_print("op: " + cpp2::to_string(CPP2_UFCS(get_op)(term)) + "", indent + 1);
            if (CPP2_UFCS(is_id_expression)(term)) {
                sample_traverser(CPP2_UFCS(get_id_expression)(term), indent + 1);
            }
            else {if (CPP2_UFCS(is_expression_list)(term)) {
                sample_traverser(CPP2_UFCS(get_expression_list)(term), indent + 1);
            }
            else {if (CPP2_UFCS(is_expression)(term)) {
                sample_traverser(CPP2_UFCS(get_expression)(term), indent + 1);
            }}}
        }
    }
}

#line 4005 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::unqualified_id> uid, cpp2::impl::in<cpp2::i32> indent) -> void
{
    if (CPP2_UFCS(is_identifier)(uid)) {
        sample_print(CPP2_UFCS(get_identifier)(uid), indent);
    }
    else {
        sample_print(CPP2_UFCS(to_string)(uid), indent + 1);
    }
}

#line 4016 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::qualified_id> qid, cpp2::impl::in<cpp2::i32> indent) -> void
{
{
auto first{true};

#line 4019 "reflect.h2"
    for ( 
         auto const& term : CPP2_UFCS(get_terms)(qid) ) 
    {
        if (!(first)) {
            sample_print("op: " + cpp2::to_string(CPP2_UFCS(get_op)(term)) + "", indent + 1);
        }
        first = false;
        sample_print("unqualified:", indent + 1);
        sample_traverser(CPP2_UFCS(get_unqualified)(term), indent + 2);
    }
}
#line 4029 "reflect.h2"
}

#line 4032 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::type_id> tid, cpp2::impl::in<cpp2::i32> indent) -> void
{
    if (CPP2_UFCS(is_postfix_expression)(tid)) {
        sample_traverser(CPP2_UFCS(as_postfix_expression)(tid), indent);
    }
    else {if (CPP2_UFCS(is_qualified_id)(tid)) {
        sample_traverser(CPP2_UFCS(as_qualified_id)(tid), indent);
    }
    else {if (CPP2_UFCS(is_unqualified_id)(tid)) {
        sample_traverser(CPP2_UFCS(as_unqualified_id)(tid), indent);
    }
    else {
        sample_print(CPP2_UFCS(to_string)(tid), indent);
    }}}
}

#line 4049 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::primary_expression> primary, cpp2::impl::in<cpp2::i32> indent) -> void
{
    if (CPP2_UFCS(is_identifier)(primary)) {
        sample_print(CPP2_UFCS(as_identifier)(primary), indent + 1);
    }
    else {if (CPP2_UFCS(is_expression_list)(primary)) {
        sample_traverser(CPP2_UFCS(as_expression_list)(primary), indent + 1);
    }
    else {if (CPP2_UFCS(is_literal)(primary)) {
        sample_print(CPP2_UFCS(as_literal)(primary), indent + 1);
    }
    else {if (CPP2_UFCS(is_declaration)(primary)) {
        sample_traverser(CPP2_UFCS(as_declaration)(primary), indent + 1);
    }
    else {
        sample_print(CPP2_UFCS(to_string)(primary), indent + 1);
    }}}}
}

#line 4069 "reflect.h2"
auto sample_traverser(cpp2::impl::in<meta::id_expression> idexpr, cpp2::impl::in<cpp2::i32> indent) -> void
{
    if (CPP2_UFCS(is_identifier)(idexpr)) {
        sample_print(CPP2_UFCS(as_identifier)(idexpr), indent + 1);
    }
    else {if (CPP2_UFCS(is_qualified)(idexpr)) {
        sample_traverser(CPP2_UFCS(as_qualified)(idexpr), indent + 1);
    }
    else {if (CPP2_UFCS(is_unqualified)(idexpr)) {
        sample_traverser(CPP2_UFCS(as_unqualified)(idexpr), indent + 1);
    }
    else {
        sample_print(CPP2_UFCS(to_string)(idexpr), indent + 1);
    }}}
}

#line 4086 "reflect.h2"
//-----------------------------------------------------------------------
//
//  autodiff - stub
//

#line 4101 "reflect.h2"
    autodiff_special_func::autodiff_special_func(cpp2::impl::in<std::string> name_, cpp2::impl::in<int> n_args_, cpp2::impl::in<bool> is_member_, cpp2::impl::in<std::string> code_primal_, cpp2::impl::in<std::string> code_fwd_, 
                          cpp2::impl::in<std::string> code_primal_higher_order_, cpp2::impl::in<std::string> code_fwd_higher_order_)
        : name{ name_ }
        , n_args{ n_args_ }
        , is_member{ is_member_ }
        , code_primal{ code_primal_ }
        , code_fwd{ code_fwd_ }
        , code_primal_higher_order{ code_primal_higher_order_ }
        , code_fwd_higher_order{ code_fwd_higher_order_ }{

#line 4112 "reflect.h2"
        if (CPP2_UFCS(empty)(code_primal_higher_order)) {
            code_primal_higher_order = code_primal;
        }
        if (CPP2_UFCS(empty)(code_fwd_higher_order)) {
            code_fwd_higher_order = code_fwd;
        }
    }

#line 4120 "reflect.h2"
    autodiff_special_func::autodiff_special_func(autodiff_special_func const& that)
                                   : name{ that.name }
                                   , n_args{ that.n_args }
                                   , is_member{ that.is_member }
                                   , code_primal{ that.code_primal }
                                   , code_fwd{ that.code_fwd }
                                   , code_primal_higher_order{ that.code_primal_higher_order }
                                   , code_fwd_higher_order{ that.code_fwd_higher_order }{}
#line 4120 "reflect.h2"
    auto autodiff_special_func::operator=(autodiff_special_func const& that) -> autodiff_special_func& {
                                   name = that.name;
                                   n_args = that.n_args;
                                   is_member = that.is_member;
                                   code_primal = that.code_primal;
                                   code_fwd = that.code_fwd;
                                   code_primal_higher_order = that.code_primal_higher_order;
                                   code_fwd_higher_order = that.code_fwd_higher_order;
                                   return *this; }
#line 4120 "reflect.h2"
    autodiff_special_func::autodiff_special_func(autodiff_special_func&& that) noexcept
                                   : name{ std::move(that).name }
                                   , n_args{ std::move(that).n_args }
                                   , is_member{ std::move(that).is_member }
                                   , code_primal{ std::move(that).code_primal }
                                   , code_fwd{ std::move(that).code_fwd }
                                   , code_primal_higher_order{ std::move(that).code_primal_higher_order }
                                   , code_fwd_higher_order{ std::move(that).code_fwd_higher_order }{}
#line 4120 "reflect.h2"
    auto autodiff_special_func::operator=(autodiff_special_func&& that) noexcept -> autodiff_special_func& {
                                   name = std::move(that).name;
                                   n_args = std::move(that).n_args;
                                   is_member = std::move(that).is_member;
                                   code_primal = std::move(that).code_primal;
                                   code_fwd = std::move(that).code_fwd;
                                   code_primal_higher_order = std::move(that).code_primal_higher_order;
                                   code_fwd_higher_order = std::move(that).code_fwd_higher_order;
                                   return *this; }// Default copy.

#line 4122 "reflect.h2"
    [[nodiscard]] auto autodiff_special_func::is_match(cpp2::impl::in<autodiff_special_func> o) const& -> bool{
        return name == o.name && n_args == o.n_args && is_member == o.is_member; 
    }

#line 4129 "reflect.h2"
                                        // TODO: Maybe use variant here.

#line 4133 "reflect.h2"
    autodiff_declared_variable::autodiff_declared_variable(){}

#line 4135 "reflect.h2"
    autodiff_declared_variable::autodiff_declared_variable(cpp2::impl::in<std::string> name_, cpp2::impl::in<std::string> decl_, cpp2::impl::in<bool> is_active_, cpp2::impl::in<bool> is_member_)
        : name{ name_ }
        , decl{ decl_ }
        , is_active{ is_active_ }
        , is_member{ is_member_ }{

#line 4140 "reflect.h2"
    }

#line 4142 "reflect.h2"
    autodiff_declared_variable::autodiff_declared_variable(autodiff_declared_variable const& that)
                                  : name{ that.name }
                                  , decl{ that.decl }
                                  , is_active{ that.is_active }
                                  , is_member{ that.is_member }{}
#line 4142 "reflect.h2"
    auto autodiff_declared_variable::operator=(autodiff_declared_variable const& that) -> autodiff_declared_variable& {
                                  name = that.name;
                                  decl = that.decl;
                                  is_active = that.is_active;
                                  is_member = that.is_member;
                                  return *this; }
#line 4142 "reflect.h2"
    autodiff_declared_variable::autodiff_declared_variable(autodiff_declared_variable&& that) noexcept
                                  : name{ std::move(that).name }
                                  , decl{ std::move(that).decl }
                                  , is_active{ std::move(that).is_active }
                                  , is_member{ std::move(that).is_member }{}
#line 4142 "reflect.h2"
    auto autodiff_declared_variable::operator=(autodiff_declared_variable&& that) noexcept -> autodiff_declared_variable& {
                                  name = std::move(that).name;
                                  decl = std::move(that).decl;
                                  is_active = std::move(that).is_active;
                                  is_member = std::move(that).is_member;
                                  return *this; }

#line 4146 "reflect.h2"
                                      // namespace + type name

#line 4154 "reflect.h2"
    autodiff_declaration_stack_item::autodiff_declaration_stack_item(cpp2::impl::in<std::string> full_name_, cpp2::impl::in<meta::type_or_namespace_declaration> decl_)
        : full_name{ full_name_ }
        , decl{ decl_ }{

#line 4157 "reflect.h2"
    }

#line 4159 "reflect.h2"
    [[nodiscard]] auto autodiff_declaration_stack_item::lookup_declaration(cpp2::impl::in<std::string> decl_name) const& -> lookup_declaration_ret{
        std::vector<meta::declaration> r {};
#line 4160 "reflect.h2"
        for ( auto const& cur : CPP2_UFCS(get_members)(decl) ) {
            if (CPP2_UFCS(has_name)(cur) && decl_name == CPP2_UFCS(name)(cur)) {
                CPP2_UFCS(push_back)(r, cur);

                // Do not break for overloads. <3
            }
        }return r; 
    }

#line 4169 "reflect.h2"
    [[nodiscard]] auto autodiff_declaration_stack_item::lookup_variable_declaration(cpp2::impl::in<std::string> decl_name) const& -> lookup_variable_declaration_ret{
        bool found {false};
        autodiff_declared_variable r {};
#line 4170 "reflect.h2"
        for ( auto const& cur_context : std::ranges::views::reverse(declared_variables_stack) ) {
            for ( auto const& cur : cur_context ) {
                if (cur.name == decl_name) {
                    found = true;
                    r = cur;
                    return  { std::move(found), std::move(r) }; 
                }
            }
        }return  { std::move(found), std::move(r) }; 
    }

    autodiff_declaration_stack_item::autodiff_declaration_stack_item(autodiff_declaration_stack_item const& that)
                                     : full_name{ that.full_name }
                                     , decl{ that.decl }
                                     , diff_request{ that.diff_request }
                                     , diff_done{ that.diff_done }
                                     , declared_variables_stack{ that.declared_variables_stack }{}
autodiff_declaration_stack_item::autodiff_declaration_stack_item(autodiff_declaration_stack_item&& that) noexcept
                                     : full_name{ std::move(that).full_name }
                                     , decl{ std::move(that).decl }
                                     , diff_request{ std::move(that).diff_request }
                                     , diff_done{ std::move(that).diff_done }
                                     , declared_variables_stack{ std::move(that).declared_variables_stack }{}

#line 4187 "reflect.h2"
    // Code in special function is replaced. Placeholders are:
    //   _o_  : name of object for member functions.
    //   _o_  : name of derivative object for member functions.
    //   _a1_ : First argument value
    //   _ad1_: First derivative argument value
    //   _a2_ : Second argument value
    //   _ad2_: Second derivative argument value

                                        /* is_member = */

#line 4202 "reflect.h2"
                                        /* is_member = */

#line 4208 "reflect.h2"
                                        /* is_member = */

#line 4214 "reflect.h2"
                                         /* is_member = */

#line 4220 "reflect.h2"
                                              /* is_member = */

#line 4230 "reflect.h2"
    // Members depending on order

#line 4237 "reflect.h2"
    autodiff_context::autodiff_context(){}
#line 4238 "reflect.h2"
    autodiff_context::autodiff_context(cpp2::impl::in<int> order_, cpp2::impl::in<bool> reverse_)
        : order{ order_ }
        , reverse{ reverse_ }{

#line 4242 "reflect.h2"
        if (1 != order) {
            if (reverse) {
                fwd_ad_type = "cpp2::taylor<double, " + cpp2::to_string(order - 1) + ">";
                rws_ad_type = "cpp2::taylor<double, " + cpp2::to_string(order) + ">";
            }
            else {
                fwd_ad_type = "cpp2::taylor<double, " + cpp2::to_string(order) + ">";
            }
        }

    }

#line 4254 "reflect.h2"
    auto autodiff_context::add_variable_declaration(cpp2::impl::in<std::string> name, cpp2::impl::in<std::string> type, cpp2::impl::in<bool> is_active, cpp2::impl::in<bool> is_member) & -> void{
        CPP2_UFCS(push_back)(CPP2_UFCS(back)(CPP2_UFCS(back)(declaration_stack).declared_variables_stack), autodiff_declared_variable(name, type, is_active, is_member));
    }

#line 4258 "reflect.h2"
    [[nodiscard]] auto autodiff_context::is_variable_active(cpp2::impl::in<std::string> name) & -> bool{
        return lookup_variable_declaration(name).is_active; 
    }

#line 4262 "reflect.h2"
    auto autodiff_context::create_namespace_stack(cpp2::impl::in<meta::type_or_namespace_declaration> t) & -> void{
        if (CPP2_UFCS(parent_is_nonglobal_namespace)(t)) {
            create_namespace_stack(CPP2_UFCS(as_nonglobal_namespace)(CPP2_UFCS(get_parent)(t)));
        }
        else {if (CPP2_UFCS(parent_is_type)(t)) {
            create_namespace_stack(CPP2_UFCS(as_type)(CPP2_UFCS(get_parent)(t)));
        }}

        std::string full_name {"::"}; 
        if (!(CPP2_UFCS(empty)(declaration_stack))) {
            full_name = CPP2_UFCS(back)(declaration_stack).full_name + "::";
        }
        full_name += CPP2_UFCS(name)(t);

        static_cast<void>(CPP2_UFCS(push_back)(declaration_stack, autodiff_declaration_stack_item(cpp2::move(full_name), t)));
    }

#line 4279 "reflect.h2"
    [[nodiscard]] auto autodiff_context::is_forward() const& -> decltype(auto) { return !(reverse) || (reverse && order != 1);  }
#line 4280 "reflect.h2"
    [[nodiscard]] auto autodiff_context::is_reverse() const& -> decltype(auto) { return reverse;  }
#line 4281 "reflect.h2"
    [[nodiscard]] auto autodiff_context::is_taylor() const& -> decltype(auto) { return order != 1;  }

#line 4283 "reflect.h2"
    [[nodiscard]] auto autodiff_context::gen_temporary() & -> std::string{
        temporary_count += 1;
        return "temp_" + cpp2::to_string(temporary_count) + ""; 
    }

#line 4288 "reflect.h2"
    [[nodiscard]] auto autodiff_context::is_type_active(cpp2::impl::in<std::string> type) & -> bool{
        auto decls {lookup_type_declaration(type)}; 
        auto r {false}; 

        if (!(CPP2_UFCS(empty)(decls))) {
            if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(ssize)(decls) == 1) ) { cpp2::cpp2_default.report_violation(""); }
            autodiff_activity_check ada {&(*this)}; 
            CPP2_UFCS(pre_traverse)(ada, CPP2_ASSERT_IN_BOUNDS_LITERAL(cpp2::move(decls), 0));
            r = cpp2::move(ada).active;
        }

        // TODO: Add template activity lookup.

        if (!(r)) {
            // Declaration lookup did not yield an activity: Apply some heuristics.
            r = CPP2_UFCS(contains)(type, "double");
        }

        return r; 
    }

#line 4309 "reflect.h2"
    [[nodiscard]] auto autodiff_context::get_fwd_ad_type(cpp2::impl::in<std::string> type) & -> std::string{
        auto type_d {type}; 

        if ("double" != type) {
            auto type_decls {lookup_type_declaration(type)}; 
            if (!(CPP2_UFCS(empty)(type_decls))) {
                // We found a cpp2 type declaration, mark it for differentiation.
                add_for_differentiation(CPP2_ASSERT_IN_BOUNDS_LITERAL(cpp2::move(type_decls), 0));

                // Add the AD suffix to the type
                type_d += fwd_suffix;
            }
        }

        // Replace with AD type for the AD order.
        return string_util::replace_all(cpp2::move(type_d), "double", fwd_ad_type); 
    }

#line 4327 "reflect.h2"
    [[nodiscard]] auto autodiff_context::get_rws_ad_type(cpp2::impl::in<std::string> type) & -> std::string{
        auto type_d {type}; 

        if ("double" != type) {
            auto type_decls {lookup_type_declaration(type)}; 
            if (!(CPP2_UFCS(empty)(type_decls))) {
                // We found a cpp2 type declaration, mark it for differentiation.
                add_for_differentiation(CPP2_ASSERT_IN_BOUNDS_LITERAL(cpp2::move(type_decls), 0));

                // Add the AD suffix to the type
                type_d += rws_suffix;
            }
        }

        // Replace with AD type for the AD order.
        return string_util::replace_all(cpp2::move(type_d), "double", rws_ad_type); 
    }

#line 4345 "reflect.h2"
    [[nodiscard]] auto autodiff_context::get_reverse_passing_style(cpp2::impl::in<passing_style> p) const& -> passing_style{
        // TODO: inspect does not work here: error: error: no matching function for call to ‘is<cpp2::passing_style::in>(const cpp2::passing_style&)’
        // return inspect p -> passing_style  {
        //     is passing_style::in          = passing_style::inout;
        //     is passing_style::in_ref      = passing_style::inout;
        //     is passing_style::copy        = passing_style::inout;
        //     is passing_style::inout       = passing_style::inout;
        //     is passing_style::out         = passing_style::inout;
        //     is passing_style::move        = passing_style::inout;
        //     is passing_style::forward     = passing_style::inout;
        //     is passing_style::forward_ref = passing_style::inout;
        //     is _                          = passing_style::inout;
        // };
        if (p == passing_style::in)          { return  passing_style::inout; }
        if (p == passing_style::in_ref)      { return  passing_style::inout; }
        if (p == passing_style::copy)        { return  passing_style::inout; }
        if (p == passing_style::inout)       { return  passing_style::inout; }
        if (p == passing_style::out)         { return  passing_style::inout; }
        if (p == passing_style::move)        { return  passing_style::inout; }
        if (p == passing_style::forward)     { return  passing_style::inout; }
        if (p == passing_style::forward_ref) { return  passing_style::inout; }

#line 4368 "reflect.h2"
        CPP2_UFCS(error)(CPP2_UFCS(back)(declaration_stack).decl, "AD: Do not know how to handle passing style:" + cpp2::to_string(p) + "");

        return  passing_style::inout; 
    }

#line 4373 "reflect.h2"
    [[nodiscard]] auto autodiff_context::lookup_declaration(cpp2::impl::in<std::string> decl_name) & -> lookup_declaration_ret{
        std::vector<meta::declaration> r {};
#line 4374 "reflect.h2"
        for ( auto const& cur : std::ranges::views::reverse(declaration_stack) ) {

            std::string cur_full_name {cur.full_name + "::" + decl_name}; 
            auto ele {CPP2_UFCS(find)(declaration_map, cur_full_name)}; 
            if (ele == CPP2_UFCS(end)(declaration_map)) {
                ele = CPP2_UFCS(insert_or_assign)(declaration_map, cpp2::move(cur_full_name), CPP2_UFCS(lookup_declaration)(cur, decl_name)).first;
            }

            if (!(CPP2_UFCS(empty)((*cpp2::impl::assert_not_null(ele)).second))) {
                // A simple assignment or emplace_back did not work. It tired to use move copy operators.
                for ( auto const& cp : (*cpp2::impl::assert_not_null(cpp2::move(ele))).second ) {
                    CPP2_UFCS(push_back)(r, cp);
                }
                //r = ele*.second;
                break;
                // TODO: For overload resolution we may want to continue here and just add everything for all parent namespaces.
            }
        }

        return r; 
    }

#line 4396 "reflect.h2"
    [[nodiscard]] auto autodiff_context::lookup_variable_declaration(cpp2::impl::in<std::string> name) & -> autodiff_declared_variable{
        if (name == "_") {
            return autodiff_declared_variable(name, "_", false, false); 
        }

        for ( auto const& cur_context : std::ranges::views::reverse(declaration_stack) ) {
            auto r {CPP2_UFCS(lookup_variable_declaration)(cur_context, name)}; 
            if (r.found) {
                return cpp2::move(r).r; 
            }
        }

        CPP2_UFCS(error)(CPP2_UFCS(back)(declaration_stack).decl, "AD: Could not find declaration of variable with name `" + cpp2::to_string(name) + "`.");

        return autodiff_declared_variable(); 
    }

#line 4413 "reflect.h2"
    [[nodiscard]] auto autodiff_context::lookup_function_declaration(cpp2::impl::in<std::string> decl_name) & -> lookup_function_declaration_ret{
        std::vector<meta::function_declaration> r {};
#line 4414 "reflect.h2"
        auto r_all {lookup_declaration(decl_name)}; 

        for ( auto const& cur : cpp2::move(r_all) ) {
            if (CPP2_UFCS(is_function)(cur)) {
                CPP2_UFCS(push_back)(r, CPP2_UFCS(as_function)(cur));
            }
        }return r; 
    }

#line 4423 "reflect.h2"
    [[nodiscard]] auto autodiff_context::lookup_member_function_declaration(cpp2::impl::in<meta::type_declaration> obj_type, cpp2::impl::in<std::string> decl_name) & -> lookup_member_function_declaration_ret{
        std::vector<meta::function_declaration> r {};
#line 4424 "reflect.h2"
        for ( auto const& cur : CPP2_UFCS(get_members)(obj_type) ) {
            if (CPP2_UFCS(is_function)(cur) && CPP2_UFCS(has_name)(cur) && decl_name == CPP2_UFCS(name)(cur)) {
                CPP2_UFCS(push_back)(r, CPP2_UFCS(as_function)(cur));

                // Do not break for overloads. <3
            }
        }return r; 
    }

#line 4433 "reflect.h2"
    [[nodiscard]] auto autodiff_context::lookup_type_declaration(cpp2::impl::in<std::string> decl_name) & -> lookup_type_declaration_ret{
        std::vector<meta::type_declaration> r {};
#line 4434 "reflect.h2"
        auto r_all {lookup_declaration(decl_name)}; 

        for ( auto const& cur : cpp2::move(r_all) ) {
            if (CPP2_UFCS(is_type)(cur)) {
                CPP2_UFCS(push_back)(r, CPP2_UFCS(as_type)(cur));
            }
        }return r; 
    }

#line 4443 "reflect.h2"
    [[nodiscard]] auto autodiff_context::lookup_special_function_handling(cpp2::impl::in<std::string> func_name, cpp2::impl::in<int> n_args, cpp2::impl::in<bool> is_member) const& -> lookup_special_function_handling_ret{
            cpp2::impl::deferred_init<bool> m;
            cpp2::impl::deferred_init<std::string> code_primal;
            cpp2::impl::deferred_init<std::string> code_fwd;
#line 4444 "reflect.h2"
        autodiff_special_func lookup {func_name, n_args, is_member}; 

        m.construct(false);
        code_primal.construct("");
        code_fwd.construct("");
        for ( auto const& func : special_funcs ) {
            if (CPP2_UFCS(is_match)(func, lookup)) {
                m.value() = true;
                if (is_taylor()) {
                    code_primal.value() = func.code_primal_higher_order;
                    code_fwd.value() = func.code_fwd_higher_order;
                }
                else {
                    code_primal.value() = func.code_primal;
                    code_fwd.value() = func.code_fwd;
                }
                return  { std::move(m.value()), std::move(code_primal.value()), std::move(code_fwd.value()) }; 
            }
        }return  { std::move(m.value()), std::move(code_primal.value()), std::move(code_fwd.value()) }; 
    }

#line 4465 "reflect.h2"
    auto autodiff_context::add_as_differentiated(cpp2::impl::in<meta::declaration> t) & -> void{
        auto top {&CPP2_UFCS(back)(declaration_stack)}; 

        if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(is_same)(CPP2_UFCS(get_parent)(t), (*cpp2::impl::assert_not_null(top)).decl)) ) { cpp2::cpp2_default.report_violation(""); }

        CPP2_UFCS(push_back)((*cpp2::impl::assert_not_null(cpp2::move(top))).diff_done, t);
    }

#line 4473 "reflect.h2"
    auto autodiff_context::add_for_differentiation(cpp2::impl::in<meta::declaration> t) & -> void{
        auto t_parent {CPP2_UFCS(get_parent)(t)}; 

        auto found {false}; 
        for ( auto& cur : std::ranges::views::reverse(declaration_stack) ) {
            if (CPP2_UFCS(is_same)(t_parent, cur.decl)) {
                if (!(is_in_list(t, cur.diff_request))) {
                    CPP2_UFCS(push_back)(cur.diff_request, t);
                }

                found = true;
                break;
            }
        }

        if (!(cpp2::move(found))) {
            CPP2_UFCS(error)(t, "AD: Could not find parent type/namespace for: " + cpp2::to_string(t) + "");
        }
    }

#line 4493 "reflect.h2"
    [[nodiscard]] auto autodiff_context::is_in_list(cpp2::impl::in<meta::declaration> v, cpp2::impl::in<std::vector<meta::declaration>> list) -> bool{
        for ( auto const& cur : list ) {
            if (CPP2_UFCS(is_same)(cur, v)) {
                return true; 
            }
        }

        return false; 
    }

#line 4503 "reflect.h2"
    auto autodiff_context::enter_function() & -> void{
        temporary_count = 0;
        CPP2_UFCS(push_back)(CPP2_UFCS(back)(declaration_stack).declared_variables_stack, std::vector<autodiff_declared_variable>());
    }

#line 4508 "reflect.h2"
    auto autodiff_context::leave_function() & -> void{
        CPP2_UFCS(pop_back)(CPP2_UFCS(back)(declaration_stack).declared_variables_stack);
    }

#line 4512 "reflect.h2"
    auto autodiff_context::push_stack(cpp2::impl::in<meta::type_or_namespace_declaration> decl) & -> void{
        std::string full_name {""}; 

        if (!(CPP2_UFCS(empty)(declaration_stack))) {
            full_name += CPP2_UFCS(back)(declaration_stack).full_name;
        }

        full_name += "::";
        full_name += CPP2_UFCS(name)(decl);

        CPP2_UFCS(push_back)(declaration_stack, autodiff_declaration_stack_item(cpp2::move(full_name), decl));
    }

#line 4525 "reflect.h2"
    auto autodiff_context::pop_stack() & -> void{
        if (cpp2::cpp2_default.is_active() && !(!(CPP2_UFCS(empty)(declaration_stack))) ) { cpp2::cpp2_default.report_violation(""); }

        auto top {&CPP2_UFCS(back)(declaration_stack)}; 
        autodiff_declaration_handler ad {&(*this), (*cpp2::impl::assert_not_null(top)).decl}; 

        for ( auto const& cur : (*cpp2::impl::assert_not_null(top)).diff_request ) {
            if (!(is_in_list(cur, (*cpp2::impl::assert_not_null(top)).diff_done))) {
                CPP2_UFCS(pre_traverse)(ad, cur);
            }
        }

        CPP2_UFCS(pop_back)(declaration_stack);
    }

#line 4540 "reflect.h2"
    auto autodiff_context::finish() & -> void{
        while( !(CPP2_UFCS(empty)(declaration_stack)) ) {
            pop_stack();
        }
    }

#line 4554 "reflect.h2"
    autodiff_diff_code::autodiff_diff_code(cpp2::impl::in<autodiff_context*> ctx_)
        : ctx{ ctx_ }{

#line 4556 "reflect.h2"
    }
#line 4554 "reflect.h2"
    auto autodiff_diff_code::operator=(cpp2::impl::in<autodiff_context*> ctx_) -> autodiff_diff_code& {
        ctx = ctx_;
        fwd = "";
        rws_primal = "";
        rws_backprop = "";
        return *this;

#line 4556 "reflect.h2"
    }

#line 4558 "reflect.h2"
    auto autodiff_diff_code::add_forward(cpp2::impl::in<std::string> v) & -> void{if (CPP2_UFCS(is_forward)((*cpp2::impl::assert_not_null(ctx)))) {fwd += v;}}
#line 4559 "reflect.h2"
    auto autodiff_diff_code::add_reverse_primal(cpp2::impl::in<std::string> v) & -> void{if (CPP2_UFCS(is_reverse)((*cpp2::impl::assert_not_null(ctx)))) {rws_primal += v;}}
#line 4560 "reflect.h2"
    auto autodiff_diff_code::add_reverse_backprop(cpp2::impl::in<std::string> v) & -> void{if (CPP2_UFCS(is_reverse)((*cpp2::impl::assert_not_null(ctx)))) {rws_backprop += v; }}

#line 4562 "reflect.h2"
    auto autodiff_diff_code::reset() & -> void{
        fwd          = "";
        rws_primal   = "";
        rws_backprop = "";
    }

    // Temporary: TODO: remove when everything has been adapted to primal, fwd, rws pushes.
#line 4569 "reflect.h2"
    auto autodiff_diff_code::operator=(cpp2::impl::in<std::string> v) -> autodiff_diff_code& {
        ctx = ctx;
        fwd = v;
        rws_primal = "";
        rws_backprop = "";
        return *this;

#line 4572 "reflect.h2"
    }

    // Temporary: TODO: remove when everything has been adapted to primal, fwd, rws pushes.
#line 4575 "reflect.h2"
    auto autodiff_diff_code::operator+=(cpp2::impl::in<std::string> v) & -> void{
        fwd += v;
    }

    // Temporary: TODO: remove when everything has been adapted to primal, fwd, rws pushes.
#line 4580 "reflect.h2"
    auto autodiff_diff_code::operator+=(cpp2::impl::in<autodiff_diff_code> v) & -> void{
        fwd += v.fwd;
    }

    // Temporary: TODO: remove when everything has been adapted to primal, fwd, rws pushes.
#line 4585 "reflect.h2"
    [[nodiscard]] auto autodiff_diff_code::empty() const& -> bool{
        return CPP2_UFCS(empty)(fwd); 
    }

#line 4590 "reflect.h2"
// // Temporary: TODO: remove when everything has been adapted to primal, fwd, rws pushes.
// to_string: (v: autodiff_diff_code) -> std::string = {
//     return v.fwd;
// }

#line 4601 "reflect.h2"
    autodiff_activity_check::autodiff_activity_check(cpp2::impl::in<autodiff_context*> ctx_)
        : simple_traverser{  }
        , ctx{ ctx_ }{

#line 4603 "reflect.h2"
    }

#line 4605 "reflect.h2"
    auto autodiff_activity_check::traverse(cpp2::impl::in<meta::object_declaration> o) -> void{

        auto type {o.type()}; 

        if ("_" == type) {
            if (CPP2_UFCS(has_initializer)(o)) {
                pre_traverse(CPP2_UFCS(get_initializer)(o));
            }
            else {
                // Assume active
                active = true;
            }
        }
        else {
            active |= CPP2_UFCS(is_type_active)((*cpp2::impl::assert_not_null(ctx)), cpp2::move(type));
        }
    }

#line 4623 "reflect.h2"
    auto autodiff_activity_check::traverse(cpp2::impl::in<meta::primary_expression> primary) -> void
    {
        if (CPP2_UFCS(is_identifier)(primary)) {
            active |= CPP2_UFCS(is_variable_active)((*cpp2::impl::assert_not_null(ctx)), CPP2_UFCS(to_string)(primary));
        }
        else {if (CPP2_UFCS(is_expression_list)(primary)) {
            for ( auto const& cur : CPP2_UFCS(get_expressions)(CPP2_UFCS(as_expression_list)(primary)) ) {
                pre_traverse(cur);
            }
        }
        else {if (CPP2_UFCS(is_literal)(primary)) {
            // TODO: Improve check
            if (CPP2_UFCS(contains)(CPP2_UFCS(to_string)(primary), ".")) {
                active = true;
            }
        }
        else {if (CPP2_UFCS(is_declaration)(primary)) {
            pre_traverse(CPP2_UFCS(as_declaration)(primary));
        }
        else {
            CPP2_UFCS(error)(primary, "AD: Unknown primary expression kind: " + cpp2::to_string(CPP2_UFCS(to_string)(primary)) + "");
        }}}}
    }

#line 4647 "reflect.h2"
    auto autodiff_activity_check::traverse(cpp2::impl::in<meta::postfix_expression> postfix) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(postfix)}; 

        auto is_func {false}; 
{
auto i{0};

#line 4654 "reflect.h2"
        for (                     auto const& term : terms )  { do {
            if (CPP2_UFCS(get_op)(term) == ".") {
                continue;
            }
            if (CPP2_UFCS(get_op)(term) == "(" && i + 1 == CPP2_UFCS(ssize)(terms)) {// Function operator has to be the last
                is_func = true;
                continue;
            }
            else {
                CPP2_UFCS(error)(postfix, "AD: Unknown operator for postfix expression. op: " + cpp2::to_string(CPP2_UFCS(get_op)(term)) + " expr: " + cpp2::to_string(postfix) + "");
            }
        } while (false); i += 1; }
}

        // TODO: Really check for members
#line 4668 "reflect.h2"
        if (CPP2_UFCS(ssize)(terms) != 1) {
            active |= CPP2_UFCS(is_variable_active)((*cpp2::impl::assert_not_null(ctx)), CPP2_UFCS(to_string)(CPP2_UFCS(get_primary_expression)(postfix)));
        }

        if (cpp2::move(is_func)) {
            // Check arguments of function
            for ( auto const& cur : CPP2_UFCS(get_expressions)(CPP2_UFCS(get_expression_list)(CPP2_UFCS(back)(cpp2::move(terms)))) ) {
                pre_traverse(cur);
            }
        }
    }

#line 4686 "reflect.h2"
    autodiff_handler_base::autodiff_handler_base(cpp2::impl::in<autodiff_context*> ctx_)
        : ctx{ ctx_ }
        , diff{ ctx }{

#line 4689 "reflect.h2"
    }
#line 4686 "reflect.h2"
    auto autodiff_handler_base::operator=(cpp2::impl::in<autodiff_context*> ctx_) -> autodiff_handler_base& {
        ctx = ctx_;
        diff = ctx;
        return *this;

#line 4689 "reflect.h2"
    }

    // Temporary: TODO: remove when everything has been adapted to primal, fwd, rws pushes.
#line 4692 "reflect.h2"
    auto autodiff_handler_base::append(autodiff_handler_base const& o) & -> void{
        diff.fwd          += o.diff.fwd;
        diff.rws_primal   += o.diff.rws_primal;
        diff.rws_backprop  = o.diff.rws_backprop + diff.rws_backprop;
    }

#line 4709 "reflect.h2"
    autodiff_expression_handler::autodiff_expression_handler(cpp2::impl::in<autodiff_context*> ctx_)
        : simple_traverser{  }
        , autodiff_handler_base{ ctx_ }{

#line 4711 "reflect.h2"
    }

#line 4713 "reflect.h2"
    [[nodiscard]] auto autodiff_expression_handler::add_suffix_if_not_wildcard(cpp2::impl::in<std::string> lhs, cpp2::impl::in<std::string> suffix) const& -> std::string{
        if ("_" == lhs) {
            return lhs; 
        }
        else {
            return lhs + suffix; 
        }
    }

#line 4722 "reflect.h2"
    [[nodiscard]] auto autodiff_expression_handler::prepare_backprop(cpp2::impl::in<std::string> rhs_b, cpp2::impl::in<std::string> lhs, cpp2::impl::in<std::string> lhs_d, cpp2::impl::in<std::string> lhs_b) const& -> std::string{
        auto r {rhs_b}; 
        r  = string_util::replace_all(r, "_r_", lhs);
        r  = string_util::replace_all(r, "_rd_", lhs_d);
        r  = string_util::replace_all(r, "_rb_", lhs_b);

        return r; 
    }

#line 4731 "reflect.h2"
    auto autodiff_expression_handler::gen_assignment(cpp2::impl::in<std::string> lhs, cpp2::impl::in<std::string> lhs_d, cpp2::impl::in<std::string> lhs_b, cpp2::impl::in<std::string> rhs, cpp2::impl::in<std::string> rhs_d, cpp2::impl::in<std::string> rhs_b) & -> void{
        CPP2_UFCS(add_forward)(diff, "" + cpp2::to_string(lhs_d) + " = " + cpp2::to_string(rhs_d) + ";\n");
        CPP2_UFCS(add_forward)(diff, "" + cpp2::to_string(lhs) + "   = " + cpp2::to_string(rhs) + ";\n");

        if (CPP2_UFCS(is_taylor)((*cpp2::impl::assert_not_null(ctx)))) {
            CPP2_UFCS(add_reverse_primal)(diff, "" + cpp2::to_string(lhs_d) + " = " + cpp2::to_string(rhs_d) + ";\n");
        }
        CPP2_UFCS(add_reverse_primal)(diff, "" + cpp2::to_string(lhs) + "   = " + cpp2::to_string(rhs) + ";\n");
        CPP2_UFCS(add_reverse_backprop)(diff, prepare_backprop(rhs_b, lhs, lhs_d, lhs_b));
    }
#line 4741 "reflect.h2"
    [[nodiscard]] auto autodiff_expression_handler::gen_assignment(cpp2::impl::in<std::string> lhs, cpp2::impl::in<std::string> lhs_d, cpp2::impl::in<std::string> lhs_b) & -> decltype(auto) { 
        return gen_assignment(lhs, lhs_d, lhs_b, primal_expr, fwd_expr, rws_expr);  }
#line 4743 "reflect.h2"
    [[nodiscard]] auto autodiff_expression_handler::gen_assignment(cpp2::impl::in<std::string> lhs) & -> decltype(auto) { 
        return gen_assignment(lhs, add_suffix_if_not_wildcard(lhs, (*cpp2::impl::assert_not_null(ctx)).fwd_suffix), add_suffix_if_not_wildcard(lhs, (*cpp2::impl::assert_not_null(ctx)).rws_suffix), primal_expr, fwd_expr, rws_expr);  }

#line 4747 "reflect.h2"
    auto autodiff_expression_handler::gen_declaration(cpp2::impl::in<std::string> lhs, cpp2::impl::in<std::string> lhs_d, cpp2::impl::in<std::string> lhs_b, cpp2::impl::in<std::string> rhs, cpp2::impl::in<std::string> rhs_d, cpp2::impl::in<std::string> rhs_b, cpp2::impl::in<std::string> type, cpp2::impl::in<std::string> type_d, cpp2::impl::in<std::string> type_b) & -> void{
        CPP2_UFCS(add_forward)(diff, "" + cpp2::to_string(lhs_d) + ": " + cpp2::to_string(type_d) + " = " + cpp2::to_string(rhs_d) + ";\n");
        CPP2_UFCS(add_forward)(diff, "" + cpp2::to_string(lhs) + "  : " + cpp2::to_string(type) + " = " + cpp2::to_string(rhs) + ";\n");

        if (CPP2_UFCS(is_taylor)((*cpp2::impl::assert_not_null(ctx)))) {
            CPP2_UFCS(add_reverse_primal)(diff, "" + cpp2::to_string(lhs_d) + ": " + cpp2::to_string(type_d) + " = " + cpp2::to_string(rhs_d) + ";\n");
        }
        CPP2_UFCS(add_reverse_primal)(diff, "" + cpp2::to_string(lhs) + "  : " + cpp2::to_string(type) + " = " + cpp2::to_string(rhs) + ";\n");
        CPP2_UFCS(add_reverse_backprop)(diff, prepare_backprop(rhs_b, lhs, lhs_d, lhs_b));
    }
#line 4757 "reflect.h2"
    [[nodiscard]] auto autodiff_expression_handler::gen_declaration(cpp2::impl::in<std::string> lhs, cpp2::impl::in<std::string> lhs_d, cpp2::impl::in<std::string> lhs_b, cpp2::impl::in<std::string> rhs, cpp2::impl::in<std::string> rhs_d, cpp2::impl::in<std::string> rhs_b, cpp2::impl::in<std::string> type) & -> decltype(auto) { 
        return gen_declaration(lhs, lhs_d, lhs_b, rhs, rhs_d, rhs_b, type, CPP2_UFCS(get_fwd_ad_type)((*cpp2::impl::assert_not_null(ctx)), type), CPP2_UFCS(get_rws_ad_type)((*cpp2::impl::assert_not_null(ctx)), type));  }
#line 4759 "reflect.h2"
    [[nodiscard]] auto autodiff_expression_handler::gen_declaration(cpp2::impl::in<std::string> lhs, cpp2::impl::in<std::string> lhs_d, cpp2::impl::in<std::string> lhs_b, cpp2::impl::in<std::string> type) & -> decltype(auto) { 
        return gen_declaration(lhs, lhs_d, lhs_b, primal_expr, fwd_expr, rws_expr, type);  }
#line 4761 "reflect.h2"
    [[nodiscard]] auto autodiff_expression_handler::gen_declaration(cpp2::impl::in<std::string> lhs, cpp2::impl::in<std::string> type) & -> decltype(auto) { 
        return gen_declaration(lhs, lhs + (*cpp2::impl::assert_not_null(ctx)).fwd_suffix, lhs + (*cpp2::impl::assert_not_null(ctx)).rws_suffix, type);  }

        autodiff_expression_handler::primal_fwd_rws_name::primal_fwd_rws_name(auto&& primal_, auto&& fwd_, auto&& rws_, auto&& active_)
requires (std::is_convertible_v<CPP2_TYPEOF(primal_), std::add_const_t<std::string>&> && std::is_convertible_v<CPP2_TYPEOF(fwd_), std::add_const_t<std::string>&> && std::is_convertible_v<CPP2_TYPEOF(rws_), std::add_const_t<std::string>&> && std::is_convertible_v<CPP2_TYPEOF(active_), std::add_const_t<bool>&>) 
                                                                                                                                                        : primal{ CPP2_FORWARD(primal_) }
                                                                                                                                                        , fwd{ CPP2_FORWARD(fwd_) }
                                                                                                                                                        , rws{ CPP2_FORWARD(rws_) }
                                                                                                                                                        , active{ CPP2_FORWARD(active_) }{}
autodiff_expression_handler::primal_fwd_rws_name::primal_fwd_rws_name(){}

#line 4773 "reflect.h2"
    [[nodiscard]] auto autodiff_expression_handler::handle_expression_list(cpp2::impl::in<meta::expression_list> list) & -> std::vector<primal_fwd_rws_name>{
        std::vector<primal_fwd_rws_name> args {}; 
        for ( auto const& expr : CPP2_UFCS(get_expressions)(list) ) {
            CPP2_UFCS(push_back)(args, handle_expression_term(expr));
        }

        return args; 
    }

#line 4782 "reflect.h2"
    [[nodiscard]] auto autodiff_expression_handler::handle_expression_term(auto const& term) & -> primal_fwd_rws_name{
        if (CPP2_UFCS(is_identifier)(term)) {
            auto primal {CPP2_UFCS(to_string)(term)}; 
            auto fwd {primal + (*cpp2::impl::assert_not_null(ctx)).fwd_suffix}; 
            auto rws {primal + (*cpp2::impl::assert_not_null(ctx)).rws_suffix}; 

            auto decl {CPP2_UFCS(lookup_variable_declaration)((*cpp2::impl::assert_not_null(ctx)), primal)}; 
            if (decl.is_member) {
                fwd = "this" + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).fwd_suffix) + "." + fwd;
                rws = "this" + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).rws_suffix) + "." + rws;
            }

            if (cpp2::move(decl).is_active) {
                return { cpp2::move(primal), cpp2::move(fwd), cpp2::move(rws), true }; 
            }
            else {
                return { cpp2::move(primal), "", "", false }; 
            }

        }
        else {if (CPP2_UFCS(is_expression_list)(term)) {
            auto exprs {term.as_expression_list().get_expressions()}; 
            if (CPP2_UFCS(ssize)(exprs) != 1) {
                CPP2_UFCS(error)(term, "Can not handle multiple expressions. (term.to_string())");
                return { "error", "", "", false }; 
            }
            auto expr {CPP2_ASSERT_IN_BOUNDS_LITERAL(cpp2::move(exprs), 0)}; 
            auto bin_expr {expr.as_assignment_expression()}; 

            if (CPP2_UFCS(terms_size)(bin_expr) != 0) {
                CPP2_UFCS(error)(term, "Can not handle assign expr inside of expression. " + cpp2::to_string(CPP2_UFCS(to_string)(cpp2::move(expr))) + "");
                return { "error", "", "", false }; 
            }

            return handle_expression_term(CPP2_UFCS(get_term)(CPP2_UFCS(front)(CPP2_UFCS(get_terms)(cpp2::move(bin_expr))))); 
        }
        else {
            // Nothing special. A regular expression.
            auto expr {term}; 

            autodiff_activity_check ada {ctx}; 
            CPP2_UFCS(pre_traverse)(ada, expr);

            if (cpp2::move(ada).active) {

                autodiff_expression_handler ad {ctx}; 
                ad.pre_traverse(cpp2::move(expr));
                auto t {CPP2_UFCS(gen_temporary)((*cpp2::impl::assert_not_null(ctx)))}; 
                CPP2_UFCS(gen_declaration)(ad, t, "double");// TODO: get type of expression
                append(cpp2::move(ad));

                primal_fwd_rws_name r {t, t + (*cpp2::impl::assert_not_null(ctx)).fwd_suffix, t + (*cpp2::impl::assert_not_null(ctx)).rws_suffix, true}; // TODO: Check why on return (t, t + ctx*.fwd_suffix) the primal is initialized empty. Probably because of the move(t)
                static_cast<void>(cpp2::move(t));
                return r; 
            }
            else {
                return { CPP2_UFCS(to_string)(cpp2::move(expr)), "", "", false }; 
            }
        }}
    }

#line 4843 "reflect.h2"
    auto autodiff_expression_handler::handle_function_call(cpp2::impl::in<meta::postfix_expression> postfix, cpp2::impl::in<bool> has_return) & -> void{
        auto terms {CPP2_UFCS(get_terms)(postfix)}; 

        auto is_func {true}; 
{
auto i{0};

#line 4849 "reflect.h2"
        for (                     auto const& term : terms )  { do {
            if (CPP2_UFCS(get_op)(term) == ".") {
                continue;
            }
            if (CPP2_UFCS(get_op)(term) == "(" && i + 1 == CPP2_UFCS(ssize)(terms)) {// Function operator has to be the last
                continue;
            }

            is_func = false;
        } while (false); i += 1; }
}

        // Check for function call, everything else is not handled.
#line 4861 "reflect.h2"
        if (!((cpp2::move(is_func)))) {
            CPP2_UFCS(error)(postfix, "AD: Postfix expressions are only handled for function calls, or member function calls. Do not know how to handle: " + cpp2::to_string(CPP2_UFCS(to_string)(postfix)) + "");
            return ; 
        }

        std::string object {""}; 
        std::string object_d {""}; 
        std::string function_name {""}; 
        std::vector<primal_fwd_rws_name> args {}; 

        auto primary {CPP2_UFCS(get_primary_expression)(postfix)}; 

        if (1 != CPP2_UFCS(ssize)(terms)) {
            object   = CPP2_UFCS(to_string)(primary);
            object_d = CPP2_UFCS(to_string)(cpp2::move(primary)) + (*cpp2::impl::assert_not_null(ctx)).fwd_suffix;
        }
        else {
            function_name = CPP2_UFCS(to_string)(cpp2::move(primary));
        }
{
auto i{0};

#line 4882 "reflect.h2"
        for (                     auto const& term : terms )  { do {
            if (CPP2_UFCS(get_op)(term) == ".") {
                if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(is_id_expression)(term)) ) { cpp2::cpp2_default.report_violation(""); }
                auto name {CPP2_UFCS(to_string)(CPP2_UFCS(get_id_expression)(term))}; 

                if (i + 2 == CPP2_UFCS(ssize)(terms)) {// Second last term is function name, last term is function argument list
                    function_name = cpp2::move(name);
                }
                else {
                    object   += "." + name;
                    object_d += "." + cpp2::move(name) + (*cpp2::impl::assert_not_null(ctx)).fwd_suffix;
                }
            }
            else {if (CPP2_UFCS(get_op)(term) == "(") {
                if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(is_expression_list)(term)) ) { cpp2::cpp2_default.report_violation(""); }

                args = handle_expression_list(CPP2_UFCS(get_expression_list)(term));
            }
            else {
                CPP2_UFCS(error)(postfix, "AD: Do not know how to handle postfix term: " + cpp2::to_string(CPP2_UFCS(to_string)(term)) + "");
            }}
        } while (false); i += 1; }
}

#line 4905 "reflect.h2"
        if (handle_special_function(object, object_d, function_name, args)) {
            return ; 
        }

        if (CPP2_UFCS(contains)(object, ".")) {
            CPP2_UFCS(error)(postfix, "AD: can not handle nested member function calls: " + cpp2::to_string(CPP2_UFCS(to_string)(postfix)) + "");
            return ; 
        }

        // All arguments have now been handled. Form the function call
        std::string ret_temp {""}; 
        if (has_return) {
            ret_temp = CPP2_UFCS(gen_temporary)((*cpp2::impl::assert_not_null(ctx)));
            diff += "" + cpp2::to_string(ret_temp) + " := ";
        }

        // TODO: This is untested for functions with no return value. Requires handling of out and inout parameters in functions.
        if (!(CPP2_UFCS(empty)(object))) {// Prepend object call
            diff += "" + cpp2::to_string(object) + ".";
        }
        diff += "" + cpp2::to_string(function_name) + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).fwd_suffix) + "(";
        if (!(CPP2_UFCS(empty)(object))) {// Add this_d argument.
            diff += "" + cpp2::to_string(cpp2::move(object_d)) + ", ";
        }
        for ( auto const& arg : cpp2::move(args) ) {
            if (arg.active) {
                diff += "" + cpp2::to_string(arg.primal) + ", " + cpp2::to_string(arg.fwd) + ", ";
            }
            else {
                diff += "" + cpp2::to_string(arg.primal) + ", ";
            }
        }
        diff += ");\n";

        if (has_return) {
            std::vector<meta::function_declaration> functions {}; 
            if (!(CPP2_UFCS(empty)(object))) {
                auto obj_decl {CPP2_UFCS(lookup_variable_declaration)((*cpp2::impl::assert_not_null(ctx)), object)}; 
                auto obj_decl_types {CPP2_UFCS(lookup_type_declaration)((*cpp2::impl::assert_not_null(ctx)), obj_decl.decl)}; 

                if (CPP2_UFCS(empty)(obj_decl_types)) {
                    CPP2_UFCS(error)(postfix, "AD: Could not find type declaration for `" + cpp2::to_string(cpp2::move(object)) + " with type " + cpp2::to_string(cpp2::move(obj_decl).decl) + "`.\n"
                              "    If cpp2 object: this is an alpha limitation, please declare it befor the current declaration.\n"
                              "    If cpp function: please add a special handling for this member function.");
                    return ; 
                }
                functions = CPP2_UFCS(lookup_member_function_declaration)((*cpp2::impl::assert_not_null(ctx)), CPP2_ASSERT_IN_BOUNDS_LITERAL(obj_decl_types, 0), cpp2::move(function_name));

                CPP2_UFCS(add_for_differentiation)((*cpp2::impl::assert_not_null(ctx)), CPP2_ASSERT_IN_BOUNDS_LITERAL(cpp2::move(obj_decl_types), 0));// TODO: Add more fine grained differentiation.
            }
            else {
                functions = CPP2_UFCS(lookup_function_declaration)((*cpp2::impl::assert_not_null(ctx)), function_name);
                if (CPP2_UFCS(ssize)(functions) == 0) {
                    CPP2_UFCS(error)(postfix, "AD: Could not find function declaration for `" + cpp2::to_string(cpp2::move(function_name)) + "`.\n"
                                "    If cpp2 function: this is an alpha limitation, please declare it befor the current declaration.\n"
                                "    If cpp function: please add a special handling for this function.");
                    return ; 
                }
                else {if (CPP2_UFCS(ssize)(functions) != 1) {
                    CPP2_UFCS(error)(postfix, "AD: No handling for overload resultion is currently implemented.");
                    return ; 
                }}

                CPP2_UFCS(add_for_differentiation)((*cpp2::impl::assert_not_null(ctx)), CPP2_ASSERT_IN_BOUNDS_LITERAL(functions, 0));
            }

            std::string ret_name {"r"};   // Default for regular return.
            auto returns {CPP2_UFCS(get_returns)(CPP2_ASSERT_IN_BOUNDS_LITERAL(cpp2::move(functions), 0))}; 
            if (!(CPP2_UFCS(empty)(returns))) {
                if (CPP2_UFCS(ssize)(returns) != 1) {
                    CPP2_UFCS(error)(postfix, "AD: Expecting single return.");
                }

                for ( auto const& cur : cpp2::move(returns) ) {
                    ret_name = CPP2_UFCS(name)(CPP2_UFCS(get_declaration)(cur));
                }
            }

            std::string ret_name_d {ret_name + (*cpp2::impl::assert_not_null(ctx)).fwd_suffix}; 

            primal_expr = "" + cpp2::to_string(ret_temp) + "." + cpp2::to_string(cpp2::move(ret_name)) + "";
            fwd_expr    = "" + cpp2::to_string(cpp2::move(ret_temp)) + "." + cpp2::to_string(cpp2::move(ret_name_d)) + "";
        }

        // TODO: Add function to list of functions/objects for differentiation for the no return case.
    }

#line 4992 "reflect.h2"
    [[nodiscard]] auto autodiff_expression_handler::handle_special_function(cpp2::impl::in<std::string> object, cpp2::impl::in<std::string> object_d, cpp2::impl::in<std::string> function_name, cpp2::impl::in<std::vector<primal_fwd_rws_name>> args) & -> bool{

        auto r {CPP2_UFCS(lookup_special_function_handling)((*cpp2::impl::assert_not_null(ctx)), function_name, CPP2_UFCS(ssize)(args), !(CPP2_UFCS(empty)(object)))}; 

        if (!(r.m)) {
            return false; // No match
        }

        // Have a match, do the replacement
        std::string code_primal {r.code_primal}; 
        std::string code_fwd {cpp2::move(r).code_fwd}; 

        if (!(CPP2_UFCS(empty)(object))) {
            code_primal = string_util::replace_all(code_primal, "_o_", object);
            code_primal = string_util::replace_all(code_primal, "_od_", object_d);

            code_fwd = string_util::replace_all(code_fwd, "_o_", object);
            code_fwd = string_util::replace_all(code_fwd, "_od_", object_d);
        }
{
auto i{1};

#line 5013 "reflect.h2"
        for ( auto const& arg : args ) {
            code_primal = string_util::replace_all(code_primal, "_a" + cpp2::to_string(i) + "_", arg.primal);
            code_primal = string_util::replace_all(code_primal, "_ad" + cpp2::to_string(i) + "_", arg.fwd);

            code_fwd = string_util::replace_all(code_fwd, "_a" + cpp2::to_string(i) + "_", arg.primal);
            code_fwd = string_util::replace_all(code_fwd, "_ad" + cpp2::to_string(i) + "_", arg.fwd);
        }
}

#line 5021 "reflect.h2"
        primal_expr = cpp2::move(code_primal);
        fwd_expr    = cpp2::move(code_fwd);

        return true; 
    }

#line 5027 "reflect.h2"
    auto autodiff_expression_handler::traverse(cpp2::impl::in<meta::expression> expr) -> void{
        base::traverse(expr);
    }

#line 5031 "reflect.h2"
    auto autodiff_expression_handler::traverse(cpp2::impl::in<meta::assignment_expression> binexpr) -> void{
        CPP2_UFCS(error)(binexpr, "AD: Assign expressions are not yet handled.");
    }

#line 5035 "reflect.h2"
    auto autodiff_expression_handler::traverse(cpp2::impl::in<meta::logical_or_expression> binexpr) -> void{
        CPP2_UFCS(error)(binexpr, "AD: Logical or expressions are not yet handled.");
    }

#line 5039 "reflect.h2"
    auto autodiff_expression_handler::traverse(cpp2::impl::in<meta::logical_and_expression> binexpr) -> void{
        CPP2_UFCS(error)(binexpr, "AD: Logical and expressions are not yet handled.");
    }

#line 5043 "reflect.h2"
    auto autodiff_expression_handler::traverse(cpp2::impl::in<meta::bit_or_expression> binexpr) -> void{
        CPP2_UFCS(error)(binexpr, "AD: Bit or expressions are not yet handled.");
    }

#line 5047 "reflect.h2"
    auto autodiff_expression_handler::traverse(cpp2::impl::in<meta::bit_xor_expression> binexpr) -> void{
        CPP2_UFCS(error)(binexpr, "AD: Bit xor expressions are not yet handled.");
    }

#line 5051 "reflect.h2"
    auto autodiff_expression_handler::traverse(cpp2::impl::in<meta::bit_and_expression> binexpr) -> void{
        CPP2_UFCS(error)(binexpr, "AD: Bit and expressions are not yet handled.");
    }

#line 5055 "reflect.h2"
    auto autodiff_expression_handler::traverse(cpp2::impl::in<meta::equality_expression> binexpr) -> void{
        CPP2_UFCS(error)(binexpr, "AD: Equality or expressions are not yet handled.");
    }

#line 5059 "reflect.h2"
    auto autodiff_expression_handler::traverse(cpp2::impl::in<meta::relational_expression> binexpr) -> void{
        CPP2_UFCS(error)(binexpr, "AD: Relational expressions are not yet handled.");
    }

#line 5063 "reflect.h2"
    auto autodiff_expression_handler::traverse(cpp2::impl::in<meta::compare_expression> binexpr) -> void{
        CPP2_UFCS(error)(binexpr, "AD: Compare or expressions are not yet handled.");
    }

#line 5067 "reflect.h2"
    auto autodiff_expression_handler::traverse(cpp2::impl::in<meta::shift_expression> binexpr) -> void{
        CPP2_UFCS(error)(binexpr, "AD: Shift or expressions are not yet handled.");
    }

#line 5071 "reflect.h2"
    auto autodiff_expression_handler::traverse(cpp2::impl::in<meta::additive_expression> binexpr) -> void{
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 

        auto first {true}; 
        std::string op {"+"}; 
        std::string fwd {""}; 
        std::string rws {""}; 
        std::string primal {""}; 
        for ( auto const& term : cpp2::move(terms) ) {
            if (!(first)) {
                op      = CPP2_UFCS(to_string)(CPP2_UFCS(get_op)(term));
                fwd    += " " + cpp2::to_string(op) + " ";
                primal += " " + cpp2::to_string(op) + " ";

            }

            auto var {handle_expression_term(CPP2_UFCS(get_term)(term))}; 
            if (var.active) {
                fwd    += var.fwd;
                rws    += "" + cpp2::to_string(var.rws) + " " + cpp2::to_string(op) + "= _rb_;\n";
            }
            primal += cpp2::move(var).primal;

            first = false;
        }

        primal_expr = cpp2::move(primal);
        fwd_expr    = cpp2::move(fwd);
        rws_expr    = cpp2::move(rws);
    }

#line 5102 "reflect.h2"
    auto autodiff_expression_handler::traverse(cpp2::impl::in<meta::multiplicative_expression> binexpr) -> void{
        auto terms {CPP2_UFCS(get_terms)(binexpr)}; 

        auto var_a {handle_expression_term(CPP2_UFCS(get_term)(CPP2_ASSERT_IN_BOUNDS_LITERAL(terms, 0)))}; 

        int i {1}; 
        for( ; cpp2::impl::cmp_less(i,CPP2_UFCS(ssize)(terms)); i += 1 ) {
            auto var_b {handle_expression_term(CPP2_UFCS(get_term)(CPP2_ASSERT_IN_BOUNDS(terms, i)))}; 

            auto op {CPP2_UFCS(to_string)(CPP2_UFCS(get_op)(CPP2_ASSERT_IN_BOUNDS(terms, i)))}; 

            std::string fwd {""}; 
            std::string rws {""}; 
            std::string primal {""}; 

            if ("*" == op) {
                if (CPP2_UFCS(is_taylor)((*cpp2::impl::assert_not_null(ctx)))) {
                    // TODO: Add taylor overloads
                    fwd = "" + cpp2::to_string(var_a.fwd) + "..mul(" + cpp2::to_string(var_b.fwd) + ", " + cpp2::to_string(var_a.primal) + ", " + cpp2::to_string(var_b.primal) + ")";
                    if (var_a.active) {
                        //fwd += "(var_b.primal)$ * (var_a.fwd)$";
                        rws += "" + cpp2::to_string(var_a.rws) + " += " + cpp2::to_string(var_b.fwd) + "..mul(_rb_, " + cpp2::to_string(var_b.primal) + ", _r_);\n";
                    }
                    if (var_b.active) {
                        if (!(CPP2_UFCS(empty)(fwd))) {fwd += " + "; }
                        //fwd += "(var_a.primal)$ * (var_b.fwd)$";
                        rws = "" + cpp2::to_string(var_b.rws) + " += " + cpp2::to_string(var_a.fwd) + "..mul(_rb_, " + cpp2::to_string(var_a.primal) + ", _r_);\n";
                    }
                }
                else {
                    if (var_a.active) {
                        fwd += "" + cpp2::to_string(var_b.primal) + " * " + cpp2::to_string(var_a.fwd) + "";
                        rws += "" + cpp2::to_string(var_a.rws) + " += " + cpp2::to_string(var_b.primal) + " * _rb_;\n";
                    }
                    if (var_b.active) {
                        if (!(CPP2_UFCS(empty)(fwd))) {fwd += " + "; }
                        fwd += "" + cpp2::to_string(var_a.primal) + " * " + cpp2::to_string(var_b.fwd) + "";
                        rws = "" + cpp2::to_string(var_b.rws) + " += " + cpp2::to_string(var_a.primal) + " * _rb_;\n";
                    }
                }
                primal = "" + cpp2::to_string(var_a.primal) + " * " + cpp2::to_string(var_b.primal) + "";
            }
            else {if ("/" == op) {
                if (CPP2_UFCS(is_taylor)((*cpp2::impl::assert_not_null(ctx)))) {
                    // TODO: Add taylor overloads
                    fwd = "" + cpp2::to_string(var_a.fwd) + ".div(" + cpp2::to_string(var_b.fwd) + ", " + cpp2::to_string(var_a.primal) + ", " + cpp2::to_string(var_b.primal) + ")";
                    if (var_a.active) {
                        rws += "" + cpp2::to_string(var_a.rws) + " += _rb_.div(" + cpp2::to_string(var_b.fwd) + ", _r_, " + cpp2::to_string(var_b.primal) + ");\n";
                    }
                    if (var_b.active) {
                        rws += "" + cpp2::to_string(var_b.rws) + " -= " + cpp2::to_string(var_a.fwd) + ".mul(_rb_, " + cpp2::to_string(var_a.primal) + ", _r_).div(" + cpp2::to_string(var_b.fwd) + ".mul(" + cpp2::to_string(var_b.fwd) + ", " + cpp2::to_string(var_b.primal) + ", " + cpp2::to_string(var_b.primal) + "), " + cpp2::to_string(var_a.primal) + " * _r_, " + cpp2::to_string(var_b.primal) + " * " + cpp2::to_string(var_b.primal) + ");\n";
                    }
                }
                else {
                    if (var_a.active) {
                        fwd += "" + cpp2::to_string(var_a.fwd) + " / " + cpp2::to_string(var_b.primal) + "";
                        rws = "" + cpp2::to_string(var_a.rws) + " += _rb_ / " + cpp2::to_string(var_b.primal) + ";\n";
                    }
                    if (var_b.active) {
                        if (!(CPP2_UFCS(empty)(fwd))) {fwd += " + "; }
                        fwd += "-" + cpp2::to_string(var_a.primal) + " * " + cpp2::to_string(var_b.fwd) + " / (" + cpp2::to_string(var_b.primal) + " * " + cpp2::to_string(var_b.primal) + ")";
                        rws += "" + cpp2::to_string(var_b.rws) + " -= " + cpp2::to_string(var_a.primal) + " * _rb_ / (" + cpp2::to_string(var_b.primal) + " * " + cpp2::to_string(var_b.primal) + ");\n";
                    }
                }
                primal = "" + cpp2::to_string(var_a.primal) + " / " + cpp2::to_string(var_b.primal) + "";
            }
            else {
                CPP2_UFCS(error)(binexpr, "unkown multiplicative operator '" + cpp2::to_string(cpp2::move(op)) + "'");
            }}

#line 5173 "reflect.h2"
            if (i + 1 == CPP2_UFCS(ssize)(terms)) {
                primal_expr = cpp2::move(primal);
                fwd_expr    = cpp2::move(fwd);
                rws_expr    = cpp2::move(rws);
            }
            else {
                // Temporary
                var_a.primal = CPP2_UFCS(gen_temporary)((*cpp2::impl::assert_not_null(ctx)));
                var_a.fwd    = var_a.primal + (*cpp2::impl::assert_not_null(ctx)).fwd_suffix;
                var_a.rws    = var_a.primal + (*cpp2::impl::assert_not_null(ctx)).rws_suffix;
                var_a.active = var_a.active | cpp2::move(var_b).active;
                gen_declaration(var_a.primal, var_a.fwd, var_a.rws, primal, cpp2::move(fwd), cpp2::move(rws), "", "", "");
            }
        }
    }

#line 5189 "reflect.h2"
    auto autodiff_expression_handler::traverse(cpp2::impl::in<meta::is_as_expression> isas) -> void{
        CPP2_UFCS(error)(isas, "AD: Is as expressions are not yet handled.");
    }

#line 5193 "reflect.h2"
    auto autodiff_expression_handler::traverse(cpp2::impl::in<meta::prefix_expression> prefix) -> void
    {
        auto ops {CPP2_UFCS(get_ops)(prefix)}; 

        if (CPP2_UFCS(ssize)(ops) != 1) {
            CPP2_UFCS(error)(prefix, "AD: Can only handle one prefix operation. Expression is: " + cpp2::to_string(CPP2_UFCS(to_string)(prefix)) + "");
        }

        autodiff_expression_handler ad {ctx}; 
        CPP2_UFCS(pre_traverse)(ad, CPP2_UFCS(get_postfix_expression)(prefix));
        append(ad);

        primal_expr = CPP2_ASSERT_IN_BOUNDS_LITERAL(ops, 0) + ad.primal_expr;
        fwd_expr    = CPP2_ASSERT_IN_BOUNDS_LITERAL(cpp2::move(ops), 0) + cpp2::move(ad).fwd_expr;
    }

#line 5209 "reflect.h2"
    auto autodiff_expression_handler::traverse(cpp2::impl::in<meta::postfix_expression> postfix) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(postfix)}; 

        auto is_func {false}; 
{
auto i{0};

#line 5216 "reflect.h2"
        for (                     auto const& term : terms )  { do {
            if (CPP2_UFCS(get_op)(term) == ".") {
                continue;
            }
            if (CPP2_UFCS(get_op)(term) == "(" && i + 1 == CPP2_UFCS(ssize)(terms)) {// Function operator has to be the last
                is_func = true;
                continue;
            }
            else {
                CPP2_UFCS(error)(postfix, "AD: Unknown operator for postfix expression. op: " + cpp2::to_string(CPP2_UFCS(get_op)(term)) + " expr: " + cpp2::to_string(postfix) + "");
            }
        } while (false); i += 1; }
}

#line 5229 "reflect.h2"
        if (cpp2::move(is_func)) {
            handle_function_call(postfix, true);
        }
        else {
            // Member access

            auto primary {CPP2_UFCS(get_primary_expression)(postfix)}; 
            std::string obj_access {CPP2_UFCS(to_string)(cpp2::move(primary))}; 
            std::string obj_access_d {obj_access + (*cpp2::impl::assert_not_null(ctx)).fwd_suffix}; 

            for (         auto const& term : cpp2::move(terms) ) {
                obj_access   += CPP2_UFCS(get_op)(term) + CPP2_UFCS(to_string)(CPP2_UFCS(get_id_expression)(term));
                obj_access_d += CPP2_UFCS(get_op)(term) + CPP2_UFCS(to_string)(CPP2_UFCS(get_id_expression)(term)) + (*cpp2::impl::assert_not_null(ctx)).fwd_suffix;
            }

            primal_expr = cpp2::move(obj_access);
            fwd_expr    = cpp2::move(obj_access_d);
        }
    }

#line 5249 "reflect.h2"
    auto autodiff_expression_handler::traverse(cpp2::impl::in<meta::primary_expression> primary) -> void
    {
        if (CPP2_UFCS(is_identifier)(primary)) {
            primal_expr = CPP2_UFCS(to_string)(primary);
            fwd_expr    = add_suffix_if_not_wildcard(primal_expr, (*cpp2::impl::assert_not_null(ctx)).fwd_suffix);
            rws_expr    = add_suffix_if_not_wildcard(primal_expr, (*cpp2::impl::assert_not_null(ctx)).rws_suffix);

            auto decl {CPP2_UFCS(lookup_variable_declaration)((*cpp2::impl::assert_not_null(ctx)), primal_expr)}; 
            if (cpp2::move(decl).is_member) {
                fwd_expr = "this" + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).fwd_suffix) + "." + fwd_expr;
                rws_expr = "this" + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).rws_suffix) + "." + rws_expr;
            }
        }
        else {if (CPP2_UFCS(is_expression_list)(primary)) {
            if (CPP2_UFCS(is_empty)(CPP2_UFCS(as_expression_list)(primary))) {
                primal_expr = "()";
                fwd_expr    = "()";
                rws_expr    = "()";   // TODO: Check for reverse
            }
            else {
                CPP2_UFCS(error)(primary, "AD: Do not know how to handle non empty expression list inside of primary_expression: " + cpp2::to_string(CPP2_UFCS(to_string)(primary)) + "");
            }
        }
        else {if (CPP2_UFCS(is_literal)(primary)) {
            primal_expr = CPP2_UFCS(to_string)(primary);
            fwd_expr    = "()";
            rws_expr    = "()";  // TODO: Check for reverse
        }
        else {if (CPP2_UFCS(is_declaration)(primary)) {
            CPP2_UFCS(error)(primary, "AD: Do not know how to handle declaration inside of primary_expression: " + cpp2::to_string(CPP2_UFCS(to_string)(primary)) + "");
        }
        else {
            CPP2_UFCS(error)(primary, "AD: Unknown primary expression kind: " + cpp2::to_string(CPP2_UFCS(to_string)(primary)) + "");
        }}}}
    }

#line 5294 "reflect.h2"
    autodiff_stmt_handler::autodiff_stmt_handler(cpp2::impl::in<autodiff_context*> ctx_, cpp2::impl::in<meta::function_declaration> mf_)
        : simple_traverser{  }
        , autodiff_handler_base{ ctx_ }
        , mf{ mf_ }{

#line 5297 "reflect.h2"
    }

#line 5299 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::declaration> decl) -> void{
        base::traverse(decl);
    }

#line 5304 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::function_declaration> f) -> void{
        CPP2_UFCS(error)(f, "AD: Do not know how to handle function_declaration: " + cpp2::to_string(CPP2_UFCS(to_string)(f)) + "");
    }

#line 5309 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::object_declaration> o) -> void{
        std::string lhs {CPP2_UFCS(name)(o)}; 
        auto type {o.type()}; 

        auto active {false}; 
        if ("_" != type) {
            active = CPP2_UFCS(is_type_active)((*cpp2::impl::assert_not_null(ctx)), type);
        }
        else {
            if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(has_initializer)(o)) ) { cpp2::cpp2_default.report_violation(""); }

            autodiff_activity_check ada {ctx}; 
            CPP2_UFCS(pre_traverse)(ada, CPP2_UFCS(get_initializer)(o));
            active = cpp2::move(ada).active;
        }

        if (active) {

            auto fwd_ad_type {CPP2_UFCS(get_fwd_ad_type)((*cpp2::impl::assert_not_null(ctx)), type)}; 

            std::string prim_init {""}; 
            std::string fwd_init {""}; 

            if (CPP2_UFCS(has_initializer)(o)) {
                autodiff_expression_handler ad {ctx}; 
                CPP2_UFCS(pre_traverse)(ad, CPP2_UFCS(get_initializer)(o));
                append(ad);

                prim_init = " = " + ad.primal_expr;
                fwd_init  = " = " + ad.fwd_expr;

                if (type == "_" && cpp2::move(ad).fwd_expr == "()") {
                    // Special handling for auto initialization from a literal.
                    fwd_init = " = " + CPP2_UFCS(get_fwd_ad_type)((*cpp2::impl::assert_not_null(ctx)), "double") + "()";
                }
            }
            diff += "" + cpp2::to_string(lhs) + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).fwd_suffix) + " : " + cpp2::to_string(cpp2::move(fwd_ad_type)) + cpp2::to_string(cpp2::move(fwd_init)) + ";\n";
            diff += "" + cpp2::to_string(lhs) + "   : " + cpp2::to_string(type) + cpp2::to_string(cpp2::move(prim_init)) + ";\n";
        }
        else {
            diff += "" + cpp2::to_string(lhs) + ": " + cpp2::to_string(type) + "";
            if (CPP2_UFCS(has_initializer)(o)) {
                diff += " = " + cpp2::to_string(CPP2_UFCS(to_string)(CPP2_UFCS(get_initializer)(o))) + "";
            }
            diff += ";\n";
        }

        CPP2_UFCS(add_variable_declaration)((*cpp2::impl::assert_not_null(ctx)), cpp2::move(lhs), cpp2::move(type), cpp2::move(active));
    }

#line 5360 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::type_declaration> t) -> void{
        CPP2_UFCS(error)(t, "AD: Do not know how to handle type_declaration: " + cpp2::to_string(CPP2_UFCS(to_string)(t)) + "");
    }

#line 5365 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::parameter_declaration> t) -> void{
        CPP2_UFCS(error)(t, "AD: Do not know how to handle parameter_declaration: " + cpp2::to_string(CPP2_UFCS(to_string)(t)) + "");
    }

#line 5370 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::statement> stmt) -> void{
        base::traverse(stmt);
    }

#line 5375 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::compound_statement> stmt) -> void{
        // Brackets are handled by the
        diff += "{\n";
        base::traverse(stmt);
        diff += "}\n";
    }

#line 5383 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::return_statement> stmt) -> void{
        if (CPP2_UFCS(has_expression)(stmt)) {
            // Return with expression.
            // TODO: Remove assumptions
            //     - Return expression is always active. (Look this up in mf or so.)
            //     - Return was converted to a two parameter return with the name r.
            autodiff_expression_handler ad {ctx}; 
            ad.pre_traverse(CPP2_UFCS(get_expression)(stmt));
            CPP2_UFCS(gen_assignment)(ad, "r");
            append(cpp2::move(ad));
        }
        else {
            diff += "return;\n";
        }
    }

#line 5400 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::iteration_statement> stmt) -> void{
        if (CPP2_UFCS(is_while)(stmt)) {
            // TODO: Assumption is here that nothing is in the condition
            diff += "while " + cpp2::to_string(CPP2_UFCS(to_string)(CPP2_UFCS(get_do_while_condition)(stmt))) + " ";
            if (CPP2_UFCS(has_next)(stmt)) {
                // TODO: Assumption is here that nothing is in the next expression
                diff += "next " + cpp2::to_string(CPP2_UFCS(to_string)(CPP2_UFCS(get_next_expression)(stmt))) + " ";
            }

            pre_traverse(CPP2_UFCS(get_do_while_body)(stmt));
        }
        else {if (CPP2_UFCS(is_do)(stmt)) {
            // TODO: Assumption is here that nothing is in the condition
            diff += "do ";
            pre_traverse(CPP2_UFCS(get_do_while_body)(stmt));

            if (CPP2_UFCS(has_next)(stmt)) {
                // TODO: Assumption is here that nothing is in the next expression
                diff += "next " + cpp2::to_string(CPP2_UFCS(to_string)(CPP2_UFCS(get_next_expression)(stmt))) + " ";
            }
            diff += "while " + cpp2::to_string(CPP2_UFCS(to_string)(CPP2_UFCS(get_do_while_condition)(stmt))) + ";";
        }
        else {
            if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(is_for)(stmt)) ) { cpp2::cpp2_default.report_violation(""); }
            // No zip view available in cpp 20 do a piggy back for range

            // TODO: Assumption that this is just an id expression.
            auto range {CPP2_UFCS(to_string)(CPP2_UFCS(get_for_range)(stmt))}; 

            auto param {CPP2_UFCS(get_for_parameter)(stmt)}; 
            auto param_style {to_string_view(CPP2_UFCS(get_passing_style)(param))}; 
            auto param_decl {CPP2_UFCS(get_declaration)(cpp2::move(param))}; 
            diff += "(copy " + cpp2::to_string(CPP2_UFCS(name)(param_decl)) + "_d_iter := " + cpp2::to_string(range) + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).fwd_suffix) + ".begin())\n";
            diff += "for " + cpp2::to_string(cpp2::move(range)) + " next (";
            if (CPP2_UFCS(has_next)(stmt)) {
                // TODO: Assumption is here that nothing is in the next expression
                diff += "" + cpp2::to_string(CPP2_UFCS(to_string)(CPP2_UFCS(get_next_expression)(stmt))) + ", ";
            }
            diff += "" + cpp2::to_string(CPP2_UFCS(name)(param_decl)) + "_d_iter++";
            diff += ") do (" + cpp2::to_string(param_style) + " " + cpp2::to_string(CPP2_UFCS(name)(param_decl)) + ": " + cpp2::to_string(CPP2_UFCS(type)(param_decl)) + ") {\n";
            diff += "(" + cpp2::to_string(cpp2::move(param_style)) + " " + cpp2::to_string(CPP2_UFCS(name)(param_decl)) + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).fwd_suffix) + ": " + cpp2::to_string(CPP2_UFCS(type)(param_decl)) + " = " + cpp2::to_string(CPP2_UFCS(name)(param_decl)) + "_d_iter*)";

            CPP2_UFCS(add_variable_declaration)((*cpp2::impl::assert_not_null(ctx)), "" + cpp2::to_string(CPP2_UFCS(name)(param_decl)) + "", "" + cpp2::to_string(CPP2_UFCS(type)(param_decl)) + "", true);// TODO: Handle loop/compound context variable declarations.

            pre_traverse(CPP2_UFCS(get_for_body)(stmt));
            diff += "}\n";
        }}
    }

#line 5450 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::selection_statement> stmt) -> void{
        // TODO: Currently assuming that nothing bad happens in the condition
        diff += "if " + cpp2::to_string(CPP2_UFCS(to_string)(CPP2_UFCS(get_expression)(stmt))) + "";
        pre_traverse(CPP2_UFCS(get_true_branch)(stmt));

        if (CPP2_UFCS(has_false_branch)(stmt)) {
            diff += "else ";
            pre_traverse(CPP2_UFCS(get_false_branch)(stmt));
        }
    }

#line 5461 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::expression> expr) -> void{
        base::traverse(expr);
    }

#line 5465 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::assignment_expression> binexpr) -> void{
        autodiff_expression_handler h_lhs {ctx}; 
        CPP2_UFCS(pre_traverse)(h_lhs, CPP2_UFCS(get_lhs_postfix_expression)(binexpr));

        //  Cpp2 doesn't allow chained assignment, so rhs must be a single logical_or_expression
        auto assignment_terms {CPP2_UFCS(get_terms)(binexpr)}; 

        autodiff_expression_handler h {ctx}; 
        CPP2_UFCS(pre_traverse)(h, CPP2_UFCS(get_term)(CPP2_ASSERT_IN_BOUNDS_LITERAL(cpp2::move(assignment_terms), 1)));
        CPP2_UFCS(gen_assignment)(h, h_lhs.primal_expr, h_lhs.fwd_expr, cpp2::move(h_lhs).rws_expr);
        append(cpp2::move(h));
    }

#line 5478 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::logical_or_expression> binexpr) -> void{
        CPP2_UFCS(error)(binexpr, "AD: Logical or expressions are not yet handled as standalone statements.");
    }

#line 5482 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::logical_and_expression> binexpr) -> void{
        CPP2_UFCS(error)(binexpr, "AD: Logical and expressions are not yet handled as standalone statements.");
    }

#line 5486 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::bit_or_expression> binexpr) -> void{
        CPP2_UFCS(error)(binexpr, "AD: Bit or expressions are not yet handled as standalone statements.");
    }

#line 5490 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::bit_xor_expression> binexpr) -> void{
        CPP2_UFCS(error)(binexpr, "AD: Bit xor expressions are not yet handled as standalone statements.");
    }

#line 5494 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::bit_and_expression> binexpr) -> void{
        CPP2_UFCS(error)(binexpr, "AD: Bit and expressions are not yet handled as standalone statements.");
    }

#line 5498 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::equality_expression> binexpr) -> void{
        CPP2_UFCS(error)(binexpr, "AD: Equality or expressions are not yet handled as standalone statements.");
    }

#line 5502 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::relational_expression> binexpr) -> void{
        CPP2_UFCS(error)(binexpr, "AD: Relational expressions are not yet handled as standalone statements.");
    }

#line 5506 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::compare_expression> binexpr) -> void{
        CPP2_UFCS(error)(binexpr, "AD: Compare or expressions are not yet handled as standalone statements.");
    }

#line 5510 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::shift_expression> binexpr) -> void{
        CPP2_UFCS(error)(binexpr, "AD: Shift or expressions are not yet handled as standalone statements.");
    }

#line 5514 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::additive_expression> binexpr) -> void{
        CPP2_UFCS(error)(binexpr, "AD: Additive expressions are not yet handled as standalone statements.");
    }

#line 5518 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::multiplicative_expression> binexpr) -> void{
        CPP2_UFCS(error)(binexpr, "AD: Multiplicative expressions are not yet handled as standalone statements.");
    }

#line 5522 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::is_as_expression> isas) -> void{
        CPP2_UFCS(error)(isas, "AD: Is as expressions are not yet handled as standalone statements.");
    }

#line 5526 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::prefix_expression> prefix) -> void
    {
        CPP2_UFCS(error)(prefix, "AD: Prefix expressions are not yet handled as standalone statements.");
    }

#line 5531 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::postfix_expression> postfix) -> void
    {
        auto terms {CPP2_UFCS(get_terms)(postfix)}; 

        auto is_func {false}; 
{
auto i{0};

#line 5538 "reflect.h2"
        for (                     auto const& term : terms )  { do {
            if (CPP2_UFCS(get_op)(term) == ".") {
                continue;
            }
            if (CPP2_UFCS(get_op)(term) == "(" && i + 1 == CPP2_UFCS(ssize)(terms)) {// Function operator has to be the last
                is_func = true;
                continue;
            }else {
                CPP2_UFCS(error)(postfix, "AD: Unknown operator for standalone postfix expression. op: " + cpp2::to_string(CPP2_UFCS(get_op)(term)) + " expr: " + cpp2::to_string(postfix) + "");
            }
        } while (false); i += 1; }
}

        // Check for function call, everything else is not handled.
#line 5551 "reflect.h2"
        if (!((cpp2::move(is_func)))) {
            CPP2_UFCS(error)(postfix, "AD: Postfix expressions are only handled for function calls, or member function calls. Do not know how to handle: " + cpp2::to_string(CPP2_UFCS(to_string)(postfix)) + "");
            return ; 
        }

        autodiff_expression_handler ad {ctx}; 
        CPP2_UFCS(handle_function_call)(ad, postfix, false);
        ad.diff += ad.fwd_expr + "\n";
        ad.diff += ad.primal_expr + "\n";
        append(cpp2::move(ad));
    }

#line 5563 "reflect.h2"
    auto autodiff_stmt_handler::traverse(cpp2::impl::in<meta::primary_expression> primary) -> void
    {
        CPP2_UFCS(error)(primary, "AD: Primary expressions are not yet handled as standalone statements.");
    }

#line 5580 "reflect.h2"
    autodiff_declaration_handler::autodiff_declaration_handler(cpp2::impl::in<autodiff_context*> ctx_, cpp2::impl::in<meta::type_or_namespace_declaration> decl_)
        : simple_traverser{  }
        , autodiff_handler_base{ ctx_ }
        , decl{ decl_ }{

#line 5583 "reflect.h2"
    }

#line 5585 "reflect.h2"
    auto autodiff_declaration_handler::traverse(cpp2::impl::in<meta::declaration> decl) -> void{
        base::traverse(decl);
    }

#line 5590 "reflect.h2"
    auto autodiff_declaration_handler::traverse(cpp2::impl::in<meta::function_declaration> f) -> void{
        CPP2_UFCS(enter_function)((*cpp2::impl::assert_not_null(ctx)));

        // TODO: Add activity for member functions

        CPP2_UFCS(add_forward)(diff, "    " + cpp2::to_string(CPP2_UFCS(name)(f)) + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).fwd_suffix) + ": (");
        CPP2_UFCS(add_reverse_primal)(diff, "    " + cpp2::to_string(CPP2_UFCS(name)(f)) + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).rws_suffix) + ": (");

        //  1. Generate the modified signature
        //  a) Parameters

        for ( auto const& param : CPP2_UFCS(get_parameters)(f) ) {
            std::string name {CPP2_UFCS(name)(CPP2_UFCS(get_declaration)(param))}; 

            auto fwd_pass_style {to_string_view(CPP2_UFCS(get_passing_style)(param))}; 
            auto rws_pass_style {to_string_view(CPP2_UFCS(get_reverse_passing_style)((*cpp2::impl::assert_not_null(ctx)), CPP2_UFCS(get_passing_style)(param)))}; 

            if ("this" ==  name) {
                auto fwd_ad_type {CPP2_UFCS(get_fwd_ad_type)((*cpp2::impl::assert_not_null(ctx)), std::string(CPP2_UFCS(name)(decl)))}; 
                auto rws_ad_type {CPP2_UFCS(get_rws_ad_type)((*cpp2::impl::assert_not_null(ctx)), std::string(CPP2_UFCS(name)(decl)))}; 

                CPP2_UFCS(add_forward)(diff, "" + cpp2::to_string(fwd_pass_style) + " " + cpp2::to_string(name) + ", ");
                CPP2_UFCS(add_forward)(diff, "" + cpp2::to_string(fwd_pass_style) + " " + cpp2::to_string(name) + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).fwd_suffix) + ": " + cpp2::to_string(fwd_ad_type) + ", ");

                CPP2_UFCS(add_reverse_primal)(diff, "" + cpp2::to_string(fwd_pass_style) + " " + cpp2::to_string(name) + ", ");
                if (CPP2_UFCS(is_taylor)((*cpp2::impl::assert_not_null(ctx)))) {// Add forward type for higher order
                    CPP2_UFCS(add_reverse_primal)(diff, "" + cpp2::to_string(cpp2::move(fwd_pass_style)) + " " + cpp2::to_string(name) + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).fwd_suffix) + ": " + cpp2::to_string(cpp2::move(fwd_ad_type)) + ", ");
                }
                CPP2_UFCS(add_reverse_primal)(diff, "" + cpp2::to_string(cpp2::move(rws_pass_style)) + " " + cpp2::to_string(cpp2::move(name)) + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).rws_suffix) + ": " + cpp2::to_string(cpp2::move(rws_ad_type)) + ", ");
            }
            else {
                auto type {CPP2_UFCS(get_declaration)(param).type()}; 

                autodiff_activity_check ada {ctx}; 
                CPP2_UFCS(pre_traverse)(ada, param);

                if (ada.active) {
                    CPP2_UFCS(add_forward)(diff, "" + cpp2::to_string(fwd_pass_style) + " " + cpp2::to_string(name) + " : " + cpp2::to_string(type) + ", ");
                    CPP2_UFCS(add_forward)(diff, "" + cpp2::to_string(fwd_pass_style) + " " + cpp2::to_string(name) + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).fwd_suffix) + " : " + cpp2::to_string(CPP2_UFCS(get_fwd_ad_type)((*cpp2::impl::assert_not_null(ctx)), type)) + ", ");

                    CPP2_UFCS(add_reverse_primal)(diff, "" + cpp2::to_string(fwd_pass_style) + " " + cpp2::to_string(name) + " : " + cpp2::to_string(type) + ", ");
                    if (CPP2_UFCS(is_taylor)((*cpp2::impl::assert_not_null(ctx)))) {
                        CPP2_UFCS(add_reverse_primal)(diff, "" + cpp2::to_string(cpp2::move(fwd_pass_style)) + " " + cpp2::to_string(name) + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).fwd_suffix) + " : " + cpp2::to_string(CPP2_UFCS(get_fwd_ad_type)((*cpp2::impl::assert_not_null(ctx)), type)) + ", ");
                    }
                    CPP2_UFCS(add_reverse_primal)(diff, "" + cpp2::to_string(cpp2::move(rws_pass_style)) + " " + cpp2::to_string(name) + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).rws_suffix) + " : " + cpp2::to_string(CPP2_UFCS(get_rws_ad_type)((*cpp2::impl::assert_not_null(ctx)), type)) + ", ");
                }
                else {
                    CPP2_UFCS(add_forward)(diff, "" + cpp2::to_string(fwd_pass_style) + " " + cpp2::to_string(name) + " : " + cpp2::to_string(type) + ", ");
                    CPP2_UFCS(add_reverse_primal)(diff, "" + cpp2::to_string(cpp2::move(fwd_pass_style)) + " " + cpp2::to_string(name) + " : " + cpp2::to_string(type) + ", ");
                }

                CPP2_UFCS(add_variable_declaration)((*cpp2::impl::assert_not_null(ctx)), cpp2::move(name), cpp2::move(type), cpp2::move(ada).active);
            }
        }

        //  b) Add arguments for returns that become inputs

        if (CPP2_UFCS(has_non_void_return_type)(f) && CPP2_UFCS(empty)(CPP2_UFCS(get_returns)(f))) {// TODO: has_non_void_return_type is true for return lists: (r: double) bug/feature?
            // TODO: check if name "r" is available. (Also needs inspection of functions at call sides.)
            if (CPP2_UFCS(has_deduced_return_type)(f)) {
                // TODO: Take care of initialization order error.
                CPP2_UFCS(add_reverse_primal)(diff, "inout r" + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).rws_suffix) + ", ");
            }
            else {
                CPP2_UFCS(add_reverse_primal)(diff, "inout r" + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).rws_suffix) + ": " + cpp2::to_string(CPP2_UFCS(get_rws_ad_type)((*cpp2::impl::assert_not_null(ctx)), CPP2_UFCS(get_unnamed_return_type)(f))) + ", ");
            }
        }
        else {
            for ( auto const& param : CPP2_UFCS(get_returns)(f) ) {
                auto name {CPP2_UFCS(get_declaration)(param).name()}; 
                auto type {CPP2_UFCS(get_declaration)(param).type()}; 

                auto rws_pass_style {to_string_view(CPP2_UFCS(get_reverse_passing_style)((*cpp2::impl::assert_not_null(ctx)), CPP2_UFCS(get_passing_style)(param)))}; 
                CPP2_UFCS(add_reverse_primal)(diff, "" + cpp2::to_string(cpp2::move(rws_pass_style)) + " " + cpp2::to_string(cpp2::move(name)) + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).rws_suffix) + " : " + cpp2::to_string(CPP2_UFCS(get_rws_ad_type)((*cpp2::impl::assert_not_null(ctx)), cpp2::move(type))) + " , ");
            }
        }

        CPP2_UFCS(add_forward)(diff, ") -> (");
        CPP2_UFCS(add_reverse_primal)(diff, ") -> (");

        //  c) Returns

        if (CPP2_UFCS(has_non_void_return_type)(f) && CPP2_UFCS(empty)(CPP2_UFCS(get_returns)(f))) {// TODO: has_non_void_return_type is true for return lists: (r: double) bug/feature?
            // TODO: check if name "r" is available. (Also needs inspection of functions at call sides.)
            if (CPP2_UFCS(has_deduced_return_type)(f)) {
                // TODO: Take care of initialization order error.
                CPP2_UFCS(add_forward)(diff, "r, r" + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).fwd_suffix) + ", ");
                CPP2_UFCS(add_reverse_primal)(diff, "r, ");
                if (CPP2_UFCS(is_taylor)((*cpp2::impl::assert_not_null(ctx)))) {
                    CPP2_UFCS(add_reverse_primal)(diff, "r" + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).fwd_suffix) + ",");
                }
            }
            else {
                CPP2_UFCS(add_forward)(diff, "r: " + cpp2::to_string(CPP2_UFCS(get_unnamed_return_type)(f)) + " = (), r" + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).fwd_suffix) + ": " + cpp2::to_string(CPP2_UFCS(get_fwd_ad_type)((*cpp2::impl::assert_not_null(ctx)), CPP2_UFCS(get_unnamed_return_type)(f))) + " = (), ");
                CPP2_UFCS(add_reverse_primal)(diff, "r: " + cpp2::to_string(CPP2_UFCS(get_unnamed_return_type)(f)) + " = (), ");
                if (CPP2_UFCS(is_taylor)((*cpp2::impl::assert_not_null(ctx)))) {
                    CPP2_UFCS(add_reverse_primal)(diff, "r" + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).fwd_suffix) + ": " + cpp2::to_string(CPP2_UFCS(get_fwd_ad_type)((*cpp2::impl::assert_not_null(ctx)), CPP2_UFCS(get_unnamed_return_type)(f))) + " = (), ");
                }
            }
        }
        else {
            for ( auto const& param : CPP2_UFCS(get_returns)(f) ) {
                auto name {CPP2_UFCS(get_declaration)(param).name()}; 
                auto type {CPP2_UFCS(get_declaration)(param).type()}; 

                auto fwd_pass_style {to_string_view(CPP2_UFCS(get_passing_style)(param))}; 
                auto rws_pass_style {to_string_view(CPP2_UFCS(get_reverse_passing_style)((*cpp2::impl::assert_not_null(ctx)), CPP2_UFCS(get_passing_style)(param)))}; 
                CPP2_UFCS(add_forward)(diff, "" + cpp2::to_string(fwd_pass_style) + " " + cpp2::to_string(name) + " : " + cpp2::to_string(CPP2_UFCS(type)(CPP2_UFCS(get_declaration)(param))) + " = 0.0, ");
                CPP2_UFCS(add_forward)(diff, "" + cpp2::to_string(fwd_pass_style) + " " + cpp2::to_string(name) + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).fwd_suffix) + " : " + cpp2::to_string(CPP2_UFCS(get_fwd_ad_type)((*cpp2::impl::assert_not_null(ctx)), type)) + " = 0.0, ");

                CPP2_UFCS(add_reverse_primal)(diff, "" + cpp2::to_string(fwd_pass_style) + " " + cpp2::to_string(name) + " : " + cpp2::to_string(CPP2_UFCS(type)(CPP2_UFCS(get_declaration)(param))) + " = 0.0, ");
                if (CPP2_UFCS(is_taylor)((*cpp2::impl::assert_not_null(ctx)))) {
                    CPP2_UFCS(add_reverse_primal)(diff, "" + cpp2::to_string(cpp2::move(fwd_pass_style)) + " " + cpp2::to_string(name) + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).fwd_suffix) + " : " + cpp2::to_string(CPP2_UFCS(get_fwd_ad_type)((*cpp2::impl::assert_not_null(ctx)), type)) + " = 0.0, ");
                }

                CPP2_UFCS(add_variable_declaration)((*cpp2::impl::assert_not_null(ctx)), "" + cpp2::to_string(cpp2::move(name)) + "", "" + cpp2::to_string(cpp2::move(type)) + "", true);// TODO_a: Add acitivty check
            }
        }

        CPP2_UFCS(add_forward)(diff, ") = {");
        CPP2_UFCS(add_reverse_primal)(diff, ") = {");

        //  Generate the body

        if (!(CPP2_UFCS(has_compound_body)(f))) {
            CPP2_UFCS(error)(f, "temporary alpha limitation: a differentiable function must have a {}-enclosed body");
            return ; 
        }

#line 5720 "reflect.h2"
        autodiff_stmt_handler ad_impl {&*cpp2::impl::assert_not_null(ctx), f}; 

#line 5723 "reflect.h2"
        for ( auto const& stmt : CPP2_UFCS(get_statements)(CPP2_UFCS(get_compound_body)(f)) ) 
        {
            ad_impl.pre_traverse(stmt);
        }
        CPP2_UFCS(add_forward)(diff, ad_impl.diff.fwd);
        CPP2_UFCS(add_reverse_primal)(diff, ad_impl.diff.rws_primal);
        CPP2_UFCS(add_reverse_primal)(diff, cpp2::move(ad_impl).diff.rws_backprop);

        CPP2_UFCS(add_forward)(diff, "}");
        CPP2_UFCS(add_reverse_primal)(diff, "}");

        CPP2_UFCS(leave_function)((*cpp2::impl::assert_not_null(ctx)));

        if (CPP2_UFCS(is_forward)((*cpp2::impl::assert_not_null(ctx)))) {
            CPP2_UFCS(add_member)(decl, diff.fwd);
        }
        if (CPP2_UFCS(is_reverse)((*cpp2::impl::assert_not_null(ctx)))) {
            CPP2_UFCS(add_member)(decl, diff.rws_primal);
        }
        CPP2_UFCS(reset)(diff);

        CPP2_UFCS(add_as_differentiated)((*cpp2::impl::assert_not_null(ctx)), f);
    }

#line 5748 "reflect.h2"
    auto autodiff_declaration_handler::traverse(cpp2::impl::in<meta::object_declaration> o) -> void{
        std::string ad_name {"" + cpp2::to_string(CPP2_UFCS(name)(o)) + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).fwd_suffix) + ""}; 
        std::string fwd_ad_type {CPP2_UFCS(get_fwd_ad_type)((*cpp2::impl::assert_not_null(ctx)), CPP2_UFCS(type)(o))}; 
        std::string ad_init {""}; 

        if (CPP2_UFCS(has_initializer)(o)) {
            autodiff_expression_handler ad {ctx}; 
            CPP2_UFCS(pre_traverse)(ad, CPP2_UFCS(get_initializer)(o));

            if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(empty)(ad.diff)) ) { cpp2::cpp2_default.report_violation(""); }
            ad_init = " = " + cpp2::move(ad).fwd_expr;
        }

        diff = "" + cpp2::to_string(cpp2::move(ad_name)) + " : " + cpp2::to_string(cpp2::move(fwd_ad_type)) + cpp2::to_string(cpp2::move(ad_init)) + ";";

        if (is_type_context) {

            diff_ad_type += "public " + cpp2::to_string(diff.fwd) + "\n";
        }
        else {
            CPP2_UFCS(add_member)(decl, diff.fwd);
        }
        diff = "";

        CPP2_UFCS(add_variable_declaration)((*cpp2::impl::assert_not_null(ctx)), "" + cpp2::to_string(CPP2_UFCS(name)(o)) + "", "" + cpp2::to_string(CPP2_UFCS(type)(o)) + "", true, true);// TODO_a: Add acitivty check
    }

#line 5776 "reflect.h2"
    auto autodiff_declaration_handler::traverse(cpp2::impl::in<meta::type_declaration> t) -> void{
        CPP2_UFCS(push_stack)((*cpp2::impl::assert_not_null(ctx)), t);
        autodiff_declaration_handler ad {ctx, t}; 
        ad.is_type_context = true;

        for ( 
             auto const& m : CPP2_UFCS(get_members)(t) ) 
        {
            CPP2_UFCS(pre_traverse)(ad, m);
        }

        CPP2_UFCS(pop_stack)((*cpp2::impl::assert_not_null(ctx)));

        if (!(CPP2_UFCS(empty)(ad.diff_ad_type))) {
            diff = "" + cpp2::to_string(CPP2_UFCS(name)(t)) + cpp2::to_string((*cpp2::impl::assert_not_null(ctx)).fwd_suffix) + " : type = {\n";
            diff += "" + cpp2::to_string(cpp2::move(ad).diff_ad_type) + "";
            diff += "}";

            CPP2_UFCS(add_member)(decl, diff.fwd);
            diff = "";
        }
    }

#line 5800 "reflect.h2"
    auto autodiff_declaration_handler::traverse(cpp2::impl::in<meta::parameter_declaration> t) -> void{
        CPP2_UFCS(error)(t, "AD: Do not know how to handle parameter_declaration: " + cpp2::to_string(CPP2_UFCS(to_string)(t)) + "");
    }

#line 5805 "reflect.h2"
    auto autodiff_declaration_handler::traverse(cpp2::impl::in<meta::statement> stmt) -> void{
        CPP2_UFCS(error)(stmt, "AD: Do not know how to handle statement in declaration context: " + cpp2::to_string(CPP2_UFCS(to_string)(stmt)) + "");
    }

#line 5811 "reflect.h2"
auto autodiff(meta::type_declaration& t) -> void
{

    std::string_view constexpr suffix_token{ "suffix=" };
    std::string_view constexpr rws_suffix_token{ "rws_suffix=" };
    std::string_view constexpr order_token{ "order=" };
    std::string_view constexpr reverse_token{ "reverse" };

    auto args {CPP2_UFCS(get_arguments)(t)}; 

    std::string suffix {"_d"}; 
    std::string rws_suffix {"_b"}; 
    int order {1}; 
    bool reverse {false}; 
    for ( auto const& arg_str : cpp2::move(args) ) {
        if (CPP2_UFCS(starts_with)(arg_str, "\"") && CPP2_UFCS(ends_with)(arg_str, "\"")) {
            auto arg {CPP2_UFCS(substr)(arg_str, 1, CPP2_UFCS(ssize)(arg_str) - 2)}; 

            if (CPP2_UFCS(starts_with)(arg, suffix_token)) {
                suffix = CPP2_UFCS(substr)(cpp2::move(arg), CPP2_UFCS(size)(suffix_token));
                continue;
            }
            else {if (CPP2_UFCS(starts_with)(arg, rws_suffix_token)) {
                suffix = CPP2_UFCS(substr)(cpp2::move(arg), CPP2_UFCS(size)(rws_suffix_token));
                continue;
            }
            else {if (CPP2_UFCS(starts_with)(arg, order_token)) {
                if (!(string_util::string_to_int(CPP2_UFCS(substr)(arg, CPP2_UFCS(size)(order_token)), order))) {
                    CPP2_UFCS(error)(t, "AD: Could not parse derivative order: " + cpp2::to_string(CPP2_UFCS(substr)(cpp2::move(arg), CPP2_UFCS(size)(order_token))) + "");
                    return ; 
                }
                continue;
            }
            else {if (cpp2::move(arg) == reverse_token) {
                reverse = true;
                continue;
            }}}}
        }

        CPP2_UFCS(error)(t, "AD: Unknown argument: " + cpp2::to_string(arg_str) + "");
        return ; 
    }

    autodiff_context ad_ctx {order, cpp2::move(reverse)}; 
    ad_ctx.fwd_suffix = cpp2::move(suffix);
    ad_ctx.rws_suffix = cpp2::move(rws_suffix);

    if (CPP2_UFCS(parent_is_nonglobal_namespace)(t)) {
        auto p {CPP2_UFCS(as_nonglobal_namespace)(CPP2_UFCS(get_parent)(t))}; 
        CPP2_UFCS(create_namespace_stack)(ad_ctx, p);
        autodiff_declaration_handler ad {&ad_ctx, cpp2::move(p)}; 
        CPP2_UFCS(pre_traverse)(cpp2::move(ad), t);

    }
    else {if (CPP2_UFCS(parent_is_type)(t)) {
        auto p {CPP2_UFCS(as_type)(CPP2_UFCS(get_parent)(t))}; 
        CPP2_UFCS(create_namespace_stack)(ad_ctx, p);
        autodiff_declaration_handler ad {&ad_ctx, cpp2::move(p)}; 
        CPP2_UFCS(pre_traverse)(cpp2::move(ad), t);
    }
    else {
        // TODO: Remove when global namespace is available.
        // Traverse without parent context
        CPP2_UFCS(push_stack)(ad_ctx, t);
        autodiff_declaration_handler ad {&ad_ctx, t}; 

        for ( 
             auto const& m : CPP2_UFCS(get_members)(t) ) 
        if ( CPP2_UFCS(is_function)(m)) 
        {
            CPP2_UFCS(pre_traverse)(ad, m);
        }
        CPP2_UFCS(pop_stack)(ad_ctx);
    }}

    if (1 != cpp2::move(order)) {
        CPP2_UFCS(add_runtime_support_include)(t, "cpp2taylor.h");
    }

    CPP2_UFCS(finish)(ad_ctx);

    static_cast<void>(cpp2::move(ad_ctx));
}


constexpr expression_flags::expression_flags(cpp2::impl::in<cpp2::i64> _val)
                                                          : _value{ cpp2::unchecked_narrow<cpp2::u8>(_val) } {  }

constexpr auto expression_flags::operator=(cpp2::impl::in<cpp2::i64> _val) -> expression_flags&  { 
                                                          _value = cpp2::unchecked_narrow<cpp2::u8>(_val);
                                                          return *this; }
constexpr auto expression_flags::operator|=(expression_flags const& that) & -> decltype(auto) { return _value |= that._value; }
constexpr auto expression_flags::operator&=(expression_flags const& that) & -> decltype(auto) { return _value &= that._value; }
constexpr auto expression_flags::operator^=(expression_flags const& that) & -> decltype(auto) { return _value ^= that._value; }
[[nodiscard]] constexpr auto expression_flags::operator|(expression_flags const& that) const& -> expression_flags { return _value | that._value; }
[[nodiscard]] constexpr auto expression_flags::operator&(expression_flags const& that) const& -> expression_flags { return _value & that._value; }
[[nodiscard]] constexpr auto expression_flags::operator^(expression_flags const& that) const& -> expression_flags { return _value ^ that._value; }
[[nodiscard]] constexpr auto expression_flags::has(expression_flags const& that) const& -> bool { return _value & that._value; }
constexpr auto expression_flags::set(expression_flags const& that) & -> void{_value |= that._value;}
constexpr auto expression_flags::clear(expression_flags const& that) & -> void{_value &= ~that._value;}
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
[[nodiscard]] auto expression_flags::to_string_impl(cpp2::impl::in<std::string_view> prefix, cpp2::impl::in<std::string_view> separator) const& -> std::string{

std::string ret {"("}; 

std::string sep {}; 
if ((*this) == none) {return "(none)"; }

auto pref {cpp2::to_string(prefix)}; 
if (((*this) & expression_flags::case_insensitive) == expression_flags::case_insensitive) {ret += sep + pref + "case_insensitive";sep = separator;}
if (((*this) & expression_flags::multiple_lines) == expression_flags::multiple_lines) {ret += sep + pref + "multiple_lines";sep = separator;}
if (((*this) & expression_flags::single_line) == expression_flags::single_line) {ret += sep + pref + "single_line";sep = separator;}
if (((*this) & expression_flags::no_group_captures) == expression_flags::no_group_captures) {ret += sep + pref + "no_group_captures";sep = separator;}
if (((*this) & expression_flags::perl_code_syntax) == expression_flags::perl_code_syntax) {ret += sep + pref + "perl_code_syntax";sep = separator;}
if (((*this) & expression_flags::perl_code_syntax_in_classes) == expression_flags::perl_code_syntax_in_classes) {ret += sep + cpp2::move(pref) + "perl_code_syntax_in_classes";sep = separator;}
return cpp2::move(ret) + ")"; 
}

[[nodiscard]] auto expression_flags::to_string() const& -> std::string { return to_string_impl("", ", "); }
[[nodiscard]] auto expression_flags::to_code() const& -> std::string { return to_string_impl("expression_flags::", " | "); }
[[nodiscard]] auto expression_flags::from_string(cpp2::impl::in<std::string_view> s) -> expression_flags{

auto ret {none}; 
do {{
for ( auto const& x : cpp2::string_util::split_string_list(s) ) {
if ("case_insensitive" == x) {ret |= expression_flags::case_insensitive;}
else {if ("multiple_lines" == x) {ret |= expression_flags::multiple_lines;}
else {if ("single_line" == x) {ret |= expression_flags::single_line;}
else {if ("no_group_captures" == x) {ret |= expression_flags::no_group_captures;}
else {if ("perl_code_syntax" == x) {ret |= expression_flags::perl_code_syntax;}
else {if ("perl_code_syntax_in_classes" == x) {ret |= expression_flags::perl_code_syntax_in_classes;}
else {if ("none" == x) {ret |= expression_flags::none;}
else {goto BREAK_outer;}
#line 1 "reflect.h2"
}}}}}}
}

return ret; 
} CPP2_CONTINUE_BREAK(outer) }
 while ( 
false
);
CPP2_UFCS(report_violation)(cpp2::type_safety, CPP2_UFCS(c_str)(("can't convert string '" + cpp2::to_string(s) + "' to flag_enum of type expression_flags")));
return expression_flags::none; 
}

[[nodiscard]] auto expression_flags::from_code(cpp2::impl::in<std::string_view> s) -> expression_flags{
std::string str {s}; return from_string(cpp2::string_util::replace_all(cpp2::move(str), "expression_flags::", "")); }

#line 5896 "reflect.h2"
//-----------------------------------------------------------------------
//
//  regex - creates regular expressions from members
//
//  Each member that starts with `regex` is replaced by a regular expression
//  of the initializer string. E.g.:
//  ```
//    regex := "ab";
//  ```
//  is replaced with
//  ```
//    regex := ::cpp2::regex::regular_expression<...>;
//  ```
//

#line 5912 "reflect.h2"
//  Possible modifiers for a regular expression.
//

#line 5916 "reflect.h2"
                                  // mod: i
                                  // mod: m
                                  // mod: s
                                  // mod: n
                                  // mod: x
                                  // mod: xx

#line 5925 "reflect.h2"
//  Tokens for regular expressions.
//

// Basic class for a regex token.
//

#line 5934 "reflect.h2"
    regex_token::regex_token(cpp2::impl::in<std::string> str)
        : string_rep{ str }{

#line 5936 "reflect.h2"
    }

#line 5938 "reflect.h2"
    regex_token::regex_token()
        : string_rep{ "" }{

#line 5940 "reflect.h2"
    }

    //parse: (inout ctx: parse_context) -> token_ptr;
                                                                       // Generate the matching code.
                                                                       // Create a reverse token for look behind expressions.

#line 5946 "reflect.h2"
    auto regex_token::add_groups([[maybe_unused]] std::set<int>& unnamed_param_2) const -> void{}// Adds all group indices to the set.
#line 5947 "reflect.h2"
    [[nodiscard]] auto regex_token::to_string() const& -> std::string{return string_rep; }// Create a string representation.
#line 5948 "reflect.h2"
    auto regex_token::set_string(cpp2::impl::in<std::string> s) & -> void{string_rep = s; }

    regex_token::~regex_token() noexcept{}// Set the string representation.

#line 5963 "reflect.h2"
    regex_token_check::regex_token_check(cpp2::impl::in<std::string> str, cpp2::impl::in<std::string> check_)
        : regex_token{ str }
        , check{ check_ }{

#line 5966 "reflect.h2"
    }

#line 5968 "reflect.h2"
    auto regex_token_check::generate_code(generation_context& ctx) const -> void{
        ctx.add_check(check + "(" + ctx.match_parameters() + ")");
    }

#line 5972 "reflect.h2"
    [[nodiscard]] auto regex_token_check::reverse() const -> token_ptr { return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_check>)(cpp2::shared, CPP2_UFCS(to_string)((*this)), (*this).check);  }

    regex_token_check::~regex_token_check() noexcept{}

#line 5984 "reflect.h2"
    regex_token_code::regex_token_code(cpp2::impl::in<std::string> str, cpp2::impl::in<std::string> code_)
        : regex_token{ str }
        , code{ code_ }{

#line 5987 "reflect.h2"
    }

#line 5989 "reflect.h2"
    auto regex_token_code::generate_code(generation_context& ctx) const -> void{
        ctx.add(code);
    }

#line 5993 "reflect.h2"
    [[nodiscard]] auto regex_token_code::reverse() const -> token_ptr { return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_code>)(cpp2::shared, CPP2_UFCS(to_string)((*this)), (*this).code);  }

    regex_token_code::~regex_token_code() noexcept{}

#line 6003 "reflect.h2"
    regex_token_empty::regex_token_empty(cpp2::impl::in<std::string> str)
        : regex_token{ str }{

#line 6005 "reflect.h2"
    }

#line 6007 "reflect.h2"
    auto regex_token_empty::generate_code([[maybe_unused]] generation_context& unnamed_param_2) const -> void{
        // Nothing.
    }

#line 6011 "reflect.h2"
    [[nodiscard]] auto regex_token_empty::reverse() const -> token_ptr { return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_empty>)(cpp2::shared, CPP2_UFCS(to_string)((*this)));  }

    regex_token_empty::~regex_token_empty() noexcept{}

#line 6023 "reflect.h2"
    regex_token_list::regex_token_list(cpp2::impl::in<token_vec> t)
        : regex_token{ gen_string(t) }
        , tokens{ t }{

#line 6026 "reflect.h2"
    }

#line 6028 "reflect.h2"
    auto regex_token_list::generate_code(generation_context& ctx) const -> void{
        for ( auto const& token : tokens ) {
            (*cpp2::impl::assert_not_null(token)).generate_code(ctx);
        }
    }

#line 6034 "reflect.h2"
    auto regex_token_list::add_groups(std::set<int>& groups) const -> void{
        for ( auto const& token : tokens ) {
            (*cpp2::impl::assert_not_null(token)).add_groups(groups);
        }
    }

#line 6040 "reflect.h2"
    [[nodiscard]] auto regex_token_list::gen_string(cpp2::impl::in<token_vec> vec) -> std::string{
        std::string r {""}; 
        for ( auto const& token : vec ) {
            r += (*cpp2::impl::assert_not_null(token)).to_string();
        }
        return r; 
    }

#line 6048 "reflect.h2"
    [[nodiscard]] auto regex_token_list::reverse() const -> token_ptr{
        int s {cpp2::unchecked_narrow<int>(tokens.size())}; 

        token_vec reverse_vec {}; 
        reverse_vec.resize(s);

        int i {0}; 
        for( ; cpp2::impl::cmp_less(i,CPP2_UFCS(ssize)(tokens)); (i += 1) ) {
            CPP2_ASSERT_IN_BOUNDS(reverse_vec, s - 1 - i) = CPP2_UFCS(reverse)((*cpp2::impl::assert_not_null(CPP2_ASSERT_IN_BOUNDS(tokens, i))));
        }
        return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_list>)(cpp2::shared, cpp2::move(reverse_vec)); 
    }

    regex_token_list::~regex_token_list() noexcept{}

#line 6076 "reflect.h2"
    auto parse_context_group_state::next_alternative() & -> void{
        token_vec new_list {}; 
        std::swap(new_list, cur_match_list);
        post_process_list(new_list);
        static_cast<void>(alternate_match_lists.insert(alternate_match_lists.end(), CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_list>)(cpp2::shared, cpp2::move(new_list))));
    }

#line 6084 "reflect.h2"
    auto parse_context_group_state::swap(parse_context_group_state& t) & -> void{// NOLINT(performance-noexcept-swap)
        std::swap(cur_match_list, t.cur_match_list);
        std::swap(alternate_match_lists, t.alternate_match_lists);
        std::swap(modifiers, t.modifiers);
    }

#line 6091 "reflect.h2"
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

#line 6103 "reflect.h2"
    auto parse_context_group_state::add(cpp2::impl::in<token_ptr> token) & -> void{
        cur_match_list.push_back(token);
    }

#line 6108 "reflect.h2"
    [[nodiscard]] auto parse_context_group_state::empty() const& -> bool { return cur_match_list.empty();  }

#line 6112 "reflect.h2"
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

#line 6138 "reflect.h2"
    [[nodiscard]] auto parse_context_branch_reset_state::next() & -> int{
        auto g {cur_group}; 
        cur_group += 1;
        max_group = max(max_group, cur_group);

        return g; 
    }

#line 6147 "reflect.h2"
    auto parse_context_branch_reset_state::set_next(cpp2::impl::in<int> g) & -> void{
        cur_group = g;
        max_group = max(max_group, g);
    }

#line 6153 "reflect.h2"
    auto parse_context_branch_reset_state::next_alternative() & -> void{
        if (is_active) {
            cur_group = from;
        }
    }

#line 6160 "reflect.h2"
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

#line 6190 "reflect.h2"
    parse_context::parse_context(cpp2::impl::in<std::string_view> r, auto const& e)
        : regex{ r }
        , root{ CPP2_UFCS_TEMPLATE_NONLOCAL(cpp2_new<regex_token_empty>)(cpp2::shared, "") }
        , error_out{ e }{

#line 6194 "reflect.h2"
    }

#line 6200 "reflect.h2"
    [[nodiscard]] auto parse_context::start_group() & -> parse_context_group_state
    {
        parse_context_group_state old_state {}; 
        old_state.swap(cur_group_state);
        cur_group_state.modifiers = old_state.modifiers;

        return old_state; 
    }

#line 6210 "reflect.h2"
    [[nodiscard]] auto parse_context::end_group(cpp2::impl::in<parse_context_group_state> old_state) & -> token_ptr
    {
        auto inner {cur_group_state.get_as_token()}; 
        cur_group_state = old_state;
        return inner; 
    }

#line 6217 "reflect.h2"
    [[nodiscard]] auto parse_context::get_modifiers() const& -> expression_flags{
        return cur_group_state.modifiers; 
    }

#line 6221 "reflect.h2"
    auto parse_context::set_modifiers(cpp2::impl::in<expression_flags> mod) & -> void{
        cur_group_state.modifiers = mod;
    }

#line 6228 "reflect.h2"
    [[nodiscard]] auto parse_context::branch_reset_new_state() & -> parse_context_branch_reset_state
    {
        parse_context_branch_reset_state old_state {}; 
        std::swap(old_state, cur_branch_reset_state);

        cur_branch_reset_state.set_active_reset(old_state.cur_group);
        return old_state; 
    }

#line 6237 "reflect.h2"
    auto parse_context::branch_reset_restore_state(cpp2::impl::in<parse_context_branch_reset_state> old_state) & -> void
    {
        auto max_group {cur_branch_reset_state.max_group}; 
        cur_branch_reset_state = old_state;
        cur_branch_reset_state.set_next(cpp2::move(max_group));
    }

#line 6244 "reflect.h2"
    auto parse_context::next_alternative() & -> void
    {
        cur_group_state.next_alternative();
        cur_branch_reset_state.next_alternative();
    }

#line 6252 "reflect.h2"
    auto parse_context::add_token(cpp2::impl::in<token_ptr> token) & -> void{
        cur_group_state.add(token);
    }

#line 6256 "reflect.h2"
    [[nodiscard]] auto parse_context::has_token() const& -> bool{
        return !(cur_group_state.empty()); 
    }

#line 6260 "reflect.h2"
    [[nodiscard]] auto parse_context::pop_token() & -> token_ptr
    {
        token_ptr r {nullptr}; 
        if (has_token()) {
            r = cur_group_state.cur_match_list.back();
            cur_group_state.cur_match_list.pop_back();
        }

        return r; 
    }

#line 6271 "reflect.h2"
    [[nodiscard]] auto parse_context::get_as_token() & -> token_ptr{
        return root; 
    }

#line 6277 "reflect.h2"
    [[nodiscard]] auto parse_context::get_cur_group() const& -> int{
        return cur_branch_reset_state.cur_group; 
    }

#line 6281 "reflect.h2"
    [[nodiscard]] auto parse_context::next_group() & -> int{
        return cur_branch_reset_state.next(); 
    }

#line 6285 "reflect.h2"
    auto parse_context::set_named_group(cpp2::impl::in<std::string> name, cpp2::impl::in<int> id) & -> void
    {
        if (!(named_groups.contains(name))) {// Redefinition of group name is not an error. The left most one is retained.
            CPP2_ASSERT_IN_BOUNDS(named_groups, name) = id;
        }
    }

#line 6292 "reflect.h2"
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

#line 6305 "reflect.h2"
    [[nodiscard]] auto parse_context::current() const& -> char{return CPP2_ASSERT_IN_BOUNDS(regex, pos); }

#line 6308 "reflect.h2"
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
                    cur = regex.find('\n', cur);
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

#line 6348 "reflect.h2"
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

#line 6359 "reflect.h2"
    [[nodiscard]] auto parse_context::next() & -> decltype(auto) { return next_impl(false, false); }
#line 6360 "reflect.h2"
    [[nodiscard]] auto parse_context::next_in_class() & -> decltype(auto) { return next_impl(true, false);  }
#line 6361 "reflect.h2"
    [[nodiscard]] auto parse_context::next_no_skip() & -> decltype(auto) { return next_impl(false, true); }

#line 6363 "reflect.h2"
    [[nodiscard]] auto parse_context::next_n(cpp2::impl::in<int> n) & -> bool{
        auto r {true}; 
        auto cur {0}; 
        for( ; r && cpp2::impl::cmp_less(cur,n); (r = next()) ) {
            cur += 1;
        }
        return r; 
    }

#line 6372 "reflect.h2"
    [[nodiscard]] auto parse_context::has_next() const& -> bool{return cpp2::impl::cmp_less(pos,regex.size()); }

#line 6374 "reflect.h2"
    [[nodiscard]] auto parse_context::grab_until_impl(cpp2::impl::in<std::string> e, cpp2::impl::out<std::string> r, cpp2::impl::in<bool> any) & -> bool
    {
        auto end {pos}; // NOLINT(clang-analyzer-deadcode.DeadStores)
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

#line 6395 "reflect.h2"
    [[nodiscard]] auto parse_context::grab_until(cpp2::impl::in<std::string> e, cpp2::impl::out<std::string> r) & -> decltype(auto) { return grab_until_impl(e, cpp2::impl::out(&r), false); }
#line 6396 "reflect.h2"
    [[nodiscard]] auto parse_context::grab_until(cpp2::impl::in<char> e, cpp2::impl::out<std::string> r) & -> decltype(auto) { return grab_until_impl(std::string(1, e), cpp2::impl::out(&r), false); }
#line 6397 "reflect.h2"
    [[nodiscard]] auto parse_context::grab_until_one_of(cpp2::impl::in<std::string> e, cpp2::impl::out<std::string> r) & -> decltype(auto) { return grab_until_impl(e, cpp2::impl::out(&r), true);  }

#line 6399 "reflect.h2"
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

#line 6412 "reflect.h2"
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

#line 6433 "reflect.h2"
    [[nodiscard]] auto parse_context::peek_impl(cpp2::impl::in<bool> in_class) const& -> char{
        auto next_pos {get_next_position(in_class, false)}; 
        if (cpp2::impl::cmp_less(next_pos,regex.size())) {
            return CPP2_ASSERT_IN_BOUNDS(regex, cpp2::move(next_pos)); 
        }
        else {
            return '\0'; 
        }
    }

#line 6443 "reflect.h2"
    [[nodiscard]] auto parse_context::peek() const& -> decltype(auto) { return peek_impl(false); }
#line 6444 "reflect.h2"
    [[nodiscard]] auto parse_context::peek_in_class() const& -> decltype(auto) { return peek_impl(true);  }

#line 6449 "reflect.h2"
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

#line 6503 "reflect.h2"
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
            if (!(cur_token) && valid()) {cur_token = start_match_parse((*this)); }
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

#line 6542 "reflect.h2"
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

#line 6559 "reflect.h2"
    [[nodiscard]] auto parse_context::get_pos() const& -> decltype(auto) { return pos; }
#line 6560 "reflect.h2"
    [[nodiscard]] auto parse_context::get_range(cpp2::impl::in<size_t> start, cpp2::impl::in<size_t> end) const& -> decltype(auto) { return std::string(regex.substr(start, end - start + 1));  }
#line 6561 "reflect.h2"
    [[nodiscard]] auto parse_context::valid() const& -> bool{return has_next() && !(has_error); }

#line 6563 "reflect.h2"
    [[nodiscard]] auto parse_context::error(cpp2::impl::in<std::string> err) & -> token_ptr{
        has_error = true;
        error_out("Error during parsing of regex '" + cpp2::to_string(regex) + "' at position '" + cpp2::to_string(pos) + "': " + cpp2::to_string(err) + "");
        return nullptr; 
    }

#line 6578 "reflect.h2"
    auto generation_function_context::add_tabs(cpp2::impl::in<int> c) & -> void{
        int i {0}; 
        for( ; cpp2::impl::cmp_less(i,c); i += 1 ) {
            tabs += "  ";
        }
    }

#line 6585 "reflect.h2"
    auto generation_function_context::remove_tabs(cpp2::impl::in<int> c) & -> void{
        tabs = tabs.substr(0, (cpp2::impl::as_<size_t>(c)) * 2);
    }

    generation_function_context::generation_function_context(auto const& code_, auto const& tabs_)
                                                       : code{ code_ }
                                                       , tabs{ tabs_ }{}
generation_function_context::generation_function_context(){}

#line 6603 "reflect.h2"
    [[nodiscard]] auto generation_context::match_parameters() const& -> std::string{return "r.pos, ctx"; }

#line 6608 "reflect.h2"
    auto generation_context::add(cpp2::impl::in<std::string> s) & -> void{
        auto cur {get_current()}; 
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + cpp2::to_string(s) + "\n";
    }

#line 6614 "reflect.h2"
    auto generation_context::add_check(cpp2::impl::in<std::string> check) & -> void{
        auto cur {get_current()}; 
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "if !cpp2::regex::" + cpp2::to_string(check) + " { r.matched = false; break; }\n";
    }

#line 6620 "reflect.h2"
    auto generation_context::add_statefull(cpp2::impl::in<std::string> next_func, cpp2::impl::in<std::string> check) & -> void
    {
        end_func_statefull(check);

        auto name {next_func.substr(0, next_func.size() - 2)}; 
        start_func_named(cpp2::move(name));
    }

#line 6628 "reflect.h2"
    auto generation_context::start_func_named(cpp2::impl::in<std::string> name) & -> void
    {
        auto cur {new_context()}; 

        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + cpp2::to_string(name) + ": @struct<noforward> type = {\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "  operator(): <Iter> (this, cur: Iter, forward ctx, other) -> cpp2::regex::match_return<Iter> = {\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "    r := ctx..pass(cur);\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "    do {\n";
        (*cpp2::impl::assert_not_null(cpp2::move(cur))).add_tabs(3);
    }

#line 6639 "reflect.h2"
    [[nodiscard]] auto generation_context::start_func() & -> std::string
    {
        auto name {gen_func_name()}; 
        start_func_named(name);
        return cpp2::move(name) + "()"; 
    }

#line 6646 "reflect.h2"
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
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "    _ = ctx;\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "    return r;\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "  }\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "}\n";

        finish_context();
    }

#line 6667 "reflect.h2"
    [[nodiscard]] auto generation_context::generate_func(cpp2::impl::in<token_ptr> token) & -> std::string
    {
        auto name {start_func()}; 
        (*cpp2::impl::assert_not_null(token)).generate_code((*this));
        end_func_statefull("other(" + cpp2::to_string(match_parameters()) + ")");

        return name; 
    }

#line 6677 "reflect.h2"
    [[nodiscard]] auto generation_context::generate_reset(cpp2::impl::in<std::set<int>> groups) & -> std::string
    {
        if (groups.empty()) {
            return "cpp2::regex::no_reset()"; 
        }

        auto name {gen_reset_func_name()}; 
        auto cur {new_context()}; 

        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + cpp2::to_string(name) + ": @struct<noforward> type = {\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "  operator(): (this, inout ctx) = {\n";
        for ( auto const& g : groups ) {
            (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "  ctx..set_group_invalid(" + cpp2::to_string(g) + ");\n";
        }
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "  }\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "}\n";

        finish_context();

        return cpp2::move(name) + "()"; 
    }

#line 6701 "reflect.h2"
    [[nodiscard]] auto generation_context::gen_func_name() & -> std::string{
        auto cur_id {matcher_func}; 
        matcher_func += 1;
        return "func_" + cpp2::to_string(cpp2::move(cur_id)) + ""; 
    }

#line 6707 "reflect.h2"
    [[nodiscard]] auto generation_context::next_func_name() & -> std::string{
        return gen_func_name() + "()"; 
    }

#line 6711 "reflect.h2"
    [[nodiscard]] auto generation_context::gen_reset_func_name() & -> std::string{
        auto cur_id {reset_func}; 
        reset_func += 1;
        return "reset_" + cpp2::to_string(cpp2::move(cur_id)) + ""; 
    }

#line 6717 "reflect.h2"
    [[nodiscard]] auto generation_context::gen_temp() & -> std::string{
        auto cur_id {temp_name}; 
        temp_name += 1;
        return "tmp_" + cpp2::to_string(cpp2::move(cur_id)) + ""; 
    }

#line 6725 "reflect.h2"
    [[nodiscard]] auto generation_context::new_context() & -> generation_function_context*{
        gen_stack.push_back(generation_function_context());
        auto cur {get_current()}; 
        (*cpp2::impl::assert_not_null(cur)).tabs = "    ";

        return cur; 
    }

#line 6733 "reflect.h2"
    auto generation_context::finish_context() & -> void{
        auto cur {get_current()}; 
        auto base {get_base()}; 
        (*cpp2::impl::assert_not_null(base)).code += (*cpp2::impl::assert_not_null(cpp2::move(cur))).code;

        gen_stack.pop_back();
    }

#line 6743 "reflect.h2"
    [[nodiscard]] auto generation_context::get_current() & -> generation_function_context*{
        return &gen_stack.back(); 
    }

#line 6747 "reflect.h2"
    [[nodiscard]] auto generation_context::get_base() & -> generation_function_context*{
        return &CPP2_ASSERT_IN_BOUNDS_LITERAL(gen_stack, 0); 
    }

#line 6751 "reflect.h2"
    [[nodiscard]] auto generation_context::get_entry_func() const& -> std::string{
        return entry_func; 
    }

#line 6755 "reflect.h2"
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

#line 6780 "reflect.h2"
    [[nodiscard]] auto generation_context::run(cpp2::impl::in<token_ptr> token) & -> std::string{
        entry_func = generate_func(token);

        return (*cpp2::impl::assert_not_null(get_base())).code; 
    }

#line 6795 "reflect.h2"
    alternative_token::alternative_token()
                            : regex_token_empty{ "" }{}

#line 6797 "reflect.h2"
    [[nodiscard]] auto alternative_token::parse(parse_context& ctx) -> token_ptr{
        if (ctx.current() != '|') {return nullptr; }

        if (!(ctx.has_token())) {return ctx.error("Alternative with no content."); }
        ctx.next_alternative();
        return CPP2_UFCS_TEMPLATE(cpp2_new<alternative_token>)(cpp2::shared); 
    }

    alternative_token::~alternative_token() noexcept{}

#line 6812 "reflect.h2"
    alternative_token_gen::alternative_token_gen(cpp2::impl::in<token_vec> a)
        : regex_token{ gen_string(a) }
        , alternatives{ a }{

#line 6815 "reflect.h2"
    }

#line 6817 "reflect.h2"
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

#line 6834 "reflect.h2"
    auto alternative_token_gen::add_groups(std::set<int>& groups) const -> void
    {
        for ( auto const& cur : alternatives ) {
            (*cpp2::impl::assert_not_null(cur)).add_groups(groups);
        }
    }

#line 6841 "reflect.h2"
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

#line 6854 "reflect.h2"
    [[nodiscard]] auto alternative_token_gen::reverse() const -> token_ptr{
        int s {cpp2::unchecked_narrow<int>(alternatives.size())}; 

        token_vec reverse_vec {}; 
        reverse_vec.resize(s);

        int i {0}; 
        for( ; cpp2::impl::cmp_less(i,s); (i += 1) ) {
            CPP2_ASSERT_IN_BOUNDS(reverse_vec, i) = CPP2_UFCS(reverse)((*cpp2::impl::assert_not_null(CPP2_ASSERT_IN_BOUNDS(alternatives, i))));// We only reverse the alternatives, not the order in which they are checked.
        }
        return CPP2_UFCS_TEMPLATE(cpp2_new<alternative_token_gen>)(cpp2::shared, cpp2::move(reverse_vec)); 
    }

    alternative_token_gen::~alternative_token_gen() noexcept{}

#line 6875 "reflect.h2"
    any_token::any_token(cpp2::impl::in<bool> single_line)
        : regex_token_check{ ".", "any_token_matcher<char, " + cpp2::to_string(single_line) + ">" }{

#line 6877 "reflect.h2"
    }

#line 6879 "reflect.h2"
    [[nodiscard]] auto any_token::parse(parse_context& ctx) -> token_ptr{
        if ('.' != ctx.current()) {return nullptr; }

        return CPP2_UFCS_TEMPLATE(cpp2_new<any_token>)(cpp2::shared, ctx.get_modifiers().has(expression_flags::single_line)); 
    }

    any_token::~any_token() noexcept{}

#line 6894 "reflect.h2"
    atomic_group_token::atomic_group_token()
                             : regex_token{ "" }{}

#line 6896 "reflect.h2"
    [[nodiscard]] auto atomic_group_token::reverse() const -> token_ptr{
        auto r {CPP2_UFCS_TEMPLATE(cpp2_new<atomic_group_token>)(cpp2::shared)}; 
        (*cpp2::impl::assert_not_null(r)).inner_token = CPP2_UFCS(reverse)((*cpp2::impl::assert_not_null(inner_token)));

        return r; 
    }

#line 6903 "reflect.h2"
    auto atomic_group_token::generate_code(generation_context& ctx) const -> void
    {
        auto inner_name {ctx.generate_func(inner_token)}; 

        auto next_name {ctx.next_func_name()}; 
        ctx.add_statefull(next_name, "cpp2::regex::atomic_group_matcher<char>(" + cpp2::to_string(ctx.match_parameters()) + ", " + cpp2::to_string(cpp2::move(inner_name)) + ", other, " + cpp2::to_string(next_name) + ")");
    }

#line 6911 "reflect.h2"
    auto atomic_group_token::add_groups(std::set<int>& groups) const -> void{
        (*cpp2::impl::assert_not_null(inner_token)).add_groups(groups);
    }

    atomic_group_token::~atomic_group_token() noexcept{}

#line 6925 "reflect.h2"
    char_token::char_token(cpp2::impl::in<char> t, cpp2::impl::in<bool> ignore_case_)
        : regex_token{ std::string(1, t) }
        , token{ t }
        , ignore_case{ ignore_case_ }{

#line 6929 "reflect.h2"
    }

#line 6931 "reflect.h2"
    char_token::char_token(cpp2::impl::in<std::string> t, cpp2::impl::in<bool> ignore_case_)
        : regex_token{ t }
        , token{ t }
        , ignore_case{ ignore_case_ }{

#line 6935 "reflect.h2"
    }

#line 6937 "reflect.h2"
    [[nodiscard]] auto char_token::parse(parse_context& ctx) -> token_ptr{
        return CPP2_UFCS_TEMPLATE(cpp2_new<char_token>)(cpp2::shared, ctx.current(), ctx.get_modifiers().has(expression_flags::case_insensitive)); 
    }

#line 6941 "reflect.h2"
    auto char_token::generate_code(generation_context& ctx) const -> void
    {
        if (ignore_case) {
            std::string upper {token}; 
            std::string lower {token}; 
{
size_t i{0};

#line 6947 "reflect.h2"
            for( ; cpp2::impl::cmp_less(i,token.size()); i += 1 ) {
                CPP2_ASSERT_IN_BOUNDS(lower, i) = string_util::safe_tolower(CPP2_ASSERT_IN_BOUNDS(token, i));
                CPP2_ASSERT_IN_BOUNDS(upper, i) = string_util::safe_toupper(CPP2_ASSERT_IN_BOUNDS(token, i));
            }
}

#line 6952 "reflect.h2"
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

#line 6964 "reflect.h2"
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

#line 6985 "reflect.h2"
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

#line 7003 "reflect.h2"
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

#line 7018 "reflect.h2"
    [[nodiscard]] auto char_token::reverse() const -> token_ptr{
        std::string reverse_str {token}; 
        std::reverse(reverse_str.begin(), reverse_str.end());
        return CPP2_UFCS_TEMPLATE(cpp2_new<char_token>)(cpp2::shared, cpp2::move(reverse_str), ignore_case); 
    }

#line 7024 "reflect.h2"
    auto char_token::append(char_token const& that) & -> void{
        (*this).token += that.token;
        (*this).string_rep += that.string_rep;
    }

    char_token::~char_token() noexcept{}

#line 7041 "reflect.h2"
    class_token::class_token(cpp2::impl::in<bool> negate_, cpp2::impl::in<bool> case_insensitive_, cpp2::impl::in<std::string> class_str_, cpp2::impl::in<std::string> str)
        : regex_token{ str }
        , negate{ negate_ }
        , case_insensitive{ case_insensitive_ }
        , class_str{ class_str_ }
#line 7042 "reflect.h2"
    {

#line 7047 "reflect.h2"
    }

#line 7050 "reflect.h2"
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

#line 7175 "reflect.h2"
    [[nodiscard]] auto class_token::reverse() const -> token_ptr{
        return CPP2_UFCS_TEMPLATE(cpp2_new<class_token>)(cpp2::shared, 
            negate, 
            case_insensitive, 
            class_str, 
            to_string()
            ); 
    }

#line 7184 "reflect.h2"
    auto class_token::generate_code(generation_context& ctx) const -> void
    {
        ctx.add_check("class_token_matcher<char, " + cpp2::to_string(negate) + ", " + cpp2::to_string(case_insensitive) + ", " + cpp2::to_string(class_str) + ">::match(" + cpp2::to_string(ctx.match_parameters()) + ")");
    }

#line 7189 "reflect.h2"
    [[nodiscard]] auto class_token::create_matcher(cpp2::impl::in<std::string> name, cpp2::impl::in<std::string> template_arguments) -> std::string
    {
        auto sep {", "}; 
        if (template_arguments.empty()) {sep = ""; }

        return "::cpp2::regex::" + cpp2::to_string(name) + "<char" + cpp2::to_string(cpp2::move(sep)) + cpp2::to_string(template_arguments) + ">"; 
    }

    class_token::~class_token() noexcept{}

#line 7201 "reflect.h2"
[[nodiscard]] auto escape_token_parse(parse_context& ctx) -> token_ptr
{
    if (ctx.current() != '\\') {return nullptr; }

#line 7206 "reflect.h2"
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

#line 7242 "reflect.h2"
[[nodiscard]] auto global_group_reset_token_parse(parse_context& ctx) -> token_ptr
{
    if (!((ctx.current() == '\\' && ctx.peek() == 'K'))) {return nullptr; }

    static_cast<void>(ctx.next());// Skip escape.
    return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_code>)(cpp2::shared, "\\K", "ctx..set_group_start(0, r.pos);"); 
}

#line 7265 "reflect.h2"
    group_ref_token::group_ref_token(cpp2::impl::in<int> id_, cpp2::impl::in<bool> case_insensitive_, cpp2::impl::in<bool> reverse_, cpp2::impl::in<std::string> str)
        : regex_token{ str }
        , id{ id_ }
        , case_insensitive{ case_insensitive_ }
        , reverse_eval{ reverse_ }
#line 7266 "reflect.h2"
    {

#line 7271 "reflect.h2"
    }

#line 7273 "reflect.h2"
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

                char number_as_char {cpp2::unchecked_narrow<char>(cpp2::move(number))}; 

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

        return CPP2_UFCS_TEMPLATE(cpp2_new<group_ref_token>)(cpp2::shared, cpp2::move(group_id), ctx.get_modifiers().has(expression_flags::case_insensitive), false, cpp2::move(str)); 
    }

#line 7374 "reflect.h2"
    [[nodiscard]] auto group_ref_token::reverse() const -> token_ptr{
        return CPP2_UFCS_TEMPLATE(cpp2_new<group_ref_token>)(cpp2::shared, id, case_insensitive, !(reverse_eval), to_string()); 
    }

#line 7378 "reflect.h2"
    auto group_ref_token::generate_code(generation_context& ctx) const -> void{
        ctx.add_check("group_ref_token_matcher<char, " + cpp2::to_string(id) + ", " + cpp2::to_string(case_insensitive) + ", " + cpp2::to_string(reverse_eval) + ">(" + cpp2::to_string(ctx.match_parameters()) + ")");
    }

    group_ref_token::~group_ref_token() noexcept{}

#line 7402 "reflect.h2"
    [[nodiscard]] auto group_token::parse_lookahead_lookbehind(parse_context& ctx, cpp2::impl::in<std::string> syntax, cpp2::impl::in<bool> lookahead, cpp2::impl::in<bool> positive) -> token_ptr
    {
        static_cast<void>(ctx.next());// Skip last token defining the syntax

        auto r {CPP2_UFCS_TEMPLATE(cpp2_new<lookahead_lookbehind_token>)(cpp2::shared, lookahead, positive)}; 

        auto old_state {ctx.start_group()}; 
        if (!(ctx.parse_until(')'))) {return ctx.error("Group without a closing bracket."); }
        (*cpp2::impl::assert_not_null(r)).inner = ctx.end_group(cpp2::move(old_state));
        (*cpp2::impl::assert_not_null(r)).set_string("(" + cpp2::to_string(syntax) + cpp2::to_string((*cpp2::impl::assert_not_null((*cpp2::impl::assert_not_null(r)).inner)).to_string()) + ")");

        if (!(lookahead)) {
            (*cpp2::impl::assert_not_null(r)).inner = (*cpp2::impl::assert_not_null((*cpp2::impl::assert_not_null(r)).inner)).reverse();
        }

        return r; 
    }

#line 7420 "reflect.h2"
    [[nodiscard]] auto group_token::parse_atomic_pattern(parse_context& ctx, cpp2::impl::in<std::string> syntax) -> token_ptr
    {
        static_cast<void>(ctx.next());// Skip last token defining the syntax

        auto r {CPP2_UFCS_TEMPLATE(cpp2_new<atomic_group_token>)(cpp2::shared)}; 

        auto old_state {ctx.start_group()}; 
        if (!(ctx.parse_until(')'))) {return ctx.error("Group without a closing bracket."); }
        (*cpp2::impl::assert_not_null(r)).inner_token = ctx.end_group(cpp2::move(old_state));
        (*cpp2::impl::assert_not_null(r)).set_string("(" + cpp2::to_string(syntax) + cpp2::to_string((*cpp2::impl::assert_not_null((*cpp2::impl::assert_not_null(r)).inner_token)).to_string()) + ")");

        return r; 
    }

#line 7434 "reflect.h2"
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

            if ( CPP2_UFCS(current)(ctx) == '<' && (CPP2_UFCS(peek)(ctx) == '=' || CPP2_UFCS(peek)(ctx) == '!')) 
            {
                // Lookbehind
                static_cast<void>(CPP2_UFCS(next)(ctx));// Skip the '<'

                return parse_lookahead_lookbehind(ctx, "?<" + cpp2::to_string(ctx.current()) + "", false, ctx.current() == '='); 
            }
            else {if (ctx.current() == '<' || ctx.current() == '\'') 
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
                // Lookahead
                return parse_lookahead_lookbehind(ctx, "?" + cpp2::to_string(ctx.current()) + "", true, ctx.current() == '='); 
            }
            else {if (ctx.current() == '>') 
            {
                // Atomic pattern
                return parse_atomic_pattern(ctx, "?" + cpp2::to_string(ctx.current()) + ""); 
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
            }}}}}}
        }
        else {if (ctx.current() == '*') 
        {
            //  Named pattern
            static_cast<void>(ctx.next());// Skip *.
            std::string name {""}; 
            if (!(ctx.grab_until(':', cpp2::impl::out(&name)))) {return ctx.error("Missing colon for named pattern."); }

            if (name == "pla" || name == "positive_lookahead") {
                return parse_lookahead_lookbehind(ctx, "*" + cpp2::to_string(cpp2::move(name)) + ":", true, true); 
            }
            else {if (name == "nla" || name == "negative_lookahead") {
                return parse_lookahead_lookbehind(ctx, "*" + cpp2::to_string(cpp2::move(name)) + ":", true, false); 
            }
            else {if (name == "plb" || name == "positive_lookbehind") {
                return parse_lookahead_lookbehind(ctx, "*" + cpp2::to_string(cpp2::move(name)) + ":", false, true); 
            }
            else {if (name == "nlb" || name == "negative_lookbehind") {
                return parse_lookahead_lookbehind(ctx, "*" + cpp2::to_string(cpp2::move(name)) + ":", false, false); 
            }
            else {if (name == "atomic") {
                return parse_atomic_pattern(ctx, "*" + cpp2::to_string(cpp2::move(name)) + ":"); 
            }
            else {
                return ctx.error("Unknown named group pattern: '" + cpp2::to_string(cpp2::move(name)) + "'"); 
            }}}}}
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

#line 7593 "reflect.h2"
    [[nodiscard]] auto group_token::reverse() const -> token_ptr{
        auto r {CPP2_UFCS_TEMPLATE(cpp2_new<group_token>)(cpp2::shared)}; 
        (*cpp2::impl::assert_not_null(r)).number = number;
        (*cpp2::impl::assert_not_null(r)).reverse_eval = !(reverse_eval);
        (*cpp2::impl::assert_not_null(r)).inner = CPP2_UFCS(reverse)((*cpp2::impl::assert_not_null(inner)));
        return r; 
    }

#line 7601 "reflect.h2"
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

#line 7619 "reflect.h2"
    auto group_token::generate_code(generation_context& ctx) const -> void
    {
        if (-1 != number) {
            if (reverse_eval) {
                ctx.add("ctx..set_group_end(" + cpp2::to_string(number) + ", r.pos);");
            }
            else {
                ctx.add("ctx..set_group_start(" + cpp2::to_string(number) + ", r.pos);");
            }
        }

        (*cpp2::impl::assert_not_null(inner)).generate_code(ctx);
        if (-1 != number) {
            if (reverse_eval) {
                ctx.add("ctx..set_group_start(" + cpp2::to_string(number) + ", r.pos);");
            }
            else {
                ctx.add("ctx..set_group_end(" + cpp2::to_string(number) + ", r.pos);");
            }

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

#line 7650 "reflect.h2"
    auto group_token::add_groups(std::set<int>& groups) const -> void
    {
        (*cpp2::impl::assert_not_null(inner)).add_groups(groups);
        if (-1 != number) {
            static_cast<void>(groups.insert(number));
        }
    }

    group_token::~group_token() noexcept{}

#line 7662 "reflect.h2"
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
    char number_as_char {cpp2::unchecked_narrow<char>(cpp2::move(number))}; 

    std::string syntax {string_util::int_to_string<16>(cpp2::impl::as_<int>(number_as_char))}; 
    if (cpp2::move(has_brackets)) {
        syntax = "{" + cpp2::to_string(syntax) + "}";
    }
    syntax = "\\x" + cpp2::to_string(syntax) + "";

    auto r {CPP2_UFCS_TEMPLATE(cpp2_new<char_token>)(cpp2::shared, cpp2::move(number_as_char), ctx.get_modifiers().has(expression_flags::case_insensitive))}; 
    (*cpp2::impl::assert_not_null(r)).set_string(cpp2::move(syntax));
    return r; 
}

#line 7703 "reflect.h2"
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

#line 7723 "reflect.h2"
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

#line 7749 "reflect.h2"
    lookahead_lookbehind_token::lookahead_lookbehind_token(cpp2::impl::in<bool> lookahead_, cpp2::impl::in<bool> positive_)
        : regex_token{ "" }
        , lookahead{ lookahead_ }
        , positive{ positive_ }{

#line 7752 "reflect.h2"
    }

#line 7754 "reflect.h2"
    auto lookahead_lookbehind_token::generate_code(generation_context& ctx) const -> void{
        auto inner_name {ctx.generate_func(inner)}; 

        if (lookahead) {
            ctx.add_check("lookahead_token_matcher<char, " + cpp2::to_string(positive) + ">(" + cpp2::to_string(ctx.match_parameters()) + ", " + cpp2::to_string(cpp2::move(inner_name)) + ")");
        }
        else {
            ctx.add_check("lookbehind_token_matcher<char, " + cpp2::to_string(positive) + ">(" + cpp2::to_string(ctx.match_parameters()) + ", " + cpp2::to_string(cpp2::move(inner_name)) + ")");
        }
    }

#line 7765 "reflect.h2"
    [[nodiscard]] auto lookahead_lookbehind_token::reverse() const -> token_ptr{
        auto r {CPP2_UFCS_TEMPLATE(cpp2_new<lookahead_lookbehind_token>)(cpp2::shared, lookahead, positive)}; 
        (*cpp2::impl::assert_not_null(r)).inner = inner;// We do not reverse here. Nested lookahead and lookbehind stay as they are.

        return r; 
    }

#line 7772 "reflect.h2"
    auto lookahead_lookbehind_token::add_groups(std::set<int>& groups) const -> void{
        (*cpp2::impl::assert_not_null(inner)).add_groups(groups);
    }

    lookahead_lookbehind_token::~lookahead_lookbehind_token() noexcept{}

#line 7780 "reflect.h2"
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

#line 7808 "reflect.h2"
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
    char number_as_char {cpp2::unchecked_narrow<char>(cpp2::move(number))}; 

    std::string syntax {"\\o{" + cpp2::to_string(string_util::int_to_string<8>(cpp2::impl::as_<int>(number_as_char))) + "}"}; 
    auto r {CPP2_UFCS_TEMPLATE(cpp2_new<char_token>)(cpp2::shared, cpp2::move(number_as_char), ctx.get_modifiers().has(expression_flags::case_insensitive))}; 
    (*cpp2::impl::assert_not_null(r)).set_string(cpp2::move(syntax));
    return r; 
}

#line 7845 "reflect.h2"
    range_token::range_token()
                             : regex_token{ "" }{}

#line 7847 "reflect.h2"
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

            size_t sep {inner.find(',')}; 
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

#line 7920 "reflect.h2"
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

#line 7932 "reflect.h2"
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

#line 7945 "reflect.h2"
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

#line 7964 "reflect.h2"
    [[nodiscard]] auto range_token::reverse() const -> token_ptr{
        auto r {CPP2_UFCS_TEMPLATE(cpp2_new<range_token>)(cpp2::shared)}; 
        (*cpp2::impl::assert_not_null(r)).min_count = min_count;
        (*cpp2::impl::assert_not_null(r)).max_count = max_count;
        (*cpp2::impl::assert_not_null(r)).kind = kind;
        (*cpp2::impl::assert_not_null(r)).inner_token = CPP2_UFCS(reverse)((*cpp2::impl::assert_not_null(inner_token)));

        return r; 
    }

#line 7974 "reflect.h2"
    auto range_token::generate_code(generation_context& ctx) const -> void
    {
        auto inner_name {ctx.generate_func(inner_token)}; 
        std::set<int> groups {}; 
        (*cpp2::impl::assert_not_null(inner_token)).add_groups(groups);
        auto reset_name {ctx.generate_reset(cpp2::move(groups))}; 

        auto next_name {ctx.next_func_name()}; 
        ctx.add_statefull(next_name, "cpp2::regex::range_token_matcher<char, " + cpp2::to_string(min_count) + ", " + cpp2::to_string(max_count) + ", " + cpp2::to_string(kind) + ">::match(" + cpp2::to_string(ctx.match_parameters()) + ", " + cpp2::to_string(cpp2::move(inner_name)) + ", " + cpp2::to_string(cpp2::move(reset_name)) + ", other, " + cpp2::to_string(next_name) + ")");
    }

#line 7985 "reflect.h2"
    auto range_token::add_groups(std::set<int>& groups) const -> void{
        (*cpp2::impl::assert_not_null(inner_token)).add_groups(groups);
    }

    range_token::~range_token() noexcept{}

#line 7997 "reflect.h2"
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

#line 8021 "reflect.h2"
        (*cpp2::impl::assert_not_null(r)).parse_modifier(ctx);

        (*cpp2::impl::assert_not_null(r)).inner_token = ctx.pop_token();
        (*cpp2::impl::assert_not_null(r)).string_rep = (*cpp2::impl::assert_not_null((*cpp2::impl::assert_not_null(r)).inner_token)).to_string() + cpp2::move(symbol) + (*cpp2::impl::assert_not_null(r)).gen_mod_string();
        return r; 
    }

    special_range_token::~special_range_token() noexcept{}

#line 8033 "reflect.h2"
[[nodiscard]] auto start_match_parse(parse_context& ctx) -> token_ptr
{
    if (ctx.current() != '\\') {return nullptr; }

    if (ctx.peek() == 'G') {
        if (0 != ctx.get_pos()) {return ctx.error("\\G is only supported at the first position in the regex."); }
        static_cast<void>(ctx.next());
        ctx.is_start_match = true;
        return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_empty>)(cpp2::shared, "\\G"); 
    }
    else {
        return nullptr; 
    }
}

#line 8053 "reflect.h2"
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

#line 8089 "reflect.h2"
    template <typename Error_out> regex_generator<Error_out>::regex_generator(cpp2::impl::in<std::string_view> r, Error_out const& e)
        : regex{ r }
        , error_out{ e }{

#line 8092 "reflect.h2"
    }

#line 8094 "reflect.h2"
    template <typename Error_out> [[nodiscard]] auto regex_generator<Error_out>::parse() & -> std::string
    {
        // Extract modifiers and adapt regex.
        extract_modifiers();

        parse_context parse_ctx {regex, error_out}; 
        if (!(parse_ctx.parse(modifier))) {
            return ""; 
        }

        source += "{\n";
        source += "  context: <Iter> type == cpp2::regex::match_context<CharT, Iter, " + cpp2::to_string(parse_ctx.get_cur_group()) + ">;";

        generation_context gen_ctx {}; 
        source += gen_ctx.run(parse_ctx.get_as_token());
        source += "  entry: <Iter> (cur: Iter, inout ctx: context<Iter>) -> cpp2::regex::match_return<Iter> = {\n";
        source += "    ctx..set_group_start(0, cur);\n";
        source += "    r := " + cpp2::to_string(gen_ctx.get_entry_func()) + "(cur, ctx, cpp2::regex::true_end_func());\n";
        source += "    if r.matched { ctx..set_group_end(0, r.pos); }\n";
        source += "    return r;\n";
        source += "  }\n";

        source += cpp2::move(gen_ctx).create_named_group_lookup(parse_ctx.named_groups);
        source += "  is_start_match: () -> bool == " + cpp2::to_string(parse_ctx.is_start_match) + ";";

        auto string {(*cpp2::impl::assert_not_null(parse_ctx.get_as_token())).to_string()}; 
        source += "  to_string: () -> std::string = { return R\"(" + cpp2::to_string(modifier_escape) + cpp2::to_string(cpp2::move(string)) + cpp2::to_string(modifier_escape) + cpp2::to_string(modifier) + ")\"; }\n";

        source += "}\n";

        static_cast<void>(cpp2::move(parse_ctx));

        return source; 
    }

#line 8129 "reflect.h2"
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

#line 8145 "reflect.h2"
template<typename Err> [[nodiscard]] auto generate_regex(cpp2::impl::in<std::string_view> regex, Err const& err) -> std::string
{
    regex_generator<Err> parser {regex, err}; 
    auto r {parser.parse()}; 
    static_cast<void>(cpp2::move(parser));
    return r; 
}

#line 8155 "reflect.h2"
auto regex_gen(meta::type_declaration& t) -> void
{
    auto has_default {false}; 
    auto exact_name {"regex"}; 
    auto prefix {"regex_"}; 
    std::map<std::string,std::string> expressions {}; 

    for ( auto& m : CPP2_UFCS(get_member_objects)(t) ) 
    {
        std::string name {CPP2_UFCS(name)(m)}; 

        if (CPP2_UFCS(starts_with)(name, prefix) || name == exact_name) 
        {
            if (!(CPP2_UFCS(has_initializer)(m))) {
                CPP2_UFCS(error)(t, "Regular expression must have an initializer.");
            }
            CPP2_UFCS(mark_for_removal_from_enclosing_type)(m);

            if (name == exact_name) {
                if (has_default) {
                    CPP2_UFCS(error)(t, "Type can only contain one default named regular expression.");
                }
                has_default = true;
            }

            std::string expr {CPP2_UFCS(initializer)(m)}; 
            if (CPP2_UFCS(starts_with)(expr, "R\"(") && CPP2_UFCS(ends_with)(expr, ")\"")) {
                expr = CPP2_UFCS(substr)(expr, 3, CPP2_UFCS(size)(expr) - 5);
            }
            else {if (string_util::is_escaped(expr)) {
                expr = CPP2_UFCS(substr)(expr, 1, CPP2_UFCS(size)(expr) - 2);
            }
            else {
                CPP2_UFCS(error)(t, "Unknown string format '" + cpp2::to_string(expr) + "'");
            }}

            CPP2_ASSERT_IN_BOUNDS(expressions, name) = cpp2::move(expr);
        }
    }

    CPP2_UFCS(remove_marked_members)(t);

    for ( auto const& expr : cpp2::move(expressions) ) {
        auto regular_expression {generate_regex(expr.second, [_0 = t](auto const& message) mutable -> decltype(auto) { return CPP2_UFCS(error)(_0, message);  })}; 

        if (!(regular_expression.empty())) {
            CPP2_UFCS(add_member)(t, "public " + cpp2::to_string(expr.first) + "_matcher: <CharT> type = " + cpp2::to_string(cpp2::move(regular_expression)) + "");
            CPP2_UFCS(add_member)(t, "public " + cpp2::to_string(expr.first) + ": cpp2::regex::regular_expression<char, " + cpp2::to_string(expr.first) + "_matcher<char>> = ();\n");
        }
    }

    CPP2_UFCS(add_runtime_support_include)(t, "cpp2regex.h");
}

#line 8214 "reflect.h2"
[[nodiscard]] auto apply_metafunctions(
    declaration_node& n, 
    type_declaration& rtype, 
    auto const& error
    ) -> bool

{
    if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(is_type)(n)) ) { cpp2::cpp2_default.report_violation(""); }

    //  Check for _names reserved for the metafunction implementation
    if (!(CPP2_UFCS(empty)(n.metafunctions))) 
    {
        for ( 
              auto const& m : CPP2_UFCS(get_members)(rtype) ) 
        {
            CPP2_UFCS(require)(m, 
                !(CPP2_UFCS(starts_with)(CPP2_UFCS(name)(m), "_")) || CPP2_UFCS(ssize)(CPP2_UFCS(name)(m)) == 1, 
                "a type that applies a metafunction cannot have a body that declares "
                "a name that starts with '_' - those names are reserved for the "
                "metafunction implementation"
            );
        }
    }

    //  For each metafunction, apply it
    for ( 
         auto const& meta : n.metafunctions ) 
    {
        //  Convert the name and any template arguments to strings
        //  and record that in rtype
        auto name {CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(meta)))}; 
        name = CPP2_UFCS(substr)(name, 0, CPP2_UFCS(find)(name, '<'));

        std::vector<std::string> args {}; 
        for ( 
             auto const& arg : CPP2_UFCS(template_arguments)((*cpp2::impl::assert_not_null(meta))) ) 
            CPP2_UFCS(push_back)(args, CPP2_UFCS(to_string)(arg));

        CPP2_UFCS(set_metafunction_name)(rtype, name, cpp2::move(args));

        //  Dispatch
        //
        if (name == "interface") {
            interface(rtype);
        }
        else {if (name == "polymorphic_base") {
            polymorphic_base(rtype);
        }
        else {if (name == "ordered") {
            ordered(rtype);
        }
        else {if (name == "weakly_ordered") {
            weakly_ordered(rtype);
        }
        else {if (name == "partially_ordered") {
            partially_ordered(rtype);
        }
        else {if (name == "copyable") {
            copyable(rtype);
        }
        else {if (name == "copy_constructible") {
            copy_constructible(rtype);
        }
        else {if (name == "hashable") {
            hashable(rtype);
        }
        else {if (name == "basic_value") {
            basic_value(rtype);
        }
        else {if (name == "value") {
            value(rtype);
        }
        else {if (name == "weakly_ordered_value") {
            weakly_ordered_value(rtype);
        }
        else {if (name == "partially_ordered_value") {
            partially_ordered_value(rtype);
        }
        else {if (name == "cpp1_rule_of_zero") {
            cpp1_rule_of_zero(rtype);
        }
        else {if (name == "struct") {
            cpp2_struct(rtype);
        }
        else {if (name == "enum") {
            cpp2_enum(rtype);
        }
        else {if (name == "flag_enum") {
            flag_enum(rtype);
        }
        else {if (name == "union") {
            cpp2_union(rtype);
        }
        else {if (name == "print") {
            print(rtype);
        }
        else {if (name == "noisy") {
            noisy(rtype);
        }
        else {if (name == "python") {
            python(rtype);
        }
        else {if (name == "javascript") {
            javascript(rtype);
        }
        else {if (name == "autodiff") {
            autodiff(rtype);
        }
        else {if (name == "regex") {
            regex_gen(rtype);
        }
        else {if (name == "sample_traverser") {
            sample_traverser(rtype);
        }
        else {
            error("unrecognized metafunction name: " + cpp2::move(name));
            error(
                "the current supported names are listed at "
                "https://hsutter.github.io/cppfront/cpp2/metafunctions/#built-in-metafunctions"
            );
            return false; 
        }}}}}}}}}}}}}}}}}}}}}}}}
    }

    return true; 
}

#line 8342 "reflect.h2"
}

}

#endif
