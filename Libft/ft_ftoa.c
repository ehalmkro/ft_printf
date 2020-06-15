/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:06:42 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/06/15 12:23:44 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>							//TODO: remove this

char *output_fract_part(long double nb, int precision) // TODO: REFACTOR TO OUTPUT THE RIGHT AMOUNT OF ZEROS
{
	char *ret;
	long double factor;

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

char *ft_ftoa(long double nb, int precision)
{
	long double int_part;
	long double fract_part;
	char *ret;
	char *temp;

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
	return(ret);
}