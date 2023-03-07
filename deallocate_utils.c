#include "push_swap.h"


void free_stack_memory(t_stack **stk_a)
{
    t_stack *tmp;

    while (*stk_a)
    {
        tmp = *stk_a;
        (*stk_a) = (*stk_a)->next;
        free(tmp);
    }
}

