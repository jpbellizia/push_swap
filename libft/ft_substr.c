/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:27:40 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/06/12 11:38:34 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*s2;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start > str_len)
		return (ft_strdup(""));
	if (len > (str_len - start))
		len = (str_len - start);
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s + start, len + 1);
	return (s2);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *str;
// 	str = "Alunos 42";
// 	char *str2;
// 	str2 = ft_substr(str, 0, 6);
// 	printf("%s", str2);
// 	return (0);
// }
