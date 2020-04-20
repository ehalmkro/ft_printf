/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:09:08 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/04/20 14:15:50 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void output_float(t_prt *prt)
{
	char *ret;

	prt->precision = prt->precision == 0 ? 6 : prt->precision;
	ret = ft_ftoa(va_arg(prt->ap, double), prt->precision);
	add_value_to_str(prt, ret);
}