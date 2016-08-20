#include <stdio.h>
#include <stdlib.h>

#define SIZE	7

int main(int argc, char *argv[])
{
    int index;
    int s[SIZE] = {2, 5, 8, 33, 19090, 0, 890};
    int max = 0;
	
    index = 0;
    while (1){
        if (index >= SIZE){
            break;
        }
        printf ("The s[%d] is %d \n", index, s[index++]);
    }
    
    return 0;
}
