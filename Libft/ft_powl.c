/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 11:08:06 by ehalmkro          #+#    #+#             */
/*   Updated: 2020/06/15 15:52:38 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns x raised to the power of y
*/

long double	ft_powl(long double x, long double y)
{
	return (y ? x * ft_powl(x, y - 1) : 1);
}
