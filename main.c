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

/*	char *format = "%#041o\n";
	int int1 = 20;
	printf("%s\n", "Octal D");
	printf(format, int1);
	ft_printf(format, int1);

	format = "%0 42hhu\n";
	int1 = 5656;
	printf("%s\n", "Unsigned Integer P");
	printf(format, int1);
	ft_printf(format, int1);

	format = "%010.1f\n";
	double double1 = 7.3;
	printf("%s\n", "Float x");
	printf(format, double1);
	ft_printf(format, double1);*/

/*
	printf("this %#.10f float", -0.0);
	printf("\n");
	ft_printf("this %#.10f float", -0.0);
	printf("\n");
	printf("this %05.0f", -7.3);
	printf("\n");
	ft_printf("this %05.0f", -7.3);
	printf("\n");
*/

/*	ft_printf("% 05.0f", -7.3);
	printf("\n");
	printf("% 05.0f", -7.3);
	printf("\n");
	ft_printf("% 05.6f", 7.3);
	printf("\n");
	printf("% 05.6f", 7.3);
	printf("\n");*/
/*	ft_printf("%f", -3.3);
	printf("\n");
	printf("%f", -3.3);
	printf("\n");*/


ft_printf("%05.5", -0.0);
/*	ft_printf("% 5.0f", -0.0);
	printf("\n");
	printf("% 5.0f", -0.0);
	printf("\n");
	ft_printf("% 05.0f", 7.3);
	printf("\n");
	printf("% 05.0f", 7.3);
	printf("\n");
	ft_printf("%5.3f", -0.0);
	printf("\n");
	printf("%5.3f", -0.0);*/

//ft_printf("moro %lld\n", LONG_LONG_MAX);



/*
		ft_printf("%.4d", 42);
		printf("\n");
		printf("%.4d", 42);
		printf("\n");
		ft_printf("%.4d", 424242);
		printf("\n");
		printf("%.4d", 424242);
		printf("\n");
		ft_printf("%.4d", -424242);
		printf("\n");
		printf("%.4d", -424242);
		printf("\n");
		ft_printf("%15.4d", 42);
		printf("\n");
		printf("%15.4d", 42);
		printf("\n");
		ft_printf("%15.4d", 424242);
		printf("\n");
		printf("%15.4d", 424242);
		printf("\n");
		ft_printf("%8.4d", 424242424);
		printf("\n");
		printf("%8.4d", 424242424);
		printf("\n");
		ft_printf("%15.4d", -42);
		printf("\n");
		printf("%15.4d", -42);
		printf("\n");
		ft_printf("%15.4d", -424242);
		printf("\n");
		printf("%15.4d", -424242);
		printf("\n");
		ft_printf("%8.4d", -424242424);
		printf("\n");
		printf("%8.4d", -424242424);
		printf("\n");
		ft_printf("%4.15d", 42);
		printf("\n");
		printf("%4.15d", 42);
		printf("\n");
		ft_printf("%4.15d", 424242);
		printf("\n");
		printf("%4.15d", 424242);
		printf("\n");
		ft_printf("%4.8d", 424242424);
		printf("\n");
		printf("%4.8d", 424242424);
		printf("\n");
		ft_printf("%4.15d", -42);
		printf("\n");
		printf("%4.15d", -42);
		printf("\n");
		ft_printf("%4.15d", -424242);
		printf("\n");
		printf("%4.15d", -424242);
		printf("\n");
		ft_printf("%4.8d", -424242424);
		printf("\n");
		printf("%4.8d", -424242424);
		printf("\n");
		ft_printf("%.d, %.0d", 0, 0);
		printf("\n");
		printf("%.d, %.0d", 0, 0);
		printf("\n");
		ft_printf("%.10d", -42);
		printf("\n");
		printf("%.10d", -42);
		printf("\n");
		ft_printf("%.4i", 42);
		printf("\n");
		printf("%.4i", 42);
		printf("\n");
		ft_printf("%15.4i", 42);
		printf("\n");
		printf("%15.4i", 42);
		printf("\n");
		ft_printf("%4.15i", 42);
		printf("\n");
		printf("%4.15i", 42);
		printf("\n");
		ft_printf("%.i, %.0i", 0, 0);
		printf("\n");
		printf("%.i, %.0i", 0, 0);
		printf("\n");
		ft_printf("%.4u", 42);
		printf("\n");
		printf("%.4u", 42);
		printf("\n");
		ft_printf("%.4u", 424242);
		printf("\n");
		printf("%.4u", 424242);
		printf("\n");
		ft_printf("%15.4u", 42);
		printf("\n");
		printf("%15.4u", 42);
		printf("\n");
		ft_printf("%15.4u", 424242);
		printf("\n");
		printf("%15.4u", 424242);
		printf("\n");
		ft_printf("%8.4u", 424242424);
		printf("\n");
		printf("%8.4u", 424242424);
		printf("\n");
		ft_printf("%4.15u", 42);
		printf("\n");
		printf("%4.15u", 42);
		printf("\n");
		ft_printf("%4.15u", 424242);
		printf("\n");
		printf("%4.15u", 424242);
		printf("\n");
		ft_printf("%4.8u", 424242424);
		printf("\n");
		printf("%4.8u", 424242424);
		printf("\n");
		ft_printf("%.u, %.0u", 0, 0);
		printf("\n");
		printf("%.u, %.0u", 0, 0);
		printf("\n");
		ft_printf("%32s", "abc");
		printf("\n");
		printf("%32s", "abc");
		printf("\n");
		ft_printf("%15.4d", 42);
		printf("\n");
		printf("%15.4d", 42);
		printf("\n");*/

//while(1);

	//ft_printf("%s\n", ft_uitoa(6465424242242));
	return(0);
}