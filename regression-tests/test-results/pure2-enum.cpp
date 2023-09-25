
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"


#line 2 "pure2-enum.cpp2"
class skat_game;
    

#line 11 "pure2-enum.cpp2"
class duality;
    

#line 26 "pure2-enum.cpp2"
class file_attributes;
    

//=== Cpp2 type definitions and function declarations ===========================


#line 2 "pure2-enum.cpp2"
class skat_game {
private: cpp2::i8 value__; private: constexpr skat_game(auto const& val);

private: constexpr auto operator=(auto const& val) -> skat_game& ;
public: [[nodiscard]] constexpr auto get_raw_value() const& -> cpp2::i8;
public: constexpr skat_game(skat_game const& that);
public: constexpr auto operator=(skat_game const& that) -> skat_game& ;
public: constexpr skat_game(skat_game&& that) noexcept;
public: constexpr auto operator=(skat_game&& that) noexcept -> skat_game& ;
public: [[nodiscard]] auto operator<=>(skat_game const& that) const& -> std::strong_ordering = default;
public: static const skat_game diamonds;
public: static const skat_game hearts;
public: static const skat_game spades;
public: static const skat_game clubs;
public: static const skat_game grand;
public: static const skat_game null;
public: [[nodiscard]] auto to_string() const& -> std::string;
public: friend auto operator<<(std::ostream& o, cpp2::in<skat_game> val) -> std::ostream&;

#line 4 "pure2-enum.cpp2"
             // 10
             // 11
             // 12

#line 9 "pure2-enum.cpp2"
};

class duality {

#line 15 "pure2-enum.cpp2"
    public: auto flip(cpp2::in<duality> val) & -> void;
        
        private: cpp2::i8 value__; private: constexpr duality(auto const& val);

private: constexpr auto operator=(auto const& val) -> duality& ;
public: [[nodiscard]] constexpr auto get_raw_value() const& -> cpp2::i8;
public: constexpr duality(duality const& that);
public: constexpr auto operator=(duality const& that) -> duality& ;
public: constexpr duality(duality&& that) noexcept;
public: constexpr auto operator=(duality&& that) noexcept -> duality& ;
public: [[nodiscard]] auto operator<=>(duality const& that) const& -> std::strong_ordering = default;
public: static const duality first;
public: static const duality second;
public: [[nodiscard]] auto to_string() const& -> std::string;
public: friend auto operator<<(std::ostream& o, cpp2::in<duality> val) -> std::ostream&;

#line 24 "pure2-enum.cpp2"
};

class file_attributes {
private: cpp2::u8 value__; private: constexpr file_attributes(auto const& val);

private: constexpr auto operator=(auto const& val) -> file_attributes& ;
public: [[nodiscard]] constexpr auto get_raw_value() const& -> cpp2::u8;
public: constexpr file_attributes(file_attributes const& that);
public: constexpr auto operator=(file_attributes const& that) -> file_attributes& ;
public: constexpr file_attributes(file_attributes&& that) noexcept;
public: constexpr auto operator=(file_attributes&& that) noexcept -> file_attributes& ;
public: [[nodiscard]] auto operator<=>(file_attributes const& that) const& -> std::strong_ordering = default;
public: constexpr auto operator|=(file_attributes const& that) & -> void;
public: constexpr auto operator&=(file_attributes const& that) & -> void;
public: constexpr auto operator^=(file_attributes const& that) & -> void;
public: [[nodiscard]] constexpr auto operator|(file_attributes const& that) const& -> file_attributes;
public: [[nodiscard]] constexpr auto operator&(file_attributes const& that) const& -> file_attributes;
public: [[nodiscard]] constexpr auto operator^(file_attributes const& that) const& -> file_attributes;
public: [[nodiscard]] constexpr auto has(file_attributes const& that) & -> bool;
public: constexpr auto set(file_attributes const& that) & -> void;
public: constexpr auto clear(file_attributes const& that) & -> void;
public: static const file_attributes cached;
public: static const file_attributes current;
public: static const file_attributes obsolete;
public: static const file_attributes cached_and_current;
public: static const file_attributes none;
public: [[nodiscard]] auto to_string() const& -> std::string;
public: friend auto operator<<(std::ostream& o, cpp2::in<file_attributes> val) -> std::ostream&;

#line 27 "pure2-enum.cpp2"
                // 1
                // 2
                // 4

#line 31 "pure2-enum.cpp2"
};

auto main() -> int;
    

