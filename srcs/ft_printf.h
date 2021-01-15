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
# include "../libft/libft.h"


typedef	struct		s_flags
{
	int				minus;
    int				width;
    int				precision;
	int				zero;
}					t_flags;

int ft_printf(const char *format, ...);
int ft_printString(va_list arg_ptr, t_flags list_flags);
void init_flags(t_flags *list_flags);
int countInNum(int num);
void analysisFlags(const char* format, int *i, t_flags *list_flags, va_list arg_ptr);
void printValue(va_list arg_ptr, t_flags list_flags, const char* format, int *i);

#endif
