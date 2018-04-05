/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdurand <rdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:52:12 by rdurand           #+#    #+#             */
/*   Updated: 2016/11/20 17:52:16 by rdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** transform an int_32 little_endian to big_endian
*/

int		swap_int32(int val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return (val << 16) | ((val >> 16) & 0xFFFF);
}

int		swap_int16(int val)
{
	return (val >> 8) | (val << 8);
}

int		swap_int8(int val)
{
	return ((val >> 4) | (val << 4));
}
