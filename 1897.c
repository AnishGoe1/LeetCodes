typedef struct {
    char key;
    int value;
} Pair;

bool makeEqual(char** words, int wordsSize) 
{
    int length = wordsSize;
    Pair charCount[26]; 
    for (int i = 0; i < 26; i++) 
    {
        charCount[i].key = 'a' + i;
        charCount[i].value = 0;
    }
    for (int i = 0; i < wordsSize; i++) 
    {
        char *word = words[i];
        int wordLen = strlen(word);
        for (int j = 0; j < wordLen; j++) 
        {
            charCount[word[j] - 'a'].value++;
        }
    }
    for (int i = 0; i < 26; i++) 
    {
        if (charCount[i].value % length != 0) 
        {
            return false; 
        }
    }
    return true;
}
