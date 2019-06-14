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

static void	sort_stack_a2(int count, t_stack **a)
{
	if (count == 3)
		sort_three_ontop_a(a);
	else if (count == 2)
		sort_three_ontop_a(a);
}

int			sort_stack_a(t_stack **a, t_stack **b, int count, int *blocks)
{
	t_norma	norm;

	norm.k = 0;
	while (count > 3)
	{
		norm.j = count + 1;
		blocks[++(norm.k)] = 0;
		norm.med = find_mediana(*a, count);
		while (--(norm.j) > 0)
		{
			if ((*a)->data >= norm.med->data)
				ra(a, 1);
			else
			{
				pb(b, a, 1);
				count--;
				(blocks[norm.k])++;
			}
		}
		norm.j = count + 1;
		while (--(norm.j) > 0)
			rra(a, 1);
	}
	sort_stack_a2(count, a);
	return (norm.k);
}
