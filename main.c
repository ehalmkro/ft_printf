//
// Created by Esa Halmkrona on 13.4.2020.
//

#include <stdlib.h>
#include <limits.h>
#include "include/ft_printf.h"

void compare_printf(char *str)
{
	printf("SYSTEM\t");
	int i = printf("%s", str);
	printf("\n");
	int j = ft_printf("%s", str);
	printf("\n");
	printf("SYS %i\tOWN %i\n\n", i, j);
}

void compare_printf_1(char *str, int value1)
{
	int i = printf(str, value1);
	printf("\n");
	int j = ft_printf(str, value1);
	printf("\n");
	printf("SYS %i\tOWN %i\n\n", i, j);
}

void compare_printf_2(char *str, int value1, int value2)
{
	int i = printf(str, value1, value2);
	printf("\n");
	int j = ft_printf(str, value1, value2);
	printf("\n");
	printf("SYS %i\tOWN %i\n\n", i, j);
}

int main (int argc, char **argv)
{
	//compare_printf_1("%f", 1.1);
//	compare_printf_1("%15.4d", 42);

//	compare_printf_1("%lld", LLONG_MIN);
	//compare_printf_2("%7s%-5s", "hello", "world");
//	compare_printf_2("%*d", 5, 42);
//	compare_printf_2("{%*d}", -5, 42);
//	compare_printf_2("{%*c}", -15, 0);
//	compare_printf_2("%0*i", -7, -54);
//
	for (int i = 0; i < 9999; i++){
	int j = printf("%.6d", -3);
	printf("\n");
	int g = ft_printf("%.6d", -3);;
		printf("\n");

	printf("\n");
		printf("%i %i\n", g, j);
	}

//while(1);

	//ft_printf("%s\n", ft_uintmaxtoa(6465424242242));
	return(0);
}