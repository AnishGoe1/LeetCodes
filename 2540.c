int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Function to find the first common element in two sorted arrays

    // Initialize pointers to iterate through the arrays
    int p1 = 0, p2 = 0;

    // Track the sizes of the arrays
    int n1 = nums1Size;
    int n2 = nums2Size;

    // Loop until either pointer reaches the end of its array
    while (p1 < n1 && p2 < n2) {
        // Compare elements at current positions
        if (nums1[p1] == nums2[p2]) {
            // Found a common element, return it
            return nums1[p1];
        }

        // Advance pointers based on the comparison
        // Move p1 if nums1[p1] is smaller
        if (nums1[p1] < nums2[p2]) {
            p1++;
        } else {
            // Move p2 if nums1[p1] is larger
            p2++;
        }
    }

    // No common element found, return -1
    return -1;
}
