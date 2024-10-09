
#ifndef REFLECT_IMPL_H_CPP2
#define REFLECT_IMPL_H_CPP2


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "reflect_impl.h2"

#line 33 "reflect_impl.h2"
namespace cpp2 {

namespace meta {

#line 56 "reflect_impl.h2"
class dll_symbol;
    

#line 112 "reflect_impl.h2"
namespace this_execution
 {

#line 128 "reflect_impl.h2"
}

#line 135 "reflect_impl.h2"
class diagnostic;
    

#line 139 "reflect_impl.h2"
template<typename T> class expected;
    

#line 156 "reflect_impl.h2"
}

}

#line 412 "reflect_impl.h2"
namespace cpp2 {

namespace meta {

#line 424 "reflect_impl.h2"
class compiler_services_data;

#line 474 "reflect_impl.h2"
class expression_flags;

#line 490 "reflect_impl.h2"
class regex_token;

#line 516 "reflect_impl.h2"
class regex_token_check;

#line 535 "reflect_impl.h2"
class regex_token_code;

#line 554 "reflect_impl.h2"
class regex_token_empty;

#line 570 "reflect_impl.h2"
class regex_token_list;

#line 609 "reflect_impl.h2"
class parse_context_group_state;

#line 670 "reflect_impl.h2"
class parse_context_branch_reset_state;

#line 713 "reflect_impl.h2"
class parse_context;

#line 1111 "reflect_impl.h2"
class generation_function_context;
    

#line 1129 "reflect_impl.h2"
class generation_context;

#line 1327 "reflect_impl.h2"
class alternative_token;

#line 1342 "reflect_impl.h2"
class alternative_token_gen;

#line 1394 "reflect_impl.h2"
class any_token;

#line 1412 "reflect_impl.h2"
class char_token;

#line 1515 "reflect_impl.h2"
class class_token;

#line 1730 "reflect_impl.h2"
class group_ref_token;

#line 1861 "reflect_impl.h2"
class group_token;

#line 2148 "reflect_impl.h2"
class lookahead_token;

#line 2229 "reflect_impl.h2"
class range_token;

#line 2377 "reflect_impl.h2"
class special_range_token;

#line 2444 "reflect_impl.h2"
template<typename Error_out> class regex_generator;

#line 2745 "reflect_impl.h2"
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
#include "cpp2regex.h"
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

using namespace cpp2::regex;

#line 33 "reflect_impl.h2"
namespace cpp2 {

namespace meta {

#line 38 "reflect_impl.h2"
[[nodiscard]] auto to_type_metafunction_cast(
    cpp2::impl::in<std::string_view> name, 
    cpp2::impl::in<bool> is_const_metafunction
    ) -> std::string;

#line 56 "reflect_impl.h2"
class dll_symbol {
    private: std::string value {}; 

    public: static const std::string_view constant_prefix;
    public: static const std::string_view reachable_mangle;
    public: static const std::string_view const_metafunction_mangle;

