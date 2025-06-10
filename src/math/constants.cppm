export module carbon.core.constants;
import carbon.core.types;
import carbon.math.concepts;

export namespace carbon::math {

    template<Floating T>
    inline constexpr T PI  = static_cast<T>(3.14159265358979323846264338327950288L);
    template<Floating T>
    inline constexpr T TAU = static_cast<T>(6.28318530717958647692528676655900576L);
    template<Floating T>
    inline constexpr T PHI = static_cast<T>(1.61803398874989484820458683436563811L);

}