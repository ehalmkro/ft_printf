/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:06:42 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/06/15 15:57:36 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*output_fract_part(long double nb, int precision)
{
	char		*ret;
	long double	factor;

	factor = ft_powl(10, precision);
	nb *= factor;
	nb = ft_round(nb);
	if (nb == 0)
	{
		ret = ft_strnew(precision);
		while (precision)
		{
			ret[--precision] = nb + '0';
			nb /= 10;
		}
	}
	else
		ret = ft_uintmaxtoa(nb, 10);
	return (ret);
}

char	*ft_ftoa(long double nb, int precision)
{
	long double	int_part;
	long double	fract_part;
	char		*ret;
	char		*temp;

	fract_part = ft_modf(nb, &int_part);
	fract_part = fract_part < 0 ? -fract_part : fract_part;
	temp = ft_itoa_base(int_part, 10);
	ret = ft_strdup(temp);
	free(temp);
	temp = ft_strjoin(ret, ".");
	ret = ft_strdup(temp);
	free(temp);
	temp = output_fract_part(fract_part, precision);
	ret = ft_strjoin(ret, temp);
	return (ret);
}
