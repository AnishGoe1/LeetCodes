#pragma GCC optimize("O3", "unroll-loops")
int maxLengthBetweenEqualCharacters(char* s) {
    int alpha[26];
    memset(alpha, -1, sizeof(alpha));
    int maxLen=-1;
    for(register int i=0; s[i]!='\0'; i++){
        int idx=s[i]-'a';
        int newLen=i-alpha[idx]-1;
        if (alpha[idx]!=-1 && newLen>maxLen) maxLen=newLen;
        else if (alpha[idx]==-1) alpha[idx]=i;
    }
    return maxLen;
}
