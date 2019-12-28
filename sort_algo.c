#include "push_swap.h"

int 		is_empty(int n, t_int *stack)
{
	int 	i;

	i = 0;
	while (i < n)
	{
		if (stack[i].in_use)
			return (0);
		i++;
	}
	return (1);
}

int 		is_sorted(int n, t_int *stack)
{
	int 	i;

	i = 0;
	while (!stack[i].in_use)
		i++;
	while (i < n - 1)
	{
		if (stack[i].value > stack[i + 1].value)
			return (0);
		i++;
	}
	return (1);
}

t_list		*push_back(int n, t_form *stacks, t_list **instr)
{
	while (!is_empty(n, stacks->stack_b))
	{
		stacks = make_p(n, "pa", stacks);
		ft_lstadd_front(instr, ft_lstnew("pa", 3));
	}
	return (*instr);
}

t_list		*get_algo(int n, t_form *stacks)
{
	int 	min;
	int 	flag;
	t_list	*instr;

	instr = NULL;
	while (!is_sorted(n, stacks->stack_a))
	{
		flag = 0;
		min = get_min(n, &flag, stacks->stack_a);
		while (get_peek(n, stacks->stack_a) != min)
		{
			stacks = flag ? make_rr(n, "rra", stacks) : make_r(n ,"ra", stacks);
			if (flag)
				ft_lstadd_front(&instr, ft_lstnew("rra", 4));
			else
				ft_lstadd_front(&instr, ft_lstnew("ra", 3));
			//print_stacks(n, stacks);
		}
		if (is_sorted(n, stacks->stack_a))
			return (push_back(n, stacks, &instr));
		stacks = make_p(n, "pb", stacks);
		ft_lstadd_front(&instr, ft_lstnew("pb", 3));
		//print_stacks(n, stacks);
	}
	return (push_back(n, stacks, &instr));
}
