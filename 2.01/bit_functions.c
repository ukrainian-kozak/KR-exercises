



unsigned int setbits(unsigned int x, int p, int n, unsigned int y) {
    unsigned int mask = ((1 << n) - 1) << (p + 1 - n);
    return (x & ~mask) | ((y & ((1 << n) - 1)) << (p + 1 - n));
}

unsigned invert(unsigned int x, int p, int n) {
    unsigned int mask = ((1 << n) - 1) << (p + 1 - n);
    return x ^ mask;
}

unsigned int rightrot(unsigned int x, int n) {
    return x >> n;
}
