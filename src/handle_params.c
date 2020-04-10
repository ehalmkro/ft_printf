/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:25:16 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/04/10 20:09:47 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void n_format(t_prt *prt)
{
	int *arg;
	int ret;

	ret = (int)ft_strlen(prt->output);
	arg = va_arg(prt->ap, int*);
	*arg = ret;
}

int handle_flags(t_prt *prt)
{
	char *flags;

	flags = ft_strdup("-+ #0*");
	if (ft_strchr(flags, prt->format[++prt->i]) == NULL)
		return(0);
	prt->include_space = prt->format[prt->i] == ' ' ? TRUE : FALSE;
	while (prt->format[prt->i] == ' ')
		prt->i++;
	prt->padding_char = prt->format[prt->i] == '0' ? '0' : ' '; //TODO: padding - flag
	prt->padding_char == '0' ? prt->i++ : 0;
	prt->width = prt->format[prt->i] == '*' ? va_arg(prt->ap, int) + 1 : (size_t)ft_atoi(prt->format + prt->i);
	while (ft_isdigit(prt->format[prt->i]) || prt->format[prt->i] == '*')
		prt->i++;
}
int	handle_params(t_prt *prt)
{
	handle_flags(prt);
	prt->format[prt->i] == 'i' ? output_int(prt) : 0;
	prt->format[prt->i] == '%' ? add_value_to_str(prt, "%") : 0;
	prt->format[prt->i] == 'n' ? n_format(prt) : 0;

	while (ft_isalpha(prt->format[prt->i]) == 1 && prt->format[prt->i])
		prt->i++;
	prt->prev_i = prt->i;
	return(1);
}