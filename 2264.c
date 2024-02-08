#pragma GCC optimize("O3", "unroll-loops")
char* largestGoodInteger(char* num) {
    int count=1;
    char prev=num[0], maxd=' ';
    for (register int i=1; num[i]!='\0'; i++){
        char c=num[i];
        if (c==prev) count++;
        else count=1;
        if (count==3 && c>maxd)
            maxd=c;
        prev=c;
    }
    if (maxd==' ') return "";
    char* ans=malloc(4);
    memset(ans, maxd, 3);
    ans[3]='\0';
    return ans;
}




char* largestGoodInteger(char* num) {
  int len =strlen(num), i=0, count =0, number = -1, number_index= -1;
  while(i<len-2)
  {
    int j = i+1;
    count=0;
    while(j<len && count<2 && num[i]==num[j])
    {
      
      count++;
      j++;
    }
    if(count==2)
    {
      if(num[i]>number)
      {
        number = num[i];
        number_index= i;
      }
    }  
    i++;
  }

  if(number!=-1)
    num[number_index+3] = NULL;
  return (number!=-1) ? num+number_index : "";
}
