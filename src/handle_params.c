/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:25:16 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/04/16 15:22:34 by ehalmkro         ###   ########.fr       */
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

static void percent_format(t_prt *prt)
{
	char *ret;

	ret = ft_strnew(1);
	ret[0] = '%';
	prt->width > 0 ? add_width(prt, ret) : add_value_to_str(prt, ret);

}

static void get_length(t_prt *prt)
{
	char *flags;

	flags = ft_strdup("hljztL");
	if (ft_strchr(flags, prt->format[prt->i]) == NULL)
	{
		free(flags);
		return ;
	}
	if (prt->format[prt->i] == 'h')
		prt->length = prt->format[prt->i + 1] == 'h' ? hh : h;
	if (prt->format[prt->i] == 'l')
		prt->length = prt->format[prt->i + 1] == 'l' ? ll : l;
	prt->format[prt->i] == 'j' ? prt->length = j : 0;
	prt->format[prt->i] == 'z' ? prt->length = z : 0;
	prt->format[prt->i] == 't' ? prt->length = t : 0;
	prt->format[prt->i] == 'L' ? prt->length = L : 0;
	while (ft_strchr(flags, prt->format[prt->i]) != NULL && prt->format[prt->i])
		prt->i++;

}

static void reinit(t_prt *prt)
{
	prt->width = 0;
	prt->precision = 0;
	prt->include_space = FALSE;
	prt->include_hash = FALSE;
	prt->length = undef;
	prt->padding_char = ' ';
}

int get_precision(t_prt *prt)
{
	if (prt->format[prt->i] != '.')
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

	prt->padding_char = (prt->format[prt->i] == '0' || prt->format[prt->i] == '-')
			? prt->format[prt->i++] : ' ';

	if (prt->format[prt->i] == '#')
	{
		prt->include_hash = TRUE;
		prt->i++;
	}
	prt->width = prt->format[prt->i] == '*' ? (size_t)va_arg(prt->ap, int) + 1 :
			ft_atoi(prt->format + prt->i);
	while (ft_isdigit(prt->format[prt->i]) || prt->format[prt->i] == '*')
		prt->i++;
	free(flags);
	return(0);
}
int	handle_params(t_prt *prt)
{
	get_width(prt);
	get_precision(prt);
	get_length(prt);
	printf("width %zu, padded with  \"%c\" hash %i\n prec %zu\n", prt->width, prt->padding_char, prt->include_hash, prt->precision);
	(prt->format[prt->i] == 'i' || prt->format[prt->i] == 'd') ? output_int(prt): 0;
	prt->format[prt->i] == '%' ? percent_format(prt) : 0;
	(prt->format[prt->i] == 'x' || prt->format[prt->i] == 'X' ) ? output_hex(prt) : 0;
	prt->format[prt->i] == 's' ? output_string(prt): 0;
	prt->format[prt->i++] == 'n' ? n_format(prt) : 0;
	while (ft_isalpha(prt->format[prt->i]) == 1 && prt->format[prt->i])
		prt->i++;
	prt->prev_i = prt->i;
	reinit(prt);
	return(1);
}