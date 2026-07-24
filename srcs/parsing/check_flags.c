/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneves-c <vneves-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:06:58 by vneves-c          #+#    #+#             */
/*   Updated: 2026/07/24 01:26:32 by vneves-c         ###   ########.fr       */
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

void	define_mode(int argc, char **argv, t_mode *mode, int *bench)
{
	int	i;

	i = 1;
	*mode = mode_none;
	*bench = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--simple") == 0)
			*mode = mode_simple;
		else if (ft_strcmp(argv[i], "--medium") == 0)
			*mode = mode_medium;
		else if (ft_strcmp(argv[i], "--complex") == 0)
			*mode = mode_complex;
		else if (ft_strcmp(argv[i], "--adaptive") == 0)
			*mode = mode_adaptive;
		else if (ft_strcmp(argv[i], "--bench") == 0)
			*bench = 1;
		i++;
	}
	if (*mode == mode_none)
		*mode = mode_adaptive;
}
