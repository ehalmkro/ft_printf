/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 11:56:51 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/07/29 11:16:43 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*add_width(t_prt *prt, char *ret)
{
	int		i;
	int		pad_n;
	char	*padding;
	char	*temp;

	i = 0;
	prt->padding_char = prt->padding_char == '0'
		&& (ret[0] != '0' || ft_atoi(ret) == 0) && !prt->incl_dot ? '0' : ' ';
	if ((pad_n = prt->width - prt->strlen_value) < 0)
		return (ret);
	pad_n = prt->incl_hash && CURR_POS != 'X' && CURR_POS != 'x' ? pad_n - 2 : pad_n;
	padding = ft_strnew(pad_n);
	while (pad_n > i)
		padding[i++] = prt->padding_char;
	if ((CURR_POS == 'X' || CURR_POS == 'x') && prt->incl_hash == TRUE)
		hex_width(prt, &ret, &padding, &pad_n);
	if ((CURR_POS == 'd' || CURR_POS == 'i') && (prt->incl_plus || ft_atoi(ret) < 0) && prt->incl_zero && !prt->incl_minus)
		switch_width(&ret, &padding);
	temp = prt->incl_minus ? join_values(ret, prt->strlen_value, padding, pad_n) : join_values(padding, i, ret, prt->strlen_value);
	prt->incl_minus ? ft_memmove(ret, temp, pad_n + prt->strlen_value + 1) : ft_memmove(ret, temp, i + prt->strlen_value + 1);
	prt->strlen_value = prt->incl_minus ? prt->strlen_value + pad_n : prt->strlen_value + i;
	free(temp);
	free(padding);
	return (ret);
}

char	*join_values(char *dst, size_t dst_len, char *src, size_t src_len)
{
	char	*ret;

	ret = (char*)malloc(sizeof(char) * dst_len + src_len);
	ft_memcpy(ret, dst, dst_len);
	ft_memcpy(ret + dst_len, src, src_len);
	return (ret);
}

void	join_value_to_output(t_prt *ptr, char *value, size_t len)
{
	char	*ret;

	if (value == NULL || len == 0)
		return ;
	ret = join_values(ptr->output, ptr->strlen_output, value, len);
	ptr->strlen_output += len;
	free(ptr->output);
	ptr->output = ret;
}
