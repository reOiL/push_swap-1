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

	if (ac < 2)
		return (0);
	if (!check_args(ac, av))
		return (false_print());
	if (!(stacks = init_stacks(ac, av)))
	{
		free_all(stacks, instructs);
		return (false_print());
	}
	if (ac - 1 < 4)
		instructs = get_algo(ac - 1, stacks); //TODO - сортировка для 3 элементов
	else
		instructs = get_algo(ac - 1, stacks);
	//print_stacks(ac - 1, stacks);
	print_instructs(instructs);
	//print_stacks(ac - 1, stacks);
	free_all(stacks, instructs);
	return (0);
}
