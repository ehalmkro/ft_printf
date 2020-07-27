/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 16:54:29 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/07/27 15:43:03 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	copy_format(t_prt *prt)
{
	char	*str;
	char	*temp;
	char 	*temp2;
	size_t	i;

	i = 0;
	temp = ft_strnew(prt->strlen_output);
	ft_memmove(temp, prt->output, prt->strlen_output);
	str = ft_strnew(prt->i - prt->prev_i);
	while (prt->prev_i <= prt->i)
	{
		str[i] = prt->format[prt->prev_i];
		i++;
		prt->prev_i++;
	}
	str = join_values(temp, prt->strlen_output, str, i);
	if (!CURR_POS)
		i--;
	prt->strlen_output += i;
	free(prt->output);
	prt->output = (char*)malloc(sizeof(char) * prt->strlen_output);
	ft_memmove(prt->output, str, prt->strlen_output);
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
			if (prt->prev_i != prt->i)
			{
				--prt->i;
				copy_format(prt);
				++prt->i;
			}
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
	printf->precision = 0;
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
	printf->flag_mask = "-+ 0#";
	printf->length_mask = "lhjz";
}

int			ft_printf(const char *format, ...)
{
	t_prt	*prt;

	prt = (t_prt*)malloc(sizeof(t_prt));
	if (format)
	{
		va_start(prt->ap, format);
		prt->format = (char*)format;
		init(prt);
		parse_format(prt);
	}
	ft_putnstr(prt->output, prt->strlen_output);
	free(prt);
	return (prt->strlen_output);
}
