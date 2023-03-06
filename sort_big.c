#include "push_swap.h"

void stack_sort_big(t_stack **stk_a, t_stack **stk_b)
{
    t_stack *curr; 
    int *nums; 
    int l_size;
    int i;
 
    i = 0; 
    //calcolo dimensione stack a (numero elementi)
    l_size = list_size(stk_a); 
    //printf ("lsize = %d\n", l_size);
    curr = *stk_a;
    //alloco memoria per array (x chunks)
    nums = malloc(sizeof(int) * l_size);
    populate_array(nums, stk_a); 
    sort_array(nums, l_size); 
    sort_stack_a(stk_a, stk_b, nums);
    sort_stack_b(stk_a, stk_b);
    
    
    //printf("CONTENUTO ARRAY CHUNKS:\n");
    //while(i < l_size)
        //printf("%d\n", nums[i++]);
    
    
    //distanza tra i valori (range del chunk)
    

    /*while (ch_num <= chunks)
    {
        range = get_chunk_range(nums, (l_size / chunks) - 1, ch_num, chunks);
        //printf("min range = %d, max range = %d\n", range[0], range[1]);
        curr = *stk_a; 
        while(curr != NULL)
        {
            i = 0; 
            i = find_val_pos(stk_a, range);
            curr = get_curr_pos(stk_a, range);
            //printf("indice i del valore trovato : %d\n", i);
            if (curr && l_size > 0)
            {
                check_best_rotation(i, l_size, range, stk_a);
                push_to_stack(stk_a, stk_b);
		        printf("pb\n")void check_best_rotation_a(t_stack **stk_a, int i, int l_size, int *range);;
		        l_size--;    
            }
            else
                break; 
        }
        ch_num += 1; 
    }*/

  
    /*while(list_size(stk_b) > 0)
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
        }int i, int l_size, int *range, 
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
            break;*/ 
        //printf("valore in cima a stack a = %d\n", (*stk_a)->val);
        //printf("valore successivo a stack b = %d\n", (*stk_b)->next->val);
}
    