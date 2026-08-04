/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:10:26 by vneves-c          #+#    #+#             */
/*   Updated: 2026/08/04 15:51:06 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_context *ctx)
{
	if (is_sorted(&ctx->a))
		return ;
	if (ctx->a.size == 2)
		sort_two(ctx);
	else if (ctx->a.size == 3)
		sort_three(ctx);
	else if (ctx->a.size == 4)
		sort_four(ctx);
	else if (ctx->a.size == 5)
		sort_five(ctx);
	else if (ctx->mode == mode_simple)
		sort_simple(ctx);
	else if (ctx->mode == mode_medium)
		sort_medium(ctx);
	else if (ctx->mode == mode_complex)
		sort_complex(ctx);
	else
		sort_adaptive(ctx);
}
