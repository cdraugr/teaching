#include <cstdint>
#include <iostream>
#include <utility>

using i32 = int32_t;

std::pair<i32, i32> MakePair() {
    return std::make_pair(0, 0);  // return {0, 0};
}

std::tuple<i32, i32, i32> MakeTuple() {
    return std::make_tuple(0, 0, 0);  // return {0, 0, 0};
}

int main() {
    std::pair<i32, i32> p = {1, 2};
    const auto [a, b] = p;  // a == p.first, b == p.second;

    std::tuple<i32, i32, i32> t{1, 2, 3};
    const auto [c, d, e] = t;  // c == std::get<0>(t), ...

    const auto [f, g] = MakePair();
    const auto [h, i, j] = MakeTuple();

    return 0;
}
