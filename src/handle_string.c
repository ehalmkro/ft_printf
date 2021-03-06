/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 14:46:31 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/07/27 12:03:13 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*output_string(t_prt *prt)
{
	char *ret;

	ret = ft_strdup(va_arg(prt->ap, char*));
	if (ret == NULL)
		ret = ft_strdup("(null)");
	prt->strlen_value = ft_strlen(ret);
	if (prt->incl_dot)
	{
		ret = ft_strndup(ret, prt->prec);
		prt->strlen_value = ft_strlen(ret);
	}
	ret = prt->width > prt->strlen_value ? add_width(prt, ret) : ret;
	return (ret);
}
