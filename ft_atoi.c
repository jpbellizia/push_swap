/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 11:12:14 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/06/15 16:49:27 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	signal;
	int	i;

	res = 0;
	signal = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			signal *= -1;
		}
		i++;
	}
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * signal);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     printf("Atoi: %d", ft_atoi("-a"));
// 	printf("\nOriginal Atoi: %d", atoi("-a"));
//     return (0);
// }
