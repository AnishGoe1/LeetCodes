typedef struct node{
    int x;
    int y;
    struct node* next;
}node;

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    node *head = NULL;
    for(int i=0;i<matrixSize;i++)
    {
        for(int j=0;j<*matrixColSize;j++)
        {
            if(!matrix[i][j])
            {
                    node *N = malloc(sizeof(struct node));
                    N->x = i;
                    N->y = j;
                    N->next = head ;
                    head = N; 
            }
        }
    }
    while(head)
    {
        int i;
        for(i=0;i<*matrixColSize;i++)
            matrix[head->x][i] = 0;
        
        for(i=0;i<matrixSize;i++)
            matrix[i][head->y] = 0;
        
        head = head->next;
    }
}
