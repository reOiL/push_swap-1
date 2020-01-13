/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:53:15 by eblackbu          #+#    #+#             */
/*   Updated: 2020/01/13 14:53:39 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_min_elem(int n, t_int *stack)
{
	int		i;
	int		min;
	int		min_val;

	i = get_first_used(n, stack);
	min = 2147483647;
	min_val = 2147483647;
	while (i < n)
	{
		if (stack[i].value < min_val)
		{
			min_val = stack[i].value;
			min = i;
		}
		i++;
	}
	return (min);
}

int		any_more_than_mid(int n, int mid_elem, t_int *stack_a)
{
	int		i;

	i = 0;
	while (!stack_a[i].in_use)
		i++;
	while (i < n)
	{
		if (stack_a[i].value < mid_elem)
			return (1);
		i++;
	}
	return (0);
}
