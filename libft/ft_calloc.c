/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:25:23 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/06/17 17:32:22 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total;

	if (size != 0 && count > ((size_t) -1 / size))
		return (NULL);
	total = count * size;
	if (total == 0)
		total = 1;
	ptr = malloc(total);
	if (!ptr)
	{
		return (NULL);
	}
	ft_bzero(ptr, (count * size));
	return (ptr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *str;

// 	str = ft_calloc(10, sizeof(char));
// 	str[15] = 'j';
// 	printf("%d", str[15]);
// 	free(str);
// 	return (0);
// }
