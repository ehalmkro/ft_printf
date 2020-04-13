/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:40:24 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/04/13 15:16:21 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
static void handle_int_width(t_prt *prt, char *ret)
{
	size_t padding_count;
	char *padding;
	size_t i;

	if (prt->precision >= prt->width)
		add_value_to_str(prt, ret);
	else
	{
		i = 0;
		padding_count = prt->width - ft_strlen(ret);
		padding = ft_strnew(padding_count);
		while (padding_count-- > 0)
			padding[i++] = prt->padding_char == '0' ? '0' : ' ';
		prt->padding_char == '-' ? add_value_to_str(prt, ret) : add_value_to_str(prt, padding);
		prt->padding_char == '-' ? add_value_to_str(prt, padding) : add_value_to_str(prt, ret);
	}
}

static char *handle_int_precision(t_prt *prt, char *value)
{
	size_t len;
	char *ret;
	char *padding;
	size_t i;

	i = 0;
	len = prt->precision - ft_strlen(value);
	if (len <= 0)
		return NULL;
	padding = ft_strnew(len);
	while (len-- > 0)
		padding[i++] = '0';
	ret = ft_strjoin(padding, value);
	return (ret);
}
void output_int(t_prt *prt)
{
	char *ret;

	ret = ft_itoa(va_arg(prt->ap, int));
	prt->include_space == TRUE ? add_value_to_str(prt, " ") : 0;
	if (prt->precision > 0)
		ret = handle_int_precision(prt, ret);
	prt->width > 0 ? handle_int_width(prt, ret) : add_value_to_str(prt, ret);;
	free(ret);
}