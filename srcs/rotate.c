/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:35:34 by bconwy            #+#    #+#             */
/*   Updated: 2019/06/15 19:35:36 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if ((*stack)->prev)
	{
		while (tmp->prev)
			tmp = tmp->prev;
		tmp->prev = *stack;
		tmp = (*stack)->prev;
		(*stack)->prev = NULL;
		*stack = tmp;
	}
}

void	ra(t_stack **a, int index)
{
	rotate(a);
	if (index == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int index)
{
	rotate(b);
	if (index == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int index)
{
	rotate(a);
	rotate(b);
	if (index == 1)
		write(1, "rr\n", 3);
}
