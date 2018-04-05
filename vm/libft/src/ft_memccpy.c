/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:51 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:51 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** copy n byte of a string 'src' to 'dst'
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*str_dst;
	char	*str_src;

	i = 0;
	str_dst = (char *)dst;
	str_src = (char *)src;
	while (i < n && str_src[i] != c)
	{
		str_dst[i] = str_src[i];
		i++;
	}
	if (str_src[i] == c)
	{
		str_dst[i] = c;
		return (dst + i + 1);
	}
	return (NULL);
}
