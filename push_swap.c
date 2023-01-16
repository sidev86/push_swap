#include <stdio.h> 
#include <stdlib.h> 

typedef struct	s_stack
{	
	int		val; 
	struct s_stack	*next; 
}		t_stack;

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

/*void rotate_single(t_stack *stk)
{
	//ra or rb rotate
	t_stack *t;
	char *tmp; 

	t = stk; 
	if (t->next != NULL)
	{
		tmp = stk->val;
		while(t->next)
		{
			t->val = t->next->val;
			t = t->next;
		}
		t->val = tmp; 
	}
}*/

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



void sort3_c1(t_stack **stk)
{
	swap_single(stk);
}
void sort3_c2(t_stack **stk)
{
	swap_single(stk);
	rev_rotate_single(stk);
}
void sort3_c3(t_stack **stk)
{
	rotate_single(stk);
}
void sort3_c4(t_stack **stk)
{
	swap_single(stk);
	rotate_single(stk);
}
void sort3_c5(t_stack **stk)
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





int	main(int argc, char **argv)
{
	int	i;
	t_stack *stk_a;
	t_stack *stk_a_cur;
	t_stack *stk_b;
	t_stack *stk_b_cur; 
	t_stack *t; 

	stk_a = NULL;
	stk_a_cur = NULL;   
	stk_b = NULL; 
	stk_b_cur = NULL;  
	i = 1;
	if(argc < 2)
	{
		printf("no argomenti");
		return(0);
	}
	else
	{
		//alloco memoria e salvo in stack A 
		while (i < argc)
		{
			if(stk_a == NULL)
			{
				//printf("alloco per nodo");
				stk_a = malloc(sizeof(t_stack)); 
				if (stk_a != NULL)
				{
					stk_a_cur = stk_a; 
					stk_a->val = atoi(argv[i]);
				}
			}
			else 
			{
				stk_a_cur->next = malloc(sizeof(t_stack)); 
				stk_a_cur = stk_a_cur->next;
				stk_a_cur->val = atoi(argv[i]); 
			}
			i++;
		}

		//stampa contenuto stack a 
		printf("STACK A INIZIALE\n");
		
		t = stk_a;

		while(t)
		{
			printf("%d\n", t->val); 
			t = t->next; 
		}

		//controllo numero di argomenti
		if (argc == 4)
		{
			stack_3_sort(&stk_a);
		}
		else if (argc == 6)
		{
			stack_5_sort(&stk_a, &stk_b);
		}
	}
	
	
	

	

	//sort_5_elements(&stk_a);
	
	//swap_single(&stk_a);
	//rev_rotate_single(&stk_a);
	

	//push_to_stack(&stk_a, &stk_b);
	//push_to_stack(&stk_a, &stk_b);
	//push_to_stack(&stk_b, &stk_a);
	//swap_both(stk_a, stk_b);
	//push_to_stack(&stk_b, &stk_a);
	//rotate_single(&stk_a);
	//rev_rotate_single(&stk_a);
	//rotate_both(stk_a, stk_b);

	//SMALL SORT (3 ELEMENTS)

	//3 elements: case 1 -> sa 
	//swap_single(stk_a);

	//3 elements: case 2 -> sa + rra
	//swap_single(stk_a);
	//rev_rotate_single(&stk_a);

	//3 elements: case 3 -> ra
	//rotate_single(&stk_a);

	//3 elements: case 4 -> sa + ra
	//swap_single(stk_a);
	//rotate_single(&stk_a);

	//3 elements: case 5 -> rra
	//rev_rotate_single(&stk_a);

	printf("STACK A\n");
	t = stk_a;
	while(t)
	{
		printf("%d\n", t->val); 
		t = t->next; 
	}

	printf("STACK B\n");
	t = stk_b;
	while(t)
	{
		printf("%d\n", t->val); 
		t = t->next;
	}

}
