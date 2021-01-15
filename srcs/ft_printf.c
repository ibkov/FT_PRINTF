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
#include <stdio.h>

int ft_printf(const char *format, ...)
{
	va_list arg_ptr;
	va_start(arg_ptr, format);
	t_flags list_flags;
	int     count;
	int     i;

	count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			ft_putchar_fd(format[i], 1);
		else
		{
			init_flags(&list_flags);
			i++;
			analysisFlags(format, &i, &list_flags, arg_ptr);
			printValue(arg_ptr, list_flags, format, &i);
		}
		i++;
	}
	return (0);
}
