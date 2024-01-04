
#ifndef REFLECT_IMPL_H_CPP2
#define REFLECT_IMPL_H_CPP2


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "reflect_impl.h2"

#line 31 "reflect_impl.h2"
namespace cpp2 {

namespace meta {

#line 54 "reflect_impl.h2"
class dll_symbol;
    

#line 110 "reflect_impl.h2"
namespace this_execution
 {

#line 126 "reflect_impl.h2"
}

#line 133 "reflect_impl.h2"
class diagnostic;
    

#line 137 "reflect_impl.h2"
template<typename T> class expected;
    

#line 154 "reflect_impl.h2"
}

}

#line 410 "reflect_impl.h2"
namespace cpp2 {

namespace meta {

#line 422 "reflect_impl.h2"
class compiler_services_data;

#line 635 "reflect_impl.h2"
}

}


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "reflect_impl.h2"

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
#include <cstdlib>
#include <functional>
#include <utility>
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>
#else
#include <dlfcn.h>
#endif // _WIN32

#line 31 "reflect_impl.h2"
namespace cpp2 {

namespace meta {

#line 36 "reflect_impl.h2"
[[nodiscard]] auto to_type_metafunction_cast(
    cpp2::in<std::string_view> name, 
    cpp2::in<bool> is_const_metafunction
    ) -> std::string;

#line 50 "reflect_impl.h2"
//-----------------------------------------------------------------------
//
//  dll_symbol
//
class dll_symbol {
    private: std::string value {}; 

    public: static const std::string_view constant_prefix;
    public: static const std::string_view reachable_mangle;
    public: static const std::string_view const_metafunction_mangle;

    public: dll_symbol();
    public: explicit dll_symbol(cpp2::in<declaration_node> n, cpp2::in<bool> is_reachable_);

#line 76 "reflect_impl.h2"
    public: explicit dll_symbol(std::string_view s);
#line 76 "reflect_impl.h2"
    public: auto operator=(std::string_view s) -> dll_symbol& ;

#line 84 "reflect_impl.h2"
    public: [[nodiscard]] auto c_str() const& -> char const*;
    public: [[nodiscard]] auto view() const& -> std::string_view;
    public: [[nodiscard]] auto without_prefix() const& -> std::string_view;

#line 99 "reflect_impl.h2"
    public: [[nodiscard]] auto is_reachable() const& -> bool;
    public: [[nodiscard]] auto is_const_metafunction() const& -> bool;
    public: [[nodiscard]] auto operator<=>(dll_symbol const& that) const& -> std::strong_ordering = default;
public: dll_symbol(dll_symbol const& that);

public: auto operator=(dll_symbol const& that) -> dll_symbol& ;
public: dll_symbol(dll_symbol&& that) noexcept;
public: auto operator=(dll_symbol&& that) noexcept -> dll_symbol& ;

#line 104 "reflect_impl.h2"
};

[[nodiscard]] auto symbols_accessor(cpp2::in<std::string_view> lib_path) -> dll_symbol;

#line 110 "reflect_impl.h2"
namespace this_execution
 {

//  The environment variable 'CPPFRONT_METAFUNCTION_LIBRARY'
//  is read and interpreted as the Cpp2 metafunction library path of this execution
[[nodiscard]] auto symbols_accessor() -> dll_symbol;

#line 126 "reflect_impl.h2"
}

#line 129 "reflect_impl.h2"
//-----------------------------------------------------------------------
//
//  expected with diagnostic to return to apply_metafunctions
//
class diagnostic {
    public: std::string value; 
};

template<typename T> class expected {

#line 141 "reflect_impl.h2"
    public: expected(T const& v);
#line 141 "reflect_impl.h2"
    public: auto operator=(T const& v) -> expected& ;
    public: expected(cpp2::in<diagnostic> u);
#line 142 "reflect_impl.h2"
    public: auto operator=(cpp2::in<diagnostic> u) -> expected& ;

    public: template<typename F> [[nodiscard]] auto and_then(F const& f) && -> std::remove_cvref_t<std::invoke_result_t<F,T>>;
    private: cpp2::aligned_storage<cpp2::max(sizeof(T), sizeof(diagnostic)),cpp2::max(alignof(T), alignof(diagnostic))> _storage {}; private: cpp2::i8 _discriminator {-1}; public: [[nodiscard]] auto is_value() const& -> bool;
public: [[nodiscard]] auto value() const& -> T const&;
public: [[nodiscard]] auto value() & -> T&;
public: auto set_value(cpp2::in<T> _value) & -> void;
public: auto set_value(auto&& ..._args) & -> void;
public: [[nodiscard]] auto is_error() const& -> bool;
public: [[nodiscard]] auto error() const& -> diagnostic const&;
public: [[nodiscard]] auto error() & -> diagnostic&;
public: auto set_error(cpp2::in<diagnostic> _value) & -> void;
public: auto set_error(auto&& ..._args) & -> void;
private: auto _destroy() & -> void;
public: ~expected() noexcept;
public: explicit expected();
public: expected(expected const& that);

public: expected(expected&& that) noexcept;
public: auto operator=(expected const& that) -> expected& ;
public: auto operator=(expected&& that) noexcept -> expected& ;

#line 152 "reflect_impl.h2"
};

}

}


