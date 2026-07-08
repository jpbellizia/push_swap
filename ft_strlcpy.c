/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:27:16 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/06/12 11:35:50 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *des, const char *src, size_t len)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (len == 0)
		return (srclen);
	while (i < (len - 1) && src[i] != '\0')
	{
		des[i] = src[i];
		i++;
	}
	des[i] = '\0';
	return (srclen);
}

// #include <stdio.h>

// int    main(void)
// {
//     const char    src[] = "William";
//     char    dest[50];

// 	printf("%zu", ft_strlcpy(dest, src, -3));
//     ft_strlcpy(dest, src, -3);
//     printf("%s", dest);
//     return (0);
// }
