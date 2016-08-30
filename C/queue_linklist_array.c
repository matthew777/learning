#include<stdio.h>
#include<stdlib.h>
#include"MYLIB/lib_of_max.h"

struct nodetype{
    int info;
    int next;
};
struct nodetype node[NUMNODES];

int avail;

struct queue{
    int front, rear;
};
struct queue myqueue;

int empty(struct queue *pq)
{
    return (pq -> front == -1) ? TRUE : FALSE;
}

int getnode()
{
    int p;
    if(avail == -1){
        printf("Overflow !!\n");
        exit(1);
    }
    p = avail;
    avail = node[avail].next;
    return p;
}

void freenode(int p)
{
    node[p].next = avail;
    avail = p;
    return ;
}

void queue_insert(struct queue *myqueue, int x)
{
    int p = getnode();
    node[p].info = x;
    node[p].next = -1;
    if(myqueue -> rear == -1){
        myqueue -> front = p;
    }else{
        node[myqueue -> rear].next = p;
    }
    myqueue -> rear = p;
    return ;
}

int queue_remove(struct queue *myqueue)
{
    int p = myqueue -> front;
    int x;
    if(p == -1){
        printf("Underflow !!\n");
        exit(1);
    }
    x = node[p].info;
    myqueue -> front = node[p].next;
    if(myqueue -> front == -1){
        myqueue -> rear = -1;
    }
    freenode(p);
    return x;
}

void avail_init()
{
    int i = 0;
    avail = 0;
    for(; i < NUMNODES-1; i++){
        node[i].info = -1;
        node[i].next = i+1;
    }
    node[NUMNODES-1].info = -1;
    node[NUMNODES-1].next = -1;
}

void verify(int myqueue)
{
    int i = myqueue;
    if(i == -1){
        printf("queue is empty !!\n");
        return ;
    }
    for(; i != -1; i = node[i].next){
        printf("The node info is %d node index is %d\n",
                node[i].info, i);
    }
    return ;
}

void menu()
{
    char choice;
    int info;
    int value;
    system("/usr/bin/clear");
    printf("a) Inqueue \n");
    printf("b) Dequeue \n");
    printf("c) Verify \n");
    printf("d) Exit \n");
    scanf("%c", &choice);
    switch(choice){
        case 'a':
            printf("info is ? \n");
            scanf("%d", &info);
            queue_insert(&myqueue, info);
            getchar(); getchar();
            break;
        case 'b':
            printf("dequeue info is %d\n", value = queue_remove(&myqueue));
            getchar(); getchar();
            break;
        case 'c':
            verify(myqueue.front);
            getchar(); getchar();
            break;
        case 'd':
            exit(0);
        default:
            break;
    }
    return ;
}

int main(int argc, char *argv[])
{
    avail_init();
    myqueue.rear = myqueue.front = -1;
    while(1)
        menu();
    return 0;
}
