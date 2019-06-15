/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:33:24 by bconwy            #+#    #+#             */
/*   Updated: 2019/06/15 19:33:27 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap(t_stack *a, int argc)
{
	t_stack	*b;
	int		remain;
	int		*blocks;

	blocks = (int*)ft_memalloc(33);
	remain = argc - 1;
	b = make_stack_b();
	if (!(argc == 2 || a_is_sorted(a)))
		main_sort(a, b, remain, blocks);
	clear_stack(a);
	free(blocks);
}

int			call_push_swap(int argc, char **argv)
{
	if (!check_data(argc, argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	push_swap(make_stack_a(argc, argv), argc);
	return (1);
}

int			main(int argc, char **argv)
{
	char	**new_argv;

	if (argc == 2)
	{
		new_argv = one_arg(&argc, argv);
		if (!call_push_swap(argc, new_argv))
		{
			clean_new_argv(new_argv);
			return (0);
		}
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
