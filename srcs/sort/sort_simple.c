/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:10:26 by vneves-c          #+#    #+#             */
/*   Updated: 2026/08/06 19:57:11 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
