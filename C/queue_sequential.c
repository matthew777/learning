#include<stdio.h>
#include<stdlib.h>
#include"MYLIB/lib_of_max.h"

struct queue
{
    int items[MAXQUEUE];
    int front, rear;
}q;

void queue_init()
{
    q.front = q.rear = MAXQUEUE-1;
    return ;
}

int queue_empty(struct queue *pq)
{
    return (pq -> front == pq -> rear) ? TRUE : FALSE;
}

int queue_remove(struct queue *pq)
{
    if(queue_empty(pq) == TRUE){
        printf("Underflow !!\n");
        exit(1);
    }
    if(pq -> front == MAXQUEUE - 1){
        pq -> front = 0;
    }
    else{
        (pq -> front)++;
    }
    
    return (pq -> items[pq -> front]);
}

void queue_insert(struct queue *pq, int x)
{
    if(pq -> rear == MAXQUEUE - 1){
        pq -> rear = 0;
    }
    else{
        (pq -> rear)++;
    }
    if(pq -> front == pq -> rear){
        printf("Overflow !!\n");
        exit(1);
    }
    pq -> items[pq -> rear] = x;
    return ;
}

int main(int argc, char *argv[])
{
    int res, inc = 0;
    queue_init();
    queue_insert(&q, inc++);
    queue_insert(&q, inc++);
    queue_insert(&q, inc++);
    queue_insert(&q, inc++);
    queue_insert(&q, inc++);
    queue_insert(&q, inc++);
    queue_insert(&q, inc++);
    queue_insert(&q, inc++);
    queue_insert(&q, inc++);
    while(1)
    {
        printf("res is %d front is %d rear is %d \n",
        res = queue_remove(&q), q.front, q.rear);
    }

    return 0;
}

