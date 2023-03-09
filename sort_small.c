#include "push_swap.h"

void stack_sort_3(t_stack **stk)
{
    int max; 
    int min; 
    t_stack *curr; 
    curr = *stk; 
    min = find_min(stk);
    max = find_max(stk);
    if (curr->next->val == min && curr->next->next->val == max)
    {
        //case 1
        swap_single(stk);
        write(1, "sa\n", 3);
    }
    else if(curr->val == max && curr->next->next->val == min)
    {
        //case 2
        swap_single(stk);
        rev_rotate_single(stk);
        write(1, "sa\n", 3);
        write(1, "rra\n", 4);
    }
    else if(curr->val == max && curr->next->val == min)
    {
        //case 3
        rotate_single(stk);
        write(1, "ra\n", 3);
    }
    else if(curr->val == min && curr->next->val == max)
    {
        //case 4
        swap_single(stk);
        rotate_single(stk);
        write(1, "sa\n", 3);
        write(1, "ra\n", 3);
    }
    else if(curr->next->val == max && curr->next->next->val == min)
    {
        //case 5
        rev_rotate_single(stk);
        write(1, "rra\n", 4);
    }
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
        while(curr->next)
		{
			if (curr->val != min)
			{
				i++;
				curr = curr->next;
			}	
			else 
				break;
		}
        if (i <= l_size / 2)
		{
			while((*stk_a)->val != min)
			{
				rotate_single(stk_a);
				write(1, "ra\n", 3);
			}		
		}
		else
		{
			while((*stk_a)->val != min)
			{
				rev_rotate_single(stk_a);
				write(1, "rra\n", 4);
			}			
		}
		push_to_stack(stk_a, stk_b);
		write(1, "pb\n", 3);
		l_size--;
    }
    stack_sort_3(stk_a);
    while (list_size(stk_b) > 0)
    {
        push_to_stack(stk_b, stk_a);
        write(1, "pa\n", 3);
    }
}

