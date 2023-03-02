#include "push_swap.h"

void stack_sort_big(t_stack **stk_a, t_stack **stk_b)
{
    t_stack *curr; 
    int *range;
    int *nums;
    int l_size;
    int ch_num; 
    int chunks; 
    int index; 
    int i;
    int max; 

    ch_num = 0; 
    i = 0; 
    //calcolo dimensione stack a (numero elementi)
    l_size = list_size(stk_a); 
    curr = *stk_a;
    //alloco memoria per array (x chunks)
    nums = malloc(sizeof(int) * l_size);

    populate_array(nums, stk_a); 
    sort_array(nums, l_size); 
    chunks = get_chunks_num(list_size(stk_a));
    //printf("CONTENUTO ARRAY CHUNKS:\n");
    //while(i < l_size)
        //printf("%d\n", nums[i++]);
    
    
    //distanza tra i valori (range del chunk)
    
    ch_num = 1;

    while (ch_num <= chunks)
    {
        range = get_chunk_range(nums, (l_size / chunks) - 1, ch_num, chunks);
        //printf("min range = %d, max range = %d\n", range[0], range[1]);

        curr = *stk_a; 
        while(curr != NULL)
        {
            i = 0; 
            //curr = *stk_a;
            i = find_val_pos(stk_a, range);
            curr = get_curr_pos(stk_a, range);
            /*while (curr)
            {
                if(curr->val < range[0] || curr->val > range[1])
                {
                    i++; 
                    curr = curr->next; 
                }
                else 
                    break; 
            }*/
           
            printf("indice i del valore trovato : %d\n", i);
            if (curr && l_size > 0)
            {
                if (i < l_size / 2)
                {
                    while((*stk_a)->val < range[0] || (*stk_a)->val > range[1])
                    {
                        rotate_single(stk_a);
                        printf("ra\n");
                    }
                }
                else 
                {
                    while((*stk_a)->val < range[0] || (*stk_a)->val > range[1])
                    {
                        rev_rotate_single(stk_a);
                        printf("rra\n");
                    }
                }
                push_to_stack(stk_a, stk_b);
		        printf("pb\n");
		        l_size--;    
            }
            else
                break; 
        }
        ch_num += 1; 
    }

    while(list_size(stk_b) > 0)
    {
        i = 0;
        max = find_max(stk_b);
        //printf("max valore in stack b : %d\n", max);
        curr = *stk_b;
        while(curr)
        {
            if (curr->val != max)
            {
                i++;
                curr = curr->next;
            }
            else
                break;
        }
        l_size = list_size(stk_b);
        if (curr && l_size > 0)
            {
                if (i < l_size / 2)
                {
                    while((*stk_b)->val != max)
                    {
                        rotate_single(stk_b);
                        printf("rb\n");
                    }
                }
                else 
                {
                    while((*stk_b)->val != max)
                    {
                        rev_rotate_single(stk_b);
                        printf("rrb\n");
                    }
                }
                push_to_stack(stk_b, stk_a);
		        printf("pa\n");
		        l_size--;    
            }
            else
                break; 
    }
    //printf("valore in cima a stack a = %d\n", (*stk_a)->val);
    //printf("valore successivo a stack b = %d\n", (*stk_b)->next->val);
}