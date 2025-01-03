
//  Copyright 2022-2024 Herb Sutter
//  SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//  
//  Part of the Cppfront Project, under the Apache License v2.0 with LLVM Exceptions.
//  See https://github.com/hsutter/cppfront/blob/main/LICENSE for license information.

#ifndef CPP2_EXPERIMENTAL_EXTRINSIC_STORAGE_H
#define CPP2_EXPERIMENTAL_EXTRINSIC_STORAGE_H

//  *****************************************************************
//  Enable/disable debug instrumentation and statistics printing here
constexpr inline auto debug_instrumentation = false;
//  *****************************************************************

#include <algorithm>
#include <array>
#include <atomic>
#include <cassert>
#include <cstdint>
#include <functional>
#include <iostream>
#include <memory>
#include <map>
#include <ranges>
#include <string>
#include <type_traits>


//-----------------------------------------------------------------------------------
//  Some helpers
//
auto print(std::integral auto val) -> std::string {
    auto ret = std::to_string(val % 10);
    auto pos = 0;
    while ((val /= 10) > 0) {
        if ((++pos % 3) == 0) { ret = ',' + ret; }
        ret = std::to_string(val % 10) + ret;
    }
    return ret;
}

constexpr inline auto is_prime(auto value) noexcept -> bool {
    constexpr int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, 1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597, 1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733, 1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 1823, 1831, 1847, 1861, 1867, 1871, 1873, 1877, 1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987, 1993, 1997, 1999, 2003, 2011, 2017, 2027, 2029, 2039, 2053, 2063, 2069, 2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129, 2131, 2137, 2141, 2143, 2153, 2161, 2179, 2203, 2207, 2213, 2221, 2237, 2239, 2243, 2251, 2267, 2269, 2273, 2281, 2287, 2293, 2297, 2309, 2311, 2333, 2339, 2341, 2347, 2351, 2357, 2371, 2377, 2381, 2383, 2389, 2393, 2399, 2411, 2417, 2423, 2437, 2441, 2447, 2459, 2467, 2473, 2477, 2503, 2521, 2531, 2539, 2543, 2549, 2551, 2557, 2579, 2591, 2593, 2609, 2617, 2621, 2633, 2647, 2657, 2659, 2663, 2671, 2677, 2683, 2687, 2689, 2693, 2699, 2707, 2711, 2713, 2719, 2729, 2731, 2741, 2749, 2753, 2767, 2777, 2789, 2791, 2797, 2801, 2803, 2819, 2833, 2837, 2843, 2851, 2857, 2861, 2879, 2887, 2897, 2903, 2909, 2917, 2927, 2939, 2953, 2957, 2963, 2969, 2971, 2999, 3001, 3011, 3019, 3023, 3037, 3041, 3049, 3061, 3067, 3079, 3083, 3089, 3109, 3119, 3121, 3137, 3163, 3167, 3169, 3181, 3187, 3191, 3203, 3209, 3217, 3221, 3229, 3251, 3253, 3257, 3259, 3271, 3299, 3301, 3307, 3313, 3319, 3323, 3329, 3331, 3343, 3347, 3359, 3361, 3371, 3373, 3389, 3391, 3407, 3413, 3433, 3449, 3457, 3461, 3463, 3467, 3469, 3491, 3499, 3511, 3517, 3527, 3529, 3533, 3539, 3541, 3547, 3557, 3559, 3571, 3581, 3583, 3593, 3607, 3613, 3617, 3623, 3631, 3637, 3643, 3659, 3671, 3673, 3677, 3691, 3697, 3701, 3709, 3719, 3727, 3733, 3739, 3761, 3767, 3769, 3779, 3793, 3797, 3803, 3821, 3823, 3833, 3847, 3851, 3853, 3863, 3877, 3881, 3889, 3907, 3911, 3917, 3919, 3923, 3929, 3931, 3943, 3947, 3967, 3989, 4001, 4003, 4007, 4013, 4019, 4021, 4027, 4049, 4051, 4057, 4073, 4079, 4091, 4093, 4099, 4111, 4127, 4129, 4133, 4139, 4153, 4157, 4159, 4177, 4201, 4211, 4217, 4219, 4229, 4231, 4241, 4243, 4253, 4259, 4261, 4271, 4273, 4283, 4289, 4297, 4327, 4337, 4339, 4349, 4357, 4363, 4373, 4391, 4397, 4409, 4421, 4423, 4441, 4447, 4451, 4457, 4463, 4481, 4483, 4493, 4507, 4513, 4517, 4519, 4523, 4547, 4549, 4561, 4567, 4583, 4591, 4597, 4603, 4621, 4637, 4639, 4643, 4649, 4651, 4657, 4663, 4673, 4679, 4691, 4703, 4721, 4723, 4729, 4733, 4751, 4759, 4783, 4787, 4789, 4793, 4799, 4801, 4813, 4817, 4831, 4861, 4871, 4877, 4889, 4903, 4909, 4919, 4931, 4933, 4937, 4943, 4951, 4957, 4967, 4969, 4973, 4987, 4993, 4999, 5003, 5009, 5011, 5021, 5023, 5039, 5051, 5059, 5077, 5081, 5087, 5099, 5101, 5107, 5113, 5119, 5147, 5153, 5167, 5171, 5179, 5189, 5197, 5209, 5227, 5231, 5233, 5237, 5261, 5273, 5279, 5281, 5297, 5303, 5309, 5323, 5333, 5347, 5351, 5381, 5387, 5393, 5399, 5407, 5413, 5417, 5419, 5431, 5437, 5441, 5443, 5449, 5471, 5477, 5479, 5483, 5501, 5503, 5507, 5519, 5521, 5527, 5531, 5557, 5563, 5569, 5573, 5581, 5591, 5623, 5639, 5641, 5647, 5651, 5653, 5657, 5659, 5669, 5683, 5689, 5693, 5701, 5711, 5717, 5737, 5741, 5743, 5749, 5779, 5783, 5791, 5801, 5807, 5813, 5821, 5827, 5839, 5843, 5849, 5851, 5857, 5861, 5867, 5869, 5879, 5881, 5897, 5903, 5923, 5927, 5939, 5953, 5981, 5987, 6007, 6011, 6029, 6037, 6043, 6047, 6053, 6067, 6073, 6079, 6089, 6091, 6101, 6113, 6121, 6131, 6133, 6143, 6151, 6163, 6173, 6197, 6199, 6203, 6211, 6217, 6221, 6229, 6247, 6257, 6263, 6269, 6271, 6277, 6287, 6299, 6301, 6311, 6317, 6323, 6329, 6337, 6343, 6353, 6359, 6361, 6367, 6373, 6379, 6389, 6397, 6421, 6427, 6449, 6451, 6469, 6473, 6481, 6491, 6521, 6529, 6547, 6551, 6553, 6563, 6569, 6571, 6577, 6581, 6599, 6607, 6619, 6637, 6653, 6659, 6661, 6673, 6679, 6689, 6691, 6701, 6703, 6709, 6719, 6733, 6737, 6761, 6763, 6779, 6781, 6791, 6793, 6803, 6823, 6827, 6829, 6833, 6841, 6857, 6863, 6869, 6871, 6883, 6899, 6907, 6911, 6917, 6947, 6949, 6959, 6961, 6967, 6971, 6977, 6983, 6991, 6997, 7001, 7013, 7019, 7027, 7039, 7043, 7057, 7069, 7079, 7103, 7109, 7121, 7127, 7129, 7151, 7159, 7177, 7187, 7193, 7207, 7211, 7213, 7219, 7229, 7237, 7243, 7247, 7253, 7283, 7297, 7307, 7309, 7321, 7331, 7333, 7349, 7351, 7369, 7393, 7411, 7417, 7433, 7451, 7457, 7459, 7477, 7481, 7487, 7489, 7499, 7507, 7517, 7523, 7529, 7537, 7541, 7547, 7549, 7559, 7561, 7573, 7577, 7583, 7589, 7591, 7603, 7607, 7621, 7639, 7643, 7649, 7669, 7673, 7681, 7687, 7691, 7699, 7703, 7717, 7723, 7727, 7741, 7753, 7757, 7759, 7789, 7793, 7817, 7823, 7829, 7841, 7853, 7867, 7873, 7877, 7879, 7883, 7901, 7907, 7919 };
    return std::find( std::begin(primes), std::end(primes), value ) != std::end(primes);
}


