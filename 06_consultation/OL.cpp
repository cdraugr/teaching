#include "c.h"
#include <vector>

int main() {
    C c1; // will call "constructor C()"
    C c2(c1); // same as C c2 = c1; // will call "constructor C(const C&)"
    C c3(std::move(c2)); // will call "constructor C(const C&&)"

    c2 = c1; // will call "operator = (const C&)"
    c3 = std::move(c2); // will call "operator = (const C&&)"

    return 0; // will call "destructor C()" 3 times from three to one
}
