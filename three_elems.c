#include "push_swap.h"

t_form	*second_oper(int n, t_form *stacks, t_list **instr)
{
	int 	fu;

	fu = get_first_used(n, stacks->stack_a);
	if (stacks->stack_a[fu + 2].value < stacks->stack_a[fu + 1].value \
			&& stacks->stack_a[fu + 2].value > stacks->stack_a[fu].value)
	{
		stacks = make_s(n, "sa", stacks, instr);
		stacks = make_r(n, "ra", stacks, instr);
	}
	else
	{
		stacks = make_s(n, "sa", stacks, instr);
		stacks = make_rr(n, "rra", stacks, instr);
	}
	return (stacks);
}

t_form	*three_elems_algo(int n, t_form *stacks, t_list **instr)
{
	int 	fu;

	fu = get_first_used(n, stacks->stack_a);
	if (stacks->stack_a[fu].value < stacks->stack_a[fu + 2].value \
			&& stacks->stack_a[fu].value > stacks->stack_a[fu + 1].value)
		stacks = make_s(n, "sa", stacks, instr);
	else if (stacks->stack_a[fu].value < stacks->stack_a[fu + 1].value \
			&& stacks->stack_a[fu].value > stacks->stack_a[fu + 2].value)
		stacks = make_rr(n, "rra", stacks, instr);
	else if (stacks->stack_a[fu + 2].value > stacks->stack_a[fu + 1].value \
			&& stacks->stack_a[fu + 2].value < stacks->stack_a[fu].value)
		stacks = make_r(n, "ra", stacks, instr);
	if (is_sorted(n, stacks->stack_a))
		return (stacks);
	return (second_oper(n, stacks, instr));
}