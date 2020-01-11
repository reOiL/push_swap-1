#include "push_swap.h"

t_form	*make_p(int n, char *inst, t_form *stacks, t_list **instr)
{
	int i;
	int j;
	t_int*	st_from;
	t_int*	st_where;

	j = 0;
	i = n - 1;
	st_from = inst[1] == 'a' ? stacks->stack_b : stacks->stack_a;
	st_where = inst[1] == 'a' ? stacks->stack_a : stacks->stack_b;
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
	ft_lstadd_back(instr, ft_lstnew(inst, 3));
	return (stacks);
}


