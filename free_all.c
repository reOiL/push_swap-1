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
