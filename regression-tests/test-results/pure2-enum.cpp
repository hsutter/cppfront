
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"


#line 2 "pure2-enum.cpp2"
class skat_game;
    

#line 11 "pure2-enum.cpp2"
class rgb;
    

#line 17 "pure2-enum.cpp2"
class file_attributes;
    

//=== Cpp2 type definitions and function declarations ===========================


#line 2 "pure2-enum.cpp2"
class skat_game: public cpp2::strict_value<cpp2::i8,skat_game,0> {
public: skat_game(cpp2::in<cpp2::strict_value<cpp2::i8,skat_game,0>> value);
public: auto static constexpr diamonds = cpp2::strict_value<cpp2::i8,skat_game,0>(9);
public: auto static constexpr hearts = cpp2::strict_value<cpp2::i8,skat_game,0>(10);
public: auto static constexpr spades = cpp2::strict_value<cpp2::i8,skat_game,0>(11);
public: auto static constexpr clubs = cpp2::strict_value<cpp2::i8,skat_game,0>(12);
public: auto static constexpr grand = cpp2::strict_value<cpp2::i8,skat_game,0>(20);
public: auto static constexpr null = cpp2::strict_value<cpp2::i8,skat_game,0>(23);
public: [[nodiscard]] static auto size() -> auto;
public: [[nodiscard]] static auto to_string(cpp2::in<cpp2::strict_value<cpp2::i8,skat_game,0>> value) -> std::string;
public: [[nodiscard]] auto to_string() const& -> std::string;
public: skat_game(skat_game const& that);
public: explicit skat_game();


             // 10
             // 11
             // 12

#line 9 "pure2-enum.cpp2"
};

class rgb: public cpp2::strict_value<cpp2::i8,rgb,0> {
public: rgb(cpp2::in<cpp2::strict_value<cpp2::i8,rgb,0>> value);
public: auto static constexpr red = cpp2::strict_value<cpp2::i8,rgb,0>(0);
public: auto static constexpr green = cpp2::strict_value<cpp2::i8,rgb,0>(1);
public: auto static constexpr blue = cpp2::strict_value<cpp2::i8,rgb,0>(2);
public: [[nodiscard]] static auto size() -> auto;
public: [[nodiscard]] static auto to_string(cpp2::in<cpp2::strict_value<cpp2::i8,rgb,0>> value) -> std::string;
public: [[nodiscard]] auto to_string() const& -> std::string;
public: rgb(rgb const& that);
public: explicit rgb();

             // 0
             // 1
             // 2
#line 15 "pure2-enum.cpp2"
};

class file_attributes: public cpp2::strict_value<cpp2::u8,file_attributes,1> {
public: file_attributes(cpp2::in<cpp2::strict_value<cpp2::u8,file_attributes,1>> value);
public: auto static constexpr cached = cpp2::strict_value<cpp2::u8,file_attributes,1>(1);
public: auto static constexpr current = cpp2::strict_value<cpp2::u8,file_attributes,1>(2);
public: auto static constexpr obsolete = cpp2::strict_value<cpp2::u8,file_attributes,1>(4);
public: auto static constexpr cached_and_current = cpp2::strict_value<cpp2::u8,file_attributes,1>(3);
public: auto static constexpr none = cpp2::strict_value<cpp2::u8,file_attributes,1>(0);
public: [[nodiscard]] static auto size() -> auto;
public: [[nodiscard]] static auto to_string(cpp2::in<cpp2::strict_value<cpp2::u8,file_attributes,1>> value) -> std::string;
public: [[nodiscard]] auto to_string() const& -> std::string;
public: file_attributes(file_attributes const& that);
public: explicit file_attributes();

              // 1
              // 2
              // 4

#line 22 "pure2-enum.cpp2"
};

auto main() -> int;
    

//=== Cpp2 function definitions =================================================



    skat_game::skat_game(cpp2::in<cpp2::strict_value<cpp2::i8,skat_game,0>> value)
                                                                                  : cpp2::strict_value<cpp2::i8,skat_game,0>{ value }{}
[[nodiscard]] auto skat_game::size() -> auto { return 6; }
[[nodiscard]] auto skat_game::to_string(cpp2::in<cpp2::strict_value<cpp2::i8,skat_game,0>> value) -> std::string{

    std::string ret {}; 
    if (value == diamonds) {ret = "diamonds";}
    if (value == hearts) {ret = "hearts";}
    if (value == spades) {ret = "spades";}
    if (value == clubs) {ret = "clubs";}
    if (value == grand) {ret = "grand";}
    if (value == null) {ret = "null";}
    if (CPP2_UFCS_0(empty, ret)) {ret = "(invalid skat_game enumerator value)";}
    return ret; 
    }

    [[nodiscard]] auto skat_game::to_string() const& -> std::string{return skat_game::to_string((*this)); }
skat_game::skat_game(skat_game const& that)
                                : cpp2::strict_value<cpp2::i8,skat_game,0>{ static_cast<cpp2::strict_value<cpp2::i8,skat_game,0> const&>(that) }{}
skat_game::skat_game()
                          : cpp2::strict_value<cpp2::i8,skat_game,0>{  }{}
rgb::rgb(cpp2::in<cpp2::strict_value<cpp2::i8,rgb,0>> value)
                                                                            : cpp2::strict_value<cpp2::i8,rgb,0>{ value }{}
