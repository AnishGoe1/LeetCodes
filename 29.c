int divide(int dividend, int divisor){
    
    long long int d = (long long int) dividend;
    long long int i = (long long int) divisor;
    long long int quotient = 0;
    unsigned int shift = 0;
    int sign = 1;
    
    if (d < 0 && i < 0) {
        d = -d;
        i = -i;
    } else if ((d < 0 && i > 0) || (d > 0 && i < 0)){
        sign = -1;
        if (d < 0)
            d = -d;
        else if (i < 0)
            i = -i;
    }
    
    while (d >= i) {
        
        shift = 0;
        while (d >= (i << shift))
            shift ++;
        
        quotient += (long long int) (1LL << (shift-1));
        if (quotient*sign > INT_MAX){
            return (int) sign*INT_MAX;
        } else if (quotient*sign < INT_MIN)
            return (int) sign *INT_MIN;
        d -= i<<(shift -1);
    }
    
    return (int) sign *quotient;
}
