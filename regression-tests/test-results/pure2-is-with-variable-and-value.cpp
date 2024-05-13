
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-is-with-variable-and-value.cpp2"

#line 26 "pure2-is-with-variable-and-value.cpp2"
class WithOp;
    

#line 30 "pure2-is-with-variable-and-value.cpp2"
class WithGenOp;
    

#line 39 "pure2-is-with-variable-and-value.cpp2"
class Cmp;
    

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-is-with-variable-and-value.cpp2"
auto fun(auto const& name, auto const& v) -> void;

#line 14 "pure2-is-with-variable-and-value.cpp2"
[[nodiscard]] auto main() -> int;

#line 26 "pure2-is-with-variable-and-value.cpp2"
class WithOp {
    public: [[nodiscard]] auto op_is(cpp2::impl::in<int> x) const& -> auto;
    public: WithOp() = default;
    public: WithOp(WithOp const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(WithOp const&) -> void = delete;

#line 28 "pure2-is-with-variable-and-value.cpp2"
};

class WithGenOp {
    public: [[nodiscard]] auto op_is(auto const& x) const& -> bool;
    public: WithGenOp() = default;
    public: WithGenOp(WithGenOp const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(WithGenOp const&) -> void = delete;


#line 37 "pure2-is-with-variable-and-value.cpp2"
};

class Cmp {
    public: [[nodiscard]] auto operator==(cpp2::impl::in<int> x) const& -> bool;
    public: Cmp() = default;
    public: Cmp(Cmp const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(Cmp const&) -> void = delete;

#line 41 "pure2-is-with-variable-and-value.cpp2"
};


//=== Cpp2 function definitions =================================================

#line 1 "pure2-is-with-variable-and-value.cpp2"
auto fun(auto const& name, auto const& v) -> void{
#line 2 "pure2-is-with-variable-and-value.cpp2"
    std::cout << name << ": " << 
                [&] () -> std::string { auto&& _expr = v;
                if (cpp2::impl::is(_expr, (42))) { if constexpr( requires{"42";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("42")),std::string> ) return "42"; else return std::string{}; else return std::string{}; }
                else if (cpp2::impl::is(_expr, 123)) { if constexpr( requires{"op_is";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("op_is")),std::string> ) return "op_is"; else return std::string{}; else return std::string{}; }
                else if (cpp2::impl::is(_expr, -123)) { if constexpr( requires{"generic op_is";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("generic op_is")),std::string> ) return "generic op_is"; else return std::string{}; else return std::string{}; }
                else if (cpp2::impl::is(_expr, 4321)) { if constexpr( requires{"comparable";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("comparable")),std::string> ) return "comparable"; else return std::string{}; else return std::string{}; }
                else if (cpp2::impl::is(_expr, "text")) { if constexpr( requires{"text";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("text")),std::string> ) return "text"; else return std::string{}; else return std::string{}; }
                else return "unknown"; }
              () 
              << std::endl;
}

#line 14 "pure2-is-with-variable-and-value.cpp2"
[[nodiscard]] auto main() -> int{
    fun("3.14", 3.14);
    fun("42", 42);
    fun("WithOp()", WithOp());
    fun("WithGenOp()", WithGenOp());
    fun("Cmp()", Cmp());
    fun("std::string(\"text\")", std::string("text"));
    fun("\"text\"", "text");
    fun("std::string_view(\"text\")", std::string_view("text"));
    fun(":std::vector = ('t','e','x','t','\\0')", std::vector{'t', 'e', 'x', 't', '\0'});
}

#line 27 "pure2-is-with-variable-and-value.cpp2"
    [[nodiscard]] auto WithOp::op_is(cpp2::impl::in<int> x) const& -> auto { return x == 123;  }

#line 31 "pure2-is-with-variable-and-value.cpp2"
    [[nodiscard]] auto WithGenOp::op_is(auto const& x) const& -> bool{
        if constexpr (std::convertible_to<decltype(x),int>) {
            return x == -123; 
        }
        return false; 
    }

#line 40 "pure2-is-with-variable-and-value.cpp2"
    [[nodiscard]] auto Cmp::operator==(cpp2::impl::in<int> x) const& -> bool { return x == 4321;  }

