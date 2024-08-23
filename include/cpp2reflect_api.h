
#ifndef CPP2REFLECT_API_H_CPP2
#define CPP2REFLECT_API_H_CPP2


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "cpp2reflect_api.h2"

#line 47 "cpp2reflect_api.h2"
namespace cpp2 {

#line 51 "cpp2reflect_api.h2"
namespace meta {

class compiler_services;

#line 77 "cpp2reflect_api.h2"
class declaration;

#line 142 "cpp2reflect_api.h2"
class function_declaration;

#line 195 "cpp2reflect_api.h2"
class object_declaration;

#line 208 "cpp2reflect_api.h2"
class _query_declared_value_set_functions_ret;
    

#line 215 "cpp2reflect_api.h2"
class type_declaration;

#line 241 "cpp2reflect_api.h2"
class alias_declaration;

#line 262 "cpp2reflect_api.h2"
}

}


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "cpp2reflect_api.h2"

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
//  Cpp2 reflection (meta and generation) public interface declaration file:
//      This file contains only declarations (not definitions) usable by
//      authors of metafunctions. See documentation for more details.
//

namespace cpp2::meta {

//-----------------------------------------------------------------------
//
//  Metafunction registration support. Definitions are provided by the
//  implementation (cppfront).
//

using mf_sign_type_in = void(cpp2::impl::in<type_declaration>);
using mf_sign_type_inout = void(type_declaration&);
using mf_sign_func_in = void(cpp2::impl::in<function_declaration>);
using mf_sign_func_inout = void(function_declaration&);

struct register_metafunction {
    register_metafunction(const char* name, mf_sign_type_in* f);
    register_metafunction(const char* name, mf_sign_type_inout* f);
    register_metafunction(const char* name, mf_sign_func_in* f);
    register_metafunction(const char* name, mf_sign_func_inout* f);
};

} // cpp2::meta

#line 47 "cpp2reflect_api.h2"
namespace cpp2 {

#line 51 "cpp2reflect_api.h2"
namespace meta {

class compiler_services
 {

#line 57 "cpp2reflect_api.h2"
    public: [[nodiscard]] auto get_metafunction_name() const& -> std::string_view;

    public: [[nodiscard]] auto get_argument(cpp2::impl::in<int> index) & -> std::string;
    public: [[nodiscard]] auto get_arguments() & -> std::vector<std::string>;

    public: auto add_runtime_support_include(cpp2::impl::in<std::string_view> s) & -> void;

