#include "push_swap.h"


static void check_best_rotation_b(t_stack **stk_b, int i, int l_size, int max)
{
    if (i < l_size / 2)
    {
        while((*stk_b)->val != max)
            rotate_single(stk_b, 'b');

    }
    else 
    {
        while((*stk_b)->val != max)
            rev_rotate_single(stk_b, 'b');
    }
}

static t_stack *get_curr_max_pos(t_stack **stk_b, int max)
{
    t_stack *curr;
    int i;

    i = 0;
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
    return curr;
}


void sort_stack_b(t_stack **stk_a, t_stack **stk_b)
{
    t_stack *curr; 
    int i; 
    int max;
    int l_size; 

    while(list_size(stk_b) > 0)
    {
        max = find_max(stk_b);
        curr = *stk_b;
        curr = get_curr_max_pos(stk_b, max);
        i = get_curr_val_index(stk_b, curr->val);
        l_size = list_size(stk_b);
        if (curr && l_size > 0)
        {
            check_best_rotation_b(stk_b, i, l_size, max);
            push_to_stack(stk_b, stk_a, 'a');
            l_size--;    
        }
        else
            break; 
    }
}








