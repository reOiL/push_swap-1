#include "push_swap.h"

t_form	*make_p(int n, char *inst, t_form *stacks)
{
	int i;
	int j;
	t_int*	st_from;
	t_int*	st_where;

	j = 0;
	i = n - 1;
	if (inst[1] == 'a')
	{
		st_from = stacks->stack_b;
		st_where = stacks->stack_a;
	}
	else
	{
		st_from = stacks->stack_a;
		st_where = stacks->stack_b;
	}
	while (st_where[i].in_use == 1)
	{
		i--;
		j++;
	}
	if (i >= 0)
	{
		st_where[i].value = st_from[j].value;
		st_where[i].in_use = 1;
		st_from[j].in_use = 0;
	}
	return (stacks);
}


