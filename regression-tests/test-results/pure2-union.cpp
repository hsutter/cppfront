
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-union.cpp2"

#line 2 "pure2-union.cpp2"
class name_or_number;
    

#line 7 "pure2-union.cpp2"
template<typename T> class name_or_other;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-union.cpp2"

#line 2 "pure2-union.cpp2"
class name_or_number {
private: cpp2::aligned_storage<cpp2::max(sizeof(std::string), sizeof(cpp2::i32)),cpp2::max(alignof(std::string), alignof(cpp2::i32))> _storage {}; private: cpp2::i8 _discriminator {-1}; public: [[nodiscard]] auto is_name() const& -> bool;
public: [[nodiscard]] auto name() const& -> std::string const&;
public: [[nodiscard]] auto name() & -> std::string&;
public: auto set_name(cpp2::in<std::string> _value) & -> void;
public: auto set_name(auto&& ..._args) & -> void;
public: [[nodiscard]] auto is_num() const& -> bool;
public: [[nodiscard]] auto num() const& -> cpp2::i32 const&;
public: [[nodiscard]] auto num() & -> cpp2::i32&;
public: auto set_num(cpp2::in<cpp2::i32> _value) & -> void;
public: auto set_num(auto&& ..._args) & -> void;
private: auto _destroy() & -> void;
public: ~name_or_number() noexcept;
public: explicit name_or_number();
public: name_or_number(name_or_number const& that);

public: name_or_number(name_or_number&& that) noexcept;
public: auto operator=(name_or_number const& that) -> name_or_number& ;
public: auto operator=(name_or_number&& that) noexcept -> name_or_number& ;

#line 5 "pure2-union.cpp2"
};

template<typename T> class name_or_other
 {

#line 12 "pure2-union.cpp2"
    public: [[nodiscard]] auto to_string() const& -> std::string;
    private: cpp2::aligned_storage<cpp2::max(sizeof(std::string), sizeof(T)),cpp2::max(alignof(std::string), alignof(T))> _storage {}; private: cpp2::i8 _discriminator {-1}; public: [[nodiscard]] auto is_name() const& -> bool;
public: [[nodiscard]] auto name() const& -> std::string const&;
public: [[nodiscard]] auto name() & -> std::string&;
public: auto set_name(cpp2::in<std::string> _value) & -> void;
public: auto set_name(auto&& ..._args) & -> void;
public: [[nodiscard]] auto is_other() const& -> bool;
public: [[nodiscard]] auto other() const& -> T const&;
public: [[nodiscard]] auto other() & -> T&;
public: auto set_other(cpp2::in<T> _value) & -> void;
public: auto set_other(auto&& ..._args) & -> void;
private: auto _destroy() & -> void;
public: ~name_or_other() noexcept;
public: explicit name_or_other();
public: name_or_other(name_or_other const& that);

public: name_or_other(name_or_other&& that) noexcept;
public: auto operator=(name_or_other const& that) -> name_or_other& ;
public: auto operator=(name_or_other&& that) noexcept -> name_or_other& ;

#line 17 "pure2-union.cpp2"
};

auto print_name(cpp2::in<name_or_number> non) -> void;

#line 28 "pure2-union.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-union.cpp2"


#line 1 "pure2-union.cpp2"
[[nodiscard]] auto name_or_number::is_name() const& -> bool { return _discriminator == 0; }
[[nodiscard]] auto name_or_number::name() const& -> std::string const& { 
                                                         if (cpp2::Default.has_handler() && !(is_name()) ) { cpp2::Default.report_violation(""); }return *cpp2::assert_not_null(reinterpret_cast<std::string const*>(&_storage)); }
[[nodiscard]] auto name_or_number::name() & -> std::string& { 
                                                               if (cpp2::Default.has_handler() && !(is_name()) ) { cpp2::Default.report_violation(""); }return *cpp2::assert_not_null(reinterpret_cast<std::string*>(&_storage)); }
auto name_or_number::set_name(cpp2::in<std::string> _value) & -> void{if (!(is_name())) {_destroy();std::construct_at(reinterpret_cast<std::string*>(&_storage), _value);}else {*cpp2::assert_not_null(reinterpret_cast<std::string*>(&_storage)) = _value;}_discriminator = 0;}
auto name_or_number::set_name(auto&& ..._args) & -> void{if (!(is_name())) {_destroy();std::construct_at(reinterpret_cast<std::string*>(&_storage), _args...);}else {*cpp2::assert_not_null(reinterpret_cast<std::string*>(&_storage)) = std::string{_args...};}_discriminator = 0;}
[[nodiscard]] auto name_or_number::is_num() const& -> bool { return _discriminator == 1; }
[[nodiscard]] auto name_or_number::num() const& -> cpp2::i32 const& { 
                                               if (cpp2::Default.has_handler() && !(is_num()) ) { cpp2::Default.report_violation(""); }return *cpp2::assert_not_null(reinterpret_cast<cpp2::i32 const*>(&_storage)); }
