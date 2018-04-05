/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:18:44 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:19:02 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "vm.h"

static unsigned int	is_neg(char n)
{
	return ((unsigned char)(UCHAR_MAX + n + 1));
}

static void			ft_length(char n, size_t *len, size_t *w)
{
	unsigned char	u_value;

	u_value = 0;
	if (n < 0)
	{
		u_value = is_neg(n);
	}
	else
		u_value = (unsigned char)n;
	while ((u_value / *w) >= 16)
	{
		*w *= 16;
		*len += 1;
	}
	*len += 1;
}

static char			to_char(char n)
{
	char			c;

	if (n > 9)
		c = (n - 10) + 'a';
	else
		c = n + '0';
	return (c);
}

char				*ft_putchar_hex(char c)
{
	char			*str;
	unsigned char	u_value;
	size_t			len;
	size_t			weight;

	str = NULL;
	weight = 1;
	len = 0;
	u_value = (unsigned char)c;
	if (c < 0)
		u_value = is_neg(c);
	ft_length(c, &len, &weight);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (weight > 0)
	{
		*str++ = to_char((u_value / weight) % 16);
		weight /= 16;
	}
	return (str - len);
}
