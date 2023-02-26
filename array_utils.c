#include "push_swap.h"

void populate_array(int nums[], t_stack **stk_a)
{
    t_stack *curr;
    int i; 

    i = 0; 
    curr = *stk_a; 
    while (curr)
    {
        nums[i]= curr->val;
        curr = curr->next; 
        i++;
    }
}

void sort_array(int nums[], int size)
{
    int i; 
    int k; 
    int temp; 

    i = 0; 
    k = 0; 
    while (i < size - 1)
    {
        while (k < size - 1 - i)
        {
            if (nums[k] > nums[k+1])
            {
                temp = nums[k];
                nums[k] = nums[k+1]; 
                nums[k+1] = temp; 
            }
            k++;
        }
        k = 0; 
        i++; 
    }
}

int array_size(int *nums)
{
    int size; 

    size = 0; 
    while (*nums)
    {
        size++; 
        nums++; 
    }
    return(size); 
}

int *get_chunk_range(int nums[], int dist, int ch_num, int chunks)
{
    static int index;
    static int range[2];
    int dim; 

    dim = array_size(nums); 
    printf("dimensione array = %d\n", dim); 
    range[0] = nums[index];
    if (ch_num != chunks)
        range[1] = nums[index + dist];
    else 
        range[1] = nums[dim - 1];
    index += dist + 1; 
    return(range);
}



