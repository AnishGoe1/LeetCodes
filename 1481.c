int compare(const void *a, const void *b) //qsort need compare
{
int c = *(int *)a;
int d = *(int *)b;
if(c < d) {return -1;}
else if (c == d) {return 0;}
else return 1;
}

int findLeastNumOfUniqueInts(int* arr, int arrSize, int k){
int i,arr_temp[100000],count = 0,answer;
memset(arr_temp,0,sizeof(arr_temp));
qsort(arr,arrSize,sizeof(int),compare);

arr_temp[count]++;
for(i = 1; i < arrSize; i++)
{
    if(arr[i] != 0)
    {
        if(arr[i-1] == arr[i])
        {
            arr_temp[count]++;
        }
        else
        {
            count++;
            arr_temp[count]++;
        }
    }
}

int arr_temp1[count+1];

for(i = 0; i <= count; i++)
{
    arr_temp1[i] = arr_temp[i];
}

qsort(arr_temp1,count+1,sizeof(int),compare);
    
answer = count+1;

for(i = 0; i <= count; i++)
{
    if(k - arr_temp1[i] >= 0)
    {
        k -= arr_temp1[i];
        answer -- ;
    }
}
return answer;
}
