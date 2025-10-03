#pragma once
#include <typeindex>

#include <memory>
#include <string>

#include "ntuples/std_adapter.hh"
#include "ntuples/constexpr_for.hh"

namespace nt
{


    template <typename T>
    struct is_ntuple : std::false_type {};

    template <typename... Ts>
    struct is_ntuple<ntuple<Ts...>> : std::true_type {};
    template <typename T>
    concept ntuple_type = nt::is_ntuple<std::remove_cvref_t<T>>::value;


    template <typename T = double>
    struct nt_erased
    {
        struct concept1
        {
            virtual ~concept1() = default;
            virtual std::type_index type_at(size_t index) const = 0;
            virtual const void *get_raw(size_t index) const = 0;

            virtual std::type_index type_at(const std::string &name) const = 0;
            virtual const void *get_raw(const std::string &name) const = 0;
            virtual std::size_t size() const = 0;
            virtual std::string get_name(size_t index) = 0;

            virtual T get(const std::string &name) const = 0;
            virtual T get(size_t index) const = 0;

        };

        template <typename NT>
        struct model : concept1
        {
            NT *data = nullptr;

            model(NT *d) : data(d) {}

            std::type_index type_at(size_t index) const override
            {
                std::type_index ret = typeid(int);

                constexpr_for<0, NT::__size__, 1>([&](auto i)
                                                  {
                                                      if (i == index)
                                                      {
                                                          ret = typeid(nt::_Remove_cvref_t<decltype(::nt::get<i>((NT)*data).v)>);
                                                      } });

                return ret;
            }

            const void *get_raw(size_t index) const override
            {
                void *ret = nullptr;

                constexpr_for<0, NT::__size__, 1>([&](auto i)
                                                  {
                                                      if (i == index)
                                                      {
                                                          ret = &::nt::get<i>(*data).v;
                                                      } });

                return ret;
            }

            virtual std::type_index type_at(const std::string &name) const override
            {
                std::type_index ret = typeid(int);

                constexpr_for<0, NT::__size__, 1>([&](auto i)
                                                  {
                                                      auto &ele = ::nt::get<i>(*data);
                                                      if (ele.get_name() == name)
                                                      {
                                                          ret = typeid(nt::_Remove_cvref_t<decltype(::nt::get<i>((NT)*data).v)>);
                                                      } });

                return ret;
            }
            virtual const void *get_raw(const std::string &name) const override
            {
                void *ret = nullptr;

                constexpr_for<0, NT::__size__, 1>([&](auto i)
                                                  {
                                                      auto &ele = ::nt::get<i>(*data);
                                                      if (ele.get_name() == name)
                                                      {
                                                          ret = &ele.v;
                                                      } });

                return ret;
            }

            virtual std::size_t size() const override
            {
                return NT::__size__;
            }

            virtual std::string get_name(size_t index) {
                std::string  ret {};

                constexpr_for<0, NT::__size__, 1>([&](auto i)
                                                  {
                                                      if (i == index)
                                                      {
                                                          ret = ::nt::get<i>(*data).get_name();
                                                      } });
                if (ret.empty())
                {
                    throw std::runtime_error("get_name: Could not find element at index: " + std::to_string(index));
                }
                return ret;
            }

            virtual T get(const std::string &name) const override
            {
                T ret = 0;

                constexpr_for<0, NT::__size__, 1>([&](auto i)
                                                  {
                                                      auto &ele = ::nt::get<i>(*data);
                                                      if (ele.get_name() == name)
                                                      {
                                                        if constexpr (std::is_convertible_v<decltype(ele.v), T>) {
                                                            ret =  static_cast<T>(ele.v);
                                                        } else {
                                                            throw std::runtime_error("Value is not convertible to T");
                                                        }
                                                          
                                                      } });

                return ret;
            }

            virtual T get(size_t index) const override
            {
                T ret = 0;

                constexpr_for<0, NT::__size__, 1>([&](auto i)
                                                  {
                                                      if (i == index)
                                                      {
                                                          auto& ele = ::nt::get<i>(*data);

                                                        if constexpr (std::is_convertible_v<decltype(ele.v), T>) {
                                                            ret =  static_cast<T>(ele.v);
                                                        } else {
                                                            throw std::runtime_error("Value is not convertible to T");
                                                        }
                                                      } });

                return ret;
            }


        };

        std::shared_ptr<concept1> self;

        template <ntuple_type NT>
        nt_erased(NT &val) : self(std::make_shared<model<NT>>(&val)) {}

        nt_erased(const nt_erased &) = default;
        nt_erased(nt_erased &) = default;
        nt_erased(nt_erased &&) = default;


        std::string get_name(size_t index) const {
            return self->get_name(index);
        }
        auto type_at(size_t index) const{
            return self->type_at(index);
        }
        template <typename T1>
        T1 get(size_t index) const
        {
            if (self->type_at(index) != typeid(T1))
                throw std::runtime_error("Type mismatch at index");
            return *reinterpret_cast<const T1 *>(self->get_raw(index));
        }

        template <typename T1>
        T1 get(const std::string &name) const
        {
            if (self->type_at(name) != typeid(T1))
                throw std::runtime_error("Type mismatch at index");
            return *reinterpret_cast<const T1 *>(self->get_raw(name));
        }

        auto size() const
        {
            return self->size();
        }

        int get(const std::string &name) const
        {
            return self->get(name);
        }

        int get(size_t index) const
        {
            return self->get(index);
        }

      
    };
}