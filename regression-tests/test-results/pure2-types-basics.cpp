
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"


#line 2 "pure2-types-basics.cpp2"
namespace N {

class myclass;

#line 60 "pure2-types-basics.cpp2"
}


//=== Cpp2 type definitions and function declarations ===========================


#line 2 "pure2-types-basics.cpp2"
namespace N {

class myclass {

    public: myclass(cpp2::in<int> x);
        
#line 6 "pure2-types-basics.cpp2"
    public: auto operator=(cpp2::in<int> x) -> myclass& ;
        

#line 13 "pure2-types-basics.cpp2"
    public: explicit myclass(cpp2::in<std::string> s);
        
#line 13 "pure2-types-basics.cpp2"
    public: auto operator=(cpp2::in<std::string> s) -> myclass& ;
        

#line 20 "pure2-types-basics.cpp2"
    public: myclass(cpp2::in<int> x, cpp2::in<std::string> s);
        

#line 27 "pure2-types-basics.cpp2"
    public: explicit myclass();
        

#line 34 "pure2-types-basics.cpp2"
    public: auto print() const -> void;
        

#line 38 "pure2-types-basics.cpp2"
    public: ~myclass();
        

#line 42 "pure2-types-basics.cpp2"
    public: auto f(cpp2::in<int> x) const -> void;
        

#line 46 "pure2-types-basics.cpp2"
    private: int data {42 * 12}; 
    private: std::string more {std::to_string(42 * 12)}; 

    public: class nested {
        public: static auto g() -> void;
    
        public: nested() = default;
        public: nested(nested const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(nested const&) -> void = delete;

#line 51 "pure2-types-basics.cpp2"
    };

    public: template<typename T, typename U> [[nodiscard]] static auto f1(T const& t, U const& u) -> auto;
    public: template<typename T, typename U> [[nodiscard]] static auto f2(T const& t, U const& u) -> auto;
    public: template<auto T, auto U> [[nodiscard]] static auto f3() -> auto;
    public: template<cpp2::i8 T, cpp2::i16 U> [[nodiscard]] static auto f4() -> auto;

    public: myclass(myclass const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(myclass const&) -> void = delete;
#line 58 "pure2-types-basics.cpp2"
};

}

auto main() -> int;
    

//=== Cpp2 function definitions =================================================


#line 2 "pure2-types-basics.cpp2"
namespace N {

#line 6 "pure2-types-basics.cpp2"
    myclass::myclass(cpp2::in<int> x)
        : data{ x }
#line 6 "pure2-types-basics.cpp2"
    {

        // use default initializer for this.more
        std::cout << "myclass: implicit from int\n";
        print();
    }
#line 6 "pure2-types-basics.cpp2"
    auto myclass::operator=(cpp2::in<int> x) -> myclass& {
        data = x;
        more = std::to_string(42 * 12);

#line 9 "pure2-types-basics.cpp2"
        std::cout << "myclass: implicit from int\n";
        print();
        return *this;
#line 11 "pure2-types-basics.cpp2"
    }

    myclass::myclass(cpp2::in<std::string> s)
        : data{ 99 }
        , more{ s }
#line 13 "pure2-types-basics.cpp2"
    {

#line 16 "pure2-types-basics.cpp2"
        std::cout << "myclass: explicit from string\n";
        print();
    }
#line 13 "pure2-types-basics.cpp2"
    auto myclass::operator=(cpp2::in<std::string> s) -> myclass& {
        data = 99;
        more = s;

#line 16 "pure2-types-basics.cpp2"
        std::cout << "myclass: explicit from string\n";
        print();
        return *this;
#line 18 "pure2-types-basics.cpp2"
    }

    myclass::myclass(cpp2::in<int> x, cpp2::in<std::string> s)
        : data{ 77 }
        , more{ s + " plugh" }
#line 20 "pure2-types-basics.cpp2"
    {

#line 23 "pure2-types-basics.cpp2"
        std::cout << "myclass: from int and string\n";
        print();
    }

    myclass::myclass()
        : more{ std::to_string(3.14159) }
#line 27 "pure2-types-basics.cpp2"
    {
        // use default initializer for this.data

        std::cout << "myclass: default\n";
        print();
    }

    auto myclass::print() const -> void{
        std::cout << "    data: " + cpp2::to_string(data) + ", more: " + cpp2::to_string(more) + "\n";
    }

    myclass::~myclass(){
        std::cout << "myclass: destructor\n";
    }

    auto myclass::f(cpp2::in<int> x) const -> void{
        std::cout << "N::myclass::f with " + cpp2::to_string(x) + "\n";
    }

#line 50 "pure2-types-basics.cpp2"
        auto myclass::nested::g() -> void { std::cout << "N::myclass::nested::g\n";  }

#line 53 "pure2-types-basics.cpp2"
    template<typename T, typename U> [[nodiscard]] auto myclass::f1(T const& t, U const& u) -> auto { return t + u; }
    template<typename T, typename U> [[nodiscard]] auto myclass::f2(T const& t, U const& u) -> auto { return t + u;  }
    template<auto T, auto U> [[nodiscard]] auto myclass::f3() -> auto { return T + U; }
    template<cpp2::i8 T, cpp2::i16 U> [[nodiscard]] auto myclass::f4() -> auto { return T + U; }

#line 60 "pure2-types-basics.cpp2"
}

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

