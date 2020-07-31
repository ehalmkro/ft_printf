/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:06:42 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/07/31 12:54:29 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long double	rounding(long double nb, int precision)
{
	long double	rounding;

	rounding = precision == 0 ? 0.499 : 0.500;
	if (nb == 0)
		return (nb);
	if (nb < 0)
		rounding *= -1;
	while (precision-- > 0)
		rounding /= 10.0;
	return (rounding);
}

static int			ft_sbit(long double nb)
{
	t_signbit			signbit;

	signbit.ld = nb;
	return (int)(signbit.shifter.sexp >> 15);
}

static char			*get_floor_value(long double n)
{
	long double			int_val;
	long double			dec_val;
	char				*ret;
	char				*header;
	char				*temp;

	header = NULL;
	dec_val = ft_modf(n, &int_val);
	if (ft_sbit(n) && dec_val <= 0)
		header = ft_strdup("-");
	n *= (n < 0) ? -1 : 1;
	ret = ft_itoa_base(n, 10);
	if (header)
	{
		temp = ft_strjoin(header, ret);
		free(ret);
		ret = ft_strdup(temp);
		free(temp);
		free(header);
	}
	return (ret);
}

char				*ft_ftoa(long double n, int precision)
{
	unsigned long long	dec;
	char				*ipart;
	char				*fpart;
	char				*ret;
	int					i;

	n = n + rounding(n, precision);
	ipart = get_floor_value(n);
	n *= (n < 0) ? -1 : 1;
	dec = n;
	n = precision ? (n - dec) : 0;
	fpart = ft_strnew(precision + 2);
	fpart[0] = '.';
	i = 0;
	while (precision > i++)
	{
		n *= 10;
		dec = n;
		n -= dec;
		fpart[i] = dec + '0';
	}
	ret = precision > 0 ? ft_strjoin(ipart, fpart) : ft_strdup(ipart);
	free(fpart);
	free(ipart);
	return (ret);
}
