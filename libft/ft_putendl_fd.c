/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 18:30:20 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/06/15 19:04:03 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

// #include <fcntl.h>

// int	main(void)
// {
// 	int fd;
// 	fd = open("teste.txt", O_WRONLY | O_CREAT, 0777);
// 	ft_putendl_fd("testandodoc", fd);
// 	close(fd);
// 	return (0);
// }