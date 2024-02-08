
int compare(const void *a, const void *b) {

    return (*(int*)a - *(int*)b);

}
int minOperations(int* nums, int numsSize){
     qsort(nums, numsSize, sizeof(int), compare);
    int res = 0,si=0;


        while(si < numsSize){

            int ei = si;

            

            while(ei < numsSize && nums[ei] == nums[si]) {

                ei++;

            }

            int count = ei-si;

            if(count == 1) return -1;

            res += count/3;

            if(count%3 != 0) res++;

            si=ei;

        }

        return res;
}
