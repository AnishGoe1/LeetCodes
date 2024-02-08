int numSpecial(int** mat, int matSize, int* matColSize) {
  // Initialize counter for special positions
  int ans = 0;

  // Get dimensions of the matrix
  int m = matSize;
  int n = *matColSize;

  // Loop through each row
  for (int row = 0; row < m; row++) {
    // Loop through each column
    for (int col = 0; col < n; col++) {
      // Skip if the current element is 0
      if (mat[row][col] == 0) {
        continue;
      }

      // Flag for valid special position
      int good = 1;

      // Check other elements in the current row (except itself)
      for (int r = 0; r < m && good; r++) { // Early exit if not special
        if (r != row && mat[r][col] == 1) {
          good = 0;
          break;
        }
      }

      // Check other elements in the current column (except itself)
      for (int c = 0; c < n && good; c++) { // Early exit if not special
        if (c != col && mat[row][c] == 1) {
          good = 0;
          break;
        }
      }

      // Increment counter if the current element is special
      if (good) {
        ans++;
      }
    }
  }

  return ans; // Total number of special positions
}
