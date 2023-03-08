#include "push_swap.h"
void swap_single(t_stack **stk)
{
	//sa or sb swap
	t_stack *t; 
    int	tmp; 
	t = *stk; 
	if (t->next != NULL)
	{
		tmp = t->val; 
		t->val = t->next->val; 
		t->next->val = tmp; 
	}
}

void rotate_single(t_stack **stk) //ra or rb rotate
{
    t_stack *t;  
 
	t = *stk; 
	if (t->next != NULL)
	{
		//printf("ra\n");
		while(t->next)
			t = t->next;
		//printf("valore fondo stack: %d\n", t->val); 
		t->next = *stk; 
		t->next->prev = t; 
		*stk = (*stk)->next;
		t->next->next = 0; 
		(*stk)->prev = 0; 
	}
}

void rev_rotate_single(t_stack **stk)//rra or rrb rotate
{
	t_stack *t;
	t_stack *l; 

	l = *stk;
	t = *stk;
	//printf("valore primo nodo: %d", t->val);
	if (t->next)
	{
		while(l->next)
		{
			t = l;
			l = l->next; 
		}
		//printf("valore fondo stack: %d\n", t->val); 
		t->next = 0; 
		l->next = *stk;
		*stk = l; 
		(*stk)->prev = 0; 
		(*stk)->next->prev = *stk; 
	}
}

void push_to_stack(t_stack **stk_o, t_stack **stk_d)
{
	//stk_o = stack origin,  stk_d = stack destination
	//pa or pb -> push from stack origin (stk_o) to stack destination (stk_d)
	t_stack *tmp; 
	tmp = *stk_o;
	
	if (tmp->next)
	{
		*stk_o = (*stk_o)->next; 
		(*stk_o)->prev = NULL; 
	}
	else
	{
		(*stk_o) = NULL; 
	}
	tmp->next = *stk_d; 
	*stk_d = tmp; 
	if(tmp->next)
		tmp->next->prev = tmp; 
	tmp->prev = NULL;
}