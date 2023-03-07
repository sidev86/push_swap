#include <stdio.h> 
#include <stdlib.h> 
#include <stddef.h>
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_stack
{	
	int		val; 
	struct s_stack	*next; 
	struct s_stack	*prev; 
}		t_stack;


t_stack *get_curr_stka_top(t_stack **stk_a, int *range);
t_stack *get_curr_stka_bottom(t_stack **stk_a, int *range);
t_stack *get_curr_max_pos(t_stack **stk_a, int max);
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
int is_sorted(t_stack **stk_a);
void populate_array(int nums[], t_stack **stk_a);
void sort_array(int nums[], int size);
int *get_chunk_range(int nums[], int dist, int ch_num, int chunks);
int get_chunks_num(int l_size);
int find_val_stka_top(t_stack **stk_a, int *range);
int find_val_stka_bottom(t_stack **stk_a, int *range);
int find_val_pos_b(t_stack **stk_b, int max);
int get_curr_val_index(t_stack **stk_a, int val);
int check_doubles(t_stack **stk_a);
int is_integer(char *str);

void check_best_rotation_a(t_stack **stk_a, int i, int l_size, int *range);
void check_best_rotation_b(t_stack **stk_b, int i, int l_size, int max);
void sort_stack_a(t_stack **stk_a, t_stack **stk_b, int *nums);
void sort_stack_b(t_stack **stk_a, t_stack **stk_b);
void free_stack_memory(t_stack **stk_a);

#endif