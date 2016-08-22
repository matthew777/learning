#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int array[SIZE] = {5, 4, 3, 2, 1};

void call_by_value(int *p, int size)
{
    int *q = p;
    int i;
    for (i=0; i<(size -1); i++)
    {
        printf("array[%d]: %d\n", i, *q);
        q++;
    }
    p = q;
    printf("p: %x; *p: %d\n", p, *p);
}

int main(int argc, char *argv[])
{
    call_by_value(array, SIZE);
    
    printf("array: %x; *array: %d\n", array, *array);
    return 0;
}
