#pragma once

#include <cstddef>
#include <iostream>

namespace nt
{
    template <typename T>
    class span : public std::ranges::view_interface<span<T>>
    {
    public:
        using element_type = T;
        using value_type = std::remove_cv_t<T>;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using pointer = T *;
        using reference = T &;
        class iterator
        {
        public:
            using iterator_category = std::random_access_iterator_tag;
            using value_type = T;
            using difference_type = std::ptrdiff_t;
            using pointer = T *;
            using reference = T &;

            iterator() : m_ptr(nullptr), m_stride(0) {}
            iterator(std::byte *ptr, size_type stride) : m_ptr(ptr), m_stride(stride) {}

            reference operator*() const { return *reinterpret_cast<pointer>(m_ptr); }
            pointer operator->() const { return reinterpret_cast<pointer>(m_ptr); }

            iterator &operator++()
            {
                m_ptr += m_stride;
                return *this;
            }
            iterator operator++(int)
            {
                auto tmp = *this;
                ++(*this);
                return tmp;
            }

            iterator &operator--()
            {
                m_ptr -= m_stride;
                return *this;
            }
            iterator operator--(int)
            {
                auto tmp = *this;
                --(*this);
                return tmp;
            }

            iterator operator+(difference_type n) const { return iterator(m_ptr + n * m_stride, m_stride); }
            iterator operator-(difference_type n) const { return iterator(m_ptr - n * m_stride, m_stride); }
            difference_type operator-(const iterator &other) const { return (m_ptr - other.m_ptr) / m_stride; }

            iterator &operator+=(difference_type n)
            {
                m_ptr += n * m_stride;
                return *this;
            }
            iterator &operator-=(difference_type n)
            {
                m_ptr -= n * m_stride;
                return *this;
            }

            reference operator[](difference_type n) const { return *reinterpret_cast<pointer>(m_ptr + n * m_stride); }

            bool operator==(const iterator &other) const { return m_ptr == other.m_ptr; }
            bool operator!=(const iterator &other) const { return m_ptr != other.m_ptr; }
            bool operator<(const iterator &other) const { return m_ptr < other.m_ptr; }
            bool operator<=(const iterator &other) const { return m_ptr <= other.m_ptr; }
            bool operator>(const iterator &other) const { return m_ptr > other.m_ptr; }
            bool operator>=(const iterator &other) const { return m_ptr >= other.m_ptr; }

        private:
            std::byte *m_ptr;
            size_type m_stride;
        };

        span(T *ptr, size_type count, size_type stride = sizeof(T))
            : m_ptr((std::byte *)ptr), m_count(count), m_stride(stride) {}

        span() = default;

        operator nt::span<const T>() { return nt::span<const T>((const T *)m_ptr, m_count, m_stride); }

        reference operator[](size_type idx) const
        {
            return *reinterpret_cast<pointer>(m_ptr + idx * m_stride);
        }

        pointer data() const noexcept
        {
            return reinterpret_cast<pointer>(m_ptr);
        }

        size_type size() const noexcept
        {
            return m_count;
        }

        size_type stride() const noexcept
        {
            return m_stride;
        }

        iterator begin() const noexcept
        {
            return iterator(m_ptr, m_stride);
        }

        iterator end() const noexcept
        {
            return iterator(m_ptr + m_count * m_stride, m_stride);
        }

    private:
        std::byte *m_ptr = nullptr;
        size_type m_count = 0;
        size_type m_stride = 0;
    };

}
