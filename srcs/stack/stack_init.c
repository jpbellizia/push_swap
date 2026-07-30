/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 08:44:43 by vneves-c          #+#    #+#             */
/*   Updated: 2026/07/30 12:55:21 by vneves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_numbers(int argc, char **argv)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		if (is_flag(argv[i]) == 0)
			count++;
		i++;
	}
	return (count);
}

int	stack_alloc(t_stack *stack, int capacity)
{
	stack->values = malloc(sizeof(int) * capacity);
	if (!stack->values)
		return (0);
	stack->size = 0;
	stack->capacity = capacity;
	return (1);
}

int	stack_fill(t_stack *stack, int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (is_flag(argv[i]) == 0)
		{
			stack->values[j] = (int)ft_atol(argv[i]);
			j++;
		}
		i++;
	}
	stack->size = j;
	return (1);
}

int	context_init(t_context *ctx, int argc, char **argv)
{
	int	n;

	n = count_numbers(argc, argv);
	if (stack_alloc(&ctx->a, n) == 0)
		return (0);
	if (stack_alloc(&ctx->b, n) == 0)
	{
		free_context(&ctx);
		return (0);
	}
	stack_fill(&ctx->a, argc, argv);
	ft_bzero(ctx->count, sizeof(int) * op_total);
	return (1);
}

int	normalize(t_stack *stack)
{
	int	*ranks;
	int	i;
	int	j;
	int	rank;

	ranks = malloc(sizeof(int) * stack->size);
	if (!ranks)
		return (0);
	i = 0;
	while (i < stack->size)
	{
		rank = 0;
		j = 0;
		while (j < stack->size)
		{
			j++;
		}
		ranks[i] = rank;
		i++;
	}
	free(ranks);
	return (1);
}
