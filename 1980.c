char* findDifferentBinaryString(char** nums, int numsSize) {
    char* ans = (char*)malloc((numsSize + 1) * sizeof(char));
    memset(ans, '\0', (numsSize + 1) * sizeof(char)); 
    for (int i = 0; i < numsSize; i++) {
        ans[i] = (nums[i][i] == '0') ? '1' : '0';
    }
    return ans;
}
