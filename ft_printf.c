/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:23:16 by kbelov            #+#    #+#             */
/*   Updated: 2019/10/10 22:24:23 by kbelov           ###   ########.fr       */
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
	f->length = "a";
	f->specifier = 'a';
}

t_format	*parse_format(const char *restrict format)
{
	t_format *f;

	f = NULL;
	format = NULL;
	return (f);
}

int			print_formated(va_list ap, const char *restrict format)
{
	int			charcount;
	t_format	*f;

	ap = NULL;
	charcount = 0;
	f = NULL;
	reset_format(f);
	parse_format(format);
	return (charcount);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list ap;
	int		charcount;

	charcount = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			ft_putchar((char)*format);
			charcount++;
		}
		else
			charcount += print_formated(ap, format);
		format++;
	}
	va_end(ap);
	return (charcount);
}
