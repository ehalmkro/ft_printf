/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:09:08 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/06/02 11:51:10 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char *output_float(t_prt *prt)
{
	char *ret;

	prt->precision = prt->precision == 0 ? 6 : prt->precision;
	ret = ft_ftoa(va_arg(prt->ap, double), prt->precision);
	return(ret);
}