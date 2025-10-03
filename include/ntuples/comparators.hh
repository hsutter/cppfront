#pragma once
#include "ntuples/ntuples.hh"


namespace nt::comparators
{

  struct on_common_args_t
  {

    template <typename T1, typename T2>
    constexpr static bool __comp__(T1 &&t1, T2 &&t2)
    {
      bool ret = true;
      constexpr_for<0, _Remove_cvref_t<T1>::__size__, 1>(
          [&](const auto i)
          {
            using N_th_T = _Remove_cvref_t<decltype(nt::get_nth<i>(t1))>;
            if constexpr (contains_type_v<N_th_T, _Remove_cvref_t<T2>>)
            {
              ret &= (N_th_T::get(t1) == N_th_T::get(t2));
            }
          });
      return ret;
    }

    template <typename T1, typename T2>
    constexpr bool operator()(T1 &&t1, T2 &&t2) const
    {
      return __comp__(std::forward<T1>(t1), std::forward<T2>(t2));
    }
  };
  constexpr inline on_common_args_t on_common_args;
}

