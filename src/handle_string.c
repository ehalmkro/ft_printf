/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 14:46:31 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/04/16 15:24:04 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void output_string(t_prt *prt)
{
	char *ret;

	ret = va_arg(prt->ap, char*);
	ret = ret == NULL ? ft_strdup("(null)") : ret;
	ret = prt->precision > 0 ? ft_strndup(ret, prt->precision) : 0;
	prt->width > 0 ? add_width(prt, ret) : add_value_to_str(prt, ret);
	free(ret);
}