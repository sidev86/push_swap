#include "push_swap.h"

void stack_sort_3(t_stack **stk)
{
    int max; 
    int min; 
    t_stack *curr; 
    curr = *stk; 
    min = find_min(stk);
    max = find_max(stk);
    //printf("valore minimo = %d\n", min);
    //printf("valore massimo = %d\n", max);
    if (curr->next->val == min && curr->next->next->val == max)
    {
        //case 1
        swap_single(stk);
        printf("sa\n");
    }
    else if(curr->val == max && curr->next->next->val == min)
    {
        //case 2
        swap_single(stk);
        rev_rotate_single(stk);
        printf("sa\n");
        printf("rra\n");
    }
    else if(curr->val == max && curr->next->val == min)
    {
        //case 3
        rotate_single(stk);
        printf("ra\n");
    }
    else if(curr->val == min && curr->next->val == max)
    {
        //case 4
        swap_single(stk);
        rotate_single(stk);
        printf("sa\n");
        printf("ra\n");
    }
    else if(curr->next->val == max && curr->next->next->val == min)
    {
        //case 5
        rev_rotate_single(stk);
        printf("rra\n");
    }
}


void stack_sort_4_5(t_stack **stk_a, t_stack **stk_b)
{
    t_stack *curr; 
    int l_size; 
    int min; 
    int i; 

    l_size = list_size(stk_a); 
    while (l_size >= 4)
    {
        //printf("dimensione lista = %d\n", l_size);
        curr = *stk_a;
        i = 0; 
        min = find_min(stk_a); 
        while(curr->next)
		{
			if (curr->val != min)
			{
				i++;
				curr = curr->next;
			}	
			else 
				break;
		}
		//printf("indice i = %d\n", i);
        if (i <= l_size / 2)
		{
			while((*stk_a)->val != min)
			{
				rotate_single(stk_a);
				printf("ra\n");
			}		
		}
		else
		{
			while((*stk_a)->val != min)
			{
				rev_rotate_single(stk_a);
				printf("rra\n");
			}			
		}
		push_to_stack(stk_a, stk_b);
		printf("pb\n");
		l_size--;
    }

    stack_sort_3(stk_a);
    while (list_size(stk_b) > 0)
    {
        push_to_stack(stk_b, stk_a);
        printf("pa\n");
    }
        
    
    
    //push_to_stack(stk_b, stk_a);
	/*while (*stk_b)
	{
		push_to_stack(stk_b, stk_a);
		//printf("pa\n");
	}*/
}

