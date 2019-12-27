#include "push_swap.h"

int		main(int ac, char **av)
{
	t_form *stacks;
	t_list *instructs;

	if (!check_args(ac, av))
		return (false_print());
	if (!(stacks = init_stacks(ac, av)))
	{
		free_all(stacks, instructs);
		return (false_print());
	}
	instructs = get_algo(ac - 1, stacks);
	print_and_free(ac - 1, stacks, instructs);
	return (0);
}
