# include "push_swap.h"

void		main_sort(t_sort *a, t_sort *b, int argc, char **argv)
{
	t_stack	*copy;
	t_stack	*med;
	int		count;
	int		*blocks;	

	copy = a;
	count = argc;
	blocks = (int*)malloc(sizeof(int) * 33);
	while (!(check_three(a) || check_two(a)))
	{
		med = find_mediana(count, argv);
		while (copy)
		{
			if (copy->data > med->data)
				ra(a);
			else
			{
				pb(b, copy);
				count--;
			}
			copy = copy->prev;
		}
	}
	if (check_three(a))
		sort_three(a, ASCEND);
	else if (check_two(a))
		sort_two(a, ASCEND);
	main_sort2(a, b, argc, argv);
	free(blocks);
}

void	main_sort2(t_sort *a, t_sort *b, char **argv)
{

}

void		sort_three(t_stack *stack, int order)
{
	t_sort	*copy;

	copy = stack;
	if (order = ASCEND)
	{
		if (copy->data > copy->prev->data)
			sa(stack);
		if (find_last(stack) < copy)
			rra(stack);
	}
	else
	{
		if (copy->data < copy->prev->data)
			sa(stack);
		if (find_last(stack) > copy)
			rra(stack);
	}
}

void		sort_two(t_stack *stack, int order)
{
	if (order = ASCEND)
	{
		if (stack->data > stack->prev->data)
			sa(stack);
	}
	else
		sb(stack);
}
