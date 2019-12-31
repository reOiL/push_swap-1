#include "push_swap.h"

t_int	*rotate(int n, t_int* stack)
{
	int 	i;
	int 	tmp;

	i = 0;
	while (stack[i].in_use == 0)
		i++;
	tmp = stack[i].value;
	while (i < n - 1)
	{
		stack[i].value = stack[i + 1].value;
		i++;
	}
	stack[i].value = tmp;
	return (stack);
}

t_form	*make_r(int n, char *inst, t_form *stacks, t_list **instr)
{
	if (inst[1] == 'a')
		stacks->stack_a = rotate(n, stacks->stack_a);
	else if (inst[1] == 'b')
		stacks->stack_b = rotate(n, stacks->stack_b);
	else
	{
		stacks->stack_a = rotate(n, stacks->stack_a);
		stacks->stack_b = rotate(n, stacks->stack_b);
	}
	ft_lstadd_front(instr, ft_lstnew(inst, 4));
	return (stacks);
}

