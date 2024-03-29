/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_oxx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:23:31 by kbelov            #+#    #+#             */
/*   Updated: 2019/10/24 19:23:36 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_oxx(t_format *f, va_list *ap, int *charcount)
{
	int		len;
	char	*str;

	get_oxxp_str(f, ap, &str);
	len = ft_strlen(str);
	if (ft_strcmp(str, "0") == 0 || ft_strcmp(str, "") == 0)
		f->hash = 0;
	apply_precision(f, &len, &str);
	if (f->hash && ft_strcmp(str, "0") != 0)
	{
		if (f->specifier == 'o' && str[0] != '0')
			str = ft_strjoin("0", str);
		else if (f->specifier == 'x')
			str = ft_strjoin("0x", str);
		else if (f->specifier == 'X')
			str = ft_strjoin("0X", str);
	}
	len = ft_strlen(str);
	if (f->width > len)
		print_num_wide(f, &len, charcount, &str);
	else
		(*charcount) += ft_putstr_len(str);
}

void		get_oxxp_str(t_format *f, va_list *ap, char **str)
{
	if (f->specifier == 'o')
		get_o_str(f, ap, str);
	else if (f->specifier == 'x' || f->specifier == 'X' || f->specifier == 'p')
		get_xxp_str(f, ap, str);
	else if (f->specifier == 'b')
		get_b_str(f, ap, str);
	if (!(*str))
	{
		*str = malloc(sizeof(char) * 7);
		*str = "(null)";
	}
	if (*str && f->plus && (*str)[0] != '-')
		*str = ft_strjoin("+", *str);
	if (f->space && *str && !f->plus && (*str)[0] != '-')
		*str = ft_strjoin(" ", *str);
	if (!f->precision && ft_strcmp(*str, "0") == 0 &&
		!(f->hash && f->specifier == 'o'))
		*str = ft_strdup("");
}

void		get_o_str(t_format *f, va_list *ap, char **str)
{
	if (f->length == 1)
		*str = ft_strdup(ft_ullitoa_base((unsigned short)va_arg(*ap, int), 8));
	else if (f->length == 2)
		*str = ft_strdup(ft_ullitoa_base((unsigned char)va_arg(*ap, int), 8));
	else if (f->length == 3)
		*str = ft_strdup(ft_ullitoa_base(va_arg(*ap, unsigned long int), 8));
	else if (f->length == 4)
		*str = ft_strdup(ft_ullitoa_base(va_arg(*ap, unsigned long long), 8));
	else
		*str = ft_strdup(ft_ullitoa_base(va_arg(*ap, intmax_t), 8));
}

void		get_xxp_str(t_format *f, va_list *ap, char **str)
{
	if (f->length == 1)
		*str = ft_strdup(ft_ullitoa_base((unsigned short)va_arg(*ap, int), 16));
	else if (f->length == 2)
		*str = ft_strdup(ft_ullitoa_base((unsigned char)va_arg(*ap, int), 16));
	else if (f->length == 3)
		*str = ft_strdup(ft_ullitoa_base(va_arg(*ap, unsigned long int), 16));
	else if (f->length == 4)
		*str = ft_strdup(ft_ullitoa_base(va_arg(*ap, unsigned long long), 16));
	else
		*str = ft_strdup(ft_ullitoa_base(va_arg(*ap, unsigned int), 16));
	if (f->specifier == 'x' || f->specifier == 'p')
		str_tolower(str);
}

void		get_b_str(t_format *f, va_list *ap, char **str)
{
	if (f->length == 1)
		*str = ft_strdup(ft_ullitoa_base((unsigned short)va_arg(*ap, int), 2));
	else if (f->length == 2)
		*str = ft_strdup(ft_ullitoa_base((unsigned char)va_arg(*ap, int), 2));
	else if (f->length == 3)
		*str = ft_strdup(ft_ullitoa_base(va_arg(*ap, unsigned long int), 2));
	else if (f->length == 4)
		*str = ft_strdup(ft_ullitoa_base(va_arg(*ap, unsigned long long), 2));
	else
		*str = ft_strdup(ft_ullitoa_base(va_arg(*ap, intmax_t), 2));
}
