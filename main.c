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
	int i;
	//intmax_t j;

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

	printf("*************************************************************\n");
	printf("actual_014:\n");
	i = ft_printf("%x", 0);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_014:\n");
	i = printf("%x", 0);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	printf("actual_:\n");
	ft_printf("%d", 0);
	printf("\n");
	printf("expected_:\n");
	printf("%d", 0);
	printf("\n");

	printf("*************************************************************\n");
	printf("actual_16:\n");
	i = ft_printf("%x", -42);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_16:\n");
	i = printf("%x", -42);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	printf("*************************************************************\n");
	printf("actual_23:\n");
	i = ft_printf("%lx", 4294967296);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_23:\n");
	i = printf("%lx", 4294967296);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	printf("*************************************************************\n");
	printf("actual_24:\n");
	i = ft_printf("%llX", 4294967296);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_24:\n");
	i = printf("%llX", 4294967296);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");


	printf("*************************************************************\n");
	printf("actual_40:\n");
	i = ft_printf("%#08x", 42);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_40:\n");
	i = printf("%#08x", 42);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	printf("*************************************************************\n");
	printf("actual_42:\n");
	i = ft_printf("@moulitest: %#.x %#.0x", 0, 0);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_42:\n");
	i = printf("@moulitest: %#.x %#.0x", 0, 0);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

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

	printf("*************************************************************\n");
	printf("actual_91:\n");
	i = ft_printf("@moulitest: %#.o %#.0o", 0, 0);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_91:\n");
	i = printf("@moulitest: %#.o %#.0o", 0, 0);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	printf("actual_0093:\n");
	ft_printf("%d", 1);
	printf("\n");
	printf("expected_0093:\n");
	printf("%d", 1);
	printf("\n");	

	printf("actual_0105:\n");
	ft_printf("%+d", 42);
	printf("\n");
	printf("expected_0105:\n");
	printf("%+d", 42);
	printf("\n");

	printf("actual_0105:\n");
	ft_printf("%+d", 42);
	printf("\n");
	printf("expected_0105:\n");
	printf("%+d", 42);
	printf("\n");

	//short int i = 32767;
	printf("actual_0133:\n");
	ft_printf("%hd", 32767);
	printf("\n");
	printf("expected_0133:\n");
	//printf("%hd", 32767);
	printf("\n");

	//short int i = -32768;
	printf("actual_0134:\n");
	ft_printf("%hd", -32768);
	printf("\n");
	printf("expected_0134:\n");
	printf("%hd", -32768);
	printf("\n");

	printf("actual_0136:\n");
	ft_printf("%hd", -32769);
	printf("\n");
	printf("expected_0136:\n");
	//printf("%hd", -32769);
	printf("\n");

	printf("*************************************************************\n");
	printf("actual_136:\n");
	i = ft_printf("%hd", -32769);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_136:\n");
	i = printf("%hd", -32769);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	printf("actual_012:\n");
	ft_printf("%x", 42);
	printf("\n");
	printf("expected_012:\n");
	printf("%x", 42);
	printf("\n");

	printf("*************************************************************\n");
	printf("actual_144:\n");
	i = ft_printf("%ld", -2147483649);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_144:\n");
	i = printf("%ld", -2147483649);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	printf("actual_177:\n");
	ft_printf("%+u", 4294967295);
	printf("\n");
	printf("expected_177:\n");
	printf("%+u", 4294967295);
	printf("\n");


	printf("*************************************************************\n");
	printf("actual_167:\n");
	i = ft_printf("%u", 0);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_167:\n");
	i = printf("%u", 0);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	printf("*************************************************************\n");
	j = -42;
	printf("actual_180:\n");
	i = ft_printf("%lu", -42);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_180:\n");
	i = printf("%lu", j);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	printf("*************************************************************\n");
	printf("actual_182:\n");
	i = ft_printf("@moulitest: %.5u", 42);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_182:\n");
	i = printf("@moulitest: %.5u", 42);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	char grade = "B";
	char name[] = "Josh";
	char sport[] = "football";
	int age = 18;
	double fees = 19.8;

	printf("PFT:\n");

	printf("*************************************************************\n");
	printf("actual_0001:\n");
	i = ft_printf("%");
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_0001:\n");
	i = printf("%");
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	printf("*************************************************************\n");
	printf("actual_0004:\n");
	i = ft_printf("%Z");
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_0004:\n");
	i = printf("%Z");
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	printf("*************************************************************\n");
	printf("actual_9:\n");
	i = ft_printf("%05%");
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_9:\n");
	i = printf("%05%");
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	printf("*************************************************************\n");
	printf("actual_10:\n");
	i = ft_printf("%-05%");
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_10:\n");
	i = printf("%-05%");
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	printf("*************************************************************\n");
	printf("actual_11:\n");
	i = ft_printf("%");
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_11:\n");
	i = printf("%");
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	printf("*************************************************************\n");
	printf("actual_12:\n");
	i = ft_printf("%5");
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_12:\n");
	i = printf("%5");
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	printf("*************************************************************\n");
	printf("actual_482:\n");
	i = ft_printf("%+.0i", 0);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_482:\n");
	i = printf("%+.0i", 0);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	printf("*************************************************************\n");
	printf("actual_960:\n");
	i = ft_printf("%#.5x", 21);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_960:\n");
	i = printf("%#.5x", 21);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	printf("*************************************************************\n");
	printf("actual_977:\n");
	i = ft_printf("%#08.5x", 34);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_977:\n");
	i = printf("%#08.5x", 34);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	printf("*************************************************************\n");
	printf("actual_1215:\n");
	i = ft_printf("%#o", 4294967295u);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_1215:\n");
	i = printf("%#o", 4294967295u);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	printf("*************************************************************\n");
	printf("actual_1313:\n");
	i = ft_printf("this %f float", 1.5);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_1313:\n");
	i = printf("this %f float", 1.5);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	printf("*************************************************************\n");
	printf("actual_1317:\n");
	i = ft_printf("%f", 573.924);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_1317:\n");
	i = printf("%f", 573.924);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");
	
	printf("*************************************************************\n");
	printf("actual_1321:\n");
	i = ft_printf("%f", -7.00036);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_1321:\n");
	i = printf("%f", -7.00036);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	printf("*************************************************************\n");
	printf("actual_1322:\n");
	i = ft_printf("%f", -0.00032);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_1322:\n");
	i = printf("%f", -0.00032);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	printf("*************************************************************\n");
	printf("actual_1333:\n");
	i = ft_printf("%f", 0.0894255);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_1333:\n");
	i = printf("%f", 0.0894255);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	printf("*************************************************************\n");
	printf("actual_1343:\n");
	i = ft_printf("this %.0f float", 1.6);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_1343:\n");
	i = printf("this %.0f float", 1.6);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");
*/
	printf("*************************************************************\n");
	printf("actual_1353:\n");
	i = ft_printf("this %.1f float", 1.5);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("expected_1353:\n");
	i = printf("this %.1f float", 1.5);
	printf("\n");
	printf("Returned value: %d", i);
	printf("\n");
	printf("*************************************************************\n");

	return (0);
}
