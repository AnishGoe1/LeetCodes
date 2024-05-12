/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int findmax(int ** grid,int row,int column)
{
    int max = 0;
    for(int i=row;i<row+3;i++)
    {
        for(int j=column;j<column+3;j++)
        {
            if(grid[i][j]>max)
            {
                max=grid[i][j];
            }
        }
    }
    return max;

}


int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    
    * returnSize=gridSize-2;
    *returnColumnSizes=(int*)malloc(sizeof(int) * (*returnSize));



    int ** ptr=(int**)malloc(sizeof(int*)*(gridSize-2));
    for(int i=0;i<gridSize-2;i++)
    {
        ptr[i]=(int*)malloc(sizeof(int)*(gridSize-2));
        (*returnColumnSizes)[i] = *returnSize;
    }


    for(int j=0;j<gridSize-2;j++)
    {
        for(int i=0;i<gridSize-2;i++)
        {
            ptr[j][i]=findmax(grid,j,i);
            
        }
    }
    return ptr;


    
}
