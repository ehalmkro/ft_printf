/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 16:23:41 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/04/16 16:40:06 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void output_char(t_prt *prt)
{
	char *ret;
	char c;

	c = va_arg(prt->ap, int);
	ret = ft_strnew(1);
	ret[0] = c;
	prt->width > 0 ? add_width(prt, ret) : add_value_to_str(prt, ret);
	free(ret);
}