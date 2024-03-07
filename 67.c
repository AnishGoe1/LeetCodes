char* addBinary(char* a, char* b)
{
    int i, j, k, c = 0;
    char *res;
    
    i = strlen(a);
    j = strlen(b);
    k = i > j ? i : j;
    k += 2;

    res = malloc(k * sizeof(char));
    
    i--;
    j--;
    res[--k] = '\0';
    
    while (--k >= 0) {
        c += i >= 0 ? a[i--] - '0': 0;
        c += j >= 0 ? b[j--] - '0': 0;
        
        res[k] = c % 2 + '0';
        c /= 2;
    }
    
    if (res[0] == '0')
       memmove(res, res + 1, strlen(res) * sizeof(char));
    
    return res;
}
