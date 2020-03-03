#include <cassert>
#include <iostream>
#include <vector>

template<typename T>
class Matrix {
public:
    using const_iterator = typename std::vector<T>::const_iterator;

    Matrix(const std::vector<std::vector<T>>& givenMatrix)
        : rows_{givenMatrix.size()} {
        assert(GetRows() != 0);
        data_.reserve(rows_ * givenMatrix[0].size());
        for (const auto& row : givenMatrix) {
            for (const auto& value : row) {
                data_.push_back(value);
            }
        }
    }

    std::pair<size_t, size_t> size() const {
        return {GetRows(), GetColumns()};
    }

    size_t GetRows() const {
        return rows_;
    }

    size_t GetColumns() const {
        return data_.size() / GetRows();
    }

    const T& index(size_t i, size_t j) const {
        return data_[i * GetColumns() + j];
    }

    template<typename otherT>
    Matrix<T>& operator*=(const otherT& scalar); // { /* ... */ return *this; }

    Matrix<T>& transpose(); // { /* ... */ return *this; }

    Matrix<T> transposed() const {
        auto matrix = *this;
        return matrix.transpose();
    }

    const_iterator begin() const {
        return data_.cbegin();
    }

    const_iterator end() const {
        return data_.cend();
    }

private:
    std::vector<T> data_;
    size_t rows_{};  // columns_ also;
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix) {
    for (size_t i = 0; i != matrix.GetRows(); ++i) {
        if (i) {
            out << '\n';
        }
        for (size_t j = 0; j != matrix.GetColumns(); ++j) {
            if (j) {
                out << '\t' << matrix.index(i, j);
            } else {
                out << matrix.index(i, j);
            }
        }
    }
    return out;
}

/*

{{1, 2, 3},
{4, 5, 6},
{7, 8, 9}}

1   2   3
4   5   6
7   8   9

index(2, 2)  == data_[2 * 3 + 2]  == data_[8]

{1, 2, 3, 4, 5, 6, 7, 8, 9}

*/