namespace cpp2::meta {


//-----------------------------------------------------------------------
//
//  (de)mangling
//
auto mangle(std::string res)
    -> std::string
{
    //  Mangle (id length, id) pairs according to
    //  https://en.wikipedia.org/wiki/Name_mangling#Complex_example
    //  "... by the GNU GCC 3.x compilers, according to the IA-64 (Itanium) ABI"
    auto xpos = res.size();
    auto prev_id_end = xpos;
    while ((xpos = res.find_last_of(':', xpos)) != res.npos)
    {
        res.replace(xpos - 1, 2, std::to_string(prev_id_end - xpos - 1));
        prev_id_end = xpos - 1;
    }

    return res;
}

auto mangle(declaration_node const& n)
    -> std::string
{
    assert(n.identifier);
    assert(n.identifier->template_arguments().empty());
    assert(n.parent_is_namespace());

    return mangle(n.fully_qualified_name());
}

auto demangle(std::string_view s)
    -> std::string
{
    std::string res{};

    //  Demangle (id length, id) pairs according to
    //  https://en.wikipedia.org/wiki/Name_mangling#Complex_example
    //  "... by the GNU GCC 3.x compilers, according to the IA-64 (Itanium) ABI"
    while (!s.empty())
    {
        auto length = s.substr(0, s.find_first_not_of("0123456789"));
        s.remove_prefix(length.size());
        auto id = s.substr(0, unsafe_narrow<unsigned>(std::stoi(std::string{length})));
        s.remove_prefix(id.size());

        assert(!length.empty());
        assert(!id.empty());

        res += id;
        if (!s.empty()) {
            res += "::";
        }
    }

    return res;
}


//-----------------------------------------------------------------------
//
//  dll Load DLL and its symbols with the OS API
//
class dll
{
public:
    dll(std::string const& path)
      : handle_{
#ifdef _WIN32
            static_cast<void*>(LoadLibraryA(path.c_str()))
#else
            static_cast<void*>(dlopen(path.c_str(), RTLD_NOW|RTLD_LOCAL))
#endif // _WIN32
            , +[](void* handle)
            {
#ifdef _WIN32
                FreeLibrary(static_cast<HMODULE>(handle));
#else
                dlclose(handle);
#endif // _WIN32
            }
        }
    {
        if(!handle_) {
            Default.report_violation(("failed to load DLL '" + path + "': " + get_last_error()).c_str());
        }
    }

