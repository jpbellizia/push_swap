/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:58:36 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/06/17 18:07:56 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_strings(const char *str, char sep)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		while (str[i] == sep)
			i++;
		if (str[i] != '\0')
			counter++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (counter);
}

static	size_t	ft_return_counter(const char *s, char c)
{
	size_t	counter;

	counter = 0;
	while (*s && *s != c)
	{
		s++;
		counter++;
	}
	return (counter);
}

static	char	*ft_allocate_str(const char *s, char c)
{
	char	*new_str;
	size_t	count_word;

	count_word = ft_return_counter(s, c);
	new_str = malloc(sizeof(char) * count_word + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s, count_word + 1);
	return (new_str);
}

static void	ft_free_splited(char **str_splitted, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(str_splitted[j]);
		j++;
	}
	free(str_splitted);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**str_splitted;

	str_splitted = malloc(sizeof(char *) * (count_strings(s, c) + 1));
	if (!str_splitted)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		str_splitted[i] = ft_allocate_str(s, c);
		if (!str_splitted[i])
			return (ft_free_splited(str_splitted, i), NULL);
		s += ft_return_counter(s, c);
		i++;
	}
	str_splitted[i] = NULL;
	return (str_splitted);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *str;
// 	str = "Vamos  entender split   ";
// 	char **splitted;
// 	splitted = ft_split(str, ' ');
// 	printf("%s", splitted[0]);
// 	printf("\n%s", splitted[1]);
// 	printf("\n%s", splitted[2]);
// 	return (0);
// }