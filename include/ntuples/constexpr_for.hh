#pragma once

namespace nt{

  template <auto Start, auto End, auto Inc, class F>
  constexpr void constexpr_for(F &&f)
  {
    if constexpr (Start < End)
    {
      f(std::integral_constant<decltype(Start), Start>());
      constexpr_for<Start + Inc, End, Inc>(f);
    }
  }

}