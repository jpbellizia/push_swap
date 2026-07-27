/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:14:36 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/07/27 16:18:15 by jpaulo-p         ###   ########.fr       */
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
	t_stack	pilha_a;
	int		numeros[] = {5, 8, 2, 6};

	pilha_a = criar_pilha(numeros, 4);
	print_stack(&pilha_a, 'a');
	rotate(&pilha_a);
	print_stack(&pilha_a, 'a');

	reverse_rotate(&pilha_a);
	print_stack(&pilha_a, 'a');

	ft_printf('\n');
	int	tirado;
	tirado = pop(&pilha_a);
	ft_printf("tirei: %d\n", tirado);
	print_stack(&pilha_a, 'a');
	push(&pilha_a, tirado);
	print_stack(&pilha_a, 'a');
	return (0);
}