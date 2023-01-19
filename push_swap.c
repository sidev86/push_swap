#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	t_stack *stk_a;
	t_stack *stk_a_cur;
	t_stack *stk_b;
	t_stack *t; 

	stk_a = NULL;
	stk_a_cur = NULL;   
	stk_b = NULL;   
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
		
		//controllo numero di argomenti (dimensione stack)
		if (argc == 3)
		{
			if (stk_a->val > stk_a->next->val)
			{
				swap_single(&stk_a);
			}
		}
		else if (argc == 4)
		{
			stack_3_sort(&stk_a);
		}
		else if (argc == 6)
		{
			stack_5_sort(&stk_a, &stk_b);
		}
	}
	//SMALL SORT WITH 3 ELEMENTS CASES

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
