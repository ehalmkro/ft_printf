/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 14:46:31 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/06/05 13:12:27 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char *output_string(t_prt *prt)
{
	char *ret;

	ret = ft_strdup(va_arg(prt->ap, char*));
	if (ret == NULL)
		ret = ft_strdup("(null)");
	else
	{
		ret = prt->precision > 0 ? ft_strndup(ret, prt->precision) : ret;
		ret = prt->width > 0 ? add_width(prt, ret) : ret;
	}
	prt->strlen_value = ft_strlen(ret);
	return(ret);
}