# include "push_swap.h"

static t_stack 	*find_last(t_stack *stack)
{
	t_stack	*last;

	last = stack;
	while (last->prev)
		last = last->prev;
	return (last);
}

static void		sort_three(t_stack *stack)
{
	if (stack->data > stack->prev->data)
		sa(stack);
	if (find_last(stack)->data < stack->data)
		rra(stack);
}

static void		sort_two(t_stack *stack)
{
	if (stack->data > stack->prev->data)
		sa(stack);
}

void		main_sort(t_stack *a, t_stack *b, int argc)
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
		if (i == 0)
			j = argc;
		else
			j = argc - blocks[i - 1];
		med = find_mediana(a, j - 1);
		while (--j > 0)
		{
			if (a->data >= med->data)
				ra(a);
			else
			{
				pb(b, a);
				count++;
			}
		}
		blocks[i++] = count;
		count = 0;
	}
	blocks[i] = 0;
	if (check_three(a))
		sort_three(a);
	else if (check_two(a))
		sort_two(a);
	main_sort2(a, b, blocks, i);
	free(blocks);
}

void		main_sort2(t_stack *a, t_stack *b, int *blocks, int i)
{
	t_stack	*med;
	int		count;
	int 	j;

	count = 0;
	while (--i >= 0)
	{
		while (blocks[i] > 3)
		{
			med = find_mediana(b, blocks[i]);
			j = blocks[i];
			while (j-- > 0)
			{
				if (b->data <= med->data)
					rb(b);
				else
				{
					pa(a, b);
					count++;
				}
			}
			j = blocks[i] - count;
			blocks[i] = j;
			while (j-- > 0)
				rrb(b);
		}
		if (blocks[i] == 3)
			sort_three_ontop(a, b);
		else if (blocks[i] == 2)
			sort_two_ontop(a, b);
	}
}
