/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:14:15 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/07/24 16:55:19 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

    if (!stack || stack->size < 2)
    {
        return ;
    }
    temp = stack->values[0];
	stack->values[0] = stack->values[1];
	stack->values[1] = temp; 
}

void	push(t_stack *stack, int value)
{
    
}

void	rotate(t_stack *stack)
{
    
}

void	reverse_rotate(t_stack *stack)
{
    
}

int		pop(t_stack	*stack)
{
    
}
