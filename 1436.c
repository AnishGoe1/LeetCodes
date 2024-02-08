char* destCity(char*** paths, int pathsSize, int* pathsColSize) {
    char** sourceCities = (char**)malloc(pathsSize * sizeof(char*));
    for (int i = 0; i < pathsSize; ++i) {
        sourceCities[i] = paths[i][0];
    }
    for (int i = 0; i < pathsSize; ++i) {
        int j;
        for (j = 0; j < pathsSize; ++j) {
            if (strcmp(paths[i][1], sourceCities[j]) == 0) {
                break;
            }
        }
        if (j == pathsSize) {
            return paths[i][1];
        }
    }
    return "";
}
