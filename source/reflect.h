
#ifndef REFLECT_H__CPP2
#define REFLECT_H__CPP2


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"


#line 283 "reflect.h2"
namespace cpp2 {
namespace meta {

#line 289 "reflect.h2"
class object_declaration;

#line 314 "reflect.h2"
}
}

#line 434 "reflect.h2"
namespace cpp2 {

#line 748 "reflect.h2"
}


//=== Cpp2 type definitions and function declarations ===========================


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

namespace cpp2 {

namespace meta {


//-----------------------------------------------------------------------
//
//  Compiler services
//
//-----------------------------------------------------------------------
//

class compiler_services
{
    std::vector<error_entry>* errors;
    int                       errors_original_size;
    std::deque<token>*        generated_tokens;
    cpp2::parser              parser;
    std::string               meta_function_name;

public:
    compiler_services(
        std::vector<error_entry>* errors_,
        std::deque<token>*        generated_tokens_
    )
        : errors{errors_}
        , errors_original_size{static_cast<int>(std::ssize(*errors))}
        , generated_tokens{generated_tokens_}
        , parser{*errors}
    {
    }

    auto set_meta_function_name(std::string_view s) {
        meta_function_name = s;
    }

protected:
    auto parse_statement(
        std::string_view source
    )
        -> std::unique_ptr<statement_node>
    {
        generated_lines.push_back({});
        auto &lines = generated_lines.back();

        auto add_line = [&] (std::string_view s) {
            lines.emplace_back( s, source_line::category::cpp2 );
        };

        //  First split this string into source_lines
        //
        if (auto newline_pos = source.find('\n');
            source.length() > 1
            && newline_pos != source.npos
            )
        {
            while (newline_pos != std::string_view::npos)
            {
                add_line( source.substr(0, newline_pos) );
                source.remove_prefix( newline_pos+1 );
                newline_pos = source.find('\n');
            }
        }
        if (!source.empty()) {
            add_line( source );
        }

        //  Now lex this source fragment to generate
        //  a single grammar_map entry, whose .second
        //  is the vector of tokens
        generated_lexers.emplace_back( *errors );
        auto& tokens = generated_lexers.back();
        tokens.lex( lines, true );
        assert(std::ssize(tokens.get_map()) == 1);

        //  Now parse this single declaration from
        //  the lexed tokens
        return parser.parse_one_declaration(
            tokens.get_map().begin()->second,
            *generated_tokens
        );
    }

public:
    virtual auto position() const
        -> source_position
    {
        return {};
    }

    auto require(
        bool             b,
        std::string_view msg
    ) const
        -> void
    {
        if (!b) {
            error( msg );
        }
    }

    auto error(std::string_view msg) const
        -> void
    {
        auto message = std::string{msg};
        if (!meta_function_name.empty()) {
            message = "while applying @" + meta_function_name + " - " + message;
        }
        errors->emplace_back( position(), message);
    }
};


//-----------------------------------------------------------------------
//
//  Declarations
//
//-----------------------------------------------------------------------
//

//  All declarations are noncopyable wrappers around a pointer to node
//
class declaration_base : public compiler_services
{
protected:
    //  Note: const member => implicitly =delete's copy/move
    declaration_node* const n;

    declaration_base(
        declaration_node*        n_,
        compiler_services const& s
    )
        : compiler_services{s}
        , n{n_}
    {
        assert(n && "a meta::declaration must point to a valid declaration_node, not null");
    }

