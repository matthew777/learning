#include<stdio.h>
#include<stdlib.h>
#include "MYLIB/lib_of_max.h"

struct nodetype{
    int info;
    int next;
};

struct nodetype node[NUMNODES];

int avail;
int px;
int list_a;
int list_b;

void list_init()
{
    int i;
    avail = 0;
    for(i = 0; i < NUMNODES-1; i++){
        node[i].next = i+1;
    }
    node[NUMNODES-1].next = -1;
    return ;
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

void insafter(int p, int x)
{
    int q;
    if(p == -1){
        printf("Void insertion !!\n");
        return ;
    }
    q = getnode();
    node[q].info = x;
    node[q].next = node[p].next;
    node[p].next = q;
    return ;
}

void delafter(int p, int *px)
{
    int q;
    if((p == -1) || (node[p].next == -1)){
        printf("Void deletion !!\n");
        return ;
    }
    q = node[p].next;
    *px = node[q].info;
    node[p].next = node[q].next;
    freenode(q);
    return ;
}

int list_create(int size)
{
    int i;
    int p, list;
    p = list = getnode();
    node[p].info = 0;
    for(i = 0; i < size-1; i++){
        insafter(p,0);
        p = node[p].next;
    }
    node[p].next = -1;
    return list;
}

void verify_list(int list)
{
    int p = list;
    printf("list heade is %d \n",list);
    printf("which node is ==>");
    while(p != -1){
        printf("%d \t",p);
        p = node[p].next;
    }
    printf("\n");
    return ;
}

int main(int argc, char *argv[])
{
    list_init();
    list_a = list_create(3);
    list_b = list_create(5);
    verify_list(list_a);
    verify_list(list_b);
    verify_list(avail);

    insafter(list_a, 77);
    delafter(list_a, &px);
    verify_list(list_a);
    verify_list(avail);

    return 0;
}
