# include "push_swap.h"

void    sort_three_ontop(t_stack *b)
{
	if (b->data > b->prev->data)
	{
		rb(b);
		if (b->data < b->prev->data)
			sb(b);
		rrb(b);
		if (b->data < b->prev->data)
			sb(b);
	}
	else
	{
		sb(b);
		rb(b);
		if (b->data < b->prev->data)
			sb(b);
		rrb(b);
		if (b->data < b->prev->data)
			sb(b);
	}
}

void    sort_two_ontop(t_stack *a, t_stack *b)
{
    if (b->data > b->prev->data)
		pa(a, b);
	else
	{
		sb(b);
		pa(a, b);
	}
	pa(a, b);
}

int			check_two(t_stack *stack)
{
	int		count;
	t_stack	*copy;

	count = 0;
	copy = stack;
	while (copy)
	{
		copy = copy->prev;
		count++;
	}
	if (count == 2)
		return (1);
	return (0);
}

int			check_three(t_stack *stack)
{
	int		count;
	t_stack	*copy;

	count = 0;
	copy = stack;
	while (copy)
	{
		copy = copy->prev;
		count++;
	}
	if (count == 3)
		return (1);
	return (0);
}
