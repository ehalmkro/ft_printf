/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 15:27:46 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/06/09 15:28:38 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strupr(char *str)
{
	size_t i;
	char *ret;

	ret = ft_strnew(ft_strlen(str));
	i = 0;
	while (str[i])
	{
		ret[i] = ft_toupper(str[i]);
		i++;
	}
	ret[i] = '\0';
	free(str);
	return(ret);


}