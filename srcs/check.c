# include "push_swap.h"

int		check_data(int argc, char **argv)
{
	int		i;
	int		arg;

	i = 0;
	arg = argc;
	while (argc > 1)
	{
		while (argv[argc - 1][i])
		{
			if (!((argv[argc - 1][i] >= '0' &&  argv[argc - 1][i] <= '9') || argv[argc - 1][i] == '-'))
				return (0);
			i++;
		}
		i = 0;
		argc--;
	}
	if (!check_size(arg, argv))
		return (0);
	if (!check_duplicates(arg, argv))
		return (0);
	return (1);
}

int		check_size(int argc, char **argv)
{
	long long	data;


	while (argc > 1)
	{
		data = ft_atoi(argv[argc - 1]);
		if (!(data >= MIN_INT && data <= MAX_INT))
			return (0);
		argc--;
	}
	return (1);
}

int     check_duplicates(int argc, char **argv)
{
    int		i;

	i = argc - 2;
	while (argc > 1)
	{
		while (i > 0)
		{
            if (ft_strequ(argv[argc - 1], argv[i]))
				return (0);
			i--;
		}
		argc--;
		i = argc - 2;
	}
	return (1);
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
