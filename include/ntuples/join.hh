#pragma once
#include <vector>

namespace nt
{

  template <typename T, typename T2>
  auto join_on(nt::span<T> s1, nt::span<T2> s2)
  {
    return std::pair<nt::span<T>, nt::span<T2>>(s1, s2);
  }

  template <typename... T>
  auto joinIndex(T... t)
  {

    std::vector<std::pair<size_t, size_t>> ret;

    const auto &t1 = std::get<0>(std::tie(t...));
    const size_t rows1 = t1.first.size();
    const size_t rows2 = t1.second.size();

    // Check if all sizes match
    bool same_size = ((t.first.size() == rows1 && t.second.size() == rows2) && ...);
    if (!same_size)
    {
      throw std::runtime_error("Mismatched input sizes");
    }

    for (size_t i = 0; i < rows1; ++i)
    {
      for (size_t j = 0; j < rows2; ++j)
      {

        bool all_match = ((t.first[i] == t.second[j]) && ...);
        if (all_match)
          ret.emplace_back(i, j);
      }
    }

    return ret;
  }
}