    public: dll_symbol();
    public: explicit dll_symbol(cpp2::impl::in<declaration_node> n, cpp2::impl::in<bool> is_reachable_);

#line 78 "reflect_impl.h2"
    public: explicit dll_symbol(std::string_view s);
#line 78 "reflect_impl.h2"
    public: auto operator=(std::string_view s) -> dll_symbol& ;

#line 86 "reflect_impl.h2"
    public: [[nodiscard]] auto c_str() const& -> char const*;
    public: [[nodiscard]] auto view() const& -> std::string_view;
    public: [[nodiscard]] auto without_prefix() const& -> std::string_view;

#line 101 "reflect_impl.h2"
    public: [[nodiscard]] auto is_reachable() const& -> bool;
    public: [[nodiscard]] auto is_const_metafunction() const& -> bool;
    public: [[nodiscard]] auto operator<=>(dll_symbol const& that) const& -> std::strong_ordering = default;
public: dll_symbol(dll_symbol const& that);

public: auto operator=(dll_symbol const& that) -> dll_symbol& ;
public: dll_symbol(dll_symbol&& that) noexcept;
public: auto operator=(dll_symbol&& that) noexcept -> dll_symbol& ;

#line 106 "reflect_impl.h2"
};

[[nodiscard]] auto symbols_accessor(cpp2::impl::in<std::string_view> lib_path) -> dll_symbol;

#line 112 "reflect_impl.h2"
namespace this_execution
 {

#line 117 "reflect_impl.h2"
[[nodiscard]] auto symbols_accessor() -> dll_symbol;

#line 128 "reflect_impl.h2"
}

#line 135 "reflect_impl.h2"
class diagnostic {
    public: std::string value; 
    public: diagnostic(auto&& value_)
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(value_), std::add_const_t<std::string>&>) ;

public: auto operator=(auto&& value_) -> diagnostic& 
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(value_), std::add_const_t<std::string>&>) ;

#line 137 "reflect_impl.h2"
};

template<typename T> class expected {

#line 143 "reflect_impl.h2"
    public: expected(T const& v);
#line 143 "reflect_impl.h2"
    public: auto operator=(T const& v) -> expected& ;
    public: expected(cpp2::impl::in<diagnostic> u);
#line 144 "reflect_impl.h2"
    public: auto operator=(cpp2::impl::in<diagnostic> u) -> expected& ;

    public: template<typename F> [[nodiscard]] auto and_then(F const& f) && -> std::remove_cvref_t<std::invoke_result_t<F,T>>;
    private: cpp2::aligned_storage<cpp2::max(sizeof(T), sizeof(diagnostic)),cpp2::max(alignof(T), alignof(diagnostic))> _storage {}; private: cpp2::i8 _discriminator {-1}; public: [[nodiscard]] auto is_value() const& -> bool;
public: [[nodiscard]] auto value() const& -> T const&;
public: [[nodiscard]] auto value() & -> T&;
public: auto set_value(cpp2::impl::in<T> _value) & -> void;
public: auto set_value(auto&& ..._args) & -> void;
public: [[nodiscard]] auto is_error() const& -> bool;
public: [[nodiscard]] auto error() const& -> diagnostic const&;
public: [[nodiscard]] auto error() & -> diagnostic&;
public: auto set_error(cpp2::impl::in<diagnostic> _value) & -> void;
public: auto set_error(auto&& ..._args) & -> void;
private: auto _destroy() & -> void;
public: ~expected() noexcept;
public: explicit expected();
public: expected(expected const& that);

public: expected(expected&& that) noexcept;
public: auto operator=(expected const& that) -> expected& ;
public: auto operator=(expected&& that) noexcept -> expected& ;

#line 154 "reflect_impl.h2"
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
        auto id = s.substr(0, unchecked_narrow<unsigned>(std::stoi(std::string{length})));
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
            cpp2_default.report_violation(("failed to load DLL '" + path + "': " + get_last_error()).c_str());
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
            cpp2_default.report_violation(("failed to load DLL symbol '" + name+ "': " + get_last_error()).c_str());
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
        std::string message(messageBuffer, unchecked_narrow<std::size_t>(size));
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
                cpp2_default.report_violation(
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

#line 412 "reflect_impl.h2"
namespace cpp2 {

namespace meta {

#line 424 "reflect_impl.h2"
class compiler_services_data
 {

#line 428 "reflect_impl.h2"
           public: std::vector<error_entry>* errors; 
           public: std::set<std::string>* includes; 
    public: int errors_original_size; 
    public: stable_vector<token>* generated_tokens; 
    public: cpp2::parser parser; 
    public: std::string metafunction_name {}; 
    public: std::vector<std::string> metafunction_args {}; 
    public: bool metafunctions_used {false}; 

#line 439 "reflect_impl.h2"
    public: [[nodiscard]] static auto make(
        std::vector<error_entry>* errors_, 
        std::set<std::string>* includes_, 
        stable_vector<token>* generated_tokens_, 
        cpp2::impl::in<bool> translation_unit_has_interface
    ) -> compiler_services_data;

#line 453 "reflect_impl.h2"
};

#line 470 "reflect_impl.h2"
using error_func = std::function<void(cpp2::impl::in<std::string> x)>;

#line 474 "reflect_impl.h2"
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

#line 482 "reflect_impl.h2"
};

#line 490 "reflect_impl.h2"
class regex_token
 {
    public: std::string string_rep; 

    public: explicit regex_token(cpp2::impl::in<std::string> str);

#line 498 "reflect_impl.h2"
    public: explicit regex_token();

#line 503 "reflect_impl.h2"
    public: virtual auto generate_code([[maybe_unused]] generation_context& unnamed_param_2) const -> void = 0;

    public: virtual auto add_groups([[maybe_unused]] std::set<int>& unnamed_param_2) const -> void;
    public: [[nodiscard]] auto to_string() const& -> std::string;
    public: auto set_string(cpp2::impl::in<std::string> s) & -> void;
    public: virtual ~regex_token() noexcept;

    public: regex_token(regex_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_token const&) -> void = delete;

#line 508 "reflect_impl.h2"
};

using token_ptr = std::shared_ptr<regex_token>;
using token_vec = std::vector<token_ptr>;

#line 514 "reflect_impl.h2"
//  Adds a check in code generation.
//
class regex_token_check
: public regex_token {

#line 520 "reflect_impl.h2"
    private: std::string check; 

    public: explicit regex_token_check(cpp2::impl::in<std::string> str, cpp2::impl::in<std::string> check_);

#line 527 "reflect_impl.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;
    public: virtual ~regex_token_check() noexcept;

    public: regex_token_check(regex_token_check const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_token_check const&) -> void = delete;


#line 530 "reflect_impl.h2"
};

#line 533 "reflect_impl.h2"
//  Adds code in code generation.
//
class regex_token_code
: public regex_token {

#line 539 "reflect_impl.h2"
    private: std::string code; 

    public: explicit regex_token_code(cpp2::impl::in<std::string> str, cpp2::impl::in<std::string> code_);

#line 546 "reflect_impl.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;
    public: virtual ~regex_token_code() noexcept;

    public: regex_token_code(regex_token_code const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_token_code const&) -> void = delete;


#line 549 "reflect_impl.h2"
};

#line 552 "reflect_impl.h2"
//  Token that does not influence the matching. E.g. comment.
//
class regex_token_empty
: public regex_token {

#line 558 "reflect_impl.h2"
    public: explicit regex_token_empty(cpp2::impl::in<std::string> str);

#line 562 "reflect_impl.h2"
    public: auto generate_code([[maybe_unused]] generation_context& unnamed_param_2) const -> void override;
    public: virtual ~regex_token_empty() noexcept;

    public: regex_token_empty(regex_token_empty const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_token_empty const&) -> void = delete;


#line 565 "reflect_impl.h2"
};

#line 568 "reflect_impl.h2"
//  Represents a list of regex tokens as one token.
//
class regex_token_list
: public regex_token {

#line 574 "reflect_impl.h2"
    public: token_vec tokens; 

    public: explicit regex_token_list(cpp2::impl::in<token_vec> t);

#line 581 "reflect_impl.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 587 "reflect_impl.h2"
    public: auto add_groups(std::set<int>& groups) const -> void override;

#line 593 "reflect_impl.h2"
    public: [[nodiscard]] static auto gen_string(cpp2::impl::in<token_vec> vec) -> std::string;
    public: virtual ~regex_token_list() noexcept;

    public: regex_token_list(regex_token_list const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_token_list const&) -> void = delete;


#line 600 "reflect_impl.h2"
};

#line 603 "reflect_impl.h2"
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

#line 623 "reflect_impl.h2"
    //  Swap this state with the other one. NOLINTNEXTLINE(performance-noexcept-swap)
    public: auto swap(parse_context_group_state& t) & -> void;

#line 630 "reflect_impl.h2"
    //  Convert this state into a regex token.
    public: [[nodiscard]] auto get_as_token() & -> token_ptr;

#line 642 "reflect_impl.h2"
    //  Add a token to the current matcher list.
    public: auto add(cpp2::impl::in<token_ptr> token) & -> void;

#line 647 "reflect_impl.h2"
    //  True if current matcher list is empty.
    public: [[nodiscard]] auto empty() const& -> bool;

#line 651 "reflect_impl.h2"
    //  Apply optimizations to the matcher list.
    public: static auto post_process_list(token_vec& list) -> void;
    public: parse_context_group_state(auto const& cur_match_list_, auto const& alternate_match_lists_, auto const& modifiers_);
public: parse_context_group_state();


#line 665 "reflect_impl.h2"
};

#line 668 "reflect_impl.h2"
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

#line 686 "reflect_impl.h2"
    //  Set next group identifier.
    public: auto set_next(cpp2::impl::in<int> g) & -> void;

#line 692 "reflect_impl.h2"
    //  Start a new alternative branch.
    public: auto next_alternative() & -> void;

#line 699 "reflect_impl.h2"
    //  Initialize for a branch reset group.
    public: auto set_active_reset(cpp2::impl::in<int> restart) & -> void;
    public: parse_context_branch_reset_state(auto const& is_active_, auto const& cur_group_, auto const& max_group_, auto const& from_);
public: parse_context_branch_reset_state();


#line 706 "reflect_impl.h2"
};

#line 709 "reflect_impl.h2"
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

#line 723 "reflect_impl.h2"
           public: std::map<std::string,int> named_groups {}; 

    private: error_func error_out; // TODO: Declaring std::function<void(std::string)> fails for cpp2.
    private: bool has_error {false}; 

    public: explicit parse_context(cpp2::impl::in<std::string_view> r, auto const& e);

#line 734 "reflect_impl.h2"
    //  State management functions
    //

    //  Returned group state needs to be stored and provided in `end_group`.
    public: [[nodiscard]] auto start_group() & -> parse_context_group_state;

#line 747 "reflect_impl.h2"
    //  `old_state` argument needs to be from start group.
    public: [[nodiscard]] auto end_group(cpp2::impl::in<parse_context_group_state> old_state) & -> token_ptr;

#line 755 "reflect_impl.h2"
    public: [[nodiscard]] auto get_modifiers() const& -> expression_flags;

#line 759 "reflect_impl.h2"
    public: auto set_modifiers(cpp2::impl::in<expression_flags> mod) & -> void;

#line 763 "reflect_impl.h2"
    //  Branch reset management functions
    //

    public: [[nodiscard]] auto branch_reset_new_state() & -> parse_context_branch_reset_state;

#line 775 "reflect_impl.h2"
    public: auto branch_reset_restore_state(cpp2::impl::in<parse_context_branch_reset_state> old_state) & -> void;

#line 782 "reflect_impl.h2"
    public: auto next_alternative() & -> void;

#line 788 "reflect_impl.h2"
    //  Regex token management
    //
    public: auto add_token(cpp2::impl::in<token_ptr> token) & -> void;

#line 794 "reflect_impl.h2"
    public: [[nodiscard]] auto has_token() const& -> bool;

#line 798 "reflect_impl.h2"
    public: [[nodiscard]] auto pop_token() & -> token_ptr;

#line 809 "reflect_impl.h2"
    public: [[nodiscard]] auto get_as_token() & -> token_ptr;

#line 813 "reflect_impl.h2"
    //  Group management
    //
    public: [[nodiscard]] auto get_cur_group() const& -> int;

#line 819 "reflect_impl.h2"
    public: [[nodiscard]] auto next_group() & -> int;

#line 823 "reflect_impl.h2"
    public: auto set_named_group(cpp2::impl::in<std::string> name, cpp2::impl::in<int> id) & -> void;

#line 830 "reflect_impl.h2"
    public: [[nodiscard]] auto get_named_group(cpp2::impl::in<std::string> name) const& -> int;

#line 841 "reflect_impl.h2"
    //  Position management functions
    //
    public: [[nodiscard]] auto current() const& -> char;

    //  Get the next token in the regex, skipping spaces according to the parameters. See `x` and `xx` modifiers.
    private: [[nodiscard]] auto get_next_position(cpp2::impl::in<bool> in_class, cpp2::impl::in<bool> no_skip) const& -> size_t;

#line 885 "reflect_impl.h2"
    //  Return true if next token is available.
    private: [[nodiscard]] auto next_impl(cpp2::impl::in<bool> in_class, cpp2::impl::in<bool> no_skip) & -> bool;

#line 897 "reflect_impl.h2"
    public: [[nodiscard]] auto next() & -> decltype(auto);
    public: [[nodiscard]] auto next_in_class() & -> decltype(auto);
    public: [[nodiscard]] auto next_no_skip() & -> decltype(auto);

    public: [[nodiscard]] auto next_n(cpp2::impl::in<int> n) & -> bool;

#line 910 "reflect_impl.h2"
    public: [[nodiscard]] auto has_next() const& -> bool;

    private: [[nodiscard]] auto grab_until_impl(cpp2::impl::in<std::string> e, cpp2::impl::out<std::string> r, cpp2::impl::in<bool> any) & -> bool;

#line 933 "reflect_impl.h2"
    public: [[nodiscard]] auto grab_until(cpp2::impl::in<std::string> e, cpp2::impl::out<std::string> r) & -> decltype(auto);
    public: [[nodiscard]] auto grab_until(cpp2::impl::in<char> e, cpp2::impl::out<std::string> r) & -> decltype(auto);
    public: [[nodiscard]] auto grab_until_one_of(cpp2::impl::in<std::string> e, cpp2::impl::out<std::string> r) & -> decltype(auto);

    public: [[nodiscard]] auto grab_n(cpp2::impl::in<int> n, cpp2::impl::out<std::string> r) & -> bool;

#line 950 "reflect_impl.h2"
    public: [[nodiscard]] auto grab_number() & -> std::string;

#line 971 "reflect_impl.h2"
    private: [[nodiscard]] auto peek_impl(cpp2::impl::in<bool> in_class) const& -> char;

#line 981 "reflect_impl.h2"
    public: [[nodiscard]] auto peek() const& -> decltype(auto);
    public: [[nodiscard]] auto peek_in_class() const& -> decltype(auto);

#line 985 "reflect_impl.h2"
    //  Parsing functions
    //
    public: [[nodiscard]] auto parser_group_modifiers(cpp2::impl::in<std::string> change_str, expression_flags& parser_modifiers) & -> bool;

#line 1041 "reflect_impl.h2"
    public: [[nodiscard]] auto parse_until(cpp2::impl::in<char> term) & -> bool;

#line 1079 "reflect_impl.h2"
    public: [[nodiscard]] auto parse(cpp2::impl::in<std::string> modifiers) & -> bool;

#line 1094 "reflect_impl.h2"
    //  Misc functions

    public: [[nodiscard]] auto get_pos() const& -> decltype(auto);
    public: [[nodiscard]] auto get_range(cpp2::impl::in<size_t> start, cpp2::impl::in<size_t> end) const& -> decltype(auto);
    public: [[nodiscard]] auto valid() const& -> bool;

    public: [[nodiscard]] auto error(cpp2::impl::in<std::string> err) & -> token_ptr;
    public: parse_context(parse_context const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(parse_context const&) -> void = delete;


#line 1105 "reflect_impl.h2"
};

#line 1108 "reflect_impl.h2"
//  Context for one function generation. Generation of functions can be interleaved,
//  therefore we buffer the code for one function here.
//
class generation_function_context {
    public: std::string code {""}; 
    public: std::string tabs {""}; 

    public: auto add_tabs(cpp2::impl::in<int> c) & -> void;

#line 1122 "reflect_impl.h2"
    public: auto remove_tabs(cpp2::impl::in<int> c) & -> void;
    public: generation_function_context(auto const& code_, auto const& tabs_);
public: generation_function_context();


#line 1125 "reflect_impl.h2"
};

#line 1128 "reflect_impl.h2"
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

#line 1150 "reflect_impl.h2"
    //  Add check for token. The check needs to be a function call that returns a boolean.
    public: auto add_check(cpp2::impl::in<std::string> check) & -> void;

#line 1156 "reflect_impl.h2"
    //  Add a stateful check. The check needs to return a `match_return`.
    public: auto add_statefull(cpp2::impl::in<std::string> next_func, cpp2::impl::in<std::string> check) & -> void;

#line 1165 "reflect_impl.h2"
    protected: auto start_func_named(cpp2::impl::in<std::string> name) & -> void;

#line 1176 "reflect_impl.h2"
    protected: [[nodiscard]] auto start_func() & -> std::string;

#line 1183 "reflect_impl.h2"
    protected: auto end_func_statefull(cpp2::impl::in<std::string> s) & -> void;

#line 1202 "reflect_impl.h2"
    //  Generate the function for a token.
    public: [[nodiscard]] auto generate_func(cpp2::impl::in<token_ptr> token) & -> std::string;

#line 1212 "reflect_impl.h2"
    //  Generate the reset for a list of group identifiers.
    public: [[nodiscard]] auto generate_reset(cpp2::impl::in<std::set<int>> groups) & -> std::string;

#line 1235 "reflect_impl.h2"
    //  Name generation
    //
    protected: [[nodiscard]] auto gen_func_name() & -> std::string;

#line 1243 "reflect_impl.h2"
    public: [[nodiscard]] auto next_func_name() & -> std::string;

#line 1247 "reflect_impl.h2"
    protected: [[nodiscard]] auto gen_reset_func_name() & -> std::string;

#line 1253 "reflect_impl.h2"
    public: [[nodiscard]] auto gen_temp() & -> std::string;

#line 1259 "reflect_impl.h2"
    //  Context management
    //
    public: [[nodiscard]] auto new_context() & -> generation_function_context*;

#line 1269 "reflect_impl.h2"
    public: auto finish_context() & -> void;

#line 1277 "reflect_impl.h2"
    //  Misc functions
    //
    private: [[nodiscard]] auto get_current() & -> generation_function_context*;

#line 1283 "reflect_impl.h2"
    private: [[nodiscard]] auto get_base() & -> generation_function_context*;

#line 1287 "reflect_impl.h2"
    public: [[nodiscard]] auto get_entry_func() const& -> std::string;

#line 1291 "reflect_impl.h2"
    public: [[nodiscard]] auto create_named_group_lookup(cpp2::impl::in<std::map<std::string,int>> named_groups) const& -> std::string;

#line 1315 "reflect_impl.h2"
    //  Run the generation for the token.
    public: [[nodiscard]] auto run(cpp2::impl::in<token_ptr> token) & -> std::string;
    public: generation_context() = default;
    public: generation_context(generation_context const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(generation_context const&) -> void = delete;


#line 1321 "reflect_impl.h2"
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


#line 1340 "reflect_impl.h2"
};

class alternative_token_gen
: public regex_token {

#line 1346 "reflect_impl.h2"
    private: token_vec alternatives; 

    public: explicit alternative_token_gen(cpp2::impl::in<token_vec> a);

#line 1353 "reflect_impl.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 1370 "reflect_impl.h2"
    public: auto add_groups(std::set<int>& groups) const -> void override;

#line 1377 "reflect_impl.h2"
    public: [[nodiscard]] static auto gen_string(cpp2::impl::in<token_vec> a) -> std::string;
    public: virtual ~alternative_token_gen() noexcept;

    public: alternative_token_gen(alternative_token_gen const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(alternative_token_gen const&) -> void = delete;


#line 1389 "reflect_impl.h2"
};

#line 1392 "reflect_impl.h2"
//  Regex syntax: .
//
class any_token
: public regex_token_check {

#line 1398 "reflect_impl.h2"
    public: explicit any_token(cpp2::impl::in<bool> single_line);

#line 1402 "reflect_impl.h2"
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;
    public: virtual ~any_token() noexcept;

    public: any_token(any_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(any_token const&) -> void = delete;


#line 1407 "reflect_impl.h2"
};

#line 1410 "reflect_impl.h2"
//  Regex syntax: a
//
class char_token
: public regex_token {

#line 1416 "reflect_impl.h2"
    private: std::string token; 
    private: bool ignore_case; 

    public: explicit char_token(cpp2::impl::in<char> t, cpp2::impl::in<bool> ignore_case_);

#line 1425 "reflect_impl.h2"
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 1429 "reflect_impl.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 1452 "reflect_impl.h2"
    public: auto gen_case_insensitive(cpp2::impl::in<std::string> lower, cpp2::impl::in<std::string> upper, generation_context& ctx) const& -> void;

#line 1473 "reflect_impl.h2"
    public: auto gen_case_sensitive(generation_context& ctx) const& -> void;

#line 1491 "reflect_impl.h2"
    public: [[nodiscard]] auto add_escapes(std::string str) const& -> std::string;

#line 1506 "reflect_impl.h2"
    public: auto append(char_token const& that) & -> void;
    public: virtual ~char_token() noexcept;

    public: char_token(char_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(char_token const&) -> void = delete;


#line 1510 "reflect_impl.h2"
};

#line 1513 "reflect_impl.h2"
//  Regex syntax: [<character classes>]  Example: [abcx-y[:digits:]]
//
class class_token
: public regex_token {

#line 1519 "reflect_impl.h2"
    private: bool negate; 
    private: bool case_insensitive; 
    private: std::string class_str; 

    public: explicit class_token(cpp2::impl::in<bool> negate_, cpp2::impl::in<bool> case_insensitive_, cpp2::impl::in<std::string> class_str_, cpp2::impl::in<std::string> str);

#line 1531 "reflect_impl.h2"
    //  TODO: Rework class generation: Generate check functions for classes.
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 1657 "reflect_impl.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 1662 "reflect_impl.h2"
    private: [[nodiscard]] static auto create_matcher(cpp2::impl::in<std::string> name, cpp2::impl::in<std::string> template_arguments) -> std::string;
    public: virtual ~class_token() noexcept;

    public: class_token(class_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(class_token const&) -> void = delete;


#line 1669 "reflect_impl.h2"
};

#line 1672 "reflect_impl.h2"
//  Regex syntax: \a or \n or \[
//
[[nodiscard]] auto escape_token_parse(parse_context& ctx) -> token_ptr;

#line 1713 "reflect_impl.h2"
//  Regex syntax: \K Example: ab\Kcd
//
[[nodiscard]] auto global_group_reset_token_parse(parse_context& ctx) -> token_ptr;

#line 1724 "reflect_impl.h2"
//  Regex syntax: \<number>  Example: \1
//                \g{name_or_number}
//                \k{name_or_number}
//                \k<name_or_number>
//                \k'name_or_number'
//
class group_ref_token
: public regex_token {

#line 1734 "reflect_impl.h2"
    private: int id; 
    private: bool case_insensitive; 

    public: explicit group_ref_token(cpp2::impl::in<int> id_, cpp2::impl::in<bool> case_insensitive_, cpp2::impl::in<std::string> str);

#line 1744 "reflect_impl.h2"
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 1845 "reflect_impl.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;
    public: virtual ~group_ref_token() noexcept;

    public: group_ref_token(group_ref_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_ref_token const&) -> void = delete;


#line 1848 "reflect_impl.h2"
};

#line 1851 "reflect_impl.h2"
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

#line 1865 "reflect_impl.h2"
    private: int number {-1}; 
    private: token_ptr inner {nullptr}; 

    public: [[nodiscard]] static auto parse_lookahead(parse_context& ctx, cpp2::impl::in<std::string> syntax, cpp2::impl::in<bool> positive) -> token_ptr;

#line 1882 "reflect_impl.h2"
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 2019 "reflect_impl.h2"
    public: [[nodiscard]] static auto gen_string(cpp2::impl::in<std::string> name, cpp2::impl::in<bool> name_brackets, cpp2::impl::in<bool> has_modifier, cpp2::impl::in<std::string> modifiers, cpp2::impl::in<token_ptr> inner_) -> std::string;

#line 2037 "reflect_impl.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 2057 "reflect_impl.h2"
    public: auto add_groups(std::set<int>& groups) const -> void override;
    public: virtual ~group_token() noexcept;

    public: group_token() = default;
    public: group_token(group_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(group_token const&) -> void = delete;


#line 2064 "reflect_impl.h2"
};

#line 2067 "reflect_impl.h2"
//  Regex syntax: \x<number> or \x{<number>}  Example: \x{62}
//
[[nodiscard]] auto hexadecimal_token_parse(parse_context& ctx) -> token_ptr;

#line 2108 "reflect_impl.h2"
//  Regex syntax: $  Example: aa$
//
[[nodiscard]] auto line_end_token_parse(parse_context& ctx) -> token_ptr;

#line 2128 "reflect_impl.h2"
//  Regex syntax: ^  Example: ^aa
//
[[nodiscard]] auto line_start_token_parse(parse_context& ctx) -> token_ptr;

#line 2144 "reflect_impl.h2"
//  Regex syntax: (?=) or (?!) or (*pla), etc.  Example: (?=AA)
//
//  Parsed in group_token.
//
class lookahead_token
: public regex_token {

#line 2152 "reflect_impl.h2"
    protected: bool positive; 
    public:   token_ptr inner {nullptr}; 

    public: explicit lookahead_token(cpp2::impl::in<bool> positive_);

#line 2159 "reflect_impl.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 2165 "reflect_impl.h2"
    public: auto add_groups(std::set<int>& groups) const -> void override;
    public: virtual ~lookahead_token() noexcept;

    public: lookahead_token(lookahead_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(lookahead_token const&) -> void = delete;


#line 2168 "reflect_impl.h2"
};

#line 2171 "reflect_impl.h2"
// Named character classes
//
[[nodiscard]] auto named_class_token_parse(parse_context& ctx) -> token_ptr;

#line 2199 "reflect_impl.h2"
//  Regex syntax: \o{<number>}  Example: \o{142}
//
[[nodiscard]] auto octal_token_parse(parse_context& ctx) -> token_ptr;

#line 2227 "reflect_impl.h2"
//  Regex syntax: <matcher>{min, max}  Example: a{2,4}
//
class range_token
: public regex_token {

#line 2233 "reflect_impl.h2"
              protected: int min_count {-1}; 
              protected: int max_count {-1}; 
              protected: int kind {range_flags::greedy}; 
              protected: token_ptr inner_token {nullptr}; 

    public: explicit range_token();

    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;

#line 2313 "reflect_impl.h2"
    public: auto parse_modifier(parse_context& ctx) & -> void;

#line 2325 "reflect_impl.h2"
    public: [[nodiscard]] auto gen_mod_string() const& -> std::string;

#line 2338 "reflect_impl.h2"
    public: [[nodiscard]] auto gen_range_string() const& -> std::string;

#line 2357 "reflect_impl.h2"
    public: auto generate_code(generation_context& ctx) const -> void override;

#line 2368 "reflect_impl.h2"
    public: auto add_groups(std::set<int>& groups) const -> void override;
    public: virtual ~range_token() noexcept;

    public: range_token(range_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(range_token const&) -> void = delete;


#line 2372 "reflect_impl.h2"
};

#line 2375 "reflect_impl.h2"
//  Regex syntax: *, +, or ?  Example: aa*
//
class special_range_token
: public range_token {

#line 2381 "reflect_impl.h2"
    public: [[nodiscard]] static auto parse(parse_context& ctx) -> token_ptr;
    public: virtual ~special_range_token() noexcept;

    public: special_range_token() = default;
    public: special_range_token(special_range_token const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(special_range_token const&) -> void = delete;


#line 2411 "reflect_impl.h2"
};

#line 2414 "reflect_impl.h2"
//  Regex syntax: \b or \B  Example: \bword\b
//
//  Matches the start end end of word boundaries.
//
[[nodiscard]] auto word_boundary_token_parse(parse_context& ctx) -> token_ptr;

#line 2436 "reflect_impl.h2"
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

#line 2459 "reflect_impl.h2"
    public: [[nodiscard]] auto parse() & -> std::string;

#line 2494 "reflect_impl.h2"
    private: auto extract_modifiers() & -> void;
    public: regex_generator(regex_generator const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(regex_generator const&) -> void = delete;


#line 2508 "reflect_impl.h2"
};

template<typename Err> [[nodiscard]] auto generate_regex(cpp2::impl::in<std::string_view> regex, Err const& err) -> std::string;

#line 2520 "reflect_impl.h2"
auto regex_gen(meta::type_declaration& t) -> void;

#line 2575 "reflect_impl.h2"
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

#line 2704 "reflect_impl.h2"
[[nodiscard]] auto apply_metafunctions(
    declaration_node& n, 
    function_declaration& rfunction, 
    auto const& error
    ) -> bool;

#line 2745 "reflect_impl.h2"
}

}


#include "cpp2reflect.hpp"


//=== Cpp2 function definitions =================================================

#line 1 "reflect_impl.h2"

#line 33 "reflect_impl.h2"
namespace cpp2 {

namespace meta {

#line 38 "reflect_impl.h2"
[[nodiscard]] auto to_type_metafunction_cast(
    cpp2::impl::in<std::string_view> name, 
    cpp2::impl::in<bool> is_const_metafunction
    ) -> std::string

{
    auto const_ {""}; 
    if (is_const_metafunction) {
        const_ = " const";
    }
    return "static_cast<void(*)(cpp2::meta::type_declaration" + cpp2::to_string(cpp2::move(const_)) + "&)>(" + cpp2::to_string(name) + ")"; 
}

#line 52 "reflect_impl.h2"
//-----------------------------------------------------------------------
//
//  dll_symbol
//

#line 59 "reflect_impl.h2"
    inline CPP2_CONSTEXPR std::string_view dll_symbol::constant_prefix{ "cpp2_metafunction_" };
    inline CPP2_CONSTEXPR std::string_view dll_symbol::reachable_mangle{ "r" };
    inline CPP2_CONSTEXPR std::string_view dll_symbol::const_metafunction_mangle{ "c" };

#line 63 "reflect_impl.h2"
    dll_symbol::dll_symbol(){}
#line 64 "reflect_impl.h2"
    dll_symbol::dll_symbol(cpp2::impl::in<declaration_node> n, cpp2::impl::in<bool> is_reachable_)
        : value{ constant_prefix }

#line 68 "reflect_impl.h2"
    {
        cpp2::finally_presuccess cpp2_finally_presuccess;
        if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(is_metafunction)(n)) ) { cpp2::cpp2_default.report_violation(""); }
        cpp2_finally_presuccess.add([&]{if (cpp2::cpp2_default.is_active() && !(is_reachable() == is_reachable_) ) { cpp2::cpp2_default.report_violation(""); }} );
        cpp2_finally_presuccess.add([&]{if (cpp2::cpp2_default.is_active() && !(is_const_metafunction() == CPP2_UFCS(is_const_metafunction)(n)) ) { cpp2::cpp2_default.report_violation(""); }} );

#line 70 "reflect_impl.h2"
        if (is_reachable_) {
            value += reachable_mangle;
        }
        if (CPP2_UFCS(is_const_metafunction)(n)) {
            value += const_metafunction_mangle;
        }
        value += mangle(n);
    }
#line 78 "reflect_impl.h2"
    dll_symbol::dll_symbol(std::string_view s)
    {
        if (!(CPP2_UFCS(starts_with)(s, constant_prefix))) {
            value += constant_prefix;
        }
        value += cpp2::move(s);
    }
#line 78 "reflect_impl.h2"
    auto dll_symbol::operator=(std::string_view s) -> dll_symbol& 
#line 79 "reflect_impl.h2"
    {
        value = {};
#line 80 "reflect_impl.h2"
        if (!(CPP2_UFCS(starts_with)(s, constant_prefix))) {
            value += constant_prefix;
        }
        value += cpp2::move(s);
        return *this;
#line 84 "reflect_impl.h2"
    }

#line 86 "reflect_impl.h2"
    [[nodiscard]] auto dll_symbol::c_str() const& -> char const* { return CPP2_UFCS(c_str)(value);  }
#line 87 "reflect_impl.h2"
    [[nodiscard]] auto dll_symbol::view() const& -> std::string_view { return value;  }
#line 88 "reflect_impl.h2"
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

#line 101 "reflect_impl.h2"
    [[nodiscard]] auto dll_symbol::is_reachable() const& -> bool { return CPP2_UFCS(starts_with)(CPP2_UFCS(substr)(view(), CPP2_UFCS(size)(constant_prefix)), reachable_mangle);  }
#line 102 "reflect_impl.h2"
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
#line 108 "reflect_impl.h2"
[[nodiscard]] auto symbols_accessor(cpp2::impl::in<std::string_view> lib_path) -> dll_symbol { 

    return dll_symbol("get_symbol_names_" + cpp2::to_string(to_lower_and_collapsed_underbar(lib_path, true, true)) + "");  }

namespace this_execution
 {

//  The environment variable 'CPPFRONT_METAFUNCTION_LIBRARY'
//  is read and interpreted as the Cpp2 metafunction library path of this execution
#line 117 "reflect_impl.h2"
[[nodiscard]] auto symbols_accessor() -> dll_symbol

{
    auto constexpr env_var{ "CPPFRONT_METAFUNCTION_LIBRARY" };
    auto lib_path {std::getenv(env_var)}; 
    if (cpp2::cpp2_default.is_active() && !(lib_path && CPP2_ASSERT_IN_BOUNDS_LITERAL(lib_path, 0) != '\0') ) { cpp2::cpp2_default.report_violation(CPP2_CONTRACT_MSG("" + cpp2::to_string(env_var) + " should be set for a Cpp2 source with metafunctions")); }
    // FIXME Doesn't work for a library with more than one source providing a metafunction
    // See https://github.com/hsutter/cppfront/pull/907#issuecomment-1872644205
    return meta::symbols_accessor(cpp2::move(lib_path)); 
}

}


diagnostic::diagnostic(auto&& value_)
requires (std::is_convertible_v<CPP2_TYPEOF(value_), std::add_const_t<std::string>&>) 
                                                                       : value{ CPP2_FORWARD(value_) }{}
auto diagnostic::operator=(auto&& value_) -> diagnostic& 
requires (std::is_convertible_v<CPP2_TYPEOF(value_), std::add_const_t<std::string>&>) {
                                                                       value = CPP2_FORWARD(value_);
                                                                       return *this;}
#line 131 "reflect_impl.h2"
//-----------------------------------------------------------------------
//
//  expected with diagnostic to return to apply_metafunctions
//

#line 143 "reflect_impl.h2"
    template <typename T> expected<T>::expected(T const& v) { set_value(v);  }
#line 143 "reflect_impl.h2"
    template <typename T> auto expected<T>::operator=(T const& v) -> expected&  { 
                                           _storage = {};
                                           _discriminator = -1; set_value(v);
                                           return *this;  }
#line 144 "reflect_impl.h2"
    template <typename T> expected<T>::expected(cpp2::impl::in<diagnostic> u) { set_error(u);  }
#line 144 "reflect_impl.h2"
    template <typename T> auto expected<T>::operator=(cpp2::impl::in<diagnostic> u) -> expected&  { 
                                                    _storage = {};
                                                    _discriminator = -1; set_error(u);
                                                    return *this;  }

#line 146 "reflect_impl.h2"
    template <typename T> template<typename F> [[nodiscard]] auto expected<T>::and_then(F const& f) && -> std::remove_cvref_t<std::invoke_result_t<F,T>>{
        if (is_value()) {
            return f(cpp2::move(*this).value()); 
        }
        else {
            return { cpp2::move(*this).error() }; 
        }
    }



    template <typename T> [[nodiscard]] auto expected<T>::is_value() const& -> bool { return _discriminator == 0; }
template <typename T> [[nodiscard]] auto expected<T>::value() const& -> T const& { 
                                                 if (cpp2::cpp2_default.is_active() && !(is_value()) ) { cpp2::cpp2_default.report_violation(""); }return *cpp2::impl::assert_not_null(reinterpret_cast<T const*>(&_storage)); }
template <typename T> [[nodiscard]] auto expected<T>::value() & -> T& { 
                                                       if (cpp2::cpp2_default.is_active() && !(is_value()) ) { cpp2::cpp2_default.report_violation(""); }return *cpp2::impl::assert_not_null(reinterpret_cast<T*>(&_storage)); }
template <typename T> auto expected<T>::set_value(cpp2::impl::in<T> _value) & -> void{if (!(is_value())) {_destroy();std::construct_at(reinterpret_cast<T*>(&_storage), _value);}else {*cpp2::impl::assert_not_null(reinterpret_cast<T*>(&_storage)) = _value;}_discriminator = 0;}
template <typename T> auto expected<T>::set_value(auto&& ..._args) & -> void{if (!(is_value())) {_destroy();std::construct_at(reinterpret_cast<T*>(&_storage), CPP2_FORWARD(_args)...);}else {*cpp2::impl::assert_not_null(reinterpret_cast<T*>(&_storage)) = T{CPP2_FORWARD(_args)...};}_discriminator = 0;}
template <typename T> [[nodiscard]] auto expected<T>::is_error() const& -> bool { return _discriminator == 1; }
template <typename T> [[nodiscard]] auto expected<T>::error() const& -> diagnostic const& { 
                                                          if (cpp2::cpp2_default.is_active() && !(is_error()) ) { cpp2::cpp2_default.report_violation(""); }return *cpp2::impl::assert_not_null(reinterpret_cast<diagnostic const*>(&_storage)); }
template <typename T> [[nodiscard]] auto expected<T>::error() & -> diagnostic& { 
                                                                if (cpp2::cpp2_default.is_active() && !(is_error()) ) { cpp2::cpp2_default.report_violation(""); }return *cpp2::impl::assert_not_null(reinterpret_cast<diagnostic*>(&_storage)); }
template <typename T> auto expected<T>::set_error(cpp2::impl::in<diagnostic> _value) & -> void{if (!(is_error())) {_destroy();std::construct_at(reinterpret_cast<diagnostic*>(&_storage), _value);}else {*cpp2::impl::assert_not_null(reinterpret_cast<diagnostic*>(&_storage)) = _value;}_discriminator = 1;}
template <typename T> auto expected<T>::set_error(auto&& ..._args) & -> void{if (!(is_error())) {_destroy();std::construct_at(reinterpret_cast<diagnostic*>(&_storage), CPP2_FORWARD(_args)...);}else {*cpp2::impl::assert_not_null(reinterpret_cast<diagnostic*>(&_storage)) = diagnostic{CPP2_FORWARD(_args)...};}_discriminator = 1;}
template <typename T> auto expected<T>::_destroy() & -> void{
    if (_discriminator == 0) {std::destroy_at(reinterpret_cast<T*>(&_storage));}
    if (_discriminator == 1) {std::destroy_at(reinterpret_cast<diagnostic*>(&_storage));}
    _discriminator = -1;
    }

    template <typename T> expected<T>::~expected() noexcept{_destroy();static_cast<void>(cpp2::move((*this)));}
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
    if (CPP2_UFCS(is_value)(cpp2::move(that))) {set_value(CPP2_UFCS(value)(cpp2::move(that)));}
    if (CPP2_UFCS(is_error)(cpp2::move(that))) {set_error(CPP2_UFCS(error)(cpp2::move(that)));}
    }

    template <typename T> auto expected<T>::operator=(expected const& that) -> expected& {
    if (CPP2_UFCS(is_value)(that)) {set_value(CPP2_UFCS(value)(that));}
    if (CPP2_UFCS(is_error)(that)) {set_error(CPP2_UFCS(error)(that));}
        return *this;
    }

    template <typename T> auto expected<T>::operator=(expected&& that) noexcept -> expected& {
    if (CPP2_UFCS(is_value)(cpp2::move(that))) {set_value(CPP2_UFCS(value)(cpp2::move(that)));}
    if (CPP2_UFCS(is_error)(cpp2::move(that))) {set_error(CPP2_UFCS(error)(cpp2::move(that)));}
        return *this;
    }
#line 156 "reflect_impl.h2"
}

}

#line 412 "reflect_impl.h2"
namespace cpp2 {

namespace meta {

#line 417 "reflect_impl.h2"
//-----------------------------------------------------------------------
//
//  Compiler services data
//
//-----------------------------------------------------------------------
//

#line 426 "reflect_impl.h2"
    //  Common data members
    //

#line 437 "reflect_impl.h2"
    //  Make function
    //
#line 439 "reflect_impl.h2"
    [[nodiscard]] auto compiler_services_data::make(
        std::vector<error_entry>* errors_, 
        std::set<std::string>* includes_, 
        stable_vector<token>* generated_tokens_, 
        cpp2::impl::in<bool> translation_unit_has_interface
    ) -> compiler_services_data

    {
        return { errors_, 
                includes_, 
                cpp2::unchecked_narrow<int>(std::ssize(*cpp2::impl::assert_not_null(errors_))), 
                generated_tokens_, 
                cpp2::parser(*cpp2::impl::assert_not_null(errors_), *cpp2::impl::assert_not_null(includes_), translation_unit_has_interface) }; 
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
    if (((*this) & case_insensitive) == case_insensitive) {ret += sep + pref + "case_insensitive";sep = separator;}
    if (((*this) & multiple_lines) == multiple_lines) {ret += sep + pref + "multiple_lines";sep = separator;}
    if (((*this) & single_line) == single_line) {ret += sep + pref + "single_line";sep = separator;}
    if (((*this) & no_group_captures) == no_group_captures) {ret += sep + pref + "no_group_captures";sep = separator;}
    if (((*this) & perl_code_syntax) == perl_code_syntax) {ret += sep + pref + "perl_code_syntax";sep = separator;}
    if (((*this) & perl_code_syntax_in_classes) == perl_code_syntax_in_classes) {ret += sep + cpp2::move(pref) + "perl_code_syntax_in_classes";sep = separator;}
    return cpp2::move(ret) + ")"; 
    }

    [[nodiscard]] auto expression_flags::to_string() const& -> std::string { return to_string_impl("", ", "); }
[[nodiscard]] auto expression_flags::to_code() const& -> std::string { return to_string_impl("expression_flags::", " | "); }
[[nodiscard]] auto expression_flags::from_string(cpp2::impl::in<std::string_view> s) -> expression_flags{

    auto ret {none}; 
    do {{
    for ( auto const& x : cpp2::string_util::split_string_list(s) ) {
    if ("case_insensitive" == x) {ret |= case_insensitive;}
    else {if ("multiple_lines" == x) {ret |= multiple_lines;}
    else {if ("single_line" == x) {ret |= single_line;}
    else {if ("no_group_captures" == x) {ret |= no_group_captures;}
    else {if ("perl_code_syntax" == x) {ret |= perl_code_syntax;}
    else {if ("perl_code_syntax_in_classes" == x) {ret |= perl_code_syntax_in_classes;}
    else {if ("none" == x) {ret |= none;}
    else {goto BREAK_outer;}
#line 1 "reflect_impl.h2"
}}}}}}
}

return ret; 
} CPP2_CONTINUE_BREAK(outer) }
 while ( 
false
);
CPP2_UFCS(report_violation)(cpp2::type_safety, CPP2_UFCS(c_str)(("can't convert string '" + cpp2::to_string(s) + "' to flag_enum of type expression_flags")));
return none; 
}

[[nodiscard]] auto expression_flags::from_code(cpp2::impl::in<std::string_view> s) -> expression_flags{
std::string str {s}; return from_string(cpp2::string_util::replace_all(cpp2::move(str), "expression_flags::", "")); }

#line 456 "reflect_impl.h2"
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

#line 472 "reflect_impl.h2"
//  Possible modifiers for a regular expression.
//

#line 476 "reflect_impl.h2"
                                  // mod: i
                                  // mod: m
                                  // mod: s
                                  // mod: n
                                  // mod: x
                                  // mod: xx

#line 485 "reflect_impl.h2"
//  Tokens for regular expressions.
//

// Basic class for a regex token.
//

#line 494 "reflect_impl.h2"
    regex_token::regex_token(cpp2::impl::in<std::string> str)
        : string_rep{ str }{

#line 496 "reflect_impl.h2"
    }

#line 498 "reflect_impl.h2"
    regex_token::regex_token()
        : string_rep{ "" }{

#line 500 "reflect_impl.h2"
    }

    //parse: (inout ctx: parse_context) -> token_ptr;
                                                                       // Generate the matching code.

#line 505 "reflect_impl.h2"
    auto regex_token::add_groups([[maybe_unused]] std::set<int>& unnamed_param_2) const -> void{}// Adds all group indices to the set.
#line 506 "reflect_impl.h2"
    [[nodiscard]] auto regex_token::to_string() const& -> std::string{return string_rep; }// Create a string representation.
#line 507 "reflect_impl.h2"
    auto regex_token::set_string(cpp2::impl::in<std::string> s) & -> void{string_rep = s; }

    regex_token::~regex_token() noexcept{}// Set the string representation.

#line 522 "reflect_impl.h2"
    regex_token_check::regex_token_check(cpp2::impl::in<std::string> str, cpp2::impl::in<std::string> check_)
        : regex_token{ str }
        , check{ check_ }{

#line 525 "reflect_impl.h2"
    }

#line 527 "reflect_impl.h2"
    auto regex_token_check::generate_code(generation_context& ctx) const -> void{
        ctx.add_check(check + "(" + ctx.match_parameters() + ")");
    }

    regex_token_check::~regex_token_check() noexcept{}

#line 541 "reflect_impl.h2"
    regex_token_code::regex_token_code(cpp2::impl::in<std::string> str, cpp2::impl::in<std::string> code_)
        : regex_token{ str }
        , code{ code_ }{

#line 544 "reflect_impl.h2"
    }

#line 546 "reflect_impl.h2"
    auto regex_token_code::generate_code(generation_context& ctx) const -> void{
        ctx.add(code);
    }

    regex_token_code::~regex_token_code() noexcept{}

#line 558 "reflect_impl.h2"
    regex_token_empty::regex_token_empty(cpp2::impl::in<std::string> str)
        : regex_token{ str }{

#line 560 "reflect_impl.h2"
    }

#line 562 "reflect_impl.h2"
    auto regex_token_empty::generate_code([[maybe_unused]] generation_context& unnamed_param_2) const -> void{
        // Nothing.
    }

    regex_token_empty::~regex_token_empty() noexcept{}

#line 576 "reflect_impl.h2"
    regex_token_list::regex_token_list(cpp2::impl::in<token_vec> t)
        : regex_token{ gen_string(t) }
        , tokens{ t }{

#line 579 "reflect_impl.h2"
    }

#line 581 "reflect_impl.h2"
    auto regex_token_list::generate_code(generation_context& ctx) const -> void{
        for ( auto const& token : tokens ) {
            (*cpp2::impl::assert_not_null(token)).generate_code(ctx);
        }
    }

#line 587 "reflect_impl.h2"
    auto regex_token_list::add_groups(std::set<int>& groups) const -> void{
        for ( auto const& token : tokens ) {
            (*cpp2::impl::assert_not_null(token)).add_groups(groups);
        }
    }

#line 593 "reflect_impl.h2"
    [[nodiscard]] auto regex_token_list::gen_string(cpp2::impl::in<token_vec> vec) -> std::string{
        std::string r {""}; 
        for ( auto const& token : vec ) {
            r += (*cpp2::impl::assert_not_null(token)).to_string();
        }
        return r; 
    }

    regex_token_list::~regex_token_list() noexcept{}

#line 616 "reflect_impl.h2"
    auto parse_context_group_state::next_alternative() & -> void{
        token_vec new_list {}; 
        std::swap(new_list, cur_match_list);
        post_process_list(new_list);
        static_cast<void>(alternate_match_lists.insert(alternate_match_lists.end(), CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_list>)(cpp2::shared, cpp2::move(new_list))));
    }

#line 624 "reflect_impl.h2"
    auto parse_context_group_state::swap(parse_context_group_state& t) & -> void{// NOLINT(performance-noexcept-swap)
        std::swap(cur_match_list, t.cur_match_list);
        std::swap(alternate_match_lists, t.alternate_match_lists);
        std::swap(modifiers, t.modifiers);
    }

#line 631 "reflect_impl.h2"
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

#line 643 "reflect_impl.h2"
    auto parse_context_group_state::add(cpp2::impl::in<token_ptr> token) & -> void{
        cur_match_list.push_back(token);
    }

#line 648 "reflect_impl.h2"
    [[nodiscard]] auto parse_context_group_state::empty() const& -> bool { return cur_match_list.empty();  }

#line 652 "reflect_impl.h2"
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

#line 678 "reflect_impl.h2"
    [[nodiscard]] auto parse_context_branch_reset_state::next() & -> int{
        auto g {cur_group}; 
        cur_group += 1;
        max_group = max(max_group, cur_group);

        return g; 
    }

#line 687 "reflect_impl.h2"
    auto parse_context_branch_reset_state::set_next(cpp2::impl::in<int> g) & -> void{
        cur_group = g;
        max_group = max(max_group, g);
    }

#line 693 "reflect_impl.h2"
    auto parse_context_branch_reset_state::next_alternative() & -> void{
        if (is_active) {
            cur_group = from;
        }
    }

#line 700 "reflect_impl.h2"
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

#line 728 "reflect_impl.h2"
    parse_context::parse_context(cpp2::impl::in<std::string_view> r, auto const& e)
        : regex{ r }
        , root{ CPP2_UFCS_TEMPLATE_NONLOCAL(cpp2_new<regex_token_empty>)(cpp2::shared, "") }
        , error_out{ e }{

#line 732 "reflect_impl.h2"
    }

#line 738 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::start_group() & -> parse_context_group_state
    {
        parse_context_group_state old_state {}; 
        old_state.swap(cur_group_state);
        cur_group_state.modifiers = old_state.modifiers;

        return old_state; 
    }

#line 748 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::end_group(cpp2::impl::in<parse_context_group_state> old_state) & -> token_ptr
    {
        auto inner {cur_group_state.get_as_token()}; 
        cur_group_state = old_state;
        return inner; 
    }

#line 755 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::get_modifiers() const& -> expression_flags{
        return cur_group_state.modifiers; 
    }

#line 759 "reflect_impl.h2"
    auto parse_context::set_modifiers(cpp2::impl::in<expression_flags> mod) & -> void{
        cur_group_state.modifiers = mod;
    }

#line 766 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::branch_reset_new_state() & -> parse_context_branch_reset_state
    {
        parse_context_branch_reset_state old_state {}; 
        std::swap(old_state, cur_branch_reset_state);

        cur_branch_reset_state.set_active_reset(old_state.cur_group);
        return old_state; 
    }

#line 775 "reflect_impl.h2"
    auto parse_context::branch_reset_restore_state(cpp2::impl::in<parse_context_branch_reset_state> old_state) & -> void
    {
        auto max_group {cur_branch_reset_state.max_group}; 
        cur_branch_reset_state = old_state;
        cur_branch_reset_state.set_next(cpp2::move(max_group));
    }

#line 782 "reflect_impl.h2"
    auto parse_context::next_alternative() & -> void
    {
        cur_group_state.next_alternative();
        cur_branch_reset_state.next_alternative();
    }

#line 790 "reflect_impl.h2"
    auto parse_context::add_token(cpp2::impl::in<token_ptr> token) & -> void{
        cur_group_state.add(token);
    }

#line 794 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::has_token() const& -> bool{
        return !(cur_group_state.empty()); 
    }

#line 798 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::pop_token() & -> token_ptr
    {
        token_ptr r {nullptr}; 
        if (has_token()) {
            r = cur_group_state.cur_match_list.back();
            cur_group_state.cur_match_list.pop_back();
        }

        return r; 
    }

#line 809 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::get_as_token() & -> token_ptr{
        return root; 
    }

#line 815 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::get_cur_group() const& -> int{
        return cur_branch_reset_state.cur_group; 
    }

#line 819 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::next_group() & -> int{
        return cur_branch_reset_state.next(); 
    }

#line 823 "reflect_impl.h2"
    auto parse_context::set_named_group(cpp2::impl::in<std::string> name, cpp2::impl::in<int> id) & -> void
    {
        if (!(named_groups.contains(name))) {// Redefinition of group name is not an error. The left most one is retained.
            CPP2_ASSERT_IN_BOUNDS(named_groups, name) = id;
        }
    }

#line 830 "reflect_impl.h2"
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

#line 843 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::current() const& -> char{return CPP2_ASSERT_IN_BOUNDS(regex, pos); }

#line 846 "reflect_impl.h2"
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

#line 886 "reflect_impl.h2"
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

#line 897 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::next() & -> decltype(auto) { return next_impl(false, false); }
#line 898 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::next_in_class() & -> decltype(auto) { return next_impl(true, false);  }
#line 899 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::next_no_skip() & -> decltype(auto) { return next_impl(false, true); }

#line 901 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::next_n(cpp2::impl::in<int> n) & -> bool{
        auto r {true}; 
        auto cur {0}; 
        for( ; r && cpp2::impl::cmp_less(cur,n); (r = next()) ) {
            cur += 1;
        }
        return r; 
    }

