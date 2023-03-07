#include "push_swap.h"

int check_doubles(t_stack **stk_a)
{
    t_stack *curr;
    t_stack *curr2;

    curr = *stk_a;
    curr2 = *stk_a;

    while (curr)
    {
        //curr = *stk_a;
        curr2 = *stk_a;
        while (curr2)
        {
            if(curr != curr2 && curr->val == curr2->val)
                return 1;
            else
                curr2 = curr2->next;
        }
        curr = curr->next;
    }
    return 0;
}

static int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int is_integer(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if(is_digit(str[i]))
        {
            i++;
        }
            
        else
            return (0);
    }
    return (1);
}
