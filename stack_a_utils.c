#include "push_swap.h"

int find_next_min(t_stack **stk_a, int curr_min)
{
	t_stack *curr; 
	int min; 

	curr = *stk_a; 
	min = curr->val; 
	if (min == curr_min)
		min = curr->next->val; 
	if (curr->val > curr_min)
		min = curr->val; 
	while(curr)
	{
		if (curr->val > curr_min && curr->val < min)
			min = curr->val; 
		curr = curr->next; 
	}
	return(min); 
}

void check_best_rotation_a(t_stack **stk_a, int i, int l_size, int *range)
{
	if (i < l_size / 2)
	{
		while((*stk_a)->val < range[0] || (*stk_a)->val > range[1])
		{
			rotate_single(stk_a);
			write(1, "ra\n", 3);
		}
	}
	else 
	{
		while((*stk_a)->val < range[0] || (*stk_a)->val > range[1])
		{
			rev_rotate_single(stk_a);
			write(1, "rra\n", 4);
		}
	}
}