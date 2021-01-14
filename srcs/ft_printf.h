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
	int				type;
	int				lenght;
}					t_flags;

int ft_printf(const char *format, ...);
int searchBeginSpecificator(const char *format);
char *ft_find_precent(char *str);
char *ft_parse_modif(char *modif);



#endif
