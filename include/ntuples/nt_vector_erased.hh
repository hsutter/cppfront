#pragma once
#include <typeindex>

#include <memory>
#include <string>
#include "ntuples/span.hh"
#include "ntuples/constexpr_for.hh"

namespace nt
{

    struct vector_erased
    {
        struct concept1
        {
            virtual ~concept1() = default;
            virtual std::size_t size() const = 0;
            virtual const void *element_ptr(std::size_t i) const = 0;
            virtual const void *element_ptr(const std::string &name) const = 0;
            virtual std::size_t element_size() const = 0;
            virtual std::size_t columns() const = 0;
            virtual std::type_index type_at(std::size_t index) const = 0;
            virtual std::type_index type_at(const std::string &name) const = 0;
            virtual bool is_const_data() const = 0;
            virtual std::string get_name(std::size_t index) const  =  0;
        };

        template <typename VecT>
        struct model : concept1
        {

            VecT *vec;

            model(VecT *v) : vec(v) {}

            bool is_const_data() const override
            {
                return std::is_const_v<std::remove_pointer_t<VecT>>;
            }

            std::size_t size() const override
            {
                return vec->size();
            }

            std::size_t columns() const override
            {

                return (*vec)[0].__size__;
            }
            virtual std::string get_name(std::size_t index) const   override {
                std::string ret;
                constexpr_for<0, nt::_Remove_cvref_t<decltype((*vec)[0])>::__size__, 1>([&](auto i)
                                                                                        {
                                                      auto &ele = ::nt::get<i>((*vec)[0]);
                                                      if (index == i)
                                                      {
                                                          ret = ele.get_name();
                                                      } });

                if (ret.empty())
                {
                    throw std::runtime_error("get_name: Could not find element at index: " + std::to_string(index));
                }
                return ret;
            }
            const void *element_ptr(std::size_t index) const override
            {
                const void *ret = nullptr;
                constexpr_for<0, nt::_Remove_cvref_t<decltype((*vec)[0])>::__size__, 1>([&](auto i)
                                                                                        {
                                                      auto &ele = ::nt::get<i>((*vec)[0]);
                                                      if (index == i)
                                                      {
                                                          ret = &(ele.v);
                                                      } });

                if (ret == nullptr)
                {
                    throw std::runtime_error("element_ptr: Could not find element at index: " + std::to_string(index));
                }
                return ret;
            }

            

            const void *element_ptr(const std::string &name) const override
            {
                const void *ret = nullptr;
                constexpr_for<0, nt::_Remove_cvref_t<decltype((*vec)[0])>::__size__, 1>([&](auto i)
                                                                                        {
                                                      auto &ele = ::nt::get<i>((*vec)[0]);
                                                      if (ele.get_name() == name)
                                                      {
                                                          ret = &(ele.v);
                                                      } });
    if (ret == nullptr) {
        throw std::runtime_error("element_ptr: Could not find element with name \"" + name + "\"");
    }
                return ret;
            }

            std::size_t element_size() const override
            {
                return sizeof((*vec)[0]);
            }

            std::type_index type_at(std::size_t index) const override
            {
                std::optional<std::type_index> ret{};

                constexpr_for<0, nt::_Remove_cvref_t<decltype((*vec)[0])>::__size__, 1>([&](auto i)
                                                                                        {
                                                      auto &ele = ::nt::get<i>((*vec)[0]);
                                                      if (index == i)
                                                      {
                                                          ret = typeid(nt::_Remove_cvref_t<decltype(::nt::get<i>((*vec)[0]).v)>);
                                                      } });

                                                      
                if (!ret.has_value())
                {
                    throw std::runtime_error("element_ptr: Could not find element at index: " + std::to_string(index));
                }
                return *ret;
            }

            virtual std::type_index type_at(const std::string &name) const override
            {
                std::optional<std::type_index> ret{};

                constexpr_for<0, nt::_Remove_cvref_t<decltype((*vec)[0])>::__size__, 1>([&](auto i)
                                                                                        {
                                                      auto &ele = ::nt::get<i>((*vec)[0]);
                                                      if (ele.get_name() == name)
                                                      {
                                                          ret = typeid(nt::_Remove_cvref_t<decltype(::nt::get<i>((*vec)[0]).v)>);
                                                      } });
                if (!ret.has_value()) {
                    throw std::runtime_error("element_ptr: Could not find element with name \"" + name + "\"");
                }
                return *ret;
            }
        };

        std::shared_ptr<concept1> self;

        template <typename VecT>
        vector_erased(VecT &vec) : self(std::make_shared<model<VecT>>(&vec)) {}

    
        vector_erased(std::shared_ptr<concept1> concept_) : self(std::move(concept_)) {}

        std::size_t size() const
        {
            return self->size();
        }



        std::size_t columns() const
        {
            return self->columns();
        }

        std::string column_name(std::size_t i){
            
            return self->get_name(i);
        }

        template <typename T>
        nt::span<T> get(std::size_t i) const
        {
            if (self->is_const_data() && !std::is_const_v<T>)
            {
                throw std::runtime_error("Cannot extract span<T> with non-const T from const vector_erased");
            }
            if (self->type_at(i) != typeid(T)){
                throw std::runtime_error("Type mismatch at index: " + std::to_string(i));
            }
            
            return nt::span<T>(
                reinterpret_cast<T *>(const_cast<void *>(self->element_ptr(i))),
                self->size(),
                self->element_size());
        }

        template <typename T>
        nt::span<T> get(const std::string &name) const
        {
            if (self->is_const_data() && !std::is_const_v<T>)
            {
                throw std::runtime_error("Cannot extract span<T> with non-const T from const vector_erased");
            }
            if (self->type_at(name) != typeid(T)){
                throw std::runtime_error("Type mismatch at element with name \"" + name + "\"");
            }

            return nt::span<T>(
                reinterpret_cast<T *>(const_cast<void *>(self->element_ptr(name))),
                self->size(),
                self->element_size());
        }
        std::type_index type_at(std::size_t index) const
        {
            return self->type_at(index);
        };

        std::type_index type_at(const std::string &name) const
        {
            return self->type_at(name);
        };
    };
}
