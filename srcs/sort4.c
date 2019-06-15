/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:33:10 by bconwy            #+#    #+#             */
/*   Updated: 2019/06/15 19:33:13 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	main_sort2_norma(int *blocks, int i, t_stack **a, t_stack **b)
{
	if (blocks[i] == 3)
		sort_three_ontop(a, b);
	else if (blocks[i] == 2)
		sort_two_ontop(a, b);
	else if (blocks[i] == 1)
		pa(a, b, 1);
}

static void	main_sort_norma2(t_norma *norm, int *blocks, t_stack **a,
			t_stack **b)
{
	while (*blocks > 3)
	{
		norm->med = find_mediana(*b, *blocks);
		norm->j = *blocks;
		while ((norm->j)-- > 0)
		{
			if ((*b)->data < norm->med->data)
				rb(b, 1);
			else
			{
				pa(a, b, 1);
				(norm->count)++;
			}
		}
		norm->j = sort_stack_a(a, b, norm->count, blocks);
		if (norm->j)
		{
			norm->index[++(norm->k)] = norm->i;
			break ;
		}
		norm->j = *blocks - norm->count;
		*blocks = norm->j;
		while ((norm->j)-- > 0)
			rrb(b, 1);
	}
}

void		main_sort2(t_stack **a, t_stack **b, int *blocks, int i)
{
	t_norma	norm;

	norm.index = ft_memalloc2(10, 34);
	norm.k = -1;
	//norm.index[norm.k] = 34;
	while (--i >= 0)
	{
		norm.count = 0;
		if (i == norm.index[norm.k])
		{
			norm.j = blocks[i];
			while ((norm.j)-- > 0)
				rrb(b, 1);
			norm.index[(norm.k)--] = 34;
		}
		norm.i = i;
		main_sort_norma2(&norm, &blocks[i], a, b);
		if (norm.index[norm.k] == i)
		{
			blocks[i] -= norm.count;
			i += norm.j + 1;
		}
		else
			main_sort2_norma(blocks, i, a, b);
	}
	free(norm.index);
}
