/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 21:44:00 by kbelov            #+#    #+#             */
/*   Updated: 2019/10/28 21:24:13 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"

char	*ft_ullitoa_base_(intmax_t value, int base)
{
	char		*digits = "0123456789ABCDEF";
	char		*num;
	intmax_t	n;
	int			i;

	if (value == 0)
		return ("0");
	i = 0;
	n = value;
	while (n)
	{
		n /= base;
		i++;
	}
	if (!(num = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	num[i] = '\0';
	while (value)
	{
		i--;
		num[i] = digits[value % base];
		value /= base;
	}
	return (num);
}
/*
#include <stdio.h>

int		main(int ac, char *av[])
{
	ac = 0;
	printf("%s\n", ft_itoa_base(atoi(av[1]), atoi(av[2])));
	return (0);
}
*/

char		*ft_utoa_(uintmax_t n)
{
	size_t		len;
	char		*a;

	len = ft_numlen_(n);
	if ((a = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	a[len] = '\0';
	while (len-- > 0)
	{
		a[len] = n % 10 + '0';
		n = n / 10;
	}
	return (a);
}

size_t		ft_numlen_(uintmax_t n)
{
	size_t		len;

	len = 1;
	//if (n < 0)
	//	n *= -1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}