/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:10:26 by vneves-c          #+#    #+#             */
/*   Updated: 2026/08/04 09:17:58 by vneves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_bits(int n)
{
	int	bits;

	bits = 0;
	while (n > 0)
	{
		bits++;
		n = n >> 1;
	}
	return (bits);
}

void	sort_complex(t_context *ctx)
{
	int	max_bits;
	int	b;
	int	i;
	int	size;

	max_bits = count_bits(ctx->a.size - 1);
	b = 0;
	while (b < max_bits)
	{
		size = ctx->a.size;
		i = 0;
		while (i < size)
		{
			if (((ctx->a.values[0] >> b) & 1) == 0)
				pb(ctx);
			else
				ra(ctx);
			i++;
		}
		while (ctx->b.size > 0)
			pa(ctx);
		b++;
	}
}
