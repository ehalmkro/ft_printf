/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 14:46:31 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/04/16 15:54:43 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void output_string(t_prt *prt)
{
	char *ret;

	ret = ft_strdup(va_arg(prt->ap, char*));
	if (ret == NULL)
	{
		add_value_to_str(prt, "(null)");
		return;
	}
	ret = prt->precision > 0 ? ft_strndup(ret, prt->precision) : ret;
	prt->width > 0 ? add_width(prt, ret) : add_value_to_str(prt, ret);
	free(ret);
}