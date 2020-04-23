/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:25:16 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/04/23 16:04:46 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_convert g_convert_tab[] =
		{
				{'c', &output_char},
				{'i', &output_int},
				{'d', &output_int},
				{'o', &output_int},
				{'u', &output_int},
				{'%', &percent_format},
				{'s', &output_string},
				{'f', &output_float},
				{'x', &output_hex},
				{'X', &output_hex},
				{'n', &n_format},
				{'\0', NULL}
		};

void n_format(t_prt *prt)
{
	int *arg;
	int ret;

	ret = (int)ft_strlen(prt->output);
	arg = va_arg(prt->ap, int*);
	*arg = ret;
}

void percent_format(t_prt *prt)
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
	prt->base = 10;
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
	int i;

	i = 0;
	get_width(prt);
	get_precision(prt);
	get_length(prt);
	while (g_convert_tab[i].specifier != '\0')
	{
		if (prt->format[prt->i] == g_convert_tab[i].specifier)
			g_convert_tab[i].f(prt);
		i++;
	}
	while (ft_isalpha(prt->format[prt->i]) == 1 && prt->format[prt->i])
		prt->i++;
	prt->prev_i = prt->i;
	reinit(prt);
	return(1);
}