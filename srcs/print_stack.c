# include "push_swap.h"
# include <stdio.h>

void	print_stack(t_stack *stack)
{
	int		dat;
	t_stack	*copy;

	copy = stack;
	while (copy)
	{
		dat = copy->data;
		printf("%i ", dat);
		copy = copy->prev;
	}
	write(1, "\n", 1);
}