//-----------------------------------------------------------------------------------
//  Stub in just enough of atomic<unique_ptr> for this use
//
template<typename T>
class atomic_unique_ptr {
    std::atomic<T*> p = {};
public:
    atomic_unique_ptr ()                                noexcept = default;
    atomic_unique_ptr (atomic_unique_ptr const&)        noexcept = delete;             // this use doesn't need movability
    ~atomic_unique_ptr()                                noexcept { delete p.load(); }

    explicit atomic_unique_ptr(std::unique_ptr<T>&& up) noexcept : p{up.release()} { } // but we do need convertability
    auto release() noexcept -> std::unique_ptr<T>                { auto ret = std::unique_ptr<T>(p.load()); p.store(nullptr); return ret; }
                                                        // and for an emptying mutating move function I prefer a named function
                                                        // to a conversion operator (even one that's 'explicit' and &&-qualified)

    auto load(std::memory_order m_o = std::memory_order_seq_cst) const noexcept -> T* { return p.load(m_o); }

    //  We only need c_e_weak(null, desired), so can provide this simpler API
    auto compare_exchange_weak_null(std::unique_ptr<T>& desired) noexcept -> bool {
        T* null = nullptr;
        if (p.compare_exchange_weak(null, desired.get())) {
            desired.release();
            return true;
        }
        return false;
    }
};


