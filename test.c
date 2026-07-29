/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneves-c <vneves-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:10:33 by vneves-c          #+#    #+#             */
/*   Updated: 2026/07/29 15:10:33 by vneves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_stack(t_stack stack, char nome)
{
    int    i;

    ft_printf("%c: ", nome);
    i = 0;
    while (i < stack->size)
    {
        ft_printf("%d ", stack->values[i]);
        i++;
    }
    ft_printf("\n");
}

t_stack    criar_pilha(intnumeros, int quantidade)
{
    t_stack    stack;
    int        i;

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

int    main(void)
{
    t_context    ctx;
    int    numeros[] = {3, 2, 1};

    ctx.a = criar_pilha(numeros, 3);
    sa(&ctx);
    return (0);
}
﻿
ET Bilu
jpbellizia
 