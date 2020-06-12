/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:25:16 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/06/12 14:02:02 by ehalmkro         ###   ########.fr       */
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
				{'p', &output_pointer},
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
	prt->strlen_value = 1;
	ret = prt->width > 0 ? add_width(prt, ret) : ret;
	prt->strlen_value = ft_strlen(ret);
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
		prt->length = NEXT_POS == 'h' ? hh : h;
	if (CURR_POS == 'l')
		prt->length = NEXT_POS == 'l' ? ll : l;
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
	prt->u_sign = FALSE;
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

static int get_flags(t_prt *prt)
{
	char *flags;

	flags = ft_strdup("-+ #0");
	if ((ft_strchr(flags, CURR_POS) == NULL || ft_strcmp(ft_strchr(flags, CURR_POS), "") == 0) &&
		ft_isdigit(CURR_POS) == 0)
	{
		free(flags);
		return (0);
	}
	while (ft_strchr(flags, CURR_POS) && CURR_POS)
	{
		if (CURR_POS == ' ')
		{
			prt->include_space = TRUE;
			while (CURR_POS == ' ')
				prt->i++;
			if (!ft_strchr(flags, CURR_POS) ||!CURR_POS)
				break;
		}
		CURR_POS == '#' ? prt->include_hash = TRUE : 0;
		CURR_POS == '0' ? prt->include_zero = TRUE : 0;
		CURR_POS == '-' ? prt->include_minus = TRUE : 0;
		CURR_POS == '+' ? prt->include_plus = TRUE : 0;
		prt->i++;
	}
	prt->padding_char = prt->include_zero && !prt->include_minus ? '0' : ' ';
	free(flags);
	return(0);
}

static int get_width(t_prt *prt)
{
	if (ft_isdigit(CURR_POS) || CURR_POS == '*')
	{
		if (CURR_POS == '*')
		{
			prt->width = (size_t)va_arg(prt->ap, int) + 1;
			prt->i++;
		}
		if (ft_isdigit(CURR_POS))
		{
			prt->width = ft_atoi(prt->format + prt->i);
			while (ft_isdigit(CURR_POS))
				prt->i++;
		}
	}
	return(0);
}


void handle_params(t_prt *prt)
{
	int i;
	char *ret;

	ret = NULL;
	i = 0;
	prt->i++;
	while (!ft_strchr("scSCdDiuUoOxXbp%", CURR_POS))
	{
		get_flags(prt);
		get_width(prt);
		get_precision(prt);
		get_length(prt);
	}
	while (g_convert_tab[i].specifier != '\0' && CURR_POS)
	{
		if (CURR_POS == g_convert_tab[i].specifier)
		{
		//printf("WIDTH \t\t '%c' %lu\nPRECISION \t\t %i\nINCLUDE DOT \t %i\nINCLUDE HASH\t %i\nINCLUDE SPACE \t %i\nINCLUDE PLUS \t %i\nSPECIFIER \t\t %c\nLENGTH \t\t%i\n",
		//prt->padding_char, prt->width, prt->precision, prt->include_dot, prt->include_hash, prt->include_space, prt->include_plus, CURR_POS, prt->length);

			ret = g_convert_tab[i].f(prt);
			join_value_to_output(prt, ret, prt->strlen_value);
		}
		i++;
	}
	CURR_POS && ret != NULL ? prt->i++ : 0;
	prt->prev_i = prt->i;
	reinit(prt);
}