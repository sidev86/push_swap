#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_stack
{	
	int				val;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*get_curr_stka_top(t_stack **stk_a, int *range);
t_stack	*get_curr_stka_bottom(t_stack **stk_a, int *range);

int		find_min(t_stack **stk);
int		find_next_min(t_stack **stk_a, int curr_min);
int		find_max(t_stack **stk);
int		list_size(t_stack **stk);
int		is_sorted(t_stack **stk_a);
int		get_chunks_num(int l_size);
int		find_val_stka_top(t_stack **stk_a, int *range);
int		find_val_stka_bottom(t_stack **stk_a, int *range);
int		find_val_pos_b(t_stack **stk_b, int max);
int		get_curr_val_index(t_stack **stk_a, int val);
int		has_duplicates(t_stack **stk_a);
int		is_integer(char *str);
int		ft_atoi(char *str);

long	ft_atol(char *str);
int		*get_chunk_range(int nums[], int dist, int ch_num, int chunks);

void	populate_array(int nums[], t_stack **stk_a);
void	sort_array(int nums[], int size);
void	swap_single(t_stack **stk, char s);
void	rotate_single(t_stack **stk, char s);
void	rev_rotate_single(t_stack **stk, char s);
void	push_to_stack(t_stack **stk_o, t_stack **stk_d, char s);
void	stack_sort_3(t_stack **stk);
void	stack_sort_4_5(t_stack **stk_a, t_stack **stk_b);
void	stack_sort_big(t_stack **stk_a, t_stack **stk_b);
void	check_best_rotation_a_range(t_stack **stk_a, int i,
			int l_size, int *range);
void	check_best_rotation_a_val(t_stack **stk_a, int i, int l_size, int min);
void	sort_stack_a(t_stack **stk_a, t_stack **stk_b, int *nums);
void	sort_stack_b(t_stack **stk_a, t_stack **stk_b);
void	free_stack_memory(t_stack **stk_a);
void	populate_stka(t_stack **head_a, int argc, char **argv);
void	get_sort_solution(t_stack **curr, int argc);

#endif
