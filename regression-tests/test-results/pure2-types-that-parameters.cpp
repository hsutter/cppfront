
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"


#line 2 "pure2-types-that-parameters.cpp2"
class myclass;


//=== Cpp2 type definitions and function declarations ===========================


#line 2 "pure2-types-that-parameters.cpp2"
class myclass {

    public: explicit myclass();

    public: myclass(myclass const& that);
        
#line 6 "pure2-types-that-parameters.cpp2"
    public: auto operator=(myclass const& that) -> myclass& ;
        

#line 11 "pure2-types-that-parameters.cpp2"
    public: myclass(myclass&& that) noexcept
#line 11 "pure2-types-that-parameters.cpp2"
    ;
        
#line 11 "pure2-types-that-parameters.cpp2"
    public: auto operator=(myclass&& that) noexcept
#line 11 "pure2-types-that-parameters.cpp2"
     -> myclass& ;
        

#line 16 "pure2-types-that-parameters.cpp2"
    public: auto print() const -> void;
        

#line 20 "pure2-types-that-parameters.cpp2"
    private: std::string name {"Henry"}; 
    private: std::string addr {"123 Ford Dr."}; 

};

auto main() -> int;
    

//=== Cpp2 function definitions =================================================


#line 4 "pure2-types-that-parameters.cpp2"
    myclass::myclass(){}

    myclass::myclass(myclass const& that)
        : name{ that.name }
        , addr{ that.addr }
#line 6 "pure2-types-that-parameters.cpp2"
    {

#line 9 "pure2-types-that-parameters.cpp2"
    }
#line 6 "pure2-types-that-parameters.cpp2"
    auto myclass::operator=(myclass const& that) -> myclass& {
        name = that.name;
        addr = that.addr;
        return *this;

#line 9 "pure2-types-that-parameters.cpp2"
    }

    myclass::myclass(myclass&& that) noexcept
#line 11 "pure2-types-that-parameters.cpp2"
    
        : name{ std::move(that).name }
        , addr{ std::move(that).addr }
#line 11 "pure2-types-that-parameters.cpp2"
    {

#line 14 "pure2-types-that-parameters.cpp2"
    }
#line 11 "pure2-types-that-parameters.cpp2"
    auto myclass::operator=(myclass&& that) noexcept
#line 11 "pure2-types-that-parameters.cpp2"
     -> myclass& {
        name = std::move(that).name;
        addr = std::move(that).addr;
        return *this;

#line 14 "pure2-types-that-parameters.cpp2"
    }

    auto myclass::print() const -> void{
        std::cout << "name '" + cpp2::to_string(name) + "', addr '" + cpp2::to_string(addr) + "'\n";
    }

#line 25 "pure2-types-that-parameters.cpp2"
auto main() -> int{
    myclass x {}; 
    CPP2_UFCS_0(print, x);

    std::cout << "-----\n";
    auto y {x}; 
    CPP2_UFCS_0(print, x);
    CPP2_UFCS_0(print, std::move(y));

    std::cout << "-----\n";
    auto z {std::move(x)}; 
    CPP2_UFCS_0(print, std::move(x));
    CPP2_UFCS_0(print, std::move(z));
}

