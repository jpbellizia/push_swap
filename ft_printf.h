/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 23:52:07 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/07/04 11:39:51 by jpaulo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(int c);
int	ft_print_string(char *string);
int	ft_print_decimal(int n);
int	ft_print_hexa(unsigned long n, char c);
int	ft_print_pointer(void *n);
int	ft_print_unsigned(unsigned int num);
int	ft_check_symbol(char c, va_list *args);

#endif