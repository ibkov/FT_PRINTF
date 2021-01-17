/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burswyck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:46:33 by burswyck          #+#    #+#             */
/*   Updated: 2020/12/09 18:46:47 by burswyck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# include <stdarg.h>

#include <stdio.h>//del

# include "../libft/libft.h"


typedef	struct		s_flags
{
	int				minus;
    int				width;
    int				precision;
	int				zero;
}					t_flags;

int     ft_printf(const char *format, ...);
void     ft_printString(va_list arg_ptr, t_flags list_flags, int *count);
void    init_flags(t_flags *list_flags);
void    analysisFlags(const char* format, int *i, t_flags *list_flags, va_list arg_ptr);
void    printValue(va_list arg_ptr, t_flags list_flags, const char* format, int *i, int *count);
void    ft_printChar(va_list arg_ptr, t_flags list_flags, int *count);
int     ft_printPrecent(t_flags list_flags);
int     ft_printInteger(va_list arg_ptr, t_flags list_flags);
int	    addForwardChar(char c, int width);
int     ft_printUnsignedInteger(va_list arg_ptr, t_flags list_flags);
int     ft_printPointer(va_list arg_ptr, t_flags list_flags);
char	*ft_convert_base(char *alf_hex, unsigned long long num);
int     countInNumHex(unsigned long long num, int len);
int     ft_printHexadecimal(va_list arg_ptr, t_flags list_flags, char *alf_hex);
int     ft_abs(int num);



#endif
