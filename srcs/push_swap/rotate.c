# include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	if (stack->prev)
	{
		while (tmp->prev)
			tmp = tmp->prev;
		tmp->prev = stack;
		stack->prev = NULL;
	}
}

void    ra(t_stack *a)
{
    rotate(a);
	write(1, "ra\n", 3);
}

void    rb(t_stack *b)
{
    rotate(b);
	write(1, "rb\n", 3);
}

void    rr(t_stack *a, t_stack *b)
{
    rotate(a);
    rotate(b);
	write(1, "rr\n", 3);
}
