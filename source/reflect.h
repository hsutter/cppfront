
#ifndef REFLECT_H_CPP2
#define REFLECT_H_CPP2


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "reflect.h2"

#line 21 "reflect.h2"
namespace cpp2 {

namespace meta {

#line 33 "reflect.h2"
class compiler_services;

#line 224 "reflect.h2"
class declaration_base;

#line 250 "reflect.h2"
class declaration;

#line 332 "reflect.h2"
class function_declaration;

#line 419 "reflect.h2"
class object_declaration;

#line 455 "reflect.h2"
class type_declaration;

#line 590 "reflect.h2"
class alias_declaration;

#line 963 "reflect.h2"
class value_member_info;

#line 1559 "reflect.h2"
}

}


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "reflect.h2"

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
//  Reflection and meta
//===========================================================================

#include "parse.h"
#include "cpp2regex.h"

#line 21 "reflect.h2"
namespace cpp2 {

namespace meta {

#line 26 "reflect.h2"
//-----------------------------------------------------------------------
//
//  Compiler services
//
//-----------------------------------------------------------------------
//

class compiler_services
 {
    //  Common data members
    //
    private: std::vector<error_entry>* errors; 
    private: int errors_original_size; 
    private: stable_vector<token>* generated_tokens; 
    private: cpp2::parser parser; 
    private: std::string metafunction_name {}; 
    private: std::vector<std::string> metafunction_args {}; 
    private: bool metafunctions_used {false}; 

    //  Constructor
    //
    public: explicit compiler_services(

        std::vector<error_entry>* errors_, 
        stable_vector<token>* generated_tokens_
    );

#line 59 "reflect.h2"
    //  Common API
    //
    public: auto set_metafunction_name(cpp2::impl::in<std::string_view> name, cpp2::impl::in<std::vector<std::string>> args) & -> void;

#line 67 "reflect.h2"
    public: [[nodiscard]] auto get_metafunction_name() const& -> std::string_view;

