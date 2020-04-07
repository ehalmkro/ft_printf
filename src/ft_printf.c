#include "../include/ft_printf.h"

static int	copy_format(t_prt *prt)
{
	size_t j;
	if (!prt->output)
	{
		j = 0;
		prt->output = ft_strnew(prt->i - 1);
	}
	else
		j = ft_strlen(prt->output);
	while (j < prt->i)
	{
		prt->output[j++] = prt->format[prt->prev_i++];
	}
}


static int	handle_flag(t_prt *prt)
{
	copy_format(prt);
	prt->format[++prt->i] == 'i' ? output_int(prt) : 0;
	while (ft_isalpha(prt->format[prt->i]) == 1)
		prt->i++;
	prt->prev_i = prt->i;
}

static void parse_format(t_prt *prt)
{
	while (prt->format[prt->i++])
	{
		prt->format[prt->i] == '%' ? handle_flag(prt) : 0;
	}
	copy_format(prt);
}

static void init(t_prt *printf)
{
	printf->i = 0;
	printf->prev_i = 0;
	printf->width = 0;
	printf->precision = 0;
}
int ft_printf(const char *format, ...)
{
	va_list ap;
	t_prt *prt;

	prt = (t_prt*)malloc(sizeof(t_prt));
	if (format)
	{
		va_start(prt->ap, format);
		prt->format = (char*)format;
		init(prt);
		parse_format(prt);
	}
	ft_putstr(prt->output);
	return(0);
}

int main(int argc, char **argv)
{
	ft_printf(" jou %i esa G %i %i\n", 1, 2, 3);
	printf(" jou %i esa G %i \n", 1, 2);
	return(0);
}
