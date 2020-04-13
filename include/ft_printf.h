#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>						// TODO: REMOVE THIS
#include <string.h>						// TODO: REMOVE THIS
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../Libft/libft.h"

typedef enum
{
	TRUE,
	FALSE
}	e_boolean;

typedef struct		s_printf
{
	char *format;
	char *output;
	va_list ap;

	char specifier;
	size_t precision;
	size_t i;
	size_t prev_i;
	size_t j;
	e_boolean include_space;
	char padding_char;
	size_t width;


}					t_prt;

int					ft_printf(const char *format, ...);

void				output_int(t_prt *prt);

void 				add_value_to_str(t_prt *ptr, char *value);

int					handle_params(t_prt *prt);

void 				add_width(t_prt *prt, char *ret);

#endif //FT_PRINTF_H
