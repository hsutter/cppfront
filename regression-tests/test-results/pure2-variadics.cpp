
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"


#line 2 "pure2-variadics.cpp2"
template<typename ...Ts> class x;
    

//=== Cpp2 type definitions and function declarations ===========================


#line 2 "pure2-variadics.cpp2"
template<typename ...Ts> class x {
    private: std::tuple<Ts...> tup {}; 
    public: x() = default;
    public: x(x const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(x const&) -> void = delete;

#line 4 "pure2-variadics.cpp2"
};

template<typename ...Args> [[nodiscard]] auto make_string(Args&& ...args) -> auto;

template<typename T, typename ...Args> [[nodiscard]] auto make(Args&& ...args) -> auto;

auto main() -> int;


//=== Cpp2 function definitions =================================================


#line 6 "pure2-variadics.cpp2"
template<typename ...Args> [[nodiscard]] auto make_string(Args&& ...args) -> auto { return std::string{CPP2_FORWARD(args)...};  }

template<typename T, typename ...Args> [[nodiscard]] auto make(Args&& ...args) -> auto { return T{CPP2_FORWARD(args)...};  }

auto main() -> int
{
    x<int,long,std::string> a {}; 

    std::cout << std::string("xyzzy", 3) << "\n";
    std::cout << make_string("plugh", cpp2::u8{3}) << "\n";
    std::cout << make<std::string>("abracadabra", cpp2::u8{3}) << "\n";
}

