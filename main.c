/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:02:11 by kbelov            #+#    #+#             */
/*   Updated: 2019/10/12 15:16:17 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int			main(void)
{

	printf("actual_1:\n");
	ft_printf("Hello World!\n");
	printf("expected_1\n");
	printf("Hello World!\n");

	printf("actual_2:\n");
	ft_printf("%s", "Hello World!\n");
	//printf("\n");
	printf("expected_2\n");
	printf("%s", "Hello World!\n");

	printf("actual_1:\n");
	ft_printf("%Z");
	//printf("expected_3\n");
	//printf("%Z");

/*
	char grade = "B";
	char name[] = "Josh";
	char sport[] = "football";
	int age = 18;
	double fees = 19.8;
*/
	return (0);
}
