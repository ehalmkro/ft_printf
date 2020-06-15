/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 11:05:43 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/06/15 15:56:28 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	return_length(intmax_t nb, int base)
{
	size_t	len;

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

char			*ft_itoa_base(intmax_t nb, int base)
{
	char	*ret;
	char	*base_chars;
	size_t	char_count;

	if (nb == 0)
		return (ft_strdup("0"));
	base_chars = ft_strdup("0123456789abcdef");
	char_count = return_length(nb, base);
	if ((ret = ft_strnew(char_count + 1)) == NULL)
		return (NULL);
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
	return (ret);
}
