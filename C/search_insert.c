#include<stdio.h>
#include<stdlib.h>
#include"MYLIB/lib_of_max.h"

struct nodetype{
    int info;
    struct nodetype *next;
};
typedef struct nodetype *NODEPTR;

NODEPTR list_a;

NODEPTR getnode()
{
    return (NODEPTR) malloc(sizeof(struct nodetype));
}

void freenode(NODEPTR p)
{
    free(p);
    p = NULL;
}

void verify_list(NODEPTR p)
{
    NODEPTR list = p;
    printf("list head at %x / list head info: %d\n", list, list->info);
    p = p -> next;
    while(p != NULL){
        printf("node is %x info is %d next is %x \n",
                p, p -> info, p -> next);
        p = p -> next;
    }
    return ;
}

void insafter(NODEPTR p, int x)
{
    NODEPTR q;
    if(p == NULL){
        printf("Void insertion !!\n");
        exit(1) ;
    }
    q = getnode();
    q -> info = x;
    q -> next = p -> next;
    p -> next = q;
    return ;
}

void delafter(NODEPTR p, int *px)
{
    if((p == NULL) || (p -> next == NULL)){
        printf("Void deletion !!\n");
        return ;
    }
    NODEPTR q = p -> next;
    *px = q -> info;
    p -> next = q -> next;
    free(q);
    return ;
}

NODEPTR list_create(int size)
{
    NODEPTR p, list;
    int i;
    p = list = getnode();
    p -> info = 0;
    p -> next = NULL;
    for(i = 0; i < size-1; i++){
        insafter(p, 0);
        p = p -> next;
    }
    p -> next = NULL;
    return list;
}

NODEPTR search_and_insert(NODEPTR list, int target)
{
    NODEPTR retval;
    NODEPTR i;
    if(!list)
    {
        printf("list is empty\n");
        retval = NULL;
        goto exit;
    }
    else
        i = list -> next;
    while( i != NULL)
    {
        if(i -> info == target)
        {
            retval = i;
            goto exit;
        }
        i = i->next;
    }
    insafter(list, target);
    retval = list -> next;

exit:
    return retval;
}

int main(int argc, char *argv[])
{
    int px;
    list_a = list_create(1);
    list_a->info = 001;
    insafter(list_a, 1);
    insafter(list_a, 2);
    insafter(list_a, 3);
    insafter(list_a, 4);
    verify_list(list_a);
    printf("Target at %x\n", search_and_insert(list_a, 777));
    verify_list(list_a);
    
    return 0;
}

