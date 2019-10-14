/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:02:11 by kbelov            #+#    #+#             */
/*   Updated: 2019/10/10 21:45:42 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int			main(int ac, char *av[])
{
	ac = 0;
	printf("%s\n", "*** actual result: ***");
	ft_printf(av[1], av[2]);
	printf("\n");
	printf("%s\n", "*** expected result: ***");
	printf(av[1], av[2]);
	return (0);
}