#line 910 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::has_next() const& -> bool{return cpp2::impl::cmp_less(pos,regex.size()); }

#line 912 "reflect_impl.h2"
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

#line 933 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::grab_until(cpp2::impl::in<std::string> e, cpp2::impl::out<std::string> r) & -> decltype(auto) { return grab_until_impl(e, cpp2::impl::out(&r), false); }
#line 934 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::grab_until(cpp2::impl::in<char> e, cpp2::impl::out<std::string> r) & -> decltype(auto) { return grab_until_impl(std::string(1, e), cpp2::impl::out(&r), false); }
#line 935 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::grab_until_one_of(cpp2::impl::in<std::string> e, cpp2::impl::out<std::string> r) & -> decltype(auto) { return grab_until_impl(e, cpp2::impl::out(&r), true);  }

#line 937 "reflect_impl.h2"
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

#line 950 "reflect_impl.h2"
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

#line 971 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::peek_impl(cpp2::impl::in<bool> in_class) const& -> char{
        auto next_pos {get_next_position(in_class, false)}; 
        if (cpp2::impl::cmp_less(next_pos,regex.size())) {
            return CPP2_ASSERT_IN_BOUNDS(regex, cpp2::move(next_pos)); 
        }
        else {
            return '\0'; 
        }
    }

