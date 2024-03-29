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

void		str_tolower(char **s)
{
	char	*tmp;

	tmp = *s;
	while (*tmp != '\0')
	{
		if (*tmp >= 'A' && *tmp <= 'Z')
			*tmp += 32;
		tmp++;
	}
}

int			print_formated(t_format *f, va_list *ap)
{
	int			charcount;

	charcount = 0;
	if (f->specifier == 'c')
		print_c(f, ap, &charcount);
	else if (f->specifier == '%')
		print_percent(f, &charcount);
	else if (f->specifier == 's')
		print_s(f, ap, &charcount);
	else if (f->specifier == 'd' || f->specifier == 'i')
		print_d(f, ap, &charcount);
	else if (f->specifier == 'u')
		print_u(f, ap, &charcount);
	else if (f->specifier == 'o' || f->specifier == 'x' ||
		f->specifier == 'X' || f->specifier == 'b')
		print_oxx(f, ap, &charcount);
	else if (f->specifier == 'p')
		print_p(f, ap, &charcount);
	else if (f->specifier == 'f')
		print_f(f, ap, &charcount);
	else
		charcount = 0;
	return (charcount);
}

t_format	*parse_format(const char *format, va_list *ap, size_t *i)
{
	t_format *f;

	f = malloc(sizeof(t_format));
	(*i)++;
	reset_format(f);
	parse_flags(f, format, i);
	parse_wid(f, format, i, ap);
	parse_prec(f, format, i, ap);
	parse_length(f, format, i);
	parse_flags(f, format, i);
	parse_type(f, format, i);
	return (f);
}

int			print_ap(const char *format, va_list *ap)
{
	t_format	*f;
	int			charcount;
	size_t		i;

	charcount = 0;
	i = 0;
	while (i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			f = parse_format(format, ap, &i);
			if (f->specifier != 'a')
				charcount += print_formated(f, ap);
		}
		else
		{
			ft_putchar(format[i]);
			charcount++;
			i++;
		}
	}
	free(f);
	return (charcount);
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
