/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 16:26:05 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/07/03 17:42:49 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned long n, char c)
{
	char 	*base_convertion;
	int 	count;

	count = 0;
	if (c == 'x')
		base_convertion = "0123456789abcdef";
	else
		base_convertion = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_print_hexa(n / 16, c);
	count += write(1, &base_convertion[n % 16], 1);
	return (count);
}
