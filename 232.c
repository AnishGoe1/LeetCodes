typedef struct {
    int ar[100];
    int head;
    int tail;
    int cnt;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj = malloc(sizeof(MyQueue));
    obj->head = 0;
    obj->tail = 0;
    obj->cnt = 0;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    if(obj == NULL) return;
    
    obj->cnt++;
    obj->ar[obj->tail] = x;
    obj->tail = (obj->tail + 1)%100;
}

int myQueuePop(MyQueue* obj) {
    if(obj == NULL) return NULL;
    
    obj->cnt--;
    obj->head = (obj->head + 1)%100;
    return (obj->ar[(obj->head-1)%100]);
}

int myQueuePeek(MyQueue* obj) {
    if(obj == NULL) return NULL;
    
    return obj->ar[obj->head];
}

bool myQueueEmpty(MyQueue* obj) {
    if(obj == NULL) return false;
    
    return (obj->cnt?false:true);
}

void myQueueFree(MyQueue* obj) {
    if(obj == NULL) return;
    free(obj);
}
