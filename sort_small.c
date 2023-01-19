#include "push_swap.h"

static void sort3_c1(t_stack **stk)
{
	swap_single(stk);
}
static void sort3_c2(t_stack **stk)
{
	swap_single(stk);
	rev_rotate_single(stk);
}
static void sort3_c3(t_stack **stk)
{
	rotate_single(stk);
}
static void sort3_c4(t_stack **stk)
{
	swap_single(stk);
	rotate_single(stk);
}
static void sort3_c5(t_stack **stk)
{
	rev_rotate_single(stk);
}


int find_min(t_stack **stk)
{
	t_stack *t;
	int		min;

	t = *stk;
	min = t->val;
	while(t->next)
	{
		if(t->val < min)
			min = t->val;
		t = t->next;
	}
	printf("valore minimo stack: %d\n", min);
	return(min);
}

int	list_size(t_stack **stk)
{
	t_stack *t;
	int size;

	size = 0;
	t = *stk;
	while (t)
	{
		size++;
		t = t->next;
	}
	return (size);
}

void stack_3_sort(t_stack **stk)
{
	t_stack *t;

	t = *stk;
	printf("nodo 1: %d, nodo 2: %d, nodo 3: %d\n", t->val, t->next->val, t->next->next->val);
	if (t->val > t->next->val && t->next->val < t->next->next->val && t->val < t->next->next->val)
	{
		printf("caso 1\n");
		sort3_c1(stk);
	}
	else if (t->val > t->next->val && t->next->val > t->next->next->val && t->val > t->next->next->val)
	{
		printf("caso 2\n");
		sort3_c2(stk);
	}
	else if (t->val > t->next->val && t->next->val < t->next->next->val && t->val > t->next->next->val)
	{
		printf("caso 3\n");
		sort3_c3(stk);
	}
	else if (t->val < t->next->val && t->next->val > t->next->next->val && t->val < t->next->next->val)
	{
		printf("caso 4\n");
		sort3_c4(stk);
	}
	else if (t->val < t->next->val && t->next->val > t->next->next->val && t->val > t->next->next->val)
	{
		printf("caso 5\n");
		sort3_c5(stk);
	}
}

void stack_5_sort(t_stack **stk_a, t_stack **stk_b)
{
	t_stack *t;

	int		i;
	int		min;
	int l_size;
	printf("ordinamento 5 valori\n");
	
	
	l_size = list_size(stk_a);

	while (l_size >= 4)
	{
		t = *stk_a;
		i = 0;
		min = find_min(stk_a);
		printf("dimensione lista = %d\n", l_size);
		//calcolo indice di dove si trova i
		while(t->next)
		{
			if (t->val != min)
			{
				i++;
				t = t->next;
			}	
			else 
				break;
		}
		printf("indice i = %d\n", i);

		//stabilisco quale rotate risulta migliore utilizzare ovvero usando meno istruzioni (ra o rra)
		if (i < l_size / 2)
		{
			while((*stk_a)->val != min)
				rev_rotate_single(stk_a);
		}
		else
		{
			while((*stk_a)->val != min)
				rotate_single(stk_a);
		}
		push_to_stack(stk_a, stk_b);
		l_size--;
	}
	stack_3_sort(stk_a);
	push_to_stack(stk_b, stk_a);
	push_to_stack(stk_b, stk_a);
	

	/*find_min(stk_a);
	push_to_stack(stk_a, stk_b);
	push_to_stack(stk_a, stk_b);
	t = *stk_b;
	if (t->val < t->next->val)
		swap_single(stk_b);
	
	stack_3_sort(stk_a);
	push_to_stack(stk_b, stk_a);
	push_to_stack(stk_b, stk_a);*/

}