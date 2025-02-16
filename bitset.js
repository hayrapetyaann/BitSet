class Bitset {
    constructor(N) {
      this.N = N;
      this.bits = new Array(Math.ceil(N / 32)).fill(0);
    }
  
    getIndex(position) {
      return Math.floor(position / 32);
    }
  
    getPosition(position) {
      return position % 32;
    }
  
    set(position, value = true) {
      if (position < this.N) {
        const idx = this.getIndex(position);
        const bitIdx = this.getPosition(position);
  
        if (value) {
          this.bits[idx] |= (1 << bitIdx);
        } else {
          this.bits[idx] &= ~(1 << bitIdx);
        }
      }
    }
  
    get(position) {
      if (position < this.N) {
        const idx = this.getIndex(position);
        const bitIdx = this.getPosition(position);
        return (this.bits[idx] >> bitIdx) & 1;
      }
      return false;
    }
  
    toggle(position) {
      if (position < this.N) {
        const idx = this.getIndex(position);
        const bitIdx = this.getPosition(position);
        this.bits[idx] ^= (1 << bitIdx);
      }
    }
  
    reset() {
      this.bits.fill(0);
    }
  
    print() {
      for (let i = 0; i < this.N; i++) {
        process.stdout.write(this.get(i).toString());
      }
      console.log();
    }
  
    size() {
      return this.N;
    }
}
  
  // Test
const bitset = new Bitset(5);

bitset.set(2);
bitset.set(4);
bitset.set(1, false);

bitset.print();

bitset.toggle(4);
bitset.print();

bitset.reset();
bitset.print();
