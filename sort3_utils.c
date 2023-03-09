#include "push_swap.h"

void stack_3_cases(t_stack **curr, int min, int max)
{
    if ((*curr)->next->val == min && (*curr)->next->next->val == max)
        swap_single(curr, 'a');
    else if((*curr)->val == max && (*curr)->next->next->val == min)
    {
        swap_single(curr, 'a');
        rev_rotate_single(curr, 'a');
    }
    else if((*curr)->val == max && (*curr)->next->val == min)
        rotate_single(curr, 'a');
    else if((*curr)->val == min && (*curr)->next->val == max)
    {
        swap_single(curr, 'a');
        rotate_single(curr, 'a');
    }
    else if((*curr)->next->val == max && (*curr)->next->next->val == min)
        rev_rotate_single(curr, 'a');
}