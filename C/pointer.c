#include <stdio.h>
#include <stdlib.h>

#define N 10

int main (int argc, char *argv[])
{
    int A[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int index;
    int *pointer_to_A, *another_pointer_to_A;
    pointer_to_A = another_pointer_to_A = A;

    for(index = 0; index <= N-7; index++)
        {
            printf(" %x, %d,\n", &A[index], A[index]);
            printf(" %x, %x \n", A, pointer_to_A + index);
            printf(" %x,    \n", another_pointer_to_A++);
        }

    printf("Wait......., Press any key to continue!!");
    getchar();

    printf("Finally, the A is %x\n", A);
    printf("Finally, the pointer_to_A is %x\n", pointer_to_A);
    printf("Finally, the another_pointer_to_A is %x\n", another_pointer_to_A);
    printf("while another_pointer_to_A-- is %x\n", --another_pointer_to_A);
	
    return 0;
}

