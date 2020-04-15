//
// Created by Esa Halmkrona on 13.4.2020.
//

#include <stdlib.h>
#include "include/ft_printf.h"

int main (int argc, char **argv)
{

	ft_printf("%09x\n", 42);
	printf("%0#9x", 42);
	//ft_printf("%llX\n", 4294967296);
//	ft_printf("%lX\n", 4294967296);
//	ft_printf("%jX", 4294967296);
//	ft_printf("%zX\n", 4294967296);
//	ft_printf("%tX\n", 4294967296);
//	ft_printf("%LX\n", 4294967296);

	return(0);
}