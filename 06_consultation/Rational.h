#include <cstdint>
#include <iostream>
#include <numeric>  // for gcd
#include <stdexcept>

/* https://en.cppreference.com/w/cpp/language/operators */

class Rational {
public:
    using i32 = std::int32_t;

    Rational(i32 numer = 0, i32 denom = 1)
        : numerator_{denom < 0 ? -numer : numer},
            denominator_{denom < 0 ? -denom : denom} {
            if (!denominator()) {
                throw std::overflow_error("Divide by zero.");
            }
            normalize();
        }

    i32 numerator() const noexcept {
        return numerator_;
    }

    i32 denominator() const noexcept {
        return denominator_;
    }

    Rational& operator+=(const Rational& other) {
        numerator_ *= other.denominator();
        numerator_ += other.numerator() * denominator();
        denominator_ *= other.denominator();
        normalize();
        return *this;
    }

    friend Rational operator+(Rational left, const Rational& right) {
        left += right;
        return left;
    }

    Rational& operator++() {  // ++rational;
        numerator_ += denominator();
        return *this;
    }

    Rational operator++(int) {  // rational++;
        Rational tmp(*this);
        operator++();
        return tmp;
    }

private:
    void normalize() {
        auto gcd = std::gcd(numerator(), denominator());
        numerator_ /= gcd;
        denominator_ /= gcd;
    }

    i32 numerator_{}, denominator_{};
};

std::ostream& operator<<(std::ostream& out, const Rational& rational) {
   return out << rational.numerator() << " / " << rational.denominator() ;
}

bool operator==(const Rational& lft, const Rational& rht) {
    return lft.numerator() == rht.numerator() &&
            lft.denominator() == rht.denominator();
}
bool operator!=(const Rational& lft, const Rational& rht) {
    return !(lft == rht);
}
