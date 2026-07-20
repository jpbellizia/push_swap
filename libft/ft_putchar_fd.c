/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:59:51 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/06/17 17:29:18 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include <fcntl.h>

// int	main(void)
// {
// 	int fd;
// 	fd = open("teste.txt", O_WRONLY | O_CREAT, 0777);
// 	ft_putchar_fd('J', fd);
// 	close(fd);
// 	return (0);
// }