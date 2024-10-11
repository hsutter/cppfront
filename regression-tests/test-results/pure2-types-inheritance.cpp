
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-types-inheritance.cpp2"

#line 2 "pure2-types-inheritance.cpp2"
class Human;
    

#line 6 "pure2-types-inheritance.cpp2"
namespace N {
    template<int I> class Machine;
        

#line 11 "pure2-types-inheritance.cpp2"
}

class Cyborg;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-types-inheritance.cpp2"

#line 2 "pure2-types-inheritance.cpp2"
class Human {
    public: virtual auto speak() const -> void = 0;
    public: virtual ~Human() noexcept;

    public: Human() = default;
    public: Human(Human const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(Human const&) -> void = delete;

#line 4 "pure2-types-inheritance.cpp2"
};

namespace N {
    template<int I> class Machine {
        public: explicit Machine([[maybe_unused]] cpp2::impl::in<std::string> unnamed_param_2);
        public: virtual auto work() const -> void = 0;
        public: virtual ~Machine() noexcept;

        public: Machine(Machine const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(Machine const&) -> void = delete;

#line 10 "pure2-types-inheritance.cpp2"
    };
}

struct Cyborg_name_as_base { std::string name; };
struct Cyborg_address_as_base { std::string address; };
#line 13 "pure2-types-inheritance.cpp2"
class Cyborg: public Cyborg_name_as_base, public Human, public Cyborg_address_as_base, public N::Machine<99> {

#line 19 "pure2-types-inheritance.cpp2"
    public: explicit Cyborg(cpp2::impl::in<std::string> n);

#line 25 "pure2-types-inheritance.cpp2"
    public: auto speak() const -> void override;

#line 29 "pure2-types-inheritance.cpp2"
    public: auto work() const -> void override;

#line 33 "pure2-types-inheritance.cpp2"
    public: auto print() const& -> void;

#line 37 "pure2-types-inheritance.cpp2"
    public: ~Cyborg() noexcept;
    public: Cyborg(Cyborg const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(Cyborg const&) -> void = delete;


#line 39 "pure2-types-inheritance.cpp2"
};

auto make_speak(cpp2::impl::in<Human> h) -> void;

#line 46 "pure2-types-inheritance.cpp2"
auto do_work(cpp2::impl::in<N::Machine<99>> m) -> void;

#line 51 "pure2-types-inheritance.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-types-inheritance.cpp2"


Human::~Human() noexcept{}
#line 6 "pure2-types-inheritance.cpp2"
namespace N {

#line 8 "pure2-types-inheritance.cpp2"
        template <int I> Machine<I>::Machine([[maybe_unused]] cpp2::impl::in<std::string> unnamed_param_2){}

        template <int I> Machine<I>::~Machine() noexcept{}

#line 11 "pure2-types-inheritance.cpp2"
}

#line 19 "pure2-types-inheritance.cpp2"
    Cyborg::Cyborg(cpp2::impl::in<std::string> n)
        : Cyborg_name_as_base{ n }
        , Human{  }
        , Cyborg_address_as_base{ "123 Main St." }
        , N::Machine<99>{ "Acme Corp. engineer tech" }{

#line 22 "pure2-types-inheritance.cpp2"
        std::cout << "" + cpp2::to_string(name) + " checks in for the day's shift\n";
    }

#line 25 "pure2-types-inheritance.cpp2"
    auto Cyborg::speak() const -> void{
        std::cout << "" + cpp2::to_string(name) + " cracks a few jokes with a coworker\n";
    }

#line 29 "pure2-types-inheritance.cpp2"
    auto Cyborg::work() const -> void{
        std::cout << "" + cpp2::to_string(name) + " carries some half-tonne crates of Fe2O3 to cold storage\n";
    }

#line 33 "pure2-types-inheritance.cpp2"
    auto Cyborg::print() const& -> void{
        std::cout << "printing: " + cpp2::to_string(name) + " lives at " + cpp2::to_string(address) + "\n";
    }

#line 37 "pure2-types-inheritance.cpp2"
    Cyborg::~Cyborg() noexcept { 
        std::cout << "Tired but satisfied after another successful day, " + cpp2::to_string(cpp2::move(*this).name) + " checks out and goes home to their family\n";  }

#line 41 "pure2-types-inheritance.cpp2"
auto make_speak(cpp2::impl::in<Human> h) -> void{
    std::cout << "-> [vcall: make_speak] ";
    CPP2_UFCS(speak)(h);
}

#line 46 "pure2-types-inheritance.cpp2"
auto do_work(cpp2::impl::in<N::Machine<99>> m) -> void{
    std::cout << "-> [vcall: do_work] ";
    CPP2_UFCS(work)(m);
}

#line 51 "pure2-types-inheritance.cpp2"
auto main() -> int{
    Cyborg c {"Parsnip"}; 
    CPP2_UFCS(print)(c);
    CPP2_UFCS(make_speak)(c);
    CPP2_UFCS(do_work)(cpp2::move(c));
}

