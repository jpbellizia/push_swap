/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:32:57 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/07/30 14:34:32 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rank(t_stack *stack, int value)
{
	int	rank;
	int	j;

	rank = 0;
	j = 0;
	while (j < stack->size)
	{
		if (stack->values[j] < value)
			rank++;
		j++;
	}
	return (rank);
}

int	normalize(t_stack *stack)
{
	int	*ranks;
	int	i;

	ranks = malloc(sizeof(int) * stack->size);
	if (!ranks)
		return (0);
	i = 0;
	while (i < stack->size)
	{
		ranks[i] = get_rank(stack, stack->values[i]);
		i++;
	}
	i = 0;
	while (i < stack->size)
	{
		stack->values[i] = ranks[i];
		i++;
	}
	free(ranks);
	return (1);
}
