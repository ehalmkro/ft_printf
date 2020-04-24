//
// Created by Esa Halmkrona on 13.4.2020.
//

#include <stdlib.h>
#include "include/ft_printf.h"

int main (int argc, char **argv)
{

	ft_printf("%#-8x\n", 42);
	printf("%#-8x", 42);

//	ft_printf("%.2s is a string\n", "this");
//	printf("%.2s is a string\n", "this");
	//ft_printf("%f", 1245.254);
	//printf("%f", "12.254");
	//ft_printf("%llX\n", 4294967296);
//	ft_printf("%lX\n", 4294967296);
//	ft_printf("%jX", 4294967296);
//	ft_printf("%zX\n", 4294967296);
//	ft_printf("%tX\n", 4294967296);
	//ft_printf(";%c;\n", 0);
//	printf("%d %d\n", 2500, -2);
	//ft_printf("%d\n", -2);

	return(0);
}