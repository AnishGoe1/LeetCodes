int lengthOfLastWord(char * s){
    int count=0, i;
    int x=strlen(s)-1;
    for(i=strlen(s)-1;i>=0;i--){
        if(s[i]!=' ')
        break;
        x=x-1;
    }
 for(i=x;i>=0;i--){
     if(s[i]==' ')
     break;
     count++;
 }
 return count;
}
