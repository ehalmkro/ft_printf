/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 11:56:51 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/06/05 15:47:39 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char *add_width(t_prt *prt, char *ret)
{
	int i;
	int padding_count;
	char *padding;
	char padding_char;
	char *temp;

	i = 0;
	padding_char = prt->padding_char == '0' ? '0' : ' ';
	if ((padding_count = prt->width - ft_strlen(ret)) < 0)
		return (ret);
	padding_count = prt->include_hash && prt->padding_char == '-' ? padding_count - 2 : padding_count;
	padding = ft_strnew(padding_count);
	prt->strlen_value = padding_count;
	while (padding_count > i)
		padding[i++] = padding_char;
	if ((CURR_POS == 'X' || CURR_POS == 'x') && prt->include_hash == TRUE)
	{
		padding[1] = ft_strlen(ret) < prt->width && padding_char == '0' ? CURR_POS : padding[1];
		if (padding_char == ' ')
		{
			if (prt->padding_char != '-')
			{
				padding[--padding_count] = 'x';
				padding[--padding_count] = '0';
				padding = CURR_POS == 'X' ? str_toupper(padding) : padding;
			}
			else
				ret = CURR_POS == 'x' ? ft_strjoin("0x", ret) : ft_strjoin("0X", ret);
		}
	}
	temp = prt->padding_char == '-' ? ft_strjoin(ret, padding) : ft_strjoin(padding, ret);
	ret = ft_strdup(temp);
	free(temp);
	free(padding);
	return(ret);
}
char *join_values(char *dst, size_t dst_len, char *src, size_t src_len)
{
	char *ret;

	ret = (char*)malloc(sizeof(char) * dst_len + src_len);
	ft_memcpy(ret, dst, dst_len);
	ft_memcpy(ret + dst_len, src, src_len);
	return (ret);
}

void join_value_to_output(t_prt *ptr, char *value, size_t len)
{
	char *ret;

	ret = join_values(ptr->output, ptr->strlen_output, value, len);
	ptr->strlen_output += len;
	free(ptr->output);
	ptr->output = ft_strnew(ptr->strlen_output);
	ft_memcpy(ptr->output, ret, ptr->strlen_output);
	free(ret);
}