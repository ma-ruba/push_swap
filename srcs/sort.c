# include "push_swap.h"

static void		sort_three(t_stack **a)
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

static void		sort_two(t_stack **stack)
{
	if ((*stack)->data > (*stack)->prev->data)
		sa(stack, 1);
}

static	void	main_sort_norma(t_stack *a)
{
	if (check_three(a))
		sort_three(&a);
	else if (check_two(a))
		sort_two(&a);
}

void		main_sort(t_stack *a, t_stack *b, int remain, int *blocks)
{
	t_norma	norm;

	norm.i = 0;
	while (!(check_three(a) || check_two(a)))
	{
		norm.count = 0;
		norm.j = remain + 1;
		norm.med = find_mediana(a, remain);
		while (--(norm.j) > 0)
		{
			if (a->data >= norm.med->data)
				ra(&a, 1);
			else
			{
				pb(&b, &a, 1);
				(norm.count)++;
			}
		}
		blocks[(norm.i)++] = norm.count;
		remain -= norm.count;
	}
	blocks[norm.i] = 0;
	main_sort_norma(a);
	main_sort2(&a, &b, blocks, norm.i);
	print_stack(a);       
}

static void	main_sort2_norma(int *blocks, int i, t_stack **a, t_stack **b)
{
	if (blocks[i] == 3)
		sort_three_ontop(a, b);
	else if (blocks[i] == 2)
		sort_two_ontop(a, b);
	else if (blocks[i] == 1)
		pa(a, b, 1);
}

static void	main_sort_norma2(t_norma *norm, int *blocks, t_stack **a, t_stack **b)
{
	while (*blocks > 3)
	{
		norm->med = find_mediana(*b, *blocks);
		norm->j = *blocks;
		while ((norm->j)-- > 0)
		{
			if ((*b)->data < norm->med->data)
				rb(b, 1);
			else
			{
				pa(a, b, 1);
				(norm->count)++;
			}
		}
		norm->j = sort_stack_a(a, b, norm->count, blocks);
		if (norm->j)
		{
			norm->index = norm->i;
			break ;
		}
		norm->j = *blocks - norm->count;
		*blocks = norm->j;
		while ((norm->j)-- > 0)
			rrb(b, 1);
	}
}

void		main_sort2(t_stack **a, t_stack **b, int *blocks, int i)
{
	t_norma	norm;

	norm.index = 34;
	while (--i >= 0)
	{
		norm.count = 0;
		if (i == norm.index)
		{
			norm.j = blocks[i];
			while ((norm.j)-- > 0)
				rrb(b, 1);
			norm.index = 34;
		}
		norm.i = i;
		main_sort_norma2(&norm, &blocks[i], a, b);
		if (norm.index == i)
		{
			blocks[i] -= norm.count; 
			i += norm.j + 1;
		}
		else
			main_sort2_norma(blocks, i, a, b);
	}
}
