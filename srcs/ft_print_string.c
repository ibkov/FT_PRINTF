/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burswyck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:46:33 by burswyck          #+#    #+#             */
/*   Updated: 2020/12/09 18:46:47 by burswyck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int		ft_print_string(va_list arg_ptr, t_flags list_flags)
{
	char	*arg;
	int		len;
	int		count;

	count = 0;
	if (!(arg = ft_strdup(va_arg(arg_ptr, char*))))
		arg = ft_strdup("(null)");
	if (list_flags.precision < (int)ft_strlen(arg))
		arg[list_flags.precision] = '\0';
	len = ft_strlen(arg);
	if (!list_flags.minus && list_flags.width > 0)
	{
		count += add_forward_char(' ', list_flags.width - len);
		count += ft_putstr_fd(arg, 1);
	}
	else if ((list_flags.width != 0 && list_flags.minus) || \
	list_flags.width < 0)
	{
		count += ft_putstr_fd(arg, 1);
		count += add_forward_char(' ', ft_abs(list_flags.width) - len);
	}
	else
		count += ft_putstr_fd(arg, 1);
	free(arg);
	return (count);
}
