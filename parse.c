/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:36:53 by kbelov            #+#    #+#             */
/*   Updated: 2019/10/13 16:37:01 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(t_format *f, const char *restrict format, size_t *i)
{
	while (FLAGS(format[*i]))
	{
		if (format[*i] == '-')
			f->minus = 1;
		else if (format[*i] == '+')
			f->plus = 1;
		else if (format[*i] == ' ')
			f->space = 1;
		else if (format[*i] == '#')
			f->hash = 1;
		else if (format[*i] == '0')
			f->null = 1;
		(*i)++;
	}
}

void	parse_wid(t_format *f, const char *ft, size_t *i, va_list *ap)
{
	if (ft[*i] == '*')
	{
		f->width = va_arg(*ap, int);
		i++;
	}
	else if (ft_isdigit(ft[*i]))
		f->width = ft_atoi(&(ft[*i]));
	while (ft_isdigit(ft[*i]))
		(*i)++;
}

void	parse_prec(t_format *f, const char *ft, size_t *i, va_list *ap)
{
	if (ft[*i] == '.')
	{
		(*i)++;
		if (ft[*i] == '*')
		{
			f->precision = va_arg(*ap, int);
			(*i)++;
		}
		else if (ft_isdigit(ft[*i]))
			f->precision = ft_atoi(&(ft[*i]));
		else
			f->precision = 0;
		while (ft_isdigit(ft[*i]))
			(*i)++;
	}
}

void	parse_length(t_format *f, const char *format, size_t *i)
{
	if (format[*i] == 'h')
	{
		if (format[*i + 1] == 'h')
			f->length = 2;
		else
			f->length = 1;
	}
	else if (format[*i] == 'l')
	{
		if (format[*i + 1] == 'l')
			f->length = 4;
		else
			f->length = 3;
	}
	else if (format[*i] == 'L')
		f->length = 5;
	else if (format[*i] == 'j')
		f->length = 7;
	else if (format[*i] == 'z')
		f->length = 9;
	if ((f->length % 2 == 1) && f->length)
		(*i)++;
	if ((f->length % 2 == 0) && f->length)
		(*i) += 2;
}

void	parse_type(t_format *f, const char *format, size_t *i)
{
	if (TYPE1(format[*i]) || TYPE2(format[*i]) || TYPE3(format[*i]))
	{
		f->specifier = format[*i];
		(*i)++;
	}
	else if (format[*i] == 'U')
	{
		f->specifier = 'u';
		(*i)++;
	}
}
