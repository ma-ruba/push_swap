# include "push_swap.h"

void	swap(t_stack *stack)
{
	t_stack	*tmp;

	if (stack->prev)
	{
		tmp = stack->prev;
		stack->prev = tmp->prev;
		tmp->prev = stack;
	}
}

void    sa(t_stack *a)
{
    swap(a);
}

void    sb(t_stack *a)
{
    swap(b);
}

void    ss(t_stack *a, t_stack *b)
{
    swap(a);
    swap(b);
}
