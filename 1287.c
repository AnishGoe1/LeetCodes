int findSpecialInteger(int* arr, int arrSize) {
    int a=arrSize/4,n=arrSize-a;
    for(int i=0; i<n; i++){
        if(arr[i] == arr[i+a]) return arr[i];
    }
    return -1;
}
