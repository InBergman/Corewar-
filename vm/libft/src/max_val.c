/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdurand <rdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:51:21 by rdurand           #+#    #+#             */
/*   Updated: 2016/11/20 17:51:24 by rdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** return the max value of an array of int
*/

int		max_val(int *array, int size)
{
	int		i;
	int		max;

	i = 0;
	max = array[0];
	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}