    template<typename T>
    auto get_alias(std::string const& name) noexcept -> T&
    {
#ifdef _WIN32
        auto symbol = reinterpret_cast<void*>(GetProcAddress(static_cast<HMODULE>(handle_.get()), name.c_str()));
#else
        auto symbol = dlsym(handle_.get(), name.c_str());
        if(!symbol)
        {
            //  Some platforms export with additional underscore, so try that
            auto const us_name = "_" + name;
            symbol = dlsym(handle_.get(), us_name.c_str());
        }
#endif // _WIN32
        if (!symbol) {
            Default.report_violation(("failed to load DLL symbol '" + name+ "': " + get_last_error()).c_str());
        }
        return **reinterpret_cast<T**>(symbol);
    }
private:
    std::shared_ptr<void> handle_;

    static auto get_last_error() noexcept -> std::string
    {
#ifdef _WIN32
        DWORD errorMessageID = GetLastError();
        if(errorMessageID == 0) {
            return {}; //  No error message has been recorded
        }
        LPSTR messageBuffer = nullptr;
        auto size = FormatMessageA(
            FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM|FORMAT_MESSAGE_IGNORE_INSERTS,
            nullptr,
            errorMessageID,
            MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
            (LPSTR)&messageBuffer,
            0,
            nullptr
        );
        std::string message(messageBuffer, unsafe_narrow<std::size_t>(size));
        LocalFree(messageBuffer);
        return message;
#else
        return std::string{dlerror()};
#endif // _WIN32
    }

};


//-----------------------------------------------------------------------
//
//  get_reachable_metafunction_symbols
//
struct library
{
    std::string_view name;
    std::vector<dll_symbol> symbols;
};

namespace this_execution {

//  Load Cpp2 libraries with metafunctions by opening DLL with the OS API
//
//  The environment variable 'CPPFRONT_METAFUNCTION_LIBRARIES'
//  is read and interpreted as ':'-separated Cpp2 metafunction library paths
std::span<library> get_reachable_metafunction_symbols()
{
    static std::vector<library> res = []{
        std::vector<library> res;

        // FIXME: On Windows, using this approach with the system apis not set to utf8, will
        // break if a metafunction library contains unicode codepoints in its name, a proper
        // way to handle this would be to use _wgetenv and use wchar_t strings for the dll opening
        // function
        auto cpp1_libraries_cstr = std::getenv("CPPFRONT_METAFUNCTION_LIBRARIES");
        if (
            !cpp1_libraries_cstr
            || cpp1_libraries_cstr[0] == '\0'
            )
        {
            return res;
        }

        auto cpp1_libraries = std::string_view{cpp1_libraries_cstr};
        while (!cpp1_libraries.empty())
        {
            auto colon = cpp1_libraries.find(':');
            auto lib_path = cpp1_libraries.substr(0, colon);
            cpp1_libraries.remove_prefix(lib_path.size() + unsigned(colon != lib_path.npos));

            auto lib = dll{std::string{lib_path}};

            auto get_symbols = lib.get_alias<char const**()>(meta::symbols_accessor(lib_path).c_str());

            res.push_back({lib_path, {}});
            auto c_strings = get_symbols();
            if (!c_strings || !*c_strings) {
                Default.report_violation(
                    ("symbols accesor returns no symbols (in '" + std::string{lib_path} + "')").c_str()
                );
            }

            for (; *c_strings; ++c_strings) {
                auto symbol = res.back().symbols.emplace_back(*c_strings);
            }
        }

        return res;
    }();

    return res;
}

}


//-----------------------------------------------------------------------
//
//  load_metafunction
//
struct lookup_res {
    std::string_view library;
    dll_symbol const* symbol;
};

using load_metafunction_ret = std::function<void(type_declaration&)>;

//  Load Cpp2 metafunction by opening DLL with the OS API
auto load_metafunction(
    std::string const& name,
    std::function<expected<lookup_res>(std::string const&)> lookup
    )
    -> expected<load_metafunction_ret>
{
    return lookup(name).and_then(
        [](lookup_res res)
            -> expected<load_metafunction_ret>
        {
            auto [lib_path, cpp1_name] = res;

            auto lib = dll{std::string(lib_path)};
            return load_metafunction_ret{
                [
                 fun = lib.get_alias<void(type_declaration&)>(cpp1_name->c_str()),
                 lib = std::move(lib)
                 ]
                (type_declaration& t)
                    -> void
                {
                    fun(t);
                }
            };
        }
    );
}

}