    public: [[nodiscard]] auto get_argument(cpp2::impl::in<int> index) & -> std::string;

#line 77 "reflect.h2"
    public: [[nodiscard]] auto get_arguments() & -> std::vector<std::string>;

#line 82 "reflect.h2"
    public: [[nodiscard]] auto arguments_were_used() const& -> bool;
using parse_statement_ret = std::unique_ptr<statement_node>;


#line 84 "reflect.h2"
    protected: [[nodiscard]] auto parse_statement(

        std::string_view source
    ) & -> parse_statement_ret;

#line 137 "reflect.h2"
    public: [[nodiscard]] virtual auto position() const -> source_position;

#line 143 "reflect.h2"
    //  Error diagnosis and handling, integrated with compiler output
    //  Unlike a contract violation, .requires continues further processing
    //
    public: auto require(

        cpp2::impl::in<bool> b, 
        cpp2::impl::in<std::string_view> msg
    ) const& -> void;

#line 157 "reflect.h2"
    public: auto error(cpp2::impl::in<std::string_view> msg) const& -> void;

#line 166 "reflect.h2"
    //  Enable custom contracts on this object, integrated with compiler output
    //  Unlike .requires, a contract violation stops further processing
    //
    public: auto report_violation(auto const& msg) const& -> void;

#line 174 "reflect.h2"
    public: [[nodiscard]] auto is_active() const& -> auto;
    public: virtual ~compiler_services() noexcept;
public: compiler_services(compiler_services const& that);

#line 175 "reflect.h2"
};

#line 178 "reflect.h2"
/*
//-----------------------------------------------------------------------
//
//  Type IDs
//
//-----------------------------------------------------------------------
//

//  All type_ids are wrappers around a pointer to node
//
type_id: @polymorphic_base @copyable type =
{
    this: compiler_services = ();

    n: type_id_node;

    protected operator=: (
        out this,
        n_: type_id_node,
        s : compiler_services
    )
    = {
        compiler_services = s;
        n = n_;
        assert( n, "a meta::type_id must point to a valid type_id_node, not null" );
    }

    is_wildcard         : (this) -> bool        = n.is_wildcard();
    is_pointer_qualified: (this) -> bool        = n.is_pointer_qualified();
    template_args_count : (this) -> int         = n.template_arguments().ssize();
    to_string           : (this) -> std::string = n.to_string();

    position: (override this) -> source_position = n.position();
}
*/

#line 215 "reflect.h2"
//-----------------------------------------------------------------------
//
//  Declarations
//
//-----------------------------------------------------------------------
//

//  All declarations are wrappers around a pointer to node
//
class declaration_base
: public compiler_services {

#line 228 "reflect.h2"
    protected: declaration_node* n; 

    protected: explicit declaration_base(

        declaration_node* n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 241 "reflect.h2"
    public: [[nodiscard]] auto position() const -> source_position override;

    public: [[nodiscard]] auto print() const& -> std::string;
    public: virtual ~declaration_base() noexcept;
public: declaration_base(declaration_base const& that);

#line 244 "reflect.h2"
};

#line 247 "reflect.h2"
//-----------------------------------------------------------------------
//  All declarations
//
class declaration
: public declaration_base {

#line 254 "reflect.h2"
    public: explicit declaration(

        declaration_node* n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 263 "reflect.h2"
    public: [[nodiscard]] auto is_public() const& -> bool;
    public: [[nodiscard]] auto is_protected() const& -> bool;
    public: [[nodiscard]] auto is_private() const& -> bool;
    public: [[nodiscard]] auto is_default_access() const& -> bool;

    public: auto default_to_public() & -> void;
    public: auto default_to_protected() & -> void;
    public: auto default_to_private() & -> void;

    public: [[nodiscard]] auto make_public() & -> bool;
    public: [[nodiscard]] auto make_protected() & -> bool;
    public: [[nodiscard]] auto make_private() & -> bool;

    public: [[nodiscard]] auto has_name() const& -> bool;
    public: [[nodiscard]] auto has_name(cpp2::impl::in<std::string_view> s) const& -> bool;

    public: [[nodiscard]] auto name() const& -> std::string_view;

#line 284 "reflect.h2"
    public: [[nodiscard]] auto has_initializer() const& -> bool;

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
    public: [[nodiscard]] auto as_alias() const& -> alias_declaration;

    public: [[nodiscard]] auto get_parent() const& -> declaration;

    public: [[nodiscard]] auto parent_is_function() const& -> bool;
    public: [[nodiscard]] auto parent_is_object() const& -> bool;
    public: [[nodiscard]] auto parent_is_type() const& -> bool;
    public: [[nodiscard]] auto parent_is_namespace() const& -> bool;
    public: [[nodiscard]] auto parent_is_alias() const& -> bool;

    public: [[nodiscard]] auto parent_is_type_alias() const& -> bool;
    public: [[nodiscard]] auto parent_is_namespace_alias() const& -> bool;
    public: [[nodiscard]] auto parent_is_object_alias() const& -> bool;

    public: [[nodiscard]] auto parent_is_polymorphic() const& -> bool;

    public: auto mark_for_removal_from_enclosing_type() & -> void;
    public: virtual ~declaration() noexcept;
public: declaration(declaration const& that);

                                                    // this precondition should be sufficient ...

#line 326 "reflect.h2"
};

#line 329 "reflect.h2"
//-----------------------------------------------------------------------
//  Function declarations
//
class function_declaration
: public declaration {

#line 336 "reflect.h2"
    public: explicit function_declaration(

        declaration_node* n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 346 "reflect.h2"
    public: [[nodiscard]] auto index_of_parameter_named(cpp2::impl::in<std::string_view> s) const& -> int;
    public: [[nodiscard]] auto has_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool;
    public: [[nodiscard]] auto has_in_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool;
    public: [[nodiscard]] auto has_out_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool;
    public: [[nodiscard]] auto has_move_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool;
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

    public: [[nodiscard]] auto unnamed_return_type() const& -> std::string;

    public: [[nodiscard]] auto get_parameters() const& -> std::vector<object_declaration>;

#line 390 "reflect.h2"
    public: [[nodiscard]] auto is_binary_comparison_function() const& -> bool;

    public: auto default_to_virtual() & -> void;

    public: [[nodiscard]] auto make_virtual() & -> bool;

    public: auto add_initializer(cpp2::impl::in<std::string_view> source) & -> void;
    public: function_declaration(function_declaration const& that);


#line 413 "reflect.h2"
};

#line 416 "reflect.h2"
//-----------------------------------------------------------------------
//  Object declarations
//
class object_declaration
: public declaration {

#line 423 "reflect.h2"
    public: explicit object_declaration(

        declaration_node* n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 433 "reflect.h2"
    public: [[nodiscard]] auto is_const() const& -> bool;
    public: [[nodiscard]] auto has_wildcard_type() const& -> bool;

    public: [[nodiscard]] auto type() const& -> std::string;

#line 443 "reflect.h2"
    public: [[nodiscard]] auto initializer() const& -> std::string;
    public: object_declaration(object_declaration const& that);


#line 449 "reflect.h2"
};

#line 452 "reflect.h2"
//-----------------------------------------------------------------------
//  Type declarations
//
class type_declaration
: public declaration {

#line 459 "reflect.h2"
    public: explicit type_declaration(

        declaration_node* n_, 
        cpp2::impl::in<compiler_services> s
    );

#line 469 "reflect.h2"
    public: auto reserve_names(cpp2::impl::in<std::string_view> name, auto&& ...etc) const& -> void;

#line 481 "reflect.h2"
    public: [[nodiscard]] auto is_polymorphic() const& -> bool;
    public: [[nodiscard]] auto is_final() const& -> bool;
    public: [[nodiscard]] auto make_final() & -> bool;

    public: [[nodiscard]] auto get_member_functions() const& -> std::vector<function_declaration>;

#line 496 "reflect.h2"
    public: [[nodiscard]] auto get_member_functions_needing_initializer() const& -> std::vector<function_declaration>;

#line 511 "reflect.h2"
    public: [[nodiscard]] auto get_member_objects() const& -> std::vector<object_declaration>;

#line 521 "reflect.h2"
    public: [[nodiscard]] auto get_member_types() const& -> std::vector<type_declaration>;

#line 531 "reflect.h2"
    public: [[nodiscard]] auto get_member_aliases() const& -> std::vector<alias_declaration>;

#line 541 "reflect.h2"
    public: [[nodiscard]] auto get_members() const& -> std::vector<declaration>;
struct query_declared_value_set_functions_ret { bool out_this_in_that; bool out_this_move_that; bool inout_this_in_that; bool inout_this_move_that; };



#line 551 "reflect.h2"
    public: [[nodiscard]] auto query_declared_value_set_functions() const& -> query_declared_value_set_functions_ret;

#line 566 "reflect.h2"
    public: auto add_member(cpp2::impl::in<std::string_view> source) & -> void;

#line 580 "reflect.h2"
    public: auto remove_marked_members() & -> void;
    public: auto remove_all_members() & -> void;

    public: auto disable_member_function_generation() & -> void;
    public: type_declaration(type_declaration const& that);

#line 584 "reflect.h2"
};

#line 587 "reflect.h2"
//-----------------------------------------------------------------------
//  Alias declarations
//
class alias_declaration
: public declaration {

#line 594 "reflect.h2"
    public: explicit alias_declaration(

        declaration_node* n_, 
        cpp2::impl::in<compiler_services> s
    );
    public: alias_declaration(alias_declaration const& that);


#line 603 "reflect.h2"
};

#line 606 "reflect.h2"
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
auto add_virtual_destructor(meta::type_declaration& t) -> void;

#line 624 "reflect.h2"
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
//  an abstract base class having only pure virtual functions
//
auto interface(meta::type_declaration& t) -> void;

#line 663 "reflect.h2"
//-----------------------------------------------------------------------
//
//     "C.35: A base class destructor should be either public and
//      virtual, or protected and non-virtual."
//
//     "[C.43] ... a base class should not be copyable, and so does not
//      necessarily need a default constructor."
//
//          -- Stroustrup, Sutter, et al. (C++ Core Guidelines)
//
//-----------------------------------------------------------------------
//
//  polymorphic_base
//
//  A pure polymorphic base type that is not copyable, and whose
//  destructor is either public and virtual or protected and nonvirtual.
//
//  Unlike an interface, it can have nonpublic and nonvirtual functions.
//
auto polymorphic_base(meta::type_declaration& t) -> void;

#line 707 "reflect.h2"
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

auto ordered_impl(
    meta::type_declaration& t, 
    cpp2::impl::in<std::string_view> ordering// must be "strong_ordering" etc.
) -> void;

#line 751 "reflect.h2"
//-----------------------------------------------------------------------
//  ordered - a totally ordered type
//
//  Note: the ordering that should be encouraged as default gets the nice name
//
auto ordered(meta::type_declaration& t) -> void;

#line 761 "reflect.h2"
//-----------------------------------------------------------------------
//  weakly_ordered - a weakly ordered type
//
auto weakly_ordered(meta::type_declaration& t) -> void;

#line 769 "reflect.h2"
//-----------------------------------------------------------------------
//  partially_ordered - a partially ordered type
//
auto partially_ordered(meta::type_declaration& t) -> void;

#line 778 "reflect.h2"
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
auto copyable(meta::type_declaration& t) -> void;

#line 815 "reflect.h2"
//-----------------------------------------------------------------------
//
//  basic_value
//
//  A regular type: copyable, plus has public default construction
//  and no protected or virtual functions
//
auto basic_value(meta::type_declaration& t) -> void;

#line 840 "reflect.h2"
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
auto value(meta::type_declaration& t) -> void;

#line 856 "reflect.h2"
auto weakly_ordered_value(meta::type_declaration& t) -> void;

#line 862 "reflect.h2"
auto partially_ordered_value(meta::type_declaration& t) -> void;

#line 869 "reflect.h2"
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
auto cpp1_rule_of_zero(meta::type_declaration& t) -> void;

#line 903 "reflect.h2"
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
auto cpp2_struct(meta::type_declaration& t) -> void;

#line 946 "reflect.h2"
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
class value_member_info {
    public: std::string name; 
    public: std::string type; 
    public: std::string value; 
};

auto basic_enum(
    meta::type_declaration& t, 
    auto const& nextval, 
    cpp2::impl::in<bool> bitwise
    ) -> void;

#line 1153 "reflect.h2"
//-----------------------------------------------------------------------
//
//    "An enum[...] is a totally ordered value type that stores a
//     value of its enumerators's type, and otherwise has only public
//     member variables of its enumerator's type, all of which are
//     naturally scoped because they are members of a type."
//
//          -- P0707R4, section 3
//
auto cpp2_enum(meta::type_declaration& t) -> void;

#line 1179 "reflect.h2"
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
auto flag_enum(meta::type_declaration& t) -> void;

#line 1211 "reflect.h2"
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

auto cpp2_union(meta::type_declaration& t) -> void;

#line 1364 "reflect.h2"
//-----------------------------------------------------------------------
//
//  print - output a pretty-printed visualization of t
//
auto print(cpp2::impl::in<meta::type_declaration> t) -> void;

#line 1373 "reflect.h2"
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
auto regex_gen(meta::type_declaration& t) -> void;

#line 1449 "reflect.h2"
//-----------------------------------------------------------------------
//
//  apply_metafunctions
//
[[nodiscard]] auto apply_metafunctions(
    declaration_node& n, 
    type_declaration& rtype, 
    auto const& error
    ) -> bool;

#line 1559 "reflect.h2"
}

}


//=== Cpp2 function definitions =================================================

#line 1 "reflect.h2"

#line 21 "reflect.h2"
namespace cpp2 {

namespace meta {

#line 47 "reflect.h2"
    compiler_services::compiler_services(

        std::vector<error_entry>* errors_, 
        stable_vector<token>* generated_tokens_
    )
        : errors{ errors_ }
        , errors_original_size{ cpp2::unsafe_narrow<int>(std::ssize(*cpp2::impl::assert_not_null(errors))) }
        , generated_tokens{ generated_tokens_ }
        , parser{ *cpp2::impl::assert_not_null(errors) }
#line 52 "reflect.h2"
    {

#line 57 "reflect.h2"
    }

#line 61 "reflect.h2"
    auto compiler_services::set_metafunction_name(cpp2::impl::in<std::string_view> name, cpp2::impl::in<std::vector<std::string>> args) & -> void{
        metafunction_name  = name;
        metafunction_args  = args;
        metafunctions_used = CPP2_UFCS(empty)(args);
    }

#line 67 "reflect.h2"
    [[nodiscard]] auto compiler_services::get_metafunction_name() const& -> std::string_view { return metafunction_name;  }

#line 69 "reflect.h2"
    [[nodiscard]] auto compiler_services::get_argument(cpp2::impl::in<int> index) & -> std::string{
        metafunctions_used = true;
        if (([_0 = 0, _1 = index, _2 = CPP2_UFCS(ssize)(metafunction_args)]{ return cpp2::impl::cmp_less_eq(_0,_1) && cpp2::impl::cmp_less(_1,_2); }())) {
            return CPP2_ASSERT_IN_BOUNDS(metafunction_args, index); 
        }
        return ""; 
    }

#line 77 "reflect.h2"
    [[nodiscard]] auto compiler_services::get_arguments() & -> std::vector<std::string>{
        metafunctions_used = true;
        return metafunction_args; 
    }

#line 82 "reflect.h2"
    [[nodiscard]] auto compiler_services::arguments_were_used() const& -> bool { return metafunctions_used;  }

#line 84 "reflect.h2"
    [[nodiscard]] auto compiler_services::parse_statement(

        std::string_view source
    ) & -> parse_statement_ret

    {
            cpp2::impl::deferred_init<std::unique_ptr<statement_node>> ret;
#line 90 "reflect.h2"
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

#line 102 "reflect.h2"
        if ( cpp2::impl::cmp_greater(CPP2_UFCS(ssize)(source),1) 
            && newline_pos != source.npos) 
        {
            while( newline_pos != std::string_view::npos ) 
            {
                add_line(CPP2_UFCS(substr)(source, 0, newline_pos));
                CPP2_UFCS(remove_prefix)(source, newline_pos + 1);
                newline_pos = CPP2_UFCS(find)(source, '\n');
            }
        }
}

#line 113 "reflect.h2"
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
            error(("parse failed - the source string is not a valid statement:\n" + cpp2::to_string(cpp2::move(original_source))));
        }return std::move(ret.value()); 
    }

#line 137 "reflect.h2"
    [[nodiscard]] auto compiler_services::position() const -> source_position

    {
        return {  }; 
    }

#line 146 "reflect.h2"
    auto compiler_services::require(

        cpp2::impl::in<bool> b, 
        cpp2::impl::in<std::string_view> msg
    ) const& -> void
    {
        if (!(b)) {
            error(msg);
        }
    }

#line 157 "reflect.h2"
    auto compiler_services::error(cpp2::impl::in<std::string_view> msg) const& -> void
    {
        auto message {cpp2::impl::as_<std::string>(msg)}; 
        if (!(CPP2_UFCS(empty)(metafunction_name))) {
            message = { "while applying @" + cpp2::to_string(metafunction_name) + " - " + cpp2::to_string(message) };
        }
        static_cast<void>(CPP2_UFCS(emplace_back)((*cpp2::impl::assert_not_null(errors)), position(), cpp2::move(message)));
    }

#line 169 "reflect.h2"
    auto compiler_services::report_violation(auto const& msg) const& -> void{
        error(msg);
        throw(std::runtime_error(("  ==> programming bug found in metafunction @" + cpp2::to_string(metafunction_name) + " - contract violation - see previous errors")));
    }

#line 174 "reflect.h2"
    [[nodiscard]] auto compiler_services::is_active() const& -> auto { return true;  }

    compiler_services::~compiler_services() noexcept{}
compiler_services::compiler_services(compiler_services const& that)
                                : errors{ that.errors }
                                , errors_original_size{ that.errors_original_size }
                                , generated_tokens{ that.generated_tokens }
                                , parser{ that.parser }
                                , metafunction_name{ that.metafunction_name }
                                , metafunction_args{ that.metafunction_args }
                                , metafunctions_used{ that.metafunctions_used }{}

#line 230 "reflect.h2"
    declaration_base::declaration_base(

        declaration_node* n_, 
        cpp2::impl::in<compiler_services> s
    )
        : compiler_services{ s }
        , n{ n_ }
#line 235 "reflect.h2"
    {

#line 238 "reflect.h2"
        if (cpp2::cpp2_default.is_active() && !(n) ) { cpp2::cpp2_default.report_violation(CPP2_CONTRACT_MSG("a meta::declaration must point to a valid declaration_node, not null")); }
    }

#line 241 "reflect.h2"
    [[nodiscard]] auto declaration_base::position() const -> source_position { return CPP2_UFCS(position)((*cpp2::impl::assert_not_null(n)));  }

#line 243 "reflect.h2"
    [[nodiscard]] auto declaration_base::print() const& -> std::string { return CPP2_UFCS(pretty_print_visualize)((*cpp2::impl::assert_not_null(n)), 0);  }

    declaration_base::~declaration_base() noexcept{}
declaration_base::declaration_base(declaration_base const& that)
                                : compiler_services{ static_cast<compiler_services const&>(that) }
                                , n{ that.n }{}

#line 254 "reflect.h2"
    declaration::declaration(

        declaration_node* n_, 
        cpp2::impl::in<compiler_services> s
    )
        : declaration_base{ n_, s }
#line 259 "reflect.h2"
    {

    }

#line 263 "reflect.h2"
    [[nodiscard]] auto declaration::is_public() const& -> bool { return CPP2_UFCS(is_public)((*cpp2::impl::assert_not_null(n))); }
#line 264 "reflect.h2"
    [[nodiscard]] auto declaration::is_protected() const& -> bool { return CPP2_UFCS(is_protected)((*cpp2::impl::assert_not_null(n))); }
#line 265 "reflect.h2"
    [[nodiscard]] auto declaration::is_private() const& -> bool { return CPP2_UFCS(is_private)((*cpp2::impl::assert_not_null(n))); }
#line 266 "reflect.h2"
    [[nodiscard]] auto declaration::is_default_access() const& -> bool { return CPP2_UFCS(is_default_access)((*cpp2::impl::assert_not_null(n)));  }

#line 268 "reflect.h2"
    auto declaration::default_to_public() & -> void { static_cast<void>(CPP2_UFCS(make_public)((*cpp2::impl::assert_not_null(n)))); }
#line 269 "reflect.h2"
    auto declaration::default_to_protected() & -> void { static_cast<void>(CPP2_UFCS(make_protected)((*cpp2::impl::assert_not_null(n))));  }
#line 270 "reflect.h2"
    auto declaration::default_to_private() & -> void { static_cast<void>(CPP2_UFCS(make_private)((*cpp2::impl::assert_not_null(n)))); }

#line 272 "reflect.h2"
    [[nodiscard]] auto declaration::make_public() & -> bool { return CPP2_UFCS(make_public)((*cpp2::impl::assert_not_null(n))); }
#line 273 "reflect.h2"
    [[nodiscard]] auto declaration::make_protected() & -> bool { return CPP2_UFCS(make_protected)((*cpp2::impl::assert_not_null(n))); }
#line 274 "reflect.h2"
    [[nodiscard]] auto declaration::make_private() & -> bool { return CPP2_UFCS(make_private)((*cpp2::impl::assert_not_null(n))); }

#line 276 "reflect.h2"
    [[nodiscard]] auto declaration::has_name() const& -> bool { return CPP2_UFCS(has_name)((*cpp2::impl::assert_not_null(n))); }
#line 277 "reflect.h2"
    [[nodiscard]] auto declaration::has_name(cpp2::impl::in<std::string_view> s) const& -> bool { return CPP2_UFCS(has_name)((*cpp2::impl::assert_not_null(n)), s); }

#line 279 "reflect.h2"
    [[nodiscard]] auto declaration::name() const& -> std::string_view{
        if (has_name()) {return CPP2_UFCS(as_string_view)((*cpp2::impl::assert_not_null(CPP2_UFCS(name)(*cpp2::impl::assert_not_null(n))))); }
        else          { return ""; }
    }

#line 284 "reflect.h2"
    [[nodiscard]] auto declaration::has_initializer() const& -> bool { return CPP2_UFCS(has_initializer)((*cpp2::impl::assert_not_null(n)));  }

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
    [[nodiscard]] auto declaration::as_function() const& -> function_declaration { return function_declaration(n, (*this));  }
#line 302 "reflect.h2"
    [[nodiscard]] auto declaration::as_object() const& -> object_declaration { return object_declaration(n, (*this)); }
#line 303 "reflect.h2"
    [[nodiscard]] auto declaration::as_type() const& -> type_declaration { return type_declaration(n, (*this)); }
#line 304 "reflect.h2"
    [[nodiscard]] auto declaration::as_alias() const& -> alias_declaration { return alias_declaration(n, (*this)); }

#line 306 "reflect.h2"
    [[nodiscard]] auto declaration::get_parent() const& -> declaration { return declaration((*cpp2::impl::assert_not_null(n)).parent_declaration, (*this)); }

#line 308 "reflect.h2"
    [[nodiscard]] auto declaration::parent_is_function() const& -> bool { return CPP2_UFCS(parent_is_function)((*cpp2::impl::assert_not_null(n))); }
#line 309 "reflect.h2"
    [[nodiscard]] auto declaration::parent_is_object() const& -> bool { return CPP2_UFCS(parent_is_object)((*cpp2::impl::assert_not_null(n))); }
#line 310 "reflect.h2"
    [[nodiscard]] auto declaration::parent_is_type() const& -> bool { return CPP2_UFCS(parent_is_type)((*cpp2::impl::assert_not_null(n))); }
#line 311 "reflect.h2"
    [[nodiscard]] auto declaration::parent_is_namespace() const& -> bool { return CPP2_UFCS(parent_is_namespace)((*cpp2::impl::assert_not_null(n))); }
#line 312 "reflect.h2"
    [[nodiscard]] auto declaration::parent_is_alias() const& -> bool { return CPP2_UFCS(parent_is_alias)((*cpp2::impl::assert_not_null(n))); }

#line 314 "reflect.h2"
    [[nodiscard]] auto declaration::parent_is_type_alias() const& -> bool { return CPP2_UFCS(parent_is_type_alias)((*cpp2::impl::assert_not_null(n))); }
#line 315 "reflect.h2"
    [[nodiscard]] auto declaration::parent_is_namespace_alias() const& -> bool { return CPP2_UFCS(parent_is_namespace_alias)((*cpp2::impl::assert_not_null(n)));  }
#line 316 "reflect.h2"
    [[nodiscard]] auto declaration::parent_is_object_alias() const& -> bool { return CPP2_UFCS(parent_is_object_alias)((*cpp2::impl::assert_not_null(n))); }

#line 318 "reflect.h2"
    [[nodiscard]] auto declaration::parent_is_polymorphic() const& -> bool { return CPP2_UFCS(parent_is_polymorphic)((*cpp2::impl::assert_not_null(n)));  }

#line 320 "reflect.h2"
    auto declaration::mark_for_removal_from_enclosing_type() & -> void

    {
        if (cpp2::type_safety.is_active() && !(parent_is_type()) ) { cpp2::type_safety.report_violation(""); }
#line 323 "reflect.h2"
        auto test {CPP2_UFCS(type_member_mark_for_removal)((*cpp2::impl::assert_not_null(n)))}; 
        if (cpp2::cpp2_default.is_active() && !(cpp2::move(test)) ) { cpp2::cpp2_default.report_violation(""); }// ... to ensure this assert is true
    }

    declaration::~declaration() noexcept{}
declaration::declaration(declaration const& that)
                                : declaration_base{ static_cast<declaration_base const&>(that) }{}

#line 336 "reflect.h2"
    function_declaration::function_declaration(

        declaration_node* n_, 
        cpp2::impl::in<compiler_services> s
    )
        : declaration{ n_, s }
#line 341 "reflect.h2"
    {

        if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(is_function)((*cpp2::impl::assert_not_null(n)))) ) { cpp2::cpp2_default.report_violation(""); }
    }

#line 346 "reflect.h2"
    [[nodiscard]] auto function_declaration::index_of_parameter_named(cpp2::impl::in<std::string_view> s) const& -> int { return CPP2_UFCS(index_of_parameter_named)((*cpp2::impl::assert_not_null(n)), s); }
#line 347 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool { return CPP2_UFCS(has_parameter_named)((*cpp2::impl::assert_not_null(n)), s); }
#line 348 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_in_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool { return CPP2_UFCS(has_in_parameter_named)((*cpp2::impl::assert_not_null(n)), s); }
#line 349 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_out_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool { return CPP2_UFCS(has_out_parameter_named)((*cpp2::impl::assert_not_null(n)), s); }
#line 350 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_move_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool { return CPP2_UFCS(has_move_parameter_named)((*cpp2::impl::assert_not_null(n)), s); }
#line 351 "reflect.h2"
    [[nodiscard]] auto function_declaration::first_parameter_name() const& -> std::string { return CPP2_UFCS(first_parameter_name)((*cpp2::impl::assert_not_null(n))); }

#line 353 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_parameter_with_name_and_pass(cpp2::impl::in<std::string_view> s, cpp2::impl::in<passing_style> pass) const& -> bool { 
                                                  return CPP2_UFCS(has_parameter_with_name_and_pass)((*cpp2::impl::assert_not_null(n)), s, pass);  }
#line 355 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_function_with_this() const& -> bool { return CPP2_UFCS(is_function_with_this)((*cpp2::impl::assert_not_null(n))); }
#line 356 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_virtual() const& -> bool { return CPP2_UFCS(is_virtual_function)((*cpp2::impl::assert_not_null(n))); }
#line 357 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_defaultable() const& -> bool { return CPP2_UFCS(is_defaultable_function)((*cpp2::impl::assert_not_null(n))); }
#line 358 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_constructor() const& -> bool { return CPP2_UFCS(is_constructor)((*cpp2::impl::assert_not_null(n))); }
#line 359 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_default_constructor() const& -> bool { return CPP2_UFCS(is_default_constructor)((*cpp2::impl::assert_not_null(n))); }
#line 360 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_move() const& -> bool { return CPP2_UFCS(is_move)((*cpp2::impl::assert_not_null(n))); }
#line 361 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_swap() const& -> bool { return CPP2_UFCS(is_swap)((*cpp2::impl::assert_not_null(n))); }
#line 362 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_constructor_with_that() const& -> bool { return CPP2_UFCS(is_constructor_with_that)((*cpp2::impl::assert_not_null(n))); }
#line 363 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_constructor_with_in_that() const& -> bool { return CPP2_UFCS(is_constructor_with_in_that)((*cpp2::impl::assert_not_null(n))); }
#line 364 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_constructor_with_move_that() const& -> bool { return CPP2_UFCS(is_constructor_with_move_that)((*cpp2::impl::assert_not_null(n)));  }
#line 365 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_assignment() const& -> bool { return CPP2_UFCS(is_assignment)((*cpp2::impl::assert_not_null(n))); }
#line 366 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_assignment_with_that() const& -> bool { return CPP2_UFCS(is_assignment_with_that)((*cpp2::impl::assert_not_null(n))); }
#line 367 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_assignment_with_in_that() const& -> bool { return CPP2_UFCS(is_assignment_with_in_that)((*cpp2::impl::assert_not_null(n))); }
#line 368 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_assignment_with_move_that() const& -> bool { return CPP2_UFCS(is_assignment_with_move_that)((*cpp2::impl::assert_not_null(n)));  }
#line 369 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_destructor() const& -> bool { return CPP2_UFCS(is_destructor)((*cpp2::impl::assert_not_null(n))); }

#line 371 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_copy_or_move() const& -> bool { return is_constructor_with_that() || is_assignment_with_that(); }

#line 373 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_declared_return_type() const& -> bool { return CPP2_UFCS(has_declared_return_type)((*cpp2::impl::assert_not_null(n))); }
#line 374 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_deduced_return_type() const& -> bool { return CPP2_UFCS(has_deduced_return_type)((*cpp2::impl::assert_not_null(n))); }
#line 375 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_bool_return_type() const& -> bool { return CPP2_UFCS(has_bool_return_type)((*cpp2::impl::assert_not_null(n))); }
#line 376 "reflect.h2"
    [[nodiscard]] auto function_declaration::has_non_void_return_type() const& -> bool { return CPP2_UFCS(has_non_void_return_type)((*cpp2::impl::assert_not_null(n))); }

#line 378 "reflect.h2"
    [[nodiscard]] auto function_declaration::unnamed_return_type() const& -> std::string { return CPP2_UFCS(unnamed_return_type_to_string)((*cpp2::impl::assert_not_null(n))); }

#line 380 "reflect.h2"
    [[nodiscard]] auto function_declaration::get_parameters() const& -> std::vector<object_declaration>

