/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 20:15:50 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/06/09 15:27:26 by ehalmkro         ###   ########.fr       */
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
	int padding;
	char *temp;


	prt->base = 16;
	ret = prt->length == undef ? ft_itoa_base(va_arg(prt->ap, int),
			prt->base) : integer_length(prt);
	padding = prt->width - ft_strlen(ret);
	if (prt->include_hash == TRUE && ft_atoi(ret) != 0 && padding < 3)
	{
		temp = ft_strjoin("0x", ret);
		prt->include_hash = FALSE;
		free(ret);
		ret = ft_strdup(temp);
	}
	ret = CURR_POS == 'X' ? ft_strupr(ret) : ret;
	if (prt->include_dot == TRUE && prt->precision == 0)
	{
		free(ret);
		ret = ft_strdup("");
	}
	prt->strlen_value = ft_strlen(ret);
	if (prt->width - ft_strlen(ret) > 0 && prt->width != 0)
		ret = add_width(prt, ret);
	return(ret);
}