#line 981 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::peek() const& -> decltype(auto) { return peek_impl(false); }
#line 982 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::peek_in_class() const& -> decltype(auto) { return peek_impl(true);  }

#line 987 "reflect_impl.h2"
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

#line 1041 "reflect_impl.h2"
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

#line 1079 "reflect_impl.h2"
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

#line 1096 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::get_pos() const& -> decltype(auto) { return pos; }
#line 1097 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::get_range(cpp2::impl::in<size_t> start, cpp2::impl::in<size_t> end) const& -> decltype(auto) { return std::string(regex.substr(start, end - start + 1));  }
#line 1098 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::valid() const& -> bool{return has_next() && !(has_error); }

#line 1100 "reflect_impl.h2"
    [[nodiscard]] auto parse_context::error(cpp2::impl::in<std::string> err) & -> token_ptr{
        has_error = true;
        error_out("Error during parsing of regex '" + cpp2::to_string(regex) + "' at position '" + cpp2::to_string(pos) + "': " + cpp2::to_string(err) + "");
        return nullptr; 
    }

#line 1115 "reflect_impl.h2"
    auto generation_function_context::add_tabs(cpp2::impl::in<int> c) & -> void{
        int i {0}; 
        for( ; cpp2::impl::cmp_less(i,c); i += 1 ) {
            tabs += "  ";
        }
    }

