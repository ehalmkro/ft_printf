/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:40:24 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/04/08 19:52:17 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*static void check_width(t_prt *prt)
{
	;
}*/


void output_int(t_prt *prt)
{
	char *ret;

	ret = ft_itoa(va_arg(prt->ap, int));			//TODO: return if error
	//	check_width(prt);
	//printf("ret %s\n", ret);
	add_value_to_str(prt, ret);
	free(ret);
}