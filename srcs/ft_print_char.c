/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burswyck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:46:33 by burswyck          #+#    #+#             */
/*   Updated: 2020/12/09 18:46:47 by burswyck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list arg_ptr, t_flags list_flags)
{
	int	arg;
	int count;

	count = 0;
	arg = va_arg(arg_ptr, int);
	if (list_flags.width != 0 && !list_flags.minus && list_flags.width > 0)
	{
		count += add_forward_char(' ', ft_abs(list_flags.width) - 1);
		ft_putchar_fd(arg, 1);
		count += 1;
	}
	else if ((list_flags.width != 0 && list_flags.minus) || \
		list_flags.width < 0)
	{
		ft_putchar_fd(arg, 1);
		count += 1;
		count += add_forward_char(' ', ft_abs(list_flags.width) - 1);
	}
	else
	{
		ft_putchar_fd(arg, 1);
		count += 1;
	}
	return (count);
}
