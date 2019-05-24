# include "push_swap.h"

void    clean_new_argv(char **new_argv)
{
	int i;

	i = 0
	while (new_argv[i])
	{
		free((void*)new_argv[i]);
		i++;
	}
	free(new_argv);
}
