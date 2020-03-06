#include "../include/ft_printf.h"

static int handle_flag(t_prt *prt)
{

	prt->i++;
	return (1);

}

static int parse_format(t_prt *prt)
{
	while (prt->format[prt->i])
	{
		prt->format[prt->i] == '%' ? handle_flag(prt) : prt->i++;
	}
	prt->output = ft_strndup(prt->format, prt->i);
	return(prt->i);
}

static void init(t_prt *printf)
{
	printf->i = 0;
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
		prt->format = (char*)format;
		init(prt);
		parse_format(prt);
	}
	ft_putstr(prt->output);
	return(0);
}

int main(int argc, char **argv)
{
	ft_printf("jou %i\n", 245);
	printf("jou %c\n", '\0');
	return(0);
}
