int dp[2001][2001];
bool match(int s_index, char* s, int p_index, char* p, int s_len, int p_len)
{
    if(dp[s_index][p_index] != -1)
        return (bool)dp[s_index][p_index];
    if(s_index == s_len)
    {
        int curr_index = p_index;
        while(p[curr_index] == '*')
            curr_index++;
        dp[s_index][p_index] = curr_index == p_len;
        return curr_index == p_len;
    }
    if(p_index == p_len)
    {
        dp[s_index][p_index] = 0;
        return false;
    }
    if(p[p_index] == '?')
    {
        dp[s_index][p_index] = match(s_index + 1, s, p_index + 1, p, s_len, p_len);
        return (bool)dp[s_index][p_index];
    }
    if(p[p_index] == '*')
    {
        dp[s_index][p_index] = match(s_index + 1, s, p_index, p, s_len, p_len) || match(s_index, s, p_index + 1, p, s_len, p_len);
        return (bool)dp[s_index][p_index];
    }
    if(s[s_index] != p[p_index])
    {
        dp[s_index][p_index] = 0;
        return false;
    }
    dp[s_index][p_index] = match(s_index + 1, s, p_index + 1, p, s_len, p_len);
    return (bool)dp[s_index][p_index];
}

bool isMatch(char * s, char * p)
{
    memset(dp, -1, sizeof(dp));
    dp[strlen(s)][strlen(p)] = 1;
    return match(0, s, 0, p, strlen(s), strlen(p));
}
