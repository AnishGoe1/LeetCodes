#define MIN(a, b) ((a) < (b) ? (a) : (b))  // Macro to find the minimum of two numbers

int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize) {
    int dr[] = {1, 1, 1};        // Direction vectors for downward, diagonal left, and diagonal right
    int dc[] = {-1, 0, 1};
    int sum[matrixSize][*matrixColSize];  // DP table to store minimum falling path sums

    // Initialize the bottom row with matrix values
    for (int c = 0; c < *matrixColSize; c++) {
        sum[matrixSize - 1][c] = matrix[matrixSize - 1][c];
    }

    // Build up minimum path sums from bottom to top
    for (int r = matrixSize - 2; r >= 0; r--) {
        for (int c = 0; c < *matrixColSize; c++) {
            sum[r][c] = INT_MAX;  // Initialize with a large value

            // Explore possible paths from current cell
            for (int d = 0; d < 3; d++) {
                // Check boundary conditions
                if (r + dr[d] < 0 || r + dr[d] >= matrixSize || c + dc[d] < 0 || c + dc[d] >= *matrixColSize) {
                    continue;
                }

                // Update minimum path sum considering the current cell's value and the path below
                sum[r][c] = MIN(sum[r][c], matrix[r][c] + sum[r + dr[d]][c + dc[d]]);
            }
        }
    }

    // Find the minimum falling path sum among all starting points in the top row
    int ans = INT_MAX;
    for (int c = 0; c < *matrixColSize; c++) {
        ans = MIN(ans, sum[0][c]);
    }
    return ans;
}

