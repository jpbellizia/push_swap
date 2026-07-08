/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:27:05 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/06/12 11:35:09 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1) + 1;
	s2 = malloc(len * sizeof(char));
	if (!s2)
	{
		return (NULL);
	}
	ft_strlcpy(s2, s1, len);
	return (s2);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char str1[] = "Will";
// 	char *str2;

// 	str2 = ft_strdup(str1);
// 	printf("%s", str2);
// 	return (0);
// }
