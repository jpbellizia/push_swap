/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:10:26 by vneves-c          #+#    #+#             */
/*   Updated: 2026/07/31 14:39:30 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_context *ctx)
{
	int	*v;

	v = ctx->a.values;
	if (v[0] < v[1] && v[1] < v[2])
		return ;
	if (v[0] > v[1] && v[1] < v[2] && v[0] < v[2])
		sa(ctx);
	else if (v[0] > v[1] && v[1] > v[2])
	{
		sa(ctx);
		rra(ctx);
	}
	else if (v[0] < v[1] && v[1] > v[2] && v[0] > v[2])
		rra(ctx);
	else if (v[0] > v[1] && v[1] < v[2] && v[0] > v[2])
		ra(ctx);
	else
	{
		sa(ctx);
		ra(ctx);
	}
}

void	sort_two(t_context *ctx)
{
	int	*v;

	v = ctx->a.values;
	if (v[0] > v[1])
		sa(ctx);
}

void	sort_five(t_context *ctx)
{
	rotate_a_to_top(ctx, find_min_index(&ctx->a));
	pb(ctx);
	rotate_a_to_top(ctx, find_min_index(&ctx->a));
	pb(ctx);
	sort_three(ctx);
	pa(ctx);
	pa(ctx);
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