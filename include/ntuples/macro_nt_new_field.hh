#pragma once

#include "ntuples/ntuples.hh"




#define __nt_new_field_core(field_name)                   \
  struct zt##field_name                                   \
  {                                                       \
    template <typename T>                                 \
    struct base_t                                         \
    {                                                     \
      constexpr base_t() {}                               \
      template <typename T1>                              \
      constexpr base_t(T1 &&e_) :                         \
             field_name(std::forward<T1>(e_)) {}          \
      T field_name;                                       \
      decltype(auto) value() const                        \
          {                                               \
            return field_name;                            \
          }                                               \
    };                                                    \
    static auto get_name()                                \
    {                                                     \
      return #field_name;                                 \
    }                                                     \
    template <typename T>                                 \
    static constexpr decltype(auto) get(T&& t) {          \
      return (std::forward<T>(t).field_name);             \
    }                                                     \
    template <typename T=int>                             \
    static constexpr decltype(auto) static_assert_fail() {\
       static_assert(dependent_false<T>::value,           \
        "[NTUPLE ERROR] Field `" #field_name              \
        "` does not exist in this ntuple");               \
    }                                                     \
    template <typename T1>                                \
    static constexpr bool _is_containt_in(){                 \
       using T = std::remove_reference_t<T1>;             \
    if constexpr (requires (T& x) { x.field_name; }) {    \
        return true;                                      \
    } else {                                              \
        return false;                                     \
    }                                                     \
    }                                                     \
  }

#define __nt_new_field(qualifier, field_name, value) \
  namespace __nt                               \
  {                                            \
    __nt_new_field_core(field_name);                 \
  }                                            \
  qualifier field_name = (nt::field_name_container<__nt::zt##field_name>{} = value)

#define nt_new_field(field_name, value) __nt_new_field(static constexpr inline auto, field_name, value)
#define nt_new_field_c(field_name, value) __nt_new_field(static const inline auto, field_name, value)

#define nt_new_field_t(field_name, value) \
  namespace __nt                    \
  {                                 \
    __nt_new_field_core(field_name);      \
  }                                 \
  using field_name = decltype(nt::field_name_container<__nt::zt##field_name>{} = value)

#define nt_new_field_name(field_name)     \
  namespace __nt               \
  {                            \
    __nt_new_field_core(field_name); \
  }                            \
  static constexpr inline auto field_name = nt::field_name_container<__nt::zt##field_name> {}

#define nt_new_field_name_t(field_name)   \
  namespace __nt               \
  {                            \
    __nt_new_field_core(field_name); \
  }                            \
  using field_name = nt::field_name_container<__nt::zt##field_name>