    {
        std::vector<object_declaration> ret {}; 
        for ( auto const& param : CPP2_UFCS(get_function_parameters)((*cpp2::impl::assert_not_null(n))) ) {
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, &*cpp2::impl::assert_not_null((*cpp2::impl::assert_not_null(param)).declaration), (*this)));
        }
        return ret; 
    }

#line 390 "reflect.h2"
    [[nodiscard]] auto function_declaration::is_binary_comparison_function() const& -> bool { return CPP2_UFCS(is_binary_comparison_function)((*cpp2::impl::assert_not_null(n)));  }

#line 392 "reflect.h2"
    auto function_declaration::default_to_virtual() & -> void { static_cast<void>(CPP2_UFCS(make_function_virtual)((*cpp2::impl::assert_not_null(n)))); }

#line 394 "reflect.h2"
    [[nodiscard]] auto function_declaration::make_virtual() & -> bool { return CPP2_UFCS(make_function_virtual)((*cpp2::impl::assert_not_null(n))); }

#line 396 "reflect.h2"
    auto function_declaration::add_initializer(cpp2::impl::in<std::string_view> source) & -> void

#line 399 "reflect.h2"
    {
        if ((*this).is_active() && !(!(has_initializer())) ) { (*this).report_violation(CPP2_CONTRACT_MSG("cannot add an initializer to a function that already has one")); }
        if ((*this).is_active() && !(parent_is_type()) ) { (*this).report_violation(CPP2_CONTRACT_MSG("cannot add an initializer to a function that isn't in a type scope")); }
        //require( !has_initializer(),
        //         "cannot add an initializer to a function that already has one");
        //require( parent_is_type(),
        //         "cannot add an initializer to a function that isn't in a type scope");

#line 405 "reflect.h2"
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

#line 423 "reflect.h2"
    object_declaration::object_declaration(

        declaration_node* n_, 
        cpp2::impl::in<compiler_services> s
    )
        : declaration{ n_, s }
#line 428 "reflect.h2"
    {

        if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(is_object)((*cpp2::impl::assert_not_null(n)))) ) { cpp2::cpp2_default.report_violation(""); }
    }

