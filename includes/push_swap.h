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

#endif