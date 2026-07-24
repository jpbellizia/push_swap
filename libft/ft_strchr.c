/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:26:54 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/06/15 16:45:40 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((char) c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main() {
// 	char *res;
//     char texto[] = "Programacao em C";
//     char caractere = '\0';

//     // Busca a primeira ocorrência da letra 'm'

//     printf("%s", ft_strchr(texto, caractere));
// 	res = ft_strchr(texto, caractere);
// 	printf("\n%p", &res);
//     return 0;
// }
