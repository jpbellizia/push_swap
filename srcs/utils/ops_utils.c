/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:14:15 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/07/28 11:23:19 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (!stack || stack->size < 2)
		return ;
	temp = stack->values[0];
	stack->values[0] = stack->values[1];
	stack->values[1] = temp;
}

void	push(t_stack *stack, int value)
{
	int	i;

	stack->size++;
	i = stack->size - 1;
	while (i > 0)
	{
		stack->values[i] = stack->values[i - 1];
		i--;
	}
	stack->values[0] = value;
}

void	rotate(t_stack *stack)
{
	int	temp;
	int	i;

	if (!stack || stack->size < 2)
		return ;
	i = 0;
	temp = stack->values[0];
	while (i < stack->size - 1)
	{
		stack->values[i] = stack->values[i + 1];
		i++;
	}
	stack->values[stack->size - 1] = temp;
}

void	reverse_rotate(t_stack *stack)
{
	int	temp;
	int	i;

	if (!stack || stack->size < 2)
		return ;
	i = stack->size - 1;
	temp = stack->values[stack->size - 1];
	while (i > 0)
	{
		stack->values[i] = stack->values[i - 1];
		i--;
	}
	stack->values[0] = temp;
}

int	pop(t_stack	*stack)
{
	int	value;
	int	i;

	if (stack->size <= 0)
		return (0);
	value = stack->values[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->values[i] = stack->values[i + 1];
		i++;
	}
	stack->size--;
	return (value);
}
