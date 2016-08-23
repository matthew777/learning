#include <stdio.h>
#include <stdlib.h>

#define NUMNODES 10
#define TRUE 1
#define FALSE 0

struct NODETYPE{
    int info;
    int next;
};

struct NODETYPE list[NUMNODES];

int avail;
int info;

void init_list()
{
    int i = 0;
    avail = 0;
    for (i; i<NUMNODES-1; i++)
    {
        list[i].next = i+1;
    }
    list[i].next = -1;
}

int list_empty()
{
    return (avail == -1) ? TRUE : FALSE;
}

int getnode()
{
    int p;
    if (list_empty() == TRUE){
        printf("Overflow !!\n");
        exit(1);
    }
    else{
        p = avail;
        avail = list[avail].next;
        return p;
    }
}

void freenode(int p)
{
    list[p].next = avail;
    avail = p;
}

void insafter(int p, int x)
{
    int q;
    if(p == -1){
        printf("void insertion\n");
        exit(1);
    }
    q = getnode();
    list[q].info = x;
    list[q].next = list[p].next;
    list[p].next = q;
}

void delafter(int p, int *info)
{
    int q;
    if(p == -1 || list[p].next == -1){
        printf("Underflow !!\n");
        exit(1);
    }
    else{
        q = list[p].next;
        *info = list[q].info;
        list[p].next = list[q].next;
        freenode(q);
    }
}

int main(int argc, char *argv[])
{
    int i = 0;
    init_list();
    for(i; i<NUMNODES; i++){
        printf("node is %d which next is %d \n", i, list[i].next);
    }

    for(i=0; i<=NUMNODES; i++){
        printf("node is %d avail is %d\n", getnode(), avail);
    }
}











