#line 433 "reflect.h2"
    [[nodiscard]] auto object_declaration::is_const() const& -> bool { return CPP2_UFCS(is_const)((*cpp2::impl::assert_not_null(n))); }
#line 434 "reflect.h2"
    [[nodiscard]] auto object_declaration::has_wildcard_type() const& -> bool { return CPP2_UFCS(has_wildcard_type)((*cpp2::impl::assert_not_null(n)));  }

#line 436 "reflect.h2"
    [[nodiscard]] auto object_declaration::type() const& -> std::string{
        auto ret {CPP2_UFCS(object_type)((*cpp2::impl::assert_not_null(n)))}; 
        require(!(contains(ret, "(*ERROR*)")), 
                 "cannot to_string this type: " + ret);
        return ret; 
    }

#line 443 "reflect.h2"
    [[nodiscard]] auto object_declaration::initializer() const& -> std::string{
        auto ret {CPP2_UFCS(object_initializer)((*cpp2::impl::assert_not_null(n)))}; 
        require(!(contains(ret, "(*ERROR*)")), 
                 "cannot to_string this initializer: " + ret);
        return ret; 
    }

    object_declaration::object_declaration(object_declaration const& that)
                                : declaration{ static_cast<declaration const&>(that) }{}

#line 459 "reflect.h2"
    type_declaration::type_declaration(

        declaration_node* n_, 
        cpp2::impl::in<compiler_services> s
    )
        : declaration{ n_, s }
