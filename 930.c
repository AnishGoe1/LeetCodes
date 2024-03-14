/**
 * @brief Counts the number of subarrays in the given array `nums` that have a sum equal to `goal`.
 * @param nums An integer array containing the elements.
 * @param numsSize The size of the array `nums`.
 * @param goal The target sum to find subarrays for.
 * @return The number of subarrays in `nums` that have a sum equal to `goal`.
 */
int numSubarraysWithSum(int* nums, int numsSize, int goal) {
    int n = numsSize;

    // Hash table to store cumulative sums (keys) and their frequencies (values)
    int** hashMap = (int**)calloc(n + 1, sizeof(int*));  // Allocate memory for n + 1 entries

    // Initialize the first entry in the hash table for sum 0 (frequency 1)
    hashMap[0] = (int*)malloc(2 * sizeof(int));
    hashMap[0][0] = 0;
    hashMap[0][1] = 1;

    int sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];

        // Calculate the remainder (running sum minus goal) for potential match in the hash table
        int rm = sum - goal;

        // Check if the hash table contains the remainder (key)
        if (rm >= 0 && hashMap[rm % (n + 1)] != NULL) {
            ans += hashMap[rm % (n + 1)][1];  // Add the frequency of the matching remainder
        }

        // Update the hash table for the current sum (key), incrementing its frequency (value)
        int* currentEntry = hashMap[sum % (n + 1)];
        if (currentEntry == NULL) {
            currentEntry = (int*)malloc(2 * sizeof(int));
            currentEntry[0] = sum;
            currentEntry[1] = 1;
            hashMap[sum % (n + 1)] = currentEntry;
        } else {
            currentEntry[1]++;
        }
    }

    // Free the dynamically allocated memory within the hash table
    for (int i = 0; i < n + 1; i++) {
        if (hashMap[i] != NULL) {
            free(hashMap[i]);
        }
    }
    free(hashMap);

    return ans;
}

