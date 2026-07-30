/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneves-c <vneves-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:10:26 by vneves-c          #+#    #+#             */
/*   Updated: 2026/07/30 14:28:12 by vneves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_stack *stack)
{
	int	i;
	int	min;

	i = 1;
	min = 0;
	while (i < stack->size)
	{
		if (stack->values[i] < stack->values[min])
			min = i;
		i++;
	}
	return (min);
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

void	sort_simple(t_context *ctx)
{
	int	min;

	while (ctx->a.size > 0)
	{
		min = find_min_index(&ctx->a);
		rotate_a_to_top(ctx, min);
		pb(ctx);
	}
	while (ctx->b.size > 0)
		pa(ctx);
}
