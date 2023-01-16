#include <stdio.h> 
#include <stdlib.h> 
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_stack
{	
	int		val; 
	struct s_stack	*next; 
}		t_stack;

void    stack_3_sort(t_stack **stk);
void    stack_5_sort(t_stack **stk_a, t_stack **stk_b);
void    swap_single(t_stack **stk);
void    push_to_stack(t_stack **stk_o, t_stack **stk_d);
void    rotate_single(t_stack **stk);
void    rev_rotate_single(t_stack **stk);
void    rotate_both(t_stack *stk_1, t_stack *stk_2);
void    swap_both(t_stack **stk_1, t_stack **stk_2);

#endif