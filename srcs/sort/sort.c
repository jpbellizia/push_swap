/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneves-c <vneves-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:10:26 by vneves-c          #+#    #+#             */
/*   Updated: 2026/07/30 14:42:30 by vneves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_context *ctx)
{
	if (is_sorted(&ctx->a) == 1)
		return ;
	if (ctx->mode == mode_simple)
		sort_simple(ctx);
}
