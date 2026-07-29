/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:30:07 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/07/28 12:25:07 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_context *ctx)
{
	swap(&ctx->a);
	emit(ctx, "sa", op_sa);
}

void	sb(t_context *ctx)
{
	swap(&ctx->b);
	emit(ctx, "sb", op_sb);
}

void	ss(t_context *ctx)
{
	swap(&ctx->a);
	swap(&ctx->b);
	emit(ctx, "ss", op_ss);
}
