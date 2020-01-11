#include "push_swap.h"

int 		is_empty(int n, t_int *stack)
{
	int 	i;

	i = 0;
	while (i < n)
	{
		if (stack[i].in_use)
			return (0);
		i++;
	}
	return (1);
}

int 		is_sorted(int n, t_int *stack)
{
	int 	i;

	i = get_first_used(n, stack);
	while (i < n - 1)
	{
		if (stack[i].value > stack[i + 1].value)
			return (0);
		i++;
	}
	return (1);
}

t_form		*quick_sort_a(int n, t_form *stacks, t_list **instr)
{
	int 	i;
	int 	flag;
	int 	mid_elem;

	i = get_first_used(n, stacks->stack_a);
	if (n - i < 3 || is_sorted(n, stacks->stack_a))
		return (is_sorted(n, stacks->stack_a) ? stacks : make_s(n, "sa", stacks, instr));
	mid_elem = get_mid_elem(n, stacks->stack_a);
	while (any_more_than_mid(n, mid_elem, stacks->stack_a))
	{
		if (is_sorted(n, stacks->stack_a))
			return (stacks);
		i = get_first_used(n, stacks->stack_a);
		flag = rra_or_ra(n, i, mid_elem, stacks->stack_a);
		if (stacks->stack_a[i].value < mid_elem)
			stacks = make_p(n, "pb", stacks, instr);
		else
			stacks = flag ? make_r(n, "ra", stacks, instr) : make_rr(n, "rra", stacks, instr);
	}
	//print_stacks(n, stacks);
	return (quick_sort_a(n, stacks, instr));
}

t_list		*insertion_from_b(int n, t_form *stacks, t_list **instr)
{
	int		max;
	int		flag;

	while (!is_empty(n, stacks->stack_b))
	{
		flag = 0;
		max = get_max(n, &flag, stacks->stack_b);
		while (get_peek(n, stacks->stack_b) != max)
		{
			stacks = flag ? make_rr(n, "rrb", stacks, instr) : make_r(n ,"rb", stacks, instr);
			//print_stacks(n, stacks);
		}
		stacks = make_p(n, "pa", stacks, instr);
	}
	return (*instr);
}

t_list		*get_algo(int n, t_form *stacks)
{
	int 	elem;
	t_list	*instr;

	instr = NULL;
	print_stacks(n, stacks);
	stacks = quick_sort_a(n, stacks, &instr);
	print_stacks(n, stacks);
	while (!is_empty(n, stacks->stack_b))
	{
		if (get_first_used(n, stacks->stack_b) == n - 2)
			stacks = is_sorted(n, stacks->stack_b) ? make_s(n, "sb", stacks, &instr) : stacks;
		elem = get_min_instr(n, &stacks);
		int a = stacks->stack_b[elem].min_instr;
		push_min_elem(elem, n, &stacks, &instr);
		print_stacks(n, stacks);
	}
	//return (insertion_from_b(n, stacks, &instr));
	return (instr);
}
