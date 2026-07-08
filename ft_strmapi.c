/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 21:10:20 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/06/17 17:30:57 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	s_len;
	char	*result;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s) + 1;
	result = malloc(sizeof(char) * s_len);
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// #include <stdio.h>

// char	to_upper_mapi(unsigned int i, char c)
// {
// 	(void)i;
// 	return ((char)ft_toupper(c));
// }

// int	main(void)
// {
// 	char	*result;

// 	result = ft_strmapi("test", to_upper_mapi);
// 	if (result)
// 	{
// 		printf("%s\n", result);
// 		free(result);
// 	}
// 	return (0);
// }