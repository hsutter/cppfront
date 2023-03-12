
#define CPP2_USE_MODULES         Yes

#include "cpp2util.h"


#line 2 "pure2-types-that-parameters.cpp2"
class myclass;
#line 25 "pure2-types-that-parameters.cpp2"
auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-types-that-parameters.cpp2"

class myclass   {

    public: myclass()         
                              : name{ "Henry" }
                              , addr{ "123 Ford Dr." }
#line 5 "pure2-types-that-parameters.cpp2"
{}
    public: explicit myclass(myclass const& that)
        : name{ that.name }
        , addr{ that.addr }
#line 7 "pure2-types-that-parameters.cpp2"
{

    }public: auto operator=(myclass const& that) -> void{name = that.name;addr = that.addr;}

    public: explicit myclass(myclass&& that)
        : name{ std::move(that).name }
        , addr{ std::move(that).addr }
#line 12 "pure2-types-that-parameters.cpp2"
{

    }public: auto operator=(myclass&& that) -> void{name = std::move(that).name;addr = std::move(that).addr;}

    public: auto print() const -> void{
        std::cout << "name '" + cpp2::to_string(name) + "', addr '" + cpp2::to_string(addr) + "'\n";
    }

    private: std::string name {"Henry"}; 
    private: std::string addr {"123 Ford Dr."}; 

};

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

