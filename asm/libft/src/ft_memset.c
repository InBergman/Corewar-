/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:52 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:53 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include "libft.h"

/*
** write 'len' bytes of value 'c' in string 'b'
*/

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str_b;

	str_b = (unsigned char*)b;
	i = 0;
	while (i < len)
		str_b[i++] = c;
	return (b);
}
