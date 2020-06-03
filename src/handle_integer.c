/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:40:24 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/06/02 11:51:10 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char *handle_int_width(t_prt *prt, char *ret)
{
	if (prt->precision >= prt->width)
		return(ret);
	else
		return(add_width(prt, ret));
}

static char *handle_int_precision(t_prt *prt, char *value)
{
	int len;
	char *ret;
	char *padding;
	int i;

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

char *integer_length(t_prt *prt)
{
	long long nb;

	nb = 0;
	if (CURR_POS == 'u')
	{
		nb = prt->length == h ? (unsigned short) va_arg(prt->ap, int) : nb;
		nb = prt->length == ll ? (unsigned long long)va_arg(prt->ap, long long) : nb;
		nb = prt->length == l ? (unsigned long)va_arg(prt->ap, long) : nb;
	}
	else
	{
		nb = prt->length == hh ? (char) va_arg(prt->ap, int) : nb;
		nb = prt->length == h ? (short) va_arg(prt->ap, int) : nb;
		nb = prt->length == ll ? va_arg(prt->ap, long long) : nb;
		nb = prt->length == l ? va_arg(prt->ap, long) : nb;
	}
	return (ft_itoa_base(nb, prt->base));
}
char *output_int(t_prt *prt)
{
	char	*ret;
	char	*temp;

	CURR_POS == 'o' ? prt->base = 8 : 0;
	if (CURR_POS == 'u')
		ret = prt->length == undef ? ft_itoa_base(va_arg(prt->ap, unsigned int), prt->base) : integer_length(prt);
	else
		ret = prt->length == undef ? ft_itoa_base(va_arg(prt->ap, int), prt->base) : integer_length(prt);
	prt->include_space == TRUE ? add_value_to_str(prt, " ") : 0;
	if (prt->precision > 0)
	{
		temp = ft_strdup(ret);
		free (ret);
		ret = handle_int_precision(prt, temp);
		free(temp);
	}
	temp = prt->include_plus == TRUE ? ft_strdup("+") : NULL;
	ret = temp != NULL && ft_atoi(ret) >= 0 ? ft_strjoin(temp, ret) : ret;
	if (prt->include_dot == TRUE && prt->precision == 0 && ft_atoi(ret) == 0)
	{
		free(ret);
		ret = ft_strdup("");
	}
	ret = prt->width > 0 ? handle_int_width(prt, ret) : ret;
	free(temp);
	return(ret);
}