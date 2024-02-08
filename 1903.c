char* largestOddNumber(char* num) {
    // Get the length of the input string
    int n = strlen(num);
    // Static array to store the result
    static char ans[100001];
    // Initialize ans as an empty string
    ans[0] = '\0';
    // Check if the last digit of the input is odd, if so, no changes needed
    if ((num[n - 1] - '0') % 2 != 0)
        return num;
    // Iterate through the digits of the input from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Check if the current digit is odd
        if ((num[i] - '0') % 2 != 0) {
            // If odd, truncate the string from the next digit onwards
            num[i + 1] = '\0';
            // Copy the updated string to the result array
            strcpy(ans, num);
            // Return the result
            return ans;
        }
    }
    // If no odd digit is found, return an empty string
    return "";
}
