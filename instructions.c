#include "push_swap.h"

void swap_single(t_stack **stk)
{
	//sa or sb swap
	int	tmp; 
	t_stack *t; 
	t = *stk; 
	if (t->next != NULL)
	{
		tmp = t->val; 
		t->val = t->next->val; 
		t->next->val = tmp; 
	}
}


void push_to_stack(t_stack **stk_o, t_stack **stk_d)
{
	//pa or pb -> push from stack origin (stk_o) to stack destination (stk_d)
	int	tmp;
	t_stack *t; 
 
	if (*stk_d == NULL)
	{
		//printf("stack b vuoto \n");
		*stk_d = malloc(sizeof(t_stack)); 
		if(*stk_d != NULL && *stk_o != NULL)
		{
			tmp = (*stk_o)->val; 
			t = *stk_o; 
			 *stk_o = (*stk_o)->next; 
			 free(t);
			 (*stk_d)->val = tmp; 
		}
	}
	else 
	{
		t_stack *new;
		new = malloc(sizeof(t_stack));
		if (new != NULL)
		{
			new->next = *stk_d; 
			*stk_d = new; 
			tmp = (*stk_o)->val; 
			t = *stk_o; 
			*stk_o = (*stk_o)->next; 
			free(t);
			(*stk_d)->val = tmp;
		}
	}
}

void rotate_single(t_stack **stk)
{
	//rra or rrb rotate
	t_stack *t;  

	t = *stk; 
	
	if (t->next != NULL)
	{
		printf("istruzione rotate\n");
		while(t->next)
			t = t->next;
		printf("valore fondo stack: %d\n", t->val); 
		t->next = *stk; 
		*stk = (*stk)->next;
		t->next->next = 0; 
	}
}

void rev_rotate_single(t_stack **stk)
{
	//ra or rb rotate
	t_stack *t;
	t_stack *l; 

	l = *stk;
	t = *stk;
	printf("valore primo nodo: %d", t->val);
	if (t->next != NULL)
	{
		while(l->next)
		{
			t = l;
			l = l->next; 
		}
	
		printf("valore fondo stack: %d\n", t->val); 
		t->next = 0; 
		l->next = *stk;
		*stk = l; 
	}
}

void rotate_both(t_stack *stk_1, t_stack *stk_2)
{
	//rr (rotate both stacks)
	rotate_single(&stk_1); 
	rotate_single(&stk_2);
}


void swap_both(t_stack **stk_1, t_stack **stk_2)
{
	//ss (swap both stacks)
	swap_single(stk_1); 
	swap_single(stk_2);
}