    auto position() const -> source_position override { return n->position(); }
};

class function_declaration;
class type_declaration;
class object_declaration;


//-----------------------------------------------------------------------
//  All declarations
//
class declaration
    : public declaration_base
{
public:
    declaration(
        declaration_node*        n_,
        compiler_services const& s
    )
        : declaration_base{n_, s}
    { }

    auto is_public        () const -> bool { return n->is_public(); }
    auto is_protected     () const -> bool { return n->is_protected(); }
    auto is_private       () const -> bool { return n->is_private(); }
    auto is_default_access() const -> bool { return n->is_default_access(); }

    auto make_public      () const -> bool { return n->make_public(); }
    auto make_protected   () const -> bool { return n->make_protected(); }
    auto make_private     () const -> bool { return n->make_private(); }

    auto has_name()                   const -> bool        { return n->has_name(); }
    auto has_name(std::string_view s) const -> bool        { return n->has_name(s); }

    auto name() const -> std::string_view {
        if (has_name()) { return n->name()->as_string_view(); }
        else            { return ""; }
    }

    auto has_initializer() const -> bool { return n->has_initializer(); }

    auto is_global   () const -> bool { return n->is_global(); }

    auto is_function () const -> bool { return n->is_function(); }
    auto is_object   () const -> bool { return n->is_object(); }
    auto is_type     () const -> bool { return n->is_type(); }
    auto is_namespace() const -> bool { return n->is_namespace(); }
    auto is_alias    () const -> bool { return n->is_alias(); }

    auto as_function() const -> function_declaration;
    auto as_object  () const -> object_declaration;
    auto as_type    () const -> type_declaration;

    auto parent_is_function   () const -> bool { return n->parent_is_function(); }
    auto parent_is_object     () const -> bool { return n->parent_is_object(); }
    auto parent_is_type       () const -> bool { return n->parent_is_type(); }
    auto parent_is_namespace  () const -> bool { return n->parent_is_namespace(); }
    auto parent_is_alias      () const -> bool { return n->parent_is_alias(); }
    auto parent_is_polymorphic() const -> bool { return n->parent_is_polymorphic(); }
};


//-----------------------------------------------------------------------
//  Function declarations
//
class function_declaration
    : public declaration
{
public:
    function_declaration(
        declaration_node*        n_,
        compiler_services const& s
    )
        : declaration{n_, s}
    {
        assert(n->is_function());
    }

    auto index_of_parameter_named(std::string_view s) const -> int  { return n->index_of_parameter_named(s); }
    auto has_parameter_named     (std::string_view s) const -> bool { return n->has_parameter_named(s); }
    auto has_in_parameter_named  (std::string_view s) const -> bool { return n->has_in_parameter_named(s); }
    auto has_out_parameter_named (std::string_view s) const -> bool { return n->has_out_parameter_named(s); }
    auto has_move_parameter_named(std::string_view s) const -> bool { return n->has_move_parameter_named(s); }

    auto has_parameter_with_name_and_pass(std::string_view s, passing_style pass) const -> bool
                                                      { return n->has_parameter_with_name_and_pass(s, pass); }

    auto is_function_with_this        () const -> bool { return n->is_function_with_this(); }
    auto is_virtual                   () const -> bool { return n->is_virtual_function(); }
    auto is_defaultable               () const -> bool { return n->is_defaultable_function(); }
    auto is_constructor               () const -> bool { return n->is_constructor(); }
    auto is_default_constructor       () const -> bool { return n->is_default_constructor(); }
    auto is_constructor_with_that     () const -> bool { return n->is_constructor_with_that(); }
    auto is_constructor_with_in_that  () const -> bool { return n->is_constructor_with_in_that(); }
    auto is_constructor_with_move_that() const -> bool { return n->is_constructor_with_move_that(); }
    auto is_assignment                () const -> bool { return n->is_assignment(); }
    auto is_assignment_with_that      () const -> bool { return n->is_assignment_with_that(); }
    auto is_assignment_with_in_that   () const -> bool { return n->is_assignment_with_in_that(); }
    auto is_assignment_with_move_that () const -> bool { return n->is_assignment_with_move_that(); }
    auto is_destructor                () const -> bool { return n->is_destructor(); }

    auto is_copy_or_move() const -> bool { return is_constructor_with_that() || is_assignment_with_that(); }

    auto has_declared_return_type() const -> bool { return n->has_declared_return_type(); }
    auto has_bool_return_type    () const -> bool { return n->has_bool_return_type(); }
    auto has_non_void_return_type() const -> bool { return n->has_non_void_return_type(); }

    auto unnamed_return_type() const -> std::string { return n->unnamed_return_type_to_string(); }

    auto is_binary_comparison_function() const -> bool { return n->is_binary_comparison_function(); }

    auto make_virtual() -> bool { return n->make_function_virtual(); }
};

auto declaration::as_function() const
    -> function_declaration
{
    return function_declaration(n, *this);
}


//=======================================================================
//  Switch to Cpp2
}
}
#line 283 "reflect.h2"
namespace cpp2 {
namespace meta {

//-----------------------------------------------------------------------
//  Object declarations
//
class object_declaration
: public declaration {

#line 293 "reflect.h2"
    public: object_declaration(

        cpp2::in<declaration_node*> n_, 
        cpp2::in<compiler_services> s
    );

#line 303 "reflect.h2"
    public: [[nodiscard]] auto is_const() const -> bool;

    public: [[nodiscard]] auto has_wildcard_type() const -> bool;

public: object_declaration(object_declaration const& that);

    // TODO: auto get_type() const ->

#line 309 "reflect.h2"
};

#line 312 "reflect.h2"
//=======================================================================
//  Switch to Cpp1
}
}
namespace cpp2 {
namespace meta {

auto declaration::as_object() const
    -> object_declaration
{
    return object_declaration(n, *this);
}


//-----------------------------------------------------------------------
//  Type declarations
//
class type_declaration
    : public declaration
{
public:
    type_declaration(
        declaration_node*        n_,
        compiler_services const& s
    )
        : declaration{n_, s}
    {
        assert(n->is_type());
    }

    auto is_polymorphic() const -> bool { return n->is_polymorphic(); }
    auto is_final      () const -> bool { return n->is_type_final(); }
    auto make_final    ()       -> bool { return n->make_type_final(); }

    auto get_member_functions() const
        -> std::vector<function_declaration>
    {
        auto ret = std::vector<function_declaration>{};
        for (auto d : n->get_type_scope_declarations(declaration_node::functions)) {
            ret.emplace_back( d, *this );
        }
        return ret;
    }

    auto get_member_objects() const
        -> std::vector<object_declaration>
    {
        auto ret = std::vector<object_declaration>{};
        for (auto& d : n->get_type_scope_declarations(declaration_node::objects)) {
            ret.emplace_back( d, *this );
        }
        return ret;
    }

    auto get_member_types() const
        -> std::vector<type_declaration>
    {
        auto ret = std::vector<type_declaration>{};
        for (auto& d : n->get_type_scope_declarations(declaration_node::types)) {
            ret.emplace_back( d, *this );
        }
        return ret;
    }

    auto get_members() const
        -> std::vector<declaration>
    {
        auto ret = std::vector<declaration>{};
        for (auto& d : n->get_type_scope_declarations(declaration_node::all)) {
            ret.emplace_back( d, *this );
        }
        return ret;
    }

    struct declared_that_funcs {
        bool out_this_in_that     = false;
        bool out_this_move_that   = false;
        bool inout_this_in_that   = false;
        bool inout_this_move_that = false;
    };

    auto query_declared_that_functions() const
        -> declared_that_funcs
    {
        auto declared = n->find_declared_that_functions();
        return {
            declared.out_this_in_that     != nullptr,
            declared.out_this_move_that   != nullptr,
            declared.inout_this_in_that   != nullptr,
            declared.inout_this_move_that != nullptr
        };
    }

    auto add_member( std::string_view source )
        -> bool
    {
        if (auto decl = parse_statement(source)) {
            return n->add_type_member(std::move(decl));
        }
        return false;
    }
};


//=======================================================================
//  Switch to Cpp1
}
}
namespace cpp2 {
namespace meta {

auto declaration::as_type() const
    -> type_declaration
{
    return type_declaration(n, *this);
}


//=======================================================================
//  Switch to Cpp2, and close meta subnamespace
}
}
namespace cpp2 {

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

#line 455 "reflect.h2"
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

#line 494 "reflect.h2"
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
//  A pure polymorphic base type that has no instance data, is not
//  copyable, and whose destructor is either public and virtual or
//  protected and nonvirtual.
//
//  Unlike an interface, it can have nonpublic and nonvirtual functions.
//
auto polymorphic_base(meta::type_declaration& t) -> void;

#line 539 "reflect.h2"
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
    cpp2::in<std::string_view> ordering// must be "strong_ordering" etc.
) -> void;

