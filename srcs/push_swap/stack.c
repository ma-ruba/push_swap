# include "push_swap.h"

t_stack	*stack_new_elem(t_stack *previous)
{
	t_stack	*new;

	new = (t_stack*)malloc(sizeof(t_stack));
	new->prev = previous;
	return (new);
}

t_stack	*make_stack_a(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	while (argc > 1)
	{
		a = stack_new_elem(a);
		a->data = ft_atoi(argv[argc - 1]);
		argc--;
	}
	return (a);
}

t_stack *make_stack_b(void)
{
	t_stack	*b;

	b = NULL;
	b = stack_new_elem(b);
	return (b);
}

void    clear_stack(t_stack *stack) // make sure everything is freed
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->prev;
		free((void*)stack);
		stack = tmp;
	}
}