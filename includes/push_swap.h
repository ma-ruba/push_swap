#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct      s_stack
{
	int				*data;
	struct s_stack  *prev;
}               	t_stack;

t_stack	*make_stack_a(int argc, char **argv);
t_stack	*stack_new_elem(t_stack *previous);
void	push_swap(t_stack *a);
int		check_data(int argc, char **argv);
void	swap(t_stack *stack);
void	push(t_stack **stack1, t_stack **stack2);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);
void    sa(t_stack *a);
void    sb(t_stack *a);
void    ss(t_stack *a, t_stack *b);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif