// sort last item
int cmpfunc( const void* p1,  const void* p2){
   int* arr1 = *(int**)p1;
   int* arr2 = *(int**)p2;
  if(arr1[2] == arr2[2]) 
      return arr1[1] - arr2[1]; 
  return arr1[2] - arr2[2];
}

//sort string
int cmpStr(const void* a, const void* b){
    return *(char*)a - *(char*)b;
}

unsigned int RSHash(char *str)
{
	unsigned int b = 378551;
	unsigned int a = 63689;
	unsigned int hash = 0;

	while (*str)
	{
		hash = hash * a + (*str++);
		a *= b;
	}

	return (hash & 0x7FFFFFFF);
}

//string sort first, then use RSHash
int hash(char* s){
    int len = strlen(s);
    char* temp = malloc((len+1) * sizeof(char));
    strcpy(temp, s);
    qsort(temp, len, sizeof(char), cmpStr);
    int ans = RSHash(temp);
    free(temp);
    return ans;
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    int i, j;
    int** lenTable = malloc(strsSize * sizeof(int*)); 
    
    for(i = 0; i  < strsSize; i++){
        lenTable[i] = malloc(3 * sizeof(int));
        lenTable[i][0] = i;
        lenTable[i][1] = strlen(strs[i]);
        lenTable[i][2] = hash(strs[i]);
    }
    
    qsort(lenTable, strsSize, sizeof(int*), cmpfunc);
    int l = lenTable[0][1];
    int cn = 1;
    char*** ans = malloc(10000 * sizeof(char**));
    *returnColumnSizes = malloc(10000 * sizeof(int));
    int idx = 0;
    for(i = 1; i < strsSize; i++){
        if(lenTable[i][2] == lenTable[i-1][2]){
            cn++;
        }
        else{
            l = lenTable[i-1][1];
            ans[idx] = malloc(cn * sizeof(char*));
            returnColumnSizes[0][idx] = cn;
            for(j = 0; j < cn; j++){
                ans[idx][j] = malloc((l+1) * sizeof(char));
                //ans[idx][j][l] = '\0';
                strcpy(ans[idx][j], strs[lenTable[i-1-j][0]]);  
            }
            idx++;
            cn = 1;
        }
    }
    ans[idx] = malloc(cn * sizeof(char*));
    l = lenTable[i-1][1];
    returnColumnSizes[0][idx] = cn;
    for(j = 0; j < cn; j++){
        ans[idx][j] = malloc((l+1) * sizeof(char));
        //ans[idx][j][l] = '\0';
        strcpy(ans[idx][j], strs[lenTable[i-1-j][0]]);  
    }
    idx++;
    * returnSize = idx;
    *returnColumnSizes = realloc(*returnColumnSizes, idx*sizeof(int)) ;
    ans = realloc(ans, idx * sizeof(char**));
    return ans;
}
