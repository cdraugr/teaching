#include <cstdint>
#include <iostream>
#include <string>

bool give_byte(uint8_t mask, size_t idx) {
    return (mask >> (idx - 1)) & 1;
}

int main() {
    std::string line;
    std::getline(std::cin, line);
    const uint32_t mask = 0b111111;
    for (size_t i = 0; i != line.size(); ++i) {
        uint32_t current_number = 0;

        if (!give_byte(line[i], 8)) {
            current_number = line[i];
        } else if (!give_byte(line[i], 6)) {
            current_number = ((line[i] & 0b11111) << 6) |
                                (line[++i] & mask);
        } else if (!give_byte(line[i], 5)) {
            current_number = ((line[i] & 0b1111) << 12) |
                                ((line[++i] & mask) << 6) |
                                (line[++i] & mask);
        } else {
            current_number = ((line[i] & 0b1111) << 18) |
                                ((line[++i] & mask) << 12) |
                                ((line[++i] & mask) << 6) |
                                (line[++i] & mask);
        }

        std::cout << current_number << ' ';
    }

    std::cout << '\n';
}
