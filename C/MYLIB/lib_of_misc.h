#ifndef _LIB_OF_MISC_H_
#define _LIB_OF_MISC_H_

void init_int_array(int A[], int head, int tail)
{
    int index = head, rand_max;

    srand((int) time(0));

    for(index; index <= tail; index++)
    {
        A[index] = 1 + (int) (10.0 * (tail - head +1) * rand() / RAND_MAX);
    }
}

#endif
