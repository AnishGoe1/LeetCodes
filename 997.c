int findJudge(int n, int** trust, int trustSize, int* trustColSize){
    if(trustSize < n-1)
        return -1;
    int* count = calloc(n+1, sizeof(int)) ;
    bool* citizen = calloc(n + 1, sizeof(int));
    for(int i = 0; i < trustSize; i++){
        count[trust[i][1]]++;
        citizen[trust[i][0]] = true;
    }

    int ans = -1;
    for(int i = 1; i <= n; i++){
        if(count[i] == n-1 && citizen[i] == false){
            ans = i;
            break;
        }
    }
    free(count);
    free(citizen);
    return ans ;
}int findJudge(int n, int** trust, int trustSize, int* trustColSize){
    if(trustSize < n-1)
        return -1;
    int* count = calloc(n+1, sizeof(int)) ;
    bool* citizen = calloc(n + 1, sizeof(int));
    for(int i = 0; i < trustSize; i++){
        count[trust[i][1]]++;
        citizen[trust[i][0]] = true;
    }

    int ans = -1;
    for(int i = 1; i <= n; i++){
        if(count[i] == n-1 && citizen[i] == false){
            ans = i;
            break;
        }
    }
    free(count);
    free(citizen);
    return ans ;
}
