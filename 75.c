void sortColors(int* nums, int numsSize){
    int two_ptr = numsSize -1;
    int zero_ptr = 0;
    int one_ptr = 0;
    while (one_ptr <= two_ptr)
    {
        if (nums[one_ptr] == 0)
        {
            int save = nums[zero_ptr];
            nums[zero_ptr] = nums[one_ptr];
            nums[one_ptr] = save;
            one_ptr++; zero_ptr++;
        }
        else if (nums[one_ptr] == 1)
        {
            one_ptr++;
        }
        else
        {
            int save = nums[two_ptr];
            nums[two_ptr] = nums[one_ptr];
            nums[one_ptr] = save;
            two_ptr--;
        }
    }
}
