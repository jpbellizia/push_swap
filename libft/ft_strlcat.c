/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:27:10 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/06/12 11:35:34 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
	{
		return (dstsize + src_len);
	}
	i = dst_len;
	j = 0;
	while ((i + j) < (dstsize - 1) && src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst_len + src_len);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char src[] = "42";
// 	char dst[10] = "FT";
// 	printf("%zu", ft_strlcat(dst, src, 4));
// 	printf("\n%s", dst);

// 	char srcc[] = "42";
// 	char dstt[10] = "FT";
// 	printf("\n%zu", strlcat(dstt,srcc, 4));
// 	printf("\n%s", dstt);
//     return (0);
// }
