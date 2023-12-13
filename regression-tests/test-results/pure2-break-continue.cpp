
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-break-continue.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-break-continue.cpp2"

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

#line 177 "pure2-break-continue.cpp2"
auto for_continue_outer() -> void;

#line 194 "pure2-break-continue.cpp2"
auto for_break_inner() -> void;

#line 211 "pure2-break-continue.cpp2"
auto for_break_outer() -> void;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-break-continue.cpp2"

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
        for( ; cpp2::cmp_less(j,3); ++j ) {{
#line 26 "pure2-break-continue.cpp2"
            std::cout << i << j << " ";
            if (j == 1) {
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
    for( ; cpp2::cmp_less(i,3); ++i ) {{
#line 40 "pure2-break-continue.cpp2"
        auto j {0}; 
        for( ; cpp2::cmp_less(j,3); ++j ) {
            std::cout << i << j << " ";
            if (j == 1) {
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
        for( ; cpp2::cmp_less(j,3); ++j ) {{
#line 58 "pure2-break-continue.cpp2"
            std::cout << i << j << " ";
            if (j == 1) {
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
    for( ; cpp2::cmp_less(i,3); ++i ) {{
#line 72 "pure2-break-continue.cpp2"
        auto j {0}; 
        for( ; cpp2::cmp_less(j,3); ++j ) {
            std::cout << i << j << " ";
            if (j == 1) {
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
        do {{
#line 90 "pure2-break-continue.cpp2"
            std::cout << i << j << " ";
            if (j == 1) {
                goto CONTINUE_89_9;
            }
            std::cout << "inner ";
        } CPP2_CONTINUE_BREAK(89_9) }
#line 89 "pure2-break-continue.cpp2"
         while ( [&]{ 

#line 96 "pure2-break-continue.cpp2"
        ++j ; return true; }() && cpp2::cmp_less(j,3));

        std::cout << "outer ";
    } while ( [&]{ 
    ++i ; return true; }() && cpp2::cmp_less(i,3));
}

auto do_continue_outer() -> void
{
    auto i {0}; 
    do {{
#line 107 "pure2-break-continue.cpp2"
        auto j {0}; 
        do {
            std::cout << i << j << " ";
            if (j == 1) {
                goto CONTINUE_106_5;
            }
            std::cout << "inner ";
        } while ( [&]{ 
        ++j ; return true; }() && cpp2::cmp_less(j,3));

        std::cout << "outer ";
    } CPP2_CONTINUE_BREAK(106_5) }
#line 106 "pure2-break-continue.cpp2"
     while ( [&]{ 

#line 119 "pure2-break-continue.cpp2"
    ++i ; return true; }() && cpp2::cmp_less(i,3));
}

auto do_break_inner() -> void
{
    auto i {0}; 
    do {
        auto j {0}; 
        do {{
#line 128 "pure2-break-continue.cpp2"
            std::cout << i << j << " ";
            if (j == 1) {
                goto BREAK_127_9;
            }
            std::cout << "inner ";
        } CPP2_CONTINUE_BREAK(127_9) }
#line 127 "pure2-break-continue.cpp2"
         while ( [&]{ 

#line 134 "pure2-break-continue.cpp2"
        ++j ; return true; }() && cpp2::cmp_less(j,3));

        std::cout << "outer ";
    } while ( [&]{ 
    ++i ; return true; }() && cpp2::cmp_less(i,3));
}

auto do_break_outer() -> void
{
    auto i {0}; 
    do {{
#line 145 "pure2-break-continue.cpp2"
        auto j {0}; 
        do {
            std::cout << i << j << " ";
            if (j == 1) {
                goto BREAK_144_5;
            }
            std::cout << "inner ";
        } while ( [&]{ 
        ++j ; return true; }() && cpp2::cmp_less(j,3));

        std::cout << "outer ";
    } CPP2_CONTINUE_BREAK(144_5) }
#line 144 "pure2-break-continue.cpp2"
     while ( [&]{ 

#line 157 "pure2-break-continue.cpp2"
    ++i ; return true; }() && cpp2::cmp_less(i,3));
}

auto for_continue_inner() -> void
{
    std::vector vi {0, 1, 2}; 
    for ( auto const& i : vi ) {
        std::vector vj {0, 1, 2}; 
        for ( auto const& j : vj ) {{
#line 166 "pure2-break-continue.cpp2"
            std::cout << i << j << " ";
            if (j == 1) {
                goto CONTINUE_165_9;
            }
            std::cout << "inner ";
        } CPP2_CONTINUE_BREAK(165_9) }

#line 173 "pure2-break-continue.cpp2"
        std::cout << "outer ";
    }
}

auto for_continue_outer() -> void
{
    std::vector vi {0, 1, 2}; 
    for ( auto const& i : vi ) {{
#line 181 "pure2-break-continue.cpp2"
        std::vector vj {0, 1, 2}; 
        for ( auto const& j : vj ) {
            std::cout << i << j << " ";
            if (j == 1) {
                goto CONTINUE_180_5;
            }
            std::cout << "inner ";
        }

        std::cout << "outer ";
    } CPP2_CONTINUE_BREAK(180_5) }
#line 192 "pure2-break-continue.cpp2"
}

auto for_break_inner() -> void
{
    std::vector vi {0, 1, 2}; 
    for ( auto const& i : vi ) {
        std::vector vj {0, 1, 2}; 
        for ( auto const& j : vj ) {{
#line 200 "pure2-break-continue.cpp2"
            std::cout << i << j << " ";
            if (j == 1) {
                goto BREAK_199_9;
            }
            std::cout << "inner ";
        } CPP2_CONTINUE_BREAK(199_9) }

#line 207 "pure2-break-continue.cpp2"
        std::cout << "outer ";
    }
}

auto for_break_outer() -> void
{
    std::vector vi {0, 1, 2}; 
    for ( auto const& i : vi ) {{
#line 215 "pure2-break-continue.cpp2"
        std::vector vj {0, 1, 2}; 
        for ( auto const& j : vj ) {
            std::cout << i << j << " ";
            if (j == 1) {
                goto BREAK_214_5;
            }
            std::cout << "inner ";
        }

        std::cout << "outer ";
    } CPP2_CONTINUE_BREAK(214_5) }
#line 226 "pure2-break-continue.cpp2"
}

