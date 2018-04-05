/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_each_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:25:53 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:26:18 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	ft_search_each_char(char *str, char *list_of_chars)
{
	size_t	i;
	int		y;

	i = 0;
	if (!str || !list_of_chars)
		return (0);
	while (str[i])
	{
		y = 0;
		while (list_of_chars[y] != str[i] && list_of_chars[y] != '\0')
			y++;
		if (list_of_chars[y] == '\0')
			return (0);
		i++;
	}
	return (1);
}
