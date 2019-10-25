/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 21:44:00 by kbelov            #+#    #+#             */
/*   Updated: 2019/06/03 23:06:42 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	char	*digits = "0123456789ABCDEF";
	char	*num;
	int		n;
	int		i;
	int		sign;

	if (value == -2147483648 && base == 10)
		return ("-2147483648");
	if (value == 0)
		return ("0");
	sign = 1;
	i = 0;
	if (value < 0)
	{
		sign = -1;
		value *= -1;
		i++;
	}
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
	if (sign == -1)
	{
		i--;
		num[i] = '-';
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
