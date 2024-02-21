
/*
    Flip the LSB of B.
    if the new number is less than left then that's the answer. Else if the new number is within the range of left < number < right, then, repeat the above procedure.
*/
int rangeBitwiseAnd(int left, int right){
    
    unsigned int i = 1;
    int num = 0;
    while (right > left) {
        
        if (right & i)
            right &= ~(right&i);
        i <<= 1;
    }
    
    return right;

}
