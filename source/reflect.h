
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

#ifndef __CPP2_REFLECT
#define __CPP2_REFLECT

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
    auto require(
        bool             b,
        std::string_view msg,
        source_position  pos = source_position{}
    )
        -> void
    {
        if (!b) {
            error( msg, pos );
        }
    }

    auto error(
        std::string_view msg,
        source_position  pos = source_position{}
    )
        -> void
    {
        auto message = std::string{msg};
        if (!meta_function_name.empty()) {
            message = "while applying @" + meta_function_name + " - " + message;
        }
        errors->emplace_back( pos, message );
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

    auto position() const -> source_position { return n->position(); }

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


//-----------------------------------------------------------------------
//  Object declarations
//
class object_declaration
    : public declaration
{
public:
    object_declaration(
        declaration_node*        n_,
        compiler_services const& s
    )
        : declaration{n_, s}
    {
        assert(n->is_object());
    }

    auto is_const() const -> bool { return n->is_const(); }

    auto has_wildcard_type() const -> bool { return n->has_wildcard_type(); }

    // TODO: auto get_type() const -> 
        
};

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

auto declaration::as_type() const
    -> type_declaration
{
    return type_declaration(n, *this);
}


//  Close namespace subnamespace meta
}


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
auto add_virtual_destructor(meta::type_declaration& t)
    -> void
{
    t.require( t.add_member( "operator=: (virtual move this) = { }"),
               "could not add virtual destructor");
}


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
auto interface(meta::type_declaration& t)
    -> void
{
    auto has_dtor = false;

    for (auto m : t.get_members())
    {
        m.require( !m.is_object(),
                   "interfaces may not contain data objects");
        if (m.is_function()) {
            auto mf = m.as_function();
            mf.require( !mf.is_copy_or_move(),
                        "interfaces may not copy or move; consider a virtual clone() instead");
            mf.require( !mf.has_initializer(),
                        "interface functions must not have a function body; remove the '=' initializer");
            mf.require( mf.make_public(),
                        "interface functions must be public");
            mf.make_virtual();
            has_dtor |= mf.is_destructor();
        }
    }

    if (!has_dtor) {
        add_virtual_destructor(t);
    }
}


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
auto polymorphic_base(meta::type_declaration& t)
    -> void
{
    auto has_dtor = false;

    for (auto mf : t.get_member_functions())
    {
        if (mf.is_default_access()) {
            mf.make_public();
        }
        mf.require( !mf.is_copy_or_move(),
                    "polymorphic base types may not copy or move; consider a virtual clone() instead");
        if (mf.is_destructor()) {
            has_dtor = true;
            mf.require( (mf.is_public() && mf.is_virtual())
                        || (mf.is_protected() && !mf.is_virtual()),
                        "a polymorphic base type destructor must be public and virtual, or protected and nonvirtual");
        }
    }

    if (!has_dtor) {
        add_virtual_destructor(t);
    }

    for (auto mo : t.get_member_objects()) {
        mo.require( mo.has_name("this"),
                    "polymorphic base types may not contain data");
    }
}


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
    std::string_view        ordering    // must be "strong_ordering" etc.
)
    -> void
{
    auto has_spaceship = false;

    for (auto mf : t.get_member_functions())
    {
        if (mf.has_name("operator<=>")) {
            has_spaceship = true;
            auto return_name = mf.unnamed_return_type();
            if (return_name.find(ordering) == return_name.npos)
            {
                mf.error( "operator<=> must return std::" + std::string{ordering} );
            }
        }
    }

    if (!has_spaceship) {
        t.require( t.add_member( "operator<=>: (this, that) -> std::" + std::string{ordering} + ";" ),
                   "could not add operator<=> with std::" + std::string{ordering} );
    }
}

//-----------------------------------------------------------------------
//  ordered - a totally ordered type
// 
//  Note: the ordering that should be encouraged as default gets the nice name
//
auto ordered(meta::type_declaration& t)
-> void
{
    ordered_impl( t, "strong_ordering" );
}

//-----------------------------------------------------------------------
//  weakly_ordered - a weakly ordered type
//
auto weakly_ordered(meta::type_declaration& t)
-> void
{
    ordered_impl( t, "weak_ordering" );
}

//-----------------------------------------------------------------------
//  partially_ordered - a partially ordered type
//
auto partially_ordered(meta::type_declaration& t)
-> void
{
    ordered_impl( t, "partial_ordering" );
}


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
//  basic_value
//
//  A regular type: public default construction, copy/move construction
//  and assignment, and no protected or virtual functions
//
auto basic_value(meta::type_declaration& t)
    -> void
{
    //  If the user explicitly wrote any of the copy/move functions,
    //  they must also have written the most general one - we can't
    //  assume we can safely generate it for them since they've opted
    //  into customized semantics
    auto smfs = t.query_declared_that_functions();
    if (
        !smfs.out_this_in_that
        && (
            smfs.out_this_move_that
            || smfs.inout_this_in_that
            || smfs.inout_this_move_that
        )
        )
    {
        t.error( "this type is partially copyable/movable - when you provide any of the more-specific operator= signatures, you must also provide the one with the general signature (out this, that); alternatively, consider removing all the operator= functions and let them all be generated for you with default memberwise semantics" );
    }
    else if (!smfs.out_this_in_that) {
        t.require( t.add_member( "operator=: (out this, that) = { }"),
                   "could not add general operator=:(out this, that)");
    }

    auto has_default_ctor = false;
    for (auto mf : t.get_member_functions()) {
        has_default_ctor |= mf.is_default_constructor();
        mf.require( !mf.is_protected() && !mf.is_virtual(),
                    "a value type may not have a protected or virtual function");
        mf.require( !mf.is_destructor() || mf.is_public(),
                    "a value type may not have a non-public destructor");
    }

    if (!has_default_ctor) {
        t.require( t.add_member( "operator=: (out this) = { }"),
                   "could not add default constructor");
    }
}

//-----------------------------------------------------------------------
//
//     "A 'value' is a totally ordered basic_value..."
//          -- P0707R4, section 3
// 
//  value - a value type that is totally ordered
// 
//  Note: the ordering that should be encouraged as default gets the nice name
//
auto value(meta::type_declaration& t)
    -> void
{
    ordered(t);
    basic_value(t);
}

auto weakly_ordered_value(meta::type_declaration& t)
    -> void
{
    weakly_ordered(t);
    basic_value(t);
}

auto partially_ordered_value(meta::type_declaration& t)
    -> void
{
    partially_ordered(t);
    basic_value(t);
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
//  a basic_value with only public bases, objects, and functions,
//  no virtual functions, and no user-defined constructors
//  (i.e., no invariants) or assignment or destructors.
//
auto struct_(meta::type_declaration& t)
    -> void
{
    for (auto m : t.get_members())
    {
        m.require( m.make_public(),
                   "all struct members must be public");
        if (m.is_function()) {
            auto mf = m.as_function();
            t.require( !mf.is_virtual(),
                       "a struct may not have a virtual function");
            t.require( !mf.has_name("operator="),
                       "a struct may not have a user-defined operator=");
        }
    }
    basic_value(t);		// a plain_struct is-a basic_value
}


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
            struct_( rtype );
        }
        else {
            error( "(temporary alpha limitation) unrecognized metafunction name '" + meta->to_string() + "' - currently the supported names are: interface, polymorphic_base, ordered, weakly_ordered, partially_ordered, value, weakly_ordered_value, partially_ordered_value, struct" );
            return false;
        }
    }
    return true;
}


}

#endif
