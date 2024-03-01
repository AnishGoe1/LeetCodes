char* maximumOddBinaryNumber(char* s){
    int len, one, i;

    len = strlen(s);

    for (i = 0, one = 0; i < len; ++i)
        if (s[i] == '1')
            one++;
    for (i = 0; i < len - 1; ++i) {
        if (one > 1) {
            s[i] = '1';
            --one;
        } else {
            s[i] = '0';
        }
    }
    s[len - 1] = '1';
    return s;
}
