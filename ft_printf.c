/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:23:16 by kbelov            #+#    #+#             */
/*   Updated: 2019/10/12 15:32:03 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_formated(t_format *f, va_list *ap)
{
	int			charcount;

	charcount = 0;
	//f = NULL;
	//ap = NULL;
	//charcount += ft_putstr_len((char const *)arg);
	if (f->specifier == 'c')
		print_c(f, ap, &charcount);//? printc(f, ap, &charcount) : 1 == 1;
	else if (f->specifier == '%')
		print_percent(f, &charcount);
	else if (f->specifier == 's')
		print_s(f, ap, &charcount);
	else if (f->specifier == 'd' || f->specifier == 'i')
		print_d(f, ap, &charcount);
	else if (f->specifier == 'u')
		print_u(f, ap, &charcount);
	return (charcount);
}

int			print_ap(const char *format, va_list *ap)
{
	t_format	*f;
	int			charcount;
	size_t		i;

	charcount = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			f = parse_format(format, ap, &i);
			charcount += print_formated(f, ap);
		}
		else
		{
			ft_putchar(format[i]);
			charcount++; 
		}
		i++;
	}
	//free(f);
	return(charcount);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			charcount;

	charcount = 0;
	va_start(ap, format);
	charcount = print_ap(format, &ap);
	va_end(ap);
	return (charcount);
}
