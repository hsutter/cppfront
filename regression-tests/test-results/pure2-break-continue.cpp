// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 2 "pure2-break-continue.cpp2"
[[nodiscard]] auto main() -> int;
#line 20 "pure2-break-continue.cpp2"
auto while_continue_inner() -> void;
#line 36 "pure2-break-continue.cpp2"
auto while_continue_outer() -> void;
#line 52 "pure2-break-continue.cpp2"
auto while_break_inner() -> void;
#line 68 "pure2-break-continue.cpp2"
auto while_break_outer() -> void;
#line 84 "pure2-break-continue.cpp2"
auto do_continue_inner() -> void;
#line 103 "pure2-break-continue.cpp2"
auto do_continue_outer() -> void;
#line 122 "pure2-break-continue.cpp2"
auto do_break_inner() -> void;
#line 141 "pure2-break-continue.cpp2"
auto do_break_outer() -> void;
#line 160 "pure2-break-continue.cpp2"
auto for_continue_inner() -> void;
#line 178 "pure2-break-continue.cpp2"
auto for_continue_outer() -> void;
#line 196 "pure2-break-continue.cpp2"
auto for_break_inner() -> void;
#line 214 "pure2-break-continue.cpp2"
auto for_break_outer() -> void;

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-break-continue.cpp2"

[[nodiscard]] auto main() -> int
{
    std::cout <<   "while_continue_inner:\n  "; while_continue_inner();
    std::cout << "\nwhile_continue_outer:\n  "; while_continue_outer();
    std::cout << "\nwhile_break_inner:\n  ";    while_break_inner();
    std::cout << "\nwhile_break_outer:\n  ";    while_break_outer();

    std::cout <<  "\n\ndo_continue_inner:\n  "; do_continue_inner();
    std::cout <<    "\ndo_continue_outer:\n  "; do_continue_outer();
    std::cout <<    "\ndo_break_inner:\n  ";    do_break_inner();
    std::cout <<    "\ndo_break_outer:\n  ";    do_break_outer();

    std::cout << "\n\nfor_continue_inner:\n  "; for_continue_inner();
    std::cout <<   "\nfor_continue_outer:\n  "; for_continue_outer();
    std::cout <<   "\nfor_break_inner:\n  ";    for_break_inner();
    std::cout <<   "\nfor_break_outer:\n  ";    for_break_outer();
}

auto while_continue_inner() -> void
{
    auto i {0}; 
    for( ;       cpp2::cmp_less(i,3); ++i ) {{
        auto j {0}; 
        for( ;       cpp2::cmp_less(j,3); ++j ) {{
            std::cout << i << j << " ";
            if (j == 1) {
                goto CONTINUE_25_9;
            }
            std::cout << "inner ";
        } CPP2_CONTINUE_BREAK(25_9) }
        std::cout << "outer ";
    } CPP2_CONTINUE_BREAK(23_5) }
}

auto while_continue_outer() -> void
{
    auto i {0}; 
    for( ;       cpp2::cmp_less(i,3); ++i ) {{
        auto j {0}; 
        for( ;       cpp2::cmp_less(j,3); ++j ) {{
            std::cout << i << j << " ";
            if (j == 1) {
                goto CONTINUE_39_5;
            }
            std::cout << "inner ";
        } CPP2_CONTINUE_BREAK(41_9) }
        std::cout << "outer ";
    } CPP2_CONTINUE_BREAK(39_5) }
}

auto while_break_inner() -> void
{
    auto i {0}; 
    for( ;       cpp2::cmp_less(i,3); ++i ) {{
        auto j {0}; 
        for( ;       cpp2::cmp_less(j,3); ++j ) {{
            std::cout << i << j << " ";
            if (j == 1) {
                goto BREAK_57_9;
            }
            std::cout << "inner ";
        } CPP2_CONTINUE_BREAK(57_9) }
        std::cout << "outer ";
    } CPP2_CONTINUE_BREAK(55_5) }
}

auto while_break_outer() -> void
{
    auto i {0}; 
    for( ;       cpp2::cmp_less(i,3); ++i ) {{
        auto j {0}; 
        for( ;       cpp2::cmp_less(j,3); ++j ) {{
            std::cout << i << j << " ";
            if (j == 1) {
                goto BREAK_71_5;
            }
            std::cout << "inner ";
        } CPP2_CONTINUE_BREAK(73_9) }
        std::cout << "outer ";
    } CPP2_CONTINUE_BREAK(71_5) }
}

auto do_continue_inner() -> void
{
    auto i {0}; 
    do {      {
        auto j {0}; 
        do {      {
            std::cout << i << j << " ";
            if (j == 1) {
                goto CONTINUE_89_9;
            }
            std::cout << "inner ";
        } CPP2_CONTINUE_BREAK(89_9) } while ( 
              cpp2::cmp_less(j,3) && [&]{ ++j ; return true; }() );

        std::cout << "outer ";
    } CPP2_CONTINUE_BREAK(87_5) } while ( 
          cpp2::cmp_less(i,3) && [&]{ ++i ; return true; }() );
}