#line 410 "reflect_impl.h2"
namespace cpp2 {

namespace meta {

#line 415 "reflect_impl.h2"
//-----------------------------------------------------------------------
//
//  Compiler services data
//
//-----------------------------------------------------------------------
//

class compiler_services_data
 {
    //  Common data members
    //
    public: std::vector<error_entry>* errors; 
    public: int errors_original_size; 
    public: std::deque<token>* generated_tokens; 
    public: cpp2::parser parser; 
    public: std::string metafunction_name {}; 
    public: std::vector<std::string> metafunction_args {}; 
    public: bool metafunctions_used {false}; 

    //  Make function
    //
    public: [[nodiscard]] static auto make(
        std::vector<error_entry>* errors_, 
        std::deque<token>* generated_tokens_, 
        cpp2::in<bool> translation_unit_has_interface
    ) -> compiler_services_data;

#line 448 "reflect_impl.h2"
};

#line 451 "reflect_impl.h2"
//-----------------------------------------------------------------------
//
//  apply_metafunctions
//
[[nodiscard]] auto apply_metafunctions(
    declaration_node& n, 
    type_declaration& rtype, 
    auto const& error, 
    auto const& lookup
    ) -> bool;

#line 569 "reflect_impl.h2"
[[nodiscard]] auto apply_metafunctions(
    declaration_node& n, 
    function_declaration& rfunction, 
    auto const& error
    ) -> bool;

#line 635 "reflect_impl.h2"
}

}


#include "cpp2reflect.hpp"


//=== Cpp2 function definitions =================================================

#line 1 "reflect_impl.h2"

#line 31 "reflect_impl.h2"
namespace cpp2 {

namespace meta {

#line 36 "reflect_impl.h2"
[[nodiscard]] auto to_type_metafunction_cast(
    cpp2::in<std::string_view> name, 
    cpp2::in<bool> is_const_metafunction
    ) -> std::string

{
    auto const_ {""}; 
    if (is_const_metafunction) {
        const_ = " const";
    }
    return "static_cast<void(*)(cpp2::meta::type_declaration" + cpp2::to_string(std::move(const_)) + "&)>(" + cpp2::to_string(name) + ")"; 
}

#line 57 "reflect_impl.h2"
    inline CPP2_CONSTEXPR std::string_view dll_symbol::constant_prefix = "cpp2_metafunction_";
    inline CPP2_CONSTEXPR std::string_view dll_symbol::reachable_mangle = "r";
    inline CPP2_CONSTEXPR std::string_view dll_symbol::const_metafunction_mangle = "c";

