/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:48:35 by kbelov            #+#    #+#             */
/*   Updated: 2019/10/12 15:30:03 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
//# define SINGLE_%(c) (c == '%' && c + 1 != '%')
# define FLAGS(c) (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
//# define 
# define TYPE(c) (c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 	'c' || c == '%')


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
	int		length;
	char	specifier;
}				t_format;

int			ft_printf(const char *format, ...);
int			print_ap(const char *format, va_list *ap);
t_format	*parse_format(const char *format, va_list *ap, size_t *i);
void		reset_format(t_format *f);
void       	parse_flags(t_format *f, const char *format, size_t *i);
void        parse_width(t_format *f, const char *format, size_t *i, va_list *ap);
void        parse_precision(t_format *f, const char *format, size_t *i, va_list *ap);
void		parse_length(t_format *f, const char *format, size_t *i);
void		parse_type(t_format *f, const char *format, size_t *i);
int			print_formated(t_format *f, va_list *ap);
int			ft_putstr_len(char *s);
void		print_percent(t_format *f, int *charcount);
void		print_c(t_format *f, va_list *ap, int *charcount);
void		print_s(t_format *f, va_list *ap, int *charcount);
//void		str_precision_handler(char **str, t_format *f, int *len);
void		print_d(t_format *f, va_list *ap, int *charcount);
//char		*detect_type(const char *restrict format, int charcount);
//size_t		validate_format_specifier(const char *restrict format, size_t i);
//int			validate_format(t_format *f);

int			main(void);
//int				main(int ac, char *av[]);

#endif
