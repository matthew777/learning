#include<stdio.h>
#include<stdlib.h>
#include"MYLIB/lib_of_misc.h"
#include"MYLIB/lib_of_print.h"
#include"MYLIB/lib_of_max.h"

void partition(int x[], int lb, int ub, int *pj)
{
    int a, down, temp, up;
    a = x[lb];
    up = ub;
    down = lb;
    while(down < up){
        while(x[down] <= a && down < ub)
            down++;
        while(x[up] > a)
            up--;
        if(down < up){
            temp = x[down];
            x[down] = x[up];
            x[up] = temp;
        }
    }
    x[lb] = x[up];
    x[up] = a;
    *pj = up;
}

void quicksort(int x[], int lb, int ub)
{
    int m;
    if(lb < ub){
        partition(x, lb, ub, &m);
        quicksort(x, lb, m-1);
        quicksort(x, m+1, ub);
    }
    return ;
}

int main(int argc, char *argv[])
{
    int array[MAXSIZE];
    init_int_array(array, 0, MAXSIZE-1);
    print_int_array(array, 0, MAXSIZE-1);

    getchar();
    quicksort(array, 0, MAXSIZE-1);
    print_int_array(array, 0, MAXSIZE-1);
    
    return 0;
}