#line 1122 "reflect_impl.h2"
    auto generation_function_context::remove_tabs(cpp2::impl::in<int> c) & -> void{
        tabs = tabs.substr(0, (cpp2::impl::as_<size_t>(c)) * 2);
    }

    generation_function_context::generation_function_context(auto const& code_, auto const& tabs_)
                                                       : code{ code_ }
                                                       , tabs{ tabs_ }{}
generation_function_context::generation_function_context(){}

#line 1140 "reflect_impl.h2"
    [[nodiscard]] auto generation_context::match_parameters() const& -> std::string{return "r.pos, ctx"; }

#line 1145 "reflect_impl.h2"
    auto generation_context::add(cpp2::impl::in<std::string> s) & -> void{
        auto cur {get_current()}; 
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + cpp2::to_string(s) + "\n";
    }

#line 1151 "reflect_impl.h2"
    auto generation_context::add_check(cpp2::impl::in<std::string> check) & -> void{
        auto cur {get_current()}; 
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "if !cpp2::regex::" + cpp2::to_string(check) + " { r.matched = false; break; }\n";
    }

#line 1157 "reflect_impl.h2"
    auto generation_context::add_statefull(cpp2::impl::in<std::string> next_func, cpp2::impl::in<std::string> check) & -> void
    {
        end_func_statefull(check);

        auto name {next_func.substr(0, next_func.size() - 2)}; 
        start_func_named(cpp2::move(name));
    }

