#ifndef _LIB_OF_PRINT_H_
#define _LIB_OF_PRINT_H_

void print_duration(int unsorted_time, int sorted_time)
{
    fprintf(stdout, "\nDuration time is %d !!\n\n",
            sorted_time - unsorted_time);
}

void print_int_array(int array[], int head, int tail)
{
    int index = head;
    for (index; index <= tail; index++)
    {
        fprintf(stdout, "Array[%d] is %d\n", index, array[index]);
    }
}

#endif
