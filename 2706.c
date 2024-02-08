int buyChoco(int* prices, int pricesSize, int money){
    int smallest = INT_MAX, second_smallest = 0;
    for(int i=0; i<pricesSize; i++){
        if(smallest > prices[i]){
            second_smallest = smallest;
            smallest = prices[i];
        }
        else if(second_smallest > prices[i] || second_smallest == INT_MAX){
            second_smallest = prices[i];
        }
    }
    if(smallest + second_smallest <= money)
        return (money - (smallest + second_smallest));
    return money;
}
