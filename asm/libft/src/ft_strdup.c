/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:53 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:53 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s1cpy;
	int		i;

	s1cpy = malloc(sizeof(char) * ft_strlen(s1) + 1);
	i = 0;
	if (s1cpy == NULL)
		return (NULL);
	while (s1[i])
	{
		s1cpy[i] = s1[i];
		i++;
	}
	s1cpy[i] = '\0';
	return (s1cpy);
}
