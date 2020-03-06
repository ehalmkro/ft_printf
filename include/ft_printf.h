#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>						// TODO: REMOVE THIS
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct		s_printf
{
	char *format;
	char *output;
	va_list ap;

	char specifier;
	size_t width;
	size_t precision;
	size_t i;

}					t_prt;

int					ft_printf(const char *format, ...);
void				ft_putstr(char const *s);
size_t				ft_strlen(const char *s);
char				*ft_strndup(const char *s1, size_t len);

#endif //FT_PRINTF_H
