//
// Created by Esa Halmkrona on 13.4.2020.
//

#include <stdlib.h>
#include "include/ft_printf.h"

int main (int argc, char **argv)
{
	printf("%#10X\n", 255);
	ft_printf("%#10X\n", 255);

	return(0);
}