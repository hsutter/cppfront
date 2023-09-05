
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
class skat_game {
private: cpp2::strict_value<cpp2::i8,skat_game> value {}; private: explicit skat_game(cpp2::in<cpp2::strict_value<cpp2::i8,skat_game>> value_);

private: auto operator=(cpp2::in<cpp2::strict_value<cpp2::i8,skat_game>> value_) -> skat_game& ;
public: auto static constexpr diamonds = cpp2::strict_value<cpp2::i8,skat_game>(9);
public: auto static constexpr hearts = cpp2::strict_value<cpp2::i8,skat_game>(10);
public: auto static constexpr spades = cpp2::strict_value<cpp2::i8,skat_game>(11);
public: auto static constexpr clubs = cpp2::strict_value<cpp2::i8,skat_game>(12);
public: auto static constexpr grand = cpp2::strict_value<cpp2::i8,skat_game>(20);
public: auto static constexpr null = cpp2::strict_value<cpp2::i8,skat_game>(23);
public: [[nodiscard]] auto operator<=>(skat_game const& that) const& -> std::strong_ordering = default;
public: skat_game(skat_game const& that);
public: auto operator=(skat_game const& that) -> skat_game& ;
public: skat_game(skat_game&& that) noexcept;
public: auto operator=(skat_game&& that) noexcept -> skat_game& ;
public: explicit skat_game();

#line 4 "pure2-enum.cpp2"
             // 10
             // 11
             // 12

#line 9 "pure2-enum.cpp2"
};

class rgb {
private: cpp2::strict_value<cpp2::i8,rgb> value {}; private: explicit rgb(cpp2::in<cpp2::strict_value<cpp2::i8,rgb>> value_);

private: auto operator=(cpp2::in<cpp2::strict_value<cpp2::i8,rgb>> value_) -> rgb& ;
public: auto static constexpr red = cpp2::strict_value<cpp2::i8,rgb>(0);
public: auto static constexpr green = cpp2::strict_value<cpp2::i8,rgb>(1);
public: auto static constexpr blue = cpp2::strict_value<cpp2::i8,rgb>(2);
public: [[nodiscard]] auto operator<=>(rgb const& that) const& -> std::strong_ordering = default;
public: rgb(rgb const& that);
public: auto operator=(rgb const& that) -> rgb& ;
public: rgb(rgb&& that) noexcept;
public: auto operator=(rgb&& that) noexcept -> rgb& ;
public: explicit rgb();

#line 12 "pure2-enum.cpp2"
             // 0
             // 1
             // 2
#line 15 "pure2-enum.cpp2"
};

class file_attributes {
private: cpp2::strict_value<cpp2::i8,file_attributes> value {}; private: explicit file_attributes(cpp2::in<cpp2::strict_value<cpp2::i8,file_attributes>> value_);

private: auto operator=(cpp2::in<cpp2::strict_value<cpp2::i8,file_attributes>> value_) -> file_attributes& ;
public: auto static constexpr cached = cpp2::strict_value<cpp2::i8,file_attributes>(1);
public: auto static constexpr current = cpp2::strict_value<cpp2::i8,file_attributes>(2);
public: auto static constexpr obsolete = cpp2::strict_value<cpp2::i8,file_attributes>(4);
public: auto static constexpr none = cpp2::strict_value<cpp2::i8,file_attributes>(0);
public: [[nodiscard]] auto operator<=>(file_attributes const& that) const& -> std::strong_ordering = default;
public: file_attributes(file_attributes const& that);
public: auto operator=(file_attributes const& that) -> file_attributes& ;
public: file_attributes(file_attributes&& that) noexcept;
public: auto operator=(file_attributes&& that) noexcept -> file_attributes& ;
public: explicit file_attributes();
public: auto operator|=(file_attributes const& that) & -> void;
public: auto operator&=(file_attributes const& that) & -> void;
public: auto operator^=(file_attributes const& that) & -> void;
public: [[nodiscard]] auto operator|(file_attributes const& that) const& -> auto;
public: [[nodiscard]] auto operator&(file_attributes const& that) const& -> auto;
public: [[nodiscard]] auto operator^(file_attributes const& that) const& -> auto;

#line 18 "pure2-enum.cpp2"
              // 1
              // 2
              // 4
#line 21 "pure2-enum.cpp2"
};

auto main() -> int;
    

//=== Cpp2 function definitions =================================================



    #line 1 "pure2-enum.cpp2"
skat_game::skat_game(cpp2::in<cpp2::strict_value<cpp2::i8,skat_game>> value_)
                                                                             : value{ value_ }{}
