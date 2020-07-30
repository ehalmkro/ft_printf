/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:40:24 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/07/30 12:05:48 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		switch_width(char **ret, char **padding)
{
	char		temp;

	if (!padding[1])
		return ;
	temp = (*ret)[0];
	(*ret)[0] = (*padding)[0];
	(*padding)[0] = temp;
}

char		*handle_int_precision(t_prt *prt, char *value)
{
	int			len;
	char		*ret;
	char		*padding;
	int			i;
	int			j;

	i = 0;
	j = 0;
	len = prt->prec - ft_strlen(value);
	if (len < 0)
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

char		*output_int(t_prt *prt)
{
	char			*ret;
	char			*temp;
	char			*header;
	intmax_t		nb;

	header = NULL;
	if (CURR_POS == 'o' || CURR_POS == 'u')
	{
		prt->u_sign = TRUE;
		prt->base = CURR_POS == 'o' ? 8 : prt->base;
	}
	prt->incl_zero = prt->incl_dot && prt->incl_zero ? FALSE : prt->incl_zero;
	nb = get_integer_length(prt);
	ret = prt->u_sign  ? ft_uintmaxtoa(nb, prt->base) : ft_itoa_base(nb, prt->base);
	if (prt->incl_dot && (int)ft_strlen(ret) <= prt->prec)
		ret = handle_int_precision(prt, ret);
	if (prt->incl_plus)
		header = ft_strdup("+");
	else if (prt->incl_hash && CURR_POS == 'o' && (ft_atoi(ret) != 0 && ret[0] != '0'))
	{
		header = ft_strdup("0");
		prt->width += 2;
	}
	if (header != NULL && (ft_atoi(ret) >= 0 && (prt->incl_plus || prt->incl_hash)))
	{
		temp = ft_strjoin(header, ret);
		free(ret);
		ret = ft_strdup(temp);
		free(temp);
	}
	if (prt->incl_dot == TRUE && prt->prec == 0 && ft_atoi(ret) == 0 && !prt->incl_hash)
	{
		free(ret);
		ret = ft_strdup("");
	}
	prt->strlen_value = ft_strlen(ret);
	if (prt->incl_space && !prt->incl_plus && ft_atoi(ret) >= 0 && !ft_strchr(ret, ' '))
	{
		prt->width > 0 ? --prt->width : 0;
		join_value_to_output(prt, " ", 1);
	}
	ret = prt->width > 0 && prt->prec < prt->width ? add_width(prt, ret) : ret;
	free(header);
	return (ret);
}
