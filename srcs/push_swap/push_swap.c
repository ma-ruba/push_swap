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
		a->data = (int)argv[argc - 1];
		argc--;
	}
	return (a);
}

/*t_stack *make_stack_b(void)
{
	t_stack	*b;

	b = NULL;
	b = stack_new_elem(b);
	return (b);
}*/

void	push_swap(t_stack *a)
{

}

int		main(int argc, char **argv)
{
	if (argc >= 2)
	{
		if (!check_data(argc, argv))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		push_swap(make_stack_a(argc, argv));
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
