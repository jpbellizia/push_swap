/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:06:58 by vneves-c          #+#    #+#             */
/*   Updated: 2026/07/29 15:03:38 by vneves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(char *arg)
{
	int		i;
	long	value;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (arg[i] == '\0')
		return (0);
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) == 0)
			return (0);
		i++;
	}
	value = ft_atol(arg);
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	return (1);
}

int	validate_numbers(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_flag(argv[i]) == 0)
		{
			if (check_number(argv[i]) == 0)
				return (error());
		}
		i++;
	}
	return (0);
}

int	check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		if (is_flag(argv[i]) == 0)
		{
			j = i + 1;
			while (j < argc)
			{
				if (is_flag(argv[j]) == 0)
				{
					if (ft_atol(argv[i]) == ft_atol(argv[j]))
						return (error());
				}
				j++;
			}
		}
		i++;
	}
	return (0);
}
