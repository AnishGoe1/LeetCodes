#define MAX(a, b) (a)>(b)?(a):(b)

char * multiply(char * num1, char * num2){
    int *ret = calloc(512, sizeof(int));
    
    int c = 0;
	// to remove leading zeros
    int nonzero = 0;
    int shift = 0;

    int l1 = strlen(num1);
    int l2 = strlen(num2);
    for(int i=l1-1; i>=0; i--) {
        c = l1-1-i;
        int carry=0;
        for(int j=l2-1; j>=0; j--, c++) {
            ret[c] += (num1[i]-'0')*(num2[j]-'0')+carry;
            carry = ret[c] / 10;
            ret[c] %= 10;
        }
		// if we still has carry, remember to  do this..
        if(carry) {
            ret[c++] = carry;
        }
        if(ret[c-1])
            nonzero = MAX(nonzero, c-1);
        
    }
    
	// int to str
    static char str[512];
    for(int i=nonzero; i>=0; i--) {
        str[nonzero-i] = ret[i]+'0';
    }
    str[nonzero+1] = '\0';
    
    free(ret);
    return str;
}
