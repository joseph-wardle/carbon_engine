export module carbon.math.comparison;

import carbon.math.concepts;
import carbon.core.types;

export namespace carbon::math {
    template<Scalar T> constexpr T min  (T a, T b) noexcept { return (a < b) ? a : b; }
    template<Scalar T> constexpr T max  (T a, T b) noexcept { return (a > b) ? a : b; }
    template<Scalar T> constexpr T clamp(T v, T lo, T hi) noexcept { return max(lo, min(v, hi)); }
    template<Scalar T> constexpr i8 sign(T v) noexcept {
        return (v > T{0}) ?  1
             : (v < T{0}) ? -1
                          :  0;
    }
}