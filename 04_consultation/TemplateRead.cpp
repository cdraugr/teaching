#include <cstdint>
#include <iostream>
#include <string>

using i32 = int32_t;

template <typename T>
T Read(std::istream& input = std::cin) {
    T value;
    input >> value;
    return value;
}

int main() {
    // i32 number = 0;
    // std::cin >> number;
    const auto number = Read<i32>();
    const auto str = Read<std::string>();

    std::cout << number << '\n' << str << '\n';
}