#line 1165 "reflect_impl.h2"
    auto generation_context::start_func_named(cpp2::impl::in<std::string> name) & -> void
    {
        auto cur {new_context()}; 

        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + cpp2::to_string(name) + ": @struct<noforward> type = {\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "  operator(): (this, cur: Iter, inout ctx: context, other) -> cpp2::regex::match_return<Iter> = {\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "    r := ctx..pass(cur);\n";
        (*cpp2::impl::assert_not_null(cur)).code += "" + cpp2::to_string((*cpp2::impl::assert_not_null(cur)).tabs) + "    do {\n";
        (*cpp2::impl::assert_not_null(cpp2::move(cur))).add_tabs(3);
    }

#line 1176 "reflect_impl.h2"
    [[nodiscard]] auto generation_context::start_func() & -> std::string
    {
        auto name {gen_func_name()}; 
        start_func_named(name);
        return cpp2::move(name) + "()"; 
    }

#line 1183 "reflect_impl.h2"
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

#line 1203 "reflect_impl.h2"
    [[nodiscard]] auto generation_context::generate_func(cpp2::impl::in<token_ptr> token) & -> std::string
    {
        auto name {start_func()}; 
        (*cpp2::impl::assert_not_null(token)).generate_code((*this));
        end_func_statefull("other(" + cpp2::to_string(match_parameters()) + ")");

        return name; 
    }

#line 1213 "reflect_impl.h2"
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

#line 1237 "reflect_impl.h2"
    [[nodiscard]] auto generation_context::gen_func_name() & -> std::string{
        auto cur_id {matcher_func}; 
        matcher_func += 1;
        return "func_" + cpp2::to_string(cpp2::move(cur_id)) + ""; 
    }

#line 1243 "reflect_impl.h2"
    [[nodiscard]] auto generation_context::next_func_name() & -> std::string{
        return gen_func_name() + "()"; 
    }

#line 1247 "reflect_impl.h2"
    [[nodiscard]] auto generation_context::gen_reset_func_name() & -> std::string{
        auto cur_id {reset_func}; 
        reset_func += 1;
        return "reset_" + cpp2::to_string(cpp2::move(cur_id)) + ""; 
    }

#line 1253 "reflect_impl.h2"
    [[nodiscard]] auto generation_context::gen_temp() & -> std::string{
        auto cur_id {temp_name}; 
        temp_name += 1;
        return "tmp_" + cpp2::to_string(cpp2::move(cur_id)) + ""; 
    }

#line 1261 "reflect_impl.h2"
    [[nodiscard]] auto generation_context::new_context() & -> generation_function_context*{
        gen_stack.push_back(generation_function_context());
        auto cur {get_current()}; 
        (*cpp2::impl::assert_not_null(cur)).tabs = "    ";

        return cur; 
    }

#line 1269 "reflect_impl.h2"
    auto generation_context::finish_context() & -> void{
        auto cur {get_current()}; 
        auto base {get_base()}; 
        (*cpp2::impl::assert_not_null(base)).code += (*cpp2::impl::assert_not_null(cpp2::move(cur))).code;

        gen_stack.pop_back();
    }

#line 1279 "reflect_impl.h2"
    [[nodiscard]] auto generation_context::get_current() & -> generation_function_context*{
        return &gen_stack.back(); 
    }

#line 1283 "reflect_impl.h2"
    [[nodiscard]] auto generation_context::get_base() & -> generation_function_context*{
        return &CPP2_ASSERT_IN_BOUNDS_LITERAL(gen_stack, 0); 
    }

#line 1287 "reflect_impl.h2"
    [[nodiscard]] auto generation_context::get_entry_func() const& -> std::string{
        return entry_func; 
    }

#line 1291 "reflect_impl.h2"
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

#line 1316 "reflect_impl.h2"
    [[nodiscard]] auto generation_context::run(cpp2::impl::in<token_ptr> token) & -> std::string{
        entry_func = generate_func(token);

        return (*cpp2::impl::assert_not_null(get_base())).code; 
    }

#line 1331 "reflect_impl.h2"
    alternative_token::alternative_token()
                            : regex_token_empty{ "" }{}

#line 1333 "reflect_impl.h2"
    [[nodiscard]] auto alternative_token::parse(parse_context& ctx) -> token_ptr{
        if (ctx.current() != '|') {return nullptr; }

        if (!(ctx.has_token())) {return ctx.error("Alternative with no content."); }
        ctx.next_alternative();
        return CPP2_UFCS_TEMPLATE(cpp2_new<alternative_token>)(cpp2::shared); 
    }

    alternative_token::~alternative_token() noexcept{}

#line 1348 "reflect_impl.h2"
    alternative_token_gen::alternative_token_gen(cpp2::impl::in<token_vec> a)
        : regex_token{ gen_string(a) }
        , alternatives{ a }{

#line 1351 "reflect_impl.h2"
    }

#line 1353 "reflect_impl.h2"
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

#line 1370 "reflect_impl.h2"
    auto alternative_token_gen::add_groups(std::set<int>& groups) const -> void
    {
        for ( auto const& cur : alternatives ) {
            (*cpp2::impl::assert_not_null(cur)).add_groups(groups);
        }
    }

#line 1377 "reflect_impl.h2"
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

#line 1398 "reflect_impl.h2"
    any_token::any_token(cpp2::impl::in<bool> single_line)
        : regex_token_check{ ".", "any_token_matcher<char, " + cpp2::to_string(single_line) + ">" }{

#line 1400 "reflect_impl.h2"
    }

#line 1402 "reflect_impl.h2"
    [[nodiscard]] auto any_token::parse(parse_context& ctx) -> token_ptr{
        if ('.' != ctx.current()) {return nullptr; }

        return CPP2_UFCS_TEMPLATE(cpp2_new<any_token>)(cpp2::shared, ctx.get_modifiers().has(expression_flags::single_line)); 
    }

    any_token::~any_token() noexcept{}

#line 1419 "reflect_impl.h2"
    char_token::char_token(cpp2::impl::in<char> t, cpp2::impl::in<bool> ignore_case_)
        : regex_token{ std::string(1, t) }
        , token{ t }
        , ignore_case{ ignore_case_ }{

#line 1423 "reflect_impl.h2"
    }

#line 1425 "reflect_impl.h2"
    [[nodiscard]] auto char_token::parse(parse_context& ctx) -> token_ptr{
        return CPP2_UFCS_TEMPLATE(cpp2_new<char_token>)(cpp2::shared, ctx.current(), ctx.get_modifiers().has(expression_flags::case_insensitive)); 
    }

#line 1429 "reflect_impl.h2"
    auto char_token::generate_code(generation_context& ctx) const -> void
    {
        if (ignore_case) {
            std::string upper {token}; 
            std::string lower {token}; 
{
size_t i{0};

#line 1435 "reflect_impl.h2"
            for( ; cpp2::impl::cmp_less(i,token.size()); i += 1 ) {
                CPP2_ASSERT_IN_BOUNDS(lower, i) = string_util::safe_tolower(CPP2_ASSERT_IN_BOUNDS(token, i));
                CPP2_ASSERT_IN_BOUNDS(upper, i) = string_util::safe_toupper(CPP2_ASSERT_IN_BOUNDS(token, i));
            }
}

#line 1440 "reflect_impl.h2"
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

#line 1452 "reflect_impl.h2"
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

#line 1473 "reflect_impl.h2"
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

#line 1491 "reflect_impl.h2"
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

#line 1506 "reflect_impl.h2"
    auto char_token::append(char_token const& that) & -> void{
        (*this).token += that.token;
        (*this).string_rep += that.string_rep;
    }

    char_token::~char_token() noexcept{}

#line 1523 "reflect_impl.h2"
    class_token::class_token(cpp2::impl::in<bool> negate_, cpp2::impl::in<bool> case_insensitive_, cpp2::impl::in<std::string> class_str_, cpp2::impl::in<std::string> str)
        : regex_token{ str }
        , negate{ negate_ }
        , case_insensitive{ case_insensitive_ }
        , class_str{ class_str_ }
#line 1524 "reflect_impl.h2"
    {

#line 1529 "reflect_impl.h2"
    }

#line 1532 "reflect_impl.h2"
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

#line 1657 "reflect_impl.h2"
    auto class_token::generate_code(generation_context& ctx) const -> void
    {
        ctx.add_check("class_token_matcher<char, " + cpp2::to_string(negate) + ", " + cpp2::to_string(case_insensitive) + ", " + cpp2::to_string(class_str) + ">::match(" + cpp2::to_string(ctx.match_parameters()) + ")");
    }

#line 1662 "reflect_impl.h2"
    [[nodiscard]] auto class_token::create_matcher(cpp2::impl::in<std::string> name, cpp2::impl::in<std::string> template_arguments) -> std::string
    {
        auto sep {", "}; 
        if (template_arguments.empty()) {sep = ""; }

        return "::cpp2::regex::" + cpp2::to_string(name) + "<char" + cpp2::to_string(cpp2::move(sep)) + cpp2::to_string(template_arguments) + ">"; 
    }

    class_token::~class_token() noexcept{}

#line 1674 "reflect_impl.h2"
[[nodiscard]] auto escape_token_parse(parse_context& ctx) -> token_ptr
{
    if (ctx.current() != '\\') {return nullptr; }

#line 1679 "reflect_impl.h2"
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

#line 1715 "reflect_impl.h2"
[[nodiscard]] auto global_group_reset_token_parse(parse_context& ctx) -> token_ptr
{
    if (!((ctx.current() == '\\' && ctx.peek() == 'K'))) {return nullptr; }

    static_cast<void>(ctx.next());// Skip escape.
    return CPP2_UFCS_TEMPLATE(cpp2_new<regex_token_code>)(cpp2::shared, "\\K", "ctx..set_group_start(0, r.pos);"); 
}

#line 1737 "reflect_impl.h2"
    group_ref_token::group_ref_token(cpp2::impl::in<int> id_, cpp2::impl::in<bool> case_insensitive_, cpp2::impl::in<std::string> str)
        : regex_token{ str }
        , id{ id_ }
        , case_insensitive{ case_insensitive_ }
#line 1738 "reflect_impl.h2"
    {

#line 1742 "reflect_impl.h2"
    }

#line 1744 "reflect_impl.h2"
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

        return CPP2_UFCS_TEMPLATE(cpp2_new<group_ref_token>)(cpp2::shared, cpp2::move(group_id), ctx.get_modifiers().has(expression_flags::case_insensitive), cpp2::move(str)); 
    }

#line 1845 "reflect_impl.h2"
    auto group_ref_token::generate_code(generation_context& ctx) const -> void{
        ctx.add_check("group_ref_token_matcher<char, " + cpp2::to_string(id) + ", " + cpp2::to_string(case_insensitive) + ">(" + cpp2::to_string(ctx.match_parameters()) + ")");
    }

    group_ref_token::~group_ref_token() noexcept{}

#line 1868 "reflect_impl.h2"
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

#line 1882 "reflect_impl.h2"
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

#line 2019 "reflect_impl.h2"
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

#line 2037 "reflect_impl.h2"
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

#line 2057 "reflect_impl.h2"
    auto group_token::add_groups(std::set<int>& groups) const -> void
    {
        (*cpp2::impl::assert_not_null(inner)).add_groups(groups);
        if (-1 != number) {
            static_cast<void>(groups.insert(number));
        }
    }

    group_token::~group_token() noexcept{}

#line 2069 "reflect_impl.h2"
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

#line 2110 "reflect_impl.h2"
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

#line 2130 "reflect_impl.h2"
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

#line 2155 "reflect_impl.h2"
    lookahead_token::lookahead_token(cpp2::impl::in<bool> positive_)
        : regex_token{ "" }
        , positive{ positive_ }{

#line 2157 "reflect_impl.h2"
    }

#line 2159 "reflect_impl.h2"
    auto lookahead_token::generate_code(generation_context& ctx) const -> void{
        auto inner_name {ctx.generate_func(inner)}; 

        ctx.add_check("lookahead_token_matcher<char, " + cpp2::to_string(positive) + ">(" + cpp2::to_string(ctx.match_parameters()) + ", " + cpp2::to_string(cpp2::move(inner_name)) + ")");
    }

#line 2165 "reflect_impl.h2"
    auto lookahead_token::add_groups(std::set<int>& groups) const -> void{
        (*cpp2::impl::assert_not_null(inner)).add_groups(groups);
    }

    lookahead_token::~lookahead_token() noexcept{}

#line 2173 "reflect_impl.h2"
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

#line 2201 "reflect_impl.h2"
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

#line 2238 "reflect_impl.h2"
    range_token::range_token()
                             : regex_token{ "" }{}

#line 2240 "reflect_impl.h2"
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

#line 2313 "reflect_impl.h2"
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

#line 2325 "reflect_impl.h2"
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

#line 2338 "reflect_impl.h2"
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

#line 2357 "reflect_impl.h2"
    auto range_token::generate_code(generation_context& ctx) const -> void
    {
        auto inner_name {ctx.generate_func(inner_token)}; 
        std::set<int> groups {}; 
        (*cpp2::impl::assert_not_null(inner_token)).add_groups(groups);
        auto reset_name {ctx.generate_reset(cpp2::move(groups))}; 

        auto next_name {ctx.next_func_name()}; 
        ctx.add_statefull(next_name, "cpp2::regex::range_token_matcher<char, " + cpp2::to_string(min_count) + ", " + cpp2::to_string(max_count) + ", " + cpp2::to_string(kind) + ">::match(" + cpp2::to_string(ctx.match_parameters()) + ", " + cpp2::to_string(cpp2::move(inner_name)) + ", " + cpp2::to_string(cpp2::move(reset_name)) + ", other, " + cpp2::to_string(next_name) + ")");
    }

#line 2368 "reflect_impl.h2"
    auto range_token::add_groups(std::set<int>& groups) const -> void{
        (*cpp2::impl::assert_not_null(inner_token)).add_groups(groups);
    }

    range_token::~range_token() noexcept{}

#line 2381 "reflect_impl.h2"
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

#line 2405 "reflect_impl.h2"
        (*cpp2::impl::assert_not_null(r)).parse_modifier(ctx);

        (*cpp2::impl::assert_not_null(r)).inner_token = ctx.pop_token();
        (*cpp2::impl::assert_not_null(r)).string_rep = (*cpp2::impl::assert_not_null((*cpp2::impl::assert_not_null(r)).inner_token)).to_string() + cpp2::move(symbol) + (*cpp2::impl::assert_not_null(r)).gen_mod_string();
        return r; 
    }

    special_range_token::~special_range_token() noexcept{}

#line 2418 "reflect_impl.h2"
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

#line 2454 "reflect_impl.h2"
    template <typename Error_out> regex_generator<Error_out>::regex_generator(cpp2::impl::in<std::string_view> r, Error_out const& e)
        : regex{ r }
        , error_out{ e }{

#line 2457 "reflect_impl.h2"
    }

#line 2459 "reflect_impl.h2"
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

#line 2494 "reflect_impl.h2"
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

#line 2510 "reflect_impl.h2"
template<typename Err> [[nodiscard]] auto generate_regex(cpp2::impl::in<std::string_view> regex, Err const& err) -> std::string
{
    regex_generator<Err> parser {regex, err}; 
    auto r {parser.parse()}; 
    static_cast<void>(cpp2::move(parser));
    return r; 
}

#line 2520 "reflect_impl.h2"
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
            CPP2_UFCS(add_member)(t, "public " + cpp2::to_string(expr.first) + "_matcher: type = " + cpp2::to_string(cpp2::move(regular_expression)) + "");
            CPP2_UFCS(add_member)(t, "public " + cpp2::to_string(expr.first) + ": cpp2::regex::regular_expression<char, " + cpp2::to_string(expr.first) + "_matcher> = ();");
        }
    }

    CPP2_UFCS(add_runtime_support_include)(t, "cpp2regex.h");
}

