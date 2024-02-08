int compareChars(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}
bool isAnagram(char* s, char* t) {
    int len_s = strlen(s);
    int len_t = strlen(t);
    if (len_s != len_t) {
        return false;
    }
    char* sorted_s = strdup(s);
    char* sorted_t = strdup(t);
    qsort(sorted_s, len_s, sizeof(char), compareChars);
    qsort(sorted_t, len_t, sizeof(char), compareChars);
    bool result = strcmp(sorted_s, sorted_t) == 0;
    free(sorted_s);
    free(sorted_t);
    return result;
}
