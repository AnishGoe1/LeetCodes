int garbageCollection(char** garbage, int garbageSize, int* travel, int travelSize) {
    long long totalMinutes = 0;
    long long currentTravelTime = 0;
    totalMinutes += strlen(garbage[0]);
    int lastGarbageIndices[3] = {-1, -1, -1};
    for (int houseIndex = 1; houseIndex < garbageSize; houseIndex++) {
        totalMinutes += strlen(garbage[houseIndex]);
        if (strchr(garbage[houseIndex], 'M') != NULL)
            lastGarbageIndices[0] = houseIndex - 1;
        if (strchr(garbage[houseIndex], 'P') != NULL)
            lastGarbageIndices[1] = houseIndex - 1;
        if (strchr(garbage[houseIndex], 'G') != NULL)
            lastGarbageIndices[2] = houseIndex - 1;
    }
    for (int travelIndex = 0; travelIndex < travelSize; travelIndex++) {
        currentTravelTime += travel[travelIndex];
        for (int truckIndex = 0; truckIndex < 3; truckIndex++) {
            if (lastGarbageIndices[truckIndex] == travelIndex) {
                totalMinutes += currentTravelTime;
            }
        }
    }
    return (int)totalMinutes;
}
