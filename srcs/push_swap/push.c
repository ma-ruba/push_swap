# include "push_swap.h"

void	push(t_stack **stack1, t_stack **stack2)
{
	if (*stack2)
	{
		(*stack2)->prev = stack1;
		*stack1 = *stack2;
		*stack2 = (*stack2)->prev;
	}
}

void	pa(t_stack *a, t_stack *b)
{
	push(&a, &b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *b, t_stack *a)
{
	push(&b, &a);
	write(1, "pb\n", 3);
}
