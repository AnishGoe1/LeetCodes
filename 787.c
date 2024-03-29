
#define INF (INT_MAX>>2)



int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k){
    int *dist = malloc(n * sizeof(int));
    int *dist_temp = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        dist[i] = INF;
        dist_temp[i] = INF;
    }
    dist[src] = 0;
    dist_temp[src] = 0;
    while(k>=0){
        for (int i = 0; i < flightsSize; i++){
            int from = flights[i][0];
            int to = flights[i][1];
            int price = flights[i][2];

            if (dist_temp[to] > dist[from] + price){
                dist_temp[to] = dist[from] + price;
            }
        }

        memcpy(&dist[0], &dist_temp[0], n * sizeof(int));
        k--;

    }
    int ret = dist[dst];
    //free(dist);
    //free(dist_temp);
    if (ret == INF) return -1;
    return ret;
}
