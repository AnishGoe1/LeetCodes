#define RES_LEN 300

char ** fullJustify(char ** words, int wordsSize, int maxWidth, int* returnSize){
    int spaces, pad, remainSpaces, lWidth, cWordLen;
    // allocate memory for the result
    char **res = calloc(sizeof(char *),  RES_LEN);
    for(int i = 0; i < RES_LEN; i++)
        res[i] = calloc(sizeof(char), maxWidth + 1);
    *returnSize = 0;
    int cLen = 0;
    
    for(int l = 0, r; l < wordsSize; l = r) {
        // find words that can fit to form a current line in result
        r = l;
        lWidth = 0; 
        cWordLen = strlen(words[r]);
        while(r < wordsSize && cWordLen + lWidth + r - l <= maxWidth) {
            lWidth += cWordLen;
            r++;
            if(r < wordsSize)
                cWordLen = strlen(words[r]);
        }
        
        // calculate the spaces and extra spaces to pad after each word in this line
        spaces = 1;
        pad = 0;
        if(r - l != 1 && r != wordsSize) {
            spaces = (maxWidth - lWidth) / (r - l - 1);
            pad = (maxWidth - lWidth) % (r - l - 1);
        }
        
		// Now, words from left to right pointers can be added to current line by justifying. 
        // Add the left most word first. Then, add all the spaces and extra padded spaces.
		// Then, add the next word 
        cLen = 0;
        cLen += sprintf(res[*returnSize], "%s", words[l]);
        for(int w = l + 1; w < r; w++) {										
            for(int i = 0; i < spaces; i++)									// append spaces after current word
                cLen += sprintf(res[*returnSize] + cLen, "%c", ' ');

            // pad extra space for words in line from left to right 
            if(pad-- > 0)													// append extra padded spaces in left justified manner                
                cLen += sprintf(res[*returnSize] + cLen, "%c", ' ');
            
            cLen += sprintf(res[*returnSize] + cLen, "%s", words[w]);            
        }
        
        // Adjust the last line by appending remaining spaces to the right
        remainSpaces = maxWidth - cLen;
        for(int i = 0; i < remainSpaces; i++)
            cLen += sprintf(res[*returnSize] + cLen, "%c", ' ');
        
        (*returnSize)++;
    }
    return res;
}
