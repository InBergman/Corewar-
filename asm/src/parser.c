/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:26:07 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:26:18 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		ft_check_ext(char *file)
{
	size_t	i;

	i = ft_strlen(file) - 1;
	if (file[i] != 's' || file[i - 1] != '.')
		ft_error("Wrong extension !\n");
}

void			parser(t_header *h, char *file, t_parser *p)
{
	p->h = h;
	ft_check_ext(file);
	p->file = ft_strdup(file);
	if ((p->fd = open(file, O_RDONLY)) < 0)
		parser_error(p, strerror(errno), "");
	while (get_next_line(p->fd, &p->line) > 0)
	{
		p->count_line++;
		if (!p->is_name || !p->is_comment)
			parser_header(p);
		else
			parser_inst(p);
		ft_strdel(&p->line);
	}
	check_label(p);
}
