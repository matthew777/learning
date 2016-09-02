#include<stdio.h>
#include<stdlib.h>

#define HASHTABLES_SIZE 4
#define RUN_TIMES 5

typedef struct node_t{
    int info;
    struct node_t *next;
}NODE;

NODE *getnode()
{
    NODE *p;
    if((p = calloc(1, sizeof(*p))) == NULL){
        printf("calloc failed !\n");
        exit(0);
    }
    return p;
}

void freenode(NODE *p)
{
    free(p);
    p = NULL;
    return;
}

void insafter(NODE *p, int info)
{
    NODE *q;
    q = getnode();
    q -> info = info;
    q -> next = NULL;
    p -> next = q;
    return;
}

void delafter(NODE *p, int *info)
{
    NODE *q;
    if((p == NULL) || (p -> next == NULL)){
        printf("Invalid deletion !\n");
        return;
    }
    q = p -> next;
    *info = q -> info;
    p -> next = q -> next;
    freenode(q);
    return;
}

int main(int argc, char *argv[])
{
    NODE hashtable[HASHTABLES_SIZE];
    int i = 0;
    int info = 0;
    int table_index = 0;
    NODE *node;
    for(i = 0; i < HASHTABLES_SIZE; i++){
        hashtable[i].info = -1;
        hashtable[i].next = NULL;
    }
    srand((int) time(0));
    for(i = 0; i < RUN_TIMES; i++){
        info = 1 + (int) (10.0 * 100 * rand() / RAND_MAX);
        printf("this node info is %d\n", info);
        table_index = (info % HASHTABLES_SIZE);
        if(hashtable[table_index].info == -1){
            hashtable[table_index].info = info;
        }else{
            printf("Collision!!, index is %d \n", table_index);  
            getchar();
            node = &hashtable[table_index];
            while(node -> next != NULL){
                node = node -> next;
            }
            insafter(node, info);
        }
    }
    printf("RUN_TIMES arrived, Show hashtable content, Are you ready ?\n");
    printf("Press any key !!");
    getchar();
    for(i = 0; i < HASHTABLES_SIZE; i++){
        printf("Bucket %d -> info is %d\n", i, hashtable[i].info);
        if(hashtable[i].next != NULL){
            printf("The hashtable [%d] has a linked list !!\n", i);
            node = hashtable[i].next;
            do{
                printf("node->info: %d;\t", node->info);
            }while((node = node -> next) != NULL);
        }
        printf("\nNext bucket, Are you ready? press any key");
        getchar();
    }
    return 0;
}
