/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehalmkro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:07:53 by ehalmkro          #+#    #+#             */
/*   Updated: 2019/10/16 10:07:55 by ehalmkro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (tab[i])
	{
		if ((*f)(tab[i]) == 1)
			count++;
		i++;
	}
	return (count);
}