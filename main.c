//
// Created by Esa Halmkrona on 13.4.2020.
//

#include <stdlib.h>
#include "include/ft_printf.h"

int main (int argc, char **argv)
{


	ft_printf("%-#6o", 2500);
	printf("\n");
	printf("%-#6o", 2500);

	return(0);
}