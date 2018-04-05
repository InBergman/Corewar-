/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:49 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:49 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**return the end of the string 's' from the 'c' caracter or NULL if the 'c'
**caracter isn't find
*/

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (c != s[i] && s[i])
		i++;
	if (s[i] == c)
		return (char*)(s + i);
	return (NULL);
}
