/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:10:26 by vneves-c          #+#    #+#             */
/*   Updated: 2026/08/07 11:21:47 by vneves-c         ###   ########.fr       */
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

void	print_total(t_context *ctx)
{
	int	acum;
	int	i;

	acum = 0;
	i = 0;
	while (i < op_total)
	{
		acum += ctx->count[i];
		i++;
	}
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(acum, 2);
	ft_putstr_fd("\n", 2);
}

void	print_counts(t_context *ctx)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(ctx->count[op_sa], 2);
	ft_putstr_fd("  sb: ", 2);
	ft_putnbr_fd(ctx->count[op_sb], 2);
	ft_putstr_fd("  ss: ", 2);
	ft_putnbr_fd(ctx->count[op_ss], 2);
	ft_putstr_fd("  pa: ", 2);
	ft_putnbr_fd(ctx->count[op_pa], 2);
	ft_putstr_fd("  pb: ", 2);
	ft_putnbr_fd(ctx->count[op_pb], 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(ctx->count[op_ra], 2);
	ft_putstr_fd("  rb: ", 2);
	ft_putnbr_fd(ctx->count[op_rb], 2);
	ft_putstr_fd("  rr: ", 2);
	ft_putnbr_fd(ctx->count[op_rr], 2);
	ft_putstr_fd("  rra: ", 2);
	ft_putnbr_fd(ctx->count[op_rra], 2);
	ft_putstr_fd("  rrb: ", 2);
	ft_putnbr_fd(ctx->count[op_rrb], 2);
	ft_putstr_fd("  rrr: ", 2);
	ft_putnbr_fd(ctx->count[op_rrr], 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_context *ctx)
{
	print_disorder(ctx);
	print_mode(ctx);
	print_total(ctx);
	print_counts(ctx);
}
