int beamInFloor(const char *floor, const int n) {
    int result = 0; 
    for (int i = 0; i < n; ++i) {
        result += floor[i] == '1';
    }
    return result;
}

int numberOfBeams(char** bank, int bankSize) {
    int num_beam = 0;
    int prev = 0;

    for (int i = 0; i < bankSize; ++i) {
        // Get the number of beams on current floor
        int beam = beamInFloor(bank[i], strlen(bank[i]));
        num_beam += beam * prev;

        // Only when the floor has beams, update the number to prev
        if (beam > 0) {
            prev = beam;
        }
    }

    return num_beam;
}
