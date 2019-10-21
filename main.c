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
	/*
	printf("actual_1:\n");
	ft_printf("Hello World!\n");
	printf("expected_1\n");
	printf("Hello World!\n");

	printf("actual_2:\n");
	ft_printf("%s", "Hello World!\n");
	//printf("\n");
	printf("expected_2\n");
	printf("%s", "Hello World!\n");

	printf("actual_3:\n");
	ft_printf("%Z");
	printf("\n");
	//printf("expected_3\n");
	//printf("%Z");
	printf("\n");
	printf("*********************************************************\n");

	printf("actual_2:\n");
	ft_printf("% ");
	//printf("\n");
	//printf("expected_2\n");
	//printf("% ");
	//printf("\n");

	printf("actual_0006:\n");
	ft_printf("%%");
	printf("\n");
	printf("expected_0006:\n");
	printf("%%");
	printf("\n");

	printf("actual_0007:\n");
	ft_printf("%5%");
	printf("\n");
	printf("expected_0007:\n");
	printf("%5%");
	printf("\n");

	printf("actual_0009:\n");
	ft_printf("%.0%");
	printf("\n");
	printf("expected_0009:\n");
	printf("%.0%");
	printf("\n");

	printf("actual_0045:\n");
	ft_printf("%s", "abc");
	printf("\n");
	printf("expected_0045:\n");
	printf("%s", "abc");
	printf("\n");	

	printf("actual_0045:\n");
	ft_printf("%.2s is a string", "this");
	printf("\n");
	printf("expected_0045:\n");
	printf("%.2s is a string", "this");
	printf("\n");	

	printf("actual_0069:\n");
	ft_printf("@moulitest: %s", NULL);
	printf("\n");
	printf("expected_0069:\n");
	printf("@moulitest: %s", NULL);
	printf("\n");	

	printf("actual_0093:\n");
	ft_printf("%d", 1);
	printf("\n");
	printf("expected_0093:\n");
	printf("%d", 1);
	printf("\n");	
*/
	printf("actual_0105:\n");
	ft_printf("%+d", 42);
	printf("\n");
	printf("expected_0105:\n");
	printf("%+d", 42);
	printf("\n");


/*
	char grade = "B";
	char name[] = "Josh";
	char sport[] = "football";
	int age = 18;
	double fees = 19.8;
*/
	return (0);
}
