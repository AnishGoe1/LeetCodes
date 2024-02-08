/*
 * Finds the size of the hash array needed based on the range of values in the input array.
 */
int findSize(int* arr, int arrSize, int* min) {
    int max = arr[0];  // Initialize max with the first element

    // Iterate through the array to find the maximum and minimum values
    for (int i = 1; i < arrSize; i++) {
        max = arr[i] > max ? arr[i] : max;  // Update max if needed
        *min = arr[i] < *min ? arr[i] : *min;  // Update min if needed
    }

    // Calculate the size based on the range, considering negative values
    return *min < 0 ? max + abs(*min) + 1 : max + 1;
}

/*
 * Comparison function for qsort, used to sort elements in descending order.
 */
int cmp(const void* a, const void* b) {
    return *(const int*) b - *(const int*) a;  // Compare integers in descending order
}

/*
 * Checks if all element frequencies (occurrences) in the array are unique.
 */
bool uniqueOccurrences(int* arr, int arrSize) {
    int shift = arr[0];  // Initial shift for handling negative values
    int size = findSize(arr, arrSize, &shift);  // Determine hash array size
    shift = (shift > 0) ? 0 : abs(shift);  // Adjust shift if needed

    // Create a hash array to count element frequencies
    int* hash = (int*)calloc(size, sizeof(int));

    // Count element frequencies using the hash array
    for (int i = 0; i < arrSize; i++) {
        hash[arr[i] + shift]++;
    }

    // Sort frequencies in descending order to easily check for duplicates
    qsort(hash, size, sizeof(int), cmp);

    // Check for duplicate frequencies
    for (int i = 0; i + 1 < size; i++) {
        if (hash[i + 1] == 0) {
            break;  // Stop if remaining frequencies are 0
        }
        if (hash[i] == hash[i + 1]) {
            free(hash);  // Free memory before returning
            return false;  // Duplicate frequency found
        }
    }

    free(hash);  // Free memory after successful check
    return true;  // All frequencies are unique
}

