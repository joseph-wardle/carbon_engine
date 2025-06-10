import carbon.core.types;
import carbon.math.algebra;
#include <print>

using namespace carbon;

i32 main() {
    std::println("Pow (5, 2): {}", math::pow(5, 2));
    std::println("Pow (5.5, 2.2): {}", math::pow(5.5, 2.2));
    std::println("Abs (5): {}", math::abs(5));
    std::println("Abs (-5): {}", math::abs(-5));
    std::println("Abs (5.5): {}", math::abs(5.5));
    std::println("Abs (-5.5): {}", math::abs(-5.5));
    std::println("Sqrt (4): {}", math::sqrt(4));
    std::println("Sqrt (-4): {}", math::sqrt(-4));
    std::println("Sqrt (4.2): {}", math::sqrt(4.2));

    return 0;
}