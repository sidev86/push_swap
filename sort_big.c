#include "push_swap.h"

void stack_sort_big(t_stack **stk_a, t_stack **stk_b)
{
    t_stack *curr; 
    int l_size;
    int ch_num; 
    int chunks; 
    int dist; 
    int *range;
    int index; 
    int *nums;
    int i; 

    ch_num = 0; 
    i = 0; 
    //calcolo dimensione stack a (numero elementi)
    l_size = list_size(stk_a); 
    curr = *stk_a;
    //alloco memoria per array (x chunks)
    nums = malloc(sizeof(int) * l_size);

    populate_array(nums, stk_a); 
    sort_array(nums, l_size); 
    printf("CONTENUTO ARRAY CHUNKS:\n");
    while(i < l_size)
        printf("%d\n", nums[i++]);
    
    //stabilisco numero di chunk in base a dimensione stack
    if (l_size <= 10)
        chunks = 2;
    else 
        chunks = 4; 
    //distanza tra i valori (range del chunk)
    dist = (l_size / chunks) - 1;
    
    ch_num = 1;

    while (ch_num <= chunks)
    {
        range = get_chunk_range(nums, dist, ch_num, chunks);
        printf("min range = %d, max range = %d\n", range[0], range[1]);

        curr = *stk_a; 
        
       

        while(curr != NULL)
        {

            i = 0; 
            curr = *stk_a;
            while (curr)
            {
                if(curr->val < range[0] || curr->val > range[1])
                {
                    i++; 
                    curr = curr->next; 
                }
                else 
                    break; 
               
            }
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
     
       
 
}