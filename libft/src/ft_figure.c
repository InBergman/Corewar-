/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_figure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:49 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:49 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_figure(int number)
{
	int		i;

	i = 0;
	if (number < 0)
		i++;
	number = ft_abs(number);
	while (number)
	{
		number /= 10;
		i++;
	}
	return (i);
}
