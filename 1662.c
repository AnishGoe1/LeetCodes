bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    // Concatenate elements in each array to form strings
    char str1[10000] = "";
    char str2[10000] = "";

    for (int i = 0; i < word1Size; i++) {
        strcat(str1, word1[i]);
    }

    for (int i = 0; i < word2Size; i++) {
        strcat(str2, word2[i]);
    }

    // Compare the concatenated strings
    return strcmp(str1, str2) == 0;
}




bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    // Dynamically allocate memory for concatenated strings
    char* str1 = (char*)malloc(1);  // Initialize with size 1 for the null terminator
    char* str2 = (char*)malloc(1);
    str1[0] = '\0';
    str2[0] = '\0';
    // Concatenate elements in each array to form strings
    for (int i = 0; i < word1Size; i++) {
        str1 = (char*)realloc(str1, strlen(str1) + strlen(word1[i]) + 1);
        strcat(str1, word1[i]);
    }
    for (int i = 0; i < word2Size; i++) {
        str2 = (char*)realloc(str2, strlen(str2) + strlen(word2[i]) + 1);
        strcat(str2, word2[i]);
    }
    // Compare the concatenated strings
    int result = strcmp(str1, str2);
    // Free dynamically allocated memory
    free(str1);
    free(str2);
    return result == 0;
}






bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    // Calculate the total length needed for each concatenated string
    int length1 = 0;
    int length2 = 0;
    for (int i = 0; i < word1Size; i++) {
        length1 += strlen(word1[i]);
    }
    for (int i = 0; i < word2Size; i++) {
        length2 += strlen(word2[i]);
    }
    // Dynamically allocate memory for concatenated strings
    char* str1 = (char*)malloc(length1 + 1);  // Add 1 for the null terminator
    char* str2 = (char*)malloc(length2 + 1);
    str1[0] = '\0';
    str2[0] = '\0';
    // Concatenate elements in each array to form strings
    for (int i = 0; i < word1Size; i++) {
        strcat(str1, word1[i]);
    }
    for (int i = 0; i < word2Size; i++) {
        strcat(str2, word2[i]);
    }
    // Compare the concatenated strings
    int result = strcmp(str1, str2);
    // Free dynamically allocated memory
    free(str1);
    free(str2);
    return result == 0;
}
