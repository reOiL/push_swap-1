/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:05:54 by eblackbu          #+#    #+#             */
/*   Updated: 2020/01/13 15:06:13 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_int	*rev_rotate(int n, t_int *stack)
{
	int		i;
	int		tmp;

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

t_form	*make_rr(int n, char *inst, t_form *stacks, t_list **instr)
{
	if (inst[2] == 'a')
		stacks->stack_a = rev_rotate(n, stacks->stack_a);
	else if (inst[2] == 'b')
		stacks->stack_b = rev_rotate(n, stacks->stack_b);
	else
	{
		stacks->stack_a = rev_rotate(n, stacks->stack_a);
		stacks->stack_b = rev_rotate(n, stacks->stack_b);
	}
	ft_lstadd_back(instr, ft_lstnew(inst, 4));
	return (stacks);
}
