/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 19:36:30 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/07/04 11:24:50 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int num)
{
	char	res;
	int		count;

	count = 0;
	if (num > 9)
		count += ft_print_unsigned(num / 10);
	res = (num % 10) + '0';
	write(1, &res, 1);
	count += 1;
	return (count);
}
