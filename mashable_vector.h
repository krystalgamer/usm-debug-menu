#pragma once

#include <cstdint>
#include <cassert>

template<typename T>
struct mashable_vector
{
    using value_t = T;

    T *m_data;
    uint16_t m_size;
    bool m_shared;
    bool field_7;

    auto size() const
    {
        return m_size;
    }

    inline auto &at(int index) {
        return m_data[index];
    }

    inline auto &at(int index) const {
        return m_data[index];
    }

    struct iterator {
        T *m_ptr;

        bool operator==(const iterator &it) {
            return (this->m_ptr == it.m_ptr);
        }

        bool operator!=(const iterator &it) {
            return (this->m_ptr != it.m_ptr);
        }

        auto &operator*() {
            return (*m_ptr);
        }

        auto &operator++() {
            return (++m_ptr);
        }
    };

    iterator begin() {
        return iterator{&m_data[0]};
    }

    iterator end()
    {
        if (this->m_data != nullptr) {
            return iterator{&this->m_data[this->m_size]};
        }

        return {};
    }
};
