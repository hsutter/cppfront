#pragma once

namespace nt::algorithms
{

  template <typename VEC, typename FUNC_T>
  auto add_column(const VEC &vec, FUNC_T &&func)
  {
    std::vector<decltype(vec[0] | func(vec[0]))> ret;
    ret.reserve(vec.size());
    for (const auto &e : vec)
    {
      ret.push_back(e | func(e));
    }
    return ret;
  }

  template <typename FUNC_T>
  auto fill_vector(size_t entries, FUNC_T &&func)
  {
    std::vector<decltype(func(size_t(0)))> ret;
    ret.reserve(entries);
    for (size_t i = 0; i < entries; ++i)
    {
      ret.push_back(func(i));
    }
    return ret;
  }

  template <typename... ARGS>
  std::ostream &operator<<(std::ostream &out, const std::vector<nt::ntuple<ARGS...>> &self)
  {
    out << "|";

    constexpr_for<0, sizeof...(ARGS), 1>([&](auto ntuple_index)
                                         {
                                          using T =   nt::_Remove_cvref_t<decltype(nt::get_nth<ntuple_index>(self[0]))>;
                                           out << ' '<<T::get_name() << " |" ;
                                         });
        out << "\n";
        out << "|";
    constexpr_for<0, sizeof...(ARGS), 1>([&](auto ntuple_index)
                                         {
                                          using T =   nt::_Remove_cvref_t<decltype(nt::get_nth<ntuple_index>(self[0]))>;
                                           out  << "----|" ;
                                         });

    for (auto&& e : self){
        out << "\n";
        out << "|";
          constexpr_for<0, sizeof...(ARGS), 1>([&](auto ntuple_index)
                                         {
                                         
                                           out << ' '<< nt::get_nth<ntuple_index>(e).v  << " |" ;
                                         });
    }
    out << "\n";

    return out;
  }

  template <typename T0, typename T1, typename T2, typename Comparision_T, typename projecttion_t>
  void join_vectors_r(T0 &ret, const T1 &t1, const T2 &t2, Comparision_T comp, projecttion_t project)
  {
    ret.clear();
    for (const auto &e1 : t1)
    {
      for (const auto &e2 : t2)
      {
        if (comp(e1, e2))
        {
          ret.push_back(project(e1, e2));
        }
      }
    }
  }

  template <typename T1, typename T2, typename Comparision_T, typename projecttion_t>
  auto join_vectors(const T1 &t1, const T2 &t2, Comparision_T comp, projecttion_t project)
  {
    std::vector<decltype(project(t1[0], t2[0]))> ret;
    join_vectors_r(ret, t1, t2, comp, project);
    return ret;
  }

  template <typename CONTAINER_T>
  void sort(CONTAINER_T &container)
  {
    std::sort(container.begin(), container.end());
  }

  template <typename CONTAINER_T, typename COMP_T>
  void sort(CONTAINER_T &container, COMP_T &&comp)
  {
    std::sort(container.begin(), container.end(), comp);
  }

  template <typename CONTAINER_T, typename OP_T>
  auto count_if(const CONTAINER_T &container, OP_T op)
  {
    int i = 0;
    for (const auto &e : container)
      if (op(e))
        ++i;
    return i;
  }

  template <typename VEC_T, typename FILTER_T>
  void filter(VEC_T &vec, FILTER_T &&f)
  {
    auto removeIt = std::remove_if(vec.begin(), vec.end(), [&](auto &&e)
                                   { return !f(e); });
    vec.erase(removeIt, vec.end());
  }

  template <typename VEC_T, typename FILTER_T>
  auto filter_copy(const VEC_T &vec, FILTER_T &&f)
  {
    VEC_T ret;
    ret.reserve(vec.size());
    for (const auto &e : vec)
    {
      if (f(e))
      {
        ret.push_back(e);
      }
    }
    return ret;
  }
}