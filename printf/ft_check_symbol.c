/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_symbol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:47:07 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/07/03 17:01:20 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_symbol(char c, va_list *args)
{
		if (c == 'c')
			return (ft_print_char(va_arg(*args, int)));
		else if (c == 's')
			return (ft_print_string(va_arg(*args, char *)));
		else if (c == 'p')
			return (ft_print_pointer(va_arg(*args, void *)));
		else if (((c == 'd') || (c == 'i')))
			return (ft_print_decimal(va_arg(*args, int)));
		else if (c == 'u')
			return (ft_print_unsigned(va_arg(*args, unsigned int)));
		else if (((c == 'x') || (c == 'X')))
			return (ft_print_hexa(va_arg(*args, unsigned int), c));
		else if (c == '%')
			return (ft_print_char('%'));
		return (0);
}
