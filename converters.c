#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	sign = 1;
	num = 0;
	if (str[0] == '-')
		sign = -1;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		while (str[i] >= '0' && str[i] <= '9')
			num = (num * 10) + (str[i++] - '0');
	}
	return (num * sign);
}

long	ft_atol(char *str)
{
	int			i;
	int			sign;
	long int	num;

	i = 0;
	sign = 1;
	num = 0;
	if (str[0] == '-')
		sign = -1;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		while (str[i] >= '0' && str[i] <= '9')
			num = (num * 10) + (str[i++] - '0');
	}
	return (num * sign);
}
