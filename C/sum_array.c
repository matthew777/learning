#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int A[SIZE] = {1,2,3,4,40};

int sum(int index);

int main()
{
    printf("The sum of array is %d\n", sum(0));
    
    return 0;
}

int sum(int index)
{
    int b;
    if(index >= SIZE)
        return 0;
    else{
        //return (b = A[index] + sum(index+1));
        b = A[index] + sum(index+1);
        printf("b = %d\n",b);
        
	return b;
    }

    return -1;
}
