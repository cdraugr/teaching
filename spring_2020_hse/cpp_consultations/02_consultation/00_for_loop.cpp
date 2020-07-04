#include <cstdint>
#include <iostream>
#include <vector>

using i32 = int32_t;  // std::int32_t

int main() {
    std::vector<i32> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<std::vector<i32>> big_number = {
        {1, 2, 3},
        {4, 5, 6}
    };

    for (const auto& numbers : big_number) {  // same name
        for (const auto& number : numbers) {
            std::cout << number << ' ';
        }
        std::cout << '\n';
    }

    for (const auto x : numbers) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    for (auto& x : numbers) {
        x *= 2;
    }

    for (auto it = numbers.cbegin(); it != numbers.cend(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        *it /= 2;
    }

    for (auto it = numbers.crbegin(); it != numbers.crend(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    for (std::size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << ' ';
    }
    std::cout << '\n';

    for (std::size_t i = 0; i < numbers.size(); i += 2, ++numbers.back()) {
        std::cout << numbers[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}
