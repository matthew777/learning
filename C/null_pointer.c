#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 5;
    int *ptr = NULL;
    //int *ptr = &i;
    
    printf("i = %d\n", i);

    if(!ptr)
        printf("p = %x\n", ptr);

    return 0;
}
