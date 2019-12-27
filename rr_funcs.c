#include "push_swap.h"

t_int	*rev_rotate(int n, t_int* stack)
{
	int 	i;
	int 	tmp;

	i = n - 1;
	tmp = stack[i].value;
	while (i > 0 && stack[i - 1].in_use)
	{
		stack[i].value = stack[i - 1].value;
		i--;
	}
	stack[i].value = tmp;
	return (stack);
}

t_form	*make_rr(int n, char *inst, t_form *stacks)
{
	if (inst[2] == 'a')
	{
		stacks->stack_a = rev_rotate(n, stacks->stack_a);
		return (stacks);
	}
	if (inst[2] == 'b')
	{
		stacks->stack_b = rev_rotate(n, stacks->stack_b);
		return (stacks);
	}
	stacks->stack_a = rev_rotate(n, stacks->stack_a);
	stacks->stack_b = rev_rotate(n, stacks->stack_b);
	return (stacks);
}
