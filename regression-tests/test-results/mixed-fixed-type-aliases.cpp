

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-fixed-type-aliases.cpp2"

#line 15 "mixed-fixed-type-aliases.cpp2"
template<typename T> class mytype;
    

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-fixed-type-aliases.cpp2"
#include <filesystem>
#include <iostream>
#include <typeinfo>

namespace my {
    using u16 = float;
}

#line 9 "mixed-fixed-type-aliases.cpp2"
auto test(auto const& x) -> void;

#line 15 "mixed-fixed-type-aliases.cpp2"
template<typename T> class mytype {
    public: template<typename U> static const bool myvalue;
};

[[nodiscard]] auto main(int const argc_, char** argv_) -> int;

//=== Cpp2 function definitions =================================================

#line 1 "mixed-fixed-type-aliases.cpp2"

#line 9 "mixed-fixed-type-aliases.cpp2"
auto test(auto const& x) -> void{
    std::cout 
        << cpp2::impl::as_<std::string>(std::is_floating_point_v<CPP2_TYPEOF(x)>) 
        << "\n";
}

#line 16 "mixed-fixed-type-aliases.cpp2"
    template <typename T> template<typename U> inline CPP2_CONSTEXPR bool mytype<T>::myvalue{ true };

#line 19 "mixed-fixed-type-aliases.cpp2"
[[nodiscard]] auto main(int const argc_, char** argv_) -> int{
    auto const args = cpp2::make_args(argc_, argv_); 
#line 20 "mixed-fixed-type-aliases.cpp2"
    my::u16 y {42}; 
    test(cpp2::move(y));

    cpp2::u16 z {42}; 
    test(cpp2::move(z));

    for ( auto const& arg : args ) 
        std::cout << CPP2_UFCS(filename)(std::filesystem::path(arg)) << "\n";

    std::cout << (cpp2::to_string(mytype<int>::myvalue<int>) + "\n");
}

