
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-enum.cpp2"

#line 2 "pure2-enum.cpp2"
class skat_game;
    

#line 11 "pure2-enum.cpp2"
class janus;
    

#line 21 "pure2-enum.cpp2"
class file_attributes;
    

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-enum.cpp2"

#line 2 "pure2-enum.cpp2"
class skat_game {
private: cpp2::i8 _value; private: constexpr skat_game(cpp2::impl::in<cpp2::i64> _val);

private: constexpr auto operator=(cpp2::impl::in<cpp2::i64> _val) -> skat_game& ;
public: static const skat_game diamonds;
public: static const skat_game hearts;
public: static const skat_game spades;
public: static const skat_game clubs;
public: static const skat_game grand;
public: static const skat_game null;
public: [[nodiscard]] constexpr auto get_raw_value() const& -> cpp2::i8;
public: constexpr explicit skat_game();
public: constexpr skat_game(skat_game const& that);
public: constexpr auto operator=(skat_game const& that) -> skat_game& ;
public: constexpr skat_game(skat_game&& that) noexcept;
public: constexpr auto operator=(skat_game&& that) noexcept -> skat_game& ;
public: [[nodiscard]] auto operator<=>(skat_game const& that) const& -> std::strong_ordering = default;
public: [[nodiscard]] auto to_string_impl(cpp2::impl::in<std::string_view> prefix) const& -> std::string;
public: [[nodiscard]] auto to_string() const& -> std::string;
public: [[nodiscard]] auto to_code() const& -> std::string;
public: [[nodiscard]] static auto from_string(cpp2::impl::in<std::string_view> s) -> skat_game;
public: [[nodiscard]] static auto from_code(cpp2::impl::in<std::string_view> s) -> skat_game;

#line 4 "pure2-enum.cpp2"
             // 10
             // 11
             // 12

#line 9 "pure2-enum.cpp2"
};

class janus {

#line 15 "pure2-enum.cpp2"
    public: constexpr auto flip() & -> void;
    private: cpp2::i8 _value; private: constexpr janus(cpp2::impl::in<cpp2::i64> _val);

private: constexpr auto operator=(cpp2::impl::in<cpp2::i64> _val) -> janus& ;
public: static const janus past;
public: static const janus future;
public: [[nodiscard]] constexpr auto get_raw_value() const& -> cpp2::i8;
public: constexpr explicit janus();
public: constexpr janus(janus const& that);
public: constexpr auto operator=(janus const& that) -> janus& ;
public: constexpr janus(janus&& that) noexcept;
public: constexpr auto operator=(janus&& that) noexcept -> janus& ;
public: [[nodiscard]] auto operator<=>(janus const& that) const& -> std::strong_ordering = default;
public: [[nodiscard]] auto to_string_impl(cpp2::impl::in<std::string_view> prefix) const& -> std::string;
public: [[nodiscard]] auto to_string() const& -> std::string;
public: [[nodiscard]] auto to_code() const& -> std::string;
public: [[nodiscard]] static auto from_string(cpp2::impl::in<std::string_view> s) -> janus;
public: [[nodiscard]] static auto from_code(cpp2::impl::in<std::string_view> s) -> janus;

#line 19 "pure2-enum.cpp2"
};

