/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:25:30 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/07/04 11:40:19 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *n)
{
	int				count;
	unsigned long	num;

	count = 0;
	if (!n)
	{
		count += ft_print_string("(nil)");
		return (count);
	}
	num = (unsigned long) n;
	count += ft_print_string("0x");
	count += ft_print_hexa(num, 'x');
	return (count);
}
