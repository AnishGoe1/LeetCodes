int minCost(char * colors, int* neededTime, int neededTimeSize){
    int ans = 0, n=strlen(colors), count = 0, rem = 0;
    for(int i=0;i<n;++i){       
        if(count >= 1 && colors[i] == colors[i-1]){
            if(neededTime[i]>rem){
                ans+=rem;
                rem = neededTime[i];
            }else{
                ans+=neededTime[i];
            }
            count++;
        }else {
            count = 1;
            rem = neededTime[i];   
        }
    }
    return ans;
}
