#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> vec(5, "Hello, world!");
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << '\n';
    }

    for (const auto& str : vec) {
        // ...
    }

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << '\n';
    }

    auto jt = vec.begin();
    while (jt != vec.end()) {
        std::cout << *jt << '\n';
        ++jt;
    }

    // vec[0] == vec.front()
    // vec[vec.size() - 1] == vec.back()
}
