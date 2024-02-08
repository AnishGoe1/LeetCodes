/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool canFormArithmeticSequence(int* arr, int left, int right) {
    // Sort the subarray to check if the differences are constant
    int size = right - left + 1;
    int* subarray = (int*)malloc(size * sizeof(int));
    
    for (int i = 0; i < size; ++i) {
        subarray[i] = arr[left + i];
    }
    
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (subarray[j] > subarray[j + 1]) {
                // Swap elements if they are in the wrong order
                int temp = subarray[j];
                subarray[j] = subarray[j + 1];
                subarray[j + 1] = temp;
            }
        }
    }
    
    // Check if the differences are constant
    int commonDiff = subarray[1] - subarray[0];
    for (int i = 2; i < size; ++i) {
        if (subarray[i] - subarray[i - 1] != commonDiff) {
            free(subarray);
            return false;
        }
    }
    
    free(subarray);
    return true;
}

bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize) {
    bool* result = (bool*)malloc(lSize * sizeof(bool));
    
    for (int i = 0; i < lSize; ++i) {
        int left = l[i];
        int right = r[i];
        
        // Check if the subarray can be rearranged to form an arithmetic sequence
        result[i] = canFormArithmeticSequence(nums, left, right);
    }
    
    *returnSize = lSize;
    return result;
}





bool CheckArithmeticSubarraysInner(int* pnNums, short sLength)
{
    // get nMin & nMax input value
    int nMin = INT_MAX, nMax = INT_MIN;
    short sNumsSize = 1 + sLength;
    while(sNumsSize--)
    {
        if(nMin > *pnNums) nMin = *pnNums;
        if(nMax < *pnNums) nMax = *pnNums;

        pnNums++;
    }

    // return true directly if all input value are the same
    if(nMin == nMax) return true;

    // check nDiff from nMin and nMax, return false if nDiff cannot by divided by sLength
    int nDiff = nMax - nMin;
    if(nDiff % sLength) return false;

    // ** change nDiff to one time only
    nDiff /= sLength;

    // allocate aucMask to identify if i * nDiff is already hit or not
    char cSize = 1 + ((sLength++) >> 3);
    unsigned char aucMask[cSize];
    memset(aucMask, 0, cSize*sizeof(char));

    while(sLength--)
    {
        // get nCurrDiff from nMin and nMax, return false if nCurrDiff cannot by divided by nDiff
        int nCurrDiff = *(--pnNums) - nMin;
        if(nCurrDiff % nDiff) return false;

        // covert nCurrDiff into index of aucMask and also get bit ucMask
        nCurrDiff /= nDiff;
        unsigned char ucMask = 1 << (nCurrDiff % 8);
        nCurrDiff >>= 3;

        // return false if duplicate ucMask
        if(aucMask[nCurrDiff] & ucMask) return false;

        aucMask[nCurrDiff] |= ucMask;
    }

    return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize) {
    *returnSize = lSize;
    bool* pbRet = (bool*) malloc(lSize*sizeof(bool));
    bool* pbWrite = pbRet;
    while(lSize--)
    {
        *(pbWrite++) = CheckArithmeticSubarraysInner(nums+*l, *r-*l);

        l++;
        r++;
    }

    return pbRet;
}