#line 584 "reflect.h2"
//-----------------------------------------------------------------------
//  ordered - a totally ordered type
//
//  Note: the ordering that should be encouraged as default gets the nice name
//
auto ordered(meta::type_declaration& t) -> void;

#line 594 "reflect.h2"
//-----------------------------------------------------------------------
//  weakly_ordered - a weakly ordered type
//
auto weakly_ordered(meta::type_declaration& t) -> void;

#line 602 "reflect.h2"
//-----------------------------------------------------------------------
//  partially_ordered - a partially ordered type
//
auto partially_ordered(meta::type_declaration& t) -> void;

#line 611 "reflect.h2"
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

#line 649 "reflect.h2"
//-----------------------------------------------------------------------
//
//  basic_value
//
//  A regular type: copyable, plus has public default construction
//  and no protected or virtual functions
//
auto basic_value(meta::type_declaration& t) -> void;

#line 675 "reflect.h2"
//-----------------------------------------------------------------------
//
//     "A 'value' is a totally ordered basic_value..."
//          -- P0707R4, section 3
//
//  value - a value type that is totally ordered
//
//  Note: the ordering that should be encouraged as default gets the nice name
//
auto value(meta::type_declaration& t) -> void;

#line 690 "reflect.h2"
auto weakly_ordered_value(meta::type_declaration& t) -> void;

