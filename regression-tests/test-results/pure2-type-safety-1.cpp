
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-type-safety-1.cpp2"

#line 39 "pure2-type-safety-1.cpp2"
class B;
class D;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-type-safety-1.cpp2"

#line 2 "pure2-type-safety-1.cpp2"
[[nodiscard]] auto main() -> int;

#line 32 "pure2-type-safety-1.cpp2"
auto test_generic(auto const& x, auto const& msg) -> void;

#line 39 "pure2-type-safety-1.cpp2"
class B {
      public: B() = default;
      public: B(B const&) = delete; /* No 'that' constructor, suppress copy */
      public: auto operator=(B const&) -> void = delete;
};
#line 40 "pure2-type-safety-1.cpp2"
class D: public B {
      public: D() = default;
      public: D(D const&) = delete; /* No 'that' constructor, suppress copy */
      public: auto operator=(D const&) -> void = delete;
};
#line 41 "pure2-type-safety-1.cpp2"

auto test_1365(auto const& o) -> void;

#line 63 "pure2-type-safety-1.cpp2"
auto print(cpp2::impl::in<std::string> msg, cpp2::impl::in<bool> b) -> void;
#line 69 "pure2-type-safety-1.cpp2"

#line 1 "pure2-type-safety-1.cpp2"

//=== Cpp2 function definitions =================================================

#line 1 "pure2-type-safety-1.cpp2"

#line 2 "pure2-type-safety-1.cpp2"
[[nodiscard]] auto main() -> int
{
    std::variant<int,int,double> v {42.0}; 
    std::any a {"xyzzy"}; 
    std::optional<int> o {}; 

    test_generic(3.14, "double");
    test_generic(v,    "variant<int, int, double>");
    test_generic(a,    "any");
    test_generic(o,    "optional<int>");

    std::cout << "\n";

    static_cast<void>(CPP2_UFCS_TEMPLATE(emplace<1>)(v, 1));
    a = 2;
    o = 3;
    test_generic(42,   "int");
    test_generic(cpp2::move(v), "variant<int, int, double>");
    test_generic(cpp2::move(a), "any");
    test_generic(cpp2::move(o), "optional<int>");

    std::optional<int> oi {5}; 
    std::cout << "optional<int> is: ";
    test_1365(cpp2::move(oi));
    std::optional<D*> od {nullptr}; 
    std::cout << "\noptional<*D> is: ";
    test_1365(cpp2::move(od));
    std::cout << "\n";
}

#line 32 "pure2-type-safety-1.cpp2"
auto test_generic(auto const& x, auto const& msg) -> void{
    std::string msgx {msg}; 
    // Full qualification is necessary to avoid ambiguity in C++23
    // C++23 defines std::print, which would be picked up here by ADL
    ::print(cpp2::move(msgx) + " is int? ", cpp2::impl::is<int>(x));
}

#line 42 "pure2-type-safety-1.cpp2"
auto test_1365(auto const& o) -> void{
    if (cpp2::impl::is<int>(o)) {
        std::cout << "int ";
    }
    if (cpp2::impl::is<bool>(o)) {
        std::cout << "bool ";
    }
    if (cpp2::impl::is<float>(o)) {
        std::cout << "float ";
    }
    if (cpp2::impl::is<B*>(o)) {
        std::cout << "*B ";
    }
    if (cpp2::impl::is<D*>(o)) {
        std::cout << "*D ";
    }
    if (cpp2::impl::is<std::string>(o)) {
        std::cout << "std::string ";
    }
}

#line 63 "pure2-type-safety-1.cpp2"
auto print(cpp2::impl::in<std::string> msg, cpp2::impl::in<bool> b) -> void{
    cpp2::impl::deferred_init<char const*> bmsg; 
    if (b) { bmsg.construct("true");}
    else {bmsg.construct("false"); }
    std::cout << std::setw(40) << msg << cpp2::move(bmsg.value()) << "\n";
}

