#include <stdlib.h>
#include <stdio.h>
#include "MYLIB/lib_of_max.h"
#include "MYLIB/lib_of_misc.h"
#include "MYLIB/lib_of_print.h"

int comp (const void *d1, const void *d2);
typedef int (*pfunction) (const void *a, const void *b);
pfunction function_1 = comp, function_2 = comp;

int comp(const void *d1, const void *d2)
{
    int value;
    const int *data1, *data2;
    data1 = (const int *) d1;
    data2 = (const int *) d2;
    value = *data1 - *data2;

    if(value < 0)
    {
        return -1;
    }
    else if(value > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main (int argc, char *argv[])
{
    int array[MAXSIZE];
    int key = 7;
    int *px = NULL;
    
    init_int_array (array, 0, MAXSIZE -1);
    print_int_array (array, 0, MAXSIZE-1);

    getchar();
    qsort (array, MAXSIZE, sizeof (int), function_1);
    px = (int *) bsearch (&key, array, MAXSIZE, sizeof (int), function_1);

    print_int_array(array, 0, MAXSIZE -1);
    if (px == NULL)
        printf ("\nThe key: %d not found \n", key);
    else
        printf ("\nThe key position is %x\n", px);
    
    return 0;
}
