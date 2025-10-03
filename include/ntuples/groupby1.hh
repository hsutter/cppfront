#pragma once

#include <vector>
#include <map>
#include "ntuples/ntuples.hh"

#include <set>

#include <vector>
#include <utility>
#include <span>
#include <iterator>

namespace nt
{
    namespace __imple__{

        struct group_IDS_T{
            size_t index = 0, group_ID = 0;
        };
    }

    template <typename... Vecs>
    std::vector<::nt::__imple__::group_IDS_T> compute_group_ids_indexed(const Vecs &...keys)
    {
        using KeyT = std::tuple<nt::_Remove_cvref_t<decltype(keys[0])>...>;
        std::map<KeyT, size_t> seen;
        std::vector<::nt::__imple__::group_IDS_T> result;

        size_t group_id = 0;
        std::size_t N = std::get<0>(std::tie(keys...)).size();

        for (std::size_t i = 0; i < N; ++i)
        {
            KeyT k{keys[i]...};
            auto [it, inserted] = seen.try_emplace(k, group_id);
            if (inserted)
                ++group_id;
            result.emplace_back(i, it->second);
        }

        std::ranges::sort(result, [](const auto &a, const auto &b)
                          { return a.group_ID < b.group_ID; });

        return result;
    }

    class GroupIndexBuffer : public std::vector< std::span<const ::nt::__imple__::group_IDS_T> > 
    {
        const std::vector<::nt::__imple__::group_IDS_T> data;
        //std::vector<std::pair<size_t, size_t>> spans; // [start, end) indices

    public:
        template <typename... Vecs>
           
        explicit GroupIndexBuffer(Vecs&&... keys )
            : data(compute_group_ids_indexed(std::forward<Vecs>(keys)...))
        {
            if (data.empty())
                return;

            size_t start = 0;
            for (size_t i = 1; i <= data.size(); ++i)
            {
                if (i == data.size() || data[i].group_ID != data[start].group_ID)
                {
                    this->emplace_back(&data[start], i-start);
                    start = i;
                }
            }
        }

    };

    
}