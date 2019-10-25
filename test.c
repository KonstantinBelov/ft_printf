#include <stdio.h>
#include "ft_printf.h"
int		main(void)
{
	// /*
	// printf("%-5c", 'a');
	// printf("% ");
	// */
	// short x = -32768;
	// int i =	printf("%hd", x);
	// printf("\n");
	// printf("%d\n", i);

	// short y = -32769;
	// int j =	printf("%hd", y);
	// printf("\n");
	// printf("%d\n", j);



	printf("%hd", -32768);
	ft_printf("%hd", -32768);
	return(0);
}
