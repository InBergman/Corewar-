/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:50 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:50 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**copy 'len' bytes from 'src' to 'dst'
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*str_dst;
	unsigned char	*str_src;

	i = 0;
	str_dst = (unsigned char*)dst;
	str_src = (unsigned char*)src;
	if (str_dst > str_src)
		while (i < len)
		{
			str_dst[len - 1] = str_src[len - 1];
			len--;
		}
	else
		while (i < len)
		{
			str_dst[i] = str_src[i];
			i++;
		}
	return (dst);
}
