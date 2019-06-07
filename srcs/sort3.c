# include "push_swap.h"

void    sort_three_ontop_a(t_stack **a)
{
	if ((*a)->data < (*a)->prev->data)
	{
		ra(a, 1);
		if ((*a)->data > (*a)->prev->data)
			sa(a, 1);
		rra(a, 1);
		if ((*a)->data > (*a)->prev->data)
			sa(a, 1);
	}
	else
	{
		sa(a, 1);
		ra(a, 1);
		if ((*a)->data > (*a)->prev->data)
			sa(a, 1);
		rra(a, 1);
		if ((*a)->data > (*a)->prev->data)
			sa(a, 1);
	}
}

void    sort_two_ontop_a(t_stack **a)
{
    if ((*a)->data > (*a)->prev->data)
		sa(a, 1);
}
