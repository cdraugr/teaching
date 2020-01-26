#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using i64 = std::int64_t;

struct RaceInfo {
    i64 dist = 0;  // meters
    std::string date;  // dd.mm.yyyy
};

void print_races(const std::vector<RaceInfo>& races) {
    for (const auto& [dist, date] : races) {
        std::cout << dist << ' ' << date << '\n';
    }
}

bool compar(const RaceInfo& left, const RaceInfo& right) {
    return left.dist < right.dist;
}

void sort_races(std::vector<RaceInfo>& races) {
    std::sort(races.begin(), races.end(), compar);
}

int main() {
    i64 distanse = 0;
    std::string day, month, year;
    std::vector<RaceInfo> races;

    while (std::cin >> distanse >> day >> month >> year) {
        races.push_back({distanse, day + "." + month + "." + year});
    }

    print_races(races);
    sort_races(races);
    std::cout << "--------------------\n";
    print_races(races);

    return 0;
}
