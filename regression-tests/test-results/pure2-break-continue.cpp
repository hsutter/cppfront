
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================


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


//=== Cpp2 function definitions =================================================


#line 2 "pure2-break-continue.cpp2"
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
    for( ; cpp2::cmp_less(i,3); ++i ) {
        auto j {0}; 
        for( ; cpp2::cmp_less(j,3); ++j ) {
#line 25 "pure2-break-continue.cpp2"
        {
            std::cout << i << j << " ";
            if (j==1) {
                goto CONTINUE_25_9;
            }
            std::cout << "inner ";
        } CPP2_CONTINUE_BREAK(25_9) }
#line 32 "pure2-break-continue.cpp2"
        std::cout << "outer ";
    }
}

auto while_continue_outer() -> void
{
    auto i {0}; 
    for( ; cpp2::cmp_less(i,3); ++i ) {
#line 39 "pure2-break-continue.cpp2"
    {
        auto j {0}; 
        for( ; cpp2::cmp_less(j,3); ++j ) {
            std::cout << i << j << " ";
            if (j==1) {
                goto CONTINUE_39_5;
            }
            std::cout << "inner ";
        }
        std::cout << "outer ";
    } CPP2_CONTINUE_BREAK(39_5) }
#line 50 "pure2-break-continue.cpp2"
}

auto while_break_inner() -> void
{
    auto i {0}; 
    for( ; cpp2::cmp_less(i,3); ++i ) {
        auto j {0}; 
        for( ; cpp2::cmp_less(j,3); ++j ) {
#line 57 "pure2-break-continue.cpp2"
        {
            std::cout << i << j << " ";
            if (j==1) {
                goto BREAK_57_9;
            }
            std::cout << "inner ";
        } CPP2_CONTINUE_BREAK(57_9) }
#line 64 "pure2-break-continue.cpp2"
        std::cout << "outer ";
    }
}

auto while_break_outer() -> void
{
    auto i {0}; 
    for( ; cpp2::cmp_less(i,3); ++i ) {
#line 71 "pure2-break-continue.cpp2"
    {
        auto j {0}; 
        for( ; cpp2::cmp_less(j,3); ++j ) {
            std::cout << i << j << " ";
            if (j==1) {
                goto BREAK_71_5;
            }
            std::cout << "inner ";
        }
        std::cout << "outer ";
    } CPP2_CONTINUE_BREAK(71_5) }
#line 82 "pure2-break-continue.cpp2"
}

auto do_continue_inner() -> void
{
    auto i {0}; 
    do {
        auto j {0}; 
        do {
#line 89 "pure2-break-continue.cpp2"
        {
            std::cout << i << j << " ";
            if (j==1) {
                goto CONTINUE_89_9;
            }
            std::cout << "inner ";
        } CPP2_CONTINUE_BREAK(89_9) }
#line 89 "pure2-break-continue.cpp2"
         while ( 

#line 96 "pure2-break-continue.cpp2"
        cpp2::cmp_less(j,3) && [&]{ ++j ; return true; }() );

        std::cout << "outer ";
    } while ( 
    cpp2::cmp_less(i,3) && [&]{ ++i ; return true; }() );
}

auto do_continue_outer() -> void
{
    auto i {0}; 
    do {
#line 106 "pure2-break-continue.cpp2"
    {
        auto j {0}; 
        do {
            std::cout << i << j << " ";
            if (j==1) {
                goto CONTINUE_106_5;
            }
            std::cout << "inner ";
        } while ( 
        cpp2::cmp_less(j,3) && [&]{ ++j ; return true; }() );

        std::cout << "outer ";
    } CPP2_CONTINUE_BREAK(106_5) }
#line 106 "pure2-break-continue.cpp2"
     while ( 

#line 119 "pure2-break-continue.cpp2"
    cpp2::cmp_less(i,3) && [&]{ ++i ; return true; }() );
}

