#include "push_swap.h"


void move_chunks_to_stackb(int chunks, int *nums, t_stack **stk_a, t_stack **stk_b)
{
    t_stack *curr; 
    int *range; 
    int i;
    int l_size;
    int ch_num; 
    
    ch_num = 1; 
    l_size = list_size(stk_a);
    while ((ch_num++) <= chunks)
    {
        range = get_chunk_range(nums, (l_size/ chunks) - 1, ch_num, chunks);
        //printf("min range = %d, max range = %d\n", range[0], range[1]);
        curr = *stk_a; 
        while(curr != NULL)
        {
            i = find_val_pos(stk_a, range);
            curr = get_curr_pos(stk_a, range);
            printf("indice i del valore trovato : %d\n", i);
            if (curr && l_size > 0)
            {
                check_best_rotation(i, l_size, range, stk_a);
                push_to_stack(stk_a, stk_b);
		        printf("pb\n");
                l_size--;   
            }
            else
                break; 
        }
    }
}

void sort_stack_a(t_stack **stk_a, t_stack **stk_b, int *nums)
{
    t_stack *curr; 
    int chunks; 
     

    chunks = get_chunks_num(list_size(stk_a));

    move_chunks_to_stackb(chunks, nums, stk_a, stk_b);
   
}