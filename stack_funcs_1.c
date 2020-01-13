/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:09:23 by eblackbu          #+#    #+#             */
/*   Updated: 2020/01/13 16:45:42 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_int		*init_stack_a(int ac, char **av)
{
	int		i;
	t_int	*stack_a;

	i = 1;
	if (!(stack_a = (t_int*)malloc(sizeof(t_int) * (ac - 1))))
		return (NULL);
	while (i < ac)
	{
		stack_a[i - 1].value = ft_atoi(av[i]);
		stack_a[i - 1].in_use = 1;
		stack_a[i - 1].min_instr = 0;
		i++;
	}
	return (stack_a);
}

t_int		*init_stack_b(int ac)
{
	int		i;
	t_int	*stack_b;

	i = 1;
	if (!(stack_b = (t_int*)malloc(sizeof(t_int) * (ac - 1))))
		return (NULL);
	while (i < ac)
	{
		stack_b[i - 1].value = 0;
		stack_b[i - 1].in_use = 0;
		stack_b[i - 1].min_instr = 0;
		i++;
	}
	return (stack_b);
}

t_form		*init_stacks(int ac, char **av)
{
	t_form		*form;

	if (!(form = (t_form*)malloc(sizeof(t_form))))
		return (NULL);
	if (!(form->stack_a = init_stack_a(ac, av)))
	{
		free(form);
		return (NULL);
	}
	if (!(form->stack_b = init_stack_b(ac)))
	{
		free(form->stack_a);
		free(form);
		return (NULL);
	}
	return (form);
}
