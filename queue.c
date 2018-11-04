#include "queue.h"
#include <stdlib.h>
queue *newQueue(){
    queue *new;
    if((new = (queue*)malloc(sizeof(queue))) == NULL){
        return NULL;
    }
    new->Count=0;
    new->Head = NULL;
    new->Tail = NULL;
    return new;
}

char *dequeue(queue *where){
    if(where->Count <=0){
        return NULL;
    }
    char *ret = where->Head->Directory;
    where->Head->Directory = NULL;
    queueNode *headTmp = where->Head;
    where->Head = where->Head->Next;
    if(where->Head == NULL){
        where->Tail = NULL;
    }
    headTmp->Next = NULL;
    free(headTmp);
    where->Count--;
    return ret;
}

int enqueue(char *toQueue, queue *where){
    queueNode *new;
    if((new = (queueNode*)malloc(sizeof(queueNode))) == NULL){
        return 1;
    }
    
    new->Next = NULL;
    new->Directory = toQueue;
    if(where->Head == NULL){
        where->Head = new;
        where->Tail = new;
    }
    else {
        where->Tail->Next = new;
        where->Tail = new;
    }
    new = NULL;
    where->Count++;
    return 0;
}