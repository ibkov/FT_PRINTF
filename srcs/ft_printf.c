/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burswyck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:44:42 by burswyck          #+#    #+#             */
/*   Updated: 2020/12/09 18:44:52 by burswyck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg_ptr;
	t_flags	list_flags;
	int		count;
	int		i;

	va_start(arg_ptr, format);
	count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		count += (format[i] == '%') ? 0 : 1;
		if (format[i] != '%')
			ft_putchar_fd(format[i], 1);
		else
		{
			init_flags(&list_flags);
			i++;
			analysis_flags(format, &i, &list_flags, arg_ptr);
			print_value(arg_ptr, list_flags, format, &i, &count);
		}
		i++;
	}
	va_end(arg_ptr);
	return (count);
}
