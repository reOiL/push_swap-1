#include "push_swap.h"

void		go_rr(int elem, int n, t_form **stacks, t_list **instr)
{
	int		top_a;
	int 	val;

	val = (*stacks)->stack_b[elem].value;
	top_a = get_first_used(n, (*stacks)->stack_a);
	//int a = get_first_used(n, (*stacks)->stack_b);
	while (elem != get_first_used(n, (*stacks)->stack_b) && (*stacks)->stack_a[top_a].value < val)
	{
		*stacks = make_r(n, "rr", *stacks, instr);
		print_stacks(n, *stacks);
		elem--;
	}
	if (elem == get_first_used(n, (*stacks)->stack_b))
	{
		while ((*stacks)->stack_a[top_a].value < val)
			*stacks = make_r(n, "ra", *stacks, instr);
	}
	else
	{
		while (elem-- != get_first_used(n, (*stacks)->stack_b))
			*stacks = make_r(n, "rb", *stacks, instr);
	}
	make_p(n, "pa", *stacks, instr);
}

void		go_rrr(int elem, int n, t_form **stacks, t_list **instr)
{
	int		top_a;
	int 	val;

	val = (*stacks)->stack_b[elem].value;
	top_a = get_first_used(n, (*stacks)->stack_a);
	while (elem != n && !((*stacks)->stack_a[top_a].value > val && ((*stacks)->stack_a[n - 1].value < val || (*stacks)->stack_a[n - 1].value) > (*stacks)->stack_a[top_a].value))
	{
		*stacks = make_rr(n, "rrr", *stacks, instr);
		elem++;
	}
	if (elem == n)
	{
		while (!((*stacks)->stack_a[top_a].value > val && ((*stacks)->stack_a[n - 1].value < val || (*stacks)->stack_a[n - 1].value) > (*stacks)->stack_a[top_a].value))
			*stacks = make_rr(n, "rra", *stacks, instr);
	}
	else
	{
		while (elem++ != n)
			*stacks = make_rr(n, "rrb", *stacks, instr);
	}
	make_p(n, "pa", *stacks, instr);
}

void		go_rrarb(int elem, int n, t_form **stacks, t_list **instr)
{
	int		top_a;
	int 	val;

	val = (*stacks)->stack_b[elem].value;
	top_a = get_first_used(n, (*stacks)->stack_a);
	while ((*stacks)->stack_b[get_first_used(n, (*stacks)->stack_b)].value != val)
		*stacks = make_r(n, "rb", *stacks, instr);
	while ((*stacks)->stack_a[n - 1].value < val)
		*stacks = make_rr(n, "rra", *stacks, instr);
	make_p(n, "pa", *stacks, instr);
}

void		go_rarrb(int elem, int n, t_form **stacks, t_list **instr)
{
	int		top_a;
	int 	val;

	val = (*stacks)->stack_b[elem].value;
	top_a = get_first_used(n, (*stacks)->stack_a);
	while ((*stacks)->stack_b[get_first_used(n, (*stacks)->stack_b)].value != val)
		*stacks = make_rr(n, "rrb", *stacks, instr);
	while ((*stacks)->stack_a[n - 1].value > val)
		*stacks = make_r(n, "ra", *stacks, instr);
	make_p(n, "pa", *stacks, instr);
}

void		push_min_elem(int elem, int n, t_form **stacks, t_list **instr)
{
	t_flag	flag_rr;

	get_needed_astack(elem, n, stacks, &flag_rr);
	get_needed_bstack(elem, n, stacks, &flag_rr);
	if (flag_rr.flag_rra == flag_rr.flag_rrb)
	{
		if (flag_rr.flag_rra)
			go_rrr(elem, n, stacks, instr);
		else
			go_rr(elem, n, stacks, instr);
	}
	else
	{
		if (flag_rr.flag_rra)
			go_rrarb(elem, n, stacks, instr);
		else
			go_rarrb(elem, n, stacks, instr);
	}
}
