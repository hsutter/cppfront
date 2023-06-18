
#ifndef REFLECT_H__CPP2
#define REFLECT_H__CPP2


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"


#line 20 "reflect.h2"
namespace cpp2 {

namespace meta {

#line 32 "reflect.h2"
class compiler_services;

#line 141 "reflect.h2"
class declaration_base;

#line 165 "reflect.h2"
class declaration;

#line 225 "reflect.h2"
class function_declaration;

#line 282 "reflect.h2"
class object_declaration;

#line 308 "reflect.h2"
class type_declaration;

#line 704 "reflect.h2"
}
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

#line 20 "reflect.h2"
namespace cpp2 {

namespace meta {

#line 25 "reflect.h2"
//-----------------------------------------------------------------------
//
//  Compiler services
//
//-----------------------------------------------------------------------
//

class compiler_services
 {
    private: std::vector<error_entry>* errors; 
    private: int errors_original_size; 
    private: std::deque<token>* generated_tokens; 
    private: cpp2::parser parser; 
    private: std::string meta_function_name {}; 

    public: compiler_services(

        std::vector<error_entry>* errors_, 
        std::deque<token>* generated_tokens_
    );

#line 52 "reflect.h2"
    public: auto set_meta_function_name(cpp2::in<std::string_view> s) -> void;
        

#line 56 "reflect.h2"
    protected: [[nodiscard]] auto parse_statement(

        std::string_view source
    ) -> 
        std::unique_ptr<statement_node>;

#line 104 "reflect.h2"
    public: [[nodiscard]] virtual auto position() const -> 
        source_position; 

#line 110 "reflect.h2"
    public: auto require(

        cpp2::in<bool> b, 
        cpp2::in<std::string_view> msg
    ) const -> void;

#line 121 "reflect.h2"
    public: auto error(cpp2::in<std::string_view> msg) const -> void;
    
    public: virtual ~compiler_services() noexcept;
public: compiler_services(compiler_services const& that);


#line 129 "reflect.h2"
};

#line 132 "reflect.h2"
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

#line 145 "reflect.h2"
    protected: declaration_node* n; 

