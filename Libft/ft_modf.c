/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:31:12 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/04/17 12:44:14 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long double ft_modf(long double x, long double *integer)
{
	long double int_part;

	int_part = (long double)(int)x;
	*integer = int_part;
	return (x - int_part);
}