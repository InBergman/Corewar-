/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:53 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:53 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	max;
	size_t	len_src;
	size_t	i;

	i = 0;
	max = size - ft_strlen(dest) - 1;
	len_src = ft_strlen(src);
	while (dest[i] && i < size)
		i++;
	len_src += ((i < size) ? i : size);
	if ((int)max > 0)
		ft_strncat(dest, src, size - ft_strlen(dest) - 1);
	return (len_src);
}
