/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:48:35 by kbelov            #+#    #+#             */
/*   Updated: 2019/11/08 20:49:57 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FLAGS(c) (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
# define TYPE(c) (c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 	'c' || c == '%' || c == 'f')
# define SIGN(c) (c == '+' || c == '-' || c == ' ')
# define ZERO(c) (c == "0")
# define OXX(c) (c == 'o' || c == 'x' || c == 'X')

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

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
void		parse_flags(t_format *f, const char *format, size_t *i);
void		parse_width(t_format *f, const char *format, size_t *i, va_list *ap);
void		parse_precision(t_format *f, const char *format, size_t *i, va_list *ap);
void		parse_length(t_format *f, const char *format, size_t *i);
void		parse_type(t_format *f, const char *format, size_t *i);
int			print_formated(t_format *f, va_list *ap);
int			ft_putstr_len(char *s);
void		print_percent(t_format *f, int *charcount);
void		print_c(t_format *f, va_list *ap, int *charcount);
void		print_s(t_format *f, va_list *ap, int *charcount);
void		print_s_extrawide(t_format *f, int *len, int *charcount, char **str);
void		print_d(t_format *f, va_list *ap, int *charcount);
void		print_u(t_format *f, va_list *ap, int *charcount);
void		print_oxx(t_format *f, va_list *ap, int *charcount);
void		print_p(t_format *f, va_list *ap, int *charcount);
void		print_f(t_format *f, va_list *ap, int *charcount);
void		get_d_str(t_format *f, va_list *ap, char **str);
void		get_u_str(t_format *f, va_list *ap, char **str);
void		get_oxx_str(t_format *f, va_list *ap, char **str);
void		apply_precision(t_format *f, int *len, char **str);
void		print_num_extrawide(t_format *f, int *len, int *charcount, char **str);
void		str_tolower(char **s);
void		print_wide_hash(t_format *f, char **w_pad, char **str);
char		*ft_ullitoa_base_(intmax_t value, int base);
char		*ft_utoa_(uintmax_t n);
size_t		ft_numlen_(uintmax_t n);
char		*ft_ftoa_(double n);
char		*ft_itoa_(int n);
double		ajust_floats_precision(double *n, t_format *f);
int			ajust_floats_precision_zero(double *n, t_format *f);
char		*ft_ftoa_nopad(double n, t_format *f);

int			main(void);

#endif

