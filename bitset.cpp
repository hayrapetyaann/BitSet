#include <iostream>
#include <vector>

template<size_t N>
class Bitset {
private:
    std::vector<int> bits;

    size_t getIndex(size_t position) const {
        return position / 32;
    }

    size_t getPosition(size_t position) const {
        return position % 32;
    }

public:
    Bitset() {
        bits.resize((N + 31) / 32, 0);
    }

    void set(size_t position, bool value = true) {
        if (position < N) {
            size_t idx = getIndex(position);
            size_t bit_idx = getPosition(position);

            if (value) {
                bits[idx] |= (1 << bit_idx);
            } else {
                bits[idx] &= ~(1 << bit_idx);
            }
        }
    }

    bool get(size_t position) const {
        if (position < N) {
            size_t idx = getIndex(position);
            size_t bit_idx = getPosition(position);
            return (bits[idx] >> bit_idx) & 1;
        }
        return false;
    }

    void toggle(size_t position) {
        if (position < N) {
            size_t idx = getIndex(position);
            size_t bit_idx = getPosition(position);
            bits[idx] ^= (1 << bit_idx);
        }
    }

    void reset() {
        std::fill(bits.begin(), bits.end(), 0);
    }

    void print() const {
        for (size_t i = 0; i < N; ++i) {
            std::cout << get(i);
        }
        std::cout << std::endl;
    }

    size_t size() const {
        return N;
    }
};

int main() {
    Bitset<5> bitset;

    bitset.set(2);
    bitset.set(4);
    bitset.set(1, false);

    bitset.print();

    bitset.toggle(4);
    bitset.print();

    bitset.reset();
    bitset.print();

    return 0;
}
