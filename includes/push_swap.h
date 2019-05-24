#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# define MIN_INT  	-2147483648
# define MAX_INT  	2147483647

typedef struct      s_stack
{
	int				*data;
	struct s_stack  *prev;
}               	t_stack;

t_stack				*make_stack_a(int argc, char **argv);
t_stack				*make_stack_b(void);
t_stack				*stack_new_elem(t_stack *previous);
void    			clear_stack(t_stack *stack);
void				push_swap(t_stack *a, int argc, char **argv);
int					check_data(int argc, char **argv);
int     			check_duplicates(int argc, char **argv);
int					check_size(int argc, char **argv);
int					call_push_swap(int argc, argv);
int					call_cheker(int argc, argv);
char				**one_arg(int *argc, char **argv);
void				swap(t_stack *stack);
void				push(t_stack **stack1, t_stack **stack2);
void				rotate(t_stack *stack);
void				reverse_rotate(t_stack *stack);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *b, t_stack *a);
void    			sa(t_stack *a);
void   				sb(t_stack *a);
void    			ss(t_stack *a, t_stack *b);
void    			ra(t_stack *a);
void    			rb(t_stack *b);
void    			rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
void    			clean_new_argv(char **new_argv);
t_stack				*find_mediana(int argc, char **argv, t_stack *stack);
t_stack				*find_elem(int number, t_stack *stack);
t_stack				*find_last(t_stack *stack);

#endif