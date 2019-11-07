/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:46:16 by kbelov            #+#    #+#             */
/*   Updated: 2019/11/06 18:46:24 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_f(t_format *f, va_list *ap, int *charcount)
{
	char    *str;
	double	n;

	n = va_arg(*ap, double);
	if (f->precision == -1 || f->precision == 6)
		str = ft_strdup(ft_ftoa_(n));
	if (f->precision == 0)
		str = ft_strdup(ft_itoa(ajust_floats_precision_zero(&n , f)));
    if (f->precision < 6 && f->precision > 0)
		str = ft_strdup(ft_ftoa_nopad(ajust_floats_precision(&n , f), f));
    /*
	if (str && f->plus && str[0] != '-')
		str = ft_strjoin("+", str);
	if (f->space && str && !f->plus && str[0] != '-')
		str = ft_strjoin(" ", str);
	if (f->precision == 0 && ft_strcmp(str, "0") == 0)
		str = ft_strdup("");
	if (f->precision == 0 && ft_strcmp(str, "+0") == 0)
		str = ft_strdup("+");
	len = ft_strlen(str);
	apply_precision(f, &len, &str);
	if (f->width > len)
		print_num_extrawide(f, &len, charcount, &str);
	else*/
		(*charcount) += ft_putstr_len(str);
	//ft_strdel(&str);
}

char		*ft_ftoa_(double n)
{
	size_t		len_f;
	char		*ip;
	char		*fp;
	char		*f_pad;
	intmax_t	i;

	n *= 10000000;
	i = (intmax_t)n;
	if (i % 10 >= 5)
		i += 10;
	if (i % 10 <= -5)
		i -= 10;
	i /= 10;
	n = i % 1000000;
	i /= 1000000;
	ip = ft_strjoin(ft_itoa_(i), ".");
	if (n < 0 && (int)i == 0)
		ip = ft_strjoin("-", ip);
	if (n < 0)
		n *= -1;
	fp = ft_itoa(n);
	len_f = ft_strlen(fp);
	if (len_f < 6)
	{
		f_pad = ft_strnew(6 - len_f);
		ft_memset(f_pad, '0', 6 - len_f);
		fp = ft_strjoin(f_pad, fp);
	}
	return(ft_strjoin(ip, fp));
}

char		*ft_itoa_(int n)
{
	size_t		len;
	char		*a;
	int			negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_numlen(n);
	negative = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
		negative = 1;
	}
	if ((a = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	a[len] = '\0';
	while (len-- > 0)
	{
		a[len] = n % 10 + '0';
		n = n / 10;
	}
	if (negative == 1)
		a[0] = '-';
	return (a);
}

int		ajust_floats_precision_zero(double *n, t_format *f)
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

double	ajust_floats_precision(double *n, t_format *f)
{
	int	i;
	int m;

	i = 6;
	while (i > 0)
	{
		*n *= 10;
		i--;
	}
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
	return(*n);
}

char		*ft_ftoa_nopad(double n, t_format *f)
{
	//size_t		len_f;
	char		*ip;
	char		*fp;
	//char		*f_pad;
	intmax_t	i;

    i = 0;
    /*
	n *= 10000000;
	i = (intmax_t)n;
	if (i % 10 >= 5)
		i += 10;
	if (i % 10 <= -5)
		i -= 10;
	i /= 10;
	n = i % 1000000;
	i /= 1000000;*/
	ip = ft_strjoin(ft_itoa_(n), ".");
	if (n < 0 && (int)n == 0)
		ip = ft_strjoin("-", ip);
	if (n < 0)
		n *= -1;
    n -= (int)n;
    while (++i <= f->precision)
        n *= 10;
	fp = ft_itoa(n);
    /*
	len_f = ft_strlen(fp);
	if (len_f < 6)
	{
		f_pad = ft_strnew(6 - len_f);
		ft_memset(f_pad, '0', 6 - len_f);
		fp = ft_strjoin(f_pad, fp);
	}*/
	return(ft_strjoin(ip, fp));
}