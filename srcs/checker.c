# include "push_swap.h"

void	checker(t_stack *a)
{
	char	*line;
	t_stack	*b;

	b = make_stack_b();
	while (get_next_line(0, &line) == 1)
		do_operations(line, b, a);
	check_stack(a, b);
	clear_stack(a);
	free(b);
}

void	do_operations(char *line, t_stack *b, t_stack *a)
{
	if (ft_strequ(line, "sa"))
		sa(&a);
	else if (ft_strequ(line, "sb"))
		sb(&b);
	else if (ft_strequ(line, "ra"))
		ra(&a);
	else if (ft_strequ(line, "rb"))
		rb(&b);
	else if (ft_strequ(line, "rra"))
		rra(&a);
	else if (ft_strequ(line, "rrb"))
		rrb(&b);
	else if (ft_strequ(line, "pa"))
		pa(&a, &b);
	else if (ft_strequ(line, "pb"))
		pb(&b, &a);
}

int		call_checker(int argc, char **argv)
{
	if (!check_data(argc, argv))
	{
		if (argc == 2)
			clean_new_argv(argv);
		write(1, "Error\n", 6);
		return (0);
	}
	checker(make_stack_a(argc, argv));
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!call_checker(argc, one_arg(&argc, argv)))
			return (0);
	}
	else if (argc > 2)
	{
		if (!call_checker(argc, argv))
			return (0);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
