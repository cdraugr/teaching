#include <iostream>
#include <vector>

using i32 = int32_t;
using Matrix = std::vector<std::vector<i32>>;

int main() {
    i32 m = 0, n = 0;
    std::cin >> m >> n;
    Matrix matrix(m, std::vector<i32>(n));
    for (auto& row : matrix) {
        for (auto& elem : row) {
            std::cin >> elem;
        }
    }
}
