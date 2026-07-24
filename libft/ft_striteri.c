/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:51:26 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/06/17 17:29:31 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f (i, &s[i]);
		i++;
	}
}

// #include <stdio.h>

// void	ftft_toupper(unsigned int i, char* str)
// {
// 	(void)	i;
// 	*str -= 32;
// }

// int	main(void)
// {
// 	char result[] = "testandooo123";

// 	ft_striteri(result, ftft_toupper);
// 	printf("%s\n", result);

// 	return (0);
// }