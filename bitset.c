#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct {
    unsigned int *bits;
} Bitset;

size_t getIndex(size_t position) {
    return position / 32;
}

size_t getPosition(size_t position) {
    return position % 32;
}

void init(Bitset *bitset) {
    bitset->bits = (unsigned int *)calloc((SIZE + 31) / 32, sizeof(unsigned int));
}

void set(Bitset *bitset, size_t position, int value) {
    if (position < SIZE) {
        size_t idx = getIndex(position);
        size_t bit_idx = getPosition(position);

        if (value) {
            bitset->bits[idx] |= (1 << bit_idx);
        } else {
            bitset->bits[idx] &= ~(1 << bit_idx);
        }
    }
}

int get(const Bitset *bitset, size_t position) {
    if (position < SIZE) {
        size_t idx = getIndex(position);
        size_t bit_idx = getPosition(position);
        return (bitset->bits[idx] >> bit_idx) & 1;
    }
    return 0;
}

void toggle(Bitset *bitset, size_t position) {
    if (position < SIZE) {
        size_t idx = getIndex(position);
        size_t bit_idx = getPosition(position);
        bitset->bits[idx] ^= (1 << bit_idx);
    }
}

void reset(Bitset *bitset) {
    for (size_t i = 0; i < (SIZE + 31) / 32; ++i) {
        bitset->bits[i] = 0;
    }
}

void print(const Bitset *bitset) {
    for (size_t i = 0; i < SIZE; ++i) {
        printf("%d", get(bitset, i));
    }
    printf("\n");
}

int main() {
    Bitset bitset;
    init(&bitset);

    set(&bitset, 2, 1);
    set(&bitset, 4, 1);
    set(&bitset, 1, 0);

    print(&bitset);

    toggle(&bitset, 4);
    print(&bitset);

    reset(&bitset);
    print(&bitset);

    free(bitset.bits);
    return 0;
}
