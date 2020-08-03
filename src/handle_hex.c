/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 20:15:50 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/08/03 18:58:41 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char	*add_hash(t_prt *prt, char *ret)
{
	char *temp;
	char *hex_hash;

	(void)prt;
	hex_hash = ft_strdup("0x");
	temp = ft_strjoin(hex_hash, ret);
	free(ret);
	ret = ft_strdup(temp);
	free(temp);
	free(hex_hash);
	if (CURR_POS == 'p')
		prt->width += 2;
	return (ret);
}

char		*output_hex(t_prt *prt)
{
	char		*ret;
	int			padding_count;
	uintmax_t	nb;

	prt->base = 16;
	prt->u_sign = TRUE;
	nb = get_integer_length(prt);
	ret = ft_uitoa(nb, prt->base);
	padding_count = prt->width - ft_strlen(ret);
	if (prt->incl_dot == TRUE)
	{
		if (prt->prec == 0)
			ret = ft_strdup("");
		else
			ret = handle_int_precision(prt, ret);
	}
	if (((prt->incl_hash == TRUE && ((nb != 0)))
	|| CURR_POS == 'p'))
		ret = add_hash(prt, ret);
	if (CURR_POS == 'X')
		ret = ft_strupr(ret);
	prt->strlen_value = ft_strlen(ret);
	if (prt->width - ft_strlen(ret) > 0 && prt->width != 0)
		ret = add_width(prt, ret);
	return (ret);
}
