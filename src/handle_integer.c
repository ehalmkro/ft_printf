/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:40:24 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/04/15 16:15:40 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void handle_int_width(t_prt *prt, char *ret)
{
	if (prt->precision >= prt->width)
		add_value_to_str(prt, ret);
	else
		add_width(prt, ret);
}

static char *handle_int_precision(t_prt *prt, char *value)
{
	size_t len;
	char *ret;
	char *padding;
	size_t i;

	i = 0;
	len = prt->precision - ft_strlen(value);
	padding = ft_strnew(len + 1);
	if (value[0] == '-')
	{
		padding[i++] = '-';
		value++;
		len++;
	}
	while (len-- > 0)
	{
		padding[i++] = '0';
	}
	padding[i] = '\0';
	ret = ft_strjoin(padding, value);
	free(padding);
	return (ret);
}

char *integer_length(t_prt *prt, int base)
{
	long long nb;

	nb = 0;
	nb = prt->length == hh ? (char)va_arg(prt->ap, int) : nb;
	nb = prt->length == h ? (short)va_arg(prt->ap, int) : nb;
	nb = prt->length == ll ? va_arg(prt->ap, long long) : nb;
	nb = prt->length == l ? va_arg(prt->ap, long) : nb;
	return (ft_itoa_base(nb, base));
}
void output_int(t_prt *prt)
{
	char	*ret;
	char	*temp;

	ret = prt->length == undef ? ft_itoa_base(va_arg(prt->ap, int), 10) : integer_length(prt, 10);
	prt->include_space == TRUE ? add_value_to_str(prt, " ") : 0;
	if (prt->precision > 0)
	{
		temp = ret;
		free (ret);
		ret = handle_int_precision(prt, temp);
	}
	prt->width > 0 ? handle_int_width(prt, ret) : add_value_to_str(prt, ret);
	free(ret);
}