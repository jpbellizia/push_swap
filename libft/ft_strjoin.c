/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:15:39 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/06/23 11:17:43 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	phrase_length;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	phrase_length = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = malloc(sizeof(char) * phrase_length);
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, phrase_length);
	ft_strlcat(s3, s2, phrase_length);
	return (s3);
}

// #include <stdio.h>

// int    main(void)
// {
// 	char *str1;
// 	char *str2;
// 	str1 = "Casa ";
// 	str2 = "Casa.";
// 	printf("%s", ft_strjoin(str1, str2));
//     return (0);
// }