//-----------------------------------------------------------------------------------
//  extrinsic_storage - constant-time lock-free data structure to nonintrusively
//                      store external additional data for program objects
//
//  Template parameters
//      Data            additional data to store for each object
//      Buckets         #buckets in hash table
// 
//  Concurrency
//      Lock-free for insertion if additional storage is needed
//      Wait-free for all other operations, including insertion that doesn't grow storage
//      Note: Every use of explicit std::memory_order_* (aka m_o_*) MUST include rationale
//
//  Complexity
//      Constant-time could be achieved by periodically growing the hash table (not implemented)
//

template <typename Data, int Buckets = 211> // fixed is ok for prototyping; can be made dynamic to maintain O(K)
    requires (is_prime(Buckets))
class extrinsic_storage {
public:
    using Key   = std::atomic<void*>;
    using Value = Data;

    ~extrinsic_storage() { 
        debug_report();

        //  Explicitly iterate the cleanup work to minimize stack use
        //      Without this cleanup traversal, automatic safe-by-construction
        //      cleanup would still occur but would be recursive and could
        //      require stack space proportional to the largest bucket size
        for (auto& bucket : buckets) {
            auto pnext = bucket.next.release();
            while (pnext) {
                auto pdelete = std::move(pnext);
                pnext = pdelete->next.release();
            }
        }
    }

    //--------------------------------------------------------------------------
    //  find_or_insert( pobj ) - returns the data entry for pobj
    //
    //  If pobj does not yet have an entry, creates it
    //  Returns null only if not present and allocation is needed but fails
    //
    auto find_or_insert(void* pobj) noexcept -> Value* {
        if constexpr (debug_instrumentation) {
            //  m_o_relaxed is enough, inc order doesn't matter for totals
            instrument_access_count.fetch_add(1, std::memory_order_relaxed);
        }
        return lookup(pobj, lookup_mode::find_or_insert);
    }

    //--------------------------------------------------------------------------
    //  find( pobj ) - returns the data entry for pobj or null if not present
    //
    auto find(void* pobj) noexcept -> Value* {
        if constexpr (debug_instrumentation) {
            //  m_o_relaxed is enough, inc order doesn't matter for totals
            instrument_access_count.fetch_add(1, std::memory_order_relaxed);
        }
        return lookup(pobj, lookup_mode::find);
    }

    //--------------------------------------------------------------------------
    //  erase( pobj ) - removes the entry for pobj
    //
    auto erase(void* pobj) noexcept -> void {
        if constexpr (debug_instrumentation) {
            //  m_o_relaxed is enough, inc order doesn't matter for totals
            instrument_erase_count.fetch_add(1, std::memory_order_relaxed);
        }
        lookup(pobj, lookup_mode::erase);
    }

private:
    static inline constexpr std::size_t ChunkSize = 32;
    struct chunk {
        std::array<Key,   ChunkSize> keys   = { }; // SOA for better key locality
        std::array<Value, ChunkSize> values = { };
        atomic_unique_ptr<chunk>     next   = { };
    };
    std::array<chunk, Buckets> buckets = {}; // prime for some minimal QoI

