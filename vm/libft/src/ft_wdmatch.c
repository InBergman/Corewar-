/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:54 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:54 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wdmatch(char *s1, char *s2)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (s2[++i])
		while (s1[j] == s2[i])
		{
			j++;
			i++;
			if (s1[j] == '\0')
				return (1);
		}
	return (0);
}
