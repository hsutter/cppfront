
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"


#line 2 "pure2-types-inheritance.cpp2"
class Human;

#line 7 "pure2-types-inheritance.cpp2"
namespace N {
    template<int I> class Machine;

#line 12 "pure2-types-inheritance.cpp2"
}

class Cyborg;

//=== Cpp2 type definitions and function declarations ===========================


#line 2 "pure2-types-inheritance.cpp2"
class Human {
    public: Human();
    public: virtual auto speak() const -> void = 0;
};

namespace N {
    template<int I> class Machine {
        public: explicit Machine(cpp2::in<std::string> id);
        public: virtual auto work() const -> void = 0;
    };
}

class Cyborg: private cpp2::store_as_base<"name",std::string>, public Human, private cpp2::store_as_base<"address",std::string>, public N::Machine<99> {

#line 20 "pure2-types-inheritance.cpp2"
    public: explicit Cyborg(cpp2::in<std::string> n);

#line 26 "pure2-types-inheritance.cpp2"
    public: auto speak() const -> void override;

#line 29 "pure2-types-inheritance.cpp2"
    public: auto work() const -> void override;

#line 32 "pure2-types-inheritance.cpp2"
    public: auto print() const -> void;

#line 35 "pure2-types-inheritance.cpp2"
    public: ~Cyborg();

};

auto make_speak(cpp2::in<Human> h) -> void;

#line 44 "pure2-types-inheritance.cpp2"
auto do_work(cpp2::in<N::Machine<99>> m) -> void;

#line 49 "pure2-types-inheritance.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================


#line 3 "pure2-types-inheritance.cpp2"
    Human::Human(){}

#line 7 "pure2-types-inheritance.cpp2"
namespace N {

        template <int I> Machine<I>::Machine(cpp2::in<std::string> id){}

#line 12 "pure2-types-inheritance.cpp2"
}

#line 20 "pure2-types-inheritance.cpp2"
    Cyborg::Cyborg(cpp2::in<std::string> n)
        : cpp2::store_as_base<"name",std::string>{ n }
        , Human{  }
        , cpp2::store_as_base<"address",std::string>{ "123 Main St." }
        , N::Machine<99>{ "Acme Corp. engineer tech" }
#line 20 "pure2-types-inheritance.cpp2"
    {

#line 23 "pure2-types-inheritance.cpp2"
        std::cout << cpp2::to_string(cpp2::store_as_base<"name",std::string>::value__()) + " checks in for the day's shift\n";
    }

    auto Cyborg::speak() const -> void { 
        std::cout << cpp2::to_string(cpp2::store_as_base<"name",std::string>::value__()) + " cracks a few jokes with a coworker\n";  }

    auto Cyborg::work() const -> void { 
        std::cout << cpp2::to_string(cpp2::store_as_base<"name",std::string>::value__()) + " carries some half-tonne crates of Fe2O3 to cold storage\n";  }

    auto Cyborg::print() const -> void { 
        std::cout << "printing: " + cpp2::to_string(cpp2::store_as_base<"name",std::string>::value__()) + " lives at " + cpp2::to_string(cpp2::store_as_base<"address",std::string>::value__()) + "\n";  }

    Cyborg::~Cyborg() { 
        std::cout << "Tired but satisfied after another successful day, " + cpp2::to_string(cpp2::store_as_base<"name",std::string>::value__()) + " checks out and goes home to their family\n";  }

#line 39 "pure2-types-inheritance.cpp2"
auto make_speak(cpp2::in<Human> h) -> void{
    std::cout << "-> [vcall: make_speak] ";
    CPP2_UFCS_0(speak, h);
}

auto do_work(cpp2::in<N::Machine<99>> m) -> void{
    std::cout << "-> [vcall: do_work] ";
    CPP2_UFCS_0(work, m);
}

auto main() -> int{
    Cyborg c {"Parsnip"}; 
    CPP2_UFCS_0(print, c);
    CPP2_UFCS_0(make_speak, c);
    CPP2_UFCS_0(do_work, std::move(c));
}

