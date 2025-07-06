
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-types-that-parameters.cpp2"

#line 2 "pure2-types-that-parameters.cpp2"
class myclass;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-types-that-parameters.cpp2"

#line 2 "pure2-types-that-parameters.cpp2"
class myclass {

    public: explicit myclass();

    public: myclass(myclass const& that);

#line 11 "pure2-types-that-parameters.cpp2"
    public: myclass(myclass&& that) noexcept;

#line 16 "pure2-types-that-parameters.cpp2"
    public: auto print() const& -> void;

#line 20 "pure2-types-that-parameters.cpp2"
    private: std::string name {"Henry"}; 
    private: std::string addr {"123 Ford Dr."}; 

};

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-types-that-parameters.cpp2"

#line 4 "pure2-types-that-parameters.cpp2"
    myclass::myclass(){}

#line 6 "pure2-types-that-parameters.cpp2"
    myclass::myclass(myclass const& that)
        : name{ that.name }
        , addr{ that.addr }{

#line 9 "pure2-types-that-parameters.cpp2"
    }

#line 11 "pure2-types-that-parameters.cpp2"
    myclass::myclass(myclass&& that) noexcept
        : name{ cpp2::move(that).name }
        , addr{ cpp2::move(that).addr }{

#line 14 "pure2-types-that-parameters.cpp2"
    }

#line 16 "pure2-types-that-parameters.cpp2"
    auto myclass::print() const& -> void{
        std::cout << "name '" + cpp2::to_string(name) + "', addr '" + cpp2::to_string(addr) + "'\n";
    }

#line 25 "pure2-types-that-parameters.cpp2"
auto main() -> int{
    myclass x {}; 
    CPP2_UFCS(print)(x);

    std::cout << "-----\n";
    auto y {x}; 
    CPP2_UFCS(print)(x);
    CPP2_UFCS(print)(cpp2::move(y));

    std::cout << "-----\n";
    auto z {std::move(x)}; 
    CPP2_UFCS(print)(cpp2::move(x));
    CPP2_UFCS(print)(cpp2::move(z));
}

