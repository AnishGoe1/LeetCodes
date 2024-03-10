// Define a structure to store keys and intersection flags, along with a hash handle for UT_hash
typedef struct {
    int key;              // The integer key
    bool intersect;       // Flag indicating intersection
    UT_hash_handle hh;    // Hash handle for UT_hash
} Map;

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    Map *map = NULL, *element, *tmp;    // Map for storing keys and intersection flags
    int *result, len = 0;               // Array to store the intersection, and its length

    // Allocate initial space for the result array, considering potential size
    *returnSize = nums1Size < nums2Size ? nums1Size : nums2Size;
    result = malloc(*returnSize * sizeof(int));

    // Add elements from nums1 to the hash map
    for (int i = 0; i < nums1Size; i++) {
        element = malloc(sizeof(Map));
        element->key = nums1[i];
        element->intersect = false;  // Initially assume no intersection
        HASH_ADD_INT(map, key, element);  // Add to the hash map
    }

    // Mark intersecting elements in the hash map using nums2
    for (int i = 0; i < nums2Size; i++) {
        element = NULL;
        HASH_FIND_INT(map, &nums2[i], element);  // Find if the element exists in the map
        if (element) {
            element->intersect = true;  // Mark as intersecting
        }
    }

    // Iterate through the hash map and collect intersecting elements
    HASH_ITER(hh, map, element, tmp) {
        if (element->intersect) {
            result[len++] = element->key;  // Add to the result array
        }
        HASH_DEL(map, element);            // Free the hash element
        free(element);
    }

    // Resize the result array to the actual number of intersecting elements
    *returnSize = len;
    return realloc(result, sizeof(int) * len);
}