    dll_symbol::dll_symbol(){}
    dll_symbol::dll_symbol(cpp2::in<declaration_node> n, cpp2::in<bool> is_reachable_)
        : value{ constant_prefix }

#line 66 "reflect_impl.h2"
    {
        cpp2::finally_presuccess cpp2_finally_presuccess;
        if (cpp2::Default.has_handler() && !(CPP2_UFCS(is_metafunction)(n)) ) { cpp2::Default.report_violation(""); }
        cpp2_finally_presuccess.add([&]{if (cpp2::Default.has_handler() && !(is_reachable() == is_reachable_) ) { cpp2::Default.report_violation(""); }} );
        cpp2_finally_presuccess.add([&]{if (cpp2::Default.has_handler() && !(is_const_metafunction() == CPP2_UFCS(is_const_metafunction)(n)) ) { cpp2::Default.report_violation(""); }} );

#line 68 "reflect_impl.h2"
        if (is_reachable_) {
            value += reachable_mangle;
        }
        if (CPP2_UFCS(is_const_metafunction)(n)) {
            value += const_metafunction_mangle;
        }
        value += mangle(n);
    }
    dll_symbol::dll_symbol(std::string_view s)
    {
        if (!(CPP2_UFCS(starts_with)(s, constant_prefix))) {
            value += constant_prefix;
        }
        value += std::move(s);
    }
#line 76 "reflect_impl.h2"
    auto dll_symbol::operator=(std::string_view s) -> dll_symbol& 
    {
        value = {};
#line 78 "reflect_impl.h2"
        if (!(CPP2_UFCS(starts_with)(s, constant_prefix))) {
            value += constant_prefix;
        }
        value += std::move(s);
        return *this;
#line 82 "reflect_impl.h2"
    }

    [[nodiscard]] auto dll_symbol::c_str() const& -> char const* { return CPP2_UFCS(c_str)(value);  }
    [[nodiscard]] auto dll_symbol::view() const& -> std::string_view { return value;  }
    [[nodiscard]] auto dll_symbol::without_prefix() const& -> std::string_view

    {
        auto res {view()}; 
        CPP2_UFCS(remove_prefix)(res, CPP2_UFCS(size)(constant_prefix));
        for ( 
             auto const& m : { reachable_mangle, const_metafunction_mangle } ) 
        if (CPP2_UFCS(starts_with)(res, m)) {
            CPP2_UFCS(remove_prefix)(res, CPP2_UFCS(size)(m));
        }
        return res; 
    }

    [[nodiscard]] auto dll_symbol::is_reachable() const& -> bool { return CPP2_UFCS(starts_with)(CPP2_UFCS(substr)(view(), CPP2_UFCS(size)(constant_prefix)), reachable_mangle);  }
    [[nodiscard]] auto dll_symbol::is_const_metafunction() const& -> bool { 
                                   return CPP2_UFCS(starts_with)(CPP2_UFCS(substr)(CPP2_UFCS(substr)(view(), CPP2_UFCS(size)(constant_prefix))
                                         , unsigned(is_reachable()) * CPP2_UFCS(size)(reachable_mangle))
                                         , const_metafunction_mangle); }


                                         dll_symbol::dll_symbol(dll_symbol const& that)
                                : value{ that.value }{}

auto dll_symbol::operator=(dll_symbol const& that) -> dll_symbol& {
                                value = that.value;
                                return *this;}
dll_symbol::dll_symbol(dll_symbol&& that) noexcept
                                : value{ std::move(that).value }{}
auto dll_symbol::operator=(dll_symbol&& that) noexcept -> dll_symbol& {
                                value = std::move(that).value;
                                return *this;}
#line 106 "reflect_impl.h2"
[[nodiscard]] auto symbols_accessor(cpp2::in<std::string_view> lib_path) -> dll_symbol { 

    return dll_symbol("get_symbol_names_" + cpp2::to_string(to_lower_and_collapsed_underbar(lib_path, true, true)));  }

namespace this_execution
 {

#line 115 "reflect_impl.h2"
[[nodiscard]] auto symbols_accessor() -> dll_symbol

{
    auto constexpr env_var = "CPPFRONT_METAFUNCTION_LIBRARY";
    auto lib_path {std::getenv(env_var)}; 
    if (cpp2::Default.has_handler() && !(lib_path && CPP2_ASSERT_IN_BOUNDS(lib_path, 0) != '\0') ) { cpp2::Default.report_violation(CPP2_CONTRACT_MSG(cpp2::to_string(env_var) + " should be set for a Cpp2 source with metafunctions")); }
    // FIXME Doesn't work for a library with more than one source providing a metafunction
    // See https://github.com/hsutter/cppfront/pull/907#issuecomment-1872644205
    return meta::symbols_accessor(std::move(lib_path)); 
}

}

#line 141 "reflect_impl.h2"
    template <typename T> expected<T>::expected(T const& v) { set_value(v);  }
#line 141 "reflect_impl.h2"
    template <typename T> auto expected<T>::operator=(T const& v) -> expected&  { 
                                           _storage = {};
                                           _discriminator = -1; set_value(v);
                                           return *this;  }
#line 142 "reflect_impl.h2"
    template <typename T> expected<T>::expected(cpp2::in<diagnostic> u) { set_error(u);  }
#line 142 "reflect_impl.h2"
    template <typename T> auto expected<T>::operator=(cpp2::in<diagnostic> u) -> expected&  { 
                                                    _storage = {};
                                                    _discriminator = -1; set_error(u);
                                                    return *this;  }

#line 144 "reflect_impl.h2"
    template <typename T> template<typename F> [[nodiscard]] auto expected<T>::and_then(F const& f) && -> std::remove_cvref_t<std::invoke_result_t<F,T>>{
        if (is_value()) {
            return f(value()); 
        }
        else {
            return { error() }; 
        }
    }



