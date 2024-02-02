char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }

    int count = 0;
    int x=strlen(strs[0]);
    for (int i = 0; i< x ; i++) {
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != strs[0][i]) {
                goto end;
            }
        }
        count++;
    }

    end:
    char *result = (char*)malloc((count + 1) * sizeof(char));
    for (int i = 0; i < count; i++) {
        result[i] = strs[0][i];
    }
    result[count] = '\0';

    return result;
}





char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }

    int len = strlen(strs[0]);
    for (int i = 0; i < len; i++) {
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != strs[0][i]) {
                char* result = (char*)malloc((i + 1) * sizeof(char));
                strncpy(result, strs[0], i);
                result[i] = '\0';
                return result;
            }
        }
    }

    // If the loop completes, the entire first string is the common prefix
    return strdup(strs[0]);
}
