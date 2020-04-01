#include <cstdint>
#include <iostream>
#include <string>

int main() {
    size_t counter = 0;
    std::string line;
    std::getline(std::cin, line);
    for (uint8_t mask : line) {
        if ((((mask >> 7) & 1) == 1) && ((mask >> 6) & 1) == 0) {
            continue;
        }
        ++counter;
    }

    std::cout << counter << '\n';

    /*
        0xxxxxxx
        110xxxxx 10xxxxxx
        1110xxxx 10xxxxxx 10xxxxxx
        11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
    */
}
