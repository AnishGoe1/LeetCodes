int max(int a, int b) {
    // Function to find the maximum of two integers
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int maxDepth(char *s) {
    int maximumDepth = 0; // Variable to track maximum nesting depth
    int num = 0;           // Variable to track current nesting depth
    int i = 0;             // Loop counter

    while (s[i] != '\0') { // Loop through characters in the string
        if (s[i] == '(') {
            num++;  // Increment for opening bracket '('
        } else if (s[i] == ')') {
            num--;  // Decrement for closing bracket ')'
        }
        maximumDepth = max(maximumDepth, num); // Update maximum depth if current depth is higher
        i++;                                   // Move to the next character
    }

    return maximumDepth;
}

