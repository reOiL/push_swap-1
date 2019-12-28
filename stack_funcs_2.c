#include "push_swap.h"

int 	get_min(int n, int *flag, t_int *stack)
{
	int 	i;
	int 	min;

	i = 0;
	min = 2147483647;
	while (i < n)
	{
		if (min > stack[i].value && stack[i].in_use == 1)
		{
			min = stack[i].value;
			*flag = (i < n / 2) ? 0 : 1;
		}
		i++;
	}
	return (min);
}

int 	get_peek(int n, t_int *stack)
{
	int 	i;

	i = 0;
	while (stack[i].in_use == 0)
		i++;
	return (stack[i].value);
}