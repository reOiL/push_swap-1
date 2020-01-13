/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:50:19 by eblackbu          #+#    #+#             */
/*   Updated: 2020/01/13 14:50:20 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_form *stacks, t_list *instructs)
{
	t_list	*tmp;

	if (stacks)
	{
		free(stacks->stack_a);
		free(stacks->stack_b);
		free(stacks);
	}
	tmp = instructs;
	while (tmp)
	{
		instructs = instructs->next;
		free(tmp->content);
		free(tmp);
		tmp = instructs;
	}
}
