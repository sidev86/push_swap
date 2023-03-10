/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sibrahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:54:37 by sibrahim          #+#    #+#             */
/*   Updated: 2023/03/13 09:54:38 by sibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_sort_big(t_stack **stk_a, t_stack **stk_b)
{
	int	*nums;
	int	l_size;

	l_size = list_size(stk_a);
	nums = malloc(sizeof(int) * l_size);
	populate_array(nums, stk_a);
	sort_array(nums, l_size);
	sort_stack_a(stk_a, stk_b, nums);
	sort_stack_b(stk_a, stk_b);
	free(nums);
}
