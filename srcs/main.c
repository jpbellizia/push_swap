/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:06:58 by vneves-c          #+#    #+#             */
/*   Updated: 2026/07/30 11:51:35 by jpaulo-p         ###   ########.fr       */
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
	/* aqui entrará: compute_disorder, escolher estratégia, ordenar */
	free(ctx.a.values);
	free(ctx.b.values);
	return (0);
}