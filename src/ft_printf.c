/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 16:54:29 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/07/29 16:06:17 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	copy_format(t_prt *prt)
{
	char	*str;
	size_t	i;

	i = 0;
	if (prt->prev_i == prt->i)
		return (0);
	str = (char*)malloc(sizeof(char) * prt->i - prt->prev_i);
	while (prt->prev_i <= prt->i)
	{
		if (prt->format[prt->prev_i] != '%')
		{
			str[i] = prt->format[prt->prev_i];
			i++;
		}
		prt->prev_i++;
	}
	if (!CURR_POS)
		i--;
	join_value_to_output(prt, str, i);
	free(str);
	prt->prev_i = prt->i;
	return (0);
}

static void	parse_format(t_prt *prt)
{
	while (CURR_POS)
	{
		while (CURR_POS != '%' && CURR_POS)
			prt->i++;
		if (CURR_POS == '%')
		{
			copy_format(prt);
			handle_params(prt);
		}
		else
			copy_format(prt);
	}
}

static void	init(t_prt *printf)
{
	printf->i = 0;
	printf->prev_i = 0;
	printf->width = 0;
	printf->prec = 0;
	printf->strlen_output = 0;
	printf->strlen_value = 0;
	printf->output = (char*)malloc(sizeof(char));
	printf->incl_space = FALSE;
	printf->incl_hash = FALSE;
	printf->incl_plus = FALSE;
	printf->incl_dot = FALSE;
	printf->length = undef;
	printf->u_sign = FALSE;
	printf->base = 10;
}

int			ft_printf(const char *format, ...)
{
	t_prt	*prt;
	int		ret;

	prt = (t_prt*)malloc(sizeof(t_prt));
	if (format)
	{
		va_start(prt->ap, format);
		prt->format = (char*)format;
		init(prt);
		parse_format(prt);
	}
	ft_putnstr(prt->output, prt->strlen_output);
	free(prt->output);
	ret = prt->strlen_output;
	free(prt);
	return (ret);
}
