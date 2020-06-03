#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#define CURR_POS prt->format[prt->i]
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
	size_t base;
	e_boolean include_space;
	e_boolean include_hash;
	e_boolean include_plus;
	e_boolean include_dot;
	char padding_char;
	size_t width;
	e_length length;
	size_t strlen_output;
	size_t strlen_value;

}					t_prt;

typedef struct  s_convert
{
	const char  specifier;
	char*        (*f)(t_prt *prt);
}               t_convert;


int					ft_printf(const char *format, ...);

char *				output_int(t_prt *prt);
char * 				output_hex(t_prt *prt);
char * 				output_string(t_prt *prt);
char *				output_char(t_prt *prt);
char *				output_float(t_prt *prt);
char *				n_format(t_prt *prt);
char * 				percent_format(t_prt *prt);

char *str_toupper(char *str); // TODO: ADD THIS TO LIB

void 				add_value_to_str(t_prt *ptr, char *value);

void handle_params(t_prt *prt);

char* 				add_width(t_prt *prt, char *ret);

char 				*integer_length(t_prt *prt);

#endif //FT_PRINTF_H