    template <typename T> [[nodiscard]] auto expected<T>::is_value() const& -> bool { return _discriminator == 0; }
template <typename T> [[nodiscard]] auto expected<T>::value() const& -> T const& { 
                                                 if (cpp2::Default.has_handler() && !(is_value()) ) { cpp2::Default.report_violation(""); }return *cpp2::assert_not_null(reinterpret_cast<T const*>(&_storage)); }
template <typename T> [[nodiscard]] auto expected<T>::value() & -> T& { 
                                                       if (cpp2::Default.has_handler() && !(is_value()) ) { cpp2::Default.report_violation(""); }return *cpp2::assert_not_null(reinterpret_cast<T*>(&_storage)); }
template <typename T> auto expected<T>::set_value(cpp2::in<T> _value) & -> void{if (!(is_value())) {_destroy();std::construct_at(reinterpret_cast<T*>(&_storage), _value);}else {*cpp2::assert_not_null(reinterpret_cast<T*>(&_storage)) = _value;}_discriminator = 0;}
template <typename T> auto expected<T>::set_value(auto&& ..._args) & -> void{if (!(is_value())) {_destroy();std::construct_at(reinterpret_cast<T*>(&_storage), _args...);}else {*cpp2::assert_not_null(reinterpret_cast<T*>(&_storage)) = T{_args...};}_discriminator = 0;}
template <typename T> [[nodiscard]] auto expected<T>::is_error() const& -> bool { return _discriminator == 1; }
template <typename T> [[nodiscard]] auto expected<T>::error() const& -> diagnostic const& { 
                                                          if (cpp2::Default.has_handler() && !(is_error()) ) { cpp2::Default.report_violation(""); }return *cpp2::assert_not_null(reinterpret_cast<diagnostic const*>(&_storage)); }
template <typename T> [[nodiscard]] auto expected<T>::error() & -> diagnostic& { 
                                                                if (cpp2::Default.has_handler() && !(is_error()) ) { cpp2::Default.report_violation(""); }return *cpp2::assert_not_null(reinterpret_cast<diagnostic*>(&_storage)); }
template <typename T> auto expected<T>::set_error(cpp2::in<diagnostic> _value) & -> void{if (!(is_error())) {_destroy();std::construct_at(reinterpret_cast<diagnostic*>(&_storage), _value);}else {*cpp2::assert_not_null(reinterpret_cast<diagnostic*>(&_storage)) = _value;}_discriminator = 1;}
template <typename T> auto expected<T>::set_error(auto&& ..._args) & -> void{if (!(is_error())) {_destroy();std::construct_at(reinterpret_cast<diagnostic*>(&_storage), _args...);}else {*cpp2::assert_not_null(reinterpret_cast<diagnostic*>(&_storage)) = diagnostic{_args...};}_discriminator = 1;}
template <typename T> auto expected<T>::_destroy() & -> void{
    if (_discriminator == 0) {std::destroy_at(reinterpret_cast<T*>(&_storage));}
    if (_discriminator == 1) {std::destroy_at(reinterpret_cast<diagnostic*>(&_storage));}
    _discriminator = -1;
    }