    public: auto append_declaration_to_translation_unit(cpp2::impl::in<std::string_view> source) & -> void;

#line 69 "cpp2reflect_api.h2"
    public: auto require(cpp2::impl::in<bool> b, cpp2::impl::in<std::string_view> msg) const& -> void;
    public: auto error(cpp2::impl::in<std::string_view> msg) const& -> void;

#line 74 "cpp2reflect_api.h2"
    public: auto report_violation(cpp2::impl::in<std::string_view> msg) const& -> void;
    public: class interface {
    public: [[nodiscard]] virtual auto get_metafunction_name() const -> std::string_view = 0;

    public: [[nodiscard]] virtual auto get_argument(
    cpp2::impl::in<int> index
    )
     -> std::string = 0;

    public: [[nodiscard]] virtual auto get_arguments() -> std::vector<std::string> = 0;

    public: virtual auto add_runtime_support_include(
    cpp2::impl::in<std::string_view> s
    )
     -> void = 0;

    public: virtual auto append_declaration_to_translation_unit(
    cpp2::impl::in<std::string_view> source
    )
     -> void = 0;

    public: virtual auto require(
    cpp2::impl::in<bool> b, 
    cpp2::impl::in<std::string_view> msg
    )
     const -> void = 0;

    public: virtual auto error(
    cpp2::impl::in<std::string_view> msg
    )
     const -> void = 0;

    public: virtual auto report_violation(
    cpp2::impl::in<std::string_view> msg
    )
     const -> void = 0;

    public: virtual ~interface() noexcept;

        public: interface() = default;
        public: interface(interface const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(interface const&) -> void = delete;

    };

    private: std::unique_ptr<interface> _pimpl; public: explicit compiler_services(std::unique_ptr<interface> pimpl);

public: auto operator=(std::unique_ptr<interface> pimpl) -> compiler_services& ;
public: compiler_services(compiler_services&& that) noexcept;
public: auto operator=(compiler_services&& that) noexcept -> compiler_services& ;
public: ~compiler_services() noexcept;

#line 75 "cpp2reflect_api.h2"
};

class declaration
: public compiler_services {

#line 81 "cpp2reflect_api.h2"
    public: [[nodiscard]] auto print() const& -> std::string;

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
    public: [[nodiscard]] auto fully_qualified_name() const& -> std::string;

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
    public: class interface {
    public: [[nodiscard]] virtual auto print() const -> std::string = 0;

    public: [[nodiscard]] virtual auto is_public() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_protected() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_private() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_default_access() const -> bool = 0;

    public: virtual auto default_to_public() -> void = 0;

    public: virtual auto default_to_protected() -> void = 0;

    public: virtual auto default_to_private() -> void = 0;

    public: [[nodiscard]] virtual auto make_public() -> bool = 0;

    public: [[nodiscard]] virtual auto make_protected() -> bool = 0;

    public: [[nodiscard]] virtual auto make_private() -> bool = 0;

    public: [[nodiscard]] virtual auto has_name() const -> bool = 0;

    public: [[nodiscard]] virtual auto has_name(
    cpp2::impl::in<std::string_view> s
    )
     const -> bool = 0;

    public: [[nodiscard]] virtual auto name() const -> std::string_view = 0;

    public: [[nodiscard]] virtual auto fully_qualified_name() const -> std::string = 0;

    public: [[nodiscard]] virtual auto has_initializer() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_global() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_function() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_object() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_base_object() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_member_object() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_type() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_namespace() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_alias() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_type_alias() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_namespace_alias() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_object_alias() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_function_expression() const -> bool = 0;

    public: [[nodiscard]] virtual auto as_function() const -> function_declaration = 0;

    public: [[nodiscard]] virtual auto as_object() const -> object_declaration = 0;

    public: [[nodiscard]] virtual auto as_type() const -> type_declaration = 0;

    public: [[nodiscard]] virtual auto as_alias() const -> alias_declaration = 0;

    public: [[nodiscard]] virtual auto get_parent() const -> declaration = 0;

    public: [[nodiscard]] virtual auto parent_is_function() const -> bool = 0;

    public: [[nodiscard]] virtual auto parent_is_object() const -> bool = 0;

    public: [[nodiscard]] virtual auto parent_is_type() const -> bool = 0;

    public: [[nodiscard]] virtual auto parent_is_namespace() const -> bool = 0;

    public: [[nodiscard]] virtual auto parent_is_alias() const -> bool = 0;

    public: [[nodiscard]] virtual auto parent_is_type_alias() const -> bool = 0;

    public: [[nodiscard]] virtual auto parent_is_namespace_alias() const -> bool = 0;

    public: [[nodiscard]] virtual auto parent_is_object_alias() const -> bool = 0;

    public: [[nodiscard]] virtual auto parent_is_polymorphic() const -> bool = 0;

    public: virtual auto mark_for_removal_from_enclosing_type() -> void = 0;

    public: virtual ~interface() noexcept;

        public: interface() = default;
        public: interface(interface const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(interface const&) -> void = delete;

    };

    private: std::unique_ptr<interface> _pimpl; public: explicit declaration(std::unique_ptr<interface> pimpl, auto&& ...parent_pimpls);
public: declaration(declaration&& that) noexcept;
public: ~declaration() noexcept;

#line 139 "cpp2reflect_api.h2"
};

#line 142 "cpp2reflect_api.h2"
class function_declaration
: public declaration {

#line 146 "cpp2reflect_api.h2"
    public: [[nodiscard]] auto index_of_parameter_named(cpp2::impl::in<std::string_view> s) const& -> int;
    public: [[nodiscard]] auto has_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool;
    public: [[nodiscard]] auto has_in_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool;
    public: [[nodiscard]] auto has_copy_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool;
    public: [[nodiscard]] auto has_inout_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool;
    public: [[nodiscard]] auto has_out_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool;
    public: [[nodiscard]] auto has_move_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool;
    public: [[nodiscard]] auto has_forward_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool;
    public: [[nodiscard]] auto first_parameter_name() const& -> std::string;

#line 158 "cpp2reflect_api.h2"
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

    public: [[nodiscard]] auto is_binary_comparison_function() const& -> bool;

    public: auto default_to_virtual() & -> void;

    public: [[nodiscard]] auto make_virtual() & -> bool;

    public: auto add_initializer(cpp2::impl::in<std::string_view> source) & -> void;
    public: class interface {
    public: [[nodiscard]] virtual auto index_of_parameter_named(
    cpp2::impl::in<std::string_view> s
    )
     const -> int = 0;

    public: [[nodiscard]] virtual auto has_parameter_named(
    cpp2::impl::in<std::string_view> s
    )
     const -> bool = 0;

    public: [[nodiscard]] virtual auto has_in_parameter_named(
    cpp2::impl::in<std::string_view> s
    )
     const -> bool = 0;

    public: [[nodiscard]] virtual auto has_copy_parameter_named(
    cpp2::impl::in<std::string_view> s
    )
     const -> bool = 0;

    public: [[nodiscard]] virtual auto has_inout_parameter_named(
    cpp2::impl::in<std::string_view> s
    )
     const -> bool = 0;

    public: [[nodiscard]] virtual auto has_out_parameter_named(
    cpp2::impl::in<std::string_view> s
    )
     const -> bool = 0;

    public: [[nodiscard]] virtual auto has_move_parameter_named(
    cpp2::impl::in<std::string_view> s
    )
     const -> bool = 0;

    public: [[nodiscard]] virtual auto has_forward_parameter_named(
    cpp2::impl::in<std::string_view> s
    )
     const -> bool = 0;

    public: [[nodiscard]] virtual auto first_parameter_name() const -> std::string = 0;

    public: [[nodiscard]] virtual auto is_function_with_this() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_virtual() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_defaultable() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_constructor() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_default_constructor() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_move() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_swap() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_constructor_with_that() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_constructor_with_in_that() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_constructor_with_move_that() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_assignment() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_assignment_with_that() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_assignment_with_in_that() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_assignment_with_move_that() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_destructor() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_copy_or_move() const -> bool = 0;

    public: [[nodiscard]] virtual auto has_declared_return_type() const -> bool = 0;

    public: [[nodiscard]] virtual auto has_deduced_return_type() const -> bool = 0;

    public: [[nodiscard]] virtual auto has_bool_return_type() const -> bool = 0;

    public: [[nodiscard]] virtual auto has_non_void_return_type() const -> bool = 0;

    public: [[nodiscard]] virtual auto unnamed_return_type() const -> std::string = 0;

    public: [[nodiscard]] virtual auto get_parameters() const -> std::vector<object_declaration> = 0;

    public: [[nodiscard]] virtual auto is_binary_comparison_function() const -> bool = 0;

    public: virtual auto default_to_virtual() -> void = 0;

    public: [[nodiscard]] virtual auto make_virtual() -> bool = 0;

    public: virtual auto add_initializer(
    cpp2::impl::in<std::string_view> source
    )
     -> void = 0;

    public: virtual ~interface() noexcept;

        public: interface() = default;
        public: interface(interface const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(interface const&) -> void = delete;

    };

    private: std::unique_ptr<interface> _pimpl; public: explicit function_declaration(std::unique_ptr<interface> pimpl, auto&& ...parent_pimpls);
public: function_declaration(function_declaration&& that) noexcept;
public: ~function_declaration() noexcept;

#line 192 "cpp2reflect_api.h2"
};

#line 195 "cpp2reflect_api.h2"
class object_declaration
: public declaration {

#line 199 "cpp2reflect_api.h2"
    public: [[nodiscard]] auto is_const() const& -> bool;
    public: [[nodiscard]] auto has_wildcard_type() const& -> bool;

    public: [[nodiscard]] auto type() const& -> std::string;

    public: [[nodiscard]] auto initializer() const& -> std::string;
    public: class interface {
    public: [[nodiscard]] virtual auto is_const() const -> bool = 0;

    public: [[nodiscard]] virtual auto has_wildcard_type() const -> bool = 0;

    public: [[nodiscard]] virtual auto type() const -> std::string = 0;

    public: [[nodiscard]] virtual auto initializer() const -> std::string = 0;

    public: virtual ~interface() noexcept;

        public: interface() = default;
        public: interface(interface const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(interface const&) -> void = delete;

    };

    private: std::unique_ptr<interface> _pimpl; public: explicit object_declaration(std::unique_ptr<interface> pimpl, auto&& ...parent_pimpls);
public: object_declaration(object_declaration&& that) noexcept;
public: ~object_declaration() noexcept;

#line 205 "cpp2reflect_api.h2"
};

#line 208 "cpp2reflect_api.h2"
class _query_declared_value_set_functions_ret {
    public: bool out_this_in_that {false}; 
    public: bool out_this_move_that {false}; 
    public: bool inout_this_in_that {false}; 
    public: bool inout_this_move_that {false}; 
    public: [[nodiscard]] auto operator<=>(_query_declared_value_set_functions_ret const& that) const& -> std::strong_ordering = default;
public: _query_declared_value_set_functions_ret(_query_declared_value_set_functions_ret const& that);

public: auto operator=(_query_declared_value_set_functions_ret const& that) -> _query_declared_value_set_functions_ret& ;
public: _query_declared_value_set_functions_ret(_query_declared_value_set_functions_ret&& that) noexcept;
public: auto operator=(_query_declared_value_set_functions_ret&& that) noexcept -> _query_declared_value_set_functions_ret& ;
public: explicit _query_declared_value_set_functions_ret();

#line 213 "cpp2reflect_api.h2"
};

class type_declaration
: public declaration {

#line 219 "cpp2reflect_api.h2"
    public: [[nodiscard]] auto is_polymorphic() const& -> bool;
    public: [[nodiscard]] auto is_final() const& -> bool;
    public: [[nodiscard]] auto make_final() & -> bool;

    public: [[nodiscard]] auto get_member_functions() const& -> std::vector<function_declaration>;
    public: [[nodiscard]] auto get_member_functions_needing_initializer() const& -> std::vector<function_declaration>;
    public: [[nodiscard]] auto get_member_objects() const& -> std::vector<object_declaration>;
    public: [[nodiscard]] auto get_member_types() const& -> std::vector<type_declaration>;
    public: [[nodiscard]] auto get_member_aliases() const& -> std::vector<alias_declaration>;
    public: [[nodiscard]] auto get_members    () const& -> std::vector<declaration>;

    public: [[nodiscard]] auto query_declared_value_set_functions() const& -> _query_declared_value_set_functions_ret;

    public: auto add_member(cpp2::impl::in<std::string_view> source) & -> void;

    public: auto remove_marked_members() & -> void;
    public: auto remove_all_members() & -> void;

    public: auto disable_member_function_generation() & -> void;
    public: class interface {
    public: [[nodiscard]] virtual auto is_polymorphic() const -> bool = 0;

    public: [[nodiscard]] virtual auto is_final() const -> bool = 0;

    public: [[nodiscard]] virtual auto make_final() -> bool = 0;

    public: [[nodiscard]] virtual auto get_member_functions() const -> std::vector<function_declaration> = 0;

    public: [[nodiscard]] virtual auto get_member_functions_needing_initializer() const -> std::vector<function_declaration> = 0;

    public: [[nodiscard]] virtual auto get_member_objects() const -> std::vector<object_declaration> = 0;

    public: [[nodiscard]] virtual auto get_member_types() const -> std::vector<type_declaration> = 0;

    public: [[nodiscard]] virtual auto get_member_aliases() const -> std::vector<alias_declaration> = 0;

    public: [[nodiscard]] virtual auto get_members() const -> std::vector<declaration> = 0;

    public: [[nodiscard]] virtual auto query_declared_value_set_functions() const -> _query_declared_value_set_functions_ret = 0;

    public: virtual auto add_member(
    cpp2::impl::in<std::string_view> source
    )
     -> void = 0;

    public: virtual auto remove_marked_members() -> void = 0;

    public: virtual auto remove_all_members() -> void = 0;

    public: virtual auto disable_member_function_generation() -> void = 0;

    public: virtual ~interface() noexcept;

        public: interface() = default;
        public: interface(interface const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(interface const&) -> void = delete;

    };

    private: std::unique_ptr<interface> _pimpl; public: explicit type_declaration(std::unique_ptr<interface> pimpl, auto&& ...parent_pimpls);
public: type_declaration(type_declaration&& that) noexcept;
public: ~type_declaration() noexcept;

#line 238 "cpp2reflect_api.h2"
};

#line 241 "cpp2reflect_api.h2"
class alias_declaration
: public declaration {
public: class interface {public: virtual ~interface() noexcept;

        public: interface() = default;
        public: interface(interface const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(interface const&) -> void = delete;

};

private: std::unique_ptr<interface> _pimpl; public: explicit alias_declaration(std::unique_ptr<interface> pimpl, auto&& ...parent_pimpls);
public: alias_declaration(alias_declaration&& that) noexcept;
public: ~alias_declaration() noexcept;


#line 244 "cpp2reflect_api.h2"
};

#line 247 "cpp2reflect_api.h2"
auto reserve_names(type_declaration& t, cpp2::impl::in<std::string_view> name, auto&& ...etc) -> void;

#line 262 "cpp2reflect_api.h2"
} // meta

} // cpp2


//=== Cpp2 function definitions =================================================

#line 1 "cpp2reflect_api.h2"

#line 41 "cpp2reflect_api.h2"
//-----------------------------------------------------------------------
//
//  Metafunction objects. Expanded to complete definitions that use a
//  interface, which is provided by the implementation (cppfront).
//

#line 47 "cpp2reflect_api.h2"
namespace cpp2 {

// TODO(DyXel): put passing_style here, maybe?

namespace meta {

#line 55 "cpp2reflect_api.h2"
    //  Common API
    //
#line 57 "cpp2reflect_api.h2"
    [[nodiscard]] auto compiler_services::get_metafunction_name() const& -> std::string_view { 
    return CPP2_UFCS(get_metafunction_name)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 59 "cpp2reflect_api.h2"
    [[nodiscard]] auto compiler_services::get_argument(cpp2::impl::in<int> index) & -> std::string { 
    return CPP2_UFCS(get_argument)((*cpp2::impl::assert_not_null(_pimpl)), index); }
#line 60 "cpp2reflect_api.h2"
    [[nodiscard]] auto compiler_services::get_arguments() & -> std::vector<std::string> { 
    return CPP2_UFCS(get_arguments)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 62 "cpp2reflect_api.h2"
    auto compiler_services::add_runtime_support_include(cpp2::impl::in<std::string_view> s) & -> void { 
    CPP2_UFCS(add_runtime_support_include)((*cpp2::impl::assert_not_null(_pimpl)), s); }

#line 64 "cpp2reflect_api.h2"
    auto compiler_services::append_declaration_to_translation_unit(cpp2::impl::in<std::string_view> source) & -> void { 
    CPP2_UFCS(append_declaration_to_translation_unit)((*cpp2::impl::assert_not_null(_pimpl)), source); }

    //  Error diagnosis and handling, integrated with compiler output
    //  Unlike a contract violation, .require continues further processing
    //
#line 69 "cpp2reflect_api.h2"
    auto compiler_services::require(cpp2::impl::in<bool> b, cpp2::impl::in<std::string_view> msg) const& -> void { 
    CPP2_UFCS(require)((*cpp2::impl::assert_not_null(_pimpl)), b, msg); }
#line 70 "cpp2reflect_api.h2"
    auto compiler_services::error(cpp2::impl::in<std::string_view> msg) const& -> void { 
    CPP2_UFCS(error)((*cpp2::impl::assert_not_null(_pimpl)), msg); }
    //  Enable custom contracts on this object, integrated with compiler output
    //  Unlike .require, a contract violation stops further processing
    //
#line 74 "cpp2reflect_api.h2"
    auto compiler_services::report_violation(cpp2::impl::in<std::string_view> msg) const& -> void { 
    CPP2_UFCS(report_violation)((*cpp2::impl::assert_not_null(_pimpl)), msg); }









compiler_services::interface::~interface() noexcept{}

compiler_services::compiler_services(std::unique_ptr<interface> pimpl)
                                                                : _pimpl{ std::move(cpp2::move(pimpl)) } {  }

auto compiler_services::operator=(std::unique_ptr<interface> pimpl) -> compiler_services&  { 
                                                                _pimpl = std::move(cpp2::move(pimpl));
                                                                return *this; }
compiler_services::compiler_services(compiler_services&& that) noexcept
                                     : _pimpl{ std::move(cpp2::move(that)._pimpl) }{}
auto compiler_services::operator=(compiler_services&& that) noexcept -> compiler_services& {
                                     _pimpl = std::move(cpp2::move(that)._pimpl);
                                     return *this;}
compiler_services::~compiler_services() noexcept{}
#line 81 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::print() const& -> std::string { 
    return CPP2_UFCS(print)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 83 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::is_public() const& -> bool { 
    return CPP2_UFCS(is_public)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 84 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::is_protected() const& -> bool { 
    return CPP2_UFCS(is_protected)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 85 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::is_private() const& -> bool { 
    return CPP2_UFCS(is_private)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 86 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::is_default_access() const& -> bool { 
    return CPP2_UFCS(is_default_access)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 88 "cpp2reflect_api.h2"
    auto declaration::default_to_public() & -> void { 
    CPP2_UFCS(default_to_public)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 89 "cpp2reflect_api.h2"
    auto declaration::default_to_protected() & -> void { 
    CPP2_UFCS(default_to_protected)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 90 "cpp2reflect_api.h2"
    auto declaration::default_to_private() & -> void { 
    CPP2_UFCS(default_to_private)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 92 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::make_public() & -> bool { 
    return CPP2_UFCS(make_public)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 93 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::make_protected() & -> bool { 
    return CPP2_UFCS(make_protected)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 94 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::make_private() & -> bool { 
    return CPP2_UFCS(make_private)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 96 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::has_name() const& -> bool { 
    return CPP2_UFCS(has_name)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 97 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::has_name(cpp2::impl::in<std::string_view> s) const& -> bool { 
    return CPP2_UFCS(has_name)((*cpp2::impl::assert_not_null(_pimpl)), s); }

#line 99 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::name() const& -> std::string_view { 
    return CPP2_UFCS(name)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 100 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::fully_qualified_name() const& -> std::string { 
    return CPP2_UFCS(fully_qualified_name)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 102 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::has_initializer() const& -> bool { 
    return CPP2_UFCS(has_initializer)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 104 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::is_global() const& -> bool { 
    return CPP2_UFCS(is_global)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 105 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::is_function() const& -> bool { 
    return CPP2_UFCS(is_function)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 106 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::is_object() const& -> bool { 
    return CPP2_UFCS(is_object)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 107 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::is_base_object() const& -> bool { 
    return CPP2_UFCS(is_base_object)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 108 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::is_member_object() const& -> bool { 
    return CPP2_UFCS(is_member_object)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 109 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::is_type() const& -> bool { 
    return CPP2_UFCS(is_type)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 110 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::is_namespace() const& -> bool { 
    return CPP2_UFCS(is_namespace)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 111 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::is_alias() const& -> bool { 
    return CPP2_UFCS(is_alias)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 113 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::is_type_alias() const& -> bool { 
    return CPP2_UFCS(is_type_alias)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 114 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::is_namespace_alias() const& -> bool { 
    return CPP2_UFCS(is_namespace_alias)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 115 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::is_object_alias() const& -> bool { 
    return CPP2_UFCS(is_object_alias)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 117 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::is_function_expression() const& -> bool { 
    return CPP2_UFCS(is_function_expression)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 119 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::as_function() const& -> function_declaration { 
    return CPP2_UFCS(as_function)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 120 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::as_object() const& -> object_declaration { 
    return CPP2_UFCS(as_object)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 121 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::as_type() const& -> type_declaration { 
    return CPP2_UFCS(as_type)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 122 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::as_alias() const& -> alias_declaration { 
    return CPP2_UFCS(as_alias)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 124 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::get_parent() const& -> declaration { 
    return CPP2_UFCS(get_parent)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 126 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::parent_is_function() const& -> bool { 
    return CPP2_UFCS(parent_is_function)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 127 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::parent_is_object() const& -> bool { 
    return CPP2_UFCS(parent_is_object)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 128 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::parent_is_type() const& -> bool { 
    return CPP2_UFCS(parent_is_type)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 129 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::parent_is_namespace() const& -> bool { 
    return CPP2_UFCS(parent_is_namespace)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 130 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::parent_is_alias() const& -> bool { 
    return CPP2_UFCS(parent_is_alias)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 132 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::parent_is_type_alias() const& -> bool { 
    return CPP2_UFCS(parent_is_type_alias)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 133 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::parent_is_namespace_alias() const& -> bool { 
    return CPP2_UFCS(parent_is_namespace_alias)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 134 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::parent_is_object_alias() const& -> bool { 
    return CPP2_UFCS(parent_is_object_alias)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 136 "cpp2reflect_api.h2"
    [[nodiscard]] auto declaration::parent_is_polymorphic() const& -> bool { 
    return CPP2_UFCS(parent_is_polymorphic)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 138 "cpp2reflect_api.h2"
    auto declaration::mark_for_removal_from_enclosing_type() & -> void { 
    CPP2_UFCS(mark_for_removal_from_enclosing_type)((*cpp2::impl::assert_not_null(_pimpl))); }












































declaration::interface::~interface() noexcept{}

declaration::declaration(std::unique_ptr<interface> pimpl, auto&& ...parent_pimpls)
                                                                                            : compiler_services{ CPP2_FORWARD(parent_pimpls)... }
                                                                                            , _pimpl{ cpp2::move(pimpl) }{}
declaration::declaration(declaration&& that) noexcept
                                     : compiler_services{ static_cast<compiler_services&&>(that) }
                                     , _pimpl{ std::move(cpp2::move(that)._pimpl) }{}
declaration::~declaration() noexcept{}

#line 146 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::index_of_parameter_named(cpp2::impl::in<std::string_view> s) const& -> int { 
    return CPP2_UFCS(index_of_parameter_named)((*cpp2::impl::assert_not_null(_pimpl)), s); }
#line 147 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::has_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool { 
    return CPP2_UFCS(has_parameter_named)((*cpp2::impl::assert_not_null(_pimpl)), s); }
#line 148 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::has_in_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool { 
    return CPP2_UFCS(has_in_parameter_named)((*cpp2::impl::assert_not_null(_pimpl)), s); }
#line 149 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::has_copy_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool { 
    return CPP2_UFCS(has_copy_parameter_named)((*cpp2::impl::assert_not_null(_pimpl)), s); }
#line 150 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::has_inout_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool { 
    return CPP2_UFCS(has_inout_parameter_named)((*cpp2::impl::assert_not_null(_pimpl)), s); }
#line 151 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::has_out_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool { 
    return CPP2_UFCS(has_out_parameter_named)((*cpp2::impl::assert_not_null(_pimpl)), s); }
#line 152 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::has_move_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool { 
    return CPP2_UFCS(has_move_parameter_named)((*cpp2::impl::assert_not_null(_pimpl)), s); }
#line 153 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::has_forward_parameter_named(cpp2::impl::in<std::string_view> s) const& -> bool { 
    return CPP2_UFCS(has_forward_parameter_named)((*cpp2::impl::assert_not_null(_pimpl)), s); }
#line 154 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::first_parameter_name() const& -> std::string { 
    return CPP2_UFCS(first_parameter_name)((*cpp2::impl::assert_not_null(_pimpl))); }

    // has_parameter_with_name_and_pass: (this, s: std::string_view, pass: passing_style) -> bool; // TODO

#line 158 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::is_function_with_this() const& -> bool { 
    return CPP2_UFCS(is_function_with_this)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 159 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::is_virtual() const& -> bool { 
    return CPP2_UFCS(is_virtual)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 160 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::is_defaultable() const& -> bool { 
    return CPP2_UFCS(is_defaultable)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 161 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::is_constructor() const& -> bool { 
    return CPP2_UFCS(is_constructor)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 162 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::is_default_constructor() const& -> bool { 
    return CPP2_UFCS(is_default_constructor)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 163 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::is_move() const& -> bool { 
    return CPP2_UFCS(is_move)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 164 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::is_swap() const& -> bool { 
    return CPP2_UFCS(is_swap)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 165 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::is_constructor_with_that() const& -> bool { 
    return CPP2_UFCS(is_constructor_with_that)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 166 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::is_constructor_with_in_that() const& -> bool { 
    return CPP2_UFCS(is_constructor_with_in_that)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 167 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::is_constructor_with_move_that() const& -> bool { 
    return CPP2_UFCS(is_constructor_with_move_that)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 168 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::is_assignment() const& -> bool { 
    return CPP2_UFCS(is_assignment)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 169 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::is_assignment_with_that() const& -> bool { 
    return CPP2_UFCS(is_assignment_with_that)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 170 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::is_assignment_with_in_that() const& -> bool { 
    return CPP2_UFCS(is_assignment_with_in_that)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 171 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::is_assignment_with_move_that() const& -> bool { 
    return CPP2_UFCS(is_assignment_with_move_that)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 172 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::is_destructor() const& -> bool { 
    return CPP2_UFCS(is_destructor)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 174 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::is_copy_or_move() const& -> bool { 
    return CPP2_UFCS(is_copy_or_move)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 176 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::has_declared_return_type() const& -> bool { 
    return CPP2_UFCS(has_declared_return_type)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 177 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::has_deduced_return_type() const& -> bool { 
    return CPP2_UFCS(has_deduced_return_type)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 178 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::has_bool_return_type() const& -> bool { 
    return CPP2_UFCS(has_bool_return_type)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 179 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::has_non_void_return_type() const& -> bool { 
    return CPP2_UFCS(has_non_void_return_type)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 181 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::unnamed_return_type() const& -> std::string { 
    return CPP2_UFCS(unnamed_return_type)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 183 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::get_parameters() const& -> std::vector<object_declaration> { 
    return CPP2_UFCS(get_parameters)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 185 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::is_binary_comparison_function() const& -> bool { 
    return CPP2_UFCS(is_binary_comparison_function)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 187 "cpp2reflect_api.h2"
    auto function_declaration::default_to_virtual() & -> void { 
    CPP2_UFCS(default_to_virtual)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 189 "cpp2reflect_api.h2"
    [[nodiscard]] auto function_declaration::make_virtual() & -> bool { 
    return CPP2_UFCS(make_virtual)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 191 "cpp2reflect_api.h2"
    auto function_declaration::add_initializer(cpp2::impl::in<std::string_view> source) & -> void { 
    CPP2_UFCS(add_initializer)((*cpp2::impl::assert_not_null(_pimpl)), source); }




































function_declaration::interface::~interface() noexcept{}

function_declaration::function_declaration(std::unique_ptr<interface> pimpl, auto&& ...parent_pimpls)
                                                                                            : declaration{ CPP2_FORWARD(parent_pimpls)... }
                                                                                            , _pimpl{ cpp2::move(pimpl) }{}
function_declaration::function_declaration(function_declaration&& that) noexcept
                                     : declaration{ static_cast<declaration&&>(that) }
                                     , _pimpl{ std::move(cpp2::move(that)._pimpl) }{}
function_declaration::~function_declaration() noexcept{}

#line 199 "cpp2reflect_api.h2"
    [[nodiscard]] auto object_declaration::is_const() const& -> bool { 
    return CPP2_UFCS(is_const)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 200 "cpp2reflect_api.h2"
    [[nodiscard]] auto object_declaration::has_wildcard_type() const& -> bool { 
    return CPP2_UFCS(has_wildcard_type)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 202 "cpp2reflect_api.h2"
    [[nodiscard]] auto object_declaration::type() const& -> std::string { 
    return CPP2_UFCS(type)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 204 "cpp2reflect_api.h2"
    [[nodiscard]] auto object_declaration::initializer() const& -> std::string { 
    return CPP2_UFCS(initializer)((*cpp2::impl::assert_not_null(_pimpl))); }





object_declaration::interface::~interface() noexcept{}

object_declaration::object_declaration(std::unique_ptr<interface> pimpl, auto&& ...parent_pimpls)
                                                                                            : declaration{ CPP2_FORWARD(parent_pimpls)... }
                                                                                            , _pimpl{ cpp2::move(pimpl) }{}
object_declaration::object_declaration(object_declaration&& that) noexcept
                                     : declaration{ static_cast<declaration&&>(that) }
                                     , _pimpl{ std::move(cpp2::move(that)._pimpl) }{}
object_declaration::~object_declaration() noexcept{}

_query_declared_value_set_functions_ret::_query_declared_value_set_functions_ret(_query_declared_value_set_functions_ret const& that)
                                : out_this_in_that{ that.out_this_in_that }
                                , out_this_move_that{ that.out_this_move_that }
                                , inout_this_in_that{ that.inout_this_in_that }
                                , inout_this_move_that{ that.inout_this_move_that }{}

auto _query_declared_value_set_functions_ret::operator=(_query_declared_value_set_functions_ret const& that) -> _query_declared_value_set_functions_ret& {
                                out_this_in_that = that.out_this_in_that;
                                out_this_move_that = that.out_this_move_that;
                                inout_this_in_that = that.inout_this_in_that;
                                inout_this_move_that = that.inout_this_move_that;
                                return *this;}
_query_declared_value_set_functions_ret::_query_declared_value_set_functions_ret(_query_declared_value_set_functions_ret&& that) noexcept
                                : out_this_in_that{ std::move(that).out_this_in_that }
                                , out_this_move_that{ std::move(that).out_this_move_that }
                                , inout_this_in_that{ std::move(that).inout_this_in_that }
                                , inout_this_move_that{ std::move(that).inout_this_move_that }{}
auto _query_declared_value_set_functions_ret::operator=(_query_declared_value_set_functions_ret&& that) noexcept -> _query_declared_value_set_functions_ret& {
                                out_this_in_that = std::move(that).out_this_in_that;
                                out_this_move_that = std::move(that).out_this_move_that;
                                inout_this_in_that = std::move(that).inout_this_in_that;
                                inout_this_move_that = std::move(that).inout_this_move_that;
                                return *this;}
_query_declared_value_set_functions_ret::_query_declared_value_set_functions_ret(){}
#line 207 "cpp2reflect_api.h2"
// Workaround due to https://github.com/hsutter/cppfront/issues/1109

#line 219 "cpp2reflect_api.h2"
    [[nodiscard]] auto type_declaration::is_polymorphic() const& -> bool { 
    return CPP2_UFCS(is_polymorphic)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 220 "cpp2reflect_api.h2"
    [[nodiscard]] auto type_declaration::is_final() const& -> bool { 
    return CPP2_UFCS(is_final)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 221 "cpp2reflect_api.h2"
    [[nodiscard]] auto type_declaration::make_final() & -> bool { 
    return CPP2_UFCS(make_final)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 223 "cpp2reflect_api.h2"
    [[nodiscard]] auto type_declaration::get_member_functions() const& -> std::vector<function_declaration> { 
    return CPP2_UFCS(get_member_functions)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 224 "cpp2reflect_api.h2"
    [[nodiscard]] auto type_declaration::get_member_functions_needing_initializer() const& -> std::vector<function_declaration> { 
    return CPP2_UFCS(get_member_functions_needing_initializer)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 225 "cpp2reflect_api.h2"
    [[nodiscard]] auto type_declaration::get_member_objects() const& -> std::vector<object_declaration> { 
    return CPP2_UFCS(get_member_objects)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 226 "cpp2reflect_api.h2"
    [[nodiscard]] auto type_declaration::get_member_types() const& -> std::vector<type_declaration> { 
    return CPP2_UFCS(get_member_types)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 227 "cpp2reflect_api.h2"
    [[nodiscard]] auto type_declaration::get_member_aliases() const& -> std::vector<alias_declaration> { 
    return CPP2_UFCS(get_member_aliases)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 228 "cpp2reflect_api.h2"
    [[nodiscard]] auto type_declaration::get_members() const& -> std::vector<declaration> { 
    return CPP2_UFCS(get_members)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 230 "cpp2reflect_api.h2"
    [[nodiscard]] auto type_declaration::query_declared_value_set_functions() const& -> _query_declared_value_set_functions_ret { 
    return CPP2_UFCS(query_declared_value_set_functions)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 232 "cpp2reflect_api.h2"
    auto type_declaration::add_member(cpp2::impl::in<std::string_view> source) & -> void { 
    CPP2_UFCS(add_member)((*cpp2::impl::assert_not_null(_pimpl)), source); }

#line 234 "cpp2reflect_api.h2"
    auto type_declaration::remove_marked_members() & -> void { 
    CPP2_UFCS(remove_marked_members)((*cpp2::impl::assert_not_null(_pimpl))); }
#line 235 "cpp2reflect_api.h2"
    auto type_declaration::remove_all_members() & -> void { 
    CPP2_UFCS(remove_all_members)((*cpp2::impl::assert_not_null(_pimpl))); }

#line 237 "cpp2reflect_api.h2"
    auto type_declaration::disable_member_function_generation() & -> void { 
    CPP2_UFCS(disable_member_function_generation)((*cpp2::impl::assert_not_null(_pimpl))); }















type_declaration::interface::~interface() noexcept{}

type_declaration::type_declaration(std::unique_ptr<interface> pimpl, auto&& ...parent_pimpls)
                                                                                            : declaration{ CPP2_FORWARD(parent_pimpls)... }
                                                                                            , _pimpl{ cpp2::move(pimpl) }{}
type_declaration::type_declaration(type_declaration&& that) noexcept
                                     : declaration{ static_cast<declaration&&>(that) }
                                     , _pimpl{ std::move(cpp2::move(that)._pimpl) }{}
type_declaration::~type_declaration() noexcept{}

alias_declaration::interface::~interface() noexcept{}

alias_declaration::alias_declaration(std::unique_ptr<interface> pimpl, auto&& ...parent_pimpls)
                                                                                            : declaration{ CPP2_FORWARD(parent_pimpls)... }
                                                                                            , _pimpl{ cpp2::move(pimpl) }{}
alias_declaration::alias_declaration(alias_declaration&& that) noexcept
                                     : declaration{ static_cast<declaration&&>(that) }
                                     , _pimpl{ std::move(cpp2::move(that)._pimpl) }{}
alias_declaration::~alias_declaration() noexcept{}

#line 247 "cpp2reflect_api.h2"
auto reserve_names(type_declaration& t, cpp2::impl::in<std::string_view> name, auto&& ...etc) -> void
{                           // etc is not declared ':string_view' for compatibility with GCC 10.x
    for ( 
         auto const& m : CPP2_UFCS(get_members)(t) ) {
        auto n {CPP2_UFCS(get_metafunction_name)(t)}; 
        CPP2_UFCS(require)(m, !(CPP2_UFCS(has_name)(m, name)), 
                    "in a '" + cpp2::to_string(n) + "' type, the name '" + cpp2::to_string(name) + "' "
                    "is reserved for use by the '" + cpp2::to_string(n) + "' implementation"
        );
    }
    if constexpr (!(CPP2_PACK_EMPTY(etc))) {
        CPP2_UFCS(reserve_names)(t, CPP2_FORWARD(etc)...);
    }
}

}

}

#endif
