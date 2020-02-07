#include <iostream>
#include <string>

struct Student {
    std::string name, sname;
};

std::ostream& operator<<(std::ostream& os, const Student& student) {
    return os << student.name << ' ' << student.sname << '\n';
}

std::istream& operator>>(std::istream& is, Student& student) {
    return is >> student.name >> student.sname;
}
