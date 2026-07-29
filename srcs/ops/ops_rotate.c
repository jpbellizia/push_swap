/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:05:36 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/07/28 12:28:05 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_context *ctx)
{
	rotate(&ctx->a);
	emit(ctx, "ra", op_ra);
}

void	rb(t_context *ctx)
{
	rotate(&ctx->b);
	emit(ctx, "rb", op_rb);
}

void	rr(t_context *ctx)
{
	rotate(&ctx->a);
	rotate(&ctx->b);
	emit(ctx, "rr", op_rr);
}
