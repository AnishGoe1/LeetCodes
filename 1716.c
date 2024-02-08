int min(int a, int b) {
    return (a < b) ? a : b;
}
int totalMoney(int n) {
    int ans = 0;
    int monday = 1;
    
    while (n > 0) {
        for (int day = 0; day < (n < 7 ? n : 7); day++) {
            ans += monday + day;
        }
        n -= 7; 
        monday++;
    }
    return ans; 
}
