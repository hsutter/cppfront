
//  Copyright 2022-2024 Herb Sutter
//  SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//  
//  Part of the Cppfront Project, under the Apache License v2.0 with LLVM Exceptions.
//  See https://github.com/hsutter/cppfront/blob/main/LICENSE for license information.

//#include "extrinsic_storage_std_locked.h"
#include "extrinsic_storage.h"

#include <chrono>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <source_location>
#include <thread>
#include <vector>


//-------------------------------------------------------------------------------
//  Union instrumentation API for compiler integration
// 
//  Template parameters
//      Tag             discriminator tag to store for each object (uintNN_t where
//                      NN is large enough to hold the #alternatives in the union)
//
//  For an object U of union type that
//  has a unique address, when              Inject a call to this (zero-based alternative #s)
//
//    U is created initialized                on_set_alternative(&U,0) = the first alternative# is active
//
//    U is created uninitialized              on_set_alternative(&U,invalid)
//
//    U.A = xxx (alt A is assigned to)        on_set_alternative(&U,#A)
//
//    U or U.A is passed to a function by     on_set_alternative(&U,unknown)
//      pointer/reference to non-const
//      and we don't know the function
//      is compiled in this mode
//
//    U.A (alt A is otherwise used)           on_get_alternative(&U,#A)
//      and A is not a common initial
//      sequence
//
//    U is destroyed / goes out of scope      on_destroy(&U)
//
//  That's it. Here's an example:
//    {
//      union Test { int a; double b; };
//      Test t = {42};                        union_registry<>::on_set_alternative(&u,0);
//      std::cout << t.a;                     union_registry<>::on_get_alternative(&u,0);
//      t.b = 3.14159;                        union_registry<>::on_set_alternative(&u,1);
//      std::cout << t.b;                     union_registry<>::on_get_alternative(&u,1);
//    }                                       union_registry<>::on_destroy(&u);
//
//  For all unions with up to 254 alternatives, use union_registry<>
//  For all unions with between 255 and 16k-2 alternatives, use union_registry<uint16_t>
//  If you find a union with >16k-2 alternatives, email me the story and use union_registry<uint32_t>
//
template<typename Tag = uint8_t>
class union_registry {
    static inline auto tags    = extrinsic_storage<Tag>{};
    static inline auto log     = std::ofstream{ "union-violations.log" };
public:
    static inline auto invalid = std::numeric_limits<Tag>::max();
    static inline auto unknown = std::numeric_limits<Tag>::max()-1;

    static inline auto on_destroy(void* pobj) noexcept -> void { tags.erase(pobj); }

    static inline auto on_set_alternative(void* pobj, uint32_t alt) noexcept -> void {
        if (auto p = tags.find_or_insert(pobj)) { *p = alt; }
    }
    
    static inline auto on_get_alternative(void* pobj, uint32_t alt, std::source_location where = std::source_location::current()) -> void {
        if (auto active = tags.find(pobj);
            active                  // if we have discriminator info for this union
            && *active != alt       // and the discriminator not what is expected
            && *active != unknown   // and is not unknown
            )
        { 
            log << where.file_name() << '(' << where.line()
                << "): union type safety violation - active member " << (*active == invalid ? "invalid" : std::to_string(*active))
                << ", attempted to access " << alt << "\n";
        }
    }
};


//-------------------------------------------------------------------------------
//  Sample union
//
union Union {
    char        alt0;
    int         alt1;
    long double alt2;
};


//-------------------------------------------------------------------------------
//  Multithreaded test harness
//
template <bool SafetyChecks = false>
auto test(int threads = 1) -> void
{
    auto fault_inject_counter = std::atomic<int>{9900};
    auto size = 10'000/threads;

    //  1M unions, 10K at a time
    auto run = [&] {
        for (auto iteration = 0; iteration < 100; ++iteration)
        {
            auto us = std::vector<Union>{};
            us.reserve(size);
            for (int i = 0; i < size; ++i) {
                us.emplace_back('x');
                if constexpr (SafetyChecks) { union_registry<>::on_set_alternative(&us[i],0); } // 1st access for this union
            }

            for (auto& u : us)
            {
                if (--fault_inject_counter != 0) {  // occasionally forget to set .alt1
                    u.alt1 = 123;
                    if constexpr (SafetyChecks) { union_registry<>::on_set_alternative(&u,1); } // 2nd
                }

                if constexpr (SafetyChecks) { union_registry<>::on_get_alternative(&u,1); } // 3rd
                u.alt1 += 456;

                u.alt2 = 12.345678;
                if constexpr (SafetyChecks) { union_registry<>::on_set_alternative(&u,2); } // 4th

                if constexpr (SafetyChecks) { union_registry<>::on_get_alternative(&u,2); } // 5th
                u.alt2 += 3.14169265;

                u.alt0 = 'y';
                if constexpr (SafetyChecks) { union_registry<>::on_set_alternative(&u,0); } // 6th

                if constexpr (SafetyChecks) { union_registry<>::on_get_alternative(&u,0); } // 7th
                auto _ = u.alt0;

                u.alt2 = 3.1415926535;
                if constexpr (SafetyChecks) { union_registry<>::on_set_alternative(&u,2); } // 8th

                if constexpr (SafetyChecks) { union_registry<>::on_get_alternative(&u,2); } // 9th
                u.alt2 += 3.14169265;
            }

            for (int i = 0; i < size; ++i) {
                if constexpr (SafetyChecks) { union_registry<>::on_destroy(&us[i]); } // 10th and last
            }
        }
    };

    if (threads == 1) {
        run();
    }
    else {
        std::vector<std::jthread> thds;
        for (auto i = 0; i < threads; ++i) {
            thds.emplace_back( run );
        }
    }
}


class timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
    timer()                   : start{ std::chrono::high_resolution_clock::now() } { }
    auto microseconds() const { return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count(); }
};


int main()
{
    auto tot_raw = int64_t{0};
    auto tot_chk = int64_t{0};

    //  Repeat test sequence a couple of times
    for (auto reps = 0; reps < 2; ++reps)
    {
       //  Run "raw" vs "checked" test for 1, 2, 4, 8, 16, 32, and 64 threads
       for (auto i = 1; i <= 64; i *= 2)
       {
           std::cout << "# threads: " << i << "\n";

           //  First without checks
           auto t = timer{};
           test(i);
           auto raw_time = t.microseconds();
           std::cout << "  raw:     " << print(raw_time) << "\n";
           tot_raw += raw_time;

           //  Then with checks, via specifying <true>
           t = timer{};
           test<true>(i);
           auto chk_time = t.microseconds();
           std::cout << "  checked: " << print(chk_time) << "\n";
           tot_chk += chk_time;
       }
    }

    std::cout << "totals\n"
              << "  raw:     " << print(tot_raw) << "\n"
              << "  checked: " << print(tot_chk) << "\n";

}