auto do_continue_outer() -> void
{
    auto i {0}; 
    do {      {
        auto j {0}; 
        do {      {
            std::cout << i << j << " ";
            if (j == 1) {
                goto CONTINUE_106_5;
            }
            std::cout << "inner ";
        } CPP2_CONTINUE_BREAK(108_9) } while ( 
              cpp2::cmp_less(j,3) && [&]{ ++j ; return true; }() );

        std::cout << "outer ";
    } CPP2_CONTINUE_BREAK(106_5) } while ( 
          cpp2::cmp_less(i,3) && [&]{ ++i ; return true; }() );
}

auto do_break_inner() -> void
{
    auto i {0}; 
    do {      {
        auto j {0}; 
        do {      {
            std::cout << i << j << " ";
            if (j == 1) {
                goto BREAK_127_9;
            }
            std::cout << "inner ";
        } CPP2_CONTINUE_BREAK(127_9) } while ( 
              cpp2::cmp_less(j,3) && [&]{ ++j ; return true; }() );

        std::cout << "outer ";
    } CPP2_CONTINUE_BREAK(125_5) } while ( 
          cpp2::cmp_less(i,3) && [&]{ ++i ; return true; }() );
}

auto do_break_outer() -> void
{
    auto i {0}; 
    do {      {
        auto j {0}; 
        do {      {
            std::cout << i << j << " ";
            if (j == 1) {
                goto BREAK_144_5;
            }
            std::cout << "inner ";
        } CPP2_CONTINUE_BREAK(146_9) } while ( 
              cpp2::cmp_less(j,3) && [&]{ ++j ; return true; }() );

        std::cout << "outer ";
    } CPP2_CONTINUE_BREAK(144_5) } while ( 
          cpp2::cmp_less(i,3) && [&]{ ++i ; return true; }() );
}

auto for_continue_inner() -> void
{
    std::vector vi {0, 1, 2}; 
    auto counter {0}; 
    for ( auto&& cpp2_range = vi;     auto const& i : cpp2_range ) { { do {
        std::vector vj {0, 1, 2}; 
        for ( auto&& cpp2_range = vj;  auto const& j : cpp2_range ) {{
            std::cout << i << j << " ";
            if (j == 1) {
                goto CONTINUE_166_9;
            }
            std::cout << "inner ";
        } CPP2_CONTINUE_BREAK(166_9) }

        std::cout << "outer ";
    } while (false); ++counter; } CPP2_CONTINUE_BREAK(164_5) }
}

auto for_continue_outer() -> void
{
    std::vector vi {0, 1, 2}; 
    auto counter {0}; 
    for ( auto&& cpp2_range = vi;     auto const& i : cpp2_range ) { { do {
        std::vector vj {0, 1, 2}; 
        for ( auto&& cpp2_range = vj;  auto const& j : cpp2_range ) {{
            std::cout << i << j << " ";
            if (j == 1) {
                goto CONTINUE_182_5;
            }
            std::cout << "inner ";
        } CPP2_CONTINUE_BREAK(184_9) }

        std::cout << "outer ";
    } while (false); ++counter; } CPP2_CONTINUE_BREAK(182_5) }
}

auto for_break_inner() -> void
{
    std::vector vi {0, 1, 2}; 
    auto counter {0}; 
    for ( auto&& cpp2_range = vi;     auto const& i : cpp2_range ) { { do {
        std::vector vj {0, 1, 2}; 
        for ( auto&& cpp2_range = vj;  auto const& j : cpp2_range ) {{
            std::cout << i << j << " ";
            if (j == 1) {
                goto BREAK_202_9;
            }
            std::cout << "inner ";
        } CPP2_CONTINUE_BREAK(202_9) }

        std::cout << "outer ";
    } while (false); ++counter; } CPP2_CONTINUE_BREAK(200_5) }
}

auto for_break_outer() -> void
{
    std::vector vi {0, 1, 2}; 
    auto counter {0}; 
    for ( auto&& cpp2_range = vi;     auto const& i : cpp2_range ) { { do {
        std::vector vj {0, 1, 2}; 
        for ( auto&& cpp2_range = vj;  auto const& j : cpp2_range ) {{
            std::cout << i << j << " ";
            if (j == 1) {
                goto BREAK_218_5;
            }
            std::cout << "inner ";
        } CPP2_CONTINUE_BREAK(220_9) }

        std::cout << "outer ";
    } while (false); ++counter; } CPP2_CONTINUE_BREAK(218_5) }
}

