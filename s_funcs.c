/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_funcs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:06:25 by eblackbu          #+#    #+#             */
/*   Updated: 2020/01/13 15:06:54 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_int	*swap(int n, t_int *stack)
{
	int		i;
	int		tmp;

	i = 0;
	while (stack[i].in_use == 0)
		i++;
	if (i + 1 < n)
	{
		tmp = stack[i + 1].value;
		stack[i + 1].value = stack[i].value;
		stack[i].value = tmp;
	}
	return (stack);
}

t_form	*make_s(int n, char *inst, t_form *stacks, t_list **instr)
{
	if (inst[1] == 'a')
		stacks->stack_a = swap(n, stacks->stack_a);
	else if (inst[1] == 'b')
		stacks->stack_b = swap(n, stacks->stack_b);
	else
	{
		stacks->stack_a = swap(n, stacks->stack_a);
		stacks->stack_b = swap(n, stacks->stack_b);
	}
	ft_lstadd_back(instr, ft_lstnew(inst, 4));
	return (stacks);
}
