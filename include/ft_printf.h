/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:08:36 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/07/31 18:23:41 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CURR_POS prt->format[prt->i]
# define NEXT_POS prt->format[prt->i + 1]
# define PREV_POS prt->format[prt->i - 1]

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../Libft/libft.h"

typedef enum
{
	FALSE,
	TRUE
}	t_boolean;

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
}	t_length;

typedef struct	s_printf
{
	char		*format;
	char		*output;
	va_list		ap;

	size_t		i;
	size_t		prev_i;

	int			prec;
	int			width;

	size_t		base;
	t_boolean	incl_space;
	t_boolean	incl_hash;
	t_boolean	incl_plus;
	t_boolean	incl_dot;
	t_boolean	incl_zero;
	t_boolean	incl_minus;
	t_boolean	u_sign;
	char		padding_char;

	t_length	length;
	int			strlen_output;
	int			strlen_value;

}				t_prt;

typedef struct	s_convert
{
	const char	specifier;
	char		*(*f)(t_prt *prt);
}				t_convert;

int				ft_printf(const char *format, ...);

void			hex_width(t_prt *prt, char **ret, char **pad, int *pad_count);
void			switch_width_sign(char **ret, char **padding);

char			*output_int(t_prt *prt);
char			*output_hex(t_prt *prt);
char			*output_string(t_prt *prt);
char			*output_char(t_prt *prt);
char			*output_float(t_prt *prt);
char			*n_format(t_prt *prt);
char			*percent_format(t_prt *prt);
char			*output_pointer(t_prt *prt);

void			join_value_to_output(t_prt *ptr, char *value, size_t len);
char			*join_values(char *dst, size_t dst_len,
				char *src, size_t src_len);

char			*handle_int_precision(t_prt *prt, char *value);

void			handle_params(t_prt *prt);

char			*add_width(t_prt *prt, char *ret);

intmax_t		get_integer_length(t_prt *tab);
void			get_width(t_prt *prt);
void			get_flags(t_prt *prt);
void			get_precision(t_prt *prt);
void			get_length(t_prt *prt);
long double		rounding(long double nb, int precision);

void			add_space_to_output(t_prt *prt);
char			*initialize_int(t_prt *prt);

#endif
