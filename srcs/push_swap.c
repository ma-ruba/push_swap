# include "push_swap.h"

void		push_swap(t_stack *a, int argc)
{
	t_stack	*b;
	int		remain;

	remain = argc - 1;
	b = make_stack_b();
	main_sort(a, b, remain);
	clear_stack(a);
	//clear_stack(b);
}

int		call_push_swap(int argc, char **argv)
{
	if (!check_data(argc, argv))
	{
		if (argc == 2)
			clean_new_argv(argv);
		write(1, "Error\n", 6);
		return (0);
	}
	push_swap(make_stack_a(argc, argv), argc);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!call_push_swap(argc, one_arg(&argc, argv)))
			return (0);
	}
	else if (argc > 2)
	{
		if (!call_push_swap(argc, argv))
			return (0);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
