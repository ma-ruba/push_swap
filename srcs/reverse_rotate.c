# include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*pre_last;

	tmp = *stack;
	if ((*stack)->prev)
	{
		while (tmp->prev->prev)
			tmp = tmp->prev;
		pre_last = tmp;
		tmp = tmp->prev;
		tmp->prev = *stack;
		pre_last->prev = NULL;
		*stack = tmp;
	}
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
