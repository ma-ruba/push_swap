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

typedef struct 		s_norma
{
	t_stack			*med;
	int				k;
	int				j;
	int				i;
	int				count;
	int				index;
}					t_norma;


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
void				pa(t_stack **a, t_stack **b, int index);
void				pb(t_stack **b, t_stack **a, int index);
void    			sa(t_stack **a, int index);
void   				sb(t_stack **b, int index);
void    			ss(t_stack **a, t_stack **b, int index);
void    			ra(t_stack **a, int index);
void    			rb(t_stack **b, int index);
void    			rr(t_stack **a, t_stack **b, int index);
void				rra(t_stack **a, int index);
void				rrb(t_stack **b, int index);
void				rrr(t_stack **a, t_stack **b, int index);
void    			clean_new_argv(char **new_argv);
t_stack				*find_mediana(t_stack *stack, int nb);
void				main_sort(t_stack *a, t_stack *b, int remain);
void				main_sort2(t_stack **a, t_stack **b, int *blocks, int i);
int					sort_stack_a(t_stack **a, t_stack **b, int count, int *blocks);
int					check_two(t_stack *stack);
int					check_three(t_stack *stack);
void    			sort_three_ontop(t_stack **b, t_stack **a);
void    			sort_two_ontop(t_stack **a, t_stack **b);
void    			sort_three_ontop_a(t_stack **a);
void				print_stack(t_stack *stack);
void    			sort_two_ontop_a(t_stack **a);
int					call_checker(int argc, char **argv);
void				do_operations(char *line, t_stack **b, t_stack **a);
void				checker(t_stack *a);
void				check_stack(t_stack *a, t_stack *b);
int					a_is_sorted(t_stack *a);

#endif