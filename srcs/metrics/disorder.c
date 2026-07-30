/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 11:28:55 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/07/29 15:10:33 by vneves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compute_disorder(t_stack *stack)
{
	long	total_pairs;
	long	mistakes;
	long	i;
	long	j;

	total_pairs = 0;
	mistakes = 0;
	i = 0;
	if (stack->size < 2)
		return (0);
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			total_pairs++;
			if (stack->values[i] > stack->values[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes * 10000 / total_pairs);
}
