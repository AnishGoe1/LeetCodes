int countCharacters(char** words, int wordsSize, char* chars) {
    int result = 0;
    int charCount[26] = {0};
    int charsLength = strlen(chars);
    for (int i = 0; i < charsLength; i++) 
    {
        charCount[chars[i] - 'a']++;
    }
    for (int i = 0; i < wordsSize; i++) 
    {
        int wordCharCount[26];
        memcpy(wordCharCount, charCount, sizeof(charCount));
        int wordLength = strlen(words[i]);
        int canFormWord = 1;
        for (int j = 0; j < wordLength; j++) 
        {
            int index = words[i][j] - 'a';
            if (wordCharCount[index] > 0) 
            {
                wordCharCount[index]--;
            } 
            else 
            {
                canFormWord = 0;
                break;
            }
        }
        if (canFormWord) 
        {
            result += wordLength;
        }
    }
    return result;
}




int countCharacters(char ** words, int wordsSize, char * chars){
    int hash[26][2] = {0};
    int len, cnt, ans = 0;
    for (int i = 0; i < strlen(chars); i++) {
        hash[chars[i] - 'a'][0]++;
        hash[chars[i] - 'a'][1]++;
    }
    for (int i = 0; i < wordsSize; i++) {
        len = strlen(words[i]);
        cnt = 0;
        for (int j = 0; words[i][j]; j++) {
            if (hash[words[i][j] - 'a'][0] && hash[words[i][j] - 'a'][1]) {
                hash[words[i][j] - 'a'][1]--;
                cnt++;
            }
            else {
                break;
            }
        }
        if (cnt == len) {
            ans += cnt;   
        }
        for (int i = 0; i < 26; i++) {
            hash[i][1] = hash[i][0];
        }
    }
    return ans;
}
