/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneves-c <vneves-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:06:58 by vneves-c          #+#    #+#             */
/*   Updated: 2026/07/24 00:06:58 by vneves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_mode		mode;
	int			bench;
	t_context	ctx;

	if (argc == 1)
		return (0);
	if (validate_numbers(argc, argv) == 1)
		return (1);
	if (count_numbers(argc, argv) == 0)
		return (0);
	define_mode(argc, argv, &mode, &bench);
	if (context_init(&ctx, argc, argv) == 0)
		return (error());
	free(ctx.a.values);
	free(ctx.b.values);
	return (0);
}
