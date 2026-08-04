/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:10:26 by vneves-c          #+#    #+#             */
/*   Updated: 2026/08/01 01:03:11 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_context *ctx)
{
	int	*v;

	v = ctx->a.values;
	if (v[0] > v[1])
		sa(ctx);
}

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

void	sort_four(t_context *ctx)
{
	rotate_a_to_top(ctx, find_min_index(&ctx->a));
	pb(ctx);
	sort_three(ctx);
	pa(ctx);
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
