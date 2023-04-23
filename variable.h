#pragma once

template<typename T>
struct Var {
    using value_type = T;

    Var() = delete;

    Var(const Var &) = delete;
    Var &operator=(const Var &) = delete;

    Var(Var &&) = delete;
    Var &operator=(Var &&) = delete;

    Var(ptrdiff_t &&address) : pointer(reinterpret_cast<T *>(address)) {
    }

    T *pointer;

    inline T &operator()() {
        return (*pointer);
    }

    inline T &operator*() {
        return (*pointer);
    }

    inline const T &operator()() const {
        return (*pointer);
    }
};
