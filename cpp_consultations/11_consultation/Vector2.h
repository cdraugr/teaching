#include <cstddef>  // for std::size_t
#include <memory>
// https://en.cppreference.com/w/cpp/header/memory
/*
    std::uninitialized_copy
    std::uninitialized_value_construct_n
    std::destroy_n
    std::destroy_at
*/
#include <utility>  // for std::swap

template <typename T>
class Vector {
public:
    using value_type = T;
    using size_type = std::size_t;

    using reference = value_type&;
    using const_reference = const value_type&;

    using pointer = value_type*;
    using const_pointer = const value_type*;

    using iterator = pointer;
    using const_iterator = const_pointer;

private:
    size_type size_{0};
    size_type capacity_{0};
    value_type *data_{nullptr};

    pointer _allocate(size_type capacity) {
        void *new_data = operator new(sizeof(value_type) * capacity);
        return reinterpret_cast<value_type *>(new_data);
    }

    void _deallocate() {
        std::destroy_n(data_, size());
        operator delete(data_);

        size_ = 0;
        capacity_ = 0;
        data_ = nullptr;
    }

public:
    Vector() noexcept = default;
    explicit Vector(size_type count);
    Vector(const Vector<T>& other);

    ~Vector() {
        _deallocate();
    }

    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this;
        }

        _deallocate();
        data_ = _allocate(other.size());
        try {
            std::uninitialized_copy(other.cbegin(), other.cend(), data());
            size_ = other.size();
            capacity_ = other.size();
        } catch (...) {
            _deallocate();
            throw;
        }
        return *this;
    }

    void swap(Vector& other) noexcept;

    reference operator[](size_type pos);
    const_reference operator[](size_type pos) const;

    pointer data() noexcept;
    const_pointer data() const noexcept;

    size_type size() const noexcept;
    size_type capacity() const noexcept;

    iterator begin() noexcept;
    const_iterator begin() const noexcept;
    const_iterator cbegin() const noexcept;

    iterator end() noexcept;
    const_iterator end() const noexcept;
    const_iterator cend() const noexcept;

    void reserve(size_type new_cap);

    void clear() noexcept;
    void pop_back();

    void push_back(const_reference value);
    void resize(size_type new_size);
};
