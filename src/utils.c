/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 16:07:38 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/07/31 17:42:57 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		add_space_to_output(t_prt *prt)
{
	prt->width > 0 ? --prt->width : 0;
	join_value_to_output(prt, " ", 1);
}

void		switch_width_sign(char **ret, char **padding)
{
	char		temp;

	if (!padding[1])
		return ;
	temp = (*ret)[0];
	(*ret)[0] = (*padding)[0];
	(*padding)[0] = temp;
}

char		*n_format(t_prt *prt)
{
	int *arg;
	int ret;

	ret = (int)ft_strlen(prt->output);
	arg = va_arg(prt->ap, int*);
	*arg = ret;
	return (ft_strdup(""));
}

char		*percent_format(t_prt *prt)
{
	char *ret;

	ret = ft_strnew(1);
	ret[0] = '%';
	prt->strlen_value = 1;
	ret = prt->width > 0 ? add_width(prt, ret) : ret;
	prt->strlen_value = ft_strlen(ret);
	return (ret);
}
