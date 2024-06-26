bool checkValidString(char * s){
    int n = strlen(s) ;
    int count = 0; 
    //from left to right
    for(int i = 0; i < n; i++){
        if(s[i] == '(' || s[i] == '*')
            count++ ;
        else{
            count-- ;
            if(count < 0)
                return false ;
        }
    }
    //from left to right
    count = 0 ;
    for(int i = n-1; i >=0 ; i--){
        if(s[i] == ')' || s[i] == '*')
            count++ ;
        else{
            count-- ;
            if(count < 0)
                return false ;
        }
    }
    return true ;
}
