int climbStairs(int n) {
    if(n<=3)return n;
        int a = 2, b = 3,ans;
        for(int i = 4; i <= n; i++){
            ans = a+b;
            a = b, b = ans;
        }
        return b;
}
