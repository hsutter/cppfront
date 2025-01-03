
//  Copyright 2022-2024 Herb Sutter
//  SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//  
//  Part of the Cppfront Project, under the Apache License v2.0 with LLVM Exceptions.
//  See https://github.com/hsutter/cppfront/blob/main/LICENSE for license information.

#ifndef CPP2_EXPERIMENTAL_EXTRINSIC_STORAGE_STD_LOCKED_H
#define CPP2_EXPERIMENTAL_EXTRINSIC_STORAGE_STD_LOCKED_H

#include <map>
#include <mutex>
#include <string>
#include <unordered_map>


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


//-----------------------------------------------------------------------------------
//  A "brute-force" locked implementation to measure against
//
//  NOTE: For performance comparison only, not recommended
//
template <typename Data>
class extrinsic_storage {
    std::mutex                     mut;
    //std::map<void*,Data>           data;
    std::unordered_map<void*,Data> data;
public:
    //--------------------------------------------------------------------------
    //  find_or_insert( pobj ) - returns the data entry for pobj
    //
    //  If pobj does not yet have an entry, creates it
    //
    auto find_or_insert(void* pobj) -> Data* {
        auto _ = std::lock_guard{mut};
        return &data[pobj];
    }

    //--------------------------------------------------------------------------
    //  find( pobj ) - returns the data entry for pobj or null if not present
    //
    auto find(void* pobj) noexcept -> Data* {
        auto _ = std::lock_guard{mut};
        if (auto iter = data.find(pobj);
            iter != data.end()
            )
        {
            return &iter->second;
        }
        // Else
        return nullptr;
    }

    //--------------------------------------------------------------------------
    //  erase( pobj ) - removes the entry for pobj
    //
    auto erase(void* pobj) noexcept -> void {
        auto _ = std::lock_guard{mut};
        data.erase(pobj);
    }
};

#endif
