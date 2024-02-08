int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize){
    
    *returnSize = temperaturesSize;
    
    int* arry = (int*) calloc(temperaturesSize, sizeof(int));
    
    for(int i = temperaturesSize - 1; i >= 0; --i)
    {
        for (int j = i + 1; j < temperaturesSize;)
        {
            if (*(temperatures+i) < *(temperatures+j))
            {
                *(arry+i) = j - i;
                break;
            } else if (*(arry+j) == 0) {
                break;
            } else {
                j += *(arry+j);
            }
        }
    } 
    
    return arry;
}
