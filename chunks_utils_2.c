#include "push_swap.h"

int get_curr_val_index(t_stack **stk_a, int val)
{
    t_stack *curr; 
    int i; 

    curr = *stk_a; 
    i = 0;
    while (curr)
    {
        if (curr->val != val)
        {
            i++; 
            curr = curr->next; 
        }
        else 
            break; 
    }
    return i; 
}