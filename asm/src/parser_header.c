/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:26:14 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:26:18 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		check_end_line(char *s)
{
	remove_comment(&s);
	ft_trim_ending_space(&s);
	if (*s != '\0')
		return (1);
	return (0);
}

static int		get_quote_string(char *s)
{
	unsigned int	i;

	i = 1;
	while (s[i] != '"' && s[i])
		i++;
	if (s[i] == '"')
		return (i);
	return (0);
}

static void		get_name(t_parser *p, char *s)
{
	int		i;
	int		index;
	char	*line;

	line = NULL;
	index = s - p->line;
	while ((i = get_quote_string(s)) == 0)
	{
		p->line = join(p->line, "\n");
		if (get_next_line(p->fd, &line) < 1)
			parser_error(p, "Name quote not close", "");
		p->count_line++;
		p->line = join(p->line, line);
		s = p->line + index;
		ft_strdel(&line);
	}
	if (check_end_line(s + i + 1))
		parser_error(p, "Strange thing after name :", s + i);
	else if (i - 1 > PROG_NAME_LENGTH)
		parser_error(p, "Champion name too long (Max length 128)", "");
	ft_strncpy(p->h->prog_name, s + 1, i - 1);
	p->is_name = 1;
}

static void		get_comment(t_parser *p, char *s)
{
	int		i;
	int		index;
	char	*line;

	line = NULL;
	index = s - p->line;
	while ((i = get_quote_string(s)) == 0)
	{
		p->line = join(p->line, "\n");
		if (get_next_line(p->fd, &line) < 1)
			parser_error(p, "Comment quote not close", "");
		p->count_line++;
		p->line = join(p->line, line);
		s = p->line + index;
		ft_strdel(&line);
	}
	if (check_end_line(s + i + 1))
		parser_error(p, "Strange thing after comment :", s + i);
	else if (i - 1 > PROG_NAME_LENGTH)
		parser_error(p, "Champion comment too long (Max length 2048)", "");
	ft_strncpy(p->h->comment, s + 1, i - 1);
	p->is_comment = 1;
}

void			parser_header(t_parser *p)
{
	char	*s;

	s = p->line;
	ft_trim_leading_space(&s);
	if (*s == '\0' || *s == '#' || *s == ';')
		return ;
	else if (!ft_strncmp(s, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
	{
		s += ft_strlen(NAME_CMD_STRING);
		ft_trim_leading_space(&s);
		if (*s != '"')
			parser_error(p, "Syntax error name :", s);
		get_name(p, s);
	}
	else if (!ft_strncmp(s, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
	{
		s += ft_strlen(COMMENT_CMD_STRING);
		ft_trim_leading_space(&s);
		if (*s != '"')
			parser_error(p, "Syntax error comment :", s);
		get_comment(p, s);
	}
	else
		parser_error(p, "Header not conform :", s);
}
