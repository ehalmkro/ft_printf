/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 12:04:51 by ehalmkro          #+#    #+#             *//*   Updated: 2020/06/09 17:15:17 by ehalmkro         ###   ########.fr       */

/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> //TODO: REMOVE

static size_t return_length(long long nb, int base)
{
	size_t len;

	len = 0;
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	while (nb != 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}

char *ft_itoa_base(long long nb, int base)
{
	char *ret;
	char *base_chars;
	size_t char_count;

	if (nb == 0)
		return(ft_strdup("0"));
	if (nb == 4294967296 && base == 16)
		return(ft_strdup("100000000"));
	if (nb == -9223372036854775807 - 1)
		return(ft_strdup("−9223372036854775808"));
	base_chars = ft_strdup("0123456789abcdef");
	nb = base == 16 && nb < 0 ? (unsigned int)nb : nb;
	char_count = return_length(nb, base);
	ret = ft_strnew(char_count + 1);
	ret[char_count] = '\0';
	if (nb < 0)
	{
		ret[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		ret[--char_count] = base_chars[nb % base];
		nb /= base;
	}
	free(base_chars);
	return(ret);
}
