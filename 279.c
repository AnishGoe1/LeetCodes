int numSquares(int n) {
    // Handle special cases for quick optimization:
    while (n % 4 == 0) {
        n /= 4; // Reduce n by dividing by 4 as long as it's divisible by 4
    }
    if (n % 8 == 7) {
        return 4; // If n is 7 modulo 8, the minimum number of squares is 4
    }

    // Optimized iteration to check for two squares
    for (int a = 0; a * a <= n; ++a) {
        int b = sqrt(n - a*a); // Calculate potential remainder squares to find
        if (a*a + b*b == n){ // Check if b is an integer perfect square
            return 1 + !!a; // If n can be formed by two squares, return 1 + !!a
        }
    }

    // General case: Handle squares with 3 components
    return 3; // In the general case, at most 3 squares are needed
}
