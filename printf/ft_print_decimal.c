/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:45:53 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/07/03 16:35:03 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal(int n)
{
	long int	long_n;
	char		res;
	int	count;

	long_n = n;
	count = 0;
	if (long_n < 0)
	{
		count++;
		write(1, "-", 1);
		long_n *= -1;
	}
	if (long_n > 9)
		count += ft_print_decimal(long_n / 10);
	res = (long_n % 10) + '0';
	count += write(1, &res, 1);
	return (count);
}

// int	main(void)
// {
// 	ft_print_decimal(255);
// 	return (0);
// }