#line 696 "reflect.h2"
auto partially_ordered_value(meta::type_declaration& t) -> void;

#line 703 "reflect.h2"
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
//  a basic_value with only public bases, objects, and functions,
//  no virtual functions, and no user-defined constructors
//  (i.e., no invariants) or assignment or destructors.
//
auto cpp2_struct(meta::type_declaration& t) -> void;

#line 746 "reflect.h2"
//=======================================================================
//  Switch to Cpp1
}
namespace cpp2 {


//-----------------------------------------------------------------------
//
//  Now finish the rest of the parser definition
//
//-----------------------------------------------------------------------
//

auto parser::apply_type_meta_functions( declaration_node& n )
    -> bool
{
    assert(n.is_type());

    //  Get the reflection state ready to pass to the function
    auto cs = meta::compiler_services{ &errors, generated_tokens };
    auto rtype = meta::type_declaration{ &n, cs };

    //  For each metafunction, apply it
    for (auto& meta : n.meta_functions)
    {
        rtype.set_meta_function_name( meta->to_string() );

        if (meta->to_string() == "interface") {
            interface( rtype );
        }
        else if (meta->to_string() == "polymorphic_base") {
            polymorphic_base( rtype );
        }
        else if (meta->to_string() == "ordered") {
            ordered( rtype );
        }
        else if (meta->to_string() == "weakly_ordered") {
            weakly_ordered( rtype );
        }
        else if (meta->to_string() == "partially_ordered") {
            partially_ordered( rtype );
        }
        else if (meta->to_string() == "copyable") {
            copyable( rtype );
        }
        else if (meta->to_string() == "basic_value") {
            basic_value( rtype );
        }
        else if (meta->to_string() == "value") {
            value( rtype );
        }
        else if (meta->to_string() == "weakly_ordered_value") {
            weakly_ordered_value( rtype );
        }
        else if (meta->to_string() == "partially_ordered_value") {
            partially_ordered_value( rtype );
        }
        else if (meta->to_string() == "struct") {
            cpp2_struct( rtype );
        }
        else {
            error( "(temporary alpha limitation) unrecognized metafunction name '" + meta->to_string() + "' - currently the supported names are: interface, polymorphic_base, ordered, weakly_ordered, partially_ordered, copyable, basic_value, value, weakly_ordered_value, partially_ordered_value, struct" );
            return false;
        }
    }
    return true;
}


}


//=== Cpp2 function definitions =================================================


#line 283 "reflect.h2"
namespace cpp2 {
namespace meta {

#line 293 "reflect.h2"
    object_declaration::object_declaration(

        cpp2::in<declaration_node*> n_, 
        cpp2::in<compiler_services> s
    )
        : declaration{ n_, s }
#line 298 "reflect.h2"
    {

        cpp2::Default.expects(CPP2_UFCS_0(is_object, (*cpp2::assert_not_null(n))), "");
    }

