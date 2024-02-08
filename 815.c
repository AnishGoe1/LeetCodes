#define MAX_HASH 2999
struct linkListNode{
    int val;
    struct linkListNode* next;
};
typedef struct linkListNode lknode;
struct stopNode{
    int stop;
    lknode* bus;
    struct stopNode* next;
};
typedef struct stopNode snode;
int val2key(int val){
    return val % MAX_HASH;
}
void addBus(int stop, int bus, snode** table){
    int key = val2key(stop);
    for(snode* cur = table[key];cur!=NULL;cur=cur->next){
        if(cur->stop == stop){
            lknode* newNode = (lknode*)malloc(sizeof(lknode));
            newNode->val = bus;
            newNode->next = cur->bus;
            cur->bus = newNode;
            return;
        }
    }
    snode* newSnode = (snode*)calloc(1,sizeof(snode));
    newSnode->stop = stop;
    lknode* newNode = (lknode*)malloc(sizeof(lknode));
    newNode->val = bus;
    newNode->next = NULL;
    newSnode->bus = newNode;
    newSnode->next = table[key];
    table[key] = newSnode;
}
lknode* checkBus(int stop, snode** table){
    int key = val2key(stop);
    for(snode* cur = table[key];cur!=NULL;cur=cur->next){
        if(cur->stop == stop){
            return cur->bus;
        }
    }
    printf("Should Not Happen!!");
    return NULL;
}
int numBusesToDestination(int** routes, int routesSize, int* routesColSize, int source, int target) {
    if(source == target) return 0;
    snode** table = (snode**)calloc(MAX_HASH,sizeof(snode*));
    int stopSize = 0;
    for(int i = 0;i<routesSize;i++){
        for(int j = 0;j<routesColSize[i];j++){
            addBus(routes[i][j],i,table);
            stopSize++;
        }
    }
    bool* visitedBus = (bool*)calloc(routesSize,sizeof(bool));
    bool* targetBus = (bool*)calloc(routesSize,sizeof(bool));
    for(lknode* cur = checkBus(target,table);cur!=NULL;cur=cur->next){
        targetBus[cur->val] = true;
    }
    int* queue = (int*)malloc(sizeof(int) * routesSize);
    int qsize = 0;
    for(lknode* cur = checkBus(source,table);cur!=NULL;cur=cur->next){
        queue[qsize++] = cur->val;
        visitedBus[cur->val] = true;
    }
    int* stopQ = (int*)malloc(sizeof(int) * stopSize);
    int stopQSize = 0;
    int cnt = 1;
    bool find = false;
    while(qsize > 0){
        while(qsize > 0){
            int popBus = queue[--qsize];
            if(targetBus[popBus]){
                find = true;
                break;
            }
            for(int i = 0;i<routesColSize[popBus];i++){
                stopQ[stopQSize++] = routes[popBus][i];
            }
        }
        if(find) break;
        while(stopQSize > 0){
            int popStop = stopQ[--stopQSize];
            for(lknode* cur = checkBus(popStop,table);cur!=NULL;cur=cur->next){
                if(!visitedBus[cur->val]) queue[qsize++] = cur->val;
                visitedBus[cur->val] = true;
            }
        }
        cnt++;
    }
    free(visitedBus);
    free(targetBus);
    for(int i = 0;i<MAX_HASH;i++){
        for(snode* snCur = table[i];snCur!=NULL;){
            for(lknode* lkCur = snCur->bus;lkCur!=NULL;){
                lknode* lkTemp = lkCur;
                lkCur = lkCur->next;
                free(lkTemp);
            }
            snode* snTemp = snCur;
            snCur=snCur->next;
            free(snTemp);
        }
    }
    free(table);
    if(find) return cnt;
    return -1;
}
