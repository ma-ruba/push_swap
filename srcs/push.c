# include "push_swap.h"

void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*tmp;

	if (*stack2)
	{
		tmp = (*stack2)->prev;
		(*stack2)->prev = *stack1;
		*stack1 = *stack2;
		*stack2 = tmp;
	}
}

void	pa(t_stack **a, t_stack **b, int index)
{
	push(a, b);
	if (index == 1)
		write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a, int index)
{
	push(b, a);
	if (index == 1)
		write(1, "pb\n", 3);
}
