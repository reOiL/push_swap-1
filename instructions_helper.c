#include "push_swap.h"

int		get_min_elem(int n, t_int *stack)
{
	int		i;
	int 	min;
	int 	min_val;

	i = get_first_used(n, stack);
	min = 2147483647;
	min_val = 2147483647;
	while (i < n)
	{
		if (stack[i].value < min_val)
		{
			min_val = stack[i].value;
			min = i;
		}
		i++;
	}
	return (min);
}
