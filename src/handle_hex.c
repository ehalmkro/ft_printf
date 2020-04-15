/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 20:15:50 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/04/15 16:59:51 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char *str_toupper(char *str)
{
	size_t i;
	char *ret;

	ret = ft_strnew(ft_strlen(str));
	i = 0;
	while (str[i])
	{
		ret[i] = ft_toupper(str[i]);
		i++;
	}
	ret[i] = '\0';
	free(str);
	return(ret);


}
void output_hex(t_prt *prt)
{
	char *ret;

	ret = prt->length == undef ? ft_itoa_base(va_arg(prt->ap, int), 16) : integer_length(prt, 16);
	ret = prt->include_hash == TRUE && ft_atoi(ret) != 0 ? ft_strjoin("0x", ret) : ret;
	ret = prt->format[prt->i] == 'X' ? str_toupper(ret) : ret;
	prt->width > 0 ? add_width(prt, ret) : add_value_to_str(prt, ret);
}