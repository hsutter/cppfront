

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-as-with-typesafety.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-as-with-typesafety.cpp2"
void throw_error(CPP2_MESSAGE_PARAM msg CPP2_SOURCE_LOCATION_PARAM) {
    throw std::runtime_error(std::string("Type safety exception: ") + msg);
}

#line 5 "mixed-as-with-typesafety.cpp2"
[[nodiscard]] auto make_throwable(cpp2::contract_group& cg) -> auto;
#line 13 "mixed-as-with-typesafety.cpp2"

void expect_no_throw(auto&& fun) try {
    fun();
} catch(std::exception const& e) {
    std::cout << e.what() << std::endl;
} catch(...) {
    std::cout << "Unknown exception!" << std::endl;
}

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "mixed-as-with-typesafety.cpp2"

#line 5 "mixed-as-with-typesafety.cpp2"
[[nodiscard]] auto make_throwable(cpp2::contract_group& cg) -> auto{
    auto h {CPP2_UFCS(get_handler)(cg)}; 
    auto sh {[_0 = cpp2::move(h)](cpp2::contract_group* pcg) mutable -> void{
        CPP2_UFCS(set_handler)((*cpp2::impl::assert_not_null(pcg)), _0);
    }}; 
    CPP2_UFCS(set_handler)(cg, throw_error);
    return std::unique_ptr<cpp2::contract_group,decltype(sh)>(&cg, cpp2::move(sh)); 
}

#line 22 "mixed-as-with-typesafety.cpp2"
auto main() -> int{
    std::optional<int> o {}; 
{
[[maybe_unused]] auto const& unnamed_param_1{make_throwable(cpp2::type_safety)};

#line 25 "mixed-as-with-typesafety.cpp2"
    {
        expect_no_throw([_0 = o]() mutable -> void{
            std::cout << (cpp2::impl::as_<int>(_0)) << std::endl;// that will throw
        });
    }
}

#line 31 "mixed-as-with-typesafety.cpp2"
    std::cout << (cpp2::impl::as_<int>(cpp2::move(o))) << std::endl;// that will terminate
}

