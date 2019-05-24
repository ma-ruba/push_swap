# include "push_swap.h"

void	checker(t_stack *a)
{

}

void	read_instructions()
{
	
}

int		call_cheker(int argc, argv)
{
	if (!check_data(argc, argv))
	{
		if (argc = 2)
			clean_new_argv(argv);
		write(1, "Error\n", 6);
		return (0);
	}
	cheker(make_stack_a(argc, argv));
	return (1);
}

int	main(int argc. char **argv)
{
	if (argc = 2)
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
