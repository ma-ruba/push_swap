# include "push_swap.h"

void	push_swap(t_stack *a)
{

}

char	**one_arg(int *argc, char **argv)
{
	char	**new_argv;
	char	**tmp;
	int		count;

	count = 0;
	tmp = ft_strsplit(argv[2], ' ');
	while (tmp[count])
		count++;
	new_argv = (char**)malloc(sizeof(char*) * (count + 2));
	new_argv[1] = ft_strdup(argv[1]);
	*argc = count + 1;
	new_argv[count + 1] = NULL;
	count = 1;
	while (new_argv[count])
	{
		new_argv[count] = ft_strdup(tmp[count -1]);
		count++;
	}
	clean_new_argv(tmp);
	return (new_argv);
}

int		call_push_swap(int argc, argv)
{
	if (!check_data(argc, argv))
	{
		if (argc = 2)
			clean_new_argv(argv);
		write(1, "Error\n", 6);
		return (0);
	}
	push_swap(make_stack_a(argc, argv));
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc = 2)
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
