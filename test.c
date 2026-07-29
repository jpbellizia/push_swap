/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:14:36 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/07/28 19:14:51 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, char nome)
{
	int	i;

	ft_printf("%c: ", nome);
	i = 0;
	while (i < stack->size)
	{
		ft_printf("%d ", stack->values[i]);
		i++;
	}
	ft_printf("\n");
}

t_stack	criar_pilha(int *numeros, int quantidade)
{
	t_stack	stack;
	int		i;

	stack.values = malloc(sizeof(int) * quantidade);
	stack.size = quantidade;
	stack.capacity = quantidade;
	i = 0;
	while (i < quantidade)
	{
		stack.values[i] = numeros[i];
		i++;
	}
	return (stack);
}

int	main(void)
{
	t_context	ctx;
	int	numeros[] = {3, 2, 1};

	ctx.a = criar_pilha(numeros, 3);
	sa(&ctx);
	return (0);
}
