module;

import carbon.math.concepts;
import carbon.core.types;

module carbon.math.algebra;

namespace carbon::math {

    template<Scalar T>
    constexpr T abs(T value) noexcept {
        if constexpr (Signed<T>) {
            return (value < 0) ? -value : value;
        } else {
            return value;
        }
    }

    template<Scalar T>
    constexpr T pow(T base, T exponent) noexcept {
        if constexpr (Floating<T>) {
            if constexpr (sizeof(T) == sizeof(float)) {
                return __builtin_powf(base, exponent);
            } else {
                return __builtin_pow(base, exponent);
            }
        } else {
            T result = 1;
            T b      = base;
            T e      = exponent;
            while (e > 0) {
                if ((e & 1) != 0)
                    result = result * b;
                b = b * b;
                e = static_cast<T>(e >> 1);
            }
            return result;
        }
    }

    template<Scalar T>
    constexpr T sqrt(T value) noexcept {
        if (value <= T(0)) {
            return T(0);
        }

        if constexpr (Floating<T>) {
            // Initial guess: bit-level hack for speed
            // Re-interpret exponent to get a rough 1/√2 start
            union { T f; u64 i; } u{ value };
            if constexpr (sizeof(T) == 4)
                u.i = 0x1FBD1DF5 + (u.i >> 1);          // magic for 32-bit
            else
                u.i = 0x5FE6EC85E7DE30DALL + (u.i >> 1); // magic for 64-bit
            T x    = u.f;
            T last = 0;

            // Newton–Raphson iterations: xₙ₊₁ = ½(xₙ + value/xₙ)
            for (int i = 0; i < 8 && x != last; ++i) {
                last = x;
                x    = (x + value / x) * T(0.5);
            }
            return x;
        } else {
            T x = value;
            T y = (x + 1) / 2;
            while (y < x) {
                x = y;
                y = (x + value / x) / 2;
            }
            return x;
        }
    }

}

// explicit instantiations to avoid repeated code-gen
namespace carbon::math {
    template i8    abs(i8)    noexcept;
    template i16   abs(i16)   noexcept;
    template i32   abs(i32)   noexcept;
    template i64   abs(i64)   noexcept;
    template isize abs(isize) noexcept;
    template u8    abs(u8)    noexcept;
    template u16   abs(u16)   noexcept;
    template u32   abs(u32)   noexcept;
    template u64   abs(u64)   noexcept;
    template usize abs(usize) noexcept;
    template f32   abs(f32)   noexcept;
    template f64   abs(f64)   noexcept;

    template i8    pow(i8, i8)   noexcept;
    template i16   pow(i16, i16) noexcept;
    template i32   pow(i32, i32) noexcept;
    template i64   pow(i64, i64) noexcept;
    template isize pow(isize, isize) noexcept;
    template u8    pow(u8, u8)   noexcept;
    template u16   pow(u16, u16) noexcept;
    template u32   pow(u32, u32) noexcept;
    template u64   pow(u64, u64) noexcept;
    template usize pow(usize, usize) noexcept;
    template f32   pow(f32, f32) noexcept;
    template f64   pow(f64, f64) noexcept;

    template i8    sqrt(i8)    noexcept;
    template i16   sqrt(i16)   noexcept;
    template i32   sqrt(i32)   noexcept;
    template i64   sqrt(i64)   noexcept;
    template isize sqrt(isize) noexcept;
    template u8    sqrt(u8)    noexcept;
    template u16   sqrt(u16)   noexcept;
    template u32   sqrt(u32)   noexcept;
    template u64   sqrt(u64)   noexcept;
    template usize sqrt(usize) noexcept;
    template f32   sqrt(f32)   noexcept;
    template f64   sqrt(f64)   noexcept;
}