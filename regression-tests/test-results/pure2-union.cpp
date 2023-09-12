
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"


#line 2 "pure2-union.cpp2"
class name_or_number;
    

//=== Cpp2 type definitions and function declarations ===========================


#line 2 "pure2-union.cpp2"
class name_or_number {
private: std::array<std::byte,cpp2::max(sizeof(std::string), sizeof(cpp2::i32))> storage__ {}; private: cpp2::i8 discriminator__ {-1}; public: [[nodiscard]] auto is_name() const& -> bool;
public: [[nodiscard]] auto get_name() const& -> auto&&;
public: [[nodiscard]] auto get_name() & -> auto&&;
public: auto set_name(auto&& value) & -> void
CPP2_REQUIRES_ (std::is_same_v<CPP2_TYPEOF(value), std::string>);
public: [[nodiscard]] auto is_num() const& -> bool;
public: [[nodiscard]] auto get_num() const& -> auto&&;
public: [[nodiscard]] auto get_num() & -> auto&&;
public: auto set_num(auto&& value) & -> void
CPP2_REQUIRES_ (std::is_same_v<CPP2_TYPEOF(value), cpp2::i32>);
private: auto destroy() & -> void;
public: ~name_or_number() noexcept;

    public: name_or_number() = default;
    public: name_or_number(name_or_number const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(name_or_number const&) -> void = delete;

#line 5 "pure2-union.cpp2"
};

auto print_name(cpp2::in<name_or_number> non) -> void;
    

#line 16 "pure2-union.cpp2"
auto main() -> int;
    

//=== Cpp2 function definitions =================================================



    [[nodiscard]] auto name_or_number::is_name() const& -> bool { return discriminator__ == 0; }
[[nodiscard]] auto name_or_number::get_name() const& -> auto&& { 
                                                              cpp2::Default.expects(is_name(), "");return *cpp2::assert_not_null(reinterpret_cast<std::string const*>(&storage__)); }
[[nodiscard]] auto name_or_number::get_name() & -> auto&& { 
                                                                    cpp2::Default.expects(is_name(), "");return *cpp2::assert_not_null(reinterpret_cast<std::string*>(&storage__)); }
auto name_or_number::set_name(auto&& value) & -> void
requires (std::is_same_v<CPP2_TYPEOF(value), std::string>){if (!(is_name())) {destroy();std::construct_at(reinterpret_cast<std::string*>(&storage__), value);}else {*cpp2::assert_not_null(reinterpret_cast<std::string*>(&storage__)) = value;}discriminator__ = 0;}
[[nodiscard]] auto name_or_number::is_num() const& -> bool { return discriminator__ == 1; }
[[nodiscard]] auto name_or_number::get_num() const& -> auto&& { 
                                                            cpp2::Default.expects(is_num(), "");return *cpp2::assert_not_null(reinterpret_cast<cpp2::i32 const*>(&storage__)); }
[[nodiscard]] auto name_or_number::get_num() & -> auto&& { 
                                                                  cpp2::Default.expects(is_num(), "");return *cpp2::assert_not_null(reinterpret_cast<cpp2::i32*>(&storage__)); }
auto name_or_number::set_num(auto&& value) & -> void
requires (std::is_same_v<CPP2_TYPEOF(value), cpp2::i32>){if (!(is_num())) {destroy();std::construct_at(reinterpret_cast<cpp2::i32*>(&storage__), value);}else {*cpp2::assert_not_null(reinterpret_cast<cpp2::i32*>(&storage__)) = value;}discriminator__ = 1;}
auto name_or_number::destroy() & -> void{
    if (discriminator__ == 0) {std::destroy_at(reinterpret_cast<std::string*>(&storage__));}
    if (discriminator__ == 1) {std::destroy_at(reinterpret_cast<cpp2::i32*>(&storage__));}
    }

    name_or_number::~name_or_number() noexcept{destroy();}
#line 7 "pure2-union.cpp2"
auto print_name(cpp2::in<name_or_number> non) -> void{
    if (CPP2_UFCS_0(is_name, non)) {
        std::cout << CPP2_UFCS_0(get_name, non) << "\n";
    }
    else {
        std::cout << "(not a name)\n";
    }
}

auto main() -> int{
    name_or_number x {}; 
    std::cout << "sizeof(x) is " + cpp2::to_string(sizeof(x)) + "\n";

    CPP2_UFCS_0(print_name, x);

    std::string s {"xyzzy"}; 
    CPP2_UFCS(set_name, x, std::move(s));

    CPP2_UFCS_0(print_name, std::move(x));
}

