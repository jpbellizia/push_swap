/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 20:43:40 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/06/17 18:13:48 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_set_or_not(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	by_start;
	size_t	by_end;

	if (!s1 || !set)
	{
		return (NULL);
	}
	by_start = 0;
	by_end = ft_strlen(s1);
	while (s1[by_start] && ft_set_or_not(s1[by_start], set))
	{
		by_start++;
	}
	if (by_start == by_end)
	{
		return (ft_strdup(""));
	}
	while (by_end > by_start && ft_set_or_not(s1[by_end - 1], set))
	{
		by_end--;
	}
	return (ft_substr(s1, by_start, by_end - by_start));
}

// #include <stdio.h>

// int main(void ) {

//     printf("%s", ft_strtrim("$$#Testando!$$", "$#"));
//     return 0;
// }
