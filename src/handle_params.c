/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:25:16 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/07/31 17:40:15 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char *g_identifiers = "scSCdDiuUoOxXpfF%";

t_convert	g_convert_tab[] =
{
	{'c', &output_char},
	{'i', &initialize_int},
	{'d', &initialize_int},
	{'o', &initialize_int},
	{'u', &initialize_int},
	{'%', &percent_format},
	{'s', &output_string},
	{'f', &output_float},
	{'x', &output_hex},
	{'X', &output_hex},
	{'n', &n_format},
	{'p', &output_pointer},
	{'\0', NULL}
};

static void	reinit(t_prt *prt)
{
	prt->prec = 0;
	prt->width = 0;
	prt->base = 10;
	prt->incl_space = FALSE;
	prt->incl_hash = FALSE;
	prt->incl_plus = FALSE;
	prt->incl_dot = FALSE;
	prt->incl_zero = FALSE;
	prt->incl_minus = FALSE;
	prt->u_sign = FALSE;
	prt->padding_char = ' ';
	prt->length = undef;
	prt->strlen_value = 0;
}

static void	identifier_loop(t_prt *prt)
{
	while (!ft_strchr(g_identifiers, CURR_POS) && CURR_POS)
	{
		get_flags(prt);
		get_width(prt);
		get_precision(prt);
		get_length(prt);
	}
	prt->incl_zero = prt->incl_minus ? FALSE : prt->incl_zero;
	prt->incl_space = prt->incl_plus ? FALSE : prt->incl_space;
}

void		handle_params(t_prt *prt)
{
	int		i;
	char	*ret;

	ret = NULL;
	i = 0;
	prt->i++;
	identifier_loop(prt);
	while (g_convert_tab[i].specifier != '\0' && CURR_POS)
	{
		if (CURR_POS == g_convert_tab[i].specifier)
		{
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
