/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:09:08 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/07/27 11:42:38 by ehalmkro         ###   ########.fr       */
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

char		*output_float(t_prt *prt)
{
	char			*ret;
	long double		nb;

	nb = get_float_length(prt);
	prt->precision = prt->precision == 0 ? 6 : prt->precision;
	ret = ft_ftoa(nb, prt->precision);
	prt->strlen_value = ft_strlen(ret);
	return (ret);
}
