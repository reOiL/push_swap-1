#include "push_swap.h"

int		false_print(void)
{
	ft_putstr("Error\n");
	return (0);
}

int 	check_ints(char *val)
{
	char	*check;

	check = ft_itoa(ft_atoi(val));
	if (ft_strequ(val, check))
	{
		free(check);
		return (1);
	}
	if (check)
		free(check);
	return (0);
}

int 	check_duplicates(int ac, char **av, int i)
{
	int 	n;

	n = i + 1;
	while (n <= ac)
	{
		if (ft_strequ(av[i], av[n]))
			return (0);
		n++;
	}
	return (1);
}

int		check_args(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac < 0)
		return (0);
	while (i < ac)
	{
		if (!check_ints(av[i]) || !(check_duplicates(ac, av, i)))
			return (0);
		i++;
	}
	return (1);
}

int		get_first_used(int n, t_int *stack)
{
	int		i;

	i = 0;
	while (!stack[i].in_use)
		i++;
	return (i);
}