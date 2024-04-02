bool isIsomorphic(char * s, char * t){
char a[1000]={0};
char b[1000]={0};
int i=0;
while(s[i]!='\0'){
    if(a[s[i]]=='\0' && b[t[i]]=='\0'){
        a[s[i]]=t[i];
        b[t[i]]=s[i];
    }
    else if(a[s[i]]!=t[i] || b[t[i]]!=s[i]){
        return false;
    }
    i++;
}
return true;
}
