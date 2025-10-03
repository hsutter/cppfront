#pragma once
#include "ntuples/ntuples.hh"
#include "ntuples/constexpr_for.hh"
#include "ntuples/generic_algorithms.hh"
#include <vector>
#include <fstream>
#include <sstream>
#include <map>


namespace nt
{

    namespace __imple__
    {

        template <typename FIELD_T, typename VECT_T, std::size_t Index>
        struct member_span
        {
            member_span()
            {
            }
            static constexpr std::size_t field_index = Index;
            using M_FIELD_T = FIELD_T;
            using M_VEC_T = VECT_T;

            nt::span<FIELD_T> get()
            {
                auto &m_vec = reinterpret_cast<VECT_T &>(*(this - field_index));

                return nt::span<FIELD_T>(
                    m_vec.m_data.size() ? &(FIELD_T::get(m_vec.m_data[0])) : nullptr,
                    m_vec.m_data.size(), sizeof(decltype(m_vec.m_data[0])));
            }

            auto get_primitive()
            {
                auto &m_vec = reinterpret_cast<VECT_T &>(*(this - field_index));

                return nt::span<decltype(FIELD_T::get(m_vec.m_data[0]).v)>(
                    m_vec.m_data.size() ? &(FIELD_T::get(m_vec.m_data[0]).v) : nullptr,
                    m_vec.m_data.size(), sizeof(decltype(m_vec.m_data[0])));
            }

            auto operator()() 
            {
                return get();
            }

            auto operator()() const
            {
                return get();
            }

            decltype(auto) operator[](size_t i) const 
            {
                auto &m_vec = reinterpret_cast<const VECT_T &>(*(this - field_index));
                return  FIELD_T::get(m_vec.m_data[i]);
            }

            decltype(auto) operator[](size_t i)
            {
                auto &m_vec = reinterpret_cast<VECT_T &>(*(this - field_index));
                return  FIELD_T::get(m_vec.m_data[i]);
            }
        };

        template <typename IndexSeq, typename... Ts>
        struct vector_frame_impl;

        template <std::size_t... Is, typename... Ts>
        struct vector_frame_impl<std::index_sequence<Is...>, Ts...> :

            nt::base_maker_t<
                nt::_Remove_cvref_t<Ts>,
                nt::ax_type2<
                    nt::__imple__::member_span<Ts, vector_frame_impl<std::index_sequence<Is...>, Ts...>, Is>,
                    typename Ts::field_name_container_T>>...
        {
            std::vector<nt::ntuple<Ts...>> m_data;
            /* data */
            vector_frame_impl(const std::vector<
                              nt::ntuple<Ts...>> &vec) : m_data(vec) {}

            vector_frame_impl() = default;
            friend auto begin(vector_frame_impl const &v) { return v.m_data.begin(); }
            friend auto end(vector_frame_impl const &v) { return v.m_data.end(); }

            friend auto begin(vector_frame_impl &v) { return v.m_data.begin(); }
            friend auto end(vector_frame_impl &v) { return v.m_data.end(); }
            friend std::ostream &operator<<(std::ostream &os, const vector_frame_impl &v)
            {
                using nt::algorithms::operator<<;
                os << v.m_data;
                return os;
            }
            decltype(auto) operator[](std::size_t i)
            {
                return m_data[i];
            }
            decltype(auto) operator[](std::size_t i) const
            {
                return m_data[i];
            }
            std::size_t size() const
            {
                return m_data.size();
            }
        };
    }
    template <typename... Ts>
    using vector_frame = nt::__imple__::vector_frame_impl<std::index_sequence_for<Ts...>, Ts...>;

    template <typename... T>
    auto to_vector_frame(const std::vector<nt::ntuple<T...>> &vec)
    {
        return vector_frame<T...>(vec);
    }

    namespace __imple__
    {
        template <typename... T>
        auto get_vector_frame_type(const nt::ntuple<T...> &vec)
        {
            return vector_frame<T...>(std::vector<nt::ntuple<T...>>{});
        }
    }

