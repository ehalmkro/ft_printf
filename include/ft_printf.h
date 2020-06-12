#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#define CURR_POS prt->format[prt->i]
#define NEXT_POS prt->format[prt->i + 1]

#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define UINT_MAX 4294967295
#define ULONG_MAX 18,446,744,073,709,551,615
#define LONG_MIN -9223372036854775808
#define LONG_MAX 9223372036854775807

#include <stdio.h>						// TODO: REMOVE THIS
#include <string.h>						// TODO: REMOVE THIS
#include <stdarg.h>
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

	int precision;
	size_t i;
	size_t prev_i;
	size_t base;
	e_boolean include_space;
	e_boolean include_hash;
	e_boolean include_plus;
	e_boolean include_dot;
	e_boolean include_zero;
	e_boolean include_minus;
	e_boolean u_sign;
	char *flag_mask;
	char *length_mask;
	char padding_char;
	int width;
	e_length length;
	int strlen_output;
	int strlen_value;

}					t_prt;

typedef struct  s_convert
{
	const char  specifier;
	char*        (*f)(t_prt *prt);
}               t_convert;


int					ft_printf(const char *format, ...);

void hex_width(t_prt *prt, char **ret, char **padding, char padding_char, int *padding_count);
void int_width(t_prt *prt, char **ret, char **padding, int *padding_count);


char 				*output_int(t_prt *prt);
char 				*output_hex(t_prt *prt);
char 				*output_string(t_prt *prt);
char 				*output_char(t_prt *prt);
char 				*output_float(t_prt *prt);
char 				*n_format(t_prt *prt);
char 				*percent_format(t_prt *prt);
char 				*output_pointer(t_prt *prt);

char *ft_strupr(char *str);

void 				join_value_to_output(t_prt *ptr, char *value, size_t len);
char 				*join_values(char *dst, size_t dst_len, char *src, size_t src_len);

char *handle_int_precision(t_prt *prt, char *value);



void handle_params(t_prt *prt);

char* 				add_width(t_prt *prt, char *ret);

intmax_t 	integer_length(t_prt *tab);

#endif //FT_PRINTF_H
