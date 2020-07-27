/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:36:45 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/07/27 15:19:51 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*output_pointer(t_prt *prt)
{
	prt->incl_hash = TRUE;
	prt->length = prt->length == undef ? l : prt->length;
	prt->u_sign = TRUE;
	return (output_hex(prt));
}