auto do_break_inner() -> void
{
    auto i {0}; 
    do {
        auto j {0}; 
        do {
#line 127 "pure2-break-continue.cpp2"
        {
            std::cout << i << j << " ";
            if (j==1) {
                goto BREAK_127_9;
            }
            std::cout << "inner ";
        } CPP2_CONTINUE_BREAK(127_9) }
#line 127 "pure2-break-continue.cpp2"
         while ( 

#line 134 "pure2-break-continue.cpp2"
        cpp2::cmp_less(j,3) && [&]{ ++j ; return true; }() );

        std::cout << "outer ";
    } while ( 
    cpp2::cmp_less(i,3) && [&]{ ++i ; return true; }() );
}

auto do_break_outer() -> void
{
    auto i {0}; 
    do {
#line 144 "pure2-break-continue.cpp2"
    {
        auto j {0}; 
        do {
            std::cout << i << j << " ";
            if (j==1) {
                goto BREAK_144_5;
            }
            std::cout << "inner ";
        } while ( 
        cpp2::cmp_less(j,3) && [&]{ ++j ; return true; }() );

        std::cout << "outer ";
    } CPP2_CONTINUE_BREAK(144_5) }
#line 144 "pure2-break-continue.cpp2"
     while ( 

#line 157 "pure2-break-continue.cpp2"
    cpp2::cmp_less(i,3) && [&]{ ++i ; return true; }() );
}

auto for_continue_inner() -> void
{
    std::vector vi {0, 1, 2}; 
    auto counter {0}; 
    for ( auto const& i : vi )  { do {
        std::vector vj {0, 1, 2}; 
        for ( auto const& j : vj ) {
#line 166 "pure2-break-continue.cpp2"
        {
            std::cout << i << j << " ";
            if (j==1) {
                goto CONTINUE_166_9;
            }
            std::cout << "inner ";
        } CPP2_CONTINUE_BREAK(166_9) }

#line 174 "pure2-break-continue.cpp2"
        std::cout << "outer ";
    } while (false); ++counter; }
}

auto for_continue_outer() -> void
{
    std::vector vi {0, 1, 2}; 
    auto counter {0}; 
    for ( auto const& i : vi ) {
#line 182 "pure2-break-continue.cpp2"
     { do {
        std::vector vj {0, 1, 2}; 
        for ( auto const& j : vj ) {
            std::cout << i << j << " ";
            if (j==1) {
                goto CONTINUE_182_5;
            }
            std::cout << "inner ";
        }

        std::cout << "outer ";
    } while (false); ++counter; } CPP2_CONTINUE_BREAK(182_5) }
#line 194 "pure2-break-continue.cpp2"
}

auto for_break_inner() -> void
{
    std::vector vi {0, 1, 2}; 
    auto counter {0}; 
    for ( auto const& i : vi )  { do {
        std::vector vj {0, 1, 2}; 
        for ( auto const& j : vj ) {
#line 202 "pure2-break-continue.cpp2"
        {
            std::cout << i << j << " ";
            if (j==1) {
                goto BREAK_202_9;
            }
            std::cout << "inner ";
        } CPP2_CONTINUE_BREAK(202_9) }

#line 210 "pure2-break-continue.cpp2"
        std::cout << "outer ";
    } while (false); ++counter; }
}

auto for_break_outer() -> void
{
    std::vector vi {0, 1, 2}; 
    auto counter {0}; 
    for ( auto const& i : vi ) {
#line 218 "pure2-break-continue.cpp2"
     { do {
        std::vector vj {0, 1, 2}; 
        for ( auto const& j : vj ) {
            std::cout << i << j << " ";
            if (j==1) {
                goto BREAK_218_5;
            }
            std::cout << "inner ";
        }

        std::cout << "outer ";
    } while (false); ++counter; } CPP2_CONTINUE_BREAK(218_5) }
#line 230 "pure2-break-continue.cpp2"
}

