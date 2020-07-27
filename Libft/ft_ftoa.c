/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:06:42 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/07/27 11:35:55 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long double	rounding(long double nb, int precision)
{
	long double	rounding;
	int i;

	rounding = 0.5;
	if (nb < 0)
		rounding *= -1;
	i = 0;
	while (precision-- > 0)
		rounding /= 10.0;
	return (rounding);
}

char				*ft_ftoa(long double nb, int precision)
{
	unsigned long long	dec;
	char				*ipart;
	char				*fpart;
	char				*ret;
	int					i;

	nb = nb + rounding(nb, precision);
	nb *= (nb < 0) ? -1 : 1;
	dec = nb;
	ipart = ft_itoa(dec);
	nb = precision ? (nb - dec) : 0;
	fpart = ft_strnew(precision + 2);
	fpart[0] = '.';
	i = 1;
	while (precision-- > 0)
	{
		nb *= 10;
		dec = nb;
		nb -= dec;
		fpart[i++] = dec + '0';
	}
	ret = ft_strjoin(ipart, fpart);
	free(fpart);
	free(ipart);
	return (ret);
}

