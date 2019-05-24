# include "push_swap.h"

int		check_data(int argc, char **argv)
{
	int		i;

	i = 0;
	while (argc > 1)
	{
		while (argv[argc - 1])
		{
			if (!(argv[argc - 1][i] >= '0' &&  argv[argc - 1][i] <= '9') &&
				argv[argc - 1][i] >= MIN_INT && argv[argc - 1][i] <= MAX_INT)
				return (0);
			i++;
		}
		i = 0;
		argc--;
	}
	return (1);
}

int     check_duplicates(int argc, char **argv) // not finished
{
    int		i;
    char    tmp;

	i = 0;
	while (argc > 1)
	{
        tmp = argv[argc - 1];
        argc--;
		while (argv[argc - 1])
		{
            if (argv[argc - 1] = tmp)
				return (0);
			i++;
		}
		i = 0;
		
	}
	return (1);
}
