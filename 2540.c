int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int p1 = 0, p2 = 0 ;
    int n1 = nums1Size ; 
    int n2 = nums2Size ;
    while(p1 < n1 || p2 < n2){
        if(p1 == n1 ){
            if( nums2[p2] > nums1[n1-1] )
                return -1 ;
            else{
                for(int i = p2 ; i < n2 ; i++){
                    if(nums2[i] == nums1[n1-1])
                        return nums2[i] ;
                }
                return -1 ;
            }
        }
        if(p2 == n2 ){
            if( nums1[p1] > nums2[n2-1] )
                return -1 ;
            else{
                for(int i = p1 ; i < n1 ; i++){
                    if(nums1[i] == nums2[n2-1])
                        return nums1[i] ;
                }
                return -1 ;
            }
        }
        if(nums1[p1] == nums2[p2])
            return nums1[p1] ;
        if(nums1[p1] < nums2[p2])
            p1++;
        else
            p2++;
    }
    return -1 ;
}
