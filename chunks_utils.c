#include "push_swap.h"

int	get_chunks_num(int l_size)
{
	int	chunks;

	chunks = 2;
	if (l_size <= 10)
		chunks = 2;
	else if (l_size > 10 && l_size <= 50)
		chunks = 4;
	else if (l_size > 50 && l_size <= 100)
		chunks = 5;
	else if (l_size > 100)
		chunks = 11;
	return (chunks);
}

int	find_val_stka_top(t_stack **stk_a, int *range)
{
	t_stack	*curr;
	int		i;

	i = 0;
	curr = *stk_a;
	while (curr)
	{
		if (curr->val < range[0] || curr->val > range[1])
		{
			i++;
			curr = curr->next;
		}
		else
			break ;
	}
	return (i);
}

int	find_val_stka_bottom(t_stack **stk_a, int *range)
{
	t_stack	*curr;
	int		j;

	j = 0;
	curr = *stk_a;
	while (curr->next)
		curr = curr->next;
	while (curr)
	{
		if (curr->val < range[0] || curr->val > range[1])
		{
			j++;
			curr = curr->prev;
		}
		else
			break ;
	}
	return (j);
}

t_stack	*get_curr_stka_top(t_stack **stk_a, int *range)
{
	t_stack	*curr;

	curr = *stk_a;
	while (curr)
	{
		if (curr->val < range[0] || curr->val > range[1])
		{
			curr = curr->next;
		}
		else
			break ;
	}
	return (curr);
}

t_stack	*get_curr_stka_bottom(t_stack **stk_a, int *range)
{
	t_stack	*curr;

	curr = *stk_a;
	while (curr->next)
		curr = curr->next;
	while (curr)
	{
		if (curr->val < range[0] || curr->val > range[1])
		{
			curr = curr->prev;
		}
		else
			break ;
	}
	return (curr);
}
