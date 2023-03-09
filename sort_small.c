#include "push_swap.h"

void stack_sort_3(t_stack **stk)
{
    int max; 
    int min; 
    t_stack *curr; 
    
    curr = *stk; 
    min = find_min(stk);
    max = find_max(stk);
    stack_3_cases(&curr, min, max);   
}


void stack_sort_4_5(t_stack **stk_a, t_stack **stk_b)
{
    t_stack *curr; 
    int l_size; 
    int min; 
    int i; 

    l_size = list_size(stk_a); 
    while (l_size >= 4)
    {
        curr = *stk_a;
        i = 0; 
        min = find_min(stk_a); 
        i = get_curr_val_index(&curr, min);
        check_best_rotation_a_val(stk_a, i, l_size, min);
        push_to_stack(stk_a, stk_b, 'b');
		l_size--;
    }
    stack_sort_3(stk_a);
    while (list_size(stk_b) > 0)
        push_to_stack(stk_b, stk_a, 'a');
}

