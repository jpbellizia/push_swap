/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 23:52:07 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/08/05 19:11:00 by vneves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(int c);
int		ft_print_string(char *string);
int		ft_print_decimal(int n);
int		ft_print_hexa(unsigned long n, char c);
int		ft_print_pointer(void *n);
int		ft_print_unsigned(unsigned int num);
int		ft_check_symbol(char c, va_list *args);

#endif
