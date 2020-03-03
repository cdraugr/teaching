#include "Matrix.h"

using i32 = std::int32_t;

int main() {
    const Matrix<i32> matrix({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    });

    for (const auto& x : matrix) {
        std::cout << x << ' ';
    }

    std::cout << '\n' << matrix << '\n';
}