[[nodiscard]] auto name_or_number::num() & -> cpp2::i32& { 
                                                     if (cpp2::Default.has_handler() && !(is_num()) ) { cpp2::Default.report_violation(""); }return *cpp2::assert_not_null(reinterpret_cast<cpp2::i32*>(&_storage)); }
auto name_or_number::set_num(cpp2::in<cpp2::i32> _value) & -> void{if (!(is_num())) {_destroy();std::construct_at(reinterpret_cast<cpp2::i32*>(&_storage), _value);}else {*cpp2::assert_not_null(reinterpret_cast<cpp2::i32*>(&_storage)) = _value;}_discriminator = 1;}
auto name_or_number::set_num(auto&& ..._args) & -> void{if (!(is_num())) {_destroy();std::construct_at(reinterpret_cast<cpp2::i32*>(&_storage), _args...);}else {*cpp2::assert_not_null(reinterpret_cast<cpp2::i32*>(&_storage)) = cpp2::i32{_args...};}_discriminator = 1;}
auto name_or_number::_destroy() & -> void{
if (_discriminator == 0) {std::destroy_at(reinterpret_cast<std::string*>(&_storage));}
if (_discriminator == 1) {std::destroy_at(reinterpret_cast<cpp2::i32*>(&_storage));}
_discriminator = -1;
}

name_or_number::~name_or_number() noexcept{_destroy();}
name_or_number::name_or_number(){}
name_or_number::name_or_number(name_or_number const& that)
        : _storage{  }
        , _discriminator{ -1 }{
if (CPP2_UFCS(is_name)(that)) {set_name(CPP2_UFCS(name)(that));}
if (CPP2_UFCS(is_num)(that)) {set_num(CPP2_UFCS(num)(that));}
}

name_or_number::name_or_number(name_or_number&& that) noexcept
        : _storage{  }
        , _discriminator{ -1 }{
if (CPP2_UFCS(is_name)(std::move(that))) {set_name(CPP2_UFCS(name)(std::move(that)));}
if (CPP2_UFCS(is_num)(std::move(that))) {set_num(CPP2_UFCS(num)(std::move(that)));}
}

auto name_or_number::operator=(name_or_number const& that) -> name_or_number& {
if (CPP2_UFCS(is_name)(that)) {set_name(CPP2_UFCS(name)(that));}
if (CPP2_UFCS(is_num)(that)) {set_num(CPP2_UFCS(num)(that));}
        return *this;
}

auto name_or_number::operator=(name_or_number&& that) noexcept -> name_or_number& {
if (CPP2_UFCS(is_name)(std::move(that))) {set_name(CPP2_UFCS(name)(std::move(that)));}
if (CPP2_UFCS(is_num)(std::move(that))) {set_num(CPP2_UFCS(num)(std::move(that)));}
        return *this;
}
#line 12 "pure2-union.cpp2"
    template <typename T> [[nodiscard]] auto name_or_other<T>::to_string() const& -> std::string{
        if (is_name())       { return name(); }
        else {if (is_other()) {return cpp2::as_<std::string>(other()); }
        else               { return "invalid value"; }}
    }



    template <typename T> [[nodiscard]] auto name_or_other<T>::is_name() const& -> bool { return _discriminator == 0; }
template <typename T> [[nodiscard]] auto name_or_other<T>::name() const& -> std::string const& { 
                                                         if (cpp2::Default.has_handler() && !(is_name()) ) { cpp2::Default.report_violation(""); }return *cpp2::assert_not_null(reinterpret_cast<std::string const*>(&_storage)); }
template <typename T> [[nodiscard]] auto name_or_other<T>::name() & -> std::string& { 
                                                               if (cpp2::Default.has_handler() && !(is_name()) ) { cpp2::Default.report_violation(""); }return *cpp2::assert_not_null(reinterpret_cast<std::string*>(&_storage)); }
