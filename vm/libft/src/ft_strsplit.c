/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:49 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:49 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int		i;
	int		j;
	int		test;

	i = 0;
	j = 0;
	while (s[j])
	{
		test = 0;
		while (s[j] == c && s[j])
			j++;
		while (s[j] != c && s[j])
		{
			j++;
			test = 1;
		}
		if (test == 1)
			i++;
	}
	return (i);
}

static int	ft_word(char const *s, char c)
{
	int		i;

	i = 0;
	while (*s != c && *s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;

	i = ft_count(s, c);
	str = (char **)malloc(sizeof(*str) * i + 1);
	j = 0;
	if (str == NULL)
		return (NULL);
	while (i > 0)
	{
		while (*s == c && *s != '\0')
			s++;
		str[j] = ft_strsub(s, 0, (ft_word(s, c)));
		if (str[j] == NULL)
			return (NULL);
		s = s + ft_word(s, c);
		j++;
		i--;
	}
	str[j] = NULL;
	return (str);
}