[[nodiscard]] auto rgb::size() -> auto { return 3; }
[[nodiscard]] auto rgb::to_string(cpp2::in<cpp2::strict_value<cpp2::i8,rgb,0>> value) -> std::string{

    std::string ret {}; 
    if (value == red) {ret = "red";}
    if (value == green) {ret = "green";}
    if (value == blue) {ret = "blue";}
    if (CPP2_UFCS_0(empty, ret)) {ret = "(invalid rgb enumerator value)";}
    return ret; 
    }

    [[nodiscard]] auto rgb::to_string() const& -> std::string{return rgb::to_string((*this)); }
rgb::rgb(rgb const& that)
                                : cpp2::strict_value<cpp2::i8,rgb,0>{ static_cast<cpp2::strict_value<cpp2::i8,rgb,0> const&>(that) }{}
rgb::rgb()
                          : cpp2::strict_value<cpp2::i8,rgb,0>{  }{}
file_attributes::file_attributes(cpp2::in<cpp2::strict_value<cpp2::u8,file_attributes,1>> value)
                                                                                        : cpp2::strict_value<cpp2::u8,file_attributes,1>{ value }{}
[[nodiscard]] auto file_attributes::size() -> auto { return 5; }
[[nodiscard]] auto file_attributes::to_string(cpp2::in<cpp2::strict_value<cpp2::u8,file_attributes,1>> value) -> std::string{

    std::string ret {}; 

    std::string comma {}; 
    ret = "(";
    if ((value & cached) == cached) {ret += comma + "cached";comma = ", ";}
    if ((value & current) == current) {ret += comma + "current";comma = ", ";}
    if ((value & obsolete) == obsolete) {ret += comma + "obsolete";comma = ", ";}
    if ((value & cached_and_current) == cached_and_current) {ret += comma + "cached_and_current";comma = ", ";}
    if (value == none) {ret += comma + "none";comma = ", ";}
    if (CPP2_UFCS_0(empty, ret)) {ret = "(invalid file_attributes enumerator value)";}
    return ret + ")"; 
    }

    [[nodiscard]] auto file_attributes::to_string() const& -> std::string{return file_attributes::to_string((*this)); }
file_attributes::file_attributes(file_attributes const& that)
                                : cpp2::strict_value<cpp2::u8,file_attributes,1>{ static_cast<cpp2::strict_value<cpp2::u8,file_attributes,1> const&>(that) }{}
file_attributes::file_attributes()
                          : cpp2::strict_value<cpp2::u8,file_attributes,1>{  }{}
#line 24 "pure2-enum.cpp2"
auto main() -> int{
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

    file_attributes f {file_attributes::cached_and_current}; 
    f &= file_attributes::cached  | file_attributes::obsolete;

    auto f2 {file_attributes::cached}; 

    std::cout << "f  is " << f  << "\n";
    std::cout << "f2 is " << f2 << "\n";

    CPP2_UFCS(clear, f2, f2);
    std::cout << "f2 is " << f2 << "\n";
    CPP2_UFCS(set, f2, file_attributes::cached);
    std::cout << "f2 is " << f2 << "\n";

    std::cout << "f  as int  is " + cpp2::to_string(cpp2::as_<int>(f)) + "\n";
    std::cout << "f2 as int  is " + cpp2::to_string(cpp2::as_<int>(f2)) + "\n";

    std::cout << "f  is (f2) is " + cpp2::to_string(cpp2::is(f, (f2))) + "\n";
    std::cout << "f2 is (f ) is " + cpp2::to_string(cpp2::is(f2, (f))) + "\n\n";

    CPP2_UFCS(clear, f, f2);
    CPP2_UFCS(set, f, file_attributes::current | f2);
    f  |= file_attributes::obsolete;
    f2 |= file_attributes::current;

    std::cout << "f  is " << f  << "\n";
    std::cout << "f2 is " << f2 << "\n";
    std::cout << "f  as int  is " + cpp2::to_string(cpp2::as_<int>(f)) + "\n";
    std::cout << "f2 as int  is " + cpp2::to_string(cpp2::as_<int>(f2)) + "\n";
    std::cout << "f  == f2   is " + cpp2::to_string(f  == f2  ) + "\n";
    std::cout << "f  is (f2) is " + cpp2::to_string(cpp2::is(f, (f2))) + "\n";
    std::cout << "f2 is (f ) is " + cpp2::to_string(cpp2::is(f2, (f))) + "\n";
    std::cout << "(f & f2) == f2 is " + cpp2::to_string((f & f2) == f2) + "\n";

    std::cout << "inspecting: " << [&] () -> std::string { auto&& __expr = std::move(f);
        if (cpp2::is(__expr, (file_attributes::current))) { if constexpr( requires{"exactly 'current'";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("exactly 'current'")),std::string> ) return "exactly 'current'"; else return std::string{}; else return std::string{}; }
        else if (cpp2::is(__expr, cpp2::has_flags(std::move(f2)))) { if constexpr( requires{"includes all f2's flags ('cached' and 'current')";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("includes all f2's flags ('cached' and 'current')")),std::string> ) return "includes all f2's flags ('cached' and 'current')"; else return std::string{}; else return std::string{}; }
        else return "something else"; }
    () << "\n";
}

