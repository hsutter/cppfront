#pragma once

#include <type_traits>

#include <iostream>
#include <vector>

#include <iomanip>
#include <algorithm>

#include "ntuples/constexpr_for.hh"




template <typename T>
struct dependent_false : std::false_type
{
};

namespace nt
{

  template <class _Ty>
  using _Remove_cvref_t = std::remove_cv_t<std::remove_reference_t<_Ty>>;

  template <int N, typename... Ts>
  using NthTypeOf =
      typename std::tuple_element<N, std::tuple<Ts...>>::type;

  template <typename T1>
  struct type_container
  {
    using type = T1;
  };

  template <typename T1, typename field_name_container_T_>
  struct field_type : field_name_container_T_
  {
    T1 v = {};
    constexpr field_type()  =default;
    constexpr field_type(const field_type&) = default;
    constexpr field_type(field_type&&) = default;
    constexpr field_type(T1 t1) : v(std::move(t1)) {}
    constexpr field_type operator=(T1 &&t1) const { return field_type(std::move(t1)); }
    constexpr field_type operator=(const T1 &t1) const { return field_type(t1); }

    template <typename T_IN>
    constexpr field_type operator()(T_IN &&t1) const { return field_type(std::move(static_cast<T1>(t1))); }

    template <typename T_IN>
    constexpr field_type operator()(const T_IN &t1) const { return field_type(static_cast<T1>(t1)); }
    constexpr field_type operator=(T1 &&t1)
    {
      v = std::move(t1);
      return *this;
    }
    constexpr field_type &operator=(const T1 &t1)
    {
      v = t1;
      return *this;
    }

    template <typename T>
    constexpr field_type &operator=(const field_type<T1, T> &t1)
    {
      v = t1.v;
      return *this;
    }

    using field_name_container_T = field_name_container_T_;
    using data_t = T1;

    operator T1()
    {
      return v;
    }

    operator const T1() const
    {
      return v;
    }

    template <typename T_RHS>
    friend constexpr bool operator<(const field_type &lhs, const field_type<T1, T_RHS> &rhs)
    {
      return lhs.v < rhs.v;
    }

    template <typename T_RHS>
    friend constexpr bool operator<=(const field_type &lhs, const field_type<T1, T_RHS> &rhs)
    {
      return lhs.v <= rhs.v;
    }

    template <typename T_RHS>
    friend constexpr bool operator==(const field_type &lhs, const field_type<T1, T_RHS> &rhs)
    {
      return lhs.v == rhs.v;
    }

    template <typename T_RHS>
    friend constexpr bool operator!=(const field_type &lhs, const field_type<T1, T_RHS> &rhs)
    {
      return lhs.v != rhs.v;
    }

    template <typename T_RHS>
    friend constexpr bool operator>=(const field_type &lhs, const field_type<T1, T_RHS> &rhs)
    {
      return lhs.v >= rhs.v;
    }

    template <typename T_RHS>
    friend constexpr bool operator>(const field_type &lhs, const field_type<T1, T_RHS> &rhs)
    {
      return lhs.v > rhs.v;
    }

    friend constexpr bool operator<(const field_type &lhs, const T1 &rhs)
    {
      return lhs.v < rhs;
    }
    friend constexpr bool operator<(const T1 lhs, const field_type &rhs)
    {
      return lhs < rhs.v;
    }

    friend constexpr bool operator<=(const field_type &lhs, const T1 &rhs)
    {
      return lhs.v <= rhs;
    }

    friend constexpr bool operator<=(const T1 &lhs, const field_type &rhs)
    {
      return lhs <= rhs.v;
    }

    friend constexpr bool operator==(const field_type &lhs, const T1 &rhs)
    {
      return lhs.v == rhs;
    }

    friend constexpr bool operator==(const T1 &lhs, const field_type &rhs)
    {
      return lhs == rhs.v;
    }

    friend constexpr bool operator!=(const field_type &lhs, const T1 &rhs)
    {
      return lhs.v != rhs;
    }

    friend constexpr bool operator!=(const T1 &lhs, const field_type &rhs)
    {
      return lhs != rhs.v;
    }

