/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:56:19 by kbelov            #+#    #+#             */
/*   Updated: 2019/11/08 21:02:33 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_d(t_format *f, va_list *ap, int *charcount)
{
	int		len;
	char	*str;

	get_d_str(f, ap, &str);
	if (str && f->plus && str[0] != '-')
		str = ft_strjoin("+", str);
	if (f->space && str && !f->plus && str[0] != '-')
		str = ft_strjoin(" ", str);
	if (f->precision == 0 && ft_strcmp(str, "0") == 0)
		str = ft_strdup("");
	if (f->precision == 0 && ft_strcmp(str, "+0") == 0)
		str = ft_strdup("+");
	len = ft_strlen(str);
	apply_precision(f, &len, &str);
	if (f->width > len)
		print_num_extrawide(f, &len, charcount, &str);
	else
		(*charcount) += ft_putstr_len(str);
	//ft_strdel(&str);
}

void		print_u(t_format *f, va_list *ap, int *charcount)
{
	int		len;
	char	*str;

	get_u_str(f, ap, &str);
	if (f->precision == 0 && ft_strcmp(str, "0") == 0)
		str = ft_strdup("");
	len = ft_strlen(str);
	apply_precision(f, &len, &str);
	if (f->width > len)
		print_num_extrawide(f, &len, charcount, &str);
	else
		(*charcount) += ft_putstr_len(str);
	//ft_strdel(&str);
}

void		print_num_extrawide(t_format *f, int *len, int *charcount, char **str)
{
	char	*w_pad;

	w_pad = ft_strnew(f->width - *len);
	f->null && !f->minus && (f->precision < 0) ? ft_memset(w_pad, '0', f->width - *len) : ft_memset(w_pad, ' ', f->width - *len);
	(*charcount) += f->width;
	if (f->minus)
	{
		ft_putstr(*str);
		ft_putstr(w_pad);
	}
	else
	{
		if ((*str[0] == '+' || *str[0] == '-' || *str[0] == ' ') && w_pad[0] == '0')
		{
			ft_putchar(*str[0]);
			(*str)++;
		}
		if (f->hash && f->null && ft_strcmp(*str, "0") != 0 && w_pad[0] == '0')
			print_wide_hash(f, &w_pad, str);
		else
		{
			ft_putstr(w_pad);
			ft_putstr(*str);
		}
	}
}

void		print_p(t_format *f, va_list *ap, int *charcount)
{
	int		len;
	char	*str;

	get_oxx_str(f, ap, &str);
	if (str && f->plus && str[0] != '-')
		str = ft_strjoin("+", str);
	if (f->space && str && !f->plus && str[0] != '-')
		str = ft_strjoin(" ", str);
	if (!f->precision && ft_strcmp(str, "0") == 0 && !(f->hash && f->specifier == 'o'))
		str = ft_strdup("");
	len = ft_strlen(str);
	//if (ft_strcmp(str, "0") == 0 || ft_strcmp(str, "") == 0)
	//	f->hash = 0;
	apply_precision(f, &len, &str);
	if (ft_strlen(str) == 7)
		str = ft_strjoin("0x10", str);
	else
		str = ft_strjoin("0x", str);
	len = ft_strlen(str);
	if (f->width > len)
		print_num_extrawide(f, &len, charcount, &str);
	else
		(*charcount) += ft_putstr_len(str);
	//ft_strdel(&str);
}

