/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 11:50:51 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/07/27 13:02:41 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char *g_flags = "-+ #0";
char *g_specifiers = "hljztL";

void		get_length(t_prt *prt)
{
	if (ft_strchr(g_specifiers, CURR_POS) == NULL)
		return ;
	if (CURR_POS == 'h')
		prt->length = NEXT_POS == 'h' ? hh : h;
	if (CURR_POS == 'l')
		prt->length = NEXT_POS == 'l' ? ll : l;
	CURR_POS == 'j' ? prt->length = j : 0;
	CURR_POS == 'z' ? prt->length = z : 0;
	CURR_POS == 't' ? prt->length = t : 0;
	CURR_POS == 'L' ? prt->length = L : 0;
	while (ft_strchr(g_specifiers, CURR_POS) != NULL && CURR_POS)
		prt->i++;
}

void		get_precision(t_prt *prt)
{
	if (CURR_POS != '.')
		return ;
	prt->incl_dot = TRUE;
	prt->i++;
	prt->prec = CURR_POS == '*' ? (size_t)va_arg(prt->ap, int)
								: (size_t)ft_atoi(prt->format + prt->i);
	while (ft_isdigit(CURR_POS) || CURR_POS == '*')
		prt->i++;
	prt->incl_dot = prt->prec < 0 ? FALSE : prt->incl_dot;
	prt->prec = prt->prec < 0 ? 0 : prt->prec;
}

void		get_flags(t_prt *prt)
{
	if ((ft_strchr(g_flags, CURR_POS) == NULL || ft_strcmp(ft_strchr(g_flags,
		CURR_POS), "") == 0) && ft_isdigit(CURR_POS) == 0)
		return ;
	while (ft_strchr(g_flags, CURR_POS) && CURR_POS)
	{
		if (CURR_POS == ' ')
		{
			prt->incl_space = TRUE;
			while (CURR_POS == ' ')
				prt->i++;
			if (!ft_strchr(g_flags, CURR_POS) || !CURR_POS)
				break ;
		}
		CURR_POS == '#' ? prt->incl_hash = TRUE : 0;
		CURR_POS == '0' ? prt->incl_zero = TRUE : 0;
		CURR_POS == '-' ? prt->incl_minus = TRUE : 0;
		CURR_POS == '+' ? prt->incl_plus = TRUE : 0;
		prt->i++;
	}
	prt->padding_char = prt->incl_zero && !prt->incl_minus ? '0' : ' ';
}

void		get_width(t_prt *prt)
{
	if (ft_isdigit(CURR_POS) || CURR_POS == '*')
	{
		if (CURR_POS == '*')
		{
			prt->width = (size_t)va_arg(prt->ap, int);
			prt->i++;
			if (prt->width < 0)
			{
				prt->width = -prt->width;
				prt->incl_minus = TRUE;
				prt->incl_zero = FALSE;
				prt->padding_char = ' ';
			}
		}
		if (ft_isdigit(CURR_POS))
		{
			prt->width = ft_atoi(prt->format + prt->i);
			while (ft_isdigit(CURR_POS))
				prt->i++;
		}
	}
}
