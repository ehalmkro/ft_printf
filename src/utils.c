/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 16:07:38 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/07/31 16:09:08 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	add_space_to_output(t_prt *prt)
{
	prt->width > 0 ? --prt->width : 0;
	join_value_to_output(prt, " ", 1);
}