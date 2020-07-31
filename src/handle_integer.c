/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:40:24 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/07/31 18:19:36 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*handle_int_precision(t_prt *prt, char *value)
{
	int			len;
	char		*ret;
	char		*padding;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if ((len = prt->prec - ft_strlen(value)) < 0)
		return (value);
	padding = ft_strnew(len + 1);
	if (value[j] == '-')
	{
		padding[i++] = '-';
		j++;
		len++;
	}
	while (len-- > 0)
		padding[i++] = '0';
	padding[i] = '\0';
	ret = ft_strjoin(padding, value + j);
	free(value);
	prt->strlen_value = ft_strlen(ret);
	free(padding);
	return (ret);
}

intmax_t	get_integer_length(t_prt *tab)
{
	intmax_t	nb;

	nb = 0;
	if (tab->u_sign)
	{
		nb = tab->length == hh ? (unsigned char)va_arg(tab->ap, uintmax_t) : nb;
		nb = tab->length == h ? (unsigned short)va_arg(tab->ap, uintmax_t) : nb;
		nb = tab->length == ll ? (unsigned long long)va_arg(tab->ap, uintmax_t)
			: nb;
		nb = tab->length == l ? (unsigned long)va_arg(tab->ap, uintmax_t) : nb;
		nb = tab->length == j ? va_arg(tab->ap, uintmax_t) : nb;
		nb = tab->length == undef ? (unsigned int)va_arg(tab->ap, uintmax_t)
			: nb;
	}
	else
	{
		nb = tab->length == hh ? (char)va_arg(tab->ap, intmax_t) : nb;
		nb = tab->length == h ? (short)va_arg(tab->ap, intmax_t) : nb;
		nb = tab->length == ll ? (long long)va_arg(tab->ap, intmax_t) : nb;
		nb = tab->length == l ? (long)va_arg(tab->ap, intmax_t) : nb;
		nb = tab->length == j ? va_arg(tab->ap, intmax_t) : nb;
		nb = tab->length == undef ? (int)va_arg(tab->ap, intmax_t) : nb;
	}
	return (nb);
}

char		*initialize_int(t_prt *prt)
{
	if (CURR_POS == 'o' || CURR_POS == 'u')
	{
		prt->u_sign = TRUE;
		prt->base = CURR_POS == 'o' ? 8 : prt->base;
		prt->incl_plus = FALSE;
		prt->incl_space = FALSE;
	}
	prt->incl_zero = prt->incl_dot && prt->incl_zero ? FALSE : prt->incl_zero;
	return (output_int(prt));
}

static char	*check_int_flags(t_prt *prt, intmax_t nb, char *header, char *ret)
{
	char *temp;

	if (header != NULL && (nb >= 0 && (prt->incl_plus || prt->incl_hash)))
	{
		temp = ft_strjoin(header, ret);
		free(ret);
		ret = ft_strdup(temp);
		free(temp);
	}
	if (prt->incl_dot == TRUE && prt->prec == 0 && nb == 0 && !prt->incl_hash)
	{
		free(ret);
		ret = ft_strdup("");
	}
	prt->strlen_value = ft_strlen(ret);
	if (prt->incl_space && !prt->incl_plus && nb >= 0 && !ft_strchr(ret, ' '))
		add_space_to_output(prt);
	return (ret);
}

char		*output_int(t_prt *prt)
{
	char			*ret;
	char			*header;
	intmax_t		nb;

	header = NULL;
	nb = get_integer_length(prt);
	ret = prt->u_sign ? ft_uitoa(nb, prt->base) : ft_itoa_base(nb, prt->base);
	if (prt->incl_dot && (int)ft_strlen(ret) <= prt->prec)
		ret = handle_int_precision(prt, ret);
	if (prt->incl_plus)
		header = ft_strdup("+");
	if (prt->incl_hash && CURR_POS == 'o' && ret[0] != '0')
	{
		header = ft_strdup("0");
		prt->width += 2;
	}
	ret = check_int_flags(prt, nb, header, ret);
	ret = prt->width > 0 && prt->prec < prt->width ? add_width(prt, ret) : ret;
	free(header);
	return (ret);
}
