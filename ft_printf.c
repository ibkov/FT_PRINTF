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

int print_args(va_list arg_ptr, t_flags list_flags)
{
	char* arg;
	printf("%d", list_flags.width);
	if (list_flags.type == 1)
	{
		arg = va_arg(arg_ptr, char*);
		ft_putstr_fd(arg, 1);
	}
	return (0);
}

void init_flags(t_flags *list_flags)
{
	list_flags->minus = 0;
	list_flags->lenght = 0;
	list_flags->precision = 0;
	list_flags->type = 0;
	list_flags->width = 0;
}

void analysisFlags(const char* format, int *i, t_flags *list_flags)
{
	while (format[*i] && format[*i] != 's')
	{
		if (format[*i] == '-')
			list_flags->minus = 1;
		else if (ft_isdigit(format[*i]))
			list_flags->width = (list_flags->width * 10) + (format[*i] - 48);
		(*i)++;
	}
	if (format[*i] == 's')
		list_flags->type = 1;
}

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
			analysisFlags(format, &i, &list_flags);
			print_args(arg_ptr, list_flags);
		}
//		searchBeginSpecificator(format);
//		if (format[i])
//			searchFlags()
//		format += count;
		i++;
	}
//	ch_to_per = ft_find_precent((char*)format);
//	if (ch_to_per)
//		printf("\n%s", ft_parse_modif(ch_to_per));




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
