bool dfs(char** board, int rSize, int cSize, int r, int c, char* word, int slen, int k) {
    if(k == slen) return true;
    if(r < 0 || c < 0 || r > rSize-1 || c > cSize-1 || board[r][c] != word[k]) return false;
    char tmp = board[r][c];
    board[r][c] = ' ';
    bool res = (dfs(board, rSize, cSize, r+1, c, word, slen, k+1) | dfs(board, rSize, cSize, r-1, c, word, slen, k+1) |
                dfs(board, rSize, cSize, r, c+1, word, slen, k+1) | dfs(board, rSize, cSize, r, c-1, word, slen, k+1));
    board[r][c] = tmp;
    return res;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int rSize = boardSize, cSize = boardColSize[0], slen = strlen(word);
    for(int r = 0; r < rSize; r++) {
        for(int c = 0; c < cSize; c++) {
            if(dfs(board, rSize, cSize, r, c, word, slen, 0)) return true;
        }
    }
    return false;
}
