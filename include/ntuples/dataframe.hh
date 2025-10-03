#pragma once
#include "ntuples/ntuples.hh"

namespace nt{




  template <typename... Ts>
  struct dataframe : nt::base_maker_t<nt::_Remove_cvref_t<Ts>, nt::ax_type2<std::vector<Ts>, typename Ts::struct_maker>>...
  {

    template <typename T2>
    decltype(auto) operator[](const nt::field_name_container<T2> &t)
    {
      return nt::field_name_container<T2>::get(*this);
    }

    auto operator[](size_t i)
    {
      using ret_t = nt::ntuple<_Remove_cvref_t<Ts> &...>;
      return ret_t{
          get<Ts>()[i]...};
    }

    auto operator[](size_t i) const
    {
      using ret_t = nt::ntuple<const Ts &...>;
      return ret_t{
          get<Ts>()[i]...};
    }

    template <typename T>
    void push_back(const T &t)
    {

      [](auto...) {}(Ts::get(*this).emplace_back(Ts::get(t))...);
    }

    template <typename... T>
    void emplace_back(T &&...t)
    {
      static_assert(sizeof...(t) == sizeof...(Ts), "\n==============missmatched amount of arguments=================\n");
      [](auto...) {}(T::get(*this).emplace_back(std::forward<T>(t))...);
    }

    template <typename T1>
    decltype(auto) get() const
    {
      return T1::get(*this);
    }

    template <typename T1>
    decltype(auto) get()
    {
      return T1::get(*this);
    }

    auto size() const
    {
      auto size = _Remove_cvref_t<NthTypeOf<0, Ts...>>::get(*this).size();
      return size;
    }

    template <int N>
    static constexpr auto get_nth_type()
    {

      return get_ax_name_container(NthTypeOf<N, _Remove_cvref_t<Ts>...>{});
    }
    friend std::ostream &operator<<(std::ostream &out, const dataframe &self)
    {
      out << "|";

      constexpr_for<0, sizeof...(Ts), 1>([&](auto ntuple_index)
                                         {
      static const auto x = self.template  get_nth_type<ntuple_index>();
      out << " ";
      out <<  std::setw(5) << x.get_name();
      out << " |"; });

      out << "\n";
      out << "|";
      constexpr_for<0, sizeof...(Ts), 1>([&](auto i)
                                         {
                                           out << std::setw(5) << "-------|";
                                         });
      out << "\n";
      auto size = self.size();
      for (int i = 0; i < size; ++i)
      {
        auto current_element = self[i];
        out << "|";
        constexpr_for<0, sizeof...(Ts), 1>([&](auto ntuple_index)
                                           {
        static const  auto x = self.template get_nth_type<ntuple_index>();
        out << " ";
        out <<  std::setw(5) << x.get(current_element).v;
        out << " |"; });
        out << "\n";
      }

      return out;
    }
  };

  template <typename... Ts>
  dataframe(Ts &&...ts) -> dataframe<_Remove_cvref_t<Ts>...>;

  template <typename T>
  struct dataframe_maker
  {
  };

  template <typename... T>
  struct dataframe_maker<ntuple<T...>>
  {
    using type = dataframe<_Remove_cvref_t<T>...>;
  };

  template <typename F>
  auto fill_dataframe(int index, F &&f)
  {
    typename dataframe_maker<decltype(f(0))>::type ret;
    for (int i = 0; i < index; ++i)
    {
      ret.push_back(f(i));
    }
    return ret;
  }
}