    //--------------------------------------------------------------------------
    //  lookup( pobj ) - shared helper for operator[]/erase
    //
    //  Parameters
    //      pobj    the key to look up
    //      mode    if erase, reset key to null and return nullptr
    //              if find, return a pointer to the value if it exists, or null
    //              if find_or_insert, return a pointer to the value (inserted if
    //                   not present) or null if allocation was needed and failed
    // 
    //  (*) This function requires that the calling code has exclusive access to
    //      *pobj, and if *pobj is shared has done any necessary synchronization
    //      to access *pobj (else the calling code already has a data race on 
    //      *pobj). This function uses the knowledge that no other thread can be
    //      concurrently calling us with this pobj value to perform m_o_relaxed
    //      loads of .keys and .next, noted with (*) below.
    //
    //      Using m_o_relaxed on loads will likely not be significantly faster
    //      on modern Intel and ARM architectures, where SC loads are already
    //      the same or similar speed as relaxed loads. But they should be a
    //      good performance gain on PPC, older ARM, and any other hardware 
    //      that has inefficient SC loads, so I'll use m_o_relaxed with care
    //      as I think they can be correct here and they are in the hot path
    //      of the data structure traversal.
    //
    enum class lookup_mode { find, find_or_insert, erase };
    auto lookup(
        void*       pobj,
        lookup_mode mode
    ) noexcept
        -> Value*
    {
        //auto hash = std::hash<void*>{}(pobj) % Buckets;   // A
        auto hash = (((std::size_t)pobj)>>2) % Buckets;     // B
            //  across the three major C++ implementations I tried, hash B has
            //  smoother utilization (2% to 5% difference between the most vs
            //  least popular bucket) than hash A (3.5% to 16% difference)

        assert( 0 <= hash && hash < Buckets );
        if constexpr (debug_instrumentation) {
            //  m_o_relaxed is enough, inc order doesn't matter for totals
            instrument_bucket_access[hash].fetch_add(1, std::memory_order_relaxed);
        }

        //  1. If we find key==pobj, we're done
        auto pchunk = &buckets[hash];
        while (pchunk) {
            for ( auto i = std::size_t{0}; i < ChunkSize; ++i ) {
                //  (*) m_o_relaxed is enough, equality means we own the slot
                //  and so this thread already has exclusive access to *pobj
                //  and its .values data
                if (pchunk->keys[i].load(std::memory_order_relaxed) == pobj) {
                    if (mode == lookup_mode::erase) { 
                        pchunk->keys[i].store(nullptr, std::memory_order_relaxed); 
                        return nullptr;
                    }
                    //  Else
                    return &pchunk->values[i];
                }
            }
            //  (*) m_o_relaxed is enough here, because .next is immutable after
            //  it is first set to non-null, and if a new chunk(s) was just
            //  concurrently added by a different thread then that new
            //  chunk(s) cannot contain an entry for pobj
            pchunk = pchunk->next.load(std::memory_order_relaxed);
        }

        //  2. Otherwise, if we're not allowed to insert we're done 
        //     but we didn't actually find something so return null
        if (mode != lookup_mode::find_or_insert) { 
            if constexpr (debug_instrumentation) {
                if (mode == lookup_mode::erase) {
                    //  m_o_relaxed is enough, inc order doesn't matter for totals
                    instrument_erase_fail_count.fetch_add(1, std::memory_order_relaxed);
                }
            }
            return nullptr;
        }

        //  3. Otherwise, we need to insert it
        //  a) Prefer claiming an existing null slot if one exists
        pchunk = &buckets[hash];
        while (true) {
            auto i = std::size_t{0};
            for ( ; i < ChunkSize; ++i ) {
                void* null = nullptr;
                if (
                    //  m_o_relaxed is enough for this first load...
                    pchunk->keys[i].load(std::memory_order_relaxed) == nullptr
                    //  ... because it's just a best-effort optimization to
                    //  avoid this maybe-unneeded c_e_weak (which is safely SC)
                    && pchunk->keys[i].compare_exchange_weak( null, pobj )
                    ) {
                    if constexpr (debug_instrumentation) {
                        //  m_o_relaxed is enough, inc order doesn't matter for totals
                        instrument_insert_count.fetch_add(1, std::memory_order_relaxed);
                    }
                    return &pchunk->values[i];
                }
            }
            //  (*) m_o_relaxed is enough here, because if a new chunk(s)
            //  was just concurrently added by a different thread then we'll
            //  just add an extra chunk which is fine
            if ( pchunk->next.load(std::memory_order_relaxed) == nullptr ) {
                break;
            }
            pchunk = pchunk->next.load();
        }

        //  b) Otherwise, we need to allocate a new chunk for it
        //     At this point, pchunk points to the last chunk in this bucket
        assert (pchunk);

        //  Not using make_unique: In principle, if allocation fails we don't
        //  want to change well-formed program behavior. (In practice, if this
        //  small allocation ever fails the program is already in deep trouble;
        //  unless Key or Data are large, a chunk is usually well under 1KB)
        auto pnew = std::unique_ptr<chunk>( new (std::nothrow) chunk{} );
        if (pnew == nullptr) { return nullptr; }

        pnew->keys[0] = pobj;
        auto ret  = &pnew->values[0];
        while (!pchunk->next.compare_exchange_weak_null(pnew)) {
            pchunk = pchunk->next.load();
            assert (pchunk);
        }

        if constexpr (debug_instrumentation) {
            //  m_o_relaxed is enough, inc order doesn't matter for totals
            instrument_alloc_count.fetch_add(1, std::memory_order_relaxed);
        }
        return ret;
    }

