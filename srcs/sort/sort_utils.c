/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:10:26 by vneves-c          #+#    #+#             */
/*   Updated: 2026/08/04 09:17:58 by vneves-c         ###   ########.fr       */
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

void	move_min_to_top_a(t_context *ctx)
{
	int	min_index;
	int	i;

	min_index = find_min_index(&ctx->a);
	i = 0;
	if (min_index <= ctx->a.size / 2)
	{
		while (i < min_index)
		{
			ra(ctx);
			i++;
		}
	}
	else
	{
		while (i < ctx->a.size - min_index)
		{
			rra(ctx);
			i++;
		}
	}
}