    template <typename T> expected<T>::~expected() noexcept{_destroy();}
template <typename T> expected<T>::expected(){}
template <typename T> expected<T>::expected(expected const& that)
        : _storage{  }
        , _discriminator{ -1 }{
    if (CPP2_UFCS(is_value)(that)) {set_value(CPP2_UFCS(value)(that));}
    if (CPP2_UFCS(is_error)(that)) {set_error(CPP2_UFCS(error)(that));}
    }


    template <typename T> expected<T>::expected(expected&& that) noexcept
        : _storage{  }
        , _discriminator{ -1 }{
    if (CPP2_UFCS(is_value)(std::move(that))) {set_value(CPP2_UFCS(value)(std::move(that)));}
    if (CPP2_UFCS(is_error)(std::move(that))) {set_error(CPP2_UFCS(error)(std::move(that)));}
    }

    template <typename T> auto expected<T>::operator=(expected const& that) -> expected& {
    if (CPP2_UFCS(is_value)(that)) {set_value(CPP2_UFCS(value)(that));}
    if (CPP2_UFCS(is_error)(that)) {set_error(CPP2_UFCS(error)(that));}
        return *this;
    }

    template <typename T> auto expected<T>::operator=(expected&& that) noexcept -> expected& {
    if (CPP2_UFCS(is_value)(std::move(that))) {set_value(CPP2_UFCS(value)(std::move(that)));}
    if (CPP2_UFCS(is_error)(std::move(that))) {set_error(CPP2_UFCS(error)(std::move(that)));}
        return *this;
    }
#line 154 "reflect_impl.h2"
}

}

#line 410 "reflect_impl.h2"
namespace cpp2 {

namespace meta {

#line 436 "reflect_impl.h2"
    [[nodiscard]] auto compiler_services_data::make(
        std::vector<error_entry>* errors_, 
        std::deque<token>* generated_tokens_, 
        cpp2::in<bool> translation_unit_has_interface
    ) -> compiler_services_data

