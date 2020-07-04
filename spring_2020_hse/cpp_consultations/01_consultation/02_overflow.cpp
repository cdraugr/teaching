#include <cstdint>
#include <iostream>
#include <limits>

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

int max_int() {
    return std::numeric_limits<int>::max();
}

int main() {
    i32 a = max_int() + max_int();
    auto b = max_int() + max_int();
    i64 c = max_int() + max_int();
    auto d = static_cast<i64>(max_int()) + max_int();
    i64 e = static_cast<i64>(max_int()) + max_int();
    auto f = static_cast<i64>(max_int() + max_int());
    i64 g = static_cast<i64>(max_int() + max_int());

    std::cout << "max_int(): " << max_int() << '\n';
    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';
    std::cout << "c: " << c << '\n';
    std::cout << "d: " << d << '\n';
    std::cout << "e: " << e << '\n';
    std::cout << "f: " << f << '\n';
    std::cout << "g: " << g << '\n';

    return 0;
}
