#include <iostream>
#include <string>

int main() {
    std::string str = "ш";
    std::cout << str[0] << '\n' << str[1] << '\n';
    std::cout << "size = " << str.size() << '\n';
    std::cout << "length = " << str.length() << '\n';
    std::cout << "cap = " << str.capacity() << '\n';
}
