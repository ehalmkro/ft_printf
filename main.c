//
// Created by Esa Halmkrona on 13.4.2020.
//

#include <stdlib.h>
#include "include/ft_printf.h"

int main (int argc, char **argv)
{

	//printf("%s\n", join_values("   ", 3, "esa", 3));
	//ft_printf("%Z");
	//printf("\n");
	//printf("%Moor");
//	printf("\n");
	int i = ft_printf("Line Feed %s", "\\n");
	printf("\n");
	int j = printf("%");
	printf("\n");
	printf("Line Feed %s", "\\n");
//	printf("\n%i\n", i);
	///printf("%-#6o", 2500);
	return(0);
	// TODO: POINTERS!
}