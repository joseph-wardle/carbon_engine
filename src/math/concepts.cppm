export module carbon.math.concepts;

export namespace carbon::math {
    template<typename T>
    concept Scalar = __is_arithmetic(T);

    template<typename T>
    concept Floating = __is_floating_point(T);

    template<typename T>
    concept Integral = Scalar<T> && !Floating<T>;

    template<typename T>
    concept Signed = Scalar<T> && __is_signed(T);

    template<typename T>
    concept Unsigned = Scalar<T> && !__is_signed(T);
}