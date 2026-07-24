/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:14:15 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/07/24 16:42:52 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
    if (!stack || stack->size < 2)
    {
        return ;
    }
    stack->values[0]
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


SRC			= 	srcs/main.c \
				srcs/metrics/ \
				srcs/parsing/check_flags.c \
				srcs/parsing/check_numbers.c \
				srcs/stack/ \
				srcs/strategies/ \
				srcs/utils/error.c \
				srcs/utils/ops_utils.c \
