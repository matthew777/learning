#include<stdio.h>
#include<stdlib.h>
#include"MYLIB/lib_of_max.h"

struct nodetype{
    int info;
    struct nodetype *next;
};
typedef struct nodetype *NODEPTR;

NODEPTR list = NULL;

struct queue{
    NODEPTR front, rear;
};

int empty(struct queue *pq)
{
    return (pq -> front == NULL)? TRUE : FALSE;
}

NODEPTR getnode()
{
    NODEPTR q;
    q = (NODEPTR) malloc((unsigned) sizeof(struct nodetype));
    return q;
}

void freenode(NODEPTR p)
{
    free(p);
    p = NULL;
    return ;
}

void queue_insert(struct queue *pq, int x)
{
    NODEPTR q = getnode();
    q -> info = x;
    q -> next = NULL;
    if(pq -> rear == NULL){
        pq -> front = q;
    }else{
        pq -> rear -> next =q;
    }
    pq -> rear = q;
    return ;
}

void verify(NODEPTR p)
{
    NODEPTR q = p;
    int counter = 0;
    if(p == NULL){
        printf("list or queue is empty !!\n");
    }else{
        for(; q != NULL; q = q -> next, counter++){
            printf("Node info is %d \t", q -> info);
        }
        printf("\nEND\n");
    }
    printf("Number of nodes within this queue is %d\n", counter);
    return ;
}

//inline int queue_remove(struct queue *pq)
int queue_remove(struct queue *pq)
{
    NODEPTR q;
    int x;
    if(empty(pq) == TRUE){
        printf("Underflow !!\n");
        return -1;
    }
    q = pq -> front;
    x = q -> info;
    pq -> front = q -> next;
    freenode(q);
    if(pq -> front == NULL){
        pq -> rear = NULL;
    }
    return x;
}

void menu(struct queue *myqueue)
{
    char choice;
    int value, res;
    system("/usr/bin/clear");
    printf("a) Inqueue !\n");
    printf("b) Dequeue !\n");
    printf("c) Verify avail node !\n");
    printf("d) Exit !\n");
    scanf("%c", &choice);
    switch(choice){
        case 'a':
            printf("Inqueue value is ?\n");
            scanf("%d", &value);
            queue_insert(myqueue, value);
            printf("\nPress any key to continue !!\n");
            getchar(); getchar();
            break;
        case 'b':
            printf("Dequeue value is %d \n", res = queue_remove(myqueue));
            printf("Press any key to continue !!\n");
            getchar(); getchar();
            break;
        case 'c':
            list = myqueue -> front;
            verify(list);
            getchar(); getchar();
            break;
        case 'd':
            while(empty(myqueue) == FALSE){
                res = queue_remove(myqueue);
            }
            exit(0);
        default :
            break;
    }
    return ;
}

int main(int argc, char *argv[])
{
    struct queue myqueue;
    myqueue.front = myqueue.rear = NULL;
    while(1){
        menu(&myqueue);
    }
    return 0;
}