#line 464 "reflect.h2"
    {

        if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(is_type)((*cpp2::impl::assert_not_null(n)))) ) { cpp2::cpp2_default.report_violation(""); }
    }

#line 469 "reflect.h2"
    auto type_declaration::reserve_names(cpp2::impl::in<std::string_view> name, auto&& ...etc) const& -> void
    {                           // etc is not declared ':string_view' for compatibility with GCC 10.x
        for ( 
             auto const& m : get_members() ) {
            CPP2_UFCS(require)(m, !(CPP2_UFCS(has_name)(m, name)), 
                       ("in a '" + cpp2::to_string(get_metafunction_name()) + "' type, the name '" + cpp2::to_string(name) + "' is reserved for use by the '" + cpp2::to_string(get_metafunction_name()) + "' implementation"));
        }
        if constexpr (!(CPP2_PACK_EMPTY(etc))) {
            reserve_names(CPP2_FORWARD(etc)...);
        }
    }

#line 481 "reflect.h2"
    [[nodiscard]] auto type_declaration::is_polymorphic() const& -> bool { return CPP2_UFCS(is_polymorphic)((*cpp2::impl::assert_not_null(n))); }
#line 482 "reflect.h2"
    [[nodiscard]] auto type_declaration::is_final() const& -> bool { return CPP2_UFCS(is_type_final)((*cpp2::impl::assert_not_null(n))); }
#line 483 "reflect.h2"
    [[nodiscard]] auto type_declaration::make_final() & -> bool { return CPP2_UFCS(make_type_final)((*cpp2::impl::assert_not_null(n))); }

#line 485 "reflect.h2"
    [[nodiscard]] auto type_declaration::get_member_functions() const& -> std::vector<function_declaration>

    {
        std::vector<function_declaration> ret {}; 
        for ( 
             auto const& d : CPP2_UFCS(get_type_scope_declarations)((*cpp2::impl::assert_not_null(n)), declaration_node::functions) ) {
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, d, (*this)));
        }
        return ret; 
    }

#line 496 "reflect.h2"
    [[nodiscard]] auto type_declaration::get_member_functions_needing_initializer() const& -> std::vector<function_declaration>

    {
        std::vector<function_declaration> ret {}; 
        for ( 
             auto const& d : CPP2_UFCS(get_type_scope_declarations)((*cpp2::impl::assert_not_null(n)), declaration_node::functions) ) 
        if ( !(CPP2_UFCS(has_initializer)((*cpp2::impl::assert_not_null(d)))) 
            && !(CPP2_UFCS(is_virtual_function)((*cpp2::impl::assert_not_null(d)))) 
            && !(CPP2_UFCS(is_defaultable_function)((*cpp2::impl::assert_not_null(d))))) 
        {
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, d, (*this)));
        }
        return ret; 
    }

#line 511 "reflect.h2"
    [[nodiscard]] auto type_declaration::get_member_objects() const& -> std::vector<object_declaration>

    {
        std::vector<object_declaration> ret {}; 
        for ( auto const& d : CPP2_UFCS(get_type_scope_declarations)((*cpp2::impl::assert_not_null(n)), declaration_node::objects) ) {
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, d, (*this)));
        }
        return ret; 
    }

#line 521 "reflect.h2"
    [[nodiscard]] auto type_declaration::get_member_types() const& -> std::vector<type_declaration>

    {
        std::vector<type_declaration> ret {}; 
        for ( auto const& d : CPP2_UFCS(get_type_scope_declarations)((*cpp2::impl::assert_not_null(n)), declaration_node::types) ) {
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, d, (*this)));
        }
        return ret; 
    }

