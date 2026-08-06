/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:10:26 by vneves-c          #+#    #+#             */
/*   Updated: 2026/08/06 20:05:37 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_stack *stack)
{
	int	i;
	int	max;

	i = 1;
	max = 0;
	while (i < stack->size)
	{
		if (stack->values[i] > stack->values[max])
			max = i;
		i++;
	}
	return (max);
}

int	get_chunk_size(int size)
{
	if (size <= 100)
		return (20);
	return (40);
}

void	sort_medium(t_context *ctx)
{
	sort_complex(ctx);
}