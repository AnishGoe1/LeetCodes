#define HTMOD 100000037

#define INITSIZE 10

typedef struct Node {
    char *food;
    char *cuisine;
    int rating;
    int pqIndex;
    struct Node *next;
} Node;

typedef struct {
    Node **arr;
    int size;
    int maxSize;
} PQ;

typedef struct cNode {
    char *cuisine;
    int index;
    struct cNode *next;
} cNode;

int hash(char *s, int htSize) {
    long long hashCode = 0;
    while (*s != '\0') {
        hashCode = (((hashCode * 127) % HTMOD) + *s) % HTMOD;
        ++s;
    }
    return hashCode % htSize;
}

void insertft(Node **ht, Node *n, int htSize) {
    int index = hash(n->food, htSize);
    n->next = ht[index];
    ht[index] = n;
}

int compare(Node *x, Node *y) {
    if (x->rating == y->rating) {
        return strcmp(x->food, y->food);
    }
    return y->rating - x->rating;
}
void bubbleDown(Node **pq, int size, int parent) {
    int child;
    Node *t;
    do {
        child = 2 * parent + 1;
        if (child >= size) {
            return;
        }
        if (child < size-1 && 
            compare(pq[child], pq[child+1]) > 0) {
            ++child;
        }
        if (compare(pq[parent], pq[child]) <= 0) {
            return;
        }
        t = pq[parent];
        pq[parent] = pq[child];
        pq[child] = t;
        pq[parent]->pqIndex = parent;
        pq[child]->pqIndex = child;
        parent = child;
    } while(1);
}
void bubbleUp(Node **pq, int child) {
    int parent;
    Node *t;
    do {
        if (child == 0) {
            return;
        }
        parent = (child - 1) / 2;
        if (compare(pq[parent], pq[child]) <= 0) {
            return;
        }
        t = pq[parent];
        pq[parent] = pq[child];
        pq[child] = t;
        pq[parent]->pqIndex = parent;
        pq[child]->pqIndex = child;
        child = parent;
    } while(1);
}

void insertpq(PQ *pq, Node *n) {
    if (pq->size >= pq->maxSize) {
        pq->maxSize *= 2;
        pq->arr = (Node**) 
             realloc(pq->arr, pq->maxSize * sizeof(Node*));
    }
    pq->arr[pq->size] = n;
    bubbleUp(pq->arr, pq->size);
    pq->size += 1;
}

void insertcn(cNode **ht, cNode *n, int htSize) {
    int index = hash(n->cuisine, htSize);
    n->next = ht[index];
    ht[index] = n;
}
int findcIndex(cNode **ht, char *cuisine, int htSize) {
    int index = hash(cuisine, htSize);
    cNode *n = ht[index];
    while (n != NULL) {
        if (!strcmp(n->cuisine, cuisine)) {
            return n->index;
        }
        n = n->next;
    }
    return -1;
}

Node *findft(Node **ht, char *food, int htSize) {
    int index = hash(food, htSize);
    Node *n = ht[index];
    while (n != NULL) {
        if (!strcmp(n->food, food)) {
            break;
        }
        n = n->next;
    }
    return n;
}

typedef struct {
    Node **ft;
    PQ **ct;
    cNode **cn;
    int htSize;
    int numCuisines;
} FoodRatings;


FoodRatings* foodRatingsCreate(char** foods, int foodsSize, char** cuisines, int cuisinesSize, int* ratings, int ratingsSize) {
    FoodRatings *obj = (FoodRatings*) malloc(sizeof(FoodRatings));
    Node *n;
    cNode *cn;
    int i, index;
    obj->numCuisines = 0;
    obj->htSize = 2 * foodsSize;
    obj->ft = (Node**) calloc(obj->htSize, sizeof(Node*));
    obj->ct = (PQ**) calloc(obj->htSize, sizeof(PQ*));
    obj->cn = (cNode**) calloc(obj->htSize, sizeof(cNode*));
    for (i = 0; i < foodsSize; ++i) {
        n = (Node*) malloc(sizeof(Node));
        n->food = foods[i];
        n->cuisine = cuisines[i];
        n->rating = ratings[i];
        insertft(obj->ft, n, obj->htSize);
        index = findcIndex(obj->cn, cuisines[i], obj->htSize);
        if (index < 0) {
            cn = (cNode*) malloc(sizeof(cNode));
            cn->cuisine = cuisines[i];
            index = obj->numCuisines++;
            cn->index = index;
            insertcn(obj->cn, cn, obj->htSize);
            obj->ct[index] = (PQ*) malloc(sizeof(PQ));
            obj->ct[index]->arr = 
                (Node**) malloc (INITSIZE * sizeof(Node*));
            obj->ct[index]->size = 0;
            obj->ct[index]->maxSize = INITSIZE;
        }
        n->pqIndex = obj->ct[index]->size;
        insertpq(obj->ct[index], n);
    }
    return obj;
}

void foodRatingsChangeRating(FoodRatings* obj, char* food, int newRating) {
    Node *n = findft(obj->ft, food, obj->htSize);
    int oldRating = n->rating;
    n->rating = newRating;
    if (oldRating == newRating) return;
    int index = findcIndex(obj->cn, n->cuisine, obj->htSize);
    if (oldRating < newRating) {
        bubbleUp(obj->ct[index]->arr, n->pqIndex);
    } else {
        bubbleDown(obj->ct[index]->arr, 
                   obj->ct[index]->size, 
                   n->pqIndex);
    }
}

char* foodRatingsHighestRated(FoodRatings* obj, char* cuisine) {
    int index = findcIndex(obj->cn, cuisine, obj->htSize);
//    printf("%d, %s\n", index, obj->ct[index]->arr[0]->food);
    return obj->ct[index]->arr[0]->food;
}

void foodRatingsFree(FoodRatings* obj) {
    free(obj);
}

/**
 * Your FoodRatings struct will be instantiated and called as such:
 * FoodRatings* obj = foodRatingsCreate(foods, foodsSize, cuisines, cuisinesSize, ratings, ratingsSize);
 * foodRatingsChangeRating(obj, food, newRating);
 
 * char* param_2 = foodRatingsHighestRated(obj, cuisine);
 
 * foodRatingsFree(obj);
*/