    [[nodiscard]] auto object_declaration::is_const() const -> bool { return CPP2_UFCS_0(is_const, (*cpp2::assert_not_null(n)));  }

    [[nodiscard]] auto object_declaration::has_wildcard_type() const -> bool { return CPP2_UFCS_0(has_wildcard_type, (*cpp2::assert_not_null(n)));  }

    object_declaration::object_declaration(object_declaration const& that)
                                : declaration{ that }{}

#line 314 "reflect.h2"
}
}

#line 434 "reflect.h2"
namespace cpp2 {

#line 448 "reflect.h2"
auto add_virtual_destructor(meta::type_declaration& t) -> void
{
    CPP2_UFCS(require, t, CPP2_UFCS(add_member, t, "operator=: (virtual move this) = { }"), 
               "could not add virtual destructor");
}

#line 467 "reflect.h2"
auto interface(meta::type_declaration& t) -> void
{
    auto has_dtor {false}; 

    { auto&& cpp2_range = CPP2_UFCS_0(get_members, t); for ( auto& m : cpp2_range ) 
    {
        CPP2_UFCS(require, m, !(CPP2_UFCS_0(is_object, m)), 
                   "interfaces may not contain data objects");
        if (CPP2_UFCS_0(is_function, m)) {
            auto mf {CPP2_UFCS_0(as_function, m)}; 
            CPP2_UFCS(require, mf, !(CPP2_UFCS_0(is_copy_or_move, mf)), 
                        "interfaces may not copy or move; consider a virtual clone() instead");
            CPP2_UFCS(require, mf, !(CPP2_UFCS_0(has_initializer, mf)), 
                        "interface functions must not have a function body; remove the '=' initializer");
            CPP2_UFCS(require, mf, CPP2_UFCS_0(make_public, mf), 
                        "interface functions must be public");
            CPP2_UFCS_0(make_virtual, mf);
            has_dtor |= CPP2_UFCS_0(is_destructor, mf);
        }
    }}

#line 488 "reflect.h2"
    if (!(std::move(has_dtor))) {
        add_virtual_destructor(t);
    }
}

#line 514 "reflect.h2"
auto polymorphic_base(meta::type_declaration& t) -> void
{
    auto has_dtor {false}; 

    { auto&& cpp2_range = CPP2_UFCS_0(get_member_functions, t); for ( auto& mf : cpp2_range ) 
    {
        if (CPP2_UFCS_0(is_default_access, mf)) {
            CPP2_UFCS_0(make_public, mf);
        }
        CPP2_UFCS(require, mf, !(CPP2_UFCS_0(is_copy_or_move, mf)), 
                    "polymorphic base types may not copy or move; consider a virtual clone() instead");
        if (CPP2_UFCS_0(is_destructor, mf)) {
            has_dtor = true;
            CPP2_UFCS(require, mf, (CPP2_UFCS_0(is_public, mf) && CPP2_UFCS_0(is_virtual, mf)) 
                        || (CPP2_UFCS_0(is_protected, mf) && !(CPP2_UFCS_0(is_virtual, mf))), 
                        "a polymorphic base type destructor must be public and virtual, or protected and nonvirtual");
        }
    }}

#line 533 "reflect.h2"
    if (!(std::move(has_dtor))) {
        add_virtual_destructor(t);
    }
}

#line 559 "reflect.h2"
auto ordered_impl(
    meta::type_declaration& t, 
    cpp2::in<std::string_view> ordering
) -> void
{
    auto has_spaceship {false}; 

    { auto&& cpp2_range = CPP2_UFCS_0(get_member_functions, t); for ( auto& mf : cpp2_range ) 
    {
        if (CPP2_UFCS(has_name, mf, "operator<=>")) {
            has_spaceship = true;
            auto return_name {CPP2_UFCS_0(unnamed_return_type, mf)}; 
            if (CPP2_UFCS(find, return_name, ordering)==return_name.npos) 
            {
                CPP2_UFCS(error, mf, "operator<=> must return std::" + cpp2::as_<std::string>(ordering));
            }
        }
    }}

#line 578 "reflect.h2"
    if (!(std::move(has_spaceship))) {
        CPP2_UFCS(require, t, CPP2_UFCS(add_member, t, "operator<=>: (this, that) -> std::" + (cpp2::as_<std::string>(ordering)) + ";"), 
                   "could not add operator<=> with std::" + (cpp2::as_<std::string>(ordering)));
    }
}

#line 589 "reflect.h2"
auto ordered(meta::type_declaration& t) -> void
{
    ordered_impl(t, "strong_ordering");
}

#line 597 "reflect.h2"
auto weakly_ordered(meta::type_declaration& t) -> void
{
    ordered_impl(t, "weak_ordering");
}

#line 605 "reflect.h2"
auto partially_ordered(meta::type_declaration& t) -> void
{
    ordered_impl(t, "partial_ordering");
}

#line 627 "reflect.h2"
auto copyable(meta::type_declaration& t) -> void
{
    //  If the user explicitly wrote any of the copy/move functions,
    //  they must also have written the most general one - we can't
    //  assume we can safely generate it for them since they've opted
    //  into customized semantics
    auto smfs {CPP2_UFCS_0(query_declared_that_functions, t)}; 
    if ( !(smfs.out_this_in_that) 
        && (
            smfs.out_this_move_that 
            || smfs.inout_this_in_that 
            || smfs.inout_this_move_that)) 

    {
        CPP2_UFCS(error, t, "this type is partially copyable/movable - when you provide any of the more-specific operator= signatures, you must also provide the one with the general signature (out this, that); alternatively, consider removing all the operator= functions and let them all be generated for you with default memberwise semantics");
    }
    else {if (!(std::move(smfs).out_this_in_that)) {
        CPP2_UFCS(require, t, CPP2_UFCS(add_member, t, "operator=: (out this, that) = { }"), 
                   "could not add general operator=:(out this, that)");
    }}
}

#line 656 "reflect.h2"
auto basic_value(meta::type_declaration& t) -> void
{
    copyable(t);

    auto has_default_ctor {false}; 
    { auto&& cpp2_range = CPP2_UFCS_0(get_member_functions, t); for ( auto& mf : cpp2_range ) {
        has_default_ctor |= CPP2_UFCS_0(is_default_constructor, mf);
        CPP2_UFCS(require, mf, !(CPP2_UFCS_0(is_protected, mf)) && !(CPP2_UFCS_0(is_virtual, mf)), 
                    "a value type may not have a protected or virtual function");
        CPP2_UFCS(require, mf, !(CPP2_UFCS_0(is_destructor, mf)) || CPP2_UFCS_0(is_public, mf), 
                    "a value type may not have a non-public destructor");
    }}

#line 669 "reflect.h2"
    if (!(std::move(has_default_ctor))) {
        CPP2_UFCS(require, t, CPP2_UFCS(add_member, t, "operator=: (out this) = { }"), 
                   "could not add default constructor");
    }
}

#line 684 "reflect.h2"
auto value(meta::type_declaration& t) -> void
{
    ordered(t);
    basic_value(t);
}

auto weakly_ordered_value(meta::type_declaration& t) -> void
{
    weakly_ordered(t);
    basic_value(t);
}

auto partially_ordered_value(meta::type_declaration& t) -> void
{
    partially_ordered(t);
    basic_value(t);
}

#line 728 "reflect.h2"
auto cpp2_struct(meta::type_declaration& t) -> void
{
    { auto&& cpp2_range = CPP2_UFCS_0(get_members, t); for ( auto& m : cpp2_range ) 
    {
        CPP2_UFCS(require, m, CPP2_UFCS_0(make_public, m), 
                   "all struct members must be public");
        if (CPP2_UFCS_0(is_function, m)) {
            auto mf {CPP2_UFCS_0(as_function, m)}; 
            CPP2_UFCS(require, t, !(CPP2_UFCS_0(is_virtual, mf)), 
                       "a struct may not have a virtual function");
            CPP2_UFCS(require, t, !(CPP2_UFCS(has_name, mf, "operator=")), 
                       "a struct may not have a user-defined operator=");
        }
    }}
#line 742 "reflect.h2"
    basic_value(t);  // a plain_struct is-a basic_value
}

#line 748 "reflect.h2"
}

#endif
