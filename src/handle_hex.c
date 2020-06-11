/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 20:15:50 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/06/11 14:39:22 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void hex_width(t_prt *prt, char **ret, char **padding, char padding_char, int *padding_count)
{

	(*padding)[1] = prt->strlen_value < prt->width && padding_char == '0' ? CURR_POS : (*padding)[1];
	if (padding_char == ' ')
	{

		if (!prt->include_minus)
		{
			(*padding)[*padding_count] = '\0';
			(*padding)[--*padding_count] = 'x';
			(*padding)[--*padding_count] = '0';
			*padding = CURR_POS == 'X' ? ft_strupr(*padding) : *padding;
		}
		else
		{
			*ret = CURR_POS == 'x' ? join_values("0x", 2, *ret, prt->strlen_value)
				: join_values("0X", 2, *ret, prt->strlen_value);
			prt->strlen_value += 2;
			*padding_count -= 2;
		}
	}
}

char *output_hex(t_prt *prt) // TODO: NEGATIVE HEX VALUES ARE LONG INT - VALUE
{
	char *ret;
	int padding_count;
	char *temp;

	prt->base = 16;
	if (CURR_POS == 'p')
		ret = ft_itoa_base(va_arg(prt->ap, long int), prt->base);
	else
		ret = prt->length == undef ? ft_itoa_base(va_arg(prt->ap, int),
			prt->base) : integer_length(prt);
	padding_count = prt->width - ft_strlen(ret);
	if (prt->include_dot == TRUE)
	{
		if (prt->precision == 0)
			ret = ft_strdup("");
		else
			ret = handle_int_precision(prt, ret);
	}
	if (((prt->include_hash == TRUE && ((ft_atoi(ret) != 0 && padding_count < 3))) ||
	CURR_POS == 'p'))
	{
		temp = ft_strjoin("0x", ret);
		prt->include_hash = FALSE;
		free(ret);
		ret = ft_strdup(temp);
		free(temp);
	}
	ret = CURR_POS == 'X' ? ft_strupr(ret) : ret;

	prt->strlen_value = ft_strlen(ret);
	if (prt->width - ft_strlen(ret) > 0 && prt->width != 0)
		ret = add_width(prt, ret);
	return(ret);
}