#line 531 "reflect.h2"
    [[nodiscard]] auto type_declaration::get_member_aliases() const& -> std::vector<alias_declaration>

    {
        std::vector<alias_declaration> ret {}; 
        for ( auto const& d : CPP2_UFCS(get_type_scope_declarations)((*cpp2::impl::assert_not_null(n)), declaration_node::aliases) ) {
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, d, (*this)));
        }
        return ret; 
    }

#line 541 "reflect.h2"
    [[nodiscard]] auto type_declaration::get_members() const& -> std::vector<declaration>

    {
        std::vector<declaration> ret {}; 
        for ( auto const& d : CPP2_UFCS(get_type_scope_declarations)((*cpp2::impl::assert_not_null(n)), declaration_node::all) ) {
            static_cast<void>(CPP2_UFCS(emplace_back)(ret, d, (*this)));
        }
        return ret; 
    }

#line 551 "reflect.h2"
    [[nodiscard]] auto type_declaration::query_declared_value_set_functions() const& -> query_declared_value_set_functions_ret

#line 558 "reflect.h2"
    {
            cpp2::impl::deferred_init<bool> out_this_in_that;
            cpp2::impl::deferred_init<bool> out_this_move_that;
            cpp2::impl::deferred_init<bool> inout_this_in_that;
            cpp2::impl::deferred_init<bool> inout_this_move_that;
#line 559 "reflect.h2"
        auto declared {CPP2_UFCS(find_declared_value_set_functions)((*cpp2::impl::assert_not_null(n)))}; 
        out_this_in_that.construct(declared.out_this_in_that != nullptr);
        out_this_move_that.construct(declared.out_this_move_that != nullptr);
        inout_this_in_that.construct(declared.inout_this_in_that != nullptr);
        inout_this_move_that.construct(cpp2::move(declared).inout_this_move_that != nullptr);
    return  { std::move(out_this_in_that.value()), std::move(out_this_move_that.value()), std::move(inout_this_in_that.value()), std::move(inout_this_move_that.value()) }; }

#line 566 "reflect.h2"
    auto type_declaration::add_member(cpp2::impl::in<std::string_view> source) & -> void
    {
        auto decl {parse_statement(source)}; 
        if (!((cpp2::impl::as_<bool>(decl)))) {
            error("the provided source string is not a valid statement");
            return ; 
        }
        if (!(CPP2_UFCS(is_declaration)((*cpp2::impl::assert_not_null(decl))))) {
            error("cannot add a member that is not a declaration");
        }
        require(CPP2_UFCS(add_type_member)((*cpp2::impl::assert_not_null(n)), std::move(cpp2::move(decl))), 
                 std::string("unexpected error while attempting to add member:\n") + source);
    }

#line 580 "reflect.h2"
    auto type_declaration::remove_marked_members() & -> void { CPP2_UFCS(type_remove_marked_members)((*cpp2::impl::assert_not_null(n)));  }
#line 581 "reflect.h2"
    auto type_declaration::remove_all_members() & -> void { CPP2_UFCS(type_remove_all_members)((*cpp2::impl::assert_not_null(n))); }

#line 583 "reflect.h2"
    auto type_declaration::disable_member_function_generation() & -> void { CPP2_UFCS(type_disable_member_function_generation)((*cpp2::impl::assert_not_null(n)));  }

    type_declaration::type_declaration(type_declaration const& that)
                                : declaration{ static_cast<declaration const&>(that) }{}

#line 594 "reflect.h2"
    alias_declaration::alias_declaration(

        declaration_node* n_, 
        cpp2::impl::in<compiler_services> s
    )
        : declaration{ n_, s }
#line 599 "reflect.h2"
    {

        if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(is_alias)((*cpp2::impl::assert_not_null(n)))) ) { cpp2::cpp2_default.report_violation(""); }
    }

    alias_declaration::alias_declaration(alias_declaration const& that)
                                : declaration{ static_cast<declaration const&>(that) }{}

#line 618 "reflect.h2"
auto add_virtual_destructor(meta::type_declaration& t) -> void
{
    CPP2_UFCS(add_member)(t, "operator=: (virtual move this) = { }");
}

#line 636 "reflect.h2"
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

    if (!(cpp2::move(has_dtor))) {
        CPP2_UFCS(add_virtual_destructor)(t);
    }
}

#line 682 "reflect.h2"
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

#line 727 "reflect.h2"
auto ordered_impl(
    meta::type_declaration& t, 
    cpp2::impl::in<std::string_view> ordering
) -> void
{
    auto has_spaceship {false}; 

    for ( auto& mf : CPP2_UFCS(get_member_functions)(t) ) 
    {
        if (CPP2_UFCS(has_name)(mf, "operator<=>")) {
            has_spaceship = true;
            auto return_name {CPP2_UFCS(unnamed_return_type)(mf)}; 
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

#line 756 "reflect.h2"
auto ordered(meta::type_declaration& t) -> void
{
    ordered_impl(t, "strong_ordering");
}

#line 764 "reflect.h2"
auto weakly_ordered(meta::type_declaration& t) -> void
{
    ordered_impl(t, "weak_ordering");
}

#line 772 "reflect.h2"
auto partially_ordered(meta::type_declaration& t) -> void
{
    ordered_impl(t, "partial_ordering");
}

#line 794 "reflect.h2"
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
        CPP2_UFCS(error)(t, "this type is partially copyable/movable - when you provide any of the more-specific operator= signatures, you must also provide the one with the general signature (out this, that); alternatively, consider removing all the operator= functions and let them all be generated for you with default memberwise semantics");
    }
    else {if (!(cpp2::move(smfs).out_this_in_that)) {
        CPP2_UFCS(add_member)(t, "operator=: (out this, that) = { }");
    }}
}

#line 822 "reflect.h2"
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

#line 850 "reflect.h2"
auto value(meta::type_declaration& t) -> void
{
    CPP2_UFCS(ordered)(t);
    CPP2_UFCS(basic_value)(t);
}

#line 856 "reflect.h2"
auto weakly_ordered_value(meta::type_declaration& t) -> void
{
    CPP2_UFCS(weakly_ordered)(t);
    CPP2_UFCS(basic_value)(t);
}

#line 862 "reflect.h2"
auto partially_ordered_value(meta::type_declaration& t) -> void
{
    CPP2_UFCS(partially_ordered)(t);
    CPP2_UFCS(basic_value)(t);
}

#line 891 "reflect.h2"
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

#line 928 "reflect.h2"
auto cpp2_struct(meta::type_declaration& t) -> void
{
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
    }
    CPP2_UFCS(cpp1_rule_of_zero)(t);
}

#line 969 "reflect.h2"
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

