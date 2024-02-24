void mark(int n, int** checkerboard, int i, int j){
    int left = j;
    int right = j;
    i++;
    right++;
    left--;
    while (i < n){
        if (right < n){
            checkerboard[i][right]++;
            right++;
        }
        if (left >= 0){
            checkerboard[i][left]++;
            left--;
        }
        checkerboard[i][j]++;
        i++;
    }
    return;
}

void del_mark(int n, int** checkerboard, int i, int j){
    int left = j;
    int right = j;
    i++;
    right++;
    left--;
    while (i < n){
        if (right < n){
            checkerboard[i][right]--;
            right++;
        }
        if (left >= 0){
            checkerboard[i][left]--;
            left--;
        }
        checkerboard[i][j]--;
        i++;
    }
    return;
}

void check(int** checkerboard, int n, int* ans, int i){
    if (i == n){
        *ans += 1;
        return;
    }
    for (int j = 0 ; j < n ; j++){
        if (checkerboard[i][j] == 0){
            mark( n, checkerboard, i, j);
            check(checkerboard, n, ans, i+1);
            del_mark( n, checkerboard, i, j);
        } 
    }
}

int totalNQueens(int n){
    int** checkerboard = malloc(sizeof(int*)*n);
    for (int i = 0 ; i < n ; i++){
        checkerboard[i] = calloc(n,sizeof(int));
    }
    int ans = 0;
    check(checkerboard, n, &ans, 0);
    for (int i = 0 ; i < n ; i++){
        free(checkerboard[i]);
    }
    free(checkerboard);
    return ans;
}