#line 2579 "reflect_impl.h2"
[[nodiscard]] auto apply_metafunctions(
    declaration_node& n, 
    type_declaration& rtype, 
    auto const& error, 
    auto const& lookup
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
        else {if (name == "regex") {
            regex_gen(rtype);
        }
        else {if (name == "dll_visible") {
            dll_visible(rtype);
        }
        else {
{
auto const& load{load_metafunction(name, lookup)};

#line 2681 "reflect_impl.h2"
            if (CPP2_UFCS(is_value)(load)) {
                CPP2_UFCS(value)(load)(rtype);
            }else {
                error("unrecognized metafunction name: " + name);
                if (CPP2_UFCS(find)(name, "::") == name.npos) {
                    error(
                        "(temporary alpha limitation) currently the supported names are: "
                        "interface, polymorphic_base, ordered, weakly_ordered, partially_ordered, "
                        "copyable, basic_value, value, weakly_ordered_value, partially_ordered_value, "
                        "struct, enum, flag_enum, union, cpp1_rule_of_zero, regex, dll_visible, print"
                    );
                }
                if (!(CPP2_UFCS(empty)(CPP2_UFCS(error)(load).value))) {
                    error(CPP2_UFCS(error)(load).value);
                }
                return false; 
            }
}
#line 2698 "reflect_impl.h2"
        }}}}}}}}}}}}}}}}}}}
    }

    return true; 
}

