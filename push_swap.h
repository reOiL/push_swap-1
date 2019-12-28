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

//stack_funcs_1.c
int					get_min(int n, int *flag, t_int *stack);
int					get_peek(int n, t_int *stack);

//free_all.c
void				free_all(t_form *stacks, t_list *instructs);

//sort_algo
int 				is_empty(int n, t_int *stack);
int 				is_sorted(int n, t_int *stack);
t_list				*push_back(int n, t_form *stacks, t_list **instr);
t_list				*get_algo(int n, t_form *stacks);

//s_funcs.c
t_int				*swap(int n, t_int* stack);
t_form				*make_s(int n, char *inst, t_form *stacks);

//p_funcs.c
t_form				*make_p(int n, char *inst, t_form *stacks);

//r_funcs.c
t_int				*rotate(int n, t_int* stack);
t_form				*make_r(int n, char *inst, t_form *stacks);

//rr_funcs.c
t_int				*rev_rotate(int n, t_int* stack);
t_form				*make_rr(int n, char *inst, t_form *stacks);

#endif