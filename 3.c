int lengthOfLongestSubstring(char* s) {
    int store[256]={0};
    int l=0;   
    int r=0; 
    int ans=0; 
        while(r<strlen(s))
        {
            store[s[r]]++;  
            while(store[s[r]]>1)
            { 
                store[s[l]]--;
                l++;
            }
            ans = fmax(ans,r-l+1);
            r++; 
        }
        return ans;
}





int lengthOfLongestSubstring(char * s)
{
    int counts[512];
    int i, n = strlen(s), win_start = 0;
    int best = 0;
    
    memset(counts, 0, sizeof(int) * 512);

    for (i = 0; i < n; i++) {
        int c = s[i];
        if (counts[c] >= 1) {
            assert(counts[c] == 1);
            while (win_start < i) {
                int to_del = s[win_start];
                counts[to_del]--;
                win_start++;                
                if (counts[c] == 0)
                    break;
            }
        }
        counts[c]++;
        best = fmax(best, i - win_start + 1);
    }
    
    return best;
}
