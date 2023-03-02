#include <stdio.h> 
#include <stdlib.h> 
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_stack
{	
	int		val; 
	struct s_stack	*next; 
	struct s_stack	*prev; 
}		t_stack;

void swap_single(t_stack **stk);
void stack_sort_3(t_stack **stk);
void rotate_single(t_stack **stk);
void rev_rotate_single(t_stack **stk);
void push_to_stack(t_stack **stk_o, t_stack **stk_d);
void stack_sort_4_5(t_stack **stk_a, t_stack **stk_b);
void stack_sort_big(t_stack **stk_a, t_stack **stk_b);
int find_min(t_stack **stk);
int find_next_min(t_stack **stk_a, int curr_min);
int find_max(t_stack **stk);
int	list_size(t_stack **stk);
void populate_array(int nums[], t_stack **stk_a);
void sort_array(int nums[], int size);
int *get_chunk_range(int nums[], int dist, int ch_num, int chunks);
int array_size(int *nums);
int get_chunks_num(int l_size);
int find_val_pos(t_stack **stk_a, int *range);
t_stack *get_curr_pos(t_stack **stk_a, int *range);

#endif