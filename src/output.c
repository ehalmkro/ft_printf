/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 11:56:51 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/04/13 17:29:39 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void add_width(t_prt *prt, char *ret)
{
	size_t i;
	size_t padding_count;
	char *padding;


	i = 0;
	padding_count = prt->width - ft_strlen(ret);
	padding = ft_strnew(padding_count);
	while (padding_count-- > 0)
		padding[i++] = prt->padding_char == '0' ? '0' : ' ';
	prt->padding_char == '-' ? add_value_to_str(prt, ret) : add_value_to_str(prt, padding);
	prt->padding_char == '-' ? add_value_to_str(prt, padding) : add_value_to_str(prt, ret);
	free(padding);
}

void add_value_to_str(t_prt *ptr, char *value)
{
	char *ret;

	ret = ft_strjoin(ptr->output, value);
	free(ptr->output);
	ptr->output = ft_strdup(ret);
	free(ret);
}