class file_attributes {
private: cpp2::u8 _value; private: constexpr file_attributes(cpp2::impl::in<cpp2::i64> _val);

private: constexpr auto operator=(cpp2::impl::in<cpp2::i64> _val) -> file_attributes& ;
public: constexpr auto operator|=(file_attributes const& that) & -> decltype(auto);
public: constexpr auto operator&=(file_attributes const& that) & -> decltype(auto);
public: constexpr auto operator^=(file_attributes const& that) & -> decltype(auto);
public: [[nodiscard]] constexpr auto operator|(file_attributes const& that) const& -> file_attributes;
public: [[nodiscard]] constexpr auto operator&(file_attributes const& that) const& -> file_attributes;
public: [[nodiscard]] constexpr auto operator^(file_attributes const& that) const& -> file_attributes;
public: [[nodiscard]] constexpr auto has(file_attributes const& that) const& -> bool;
public: constexpr auto set(file_attributes const& that) & -> void;
public: constexpr auto clear(file_attributes const& that) & -> void;
public: static const file_attributes cached;
public: static const file_attributes current;
public: static const file_attributes obsolete;
public: static const file_attributes cached_and_current;
public: static const file_attributes none;
public: [[nodiscard]] constexpr auto get_raw_value() const& -> cpp2::u8;
public: constexpr explicit file_attributes();
public: constexpr file_attributes(file_attributes const& that);
public: constexpr auto operator=(file_attributes const& that) -> file_attributes& ;
public: constexpr file_attributes(file_attributes&& that) noexcept;
public: constexpr auto operator=(file_attributes&& that) noexcept -> file_attributes& ;
public: [[nodiscard]] auto operator<=>(file_attributes const& that) const& -> std::strong_ordering = default;
public: [[nodiscard]] auto to_string_impl(cpp2::impl::in<std::string_view> prefix, cpp2::impl::in<std::string_view> separator) const& -> std::string;
public: [[nodiscard]] auto to_string() const& -> std::string;
public: [[nodiscard]] auto to_code() const& -> std::string;
public: [[nodiscard]] static auto from_string(cpp2::impl::in<std::string_view> s) -> file_attributes;
public: [[nodiscard]] static auto from_code(cpp2::impl::in<std::string_view> s) -> file_attributes;

#line 22 "pure2-enum.cpp2"
                // 1
                // 2
                // 4

#line 26 "pure2-enum.cpp2"
};

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-enum.cpp2"

#line 1 "pure2-enum.cpp2"

constexpr skat_game::skat_game(cpp2::impl::in<cpp2::i64> _val)
                                                          : _value{ cpp2::unchecked_narrow<cpp2::i8>(_val) } {  }
constexpr auto skat_game::operator=(cpp2::impl::in<cpp2::i64> _val) -> skat_game&  { 
                                                          _value = cpp2::unchecked_narrow<cpp2::i8>(_val);
                                                          return *this; }
inline CPP2_CONSTEXPR skat_game skat_game::diamonds{ 9 };

inline CPP2_CONSTEXPR skat_game skat_game::hearts{ 10 };

inline CPP2_CONSTEXPR skat_game skat_game::spades{ 11 };

inline CPP2_CONSTEXPR skat_game skat_game::clubs{ 12 };

inline CPP2_CONSTEXPR skat_game skat_game::grand{ 20 };

inline CPP2_CONSTEXPR skat_game skat_game::null{ 23 };

[[nodiscard]] constexpr auto skat_game::get_raw_value() const& -> cpp2::i8 { return _value; }
constexpr skat_game::skat_game()
                                        : _value{ diamonds._value }{}
constexpr skat_game::skat_game(skat_game const& that)
                                              : _value{ that._value }{}
constexpr auto skat_game::operator=(skat_game const& that) -> skat_game& {
                                              _value = that._value;
                                              return *this;}
constexpr skat_game::skat_game(skat_game&& that) noexcept
                                              : _value{ std::move(that)._value }{}
constexpr auto skat_game::operator=(skat_game&& that) noexcept -> skat_game& {
                                              _value = std::move(that)._value;
                                              return *this;}
[[nodiscard]] auto skat_game::to_string_impl(cpp2::impl::in<std::string_view> prefix) const& -> std::string{

auto pref {cpp2::to_string(prefix)}; 
if ((*this) == diamonds) {return pref + "diamonds"; }
if ((*this) == hearts) {return pref + "hearts"; }
if ((*this) == spades) {return pref + "spades"; }
if ((*this) == clubs) {return pref + "clubs"; }
if ((*this) == grand) {return pref + "grand"; }
if ((*this) == null) {return cpp2::move(pref) + "null"; }
return "invalid skat_game value"; 
}

