/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:26:49 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:26:55 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_trim_leading_space(char **s)
{
	char	*space;

	space = *s;
	while (*space == ' ' || *space == '\t')
		space++;
	*s = space;
}

void	ft_trim_ending_space(char **s)
{
	char	*space;
	size_t	len;

	len = ft_strlen(*s);
	space = *s + len - 1;
	while (*space == ' ' || *space == '\t')
		space--;
	space++;
	*space = '\0';
}

char	*join(char *str, char *buf)
{
	char	*ret;

	ret = ft_strjoin(str, buf);
	if (str != NULL)
		free(str);
	return (ret);
}

void	remove_comment(char **line)
{
	int		i;
	char	*s;

	i = 0;
	s = *line;
	while (s[i] != ';' && s[i] != '#' && s[i])
		i++;
	if (s[i] == ';' || s[i] == '#')
		s[i] = '\0';
	*line = s;
}
