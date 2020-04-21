/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 20:15:50 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/04/16 14:37:46 by ehalmkro         ###   ########.fr       */
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
	int padding;
	char *temp;

	prt->base = 16;
	ret = prt->length == undef ? ft_itoa_base(va_arg(prt->ap, int), prt->base) : integer_length(prt);
	padding = prt->width - ft_strlen(ret);
	if (prt->include_hash == TRUE && ft_atoi(ret) != 0 && padding <= 0 )
	{
		temp = ft_strjoin("0x", ret);
		prt->include_hash = FALSE;
		free(ret);
		ret = temp;
	}
	ret = prt->format[prt->i] == 'X' ? str_toupper(ret) : ret;
	prt->width - ft_strlen(ret) > 0 ? add_width(prt, ret) : add_value_to_str(prt, ret);
	free(ret);
}