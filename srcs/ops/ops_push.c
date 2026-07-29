/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:32:18 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/07/28 12:19:57 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_context *ctx)
{
	push(&ctx->a, pop(&ctx->b));
	emit(ctx, "pa", op_pa);
}

void	pb(t_context *ctx)
{
	push(&ctx->b, pop(&ctx->a));
	emit(ctx, "pb", op_pb);
}
