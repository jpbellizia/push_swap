/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:26:08 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/06/12 11:20:58 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr_str;
	size_t			i;

	ptr_str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr_str[i] == (unsigned char)c)
		{
			return ((void *)&ptr_str[i]);
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char str[] = "Paralelepipedo";
// 	printf("%p", ft_memchr(str, 'i', 14));
// 	printf("\n%p", memchr(str, 'i', 2));
// 	return (0);
// }