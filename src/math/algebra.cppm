module;

import carbon.math.concepts;

export module carbon.math.algebra;

export namespace carbon::math {

    template<Scalar T> constexpr T abs(T value) noexcept;
    template<Scalar T> constexpr T pow(T base, T exponent) noexcept;
    template<Scalar T> constexpr T sqrt(T value) noexcept;

}