auto skat_game::operator=(cpp2::in<cpp2::strict_value<cpp2::i8,skat_game>> value_) -> skat_game& {
                                                                             value = value_;
                                                                             return *this;}
skat_game::skat_game(skat_game const& that)
                                : value{ that.value }{}
auto skat_game::operator=(skat_game const& that) -> skat_game& {
                                value = that.value;
                                return *this;}
skat_game::skat_game(skat_game&& that) noexcept
                                : value{ std::move(that).value }{}
auto skat_game::operator=(skat_game&& that) noexcept -> skat_game& {
                                value = std::move(that).value;
                                return *this;}
skat_game::skat_game(){}
rgb::rgb(cpp2::in<cpp2::strict_value<cpp2::i8,rgb>> value_)
                                                                       : value{ value_ }{}
auto rgb::operator=(cpp2::in<cpp2::strict_value<cpp2::i8,rgb>> value_) -> rgb& {
                                                                       value = value_;
                                                                       return *this;}
rgb::rgb(rgb const& that)
                                : value{ that.value }{}
auto rgb::operator=(rgb const& that) -> rgb& {
                                value = that.value;
                                return *this;}
rgb::rgb(rgb&& that) noexcept
                                : value{ std::move(that).value }{}
auto rgb::operator=(rgb&& that) noexcept -> rgb& {
                                value = std::move(that).value;
                                return *this;}
rgb::rgb(){}
file_attributes::file_attributes(cpp2::in<cpp2::strict_value<cpp2::i8,file_attributes>> value_)
                                                                                   : value{ value_ }{}
auto file_attributes::operator=(cpp2::in<cpp2::strict_value<cpp2::i8,file_attributes>> value_) -> file_attributes& {
                                                                                   value = value_;
                                                                                   return *this;}
file_attributes::file_attributes(file_attributes const& that)
                                : value{ that.value }{}
auto file_attributes::operator=(file_attributes const& that) -> file_attributes& {
                                value = that.value;
                                return *this;}
file_attributes::file_attributes(file_attributes&& that) noexcept
                                : value{ std::move(that).value }{}
auto file_attributes::operator=(file_attributes&& that) noexcept -> file_attributes& {
                                value = std::move(that).value;
                                return *this;}
file_attributes::file_attributes(){}
auto file_attributes::operator|=(file_attributes const& that) & -> void{value |= that.value;}
auto file_attributes::operator&=(file_attributes const& that) & -> void{value &= that.value;}
auto file_attributes::operator^=(file_attributes const& that) & -> void{value ^= that.value;}
[[nodiscard]] auto file_attributes::operator|(file_attributes const& that) const& -> auto { return value | that.value; }
[[nodiscard]] auto file_attributes::operator&(file_attributes const& that) const& -> auto { return value & that.value; }
[[nodiscard]] auto file_attributes::operator^(file_attributes const& that) const& -> auto { return value ^ that.value; }
#line 23 "pure2-enum.cpp2"
auto main() -> int{
    // x : skat_game = 9;               // error, can't construct skat_game from integer

    auto x {skat_game::clubs}; 

    // if x == 9 { }                    // error, can't compare skat_game and integer
    // if x == rgb::red { }             // error, can't compare skat_game and rgb color

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
    () << std::endl;

    // x = 9;                           // error, can't assign skat_game from integer
    // x = rgb::red;                    // error, can't assign skat_game from rgb color

    x = skat_game::diamonds;        // ok, can assign one skat_game from another

    auto f {file_attributes::current | file_attributes::cached}; 
    f &= file_attributes::cached  | file_attributes::obsolete;
    f |= file_attributes::current;

    auto f2 {file_attributes::cached}; 

    std::cout << "f  as int  is " + cpp2::to_string(cpp2::as_<int>(f)) + "\n";
    std::cout << "f2 as int  is " + cpp2::to_string(cpp2::as_<int>(f2)) + "\n";
    std::cout << "f  == f2   is " + cpp2::to_string(std::move(f) == std::move(f2)) + "\n";

    // The following are still in progress

    // std::cout << "f  is (f2) is (f  is (f2))$\n";
    // std::cout << "f2 is (f ) is (f2 is (f ))$\n";

    // if f is (file_attributes::cached  ) { std::cout << "cached ";   }
    // if f is (file_attributes::current ) { std::cout << "current ";  }
    // if f is (file_attributes::obsolete) { std::cout << "obsolete "; }
    // if f is (file_attributes::none    ) { std::cout << "none ";     }
    // std::cout << "\n";
}

