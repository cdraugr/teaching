#include <cstdint>
#include <iostream>
#include <vector>

using i32 = int32_t;

int main() {
    std::vector<i32> vec = {10};
    auto it = vec.begin();
    std::cout << "*it " << *it << '\n';

    // for (size_t i = 0; i != 100000000; ++i) {
    //     vec.push_back(20);
    // }

    std::cout << "*it " << *it << '\n';

    return 0;
}
