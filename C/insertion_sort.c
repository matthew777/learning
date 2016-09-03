#include <stdio.h>
#include <stdlib.h>
#include "MYLIB/lib_of_print.h"
#include "MYLIB/lib_of_misc.h"
#include "MYLIB/lib_of_max.h"

void insertionsort(int x[], int size)
{
    int i, j, tmp;

    for (i=1; i<=size-1; i++)
    {
        tmp = x[i];
        for (j=i-1; j>=0 && tmp<x[j]; j--)
        {
            x[j+1] = x[j];
        }
        x[j+1] = tmp;
    }
}


int main(int argc, char *argv[])
{
    int array[MAXSIZE];
    
    init_int_array (array, 0, MAXSIZE-1);
    print_int_array (array, 0, MAXSIZE-1);
	
    getchar();

    insertionsort(array, MAXSIZE);
    print_int_array(array, 0, MAXSIZE-1);

    return 0;
}
