bool isMatch(char *s, char *p) {
    if (*p == '\0') {
        return *s == '\0';
    }

    // Check if the next character is followed by '*'
    if (*(p + 1) == '*') {
        // '*' Matches zero or more of the preceding element
        while (*s != '\0' && (*s == *p || *p == '.')) {
            if (isMatch(s, p + 2)) {
                return true;
            }
            s++;
        }

        // Case when '*' is considered as 0 occurrences
        return isMatch(s, p + 2);
    } else {
        // '.' Matches any single character
        if (*s != '\0' && (*s == *p || *p == '.')) {
            return isMatch(s + 1, p + 1);
        }
        return false;
    }
}
