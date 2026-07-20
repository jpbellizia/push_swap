/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 18:21:10 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/06/17 17:29:07 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

// #include <fcntl.h>

// int	main(void)
// {
// 	int fd;
// 	fd = open("teste.txt", O_WRONLY | O_CREAT, 0777);
// 	ft_putstr_fd("testandodoc", fd);
// 	close(fd);
// 	return (0);
// }