[[nodiscard]] auto skat_game::to_string() const& -> std::string { return to_string_impl(""); }
[[nodiscard]] auto skat_game::to_code() const& -> std::string { return to_string_impl("skat_game::"); }
[[nodiscard]] auto skat_game::from_string(cpp2::impl::in<std::string_view> s) -> skat_game{

auto x {s}; 
if ("diamonds" == x) {return diamonds; }
else {if ("hearts" == x) {return hearts; }
else {if ("spades" == x) {return spades; }
else {if ("clubs" == x) {return clubs; }
else {if ("grand" == x) {return grand; }
else {if ("null" == cpp2::move(x)) {return null; }
#line 1 "pure2-enum.cpp2"
}}}}}
CPP2_UFCS(report_violation)(cpp2::type_safety, CPP2_UFCS(c_str)(("can't convert string '" + cpp2::to_string(s) + "' to enum of type skat_game")));
return diamonds; 
}

[[nodiscard]] auto skat_game::from_code(cpp2::impl::in<std::string_view> s) -> skat_game{
std::string str {s}; return from_string(cpp2::string_util::replace_all(cpp2::move(str), "skat_game::", "")); }

#line 15 "pure2-enum.cpp2"
    constexpr auto janus::flip() & -> void{
        if ((*this) == past) {(*this) = future; }
        else {(*this) = past; }
    }


    constexpr janus::janus(cpp2::impl::in<cpp2::i64> _val)
                                                          : _value{ cpp2::unchecked_narrow<cpp2::i8>(_val) } {  }

constexpr auto janus::operator=(cpp2::impl::in<cpp2::i64> _val) -> janus&  { 
                                                          _value = cpp2::unchecked_narrow<cpp2::i8>(_val);
                                                          return *this; }
inline CPP2_CONSTEXPR janus janus::past{ 0 };

inline CPP2_CONSTEXPR janus janus::future{ 1 };

[[nodiscard]] constexpr auto janus::get_raw_value() const& -> cpp2::i8 { return _value; }
constexpr janus::janus()
                                        : _value{ past._value }{}
constexpr janus::janus(janus const& that)
                                              : _value{ that._value }{}
constexpr auto janus::operator=(janus const& that) -> janus& {
                                              _value = that._value;
                                              return *this;}
constexpr janus::janus(janus&& that) noexcept
                                              : _value{ std::move(that)._value }{}
constexpr auto janus::operator=(janus&& that) noexcept -> janus& {
                                              _value = std::move(that)._value;
                                              return *this;}
[[nodiscard]] auto janus::to_string_impl(cpp2::impl::in<std::string_view> prefix) const& -> std::string{

    auto pref {cpp2::to_string(prefix)}; 
    if ((*this) == past) {return pref + "past"; }
    if ((*this) == future) {return cpp2::move(pref) + "future"; }
    return "invalid janus value"; 
    }

    [[nodiscard]] auto janus::to_string() const& -> std::string { return to_string_impl(""); }
[[nodiscard]] auto janus::to_code() const& -> std::string { return to_string_impl("janus::"); }
[[nodiscard]] auto janus::from_string(cpp2::impl::in<std::string_view> s) -> janus{

    auto x {s}; 
    if ("past" == x) {return past; }
    else {if ("future" == cpp2::move(x)) {return future; }
#line 1 "pure2-enum.cpp2"
}
CPP2_UFCS(report_violation)(cpp2::type_safety, CPP2_UFCS(c_str)(("can't convert string '" + cpp2::to_string(s) + "' to enum of type janus")));
return past; 
}

[[nodiscard]] auto janus::from_code(cpp2::impl::in<std::string_view> s) -> janus{
std::string str {s}; return from_string(cpp2::string_util::replace_all(cpp2::move(str), "janus::", "")); }

constexpr file_attributes::file_attributes(cpp2::impl::in<cpp2::i64> _val)
                                                          : _value{ cpp2::unchecked_narrow<cpp2::u8>(_val) } {  }

constexpr auto file_attributes::operator=(cpp2::impl::in<cpp2::i64> _val) -> file_attributes&  { 
                                                          _value = cpp2::unchecked_narrow<cpp2::u8>(_val);
                                                          return *this; }