//=== Cpp2 function definitions =================================================



    constexpr skat_game::skat_game(auto const& val)
                                                    : value__{ cpp2::unsafe_narrow<cpp2::i8>(val) } {  }
constexpr auto skat_game::operator=(auto const& val) -> skat_game&  { 
                                                    value__ = cpp2::unsafe_narrow<cpp2::i8>(val);
                                                    return *this; }
[[nodiscard]] constexpr auto skat_game::get_raw_value() const& -> cpp2::i8 { return value__; }
constexpr skat_game::skat_game(skat_game const& that)
                                              : value__{ that.value__ }{}
constexpr auto skat_game::operator=(skat_game const& that) -> skat_game& {
                                              value__ = that.value__;
                                              return *this;}
constexpr skat_game::skat_game(skat_game&& that) noexcept
                                              : value__{ std::move(that).value__ }{}
constexpr auto skat_game::operator=(skat_game&& that) noexcept -> skat_game& {
                                              value__ = std::move(that).value__;
                                              return *this;}
inline constexpr skat_game skat_game::diamonds = 9;

inline constexpr skat_game skat_game::hearts = 10;

inline constexpr skat_game skat_game::spades = 11;

inline constexpr skat_game skat_game::clubs = 12;

inline constexpr skat_game skat_game::grand = 20;

inline constexpr skat_game skat_game::null = 23;

[[nodiscard]] auto skat_game::to_string() const& -> std::string{
    if ((*this) == diamonds) {return "diamonds"; }
    if ((*this) == hearts) {return "hearts"; }
    if ((*this) == spades) {return "spades"; }
    if ((*this) == clubs) {return "clubs"; }
    if ((*this) == grand) {return "grand"; }
    if ((*this) == null) {return "null"; }
    return "invalid skat_game value"; 
    }

    auto operator<<(std::ostream& o, cpp2::in<skat_game> val) -> std::ostream&{o << CPP2_UFCS_0(to_string, val);return o; }
#line 15 "pure2-enum.cpp2"
    auto duality::flip(cpp2::in<duality> val) & -> void{
        if (val == first) {
            value__ = second.value__;
        }
        else {
            cpp2::Default.expects(value__ == second.value__, "");
            value__ = first.value__;
        }
    }


    constexpr duality::duality(auto const& val)
                                                    : value__{ cpp2::unsafe_narrow<cpp2::i8>(val) } {  }

constexpr auto duality::operator=(auto const& val) -> duality&  { 
                                                    value__ = cpp2::unsafe_narrow<cpp2::i8>(val);
                                                    return *this; }
[[nodiscard]] constexpr auto duality::get_raw_value() const& -> cpp2::i8 { return value__; }
constexpr duality::duality(duality const& that)
                                              : value__{ that.value__ }{}
constexpr auto duality::operator=(duality const& that) -> duality& {
                                              value__ = that.value__;
                                              return *this;}
constexpr duality::duality(duality&& that) noexcept
                                              : value__{ std::move(that).value__ }{}
constexpr auto duality::operator=(duality&& that) noexcept -> duality& {
                                              value__ = std::move(that).value__;
                                              return *this;}
inline constexpr duality duality::first = 0;

inline constexpr duality duality::second = 1;

[[nodiscard]] auto duality::to_string() const& -> std::string{
    if ((*this) == first) {return "first"; }
    if ((*this) == second) {return "second"; }
    return "invalid duality value"; 
    }

    auto operator<<(std::ostream& o, cpp2::in<duality> val) -> std::ostream&{o << CPP2_UFCS_0(to_string, val);return o; }
constexpr file_attributes::file_attributes(auto const& val)
                                                    : value__{ cpp2::unsafe_narrow<cpp2::u8>(val) } {  }
constexpr auto file_attributes::operator=(auto const& val) -> file_attributes&  { 
                                                    value__ = cpp2::unsafe_narrow<cpp2::u8>(val);
                                                    return *this; }
[[nodiscard]] constexpr auto file_attributes::get_raw_value() const& -> cpp2::u8 { return value__; }
constexpr file_attributes::file_attributes(file_attributes const& that)
                                              : value__{ that.value__ }{}
constexpr auto file_attributes::operator=(file_attributes const& that) -> file_attributes& {
                                              value__ = that.value__;
                                              return *this;}
constexpr file_attributes::file_attributes(file_attributes&& that) noexcept
                                              : value__{ std::move(that).value__ }{}
