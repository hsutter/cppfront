
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-type-and-namespace-aliases.cpp2"

#line 2 "pure2-type-and-namespace-aliases.cpp2"
namespace N {

}

#line 8 "pure2-type-and-namespace-aliases.cpp2"
class myclass;
    

#line 25 "pure2-type-and-namespace-aliases.cpp2"
template<typename T> class myclass2;
    

#line 39 "pure2-type-and-namespace-aliases.cpp2"
class myclass3;
    

#line 53 "pure2-type-and-namespace-aliases.cpp2"
class myclass4;

template<typename T> class myclass6;
    

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-type-and-namespace-aliases.cpp2"

#line 2 "pure2-type-and-namespace-aliases.cpp2"
namespace N {
    template<typename T> using pmr_vec = std::vector<T,std::pmr::polymorphic_allocator<T>>;
}

namespace N1 = N;

class myclass {
    //  Default to public
    public: using str = std::string;

    private: using str2 = std::string;

    public: myclass() = default;
    public: myclass(myclass const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(myclass const&) -> void = delete;
};
#line 14 "pure2-type-and-namespace-aliases.cpp2"

namespace N3 = ::std::literals;

auto myfunc() -> void;

#line 25 "pure2-type-and-namespace-aliases.cpp2"
template<typename T> class myclass2 {
    public: static const int value;

    public: myclass2() = default;
    public: myclass2(myclass2 const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(myclass2 const&) -> void = delete;
};
#line 28 "pure2-type-and-namespace-aliases.cpp2"

auto main() -> int;

#line 37 "pure2-type-and-namespace-aliases.cpp2"
using myclass5 = myclass4;

class myclass3 {
    // Defined inline.
    public: static constexpr auto i0 = std::array{0};
    public: static constexpr auto i1 = i0;
    public: static constexpr auto i3 = i0;
    public: static constexpr auto i7 = []() -> decltype(auto) { return 0; };

    // Defined out of line.
    public: static const myclass3 o2;
    public: static const myclass3 o4;
    public: static const myclass4 o5;
    public: static const myclass5 o6;
};

class myclass4 {};

template<typename T> class myclass6 {
#line 56 "pure2-type-and-namespace-aliases.cpp2"
    public: template<typename U> 
CPP2_REQUIRES_ (true) static constexpr auto v = 0;
};

//=== Cpp2 function definitions =================================================

#line 1 "pure2-type-and-namespace-aliases.cpp2"

#line 2 "pure2-type-and-namespace-aliases.cpp2"
namespace N {

}

#line 17 "pure2-type-and-namespace-aliases.cpp2"
auto myfunc() -> void{
    N1::pmr_vec<myclass::str> v {"xyzzy", "plugh"}; 
{
auto const& v2{cpp2::move(v)};

#line 21 "pure2-type-and-namespace-aliases.cpp2"
    for ( auto const& s : v2 ) 
        std::cout << "" + cpp2::to_string(s) + "\n";
}
#line 23 "pure2-type-and-namespace-aliases.cpp2"
}

#line 26 "pure2-type-and-namespace-aliases.cpp2"
    template <typename T> inline CPP2_CONSTEXPR int myclass2<T>::value{ 42 };

#line 29 "pure2-type-and-namespace-aliases.cpp2"
auto main() -> int{
    using view = std::string_view;
    namespace N4 = std::literals;

    auto constexpr myfunc2{ myfunc };
    myfunc2();
}

#line 47 "pure2-type-and-namespace-aliases.cpp2"
    inline CPP2_CONSTEXPR myclass3 myclass3::o2{ myclass3() };
    inline CPP2_CONSTEXPR myclass3 myclass3::o4{ o2 };
    inline CPP2_CONSTEXPR myclass4 myclass3::o5{ myclass4() };
    inline CPP2_CONSTEXPR myclass5 myclass3::o6{ myclass5() };

