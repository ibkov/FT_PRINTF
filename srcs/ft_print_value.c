/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burswyck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:46:33 by burswyck          #+#    #+#             */
/*   Updated: 2020/12/09 18:46:47 by burswyck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_value(va_list arg_ptr, t_flags list_flags, const char *format, int *i)
{
	int count;

	count = 0;
	if (format[*i] == 's')
		count += ft_print_string(arg_ptr, list_flags);
	if (format[*i] == 'c')
		count += ft_print_char(arg_ptr, list_flags);
	if (format[*i] == '%')
		count += ft_print_precent(list_flags);
	if (format[*i] == 'd' || format[*i] == 'i')
		count += ft_print_integer(arg_ptr, list_flags);
	if (format[*i] == 'u')
		count += ft_print_unsigned_integer(arg_ptr, list_flags);
	if (format[*i] == 'p')
		count += ft_print_pointer(arg_ptr, list_flags);
	if (format[*i] == 'x')
		count += ft_print_hexadecimal(arg_ptr, list_flags, "0123456789abcdef");
	if (format[*i] == 'X')
		count += ft_print_hexadecimal(arg_ptr, list_flags, "0123456789ABCDEF");
	return (count);
}
