

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"

#line 2 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
class myclass;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"

#line 2 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
class myclass {

    public: myclass(myclass const& that);

#line 8 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    public: myclass(myclass&& that) noexcept;

#line 13 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    // operator=: (inout this,  that) = {
    //     addr = that.addr + "(AC)";
    //     std::cout << "assign - copy        ";
    // }

    public: auto operator=(myclass&& that) noexcept -> myclass& ;

#line 22 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    public: myclass(cpp2::impl::in<std::string> x);
#line 22 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    public: auto operator=(cpp2::impl::in<std::string> x) -> myclass& ;

#line 27 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    private: std::string name {"Henry"}; 
    private: std::string addr {"123 Ford Dr."}; 

    public: auto print(

        cpp2::impl::in<std::string_view> prefix, 
        cpp2::impl::in<std::string_view> suffix
        ) const& -> void;

#line 39 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
};

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"

#line 4 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    myclass::myclass(myclass const& that)
        : name{ that.name }
        , addr{ that.addr }{
#line 5 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
        std::cout << "ctor - copy (GENERAL)";
    }

#line 8 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    myclass::myclass(myclass&& that) noexcept
        : name{ cpp2::move(that).name + "(CM)" }
        , addr{ std::move(that).addr }{

#line 10 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
        std::cout << "ctor - move          ";
    }

#line 18 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    auto myclass::operator=(myclass&& that) noexcept -> myclass& {
        name = std::move(that).name;
        addr = std::move(that).addr;
#line 19 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
        std::cout << "assign - move        ";
        return *this;
#line 20 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    }

#line 22 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    myclass::myclass(cpp2::impl::in<std::string> x)
        : name{ x }{

#line 24 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
        std::cout << "ctor - from string   ";
    }
#line 22 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    auto myclass::operator=(cpp2::impl::in<std::string> x) -> myclass& {
        name = x;
        addr = "123 Ford Dr.";

#line 24 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
        std::cout << "ctor - from string   ";
        return *this;
#line 25 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    }

#line 30 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
    auto myclass::print(

        cpp2::impl::in<std::string_view> prefix, 
        cpp2::impl::in<std::string_view> suffix
        ) const& -> void
    {
        std::cout << prefix << "[ " + cpp2::to_string(name) + " | " + cpp2::to_string(addr) + " ]" << suffix;
    }

#line 41 "regression-tests/pure2-types-smf-and-that-3-provide-mvconstruct-and-mvassign.cpp2"
auto main() -> int{
    std::cout << "Function invoked        Call syntax   Results\n";
    std::cout << "----------------------  ------------  ------------------------------------------------------\n";

    myclass x {"Henry"}; 
    CPP2_UFCS(print)(x, "   construct     ", "\n");
    x = "Clara";
    CPP2_UFCS(print)(x, "   assign        ", "\n");

    auto y {x}; 
    CPP2_UFCS(print)(y, "   cp-construct  ", " <- ");
    CPP2_UFCS(print)(x, "", "\n");

    auto z {std::move(x)}; 
    CPP2_UFCS(print)(z, "   mv-construct  ", " <- ");
    CPP2_UFCS(print)(cpp2::move(x), "", "\n");

    // z = y;
    // z.print("   cp-assign     ", " <- ");
    // y.print("", "\n");

    z = { std::move(y) };
    CPP2_UFCS(print)(cpp2::move(z), "   mv-assign     ", " <- ");
    CPP2_UFCS(print)(cpp2::move(y), "", "\n");
}

