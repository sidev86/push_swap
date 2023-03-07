#include "push_swap.h"


int ft_atoi(char *str)
{
    int i;
    int num;
    int sign;

    i = 0;
    sign = 1;
    while (*str)
    {
        if(str[0] == '+')
            sign = 1;
        else if(str[0] == '-')
            sign = -1;
        
        while (str[i] >= '0' && str[i] <= '9')
            num = (num * 10) + (str[i++] - '0');
    }
}