

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-parameter-passing.cpp2"

#line 43 "mixed-parameter-passing.cpp2"
template<typename T> class container;
    

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-parameter-passing.cpp2"

#include <string>
#include <cstdlib>
#include <ctime>

#line 6 "mixed-parameter-passing.cpp2"
auto copy_from([[maybe_unused]] auto unnamed_param_1) -> void;

auto parameter_styles(
    [[maybe_unused]] cpp2::impl::in<std::string> unnamed_param_1, // "in" is default
    std::string b, 
    [[maybe_unused]] std::string& unnamed_param_3, 
    std::string&& d
    ) -> void;

#line 40 "mixed-parameter-passing.cpp2"
[[nodiscard]] auto min(auto const& a, auto const& b) -> auto&&;

#line 43 "mixed-parameter-passing.cpp2"
template<typename T> class container {
    private: std::array<T,10> buf {}; 
    public: [[nodiscard]] auto operator[](cpp2::impl::in<cpp2::i32> idx) const& -> T const&;
    public: [[nodiscard]] auto operator[](cpp2::impl::in<cpp2::i32> idx) & -> T&;
    public: container() = default;
    public: container(container const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(container const&) -> void = delete;

#line 47 "mixed-parameter-passing.cpp2"
};

auto main() -> int;
#line 57 "mixed-parameter-passing.cpp2"

#line 1 "mixed-parameter-passing.cpp2"

//=== Cpp2 function definitions =================================================

#line 1 "mixed-parameter-passing.cpp2"

#line 6 "mixed-parameter-passing.cpp2"
auto copy_from([[maybe_unused]] auto unnamed_param_1) -> void{}

#line 8 "mixed-parameter-passing.cpp2"
auto parameter_styles(
    [[maybe_unused]] cpp2::impl::in<std::string> unnamed_param_1, 
    std::string b, 
    [[maybe_unused]] std::string& unnamed_param_3, 
    std::string&& d
    ) -> void
{
    int z {12}; 

    ++z;
    b += "plugh";

    if (std::rand() % 2) {
        ++z;
        copy_from(cpp2::move(b));// definite last use
    }
    else {
        copy_from(&b);  // NB: better not move from this (why not?)
        copy_from(cpp2::move(d));
        copy_from(++z);
    }

    // std::move(z);

    copy_from(z);

    if (std::time(nullptr) % 2 == 0) {
        copy_from(cpp2::move(z));
    }

}

#line 40 "mixed-parameter-passing.cpp2"
[[nodiscard]] auto min(auto const& a, auto const& b) -> auto&&
    {if (cpp2::impl::cmp_less(b,a)) {return b; }else {return a; }}

#line 45 "mixed-parameter-passing.cpp2"
    template <typename T> [[nodiscard]] auto container<T>::operator[](cpp2::impl::in<cpp2::i32> idx) const& -> T const& { return CPP2_ASSERT_IN_BOUNDS(buf, idx); }
#line 46 "mixed-parameter-passing.cpp2"
    template <typename T> [[nodiscard]] auto container<T>::operator[](cpp2::impl::in<cpp2::i32> idx) & -> T& { return CPP2_ASSERT_IN_BOUNDS(buf, idx);  }

#line 49 "mixed-parameter-passing.cpp2"
auto main() -> int{
    auto x {456}; 
    auto y {123}; 
    std::cout << min(cpp2::move(x), cpp2::move(y)) << '\n';

    container<int> v {}; 
    std::cout << CPP2_ASSERT_IN_BOUNDS_LITERAL(cpp2::move(v), 0) << '\n';
}

