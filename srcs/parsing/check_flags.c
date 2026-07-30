/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:06:58 by vneves-c          #+#    #+#             */
/*   Updated: 2026/07/30 11:46:35 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_flag(char *arg)
{
	if (ft_strcmp(arg, "--simple") == 0 || ft_strcmp(arg, "--medium") == 0
		|| ft_strcmp(arg, "--complex") == 0 || ft_strcmp(arg, "--adaptive") == 0
		|| ft_strcmp(arg, "--bench") == 0)
		return (1);
	return (0);
}

void	define_mode(int argc, char **argv, t_context *ctx)
{
	int	i;

	i = 1;
	ctx->mode = mode_none;
	ctx->bench = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--simple") == 0)
			ctx->mode = mode_simple;
		else if (ft_strcmp(argv[i], "--medium") == 0)
			ctx->mode = mode_medium;
		else if (ft_strcmp(argv[i], "--complex") == 0)
			ctx->mode = mode_complex;
		else if (ft_strcmp(argv[i], "--adaptive") == 0)
			ctx->mode = mode_adaptive;
		else if (ft_strcmp(argv[i], "--bench") == 0)
			ctx->bench = 1;
		i++;
	}
	if (ctx->mode == mode_none)
		ctx->mode = mode_adaptive;
}
