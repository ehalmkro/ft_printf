/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:36:45 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/06/12 12:42:57 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char *output_pointer(t_prt *prt)
{
	prt->include_hash = TRUE;
	prt->length = prt->length == undef ?  l : prt->length;
	prt->u_sign = TRUE;
	return(output_hex(prt));
}