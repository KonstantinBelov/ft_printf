/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:56:19 by kbelov            #+#    #+#             */
/*   Updated: 2019/10/22 14:56:28 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_d(t_format *f, va_list *ap, int *charcount)
{
	int		len;
	char    *str;

	get_d_str(f, ap, &str);
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
	else
		(*charcount) += ft_putstr_len(str);
	//ft_strdel(&str);
}

void		print_u(t_format *f, va_list *ap, int *charcount)
{
	int		len;
	char	*str;

	get_u_str(f, ap, &str);
	if (f->precision == 0 && ft_strcmp(str, "0") == 0)
		str = ft_strdup("");
	len = ft_strlen(str);
	apply_precision(f, &len, &str);
	if (f->width > len)
		print_num_extrawide(f, &len, charcount, &str);
	else
		(*charcount) += ft_putstr_len(str);
	//ft_strdel(&str);
}

void		print_num_extrawide(t_format *f, int *len, int *charcount, char **str)
{
	char	*w_pad;
	
	w_pad = ft_strnew(f->width - *len);
	f->null && !f->minus && (f->precision < 0) ? ft_memset(w_pad, '0', f->width - *len) : ft_memset(w_pad, ' ', f->width - *len);
	(*charcount) += f->width;
	if (f->minus)
	{
		ft_putstr(*str);
		ft_putstr(w_pad);
	}
	else
	{
		if ((*str[0] == '+' || *str[0] == '-' || *str[0] == ' ') && w_pad[0] == '0')
		{
			ft_putchar(*str[0]);
			(*str)++;
		}
		if (f->hash && f->null && ft_strcmp(*str, "0") != 0 && w_pad[0] == '0')
			print_wide_hash(f, &w_pad, str);
		else
		{
			ft_putstr(w_pad);
			ft_putstr(*str);
		}
	}
}

void		print_p(t_format *f, va_list *ap, int *charcount)
{
	int		len;
	char    *str;

	get_oxx_str(f, ap, &str);
	if (str && f->plus && str[0] != '-')
		str = ft_strjoin("+", str);
	if (f->space && str && !f->plus && str[0] != '-')
		str = ft_strjoin(" ", str);
	if (!f->precision && ft_strcmp(str, "0") == 0 && !(f->hash && f->specifier == 'o'))	
		str = ft_strdup("");
	len = ft_strlen(str);
	//if (ft_strcmp(str, "0") == 0 || ft_strcmp(str, "") == 0)
	//	f->hash = 0;
	apply_precision(f, &len, &str);
	if (ft_strlen(str) == 7)
		str = ft_strjoin("0x10", str);
	else
		str = ft_strjoin("0x", str);
	len = ft_strlen(str);
	if (f->width > len)
        print_num_extrawide(f, &len, charcount, &str);
	else
		(*charcount) += ft_putstr_len(str);
	//ft_strdel(&str);
}

void		print_f(t_format *f, va_list *ap, int *charcount)
{
	int		len;
	char    *str;
	double	n;

	//str = ft_strdup(ft_ftoa_(va_arg(*ap, double)));
	n = va_arg(*ap, double);
	str = ft_strdup(ft_ftoa_(n));
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
	else
		(*charcount) += ft_putstr_len(str);
	//ft_strdel(&str);
}

char		*ft_ftoa_(double n)
{
	size_t		len_f;
	char		*a;
	//int			negative;
	char		*ip;
	char		*fp;
	char		*f_pad;

	//if (n == -2147483648)
	//	return (ft_strdup("-2147483648"));
	/*
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
	*/
	ip = ft_strjoin(ft_itoa(n), ".");
	n -= (int)n;
	//len_f = 0;
	while (n != (int)n)
		n *= 10;
	if (n < 0)
		n *= -1;
	fp = ft_itoa(n);
	len_f = ft_strlen(fp);
	if (len_f < 6)
	{
		f_pad = ft_strnew(6 - len_f);
		ft_memset(f_pad, '0', 6 - len_f);
		fp = ft_strjoin(fp, f_pad);
	}
	a = ft_strjoin(ip, fp);
	return(a);
}