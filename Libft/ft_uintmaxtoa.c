/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmaxtoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 12:01:50 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/06/15 12:55:12 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
static size_t get_len(uintmax_t nb, int base)
{
	size_t len;

	len = 0;
	while (nb > 0)
	{
		len++;
		nb /= base;
	}
	return(len == 0 ? 1 : len);
}

char *ft_uintmaxtoa(uintmax_t nb, int base)
{
	uintmax_t len;
	char *ret;
	char *base_chars;

	base_chars = ft_strdup("0123456789abcdef");
	len = get_len(nb, base);
	if (!(ret = ft_strnew(len)))
		return (NULL);
	ret[len] = '\0';
	while (len-- > 0)
	{
		ret[len] = base_chars[nb % base];
		nb /= base;
	}
	free(base_chars);
	return(ret);
}