#pragma once
#include "ntuples.hh"
#include <tuple>
#include <utility>

namespace std {

  // Make nt::ntuple behave like std::tuple

  template <typename... Ts>
  struct tuple_size<nt::ntuple<Ts...>> : std::integral_constant<std::size_t, sizeof...(Ts)> {};

  template <std::size_t N, typename... Ts>
  struct tuple_element<N, nt::ntuple<Ts...>> {
    using type = typename nt::NthTypeOf<N, Ts...>;
  };

} // namespace std

namespace nt {

  // std::get overloads for nt::ntuple

  template <std::size_t N, typename... Ts>
  decltype(auto) get(ntuple<Ts...>& t) {
    
    if constexpr (N >= sizeof...(Ts)) {
      static_assert(dependent_false<ntuple<Ts...>>::value, "[NTUPLE ERROR] get<N>: index out of range (N must be less than the number of fields).");
    } else {
      using Field = _Remove_cvref_t<NthTypeOf<N, Ts...>>;
      return Field::get(t);
    }
    
  }

  template <std::size_t N, typename... Ts>
  decltype(auto) get(const ntuple<Ts...>& t) {
    if constexpr (N >= sizeof...(Ts)) {
      static_assert(dependent_false<ntuple<Ts...>>::value, "[NTUPLE ERROR] get<N>: index out of range (N must be less than the number of fields).");
      
    } else {
      using Field = _Remove_cvref_t<NthTypeOf<N, Ts...>>;
      return Field::get(t);
    }
    
  }

  template <std::size_t N, typename... Ts>
  decltype(auto) get(ntuple<Ts...>&& t) {
    if constexpr (N >= sizeof...(Ts)) {
      static_assert(dependent_false<ntuple<Ts...>>::value, "[NTUPLE ERROR] get<N>: index out of range (N must be less than the number of fields).");
    } else {
      using Field = _Remove_cvref_t<NthTypeOf<N, Ts...>>;
      return Field::get(t);
    }
    
  }

  template <std::size_t N, typename... Ts>
  decltype(auto) get(const ntuple<Ts...>&& t) {
    if constexpr (N >= sizeof...(Ts)) {
      static_assert(dependent_false<ntuple<Ts...>>::value, "[NTUPLE ERROR] get<N>: index out of range (N must be less than the number of fields).");
    } else {
      using Field = _Remove_cvref_t<NthTypeOf<N, Ts...>>;
      return Field::get(t);
    }
    
  }

} // namespace nt