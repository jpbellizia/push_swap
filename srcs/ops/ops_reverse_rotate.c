/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:24:40 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/07/27 17:37:06 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_context *ctx)
{
    reverse_rotate(&ctx->a);
    emit(ctx, "rra", op_rra);
}

void rrb(t_context *ctx)
{
    reverse_rotate(&ctx->b);
    emit(ctx, "rrb", op_rrb);
}
