# include "push_swap.h"

static int	b_is_empty(t_stack *b)
{
	//if (b->prev == NULL)
		//return (1);
	b = NULL;
	return (1);
}

void		check_stack(t_stack *a, t_stack *b)
{
	if(a_is_sorted(a) && b_is_empty(b))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}
