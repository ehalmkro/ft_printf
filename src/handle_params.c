/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:25:16 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/06/05 12:34:50 by ehalmkro         ###   ########.fr       */
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

char *n_format(t_prt *prt)
{
	int *arg;
	int ret;

	ret = (int)ft_strlen(prt->output);
	arg = va_arg(prt->ap, int*);
	*arg = ret;
	return("");
}

char *percent_format(t_prt *prt)
{
	char *ret;

	ret = ft_strnew(1);
	ret[0] = '%';
	ret = prt->width > 0 ? add_width(prt, ret) : ret;
	return(ret);

}

static void get_length(t_prt *prt)
{
	char *flags;

	flags = ft_strdup("hljztL");
	if (ft_strchr(flags, CURR_POS) == NULL)
	{
		free(flags);
		return ;
	}
	if (CURR_POS == 'h')
		prt->length = prt->format[prt->i + 1] == 'h' ? hh : h;
	if (CURR_POS == 'l')
		prt->length = prt->format[prt->i + 1] == 'l' ? ll : l;
	CURR_POS == 'j' ? prt->length = j : 0;
	CURR_POS == 'z' ? prt->length = z : 0;
	CURR_POS == 't' ? prt->length = t : 0;
	CURR_POS == 'L' ? prt->length = L : 0;
	while (ft_strchr(flags, CURR_POS) != NULL && CURR_POS)
		prt->i++;
	free(flags);

}

static void reinit(t_prt *prt)
{
	prt->width = 0;
	prt->precision = 0;
	prt->include_space = FALSE;
	prt->include_hash = FALSE;
	prt->include_plus = FALSE;
	prt->include_dot = FALSE;
	prt->length = undef;
	prt->padding_char = ' ';
	prt->base = 10;
	prt->strlen_value = 0;
}

static int get_precision(t_prt *prt)
{
	if (CURR_POS != '.')
		return(0);
	prt->include_dot = TRUE;
	prt->i++;
	prt->precision = CURR_POS == '*' ? (size_t)va_arg(prt->ap, int)
			: (size_t)ft_atoi(prt->format + prt->i);
	while (ft_isdigit(CURR_POS) || CURR_POS == '*')
		prt->i++;
	return(0);
}

static int get_flags(t_prt *prt) // TODO: add error handling
{
	char *flags;

	flags = ft_strdup("-+ #0");
	if (ft_strchr(flags, prt->format[++prt->i]) == NULL &&
		ft_isdigit(CURR_POS) == 0)
	{
		free(flags);
		return (0);
	}
	while (ft_strchr(flags, CURR_POS))
	{
		if (CURR_POS == ' ')
		{
			prt->include_space = TRUE;
			while (CURR_POS == ' ')
				prt->i++;
			if (!ft_strchr(flags, CURR_POS))
				break;
		}
		CURR_POS == '#' ? prt->include_hash = TRUE : 0;
		CURR_POS == '0' || CURR_POS == '-' ? prt->padding_char = CURR_POS : 0;
		CURR_POS == '+' ? prt->include_plus = TRUE : 0;
		prt->i++;
	}
	free(flags);
	return(0);
}

static int get_width(t_prt *prt)
{
	if (ft_isdigit(CURR_POS) || CURR_POS == '*')
	{
		prt->width = CURR_POS == '*' ? (size_t) va_arg(prt->ap, int) + 1
			: ft_atoi(prt->format + prt->i);
		while (ft_isdigit(CURR_POS) || CURR_POS == '*')
			prt->i++;
	}
	return(0);
}


void handle_params(t_prt *prt)
{
	int i;
	char *ret;

	i = 0;
	get_flags(prt);
	get_width(prt);
	get_precision(prt);
	get_length(prt);
	while (g_convert_tab[i].specifier != '\0')
	{
		if (CURR_POS == g_convert_tab[i].specifier)
		{
		//	printf("WIDTH \t\t '%c' %lu\nPRECISION \t\t %lu\nINCLUDE HASH\t %i\nINCLUDE SPACE \t %i\nINCLUDE PLUS \t %i\nSPECIFIER \t\t %c\n",\
		//  prt->padding_char, prt->width, prt->precision, prt->include_hash, prt->include_space, prt->include_plus, CURR_POS);
			ret = g_convert_tab[i].f(prt);
			join_value_to_output(prt, ret, prt->strlen_value);
		}
		i++;
	}
	while (ft_isalpha(CURR_POS) == 1 && CURR_POS) // TODO: PROPER CHECK TO SKIP SPECIFIERS
		prt->i++;
	prt->prev_i = prt->i;
	//printf("CUR POS '%c'\n CHAR %zu\n", CURR_POS, prt->i);
	reinit(prt);
}