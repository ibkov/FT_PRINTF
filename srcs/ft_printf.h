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

typedef	struct	s_flags
{
	int	minus;
	int	width;
	int	precision;
	int	zero;
}		t_flags;

int			ft_printf(const char *format, ...);
int			ft_print_string(va_list arg_ptr, t_flags list_flags);
void		init_flags(t_flags *list_flags);
void		analysis_flags(const char *format, int *i, t_flags *list_flags,\
va_list arg_ptr);
int			print_value(va_list arg_ptr, t_flags list_flags, const char *format, int *i);
int			ft_print_char(va_list arg_ptr, t_flags list_flags);
int			ft_print_precent(t_flags list_flags);
int			ft_print_integer(va_list arg_ptr, t_flags list_flags);
int			add_forward_char(char c, int width);
int			ft_print_unsigned_integer(va_list arg_ptr, t_flags list_flags);
int			ft_print_pointer(va_list arg_ptr, t_flags list_flags);
char		*ft_convert_base(char *alf_hex, unsigned long long num);
int			count_in_num_hex(unsigned long long num, int len);
int			ft_print_hexadecimal(va_list arg_ptr,\
t_flags list_flags, char *alf_hex);
int			ft_abs(int num);

#endif