    friend constexpr bool operator>=(const field_type &lhs, const T1 &rhs)
    {
      return lhs.v >= rhs;
    }

    friend constexpr bool operator>=(const T1 &lhs, const field_type &rhs)
    {
      return lhs >= rhs.v;
    }

    friend constexpr bool operator>(const field_type &lhs, const T1 &rhs)
    {
      return lhs.v > rhs;
    }

    friend constexpr bool operator>(const T1 &lhs, const field_type &rhs)
    {
      return lhs > rhs.v;
    }

    friend std::ostream &operator<<(std::ostream &out, const field_type &self)
    {
      out << self.get_name() << ": ";

      if constexpr (requires(std::ostream &o, const decltype(self.v) &val) { o << val; })
      {
        out << self.v;
      }
      else
      {
        out << "<unsupported type>";
      }
      return out;
    }

  private:
    using field_name_container_T_::operator=;
  };

  namespace comparators
  {
    template <typename T1, typename... T_rest>
    struct _nt_compare
    {

      template <typename VECA_T, typename VECB_T>
      static auto __isLessthen(const VECA_T &vecA, const VECB_T &vecB)
      {
        if constexpr (sizeof...(T_rest) > 0)
        {
          if (T1::get(vecA) < T1::get(vecB))
          {
            return true;
          }
          else if (T1::get(vecA) > T1::get(vecB))
          {
            return false;
          }
          return _nt_compare<T_rest...>::template __isLessthen(vecA, vecB);
        }
        else
        {
          return T1::get(vecA) < T1::get(vecB);
        }
      }

      template <typename VECA_T, typename VECB_T>
      static auto __isEequal(const VECA_T &vecA, const VECB_T &vecB)
      {
        if constexpr (sizeof...(T_rest) > 0)
        {
          if (nt::_Remove_cvref_t<T1>::get(vecA) != nt::_Remove_cvref_t<T1>::get(vecB))
          {
            return false;
          }
          return _nt_compare<T_rest...>::template __isEequal(vecA, vecB);
        }
        else
        {
          return nt::_Remove_cvref_t<T1>::get(vecA) == nt::_Remove_cvref_t<T1>::get(vecB);
        }
      }
    };

    template <typename... T_rest>
    auto nt_compare(T_rest &&...)
    {
      return _nt_compare<nt::_Remove_cvref_t<T_rest>...>{};
    }

    template <typename... T_rest>
    constexpr auto lessThan(T_rest &&...)
    {
      return [less = _nt_compare<nt::_Remove_cvref_t<T_rest>...>{}](const auto &lhs, const auto &rhs)
      {
        return less.__isLessthen(lhs, rhs);
      };
    }

    template <typename... T_rest>
    constexpr auto lessThan()
    {
      return [less = _nt_compare<nt::_Remove_cvref_t<T_rest>...>{}](const auto &lhs, const auto &rhs)
      {
        return less.__isLessthen(lhs, rhs);
      };
    }

    template <typename... T_rest>
    constexpr auto equal(T_rest &&...)
    {
      return [less = _nt_compare<nt::_Remove_cvref_t<T_rest>...>{}](const auto &lhs, const auto &rhs)
      {
        return less.__isEequal(lhs, rhs);
      };
    }

    template <typename... T_rest>
    constexpr auto equal()
    {
      return [less = _nt_compare<nt::_Remove_cvref_t<T_rest>...>{}](const auto &lhs, const auto &rhs)
      {
        return less.__isEequal(lhs, rhs);
      };
    }
  }

    template <typename data_t_, typename field_name_container_T_>
  struct ax_type2 : data_t_, field_name_container_T_
  {

    constexpr ax_type2() = default;

    using field_name_container_T = field_name_container_T_;
    using data_t = data_t_;
  };

  struct field_name_container_base_const
  {
    static constexpr int c_struct_maker = 0;
    static constexpr int c_getter1 = 1;
    static constexpr int c_get_name = 2;
    static constexpr int c_has_field = 3;
    static constexpr int c_Static_assert_fail = 4;
  };

  template <typename T2>
  struct field_name_container_base : field_name_container_base_const
  {
    using Lambda_T = T2;

    constexpr field_name_container_base() = default;

