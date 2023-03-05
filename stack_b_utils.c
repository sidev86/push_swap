#include "push_swap.h"
void sort_stack_b(t_stack **stk_a, t_stack **stk_b)
{
    t_stack *curr; 
    int i; 
    int max;
    int l_size; 
    while(list_size(stk_b) > 0)
    {
        i = 0;
        max = find_max(stk_b);
        //printf("max valore in stack b : %d\n", max);
        curr = *stk_b;
        while(curr)
        {
            if (curr->val != max)
            {
                i++;
                curr = curr->next;
            }
            else
                break;
        }
        l_size = list_size(stk_b);
        if (curr && l_size > 0)
        {
            if (i < l_size / 2)
            {
                while((*stk_b)->val != max)
                {
                    rotate_single(stk_b);
                    printf("rb\n");
                }
            }
            else 
            {
                while((*stk_b)->val != max)
                {
                    rev_rotate_single(stk_b);
                    printf("rrb\n");
                }
            }
            push_to_stack(stk_b, stk_a);
            printf("pa\n");
            l_size--;    
        }
        else
            break; 
    }
}