/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdurand <rdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:51:53 by rdurand           #+#    #+#             */
/*   Updated: 2016/11/20 17:51:55 by rdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** return the min value of an array of int
*/

int		min_val(int *array, int size)
{
	int		i;
	int		min;

	i = 0;
	min = array[0];
	while (i < size)
	{
		if (array[i] < min)
			min = array[i];
		i++;
	}
	return (min);
}
