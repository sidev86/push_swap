#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack *head_a;
	t_stack *head_b;
	t_stack *tail_a;
	t_stack *tail_b;
	t_stack *new_node;
	t_stack *curr;

	int	i;

	i = 1;
	head_b = 0; 

	if (argc < 2)
		printf("Error! Missing Arguments\n");
	else
	{
		//Popoliamo lo Stack A
		while (i < argc)
		{
			if(i == 1) //primo elemento
			{
				head_a = malloc(sizeof(t_stack));
				if (head_a == NULL)
					exit(1);
				tail_a = head_a;
				head_a->val = atoi(argv[i]); //TODO: creare funzione ft_atoi
				head_a->next = NULL;
				head_a->prev = NULL;	
			}
			else //ci sono già nodi
			{
				new_node = malloc(sizeof(t_stack));
				if (new_node == NULL)
					exit(1);
				new_node->val = atoi(argv[i]);
				new_node->prev = tail_a;
				new_node->next = NULL; 
				new_node->prev->next = new_node;
				tail_a = new_node; 
			}
			i++;
		}


		
		curr = head_a; 

		if (check_doubles(&head_a))
			printf("stack non valido. sono presenti valori doppi\n");
		else
		{
			printf("stack valido. NON sono presenti valori doppi\n");
			if (argc == 3)
			{
				if (curr->val > curr->next->val)
				{
					swap_single(&head_a);
					printf("sa\n");
				}	
			}
			else if (argc == 4)
			{
				stack_sort_3(&head_a);
			}
			else if (argc == 5 || argc == 6) //ordinamento 4/5 elementi
			{
				/*head_b = malloc(sizeof(t_stack));
				if(head_b == NULL)
					exit(1);*/
				stack_sort_4_5(&head_a, &head_b);	
			}
			else if (argc > 6)
			{
				stack_sort_big(&head_a, &head_b);
			}
		}
		
		// check del numero di elementi dello stack e richiamo del relativo algoritmo
		
	
		//Visualizza contenuto Stack A
		/*printf("-- STACK A --\n");
		curr = head_a; 
		if(head_a != NULL)
		{
			while(curr)
			{
				printf("%d\n", curr->val);
				curr = curr->next; 
			}
		}
		printf("-- STACK A REVERSE--\n");
		curr = head_a; 
		while(curr->next)
			curr = curr->next;
		while(curr)
		{
			printf("%d\n", curr->val);
			curr = curr->prev; 
		}

		printf("-- STACK B --\n");
		curr = head_b; 
		while(curr)
		{
			printf("%d\n", curr->val);
			curr = curr->next; 
		}

		printf("-- STACK B REVERSE--\n");
		curr = head_b; 
		while(curr->next)
			curr = curr->next; 
		while(curr)
		{
			printf("%d\n", curr->val);
			curr = curr->prev; 
		}*/
	}
}
