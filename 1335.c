#define min(x,y) (((x) < (y))?(x):(y))  // Define a macro to find the minimum between two values
#define max(x,y) (((x) > (y))?(x):(y))  // Define a macro to find the maximum between two values
#define MAX_LIMIT 10000                 // Maximum possible job difficulty (based on constraints)

int minDifficulty(int* jobDifficulty, int jobDifficultySize, int d) {
    // Handle invalid cases:
    if (jobDifficultySize < d) {
        return -1;  // Not enough jobs for the given number of days
    }

    // Base case: If there's only one day, the minimum difficulty is the maximum job difficulty.
    if (d == 1) {
        int maxDifficulty = 0;
        for (int i = 0; i < jobDifficultySize; i++) {
            maxDifficulty = max(maxDifficulty, jobDifficulty[i]);
        }
        return maxDifficulty;
    }

    // Initialize arrays for tracking minimum difficulties:
    int maxDifficulty = 0;       // Maximum difficulty for a given day
    int minJobDiff[jobDifficultySize + 1]; // Minimum difficulty to complete jobs up to each index
    for (int i = 0; i < jobDifficultySize; i++) {
        minJobDiff[i] = MAX_LIMIT + 1;  // Initialize with a large value
    }
    minJobDiff[jobDifficultySize] = 0;  // Base case: No difficulty for completing no jobs

    // Iterate through each day:
    for (int day = 1; day <= d; ++day) {
        for (int i = 0; i <= jobDifficultySize - day; i++) {  // Consider different job starting points
            maxDifficulty = 0;
            minJobDiff[i] = MAX_LIMIT + 1;  // Reset for current day

            // Iterate through possible job lists for the current day:
            for (int j = i; j <= jobDifficultySize - day; j++) {
                maxDifficulty = max(maxDifficulty, jobDifficulty[j]);  // Update maximum difficulty for the day
                minJobDiff[i] = min(minJobDiff[i], maxDifficulty + minJobDiff[j + 1]); // Calculate minimum total difficulty
            }
        }
    }

    // The minimum difficulty for all jobs is stored in minJobDiff[0]
    return minJobDiff[0];
}
