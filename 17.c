/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Function to map digits to letters
const char *mapping[] = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

// Function to generate letter combinations using backtracking
void generateCombinations(char *digits, int index, char *current, char **result, int *count) {
    if (index == strlen(digits)) {
        result[*count] = strdup(current);
        (*count)++;
        return;
    }

    int digit = digits[index] - '0';
    const char *letters = mapping[digit];

    for (int i = 0; i < strlen(letters); i++) {
        current[index] = letters[i];
        generateCombinations(digits, index + 1, current, result, count);
    }
}

// Function to initialize and call the combination generation
char **letterCombinations(char *digits, int *returnSize) {
    int len = strlen(digits);
    if (len == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Calculate the maximum number of combinations
    int maxCombinations = 1;
    for (int i = 0; i < len; i++) {
        maxCombinations *= strlen(mapping[digits[i] - '0']);
    }

    // Allocate memory for the result array
    char *result = (char *)malloc(maxCombinations * sizeof(char *));
    *returnSize = 0;

    // Allocate memory for the current combination
    char *current = (char *)malloc((len + 1) * sizeof(char));
    current[len] = '\0';

    // Generate combinations
    generateCombinations(digits, 0, current, result, returnSize);

    // Free memory
    free(current);

    return result;
}
