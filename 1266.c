int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize) {
    // Initialize the total time variable
    int time = 0;
    // Loop through the points starting from the second point (index 1)
    for (int i = 1; i < pointsSize; ++i) {
        // Calculate the maximum of the absolute differences in x and y between consecutive points & Add the maximum difference to the total time
        time += fmax(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1]));
    }
    // Return the total time required to visit all points
    return time;
}
