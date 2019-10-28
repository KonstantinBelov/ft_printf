/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:56:19 by kbelov            #+#    #+#             */
/*   Updated: 2019/10/22 14:56:28 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_d(t_format *f, va_list *ap, int *charcount)
{
	int		len;
	char    *str;

	get_d_str(f, ap, &str);
	if (str && f->plus && str[0] != '-')
		str = ft_strjoin("+", str);
	if (f->space && str && !f->plus && str[0] != '-')
		str = ft_strjoin(" ", str);
	if (!f->precision && ft_strcmp(str, "0") == 0)
		str = ft_strdup("");
	len = ft_strlen(str);
	apply_precision(f, &len, &str);
	/*
	if (!ft_strcmp(str, "0"))
	{
		if (f->width)
			str[0] = ' ';
		else
			str++;
	}
	*/
		//f->width ? str[0] = ' ' : str++;
	if (f->width > len)
		print_num_extrawide(f, &len, charcount, &str);
	else
		(*charcount) += ft_putstr_len(str);
	//ft_strdel(&str);
}

void		print_u(t_format *f, va_list *ap, int *charcount)
{
	char	*s;
	int		len;
	char	*str;
/*
	if (!(str = ft_strdup(ft_utoa(va_arg(*ap, unsigned int)))))
	{
		str = malloc(sizeof(char) * 7);
		str = "(null)";
	}
*/
	get_u_str(f, ap, &str);
	len = ft_strlen(str);
	apply_precision(f, &len, &str);
	/*
	if (f->precision > 0 && f->precision < len)
	{
		str = ft_strsub((char const *)str, 0, f->precision);
		len = f->precision;
	}
	*/
	//str_precision_handler(&str, f, &len);
	if (f->width > len)
	{
		s = ft_strnew(f->width - len);
		f->null && !f->minus ? ft_memset(s, '0', f->width - len) : ft_memset(s, ' ', f->width - len);
		//ft_memset(s, ' ', f->width - len);
		(*charcount) += f->width;
		if (f->minus)
		{
			ft_putstr(str);
			ft_putstr(s);
		}
		//else if (f->null)
		else
		{
			if (str[0] == '+' || str[0] == '-')
			{
				str[0] == '+' ? ft_putchar('+') : ft_putchar('-');
				str++;
			}
			ft_putstr(s);
			ft_putstr(str);
		}
	}
	else
		(*charcount) += ft_putstr_len(str);
	//ft_strdel(&str);
}
