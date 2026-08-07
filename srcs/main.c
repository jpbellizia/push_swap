/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:06:58 by vneves-c          #+#    #+#             */
/*   Updated: 2026/08/06 23:25:02 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_context	ctx;

	if (argc == 1)
		return (0);
	if (validate_numbers(argc, argv) == 1)
		return (1);
	if (count_numbers(argc, argv) == 0)
		return (0);
	if (context_init(&ctx, argc, argv) == 0)
		return (error());
	define_mode(argc, argv, &ctx);
	ctx.disorder = compute_disorder(&ctx.a);
	sort(&ctx);
	if (ctx.bench == 1)
		print_bench(&ctx);
	free_context(&ctx);
	return (0);
}
