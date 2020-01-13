/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:07:07 by eblackbu          #+#    #+#             */
/*   Updated: 2020/01/13 16:53:31 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_empty(int n, t_int *stack)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (stack[i].in_use)
			return (0);
		i++;
	}
	return (1);
}

int			is_sorted(int n, t_int *stack)
{
	int		i;

	i = get_first_used(n, stack);
	while (i < n - 1)
	{
		if (stack[i].value > stack[i + 1].value)
			return (0);
		i++;
	}
	return (1);
}

t_form		*swap_two(int n, t_form *stacks, t_list **instr)
{
	if (is_sorted(n, stacks->stack_a))
		return (stacks);
	else
		return (make_s(n, "sa", stacks, instr));
}

t_form		*quick_sort_a(int n, t_form *stacks, t_list **instr)
{
	int		i;
	int		flag;
	int		mid_elem;

	i = get_first_used(n, stacks->stack_a);
	if (n - i < 3)
		return (swap_two(n, stacks, instr));
	if (n - i == 3)
		return (three_elems_algo(n, stacks, instr));
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
			stacks = flag ? make_r(n, "ra", stacks, instr) \
						: make_rr(n, "rra", stacks, instr);
	}
	return (quick_sort_a(n, stacks, instr));
}

t_list		*get_algo(int n, t_form *stacks)
{
	int		elem;
	t_list	*instr;

	instr = NULL;
	stacks = quick_sort_a(n, stacks, &instr);
	while (!is_empty(n, stacks->stack_b))
	{
		elem = get_min_instr(n, &stacks);
		push_min_elem(elem, n, &stacks, &instr);
	}
	while (get_min_elem(n, stacks->stack_a) != 0)
		stacks = get_min_elem(n, stacks->stack_a) < n / 2 ? \
		make_r(n, "ra", stacks, &instr) : make_rr(n, "rra", stacks, &instr);
	return (instr);
}
