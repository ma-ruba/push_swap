/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:32:23 by bconwy            #+#    #+#             */
/*   Updated: 2019/06/15 19:32:28 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort_three(t_stack **a)
{
	while (!a_is_sorted(*a))
	{
		if ((*a)->data > (*a)->prev->data)
			sa(a, 1);
		else
			rra(a, 1);
	}
}

static void		sort_two(t_stack **stack)
{
	if ((*stack)->data > (*stack)->prev->data)
		sa(stack, 1);
}

static	void	main_sort_norma(t_stack **a)
{
	if (check_three(*a))
		sort_three(a);
	else if (check_two(*a))
		sort_two(a);
}

void			main_sort(t_stack *a, t_stack *b, int remain, int *blocks)
{
	t_norma	norm;

	norm.i = 0;
	while (!(check_three(a) || check_two(a)))
	{
		norm.count = 0;
		norm.j = remain + 1;
		norm.med = find_mediana(a, remain);
		while (--(norm.j) > 0)
		{
			if (a->data >= norm.med->data)
				ra(&a, 1);
			else
			{
				pb(&b, &a, 1);
				(norm.count)++;
			}
		}
		blocks[(norm.i)++] = norm.count;
		remain -= norm.count;
	}
	blocks[norm.i] = 0;
	main_sort_norma(&a);
	main_sort2(&a, &b, blocks, norm.i);
}
