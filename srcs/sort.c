# include "push_swap.h"

static void		sort_three(t_stack **a)
{
	while (!a_is_sorted(*a))
	{
		if ((*a)->data > (*a)->prev->data)
			sa(a, 1);
		else
			rra(a, 1);
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
	blocks = (int*)ft_memalloc(33);
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
		//print_stack(a); 
	}
	//print_stack(a); 
	blocks[i] = 0;
	if (check_three(a))
		sort_three(&a);
	else if (check_two(a))
		sort_two(&a);
	//print_stack(a);
	main_sort2(&a, &b, blocks, i);
	//print_stack(a);       
	free(blocks);
}

void		main_sort2(t_stack **a, t_stack **b, int *blocks, int i)
{
	t_stack	*med;
	int		count;
	int 	j;
	int		*index;
	int		k;

	count = 0;
	k = -1;
	index = ft_memalloc2(10, 34);
	while (--i >= 0)
	{
		//printf("%i\n", blocks[i]);
		//printf("%i\n", blocks[i + 1]);
		//print_stack(*a);
		//print_stack(*b);
		if (i == index[k])
		{
			j = blocks[i];
			while (j-- > 0)
				rrb(b, 1);
			index[k--] = 34;
		}
		//print_stack(*b);
		while (blocks[i] > 3)
		{
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
			//print_stack(*b);
			//print_stack(*a);
			j = sort_stack_a(a, b, count, &blocks[i]);
			if (j)
			{
				index[++k] = i;
				break ;
			}
			//print_stack(*a);
			//print_stack(*b); 
			j = blocks[i] - count;
			blocks[i] = j;
			while (j-- > 0)
				rrb(b, 1);
			count = 0;
		}
		if (index[k] == i)
		{
			blocks[i] -= count; 
			i += j + 1;
			count = 0;
		}
		else
		{
			if (blocks[i] == 3)
				sort_three_ontop(a, b);
			else if (blocks[i] == 2)
				sort_two_ontop(a, b);
			else if (blocks[i] == 1)
				pa(a, b, 1);
		}
	}
}

int	sort_stack_a(t_stack **a, t_stack **b, int count, int *blocks)
{
	t_stack	*med;
	int		j;
	int		k;

	k = 0;
	while (count > 3)
	{
		j = count + 1;
		//print_stack(*a);
		k++;
		blocks[k] = 0;
		med = find_mediana(*a, count);
		while (--j > 0)
		{
			if ((*a)->data >= med->data)
				ra(a, 1);
			else
			{
				pb(b, a, 1);
				count--;
				(blocks[k])++;
				//printf("%i\n", blocks[k]);
			}
		}
		j = count + 1;
		while (--j > 0)
			rra(a, 1);
	}
	if (count == 3)
		sort_three_ontop_a(a);
	if (count == 2)
		sort_three_ontop_a(a);
	return (k);
	//print_stack(*a);
	//print_stack(*b);
}
