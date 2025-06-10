export module carbon.math.align;

export namespace carbon::math {

    template<typename T>
    constexpr T align_up       (T value, T alignment) noexcept {
        T remainder = value % alignment;
        return remainder == 0 ? value : value + (alignment - remainder);
    }


    template<typename T>
    constexpr T align_up_pow2  (T value, T alignment) noexcept {
        T mask = alignment - 1;
        return (value + mask) & ~mask;
    }

    template<typename T>
    constexpr T align_down     (T value, T alignment) noexcept {
        T remainder = value % alignment;
        return value - remainder;
    }

    template<typename T>
    constexpr T align_down_pow2(T value, T alignment) noexcept {
        T mask = alignment - 1;
        return value & ~mask;
    }

}