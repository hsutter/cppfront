
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"


#line 2 "pure2-union.cpp2"
class name_or_number;
    

#line 7 "pure2-union.cpp2"
template<typename T> class name_or_other;


//=== Cpp2 type definitions and function declarations ===========================


#line 2 "pure2-union.cpp2"
class name_or_number {
private: std::aligned_storage_t<cpp2::max(sizeof(std::string), sizeof(cpp2::i32))> _storage {}; private: cpp2::i8 _discriminator {-1}; public: [[nodiscard]] auto is_name() const& -> bool;
public: [[nodiscard]] auto name() const& -> std::string const&;
public: [[nodiscard]] auto name() & -> std::string&;
public: auto set_name(cpp2::in<std::string> value) & -> void;
public: auto set_name(auto&& ...args) & -> void;
public: [[nodiscard]] auto is_num() const& -> bool;
public: [[nodiscard]] auto num() const& -> cpp2::i32 const&;
public: [[nodiscard]] auto num() & -> cpp2::i32&;
public: auto set_num(cpp2::in<cpp2::i32> value) & -> void;
public: auto set_num(auto&& ...args) & -> void;
private: auto destroy() & -> void;
public: ~name_or_number() noexcept;

    public: name_or_number() = default;
    public: name_or_number(name_or_number const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(name_or_number const&) -> void = delete;


#line 5 "pure2-union.cpp2"
};

template<typename T> class name_or_other
 {

#line 12 "pure2-union.cpp2"
    public: [[nodiscard]] auto to_string() const& -> std::string;

        private: std::aligned_storage_t<cpp2::max(sizeof(std::string), sizeof(T))> _storage {}; private: cpp2::i8 _discriminator {-1}; public: [[nodiscard]] auto is_name() const& -> bool;
public: [[nodiscard]] auto name() const& -> std::string const&;
public: [[nodiscard]] auto name() & -> std::string&;
public: auto set_name(cpp2::in<std::string> value) & -> void;
public: auto set_name(auto&& ...args) & -> void;
public: [[nodiscard]] auto is_other() const& -> bool;
public: [[nodiscard]] auto other() const& -> T const&;
public: [[nodiscard]] auto other() & -> T&;
public: auto set_other(cpp2::in<T> value) & -> void;
public: auto set_other(auto&& ...args) & -> void;
private: auto destroy() & -> void;
public: ~name_or_other() noexcept;

    public: name_or_other() = default;
    public: name_or_other(name_or_other const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(name_or_other const&) -> void = delete;
#line 17 "pure2-union.cpp2"
};

auto print_name(cpp2::in<name_or_number> non) -> void;
    

#line 28 "pure2-union.cpp2"
auto main() -> int;
    

//=== Cpp2 function definitions =================================================



    [[nodiscard]] auto name_or_number::is_name() const& -> bool { return _discriminator == 0; }
[[nodiscard]] auto name_or_number::name() const& -> std::string const& { 
                                                             cpp2::Default.expects(is_name(), "");return *cpp2::assert_not_null(reinterpret_cast<std::string const*>(&_storage)); }
[[nodiscard]] auto name_or_number::name() & -> std::string& { 
                                                                   cpp2::Default.expects(is_name(), "");return *cpp2::assert_not_null(reinterpret_cast<std::string*>(&_storage)); }
auto name_or_number::set_name(cpp2::in<std::string> value) & -> void{if (!(is_name())) {destroy();std::construct_at(reinterpret_cast<std::string*>(&_storage), value);}else {*cpp2::assert_not_null(reinterpret_cast<std::string*>(&_storage)) = value;}_discriminator = 0;}
auto name_or_number::set_name(auto&& ...args) & -> void{if (!(is_name())) {destroy();std::construct_at(reinterpret_cast<std::string*>(&_storage), args...);}else {*cpp2::assert_not_null(reinterpret_cast<std::string*>(&_storage)) = std::string{args...};}_discriminator = 0;}
[[nodiscard]] auto name_or_number::is_num() const& -> bool { return _discriminator == 1; }
[[nodiscard]] auto name_or_number::num() const& -> cpp2::i32 const& { 
                                                   cpp2::Default.expects(is_num(), "");return *cpp2::assert_not_null(reinterpret_cast<cpp2::i32 const*>(&_storage)); }
[[nodiscard]] auto name_or_number::num() & -> cpp2::i32& { 
                                                         cpp2::Default.expects(is_num(), "");return *cpp2::assert_not_null(reinterpret_cast<cpp2::i32*>(&_storage)); }
auto name_or_number::set_num(cpp2::in<cpp2::i32> value) & -> void{if (!(is_num())) {destroy();std::construct_at(reinterpret_cast<cpp2::i32*>(&_storage), value);}else {*cpp2::assert_not_null(reinterpret_cast<cpp2::i32*>(&_storage)) = value;}_discriminator = 1;}
auto name_or_number::set_num(auto&& ...args) & -> void{if (!(is_num())) {destroy();std::construct_at(reinterpret_cast<cpp2::i32*>(&_storage), args...);}else {*cpp2::assert_not_null(reinterpret_cast<cpp2::i32*>(&_storage)) = cpp2::i32{args...};}_discriminator = 1;}
auto name_or_number::destroy() & -> void{
    if (_discriminator == 0) {std::destroy_at(reinterpret_cast<std::string*>(&_storage));}
    if (_discriminator == 1) {std::destroy_at(reinterpret_cast<cpp2::i32*>(&_storage));}
    _discriminator = -1;
    }

    name_or_number::~name_or_number() noexcept{destroy();}
#line 12 "pure2-union.cpp2"
    template <typename T> [[nodiscard]] auto name_or_other<T>::to_string() const& -> std::string{
        if (is_name())       { return name(); }
        else {if (is_other()) {return cpp2::as_<std::string>(other()); }
        else               { return "invalid value"; }}
    }



    template <typename T> [[nodiscard]] auto name_or_other<T>::is_name() const& -> bool { return _discriminator == 0; }
template <typename T> [[nodiscard]] auto name_or_other<T>::name() const& -> std::string const& { 
                                                             cpp2::Default.expects(is_name(), "");return *cpp2::assert_not_null(reinterpret_cast<std::string const*>(&_storage)); }
template <typename T> [[nodiscard]] auto name_or_other<T>::name() & -> std::string& { 
                                                                   cpp2::Default.expects(is_name(), "");return *cpp2::assert_not_null(reinterpret_cast<std::string*>(&_storage)); }
template <typename T> auto name_or_other<T>::set_name(cpp2::in<std::string> value) & -> void{if (!(is_name())) {destroy();std::construct_at(reinterpret_cast<std::string*>(&_storage), value);}else {*cpp2::assert_not_null(reinterpret_cast<std::string*>(&_storage)) = value;}_discriminator = 0;}
template <typename T> auto name_or_other<T>::set_name(auto&& ...args) & -> void{if (!(is_name())) {destroy();std::construct_at(reinterpret_cast<std::string*>(&_storage), args...);}else {*cpp2::assert_not_null(reinterpret_cast<std::string*>(&_storage)) = std::string{args...};}_discriminator = 0;}
template <typename T> [[nodiscard]] auto name_or_other<T>::is_other() const& -> bool { return _discriminator == 1; }
template <typename T> [[nodiscard]] auto name_or_other<T>::other() const& -> T const& { 
                                                     cpp2::Default.expects(is_other(), "");return *cpp2::assert_not_null(reinterpret_cast<T const*>(&_storage)); }
template <typename T> [[nodiscard]] auto name_or_other<T>::other() & -> T& { 
                                                           cpp2::Default.expects(is_other(), "");return *cpp2::assert_not_null(reinterpret_cast<T*>(&_storage)); }
template <typename T> auto name_or_other<T>::set_other(cpp2::in<T> value) & -> void{if (!(is_other())) {destroy();std::construct_at(reinterpret_cast<T*>(&_storage), value);}else {*cpp2::assert_not_null(reinterpret_cast<T*>(&_storage)) = value;}_discriminator = 1;}
template <typename T> auto name_or_other<T>::set_other(auto&& ...args) & -> void{if (!(is_other())) {destroy();std::construct_at(reinterpret_cast<T*>(&_storage), args...);}else {*cpp2::assert_not_null(reinterpret_cast<T*>(&_storage)) = T{args...};}_discriminator = 1;}
template <typename T> auto name_or_other<T>::destroy() & -> void{
    if (_discriminator == 0) {std::destroy_at(reinterpret_cast<std::string*>(&_storage));}
    if (_discriminator == 1) {std::destroy_at(reinterpret_cast<T*>(&_storage));}
    _discriminator = -1;
    }

    template <typename T> name_or_other<T>::~name_or_other() noexcept{destroy();}

#line 19 "pure2-union.cpp2"
auto print_name(cpp2::in<name_or_number> non) -> void{
    if (CPP2_UFCS_0(is_name, non)) {
        std::cout << CPP2_UFCS_0(name, non) << "\n";
    }
    else {
        std::cout << "(not a name)\n";
    }
}

auto main() -> int{
    name_or_number x {}; 
    std::cout << "sizeof(x) is " + cpp2::to_string(sizeof(x)) + "\n";

    CPP2_UFCS_0(print_name, x);

    CPP2_UFCS(set_name, x, "xyzzy", cpp2::as_<cpp2::u8, 3>());

    CPP2_UFCS_0(print_name, std::move(x));

    {
        name_or_other<int> val {}; 
        CPP2_UFCS(set_other, val, 42);
        std::cout << CPP2_UFCS_0(to_string, std::move(val));
    }
}

