int majorityElement(int* nums, int numsSize) {
    int a=-1, b=0;
    for(int i=0;i<numsSize;i++){
        if(b==0){
            a=nums[i];
            b=1;
        }
        else{
            if(a==nums[i])
            b++;
            else b--;
        }
    }
    return a;
}