    template <typename T, int N>
    struct type_wrap
    {
      static constexpr int N_value = N;
      T val;
      using type = T;
    };

    template <typename T>
    static constexpr auto struct_maker()
    {
      return decltype(std::declval<Lambda_T>()(std::declval<type_wrap<T, c_struct_maker>>())){};
    }

    template <typename Data_T>
    using base_t =  decltype(struct_maker<Data_T>());

    template <typename T>
    static constexpr decltype(auto) get(T &t)
    {
      using getter1 = decltype(std::declval<Lambda_T>()(std::declval<type_wrap<T &, c_getter1>>()));

      return getter1::get(t);
    }

    template <typename T>
    static constexpr decltype(auto) get(const T &t)
    {
      using getter1 = decltype(std::declval<Lambda_T>()(std::declval<type_wrap<const T &, c_getter1>>()));
      return getter1::get(t);
    }

    static constexpr decltype(auto) static_assert_fail()
    {
      using static_assert_fail_T = decltype(std::declval<Lambda_T>()(std::declval<type_wrap<int, c_Static_assert_fail>>()));
      static_assert_fail_T::static_assert_fail();
    }

    template <typename T>
    static constexpr decltype(auto) get_value(const T &t)
    {
      return field_name_container_base::get(t).v;
    }

    template <typename T>
    static constexpr decltype(auto) get_value(T &t)
    {
      return field_name_container_base::get(t).v;
    }

    static constexpr decltype(auto) get_name()
    {
      using name_getter = decltype(std::declval<Lambda_T>()(std::declval<type_wrap<int, c_get_name>>()));
      return name_getter::get_name();
    }
    template <typename T1>
    static constexpr auto _is_containt_in(){
       using T = std::remove_reference_t<T1>;
        using has_field_t = decltype(std::declval<Lambda_T>()(std::declval<type_wrap<T, c_has_field>>()));
      return has_field_t::has_field();
    }
  };


  template <typename TBase>
  struct field_name_container : TBase
  {
 
    template <typename T>
    inline static constexpr bool _is_containt_in_v =TBase:: template  _is_containt_in<T>();
    
    template <typename T>
    constexpr static decltype(auto) get(T &&t)
    {

      if constexpr (_is_containt_in_v<T>)
      {
        return TBase::get(std::forward<T>(t));
      }
      else
      {
        TBase::static_assert_fail();
      }
    }

    template <typename T>
    static constexpr decltype(auto) get_value(T &t)
    {
      return TBase::get(t).v;
    }

    template <typename T>
    static constexpr decltype(auto) get_value(const T &t)
    {
      return TBase::get(t).v;
    }

    template <typename T>
    constexpr auto operator=(T t) const
    {

      return field_type<_Remove_cvref_t<T>, field_name_container>{std::move(t)};
    }

    template <typename T>
    constexpr static auto has_field()
    {
      using BareT = std::remove_cvref_t<T>;
      return BareT::template contains_struct_maker_type<field_name_container<TBase>>();
    }
    template <typename T>
    constexpr static auto index_of()
    {
      using BareT = std::remove_cvref_t<T>;
      return BareT::template index_of_struct_maker_type<field_name_container<TBase>>();
    }
  };

  template <typename... Ts>
  field_name_container(Ts &&...ts) -> field_name_container<_Remove_cvref_t<Ts>...>;

  template <typename T2>
  auto constexpr get_ax_name_container(const field_name_container<T2> &t)
  {
    return field_name_container<T2>{};
  }

  template <typename T, typename data_T>
  struct base_maker
  {
    using type = typename T::template base_t<data_T>;
  };
  template <typename T, typename data_T>
  using base_maker_t = typename base_maker<T, data_T>::type;

  template <typename T>
  using ntuple_base_t = base_maker_t<_Remove_cvref_t<T>, T>;

  template <typename... T>
  struct ntuple : ntuple_base_t<T>...
  {
    constexpr ntuple(const ntuple &rhs) = default;
    constexpr ntuple &operator=(const ntuple &rhs) = default;
    constexpr ntuple(const T &...t1) : ntuple_base_t<T>(t1)... {}

