/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:23:16 by kbelov            #+#    #+#             */
/*   Updated: 2019/10/07 19:18:20 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	
	ft_putstr(s);
}

#include <stdio.h>

int			main(int ac, char* av[])
{
	ac = 0;
	printf("%s\n", "*** actual result: ***");
	ft_printf(av[1]);
	printf("%s\n", "*** expected result: ***");
	printf("%s\n", av[1]);
	return(0);
}

