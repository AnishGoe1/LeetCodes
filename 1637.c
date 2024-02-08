int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b; 
}

int maxWidthOfVerticalArea(int** points, int pointsSize, int* pointsColSize)
{
    int *arr = (int*) malloc(pointsSize * sizeof(int));
    for (int i=0; i<pointsSize; i++)
    {
        arr[i] = points[i][0];
    }
    qsort(arr, pointsSize, sizeof(int), cmp);
    int max = 0, diff;
    for (int i=0; i<pointsSize - 1; i++)
    {
        diff = arr[i+1]-arr[i];
        max = (diff > max) ? diff : max; 
    }
    free(arr);
    return max;
}
 
