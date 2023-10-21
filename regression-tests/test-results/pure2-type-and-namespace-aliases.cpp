
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"


#line 2 "pure2-type-and-namespace-aliases.cpp2"
namespace N {

}

#line 8 "pure2-type-and-namespace-aliases.cpp2"
class myclass;
    

//=== Cpp2 type definitions and function declarations ===========================


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
#line 13 "pure2-type-and-namespace-aliases.cpp2"
};

namespace N3 = ::std::literals;

auto myfunc() -> void;
    

#line 26 "pure2-type-and-namespace-aliases.cpp2"
auto main() -> int;
    

//=== Cpp2 function definitions =================================================


#line 2 "pure2-type-and-namespace-aliases.cpp2"
namespace N {

}

#line 17 "pure2-type-and-namespace-aliases.cpp2"
auto myfunc() -> void{
    N1::pmr_vec<myclass::str> v {"xyzzy", "plugh"}; 

    auto const& v2 = std::move(v);

    for ( auto const& s : v2 ) 
        std::cout << cpp2::to_string(s) + "\n";
}

auto main() -> int{
    using view = std::string_view;
    namespace N4 = std::literals;

    auto const& myfunc2 = myfunc;
    myfunc2();
}

