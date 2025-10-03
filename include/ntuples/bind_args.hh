#pragma once
#include "ntuples/ntuples.hh"
#include <optional>
namespace nt
{
    namespace __imple__
    {

        template <typename T>
        struct is_ax_name_container
        {
        private:
            template <typename U>
            static std::true_type test(const nt::field_name_container<U> *);

            static std::false_type test(...);

        public:
            static constexpr bool value = decltype(test(std::declval<std::remove_cvref_t<T> *>()))::value;
        };

        template <typename T>
        constexpr bool is_ax_name_container_v = is_ax_name_container<T>::value;

 

        template <size_t N, typename NT_T, typename T1, typename... ARGS>
        auto bind_args1(NT_T &&t, T1 &&t1, ARGS &&...args)
        {
            if constexpr (::nt::__imple__::is_ax_name_container_v<T1>)
            {
                using T1Bare = std::remove_cvref_t<T1>;
                if constexpr (T1Bare::template  index_of<NT_T>() < N)
                {
                    static_assert(dependent_false<NT_T>::value, "[NTUPLE ERROR] Named argument appears after positional arguments. "
                                                                "All named arguments must follow positional ones.");
                }
                else
                {
              
                    t[t1].v = t1.v;
            
                }
            }

            if constexpr (sizeof...(args) == 0)
            {
                return t;
            }
            else
            {
                return ::nt::__imple__::bind_args1<N>(t, std::forward<ARGS>(args)...);
            }
        }


        template <size_t N, typename NT_T, typename T1, typename... ARGS>
        auto bind_args0(NT_T &&t, T1 &&t1, ARGS &&...args)
        {
            if constexpr (is_ax_name_container_v<T1>)
            {
                return ::nt::__imple__::bind_args1<N>(t, std::forward<T1>(t1), std::forward<ARGS>(args)...);
            }
            else
            {
                nt::get_nth<N>(t).v = t1;
                if constexpr (sizeof...(args) == 0)
                {   
                    return t;
                } 
                else {
                    return ::nt::__imple__::bind_args0<N + 1>(t, std::forward<ARGS>(args)...);
                }
            }
        }

                template<typename T>
        void check_optional_has_value(const T&) {
        // Do nothing if T is not a specialization of std::optional
        }

        template<typename T>
        void check_optional_has_value(const std::optional<T>& opt) {
        if (!opt.has_value()) {
            throw std::runtime_error("std::optional is empty");
        }
        }

    }
    template <typename... NamedArgs>
    auto bind_args(NamedArgs &&...named_args)
    {
        // Return a lambda that captures named_args
        return [&](auto &&...args)
        {
            auto tup = nt::ntuple(std::forward<NamedArgs>(named_args)...);
            if constexpr (sizeof...(args) == 0)
            {
                constexpr_for<0, tup.__size__ , 1>([&](auto i){
                   ::nt::__imple__::check_optional_has_value(get_nth<i>(tup).v);
                 });

                return tup;
            }
            else
            {

                auto tup1 =  ::nt::__imple__::bind_args0<0>(std::move(tup), std::forward<decltype(args)>(args)...);
                
                constexpr_for<0, tup1.__size__ , 1>([&](auto i){
                   ::nt::__imple__::check_optional_has_value(get_nth<i>(tup).v);
                 });
                return tup1;
            }
        };
    }
    template <typename T>
    auto required(){
        return std::optional<T>();
    }
}