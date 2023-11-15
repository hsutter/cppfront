
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-variadics.cpp2"

#line 3 "pure2-variadics.cpp2"
template<typename ...Ts> class x;
    

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-variadics.cpp2"

//  Type pack expansion
#line 3 "pure2-variadics.cpp2"
template<typename ...Ts> class x {
    private: std::tuple<Ts...> tup {}; 
    public: x() = default;
    public: x(x const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(x const&) -> void = delete;

#line 5 "pure2-variadics.cpp2"
};

template<typename ...Args> auto left_fold_print(std::ostream& out, Args const& ...args) -> void;

#line 12 "pure2-variadics.cpp2"
template<typename ...Args> [[nodiscard]] auto all(Args const& ...args) -> bool;

#line 16 "pure2-variadics.cpp2"
template     <typename ...Args> [[nodiscard]] auto make_string(Args&& ...args) -> auto;

template  <typename T, typename ...Args> [[nodiscard]] auto make(Args&& ...args) -> auto;

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-variadics.cpp2"

#line 7 "pure2-variadics.cpp2"
template<typename ...Args> auto left_fold_print(std::ostream& out, Args const& ...args) -> void{
    //  Binary left fold expression
    (out << ... << args);
}

template<typename ...Args> [[nodiscard]] auto all(Args const& ...args) -> bool { 
    //  Unary left fold expression
    return (... && args);  }

template     <typename ...Args> [[nodiscard]] auto make_string(Args&& ...args) -> auto { return std::string{CPP2_FORWARD(args)...}; }

template  <typename T, typename ...Args> [[nodiscard]] auto make(Args&& ...args) -> auto { return T{CPP2_FORWARD(args)...}; }

auto main() -> int
{
    x<int,long,std::string> auto_22_5 {}; 

    std::cout << std::string("xyzzy", 3) << "\n";
    std::cout << make_string("plugh", cpp2::u8{3}) << "\n";
    std::cout << make<std::string>("abracadabra", cpp2::u8{3}) << "\n";

    left_fold_print(std::cout, 3.14, "word", -1500);

    std::cout << "\nfirst all() returned " + cpp2::to_string(all(true, true, true, false));
    std::cout << "\nsecond all() returned " << cpp2::as_<std::string>(all(true, true, true, true));
}