    template <typename FUNC_T>
    auto fill_vector_frame(size_t entries, FUNC_T &&func)
    {
        decltype(__imple__::get_vector_frame_type(func(size_t(0)))) ret;
        ret.m_data.reserve(entries);
        for (size_t i = 0; i < entries; ++i)
        {
            ret.m_data.push_back(func(i));
        }
        return ret;
    }

    template <typename RANGE_T>
    auto fill_vector_frame(RANGE_T &&range_)
    {

        decltype(__imple__::get_vector_frame_type(*range_.begin())) ret;
        // ret.m_data.reserve(entries);
        for (auto &&e : range_)
        {
            ret.m_data.push_back(e);
        }
        return ret;
    }

    template <typename FUN_T>
    struct vector_frame_filler
    {

        FUN_T m_fun;
        template <typename T>
        vector_frame_filler(T &&f) : m_fun(f) {}

        auto operator()(size_t entries)
        {
            decltype(__imple__::get_vector_frame_type(m_fun(size_t(0)))) ret;
            ret.m_data.reserve(ret.m_data.size() + entries);
            for (size_t i = 0; i < entries; ++i)
            {
                ret.m_data.push_back(m_fun(i));
            }
            return ret;
        }

        template <typename T>
        auto operator()(size_t entries, std::vector<T> &vec)
        {
            vec.reserve(vec.size() + entries);
            for (size_t i = 0; i < entries; ++i)
            {
                vec.push_back(m_fun(i));
            }
        }

        auto get_buffer() const
        {
            decltype(__imple__::get_vector_frame_type(m_fun(size_t(0)))) ret;
            return ret;
        }
    };
    template <typename F>
    vector_frame_filler(F &&) -> vector_frame_filler<std::decay_t<F>>;

    template <typename... ARGS>
    void to_csv(const std::string &filename, const nt::vector_frame<ARGS...> &vec)
    {
        auto out = std::ofstream(filename);
        std::string start = "";
        nt::constexpr_for<0, sizeof...(ARGS), 1>([&](auto i)
                                                 {
                                             using current_t = decltype(nt::NthTypeOf<i, std::remove_cvref_t<ARGS>...>{});
                                             out << start << current_t::get_name();
                                             start = ","; });

        out << "\n";
        for (auto &&e : vec)
        {
            start = "";
            nt::constexpr_for<0, sizeof...(ARGS), 1>([&](auto i)
                                                     {
                                               using current_t = decltype(nt::NthTypeOf<i, std::remove_cvref_t<ARGS>...>{});
                                               out << start << current_t::get(e).v;
                                               start = ","; });
            out << "\n";
        }
    }

    template <typename... ARGS>
    auto from_csv(const std::string &filename, nt::vector_frame<ARGS...> &ret)
    {

        auto in = std::ifstream(filename);
        std::string line;
        std::map<std::string, size_t> header;

        std::vector<double> dummy;
        std::vector<size_t> index_of_;

        if (!std::getline(in, line))
        {
            return;
        }
        std::istringstream ss(line);
        std::string token;
        size_t i1 = 0;
        while (std::getline(ss, token, ','))
        {
            header[token] = i1++;
        }
        nt::constexpr_for<0, sizeof...(ARGS), 1>([&](auto index)
                                                 {
                                             using current_t = decltype(nt::NthTypeOf<index, std::remove_cvref_t<ARGS>...>{});
                                             auto it = header.find(current_t::get_name());
                                             if (it != header.end())
                                             {
                                               index_of_.push_back(it->second);
                                             } });
        size_t j = 0;
        while (std::getline(in, line))
        {
            size_t i = 0;
            std::istringstream ss(line);
            std::string token;
            dummy.clear();
            while (std::getline(ss, token, ','))
            {
                dummy.push_back(std::atof(token.c_str()));
            }

            ret.m_data.emplace_back();

            nt::constexpr_for<0, sizeof...(ARGS), 1>([&](auto index)
                                                     {
                                               using current_t = decltype(nt::NthTypeOf<index, std::remove_cvref_t<ARGS>...>{});
                                               current_t::get(ret.m_data[j]).v = dummy[index_of_[index]]; });

            ++j;
        }
    }

    template <typename... ARGS>
    auto from_csv(const std::string &filename, nt::vector_frame<ARGS...> &&ret)
    {
        from_csv(filename, ret);
        return ret;
    }
}