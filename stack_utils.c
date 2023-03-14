/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sibrahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:55:27 by sibrahim          #+#    #+#             */
/*   Updated: 2023/03/13 09:55:28 by sibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_size(t_stack **stk)
{
	t_stack		*t;
	int			size;

	size = 0;
	t = *stk;
	while (t)
	{
		size++;
		t = t->next;
	}
	return (size);
}

int	find_min(t_stack **stk)
{
	t_stack		*t;
	int			min;

	t = *stk;
	min = t->val;
	while (t)
	{
		if (t->val < min)
			min = t->val;
		t = t->next;
	}
	return (min);
}

int	find_max(t_stack **stk)
{
	t_stack		*t;
	int			max;

	t = *stk;
	max = t->val;
	while (t)
	{
		if (t->val > max)
			max = t->val;
		t = t->next;
	}
	return (max);
}

void	get_sort_solution(t_stack **curr, int argc)
{
	t_stack		*head_b;

	head_b = 0;
	if (argc == 3)
	{
		if ((*curr)->val > (*curr)->next->val)
			swap_single(curr, 'a');
	}
	else if (argc == 4)
		stack_sort_3(curr);
	else if (argc == 5 || argc == 6)
		stack_sort_4_5(curr, &head_b);
	else if (argc > 6)
		stack_sort_big(curr, &head_b);
}
