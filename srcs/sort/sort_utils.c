/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:10:26 by vneves-c          #+#    #+#             */
/*   Updated: 2026/08/06 20:00:02 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->values[i] > stack->values[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	find_min_index(t_stack *stack)
{
	int	min_index;
	int	i;

	i = 1;
	min_index = 0;
	while (i < stack->size)
	{
		if (stack->values[i] < stack->values[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

void	rotate_a_to_top(t_context *ctx, int index)
{
	int	i;

	if (index <= ctx->a.size / 2)
	{
		i = 0;
		while (i < index)
		{
			ra(ctx);
			i++;
		}
	}
	else
	{
		i = ctx->a.size - index;
		while (i > 0)
		{
			rra(ctx);
			i--;
		}
	}
}
