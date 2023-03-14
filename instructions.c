/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sibrahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:54:12 by sibrahim          #+#    #+#             */
/*   Updated: 2023/03/13 09:54:13 by sibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_single(t_stack **stk, char s)
{
	t_stack		*t;
	int			tmp;

	t = *stk;
	if (t->next != NULL)
	{
		tmp = t->val;
		t->val = t->next->val;
		t->next->val = tmp;
	}
	if (s == 'a')
		write(1, "sa\n", 3);
	else if (s == 'b')
		write(1, "sb\n", 3);
}

void	rotate_single(t_stack **stk, char s)
{
	t_stack		*t;

	t = *stk;
	if (t->next != NULL)
	{
		while (t->next)
			t = t->next;
		t->next = *stk;
		t->next->prev = t;
		*stk = (*stk)->next;
		t->next->next = 0;
		(*stk)->prev = 0;
	}
	if (s == 'a')
		write(1, "ra\n", 3);
	else if (s == 'b')
		write(1, "rb\n", 3);
}

void	rev_rotate_single(t_stack **stk, char s)
{
	t_stack		*t;
	t_stack		*l;

	l = *stk;
	t = *stk;
	if (t->next)
	{
		while (l->next)
		{
			t = l;
			l = l->next;
		}
		t->next = 0;
		l->next = *stk;
		*stk = l;
		(*stk)->prev = 0;
		(*stk)->next->prev = *stk;
	}
	if (s == 'a')
		write(1, "rra\n", 4);
	else if (s == 'b')
		write(1, "rrb\n", 4);
}

void	push_to_stack(t_stack **stk_o, t_stack **stk_d, char s)
{
	t_stack		*tmp;

	tmp = *stk_o;
	if (tmp->next)
	{
		*stk_o = (*stk_o)->next;
		(*stk_o)->prev = NULL;
	}
	else
	{
		(*stk_o) = NULL;
	}
	tmp->next = *stk_d;
	*stk_d = tmp;
	if (tmp->next)
		tmp->next->prev = tmp;
	tmp->prev = NULL;
	if (s == 'a')
		write(1, "pa\n", 3);
	else if (s == 'b')
		write(1, "pb\n", 3);
}
