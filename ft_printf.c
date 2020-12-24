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

#include "ft_print.h"
#include <stdio.h>

int ft_printf(const char *format, ...)
{
	char *ch_to_per;

	va_list arg_ptr;
	va_start(arg_ptr, format);
	ft_find_precent((char*)format);
	if (*format == '%' && *++format == 's')
		ch_to_per = va_arg(arg_ptr, char*);
		while (*ch_to_per){
		ft_putchar_fd(*ch_to_per, 1);
		ch_to_per++;
		}


	// while ((i=va_arg(arg_ptr, int)) != -1)
	// 	write(1, i, ft_str)
	return (0);
}