#line 992 "reflect.h2"
    for ( 
          auto const& m : CPP2_UFCS(get_members)(t) ) 
    if (  CPP2_UFCS(is_member_object)(m)) 
    {
        CPP2_UFCS(require)(m, CPP2_UFCS(is_public)(m) || CPP2_UFCS(is_default_access)(m), 
                    "an enumerator cannot be protected or private");

        auto mo {CPP2_UFCS(as_object)(m)}; 
        if (!(CPP2_UFCS(has_wildcard_type)(mo))) {
            CPP2_UFCS(error)(mo, "an explicit underlying type should be specified as a template argument to the metafunction - try 'enum<u16>' or 'flag_enum<u64>'");
        }

        auto init {CPP2_UFCS(initializer)(mo)}; 

        auto is_default_or_numeric {is_empty_or_a_decimal_number(init)}; 
        found_non_numeric |= !(CPP2_UFCS(empty)(init)) && !(is_default_or_numeric);
        CPP2_UFCS(require)(m, !(cpp2::move(is_default_or_numeric)) || !(found_non_numeric) || CPP2_UFCS(has_name)(mo, "none"), 
            (cpp2::to_string(CPP2_UFCS(name)(mo)) + ": enumerators with non-numeric values must come after all default and numeric values"));

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

#line 1029 "reflect.h2"
    if ((CPP2_UFCS(empty)(enumerators))) {
        CPP2_UFCS(error)(t, "an enumeration must contain at least one enumerator value");
        return ; 
    }

    //  Compute the default underlying type, if it wasn't explicitly specified
    if (underlying_type.value() == "") 
    {
        CPP2_UFCS(require)(t, !(cpp2::move(found_non_numeric)), 
            "if you write an enumerator with a non-numeric-literal value, you must specify the enumeration's underlying type");

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
                CPP2_UFCS(error)(t, "values are outside the range representable by the largest supported underlying signed type (i64)");
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

#line 1075 "reflect.h2"
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
    CPP2_UFCS(add_member)(t, ("    _value            : " + cpp2::to_string(underlying_type.value()) + ";"));
    CPP2_UFCS(add_member)(t, ("    private operator= : (implicit out this, _val: i64) == _value = cpp2::unsafe_narrow<" + cpp2::to_string(underlying_type.value()) + ">(_val);"));

    //  Generate the bitwise operations
    if (bitwise) {
        CPP2_UFCS(add_member)(t, "    operator|=: ( inout this, that )                 == _value |= that._value;");
        CPP2_UFCS(add_member)(t, "    operator&=: ( inout this, that )                 == _value &= that._value;");
        CPP2_UFCS(add_member)(t, "    operator^=: ( inout this, that )                 == _value ^= that._value;");
        CPP2_UFCS(add_member)(t, ("    operator| : (       this, that ) -> " + cpp2::to_string(CPP2_UFCS(name)(t)) + "  == _value |  that._value;"));
        CPP2_UFCS(add_member)(t, ("    operator& : (       this, that ) -> " + cpp2::to_string(CPP2_UFCS(name)(t)) + "  == _value &  that._value;"));
        CPP2_UFCS(add_member)(t, ("    operator^ : (       this, that ) -> " + cpp2::to_string(CPP2_UFCS(name)(t)) + "  == _value ^  that._value;"));
        CPP2_UFCS(add_member)(t, "    has       : (       this, that ) -> bool         == _value &  that._value;");
        CPP2_UFCS(add_member)(t, "    set       : ( inout this, that )                 == _value |= that._value;");
        CPP2_UFCS(add_member)(t, "    clear     : ( inout this, that )                 == _value &= that._value~;");
    }

    //  Add the enumerators
    for ( auto const& e : enumerators ) {
        CPP2_UFCS(add_member)(t, ("    " + cpp2::to_string(e.name) + " : " + cpp2::to_string(CPP2_UFCS(name)(t)) + " == " + cpp2::to_string(e.value) + ";"));
    }

    //  Generate the common functions
    CPP2_UFCS(add_member)(t, ("    get_raw_value     : (this) -> " + cpp2::to_string(cpp2::move(underlying_type.value())) + " == _value;"));
    CPP2_UFCS(add_member)(t, ("    operator=         : (out this) == { _value = " + cpp2::to_string(cpp2::move(default_value)) + "._value; }"));
    CPP2_UFCS(add_member)(t, "    operator=         : (out this, that) == { }");
    CPP2_UFCS(add_member)(t, "    operator<=>       : (this, that) -> std::strong_ordering;");
{
std::string to_string{"    to_string: (this) -> std::string = { \n"};

    //  Provide a 'to_string' function to print enumerator name(s)

#line 1120 "reflect.h2"
    {
        if (bitwise) {
            to_string += "    _ret   : std::string = \"(\";\n";
            to_string += "    _comma : std::string = ();\n";
            to_string += "    if this == none { return \"(none)\"; }\n";
        }

        for ( 
              auto const& e : cpp2::move(enumerators) ) {
            if (e.name != "_") {// ignore unnamed values
                if (bitwise) {
                    if (e.name != "none") {
                        to_string += ("    if (this & " + cpp2::to_string(e.name) + ") == " + cpp2::to_string(e.name) + " { _ret += _comma + \"" + cpp2::to_string(e.name) + "\"; _comma = \", \"; }\n");
                    }
                }
                else {
                    to_string += ("    if this == " + cpp2::to_string(e.name) + " { return \"" + cpp2::to_string(e.name) + "\"; }\n");
                }
            }
        }

        if (bitwise) {
            to_string += "    return _ret+\")\";\n}\n";
        }
        else {
            to_string += ("    return \"invalid " + cpp2::to_string(CPP2_UFCS(name)(t)) + " value\";\n}\n");
        }

        CPP2_UFCS(add_member)(t, cpp2::move(to_string));
    }
}
#line 1150 "reflect.h2"
}

#line 1162 "reflect.h2"
auto cpp2_enum(meta::type_declaration& t) -> void
{
    //  Let basic_enum do its thing, with an incrementing value generator
    CPP2_UFCS(basic_enum)(t, 
        [](std::string& value, cpp2::impl::in<std::string> specified_value) mutable -> void{
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

#line 1189 "reflect.h2"
auto flag_enum(meta::type_declaration& t) -> void
{
    //  Let basic_enum do its thing, with a power-of-two value generator
    CPP2_UFCS(basic_enum)(t, 
        [](std::string& value, cpp2::impl::in<std::string> specified_value) mutable -> void{
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

#line 1235 "reflect.h2"
auto cpp2_union(meta::type_declaration& t) -> void
{
    std::vector<value_member_info> alternatives {}; 
{
auto value{0};

    //  1. Gather: All the user-written members, and find/compute the max size

#line 1242 "reflect.h2"
    for ( 

           auto const& m : CPP2_UFCS(get_members)(t) )  { do 
    if (   CPP2_UFCS(is_member_object)(m)) 
    {
        CPP2_UFCS(require)(m, CPP2_UFCS(is_public)(m) || CPP2_UFCS(is_default_access)(m), 
                   "a union alternative cannot be protected or private");

        CPP2_UFCS(require)(m, !(CPP2_UFCS(starts_with)(CPP2_UFCS(name)(m), "is_")) 
                   && !(CPP2_UFCS(starts_with)(CPP2_UFCS(name)(m), "set_")), 
                   "a union alternative's name cannot start with 'is_' or 'set_' - that could cause user confusion with the 'is_alternative' and 'set_alternative' generated functions");

        auto mo {CPP2_UFCS(as_object)(m)}; 
        CPP2_UFCS(require)(mo, CPP2_UFCS(empty)(CPP2_UFCS(initializer)(mo)), 
                    "a union alternative cannot have an initializer");

        //  Adding local variable 'e' to work around a Clang warning
        value_member_info e {cpp2::impl::as_<std::string>(CPP2_UFCS(name)(mo)), CPP2_UFCS(type)(mo), cpp2::impl::as_<std::string>(value)}; 
        CPP2_UFCS(push_back)(alternatives, cpp2::move(e));

        CPP2_UFCS(mark_for_removal_from_enclosing_type)(mo);
        static_cast<void>(cpp2::move(mo));
    } while (false); ++value; }
}

#line 1266 "reflect.h2"
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

#line 1281 "reflect.h2"
    //  2. Replace: Erase the contents and replace with modified contents

    CPP2_UFCS(remove_marked_members)(t);
{
std::string storage{"    _storage: cpp2::aligned_storage<cpp2::max( "};

    //  Provide storage

#line 1287 "reflect.h2"
    {
        for ( 
              auto const& e : alternatives ) {
            storage += ("sizeof(" + cpp2::to_string(e.type) + "), ");
        }

        storage += "), cpp2::max( ";

        for ( 
              auto const& e : alternatives ) {
            storage += ("alignof(" + cpp2::to_string(e.type) + "), ");
        }

        storage += " )> = ();\n";
        CPP2_UFCS(add_member)(t, cpp2::move(storage));
    }
}

    //  Provide discriminator
#line 1305 "reflect.h2"
    CPP2_UFCS(add_member)(t, ("    _discriminator: " + cpp2::to_string(cpp2::move(discriminator_type)) + " = -1;\n"));

    //  Add the alternatives: is_alternative, get_alternative, and set_alternative
    for ( 
         auto const& a : alternatives ) 
    {
        CPP2_UFCS(add_member)(t, ("    is_" + cpp2::to_string(a.name) + ": (this) -> bool = _discriminator == " + cpp2::to_string(a.value) + ";\n"));

        CPP2_UFCS(add_member)(t, ("    " + cpp2::to_string(a.name) + ": (this) -> forward " + cpp2::to_string(a.type) + " pre(is_" + cpp2::to_string(a.name) + "()) = reinterpret_cast<* const " + cpp2::to_string(a.type) + ">(_storage&)*;\n"));

        CPP2_UFCS(add_member)(t, ("    " + cpp2::to_string(a.name) + ": (inout this) -> forward " + cpp2::to_string(a.type) + " pre(is_" + cpp2::to_string(a.name) + "()) = reinterpret_cast<*" + cpp2::to_string(a.type) + ">(_storage&)*;\n"));

        CPP2_UFCS(add_member)(t, ("    set_" + cpp2::to_string(a.name) + ": (inout this, _value: " + cpp2::to_string(a.type) + ") = { if !is_" + cpp2::to_string(a.name) + "() { _destroy(); std::construct_at( reinterpret_cast<*" + cpp2::to_string(a.type) + ">(_storage&), _value); } else { reinterpret_cast<*" + cpp2::to_string(a.type) + ">(_storage&)* = _value; } _discriminator = " + cpp2::to_string(a.value) + "; }\n"));

        CPP2_UFCS(add_member)(t, ("    set_" + cpp2::to_string(a.name) + ": (inout this, forward _args...: _) = { if !is_" + cpp2::to_string(a.name) + "() { _destroy(); std::construct_at( reinterpret_cast<*" + cpp2::to_string(a.type) + ">(_storage&), _args...); } else { reinterpret_cast<*" + cpp2::to_string(a.type) + ">(_storage&)* = :" + cpp2::to_string(a.type) + " = (_args...); } _discriminator = " + cpp2::to_string(a.value) + "; }\n"));
    }
{
std::string destroy{"    private _destroy: (inout this) = {\n"};

    //  Add destroy

#line 1324 "reflect.h2"
    {
        for ( 
              auto const& a : alternatives ) {
            destroy += ("        if _discriminator == " + cpp2::to_string(a.value) + " { std::destroy_at( reinterpret_cast<*" + cpp2::to_string(a.type) + ">(_storage&) ); }\n");
        }

        destroy += "        _discriminator = -1;\n";
        destroy += "    }\n";
        CPP2_UFCS(add_member)(t, cpp2::move(destroy));
    }
}

    //  Add the destructor
#line 1336 "reflect.h2"
    CPP2_UFCS(add_member)(t, "    operator=: (move this) = { _destroy(); _ = this; }");

    //  Add default constructor
    CPP2_UFCS(add_member)(t, "    operator=: (out this) = { }");
{
std::string value_set{""};

    //  Add copy/move construction and assignment

#line 1343 "reflect.h2"
    {
        for ( 
              auto const& a : cpp2::move(alternatives) ) {
            value_set += ("        if that.is_" + cpp2::to_string(a.name) + "() { set_" + cpp2::to_string(a.name) + "( that." + cpp2::to_string(a.name) + "() ); }\n");
        }
        value_set += "    }\n";

        CPP2_UFCS(add_member)(t, std::string("    operator=: (out this, that) = {\n") 
                    + "        _storage = ();\n" 
                    + "        _discriminator = -1;\n" 
                    + value_set
                    );
        CPP2_UFCS(add_member)(t, std::string("    operator=: (inout this, that) = {\n") 
                    + "        _storage = _;\n" 
                    + "        _discriminator = _;\n" 
                    + cpp2::move(value_set)
                    );
    }
}
#line 1361 "reflect.h2"
}

#line 1368 "reflect.h2"
auto print(cpp2::impl::in<meta::type_declaration> t) -> void
{
    std::cout << CPP2_UFCS(print)(t) << "\n";
}

#line 1387 "reflect.h2"
auto regex_gen(meta::type_declaration& t) -> void
{
    auto has_default {false}; 
    auto prefix {"regex"}; 
    std::string postfix {"_mod"};   // TODO: Remove mod syntax when 'm.initializer()' can be '("pat", "mod")'.

    std::map<std::string,std::pair<std::string,std::string>> expressions {}; 

    for ( auto& m : CPP2_UFCS(get_member_objects)(t) ) 
    {
        std::string name {CPP2_UFCS(name)(m)}; 

        if (CPP2_UFCS(starts_with)(name, prefix)) {

            if (!(CPP2_UFCS(has_initializer)(m))) {
                CPP2_UFCS(error)(t, "Regular expression must have an initializer.");
            }
            CPP2_UFCS(mark_for_removal_from_enclosing_type)(m);

            if (name == prefix) {
                if (has_default) {
                    CPP2_UFCS(error)(t, "Type can only contain one default named regular expression.");
                }
                has_default = true;
            }

            std::string expr {CPP2_UFCS(initializer)(m)}; 
            if (!(CPP2_UFCS(is_escaped)(expr))) {
                CPP2_UFCS(error)(t, ("Unknown string format '" + cpp2::to_string(expr) + "'"));
            }
            expr = CPP2_UFCS(substr)(expr, 1, CPP2_UFCS(size)(expr) - 2);

            if (CPP2_UFCS(ends_with)(name, postfix)) {
                name = CPP2_UFCS(substr)(name, 0, CPP2_UFCS(size)(name) - CPP2_UFCS(size)(postfix));

                if (CPP2_UFCS(contains)(expressions, name)) {
                    CPP2_ASSERT_IN_BOUNDS(expressions, name).second = cpp2::move(expr);
                }
                else {
                    CPP2_UFCS(error)(t, "Expression modifier defined without expression.");
                }

            }
            else {
                CPP2_ASSERT_IN_BOUNDS(expressions, name) = std::make_pair(cpp2::move(expr), "");
            }

#line 1435 "reflect.h2"
        }
    }

    CPP2_UFCS(remove_marked_members)(t);

    for ( auto const& expr : cpp2::move(expressions) ) {
        auto regular_expression {::cpp2::regex::generate_template(expr.second.first, expr.second.second, [_0 = t](auto const& message) mutable -> void { CPP2_UFCS(error)(_0, message);  })}; 

        CPP2_UFCS(add_member)(t, ("public " + cpp2::to_string(expr.first) + "_matcher: type = " + cpp2::to_string(cpp2::move(regular_expression))));
        CPP2_UFCS(add_member)(t, ("public " + cpp2::to_string(expr.first) + ": cpp2::regex::regular_expression<char, " + cpp2::to_string(expr.first) + "_matcher> = ();"));
    }
}

#line 1453 "reflect.h2"
[[nodiscard]] auto apply_metafunctions(
    declaration_node& n, 
    type_declaration& rtype, 
    auto const& error
    ) -> bool

{
    if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(is_type)(n)) ) { cpp2::cpp2_default.report_violation(""); }

    //  Check for _names reserved for the metafunction implementation
    for ( 
          auto const& m : CPP2_UFCS(get_members)(rtype) ) 
    {
        CPP2_UFCS(require)(m, !(CPP2_UFCS(starts_with)(CPP2_UFCS(name)(m), "_")) || CPP2_UFCS(ssize)(CPP2_UFCS(name)(m)) == 1, 
                    "a type that applies a metafunction cannot have a body that declares a name that starts with '_' - those names are reserved for the metafunction implementation");
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

        CPP2_UFCS(set_metafunction_name)(rtype, name, args);

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
        else {if (name == "regex") {
            regex_gen(rtype);
        }
        else {
            error("unrecognized metafunction name: " + name);
            error("(temporary alpha limitation) currently the supported names are: interface, polymorphic_base, ordered, weakly_ordered, partially_ordered, copyable, basic_value, value, weakly_ordered_value, partially_ordered_value, struct, enum, flag_enum, union, cpp1_rule_of_zero, regex, print");
            return false; 
        }}}}}}}}}}}}}}}}}

        if ((
            !(CPP2_UFCS(empty)(args)) 
            && !(CPP2_UFCS(arguments_were_used)(rtype)))) 

        {
            error(name + " did not use its template arguments - did you mean to write '" + name + " <" + CPP2_ASSERT_IN_BOUNDS_LITERAL(cpp2::move(args), 0) + "> type' (with the spaces)?");
            return false; 
        }
    }

    return true; 
}

#line 1559 "reflect.h2"
}

}

#endif
