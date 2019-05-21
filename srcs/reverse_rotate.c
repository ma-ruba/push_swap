# include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	if (stack->prev)
	{
		while (tmp->prev)
			tmp = tmp->prev;
		tmp->prev = stack;
		stack->prev->prev = NULL;
	}
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