constexpr auto file_attributes::operator|=(file_attributes const& that) & -> decltype(auto) { return _value |= that._value; }
constexpr auto file_attributes::operator&=(file_attributes const& that) & -> decltype(auto) { return _value &= that._value; }
constexpr auto file_attributes::operator^=(file_attributes const& that) & -> decltype(auto) { return _value ^= that._value; }
[[nodiscard]] constexpr auto file_attributes::operator|(file_attributes const& that) const& -> file_attributes { return _value | that._value; }
[[nodiscard]] constexpr auto file_attributes::operator&(file_attributes const& that) const& -> file_attributes { return _value & that._value; }
[[nodiscard]] constexpr auto file_attributes::operator^(file_attributes const& that) const& -> file_attributes { return _value ^ that._value; }
[[nodiscard]] constexpr auto file_attributes::has(file_attributes const& that) const& -> bool { return _value & that._value; }
constexpr auto file_attributes::set(file_attributes const& that) & -> void{_value |= that._value;}
constexpr auto file_attributes::clear(file_attributes const& that) & -> void{_value &= ~that._value;}
inline CPP2_CONSTEXPR file_attributes file_attributes::cached{ 1 };

inline CPP2_CONSTEXPR file_attributes file_attributes::current{ 2 };

inline CPP2_CONSTEXPR file_attributes file_attributes::obsolete{ 4 };

inline CPP2_CONSTEXPR file_attributes file_attributes::cached_and_current{ cached | current };

inline CPP2_CONSTEXPR file_attributes file_attributes::none{ 0 };

[[nodiscard]] constexpr auto file_attributes::get_raw_value() const& -> cpp2::u8 { return _value; }
constexpr file_attributes::file_attributes()
                                        : _value{ none._value }{}
constexpr file_attributes::file_attributes(file_attributes const& that)
                                              : _value{ that._value }{}
constexpr auto file_attributes::operator=(file_attributes const& that) -> file_attributes& {
                                              _value = that._value;
                                              return *this;}
constexpr file_attributes::file_attributes(file_attributes&& that) noexcept
                                              : _value{ std::move(that)._value }{}
constexpr auto file_attributes::operator=(file_attributes&& that) noexcept -> file_attributes& {
                                              _value = std::move(that)._value;
                                              return *this;}
[[nodiscard]] auto file_attributes::to_string_impl(cpp2::impl::in<std::string_view> prefix, cpp2::impl::in<std::string_view> separator) const& -> std::string{

std::string ret {"("}; 

std::string sep {}; 
if ((*this) == none) {return "(none)"; }

auto pref {cpp2::to_string(prefix)}; 
if (((*this) & cached) == cached) {ret += sep + pref + "cached";sep = separator;}
if (((*this) & current) == current) {ret += sep + pref + "current";sep = separator;}
if (((*this) & obsolete) == obsolete) {ret += sep + pref + "obsolete";sep = separator;}
if (((*this) & cached_and_current) == cached_and_current) {ret += sep + cpp2::move(pref) + "cached_and_current";sep = separator;}
return cpp2::move(ret) + ")"; 
}

[[nodiscard]] auto file_attributes::to_string() const& -> std::string { return to_string_impl("", ", "); }
[[nodiscard]] auto file_attributes::to_code() const& -> std::string { return to_string_impl("file_attributes::", " | "); }
[[nodiscard]] auto file_attributes::from_string(cpp2::impl::in<std::string_view> s) -> file_attributes{

auto ret {none}; 
do {{
for ( auto const& x : cpp2::string_util::split_string_list(s) ) {
if ("cached" == x) {ret |= cached;}
else {if ("current" == x) {ret |= current;}
else {if ("obsolete" == x) {ret |= obsolete;}
else {if ("cached_and_current" == x) {ret |= cached_and_current;}
else {if ("none" == x) {ret |= none;}
else {goto BREAK_outer;}
#line 1 "pure2-enum.cpp2"
}}}}
}

return ret; 
} CPP2_CONTINUE_BREAK(outer) }
 while ( 
false
);
CPP2_UFCS(report_violation)(cpp2::type_safety, CPP2_UFCS(c_str)(("can't convert string '" + cpp2::to_string(s) + "' to flag_enum of type file_attributes")));
return none; 
}

