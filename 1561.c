int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

int maxCoins(int* piles, int pilesSize){
    int sum = 0;
    qsort(piles, pilesSize, sizeof(int), cmpfunc);
    for(int i=1; i<pilesSize; i+=2) {
        sum += piles[i];
        pilesSize--;
    }
    return sum;
}
