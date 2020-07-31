/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 11:56:51 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/07/31 18:02:57 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	get_pad_char(t_prt *prt, char *ret)
{
	if (CURR_POS != 'f' && CURR_POS != 'o')
		prt->padding_char = prt->padding_char == '0' && (ret[0] != '0'
			|| ft_atoi(ret) == 0) && !prt->incl_dot ? '0' : ' ';
	return (prt->incl_hash && CURR_POS != 'X' && CURR_POS != 'x' ?
			prt->width - prt->strlen_value - 2 :
			prt->width - prt->strlen_value);
}

static void	pad_numeric(t_prt *prt, char **ret, char **padding, int *pad_n)
{
	if ((CURR_POS == 'X' || CURR_POS == 'x') && prt->incl_hash == TRUE)
		hex_width(prt, ret, padding, pad_n);
	if ((CURR_POS == 'd' || CURR_POS == 'i' || CURR_POS == 'f') &&
	(prt->incl_plus || *(ret[0]) == '-') && prt->incl_zero && !prt->incl_minus)
		switch_width_sign(ret, padding);
}

char		*add_width(t_prt *prt, char *ret)
{
	int		i;
	int		pad_n;
	char	*padding;
	char	*temp;

	i = 0;
	if ((pad_n = get_pad_char(prt, ret)) < 0)
		return (ret);
	padding = ft_strnew(pad_n);
	while (pad_n > i)
		padding[i++] = prt->padding_char;
	pad_numeric(prt, &ret, &padding, &pad_n);
	temp = prt->incl_minus ? join_values(ret, prt->strlen_value, padding, pad_n)
			: join_values(padding, i, ret, prt->strlen_value);
	free(ret);
	ret = prt->incl_minus ? (char*)malloc(sizeof(char) * (prt->strlen_value +
		pad_n)) : (char*)malloc(sizeof(char) * (i + prt->strlen_value));
	prt->incl_minus ? ft_memmove(ret, temp, pad_n + prt->strlen_value) :
	ft_memmove(ret, temp, i + prt->strlen_value);
	prt->strlen_value = prt->incl_minus ? prt->strlen_value + pad_n :
		prt->strlen_value + i;
	free(temp);
	free(padding);
	return (ret);
}

char		*join_values(char *dst, size_t dst_len, char *src, size_t src_len)
{
	char	*ret;

	ret = (char*)malloc(sizeof(char) * dst_len + src_len);
	ft_memcpy(ret, dst, dst_len);
	ft_memcpy(ret + dst_len, src, src_len);
	return (ret);
}

void		join_value_to_output(t_prt *ptr, char *value, size_t len)
{
	char	*ret;

	if (value == NULL || len == 0)
		return ;
	ret = join_values(ptr->output, ptr->strlen_output, value, len);
	ptr->strlen_output += len;
	free(ptr->output);
	ptr->output = (char*)malloc(sizeof(char) * ptr->strlen_output);
	ptr->output = ft_memcpy(ptr->output, ret, ptr->strlen_output);
	free(ret);
}