[[nodiscard]] auto file_attributes::from_code(cpp2::impl::in<std::string_view> s) -> file_attributes{
std::string str {s}; return from_string(cpp2::string_util::replace_all(cpp2::move(str), "file_attributes::", "")); }

#line 28 "pure2-enum.cpp2"
auto main() -> int{
    auto j {janus::past}; 
    CPP2_UFCS(flip)(j);
    static_cast<void>(cpp2::move(j));

    // x : skat_game = 9;               // error, can't construct skat_game from integer

    skat_game x {skat_game::clubs}; 
    auto x2 {skat_game::diamonds}; 
    x2 = x;
    auto x3 {skat_game::from_string("hearts")}; 
    auto x4 {skat_game::from_code("skat_game::hearts")}; 

    // if x == 9 { }                    // error, can't compare skat_game and integer
    // if x == rgb::red { }             // error, can't compare skat_game and rgb color

    std::cout << "x.to_string() is " + cpp2::to_string(CPP2_UFCS(to_string)(x)) + "\n";
    std::cout << "x2.to_string() is " + cpp2::to_string(CPP2_UFCS(to_string)(cpp2::move(x2))) + "\n";
    std::cout << "x3.to_string() is " + cpp2::to_string(CPP2_UFCS(to_string)(x3)) + "\n";
    std::cout << "x3.to_code() is " + cpp2::to_string(CPP2_UFCS(to_code)(x3)) + "\n";
    std::cout << "x4.to_string() is " + cpp2::to_string(CPP2_UFCS(to_string)(cpp2::move(x3))) + "\n";

    std::cout << "with if else: ";
    if (x == skat_game::diamonds) {     // ok, can compare two skat_games
        std::cout << "diamonds";
    }
    else {if (skat_game::hearts == x) { // ok, in either order
        std::cout << "hearts";
    }
    else {if (cpp2::impl::is(x, (skat_game::spades))) {// ok, using is
        std::cout << "spades";
    }
    else {if (cpp2::impl::is(skat_game::clubs, (x))) {// ok, using is
        std::cout << "clubs";
    }
    else {
        std::cout << "not a suit";
    }}}}

    std::cout << "\nwith inspect: " << [&] () -> std::string { auto&& _expr = x;
        if (cpp2::impl::is(_expr, (skat_game::diamonds))) { if constexpr( requires{"diamonds";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("diamonds")),std::string> ) return "diamonds"; else return std::string{}; else return std::string{}; }
        else if (cpp2::impl::is(_expr, skat_game::hearts)) { if constexpr( requires{"hearts";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("hearts")),std::string> ) return "hearts"; else return std::string{}; else return std::string{}; }
        else if (cpp2::impl::is(_expr, skat_game::spades)) { if constexpr( requires{"spades";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("spades")),std::string> ) return "spades"; else return std::string{}; else return std::string{}; }
        else if (cpp2::impl::is(_expr, skat_game::clubs)) { if constexpr( requires{"clubs";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("clubs")),std::string> ) return "clubs"; else return std::string{}; else return std::string{}; }
        else return "not a suit"; }
    () << "\n\n";

    // x = 9;                           // error, can't assign skat_game from integer
    // x = rgb::red;                    // error, can't assign skat_game from rgb color

    x = skat_game::diamonds;        // ok, can assign one skat_game from another

    std::cout << "file_attributes::cached.get_raw_value() is " + cpp2::to_string(CPP2_UFCS(get_raw_value)(file_attributes::cached)) + "\n";
    std::cout << "file_attributes::current.get_raw_value() is " + cpp2::to_string(CPP2_UFCS(get_raw_value)(file_attributes::current)) + "\n";
    std::cout << "file_attributes::obsolete.get_raw_value() is " + cpp2::to_string(CPP2_UFCS(get_raw_value)(file_attributes::obsolete)) + "\n";
    std::cout << "file_attributes::cached_and_current.get_raw_value() is " + cpp2::to_string(CPP2_UFCS(get_raw_value)(file_attributes::cached_and_current)) + "\n";

    file_attributes f {file_attributes::cached_and_current}; 
    f &= file_attributes::cached | file_attributes::obsolete;
    std::cout << "f. get_raw_value() is " + cpp2::to_string(CPP2_UFCS(get_raw_value)(f)) + "\n";

    auto f2 {file_attributes::cached}; 
    std::cout << "f2.get_raw_value() is " + cpp2::to_string(CPP2_UFCS(get_raw_value)(f2)) + "\n";

    std::cout << "f  is " << CPP2_UFCS(to_string)(f) << "\n";
    std::cout << "f2 is " << CPP2_UFCS(to_string)(f2) << "\n";

    CPP2_UFCS(clear)(f2, f2);
    std::cout << "f2 is " << CPP2_UFCS(to_string)(f2) << "\n";
    CPP2_UFCS(set)(f2, file_attributes::cached);
    std::cout << "f2 is " << CPP2_UFCS(to_string)(f2) << "\n";

    std::cout << "f. get_raw_value() is " + cpp2::to_string(CPP2_UFCS(get_raw_value)(f)) + "\n";
    std::cout << "f2.get_raw_value() is " + cpp2::to_string(CPP2_UFCS(get_raw_value)(f2)) + "\n";

    std::cout << "f  is (f2) is " + cpp2::to_string(cpp2::impl::is(f, (f2))) + "\n";
    std::cout << "f2 is (f ) is " + cpp2::to_string(cpp2::impl::is(f2, (f))) + "\n\n";

    CPP2_UFCS(clear)(f, f2);
    CPP2_UFCS(set)(f, file_attributes::current | f2);
    f  |= file_attributes::obsolete;
    f2 |= file_attributes::current;

    std::cout << "f  is " << CPP2_UFCS(to_string)(f) << "\n";
    std::cout << "f2 is " << CPP2_UFCS(to_string)(f2) << "\n";
    std::cout << "f. get_raw_value() is " + cpp2::to_string(CPP2_UFCS(get_raw_value)(f)) + "\n";
    std::cout << "f2.get_raw_value() is " + cpp2::to_string(CPP2_UFCS(get_raw_value)(f2)) + "\n";
    std::cout << "f  == f2   is " + cpp2::to_string(f  == f2  ) + "\n";
    std::cout << "f  is (f2) is " + cpp2::to_string(cpp2::impl::is(f, (f2))) + "\n";
    std::cout << "f2 is (f ) is " + cpp2::to_string(cpp2::impl::is(f2, (f))) + "\n";
    std::cout << "(f & f2) == f2 is " + cpp2::to_string((f & f2) == f2) + "\n";

    std::cout << "inspecting f: " << [&] () -> std::string { auto&& _expr = cpp2::move(f);
        if (cpp2::impl::is(_expr, (file_attributes::current))) { if constexpr( requires{"exactly 'current'";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("exactly 'current'")),std::string> ) return "exactly 'current'"; else return std::string{}; else return std::string{}; }
        else if (cpp2::impl::is(_expr, cpp2::has_flags(cpp2::move(f2)))) { if constexpr( requires{"includes all f2's flags ('cached' and 'current')";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("includes all f2's flags ('cached' and 'current')")),std::string> ) return "includes all f2's flags ('cached' and 'current')"; else return std::string{}; else return std::string{}; }
        else return "something else"; }
    () << "\n";

    auto f_from_string {file_attributes::from_string("cached_and_current")}; 
    std::cout << "f_from_string is " << CPP2_UFCS(to_string)(f_from_string) << "\n";

    f_from_string = file_attributes::from_string("(current, obsolete)");
    std::cout << "f_from_string is " << CPP2_UFCS(to_string)(f_from_string) << "\n";
    std::cout << "f_from_string.to_code() is " << CPP2_UFCS(to_code)(f_from_string) << "\n";

    f_from_string = file_attributes::from_code("(file_attributes::cached | file_attributes::obsolete)");
    std::cout << "f_from_string is " << CPP2_UFCS(to_string)(cpp2::move(f_from_string)) << "\n";
}

