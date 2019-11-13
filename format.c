/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:34:34 by kbelov            #+#    #+#             */
/*   Updated: 2019/11/08 20:41:53 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		reset_format(t_format *f)
{
	f->minus = 0;
	f->plus = 0;
	f->space = 0;
	f->hash = 0;
	f->null = 0;
	f->number = 0;
	f->width = 0;
	f->precision = -1;
	f->length = 0;
	f->specifier = 'a';
}

void		get_d_str(t_format *f, va_list *ap, char **str)
{
	if (f->length == 1)
		*str = ft_strdup(ft_hitoa((short int)va_arg(*ap, int)));
	else if (f->length == 2)
		*str = ft_strdup(ft_hhitoa((signed char)va_arg(*ap, int)));
	else if (f->length == 3)
		*str = ft_strdup(ft_litoa(va_arg(*ap, long int)));
	else if (f->length == 4 || f->length == 5)
		*str = ft_strdup(ft_llitoa(va_arg(*ap, long long int)));
	else if (f->length == 7)
		*str = ft_strdup(ft_jitoa(va_arg(*ap, intmax_t)));
	else if (f->length == 9)
		*str = ft_strdup(ft_zitoa(va_arg(*ap, size_t)));
	else
		*str = ft_strdup(ft_itoa(va_arg(*ap, int)));
	if (!(*str))
	{
		*str = malloc(sizeof(char) * 7);
		*str = "(null)";
	}
}

void		get_u_str(t_format *f, va_list *ap, char **str)
{
	if (f->length == 1)
		*str = ft_strdup(ft_utoa((unsigned short)va_arg(*ap, unsigned int)));
	else if (f->length == 2)
		*str = ft_strdup(ft_utoa((unsigned char)va_arg(*ap, unsigned int)));
	else if (f->length == 3)
		*str = ft_strdup(ft_utoa(va_arg(*ap, unsigned long int)));
	else if (f->length == 4 || f->length == 5)
		*str = ft_strdup(ft_utoa(va_arg(*ap, unsigned long long)));
	else if (f->length == 7)
		*str = ft_strdup(ft_jitoa(va_arg(*ap, long long int)));
	else if (f->length == 9)
		*str = ft_strdup(ft_zitoa(va_arg(*ap, long long int)));
	else
		*str = ft_strdup(ft_utoa(va_arg(*ap, unsigned int)));
	if (!(*str))
	{
		*str = malloc(sizeof(char) * 7);
		*str = "(null)";
	}
}

void		apply_precision(t_format *f, int *len, char **str)
{
	char	*p_pad;
	char	*tmp;
	int		pad_len;
	char	*first;

	first = malloc(sizeof(char) * 2);
	first = ft_strncpy(first, *str, 1);
	if (SIGN(*str[0]) ? f->precision >= *len : f->precision > *len)
	{
		pad_len = f->precision - *len;
		*len = f->precision;
		if (SIGN(*str[0]))
			pad_len++;
		p_pad = ft_strnew(pad_len);
		ft_memset(p_pad, '0', pad_len);
		if (SIGN(*str[0]))
		{
			tmp = ft_strjoin(first, p_pad);
			(*str)++;
			*str = ft_strjoin(tmp, *str);
			(*len)++;
			ft_strdel(&tmp);
		}
		else
			*str = ft_strjoin(p_pad, *str);
		ft_strdel(&p_pad);
	}
	ft_strdel(&first);
}
