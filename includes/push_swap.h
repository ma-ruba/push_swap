#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# define MIN_INT  	-2147483648
# define MAX_INT  	2147483647
# define ASCEND		1
# define DESCEND	0

typedef struct      s_stack
{
	int				data;
	struct s_stack  *prev;
}               	t_stack;

t_stack				*make_stack_a(int argc, char **argv);
t_stack				*make_stack_b(void);
t_stack				*stack_new_elem(t_stack *previous);
void    			clear_stack(t_stack *stack);
void				push_swap(t_stack *a, int argc);
int					check_data(int argc, char **argv);
int     			check_duplicates(int argc, char **argv);
int					check_size(int argc, char **argv);
int					call_push_swap(int argc, char **argv);
int					call_cheker(int argc, char **argv);
char				**one_arg(int *argc, char **argv);
void				swap(t_stack **stack);
void				push(t_stack **stack1, t_stack **stack2);
void				rotate(t_stack **stack);
void				reverse_rotate(t_stack **stack);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **b, t_stack **a);
void    			sa(t_stack **a);
void   				sb(t_stack **b);
void    			ss(t_stack **a, t_stack **b);
void    			ra(t_stack **a);
void    			rb(t_stack **b);
void    			rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void    			clean_new_argv(char **new_argv);
t_stack				*find_mediana(t_stack *stack, int nb);
/*t_stack			*find_elem(int number, t_stack *stack);
t_stack				*find_last(t_stack *stack);*/
void				main_sort(t_stack *a, t_stack *b, int remain);
void				main_sort2(t_stack **a, t_stack **b, int *blocks, int i);
int					check_two(t_stack *stack);
int					check_three(t_stack *stack);
void    			sort_three_ontop(t_stack **b, t_stack **a);
void    			sort_two_ontop(t_stack **a, t_stack **b);
void				print_stack(t_stack *stack);

int					call_checker(int argc, char **argv);
void				do_operations(char *line, t_stack *b, t_stack *a);
void				checker(t_stack *a);
void				check_stack(t_stack *a, t_stack *b);

#endif