/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:10:26 by vneves-c          #+#    #+#             */
/*   Updated: 2026/08/04 17:16:46 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_disorder(t_context *ctx)
{
	int	integer_part;
	int	decimal_part;

	integer_part = ctx->disorder / 100;
	decimal_part = ctx->disorder % 100;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(integer_part, 2);
	ft_putstr_fd(".", 2);
	if (decimal_part < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(decimal_part, 2);
	ft_putstr_fd("%\n", 2);
}

void	print_mode(t_context *ctx)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (ctx->mode == mode_simple)
		ft_putstr_fd("Simple / O(n^2)", 2);
	else if (ctx->mode == mode_medium)
		ft_putstr_fd("Medium / O(n*sqrt(n))", 2);
	else if (ctx->mode == mode_complex)
		ft_putstr_fd("Complex / O(n log n)", 2);
	else
	{
		ft_putstr_fd("Adaptive / ", 2);
		if (ctx->disorder < 2000)
			ft_putstr_fd("O(n^2)", 2);
		else if (ctx->disorder < 5000)
			ft_putstr_fd("O(n*sqrt(n))", 2);
		else
			ft_putstr_fd("O(n log n)", 2);
	}
	ft_putstr_fd("\n", 2);
}
