/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deallocate_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sibrahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:53:39 by sibrahim          #+#    #+#             */
/*   Updated: 2023/03/13 09:53:41 by sibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack_memory(t_stack **stk_a)
{
	t_stack	*tmp;

	while (*stk_a)
	{
		tmp = *stk_a;
		(*stk_a) = (*stk_a)->next;
		free(tmp);
	}
}
