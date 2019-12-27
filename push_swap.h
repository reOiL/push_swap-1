#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "gnl/get_next_line.h"

typedef struct		s_int
{
	int 			value;
	int 			in_use;
}					t_int;

typedef struct		s_form
{
	t_int			*stack_a;
	t_int			*stack_b;
}					t_form;

//push_swap_helper.c
int					false_print(void);
int 				check_ints(char *val);
int					check_duplicates(int ac, char **av, int i);
int					check_args(int ac, char **av);

//stack_funcs_1.c
t_int				*init_stack_a(int ac, char **av);
t_int				*init_stack_b(int ac);
t_form				*init_stacks(int ac, char **av);
void				print_stacks(int n, t_form *stacks);

//free_all.c
void				free_all(t_form *stacks, t_list *instructs);

//sort_algo
t_list				*get_algo(int n, t_form *stacks);
#endif