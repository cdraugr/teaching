#include "Rational.h"
#include <iostream>

int main() {
    Rational rational1(2, 3);
    Rational rational2(1, 3);

    std::cout << "rational1 = " << rational1 << '\n';
    std::cout << "rational2 = " << rational2 << '\n';

    std::cout << "=============================\n";
    std::cout << "rational1 + 5 = " << (rational1 + 5).numerator() << " / "
                << (rational1 + 5).denominator() << '\n';
    std::cout << "5 + rational1 = " << (5 + rational1).numerator() << " / "
                << (5 + rational1).denominator() << '\n';

    std::cout << "rational1 + rational2 = " << (rational1 + rational2).numerator() << " / "
                << (rational1 + rational2).denominator() << '\n';

    std::cout << "=============================\n";
    std::cout << "rational1++ = " << rational1++ << '\n';
    std::cout << "++rational2 = " << ++rational2 << '\n';

    std::cout << "rational1 = " << rational1 << '\n';
    std::cout << "rational2 = " << rational2 << '\n';
}
