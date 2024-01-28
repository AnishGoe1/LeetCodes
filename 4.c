double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int n=nums1Size+nums2Size;
    int merged[n];
    for(int i=0;i<nums1Size;i++){
        merged[i]=nums1[i];
    }
    for(int i=0;i<nums2Size;i++){
        merged[nums1Size+i]=nums2[i];
    }
    int a;
    for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        if (merged[i] > merged[j]) {
            a = merged[i];
            merged[i] = merged[j];
            merged[j] = a;
        }
    }
}
    if(n%2==0){
        return (float)(merged[(n/2)-1]+merged[(n/2)])/2;
    }
    else{
        return merged[(n-1)/2];
    }
}





//Optimised code

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int n = nums1Size + nums2Size;
    int merged[n];
    int i = 0, j = 0, k = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] <= nums2[j]) {
            merged[k++] = nums1[i++];
        } else {
            merged[k++] = nums2[j++];
        }
    }

    while (i < nums1Size) {
        merged[k++] = nums1[i++];
    }

    while (j < nums2Size) {
        merged[k++] = nums2[j++];
    }
    if (n % 2 == 0) {
        return (double)(merged[(n / 2) - 1] + merged[n / 2]) / 2;
    } else {
        return merged[n / 2];
    }
}
