#include "push_swap.h"

t_int	*rotate(int n, t_int* stack)
{
	int 	i;
	int 	tmp;

	i = 0;
	tmp = stack[0].value;
	while (i < n - 1 && stack[i + 1].in_use)
	{
		stack[i].value = stack[i + 1].value;
		i++;
	}
	stack[i].value = tmp;
	return (stack);
}

t_form	*make_r(int n, char *inst, t_form *stacks)
{
	if (inst[1] == 'a')
	{
		stacks->stack_a = rotate(n, stacks->stack_a);
		return (stacks);
	}
	if (inst[1] == 'b')
	{
		stacks->stack_b = rotate(n, stacks->stack_b);
		return (stacks);
	}
	stacks->stack_a = rotate(n, stacks->stack_a);
	stacks->stack_b = rotate(n, stacks->stack_b);
	return (stacks);
}

