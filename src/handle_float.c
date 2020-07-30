/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:09:08 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/07/30 17:18:50 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

long double	get_float_length(t_prt *tab)
{
	long double		nb;

	nb = 0;
	nb = tab->length == L ? va_arg(tab->ap, long double) :
		va_arg(tab->ap, double);
	return (nb);
}

static char 		*add_sign(t_prt *prt, char *ret, long double nb)
{
	char *header;
	char *footer;
	char *temp;

	header = NULL;
	footer = NULL;
	if (nb < 0 && ret[0] != '-')
		header = ft_strdup("-");
	if (nb >= 0 && prt->incl_plus)
		header = ft_strdup("+");
	if (prt->incl_space && (int)ft_strlen(ret) <= prt->width)
		header = ft_strdup(" ");
	if (prt->incl_dot && prt->prec == 0 && prt->incl_hash)
		footer = ft_strdup(".");
	temp = header ? ft_strjoin(header, ret) : ft_strdup(ret);
	free(ret);
	ret = footer ? ft_strjoin(temp, footer) : ft_strdup(temp);
	free(temp);
	free(header);
	free(footer);
	return (ret);
}

char		*output_float(t_prt *prt)
{
	char			*ret;
	long double		nb;

	nb = get_float_length(prt);
	if (!prt->incl_dot)
		prt->prec = prt->prec == 0 ? 6 : prt->prec;
	ret = ft_ftoa(nb, prt->prec);
	ret = add_sign(prt, ret, nb);
	prt->incl_hash = FALSE;
	prt->strlen_value = ft_strlen(ret);
	ret = prt->width > prt->strlen_value ? add_width(prt, ret) : ret;
	prt->strlen_value = ft_strlen(ret);
	return (ret);
}