constexpr auto file_attributes::operator=(file_attributes&& that) noexcept -> file_attributes& {
                                              value__ = std::move(that).value__;
                                              return *this;}
constexpr auto file_attributes::operator|=(file_attributes const& that) & -> void { value__ |= that.value__; }
constexpr auto file_attributes::operator&=(file_attributes const& that) & -> void { value__ &= that.value__; }
constexpr auto file_attributes::operator^=(file_attributes const& that) & -> void { value__ ^= that.value__; }
[[nodiscard]] constexpr auto file_attributes::operator|(file_attributes const& that) const& -> file_attributes { return value__ | that.value__; }
[[nodiscard]] constexpr auto file_attributes::operator&(file_attributes const& that) const& -> file_attributes { return value__ & that.value__; }
[[nodiscard]] constexpr auto file_attributes::operator^(file_attributes const& that) const& -> file_attributes { return value__ ^ that.value__; }
[[nodiscard]] constexpr auto file_attributes::has(file_attributes const& that) & -> bool { return value__ & that.value__; }
constexpr auto file_attributes::set(file_attributes const& that) & -> void { value__ |= that.value__; }
constexpr auto file_attributes::clear(file_attributes const& that) & -> void { value__ &= ~that.value__; }
inline constexpr file_attributes file_attributes::cached = 1;

inline constexpr file_attributes file_attributes::current = 2;

inline constexpr file_attributes file_attributes::obsolete = 4;

inline constexpr file_attributes file_attributes::cached_and_current = cached | current;

inline constexpr file_attributes file_attributes::none = 0;

[[nodiscard]] auto file_attributes::to_string() const& -> std::string{

    std::string ret {"("}; 

    std::string comma {}; 
    if ((*this) == none) {return "(none)"; }
    if (((*this) & cached) == cached) {ret += comma + "cached";comma = ", ";}
    if (((*this) & current) == current) {ret += comma + "current";comma = ", ";}
    if (((*this) & obsolete) == obsolete) {ret += comma + "obsolete";comma = ", ";}
    if (((*this) & cached_and_current) == cached_and_current) {ret += comma + "cached_and_current";comma = ", ";}
    return ret + ")"; 
    }

    auto operator<<(std::ostream& o, cpp2::in<file_attributes> val) -> std::ostream&{o << CPP2_UFCS_0(to_string, val);return o; }
