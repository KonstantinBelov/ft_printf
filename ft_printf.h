/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:48:35 by kbelov            #+#    #+#             */
/*   Updated: 2019/10/10 21:09:42 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_format
{
	int		minus;
	int		plus;
	int		space;
	int		hash;
	int		null;
	int		number;
	int		width;
	int		precision;
	char	*length;
	char	specifier;
}				t_format;

int				ft_printf(const char *restrict format, ...);
int				print_formated(va_list ap, const char *restrict format);
t_format		*parse_format(const char *restrict format);
void			reset_format(t_format *f);
int				main(int ac, char *av[]);

#endif
