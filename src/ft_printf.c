/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 16:54:29 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/04/13 16:49:48 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"


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
	return(0);
}

static void parse_format(t_prt *prt)
{
	while (prt->format[prt->i])
	{
		prt->format[prt->i] == '%' ? handle_params(prt) : prt->i++;
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
	printf->include_space = FALSE;
	printf->include_hash = FALSE;
}
int ft_printf(const char *format, ...)
{
	t_prt *prt;
	int ret;

	prt = (t_prt*)malloc(sizeof(t_prt));
	if (format)
	{
		va_start(prt->ap, format);
		prt->format = (char*)format;
		init(prt);
		parse_format(prt);
	}
	ft_putstr(prt->output);
	ret = ft_strlen(prt->output);
	free(prt->output);
	free(prt);
	return(ret);
}
