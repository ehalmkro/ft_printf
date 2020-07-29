/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:25:16 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/07/29 11:14:18 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char *g_identifiers = "scSCdDiuUoOxXpfF%";

t_convert	g_convert_tab[] =
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

char		*n_format(t_prt *prt)
{
	int *arg;
	int ret;

	ret = (int)ft_strlen(prt->output);
	arg = va_arg(prt->ap, int*);
	*arg = ret;
	return (ft_strdup(""));
}

char		*percent_format(t_prt *prt)
{
	char *ret;

	ret = ft_strnew(1);
	ret[0] = '%';
	prt->strlen_value = 1;
	ret = prt->width > 0 ? add_width(prt, ret) : ret;
	prt->strlen_value = ft_strlen(ret);
	return (ret);
}

static void	reinit(t_prt *prt)
{
	prt->width = 0;
	prt->precision = 0;
	prt->incl_space = FALSE;
	prt->incl_hash = FALSE;
	prt->incl_plus = FALSE;
	prt->incl_dot = FALSE;
	prt->length = undef;
	prt->u_sign = FALSE;
	prt->padding_char = ' ';
	prt->base = 10;
	prt->strlen_value = 0;
}

void		handle_params(t_prt *prt)
{
	int		i;
	char	*ret;

	ret = NULL;
	i = 0;
	prt->i++;
	while (!ft_strchr(g_identifiers, CURR_POS) && CURR_POS)
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
		//	printf("WIDTH \t\t '%c' %lu\nPRECISION \t\t %i\nINCLUDE DOT \t %i\nINCLUDE HASH\t %i\nINCLUDE SPACE \t %i\nINCLUDE PLUS \t %i\nSPECIFIER \t\t %c\nLENGTH \t\t%i\n",
		//	prt->padding_char, prt->width, prt->precision, prt->incl_dot, prt->incl_hash, prt->incl_space, prt->incl_plus, CURR_POS, prt->length);
			ret = g_convert_tab[i].f(prt);
			join_value_to_output(prt, ret, prt->strlen_value);
			free(ret);
		}
		i++;
	}
	CURR_POS && ret != NULL ? prt->i++ : 0;
	prt->prev_i = prt->i;
	reinit(prt);
}
