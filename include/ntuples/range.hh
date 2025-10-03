#pragma once

#include <functional>
#include <iterator>
#include <cstddef>
#include <ranges>
#include <iostream>

namespace nt
{
    inline bool std_comp(void *v1, void *v2)
    {
        return v1 && (v1 != v2);
    }
}

namespace nt
{

    
    
    template <typename T>
    class range
    {
    public:
        inline constexpr static  T* not_nulltptr = (T*)1; 
        struct iterator
        {
            
            const T *ptr;
            const range *base;

            using value_type = T;
            using difference_type = std::ptrdiff_t;
            using iterator_category = std::forward_iterator_tag;

            const value_type& operator*() const { return base->value; }

            iterator &operator++()
            {
                ptr = (T *)base->m_next((void *)ptr, (void *)base->to_, &(base->value) );
                return *this;
            }

            iterator operator++(int)
            {
                auto tmp = *this;
                ptr = (T *)base->m_next((void *)ptr, (void *)base->to_);
                return tmp;
            }

            bool operator==(const iterator &other) const { return !base->cmp((void *)ptr, (void *)base->to_); }
            bool operator!=(const iterator &other) const { return base->cmp((void *)ptr, (void *)base->to_); }
        };

        range(const T *from, const T *to, T value_,
                    std::function<void *(void *, void *, void *)> next,
                    std::function<bool(void *, void *)> cmp_ = nt::std_comp) : from_( from), to_(to),  value(value_),  m_next(std::move(next)), cmp(cmp_)
        {
         
        }
        range(range&& rhs) : from_(rhs.from_), to_(rhs.to_),  value(rhs.value),  m_next(std::move(rhs.m_next)), cmp(std::move(rhs.cmp) ) {
           
        }
        range(const range& rhs)  = delete;

        iterator begin() const
        {
            auto ret = iterator();
            ret.ptr = from_;
            ret.base = this;
            return ret;
        }
        iterator end() const
        {
            auto ret = iterator();
            ret.ptr = to_;
            ret.base = this;
            return ret;
        }

        std::function<void *(void *, void *, void*)> m_next;
        std::function<bool(void *, void *)> cmp;
        const T *from_;
        const T *to_;
        mutable T value = {};
    };

    
  template <typename data_T, typename FUNC_T>
  auto subrange(const  data_T &data, FUNC_T &&fun)
  {
    using vector_element_t = typename std::remove_cvref_t<decltype(data)>::value_type;

    auto *begin = [&](auto *vec)
    {
      while (vec != data.data() + data.size() && !fun(*vec))
      {
        ++vec;
      }
      return vec;
    }(data.data());

    return ::nt::range<vector_element_t>{
        begin,

        data.data() + data.size(),
        *begin,
        [&](auto *v1, auto *v2, auto *v3)
        {
          double *ret = (vector_element_t *)v1;
          double *end = (vector_element_t *)v2;
          ++ret;
          while (end != v2 && !fun(*ret))
          {
            ++ret;
          }
          *(vector_element_t *)v3 = *ret;
          return (void *)ret;
        }};
  }

  template <typename T>
  auto generator(T begin_, T end, T step = 1) {
    using element_t = typename std::remove_cvref_t<decltype(begin_)>;
    return nt::range<element_t>{
        nt::range<element_t>::not_nulltptr,
        nullptr,
        begin_,
        [&, end_ = end, current = begin_, step_ = step](auto *v1, auto *v2, auto *v3) mutable
        {
          current += step_;
          void *ret = v1;
          if (current == end_)
          {
            ret = nullptr;
          } else {
            *(element_t *)v3 = current;
          }

          return (void *)ret;
        }};
  };

  
  template <typename T, typename FUNC_T>
  auto transform(const T &container, FUNC_T&& function)
  {
    using element_t = typename std::remove_cvref_t<decltype(function(*(container.begin())))>;

    auto begin = container.begin();
    auto first = function(*begin);

    return nt::range<element_t>{
        nt::range<element_t>::not_nulltptr,
        nullptr,
        first,
        [&, current = begin, end_ = container.end(), function_ = std::forward<FUNC_T>(function)](auto *v1, auto *v2, auto *v3) mutable
        {
          ++current;
          void *ret = v1;
          if (current == end_)
          {
            ret = nullptr;
          }else {
            *(element_t *)v3 = function_(*current);
          }

          return (void *)ret;
        }};
  };
}