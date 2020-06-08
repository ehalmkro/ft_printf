/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 16:23:41 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/06/08 10:35:10 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char *output_char(t_prt *prt)
{
	char *ret;
	int c;

	c = va_arg(prt->ap, int);
	ret = ft_strnew(1);
	ret[0] = (char)c;
	prt->strlen_value = 1;
	ret = prt->width > 0 ? add_width(prt, ret) : ret;
	return(ret);
}