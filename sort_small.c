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

	push_to_stack(stk_a, stk_b);
	push_to_stack(stk_a, stk_b);
	t = *stk_b;
	if (t->val < t->next->val)
		swap_single(stk_b);
	
	stack_3_sort(stk_a);
	push_to_stack(stk_b, stk_a);
	push_to_stack(stk_b, stk_a);

}