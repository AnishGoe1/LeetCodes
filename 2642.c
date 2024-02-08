
typedef struct {
    int node;
    int weight;
} Edge;

typedef struct {
    Edge* edges;
    int* nodeCount;
    int n;
} Graph;


Graph* graphCreate(int n, int** edges, int edgesSize, int* edgesColSize) {
    Edge* nodes = calloc(sizeof(Edge), n * n);
    int* nodeCount = calloc(sizeof(int), n);

    for (int i = 0; i < edgesSize; ++i) {
        int ins = nodeCount[edges[i][0]];
        nodes[edges[i][0] * n + ins].node = edges[i][1];
        nodes[edges[i][0] * n + ins].weight = edges[i][2];
        ++nodeCount[edges[i][0]];
    }

    Graph* g = malloc(sizeof(Graph));
    g->edges = nodes;
    g->nodeCount = nodeCount;
    g->n = n;
    return g;
}

void graphAddEdge(Graph* obj, int* edge, int edgeSize) {
    obj->edges[edge[0] * obj->n + obj->nodeCount[edge[0]]].node = edge[1];
    obj->edges[edge[0] * obj->n + obj->nodeCount[edge[0]]].weight = edge[2];
    obj->nodeCount[edge[0]] += 1;
}

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int graphShortestPath(Graph* obj, int node1, int node2) {
    int n = obj->n;
    int* dist = calloc(sizeof(int), n);
    for (int i = 0; i < n; ++i) {
        dist[i] = INT_MAX;
    }

    dist[node1] = 0;

    for (int i = 0; i < n; ++i) {
        int node = -1;
        int d = INT_MAX;

        for (int j = 0; j < n; ++j) {
            if (-1 < dist[j] && dist[j] < d) {
                node = j;
                d = dist[j];
            }
        }

        if (node == -1) {
            return -1;
        }

        if (node == node2) {
            return d;
        }

        Edge* edge = &obj->edges[node * n];
        int c = obj->nodeCount[node];
        dist[node] = -1;
        for (int i = 0; i < c; ++i) {
            dist[edge->node] = min(d + edge->weight, dist[edge->node]);
            ++edge;
        }
    }

    return -1;
}

void graphFree(Graph* obj) {
    free(obj->edges);
    free(obj->nodeCount);
    free(obj);
}

/**
 * Your Graph struct will be instantiated and called as such:
 * Graph* obj = graphCreate(n, edges, edgesSize, edgesColSize);
 * graphAddEdge(obj, edge, edgeSize);
 
 * int param_2 = graphShortestPath(obj, node1, node2);
 
 * graphFree(obj);
*/
