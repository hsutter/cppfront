
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-types-basics.cpp2"

#line 2 "pure2-types-basics.cpp2"
namespace N {

class myclass;

#line 64 "pure2-types-basics.cpp2"
}


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-types-basics.cpp2"

#line 2 "pure2-types-basics.cpp2"
namespace N {

class myclass {

    public: myclass(cpp2::impl::in<int> x);
#line 6 "pure2-types-basics.cpp2"
    public: auto operator=(cpp2::impl::in<int> x) -> myclass& ;

#line 13 "pure2-types-basics.cpp2"
    public: explicit myclass(cpp2::impl::in<std::string> s);
#line 13 "pure2-types-basics.cpp2"
    public: auto operator=(cpp2::impl::in<std::string> s) -> myclass& ;

#line 20 "pure2-types-basics.cpp2"
    public: explicit myclass(cpp2::impl::in<int> x, cpp2::impl::in<std::string> s);

#line 27 "pure2-types-basics.cpp2"
    public: explicit myclass();

#line 34 "pure2-types-basics.cpp2"
    public: auto print() const& -> void;

#line 38 "pure2-types-basics.cpp2"
    public: auto print() && -> void;

#line 42 "pure2-types-basics.cpp2"
    public: ~myclass() noexcept;

#line 46 "pure2-types-basics.cpp2"
    public: auto f(cpp2::impl::in<int> x) const& -> void;

#line 50 "pure2-types-basics.cpp2"
    private: int data {42 * 12}; 
    private: std::string more {std::to_string(42 * 12)}; 

    public: class nested {
        public: static auto g() -> void;
        public: nested() = default;
        public: nested(nested const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(nested const&) -> void = delete;

#line 55 "pure2-types-basics.cpp2"
    };

    public: template<typename T, typename U> [[nodiscard]] static auto f1(T const& t, U const& u) -> decltype(auto);
    public: template<typename T, typename U> [[nodiscard]] static auto f2(T const& t, U const& u) -> decltype(auto);
    public: template<auto T, auto U> [[nodiscard]] static auto f3() -> decltype(auto);
    public: template<cpp2::i8 T, cpp2::i16 U> [[nodiscard]] static auto f4() -> decltype(auto);
    public: myclass(myclass const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(myclass const&) -> void = delete;


#line 62 "pure2-types-basics.cpp2"
};

}

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-types-basics.cpp2"

#line 2 "pure2-types-basics.cpp2"
namespace N {

#line 6 "pure2-types-basics.cpp2"
    myclass::myclass(cpp2::impl::in<int> x)
        : data{ x }{

        // use default initializer for this.more
#line 9 "pure2-types-basics.cpp2"
        std::cout << "myclass: implicit from int\n";
        print();
    }
#line 6 "pure2-types-basics.cpp2"
    auto myclass::operator=(cpp2::impl::in<int> x) -> myclass& {
        data = x;
        more = std::to_string(42 * 12);

#line 9 "pure2-types-basics.cpp2"
        std::cout << "myclass: implicit from int\n";
        print();
        return *this;
#line 11 "pure2-types-basics.cpp2"
    }

#line 13 "pure2-types-basics.cpp2"
    myclass::myclass(cpp2::impl::in<std::string> s)
        : data{ 99 }
        , more{ s }{

#line 16 "pure2-types-basics.cpp2"
        std::cout << "myclass: explicit from string\n";
        print();
    }
#line 13 "pure2-types-basics.cpp2"
    auto myclass::operator=(cpp2::impl::in<std::string> s) -> myclass& {
        data = 99;
        more = s;

#line 16 "pure2-types-basics.cpp2"
        std::cout << "myclass: explicit from string\n";
        print();
        return *this;
#line 18 "pure2-types-basics.cpp2"
    }

#line 20 "pure2-types-basics.cpp2"
    myclass::myclass(cpp2::impl::in<int> x, cpp2::impl::in<std::string> s)
        : data{ 77 }
        , more{ s + std::to_string(x) + " plugh" }{

#line 23 "pure2-types-basics.cpp2"
        std::cout << "myclass: from int and string\n";
        print();
    }

#line 27 "pure2-types-basics.cpp2"
    myclass::myclass()
        : more{ std::to_string(3.14159) }{
        // use default initializer for this.data

#line 30 "pure2-types-basics.cpp2"
        std::cout << "myclass: default\n";
        print();
    }

#line 34 "pure2-types-basics.cpp2"
    auto myclass::print() const& -> void{
        std::cout << "    data: " + cpp2::to_string(data) + ", more: " + cpp2::to_string(more) + "\n";
    }

#line 38 "pure2-types-basics.cpp2"
    auto myclass::print() && -> void{
        std::cout << "    (move print) data: " + cpp2::to_string(data) + ", more: " + cpp2::to_string(cpp2::move(*this).more) + "\n";
    }

#line 42 "pure2-types-basics.cpp2"
    myclass::~myclass() noexcept{
        std::cout << "myclass: destructor\n";
    }

#line 46 "pure2-types-basics.cpp2"
    auto myclass::f(cpp2::impl::in<int> x) const& -> void{
        std::cout << "N::myclass::f with " + cpp2::to_string(x) + "\n";
    }

#line 54 "pure2-types-basics.cpp2"
        auto myclass::nested::g() -> void{std::cout << "N::myclass::nested::g\n"; }

#line 57 "pure2-types-basics.cpp2"
    template<typename T, typename U> [[nodiscard]] auto myclass::f1(T const& t, U const& u) -> decltype(auto) { return t + u; }
#line 58 "pure2-types-basics.cpp2"
    template<typename T, typename U> [[nodiscard]] auto myclass::f2(T const& t, U const& u) -> decltype(auto) { return t + u;  }
#line 59 "pure2-types-basics.cpp2"
    template<auto T, auto U> [[nodiscard]] auto myclass::f3() -> decltype(auto) { return T + U; }
#line 60 "pure2-types-basics.cpp2"
    template<cpp2::i8 T, cpp2::i16 U> [[nodiscard]] auto myclass::f4() -> decltype(auto) { return T + U; }

#line 64 "pure2-types-basics.cpp2"
}

#line 66 "pure2-types-basics.cpp2"
auto main() -> int{
    N::myclass x {1}; 
    CPP2_UFCS(f)(x, 53);
    N::myclass::nested::g();
    std::cout << "f1: " + cpp2::to_string(CPP2_UFCS(f1)(x, 1, 1)) + "\n";
    std::cout << "f2: " + cpp2::to_string(CPP2_UFCS(f2)(x, 2, 2)) + "\n";
    std::cout << "f3: " + cpp2::to_string(CPP2_UFCS_TEMPLATE(f3<3,3>)(x)) + "\n";
    std::cout << "f4: " + cpp2::to_string(CPP2_UFCS_TEMPLATE(f4<4,4>)(x)) + "\n";
    N::myclass auto_1 {"abracadabra"}; 
    N::myclass auto_2 {}; 
    N::myclass auto_3 {1, "hair"}; 

    // Invoke the single-param operator=s as actual assignments
    std::cout << "x's state before assignments: ";
    CPP2_UFCS(print)(x);
    x = 84;
    x = "syzygy";
    x = 84;
    x = "syzygy";
}