    protected: declaration_base(

        declaration_node* n_, 
        cpp2::in<compiler_services> s
    );

#line 158 "reflect.h2"
    public: [[nodiscard]] auto position() const -> source_position override;

public: virtual ~declaration_base() noexcept;
public: declaration_base(declaration_base const& that);
#line 159 "reflect.h2"
};

#line 162 "reflect.h2"
//-----------------------------------------------------------------------
//  All declarations
//
class declaration
: public declaration_base {

#line 169 "reflect.h2"
    public: declaration(

        declaration_node* n_, 
        cpp2::in<compiler_services> s
    );

#line 178 "reflect.h2"
    public: [[nodiscard]] auto is_public() const -> bool;
    public: [[nodiscard]] auto is_protected() const -> bool;
    public: [[nodiscard]] auto is_private() const -> bool;
    public: [[nodiscard]] auto is_default_access() const -> bool;

    public: auto default_to_public() -> void;
    public: auto default_to_protected() -> void;
    public: auto default_to_private() -> void;

    public: [[nodiscard]] auto make_public() -> bool;
    public: [[nodiscard]] auto make_protected() -> bool;
    public: [[nodiscard]] auto make_private() -> bool;

    public: [[nodiscard]] auto has_name() const -> bool;
    public: [[nodiscard]] auto has_name(cpp2::in<std::string_view> s) const -> bool;

    public: [[nodiscard]] auto name() const -> std::string_view;
        

#line 199 "reflect.h2"
    public: [[nodiscard]] auto has_initializer() const -> bool;

    public: [[nodiscard]] auto is_global() const -> bool;
    public: [[nodiscard]] auto is_function() const -> bool;
    public: [[nodiscard]] auto is_object() const -> bool;
    public: [[nodiscard]] auto is_type() const -> bool;
    public: [[nodiscard]] auto is_namespace() const -> bool;
    public: [[nodiscard]] auto is_alias() const -> bool;

    public: [[nodiscard]] auto as_function() const -> function_declaration;
    public: [[nodiscard]] auto as_object() const -> object_declaration;
    public: [[nodiscard]] auto as_type() const -> type_declaration;
    public: [[nodiscard]] auto get_parent() const -> declaration;

    public: [[nodiscard]] auto parent_is_function() const -> bool;
    public: [[nodiscard]] auto parent_is_object() const -> bool;
    public: [[nodiscard]] auto parent_is_type() const -> bool;
    public: [[nodiscard]] auto parent_is_namespace() const -> bool;
    public: [[nodiscard]] auto parent_is_alias() const -> bool;
    public: [[nodiscard]] auto parent_is_polymorphic() const -> bool;

public: virtual ~declaration() noexcept;
public: declaration(declaration const& that);
#line 219 "reflect.h2"
};

#line 222 "reflect.h2"
//-----------------------------------------------------------------------
//  Function declarations
//
class function_declaration
: public declaration {

#line 229 "reflect.h2"
    public: function_declaration(

        declaration_node* n_, 
        cpp2::in<compiler_services> s
    );

#line 239 "reflect.h2"
    public: [[nodiscard]] auto index_of_parameter_named(cpp2::in<std::string_view> s) const -> int;
    public: [[nodiscard]] auto has_parameter_named(cpp2::in<std::string_view> s) const -> bool;
    public: [[nodiscard]] auto has_in_parameter_named(cpp2::in<std::string_view> s) const -> bool;
    public: [[nodiscard]] auto has_out_parameter_named(cpp2::in<std::string_view> s) const -> bool;
    public: [[nodiscard]] auto has_move_parameter_named(cpp2::in<std::string_view> s) const -> bool;

    public: [[nodiscard]] auto has_parameter_with_name_and_pass(cpp2::in<std::string_view> s, cpp2::in<passing_style> pass) const -> bool;
                                                  
    public: [[nodiscard]] auto is_function_with_this() const -> bool;
    public: [[nodiscard]] auto is_virtual() const -> bool;
    public: [[nodiscard]] auto is_defaultable() const -> bool;
    public: [[nodiscard]] auto is_constructor() const -> bool;
    public: [[nodiscard]] auto is_default_constructor() const -> bool;
    public: [[nodiscard]] auto is_move() const -> bool;
    public: [[nodiscard]] auto is_swap() const -> bool;
    public: [[nodiscard]] auto is_constructor_with_that() const -> bool;
    public: [[nodiscard]] auto is_constructor_with_in_that() const -> bool;
    public: [[nodiscard]] auto is_constructor_with_move_that() const -> bool;
    public: [[nodiscard]] auto is_assignment() const -> bool;
    public: [[nodiscard]] auto is_assignment_with_that() const -> bool;
    public: [[nodiscard]] auto is_assignment_with_in_that() const -> bool;
    public: [[nodiscard]] auto is_assignment_with_move_that() const -> bool;
    public: [[nodiscard]] auto is_destructor() const -> bool;

    public: [[nodiscard]] auto is_copy_or_move() const -> bool;

    public: [[nodiscard]] auto has_declared_return_type() const -> bool;
    public: [[nodiscard]] auto has_bool_return_type() const -> bool;
    public: [[nodiscard]] auto has_non_void_return_type() const -> bool;

    public: [[nodiscard]] auto unnamed_return_type() const -> std::string;

    public: [[nodiscard]] auto is_binary_comparison_function() const -> bool;

    public: auto default_to_virtual() -> void;

    public: [[nodiscard]] auto make_virtual() -> bool;

public: function_declaration(function_declaration const& that);
#line 276 "reflect.h2"
};

#line 279 "reflect.h2"
//-----------------------------------------------------------------------
//  Object declarations
//
class object_declaration
: public declaration {

#line 286 "reflect.h2"
    public: object_declaration(

        declaration_node* n_, 
        cpp2::in<compiler_services> s
    );

#line 296 "reflect.h2"
    public: [[nodiscard]] auto is_const() const -> bool;

    public: [[nodiscard]] auto has_wildcard_type() const -> bool;

public: object_declaration(object_declaration const& that);

    // TODO: auto get_type() const ->

#line 302 "reflect.h2"
};

#line 305 "reflect.h2"
//-----------------------------------------------------------------------
//  Type declarations
//
class type_declaration
: public declaration {

#line 312 "reflect.h2"
    public: type_declaration(

        declaration_node* n_, 
        cpp2::in<compiler_services> s
    );

#line 322 "reflect.h2"
    public: [[nodiscard]] auto is_polymorphic() const -> bool;
    public: [[nodiscard]] auto is_final() const -> bool;
    public: [[nodiscard]] auto make_final() -> bool;

    public: [[nodiscard]] auto get_member_functions() const -> 
        std::vector<function_declaration>; 

#line 336 "reflect.h2"
    public: [[nodiscard]] auto get_member_objects() const -> 
        std::vector<object_declaration>; 

#line 346 "reflect.h2"
    public: [[nodiscard]] auto get_member_types() const -> 
        std::vector<type_declaration>; 

#line 356 "reflect.h2"
    public: [[nodiscard]] auto get_members() const -> 
        std::vector<declaration>; struct query_declared_that_functions__ret { bool out_this_in_that; bool out_this_move_that; bool inout_this_in_that; bool inout_this_move_that; };



#line 366 "reflect.h2"
    public: [[nodiscard]] auto query_declared_that_functions() const -> query_declared_that_functions__ret;
        

#line 381 "reflect.h2"
    public: [[nodiscard]] auto add_member(cpp2::in<std::string_view> source) -> 
        bool; 
        public: type_declaration(type_declaration const& that);


#line 390 "reflect.h2"
};

#line 393 "reflect.h2"
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

#line 412 "reflect.h2"
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

#line 451 "reflect.h2"
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

#line 495 "reflect.h2"
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

#line 540 "reflect.h2"
//-----------------------------------------------------------------------
//  ordered - a totally ordered type
//
//  Note: the ordering that should be encouraged as default gets the nice name
//
auto ordered(meta::type_declaration& t) -> void;

#line 550 "reflect.h2"
//-----------------------------------------------------------------------
//  weakly_ordered - a weakly ordered type
//
auto weakly_ordered(meta::type_declaration& t) -> void;

#line 558 "reflect.h2"
//-----------------------------------------------------------------------
//  partially_ordered - a partially ordered type
//
auto partially_ordered(meta::type_declaration& t) -> void;

#line 567 "reflect.h2"
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

#line 605 "reflect.h2"
//-----------------------------------------------------------------------
//
//  basic_value
//
//  A regular type: copyable, plus has public default construction
//  and no protected or virtual functions
//
auto basic_value(meta::type_declaration& t) -> void;

#line 631 "reflect.h2"
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

#line 646 "reflect.h2"
auto weakly_ordered_value(meta::type_declaration& t) -> void;

#line 652 "reflect.h2"
auto partially_ordered_value(meta::type_declaration& t) -> void;

#line 659 "reflect.h2"
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

#line 702 "reflect.h2"
//=======================================================================
//  Switch to Cpp1 and close subnamespace meta
}
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


#line 20 "reflect.h2"
namespace cpp2 {

namespace meta {

#line 40 "reflect.h2"
    compiler_services::compiler_services(

        std::vector<error_entry>* errors_, 
        std::deque<token>* generated_tokens_
    )
        : errors{ errors_ }
        , errors_original_size{ cpp2::unsafe_narrow<int>(std::ssize(*cpp2::assert_not_null(errors))) }
        , generated_tokens{ generated_tokens_ }
        , parser{ *cpp2::assert_not_null(errors) }
#line 45 "reflect.h2"
    {

#line 50 "reflect.h2"
    }

