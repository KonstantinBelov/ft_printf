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
	char    *str;

	get_oxx_str(f, ap, &str);
	if (str && f->plus && str[0] != '-')
		str = ft_strjoin("+", str);
	if (f->space && str && !f->plus && str[0] != '-')
		str = ft_strjoin(" ", str);
	len = ft_strlen(str);
	apply_precision(f, &len, &str);
	if (!ft_strcmp(str, "0"))
	{
		if (f->width)
			str[0] = ' ';
		else
			str++;
	}
	if (f->width > len)
        print_num_extrawide(f, &len, charcount, &str);
	else
		(*charcount) += ft_putstr_len(str);
	//ft_strdel(&str);
}

void		get_oxx_str(t_format *f, va_list *ap, char **str)
{
	if (f->length || !f->length)
	{
	//if (f->length == 0)
		if (f->length == 1)
			*str = ft_strdup(ft_hitoa((short int)va_arg(*ap, int)));
		else if (f->length == 2)
			*str = ft_strdup(ft_hhitoa((signed char)va_arg(*ap, int)));
		//if (f->length == 3)
		//	*str = ft_strdup(ft_litoa(va_arg(*ap, long long int)));
		else if (f->length == 4)
			*str = ft_strdup(ft_llitoa(va_arg(*ap, long long int)));
		/*else if (f->length == 5)
			*str = ft_strdup(ft_Litoa(va_arg(*ap, long long int)));
		else if (f->length == 7)
			*str = ft_strdup(ft_jitoa(va_arg(*ap, long long int)));
		else if (f->length == 9)
			*str = ft_strdup(ft_zitoa(va_arg(*ap, long long int)));*/
		else if (f->specifier == 'o')
			*str = ft_strdup(ft_itoa_base(va_arg(*ap, int), 8));
        else if (f->specifier == 'x' || f->specifier == 'X')
			*str = ft_strdup(ft_itoa_base(va_arg(*ap, int), 16));
        else
			*str = ft_strdup(ft_itoa(va_arg(*ap, int)));
	}
	if (!(*str))
	{
		*str = malloc(sizeof(char) * 7);
		*str = "(null)";
	}
}