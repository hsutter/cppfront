
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-default-arguments.cpp2"

#line 30 "pure2-default-arguments.cpp2"
template<typename T = int, int N = 42> class myclass;
    

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-default-arguments.cpp2"

//  Note: Using source_location requires GCC 11 or higher,
//        Clang 16 or higher, MSVC 2019 16.10 or higher.
//        Older compilers will emit failures for this test case.
#line 5 "pure2-default-arguments.cpp2"
auto my_function_name(
    char const* fn = CPP2_UFCS_NONLOCAL(function_name)(std::source_location::current())
    ) -> void;

#line 12 "pure2-default-arguments.cpp2"
auto f(cpp2::impl::in<cpp2::i32> x = 0) -> void;

template
    <
        typename AssocContainer, 
        typename Func = std::plus<>
    > auto combine_maps
    (
        AssocContainer& map1, 
              AssocContainer const& map2, 
              Func const& func = {}
    ) -> void;

#line 30 "pure2-default-arguments.cpp2"
template<typename T, int N> class myclass {
    public: template<typename TT = int, int NN = 42> static auto memfunc(cpp2::impl::in<int> MM = 43) -> void;
    public: myclass() = default;
    public: myclass(myclass const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(myclass const&) -> void = delete;

#line 32 "pure2-default-arguments.cpp2"
};
template <typename T = int, int N  = 42> auto myfunc(cpp2::impl::in<int> M = 43) -> void;

#line 38 "pure2-default-arguments.cpp2"
auto main(int const argc_, char** argv_) -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-default-arguments.cpp2"

#line 5 "pure2-default-arguments.cpp2"
auto my_function_name(
    char const* fn
    ) -> void
{
    std::cout << "calling: " + cpp2::to_string(fn) + "\n";
}

#line 12 "pure2-default-arguments.cpp2"
auto f(cpp2::impl::in<cpp2::i32> x) -> void{std::cout << x; }

#line 14 "pure2-default-arguments.cpp2"
template
    <
        typename AssocContainer, 
        typename Func
    > auto combine_maps
    (
        AssocContainer& map1, 
              AssocContainer const& map2, 
              Func const& func
    ) -> void
{
    for ( auto const& kv : map2 ) {
        CPP2_ASSERT_IN_BOUNDS(map1, kv.first) = func(CPP2_ASSERT_IN_BOUNDS(map1, kv.first), kv.second);
    }
}

#line 31 "pure2-default-arguments.cpp2"
    template <typename T, int N> template<typename TT, int NN> auto myclass<T,N>::memfunc(cpp2::impl::in<int> MM) -> void{static_cast<void>(MM); }

#line 33 "pure2-default-arguments.cpp2"
template <typename T,       int N> auto myfunc(cpp2::impl::in<int> M) -> void{
    static_cast<void>(M);
    []<typename TT = int, int NN = 42>(cpp2::impl::in<int> MM = 43) -> void{static_cast<void>(MM); };
}

#line 38 "pure2-default-arguments.cpp2"
auto main(int const argc_, char** argv_) -> int{
    auto const args = cpp2::make_args(argc_, argv_); 
#line 39 "pure2-default-arguments.cpp2"
    my_function_name();
    f();
    f(1);
    f(2);

    []<bool V = gcc_clang_msvc_min_versions(1400, 1600, 1920)>() -> void{
        if constexpr (V) {
            std::cout << "\na newer compiler\n";
        }
        else {
            std::cout << "\nan older compiler\n";
        }
    }();

    std::map<int,int> m1 {}; 
    CPP2_ASSERT_IN_BOUNDS_LITERAL(m1, 1) = 11;

    std::map<int,int> m2 {}; 
    CPP2_ASSERT_IN_BOUNDS_LITERAL(m2, 1) = 22;

    combine_maps(m1, m2, [](auto const& x, auto const& y) -> decltype(auto) { return x + y + 33;  });

    std::cout << "" + cpp2::to_string(CPP2_UFCS(size)(m1)) + ", " + cpp2::to_string(CPP2_UFCS(size)(cpp2::move(m2))) + ", " + cpp2::to_string(CPP2_ASSERT_IN_BOUNDS_LITERAL(m1, 1)) + "\n";
}

