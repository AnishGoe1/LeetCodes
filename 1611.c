int minimumOneBitOperations(int n) {
    int count=0, j=0;
    for (int i = 31; i >= 0; i--) {
        if (((n >> i) & 1) == 1) {
            if (j == 0) {
                count = count + ((1 << (i + 1))) - 1;
                j = 1;
            } else {
                count = count - ((1 << (i + 1)) - 1);
                j = 0;
            }
        }
    }
    return count;
}



int minimumOneBitOperations(int n) {
    int count = 0;
    while (n > 0) {
        count ^= n;
        n >>= 1;
    }
    return count;
}
