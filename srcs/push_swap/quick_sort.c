# include "push_swap.h"

void    quick_sort()
{



}

t_stack	*find_mediana(int argc, char **argv)
{
	int	arr[argc - 2];
	int	length;

	length = argc - 1;
	while (argc > 1)
	{
		arr[argc - 2] = ft_atoi(argv[argc - 1]);
		argc--;
	}
	
}

t_stack *find_last(t_stack *stack)
{
	t_stack	*last;

	while (stack->prev)
		stack = stack->prev;
	last = stack;
	return (stack);
}
