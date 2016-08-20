#include <stdio.h>
#include <stdlib.h>

#define SIZE	7

int main(int argc, char *argv[])
{
    int index;
    int s[SIZE] = {2, 5, 8, 33, 19090, 0, 890};
    int max = 0;

    index = 0;
    while (index < SIZE){
        if (s[index] > 50){
            ++index;
            continue;
        } else
            printf ("The s[%d] is %d which is small than 50\n", index, s[index]);
        ++index;
    }
    
    return 0;
}
