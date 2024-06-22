
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
        std::cout << (cpp2::to_string(s) + "\n");
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

