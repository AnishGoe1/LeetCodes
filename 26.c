int removeDuplicates(int* nums, int numsSize) {
    /*
      - Removes duplicates from a sorted array in-place.
      - Returns the number of unique elements left in the array.
    */

    // Handle empty array
    if (numsSize == 0) {
        return 0;
    }

    int count = 1;  // Count of unique elements
    int j = 0;      // Count of duplicates encountered

    // Iterate through the array, starting from the second element
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] != nums[i + 1]) {  // If current and next elements are different
            count++;                    // Increment count of unique elements
            nums[i + 1 - j] = nums[i + 1];  // Shift unique element to its correct position
        } else {
            j++;                       // Increment count of duplicates
        }
    }

    return count;  // Return the number of unique elements
}

// Time Complexity: O(N), where N is the length of the array
// - The loop iterates through the array once, performing constant-time operations within it.

// Space Complexity: O(1), or constant space
// - No additional data structures are used beyond a few constant-size variables.

