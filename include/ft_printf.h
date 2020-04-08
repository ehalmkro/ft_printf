#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>						// TODO: REMOVE THIS
#include <string.h>						// TODO: REMOVE THIS
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../Libft/libft.h"

typedef struct		s_printf
{
	char *format;
	char *output;
	va_list ap;

	char specifier;
	size_t width;
	size_t precision;
	size_t i;
	size_t prev_i;
	size_t j;

}					t_prt;

int					ft_printf(const char *format, ...);

void				output_int(t_prt *prt);

void add_value_to_str(t_prt *ptr, char *value);


#endif //FT_PRINTF_H
