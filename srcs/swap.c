/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:35:55 by bconwy            #+#    #+#             */
/*   Updated: 2019/06/15 19:35:57 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if ((*stack)->prev)
	{
		tmp = (*stack)->prev;
		(*stack)->prev = tmp->prev;
		tmp->prev = *stack;
		*stack = tmp;
	}
}

void	sa(t_stack **a, int index)
{
	swap(a);
	if (index == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int index)
{
	swap(b);
	if (index == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int index)
{
	swap(a);
	swap(b);
	if (index == 1)
		write(1, "ss\n", 3);
}
