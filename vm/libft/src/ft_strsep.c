/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdurand <rdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 13:46:15 by rdurand           #+#    #+#             */
/*   Updated: 2016/10/18 14:31:12 by rdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsep(char **stringp, const char *delim)
{
	char		*s;
	char		*tok;
	const char	*sep;

	if ((s = *stringp) == NULL)
		return (NULL);
	tok = s;
	while (*s)
	{
		sep = delim;
		while (*sep)
		{
			if (*s == *sep)
			{
				*s = '\0';
				*stringp = s + 1;
				return (tok);
			}
			sep++;
		}
		s++;
	}
	*stringp = NULL;
	return (tok);
}
