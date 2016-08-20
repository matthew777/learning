#include <stdio.h>
#include <stdlib.h>

#define SIZE	7

int main(int argc, char *argv[])
{
    int index;
    int s[SIZE] = {2, 5, 8, 33, 19090, 0, 890};
    int max = 0;
	
    index = 0;
    if (index < SIZE){
        do {
            printf ("The s[%d] is %d \n", index, s[index]);
        } while (++index < SIZE);
    }

    return 0;
}
