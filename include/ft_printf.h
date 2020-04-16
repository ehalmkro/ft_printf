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
	FALSE,
	TRUE
}	e_boolean;

typedef enum
{
	undef,
	hh,
	h,
	ll,
	l,
	j,
	z,
	t,
	L
}	e_length;

typedef struct		s_printf
{
	char *format;
	char *output;
	va_list ap;

	size_t precision;
	size_t i;
	size_t prev_i;
	size_t j;
	e_boolean include_space;
	e_boolean include_hash;
	char padding_char;
	size_t width;
	e_length length;
}					t_prt;

int					ft_printf(const char *format, ...);

void				output_int(t_prt *prt);
void 				output_hex(t_prt *prt);
void 				output_string(t_prt *prt);
void				output_char(t_prt *prt);

void 				add_value_to_str(t_prt *ptr, char *value);

int					handle_params(t_prt *prt);

void 				add_width(t_prt *prt, char *ret);

char 				*integer_length(t_prt *prt, int base);

#endif //FT_PRINTF_H
