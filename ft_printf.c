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
	char *arg;

	ch_to_per = NULL;
	arg = NULL;
	va_list arg_ptr;
	va_start(arg_ptr, format);
	ch_to_per = ft_find_precent((char*)format);
	ft_parse_modif(++ch_to_per);
	// ch_to_per = (char*)format;
	// while(ch_to_per)
	// {
	// if ((ch_to_per = ft_find_precent((char*)ch_to_per)) && (*ch_to_per == '%') && (ch_to_per[1] == 's'))
	// 	arg = va_arg(arg_ptr, char*);
	// 	while (*arg)
	// 	{
	// 		ft_putchar_fd(*arg, 1);
	// 		arg++;
	// 	}
	// 	ch_to_per+=2;
	// }
	

	// while ((i=va_arg(arg_ptr, int)) != -1)
	// 	write(1, i, ft_str)
	return (0);
}
