/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 16:54:29 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/07/31 18:32:17 by ehalmkro         ###   ########.fr       */
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
	printf->output = (char*)malloc(sizeof(char));
	printf->i = 0;
	printf->prev_i = 0;
	printf->prec = 0;
	printf->width = 0;
	printf->base = 10;
	printf->incl_space = FALSE;
	printf->incl_hash = FALSE;
	printf->incl_plus = FALSE;
	printf->incl_dot = FALSE;
	printf->incl_minus = FALSE;
	printf->incl_zero = FALSE;
	printf->padding_char = ' ';
	printf->length = undef;
	printf->u_sign = FALSE;
	printf->strlen_output = 0;
	printf->strlen_value = 0;
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

char		*ft_sprintf(const char *format, ...)
{
	t_prt	*prt;
	char	*ret;

	prt = (t_prt*)malloc(sizeof(t_prt));
	if (format)
	{
		va_start(prt->ap, format);
		prt->format = (char*)format;
		init(prt);
		parse_format(prt);
	}
	ft_putnstr(prt->output, prt->strlen_output);
	ret = ft_strdup(prt->output);
	free(prt->output);
	free(prt);
	return (ret);
}
