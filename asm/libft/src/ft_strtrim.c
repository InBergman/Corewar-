/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:49 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:49 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		count;
	int		len;
	char	*strim;

	i = 0;
	count = 0;
	len = ft_strlen(s);
	while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t'))
		i++;
	if (s[i])
		while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
			len--;
	strim = malloc(sizeof(char *) * (len - i) + 1);
	if (!strim || !s)
		return (NULL);
	while (count < (len - i))
	{
		strim[count] = s[i + count];
		count++;
	}
	strim[count] = '\0';
	return (strim);
}
