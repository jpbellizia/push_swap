/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:10:26 by vneves-c          #+#    #+#             */
/*   Updated: 2026/08/07 11:23:43 by vneves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_stack *stack)
{
	int	i;
	int	max;

	i = 1;
	max = 0;
	while (i < stack->size)
	{
		if (stack->values[i] > stack->values[max])
			max = i;
		i++;
	}
	return (max);
}

int	get_chunk_size(int size)
{
	if (size <= 100)
		return (20);
	return (40);
}

static void	push_chunks_to_b(t_context *ctx, int chunk)
{
	int	i;

	i = 0;
	while (ctx->a.size > 0)
	{
		if (ctx->a.values[0] <= i)
		{
			pb(ctx);
			rb(ctx);
			i++;
		}
		else if (ctx->a.values[0] <= i + chunk)
		{
			pb(ctx);
			i++;
		}
		else
			ra(ctx);
	}
}

static void	rotate_b_to_top(t_context *ctx, int index)
{
	int	i;

	if (index <= ctx->b.size / 2)
	{
		i = 0;
		while (i < index)
		{
			rb(ctx);
			i++;
		}
	}
	else
	{
		i = ctx->b.size - index;
		while (i > 0)
		{
			rrb(ctx);
			i--;
		}
	}
}

void	sort_medium(t_context *ctx)
{
	push_chunks_to_b(ctx, get_chunk_size(ctx->a.size));
	while (ctx->b.size > 0)
	{
		rotate_b_to_top(ctx, find_max_index(&ctx->b));
		pa(ctx);
	}
}
