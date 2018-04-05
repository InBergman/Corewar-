/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:26:01 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:26:18 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*ft_rename(char *str)
{
	char	*new;
	char	*s2;

	if (!str)
		return (NULL);
	s2 = ft_strchr(str, '.');
	*s2 = '\0';
	new = ft_strjoin(str, ".cor");
	return (new);
}

void		ft_open(char *str, t_header *header, t_parser *p)
{
	int		fd;
	char	*name;
	t_inst	*tmp;

	name = ft_rename(str);
	p->output = name;
	if ((fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0755)) < 0)
		parser_error(p, "ERROR open and create file :", name);
	write(fd, header, sizeof(t_header));
	tmp = p->l_inst;
	while (tmp)
	{
		print_data(fd, tmp);
		tmp = tmp->next;
	}
	close(fd);
}
