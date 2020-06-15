/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:40:24 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/06/15 14:46:37 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void int_width(t_prt *prt, char **ret, char **padding, int *padding_count)
{
	char temp;

	(void)prt;
	(void)padding_count;
	if (!padding[1])
		return;
	temp = (*ret)[0];
	(*ret)[0] = (*padding)[0];
	(*padding)[0] = temp;
}

static char *handle_int_width(t_prt *prt, char *ret)
{
	if (prt->precision >= prt->width)
		return (ret);
	else
	{
		ret = add_width(prt, ret);
		return(ret);
	}
}

char *handle_int_precision(t_prt *prt, char *value)
{
	int len;
	char *ret;
	char *padding;
	int i;

	i = 0;
	len = prt->precision - ft_strlen(value);
	if (len < 0)
		return(value);
	padding = ft_strnew(len + 1);
	if (value[0] == '-')
	{
		padding[i] = '-';
		i++;
		value++;
		len++;
	}
	while (len > 0)
	{
		padding[i] = '0';
		i++;
		len--;
	}
	padding[i] = '\0';
	ret = ft_strjoin(padding, value);
	prt->strlen_value = ft_strlen(ret);
	free(padding);
	return (ret);
}

intmax_t get_integer_length(t_prt *tab)
{
	intmax_t nb;

	nb = 0;
	if (tab->u_sign)
	{
		nb = tab->length == hh ? (unsigned char)va_arg(tab->ap, uintmax_t) : nb;
		nb = tab->length == h ? (unsigned short)va_arg(tab->ap, uintmax_t) : nb;
		nb = tab->length == ll ? (unsigned long long)va_arg(tab->ap, uintmax_t) : nb;
		nb = tab->length == l ? (unsigned long)va_arg(tab->ap, uintmax_t) : nb;
		nb = tab->length == j ? va_arg(tab->ap, uintmax_t) : nb;
		nb = tab->length == undef ? (unsigned int)va_arg(tab->ap, uintmax_t) : nb;
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

char *output_int(t_prt *prt)
{
	char	*ret;
	char	*temp;
	char 	*header;
	intmax_t nb;

	header = NULL;
	temp = NULL;
	if (CURR_POS == 'o' || CURR_POS == 'u')
	{
		prt->u_sign = TRUE;
		prt->base = CURR_POS == 'o' ? 8 : prt->base;
	}
	prt->include_zero = prt->include_dot && prt->include_zero ? FALSE : prt->include_zero;
	nb = get_integer_length(prt);
	ret = prt->u_sign ? ft_uintmaxtoa(nb, prt->base) : ft_itoa_base(nb, prt->base);
	if (prt->include_dot)
	{
		temp = ft_strdup(ret);
		free (ret);
		ret = (int)ft_strlen(ret) <= prt->precision ? handle_int_precision(prt, temp) : ft_strdup(temp);
		free(temp);
	}
	if (prt->include_plus)
		header = ft_strdup("+");
	else if (prt->include_hash && CURR_POS == 'o' && (ft_atoi(ret) != 0 && ret[0] != '0'))
	{
		header = ft_strdup("0");
		prt->width += 2;
	}
	ret = header != NULL && (ft_atoi(ret) >= 0 && (prt->include_plus || prt->include_hash)) ? ft_strjoin(header, ret) : ret;
	if (prt->include_dot == TRUE && prt->precision == 0 && ft_atoi(ret) == 0 && !prt->include_hash)
	{
		free(ret);
		ret = ft_strdup("");
	}
	prt->strlen_value = ft_strlen(ret);
	if (prt->include_space && !prt->include_plus && ft_atoi(ret) >= 0 && !ft_strchr(ret, ' '))
	{
		prt->width > 0 ? --prt->width : 0;
		join_value_to_output(prt, " ", 1);
	}
	ret = prt->width > 0 ? handle_int_width(prt, ret) : ret;
	//temp ? free(temp) : 0;
	return(ret);
}