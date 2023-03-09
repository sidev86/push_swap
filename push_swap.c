#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack *head_a;
	t_stack *curr;

	head_a = 0; 
	if (argc >= 2)
		populate_stka(&head_a, argc, argv);
	curr = head_a; 
	if (has_duplicates(&head_a))
		write(2, "Error\n", 6);
	else if(!is_sorted(&curr))
			get_sort_solution(&curr, argc);
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
