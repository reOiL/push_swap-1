/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_min_elem2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:40:21 by eblackbu          #+#    #+#             */
/*   Updated: 2020/01/13 16:44:13 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_rrr_helper(int n, int val, t_form **stacks, t_list **instr)
{
	int		flag;
	int		top_a;

	flag = 0;
	top_a = get_first_used(n, (*stacks)->stack_a);
	if (val < get_min(n, &flag, (*stacks)->stack_a))
	{
		while (get_min_elem(n, (*stacks)->stack_a) \
				!= get_first_used(n, (*stacks)->stack_a))
		{
			*stacks = get_min_elem(n, (*stacks)->stack_a) < (n + top_a) / 2 \
		? make_r(n, "ra", *stacks, instr) : make_rr(n, "rra", *stacks, instr);
		}
	}
	else
	{
		while (!((*stacks)->stack_a[n - 1].value < val \
	&& (*stacks)->stack_a[top_a].value > val) || \
get_min_elem(n, (*stacks)->stack_a) == get_first_used(n, (*stacks)->stack_a))
			*stacks = make_rr(n, "rra", *stacks, instr);
	}
}

void	go_rr_helper(int n, int val, t_form **stacks, t_list **instr)
{
	int		flag;
	int		top_a;

	flag = 0;
	top_a = get_first_used(n, (*stacks)->stack_a);
	if (val < get_min(n, &flag, (*stacks)->stack_a))
		while (get_min_elem(n, (*stacks)->stack_a) != \
		get_first_used(n, (*stacks)->stack_a))
			*stacks = make_r(n, "ra", *stacks, instr);
	else
		while (!((*stacks)->stack_a[top_a].value > val && \
		(*stacks)->stack_a[n - 1].value < val))
			*stacks = make_r(n, "ra", *stacks, instr);
}
