#include <iostream>

int main() {
/*
    std::cout << "int - " << sizeof(int) << std::endl;
    std::cout << "unsigned int - " << sizeof(unsigned int) << std::endl;
    std::cout << "long - " << sizeof(long) << std::endl;
    std::cout << "unsigned long - " << sizeof(unsigned long) << std::endl;
    std::cout << "long long - " << sizeof(long long) << std::endl;
    std::cout << "long long int - " << sizeof(long long int) << std::endl;
    std::cout << "unsigned long long - " << sizeof(unsigned long long) << std::endl;
    std::cout << "float - " << sizeof(float) << std::endl;
    std::cout << "double - " << sizeof(double) << std::endl;
    std::cout << "size_t - " << sizeof(size_t) << std::endl;
    std::cout << "bool - " << sizeof(bool) << std::endl;
    std::cout << "char - " << sizeof(char) << std::endl;
*/
    unsigned int x = -1;
    std::cin >> x;
    // -1_10 == 111111111...1

    if (x + 1 == INT32_MIN) {  // if x == INT32_MAX
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}
