/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:40:24 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/04/10 20:11:58 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void output_int(t_prt *prt)
{
	char *ret;
	size_t padding_count;
	char *padding;
	size_t i;

	i = 0;
	ret = ft_itoa(va_arg(prt->ap, int));
	prt->include_space == TRUE ? add_value_to_str(prt, " ") : 0;
	if (prt->width > 0)
	{
		padding_count = prt->width - ft_strlen(ret);
		padding = ft_strnew(padding_count);
		while (padding_count-- - 1 > 0)
			padding[i++] = prt->padding_char == '0' ? '0' : ' ';
		prt->padding_char == '0' ? add_value_to_str(prt, padding) : add_value_to_str(prt, ret);
		prt->padding_char == '0' ? add_value_to_str(prt, ret) : add_value_to_str(prt, padding);
	}
	else
		add_value_to_str(prt, ret);
	free(ret);
}