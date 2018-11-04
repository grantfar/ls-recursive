#include <sys/types.h>
#include <dirent.h>
#ifndef queueDef
#define queueDef

typedef struct queueNode{
    struct queueNode *Next;
    char * Directory;
} queueNode;

typedef struct queue{
    queueNode *Head;
    queueNode *Tail;
    int Count;
} queue;

int enqueue(char *toQueue, queue *where);
char *dequeue(queue *where);
queue *newQueue();
#endif