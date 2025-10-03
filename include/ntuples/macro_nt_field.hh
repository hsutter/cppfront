#pragma once

#include "ntuples/ntuples.hh"



#define nt_field(field_name) []() constexpr {                                          \
  auto struct_maker_template_lambda = [](auto e) constexpr {                      \
    using ARG_T = decltype(e);                                                    \
    if constexpr (e.N_value == nt::field_name_container_base_const::c_struct_maker)  \
    {                                                                             \
      if constexpr (!std::is_reference_v<typename ARG_T::type>)                   \
      {                                                                           \
        struct Zt##field_name                                                          \
        {                                                                         \
          constexpr Zt##field_name() =default;                                                         \
          constexpr Zt##field_name(const decltype(e.val) &e_) : field_name(e_) {}                     \
          constexpr Zt##field_name(decltype(e.val) &e_) : field_name(e_) {}                           \
          constexpr Zt##field_name(decltype(e.val) &&e_) : field_name(std::move(e_)) {}               \
          decltype(e.val) field_name;                                                  \
          decltype(e.val) value() const                                           \
          {                                                                       \
            return field_name;                                                         \
          }                                                                       \
        };                                                                        \
        return Zt##field_name{};                                   \
      }                                                                           \
      else                                                                        \
      {                                                                           \
        struct Zt##field_name                                                          \
        {                                                                         \
          Zt##field_name(decltype(e.val) e_) : field_name(e_) {}                            \
          decltype(e.val) field_name;                                                  \
          decltype(e.val) value() const                                           \
          {                                                                       \
            return field_name;                                                         \
          }                                                                       \
        };                                                                        \
        return Zt##field_name{};                                   \
      }                                                                           \
    }                                                                             \
    else if constexpr (e.N_value == nt::field_name_container_base_const::c_getter1)  \
    {                                                                             \
      struct getter_t                                                             \
      {                                                                           \
        static constexpr decltype(auto) get(decltype(e.val) x)                    \
        {                                                                         \
            return (x.field_name);                                                \
        }                                                                         \
      };                                                                          \
      return getter_t{};                                                          \
    }                                                                             \
    else if constexpr (e.N_value == nt::field_name_container_base_const::c_get_name) \
    {                                                                             \
      struct name_getter_t                                                        \
      {                                                                           \
        static constexpr const char* get_name()                                          \
        {                                                                         \
          return #field_name;                                                          \
        }                                                                         \
      };                                                                          \
      return name_getter_t{};                                                     \
    }                                                                             \
     else if constexpr (e.N_value == nt::field_name_container_base_const::c_Static_assert_fail) \
     {                                                                               \
       struct Static_assert_fail_T    {                                                       \
              static constexpr void static_assert_fail(){  \
                  static_assert(dependent_false<decltype(e)>::value, "[NTUPLE ERROR] Field `" #field_name "` does not exist in this ntuple");                                                                     \
              }                         \
        };                                                                          \
      return Static_assert_fail_T{};                                                       \
    }                                                                             \
     else if constexpr (e.N_value == nt::field_name_container_base_const::c_has_field) \
     {                                                                               \
       struct has_field_t    {                                                       \
              static constexpr bool has_field(){                                     \
                using T = std::remove_cvref_t<decltype(e.val)>;                      \
                if constexpr (requires (T& x) { x.field_name; }) {                   \
                  return true;                                                        \
                } else {                                                             \
                  return false;                                                      \
                }                                                                    \
              }                                                                      \
        };                                                                           \
      return has_field_t{};                                                       \
    }                                                                             \
  };                                                                              \
  return nt::field_name_container<                                                   \
      nt::field_name_container_base<decltype(struct_maker_template_lambda)>>{};      \
}()

#define nt_field_c(field_name, value) static constexpr inline auto field_name = (nt_field(field_name) = value)

#define nt_field_t(field_name, value)                                  \
  auto __internal__##field_name = [] { return nt_field(field_name) = value; }; \
  using field_name = decltype(__internal__##field_name())



