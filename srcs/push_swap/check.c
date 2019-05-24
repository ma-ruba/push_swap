# include "push_swap.h"

int		check_data(int argc, char **argv)
{
	int		i;

	i = 0;
	while (argc > 1)
	{
		while (argv[argc - 1][i])
		{
			if (!(argv[argc - 1][i] >= '0' &&  argv[argc - 1][i] <= '9'))
				return (0);
			i++;
		}
		i = 0;
		argc--;
	}
	if (!check_size(argc, argv))
		return (0);
	if (!check_duplicates(argc, argc))
		return (0);
	return (1);
}

int		check_size(int argc, char **argv)
{
	int	arr[argc - 2];


	while (argc > 1)
	{
		arr[argc - 2] = ft_atoi(argv[argc - 1]);
		if (!(arr[argc - 2] >= MIN_INT && arr[argc - 2] <= MAX_INT))
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
		while (i > 1)
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
