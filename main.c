//
// Created by Esa Halmkrona on 13.4.2020.
//

#include <stdlib.h>
#include <limits.h>
#include "include/ft_printf.h"

int main (int argc, char **argv)
{

	//printf("%s\n", join_values("   ", 3, "esa", 3));
	//ft_printf("%Z");
	//printf("\n");
	//printf("%Moor");
//	printf("\n");


int i = printf("{%30d}", 10000);
	printf("\n");
int j =	ft_printf("{%30d}", 10000);
	printf("\n%i\n%i\n", i, j);
	return(0);
	// TODO: POINTERS!
}