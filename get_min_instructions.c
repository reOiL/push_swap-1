/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:50:34 by eblackbu          #+#    #+#             */
/*   Updated: 2020/01/13 14:51:55 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_needed_bstack(int elem, int n, t_form **stacks, t_flag *flag_rr)
{
	int		top_b;
	int		oper;

	top_b = get_first_used(n, (*stacks)->stack_b);
	(*flag_rr).flag_rrb = elem < (top_b + n) / 2 ? 0 : 1;
	oper = (*flag_rr).flag_rrb ? n - elem : elem - top_b;
	return (oper);
}

int		get_needed_astack(int elem, int n, t_form **stacks, t_flag *flag_rr)
{
	int		top_a;
	int		min;
	int		val;
	int		oper;

	top_a = get_first_used(n, (*stacks)->stack_a);
	val = (*stacks)->stack_b[elem].value;
	min = get_min_elem(n, (*stacks)->stack_a);
	while ((*stacks)->stack_a[min].value < val)
	{
		if (min == n - 1)
			min = top_a;
		else
			min++;
	}
	(*flag_rr).flag_rra = min < (n + top_a) / 2 ? 0 : 1;
	oper = (*flag_rr).flag_rra ? n - min : min - top_a;
	return (oper);
}

int		get_instructions(int elem, int n, t_form **stacks)
{
	t_flag	flag_rr;
	int		in;
	int		rot_a;
	int		rot_b;

	in = 1;
	rot_a = get_needed_astack(elem, n, stacks, &flag_rr);
	rot_b = get_needed_bstack(elem, n, stacks, &flag_rr);
	if (flag_rr.flag_rra == flag_rr.flag_rrb)
	{
		in += rot_a > rot_b ? rot_a : rot_b;
		return (in);
	}
	else
		return (in + rot_a + rot_b);
}

int		get_min_instr(int n, t_form **stacks)
{
	int		i;
	int		elem;
	int		min;

	i = get_first_used(n, (*stacks)->stack_b);
	while (i < n)
	{
		(*stacks)->stack_b[i].min_instr = get_instructions(i, n, stacks);
		i++;
	}
	i = get_first_used(n, (*stacks)->stack_b);
	min = 2147483647;
	elem = 0;
	while (i < n)
	{
		if ((*stacks)->stack_b[i].min_instr < min)
		{
			elem = i;
			min = (*stacks)->stack_b[i].min_instr;
		}
		i++;
	}
	return (elem);
}
