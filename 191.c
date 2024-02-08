int hammingWeight(uint32_t n) {
    uint32_t bitMask = 1;
    uint32_t count = 0;
    while(n)
    {
        if(n & bitMask)
            count++;
        n >>= bitMask;
    }
    return count;
}
