# include "push_swap.h"

void    sort_three_ontop(t_stack *stack)
{
    
}

int			check_two(t_stack *stack)
{
	int		count;

	count = 0;
	while (stack)
	{
		stack = stack->prev;
		count++;
	}
	if (count = 2)
		return (1);
	return (0);
}

int			check_three(t_stack *stack)
{
	int		count;

	count = 0;
	while (stack)
	{
		stack = stack->prev;
		count++;
	}
	if (count = 3)
		return (1);
	return (0);
}