#line 33 "pure2-enum.cpp2"
auto main() -> int{
    auto janus {duality::second}; 
    std::cout << "janus is initially " + cpp2::to_string(CPP2_UFCS_0(to_string, janus)) + "\n";
    CPP2_UFCS(flip, janus, janus);
    std::cout << "janus is flipped to " + cpp2::to_string(CPP2_UFCS_0(to_string, std::move(janus))) + "\n";

    // x : skat_game = 9;               // error, can't construct skat_game from integer

    skat_game x {skat_game::clubs}; 
    auto x2 {skat_game::diamonds}; 
    x2 = x;

    // if x == 9 { }                    // error, can't compare skat_game and integer
    // if x == rgb::red { }             // error, can't compare skat_game and rgb color

    std::cout << "x.to_string() is " + cpp2::to_string(CPP2_UFCS_0(to_string, x)) + "\n";
    std::cout << "x2.to_string() is " + cpp2::to_string(CPP2_UFCS_0(to_string, std::move(x2))) + "\n";
    std::cout << "using << prints " << x << "\n";

    std::cout << "with if else: ";
    if (x == skat_game::diamonds) {     // ok, can compare two skat_games
        std::cout << "diamonds";
    }
    else {if (skat_game::hearts == x) { // ok, in either order
        std::cout << "hearts";
    }
    else {if (cpp2::is(x, (skat_game::spades))) {// ok, using is
        std::cout << "spades";
    }
    else {if (cpp2::is(skat_game::clubs, (x))) {// ok, using is
        std::cout << "clubs";
    }
    else {
        std::cout << "not a suit";
    }}}}

    std::cout << "\nwith inspect: " << [&] () -> std::string { auto&& __expr = x;
        if (cpp2::is(__expr, (skat_game::diamonds))) { if constexpr( requires{"diamonds";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("diamonds")),std::string> ) return "diamonds"; else return std::string{}; else return std::string{}; }
        else if (cpp2::is(__expr, skat_game::hearts)) { if constexpr( requires{"hearts";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("hearts")),std::string> ) return "hearts"; else return std::string{}; else return std::string{}; }
        else if (cpp2::is(__expr, skat_game::spades)) { if constexpr( requires{"spades";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("spades")),std::string> ) return "spades"; else return std::string{}; else return std::string{}; }
        else if (cpp2::is(__expr, skat_game::clubs)) { if constexpr( requires{"clubs";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("clubs")),std::string> ) return "clubs"; else return std::string{}; else return std::string{}; }
        else return "not a suit"; }
    () << "\n\n";

    // x = 9;                           // error, can't assign skat_game from integer
    // x = rgb::red;                    // error, can't assign skat_game from rgb color

    x = skat_game::diamonds;        // ok, can assign one skat_game from another

    std::cout << "file_attributes::cached.get_raw_value() is " + cpp2::to_string(CPP2_UFCS_0(get_raw_value, file_attributes::cached)) + "\n";
    std::cout << "file_attributes::current.get_raw_value() is " + cpp2::to_string(CPP2_UFCS_0(get_raw_value, file_attributes::current)) + "\n";
    std::cout << "file_attributes::obsolete.get_raw_value() is " + cpp2::to_string(CPP2_UFCS_0(get_raw_value, file_attributes::obsolete)) + "\n";
    std::cout << "file_attributes::cached_and_current.get_raw_value() is " + cpp2::to_string(CPP2_UFCS_0(get_raw_value, file_attributes::cached_and_current)) + "\n";

    file_attributes f {file_attributes::cached_and_current}; 
    f &= file_attributes::cached | file_attributes::obsolete;
    std::cout << "f. get_raw_value() is " + cpp2::to_string(CPP2_UFCS_0(get_raw_value, f)) + "\n";

    auto f2 {file_attributes::cached}; 
    std::cout << "f2.get_raw_value() is " + cpp2::to_string(CPP2_UFCS_0(get_raw_value, f2)) + "\n";

    std::cout << "f  is " << f  << "\n";
    std::cout << "f2 is " << f2 << "\n";

    CPP2_UFCS(clear, f2, f2);
    std::cout << "f2 is " << f2 << "\n";
    CPP2_UFCS(set, f2, file_attributes::cached);
    std::cout << "f2 is " << f2 << "\n";

    std::cout << "f. get_raw_value() is " + cpp2::to_string(CPP2_UFCS_0(get_raw_value, f)) + "\n";
    std::cout << "f2.get_raw_value() is " + cpp2::to_string(CPP2_UFCS_0(get_raw_value, f2)) + "\n";

    std::cout << "f  is (f2) is " + cpp2::to_string(cpp2::is(f, (f2))) + "\n";
    std::cout << "f2 is (f ) is " + cpp2::to_string(cpp2::is(f2, (f))) + "\n\n";

    CPP2_UFCS(clear, f, f2);
    CPP2_UFCS(set, f, file_attributes::current | f2);
    f  |= file_attributes::obsolete;
    f2 |= file_attributes::current;

    std::cout << "f  is " << f  << "\n";
    std::cout << "f2 is " << f2 << "\n";
    std::cout << "f. get_raw_value() is " + cpp2::to_string(CPP2_UFCS_0(get_raw_value, f)) + "\n";
    std::cout << "f2.get_raw_value() is " + cpp2::to_string(CPP2_UFCS_0(get_raw_value, f2)) + "\n";
    std::cout << "f  == f2   is " + cpp2::to_string(f  == f2  ) + "\n";
    std::cout << "f  is (f2) is " + cpp2::to_string(cpp2::is(f, (f2))) + "\n";
    std::cout << "f2 is (f ) is " + cpp2::to_string(cpp2::is(f2, (f))) + "\n";
    std::cout << "(f & f2) == f2 is " + cpp2::to_string((f & f2) == f2) + "\n";

    std::cout << "inspecting f: " << [&] () -> std::string { auto&& __expr = std::move(f);
        if (cpp2::is(__expr, (file_attributes::current))) { if constexpr( requires{"exactly 'current'";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("exactly 'current'")),std::string> ) return "exactly 'current'"; else return std::string{}; else return std::string{}; }
        else if (cpp2::is(__expr, cpp2::has_flags(std::move(f2)))) { if constexpr( requires{"includes all f2's flags ('cached' and 'current')";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("includes all f2's flags ('cached' and 'current')")),std::string> ) return "includes all f2's flags ('cached' and 'current')"; else return std::string{}; else return std::string{}; }
        else return "something else"; }
    () << "\n";
}

