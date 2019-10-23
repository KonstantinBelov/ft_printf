/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:17:58 by kbelov            #+#    #+#             */
/*   Updated: 2019/10/22 15:18:03 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		*ft_llitoa(long long int n)
{
	size_t		len;
	char		*a;
	int			negative;

	//if (n == -9223372036854775808)
	if (n == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	else if (n < LLONG_MIN)
		return (ft_strdup("9223372036854775807"));
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
