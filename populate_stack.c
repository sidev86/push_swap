#include "push_swap.h"

static void	first_node(t_stack **head_a, t_stack **tail_a, char *arg)
{
	*head_a = malloc(sizeof(t_stack));
	if (*head_a == NULL)
		exit(1);
	*tail_a = *head_a;
	if (is_integer(arg))
	{
		(*head_a)->val = ft_atoi(arg);
		(*head_a)->next = NULL;
		(*head_a)->prev = NULL;
	}
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

static void	next_node(t_stack **tail_a, char *arg)
{
	t_stack		*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		exit(1);
	if (is_integer(arg))
	{
		new_node->val = ft_atoi(arg);
		new_node->prev = *tail_a;
		new_node->next = NULL;
		new_node->prev->next = new_node;
		*tail_a = new_node;
	}
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}		
}

void	populate_stka(t_stack **head_a, int argc, char **argv)
{
	t_stack		*tail_a;
	int			i;

	i = 1;
	while (i < argc)
	{
		if (i == 1)
			first_node(head_a, &tail_a, argv[1]);
		else
			next_node(&tail_a, argv[i]);
		i++;
	}
}
