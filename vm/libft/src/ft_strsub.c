/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:51 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:51 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns a new character strings which is a section of the string "s"
** who start at index "start" and finish at index "len".
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sfresh;

	i = 0;
	sfresh = malloc(sizeof(char) * (len + 1));
	if (!sfresh)
		return (NULL);
	while (s[start + i] && i < len)
	{
		sfresh[i] = s[start + i];
		i++;
	}
	sfresh[i] = '\0';
	return (sfresh);
}
