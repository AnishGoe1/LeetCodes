#define SHAPE 9
#define GRID 3
#define EMPTY '.'

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int row[SHAPE+1]={0};
    int col[SHAPE+1]={0};
    int grid[SHAPE]={0};
    for(int r=0;r<SHAPE;r++){
        for(int c=0;c<SHAPE;c++){
            if(board[r][c]==EMPTY)continue;
            int val=1<<(board[r][c]-'0');
            if(row[r]&val)return false;
            else row[r]+=val;
            if(col[c]&val)return false;
            else col[c]+=val;
            int row=(r/GRID)*GRID;
            int col=(c/GRID);
            if(grid[row+col]&val)return false;
            else grid[row+col]+=val;
        }
    }
    return true;
}
