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

void		main_sort(t_stack *a, t_stack *b, int remain)
{
	t_stack	*med;
	int		count;
	int		*blocks;
	int		i;
	int 	j;	

	i = 0;
	count = 0;
	blocks = (int*)malloc(sizeof(int) * 33);
	while (!(check_three(a) || check_two(a)))
	{
		j = remain + 1;
		med = find_mediana(a, remain);
		while (--j > 0)
		{
			if (a->data >= med->data)
				ra(&a, 1);
			else
			{
				pb(&b, &a, 1);
				count++;
			}
		}
		blocks[i++] = count;
		remain -= count;
		count = 0;
	}
	blocks[i] = 0;
	if (check_three(a))
		sort_three(&a);
	else if (check_two(a))
		sort_two(&a);
	main_sort2(&a, &b, blocks, i);
	free(blocks);
}

void		main_sort2(t_stack **a, t_stack **b, int *blocks, int i)
{
	t_stack	*med;
	int		count;
	int 	j;
	int		index;

	count = 0;
	index = 34;
	while (--i >= 0)
	{
		print_stack(*a);
		print_stack(*b);
		while (blocks[i] > 3)
		{
			if (index == i)
			{
				j = blocks[i - 1];
				while (j-- > 0)
					rrb(b, 1);
			}
			med = find_mediana(*b, blocks[i]);
			j = blocks[i];
			while (j-- > 0)
			{
				if ((*b)->data < med->data)
					rb(b, 1);
				else
				{
					pa(a, b, 1);
					count++;
				}
			}
			print_stack(*b);
			print_stack(*a);
			sort_stack_a(a, b, count, &blocks[i + 1]);
			if (blocks[i + 1] != 0)
			{
				i += 2;
				index = i;
				break ;
			}
			j = blocks[i] - count;
			blocks[i] = j;
			while (j-- > 0)
				rrb(b, 1);
			count = 0;
		}
		if (blocks[i] == 3 && index != i)
			sort_three_ontop(a, b);
		else if (blocks[i] == 2 && index != i)
			sort_two_ontop(a, b);
		else if (index != i)
			pa(a, b, 1);
	}
}

void	sort_stack_a(t_stack **a, t_stack **b, int count, int *blocks)
{
	t_stack	*med;
	int		j;
	int		i;

	j = count + 1;
	*blocks = 0;
	while (count > 3)
	{
		print_stack(*a);
		med = find_mediana(*a, count);
		while (--j > 0)
		{
			if ((*a)->data >= med->data)
				ra(a, 1);
			else
			{
				pb(b, a, 1);
				count--;
				(*blocks)++;
			}
		}
		i = count + 1;
		while (--i > 0)
			rra(a, 1);
	}
	if (count == 3)
		sort_three_ontop_a(a);
	if (count == 2)
		sort_three_ontop_a(a);
	print_stack(*a);
	print_stack(*b);
}