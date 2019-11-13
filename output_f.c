/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:46:16 by kbelov            #+#    #+#             */
/*   Updated: 2019/11/08 20:58:35 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_f(t_format *f, va_list *ap, int *charcount)
{
	char    *str;
	double	n;

	n = va_arg(*ap, double);
	if (f->precision == -1 || f->precision == 6)
		str = ft_strdup(ft_ftoa(n));
	if (f->precision == 0)
		str = ft_strdup(ft_itoa(ajust_floats_precision_zero(&n, f)));
	if (f->precision < 6 && f->precision > 0)
		str = ft_strdup(ft_ftoa_nopad(ajust_floats_precision(&n, f), f));
	(*charcount) += ft_putstr_len(str);
	ft_strdel(&str);
}

int			ajust_floats_precision_zero(double *n, t_format *f)
{
	int	i;
	int m;

	i = 6 - f->precision;
	while (i > 0)
	{
		*n *= 10;
		i--;
	}
	m = *n;
	while (i < 6 - f->precision)
	{
		if (m % 10 >= 5)
			m += 10;
		if (m % 10 <= -5)
			m -= 10;
		m /= 10;
		i++;
	}
	return(m);
}

double		ajust_floats_precision(double *n, t_format *f)
{
	int	i;
	int m;

	i = 7;
	while (--i > 0)
		*n *= 10;
	m = *n;
	while (i < 6)
	{
		if (i < 6 - f->precision)
		{
			if (m % 10 >= 5)
				m += 10;
			if (m % 10 <= -5)
				m -= 10;
			m /= 10;
		}
		else
		{
			*n = m;
			*n /= 10;
		}
		i++;
	}
	return (*n);
}

char		*ft_ftoa_nopad(double n, t_format *f)
{
	char		*ip;
	char		*fp;
	intmax_t	i;

    i = 0;
	ip = ft_strjoin(ft_itoa(n), ".");
	if (n < 0 && (int)n == 0)
		ip = ft_strjoin("-", ip);
	if (n < 0)
		n *= -1;
    n -= (int)n;
    while (++i <= f->precision)
        n *= 10;
	fp = ft_itoa(n);
	ip = ft_strjoin(ip, fp);
	ft_strdel(&fp);
	return (ip);
}
