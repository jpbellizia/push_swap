/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:26:34 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/06/17 13:57:17 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
	{
		return (NULL);
	}
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>

// #include <stdio.h>
// #include <string.h>

// int main() {
//     int source_arr[] = {10, 20, 30, 40, 50};
//     int dest_arr[5];

//     // Calculate total bytes to copy: 5 elements * size of an int
//     size_t total_bytes = sizeof(source_arr);

//     // Perform the memory copy
//     ft_memcpy(dest_arr, source_arr, total_bytes);

//     // Verify results
//     for(int i = 0; i < 5; i++) {
//         printf("%d ", dest_arr[i]);
//     }
//     return 0;
// }