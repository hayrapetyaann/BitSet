class Bitset:
    def __init__(self, N):
        self.N = N
        self.bits = [0] * ((N + 31) // 32)

    def get_index(self, position):
        return position // 32

    def get_position(self, position):
        return position % 32

    def set(self, position, value=True):
        if position < self.N:
            idx = self.get_index(position)
            bit_idx = self.get_position(position)

            if value:
                self.bits[idx] |= (1 << bit_idx)
            else:
                self.bits[idx] &= ~(1 << bit_idx)

    def get(self, position):
        if position < self.N:
            idx = self.get_index(position)
            bit_idx = self.get_position(position)
            return (self.bits[idx] >> bit_idx) & 1
        return False

    def toggle(self, position):
        if position < self.N:
            idx = self.get_index(position)
            bit_idx = self.get_position(position)
            self.bits[idx] ^= (1 << bit_idx)

    def reset(self):
        self.bits = [0] * len(self.bits)

    def print(self):
        for i in range(self.N):
            print(self.get(i), end="")
        print()

    def size(self):
        return self.N


# Test
bitset = Bitset(5)

bitset.set(2)
bitset.set(4)
bitset.set(1, False)

bitset.print()

bitset.toggle(4)
bitset.print()

bitset.reset()
bitset.print()
