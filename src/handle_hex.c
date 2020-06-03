/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 20:15:50 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/06/02 11:51:10 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char *str_toupper(char *str) // TODO: ADD THIS TO LIB
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
char *output_hex(t_prt *prt)
{
	char *ret;
	int padding;
	char *temp;


	prt->base = 16;
	ret = prt->length == undef ? ft_itoa_base(va_arg(prt->ap, int),
			prt->base) : integer_length(prt);
	padding = prt->width - ft_strlen(ret);
	//printf("%i\n", padding);
	if (prt->include_hash == TRUE && ft_atoi(ret) != 0 && padding < 3)
	{
		temp = ft_strjoin("0x", ret);
		prt->include_hash = FALSE;
		free(ret);
		ret = ft_strdup(temp);
	}
	ret = CURR_POS == 'X' ? str_toupper(ret) : ret;
	if (prt->include_dot == TRUE && prt->precision == 0)
	{
		free(ret);
		ret = ft_strdup("");
	}
	ret = prt->width - ft_strlen(ret) > 0 ? add_width(prt, ret) : ret;
	return(ret);
}