    auto compiler_services::set_meta_function_name(cpp2::in<std::string_view> s) -> void{
        meta_function_name = s;
    }

    [[nodiscard]] auto compiler_services::parse_statement(

        std::string_view source
    ) -> 
        std::unique_ptr<statement_node>
    {
        CPP2_UFCS(push_back, generated_lines, std::vector<source_line>());
        auto lines {&CPP2_UFCS_0(back, generated_lines)}; 

        auto add_line {[&, _1 = lines](cpp2::in<std::string_view> s) -> void{
            (void) CPP2_UFCS(emplace_back, (*cpp2::assert_not_null(_1)), s, source_line::category::cpp2);
        }}; 
{
auto newline_pos = CPP2_UFCS(find, source, '\n');

        //  First split this string into source_lines
        //

#line 72 "reflect.h2"
        if ( cpp2::cmp_greater(CPP2_UFCS_0(ssize, source),1) 
            && newline_pos!=source.npos) 
        {
            while( newline_pos!=std::string_view::npos ) 
            {
                add_line(CPP2_UFCS(substr, source, 0, newline_pos));
                CPP2_UFCS(remove_prefix, source, newline_pos + 1);
                newline_pos = CPP2_UFCS(find, source, '\n');
            }
        }
}

#line 83 "reflect.h2"
        if (!(CPP2_UFCS_0(empty, source))) {
            std::move(add_line)(std::move(source));
        }

        //  Now lex this source fragment to generate
        //  a single grammar_map entry, whose .second
        //  is the vector of tokens
        (void) CPP2_UFCS(emplace_back, generated_lexers, *cpp2::assert_not_null(errors));
        auto tokens {&CPP2_UFCS_0(back, generated_lexers)}; 
        CPP2_UFCS(lex, (*cpp2::assert_not_null(tokens)), *cpp2::assert_not_null(std::move(lines)), true);

        cpp2::Default.expects(std::ssize(CPP2_UFCS_0(get_map, (*cpp2::assert_not_null(tokens))))==1, "");

        //  Now parse this single declaration from
        //  the lexed tokens
        return CPP2_UFCS(parse_one_declaration, parser, 
            (*cpp2::assert_not_null(CPP2_UFCS_0(begin, CPP2_UFCS_0(get_map, *cpp2::assert_not_null(std::move(tokens)))))).second, 
            *cpp2::assert_not_null(generated_tokens)
        ); 
    }

