/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 16:54:29 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/04/08 19:54:58 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void n_format(t_prt *prt)
{
	int *arg;
	int ret;

	ret = (int)ft_strlen(prt->output);
	arg = va_arg(prt->ap, int*);
	*arg = ret;
}
static int	copy_format(t_prt *prt)
{
	char *str;
	size_t index;

	index = 0;
	str = (char*)malloc(sizeof(prt->i - prt->prev_i + 1));
	while (prt->prev_i < prt->i)
		str[index++] = prt->format[prt->prev_i++];
	str[index] = '\0';
	add_value_to_str(prt, str);
	free(str);
}

static int	handle_flag(t_prt *prt)
{
	prt->format[++prt->i] == 'i' ? output_int(prt) : 0;
	prt->format[prt->i] == '%' ? add_value_to_str(prt, "%") : 0;
	prt->format[prt->i] == 'n' ? n_format(prt) : 0;

	while (ft_isalpha(prt->format[prt->i]) == 1 && prt->format[prt->i])
		prt->i++;
	prt->prev_i = prt->i;

}

static void parse_format(t_prt *prt)
{
	while (prt->format[prt->i])
	{
		prt->format[prt->i] == '%' ? handle_flag(prt) : prt->i++;
		copy_format(prt);
	}
}

static void init(t_prt *printf)
{
	printf->i = 0;
	printf->j = 0;
	printf->prev_i = 0;
	printf->width = 0;
	printf->precision = 0;
	printf->output = ft_strnew(0);
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
	free(prt->output);
	free(prt);
	return(0);
}

int main(int argc, char **argv)
{
	int n;
	int m;

//	ft_printf("moro %n \t", &n);
//	ft_printf("%i\n", n);

	//printf("moro %n \t", &m);
	//printf("%i\n", m);
//	ft_printf("%i\n", 34);
	//ft_printf("%i %i", 1, 2);
	//ft_printf("%% %% %% %i", 4);
	//ft_printf(" MORO vaan KYL MORO %i %i %i KYL ON \n", 13456, 23456, 3444);
	//printf(" MORO vaan KYL MORO %i %i %i KYL ON \n", 13456, 23456, 3444);
	//printf(" jou %i esa G %i \n", 1, 2);
//	while(1);
	return(0);
}
