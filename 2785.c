int isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i' ||
            c == 'A' || c == 'E' || c == 'O' || c == 'U' || c == 'I');
}
char* sortVowels(char* s) {
    int count[256] = {0}; 
    for (int i = 0; s[i] != '\0'; i++) {
        if (isVowel(s[i])) {
            count[s[i]]++;
        }
    }
    char sortedVowel[] = "AEIOUaeiou";
    char* ans = (char*)malloc((strlen(s) + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (!isVowel(s[i])) {
            ans[i] = s[i];
        } else {
            while (count[sortedVowel[j]] == 0) {
                j++;
            }

            ans[i] = sortedVowel[j];
            count[sortedVowel[j]]--;
        }
    }
    ans[strlen(s)] = '\0'; 
    return ans;
}