template <typename T> auto name_or_other<T>::set_name(cpp2::in<std::string> _value) & -> void{if (!(is_name())) {_destroy();std::construct_at(reinterpret_cast<std::string*>(&_storage), _value);}else {*cpp2::assert_not_null(reinterpret_cast<std::string*>(&_storage)) = _value;}_discriminator = 0;}
template <typename T> auto name_or_other<T>::set_name(auto&& ..._args) & -> void{if (!(is_name())) {_destroy();std::construct_at(reinterpret_cast<std::string*>(&_storage), _args...);}else {*cpp2::assert_not_null(reinterpret_cast<std::string*>(&_storage)) = std::string{_args...};}_discriminator = 0;}
template <typename T> [[nodiscard]] auto name_or_other<T>::is_other() const& -> bool { return _discriminator == 1; }
template <typename T> [[nodiscard]] auto name_or_other<T>::other() const& -> T const& { 
                                                 if (cpp2::Default.has_handler() && !(is_other()) ) { cpp2::Default.report_violation(""); }return *cpp2::assert_not_null(reinterpret_cast<T const*>(&_storage)); }
template <typename T> [[nodiscard]] auto name_or_other<T>::other() & -> T& { 
                                                       if (cpp2::Default.has_handler() && !(is_other()) ) { cpp2::Default.report_violation(""); }return *cpp2::assert_not_null(reinterpret_cast<T*>(&_storage)); }
template <typename T> auto name_or_other<T>::set_other(cpp2::in<T> _value) & -> void{if (!(is_other())) {_destroy();std::construct_at(reinterpret_cast<T*>(&_storage), _value);}else {*cpp2::assert_not_null(reinterpret_cast<T*>(&_storage)) = _value;}_discriminator = 1;}
template <typename T> auto name_or_other<T>::set_other(auto&& ..._args) & -> void{if (!(is_other())) {_destroy();std::construct_at(reinterpret_cast<T*>(&_storage), _args...);}else {*cpp2::assert_not_null(reinterpret_cast<T*>(&_storage)) = T{_args...};}_discriminator = 1;}
template <typename T> auto name_or_other<T>::_destroy() & -> void{
    if (_discriminator == 0) {std::destroy_at(reinterpret_cast<std::string*>(&_storage));}
    if (_discriminator == 1) {std::destroy_at(reinterpret_cast<T*>(&_storage));}
    _discriminator = -1;
    }

    template <typename T> name_or_other<T>::~name_or_other() noexcept{_destroy();}
template <typename T> name_or_other<T>::name_or_other(){}
template <typename T> name_or_other<T>::name_or_other(name_or_other const& that)
        : _storage{  }
        , _discriminator{ -1 }{
    if (CPP2_UFCS(is_name)(that)) {set_name(CPP2_UFCS(name)(that));}
    if (CPP2_UFCS(is_other)(that)) {set_other(CPP2_UFCS(other)(that));}
    }


    template <typename T> name_or_other<T>::name_or_other(name_or_other&& that) noexcept
        : _storage{  }
        , _discriminator{ -1 }{
    if (CPP2_UFCS(is_name)(std::move(that))) {set_name(CPP2_UFCS(name)(std::move(that)));}
    if (CPP2_UFCS(is_other)(std::move(that))) {set_other(CPP2_UFCS(other)(std::move(that)));}
    }

    template <typename T> auto name_or_other<T>::operator=(name_or_other const& that) -> name_or_other& {
    if (CPP2_UFCS(is_name)(that)) {set_name(CPP2_UFCS(name)(that));}
    if (CPP2_UFCS(is_other)(that)) {set_other(CPP2_UFCS(other)(that));}
        return *this;
    }

    template <typename T> auto name_or_other<T>::operator=(name_or_other&& that) noexcept -> name_or_other& {
    if (CPP2_UFCS(is_name)(std::move(that))) {set_name(CPP2_UFCS(name)(std::move(that)));}
    if (CPP2_UFCS(is_other)(std::move(that))) {set_other(CPP2_UFCS(other)(std::move(that)));}
        return *this;
    }
#line 19 "pure2-union.cpp2"
auto print_name(cpp2::in<name_or_number> non) -> void{
    if (CPP2_UFCS(is_name)(non)) {
        std::cout << CPP2_UFCS(name)(non) << "\n";
    }
    else {
        std::cout << "(not a name)\n";
    }
}

auto main() -> int{
    name_or_number x {}; 
    std::cout << "sizeof(x) is " + cpp2::to_string(sizeof(x)) + "\n";

    CPP2_UFCS(print_name)(x);

    CPP2_UFCS(set_name)(x, "xyzzy", cpp2::as_<cpp2::u8, 3>());

    CPP2_UFCS(print_name)(std::move(x));

    {
        name_or_other<int> val {}; 
        CPP2_UFCS(set_other)(val, 42);
        std::cout << CPP2_UFCS(to_string)(std::move(val));
    }
}

