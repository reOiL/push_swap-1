/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:00:34 by eblackbu          #+#    #+#             */
/*   Updated: 2020/01/13 15:00:52 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_instructs(t_list *instructs)
{
	t_list *tmp;

	tmp = instructs;
	while (tmp)
	{
		ft_putendl((char*)tmp->content);
		tmp = tmp->next;
	}
}

int		main(int ac, char **av)
{
	t_form *stacks;
	t_list *instructs;

	instructs = NULL;
	if (ac < 2)
		return (0);
	if (!check_args(ac, av))
		return (false_print());
	if (!(stacks = init_stacks(ac, av)))
	{
		free_all(stacks, instructs);
		return (false_print());
	}
	if (ac == 4)
		stacks = three_elems_algo(ac - 1, stacks, &instructs);
	else
		instructs = get_algo(ac - 1, stacks);
	print_instructs(instructs);
	free_all(stacks, instructs);
	return (0);
}
