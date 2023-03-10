#include "push_swap.h"

static void	find_values_in_chunk(t_stack **stk_a, t_stack **stk_b, int *range)
{
	t_stack	*curr;
	int		i;
	int		l_size;

	l_size = list_size(stk_a);
	curr = *stk_a;
	while (curr != NULL && l_size > 0)
	{
		if (find_val_stka_top(stk_a, range)
			<= find_val_stka_bottom(stk_a, range))
			curr = get_curr_stka_top(stk_a, range);
		else
			curr = get_curr_stka_bottom(stk_a, range);
		if (curr)
			i = get_curr_val_index(stk_a, curr->val);
		if (curr && l_size > 0)
		{
			check_best_rotation_a_range(stk_a, i, l_size, range);
			push_to_stack(stk_a, stk_b, 'b');
			l_size--;
		}
		else
			break ;
	}
}

static void	move_chunks_to_stackb(int chunks, int *nums,
t_stack **stk_a, t_stack **stk_b)
{
	int	*range;
	int	ch_num;
	int	l;

	ch_num = 1;
	l = list_size(stk_a);
	while (ch_num <= chunks)
	{
		range = get_chunk_range(nums, l, ch_num, chunks);
		find_values_in_chunk(stk_a, stk_b, range);
		ch_num++;
	}
}

void	sort_stack_a(t_stack **stk_a, t_stack **stk_b, int *nums)
{
	int	chunks;

	chunks = get_chunks_num(list_size(stk_a));
	move_chunks_to_stackb(chunks, nums, stk_a, stk_b);
}
