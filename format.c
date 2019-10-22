/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:34:34 by kbelov            #+#    #+#             */
/*   Updated: 2019/10/12 15:38:08 by kbelov           ###   ########.fr       */
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

int			validate_format(t_format *f)
{
	if (TYPE(f->specifier))
		return(1);
	return (0);
}

void		get_str(t_format *f, va_list *ap, char **str)
{
	if (f->length || !f->length)
	//if (f->length == 0)
		*str = ft_strdup(ft_itoa(va_arg(*ap, int)));
	//else if (f->length == 1)
	//	*str = ft_strdup(ft_itoa(va_arg(*ap, short)));
	if (!(*str))
	{
		*str = malloc(sizeof(char) * 7);
		*str = "(null)";
	}
}

void		apply_precision(t_format *f, int *len, char **str)
{
	char *p_pad;
	char *tmp;
	
	if (f->precision > *len)
	{
		p_pad = ft_strnew(f->precision - *len);
		ft_memset(p_pad, '0', f->precision - *len);
		*len = f->precision;
		if (*str[0] == '+' || *str[0] == '-' || *str[0] == ' ')
		{
			tmp = ft_strjoin(str[0], p_pad);
			(*str)++;
			*str = ft_strjoin(tmp, *str);
		}
		else
			*str = ft_strjoin(p_pad, *str);
	}
}