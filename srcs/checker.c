/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:34:08 by bconwy            #+#    #+#             */
/*   Updated: 2019/06/15 19:34:10 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		checker(t_stack *a)
{
	char	*line;
	t_stack	*b;

	b = make_stack_b();
	while (get_next_line(0, &line) == 1)
		do_operations(line, &b, &a);
	check_stack(a, b);
	clear_stack(a);
	free(b);
}

static void	put_error(char *line)
{
	write(1, "Error\n", 6);
	free(line);
	exit(1);
}

void		do_operations(char *line, t_stack **b, t_stack **a)
{
	if (ft_strequ(line, "sa"))
		sa(a, 0);
	else if (ft_strequ(line, "sb"))
		sb(b, 0);
	else if (ft_strequ(line, "ra"))
		ra(a, 0);
	else if (ft_strequ(line, "rb"))
		rb(b, 0);
	else if (ft_strequ(line, "rr"))
		rr(a, b, 0);
	else if (ft_strequ(line, "rra"))
		rra(a, 0);
	else if (ft_strequ(line, "rrb"))
		rrb(b, 0);
	else if (ft_strequ(line, "rrr"))
		rrr(a, b, 0);
	else if (ft_strequ(line, "pa"))
		pa(a, b, 0);
	else if (ft_strequ(line, "pb"))
		pb(b, a, 0);
	else
		put_error(line);
	free(line);
}

int			call_checker(int argc, char **argv)
{
	if (!check_data(argc, argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	checker(make_stack_a(argc, argv));
	return (1);
}

int			main(int argc, char **argv)
{
	char	**new_argv;

	if (argc == 2)
	{
		new_argv = one_arg(&argc, argv);
		if (!call_checker(argc, new_argv))
		{
			clean_new_argv(new_argv);
			return (0);
		}
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
