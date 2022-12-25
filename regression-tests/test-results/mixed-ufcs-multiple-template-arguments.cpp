// ----- Cpp2 support -----
#include "cpp2util.h"

#line 1 "mixed-ufcs-multiple-template-arguments.cpp2"

template <auto from, auto to>
auto substr(const std::string& input) -> std::string {
    return input.substr(from, to-from);
}

struct X {
    std::string input;
    X(const std::string& input) : input{input} { }
    template <auto from, auto to>
    auto substr() -> std::string {
        return input.substr(from, to-from);
    }
};

[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 15 "mixed-ufcs-multiple-template-arguments.cpp2"

[[nodiscard]] auto main() -> int{
    std::string test_string { "The rain in Spain flows mainly down the drain" }; 
    std::cout << substr<4,8>(test_string) << "\n";

    X x { test_string }; 
    std::cout << CPP2_UFCS_TEMPLATE_0(substr, (<4,8>), std::move(x)) << "\n";
        // for now this should not be UFCS-ized because of the multiple template arguments
}

