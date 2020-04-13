/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:25:16 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/04/13 15:25:10 by ehalmkro         ###   ########.fr       */
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

static void reinit(t_prt *prt)
{
	prt->width = 0;
	prt->precision = 0;
	prt->include_space = FALSE;
	prt->padding_char = ' ';
}

int get_precision(t_prt *prt)
{
	if (prt->format[prt->i + 1] != '.')
		return(0);
	prt->i++;
	prt->precision = prt->format[prt->i] == '*' ? (size_t)va_arg(prt->ap, int)
			: (size_t)ft_atoi(prt->format + prt->i);
	while (ft_isdigit(prt->format[prt->i]) || prt->format[prt->i] == '*')
		prt->i++;
	return(0);
}

int get_width(t_prt *prt) // TODO: add error handling
{
	char *flags;

	flags = ft_strdup("-+ #0*");
	if (ft_strchr(flags, prt->format[++prt->i]) == NULL &&
		ft_isdigit(prt->format[prt->i]) == 0)
	{
		free(flags);
		return (0);
	}
	prt->include_space = prt->format[prt->i] == ' ' ? TRUE : FALSE;
	while (prt->format[prt->i] == ' ')
		prt->i++;
	if (prt->format[prt->i] == '0' || prt->format[prt->i] == '-')
		prt->padding_char = prt->format[prt->i++];
	prt->width = prt->format[prt->i] == '*' ? (size_t)va_arg(prt->ap, int) + 1 : (size_t)ft_atoi(prt->format + prt->i);
	while (ft_isdigit(prt->format[prt->i]) || prt->format[prt->i] == '*')
		prt->i++;
	free(flags);
	return(0);
}
int	handle_params(t_prt *prt)
{
	get_width(prt);
	get_precision(prt);
	if (prt->format[prt->i] == 'i' || prt->format[prt->i] == 'd')
		output_int(prt);
	prt->format[prt->i] == '%' ? add_value_to_str(prt, "%") : 0;
	prt->format[prt->i] == 'n' ? n_format(prt) : 0;

	while (ft_isalpha(prt->format[prt->i]) == 1 && prt->format[prt->i])
		prt->i++;
	prt->prev_i = prt->i;
	reinit(prt);
	return(1);
}