
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"


#line 2 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
class myclass;


//=== Cpp2 type definitions and function declarations ===========================


#line 2 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
class myclass {

    public: myclass(myclass const& that);
        
#line 4 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    public: auto operator=(myclass const& that) -> myclass& ;
        

#line 9 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    public: myclass(myclass&& that) noexcept;
        

#line 15 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    // operator=: (inout this,  that) = {
    //     this = that;
    //     addr = that.addr + "(AC)";
    //     std::cout << "assign - copy        ";
    // }

    public: auto operator=(myclass&& that) noexcept -> myclass& ;
        

#line 26 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    public: explicit myclass(cpp2::in<std::string> x);
        
#line 26 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    public: auto operator=(cpp2::in<std::string> x) -> myclass& ;
        

#line 31 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    private: std::string name {"Henry"}; 
    private: std::string addr {"123 Ford Dr."}; 

    public: auto print(

        cpp2::in<std::string_view> prefix, 
        cpp2::in<std::string_view> suffix
        ) const -> void;

#line 41 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
};

auto main() -> int;
    

//=== Cpp2 function definitions =================================================


#line 4 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    myclass::myclass(myclass const& that)
        : name{ that.name }
        , addr{ that.addr }
#line 4 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    {

        std::cout << "ctor - copy (GENERAL)";
    }
#line 4 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    auto myclass::operator=(myclass const& that) -> myclass& {
        name = that.name;
        addr = that.addr;

#line 6 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
        std::cout << "ctor - copy (GENERAL)";
        return *this;
#line 7 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    }

    myclass::myclass(myclass&& that) noexcept
        : name{ std::move(that).name + "(CM)" }
        , addr{ std::move(that).addr }
#line 9 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    {

#line 12 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
        std::cout << "ctor - move          ";
    }

#line 21 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    auto myclass::operator=(myclass&& that) noexcept -> myclass& {
        name = std::move(that).name;
        addr = std::move(that).addr;

#line 23 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
        std::cout << "assign - move        ";
        return *this;
#line 24 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    }

    myclass::myclass(cpp2::in<std::string> x)
        : name{ x }
#line 26 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    {

        std::cout << "ctor - from string   ";
    }
#line 26 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    auto myclass::operator=(cpp2::in<std::string> x) -> myclass& {
        name = x;
        addr = "123 Ford Dr.";

#line 28 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
        std::cout << "ctor - from string   ";
        return *this;
#line 29 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    }

#line 34 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    auto myclass::print(

        cpp2::in<std::string_view> prefix, 
        cpp2::in<std::string_view> suffix
        ) const -> void { 
    std::cout << prefix << "[ " + cpp2::to_string(name) + " | " + cpp2::to_string(addr) + " ]" << suffix;  }

#line 43 "pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
auto main() -> int{
    std::cout << "Function invoked        Call syntax   Results\n";
    std::cout << "----------------------  ------------  ------------------------------------------------------\n";

    myclass x {"Henry"}; 
    CPP2_UFCS(print, x, "   construct     ", "\n");
    x = "Clara";
    CPP2_UFCS(print, x, "   assign        ", "\n");

    auto y {x}; 
    CPP2_UFCS(print, y, "   cp-construct  ", " <- ");
    CPP2_UFCS(print, x, "", "\n");

    auto z {std::move(x)}; 
    CPP2_UFCS(print, z, "   mv-construct  ", " <- ");
    CPP2_UFCS(print, std::move(x), "", "\n");

    z = y;
    CPP2_UFCS(print, z, "   cp-assign     ", " <- ");
    CPP2_UFCS(print, y, "", "\n");

    z = std::move(y);
    CPP2_UFCS(print, std::move(z), "   mv-assign     ", " <- ");
    CPP2_UFCS(print, std::move(y), "", "\n");
}

