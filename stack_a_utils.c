#include "push_swap.h"

int	list_size(t_stack **stk)
{
	t_stack *t;
	int size;

	size = 0;
	t = *stk;
	while (t)
	{
		size++;
		t = t->next;
	}
	//printf("dimensione listozza = %d\n", size);
	return (size);
}

int find_min(t_stack **stk)
{
	t_stack *t;
	int		min;

	t = *stk;
	min = t->val;
	while(t)
	{
		if(t->val < min)
			min = t->val;
		t = t->next;
	}
	//printf("valore minimo stack: %d\n", min);
	return(min);
}

int find_max(t_stack **stk)
{
	t_stack *t;
	int		max;

	t = *stk;
	max = t->val;
	while(t)
	{
		if(t->val > max)
			max = t->val;
		t = t->next;
	}
	//printf("valore massimo stack: %d\n", max);
	return(max);
}


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

void check_best_rotation_a(int i, int l_size, int *range, t_stack **stk_a)
{
	if (i < l_size / 2)
	{
		while((*stk_a)->val < range[0] || (*stk_a)->val > range[1])
		{
			rotate_single(stk_a);
			printf("ra\n");
		}
	}
	else 
	{
		while((*stk_a)->val < range[0] || (*stk_a)->val > range[1])
		{
			rev_rotate_single(stk_a);
			printf("rra\n");
		}
	}
}