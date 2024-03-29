typedef unsigned char  uint8_t ;
void DFS(uint8_t** data, uint8_t* len, uint8_t* cur , int pos , int n , int* ans, int length){
    if(pos == n){
        *ans = fmax( *ans , length ) ;
        return ;
    }   
    
    DFS(data, len, cur, pos+1, n, ans, length) ;
    bool pass = true ;
    for(int i = 0; i < 26 ;i++){
        cur[i] += data[pos][i] ;
        if(cur[i] > 1){
            pass = false ;
        }
    }
    if(pass)
       DFS(data, len, cur, pos+1, n, ans, length + len[pos] ) ; 
    for(int i = 0; i < 26 ;i++){
        cur[i] -= data[pos][i] ;
    }
}

int maxLength(char ** arr, int arrSize){
    uint8_t** data = malloc(arrSize * sizeof(uint8_t*) ) ;
    uint8_t* len = malloc(arrSize * sizeof(uint8_t) ) ;
    uint8_t cn = 0 ;
    for(uint8_t i = 0; i < arrSize; i++){
         data[i] = calloc(26 , sizeof(uint8_t) ) ;
    }
    data[cn] = calloc(26 , sizeof(uint8_t) ) ;
    int ans = 0 ;    
    for(int i = 0; i < arrSize; i++){  
        uint8_t l = strlen( arr[i] ) ;
        for(int j = 0; j < l ; j++){
            data[cn][arr[i][j] -'a']++ ;            
            if(data[cn][arr[i][j] -'a'] > 1){             
                memset(data[cn], 0, 26 * sizeof(uint8_t) ) ;                
                break ;
            }
            if(j == (l - 1) ){
                ans = fmax( ans, l ) ;
                len[cn] = l ;
                cn++ ;
            }
        }
    }
    
    uint8_t* cur = calloc(26, sizeof(uint8_t) ) ;
    if(cn > 1){
        DFS(data, len, cur, 0, cn, &ans, 0) ; 
    }
    free(cur) ;
    free(len) ;
    return ans ;
}
