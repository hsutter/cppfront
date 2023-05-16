
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"


#line 2 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
class myclass;


//=== Cpp2 type definitions and function declarations ===========================


#line 2 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
class myclass {

    public: myclass(myclass const& that);
        
#line 4 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
    public: auto operator=(myclass const& that) -> myclass& ;
        
#line 4 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
    public: myclass(myclass&& that) noexcept
#line 4 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
    ;
        
#line 4 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
    public: auto operator=(myclass&& that) noexcept
#line 4 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
     -> myclass& ;
        

#line 8 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
    // operator=: (out this, move that) = {
    //     name = that.name + "(CM)";
    //     std::cout << "ctor - move          ";
    // }

    // operator=: (inout this,  that) = {
    //     addr = that.addr + "(AC)";
    //     std::cout << "assign - copy        ";
    // }

    // operator=: (inout this, move that) = {
    //     std::cout << "assign - move        ";
    // }

    public: explicit myclass(cpp2::in<std::string> x);
        
#line 22 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
    public: auto operator=(cpp2::in<std::string> x) -> myclass& ;
        

#line 27 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
    private: std::string name {"Henry"}; 
    private: std::string addr {"123 Ford Dr."}; 

    public: auto print(

        cpp2::in<std::string_view> prefix, 
        cpp2::in<std::string_view> suffix
        ) const -> void;

#line 37 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
};

auto main() -> int;
    

//=== Cpp2 function definitions =================================================


#line 4 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
    myclass::myclass(myclass const& that)
        : name{ that.name }
        , addr{ that.addr }
#line 4 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
    {
        std::cout << "ctor - copy (GENERAL)";
    }
#line 4 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
    auto myclass::operator=(myclass const& that) -> myclass& {
        name = that.name;
        addr = that.addr;
#line 5 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
        std::cout << "ctor - copy (GENERAL)";
        return *this;
#line 6 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
    }
#line 4 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
    myclass::myclass(myclass&& that) noexcept
#line 4 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
    
        : name{ std::move(that).name }
        , addr{ std::move(that).addr }
#line 4 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
    {
        std::cout << "ctor - copy (GENERAL)";
    }
#line 4 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
    auto myclass::operator=(myclass&& that) noexcept
#line 4 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
     -> myclass& {
        name = std::move(that).name;
        addr = std::move(that).addr;
#line 5 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
        std::cout << "ctor - copy (GENERAL)";
        return *this;
#line 6 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
    }

#line 22 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
    myclass::myclass(cpp2::in<std::string> x)
        : name{ x }
#line 22 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
    {

        std::cout << "ctor - from string   ";
    }
#line 22 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
    auto myclass::operator=(cpp2::in<std::string> x) -> myclass& {
        name = x;
        addr = "123 Ford Dr.";

#line 24 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
        std::cout << "ctor - from string   ";
        return *this;
#line 25 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
    }

#line 30 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
    auto myclass::print(

        cpp2::in<std::string_view> prefix, 
        cpp2::in<std::string_view> suffix
        ) const -> void { 
    std::cout << prefix << "[ " + cpp2::to_string(name) + " | " + cpp2::to_string(addr) + " ]" << suffix;  }

#line 39 "pure2-types-smf-and-that-5-provide-nothing-but-general-case.cpp2"
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

