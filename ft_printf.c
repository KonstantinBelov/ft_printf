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

int			print_formated(t_format *f, void *arg)
{
	//char *type;
	int		charcount;

	charcount = 0;
	//write(1, "fuck\n", 6);
	f = NULL;
	//write(1, "fuck2\n", 7);
	//reset_format(f);
	//write(1, "fuck3\n", 7);
	//type = detect_type(format, charcount);
	//parse_format(format);
	charcount += ft_putstr_len((char const *)arg);
	return (charcount);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	size_t	charcount;	// counts printed characters
	size_t	i;			// iterates within format string
	t_format f;

	//f = NULL;
	charcount = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%' || (format[i] == '%' && format[i + 1] == '%'))
		{
			ft_putchar((char)format[i]);
			charcount++;
			i++;
			format[i] == '%' ? i++ : i;
		}
		else
		{
			i = parse_format(&f, format, i);
			if (!validate_format(&f))
				return(charcount);
			else
			{
				charcount += print_formated(&f, va_arg(ap, void *));
				//i = validate_format(format, i);
			}
		}
	}
	va_end(ap);
	return (charcount);
}
