/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sibrahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:54:27 by sibrahim          #+#    #+#             */
/*   Updated: 2023/03/13 09:54:29 by sibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*curr;

	head_a = 0;
	if (argc >= 2)
		populate_stka(&head_a, argc, argv);
	curr = head_a;
	if (has_duplicates(&head_a))
		write(2, "Error\n", 6);
	else if (!is_sorted(&curr))
		get_sort_solution(&curr, argc);
	if (curr)
		free_stack_memory(&curr);
	return (0);
}
