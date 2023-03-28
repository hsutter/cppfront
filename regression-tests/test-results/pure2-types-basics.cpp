
#define CPP2_USE_MODULES         Yes

#include "cpp2util.h"

#line 2 "pure2-types-basics.cpp2"
namespace N {

class myclass;

#line 60 "pure2-types-basics.cpp2"
};

auto main() -> int;

//=== Cpp2 definitions ==========================================================


#line 2 "pure2-types-basics.cpp2"
namespace N {

class myclass {

    public: myclass(cpp2::in<int> x)
        : data{ x }
#line 6 "pure2-types-basics.cpp2"
    {

        // use default initializer for this.more
        std::cout << "myclass: implicit from int\n";
        print();
    }
#line 6 "pure2-types-basics.cpp2"
    public: auto operator=(cpp2::in<int> x) -> myclass& {
        data = x;
        more = std::to_string(42 * 12);
#line 9 "pure2-types-basics.cpp2"
        std::cout << "myclass: implicit from int\n";
        print();
        return *this;
#line 11 "pure2-types-basics.cpp2"
    }

    public: explicit myclass(cpp2::in<std::string> s)
        : data{ 99 }
        , more{ s }
#line 13 "pure2-types-basics.cpp2"
    {

#line 16 "pure2-types-basics.cpp2"
        std::cout << "myclass: explicit from string\n";
        print();
    }
#line 13 "pure2-types-basics.cpp2"
    public: auto operator=(cpp2::in<std::string> s) -> myclass& {
        data = 99;
        more = s;
#line 16 "pure2-types-basics.cpp2"
        std::cout << "myclass: explicit from string\n";
        print();
        return *this;
#line 18 "pure2-types-basics.cpp2"
    }

    public: myclass(cpp2::in<int> x, cpp2::in<std::string> s)
        : data{ 77 }
        , more{ s + " plugh" }
#line 20 "pure2-types-basics.cpp2"
    {

#line 23 "pure2-types-basics.cpp2"
        std::cout << "myclass: from int and string\n";
        print();
    }

    public: myclass()
        : more{ std::to_string(3.14159) }
#line 27 "pure2-types-basics.cpp2"
    {
        // use default initializer for this.data

        std::cout << "myclass: default\n";
        print();
    }

    public: auto print() const -> void{
        std::cout << "    data: " + cpp2::to_string(data) + ", more: " + cpp2::to_string(more) + "\n";
    }

    public: ~myclass(){
        std::cout << "myclass: destructor\n";
    }

    public: virtual auto f(cpp2::in<int> x) const -> void{
        std::cout << "N::myclass::f with " + cpp2::to_string(x) + "\n";
    }

    private: int data {42 * 12}; 
    private: std::string more {std::to_string(42 * 12)}; 

    public: class nested {
        public: static auto g() -> void { std::cout << "N::myclass::nested::g\n";  }
    };

    public: template<typename T, typename U> [[nodiscard]] static auto f1(T const& t, U const& u) -> auto { return t + u; }
    public: template<typename T, typename U> [[nodiscard]] static auto f2(T const& t, U const& u) -> auto { return t + u;  }
    public: template<auto T, auto U> [[nodiscard]] static auto f3() -> auto { return T + U; }
    public: template<cpp2::i8 T, cpp2::i16 U> [[nodiscard]] static auto f4() -> auto { return T + U; }

};

};

auto main() -> int{
    N::myclass x {1}; 
    CPP2_UFCS(f, x, 53);
    N::myclass::nested::g();
    std::cout << "f1: " + cpp2::to_string(CPP2_UFCS(f1, x, 1, 1)) + "\n";
    std::cout << "f2: " + cpp2::to_string(CPP2_UFCS(f2, x, 2, 2)) + "\n";
    std::cout << "f3: " + cpp2::to_string(CPP2_UFCS_TEMPLATE_0(f3, (<3,3>), x)) + "\n";
    std::cout << "f4: " + cpp2::to_string(CPP2_UFCS_TEMPLATE_0(f4, (<4,4>), x)) + "\n";
    N::myclass x2 {"abracadabra"}; 
    N::myclass x3 {}; 
    N::myclass x4 {1, "hair"}; 

    // Invoke the single-param operator=s as actual assignments
    std::cout << "x's state before assignments: ";
    CPP2_UFCS_0(print, x);
    x = 84;
    x = "syzygy";
    x = 84;
    x = "syzygy";
}

