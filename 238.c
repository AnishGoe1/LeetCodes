/**
 * @brief Calculates the product of all elements in the array except itself for each element.
 *
 * This function takes an integer array `nums` and its size `numsSize` as input. It creates a new
 * array `ret` of the same size and calculates the product of all elements in `nums` except
 * for each element at its corresponding index in `ret`. The function uses a prefix product
 * and a postfix product approach to achieve this in O(n) time.
 *
 * @param nums: The input array of integers.
 * @param numsSize: The size of the input array.
 * @param returnSize: A pointer to store the size of the output array (which is the same as numsSize).
 *
 * @return: A pointer to the newly created output array containing the product of all elements
 *          except itself for each element in the input array. The memory for the output array
 *          needs to be freed by the caller using the `free()` function.
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {

    // Allocate memory for the output array and initialize it with zeros.
    int* ret = (int*)malloc(numsSize * sizeof(int));
    memset(ret, 0, numsSize * sizeof(int));

    // Set the return size to the size of the input array.
    *returnSize = numsSize;

    // Variable to store the postfix product.
    int postfix = 1;

    // Calculate the prefix product for each element.
    // ret[i] stores the product of all elements from index 0 to i-1 (excluding i).
    ret[0] = 1;  // Initialize the first element of prefix product as 1.
    for (int i = 1; i < numsSize; i++) {
        ret[i] = ret[i - 1] * nums[i - 1];
    }

    // Calculate the postfix product for each element.
    // postfix stores the product of all elements from i+1 to the end of the array (excluding i).
    for (int i = numsSize - 2; i >= 0; i--) {
        postfix *= nums[i + 1];
        ret[i] *= postfix;  // Multiply the prefix product with the postfix product to get the product excluding the current element.
    }

    // Return the output array.
    return ret;
}