    //  Debug instrumentation
    //
    static inline std::atomic<std::size_t>              instrument_access_count     = {};
    static inline std::atomic<std::size_t>              instrument_insert_count     = {};
    static inline std::atomic<std::size_t>              instrument_alloc_count      = {};
    static inline std::atomic<std::size_t>              instrument_erase_count      = {};
    static inline std::atomic<std::size_t>              instrument_erase_fail_count = {};
    static inline std::array<std::atomic<int>, Buckets> instrument_bucket_access    = {};

    auto debug_report() -> void {
        if constexpr (debug_instrumentation) {
            std::cout << "Report for extrinsic_storage<" << typeid(Data).name() << ">\n\n"
                      << "  all accesses (incl. inserts)  "   << print(instrument_access_count     .load()) << "\n"
                      << "  inserts                       "   << print(instrument_insert_count     .load()
                                                                      +instrument_alloc_count      .load()) << "\n"
                      << "    used existing storage         " << print(instrument_insert_count     .load()) << "\n"
                      << "    allocated new storage         " << print(instrument_alloc_count      .load()) << "\n"
                      << "  erases                        "   << print(instrument_erase_count      .load()) << "\n"
                      << "    succeeded                     " << print(instrument_erase_count      .load()
                                                                      -instrument_erase_fail_count .load()) << "\n"
                      << "    failed                        " << print(instrument_erase_fail_count .load()) << "\n\n";

            auto empty = std::size_t{0};
            auto tot   = 0;
            auto min   = instrument_bucket_access[0].load();
            auto max   = 0;
            for (auto const& count : instrument_bucket_access) {
                if (count == 0) { ++empty; }
                tot += count;
                if (count < min) { min = count; }
                if (count > max) { max = count; }
            }

            auto sizes = std::map<int, size_t>{};
            for (auto const& ch : buckets) {
                auto size = 0;
                for (auto next = ch.next.load(); next; ++size, next = next->next.load()) { ; }
                ++sizes[size];
            }
            std::cout << "  bucket utilization\n"
                      << "    # buckets\n"
                      << "      total                    " << print(Buckets) << "\n"
                      << "      empty                    " << print(empty) << "\n"
                      << "    # accesses\n"
                      << "      total                    " << print(tot) << "\n"
                      << "      to least popular bucket  " << print(min) << "\n"
                      << "      to most popular bucket   " << print(max) << "\n"
                      << "    # extra allocations\n";
            for (auto [size, count] : sizes | std::views::reverse) {
                std::cout << "      " << size << " - " << count << " buckets\n";
            }
            std::cout << "\n";

            auto static_space  = sizeof(extrinsic_storage);
            auto dynamic_space = instrument_alloc_count.load() * sizeof(chunk);
            std::cout << "  total extrinsic storage used = keys + data + housekeeping + padding (in bytes)\n"
                      << "    static   " << print(static_space) << "\n"
                      << "    dynamic  " << print(dynamic_space) << "\n"
                      << "    total    " << print(static_space + dynamic_space) << "\n"
                      << "  for comparison, intrinsic would have used approx. " 
                                         << print((instrument_alloc_count.load()+Buckets) * sizeof(chunk::values)) << "\n\n";

            std::cout << "  sizes (in bytes)\n"
                      << "    sizeof(chunk)              " << print(sizeof(chunk)) << "\n"
                      << "      sizeof(chunk.keys)       " << print(sizeof(chunk::keys)) << "\n"
                      << "      sizeof(chunk.values)     " << print(sizeof(chunk::values)) << "\n"
                      << "      sizeof(chunk.next)       " << print(sizeof(chunk::next)) << "\n"
                      << "      wasted chunk.* padding   " << print(sizeof(chunk) - sizeof(chunk::keys) - sizeof(chunk::values) - sizeof(chunk::next)) << "\n"
                      << "    sizeof(buckets)            " << print(sizeof(buckets)) << "\n"
                      << "    #buckets * sizeof(chunk)   " << print(Buckets * sizeof(chunk)) << "\n"
                      << "\n";
        }
    }
};

#endif
