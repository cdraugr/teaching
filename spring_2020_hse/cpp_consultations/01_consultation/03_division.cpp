#include <cstdint>
#include <iostream>

int main() {
    std::cout << "[int / int      ] " << 5   / 2   << '\n';
    std::cout << "[int / double   ] " << 5   / 2.0 << '\n';
    std::cout << "[double / int   ] " << 5.0 / 2   << '\n';
    std::cout << "[double / double] " << 5.0 / 2.0 << '\n';
}
