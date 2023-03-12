#include "push_swap.h"

static int	get_size_list(t_stack *stk)
{
	t_stack		*t;
	int			size;

	size = 0;
	t = stk;
	while (t)
	{
		size++;
		t = t->next;
	}
	return (size);
}

static int	execute_instruction(char *cmd, t_stack **stk_a, t_stack **stk_b)
{
	if (!ft_strncmp(cmd, "ra", 2))
		rotate_single(stk_a, 'x');
	else if (!ft_strncmp(cmd, "rb", 2))
		rotate_single(stk_b, 'x');
	else if (!ft_strncmp(cmd, "rra", 3))
		rev_rotate_single(stk_a, 'x');
	else if (!ft_strncmp(cmd, "rrb", 3))
		rev_rotate_single(stk_b, 'x');
	else if (!ft_strncmp(cmd, "sa", 2))
		swap_single(stk_a, 'x');
	else if (!ft_strncmp(cmd, "sb", 2))
		swap_single(stk_b, 'x');
	else if (!ft_strncmp(cmd, "pa", 2))
		push_to_stack(stk_b, stk_a, 'x');
	else if (!ft_strncmp(cmd, "pb", 2))
		push_to_stack(stk_a, stk_b, 'x');
	else
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

static int	read_instruction(char *cmd, t_stack **stk_a, t_stack **stk_b)
{
	int	len;

	len = ft_strlen(cmd);
	if (len < 3 || len > 4)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	cmd[len - 1] = 0;
	len = ft_strlen(cmd);
	if (!execute_instruction(cmd, stk_a, stk_b))
		return (0);
	return (1);
}

static void	read_and_execute(t_stack **stk_a)
{
	t_stack		*stk_b;
	char		*cmd;
	static char	*str;

	stk_b = 0;
	while (1)
	{
		cmd = get_next_line(&str);
		if (!cmd || !ft_strlen(cmd))
		{
			free(cmd);
			break ;
		}
		if (!read_instruction(cmd, stk_a, &stk_b))
		{
			free(cmd);
			return ;
		}
		free(cmd);
	}
	if (is_sorted(stk_a) && get_size_list(stk_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*stk_a;

	stk_a = 0;
	if (argc >= 2)
	{
		populate_stka(&stk_a, argc, argv);
		if (has_duplicates(&stk_a))
			write(2, "Error\n", 6);
		else
			read_and_execute(&stk_a);
		if (stk_a)
			free_stack_memory(&stk_a);
	}
	return (0);
}
