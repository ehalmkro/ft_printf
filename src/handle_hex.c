/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 20:15:50 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/07/29 16:38:10 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		hex_width(t_prt *prt, char **ret, char **pad, int *pad_count)
{
	(*pad)[1] = prt->strlen_value < prt->width && prt->padding_char == '0'
		? CURR_POS : (*pad)[1];
	if (prt->padding_char == ' ')
	{
		if (!prt->incl_minus)
		{
			(*pad)[*pad_count] = '\0';
			(*pad)[--*pad_count] = 'x';
			(*pad)[--*pad_count] = '0';
			*pad = CURR_POS == 'X' ? ft_strupr(*pad) : *pad;
		}
		else
		{
			*ret = CURR_POS == 'x' ? join_values("0x", 2, *ret, prt->\
			strlen_value) : join_values("0X", 2, *ret, prt->strlen_value);
			prt->strlen_value += 2;
			*pad_count -= 2;
		}
	}
}

static char *add_hash(t_prt *prt, char *ret)
{
	char *temp;
	char *hex_hash;

	hex_hash = ft_strdup("0x");
	temp = ft_strjoin(hex_hash, ret);
	free(ret);
	ret = ft_strdup(temp);
	free(temp);
	free(hex_hash);
	prt->incl_hash = FALSE;
	return(ret);
}

char		*output_hex(t_prt *prt)
{
	char		*ret;
	int			padding_count;
	uintmax_t	nb;

	prt->base = 16;
	prt->u_sign = TRUE;
	nb = get_integer_length(prt);
	ret = ft_uintmaxtoa(nb, prt->base);
	padding_count = prt->width - ft_strlen(ret);
	if (prt->incl_dot == TRUE)
	{
		if (prt->precision == 0)
			ret = ft_strdup("");
		else
			ret = handle_int_precision(prt, ret);
	}
	if (((prt->incl_hash == TRUE && ((nb != 0 && padding_count < 3)))
	|| CURR_POS == 'p'))
		ret = add_hash(prt, ret);
	if (CURR_POS == 'X')
		ret = ft_strupr(ret);
	prt->strlen_value = ft_strlen(ret);
	if (prt->width - ft_strlen(ret) > 0 && prt->width != 0)
		ret = add_width(prt, ret);
	return (ret);
}
