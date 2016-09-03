#include <stdio.h>
#include <stdlib.h>

#define SIZE	7

int main(int argc, char *argv[])
{
    int index;
    int s[SIZE] = {2, 5, 8, 33, 19090, 0, 890};
    int max = 0;
	
    for (index = 0; index < SIZE; index++){
        if (s[index] > max)
            max = s[index];
    }	

    printf("The max is %d \n", max);
    
    return 0;
}
