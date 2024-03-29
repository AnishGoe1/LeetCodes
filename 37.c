

int free1(char** board,int *row, int *col ) {
    
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++) {
            if(board[i][j] == '.') {
                *row = i;
                *col = j;
                 return 1;
            }
           
        }
        
    }
        return 0;
}

int safe(char **board, int row, int col, int num) {
    
    //check on col
    int x,y;
    for(int i=0; i<9; i++) {
        
        if(board[i][col] - '0' ==  num)
            return 0;
    }
    
    //check on row
    
    for(int i=0; i<9; i++) {
        
        if(board[row][i] - '0' == num)
            return 0;
    }       
    
    //check on 3*3 grid;
    x = row - (row%3);
    y = col - (col%3);
    
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            
            if(board[i+x][j+y]-'0' == num)
                return 0;
            
        }
        
    }
    
    return 1;
}

int help(char** board){
    
    int row, col;
    
    if(free1(board, &row, &col) == 0)
        return 1;
    
    
    for(int i=1; i<=9; i++) {
        
            if(safe(board,row,col,i)) {    
        
                
                board[row][col] = i+'0';
        
                if(help(board))
                    return 1;
                //backtracking
                board[row][col] = '.';
            }
        
    }//end of for for placing numbers
            return 0;

}
void solveSudoku(char** board, int boardSize, int* boardColSize){
    
        help(board);

}
