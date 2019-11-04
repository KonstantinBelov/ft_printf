/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:59:53 by kbelov            #+#    #+#             */
/*   Updated: 2019/11/03 16:59:58 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		*ft_ftoa(double n)
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
	n -= n - (int)n;
	//len_f = 0;
	while (n < 1)
		n *= 10;
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
