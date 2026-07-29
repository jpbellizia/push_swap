/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:24:40 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/07/28 12:29:13 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_context *ctx)
{
	reverse_rotate(&ctx->a);
	emit(ctx, "rra", op_rra);
}

void	rrb(t_context *ctx)
{
	reverse_rotate(&ctx->b);
	emit(ctx, "rrb", op_rrb);
}

void	rrr(t_context *ctx)
{
	reverse_rotate(&ctx->a);
	reverse_rotate(&ctx->b);
	emit(ctx, "rrr", op_rrr);
}
