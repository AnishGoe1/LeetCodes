

void copy(int* c,int* a,int n){
	for(int i = 0; i < n;i++){
		c[i] = *(a+i);
	}
}

void merge(int* b,int* c,int* a,int n){
	int i = 0;
	int j = 0;
	int k = 0;
	while ((i < n/2) && (j < (n-(n/2)))){
		if(b[i] < c[j]){
			a[k++] = b[i++];
		}
		else{
			a[k++] = c[j++];
		}
	}
	if(i == (n/2)){
		copy(&a[k],&c[j],(n-(n/2)-j));
	}
	else
		copy(&a[k],&b[i],(n/2-i));

}

void mergesort(int* a, int n){
	int* b = (int*)malloc(sizeof(int)*n/2);
	int* c = (int*)malloc(sizeof(int)*(n-(n/2)));
	copy(b,a,n/2);
	copy(c,&(a[n/2]),(n-(n/2)));

	if (n >1){
		mergesort(b,n/2);
		mergesort(c,(n-(n/2)));
	}
	merge(b,c,a,n);
}

int* sortedSquares(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int* returnArray = (int*)malloc(sizeof(int)*numsSize);
    for(int i = 0;i<numsSize;i++){
        returnArray[i] = nums[i]*nums[i];
    }
    mergesort(returnArray,numsSize);
    return returnArray;
    
}