    {
        return { errors_, 
                cpp2::unsafe_narrow<int>(std::ssize(*cpp2::assert_not_null(errors_))), 
                generated_tokens_, 
                cpp2::parser(*cpp2::assert_not_null(errors_), translation_unit_has_interface) }; 
    }

#line 455 "reflect_impl.h2"
[[nodiscard]] auto apply_metafunctions(
    declaration_node& n, 
    type_declaration& rtype, 
    auto const& error, 
    auto const& lookup
    ) -> bool

{
    if (cpp2::Default.has_handler() && !(CPP2_UFCS(is_type)(n)) ) { cpp2::Default.report_violation(""); }

    //  Check for _names reserved for the metafunction implementation
    for ( 
          auto const& m : CPP2_UFCS(get_members)(rtype) ) 
    {
        CPP2_UFCS(require)(m, !(CPP2_UFCS(starts_with)(CPP2_UFCS(name)(m), "_")) || cpp2::cmp_greater(CPP2_UFCS(ssize)(CPP2_UFCS(name)(m)),1), 
                    "a type that applies a metafunction cannot have a body that declares a name that starts with '_' - those names are reserved for the metafunction implementation");
    }

    //  For each metafunction, apply it
    for ( 
         auto const& meta : n.metafunctions ) 
    {
        //  Convert the name and any template arguments to strings
        //  and record that in rtype
        auto name {CPP2_UFCS(to_string)((*cpp2::assert_not_null(meta)))}; 
        name = CPP2_UFCS(substr)(name, 0, CPP2_UFCS(find)(name, '<'));

        std::vector<std::string> args {}; 
        for ( 
             auto const& arg : CPP2_UFCS(template_arguments)((*cpp2::assert_not_null(meta))) ) 
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
        else {if (name == "dll_visible") {
            dll_visible(rtype);
        }
        else {
{
auto const& load = load_metafunction(name, lookup);

#line 541 "reflect_impl.h2"
            if (CPP2_UFCS(is_value)(load)) {
                CPP2_UFCS(value)(load)(rtype);
            }else {
                error("unrecognized metafunction name: " + name);
                if (CPP2_UFCS(find)(name, "::") == name.npos) {
                    error("currently supported built-in names are: interface, polymorphic_base, ordered, weakly_ordered, partially_ordered, copyable, basic_value, value, weakly_ordered_value, partially_ordered_value, struct, enum, flag_enum, union, print, dll_visible");
                }
                if (!(CPP2_UFCS(empty)(CPP2_UFCS(error)(load).value))) {
                    error(CPP2_UFCS(error)(load).value);
                }
                return false; 
            }
}
#line 553 "reflect_impl.h2"
        }}}}}}}}}}}}}}}}

        if ((
            !(CPP2_UFCS(empty)(args)) 
            && !(CPP2_UFCS(arguments_were_used)(rtype)))) 

        {
            error(name + " did not use its template arguments - did you mean to write '" + name + " <" + CPP2_ASSERT_IN_BOUNDS(args, 0) + "> type' (with the spaces)?");
            return false; 
        }
    }

    return true; 
}

#line 569 "reflect_impl.h2"
[[nodiscard]] auto apply_metafunctions(
    declaration_node& n, 
    function_declaration& rfunction, 
    auto const& error
    ) -> bool

{
    if (cpp2::Default.has_handler() && !(CPP2_UFCS(is_function)(n)) ) { cpp2::Default.report_violation(""); }

    //  Check for _names reserved for the metafunction implementation
//  for  rfunction.get_members()
//  do   (m)
//  {
//      m.require( !m.name().starts_with("_") || m.name().ssize() > 1,
//                  "a function that applies a metafunction cannot have a body that declares a name that starts with '_' - those names are reserved for the metafunction implementation");
//  }

    //  For each metafunction, apply it
    for ( 
         auto const& meta : n.metafunctions ) 
    {
        //  Convert the name and any template arguments to strings
        //  and record that in rfunction
        auto name {CPP2_UFCS(to_string)((*cpp2::assert_not_null(meta)))}; 
        name = CPP2_UFCS(substr)(name, 0, CPP2_UFCS(find)(name, '<'));

        std::vector<std::string> args {}; 
        for ( 
             auto const& arg : CPP2_UFCS(template_arguments)((*cpp2::assert_not_null(meta))) ) 
            CPP2_UFCS(push_back)(args, CPP2_UFCS(to_string)(arg));

        CPP2_UFCS(set_metafunction_name)(rfunction, name, args);

        //  Dispatch
        //
        if (name == "dll_visible") {
            dll_visible(rfunction);
        }
        else {
//          (load := load_metafunction(name))
//          if load.metafunction {
//              load.metafunction( rfunction );
//          } else {
                error("unrecognized metafunction name: " + name);
                error("currently supported built-in names are: dll_visible");
//              if !load.error.empty() {
//                  error( load.error );
//              }
//              return false;
//          }
        }

        if ((
            !(CPP2_UFCS(empty)(args)) 
            && !(CPP2_UFCS(arguments_were_used)(rfunction)))) 

        {
            error(name + " did not use its template arguments - did you mean to write '" + name + " <" + CPP2_ASSERT_IN_BOUNDS(args, 0) + "> (...) -> ...' (with the spaces)?");
            return false; 
        }
    }

    return true; 
}

#line 635 "reflect_impl.h2"
}

}

#endif
