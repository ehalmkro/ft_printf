/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 11:56:51 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/04/16 15:13:20 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void add_width(t_prt *prt, char *ret)
{
	int i;
	int padding_count;
	char *padding;
	char padding_char;

	padding_char = prt->padding_char == '0' ? '0' : ' ';
	i = 0;
	if ((padding_count = prt->width - ft_strlen(ret)) < 0)
	{
		add_value_to_str(prt, ret);
		return;
	}
	padding = ft_strnew(padding_count);
	while (padding_count-- > 0)
		padding[i++] = padding_char;
	padding[1] = prt->include_hash == TRUE ? 'x' : padding_char;
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