    constexpr ntuple() : ntuple_base_t<T>(_Remove_cvref_t<T>{})... {}

    template <typename... Ts, typename = std::enable_if_t<(sizeof...(Ts) != 1)>>
    constexpr ntuple(Ts &&...t1) : ntuple_base_t<T>(std::forward<Ts>(t1))... {}

    template <typename T2>
    decltype(auto) operator[](const field_name_container<T2> &t)
    {
      return field_name_container<T2>::get(*this);
    }

    friend std::ostream &operator<<(std::ostream &out, const ntuple &self)
    {
      out << "|";

      constexpr_for<0, sizeof...(T), 1>([&](auto i)
                                        {
        using  current_t = decltype(NthTypeOf<i, _Remove_cvref_t<T>...>{});
        out << " ";
        out << current_t::get(self);
        out << " |"; });

      return out;
    }

    template <typename... ARGS>
    auto operator|(const ntuple<ARGS...> &rhs) const
    {
      return ntuple<T..., ARGS...>(
          T::get(*this)...,
          ARGS::get(rhs)...);
    }

    template <typename TARGET>
    constexpr static bool contains_struct_maker_type()
    {
      return (([]()
               {
    using base_t = ntuple_base_t<T>;
    using maker_t = typename decltype(std::declval<base_t>().value())::field_name_container_T;
    return std::is_same_v<maker_t, TARGET>; }()) ||
              ...);
    }

#if defined(__clang__)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wunused-value"
#elif defined(__GNUC__)
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wunused-value"
#endif

    template <typename TARGET>
    constexpr static int index_of_struct_maker_type()
    {
      int index = 0;
      int result = -1;
      // Fold expression over initializer list to evaluate in order and capture index
      ((std::is_same_v<typename decltype(std::declval<ntuple_base_t<T>>().value())::field_name_container_T, TARGET>
            ? (result = index, false)
            : true,
        ++index),
       ...);
      return result;
    }
    
#if defined(__clang__)
  #pragma clang diagnostic pop
#elif defined(__GNUC__)
  #pragma GCC diagnostic pop
#endif
    
    friend constexpr bool operator<(const ntuple &lhs, const ntuple &rhs)
    {
      constexpr auto lt = comparators::lessThan<T...>();
      return lt(lhs, rhs);
    }
    inline static constexpr std::size_t __size__ = sizeof...(T);
  };

  template <>
  struct ntuple<>
  {
    constexpr ntuple() = default;
    constexpr ntuple(const ntuple &) = default;
    constexpr ntuple &operator=(const ntuple &) = default;

    friend std::ostream &operator<<(std::ostream &out, const ntuple &self)
    {
      out << "nt::ntuple<>";

      return out;
    }

    template <typename... ARGS>
    auto operator|(const ntuple<ARGS...> &rhs) const
    {
      return rhs;
    }

    friend constexpr bool operator<(const ntuple &lhs, const ntuple &rhs)
    {

      return false;
    }
    inline static constexpr std::size_t __size__ = 0;
  };

  template <typename... Ts>
  ntuple(Ts &&...ts) -> ntuple<_Remove_cvref_t<Ts>...>;

  template <int N, typename... ARGS>
  constexpr decltype(auto) get_nth(const nt::ntuple<ARGS...> &nt)
  {
    return nt::_Remove_cvref_t<nt::NthTypeOf<N, nt::_Remove_cvref_t<ARGS>...>>::get(nt);
  }

  template <int N, typename... ARGS>
  constexpr decltype(auto) get_nth(nt::ntuple<ARGS...> &nt)
  {
    return nt::_Remove_cvref_t<nt::NthTypeOf<N, nt::_Remove_cvref_t<ARGS>...>>::get(nt);
  }

  // Primary template for contains_type; defaults to false
  template <typename T, typename Ntuple>
  struct contains_type : std::false_type
  {
  };

  // Specialization for ntuple
  template <typename T, typename... ARGS>
  struct contains_type<T, ntuple<ARGS...>> : std::disjunction<std::is_same<T, ARGS>...>
  {
  };

  // Helper variable template
  template <typename T, typename Ntuple>
  constexpr bool contains_type_v = contains_type<T, Ntuple>::value;

}