#line 2704 "reflect_impl.h2"
[[nodiscard]] auto apply_metafunctions(
    declaration_node& n, 
    function_declaration& rfunction, 
    auto const& error
    ) -> bool

{
    if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(is_function)(n)) ) { cpp2::cpp2_default.report_violation(""); }

    //  For each metafunction, apply it
    for ( 
         auto const& meta : n.metafunctions ) 
    {
        //  Convert the name and any template arguments to strings
        //  and record that in rfunction
        auto name {CPP2_UFCS(to_string)((*cpp2::impl::assert_not_null(meta)))}; 
        name = CPP2_UFCS(substr)(name, 0, CPP2_UFCS(find)(name, '<'));

        std::vector<std::string> args {}; 
        for ( 
             auto const& arg : CPP2_UFCS(template_arguments)((*cpp2::impl::assert_not_null(meta))) ) 
            CPP2_UFCS(push_back)(args, CPP2_UFCS(to_string)(arg));

        CPP2_UFCS(set_metafunction_name)(rfunction, name, cpp2::move(args));

        //  Dispatch
        //
        if (name == "dll_visible") {
            dll_visible(rfunction);
        }
        else {
            error("unrecognized metafunction name: " + cpp2::move(name));
            error("(temporary alpha limitation) currently the supported names are: dll_visible ");
            return false; 
        }
    }

    return true; 
}

#line 2745 "reflect_impl.h2"
}

}

#endif
