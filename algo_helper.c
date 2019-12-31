#include "push_swap.h"

int 	get_max(int n, int *flag, t_int *stack)
{
	int 	i;
	int 	max;

	i = 0;
	max = -2147483648;
	while (i < n)
	{
		if (max < stack[i].value && stack[i].in_use == 1)
		{
			max = stack[i].value;
			*flag = (i < n / 2) ? 0 : 1;
		}
		i++;
	}
	return (max);
}

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

int 	get_mid_elem(int n, t_int *stack)
{
	int		i;
	int 	j;
	int		first;
	int 	count;
	int 	a;

	i =  get_first_used(n, stack);
	first = get_first_used(n, stack);
	while (i < n)
	{
		j = first;
		count = 0;
		a = stack[i].value;
		while (j < n)
		{
			if (stack[j].value < stack[i].value)
				count++;
			j++;
		}
		if (count == (n - first) / 2)
			return (stack[i].value);
		i++;
	}
}

int		rra_or_ra(int n, int i, int mid_elem, t_int *stack)
{
	int 	j;

	i += 1;
	j = n - 1;
	while (i < n)
	{
		if (stack[i].value < mid_elem && stack[j].value >= mid_elem)
			return (1);
		else if (stack[j].value < mid_elem)
			return (0);
		else
		{
			i++;
			j--;
		}
	}
}

int 	any_more_than_mid(int n, int mid_elem, t_int *stack_a)
{
	int 	i;

	i = 0;
	while (!stack_a[i].in_use)
		i++;
	while (i < n)
	{
		if (stack_a[i].value < mid_elem)
			return (1);
		i++;
	}
	return (0);
}