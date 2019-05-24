#ifndef BITSET_H
#define BITSET_H

#include <cstdint>

class bitset {
public:
    bitset(int sz)
        : size_{0},
          buffer_{nullptr},
          max_{0}
    {
        size_ = sz / sizeof(std::uint_fast32_t) + 1;
        buffer_ = new std::uint_fast32_t[size_];
        reset();
    }

    ~bitset() { delete[] buffer_; }

    bool set(int index) {
        if (index < 0 || index > number_of_bits()) {
            return false;
        }
        if (index > max_) { max_ = index; }
        const auto bits_length = sizeof(std::uint_fast32_t);
        std::uint_fast32_t mask = (1 << index % bits_length);
        buffer_[index/bits_length] |= mask;
        return true;
    }

    // you might need bool unset(int index);

    bool get(int index) {
        if (index < 0 || index > number_of_bits()) {
            return false;
        }
        const auto bits_length = sizeof(std::uint_fast32_t);
        std::uint_fast32_t mask = (1 << index % bits_length);
        return (buffer_[index/bits_length] & mask);
    }

public:
    int number_of_bits() const {
        return size_ * sizeof(std::uint_fast32_t);
    }

    void reset() {
        for (int ix = 0; ix < size_; ++ix) {
            buffer_[ix] = 0;
        }
    }

private:
    int size_;
    std::uint_fast32_t* buffer_;
    int max_;
};

#endif