    [[nodiscard]] auto compiler_services::position() const -> 
        source_position
    {
        return {  }; 
    }

    auto compiler_services::require(

        cpp2::in<bool> b, 
        cpp2::in<std::string_view> msg
    ) const -> void
    {
        if (!(b)) {
            error(msg);
        }
    }

    auto compiler_services::error(cpp2::in<std::string_view> msg) const -> void
    {
        auto message {cpp2::as_<std::string>(msg)}; 
        if (!(CPP2_UFCS_0(empty, meta_function_name))) {
            message = "while applying @" + meta_function_name + " - " + message;
        }
        (void) CPP2_UFCS(emplace_back, (*cpp2::assert_not_null(errors)), position(), std::move(message));
    }

    compiler_services::~compiler_services() noexcept{}
compiler_services::compiler_services(compiler_services const& that)
                                : errors{ that.errors }
                                , errors_original_size{ that.errors_original_size }
                                , generated_tokens{ that.generated_tokens }
                                , parser{ that.parser }
                                , meta_function_name{ that.meta_function_name }{}

#line 147 "reflect.h2"
    declaration_base::declaration_base(

        declaration_node* n_, 
        cpp2::in<compiler_services> s
    )
        : compiler_services{ s }
        , n{ n_ }
#line 152 "reflect.h2"
    {

#line 155 "reflect.h2"
        cpp2::Default.expects(n, "a meta::declaration must point to a valid declaration_node, not null");
    }

    [[nodiscard]] auto declaration_base::position() const -> source_position { return CPP2_UFCS_0(position, (*cpp2::assert_not_null(n)));  }

    declaration_base::~declaration_base() noexcept{}
declaration_base::declaration_base(declaration_base const& that)
                                : compiler_services{ that }
                                , n{ that.n }{}

#line 169 "reflect.h2"
    declaration::declaration(

        declaration_node* n_, 
        cpp2::in<compiler_services> s
    )
        : declaration_base{ n_, s }
#line 174 "reflect.h2"
    {

    }

