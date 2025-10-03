#pragma once

#include "ntuples/ntuples.hh"


namespace nt::algorithms
{



  template <typename... T>
  struct __group
  {
    template <typename VEC_T, typename FUNC_T>
    static auto apply_append(const std::vector<VEC_T> &vec, FUNC_T &&fun)
    {
      auto fun_c = [&](const auto& rng)
      {
          auto tail = rng.begin();
        return nt::ntuple(T::get(*tail)...) | fun(rng);
      };
      return __apply__internal__(vec, fun_c);
    }

    template <typename VEC_T, typename FUNC_T>
    static auto apply(const std::vector<VEC_T> &vec, FUNC_T &&fun)
    {
      auto fun_c = [&](const auto & rng)
      {
        return fun(rng);
      };
      return __apply__internal__(vec, fun_c);
    }

  private:

    template <typename VEC_T, typename FUNC_T>
    static auto create_empty_vector()
    {
      return std::vector< decltype ( std::declval<FUNC_T>() ( std::declval<const std::vector<VEC_T>& >() ) ) >{};
    }

    template <typename VEC_T, typename FUNC_T>
    static auto __apply__internal__(const std::vector<VEC_T> &vec, FUNC_T &&fun_c)
    {
      static constexpr auto lt = nt::comparators::lessThan<T...>();
      static constexpr auto eq = nt::comparators::equal<T...>();
      auto ret = create_empty_vector<VEC_T, FUNC_T>();



      if (vec.empty())
      {
        return ret;
      }
      auto min_element = vec[0];
      auto max_element = vec[0];
      
      for (const auto& e : vec) {
        if (lt(e, min_element)) {
          min_element = e;
        }
     
        if (lt(max_element, e)) {
          max_element = e;
        }
      }

      if (eq(min_element, max_element)) {
        ret.push_back(
          fun_c(vec)
        );
        return ret;
      }

      std::vector<VEC_T> buff{};
      buff.reserve(vec.size());



      auto process = [&]() {
        buff.clear();
        VEC_T next_min_element{};
        next_min_element = max_element;
        
        for (const auto& e : vec) {
          if (eq(min_element, e)) {
            buff.push_back(e);
          }
          else if (lt(min_element, e) && lt(e, next_min_element)) {
            next_min_element = e;
          }

        }

        min_element = next_min_element;
        

        ret.push_back(fun_c(buff));
      };
      
      while (lt(min_element, max_element)) {
        process();
     
      }

      process();
      

      return ret;
    }
  };

  template <typename... ARGS>
  auto group(ARGS...)
  {
    return __group<nt::_Remove_cvref_t<ARGS>...>{};
  }


  template <typename T> 
  constexpr auto get_default_element(T&& t) {
    return nt::_Remove_cvref_t<decltype(t[0])>{};
  }
}

