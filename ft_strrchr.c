/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:27:32 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/06/17 17:25:33 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr_c;
	size_t	i;

	ptr_c = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			ptr_c = (char *)&s[i];
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (ptr_c);
}

// #include <stdio.h>

// int main() {
// 	char *res;
//     char texto[] = "Programacao em C vivo";
//     char caractere = 'o';

//     // Busca a primeira ocorrência da letra 'm'

//     printf("%s", ft_strrchr(texto, caractere));
// 	res = ft_strrchr(texto, caractere);
// 	printf("\n%p", &res);
//     return 0;
// }