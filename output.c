/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:41:00 by kbelov            #+#    #+#             */
/*   Updated: 2019/10/13 18:41:02 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putstr_len(char *s)
{
	int		len;
	
	len = 0;
	if (s)
	{
		while (s[len] != '\0')
		{
			write(1, &(s[len]), 1);
			len++;
		}
	}
	return(len);
}

void		print_percent(t_format *f, int *charcount)
{
	int len;
	char *c;

	len = 1;
	c = ft_strdup("%");
	if (f->width > 1)
		print_s_extrawide(f, &len, charcount, &c);
	else
	{
		ft_putchar('%');
		(*charcount)++;
	}
	free((void *)c);
}

void		print_c(t_format *f, va_list *ap, int *charcount)
{
	char *s;

	if (f->width)
	{
		s = ft_strnew(f->width - 1);
		ft_memset(s, ' ', f->width - 1);
		(*charcount) += f->width;
	}
	else
	{
		s = NULL;
		(*charcount)++;
	}
	if (f->minus)
	{
		ft_putchar(va_arg(*ap, int));
		if (s)
			ft_putstr(s);
	}
	else
	{
		if (s)
			ft_putstr(s);
		ft_putchar((char)va_arg(*ap, int));
	}	
}

void		print_s(t_format *f, va_list *ap, int *charcount)
{
	//char	*s;
	int		len;
	char	*str;

	if (!(str = ft_strdup(va_arg(*ap, char *))))
	{
		str = malloc(sizeof(char) * 7);
		str = "(null)";
	}
	len = ft_strlen(str);
	if (f->precision >= 0 && f->precision < len)
	{
		str = ft_strsub((char const *)str, 0, f->precision);
		len = f->precision;
	}
	//str_precision_handler(&str, f, &len);
	if (f->width > len)
		print_s_extrawide(f, &len, charcount, &str);
	else
		(*charcount) += ft_putstr_len(str);
	//ft_strdel(&str);
}

void		print_s_extrawide(t_format *f, int *len, int *charcount, char **str)
{
	char *w_pad;

	w_pad = ft_strnew(f->width - *len);
	f->null && !f->minus ? ft_memset(w_pad, '0', f->width - *len) : ft_memset(w_pad, ' ', f->width - *len);
	(*charcount) += f->width;
	if (f->minus)
	{
		ft_putstr(*str);
		ft_putstr(w_pad);
	}
	else
	{
		ft_putstr(w_pad);
		ft_putstr(*str);
	}
}