    [[nodiscard]] auto declaration::is_public() const -> bool { return CPP2_UFCS_0(is_public, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto declaration::is_protected() const -> bool { return CPP2_UFCS_0(is_protected, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto declaration::is_private() const -> bool { return CPP2_UFCS_0(is_private, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto declaration::is_default_access() const -> bool { return CPP2_UFCS_0(is_default_access, (*cpp2::assert_not_null(n)));  }

    auto declaration::default_to_public() -> void { (void) CPP2_UFCS_0(make_public, (*cpp2::assert_not_null(n))); }
    auto declaration::default_to_protected() -> void { (void) CPP2_UFCS_0(make_protected, (*cpp2::assert_not_null(n)));  }
    auto declaration::default_to_private() -> void { (void) CPP2_UFCS_0(make_private, (*cpp2::assert_not_null(n))); }

    [[nodiscard]] auto declaration::make_public() -> bool { return CPP2_UFCS_0(make_public, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto declaration::make_protected() -> bool { return CPP2_UFCS_0(make_protected, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto declaration::make_private() -> bool { return CPP2_UFCS_0(make_private, (*cpp2::assert_not_null(n))); }

    [[nodiscard]] auto declaration::has_name() const -> bool { return CPP2_UFCS_0(has_name, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto declaration::has_name(cpp2::in<std::string_view> s) const -> bool { return CPP2_UFCS(has_name, (*cpp2::assert_not_null(n)), s); }

    [[nodiscard]] auto declaration::name() const -> std::string_view{
        if (has_name()) {return CPP2_UFCS_0(as_string_view, (*cpp2::assert_not_null(CPP2_UFCS_0(name, *cpp2::assert_not_null(n))))); }
        else          { return ""; }
    }

    [[nodiscard]] auto declaration::has_initializer() const -> bool { return CPP2_UFCS_0(has_initializer, (*cpp2::assert_not_null(n)));  }

    [[nodiscard]] auto declaration::is_global() const -> bool { return CPP2_UFCS_0(is_global, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto declaration::is_function() const -> bool { return CPP2_UFCS_0(is_function, (*cpp2::assert_not_null(n)));  }
    [[nodiscard]] auto declaration::is_object() const -> bool { return CPP2_UFCS_0(is_object, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto declaration::is_type() const -> bool { return CPP2_UFCS_0(is_type, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto declaration::is_namespace() const -> bool { return CPP2_UFCS_0(is_namespace, (*cpp2::assert_not_null(n)));  }
    [[nodiscard]] auto declaration::is_alias() const -> bool { return CPP2_UFCS_0(is_alias, (*cpp2::assert_not_null(n))); }

    [[nodiscard]] auto declaration::as_function() const -> function_declaration { return function_declaration(n, (*this));  }
    [[nodiscard]] auto declaration::as_object() const -> object_declaration { return object_declaration(n, (*this)); }
    [[nodiscard]] auto declaration::as_type() const -> type_declaration { return type_declaration(n, (*this)); }
    [[nodiscard]] auto declaration::get_parent() const -> declaration { return declaration(n, (*this)); }

    [[nodiscard]] auto declaration::parent_is_function() const -> bool { return CPP2_UFCS_0(parent_is_function, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto declaration::parent_is_object() const -> bool { return CPP2_UFCS_0(parent_is_object, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto declaration::parent_is_type() const -> bool { return CPP2_UFCS_0(parent_is_type, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto declaration::parent_is_namespace() const -> bool { return CPP2_UFCS_0(parent_is_namespace, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto declaration::parent_is_alias() const -> bool { return CPP2_UFCS_0(parent_is_alias, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto declaration::parent_is_polymorphic() const -> bool { return CPP2_UFCS_0(parent_is_polymorphic, (*cpp2::assert_not_null(n)));  }

    declaration::~declaration() noexcept{}
declaration::declaration(declaration const& that)
                                : declaration_base{ that }{}

#line 229 "reflect.h2"
    function_declaration::function_declaration(

        declaration_node* n_, 
        cpp2::in<compiler_services> s
    )
        : declaration{ n_, s }
#line 234 "reflect.h2"
    {

        cpp2::Default.expects(CPP2_UFCS_0(is_function, (*cpp2::assert_not_null(n))), "");
    }

    [[nodiscard]] auto function_declaration::index_of_parameter_named(cpp2::in<std::string_view> s) const -> int { return CPP2_UFCS(index_of_parameter_named, (*cpp2::assert_not_null(n)), s); }
    [[nodiscard]] auto function_declaration::has_parameter_named(cpp2::in<std::string_view> s) const -> bool { return CPP2_UFCS(has_parameter_named, (*cpp2::assert_not_null(n)), s); }
    [[nodiscard]] auto function_declaration::has_in_parameter_named(cpp2::in<std::string_view> s) const -> bool { return CPP2_UFCS(has_in_parameter_named, (*cpp2::assert_not_null(n)), s); }
    [[nodiscard]] auto function_declaration::has_out_parameter_named(cpp2::in<std::string_view> s) const -> bool { return CPP2_UFCS(has_out_parameter_named, (*cpp2::assert_not_null(n)), s); }
    [[nodiscard]] auto function_declaration::has_move_parameter_named(cpp2::in<std::string_view> s) const -> bool { return CPP2_UFCS(has_move_parameter_named, (*cpp2::assert_not_null(n)), s); }

    [[nodiscard]] auto function_declaration::has_parameter_with_name_and_pass(cpp2::in<std::string_view> s, cpp2::in<passing_style> pass) const -> bool { 
                                                  return CPP2_UFCS(has_parameter_with_name_and_pass, (*cpp2::assert_not_null(n)), s, pass);  }
    [[nodiscard]] auto function_declaration::is_function_with_this() const -> bool { return CPP2_UFCS_0(is_function_with_this, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto function_declaration::is_virtual() const -> bool { return CPP2_UFCS_0(is_virtual_function, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto function_declaration::is_defaultable() const -> bool { return CPP2_UFCS_0(is_defaultable_function, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto function_declaration::is_constructor() const -> bool { return CPP2_UFCS_0(is_constructor, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto function_declaration::is_default_constructor() const -> bool { return CPP2_UFCS_0(is_default_constructor, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto function_declaration::is_move() const -> bool { return CPP2_UFCS_0(is_move, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto function_declaration::is_swap() const -> bool { return CPP2_UFCS_0(is_swap, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto function_declaration::is_constructor_with_that() const -> bool { return CPP2_UFCS_0(is_constructor_with_that, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto function_declaration::is_constructor_with_in_that() const -> bool { return CPP2_UFCS_0(is_constructor_with_in_that, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto function_declaration::is_constructor_with_move_that() const -> bool { return CPP2_UFCS_0(is_constructor_with_move_that, (*cpp2::assert_not_null(n)));  }
    [[nodiscard]] auto function_declaration::is_assignment() const -> bool { return CPP2_UFCS_0(is_assignment, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto function_declaration::is_assignment_with_that() const -> bool { return CPP2_UFCS_0(is_assignment_with_that, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto function_declaration::is_assignment_with_in_that() const -> bool { return CPP2_UFCS_0(is_assignment_with_in_that, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto function_declaration::is_assignment_with_move_that() const -> bool { return CPP2_UFCS_0(is_assignment_with_move_that, (*cpp2::assert_not_null(n)));  }
    [[nodiscard]] auto function_declaration::is_destructor() const -> bool { return CPP2_UFCS_0(is_destructor, (*cpp2::assert_not_null(n))); }

    [[nodiscard]] auto function_declaration::is_copy_or_move() const -> bool { return is_constructor_with_that() || is_assignment_with_that(); }

    [[nodiscard]] auto function_declaration::has_declared_return_type() const -> bool { return CPP2_UFCS_0(has_declared_return_type, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto function_declaration::has_bool_return_type() const -> bool { return CPP2_UFCS_0(has_bool_return_type, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto function_declaration::has_non_void_return_type() const -> bool { return CPP2_UFCS_0(has_non_void_return_type, (*cpp2::assert_not_null(n))); }

    [[nodiscard]] auto function_declaration::unnamed_return_type() const -> std::string { return CPP2_UFCS_0(unnamed_return_type_to_string, (*cpp2::assert_not_null(n))); }

    [[nodiscard]] auto function_declaration::is_binary_comparison_function() const -> bool { return CPP2_UFCS_0(is_binary_comparison_function, (*cpp2::assert_not_null(n)));  }

    auto function_declaration::default_to_virtual() -> void { (void) CPP2_UFCS_0(make_function_virtual, (*cpp2::assert_not_null(n))); }

    [[nodiscard]] auto function_declaration::make_virtual() -> bool { return CPP2_UFCS_0(make_function_virtual, (*cpp2::assert_not_null(n))); }

    function_declaration::function_declaration(function_declaration const& that)
                                : declaration{ that }{}

#line 286 "reflect.h2"
    object_declaration::object_declaration(

        declaration_node* n_, 
        cpp2::in<compiler_services> s
    )
        : declaration{ n_, s }
#line 291 "reflect.h2"
    {

        cpp2::Default.expects(CPP2_UFCS_0(is_object, (*cpp2::assert_not_null(n))), "");
    }

    [[nodiscard]] auto object_declaration::is_const() const -> bool { return CPP2_UFCS_0(is_const, (*cpp2::assert_not_null(n)));  }

    [[nodiscard]] auto object_declaration::has_wildcard_type() const -> bool { return CPP2_UFCS_0(has_wildcard_type, (*cpp2::assert_not_null(n)));  }

    object_declaration::object_declaration(object_declaration const& that)
                                : declaration{ that }{}

#line 312 "reflect.h2"
    type_declaration::type_declaration(

        declaration_node* n_, 
        cpp2::in<compiler_services> s
    )
        : declaration{ n_, s }
#line 317 "reflect.h2"
    {

        cpp2::Default.expects(CPP2_UFCS_0(is_type, (*cpp2::assert_not_null(n))), "");
    }

    [[nodiscard]] auto type_declaration::is_polymorphic() const -> bool { return CPP2_UFCS_0(is_polymorphic, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto type_declaration::is_final() const -> bool { return CPP2_UFCS_0(is_type_final, (*cpp2::assert_not_null(n))); }
    [[nodiscard]] auto type_declaration::make_final() -> bool { return CPP2_UFCS_0(make_type_final, (*cpp2::assert_not_null(n))); }

    [[nodiscard]] auto type_declaration::get_member_functions() const -> 
        std::vector<function_declaration>
    {
        std::vector<function_declaration> ret {}; 
        for ( auto const& d : CPP2_UFCS(get_type_scope_declarations, (*cpp2::assert_not_null(n)), declaration_node::functions) ) {
            (void) CPP2_UFCS(emplace_back, ret, d, (*this));
        }
        return ret; 
    }

    [[nodiscard]] auto type_declaration::get_member_objects() const -> 
        std::vector<object_declaration>
    {
        std::vector<object_declaration> ret {}; 
        for ( auto const& d : CPP2_UFCS(get_type_scope_declarations, (*cpp2::assert_not_null(n)), declaration_node::objects) ) {
            (void) CPP2_UFCS(emplace_back, ret, d, (*this));
        }
        return ret; 
    }

    [[nodiscard]] auto type_declaration::get_member_types() const -> 
        std::vector<type_declaration>
    {
        std::vector<type_declaration> ret {}; 
        for ( auto const& d : CPP2_UFCS(get_type_scope_declarations, (*cpp2::assert_not_null(n)), declaration_node::types) ) {
            (void) CPP2_UFCS(emplace_back, ret, d, (*this));
        }
        return ret; 
    }

    [[nodiscard]] auto type_declaration::get_members() const -> 
        std::vector<declaration>
    {
        std::vector<declaration> ret {}; 
        for ( auto const& d : CPP2_UFCS(get_type_scope_declarations, (*cpp2::assert_not_null(n)), declaration_node::all) ) {
            (void) CPP2_UFCS(emplace_back, ret, d, (*this));
        }
        return ret; 
    }

    [[nodiscard]] auto type_declaration::query_declared_that_functions() const -> query_declared_that_functions__ret

#line 373 "reflect.h2"
    {
            cpp2::deferred_init<bool> out_this_in_that;
            cpp2::deferred_init<bool> out_this_move_that;
            cpp2::deferred_init<bool> inout_this_in_that;
            cpp2::deferred_init<bool> inout_this_move_that;
#line 374 "reflect.h2"
        auto declared {CPP2_UFCS_0(find_declared_that_functions, (*cpp2::assert_not_null(n)))}; 
        out_this_in_that.construct(declared.out_this_in_that != nullptr);
        out_this_move_that.construct(declared.out_this_move_that!=nullptr);
        inout_this_in_that.construct(declared.inout_this_in_that!=nullptr);
        inout_this_move_that.construct(std::move(declared).inout_this_move_that!=nullptr);
    return  { std::move(out_this_in_that.value()), std::move(out_this_move_that.value()), std::move(inout_this_in_that.value()), std::move(inout_this_move_that.value()) }; }

    [[nodiscard]] auto type_declaration::add_member(cpp2::in<std::string_view> source) -> 
        bool
    {
        auto decl {parse_statement(source)}; 
        if (decl) {
            return CPP2_UFCS(add_type_member, (*cpp2::assert_not_null(n)), std::move(decl)); 
        }
        return false; 
    }

    type_declaration::type_declaration(type_declaration const& that)
                                : declaration{ that }{}

#line 405 "reflect.h2"
auto add_virtual_destructor(meta::type_declaration& t) -> void
{
    CPP2_UFCS(require, t, CPP2_UFCS(add_member, t, "operator=: (virtual move this) = { }"), 
               "could not add virtual destructor");
}

#line 424 "reflect.h2"
auto interface(meta::type_declaration& t) -> void
{
    auto has_dtor {false}; 

    for ( auto& m : CPP2_UFCS_0(get_members, t) ) 
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
            CPP2_UFCS_0(default_to_virtual, mf);
            has_dtor |= CPP2_UFCS_0(is_destructor, mf);
        }
    }

    if (!(std::move(has_dtor))) {
        add_virtual_destructor(t);
    }
}

#line 470 "reflect.h2"
auto polymorphic_base(meta::type_declaration& t) -> void
{
    auto has_dtor {false}; 

    for ( auto& mf : CPP2_UFCS_0(get_member_functions, t) ) 
    {
        if (CPP2_UFCS_0(is_default_access, mf)) {
            CPP2_UFCS_0(default_to_public, mf);
        }
        CPP2_UFCS(require, mf, !(CPP2_UFCS_0(is_copy_or_move, mf)), 
                    "polymorphic base types may not copy or move; consider a virtual clone() instead");
        if (CPP2_UFCS_0(is_destructor, mf)) {
            has_dtor = true;
            CPP2_UFCS(require, mf, (CPP2_UFCS_0(is_public, mf) && CPP2_UFCS_0(is_virtual, mf)) 
                        || (CPP2_UFCS_0(is_protected, mf) && !(CPP2_UFCS_0(is_virtual, mf))), 
                        "a polymorphic base type destructor must be public and virtual, or protected and nonvirtual");
        }
    }

    if (!(std::move(has_dtor))) {
        add_virtual_destructor(t);
    }
}

#line 515 "reflect.h2"
auto ordered_impl(
    meta::type_declaration& t, 
    cpp2::in<std::string_view> ordering
) -> void
{
    auto has_spaceship {false}; 

    for ( auto& mf : CPP2_UFCS_0(get_member_functions, t) ) 
    {
        if (CPP2_UFCS(has_name, mf, "operator<=>")) {
            has_spaceship = true;
            auto return_name {CPP2_UFCS_0(unnamed_return_type, mf)}; 
            if (CPP2_UFCS(find, return_name, ordering)==return_name.npos) 
            {
                CPP2_UFCS(error, mf, "operator<=> must return std::" + cpp2::as_<std::string>(ordering));
            }
        }
    }

    if (!(std::move(has_spaceship))) {
        CPP2_UFCS(require, t, CPP2_UFCS(add_member, t, "operator<=>: (this, that) -> std::" + (cpp2::as_<std::string>(ordering)) + ";"), 
                   "could not add operator<=> with std::" + (cpp2::as_<std::string>(ordering)));
    }
}

#line 545 "reflect.h2"
auto ordered(meta::type_declaration& t) -> void
{
    ordered_impl(t, "strong_ordering");
}

#line 553 "reflect.h2"
auto weakly_ordered(meta::type_declaration& t) -> void
{
    ordered_impl(t, "weak_ordering");
}

#line 561 "reflect.h2"
auto partially_ordered(meta::type_declaration& t) -> void
{
    ordered_impl(t, "partial_ordering");
}

#line 583 "reflect.h2"
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
        CPP2_UFCS(require, t, CPP2_UFCS(add_member, t, "operator=: (out this, that) = { this = that; }"), 
                   "could not add general operator=:(out this, that)");
    }}
}

#line 612 "reflect.h2"
auto basic_value(meta::type_declaration& t) -> void
{
    copyable(t);

    auto has_default_ctor {false}; 
    for ( auto& mf : CPP2_UFCS_0(get_member_functions, t) ) {
        has_default_ctor |= CPP2_UFCS_0(is_default_constructor, mf);
        CPP2_UFCS(require, mf, !(CPP2_UFCS_0(is_protected, mf)) && !(CPP2_UFCS_0(is_virtual, mf)), 
                    "a value type may not have a protected or virtual function");
        CPP2_UFCS(require, mf, !(CPP2_UFCS_0(is_destructor, mf)) || CPP2_UFCS_0(is_public, mf), 
                    "a value type may not have a non-public destructor");
    }

    if (!(std::move(has_default_ctor))) {
        CPP2_UFCS(require, t, CPP2_UFCS(add_member, t, "operator=: (out this) = { }"), 
                   "could not add default constructor");
    }
}

#line 640 "reflect.h2"
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

#line 684 "reflect.h2"
auto cpp2_struct(meta::type_declaration& t) -> void
{
    for ( auto& m : CPP2_UFCS_0(get_members, t) ) 
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
    }
    basic_value(t);  // a plain_struct is-a basic_value
}

#line 704 "reflect.h2"
}
}

#endif
