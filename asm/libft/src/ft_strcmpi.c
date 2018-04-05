/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmpi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdurand <rdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:50:45 by rdurand           #+#    #+#             */
/*   Updated: 2016/11/20 17:50:49 by rdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Compare 2 strings and return -1 if the 2 strings are the same
** or the index "i" of the first different char
*/

int		ft_strcmpi(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}
