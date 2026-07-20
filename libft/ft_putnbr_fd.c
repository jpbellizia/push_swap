/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 18:36:48 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/06/17 17:28:48 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	result;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= (-1);
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	result = (nb % 10) + '0';
	write(fd, &result, 1);
}

// #include <fcntl.h>

// int	main(void)
// {
// 	int fd;
// 	fd = open("teste.txt", O_WRONLY | O_CREAT, 0777);
// 	ft_putnbr_fd(-42, fd);
// 	close(fd);
// 	return (0);
// }