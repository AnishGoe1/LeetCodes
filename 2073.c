int timeRequiredToBuy(int* tickets, int ticketsSize, int k){
    int ans = 0;

    for(int i = 0; i < ticketsSize; i++){
        if(i < k)
            ans += fmin(tickets[i], tickets[k]);
        else if(i == k)
            ans += tickets[k];
        
        else
            ans += fmin(tickets[i], tickets[k]-1);
            
    }
    
    return ans;

}
